begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target xcore %s -g -Wl,L1Arg,L2Arg -Wa,A1Arg,A2Arg -### -o %t.o 2>&1 | FileCheck %s
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
comment|// CHECK: "-fno-common"
end_comment

begin_comment
comment|// CHECH: xcc" "-o"
end_comment

begin_comment
comment|// CHECK: "-c" "-g" "A1Arg" "A2Arg"
end_comment

begin_comment
comment|// CHECK: xcc" "-o"
end_comment

begin_comment
comment|// CHECK: "L1Arg" "L2Arg"
end_comment

end_unit

