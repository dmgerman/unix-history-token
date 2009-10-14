begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|type
decl_stmt|;
comment|/* Indicates, NORMAL, SUBNORMAL, etc. */
block|}
name|InternalFPF
typedef|;
end_typedef

begin_function
specifier|static
name|void
name|SetInternalFPFZero
parameter_list|(
name|InternalFPF
modifier|*
name|dest
parameter_list|)
block|{
name|dest
operator|->
name|type
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function
name|void
name|denormalize
parameter_list|(
name|InternalFPF
modifier|*
name|ptr
parameter_list|)
block|{
name|SetInternalFPFZero
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

