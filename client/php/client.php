<?php

$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
socket_connect($socket, '127.0.0.1', 15599);

$data = [];
$data['name'] = 'junping';
$data['age'] = 30;
$data['sex'] = 'man';

send_data($socket, json_encode($data));
$resp = socket_read($socket, 1024);
echo $resp;

function send_data($socket, $data)
{
    $len = strlen($data);
    $pack = pack('a8', 'work');

    $cmd = 1;
    $pack .= pack('i2', $cmd, $len);
    $pack .= $data;
    socket_write($socket, $pack);
}