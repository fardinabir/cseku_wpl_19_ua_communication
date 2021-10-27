<?php
$receiver = $_GET['receiver']; 

$db = new mysqli('localhost', 'root', '', 'cseku');

$sql = "SELECT * FROM ums_user WHERE ID LIKE '%$receiver%'";
$result = $db->query($sql);
$output = '<ul style="list-style: none; background: #eee; padding 10px; border-radius: 10px;">';
if ($result->num_rows > 0) {
	while ($row = $result->fetch_object()) {
		$output .= '<li><div class="usermini"><img src="resources/img/profile/' . $row->ID .".jpg". '" class="image-circlemini"><div class="usermini-content"><div style="float: right; margin-top: 15px;  margin-right: 10px; "></div><h3><a href="#">'.$row->ID .'</a></h3></div></div></li>';
	}
}
$output .= '</ul>';
echo $output;

?>