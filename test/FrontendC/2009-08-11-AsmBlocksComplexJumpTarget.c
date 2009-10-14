begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -fasm-blocks -S -o - | grep {\\\*1192}
end_comment

begin_comment
comment|// Complicated expression as jump target
end_comment

begin_comment
comment|// XFAIL: *
end_comment

begin_comment
comment|// XTARGET: x86,i386,i686
end_comment

begin_function
name|asm
name|void
name|Method3
parameter_list|()
block|{
name|mov
name|eax
decl_stmt|,[
name|esp
decl|+4]
name|jmp
index|[
name|eax
operator|+
operator|(
literal|299
operator|-
literal|1
operator|)
operator|*
literal|4
index|]
block|}
end_function

end_unit

