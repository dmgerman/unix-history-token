begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* strindex.c - "unsigned" lexical index */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|ident
index|[]
init|=
literal|"@(#)$Id: strindex.c,v 2.3 1992/12/15 00:20:22 jromine Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_function
name|int
name|stringdex
parameter_list|(
name|p1
parameter_list|,
name|p2
parameter_list|)
specifier|register
name|char
modifier|*
name|p1
decl_stmt|,
decl|*
name|p2
decl_stmt|;
end_function

begin_block
block|{
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
if|if
condition|(
name|p1
operator|==
literal|0
operator|||
name|p2
operator|==
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* XXX */
for|for
control|(
name|p
operator|=
name|p2
init|;
operator|*
name|p
condition|;
name|p
operator|++
control|)
if|if
condition|(
name|uprf
argument_list|(
name|p
argument_list|,
name|p1
argument_list|)
condition|)
return|return
operator|(
name|p
operator|-
name|p2
operator|)
return|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_block

end_unit

