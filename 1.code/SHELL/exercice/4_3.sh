#!/bin/bash
max_size=1024
log_seq=1


log() {
    log_time=$(date +'%Y-%m-%d %H:%M:%S')
    log_pid=$$
    log_file='my_app.log'
    echo "$(date +'%Y-%m-%d %H:%M:%S') [$log_pid] $1 $2" >> $log_file
    file_size=$(wc -c < $log_file)
    if [ "$file_size" -gt "$max_size" ];then
        mv $log_file $log_file.$log_seq
        log_seq=$((log_seq + 1))
               
        tar -cjf $log_file.$((log_seq-1)).tar.bz2 $log_file.$((log_seq-1))
        mkdir -p my_log
        mv $log_file.$((log_seq-1)).tar.bz2 my_log/
        rm $log_file.$((log_seq-1))
        echo "">$log_file 

    fi


}



while true;
do
    log 'INFO' 'User "john_doe" logged in from 9.67.116.99:0.'
    log 'INFO' 'User "john_doe" logged in from 9.67.116.99:0.'
    log 'INFO' 'User "john_doe" logged in from 9.67.116.99:0.'
    log 'INFO' 'User "john_doe" logged in from 9.67.116.99:0.'
    sleep 1


done