begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|INLINE
value|inline __attribute__((always_inline))
end_define

begin_function
name|int
name|func_not_inlined
parameter_list|(
name|void
parameter_list|)
block|{
name|printf
argument_list|(
literal|"Called func_not_inlined.\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|INLINE
name|int
name|func_inlined
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
name|int
name|func_inline_call_count
init|=
literal|0
decl_stmt|;
name|printf
argument_list|(
literal|"Called func_inlined.\n"
argument_list|)
expr_stmt|;
operator|++
name|func_inline_call_count
expr_stmt|;
name|printf
argument_list|(
literal|"Returning func_inlined call count: %d.\n"
argument_list|,
name|func_inline_call_count
argument_list|)
expr_stmt|;
return|return
name|func_inline_call_count
return|;
comment|// Set break point at this line.
block|}
end_function

begin_function_decl
specifier|extern
name|int
name|func_inlined
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|printf
argument_list|(
literal|"Starting...\n"
argument_list|)
expr_stmt|;
name|int
function_decl|(
modifier|*
name|func_ptr
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|func_ptr
operator|=
name|func_inlined
expr_stmt|;
name|int
name|a
init|=
name|func_inlined
argument_list|()
decl_stmt|;
name|printf
argument_list|(
literal|"First call to func_inlined() returns: %d.\n"
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|func_not_inlined
argument_list|()
expr_stmt|;
name|func_ptr
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"Last call to func_inlined() returns: %d.\n"
argument_list|,
name|func_inlined
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

