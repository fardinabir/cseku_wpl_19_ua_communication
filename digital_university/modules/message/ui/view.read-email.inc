<?php
include_once 'blade/view.send-email.blade.inc';
if($_GET['mid']!='')
{
	$eid= $_GET['mid'];
	$sql="SELECT * FROM `tbl_emails` WHERE id='$eid'";
	$mail=DB::getInstance()->selectFirst($sql);
	if($mail)
	{
		$receiver= $mail->receiver;
		$sender= $mail->sender;
		$subject= $mail->subject;
		$text= $mail->text;
		$file= $mail->files;
	}
	
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
				<form action="" method="POST" enctype="multipart/form-data">
					<div class="form-group">
						<p><font size="4"><b>To          : </b><pre><?php echo $receiver;?></pre></font></p>
					</div>
					<div class="form-group">
						<p><font size="4"><b>From          : </b><pre><?php echo $sender;?></pre></font></p>
					</div>

					<div id="receiverList">    </div>
					<div id="receiverContent">   </div>

					<div class="form-group">
						<p><br><font size="4"><b>Subject    : </b><?php echo $subject;?></font></p>
					</div>
					<div class="form-group">
						<p><br><font size="4"><b>Body    : </b></font></p>
						<div class="panel panel-default">
						    <div class="panel-body"><?php echo $text;?></div>
						 </div>
					</div>
					<?php
						if($file!='')
						{
							echo '<div class="form-group">
						<p><br><font size="4"><b>Attachment    : </b><a href="resources/email_attachments/'.$file.'" style="color: #ff0000" download>
							Download File
							</a></font></p>
					</div>';
						}
					?>
				</form>
			</div>
			<div class="display-table-cell" id="right">

			</div>
		</div>
	</div>