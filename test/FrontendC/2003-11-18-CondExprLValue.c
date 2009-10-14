begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|pgprot
decl_stmt|;
block|}
name|pgprot_t
typedef|;
end_typedef

begin_function
name|void
name|split_large_page
parameter_list|(
name|unsigned
name|long
name|addr
parameter_list|,
name|pgprot_t
name|prot
parameter_list|)
block|{
operator|(
name|addr
condition|?
name|prot
else|:
operator|(
operator|(
name|pgprot_t
operator|)
block|{
literal|0x001
block|}
operator|)
operator|)
operator|.
name|pgprot
expr_stmt|;
block|}
end_function

end_unit

