# 定义一个普通数组，存储一组数字
BEGIN {
    # 数组可以随时添加元素，而无需提前定义大小
    # awk 会动态地调整数组大小
    numbers[1] = 10
    numbers[2] = 20
    numbers[3] = 30
    numbers[4] = 40
}

# 注意！输入文件有几行，这段代码就会执行几次
{
    numbers[2] += 1
    numbers[3] += 1
}

# 在处理结束后打印数组元素
END {
    for (i in numbers) {
        print "第", i, "个元素的值为:", numbers[i]
    }
}
