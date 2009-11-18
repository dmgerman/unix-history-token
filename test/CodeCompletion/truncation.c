begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"truncation.c.h"
end_include

begin_struct_decl
struct_decl|struct
end_struct_decl

begin_comment
comment|// RUN: clang-cc -fsyntax-only -code-completion-at=%s.h:4:8 -o - %s | FileCheck -check-prefix=CC1 %s
end_comment

begin_comment
comment|// CHECK-CC1: X : 1
end_comment

begin_comment
comment|// CHECK-CC1-NEXT: Y : 1
end_comment

begin_comment
comment|// RUN: clang-cc -fsyntax-only -code-completion-at=%s:3:8 -o - %s | FileCheck -check-prefix=CC2 %s
end_comment

begin_comment
comment|// CHECK-CC2: X : 1
end_comment

begin_comment
comment|// CHECK-CC2: Xa : 1
end_comment

begin_comment
comment|// CHECK-CC2: Y : 1
end_comment

end_unit

