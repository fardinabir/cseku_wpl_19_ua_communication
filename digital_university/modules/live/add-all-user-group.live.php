<?php

$user = $_GET['user'];
$group_name = $_GET['group_name'];

$db = new mysqli('localhost', 'root', '', 'cseku');

$sql = "SELECT ums_user.* FROM ums_user WHERE ums_user.ID NOT IN( SELECT tbl_message_group.group_member_id FROM tbl_message_group WHERE tbl_message_group.group_name = '$group_name' )";
$result = $db->query($sql);

if ($result->num_rows > 0) {
	while ($row = $result->fetch_object()) {
		echo '<div class="user"><img src="resources/img/profile/' . $row->ID . '" class="image-circle"><div class="user-content"><div style="float: right; margin-top: 15px; margin-right: 10px; "><input type="checkbox" name="member[]" value="' . $row->ID . '"></div><h3><a href="#">'.$row->FirstName .' ' . $row->MiddleName . ' ' . $row->LastName . '</a></h3></div></div>';
	}
}
else {
	echo 'no user found.';
}
?>
