begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: not clang-cc %s -std=c89 -pedantic-errors  */
end_comment

begin_comment
comment|/* We can't put expected-warning lines on #if lines. */
end_comment

begin_if
if|#
directive|if
literal|1LL
end_if

begin_comment
comment|/* expected-warning {{long long}} */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

