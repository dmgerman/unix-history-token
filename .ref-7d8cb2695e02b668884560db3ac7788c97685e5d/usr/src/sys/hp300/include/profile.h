begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)profile.h	7.1 (Berkeley) %G%  */
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
value|extern void mcount() asm("mcount"); void mcount() { \ 	int selfpc, frompcindex; \ 	asm("movl a6@(4),%0" : "=r" (selfpc)); \ 	asm("movl a6@(0)@(4),%0" : "=r" (frompcindex)); \ 	_mcount(frompcindex, selfpc); \ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * The following two macros do splhigh and splx respectively.  * They have to be defined this way because these are real  * functions on the HP, and we do not want to invoke mcount  * recursively.  */
end_comment

begin_define
define|#
directive|define
name|MCOUNT_ENTER
define|\
value|asm("movw	sr,%0" : "=g" (s)); \ 	asm("movw	#0x2700,sr")
end_define

begin_define
define|#
directive|define
name|MCOUNT_EXIT
define|\
value|asm("movw	%0,sr" : : "g" (s))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

