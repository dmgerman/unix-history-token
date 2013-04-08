begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only %s 2>&1 | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|"macro_arg_slocentry_merge.h"
end_include

begin_comment
comment|// CHECK: macro_arg_slocentry_merge.h:7:19: error: unknown type name 'win'
end_comment

begin_comment
comment|// CHECK: macro_arg_slocentry_merge.h:5:16: note: expanded from macro 'WINDOW'
end_comment

begin_comment
comment|// CHECK: macro_arg_slocentry_merge.h:6:18: note: expanded from macro 'P_'
end_comment

end_unit

