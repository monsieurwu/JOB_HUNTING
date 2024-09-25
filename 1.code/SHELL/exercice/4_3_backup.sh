#!/bin/bash
max_size=1024
log_seq=1


log() {
    log_time=$(date +'%Y-%m-%d %H:%M:%S')
    log_pid=$$
    log_file='my_app.log'
    echo "$(date +'%Y-%m-%d %H:%M:%S') [$log_pid] $1 $2" >> $log_file



}



while true;
do
    log 'INFO' 'User "john_doe" logged in from 9.67.116.99:0.'
    log 'INFO' 'User "john_doe" logged in from 9.67.116.99:0.'
    log 'INFO' 'User "john_doe" logged in from 9.67.116.99:0.'
    log 'INFO' 'User "john_doe" logged in from 9.67.116.99:0.'
    sleep 1


done