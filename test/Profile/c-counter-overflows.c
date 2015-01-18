begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that big branch weights get scaled down to 32-bits, rather than just
end_comment

begin_comment
comment|// truncated.
end_comment

begin_comment
comment|// RUN: llvm-profdata merge %S/Inputs/c-counter-overflows.proftext -o %t.profdata
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.9 -main-file-name c-counter-overflows.c %s -o - -emit-llvm -fprofile-instr-use=%t.profdata | FileCheck %s
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|uint64_t
typedef|;
end_typedef

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
comment|// Need counts higher than 32-bits.
comment|// CHECK: br {{.*}} !prof ![[FOR:[0-9]+]]
comment|// max   = 0xffffffff0
comment|// scale = 0xffffffff0 / 0xffffffff + 1 = 17
comment|// loop-body: 0xffffffff0 / 17 + 1 = 0xf0f0f0f0 + 1 = 4042322161 => -252645135
comment|// loop-exit: 0x000000001 / 17 + 1 = 0x00000000 + 1 =          1 =>          1
for|for
control|(
name|uint64_t
name|I
init|=
literal|0
init|;
name|I
operator|<
literal|0xffffffff0
condition|;
operator|++
name|I
control|)
block|{
comment|// max   = 0xffffffff * 15 = 0xefffffff1
comment|// scale = 0xefffffff1 / 0xffffffff + 1 = 16
comment|// CHECK: br {{.*}} !prof ![[IF:[0-9]+]]
if|if
condition|(
name|I
operator|&
literal|0xf
condition|)
block|{
comment|// 0xefffffff1 / 16 + 1 = 0xefffffff + 1 = 4026531840 => -268435456
block|}
else|else
block|{
comment|// 0x0ffffffff / 16 + 1 = 0x0fffffff + 1 =  268435456 =>  268435456
block|}
comment|// max   = 0xffffffff * 5 = 0x4fffffffb
comment|// scale = 0x4fffffffb / 0xffffffff + 1 = 6
comment|// CHECK: ], !prof ![[SWITCH:[0-9]+]]
switch|switch
condition|(
operator|(
name|I
operator|&
literal|0xf
operator|)
operator|/
literal|5
condition|)
block|{
case|case
literal|0
case|:
comment|// 0x4fffffffb / 6 = 0xd5555554 + 1 = 3579139413 => -715827883
break|break;
case|case
literal|1
case|:
comment|// 0x4fffffffb / 6 = 0xd5555554 + 1 = 3579139413 => -715827883
break|break;
case|case
literal|2
case|:
comment|// 0x4fffffffb / 6 = 0xd5555554 + 1 = 3579139413 => -715827883
break|break;
default|default:
comment|// 0x0ffffffff / 6 = 0x2aaaaaaa + 1 =  715827883 =>  715827883
break|break;
block|}
block|}
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-DAG: ![[FOR]] = !{!"branch_weights", i32 -252645135, i32 1}
end_comment

begin_comment
comment|// CHECK-DAG: ![[IF]]  = !{!"branch_weights", i32 -268435456, i32 268435456}
end_comment

begin_comment
comment|// CHECK-DAG: ![[SWITCH]] = !{!"branch_weights", i32 715827883, i32 -715827883, i32 -715827883, i32 -715827883}
end_comment

end_unit

