begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Return the basename of a pathname.    This file is in the public domain. */
end_comment

begin_comment
comment|/* NAME 	basename -- return pointer to last component of a pathname  SYNOPSIS 	char *basename (const char *name)  DESCRIPTION 	Given a pointer to a string containing a typical pathname 	(/usr/src/cmd/ls/ls.c for example), returns a pointer to the 	last component of the pathname ("ls.c" in this case).  BUGS 	Presumes a UNIX style path with UNIX style separators. */
end_comment

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NEED_basename
end_ifdef

begin_function
name|char
modifier|*
name|basename
parameter_list|(
name|name
parameter_list|)
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
block|{
specifier|const
name|char
modifier|*
name|base
init|=
name|name
decl_stmt|;
while|while
condition|(
operator|*
name|name
condition|)
block|{
if|if
condition|(
operator|*
name|name
operator|++
operator|==
literal|'/'
condition|)
block|{
name|base
operator|=
name|name
expr_stmt|;
block|}
block|}
return|return
operator|(
name|char
operator|*
operator|)
name|base
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

