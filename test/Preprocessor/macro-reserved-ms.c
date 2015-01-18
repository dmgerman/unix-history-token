begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -fms-extensions -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_define
define|#
directive|define
name|inline
value|_inline
end_define

begin_undef
undef|#
directive|undef
name|inline
end_undef

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

end_unit

