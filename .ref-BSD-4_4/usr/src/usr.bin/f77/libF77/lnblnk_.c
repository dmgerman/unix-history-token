begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * This module is believed to contain source code proprietary to AT&T.  * Use and redistribution is subject to the Berkeley Software License  * Agreement and your Software Agreement with AT&T (Western Electric).  */
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
literal|"@(#)lnblnk_.c	5.3 (Berkeley) 4/12/91"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * find last occurrence of a non-blank character in string  *  * calling sequence:  *	character*(*) string  *	indx = lnblnk (string)  * where:  *	indx will be the index of the last occurence  *	of a non-blank character in string, or zero if not found.  */
end_comment

begin_function
name|long
name|lnblnk_
parameter_list|(
name|str
parameter_list|,
name|slen
parameter_list|)
name|char
modifier|*
name|str
decl_stmt|;
name|long
name|slen
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|p
init|=
name|str
operator|+
name|slen
decl_stmt|;
while|while
condition|(
operator|--
name|p
operator|>=
name|str
operator|&&
operator|*
name|p
operator|==
literal|' '
condition|)
empty_stmt|;
return|return
operator|(
call|(
name|long
call|)
argument_list|(
operator|++
name|p
operator|-
name|str
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

