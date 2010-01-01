begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o %t
end_comment

begin_define
define|#
directive|define
name|CFSTR
value|__builtin___CFStringMakeConstantString
end_define

begin_function
name|void
name|f
parameter_list|()
block|{
name|CFSTR
argument_list|(
literal|"Hello, World!"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// rdar://6248329
end_comment

begin_decl_stmt
name|void
modifier|*
name|G
init|=
name|CFSTR
argument_list|(
literal|"yo joe"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|h
parameter_list|()
block|{
specifier|static
name|void
modifier|*
name|h
init|=
name|CFSTR
argument_list|(
literal|"Goodbye, World!"
argument_list|)
decl_stmt|;
block|}
end_function

end_unit

