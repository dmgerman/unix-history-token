begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// FIXME: Check IR rather than asm, then triple is not needed.
end_comment

begin_comment
comment|// RUN: %clang -Xclang -triple=%itanium_abi_triple -S -g -fverbose-asm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// Radar 8461032
end_comment

begin_comment
comment|// CHECK: DW_AT_location
end_comment

begin_comment
comment|// CHECK-NEXT: byte 145
end_comment

begin_comment
comment|// 145 is DW_OP_fbreg
end_comment

begin_struct
struct|struct
name|s
block|{
name|int
name|a
decl_stmt|;
name|struct
name|s
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|int
name|foo
parameter_list|(
name|struct
name|s
modifier|*
name|s
parameter_list|)
block|{
switch|switch
condition|(
name|s
operator|->
name|a
condition|)
block|{
case|case
literal|1
case|:
case|case
literal|2
case|:
block|{
name|struct
name|s
modifier|*
name|sp
init|=
name|s
operator|->
name|next
decl_stmt|;
block|}
break|break;
block|}
return|return
literal|1
return|;
block|}
end_function

end_unit

