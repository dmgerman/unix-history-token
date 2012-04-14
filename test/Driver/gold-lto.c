begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: touch %t.o
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-pc-linux-gnu -### %t.o -O4 -Wl,-plugin-opt=foo 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck %s< %t.log
end_comment

begin_comment
comment|// CHECK: "-plugin" "{{.*}}/LLVMgold.so"
end_comment

begin_comment
comment|// CHECK: "-plugin-opt=foo"
end_comment

end_unit

