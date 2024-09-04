BEGIN {
	print "start......"
	print "==========================="
}

{
	if($4 == "ERROR"){
		print "发现错误： ", $0;	
	} else {
		print "正常日志： ", $0;
	}
}

END {
	print "==========================="
	print "文件处理完成"	
}
