begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Eric P. Allman  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted provided  * that: (1) source distributions retain this entire copyright notice and  * comment, and (2) distributions including binaries display the following  * acknowledgement:  ``This product includes software developed by the  * University of California, Berkeley and its contributors'' in the  * documentation or other materials provided with the distribution and in  * all advertising materials mentioning features or use of this software.  * Neither the name of the University nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1988 Regents of the University of California.\n\  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
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
literal|"@(#)matchhdr.c	5.4 (Berkeley) 6/1/90"
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
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<useful.h>
end_include

begin_expr_stmt
name|SCCSID
argument_list|(
argument|@
operator|(
operator|#
operator|)
name|matchhdr
operator|.
name|c
literal|5.4
literal|6
operator|/
literal|1
operator|/
literal|90
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* **  MATCHHDR -- Match header line ** **	Matches a header line in arpanet format (case and white **	space is ignored). ** **	This routine is used by arpa-mailer and sendmail. ** **	Parameters: **		line -- the line to match against. **		pat -- the pattern to match against; must be in **			lower case. ** **	Returns: **		address of the 'value' of the pattern (the beginning **			of the non-white string following the delim). **		NULL if none found. ** **	Side Effects: **		none ** **	Called By: **		maketemp **		sendmail [arpa.c] ** **	Deficiencies: **		It doesn't handle folded lines. */
end_comment

begin_function
name|char
modifier|*
name|matchhdr
parameter_list|(
name|line
parameter_list|,
name|pat
parameter_list|)
name|char
modifier|*
name|line
decl_stmt|;
name|char
modifier|*
name|pat
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
specifier|register
name|char
modifier|*
name|q
decl_stmt|;
for|for
control|(
name|q
operator|=
name|pat
operator|,
name|p
operator|=
name|line
init|;
operator|*
name|q
operator|!=
literal|'\0'
condition|;
name|p
operator|++
operator|,
name|q
operator|++
control|)
if|if
condition|(
name|lowercase
argument_list|(
operator|*
name|p
argument_list|)
operator|!=
operator|*
name|q
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
while|while
condition|(
name|isspace
argument_list|(
operator|*
name|p
argument_list|)
condition|)
name|p
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|p
operator|!=
literal|':'
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
while|while
condition|(
name|isspace
argument_list|(
operator|*
operator|++
name|p
argument_list|)
condition|)
continue|continue;
return|return
operator|(
operator|*
name|p
operator|==
literal|'\0'
condition|?
name|NULL
else|:
name|p
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* **  LOWERCASE -- Convert a character to lower case ** **	If the argument is an upper case letter, it is converted **	to a lower case letter, otherwise it is passed through **	unchanged. ** **	Parameters: **		c -- the character to check. ** **	Returns: **		c converted to lower case. ** **	Side Effects: **		none ** **	Called By: **		matchhdr */
end_comment

begin_expr_stmt
name|lowercase
argument_list|(
name|c
argument_list|)
specifier|register
name|char
name|c
expr_stmt|;
end_expr_stmt

begin_block
block|{
if|if
condition|(
name|isupper
argument_list|(
name|c
argument_list|)
condition|)
name|c
operator|-=
literal|'A'
operator|-
literal|'a'
expr_stmt|;
return|return
operator|(
name|c
operator|)
return|;
block|}
end_block

end_unit

