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
literal|"$Id: strdup.c,v 1.8 1993/05/23 03:38:27 moraes Exp $"
argument_list|)
end_macro

begin_comment
comment|/*   *  makes a copy of a null terminated string in malloc'ed storage.  *  returns null if it fails.  */
end_comment

begin_function
name|char
modifier|*
name|strdup
parameter_list|(
name|s
parameter_list|)
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|char
modifier|*
name|cp
decl_stmt|;
if|if
condition|(
name|s
condition|)
block|{
name|cp
operator|=
operator|(
name|char
operator|*
operator|)
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
expr_stmt|;
if|if
condition|(
name|cp
condition|)
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|cp
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
else|else
name|cp
operator|=
operator|(
name|char
operator|*
operator|)
name|NULL
expr_stmt|;
return|return
operator|(
name|cp
operator|)
return|;
block|}
end_function

end_unit

