begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o -
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|i
decl_stmt|;
block|}
name|Value
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Value
modifier|*
name|PValue
typedef|;
end_typedef

begin_function
name|int
name|get_value
parameter_list|(
name|PValue
name|v
parameter_list|)
block|{
return|return
name|v
operator|->
name|i
return|;
block|}
end_function

end_unit

