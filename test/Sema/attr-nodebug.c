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

begin_decl_stmt
name|void
name|b
argument_list|(
name|int
name|p
name|__attribute__
argument_list|(
operator|(
name|nodebug
operator|)
argument_list|)
argument_list|)
block|{
comment|// expected-warning {{'nodebug' attribute only applies to variables and functions}}
name|int
name|b
name|__attribute__
argument_list|(
operator|(
name|nodebug
operator|)
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

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

