# 定义关联数组
BEGIN {
    # 通过直接赋值创建关联数组元素
    ages["john"] = 30
    ages["jane"] = 25
    ages["alice"] = 40
}

# 遍历关联数组
END {
    # 使用 for-in 循环遍历关联数组
    for (user in ages) {
        print "用户名:", user, "- 年龄:", ages[user]
    }
}
