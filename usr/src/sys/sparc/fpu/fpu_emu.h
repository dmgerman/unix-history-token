begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)fpu_emu.h	7.3 (Berkeley) %G%  *  * from: $Header: fpu_emu.h,v 1.3 92/11/26 01:30:54 torek Exp $  */
end_comment

begin_comment
comment|/*  * Floating point emulator (tailored for SPARC, but structurally  * machine-independent).  *  * Floating point numbers are carried around internally in an `expanded'  * or `unpacked' form consisting of:  *	- sign  *	- unbiased exponent  *	- mantissa (`1.' + 112-bit fraction + guard + round)  *	- sticky bit  * Any implied `1' bit is inserted, giving a 113-bit mantissa that is  * always nonzero.  Additional low-order `guard' and `round' bits are  * scrunched in, making the entire mantissa 115 bits long.  This is divided  * into four 32-bit words, with `spare' bits left over in the upper part  * of the top word (the high bits of fp_mant[0]).  An internal `exploded'  * number is thus kept within the half-open interval [1.0,2.0) (but see  * the `number classes' below).  This holds even for denormalized numbers:  * when we explode an external denorm, we normalize it, introducing low-order  * zero bits, so that the rest of the code always sees normalized values.  *  * Note that a number of our algorithms use the `spare' bits at the top.  * The most demanding algorithm---the one for sqrt---depends on two such  * bits, so that it can represent values up to (but not including) 8.0,  * and then it needs a carry on top of that, so that we need three `spares'.  *  * The sticky-word is 32 bits so that we can use `OR' operators to goosh  * whole words from the mantissa into it.  *  * All operations are done in this internal extended precision.  According  * to Hennesey& Patterson, Appendix A, rounding can be repeated---that is,  * it is OK to do a+b in extended precision and then round the result to  * single precision---provided single, double, and extended precisions are  * `far enough apart' (they always are), but we will try to avoid any such  * extra work where possible.  */
end_comment

