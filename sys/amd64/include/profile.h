begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)profile.h	8.1 (Berkeley) 6/11/93  * $Id: profile.h,v 1.4 1994/09/15 16:27:14 paul Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PROFILE_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PROFILE_H_
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|_MCOUNT_DECL
value|static inline void _mcount
end_define

begin_define
define|#
directive|define
name|MCOUNT
define|\
value|extern void mcount() asm("mcount"); void mcount() { \ 	fptrint_t selfpc, frompc; \
comment|/* \ 	 * Find the return address for mcount, \ 	 * and the return address for mcount's caller. \ 	 * \ 	 * selfpc = pc pushed by call to mcount \ 	 */
value|\ 	asm("movl 4(%%ebp),%0" : "=r" (selfpc)); \
comment|/* \ 	 * frompc = pc pushed by call to mcount's caller. \ 	 * The caller's stack frame has already been built, so %ebp is \ 	 * the caller's frame pointer.  The caller's raddr is in the \ 	 * caller's frame following the caller's caller's frame pointer. \ 	 */
value|\ 	asm("movl (%%ebp),%0" : "=r" (frompc)); \ 	frompc = ((fptrint_t *)frompc)[1]; \ 	_mcount(frompc, selfpc); \ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_MCOUNT_DECL
value|void mcount
end_define

begin_define
define|#
directive|define
name|MCOUNT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MCOUNT_ENTER
value|{ save_eflags = read_eflags(); disable_intr(); }
end_define

begin_define
define|#
directive|define
name|MCOUNT_EXIT
value|(write_eflags(save_eflags))
end_define

begin_define
define|#
directive|define
name|CALIB_SCALE
value|1000
end_define

begin_define
define|#
directive|define
name|KCOUNT
parameter_list|(
name|p
parameter_list|,
name|index
parameter_list|)
value|((p)->kcount[(index) \ 			 / (HISTFRACTION * sizeof(*(p)->kcount))])
end_define

begin_define
define|#
directive|define
name|PC_TO_I
parameter_list|(
name|p
parameter_list|,
name|pc
parameter_list|)
value|((fptrint_t)(pc) - (fptrint_t)(p)->lowpc)
end_define

begin_comment
comment|/* An unsigned integral type that can hold function pointers. */
end_comment

begin_typedef
typedef|typedef
name|u_int
name|fptrint_t
typedef|;
end_typedef

begin_comment
comment|/*  * An unsigned integral type that can hold non-negative difference between  * function pointers.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|fptrdiff_t
typedef|;
end_typedef

begin_decl_stmt
name|u_int
name|cputime
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mcount
name|__P
argument_list|(
operator|(
name|fptrint_t
name|frompc
operator|,
name|fptrint_t
name|selfpc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mexitcount
name|__P
argument_list|(
operator|(
name|fptrint_t
name|selfpc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !MACHINE_PROFILE_H */
end_comment

end_unit

