begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)sethostent.c	6.6 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<arpa/nameser.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<resolv.h>
end_include

begin_macro
name|sethostent
argument_list|(
argument|stayopen
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|stayopen
condition|)
name|_res
operator|.
name|options
operator||=
name|RES_STAYOPEN
operator||
name|RES_USEVC
expr_stmt|;
block|}
end_block

begin_macro
name|endhostent
argument_list|()
end_macro

begin_block
block|{
name|_res
operator|.
name|options
operator|&=
operator|~
operator|(
name|RES_STAYOPEN
operator||
name|RES_USEVC
operator|)
expr_stmt|;
name|_res_close
argument_list|()
expr_stmt|;
block|}
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

