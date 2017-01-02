begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-linux-gnu -O1 -S -o - %s | FileCheck -check-prefix=STRCPY -check-prefix=MEMSET %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-linux-gnu -fno-builtin -O1 -S -o - %s | FileCheck -check-prefix=NOSTRCPY -check-prefix=NOMEMSET %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-linux-gnu -fno-builtin-memset -O1 -S -o - %s | FileCheck -check-prefix=STRCPY -check-prefix=NOMEMSET %s
end_comment

begin_function
name|void
name|PR13497
parameter_list|()
block|{
name|char
name|content
index|[
literal|2
index|]
decl_stmt|;
comment|// make sure we don't optimize this call to strcpy()
comment|// STRCPY-NOT: __strcpy_chk
comment|// NOSTRCPY: __strcpy_chk
name|__builtin___strcpy_chk
argument_list|(
name|content
argument_list|,
literal|""
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|PR4941
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
block|{
comment|// Make sure we don't optimize this loop to a memset().
comment|// NOMEMSET-NOT: memset
comment|// MEMSET: memset
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|8192
condition|;
operator|++
name|i
control|)
name|s
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
end_function

end_unit

