begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -pedantic-errors -verify
end_comment

begin_comment
comment|// PR2045
end_comment

begin_define
define|#
directive|define
name|b
end_define

begin_comment
comment|/* expected-error {{extra tokens at end of #undef directive}} */
end_comment

begin_undef
undef|#
directive|undef
name|a
name|b
end_undef

end_unit

