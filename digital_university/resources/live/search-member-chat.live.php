<?php

if(isset($_GET['value']))
{
	$value = $_GET['value'];
	$user = $_GET['user'];

	$db = new mysqli('localhost', 'root', '', 'cseku');

	$sql = "SELECT * FROM ums_user WHERE (FirstName LIKE '%$value%' OR LastName LIKE '%$value%' OR MiddleName LIKE '%$value%') AND ID != '$user'";

	$result = $db->query($sql);

	if ($result->num_rows > 0) {
		while ($row = $result->fetch_object()) {
			echo '<div class="usermini"><img src="resources/img/profile/' . $row->ID . ".jpg". '" class="image-circlemini"><div class="user-content"><div style="float: right; margin-top: 15px; margin-right: 10px; "></div><h3><a href="send-message.php?receiver='.$row->ID.'">'.$row->FirstName . ' ' . $row->MiddleName .' ' . $row->LastName . '</a></h3></div></div>';
		}
	}
	else {
		echo '<div>no result found.</div>';
	}
}

?>
