<?php
include_once 'blade/view.send-email.blade.inc';
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
<?php
if ($email_inbox) {
	foreach ($email_inbox as $user) {
?>
				<div class="mail">
					<img src="resources/img/profile/<?php echo $user->uid.".jpg" ?>" class="image-circle-mail">
					<div class="mail-content">
						<h3><a href="read-email.php?mid=<?php echo $user->id; ?>"><?php echo $user->uid; ?></a></h3>
						<p >
							<?php 
								$ut = substr($user->text,0,20).'.....  ';
								echo $ut;
								if($user->files!='')
									echo '<font size="3" color="red">   +   Attachment</font>';
							?>
						</p>
					</div>
				</div>
<?php
	}
}
else {
	echo '<p class="alert alert-primary">You are currently not member of any group.</p>';
}

?>
			</div>

			<div class="display-table-cell" id="right">
				<div class="form-group">
					<label for="search_user">Search User</label>
					<input type="text" value="" placeholder="type user name" class="form-control" id="search_user">
				</div>
			<!-- <div class="search-option">
			<form action="" method="">
				<button id="search-button"><span class="glyphicon glyphicon-search"></span></button>
				<input type="text" name="search_user" value="" placeholder="search user" id="search-textbox">
			</form>
	</div> -->

<!--         shows user list
 -->				
 				<div id="user-list"> </div>
				</div>
			</div>
		</div>
	</div>

<script type="text/javascript">
	$(document).ready(function() {
		var user = "<?php echo $_SESSION['globalUser']->getID(); ?>";
		
		$('#search_user').keyup(function() {
			var value = $(this).val();

			if (value != '') {
				$.ajax({
					method: 'GET',
					url: 'resources/live/search-member-chat.live.php',
					data: {value : value, user : user},
					dataType: 'text',
					success: function(result) {
						$('#user-list').html(result);
					}
				});
			}
			else {
				$.ajax({
					method: 'GET',
					url: 'resources/live/show-all-user-chat.live.php',
					data: {user : user},
					dataType: 'text',
					success: function(result) {
						$('#user-list').html('');
					}
				});	
			}
		});
		$('#user-list').ready(function() {
			$.ajax({
				method: 'GET',
				url: 'resources/live/show-all-user-chat.live.php',
				data: {user : user},
				dataType: 'text',
				success: function(result) {
					$('#user-list').html('');
				}
			});
		});
	});
</script>