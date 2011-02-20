begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -x c -fblocks -fms-extensions -rewrite-objc %s -o %t-rw.cpp
end_comment

begin_comment
comment|// RUN: FileCheck --input-file=%t-rw.cpp %s
end_comment

begin_comment
comment|// rdar://9006279
end_comment

begin_function
name|void
name|q
parameter_list|(
name|void
function_decl|(
modifier|^
name|p
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
block|{
name|p
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|f
parameter_list|()
block|{
specifier|__block
name|char
name|BYREF_VAR_CHECK
init|=
literal|'a'
decl_stmt|;
specifier|__block
name|char
name|d
init|=
literal|'d'
decl_stmt|;
name|q
argument_list|(
lambda|^
block|{
name|q
argument_list|(
lambda|^
block|{
specifier|__block
name|char
name|e
init|=
literal|'e'
decl_stmt|;
name|char
name|l
init|=
literal|'l'
decl_stmt|;
name|BYREF_VAR_CHECK
operator|=
literal|'b'
expr_stmt|;
name|d
operator|=
literal|'d'
expr_stmt|;
name|q
argument_list|(
lambda|^
block|{
name|e
operator|=
literal|'1'
expr_stmt|;
name|BYREF_VAR_CHECK
operator|=
literal|'2'
expr_stmt|;
name|d
operator|=
literal|'3'
expr_stmt|;
block|}
argument_list|)
expr_stmt|;
block|}
argument_list|)
expr_stmt|;
block|}
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|f
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK 2: (__Block_byref_BYREF_VAR_CHECK_0 *)BYREF_VAR_CHECK
end_comment

begin_comment
comment|// CHECK: (__Block_byref_BYREF_VAR_CHECK_0 *)&BYREF_VAR_CHECK
end_comment

begin_comment
comment|// CHECK: (struct __Block_byref_BYREF_VAR_CHECK_0 *)&BYREF_VAR_CHECK, (struct __Block_byref_d_1 *)&d, 570425344));
end_comment

end_unit

