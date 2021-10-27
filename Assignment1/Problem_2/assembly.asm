extern funcC
section .text
	global modifyStack

modifyStack:
	lea r10, [rel funcC]
	push r10
	ret