begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
literal|"@(#)wwprintf.c	3.6 %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California,  * All rights reserved.  Redistribution permitted subject to  * the terms of the Berkeley Software License Agreement.  */
end_comment

begin_include
include|#
directive|include
file|"ww.h"
end_include

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_comment
comment|/*VARARGS2*/
end_comment

begin_macro
name|wwprintf
argument_list|(
argument|w
argument_list|,
argument|fmt
argument_list|,
argument|va_alist
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|ww
modifier|*
name|w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|fmt
decl_stmt|;
end_decl_stmt

begin_macro
name|va_dcl
end_macro

begin_block
block|{
include|#
directive|include
file|<stdio.h>
name|struct
name|_iobuf
name|_wwbuf
decl_stmt|;
name|char
name|buf
index|[
literal|1024
index|]
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
comment|/* 	 * A danger is that when buf overflows, _flsbuf() will be 	 * called automatically.  It doesn't check for _IOSTR. 	 * We set the file descriptor to -1 so no actual io will be done. 	 */
name|_wwbuf
operator|.
name|_flag
operator|=
name|_IOWRT
operator|+
name|_IOSTRG
expr_stmt|;
name|_wwbuf
operator|.
name|_base
operator|=
name|_wwbuf
operator|.
name|_ptr
operator|=
name|buf
expr_stmt|;
name|_wwbuf
operator|.
name|_cnt
operator|=
sizeof|sizeof
name|buf
expr_stmt|;
name|_wwbuf
operator|.
name|_file
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* safe */
name|va_start
argument_list|(
name|ap
argument_list|)
expr_stmt|;
name|_doprnt
argument_list|(
name|fmt
argument_list|,
name|ap
argument_list|,
operator|&
name|_wwbuf
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|wwwrite
argument_list|(
name|w
argument_list|,
name|buf
argument_list|,
name|_wwbuf
operator|.
name|_ptr
operator|-
name|buf
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

