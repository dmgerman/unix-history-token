begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test this without pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include %S/Inputs/pragma-once.h -fsyntax-only -verify %s
end_comment

begin_comment
comment|// Test with pch.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t %S/Inputs/pragma-once.h
end_comment

begin_comment
comment|// RUN: %clang_cc1 -include-pch %t -fsyntax-only -verify %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// Including "pragma-once.h" twice, to verify the 'once' aspect is honored.
end_comment

begin_include
include|#
directive|include
file|"Inputs/pragma-once.h"
end_include

begin_include
include|#
directive|include
file|"Inputs/pragma-once.h"
end_include

begin_function
name|int
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

end_unit

