#!/bin/bash
file_version=1
log() {
    name=$1
    birthday=$2
    file_name='membership'
    
    max_size=1024
    echo "$(date +'%Y-%m-%d %H:%M:%S') - $name: $birthday" >> $file_name.$file_version
    echo "name: $file_name.$file_version"
    local file_size=$(wc -c < $file_name.$file_version)
    #log_file_size=`ls -l $log_file | awk '{ print $5}'`
    echo "file size:$file_size"
    if [ "$file_size" -gt "$max_size" ];then
        file_version=$((file_version+1))
        echo "file version:$file_version"
        mv $file_name.$((file_version-1)) $file_name.$((file_version-1)).backup
        tar -cjf $file_name.$((file_version-1)).backup.tar.bz2 $file_name.$((file_version-1)).backup
        rm $file_name.$((file_version-1)).backup
        echo "backup file created: $file_name.$((file_version-1)).backup.tar.bz2"

    fi

}

while true; 
do
    log 'wujw' '1996-5-30'
    log 'wujw' '1996-5-30'
    log 'wujw' '1996-5-30'
    log 'wujw' '1996-5-30'
    log 'wujw' '1996-5-30'
    log 'wujw' '1996-5-30'
    sleep 1
done
