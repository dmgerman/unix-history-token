begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  Author: Mark Moraes<moraes@csri.toronto.edu> */
end_comment

begin_comment
comment|/*LINTLIBRARY*/
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_macro
name|RCSID
argument_list|(
literal|"$Id: strsave.c,v 1.9 1993/05/23 03:38:27 moraes Exp $"
argument_list|)
end_macro

begin_comment
comment|/*   *  makes a copy of a null terminated string in malloc'ed storage. Dies  *  if enough memory isn't available or there is a malloc error  */
end_comment

begin_function
name|char
modifier|*
name|strsave
parameter_list|(
name|s
parameter_list|)
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
block|{
if|if
condition|(
name|s
condition|)
return|return
operator|(
name|strcpy
argument_list|(
name|emalloc
argument_list|(
call|(
name|size_t
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
argument_list|,
name|s
argument_list|)
operator|)
return|;
else|else
return|return
operator|(
operator|(
name|char
operator|*
operator|)
name|NULL
operator|)
return|;
block|}
end_function

end_unit

