begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific written prior permission. This software  * is provided ``as is'' without express or implied warranty.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)strchr.c	5.3 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)index.c	5.3 (Berkeley) 6/2/88"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|char
modifier|*
name|strchr
parameter_list|(
name|p
parameter_list|,
name|ch
parameter_list|)
specifier|register
name|char
modifier|*
name|p
decl_stmt|,
name|ch
decl_stmt|;
block|{
for|for
control|(
init|;
condition|;
operator|++
name|p
control|)
block|{
if|if
condition|(
operator|*
name|p
operator|==
name|ch
condition|)
return|return
operator|(
name|p
operator|)
return|;
if|if
condition|(
operator|!
operator|*
name|p
condition|)
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
comment|/* NOTREACHED */
block|}
end_function

end_unit

