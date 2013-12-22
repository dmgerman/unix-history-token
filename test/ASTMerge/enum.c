begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t.1.ast %S/Inputs/enum1.c
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-pch -o %t.2.ast %S/Inputs/enum2.c
end_comment

begin_comment
comment|// RUN: not %clang_cc1 -ast-merge %t.1.ast -ast-merge %t.2.ast -fsyntax-only %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: enum1.c:9:6: warning: type 'enum E2' has incompatible definitions in different translation units
end_comment

begin_comment
comment|// CHECK: enum1.c:11:3: note: enumerator 'E2Enumerator2' with value 3 here
end_comment

begin_comment
comment|// CHECK: enum2.c:11:3: note: enumerator 'E2Enumerator2' with value 4 here
end_comment

begin_comment
comment|// CHECK: enum2.c:13:3: error: external variable 'x2' declared with incompatible types in different translation units ('enum E2' vs. 'enum E2')
end_comment

begin_comment
comment|// CHECK: enum1.c:13:3: note: declared here with type 'enum E2'
end_comment

begin_comment
comment|// CHECK: enum1.c:16:6: warning: type 'enum E3' has incompatible definitions in different translation units
end_comment

begin_comment
comment|// CHECK: enum1.c:18:3: note: enumerator 'E3Enumerator2' with value 3 here
end_comment

begin_comment
comment|// CHECK: enum2.c:18:3: note: enumerator 'E3Enumerator' with value 3 here
end_comment

begin_comment
comment|// CHECK: enum2.c:20:3: error: external variable 'x3' declared with incompatible types in different translation units ('enum E3' vs. 'enum E3')
end_comment

begin_comment
comment|// CHECK: enum1.c:20:3: note: declared here with type 'enum E3'
end_comment

begin_comment
comment|// CHECK: enum1.c:23:6: warning: type 'enum E4' has incompatible definitions in different translation units
end_comment

begin_comment
comment|// CHECK: enum1.c:26:3: note: enumerator 'E4Enumerator3' with value 2 here
end_comment

begin_comment
comment|// CHECK: enum2.c:23:6: note: no corresponding enumerator here
end_comment

begin_comment
comment|// CHECK: enum2.c:26:3: error: external variable 'x4' declared with incompatible types in different translation units ('enum E4' vs. 'enum E4')
end_comment

begin_comment
comment|// CHECK: enum1.c:27:3: note: declared here with type 'enum E4'
end_comment

begin_comment
comment|// CHECK: enum1.c:30:6: warning: type 'enum E5' has incompatible definitions in different translation units
end_comment

begin_comment
comment|// CHECK: enum2.c:33:3: note: enumerator 'E5Enumerator4' with value 3 here
end_comment

begin_comment
comment|// CHECK: enum1.c:30:6: note: no corresponding enumerator here
end_comment

begin_comment
comment|// CHECK: enum2.c:34:3: error: external variable 'x5' declared with incompatible types in different translation units ('enum E5' vs. 'enum E5')
end_comment

begin_comment
comment|// CHECK: enum1.c:34:3: note: declared here with type 'enum E5'
end_comment

begin_comment
comment|// CHECK: 4 warnings and 4 errors generated
end_comment

end_unit

