begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: $Hdr: ioptohb.h,v 4.300 91/06/09 06:38:04 root Rel41 $ SONY  *  *	@(#)ioptohb.h	8.1 (Berkeley) 6/11/93  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IOPTOHB__
end_ifndef

begin_define
define|#
directive|define
name|__IOPTOHB__
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_SINGLE
end_ifdef

begin_define
define|#
directive|define
name|iop
value|hb
end_define

begin_define
define|#
directive|define
name|im_driver
value|hm_driver
end_define

begin_define
define|#
directive|define
name|im_ctlr
value|hm_ctlr
end_define

begin_define
define|#
directive|define
name|im_alive
value|hm_alive
end_define

begin_define
define|#
directive|define
name|im_addr
value|hm_addr
end_define

begin_define
define|#
directive|define
name|im_intr
value|hm_intr
end_define

begin_define
define|#
directive|define
name|im_scnum
value|hm_scnum
end_define

begin_define
define|#
directive|define
name|im_hd
value|hm_hd
end_define

begin_define
define|#
directive|define
name|im_tab
value|hm_tab
end_define

begin_define
define|#
directive|define
name|ii_driver
value|hi_driver
end_define

begin_define
define|#
directive|define
name|ii_unit
value|hi_unit
end_define

begin_define
define|#
directive|define
name|ii_ctlr
value|hi_ctlr
end_define

begin_define
define|#
directive|define
name|ii_slave
value|hi_slave
end_define

begin_define
define|#
directive|define
name|ii_addr
value|hi_addr
end_define

begin_define
define|#
directive|define
name|ii_intr
value|hi_intr
end_define

begin_define
define|#
directive|define
name|ii_dk
value|hi_dk
end_define

begin_define
define|#
directive|define
name|ii_flags
value|hi_flags
end_define

begin_define
define|#
directive|define
name|ii_alive
value|hi_alive
end_define

begin_define
define|#
directive|define
name|ii_type
value|hi_type
end_define

begin_define
define|#
directive|define
name|ii_forw
value|hi_forw
end_define

begin_define
define|#
directive|define
name|ii_mi
value|hi_mi
end_define

begin_define
define|#
directive|define
name|ii_hd
value|hi_hd
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_SINGLE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__IOPTOHB__ */
end_comment

end_unit

