begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -Wall -ffreestanding -fsyntax-only -fwrapv -verify %s
end_comment

begin_function
name|int
name|test
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
name|i
operator|=
operator|-
literal|1
operator|<<
literal|1
expr_stmt|;
comment|// no-warning
return|return
name|i
return|;
block|}
end_function

begin_comment
comment|// expected-no-diagnostics
end_comment

end_unit

