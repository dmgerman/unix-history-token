begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: cons.h 1.4 88/12/03$  *  *	@(#)cons.h	7.2 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|consdev
block|{
name|int
function_decl|(
modifier|*
name|cn_probe
function_decl|)
parameter_list|()
function_decl|;
comment|/* probe hardware and fill in consdev info */
name|int
function_decl|(
modifier|*
name|cn_init
function_decl|)
parameter_list|()
function_decl|;
comment|/* turn on as console */
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
name|dev_t
name|cn_dev
decl_stmt|;
comment|/* major/minor of device */
name|short
name|cn_pri
decl_stmt|;
comment|/* pecking order; the higher the better */
block|}
struct|;
end_struct

begin_comment
comment|/* values for cn_pri - reflect our policy for console selection */
end_comment

begin_define
define|#
directive|define
name|CN_DEAD
value|0
end_define

begin_comment
comment|/* device doesn't exist */
end_comment

begin_define
define|#
directive|define
name|CN_NORMAL
value|1
end_define

begin_comment
comment|/* device exists but is nothing special */
end_comment

begin_define
define|#
directive|define
name|CN_INTERNAL
value|2
end_define

begin_comment
comment|/* "internal" bit-mapped display */
end_comment

begin_define
define|#
directive|define
name|CN_REMOTE
value|3
end_define

begin_comment
comment|/* serial interface with remote bit set */
end_comment

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|CONSMAJOR
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|consdev
name|constab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|consdev
modifier|*
name|cn_tab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tty
modifier|*
name|cn_tty
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

