begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * pbrmstring() removes string identified by id from buffer.  */
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
name|pbrmstring
parameter_list|(
name|id
parameter_list|)
specifier|register
name|char
modifier|*
name|id
decl_stmt|;
comment|/* string identifier */
block|{
specifier|register
name|char
modifier|*
name|bp
decl_stmt|;
comment|/* buffer pointer */
name|char
modifier|*
name|pbskipfield
parameter_list|()
function_decl|;
comment|/* skip to next non-key field */
name|int
name|flen
decl_stmt|;
comment|/* field length */
name|int
name|pblenfield
parameter_list|()
function_decl|;
comment|/* length of nonm-key field */
name|void
name|pbshrink
parameter_list|()
function_decl|;
comment|/* shrink buffer */
name|bp
operator|=
name|CURPBUF
expr_stmt|;
while|while
condition|(
operator|*
operator|(
name|bp
operator|=
name|pbskipfield
argument_list|(
name|bp
argument_list|)
operator|)
operator|!=
literal|'\0'
condition|)
if|if
condition|(
name|bp
index|[
literal|0
index|]
operator|==
name|id
index|[
literal|0
index|]
operator|&&
name|bp
index|[
literal|1
index|]
operator|==
name|id
index|[
literal|1
index|]
operator|&&
name|bp
index|[
literal|2
index|]
operator|==
literal|'='
condition|)
block|{
name|flen
operator|=
name|pblenfield
argument_list|(
name|bp
argument_list|)
expr_stmt|;
if|if
condition|(
name|bp
index|[
name|flen
index|]
operator|==
name|_PBFS
condition|)
name|flen
operator|++
expr_stmt|;
name|pbshrink
argument_list|(
name|bp
argument_list|,
name|flen
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function

end_unit

