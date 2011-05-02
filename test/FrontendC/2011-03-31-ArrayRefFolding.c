begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S -o - -m32 -Os %s | FileCheck %s
end_comment

begin_comment
comment|// PR9571
end_comment

begin_struct
struct|struct
name|t
block|{
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|t
modifier|*
name|cfun
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|f
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
operator|!
operator|(
name|cfun
operator|+
literal|0
operator|)
condition|)
comment|// CHECK: icmp eq %struct.t* %0, null
return|return
literal|0
return|;
return|return
name|cfun
operator|->
name|x
return|;
block|}
end_function

end_unit

