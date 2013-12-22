begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wall -pedantic -verify %s
end_comment

begin_comment
comment|// RUN: cp %s %t
end_comment

begin_comment
comment|// RUN: cp %S/fixit-include.h %T
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only -fixit %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -Wall -pedantic %t
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -fsyntax-only -fdiagnostics-parseable-fixits %s 2>&1 | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<fixit-include.h>
end_include

begin_comment
comment|// expected-error {{'fixit-include.h' file not found with<angled> include; use "quotes" instead}}
end_comment

begin_comment
comment|// CHECK: fix-it:{{.*}}:{8:10-8:27}
end_comment

begin_pragma
pragma|#
directive|pragma
name|does_not_exist
end_pragma

begin_comment
comment|// expected-warning {{unknown pragma ignored}}
end_comment

begin_function
name|int
name|main
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

