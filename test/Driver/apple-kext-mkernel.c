begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -ccc-host-triple x86_64-apple-darwin10 \
end_comment

begin_comment
comment|// RUN:   -mkernel -### -fsyntax-only %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-X86< %t %s
end_comment

begin_comment
comment|// CHECK-X86: "-disable-red-zone"
end_comment

begin_comment
comment|// CHECK-X86: "-fno-builtin"
end_comment

begin_comment
comment|// CHECK-X86: "-fno-rtti"
end_comment

begin_comment
comment|// CHECK-X86: "-fno-common"
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple x86_64-apple-darwin10 \
end_comment

begin_comment
comment|// RUN:   -arch armv7 -mkernel -### -fsyntax-only %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-ARM< %t %s
end_comment

begin_comment
comment|// CHECK-ARM: "-backend-option" "-arm-long-calls"
end_comment

begin_comment
comment|// CHECK-ARM: "-backend-option" "-arm-strict-align"
end_comment

begin_comment
comment|// CHECK-ARM: "-fno-builtin"
end_comment

begin_comment
comment|// CHECK-ARM: "-fno-rtti"
end_comment

begin_comment
comment|// CHECK-ARM: "-fno-common"
end_comment

end_unit

