begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 -E -frewrite-includes %s -o - 2>&1 | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|"this file does not exist.foo"
end_include

begin_include
include|#
directive|include
file|"this file also does not exist.foo"
end_include

begin_label
name|CHECK
label|:
end_label

begin_decl_stmt
name|fatal
name|error
range|:
block|{
block|{
operator|.*
block|}
block|}
name|file
name|not
name|found
end_decl_stmt

end_unit

