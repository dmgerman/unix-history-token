begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * pbfndkey() searchs for key in buffer and returns a pointer to its  * location, otherwise null.  */
end_comment

begin_include
include|#
directive|include
file|"null.h"
end_include

begin_include
include|#
directive|include
file|"pdbuf.h"
end_include

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|CURPBUF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current database buffer */
end_comment

begin_function
name|char
modifier|*
name|pbfndkey
parameter_list|(
name|key
parameter_list|)
name|char
modifier|*
name|key
decl_stmt|;
comment|/* key string */
block|{
specifier|register
name|char
modifier|*
name|bp
decl_stmt|;
comment|/* buffer pointer */
name|char
modifier|*
name|pbskipkey
parameter_list|()
function_decl|;
comment|/* skip to next key */
name|int
name|pbcmpkey
parameter_list|()
function_decl|;
comment|/* compare keys */
name|bp
operator|=
name|CURPBUF
expr_stmt|;
while|while
condition|(
operator|*
name|bp
operator|!=
name|_PBFS
operator|&&
operator|*
name|bp
operator|!=
literal|'\0'
condition|)
block|{
if|if
condition|(
name|pbcmpkey
argument_list|(
name|key
argument_list|,
name|bp
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|bp
operator|)
return|;
name|bp
operator|=
name|pbskipkey
argument_list|(
name|bp
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

end_unit

