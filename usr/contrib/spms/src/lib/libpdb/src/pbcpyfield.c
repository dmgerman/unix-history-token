begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * pbcpyfield() copies the field pointed to by bp to field. Returns  * null-terminated field.  */
end_comment

begin_include
include|#
directive|include
file|"pdbuf.h"
end_include

begin_function
name|char
modifier|*
name|pbcpyfield
parameter_list|(
name|field
parameter_list|,
name|bp
parameter_list|)
specifier|register
name|char
modifier|*
name|field
decl_stmt|;
comment|/* field string */
specifier|register
name|char
modifier|*
name|bp
decl_stmt|;
comment|/* buffer pointer */
block|{
name|char
modifier|*
name|fieldsave
decl_stmt|;
name|fieldsave
operator|=
name|field
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
operator|*
name|field
operator|++
operator|=
operator|*
name|bp
operator|++
expr_stmt|;
operator|*
name|field
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|fieldsave
operator|)
return|;
block|}
end_function

end_unit

