begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  *  * Called by ld.so when onanating.  * This *must* be a static function, so it is not called through a jmpslot.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|md_relocate_simple
parameter_list|(
name|r
parameter_list|,
name|relocation
parameter_list|,
name|addr
parameter_list|)
name|struct
name|relocation_info
modifier|*
name|r
decl_stmt|;
name|long
name|relocation
decl_stmt|;
name|char
modifier|*
name|addr
decl_stmt|;
block|{
operator|*
operator|(
name|long
operator|*
operator|)
name|addr
operator|+=
name|relocation
expr_stmt|;
block|}
end_function

end_unit

