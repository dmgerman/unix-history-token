begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)fpu_arith.h	7.3 (Berkeley) %G%  *  * from: $Header: fpu_arith.h,v 1.3 92/11/26 01:30:50 torek Exp $  */
end_comment

begin_comment
comment|/*  * Extended-precision arithmetic.  *  * We hold the notion of a `carry register', which may or may not be a  * machine carry bit or register.  On the SPARC, it is just the machine's  * carry bit.  *  * In the worst case, you can compute the carry from x+y as  *	(unsigned)(x + y)< (unsigned)x  * and from x+y+c as  *	((unsigned)(x + y + c)<= (unsigned)x&& (y|c) != 0)  * for example.  */
end_comment

begin_comment
comment|/* set up for extended-precision arithemtic */
end_comment

begin_define
define|#
directive|define
name|FPU_DECL_CARRY
end_define

begin_comment
comment|/*  * We have three kinds of add:  *	add with carry:					  r = x + y + c  *	add (ignoring current carry) and set carry:	c'r = x + y + 0  *	add with carry and set carry:			c'r = x + y + c  * The macros use `C' for `use carry' and `S' for `set carry'.  * Note that the state of the carry is undefined after ADDC and SUBC,  * so if all you have for these is `add with carry and set carry',  * that is OK.  *  * The same goes for subtract, except that we compute x - y - c.  *  * Finally, we have a way to get the carry into a `regular' variable,  * or set it from a value.  SET_CARRY turns 0 into no-carry, nonzero  * into carry; GET_CARRY sets its argument to 0 or 1.  */
end_comment

begin_define
define|#
directive|define
name|FPU_ADDC
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|asm volatile("addx %1,%2,%0" : "=r"(r) : "r"(x), "r"(y))
end_define

begin_define
define|#
directive|define
name|FPU_ADDS
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|asm volatile("addcc %1,%2,%0" : "=r"(r) : "r"(x), "r"(y))
end_define

begin_define
define|#
directive|define
name|FPU_ADDCS
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|asm volatile("addxcc %1,%2,%0" : "=r"(r) : "r"(x), "r"(y))
end_define

begin_define
define|#
directive|define
name|FPU_SUBC
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|asm volatile("subx %1,%2,%0" : "=r"(r) : "r"(x), "r"(y))
end_define

begin_define
define|#
directive|define
name|FPU_SUBS
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|asm volatile("subcc %1,%2,%0" : "=r"(r) : "r"(x), "r"(y))
end_define

begin_define
define|#
directive|define
name|FPU_SUBCS
parameter_list|(
name|r
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|asm volatile("subxcc %1,%2,%0" : "=r"(r) : "r"(x), "r"(y))
end_define

begin_define
define|#
directive|define
name|FPU_GET_CARRY
parameter_list|(
name|r
parameter_list|)
value|asm volatile("addx %%g0,%%g0,%0" : "=r"(r))
end_define

begin_define
define|#
directive|define
name|FPU_SET_CARRY
parameter_list|(
name|v
parameter_list|)
value|asm volatile("addcc %0,-1,%%g0" : : "r"(v))
end_define

begin_define
define|#
directive|define
name|FPU_SHL1_BY_ADD
end_define

begin_comment
comment|/* shift left 1 faster by ADDC than (a<<1)|(b>>31) */
end_comment

end_unit

