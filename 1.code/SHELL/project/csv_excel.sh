#!/bin/bash

# 检查是否传递了 CSV 文件路径
if [ -z "$1" ]; then
    echo "请提供 CSV 文件路径。"
    exit 1
fi

# 获取 CSV 文件路径
csv_file="$1"

# 确定 Excel 文件的输出路径
excel_file="${csv_file%.csv}.xlsx"

# 调用 Python 进行 CSV 到 Excel 的转换
python3 - <<EOF
import pandas as pd

# 读取 CSV 文件
df = pd.read_csv("$csv_file")

# 将 CSV 文件保存为 Excel 文件
df.to_excel("$excel_file", index=False)
EOF

echo "转换完成: $excel_file"
