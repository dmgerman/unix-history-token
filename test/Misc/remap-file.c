begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -remap-file "%s;%S/Inputs/remapped-file" -fsyntax-only %s 2>&1 | FileCheck -check-prefix=CHECK-EXIST %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -remap-file "%S/nonexistent.c;%S/Inputs/remapped-file" -fsyntax-only %S/nonexistent.c 2>&1 | FileCheck -check-prefix=CHECK-NONEXIST %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -remap-file "%S/nonexistent.c;%S/Inputs/remapped-file-2" -remap-file "%S/nonexistent.h;%S/Inputs/remapped-file-3" -fsyntax-only %S/nonexistent.c 2>&1 | FileCheck -check-prefix=CHECK-HEADER %s
end_comment

begin_comment
comment|// CHECK-EXIST: remap-file.c:1:28: warning: incompatible pointer types
end_comment

begin_comment
comment|// CHECK-NONEXIST: nonexistent.c:1:28: warning: incompatible pointer types
end_comment

begin_comment
comment|// CHECK-HEADER: nonexistent.c:3:19: warning: incompatible pointer types
end_comment

begin_macro
name|int
end_macro

end_unit

