begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1982, 1986, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: Utah $Hdr: reg.h 1.1 90/07/09$  *  *	@(#)reg.h	8.3 (Berkeley) 1/27/94  */
end_comment

begin_comment
comment|/*  * Location of the users' stored  * registers relative to D0.  * Usage is u.u_ar0[XX].  */
end_comment

begin_define
define|#
directive|define
name|D0
value|(0)
end_define

begin_define
define|#
directive|define
name|D1
value|(1)
end_define

begin_define
define|#
directive|define
name|D2
value|(2)
end_define

begin_define
define|#
directive|define
name|D3
value|(3)
end_define

begin_define
define|#
directive|define
name|D4
value|(4)
end_define

begin_define
define|#
directive|define
name|D5
value|(5)
end_define

begin_define
define|#
directive|define
name|D6
value|(6)
end_define

begin_define
define|#
directive|define
name|D7
value|(7)
end_define

begin_define
define|#
directive|define
name|A0
value|(8)
end_define

begin_define
define|#
directive|define
name|A1
value|(9)
end_define

begin_define
define|#
directive|define
name|A2
value|(10)
end_define

begin_define
define|#
directive|define
name|A3
value|(11)
end_define

begin_define
define|#
directive|define
name|A4
value|(12)
end_define

begin_define
define|#
directive|define
name|A5
value|(13)
end_define

begin_define
define|#
directive|define
name|A6
value|(14)
end_define

begin_define
define|#
directive|define
name|A7
value|(15)
end_define

begin_define
define|#
directive|define
name|SP
value|A7
end_define

begin_define
define|#
directive|define
name|PC
value|(17)
end_define

begin_define
define|#
directive|define
name|PS
value|(16)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|IPCREG
end_ifdef

begin_define
define|#
directive|define
name|NIPCREG
value|16
end_define

begin_decl_stmt
name|int
name|ipcreg
index|[
name|NIPCREG
index|]
init|=
block|{
name|D0
block|,
name|D1
block|,
name|D2
block|,
name|D3
block|,
name|D4
block|,
name|D5
block|,
name|D6
block|,
name|D7
block|,
name|A0
block|,
name|A1
block|,
name|A2
block|,
name|A3
block|,
name|A4
block|,
name|A5
block|,
name|A6
block|,
name|A7
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Register set accessible via /proc/$pid/reg  */
end_comment

begin_struct
struct|struct
name|reg
block|{
name|int
name|r_regs
index|[
literal|16
index|]
decl_stmt|;
comment|/* numbered as above */
name|int
name|r_pc
decl_stmt|;
name|int
name|r_sr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Register set accessible via /proc/$pid/fpreg  */
end_comment

begin_struct
struct|struct
name|fpreg
block|{
name|int
name|fpr_xxx
decl_stmt|;
comment|/* not implemented */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Due to a mental lapse somewhere down the line, wait returns its values  * in strange registers.  Kludge it up here so we don't have to in the  * machine-independent code.  */
end_comment

begin_define
define|#
directive|define
name|R0
value|D1
end_define

begin_define
define|#
directive|define
name|R1
value|A0
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

