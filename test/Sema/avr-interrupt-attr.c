begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple avr-unknown-unknown -verify -fsyntax-only
end_comment

begin_struct
struct|struct
name|a
block|{
name|int
name|b
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|a
name|test
name|__attribute__
argument_list|(
operator|(
name|interrupt
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'interrupt' attribute only applies to functions}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt(
literal|12
argument|))
argument_list|)
end_macro

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_comment
comment|// expected-error {{'interrupt' attribute takes no arguments}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(interrupt)
argument_list|)
end_macro

begin_function
name|void
name|food
parameter_list|()
block|{}
end_function

end_unit

