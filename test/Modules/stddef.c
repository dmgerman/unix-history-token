begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -fmodules-cache-path=%t -I%S/Inputs/StdDef %s -verify -fno-modules-error-recovery
end_comment

begin_include
include|#
directive|include
file|"ptrdiff_t.h"
end_include

begin_decl_stmt
name|ptrdiff_t
name|pdt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|st
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{must be imported}}
end_comment

begin_comment
comment|// expected-note@stddef.h:* {{previous}}
end_comment

begin_include
include|#
directive|include
file|"include_again.h"
end_include

begin_decl_stmt
name|size_t
name|st2
decl_stmt|;
end_decl_stmt

end_unit

