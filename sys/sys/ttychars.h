begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ttychars.h	8.2 (Berkeley) 1/4/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TTYCHARS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TTYCHARS_H_
end_define

begin_comment
comment|/*  * 4.3 COMPATIBILITY FILE  *  * User visible structures and constants related to terminal handling.  */
end_comment

begin_struct
struct|struct
name|ttychars
block|{
name|char
name|tc_erase
decl_stmt|;
comment|/* erase last character */
name|char
name|tc_kill
decl_stmt|;
comment|/* erase entire line */
name|char
name|tc_intrc
decl_stmt|;
comment|/* interrupt */
name|char
name|tc_quitc
decl_stmt|;
comment|/* quit */
name|char
name|tc_startc
decl_stmt|;
comment|/* start output */
name|char
name|tc_stopc
decl_stmt|;
comment|/* stop output */
name|char
name|tc_eofc
decl_stmt|;
comment|/* end-of-file */
name|char
name|tc_brkc
decl_stmt|;
comment|/* input delimiter (like nl) */
name|char
name|tc_suspc
decl_stmt|;
comment|/* stop process signal */
name|char
name|tc_dsuspc
decl_stmt|;
comment|/* delayed stop process signal */
name|char
name|tc_rprntc
decl_stmt|;
comment|/* reprint line */
name|char
name|tc_flushc
decl_stmt|;
comment|/* flush output (toggles) */
name|char
name|tc_werasc
decl_stmt|;
comment|/* word erase */
name|char
name|tc_lnextc
decl_stmt|;
comment|/* literal next character */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|USE_OLD_TTY
end_ifdef

begin_include
include|#
directive|include
file|<sys/ttydefaults.h>
end_include

begin_comment
comment|/* to pick up character defaults */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_TTYCHARS_H_ */
end_comment

end_unit

