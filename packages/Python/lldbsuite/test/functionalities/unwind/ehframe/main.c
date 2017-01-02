begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function
name|void
name|func
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|__mips__
asm|__asm__ ( 		"pushq $0x10;" 		".cfi_def_cfa_offset 16;" 		"jmp label;" 		"movq $0x48, %rax;" "label: subq $0x38, %rax;" 		"movq $0x48, %rcx;" 		"movq $0x48, %rdx;" 		"movq $0x48, %rax;" 		"popq %rax;" 	);
elif|#
directive|elif
name|__mips64
asm|__asm__ (     "daddiu $sp,$sp,-16;"     ".cfi_def_cfa_offset 16;"     "sd $ra,8($sp);"     ".cfi_offset 31, -8;"     "daddiu $ra,$zero,0;"     "ld $ra,8($sp);"     "daddiu $sp, $sp,16;"     ".cfi_restore 31;"     ".cfi_def_cfa_offset 0;"    );
else|#
directive|else
comment|// For MIPS32
asm|__asm__ (     "addiu $sp,$sp,-8;"     ".cfi_def_cfa_offset 8;"     "sw $ra,4($sp);"     ".cfi_offset 31, -4;"     "addiu $ra,$zero,0;"     "lw $ra,4($sp);"     "addiu $sp,$sp,8;"     ".cfi_restore 31;"     ".cfi_def_cfa_offset 0;"    );
endif|#
directive|endif
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

