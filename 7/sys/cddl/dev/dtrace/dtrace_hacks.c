begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* XXX Hacks.... */
end_comment

begin_decl_stmt
name|dtrace_cacheid_t
name|dtrace_predcache_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|panic_quiesce
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|panic_stack
index|[
name|PANICSTKSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|boolean_t
name|priv_policy_only
parameter_list|(
specifier|const
name|cred_t
modifier|*
name|a
parameter_list|,
name|int
name|b
parameter_list|,
name|boolean_t
name|c
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

end_unit

