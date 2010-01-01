begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E %s | grep bark
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_else
unit|blah
else|#\
directive|else
end_else

begin_macro
name|bark
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

