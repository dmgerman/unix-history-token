begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_if
if|#
directive|if
operator|!
name|__has_feature
argument_list|(
name|attribute_availability
argument_list|)
end_if

begin_error
error|#
directive|error
literal|'availability'
error|attribute is not available
end_error

begin_endif
endif|#
directive|endif
end_endif

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
literal|10.2
parameter_list|,
name|deprecated
init|=
literal|10.4
parameter_list|,
name|obsoleted
init|=
literal|10.6
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|f1
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|deprecated
init|=
literal|10.4
parameter_list|,
name|introduced
init|=
literal|10.2
parameter_list|,
name|obsoleted
init|=
literal|10.6
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|f2
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|ios
parameter_list|,
name|deprecated
init|=
literal|10.4.7
parameter_list|,
name|introduced
init|=
literal|10
parameter_list|,
name|obsoleted
init|=
literal|10.6
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|f3
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|ios
parameter_list|,
name|deprecated
init|=
literal|10.4.7
parameter_list|,
name|introduced
init|=
literal|10
parameter_list|,
name|obsoleted
init|=
literal|10.6
parameter_list|,
name|introduced
init|=
literal|10.2
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{redundant 'introduced' availability change; only the last specified change will be used}}
end_comment

begin_function_decl
name|void
name|f4
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|introduced
init|=
literal|10.5
parameter_list|)
operator|,
function_decl|availability
parameter_list|(
name|ios
parameter_list|,
name|unavailable
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|f5
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|introduced
init|=
literal|10.5
parameter_list|)
operator|,
function_decl|availability
parameter_list|(
name|ios
parameter_list|,
name|unavailable
parameter_list|,
name|unavailable
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{redundant 'unavailable' availability change; only the last specified change will be used}}
end_comment

begin_function_decl
name|void
name|f6
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(availability
parameter_list|(
name|macosx
parameter_list|,
name|unavailable
parameter_list|,
name|introduced
init|=
literal|10.5
parameter_list|)
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning{{warning: 'unavailable' availability overrides all other availability information}}
end_comment

end_unit

