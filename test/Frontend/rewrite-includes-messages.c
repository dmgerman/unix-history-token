begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -frewrite-includes %s -I%S/Inputs/ | %clang_cc1 -Wall -fsyntax-only -Wunused-macros -x c - 2>&1> %t.1
end_comment

begin_comment
comment|// RUN: %clang_cc1 -I%S/Inputs/ -Wall -Wunused-macros -fsyntax-only %s 2>&1> %t.2
end_comment

begin_comment
comment|// RUN: diff %t.1 %t.2 -u
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_include
include|#
directive|include
file|"rewrite-includes-messages.h"
end_include

begin_define
define|#
directive|define
name|UNUSED_MACRO
end_define

end_unit

