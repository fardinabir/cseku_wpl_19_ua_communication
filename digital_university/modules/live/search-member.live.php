<?php

$value = $_POST['value'];
$user = $_POST['user'];

$db = new mysqli('localhost', 'root', '', 'cseku');

$sql = "SELECT * FROM ums_user WHERE (FirstName LIKE '%$value%' OR LastName LIKE '%$value%') AND ID != '$user'";

$result = $db->query($sql);
$output = '<ul style="list-style: none; background: #eee; padding 10px; border-radius: 10px;">';
if ($result->num_rows > 0) {
	while ($row = $result->fetch_object()) {
		$output .= '<li><div class="usermini"><img src="resources/img/profile/' . $row->ID . '" class="image-circlemini"><div class="usermini-content"><div style="float: right; margin-top: 15px; margin-right: 10px; "></div><h3><a href="#">'.$row->FirstName .'giiii' . $row->MiddleName . ' ' . $row->LastName . '</a></h3></div></div></li>';
	}
}
$output .= '</ul>';
echo $output;
?>
