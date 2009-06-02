begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Header for the PCH test asm.c
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
asm|asm ("foo\n" : : "a" (i + 2));
asm|asm ("foo\n" : [symbolic_name] "=a" (i) : "[symbolic_name]" (i));
block|}
end_function

begin_function
name|void
name|clobbers
parameter_list|()
block|{
asm|asm ("nop" : : : "ax", "#ax", "%ax");
asm|asm ("nop" : : : "eax", "rax", "ah", "al");
asm|asm ("nop" : : : "0", "%0", "#0");
block|}
end_function

end_unit

