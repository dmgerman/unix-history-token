begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -fblocks -analyzer-checker=core -verify %s
end_comment

begin_comment
comment|// For now, don't inline varargs.
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|int
modifier|*
name|x
parameter_list|,
modifier|...
parameter_list|)
block|{
operator|*
name|x
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_function
name|void
name|bar
parameter_list|()
block|{
name|foo
argument_list|(
literal|0
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// For now, don't inline vararg blocks.
end_comment

begin_function_decl
name|void
function_decl|(
modifier|^
name|baz
function_decl|)
parameter_list|(
name|int
modifier|*
name|x
parameter_list|,
modifier|...
parameter_list|)
init|=
lambda|^
parameter_list|(
name|int
modifier|*
name|x
parameter_list|,
modifier|...
parameter_list|)
block|{
operator|*
name|x
operator|=
literal|1
function_decl|;
end_function_decl

begin_function
unit|};
name|void
name|taz
parameter_list|()
block|{
name|baz
argument_list|(
literal|0
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// For now, don't inline global blocks.
end_comment

begin_function_decl
name|void
function_decl|(
modifier|^
name|qux
function_decl|)
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
init|=
lambda|^
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
operator|*
name|p
operator|=
literal|1
function_decl|;
end_function_decl

begin_function
unit|};
name|void
name|test_qux
parameter_list|()
block|{
name|qux
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|test_analyzer_is_running
parameter_list|()
block|{
name|int
modifier|*
name|p
init|=
literal|0
decl_stmt|;
operator|*
name|p
operator|=
literal|0xDEADBEEF
expr_stmt|;
comment|// expected-warning {{null}}
block|}
end_function

end_unit

