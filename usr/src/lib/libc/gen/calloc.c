begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)calloc.c	5.2 (Berkeley) 3/9/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|LIBC_SCCS and not lint
end_endif

begin_comment
comment|/*  * Calloc - allocate and clear memory block  */
end_comment

begin_function
name|char
modifier|*
name|calloc
parameter_list|(
name|num
parameter_list|,
name|size
parameter_list|)
specifier|register
name|unsigned
name|num
decl_stmt|,
name|size
decl_stmt|;
block|{
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
name|size
operator|*=
name|num
expr_stmt|;
if|if
condition|(
name|p
operator|=
name|malloc
argument_list|(
name|size
argument_list|)
condition|)
name|bzero
argument_list|(
name|p
argument_list|,
name|size
argument_list|)
expr_stmt|;
return|return
operator|(
name|p
operator|)
return|;
block|}
end_function

begin_macro
name|cfree
argument_list|(
argument|p
argument_list|,
argument|num
argument_list|,
argument|size
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|num
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|size
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

