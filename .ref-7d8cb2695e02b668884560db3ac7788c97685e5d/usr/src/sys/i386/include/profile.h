begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)profile.h	7.2 (Berkeley) %G%  */
end_comment

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
value|extern void mcount() asm("mcount"); void mcount() { \ 	int selfpc, frompcindex; \
comment|/* \ 	 * find the return address for mcount, \ 	 * and the return address for mcount's caller. \ 	 * \ 	 * selfpc = pc pushed by mcount call \ 	 */
value|\ 	asm("movl 4(%%ebp),%0" : "=r" (selfpc)); \
comment|/* \ 	 * frompcindex = pc pushed by jsr into self. \ 	 * In GCC the caller's stack frame has already been built so we \ 	 * have to chase a6 to find caller's raddr. \ 	 */
value|\ 	asm("movl (%%ebp),%0" : "=r" (frompcindex)); \ 	frompcindex = ((int *)frompcindex)[1]; \ 	_mcount(frompcindex, selfpc); \ }
end_define

end_unit

