begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)psl.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PSL_C
end_ifndef

begin_comment
comment|/*  * MC68000 program status word  */
end_comment

begin_define
define|#
directive|define
name|PSL_C
value|0x0001
end_define

begin_comment
comment|/* carry bit */
end_comment

begin_define
define|#
directive|define
name|PSL_V
value|0x0002
end_define

begin_comment
comment|/* overflow bit */
end_comment

begin_define
define|#
directive|define
name|PSL_Z
value|0x0004
end_define

begin_comment
comment|/* zero bit */
end_comment

begin_define
define|#
directive|define
name|PSL_N
value|0x0008
end_define

begin_comment
comment|/* negative bit */
end_comment

begin_define
define|#
directive|define
name|PSL_X
value|0x0010
end_define

begin_comment
comment|/* extend bit */
end_comment

begin_define
define|#
directive|define
name|PSL_ALLCC
value|0x001F
end_define

begin_comment
comment|/* all cc bits - unlikely */
end_comment

begin_define
define|#
directive|define
name|PSL_IPL0
value|0x0000
end_define

begin_comment
comment|/* interrupt priority level 0 */
end_comment

begin_define
define|#
directive|define
name|PSL_IPL1
value|0x0100
end_define

begin_comment
comment|/* interrupt priority level 1 */
end_comment

begin_define
define|#
directive|define
name|PSL_IPL2
value|0x0200
end_define

begin_comment
comment|/* interrupt priority level 2 */
end_comment

begin_define
define|#
directive|define
name|PSL_IPL3
value|0x0300
end_define

begin_comment
comment|/* interrupt priority level 3 */
end_comment

begin_define
define|#
directive|define
name|PSL_IPL4
value|0x0400
end_define

begin_comment
comment|/* interrupt priority level 4 */
end_comment

begin_define
define|#
directive|define
name|PSL_IPL5
value|0x0500
end_define

begin_comment
comment|/* interrupt priority level 5 */
end_comment

begin_define
define|#
directive|define
name|PSL_IPL6
value|0x0600
end_define

begin_comment
comment|/* interrupt priority level 6 */
end_comment

begin_define
define|#
directive|define
name|PSL_IPL7
value|0x0700
end_define

begin_comment
comment|/* interrupt priority level 7 */
end_comment

begin_define
define|#
directive|define
name|PSL_M
value|0x1000
end_define

begin_comment
comment|/* master (kernel) sp vs intr sp */
end_comment

begin_define
define|#
directive|define
name|PSL_S
value|0x2000
end_define

begin_comment
comment|/* supervisor enable bit */
end_comment

begin_comment
comment|/*	PSL_T0		0x4000		   ??? T0 on 68020, 8000 is T1 */
end_comment

begin_define
define|#
directive|define
name|PSL_T
value|0x8000
end_define

begin_comment
comment|/* trace enable bit */
end_comment

begin_define
define|#
directive|define
name|PSL_LOWIPL
value|(PSL_S)
end_define

begin_define
define|#
directive|define
name|PSL_HIGHIPL
value|(PSL_S | PSL_IPL7)
end_define

begin_define
define|#
directive|define
name|PSL_IPL
value|(PSL_IPL7)
end_define

begin_define
define|#
directive|define
name|PSL_USER
value|(0)
end_define

begin_define
define|#
directive|define
name|PSL_MBZ
value|0xFFFF58E0
end_define

begin_comment
comment|/* must be zero bits */
end_comment

begin_define
define|#
directive|define
name|PSL_USERSET
value|(0)
end_define

begin_define
define|#
directive|define
name|PSL_USERCLR
value|(PSL_S | PSL_IPL7 | PSL_MBZ)
end_define

begin_define
define|#
directive|define
name|USERMODE
parameter_list|(
name|ps
parameter_list|)
value|(((ps)& PSL_S) == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

