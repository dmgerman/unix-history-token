begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: mkdir -p %t
end_comment

begin_comment
comment|// RUN: echo 'int yyy = 42;'> %t/a.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s -I%t  -verify
end_comment

begin_comment
comment|// expected-error@a.h:1 {{redefinition of 'yyy'}}
end_comment

begin_comment
comment|// expected-note@a.h:1 {{unguarded header; consider using #ifdef guards or #pragma once}}
end_comment

begin_comment
comment|// expected-note-re@redefinition-same-header.c:11 {{'{{.*}}a.h' included multiple times, additional include site here}}
end_comment

begin_comment
comment|// expected-note-re@redefinition-same-header.c:12 {{'{{.*}}a.h' included multiple times, additional include site here}}
end_comment

begin_include
include|#
directive|include
file|"a.h"
end_include

begin_include
include|#
directive|include
file|"a.h"
end_include

begin_function
name|int
name|foo
parameter_list|()
block|{
return|return
name|yyy
return|;
block|}
end_function

end_unit

