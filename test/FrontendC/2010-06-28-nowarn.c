begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -m32 -fasm-blocks -o /dev/null
end_comment

begin_comment
comment|// This should not warn about unreferenced label. 7729514.
end_comment

begin_comment
comment|// XFAIL: *
end_comment

begin_comment
comment|// XTARGET: x86,i386,i686
end_comment

begin_function
name|void
name|quarterAsm
parameter_list|(
name|int
name|array
index|[]
parameter_list|,
name|int
name|len
parameter_list|)
block|{
asm|__asm
block|{
name|mov
name|esi
decl_stmt|,
name|array
decl_stmt|;
name|mov
name|ecx
decl_stmt|,
name|len
decl_stmt|;
name|shr
name|ecx
decl_stmt|, 2;
name|loop
label|:
name|movdqa
name|xmm0
decl_stmt|, [
name|esi
decl|]
decl_stmt|;
name|psrad
name|xmm0
decl_stmt|, 2;
name|movdqa
index|[
name|esi
index|]
operator|,
name|xmm0
expr_stmt|;
name|add
name|esi
decl_stmt|, 16;
name|sub
name|ecx
decl_stmt|, 1;
name|jnz
name|loop
decl_stmt|;
block|}
block|}
end_function

end_unit

