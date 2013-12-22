begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"truncation.c.h"
end_include

begin_comment
comment|/* foo */
end_comment

begin_struct_decl
struct_decl|struct
end_struct_decl

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -code-completion-at=%s.h:4:8 -o - %s | FileCheck -check-prefix=CHECK-CC1 %s
end_comment

begin_comment
comment|// CHECK-CC1: X
end_comment

begin_comment
comment|// CHECK-CC1-NEXT: Y
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -code-completion-at=%s:5:8 -o - %s | FileCheck -check-prefix=CHECK-CC2 %s
end_comment

begin_comment
comment|// CHECK-CC2: X
end_comment

begin_comment
comment|// CHECK-CC2: Xa
end_comment

begin_comment
comment|// CHECK-CC2: Y
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -code-completion-at=%s:3:3 -o - %s
end_comment

end_unit

