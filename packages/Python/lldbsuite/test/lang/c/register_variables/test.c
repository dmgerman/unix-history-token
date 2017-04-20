begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|||
name|defined
argument_list|(
name|__aarch64__
argument_list|)
end_if

begin_comment
comment|// Clang does not accept regparm attribute on these platforms.
end_comment

begin_comment
comment|// Fortunately, the default calling convention passes arguments in registers
end_comment

begin_comment
comment|// anyway.
end_comment

begin_define
define|#
directive|define
name|REGPARM
parameter_list|(
name|N
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REGPARM
parameter_list|(
name|N
parameter_list|)
value|__attribute__((regparm(N)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|bar
block|{
name|int
name|m1
decl_stmt|;
name|int
name|m2
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|f1
parameter_list|(
name|int
name|a
parameter_list|,
name|struct
name|bar
modifier|*
name|b
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noinline
end_function_decl

begin_expr_stmt
unit|))
name|REGPARM
argument_list|(
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|f1
parameter_list|(
name|int
name|a
parameter_list|,
name|struct
name|bar
modifier|*
name|b
parameter_list|)
block|{
name|b
operator|->
name|m2
operator|=
name|b
operator|->
name|m1
operator|+
name|a
expr_stmt|;
comment|// set breakpoint here
block|}
end_function

begin_function_decl
name|void
name|f2
parameter_list|(
name|struct
name|bar
modifier|*
name|b
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(noinline
end_function_decl

begin_expr_stmt
unit|))
name|REGPARM
argument_list|(
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|f2
parameter_list|(
name|struct
name|bar
modifier|*
name|b
parameter_list|)
block|{
name|int
name|c
init|=
name|b
operator|->
name|m2
decl_stmt|;
name|printf
argument_list|(
literal|"%d\n"
argument_list|,
name|c
argument_list|)
expr_stmt|;
comment|// set breakpoint here
block|}
end_function

begin_function_decl
name|float
name|f3
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(noinline
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function
name|float
name|f3
parameter_list|()
block|{
return|return
literal|3.14f
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|struct
name|bar
name|myBar
init|=
block|{
literal|3
block|,
literal|4
block|}
decl_stmt|;
name|f1
argument_list|(
literal|2
argument_list|,
operator|&
name|myBar
argument_list|)
expr_stmt|;
name|f2
argument_list|(
operator|&
name|myBar
argument_list|)
expr_stmt|;
name|float
name|f
init|=
name|f3
argument_list|()
decl_stmt|;
name|printf
argument_list|(
literal|"%f\n"
argument_list|,
name|f
argument_list|)
expr_stmt|;
comment|// set breakpoint here
return|return
literal|0
return|;
block|}
end_function

end_unit

