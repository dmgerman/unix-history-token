begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_function_decl
name|void
name|f0
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|introduced
init|=
literal|10.4
parameter_list|,
name|deprecated
init|=
literal|10.2
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning{{feature cannot be deprecated in Mac OS X version 10.2 before it was introduced in version 10.4; attribute ignored}}
end_comment

begin_function_decl
name|void
name|f1
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|ios
parameter_list|,
name|obsoleted
init|=
literal|2.1
parameter_list|,
name|deprecated
init|=
literal|3.0
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning{{feature cannot be obsoleted in iOS version 2.1 before it was deprecated in version 3.0; attribute ignored}}
end_comment

begin_function_decl
name|void
name|f2
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|otheros
parameter_list|,
name|introduced
init|=
literal|2.2
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning{{unknown platform 'otheros' in availability macro}}
end_comment

end_unit

