begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * pbaddkey() inserts a key at the head of the buffer. The buffer is not  * changed if key already exists. Returns integer NO if buffer exceeded,  * otherwise YES.  */
end_comment

begin_include
include|#
directive|include
file|"pdbuf.h"
end_include

begin_include
include|#
directive|include
file|"yesno.h"
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

begin_macro
name|pbaddkey
argument_list|(
argument|key
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|key
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* key string */
end_comment

begin_block
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
name|char
modifier|*
name|strncpy
parameter_list|()
function_decl|;
comment|/* copy n characters */
name|int
name|klen
decl_stmt|;
comment|/* key string length */
name|int
name|pbcmpkey
parameter_list|()
function_decl|;
comment|/* compare keys */
name|int
name|pbstretch
parameter_list|()
function_decl|;
comment|/* stretch buffer */
name|int
name|strlen
parameter_list|()
function_decl|;
comment|/* string length */
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
name|YES
operator|)
return|;
comment|/* key already exists */
name|bp
operator|=
name|pbskipkey
argument_list|(
name|bp
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|bp
operator|==
name|CURPBUF
operator|&&
operator|*
name|bp
operator|!=
name|_PBFS
condition|)
block|{
operator|*
name|bp
operator|++
operator|=
name|_PBFS
expr_stmt|;
comment|/* prepare virgin buffer */
operator|*
name|bp
operator|=
literal|'\0'
expr_stmt|;
block|}
name|klen
operator|=
name|strlen
argument_list|(
name|key
argument_list|)
expr_stmt|;
if|if
condition|(
name|pbstretch
argument_list|(
name|CURPBUF
argument_list|,
name|klen
operator|+
literal|1
argument_list|)
operator|==
name|NO
condition|)
return|return
operator|(
name|NO
operator|)
return|;
name|strncpy
argument_list|(
name|CURPBUF
argument_list|,
name|key
argument_list|,
name|klen
argument_list|)
expr_stmt|;
comment|/* insert key */
name|CURPBUF
index|[
name|klen
index|]
operator|=
name|_PBKS
expr_stmt|;
comment|/* add key field separator */
return|return
operator|(
name|YES
operator|)
return|;
block|}
end_block

end_unit

