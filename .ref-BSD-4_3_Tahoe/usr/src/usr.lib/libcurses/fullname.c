begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1981 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)fullname.c	5.3 (Berkeley) 6/30/88"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_define
define|#
directive|define
name|reg
value|register
end_define

begin_comment
comment|/*  *	This routine fills in "def" with the full name of the terminal.  * This is assumed to be the last name in the list of aliases.  *  */
end_comment

begin_function
name|char
modifier|*
name|fullname
parameter_list|(
name|bp
parameter_list|,
name|def
parameter_list|)
name|reg
name|char
modifier|*
name|bp
decl_stmt|,
decl|*
name|def
decl_stmt|;
end_function

begin_block
block|{
name|reg
name|char
modifier|*
name|cp
decl_stmt|;
operator|*
name|def
operator|=
literal|0
expr_stmt|;
comment|/* in case no name */
while|while
condition|(
operator|*
name|bp
operator|&&
operator|*
name|bp
operator|!=
literal|':'
condition|)
block|{
name|cp
operator|=
name|def
expr_stmt|;
comment|/* start of answer */
while|while
condition|(
operator|*
name|bp
operator|&&
operator|*
name|bp
operator|!=
literal|':'
operator|&&
operator|*
name|bp
operator|!=
literal|'|'
condition|)
block|{
operator|*
name|cp
operator|++
operator|=
operator|*
name|bp
operator|++
expr_stmt|;
comment|/* copy name over */
block|}
operator|*
name|cp
operator|=
literal|0
expr_stmt|;
comment|/* zero end of name */
if|if
condition|(
operator|*
name|bp
operator|==
literal|'|'
condition|)
block|{
name|bp
operator|++
expr_stmt|;
comment|/* skip over '|' if that is case */
block|}
block|}
return|return
operator|(
name|def
operator|)
return|;
block|}
end_block

end_unit

