begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: pathhead.c,v 1.2 85/03/08 17:21:50 nicklin Exp $ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * pathhead() removes tail of pathname and returns pathname. The tail is  * defined as that part of the pathname after the last separator.  */
end_comment

begin_include
include|#
directive|include
file|"null.h"
end_include

begin_include
include|#
directive|include
file|"path.h"
end_include

begin_function
name|char
modifier|*
name|pathhead
parameter_list|(
name|pathname
parameter_list|)
specifier|register
name|char
modifier|*
name|pathname
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
comment|/* pathname pointer */
name|ls
operator|=
name|NULL
expr_stmt|;
for|for
control|(
name|p
operator|=
name|pathname
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
name|_PSC
condition|)
name|ls
operator|=
name|p
expr_stmt|;
if|if
condition|(
name|ls
operator|!=
name|NULL
condition|)
operator|*
name|ls
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|pathname
operator|)
return|;
block|}
end_function

end_unit

