<?php
include_once 'blade/view.message.blade.inc';
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
		<form action="" method="POST">
			<div class="display-table-cell" id="middle">
<?php
if (isset($group_create_message)) {
	echo $group_create_message;
}
?>
				<div class="form-group">
					<label for="group_name">Group Name</label>
					<input type="text" name="group_name" value="" placeholder="enter group name" class="form-control">
				</div>
				<div class="form-group">
					<label for="group_name">Search Member</label>
					<input type="text" value="" placeholder="enter member name" class="form-control" id="search_member" name="search_member">
				</div>
				<div class="form-group">
					<input type="submit" name="create_group" value="Create Group" class="btn btn-default">
				</div>
				<h1>Select Member</h1>
				<div id="user-list">   </div>
				
			</div>
			<div class="display-table-cell" id="right">
				<h1>Added Members</h1>
				<div id="memberContent">   </div> 
				
			</div>
		</form>
	</div>
</div> 
 

<script type="text/javascript">
	$(document).ready(function() {
	var user = "<?php echo $_SESSION['globalUser']->getID(); ?>";
		$('#search_member').keyup(function() {
			var search_member = $(this).val();
			if (search_member != '') {
				$.ajax({
					method : 'POST',
					url : 'resources/live/search-member.live.php',
					data : {value : search_member,user : user},
					dataType : 'text',
					success : function(result) {
						$('#user-list').fadeIn().html(result);
					}
				});	
			}
			else
			{
				$.ajax({
					method : 'POST',
					url : 'resources/live/show-all-user-group.live.php',
					data : {user : user},
					dataType : 'text',
					success : function(result) {
						$('#user-list').fadeIn().html(result);
					}
				});	
			}
		});
		$('#user-list').ready(function() {
			$.ajax({
					method : 'POST',
					url : 'resources/live/show-all-user-group.live.php',
					data : {user : user},
					dataType : 'text',
					success : function(result) {
						$('#user-list').fadeIn().html(result);
					}
				});	
		});

	});

	var html = '';
	let map = new Map();
	$('#user-list').on('click', 'li', function() {
		var value = $(this).text();
		
		//alert(value);
		//alert(html);
		if(!map.has(value))
		{
			html='';
			map.set(value,true);
			for(let name of map.keys())
			{
				html += '<div name="'+name+'"><input class="esuggestion" type="text" name="h-member[]" value="'+name+'" readonly><font class="remove_name" style="color: red">&#10060;</font></div>';
			}
			
			$('#memberContent').html(html);
		}
		else
			alert("*  "+value+"   is Already Added !")
		//$('#user-list').fadeOut();
		//$('#search_member').val('');
		
	});

	$('#memberContent').on("click",".remove_name", function(){ //user click on remove text
		
		var rmvd_name=$(this).parent().attr('name');
		map.delete(rmvd_name);
		$(this).parent('div').remove();
	})


</script>
