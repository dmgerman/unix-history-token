begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_RCS
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
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_RCS and not lint */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|__progname
decl_stmt|;
end_decl_stmt

begin_function
specifier|const
name|char
modifier|*
name|getprogname
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|__progname
operator|)
return|;
block|}
end_function

end_unit

