begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function
specifier|inline
name|void
name|f1
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|__builtin_va_list
name|args
decl_stmt|;
name|__builtin_va_start
argument_list|(
name|args
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
block|}
end_function

begin_struct
struct|struct
name|non_trivial_dtor
block|{
operator|~
name|non_trivial_dtor
argument_list|()
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|implicit_dtor
block|{
name|non_trivial_dtor
name|d
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uninst_implicit_dtor
block|{
name|non_trivial_dtor
name|d
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|inline
name|void
name|use_implicit_dtor
parameter_list|()
block|{
name|implicit_dtor
name|d
decl_stmt|;
block|}
end_function

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|inst
argument_list|()
block|{ }
specifier|inline
name|void
name|inst_decl
argument_list|()
block|{
comment|// cause inst<int>'s declaration to be instantiated, without a definition.
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
operator|&
name|inst
operator|<
name|int
operator|>
argument_list|)
block|;
name|inst
operator|<
name|float
operator|>
operator|(
operator|)
block|; }
end_expr_stmt

begin_asm
asm|asm("narf");
end_asm

end_unit

