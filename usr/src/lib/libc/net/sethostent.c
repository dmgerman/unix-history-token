begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)sethostent.c	6.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|LIBC_SCCS and not lint
end_endif

begin_comment
comment|/*  * These are dummy routines to allow old programs that used /etc/hosts  * to compile and work with the BIND name server  */
end_comment

begin_macro
name|sethostent
argument_list|(
argument|stayopen
argument_list|)
end_macro

begin_block
block|{
ifdef|#
directive|ifdef
name|lint
name|stayopen
operator|=
name|stayopen
expr_stmt|;
endif|#
directive|endif
block|}
end_block

begin_macro
name|endhostent
argument_list|()
end_macro

begin_block
block|{}
end_block

begin_macro
name|sethostfile
argument_list|(
argument|name
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_block
block|{
ifdef|#
directive|ifdef
name|lint
name|name
operator|=
name|name
expr_stmt|;
endif|#
directive|endif
block|}
end_block

end_unit

