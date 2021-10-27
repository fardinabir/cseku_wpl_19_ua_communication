<?php
$senderID = $_POST['sender'];
$receiverID = $_POST['receiver'];
$messageText = $_POST['message'];


str_replace("00", "00000", $messageText);

$db = new mysqli('localhost', 'root', '', 'cseku');
$sql = "INSERT INTO tbl_message(senderID, receiverID, messageText) VALUES ('$senderID', '$receiverID', '$messageText')";
$result = $db->query($sql);


?>
