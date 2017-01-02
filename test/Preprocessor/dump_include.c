begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -w -E -dI -isystem %S -imacros %S/dump_include.h %s -o - | FileCheck %s
end_comment

begin_comment
comment|// CHECK: {{^}}#__include_macros "{{.*}}dump_
end_comment

begin_comment
comment|// CHECK: {{^}}#include<dump_
end_comment

begin_comment
comment|// CHECK: {{^}}#include "dump_
end_comment

begin_comment
comment|// CHECK: {{^}}#include_next "dump_
end_comment

begin_comment
comment|// See also `dump_import.m` which tests the `#import` directive with `-dI`.
end_comment

begin_include
include|#
directive|include
file|<dump_include.h>
end_include

begin_include
include|#
directive|include
file|"dump_include.h"
end_include

begin_empty
empty|#include_next "dump_include.h"
end_empty

end_unit

