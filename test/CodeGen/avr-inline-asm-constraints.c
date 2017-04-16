begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: avr-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple avr-unknown-unknown -emit-llvm -o - %s | FileCheck %s
end_comment

begin_decl_stmt
name|int
name|data
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|a
parameter_list|()
block|{
comment|// CHECK: call void asm sideeffect "add r5, $0", "a"(i16 %0)
asm|asm("add r5, %0" :: "a"(data));
block|}
end_function

begin_function
name|void
name|b
parameter_list|()
block|{
comment|// CHECK: call void asm sideeffect "add r5, $0", "b"(i16 %0)
asm|asm("add r5, %0" :: "b"(data));
block|}
end_function

begin_function
name|void
name|d
parameter_list|()
block|{
comment|// CHECK: call void asm sideeffect "add r5, $0", "d"(i16 %0)
asm|asm("add r5, %0" :: "d"(data));
block|}
end_function

begin_function
name|void
name|l
parameter_list|()
block|{
comment|// CHECK: call void asm sideeffect "add r5, $0", "l"(i16 %0)
asm|asm("add r5, %0" :: "l"(data));
block|}
end_function

begin_function
name|void
name|e
parameter_list|()
block|{
comment|// CHECK: call void asm sideeffect "add r5, $0", "e"(i16 %0)
asm|asm("add r5, %0" :: "e"(data));
block|}
end_function

begin_function
name|void
name|q
parameter_list|()
block|{
comment|// CHECK: call void asm sideeffect "add r5, $0", "q"(i16 %0)
asm|asm("add r5, %0" :: "q"(data));
block|}
end_function

begin_function
name|void
name|r
parameter_list|()
block|{
comment|// CHECK: call void asm sideeffect "add r5, $0", "r"(i16 %0)
asm|asm("add r5, %0" :: "r"(data));
block|}
end_function

begin_function
name|void
name|w
parameter_list|()
block|{
comment|// CHECK: call void asm sideeffect "add r5, $0", "w"(i16 %0)
asm|asm("add r5, %0" :: "w"(data));
block|}
end_function

begin_function
name|void
name|t
parameter_list|()
block|{
comment|// CHECK: call void asm sideeffect "add r5, $0", "t"(i16 %0)
asm|asm("add r5, %0" :: "t"(data));
block|}
end_function

begin_function
name|void
name|x
parameter_list|()
block|{
comment|// CHECK: call void asm sideeffect "add r5, $0", "x"(i16 %0)
asm|asm("add r5, %0" :: "x"(data));
block|}
end_function

begin_function
name|void
name|y
parameter_list|()
block|{
comment|// CHECK: call void asm sideeffect "add r5, $0", "y"(i16 %0)
asm|asm("add r5, %0" :: "y"(data));
block|}
end_function

begin_function
name|void
name|z
parameter_list|()
block|{
comment|// CHECK: call void asm sideeffect "add r5, $0", "z"(i16 %0)
asm|asm("add r5, %0" :: "z"(data));
block|}
end_function

begin_function
name|void
name|I
parameter_list|()
block|{
comment|// CHECK: call void asm sideeffect "subi r30, $0", "I"(i16 50)
asm|asm("subi r30, %0" :: "I"(50));
block|}
end_function

begin_function
name|void
name|J
parameter_list|()
block|{
comment|// CHECK: call void asm sideeffect "subi r30, $0", "J"(i16 -50)
asm|asm("subi r30, %0" :: "J"(-50));
block|}
end_function

begin_function
name|void
name|K
parameter_list|()
block|{
comment|// CHECK: call void asm sideeffect "subi r30, $0", "K"(i16 2)
asm|asm("subi r30, %0" :: "K"(2));
block|}
end_function

begin_function
name|void
name|L
parameter_list|()
block|{
comment|// CHECK: call void asm sideeffect "subi r30, $0", "L"(i16 0)
asm|asm("subi r30, %0" :: "L"(0));
block|}
end_function

begin_function
name|void
name|M
parameter_list|()
block|{
comment|// CHECK: call void asm sideeffect "subi r30, $0", "M"(i16 255)
asm|asm("subi r30, %0" :: "M"(255));
block|}
end_function

begin_function
name|void
name|O
parameter_list|()
block|{
comment|// CHECK: call void asm sideeffect "subi r30, $0", "O"(i16 16)
asm|asm("subi r30, %0" :: "O"(16));
block|}
end_function

begin_function
name|void
name|P
parameter_list|()
block|{
comment|// CHECK: call void asm sideeffect "subi r30, $0", "P"(i16 1)
asm|asm("subi r30, %0" :: "P"(1));
block|}
end_function

begin_function
name|void
name|R
parameter_list|()
block|{
comment|// CHECK: call void asm sideeffect "subi r30, $0", "R"(i16 -3)
asm|asm("subi r30, %0" :: "R"(-3));
block|}
end_function

begin_function
name|void
name|G
parameter_list|()
block|{
comment|// CHECK: call void asm sideeffect "subi r30, $0", "G"(i16 50)
asm|asm("subi r30, %0" :: "G"(50));
block|}
end_function

begin_function
name|void
name|Q
parameter_list|()
block|{
comment|// CHECK: call void asm sideeffect "subi r30, $0", "Q"(i16 50)
asm|asm("subi r30, %0" :: "Q"(50));
block|}
end_function

begin_function
name|void
name|ra
parameter_list|()
block|{
comment|// CHECK: call void asm sideeffect "subi r30, $0", "ra"(i16 50)
asm|asm("subi r30, %0" :: "ra"(50));
block|}
end_function

begin_function
name|void
name|ora
parameter_list|()
block|{
comment|// CHECK: call i16 asm "subi r30, $0", "=ra"()
asm|asm("subi r30, %0" : "=ra"(data));
block|}
end_function

end_unit

