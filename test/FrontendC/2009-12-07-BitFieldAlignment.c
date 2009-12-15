begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -m32 %s -S -o - | FileCheck %s
end_comment

begin_comment
comment|// Set alignment on bitfield accesses.
end_comment

begin_struct
struct|struct
name|S
block|{
name|int
name|a
decl_stmt|,
name|b
decl_stmt|;
name|void
modifier|*
name|c
decl_stmt|;
name|unsigned
name|d
range|:
literal|8
decl_stmt|;
name|unsigned
name|e
range|:
literal|8
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|f0
parameter_list|(
name|struct
name|S
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK: %3 = load i32* %2, align 4
comment|// CHECK: store i32 %4, i32* %2, align 4
name|a
operator|->
name|e
operator|=
literal|0
expr_stmt|;
block|}
end_function

end_unit

