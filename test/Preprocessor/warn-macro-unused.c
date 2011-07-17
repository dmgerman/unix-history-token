begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -Wunused-macros -Dfoo -Dfoo -verify
end_comment

begin_include
include|#
directive|include
file|"warn-macro-unused.h"
end_include

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

begin_comment
comment|// rdar://9745065
end_comment

begin_undef
undef|#
directive|undef
name|unused_from_header
end_undef

begin_comment
comment|// no warning
end_comment

end_unit

