begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: systemz-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-cpu zEC12 -triple s390x-unknown-unknown \
end_comment

begin_comment
comment|// RUN: -Wall -Wno-unused -Werror -fsyntax-only -verify %s
end_comment

begin_function
name|void
name|test1
parameter_list|(
name|void
parameter_list|)
block|{
name|__builtin_tabort
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error {{invalid transaction abort code}}
name|__builtin_tabort
argument_list|(
literal|255
argument_list|)
expr_stmt|;
comment|// expected-error {{invalid transaction abort code}}
block|}
end_function

end_unit

