begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * ppathhead() removes tail of project pathname and returns pathname.  * The tail is defined as that part of the pathname after the last separator.  */
end_comment

begin_include
include|#
directive|include
file|"path.h"
end_include

begin_function
name|char
modifier|*
name|ppathhead
parameter_list|(
name|ppathname
parameter_list|)
specifier|register
name|char
modifier|*
name|ppathname
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|ls
decl_stmt|;
comment|/* last separator character */
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
comment|/* project pathname pointer */
for|for
control|(
name|p
operator|=
name|ppathname
init|;
operator|*
name|p
operator|!=
literal|'\0'
condition|;
name|p
operator|++
control|)
if|if
condition|(
operator|*
name|p
operator|==
name|_PPSC
condition|)
name|ls
operator|=
name|p
expr_stmt|;
operator|*
name|ls
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|ppathname
operator|)
return|;
block|}
end_function

end_unit

