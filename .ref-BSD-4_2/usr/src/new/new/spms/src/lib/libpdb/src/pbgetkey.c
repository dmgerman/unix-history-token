begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * pbgetkey() loads the next key field into key. Returns key or null  * character if no more key fields.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|KP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next key field */
end_comment

begin_function
name|char
modifier|*
name|pbgetkey
parameter_list|(
name|key
parameter_list|)
name|char
modifier|*
name|key
decl_stmt|;
comment|/* key string */
block|{
name|char
modifier|*
name|pbcpykey
parameter_list|()
function_decl|;
comment|/* copy key */
name|char
modifier|*
name|pbskipkey
parameter_list|()
function_decl|;
comment|/* skip to next key */
name|key
operator|=
name|pbcpykey
argument_list|(
name|key
argument_list|,
name|KP
argument_list|)
expr_stmt|;
name|KP
operator|=
name|pbskipkey
argument_list|(
name|KP
argument_list|)
expr_stmt|;
return|return
operator|(
name|key
operator|)
return|;
block|}
end_function

end_unit

