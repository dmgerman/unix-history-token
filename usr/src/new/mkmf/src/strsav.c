begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: strsav.c,v 1.1 85/03/14 17:00:30 nicklin Exp $ */
end_comment

begin_comment
comment|/*  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * strsav() saves a string somewhere and returns a pointer to the somewhere.  * Returns NULL on error.  */
end_comment

begin_include
include|#
directive|include
file|"null.h"
end_include

begin_function
name|char
modifier|*
name|strsav
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|char
modifier|*
name|sptr
decl_stmt|;
comment|/* somewhere string pointer */
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
comment|/* memory allocator */
name|char
modifier|*
name|strcpy
parameter_list|()
function_decl|;
comment|/* string copy */
name|int
name|strlen
parameter_list|()
function_decl|;
comment|/* string length */
if|if
condition|(
operator|(
name|sptr
operator|=
name|malloc
argument_list|(
call|(
name|unsigned
call|)
argument_list|(
name|strlen
argument_list|(
name|s
argument_list|)
operator|+
literal|1
argument_list|)
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
return|return
operator|(
name|strcpy
argument_list|(
name|sptr
argument_list|,
name|s
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

