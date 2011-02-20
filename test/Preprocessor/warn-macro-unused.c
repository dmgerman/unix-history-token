begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -Wunused-macros -Dfoo -Dfoo -verify
end_comment

begin_define
define|#
directive|define
name|unused
end_define

begin_comment
comment|// expected-warning {{macro is not used}}
end_comment

begin_define
define|#
directive|define
name|unused
end_define

begin_macro
name|unused
end_macro

end_unit

