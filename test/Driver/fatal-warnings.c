begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### %s -c -o tmp.o -target i686-pc-linux-gnu -integrated-as -Wa,--fatal-warnings 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: not %clang %s -c -o %t.o -target i686-pc-linux-gnu -integrated-as -Wa,--fatal-warnings 2>&1 %t.log
end_comment

begin_comment
comment|// FileCheck --check-prefix=CHECK-AS %s -input-file %t.log
end_comment

begin_comment
comment|// CHECK: "-cc1" {{.*}} "-massembler-fatal-warnings"
end_comment

begin_comment
comment|// CHECK-AS: error: .warning argument must be a string
end_comment

begin_asm
asm|__asm(".warning 1");
end_asm

end_unit

