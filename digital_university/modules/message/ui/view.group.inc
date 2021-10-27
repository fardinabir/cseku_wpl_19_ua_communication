<?php  include_once 'blade/view.message.blade.inc';

if (isset($_GET['group']) && !empty($_GET['group'])) {
	$group = $_GET['group'];
	$result = DB::getInstance()->selectFirst("SELECT * FROM tbl_message_group WHERE group_id=$group");
	if ($result) {
		$group_name = $result->group_name;	
	}
	else {
		header('Location: message.php');	
	}
}
else {
	header('Location: message.php');
}

?>

<nav id="header-navigation">
	<div class="brand">
		<h1>Communication</h1>
	</div>
</nav>
<div class="container-fluid">
	<div class="row">
		<div class="col-sm-2">
			<ul class="menu">
		<div onclick="location.href='group.php?group'">
				<div class="menu-item" style="cursor: pointer;"><a href="message.php">Home</a></div>
	      </div> 
	      <div onclick="location.href='create-group.php?create-group'">
				<div class="menu-item" style="cursor: pointer;"><a href="create-group.php">Create Group</a></div>
		  </div>
		   <div onclick="location.href='send-email.php?send-email'">
				<div class="menu-item" style="cursor: pointer;"><a href="send-email.php">Send Email</a>
				</div>
			</div>
			<div onclick="location.href='email-inbox.php?email-inbox'">
				<div class="menu-item" style="cursor: pointer;"><a href="email-inbox.php">email inbox</a>
				</div>
			</div>
			
			</ul>
		</div>
			<div class="display-table-cell" id="middle">
				<div class="message">
					<h2 class="message-heading"><a href="#"><?php echo $group_name; ?></a></h2>
					<div class="message-body">
						<div class="message-box" id="message-box"></div>
					</div>
					<form action="" method="POST" id="com-form">
						<div>
							<input type="text" name="messageText" value="" placeholder="type your message" class="message-text" id="messageText">	
						</div>
						<div>
							<input type="submit" name="send-message" value="Send" class="btn btn-default btn-sm" id="send-message">
						</div>
					</form>
				</div>
			</div>
			<div class="display-table-cell" id="right">
				<div>
					<ul class="menu">
						<li><a href="add-group-member.php?group=<?php echo $_GET['group']; ?>"><span class="glyphicon glyphicon-plus"></span>Add Member</a></li>
						<li><a href="message.php?g=<?php echo $_GET['group']; ?>"><span class="glyphicon glyphicon-minus"></span>Leave Group</a></li>		
					</ul>	
				</div>
				<h1>Group Members</h1>
<?php
// show group member list
$sql = "SELECT FirstName,MiddleName,LastName,ID FROM `ums_user` WHERE id in ( SELECT DISTINCT group_member_id FROM `tbl_message_group` WHERE group_name='$group_name')  ";
$memberList = DB::getInstance()->select($sql);
foreach ($memberList as $member) {
?>
				<div class="usermini">
					<img src="resources/img/profile/<?php echo $member->ID.".jpg"; ?>" class="image-circlemini">
					<div class="usermini-content">
						<h3><a href="#"><?php echo $member->FirstName . ' ' . $member->LastName; ?></a></h3>
					</div>
				</div>
<?php	
}
?>
			</div>
		</div>
	</div>
<script type="text/javascript">
	$(document).ready(function() {
		var groupName = "<?php echo $group_name; ?>";
		var sender = "<?php echo $_SESSION['globalUser']->getID(); ?>";

		$('#com-form').submit(function(event) {
			event.preventDefault();
			var messageText = $('#messageText').val();
			$('#messageText').val('');
			
			$.ajax({
				method: 'POST',
				url : 'resources/live/send-group-message.live.php',
				data: {groupName : groupName, sender : sender, messageText : messageText},
				dataType: 'text',
				success:function() {
					console.log('success');
				}
			});
		});

		setInterval(function() {
			$.ajax({
				method: 'GET',
				url: 'resources/live/get-group-message.live.php',
				data: {sender : sender, groupName : groupName},
				dataType: 'text',
				success: function(result) {
					$('#message-box').html(result);
				}
			});
		}, 500);
	});
</script>