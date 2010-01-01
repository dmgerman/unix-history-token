begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s 2>&1 | not grep "warning\|error"
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|// Shouldn't get warnings here.
end_comment

begin_comment
unit|??( ??)
comment|// Should not get an error here.
end_comment

begin_endif
unit|` ` ` `
endif|#
directive|endif
end_endif

end_unit

