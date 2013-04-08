begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only -pedantic
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only -x c++ -pedantic
end_comment

begin_comment
comment|// This file contains UTF-8; please do not fix!
end_comment

begin_extern
extern|extern void \u00FCber(int
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern void \U000000FCber(int
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|// redeclaration, no warning
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_comment
comment|// expected-note@-2 + {{candidate function not viable}}
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|// expected-note@-4 + {{declared here}}
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|goodCalls
parameter_list|()
block|{
operator|\
name|u00FCber
argument_list|(
literal|0
argument_list|)
expr_stmt|;
operator|\
name|u00fcber
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|Ã¼ber
argument_list|(
literal|2
argument_list|)
expr_stmt|;
operator|\
name|U000000FCber
argument_list|(
literal|3
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|badCalls
parameter_list|()
block|{
operator|\
name|u00FCber
argument_list|(
literal|0.5
argument_list|)
expr_stmt|;
comment|// expected-warning{{implicit conversion from 'double' to 'int'}}
operator|\
name|u00fcber
operator|=
literal|0
expr_stmt|;
comment|// expected-error{{non-object type 'void (int)' is not assignable}}
name|Ã¼ber
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
operator|\
name|U000000FCber
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|__cplusplus
comment|// expected-error@-3 {{no matching function}}
comment|// expected-error@-3 {{no matching function}}
else|#
directive|else
comment|// expected-error@-6 {{too many arguments to function call, expected 1, have 2}}
comment|// expected-error@-6 {{too few arguments to function call, expected 1, have 0}}
endif|#
directive|endif
block|}
end_function

end_unit

