begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)asm.h	8.1 (Berkeley) 6/11/93  *  * from: $Header: asm.h,v 1.5 92/11/26 03:04:42 torek Exp $  */
end_comment

begin_comment
comment|/*  * GCC __asm constructs for doing assembly stuff.  */
end_comment

begin_comment
comment|/*  * ``Routines'' to load and store from/to alternate address space.  * The location can be a variable, the asi value (address space indicator)  * must be a constant.  *  * N.B.: You can put as many special functions here as you like, since  * they cost no kernel space or time if they are not used.  *  * These were static inline functions, but gcc screws up the constraints  * on the address space identifiers (the "n"umeric value part) because  * it inlines too late, so we have to use the funny valued-macro syntax.  */
end_comment

begin_comment
comment|/* load byte from alternate address space */
end_comment

begin_define
define|#
directive|define
name|lduba
parameter_list|(
name|loc
parameter_list|,
name|asi
parameter_list|)
value|({ \ 	register int _lduba_v; \ 	__asm __volatile("lduba [%1]%2,%0" : "=r" (_lduba_v) : \ 	    "r" ((int)(loc)), "n" (asi)); \ 	_lduba_v; \ })
end_define

begin_comment
comment|/* load int from alternate address space */
end_comment

begin_define
define|#
directive|define
name|lda
parameter_list|(
name|loc
parameter_list|,
name|asi
parameter_list|)
value|({ \ 	register int _lda_v; \ 	__asm __volatile("lda [%1]%2,%0" : "=r" (_lda_v) : \ 	    "r" ((int)(loc)), "n" (asi)); \ 	_lda_v; \ })
end_define

begin_comment
comment|/* store byte to alternate address space */
end_comment

begin_define
define|#
directive|define
name|stba
parameter_list|(
name|loc
parameter_list|,
name|asi
parameter_list|,
name|value
parameter_list|)
value|({ \ 	__asm __volatile("stba %0,[%1]%2" : : \ 	    "r" ((int)(value)), "r" ((int)(loc)), "n" (asi)); \ })
end_define

begin_comment
comment|/* store int to alternate address space */
end_comment

begin_define
define|#
directive|define
name|sta
parameter_list|(
name|loc
parameter_list|,
name|asi
parameter_list|,
name|value
parameter_list|)
value|({ \ 	__asm __volatile("sta %0,[%1]%2" : : \ 	    "r" ((int)(value)), "r" ((int)(loc)), "n" (asi)); \ })
end_define

end_unit

