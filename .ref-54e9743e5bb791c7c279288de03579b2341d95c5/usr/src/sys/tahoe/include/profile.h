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
value|extern void mcount(cntpa) asm("mcount"); void mcount(cntpa) long **cntpa; { \ 	int selfpc, frompcindex; \
comment|/* \ 	 * Find the return address for mcount, \ 	 * and address of counter pointer. \ 	 */
value|\ 	selfpc = *((char **)&cntpa-3);
comment|/* -8(fp) */
value|\ 	frompcindex = \ 	    (unsigned short *)(*((((long *)*((char **)&cntpa-1)))-2)); \ 	_mcount(frompcindex, selfpc); \ }
end_define

end_unit

