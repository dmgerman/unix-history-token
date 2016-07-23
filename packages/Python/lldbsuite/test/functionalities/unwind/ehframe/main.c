begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function
name|void
name|func
parameter_list|()
block|{
asm|__asm__ ( 		"pushq $0x10;" 		".cfi_def_cfa_offset 16;" 		"jmp label;" 		"movq $0x48, %rax;" "label: subq $0x38, %rax;" 		"movq $0x48, %rcx;" 		"movq $0x48, %rdx;" 		"movq $0x48, %rax;" 		"popq %rax;" 	);
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
specifier|const
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|func
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

