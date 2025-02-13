# 定义关联数组
BEGIN {
    # 字段分隔符改为 ,
    FS = ","
    printf "%-39s%-10s%-18s%-42s%-21s%-8s\n", "图书","版本","编号","作者","出版社","价格"
    printf "-------------------------------------------------------------------------------------------------------------------------------\n"
}

{
    printf "%-36s%-10s%-16s%-40s%-25s%-8s\n", $1, $2, $3, $4, $5, $6
    
    # 当变量作为数值使用时，默认初始值为 0, 可以不进行初始化
    total+=$6
    publishers[$5]++
}

END {
    printf "-------------------------------------------------------------------------------------------------------------------------------\n"
    
    printf "图书总价格:%10.2f \n", total
    printf "图书平均价:%10.2f \n", total/NR
    
    for (publisher in publishers) {
        print "出版商:", publisher", 图书数量：", publishers[publisher]
    }
}
