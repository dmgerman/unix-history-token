begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: %clang_cc1 %s -std=c89 -pedantic-errors -verify  */
end_comment

begin_if
if|#
directive|if
literal|1LL
end_if

begin_comment
comment|/* expected-error {{long long}} */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

