begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)ovprintf.c	1.3 (Berkeley) 6/7/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * This version of printf calls doprnt, and as such is not portable,  * since doprnt is written in pdp-11 assembly language.  (There is a  * vax doprnt which has the first 2 arguments reversed.  We don't use it.)  * This version is used because it is about 900 bytes smaller than the  * portable version, which is also included in case it is needed.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TRACE
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_undef
undef|#
directive|undef
name|putchar
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|printf
argument_list|(
argument|fmt
argument_list|,
argument|args
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|fmt
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|_doprnt
argument_list|(
name|fmt
argument_list|,
operator|&
name|args
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|_strout
argument_list|(
name|string
argument_list|,
name|count
argument_list|,
name|adjust
argument_list|,
name|file
argument_list|,
name|fillch
argument_list|)
specifier|register
name|char
operator|*
name|string
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|register
name|count
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|int
name|adjust
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|struct
name|_iobuf
modifier|*
name|file
decl_stmt|;
end_decl_stmt

begin_block
block|{
while|while
condition|(
name|adjust
operator|<
literal|0
condition|)
block|{
if|if
condition|(
operator|*
name|string
operator|==
literal|'-'
operator|&&
name|fillch
operator|==
literal|'0'
condition|)
block|{
name|putchar
argument_list|(
operator|*
name|string
operator|++
argument_list|)
expr_stmt|;
name|count
operator|--
expr_stmt|;
block|}
name|putchar
argument_list|(
name|fillch
argument_list|)
expr_stmt|;
name|adjust
operator|++
expr_stmt|;
block|}
while|while
condition|(
operator|--
name|count
operator|>=
literal|0
condition|)
name|putchar
argument_list|(
operator|*
name|string
operator|++
argument_list|)
expr_stmt|;
while|while
condition|(
name|adjust
condition|)
block|{
name|putchar
argument_list|(
name|fillch
argument_list|)
expr_stmt|;
name|adjust
operator|--
expr_stmt|;
block|}
block|}
end_block

end_unit

