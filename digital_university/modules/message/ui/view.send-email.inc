<?php
include_once 'blade/view.send-email.blade.inc';
?>
<!DOCTYPE html>
<html>
<head>
	<title></title>
</head>
<body>


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
				<form action="" method="POST" enctype="multipart/form-data">
					<div class="form-group">
						<label for="receiver">Receiver</label>
						
						<input type="text" name="receiver" value="" placeholder="enter receiver name" class="form-control" id="receiver">
					</div>

					<div id="receiverList">    </div>
					<div id="receiverContent">   </div>

					<div class="form-group">
						<label for="subject">Subject</label>

						<input type="text" name="subject" value="" placeholder="enter mail subject" class="form-control">

					</div>
					<div class="form-group">
						<label for="body">Body</label>
						<textarea name="body" class="form-controll" placeholder="enter mail body"></textarea>
					</div>
					<div class="form-group">
						<label for="file">Add Attachment(if any)</label>
						<input type="file" name="file">
					</div>
					<div class="form-group">
						<input type="submit" name="submit" value="Send" class="btn btn-primary">
					</div>
				</form>
			</div>
			<div class="display-table-cell" id="right">

			</div>
		</div>
	</div>


</body>
</html>

<script type="text/javascript">
	$(document).ready(function() {
		$('#receiver').keyup(function() {
			var receiver = $(this).val();
			if (receiver != '') {
				$.ajax({
					method : 'GET',
					url : 'resources/live/email-suggestion.live.php',
					data : {receiver : receiver},
					dataType : 'text',
					success : function(result) {
						$('#receiverList').fadeIn().html(result);
					}
				});	
			}
		});
	});
	var html = '';
	let map = new Map();
	$('#receiverList').on('click', 'li', function() {
		var value = $(this).text();
		//alert(value);
		//alert(html);

		if(!map.has(value))
		{
			html='';
			map.set(value,true);
			for(let name of map.keys())
			{
				html += '<div name="'+name+'"><input class="esuggestion" type="text" name="h-receiver[]" value="'+name+'" readonly><font class="remove_name" style="color: red">&#10060;</font></div>';
			}
			
			$('#receiverContent').html(html);
		}
		else
			alert("*  "+value+"   is Already Added !")

		
		$('#receiverContent').on("click",".remove_name", function(){ //user click on remove text
		
		var rmvd_name=$(this).parent().attr('name');
		map.delete(rmvd_name);
		$(this).parent('div').remove();
	})
		
	});
</script>