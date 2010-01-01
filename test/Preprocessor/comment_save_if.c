begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -E -CC -pedantic 2>&1 | grep -v '^/' | not grep warning
end_comment

begin_if
if|#
directive|if
literal|1
end_if

begin_comment
comment|/*bar */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*foo*/
end_comment

end_unit

