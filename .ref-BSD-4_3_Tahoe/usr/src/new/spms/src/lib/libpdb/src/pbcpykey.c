begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * pbcpykey() copies the key field pointed to by bp to key. Returns  * null-terminated key.  */
end_comment

begin_include
include|#
directive|include
file|"pdbuf.h"
end_include

begin_function
name|char
modifier|*
name|pbcpykey
parameter_list|(
name|key
parameter_list|,
name|bp
parameter_list|)
specifier|register
name|char
modifier|*
name|key
decl_stmt|;
comment|/* key string */
specifier|register
name|char
modifier|*
name|bp
decl_stmt|;
comment|/* buffer pointer */
block|{
name|char
modifier|*
name|keysave
decl_stmt|;
name|keysave
operator|=
name|key
expr_stmt|;
while|while
condition|(
operator|*
name|bp
operator|!=
name|_PBKS
operator|&&
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
operator|*
name|key
operator|++
operator|=
operator|*
name|bp
operator|++
expr_stmt|;
operator|*
name|key
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|keysave
operator|)
return|;
block|}
end_function

end_unit

