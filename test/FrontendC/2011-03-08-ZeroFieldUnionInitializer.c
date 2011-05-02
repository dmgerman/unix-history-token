begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
union|union
block|{
struct|struct
block|{ }
name|__attribute
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
block|}
union|;
block|}
name|fenv_t
typedef|;
end_typedef

begin_decl_stmt
specifier|const
name|fenv_t
name|_FE_DFL_ENV
init|=
block|{
block|{
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

