begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -o - | FileCheck %s
end_comment

begin_comment
comment|// PR 5995
end_comment

begin_struct
struct|struct
name|s
block|{
name|int
name|word
decl_stmt|;
struct|struct
block|{
name|int
name|filler
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|8
argument_list|)
operator|)
argument_list|)
decl_stmt|;
block|}
struct|;
block|}
struct|;
end_struct

begin_function
name|void
name|func
parameter_list|(
name|struct
name|s
modifier|*
name|s
parameter_list|)
block|{
comment|// CHECK: load %struct.s** %s_addr, align {{[48]}}
name|s
operator|->
name|word
operator|=
literal|0
expr_stmt|;
block|}
end_function

end_unit

