begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)setjmperr.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|LIBC_SCCS and not lint
end_endif

begin_define
define|#
directive|define
name|ERRMSG
value|"longjmp botch\n"
end_define

begin_comment
comment|/*  * This routine is called from longjmp() when an error occurs.  * Programs that wish to exit gracefully from this error may  * write their own versions.  * If this routine returns, the program is aborted.  */
end_comment

begin_macro
name|longjmperror
argument_list|()
end_macro

begin_block
block|{
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
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

