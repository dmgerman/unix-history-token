begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fno-builtin -O1 -S -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fno-builtin-memset -O1 -S -o - %s | FileCheck -check-prefix=MEMSET %s
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
comment|// CHECK: __strcpy_chk
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
comment|// MEMSET-LABEL: PR4941:
comment|// MEMSET-NOT: memset
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

