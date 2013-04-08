begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E %s -o /dev/null
end_comment

begin_comment
comment|// Note: This file deliberately contains invalid UTF-8. Please do not fix!
end_comment

begin_decl_stmt
specifier|extern
name|int
name|x
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{source file is not valid UTF-8}}
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|// Don't warn about bad UTF-8 in raw lexing mode.
end_comment

begin_endif
unit|extern int x;
endif|#
directive|endif
end_endif

begin_comment
comment|// Don't warn about bad UTF-8 in preprocessor directives.
end_comment

begin_define
define|#
directive|define
name|x82
value|
end_define

begin_pragma
pragma|#
directive|pragma
name|mark
name|
end_pragma

end_unit

