begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)frame.h	8.1 (Berkeley) 6/11/93  *  * from: $Header: frame.h,v 1.5 92/11/26 02:04:35 torek Exp $  */
end_comment

begin_comment
comment|/*  * Sparc stack frame format.  *  * Note that the contents of each stack frame may be held only in  * machine register windows.  In order to get an accurate picture  * of the frame, you must first force the kernel to write any such  * windows to the stack.  */
end_comment

begin_struct
struct|struct
name|frame
block|{
name|int
name|fr_local
index|[
literal|8
index|]
decl_stmt|;
comment|/* space to save locals (%l0..%l7) */
name|int
name|fr_arg
index|[
literal|6
index|]
decl_stmt|;
comment|/* space to save arguments (%i0..%i5) */
name|struct
name|frame
modifier|*
name|fr_fp
decl_stmt|;
comment|/* space to save frame pointer (%i6) */
name|int
name|fr_pc
decl_stmt|;
comment|/* space to save return pc (%i7) */
comment|/* 	 * SunOS reserves another 8 words here; this is pointless 	 * but we do it for compatibility. 	 */
name|int
name|fr_xxx
decl_stmt|;
comment|/* `structure return pointer' (unused) */
name|int
name|fr_argd
index|[
literal|6
index|]
decl_stmt|;
comment|/* `arg dump area' (lunacy) */
name|int
name|fr_argx
index|[
literal|1
index|]
decl_stmt|;
comment|/* arg extension (args 7..n; variable size) */
block|}
struct|;
end_struct

end_unit

