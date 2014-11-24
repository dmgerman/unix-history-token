begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target xcore %s -g -Wl,L1Arg,L2Arg -Wa,A1Arg,A2Arg -fverbose-asm -v -### -o %t.o 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -target xcore -x c++ %s -g -Wl,L1Arg,L2Arg -Wa,A1Arg,A2Arg -fverbose-asm -v -### -o %t.o 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang -target xcore -x c++ %s -fexceptions -### -o %t.o 2>&1 | FileCheck -check-prefix CHECK-EXCEP %s
end_comment

begin_comment
comment|// RUN: %clang -target xcore %s -g0 -### -o %t.o 2>&1 | FileCheck -check-prefix CHECK-G0 %s
end_comment

begin_comment
comment|// CHECK: "-nostdsysteminc"
end_comment

begin_comment
comment|// CHECK: "-momit-leaf-frame-pointer"
end_comment

begin_comment
comment|// CHECK-NOT: "-mdisable-fp-elim"
end_comment

begin_comment
comment|// CHECK: "-fno-signed-char"
end_comment

begin_comment
comment|// CHECK: "-fno-use-cxa-atexit"
end_comment

begin_comment
comment|// CHECK-NOT: "-fcxx-exceptions"
end_comment

begin_comment
comment|// CHECK-NOT: "-fexceptions"
end_comment

begin_comment
comment|// CHECK: "-fno-common"
end_comment

begin_comment
comment|// CHECK: xcc" "-o"
end_comment

begin_comment
comment|// CHECK-EXCEP-NOT: "-fexceptions"
end_comment

begin_comment
comment|// CHECK: "-c" "-v" "-g" "-fverbose-asm" "A1Arg" "A2Arg"
end_comment

begin_comment
comment|// CHECK: xcc" "-o"
end_comment

begin_comment
comment|// CHECK-EXCEP-NOT: "-fexceptions"
end_comment

begin_comment
comment|// CHECK: "-v"
end_comment

begin_comment
comment|// CHECK: "L1Arg" "L2Arg"
end_comment

begin_comment
comment|// CHECK-EXCEP: "-fno-use-cxa-atexit"
end_comment

begin_comment
comment|// CHECK-EXCEP: "-fcxx-exceptions"
end_comment

begin_comment
comment|// CHECK-EXCEP: "-fexceptions"
end_comment

begin_comment
comment|// CHECK-EXCEP: "-fno-common"
end_comment

begin_comment
comment|// CHECK-EXCEP: xcc" "-o"
end_comment

begin_comment
comment|// CHECK-EXCEP-NOT: "-fexceptions"
end_comment

begin_comment
comment|// CHECK-EXCEP: xcc" "-o"
end_comment

begin_comment
comment|// CHECK-EXCEP: "-fexceptions"
end_comment

begin_comment
comment|// CHECK-G0: xcc"
end_comment

begin_comment
comment|// CHECK-G0-NOT: "-g"
end_comment

begin_comment
comment|// CHECK-G0: xcc"
end_comment

end_unit

