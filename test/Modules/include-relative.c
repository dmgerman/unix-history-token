begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: mkdir %t
end_comment

begin_comment
comment|// RUN: cp -r %S/Inputs/include-relative %t/include-relative
end_comment

begin_comment
comment|// RUN: cd %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fmodules -x c -verify -fmodules-cache-path=%t -I include-relative %s
end_comment

begin_comment
comment|// REQUIRES: shell
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_include
include|#
directive|include
file|"a.h"
end_include

begin_function
name|int
name|f
parameter_list|()
block|{
return|return
name|n
return|;
block|}
end_function

end_unit

