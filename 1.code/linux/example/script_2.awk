BEGIN {
	numbers[1] = 10
	numbers[2] = 20
	numbers[3] = 30
	numbers[4] = 40
}

{
	numbers[2] += 1
	numbers[3] += 1 
}

END {
	for(i in numbers) {
		print "第", i, "个元素的值为：", numbers[i]	
	}
}
