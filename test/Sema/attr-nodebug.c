begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only
end_comment

begin_decl_stmt
name|int
name|a
name|__attribute__
argument_list|(
operator|(
name|nodebug
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|b
parameter_list|()
block|{
name|int
name|b
name|__attribute__
argument_list|(
operator|(
name|nodebug
operator|)
argument_list|)
decl_stmt|;
comment|// expected-warning {{'nodebug' only applies to variables with static storage duration and functions}}
block|}
end_function

begin_function_decl
name|void
name|t1
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(nodebug
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|t2
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(nodebug
parameter_list|(
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'nodebug' attribute takes no arguments}}
end_comment

end_unit

