begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -E -frewrite-includes -I %S/Inputs %s | FileCheck %s --check-prefix=GNU
end_comment

begin_comment
comment|// RUN: %clang_cc1 -E -frewrite-includes -fuse-line-directives -I %S/Inputs %s | FileCheck %s --check-prefix=LINE
end_comment

begin_include
include|#
directive|include
file|"test.h"
end_include

begin_function
name|int
name|f
parameter_list|()
block|{
return|return
name|x
return|;
block|}
end_function

begin_include
include|#
directive|include
file|"empty.h"
end_include

begin_comment
comment|// GNU: {{^}}# 1 "{{.*}}rewrite-includes-line-markers.c"
end_comment

begin_comment
comment|// GNU: {{^}}#include "test.h"
end_comment

begin_comment
comment|// GNU: {{^}}# 1 "{{.*}}test.h"
end_comment

begin_comment
comment|// GNU: {{^}}#include "test2.h"
end_comment

begin_comment
comment|// GNU: {{^}}# 1 "{{.*}}test2.h"
end_comment

begin_comment
comment|// GNU: {{^}}int x;
end_comment

begin_comment
comment|// GNU: {{^}}# 4 "{{.*}}rewrite-includes-line-markers.c" 2
end_comment

begin_comment
comment|// GNU: {{^}}int f() { return x; }
end_comment

begin_comment
comment|// GNU: {{^}}
end_comment

begin_comment
comment|// GNU: {{^}}# 1 "{{.*}}empty.h" 1
end_comment

begin_comment
comment|// GNU: {{^}}# 7 "{{.*}}rewrite-includes-line-markers.c" 2
end_comment

begin_comment
comment|// LINE: {{^}}#line 1 "{{.*}}rewrite-includes-line-markers.c"
end_comment

begin_comment
comment|// LINE: {{^}}#include "test.h"
end_comment

begin_comment
comment|// LINE: {{^}}#line 1 "{{.*}}test.h"
end_comment

begin_comment
comment|// LINE: {{^}}#include "test2.h"
end_comment

begin_comment
comment|// LINE: {{^}}#line 1 "{{.*}}test2.h"
end_comment

begin_comment
comment|// LINE: {{^}}int x;
end_comment

begin_comment
comment|// LINE: {{^}}#line 4 "{{.*}}rewrite-includes-line-markers.c"
end_comment

begin_comment
comment|// LINE: {{^}}int f() { return x; }
end_comment

begin_comment
comment|// LINE: {{^}}
end_comment

begin_comment
comment|// LINE: {{^}}#line 1 "{{.*}}empty.h"
end_comment

begin_comment
comment|// LINE: {{^}}#line 7 "{{.*}}rewrite-includes-line-markers.c"
end_comment

end_unit

