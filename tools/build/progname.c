begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Compat shims for those programs that use this newer interface.  These  * are more minimal than their libc bretheren as far as namespaces and  * such go because their use is so limited.  Also, the libc versions  * have too many depends on libc build environment; it is more of a pain  * to set that up than to recreate them here shorn of all the other goo.  */
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
name|void
name|setprogname
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
block|{
name|__progname
operator|=
name|p
expr_stmt|;
block|}
end_function

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

