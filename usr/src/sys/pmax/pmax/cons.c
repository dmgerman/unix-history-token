begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department and Ralph Campbell.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: cons.c 1.1 90/07/09$  *  *	@(#)cons.c	7.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"proc.h"
end_include

begin_include
include|#
directive|include
file|"systm.h"
end_include

begin_include
include|#
directive|include
file|"buf.h"
end_include

begin_include
include|#
directive|include
file|"ioctl.h"
end_include

begin_include
include|#
directive|include
file|"tty.h"
end_include

begin_include
include|#
directive|include
file|"file.h"
end_include

begin_include
include|#
directive|include
file|"conf.h"
end_include

begin_include
include|#
directive|include
file|"../include/machMon.h"
end_include

begin_comment
comment|/*  * Console output may be redirected to another tty  * (e.g. a window); if so, constty will point to the current  * virtual console.  */
end_comment

begin_decl_stmt
name|struct
name|tty
modifier|*
name|constty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* virtual console output device */
end_comment

begin_comment
comment|/*  * Get character from console.  */
end_comment

begin_macro
name|cngetc
argument_list|()
end_macro

begin_block
block|{
name|int
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|()
init|=
operator|(
name|int
argument_list|(
operator|*
argument_list|)
operator|(
operator|)
operator|)
name|MACH_MON_GETCHAR
function_decl|;
return|return
call|(
modifier|*
name|f
call|)
argument_list|()
return|;
block|}
end_block

begin_include
include|#
directive|include
file|"pm.h"
end_include

begin_comment
comment|/*  * Print a character on console.  */
end_comment

begin_expr_stmt
name|cnputc
argument_list|(
name|c
argument_list|)
specifier|register
name|int
name|c
expr_stmt|;
end_expr_stmt

begin_block
block|{
if|#
directive|if
name|NPM
operator|>
literal|0
name|pmPutc
argument_list|(
name|c
argument_list|)
expr_stmt|;
else|#
directive|else
name|int
name|s
decl_stmt|;
name|void
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|()
init|=
operator|(
name|void
argument_list|(
operator|*
argument_list|)
operator|(
operator|)
operator|)
name|MACH_MON_PUTCHAR
function_decl|;
name|s
operator|=
name|splhigh
argument_list|()
expr_stmt|;
call|(
modifier|*
name|f
call|)
argument_list|(
name|c
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_block

end_unit

