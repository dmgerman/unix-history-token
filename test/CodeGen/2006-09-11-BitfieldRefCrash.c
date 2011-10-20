begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o -
end_comment

begin_comment
comment|// PR906
end_comment

begin_struct
struct|struct
name|state_struct
block|{
name|unsigned
name|long
name|long
name|phys_frame
range|:
literal|50
decl_stmt|;
name|unsigned
name|valid
range|:
literal|2
decl_stmt|;
block|}
name|s
struct|;
end_struct

begin_function
name|int
name|mem_access
parameter_list|(
name|struct
name|state_struct
modifier|*
name|p
parameter_list|)
block|{
return|return
name|p
operator|->
name|valid
return|;
block|}
end_function

end_unit

