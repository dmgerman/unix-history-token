begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -fsyntax-only -iframework %S/Inputs %s -Xclang -verify
end_comment

begin_comment
comment|// RUN: %clang -fsyntax-only -isysroot %S -iframeworkwithsysroot /Inputs %s -Xclang -verify
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_include
include|#
directive|include
file|<TestFramework/TestFramework.h>
end_include

end_unit

