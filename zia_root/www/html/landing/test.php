<?php
    print_r($_SERVER);
    if (isset($_SERVER["QUERY_STRING"])) {
        $_GET = parse_url($_SERVER["QUERY_STRING"]);
        if (isset($_GET['query'])) {
            parse_str($_GET['query'], $_GET);
        }
        print_r($_GET);
    }
    parse_str(file_get_contents("php://input"), $_POST);
    print_r($_POST);
?>