#!/bin/bash

# 引入日志函数
. 4_3_backup.sh

# 设置监控文件路径和关键字
LOG_FILE="/var/log/auth.log"
KEYWORD="Accepted password"
echo "start......"
# 检查日志文件是否存在
if [ ! -f "$LOG_FILE" ]; then
    echo "日志文件 $LOG_FILE 不存在"
    exit 1
fi

# 监视文件
tail -n0 -f "$LOG_FILE" | while read line 
do
    echo "line---:$line" # 打印新增行
    # -q 使 grep 命令在找到子串时不输出任何内容，而只是返回退出状态
    if echo $line | grep -q "$KEYWORD"; then
        # 将最终 awk 输出的内容通过命令替换赋值给 info
        info=$(echo $line | awk '{print "登录人:" $9 " 时间:" $1 " " $2 " " $3 " IP:" $11 ",端 口:" $13}')
        # echo $info
        log "INFO" "$info"
    fi
done