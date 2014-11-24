begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wdocumentation -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wdocumentation -fdiagnostics-parseable-fixits %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: cp %s %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wdocumentation -fixit %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -Wdocumentation -Werror %t
end_comment

begin_struct
struct|struct
name|a
block|{
name|int
name|x
decl_stmt|;
comment|//< comment // expected-warning {{not a Doxygen trailing comment}}
name|int
name|y
decl_stmt|;
comment|/*< comment */
comment|// expected-warning {{not a Doxygen trailing comment}}
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-4]]:10-[[@LINE-4]]:13}:"///<"
end_comment

begin_comment
comment|// CHECK: fix-it:"{{.*}}":{[[@LINE-4]]:10-[[@LINE-4]]:13}:"/**<"
end_comment

end_unit

