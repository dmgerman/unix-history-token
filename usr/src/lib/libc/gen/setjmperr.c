begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)setjmperr.c	5.4 (Berkeley) 6/27/88"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_comment
comment|/*  * This routine is called from longjmp() when an error occurs.  * Programs that wish to exit gracefully from this error may  * write their own versions.  * If this routine returns, the program is aborted.  */
end_comment

begin_macro
name|longjmperror
argument_list|()
end_macro

begin_block
block|{
define|#
directive|define
name|ERRMSG
value|"longjmp botch\n"
name|write
argument_list|(
literal|2
argument_list|,
name|ERRMSG
argument_list|,
sizeof|sizeof
argument_list|(
name|ERRMSG
argument_list|)
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

