begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  *	@(#)cons.h	7.1 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|consdev
block|{
name|int
name|cn_disabled
decl_stmt|;
comment|/* If true use rom I/O routines */
name|int
name|cn_screen
decl_stmt|;
comment|/* True iff console is a screen/keyboard */
name|dev_t
name|cn_dev
decl_stmt|;
comment|/* major/minor of device */
name|struct
name|pmax_fb
modifier|*
name|cn_fb
decl_stmt|;
comment|/* Frame buffer struct for console screen */
name|int
function_decl|(
modifier|*
name|cn_getc
function_decl|)
parameter_list|()
function_decl|;
comment|/* kernel getchar interface */
name|int
function_decl|(
modifier|*
name|cn_kbdgetc
function_decl|)
parameter_list|()
function_decl|;
comment|/* kernel keyboard getchar interface */
name|void
function_decl|(
modifier|*
name|cn_putc
function_decl|)
parameter_list|()
function_decl|;
comment|/* kernel putchar interface */
name|struct
name|tty
modifier|*
name|cn_tp
decl_stmt|;
comment|/* tty structure for console device */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Major device numbers for possible console devices. XXX  */
end_comment

begin_define
define|#
directive|define
name|DTOPDEV
value|15
end_define

begin_define
define|#
directive|define
name|DCDEV
value|16
end_define

begin_define
define|#
directive|define
name|SCCDEV
value|17
end_define

end_unit

