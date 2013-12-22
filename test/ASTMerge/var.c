begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t.1.ast %S/Inputs/var1.c
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t.2.ast %S/Inputs/var2.c
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -ast-merge %t.1.ast -ast-merge %t.2.ast -fsyntax-only -fdiagnostics-show-note-include-stack %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: var2.c:2:9: error: external variable 'x1' declared with incompatible types in different translation units ('double *' vs. 'float **')
end_comment

begin_comment
comment|// CHECK: var1.c:2:9: note: declared here with type 'float **'
end_comment

begin_comment
comment|// CHECK: var2.c:3:5: error: external variable 'x2' declared with incompatible types in different translation units ('int' vs. 'double')
end_comment

begin_comment
comment|// CHECK: In file included from{{.*}}var1.c:3:
end_comment

begin_comment
comment|// CHECK: var1.h:1:8: note: declared here with type 'double'
end_comment

begin_comment
comment|// CHECK: error: external variable 'xarray3' declared with incompatible types in different translation units ('int [17]' vs. 'int [18]')
end_comment

begin_comment
comment|// CHECK: var1.c:7:5: note: declared here with type 'int [18]'
end_comment

begin_comment
comment|// CHECK: 3 errors
end_comment

end_unit

