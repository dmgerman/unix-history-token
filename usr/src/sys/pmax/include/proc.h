begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)proc.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_comment
comment|/*  * Machine-dependent part of the proc structure for DEC Station.  */
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
name|int
name|md_upte
index|[
name|UPAGES
index|]
decl_stmt|;
comment|/* ptes for mapping u page */
name|int
name|md_ss_addr
decl_stmt|;
comment|/* single step address for ptrace */
name|int
name|md_ss_instr
decl_stmt|;
comment|/* single step instruction for ptrace */
block|}
struct|;
end_struct

begin_comment
comment|/* md_flags */
end_comment

begin_define
define|#
directive|define
name|MDP_FPUSED
value|0x0001
end_define

begin_comment
comment|/* floating point coprocessor used */
end_comment

begin_define
define|#
directive|define
name|MDP_ULTRIX
value|0x0002
end_define

begin_comment
comment|/* ULTRIX process (ULTRIXCOMPAT) */
end_comment

end_unit

