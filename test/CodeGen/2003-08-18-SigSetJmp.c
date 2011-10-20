begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin -emit-llvm %s  -o /dev/null
end_comment

begin_define
define|#
directive|define
name|_JBLEN
value|((9 * 2) + 3 + 16)
end_define

begin_typedef
typedef|typedef
name|int
name|sigjmp_buf
index|[
name|_JBLEN
operator|+
literal|1
index|]
typedef|;
end_typedef

begin_function_decl
name|int
name|sigsetjmp
parameter_list|(
name|sigjmp_buf
name|env
parameter_list|,
name|int
name|savemask
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|sigjmp_buf
name|B
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|foo
parameter_list|()
block|{
name|sigsetjmp
argument_list|(
name|B
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|bar
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