begin_struct
struct|struct
name|fpn
block|{
name|int
name|fp_class
decl_stmt|;
comment|/* see below */
name|int
name|fp_sign
decl_stmt|;
comment|/* 0 => positive, 1 => negative */
name|int
name|fp_exp
decl_stmt|;
comment|/* exponent (unbiased) */
name|int
name|fp_sticky
decl_stmt|;
comment|/* nonzero bits lost at right end */
name|u_int
name|fp_mant
index|[
literal|4
index|]
decl_stmt|;
comment|/* 115-bit mantissa */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FP_NMANT
value|115
end_define

begin_comment
comment|/* total bits in mantissa (incl g,r) */
end_comment

begin_define
define|#
directive|define
name|FP_NG
value|2
end_define

begin_comment
comment|/* number of low-order guard bits */
end_comment

begin_define
define|#
directive|define
name|FP_LG
value|((FP_NMANT - 1)& 31)
end_define

begin_comment
comment|/* log2(1.0) for fp_mant[0] */
end_comment

begin_define
define|#
directive|define
name|FP_QUIETBIT
value|(1<< (FP_LG - 1))
end_define

begin_comment
comment|/* Quiet bit in NaNs (0.5) */
end_comment

begin_define
define|#
directive|define
name|FP_1
value|(1<< FP_LG)
end_define

begin_comment
comment|/* 1.0 in fp_mant[0] */
end_comment

begin_define
define|#
directive|define
name|FP_2
value|(1<< (FP_LG + 1))
end_define

begin_comment
comment|/* 2.0 in fp_mant[0] */
end_comment

begin_comment
comment|/*  * Number classes.  Since zero, Inf, and NaN cannot be represented using  * the above layout, we distinguish these from other numbers via a class.  * In addition, to make computation easier and to follow Appendix N of  * the SPARC Version 8 standard, we give each kind of NaN a separate class.  */
end_comment

begin_define
define|#
directive|define
name|FPC_SNAN
value|-2
end_define

begin_comment
comment|/* signalling NaN (sign irrelevant) */
end_comment

begin_define
define|#
directive|define
name|FPC_QNAN
value|-1
end_define

begin_comment
comment|/* quiet NaN (sign irrelevant) */
end_comment

begin_define
define|#
directive|define
name|FPC_ZERO
value|0
end_define

begin_comment
comment|/* zero (sign matters) */
end_comment

begin_define
define|#
directive|define
name|FPC_NUM
value|1
end_define

begin_comment
comment|/* number (sign matters) */
end_comment

begin_define
define|#
directive|define
name|FPC_INF
value|2
end_define

begin_comment
comment|/* infinity (sign matters) */
end_comment

begin_define
define|#
directive|define
name|ISNAN
parameter_list|(
name|fp
parameter_list|)
value|((fp)->fp_class< 0)
end_define

begin_define
define|#
directive|define
name|ISZERO
parameter_list|(
name|fp
parameter_list|)
value|((fp)->fp_class == 0)
end_define

begin_define
define|#
directive|define
name|ISINF
parameter_list|(
name|fp
parameter_list|)
value|((fp)->fp_class == FPC_INF)
end_define

begin_comment
comment|/*  * ORDER(x,y) `sorts' a pair of `fpn *'s so that the right operand (y) points  * to the `more significant' operand for our purposes.  Appendix N says that  * the result of a computation involving two numbers are:  *  *	If both are SNaN: operand 2, converted to Quiet  *	If only one is SNaN: the SNaN operand, converted to Quiet  *	If both are QNaN: operand 2  *	If only one is QNaN: the QNaN operand  *  * In addition, in operations with an Inf operand, the result is usually  * Inf.  The class numbers are carefully arranged so that if  *	(unsigned)class(op1)> (unsigned)class(op2)  * then op1 is the one we want; otherwise op2 is the one we want.  */
end_comment

begin_define
define|#
directive|define
name|ORDER
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|{ \ 	if ((u_int)(x)->fp_class> (u_int)(y)->fp_class) \ 		SWAP(x, y); \ }
end_define

begin_define
define|#
directive|define
name|SWAP
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|{ \ 	register struct fpn *swap; \ 	swap = (x), (x) = (y), (y) = swap; \ }
end_define

begin_comment
comment|/*  * Emulator state.  */
end_comment

begin_struct
struct|struct
name|fpemu
block|{
name|struct
name|fpstate
modifier|*
name|fe_fpstate
decl_stmt|;
comment|/* registers, etc */
name|int
name|fe_fsr
decl_stmt|;
comment|/* fsr copy (modified during op) */
name|int
name|fe_cx
decl_stmt|;
comment|/* exceptions */
name|struct
name|fpn
name|fe_f1
decl_stmt|;
comment|/* operand 1 */
name|struct
name|fpn
name|fe_f2
decl_stmt|;
comment|/* operand 2, if required */
name|struct
name|fpn
name|fe_f3
decl_stmt|;
comment|/* available storage for result */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Arithmetic functions.  * Each of these may modify its inputs (f1,f2) and/or the temporary.  * Each returns a pointer to the result and/or sets exceptions.  */
end_comment

begin_function_decl
name|struct
name|fpn
modifier|*
name|fpu_add
parameter_list|(
name|struct
name|fpemu
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|fpu_sub
parameter_list|(
name|fe
parameter_list|)
value|((fe)->fe_f2.fp_sign ^= 1, fpu_add(fe))
end_define

begin_function_decl
name|struct
name|fpn
modifier|*
name|fpu_mul
parameter_list|(
name|struct
name|fpemu
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|fpn
modifier|*
name|fpu_div
parameter_list|(
name|struct
name|fpemu
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|fpn
modifier|*
name|fpu_sqrt
parameter_list|(
name|struct
name|fpemu
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Other functions.  */
end_comment

begin_comment
comment|/* Perform a compare instruction (with or without unordered exception). */
end_comment

begin_function_decl
name|void
name|fpu_compare
parameter_list|(
name|struct
name|fpemu
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Build a new Quiet NaN (sign=0, frac=all 1's). */
end_comment

begin_function_decl
name|struct
name|fpn
modifier|*
name|fpu_newnan
parameter_list|(
name|struct
name|fpemu
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Shift a number right some number of bits, taking care of round/sticky.  * Note that the result is probably not a well-formed number (it will lack  * the normal 1-bit mant[0]&FP_1).  */
end_comment

begin_function_decl
name|int
name|fpu_shr
parameter_list|(
name|struct
name|fpn
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Conversion to and from internal format -- note asymmetry. */
end_comment

begin_function_decl
name|int
name|fpu_itofpn
parameter_list|(
name|struct
name|fpn
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fpu_stofpn
parameter_list|(
name|struct
name|fpn
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fpu_dtofpn
parameter_list|(
name|struct
name|fpn
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fpu_xtofpn
parameter_list|(
name|struct
name|fpn
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|fpu_fpntoi
parameter_list|(
name|struct
name|fpemu
modifier|*
parameter_list|,
name|struct
name|fpn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|fpu_fpntos
parameter_list|(
name|struct
name|fpemu
modifier|*
parameter_list|,
name|struct
name|fpn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|fpu_fpntod
parameter_list|(
name|struct
name|fpemu
modifier|*
parameter_list|,
name|struct
name|fpn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|fpu_fpntox
parameter_list|(
name|struct
name|fpemu
modifier|*
parameter_list|,
name|struct
name|fpn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fpu_explode
parameter_list|(
name|struct
name|fpemu
modifier|*
parameter_list|,
name|struct
name|fpn
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fpu_implode
parameter_list|(
name|struct
name|fpemu
modifier|*
parameter_list|,
name|struct
name|fpn
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

