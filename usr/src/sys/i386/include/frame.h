begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)frame.h	8.1 (Berkeley) 6/11/93  */
end_comment

begin_comment
comment|/*  * System stack frames.  */
end_comment

begin_comment
comment|/*  * Exception/Trap Stack Frame  */
end_comment

begin_struct
struct|struct
name|trapframe
block|{
name|int
name|tf_es
decl_stmt|;
name|int
name|tf_ds
decl_stmt|;
name|int
name|tf_edi
decl_stmt|;
name|int
name|tf_esi
decl_stmt|;
name|int
name|tf_ebp
decl_stmt|;
name|int
name|tf_isp
decl_stmt|;
name|int
name|tf_ebx
decl_stmt|;
name|int
name|tf_edx
decl_stmt|;
name|int
name|tf_ecx
decl_stmt|;
name|int
name|tf_eax
decl_stmt|;
name|int
name|tf_trapno
decl_stmt|;
comment|/* below portion defined in 386 hardware */
name|int
name|tf_err
decl_stmt|;
name|int
name|tf_eip
decl_stmt|;
name|int
name|tf_cs
decl_stmt|;
name|int
name|tf_eflags
decl_stmt|;
comment|/* below only when transitting rings (e.g. user to kernel) */
name|int
name|tf_esp
decl_stmt|;
name|int
name|tf_ss
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Interrupt stack frame */
end_comment

begin_struct
struct|struct
name|intrframe
block|{
name|int
name|if_vec
decl_stmt|;
name|int
name|if_ppl
decl_stmt|;
name|int
name|if_es
decl_stmt|;
name|int
name|if_ds
decl_stmt|;
name|int
name|if_edi
decl_stmt|;
name|int
name|if_esi
decl_stmt|;
name|int
name|if_ebp
decl_stmt|;
name|int
label|:
literal|32
expr_stmt|;
name|int
name|if_ebx
decl_stmt|;
name|int
name|if_edx
decl_stmt|;
name|int
name|if_ecx
decl_stmt|;
name|int
name|if_eax
decl_stmt|;
name|int
label|:
literal|32
expr_stmt|;
comment|/* for compat with trap frame - trapno */
name|int
label|:
literal|32
expr_stmt|;
comment|/* for compat with trap frame - err */
comment|/* below portion defined in 386 hardware */
name|int
name|if_eip
decl_stmt|;
name|int
name|if_cs
decl_stmt|;
name|int
name|if_eflags
decl_stmt|;
comment|/* below only when transitting rings (e.g. user to kernel) */
name|int
name|if_esp
decl_stmt|;
name|int
name|if_ss
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Call Gate/System Call Stack Frame  */
end_comment

begin_struct
struct|struct
name|syscframe
block|{
name|int
name|sf_edi
decl_stmt|;
name|int
name|sf_esi
decl_stmt|;
name|int
name|sf_ebp
decl_stmt|;
name|int
label|:
literal|32
expr_stmt|;
comment|/* redundant save of isp */
name|int
name|sf_ebx
decl_stmt|;
name|int
name|sf_edx
decl_stmt|;
name|int
name|sf_ecx
decl_stmt|;
name|int
name|sf_eax
decl_stmt|;
name|int
name|sf_eflags
decl_stmt|;
comment|/* below portion defined in 386 hardware */
comment|/*	int	sf_args[N]; 	/* if call gate copy args enabled!*/
name|int
name|sf_eip
decl_stmt|;
name|int
name|sf_cs
decl_stmt|;
comment|/* below only when transitting rings (e.g. user to kernel) */
name|int
name|sf_esp
decl_stmt|;
name|int
name|sf_ss
decl_stmt|;
block|}
struct|;
end_struct

end_unit

