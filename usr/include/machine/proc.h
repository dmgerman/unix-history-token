begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)proc.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_comment
comment|/*  * Machine-dependent part of the proc structure for hp300.  */
end_comment

begin_struct
struct|struct
name|mdproc
block|{
name|int
modifier|*
name|md_regs
decl_stmt|;
comment|/* registers on current frame */
name|int
name|md_flags
decl_stmt|;
comment|/* machine-dependent flags */
block|}
struct|;
end_struct

begin_comment
comment|/* md_flags */
end_comment

begin_define
define|#
directive|define
name|MDP_AST
value|0x0001
end_define

begin_comment
comment|/* async trap pending */
end_comment

begin_define
define|#
directive|define
name|MDP_HPUX
value|0x0002
end_define

begin_comment
comment|/* HP-UX process */
end_comment

begin_define
define|#
directive|define
name|MDP_HPUXTRACE
value|0x0004
end_define

begin_comment
comment|/* being traced by HP-UX process */
end_comment

begin_define
define|#
directive|define
name|MDP_HPUXMMAP
value|0x0008
end_define

begin_comment
comment|/* VA space is multiply mapped */
end_comment

begin_define
define|#
directive|define
name|MDP_CCBDATA
value|0x0010
end_define

begin_comment
comment|/* copyback caching of data (68040) */
end_comment

begin_define
define|#
directive|define
name|MDP_CCBSTACK
value|0x0020
end_define

begin_comment
comment|/* copyback caching of stack (68040) */
end_comment

end_unit

