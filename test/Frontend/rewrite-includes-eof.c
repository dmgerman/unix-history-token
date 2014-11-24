begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -frewrite-includes -I %S/Inputs %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// Note: there's no newline at the end of this C file.
end_comment

begin_include
include|#
directive|include
file|"rewrite-includes-bom.h"
end_include

end_unit

