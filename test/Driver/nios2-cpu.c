begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target nios2--- %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -target nios2--- -mcpu=r1 %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-R1 %s
end_comment

begin_comment
comment|// RUN: %clang -target nios2--- -mcpu=nios2r1 %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-R1 %s
end_comment

begin_comment
comment|// RUN: %clang -target nios2--- -march=r1 %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-R1 %s
end_comment

begin_comment
comment|// RUN: %clang -target nios2--- -march=nios2r1 %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-R1 %s
end_comment

begin_comment
comment|// RUN: %clang -target nios2--- -mcpu=r2 %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-R2 %s
end_comment

begin_comment
comment|// RUN: %clang -target nios2--- -mcpu=nios2r2 %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-R2 %s
end_comment

begin_comment
comment|// RUN: %clang -target nios2--- -march=r2 %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-R2 %s
end_comment

begin_comment
comment|// RUN: %clang -target nios2--- -march=nios2r2 %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=CHECK-R2 %s
end_comment

begin_comment
comment|// CHECK: "-triple" "nios2---"
end_comment

begin_comment
comment|// CHECK-R1: "-triple" "nios2---"
end_comment

begin_comment
comment|// CHECK-R1: "-target-cpu" "nios2r1"
end_comment

begin_comment
comment|// CHECK-R2: "-triple" "nios2---"
end_comment

begin_comment
comment|// CHECK-R2: "-target-cpu" "nios2r2"
end_comment

end_unit

