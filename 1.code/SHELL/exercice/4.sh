#!/bin/bash

log_file="my_app.log"
max_size=1024  # 1K
log_seq=1
log_dir="my_log"

log() {
    if [ ! -d $log_dir ]; then
        mkdir $log_dir
    fi

    local log_level=$1
    local log_content=$2
    local log_timestamp=$(date +"%Y-%m-%d %H:%M:%S")
    local log_pid=$$

    # 写入日志信息到日志文件
    echo "$log_timestamp [$log_pid] $log_level $log_content" >> $log_file

    # 检查日志文件大小，这里使用 wc -c 命令结合输入重定向获取文件的大小
    local log_file_size=$(wc -c < $log_file)
    # 另一种获取文件大小的写法
    # log_file_size=`ls -l $log_file | awk '{ print $5}'`

    if [ "$log_file_size" -gt "$max_size" ]; then
        echo "超过最大的 $max_size 字节，重命名并压缩、备份日志文件"
        echo "日志文件超过了 $max_size 字节，当前大小为: $log_file_size"
        local log_backup="$log_file.$log_seq"
        log_seq=$((log_seq + 1))
        echo "备份日志名称: $log_backup"
        mv "$log_file" "$log_backup"
        tar -cjf "$log_backup.tar.bz2" $log_backup
        echo "压缩完成，名称: $log_backup.tar.bz2"
        mv $log_backup.tar.bz2 $log_dir
        echo "删除备份文件"
        rm $log_backup
        # 向日志文件覆盖写入空内容，以清空文件
        echo "" > $log_file
    fi
}

# 测试log函数，相同日志内容重复调用10次日志接口，会生成 11 份日志压缩包
# 因为重复10次生成的日志超过1024*11字节
for i in {1..10}
do
    log 'INFO' 'User "john_doe" logged in from 9.67.116.99:0.'
    log 'Error' 'Invalid phone number format detected. Phone number: +8615551234567.'
    log 'WARNING' 'Potential security threat detected from IP address 192.168.1.100. User: "admin".'
    log 'INFO' 'User "jane_smith" updated email address to "jane.smith@example.com".'
    log 'ERROR' 'User "jane_smith" failed to changed password to smith_654321.'
    log 'INFO' 'User "john_doe" initiated password 12345678 reset request. Email: john.doe@example.com.'
    log 'WARNING' 'Unusual_activity detected for user "jane_smith". Phone number: +8613329876543.'
    log 'ERROR' 'ai User "joe_bloggs" is passing deactivated account in 939.222.12.0.'
    log 'INFO' 'User "admin" updated profile information. but the phone number is valid : 10008675309'
    log 'ERROR' 'pam_unix(su:auth): authentication failure; logname=kieran uid=1000 euid=0 tty=/dev/pts/0 ruser=kieran rhost=  user=root'

done