begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -E -frewrite-includes -I %S/Inputs %s -o - | %clang -fsyntax-only -Xclang -verify -x c -
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_include
include|#
directive|include
file|"rewrite-includes-bom.h"
end_include

end_unit

