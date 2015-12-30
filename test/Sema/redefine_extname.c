begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple=x86_64-unknown-linux -Wpragmas -verify %s
end_comment

begin_comment
comment|// Check that pragma redefine_extname applies to external declarations only.
end_comment

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|foo_static
name|bar_static
end_pragma

begin_function
specifier|static
name|int
name|foo_static
parameter_list|()
block|{
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|// expected-warning {{#pragma redefine_extname is applicable to external C declarations only; not applied to function 'foo_static'}}
end_comment

end_unit

