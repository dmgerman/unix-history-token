begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1990, 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: Utah $Hdr: cons.h 1.1 90/07/09$  *  * from: hp300/hp300/cons.h	7.1 (Berkeley) 6/4/92  *  *	@(#)cons.h	8.1 (Berkeley) 6/10/93  */
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

