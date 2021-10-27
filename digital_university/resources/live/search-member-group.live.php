<?php

$value = $_GET['value'];
$user = $_GET['user'];
if(isset($_GET['group_name']))
{
	$group_name = $_GET['group_name'];
}
else
	$group_name='';

$db = new mysqli('localhost', 'root', '', 'cseku');

$sql = "SELECT ums_user.* FROM ums_user WHERE ums_user.ID NOT IN( SELECT tbl_message_group.group_member_id FROM tbl_message_group WHERE tbl_message_group.group_name = '$group_name' ) AND (FirstName LIKE '%$value%' OR LastName LIKE '%$value%') AND ID != '$user'";

$result = $db->query($sql);

if ($result->num_rows > 0) {
	while ($row = $result->fetch_object()) {
		echo '<div class="user"><img src="resources/img/profile/' . $row->ID . ".jpg".'" class="image-circle"> <div class="user-content"><div style="float: right; margin-top: 15px; margin-right: 10px; "><input type="checkbox" name="member[]" value="' . $row->ID . '"></div><h3><a href="#">'.$row->FirstName .' ' . $row->MiddleName . ' ' . $row->LastName . '</a></h3></div></div>';
	}
}
else {
	echo '<div>no result found.</div>';
}

?>
