begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)wwerror.c	3.7 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"ww.h"
end_include

begin_function
name|char
modifier|*
name|wwerror
parameter_list|()
block|{
specifier|extern
name|int
name|errno
decl_stmt|;
name|char
modifier|*
name|strerror
parameter_list|()
function_decl|;
switch|switch
condition|(
name|wwerrno
condition|)
block|{
case|case
name|WWE_NOERR
case|:
return|return
literal|"No error"
return|;
case|case
name|WWE_SYS
case|:
return|return
name|strerror
argument_list|(
name|errno
argument_list|)
return|;
case|case
name|WWE_NOMEM
case|:
return|return
literal|"Out of memory"
return|;
case|case
name|WWE_TOOMANY
case|:
return|return
literal|"Too many windows"
return|;
case|case
name|WWE_NOPTY
case|:
return|return
literal|"Out of pseudo-terminals"
return|;
case|case
name|WWE_SIZE
case|:
return|return
literal|"Bad window size"
return|;
case|case
name|WWE_BADTERM
case|:
return|return
literal|"Unknown terminal type"
return|;
case|case
name|WWE_CANTDO
case|:
return|return
literal|"Can't run window on this terminal"
return|;
default|default:
return|return
literal|"Unknown error"
return|;
block|}
block|}
end_function

end_unit

