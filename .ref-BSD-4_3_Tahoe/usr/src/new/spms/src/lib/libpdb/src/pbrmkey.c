begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * pbrmkey() removes key from buffer.  */
end_comment

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
name|void
name|pbrmkey
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
comment|/* skip key field */
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
name|strlen
parameter_list|()
function_decl|;
comment|/* string length */
name|void
name|pbshrink
parameter_list|()
function_decl|;
comment|/* shrink buffer */
name|bp
operator|=
name|CURPBUF
expr_stmt|;
name|klen
operator|=
name|strlen
argument_list|(
name|key
argument_list|)
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
block|{
if|if
condition|(
name|bp
index|[
name|klen
index|]
operator|==
name|_PBKS
condition|)
name|klen
operator|++
expr_stmt|;
name|pbshrink
argument_list|(
name|bp
argument_list|,
name|klen
argument_list|)
expr_stmt|;
break|break;
block|}
name|bp
operator|=
name|pbskipkey
argument_list|(
name|bp
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

