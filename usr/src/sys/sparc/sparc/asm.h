begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)asm.h	7.3 (Berkeley) %G%  *  * from: $Header: asm.h,v 1.5 92/11/26 03:04:42 torek Exp $  */
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

