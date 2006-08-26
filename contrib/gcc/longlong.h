begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* longlong.h -- definitions for mixed size 32/64 bit arithmetic.    Copyright (C) 1991, 1992, 1994, 1995, 1996, 1997, 1998, 1999, 2000,    2005 Free Software Foundation, Inc.     This definition file is free software; you can redistribute it    and/or modify it under the terms of the GNU General Public    License as published by the Free Software Foundation; either    version 2, or (at your option) any later version.     This definition file is distributed in the hope that it will be    useful, but WITHOUT ANY WARRANTY; without even the implied    warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.    See the GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* You have to define the following before including this file:     UWtype -- An unsigned type, default type for operations (typically a "word")    UHWtype -- An unsigned type, at least half the size of UWtype.    UDWtype -- An unsigned type, at least twice as large a UWtype    W_TYPE_SIZE -- size in bits of UWtype     UQItype -- Unsigned 8 bit type.    SItype, USItype -- Signed and unsigned 32 bit types.    DItype, UDItype -- Signed and unsigned 64 bit types.     On a 32 bit machine UWtype should typically be USItype;    on a 64 bit machine, UWtype should typically be UDItype. */
end_comment

begin_define
define|#
directive|define
name|__BITS4
value|(W_TYPE_SIZE / 4)
end_define

begin_define
define|#
directive|define
name|__ll_B
value|((UWtype) 1<< (W_TYPE_SIZE / 2))
end_define

begin_define
define|#
directive|define
name|__ll_lowpart
parameter_list|(
name|t
parameter_list|)
value|((UWtype) (t)& (__ll_B - 1))
end_define

begin_define
define|#
directive|define
name|__ll_highpart
parameter_list|(
name|t
parameter_list|)
value|((UWtype) (t)>> (W_TYPE_SIZE / 2))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|W_TYPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|W_TYPE_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|UWtype
value|USItype
end_define

begin_define
define|#
directive|define
name|UHWtype
value|USItype
end_define

begin_define
define|#
directive|define
name|UDWtype
value|UDItype
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define auxiliary asm macros.     1) umul_ppmm(high_prod, low_prod, multipler, multiplicand) multiplies two    UWtype integers MULTIPLER and MULTIPLICAND, and generates a two UWtype    word product in HIGH_PROD and LOW_PROD.     2) __umulsidi3(a,b) multiplies two UWtype integers A and B, and returns a    UDWtype product.  This is just a variant of umul_ppmm.     3) udiv_qrnnd(quotient, remainder, high_numerator, low_numerator,    denominator) divides a UDWtype, composed by the UWtype integers    HIGH_NUMERATOR and LOW_NUMERATOR, by DENOMINATOR and places the quotient    in QUOTIENT and the remainder in REMAINDER.  HIGH_NUMERATOR must be less    than DENOMINATOR for correct operation.  If, in addition, the most    significant bit of DENOMINATOR must be 1, then the pre-processor symbol    UDIV_NEEDS_NORMALIZATION is defined to 1.     4) sdiv_qrnnd(quotient, remainder, high_numerator, low_numerator,    denominator).  Like udiv_qrnnd but the numbers are signed.  The quotient    is rounded towards 0.     5) count_leading_zeros(count, x) counts the number of zero-bits from the    msb to the first nonzero bit in the UWtype X.  This is the number of    steps X needs to be shifted left to set the msb.  Undefined for X == 0,    unless the symbol COUNT_LEADING_ZEROS_0 is defined to some value.     6) count_trailing_zeros(count, x) like count_leading_zeros, but counts    from the least significant end.     7) add_ssaaaa(high_sum, low_sum, high_addend_1, low_addend_1,    high_addend_2, low_addend_2) adds two UWtype integers, composed by    HIGH_ADDEND_1 and LOW_ADDEND_1, and HIGH_ADDEND_2 and LOW_ADDEND_2    respectively.  The result is placed in HIGH_SUM and LOW_SUM.  Overflow    (i.e. carry out) is not stored anywhere, and is lost.     8) sub_ddmmss(high_difference, low_difference, high_minuend, low_minuend,    high_subtrahend, low_subtrahend) subtracts two two-word UWtype integers,    composed by HIGH_MINUEND_1 and LOW_MINUEND_1, and HIGH_SUBTRAHEND_2 and    LOW_SUBTRAHEND_2 respectively.  The result is placed in HIGH_DIFFERENCE    and LOW_DIFFERENCE.  Overflow (i.e. carry out) is not stored anywhere,    and is lost.     If any of these macros are left undefined for a particular CPU,    C macros are used.  */
end_comment

begin_comment
comment|/* The CPUs come in alphabetical order below.     Please add support for more CPUs here, or improve the current support    for the CPUs below!    (E.g. WE32100, IBM360.)  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NO_ASM
argument_list|)
end_if

begin_comment
comment|/* We sometimes need to clobber "cc" with gcc2, but that would not be    understood by gcc1.  Use cpp to avoid major code duplication.  */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
end_if

begin_define
define|#
directive|define
name|__CLOBBER_CC
end_define

begin_define
define|#
directive|define
name|__AND_CLOBBER_CC
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__>= 2 */
end_comment

begin_define
define|#
directive|define
name|__CLOBBER_CC
value|: "cc"
end_define

begin_define
define|#
directive|define
name|__AND_CLOBBER_CC
value|, "cc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__< 2 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__alpha
argument_list|)
operator|&&
name|W_TYPE_SIZE
operator|==
literal|64
end_if

begin_define
define|#
directive|define
name|umul_ppmm
parameter_list|(
name|ph
parameter_list|,
name|pl
parameter_list|,
name|m0
parameter_list|,
name|m1
parameter_list|)
define|\
value|do {									\     UDItype __m0 = (m0), __m1 = (m1);					\     (ph) = __builtin_alpha_umulh (__m0, __m1);				\     (pl) = __m0 * __m1;							\   } while (0)
end_define

begin_define
define|#
directive|define
name|UMUL_TIME
value|46
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LONGLONG_STANDALONE
end_ifndef

begin_define
define|#
directive|define
name|udiv_qrnnd
parameter_list|(
name|q
parameter_list|,
name|r
parameter_list|,
name|n1
parameter_list|,
name|n0
parameter_list|,
name|d
parameter_list|)
define|\
value|do { UDItype __r;							\     (q) = __udiv_qrnnd (&__r, (n1), (n0), (d));				\     (r) = __r;								\   } while (0)
end_define

begin_function_decl
specifier|extern
name|UDItype
name|__udiv_qrnnd
parameter_list|(
name|UDItype
modifier|*
parameter_list|,
name|UDItype
parameter_list|,
name|UDItype
parameter_list|,
name|UDItype
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|UDIV_TIME
value|220
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LONGLONG_STANDALONE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__alpha_cix__
end_ifdef

begin_define
define|#
directive|define
name|count_leading_zeros
parameter_list|(
name|COUNT
parameter_list|,
name|X
parameter_list|)
value|((COUNT) = __builtin_clzl (X))
end_define

begin_define
define|#
directive|define
name|count_trailing_zeros
parameter_list|(
name|COUNT
parameter_list|,
name|X
parameter_list|)
value|((COUNT) = __builtin_ctzl (X))
end_define

begin_define
define|#
directive|define
name|COUNT_LEADING_ZEROS_0
value|64
end_define

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
specifier|const
name|UQItype
name|__clz_tab
index|[]
name|ATTRIBUTE_HIDDEN
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|count_leading_zeros
parameter_list|(
name|COUNT
parameter_list|,
name|X
parameter_list|)
define|\
value|do {									\     UDItype __xr = (X), __t, __a;					\     __t = __builtin_alpha_cmpbge (0, __xr);				\     __a = __clz_tab[__t ^ 0xff] - 1;					\     __t = __builtin_alpha_extbl (__xr, __a);				\     (COUNT) = 64 - (__clz_tab[__t] + __a*8);				\   } while (0)
end_define

begin_define
define|#
directive|define
name|count_trailing_zeros
parameter_list|(
name|COUNT
parameter_list|,
name|X
parameter_list|)
define|\
value|do {									\     UDItype __xr = (X), __t, __a;					\     __t = __builtin_alpha_cmpbge (0, __xr);				\     __t = ~__t& -~__t;							\     __a = ((__t& 0xCC) != 0) * 2;					\     __a += ((__t& 0xF0) != 0) * 4;					\     __a += ((__t& 0xAA) != 0);						\     __t = __builtin_alpha_extbl (__xr, __a);				\     __a<<= 3;								\     __t&= -__t;							\     __a += ((__t& 0xCC) != 0) * 2;					\     __a += ((__t& 0xF0) != 0) * 4;					\     __a += ((__t& 0xAA) != 0);						\     (COUNT) = __a;							\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __alpha_cix__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __alpha */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__arc__
argument_list|)
operator|&&
name|W_TYPE_SIZE
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|add_ssaaaa
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
value|__asm__ ("add.f	%1, %4, %5\n\tadc	%0, %2, %3"		\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "%r" ((USItype) (ah)),					\ 	     "rIJ" ((USItype) (bh)),					\ 	     "%r" ((USItype) (al)),					\ 	     "rIJ" ((USItype) (bl)))
end_define

begin_define
define|#
directive|define
name|sub_ddmmss
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
value|__asm__ ("sub.f	%1, %4, %5\n\tsbc	%0, %2, %3"		\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "r" ((USItype) (ah)),					\ 	     "rIJ" ((USItype) (bh)),					\ 	     "r" ((USItype) (al)),					\ 	     "rIJ" ((USItype) (bl)))
end_define

begin_comment
comment|/* Call libgcc routine.  */
end_comment

begin_define
define|#
directive|define
name|umul_ppmm
parameter_list|(
name|w1
parameter_list|,
name|w0
parameter_list|,
name|u
parameter_list|,
name|v
parameter_list|)
define|\
value|do {									\   DWunion __w;								\   __w.ll = __umulsidi3 (u, v);						\   w1 = __w.s.high;							\   w0 = __w.s.low;							\ } while (0)
end_define

begin_define
define|#
directive|define
name|__umulsidi3
value|__umulsidi3
end_define

begin_function_decl
name|UDItype
name|__umulsidi3
parameter_list|(
name|USItype
parameter_list|,
name|USItype
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|&&
name|W_TYPE_SIZE
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|add_ssaaaa
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
value|__asm__ ("adds	%1, %4, %5\n\tadc	%0, %2, %3"		\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "%r" ((USItype) (ah)),					\ 	     "rI" ((USItype) (bh)),					\ 	     "%r" ((USItype) (al)),					\ 	     "rI" ((USItype) (bl)))
end_define

begin_define
define|#
directive|define
name|sub_ddmmss
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
value|__asm__ ("subs	%1, %4, %5\n\tsbc	%0, %2, %3"		\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "r" ((USItype) (ah)),					\ 	     "rI" ((USItype) (bh)),					\ 	     "r" ((USItype) (al)),					\ 	     "rI" ((USItype) (bl)))
end_define

begin_define
define|#
directive|define
name|umul_ppmm
parameter_list|(
name|xh
parameter_list|,
name|xl
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|{register USItype __t0, __t1, __t2;					\   __asm__ ("%@ Inlined umul_ppmm\n"					\ 	   "	mov	%2, %5, lsr #16\n"				\ 	   "	mov	%0, %6, lsr #16\n"				\ 	   "	bic	%3, %5, %2, lsl #16\n"				\ 	   "	bic	%4, %6, %0, lsl #16\n"				\ 	   "	mul	%1, %3, %4\n"					\ 	   "	mul	%4, %2, %4\n"					\ 	   "	mul	%3, %0, %3\n"					\ 	   "	mul	%0, %2, %0\n"					\ 	   "	adds	%3, %4, %3\n"					\ 	   "	addcs	%0, %0, #65536\n"				\ 	   "	adds	%1, %1, %3, lsl #16\n"				\ 	   "	adc	%0, %0, %3, lsr #16"				\ 	   : "=&r" ((USItype) (xh)),					\ 	     "=r" ((USItype) (xl)),					\ 	     "=&r" (__t0), "=&r" (__t1), "=r" (__t2)			\ 	   : "r" ((USItype) (a)),					\ 	     "r" ((USItype) (b)));}
end_define

begin_define
define|#
directive|define
name|UMUL_TIME
value|20
end_define

begin_define
define|#
directive|define
name|UDIV_TIME
value|100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __arm__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__hppa
argument_list|)
operator|&&
name|W_TYPE_SIZE
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|add_ssaaaa
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
value|__asm__ ("add %4,%5,%1\n\taddc %2,%3,%0"				\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "%rM" ((USItype) (ah)),					\ 	     "rM" ((USItype) (bh)),					\ 	     "%rM" ((USItype) (al)),					\ 	     "rM" ((USItype) (bl)))
end_define

begin_define
define|#
directive|define
name|sub_ddmmss
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
value|__asm__ ("sub %4,%5,%1\n\tsubb %2,%3,%0"				\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "rM" ((USItype) (ah)),					\ 	     "rM" ((USItype) (bh)),					\ 	     "rM" ((USItype) (al)),					\ 	     "rM" ((USItype) (bl)))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_PA_RISC1_1
argument_list|)
end_if

begin_define
define|#
directive|define
name|umul_ppmm
parameter_list|(
name|w1
parameter_list|,
name|w0
parameter_list|,
name|u
parameter_list|,
name|v
parameter_list|)
define|\
value|do {									\     union								\       {									\ 	UDItype __f;							\ 	struct {USItype __w1, __w0;} __w1w0;				\       } __t;								\     __asm__ ("xmpyu %1,%2,%0"						\ 	     : "=x" (__t.__f)						\ 	     : "x" ((USItype) (u)),					\ 	       "x" ((USItype) (v)));					\     (w1) = __t.__w1w0.__w1;						\     (w0) = __t.__w1w0.__w0;						\      } while (0)
end_define

begin_define
define|#
directive|define
name|UMUL_TIME
value|8
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UMUL_TIME
value|30
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|UDIV_TIME
value|40
end_define

begin_define
define|#
directive|define
name|count_leading_zeros
parameter_list|(
name|count
parameter_list|,
name|x
parameter_list|)
define|\
value|do {									\     USItype __tmp;							\     __asm__ (								\        "ldi		1,%0\n"						\ "	extru,=		%1,15,16,%%r0		; Bits 31..16 zero?\n"	\ "	extru,tr	%1,15,16,%1		; No.  Shift down, skip add.\n"\ "	ldo		16(%0),%0		; Yes.  Perform add.\n"	\ "	extru,=		%1,23,8,%%r0		; Bits 15..8 zero?\n"	\ "	extru,tr	%1,23,8,%1		; No.  Shift down, skip add.\n"\ "	ldo		8(%0),%0		; Yes.  Perform add.\n"	\ "	extru,=		%1,27,4,%%r0		; Bits 7..4 zero?\n"	\ "	extru,tr	%1,27,4,%1		; No.  Shift down, skip add.\n"\ "	ldo		4(%0),%0		; Yes.  Perform add.\n"	\ "	extru,=		%1,29,2,%%r0		; Bits 3..2 zero?\n"	\ "	extru,tr	%1,29,2,%1		; No.  Shift down, skip add.\n"\ "	ldo		2(%0),%0		; Yes.  Perform add.\n"	\ "	extru		%1,30,1,%1		; Extract bit 1.\n"	\ "	sub		%0,%1,%0		; Subtract it.\n"	\ 	: "=r" (count), "=r" (__tmp) : "1" (x));			\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__i370__
argument_list|)
operator|||
name|defined
argument_list|(
name|__s390__
argument_list|)
operator|||
name|defined
argument_list|(
name|__mvs__
argument_list|)
operator|)
operator|&&
name|W_TYPE_SIZE
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|smul_ppmm
parameter_list|(
name|xh
parameter_list|,
name|xl
parameter_list|,
name|m0
parameter_list|,
name|m1
parameter_list|)
define|\
value|do {									\     union {DItype __ll;							\ 	   struct {USItype __h, __l;} __i;				\ 	  } __x;							\     __asm__ ("lr %N0,%1\n\tmr %0,%2"					\ 	     : "=&r" (__x.__ll)						\ 	     : "r" (m0), "r" (m1));					\     (xh) = __x.__i.__h; (xl) = __x.__i.__l;				\   } while (0)
end_define

begin_define
define|#
directive|define
name|sdiv_qrnnd
parameter_list|(
name|q
parameter_list|,
name|r
parameter_list|,
name|n1
parameter_list|,
name|n0
parameter_list|,
name|d
parameter_list|)
define|\
value|do {									\     union {DItype __ll;							\ 	   struct {USItype __h, __l;} __i;				\ 	  } __x;							\     __x.__i.__h = n1; __x.__i.__l = n0;					\     __asm__ ("dr %0,%2"							\ 	     : "=r" (__x.__ll)						\ 	     : "0" (__x.__ll), "r" (d));				\     (q) = __x.__i.__l; (r) = __x.__i.__h;				\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__i486__
argument_list|)
operator|)
operator|&&
name|W_TYPE_SIZE
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|add_ssaaaa
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
value|__asm__ ("addl %5,%1\n\tadcl %3,%0"					\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "%0" ((USItype) (ah)),					\ 	     "g" ((USItype) (bh)),					\ 	     "%1" ((USItype) (al)),					\ 	     "g" ((USItype) (bl)))
end_define

begin_define
define|#
directive|define
name|sub_ddmmss
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
value|__asm__ ("subl %5,%1\n\tsbbl %3,%0"					\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "0" ((USItype) (ah)),					\ 	     "g" ((USItype) (bh)),					\ 	     "1" ((USItype) (al)),					\ 	     "g" ((USItype) (bl)))
end_define

begin_define
define|#
directive|define
name|umul_ppmm
parameter_list|(
name|w1
parameter_list|,
name|w0
parameter_list|,
name|u
parameter_list|,
name|v
parameter_list|)
define|\
value|__asm__ ("mull %3"							\ 	   : "=a" ((USItype) (w0)),					\ 	     "=d" ((USItype) (w1))					\ 	   : "%0" ((USItype) (u)),					\ 	     "rm" ((USItype) (v)))
end_define

begin_define
define|#
directive|define
name|udiv_qrnnd
parameter_list|(
name|q
parameter_list|,
name|r
parameter_list|,
name|n1
parameter_list|,
name|n0
parameter_list|,
name|dv
parameter_list|)
define|\
value|__asm__ ("divl %4"							\ 	   : "=a" ((USItype) (q)),					\ 	     "=d" ((USItype) (r))					\ 	   : "0" ((USItype) (n0)),					\ 	     "1" ((USItype) (n1)),					\ 	     "rm" ((USItype) (dv)))
end_define

begin_define
define|#
directive|define
name|count_leading_zeros
parameter_list|(
name|count
parameter_list|,
name|x
parameter_list|)
define|\
value|do {									\     USItype __cbtmp;							\     __asm__ ("bsrl %1,%0"						\ 	     : "=r" (__cbtmp) : "rm" ((USItype) (x)));			\     (count) = __cbtmp ^ 31;						\   } while (0)
end_define

begin_define
define|#
directive|define
name|count_trailing_zeros
parameter_list|(
name|count
parameter_list|,
name|x
parameter_list|)
define|\
value|__asm__ ("bsfl %1,%0" : "=r" (count) : "rm" ((USItype)(x)))
end_define

begin_define
define|#
directive|define
name|UMUL_TIME
value|40
end_define

begin_define
define|#
directive|define
name|UDIV_TIME
value|40
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 80x86 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i960__
argument_list|)
operator|&&
name|W_TYPE_SIZE
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|umul_ppmm
parameter_list|(
name|w1
parameter_list|,
name|w0
parameter_list|,
name|u
parameter_list|,
name|v
parameter_list|)
define|\
value|({union {UDItype __ll;						\ 	   struct {USItype __l, __h;} __i;				\ 	  } __xx;							\   __asm__ ("emul	%2,%1,%0"					\ 	   : "=d" (__xx.__ll)						\ 	   : "%dI" ((USItype) (u)),					\ 	     "dI" ((USItype) (v)));					\   (w1) = __xx.__i.__h; (w0) = __xx.__i.__l;})
end_define

begin_define
define|#
directive|define
name|__umulsidi3
parameter_list|(
name|u
parameter_list|,
name|v
parameter_list|)
define|\
value|({UDItype __w;							\     __asm__ ("emul	%2,%1,%0"					\ 	     : "=d" (__w)						\ 	     : "%dI" ((USItype) (u)),					\ 	       "dI" ((USItype) (v)));					\     __w; })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __i960__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__M32R__
argument_list|)
operator|&&
name|W_TYPE_SIZE
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|add_ssaaaa
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
comment|/* The cmp clears the condition bit.  */
define|\
value|__asm__ ("cmp %0,%0\n\taddx %1,%5\n\taddx %0,%3"			\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "0" ((USItype) (ah)),					\ 	     "r" ((USItype) (bh)),					\ 	     "1" ((USItype) (al)),					\ 	     "r" ((USItype) (bl))					\ 	   : "cbit")
end_define

begin_define
define|#
directive|define
name|sub_ddmmss
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
comment|/* The cmp clears the condition bit.  */
define|\
value|__asm__ ("cmp %0,%0\n\tsubx %1,%5\n\tsubx %0,%3"			\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "0" ((USItype) (ah)),					\ 	     "r" ((USItype) (bh)),					\ 	     "1" ((USItype) (al)),					\ 	     "r" ((USItype) (bl))					\ 	   : "cbit")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __M32R__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mc68000__
argument_list|)
operator|&&
name|W_TYPE_SIZE
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|add_ssaaaa
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
value|__asm__ ("add%.l %5,%1\n\taddx%.l %3,%0"				\ 	   : "=d" ((USItype) (sh)),					\ 	     "=&d" ((USItype) (sl))					\ 	   : "%0" ((USItype) (ah)),					\ 	     "d" ((USItype) (bh)),					\ 	     "%1" ((USItype) (al)),					\ 	     "g" ((USItype) (bl)))
end_define

begin_define
define|#
directive|define
name|sub_ddmmss
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
value|__asm__ ("sub%.l %5,%1\n\tsubx%.l %3,%0"				\ 	   : "=d" ((USItype) (sh)),					\ 	     "=&d" ((USItype) (sl))					\ 	   : "0" ((USItype) (ah)),					\ 	     "d" ((USItype) (bh)),					\ 	     "1" ((USItype) (al)),					\ 	     "g" ((USItype) (bl)))
end_define

begin_comment
comment|/* The '020, '030, '040 and CPU32 have 32x32->64 and 64/32->32q-32r.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mc68020__
argument_list|)
operator|||
name|defined
argument_list|(
name|mc68020
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__mc68030__
argument_list|)
operator|||
name|defined
argument_list|(
name|mc68030
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__mc68040__
argument_list|)
operator|||
name|defined
argument_list|(
name|mc68040
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__mcpu32__
argument_list|)
operator|||
name|defined
argument_list|(
name|mcpu32
argument_list|)
end_if

begin_define
define|#
directive|define
name|umul_ppmm
parameter_list|(
name|w1
parameter_list|,
name|w0
parameter_list|,
name|u
parameter_list|,
name|v
parameter_list|)
define|\
value|__asm__ ("mulu%.l %3,%1:%0"						\ 	   : "=d" ((USItype) (w0)),					\ 	     "=d" ((USItype) (w1))					\ 	   : "%0" ((USItype) (u)),					\ 	     "dmi" ((USItype) (v)))
end_define

begin_define
define|#
directive|define
name|UMUL_TIME
value|45
end_define

begin_define
define|#
directive|define
name|udiv_qrnnd
parameter_list|(
name|q
parameter_list|,
name|r
parameter_list|,
name|n1
parameter_list|,
name|n0
parameter_list|,
name|d
parameter_list|)
define|\
value|__asm__ ("divu%.l %4,%1:%0"						\ 	   : "=d" ((USItype) (q)),					\ 	     "=d" ((USItype) (r))					\ 	   : "0" ((USItype) (n0)),					\ 	     "1" ((USItype) (n1)),					\ 	     "dmi" ((USItype) (d)))
end_define

begin_define
define|#
directive|define
name|UDIV_TIME
value|90
end_define

begin_define
define|#
directive|define
name|sdiv_qrnnd
parameter_list|(
name|q
parameter_list|,
name|r
parameter_list|,
name|n1
parameter_list|,
name|n0
parameter_list|,
name|d
parameter_list|)
define|\
value|__asm__ ("divs%.l %4,%1:%0"						\ 	   : "=d" ((USItype) (q)),					\ 	     "=d" ((USItype) (r))					\ 	   : "0" ((USItype) (n0)),					\ 	     "1" ((USItype) (n1)),					\ 	     "dmi" ((USItype) (d)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not mc68020 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mcoldfire__
argument_list|)
end_if

begin_define
define|#
directive|define
name|umul_ppmm
parameter_list|(
name|xh
parameter_list|,
name|xl
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|__asm__ ("| Inlined umul_ppmm\n"					\ 	   "	move%.l	%2,%/d0\n"					\ 	   "	move%.l	%3,%/d1\n"					\ 	   "	move%.l	%/d0,%/d2\n"					\ 	   "	swap	%/d0\n"						\ 	   "	move%.l	%/d1,%/d3\n"					\ 	   "	swap	%/d1\n"						\ 	   "	move%.w	%/d2,%/d4\n"					\ 	   "	mulu	%/d3,%/d4\n"					\ 	   "	mulu	%/d1,%/d2\n"					\ 	   "	mulu	%/d0,%/d3\n"					\ 	   "	mulu	%/d0,%/d1\n"					\ 	   "	move%.l	%/d4,%/d0\n"					\ 	   "	clr%.w	%/d0\n"						\ 	   "	swap	%/d0\n"						\ 	   "	add%.l	%/d0,%/d2\n"					\ 	   "	add%.l	%/d3,%/d2\n"					\ 	   "	jcc	1f\n"						\ 	   "	add%.l	%#65536,%/d1\n"					\ 	   "1:	swap	%/d2\n"						\ 	   "	moveq	%#0,%/d0\n"					\ 	   "	move%.w	%/d2,%/d0\n"					\ 	   "	move%.w	%/d4,%/d2\n"					\ 	   "	move%.l	%/d2,%1\n"					\ 	   "	add%.l	%/d1,%/d0\n"					\ 	   "	move%.l	%/d0,%0"					\ 	   : "=g" ((USItype) (xh)),					\ 	     "=g" ((USItype) (xl))					\ 	   : "g" ((USItype) (a)),					\ 	     "g" ((USItype) (b))					\ 	   : "d0", "d1", "d2", "d3", "d4")
end_define

begin_define
define|#
directive|define
name|UMUL_TIME
value|100
end_define

begin_define
define|#
directive|define
name|UDIV_TIME
value|400
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not ColdFire */
end_comment

begin_comment
comment|/* %/ inserts REGISTER_PREFIX, %# inserts IMMEDIATE_PREFIX.  */
end_comment

begin_define
define|#
directive|define
name|umul_ppmm
parameter_list|(
name|xh
parameter_list|,
name|xl
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|__asm__ ("| Inlined umul_ppmm\n"					\ 	   "	move%.l	%2,%/d0\n"					\ 	   "	move%.l	%3,%/d1\n"					\ 	   "	move%.l	%/d0,%/d2\n"					\ 	   "	swap	%/d0\n"						\ 	   "	move%.l	%/d1,%/d3\n"					\ 	   "	swap	%/d1\n"						\ 	   "	move%.w	%/d2,%/d4\n"					\ 	   "	mulu	%/d3,%/d4\n"					\ 	   "	mulu	%/d1,%/d2\n"					\ 	   "	mulu	%/d0,%/d3\n"					\ 	   "	mulu	%/d0,%/d1\n"					\ 	   "	move%.l	%/d4,%/d0\n"					\ 	   "	eor%.w	%/d0,%/d0\n"					\ 	   "	swap	%/d0\n"						\ 	   "	add%.l	%/d0,%/d2\n"					\ 	   "	add%.l	%/d3,%/d2\n"					\ 	   "	jcc	1f\n"						\ 	   "	add%.l	%#65536,%/d1\n"					\ 	   "1:	swap	%/d2\n"						\ 	   "	moveq	%#0,%/d0\n"					\ 	   "	move%.w	%/d2,%/d0\n"					\ 	   "	move%.w	%/d4,%/d2\n"					\ 	   "	move%.l	%/d2,%1\n"					\ 	   "	add%.l	%/d1,%/d0\n"					\ 	   "	move%.l	%/d0,%0"					\ 	   : "=g" ((USItype) (xh)),					\ 	     "=g" ((USItype) (xl))					\ 	   : "g" ((USItype) (a)),					\ 	     "g" ((USItype) (b))					\ 	   : "d0", "d1", "d2", "d3", "d4")
end_define

begin_define
define|#
directive|define
name|UMUL_TIME
value|100
end_define

begin_define
define|#
directive|define
name|UDIV_TIME
value|400
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not ColdFire */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not mc68020 */
end_comment

begin_comment
comment|/* The '020, '030, '040 and '060 have bitfield insns.    cpu32 disguises as a 68020, but lacks them.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__mc68020__
argument_list|)
operator|||
name|defined
argument_list|(
name|mc68020
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__mc68030__
argument_list|)
operator|||
name|defined
argument_list|(
name|mc68030
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__mc68040__
argument_list|)
operator|||
name|defined
argument_list|(
name|mc68040
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__mc68060__
argument_list|)
operator|||
name|defined
argument_list|(
name|mc68060
argument_list|)
operator|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|__mcpu32__
argument_list|)
end_if

begin_define
define|#
directive|define
name|count_leading_zeros
parameter_list|(
name|count
parameter_list|,
name|x
parameter_list|)
define|\
value|__asm__ ("bfffo %1{%b2:%b2},%0"					\ 	   : "=d" ((USItype) (count))					\ 	   : "od" ((USItype) (x)), "n" (0))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* mc68000 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__m88000__
argument_list|)
operator|&&
name|W_TYPE_SIZE
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|add_ssaaaa
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
value|__asm__ ("addu.co %1,%r4,%r5\n\taddu.ci %0,%r2,%r3"			\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "%rJ" ((USItype) (ah)),					\ 	     "rJ" ((USItype) (bh)),					\ 	     "%rJ" ((USItype) (al)),					\ 	     "rJ" ((USItype) (bl)))
end_define

begin_define
define|#
directive|define
name|sub_ddmmss
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
value|__asm__ ("subu.co %1,%r4,%r5\n\tsubu.ci %0,%r2,%r3"			\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "rJ" ((USItype) (ah)),					\ 	     "rJ" ((USItype) (bh)),					\ 	     "rJ" ((USItype) (al)),					\ 	     "rJ" ((USItype) (bl)))
end_define

begin_define
define|#
directive|define
name|count_leading_zeros
parameter_list|(
name|count
parameter_list|,
name|x
parameter_list|)
define|\
value|do {									\     USItype __cbtmp;							\     __asm__ ("ff1 %0,%1"						\ 	     : "=r" (__cbtmp)						\ 	     : "r" ((USItype) (x)));					\     (count) = __cbtmp ^ 31;						\   } while (0)
end_define

begin_define
define|#
directive|define
name|COUNT_LEADING_ZEROS_0
value|63
end_define

begin_comment
comment|/* sic */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mc88110__
argument_list|)
end_if

begin_define
define|#
directive|define
name|umul_ppmm
parameter_list|(
name|wh
parameter_list|,
name|wl
parameter_list|,
name|u
parameter_list|,
name|v
parameter_list|)
define|\
value|do {									\     union {UDItype __ll;						\ 	   struct {USItype __h, __l;} __i;				\ 	  } __xx;							\     __asm__ ("mulu.d	%0,%1,%2"					\ 	     : "=r" (__xx.__ll)						\ 	     : "r" ((USItype) (u)),					\ 	       "r" ((USItype) (v)));					\     (wh) = __xx.__i.__h;						\     (wl) = __xx.__i.__l;						\   } while (0)
end_define

begin_define
define|#
directive|define
name|udiv_qrnnd
parameter_list|(
name|q
parameter_list|,
name|r
parameter_list|,
name|n1
parameter_list|,
name|n0
parameter_list|,
name|d
parameter_list|)
define|\
value|({union {UDItype __ll;						\ 	   struct {USItype __h, __l;} __i;				\ 	  } __xx;							\   USItype __q;								\   __xx.__i.__h = (n1); __xx.__i.__l = (n0);				\   __asm__ ("divu.d %0,%1,%2"						\ 	   : "=r" (__q)							\ 	   : "r" (__xx.__ll),						\ 	     "r" ((USItype) (d)));					\   (r) = (n0) - __q * (d); (q) = __q; })
end_define

begin_define
define|#
directive|define
name|UMUL_TIME
value|5
end_define

begin_define
define|#
directive|define
name|UDIV_TIME
value|25
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UMUL_TIME
value|17
end_define

begin_define
define|#
directive|define
name|UDIV_TIME
value|150
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __mc88110__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __m88000__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__mips__
argument_list|)
operator|&&
name|W_TYPE_SIZE
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|umul_ppmm
parameter_list|(
name|w1
parameter_list|,
name|w0
parameter_list|,
name|u
parameter_list|,
name|v
parameter_list|)
define|\
value|__asm__ ("multu %2,%3"						\ 	   : "=l" ((USItype) (w0)),					\ 	     "=h" ((USItype) (w1))					\ 	   : "d" ((USItype) (u)),					\ 	     "d" ((USItype) (v)))
end_define

begin_define
define|#
directive|define
name|UMUL_TIME
value|10
end_define

begin_define
define|#
directive|define
name|UDIV_TIME
value|100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __mips__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ns32000__
argument_list|)
operator|&&
name|W_TYPE_SIZE
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|umul_ppmm
parameter_list|(
name|w1
parameter_list|,
name|w0
parameter_list|,
name|u
parameter_list|,
name|v
parameter_list|)
define|\
value|({union {UDItype __ll;						\ 	   struct {USItype __l, __h;} __i;				\ 	  } __xx;							\   __asm__ ("meid %2,%0"							\ 	   : "=g" (__xx.__ll)						\ 	   : "%0" ((USItype) (u)),					\ 	     "g" ((USItype) (v)));					\   (w1) = __xx.__i.__h; (w0) = __xx.__i.__l;})
end_define

begin_define
define|#
directive|define
name|__umulsidi3
parameter_list|(
name|u
parameter_list|,
name|v
parameter_list|)
define|\
value|({UDItype __w;							\     __asm__ ("meid %2,%0"						\ 	     : "=g" (__w)						\ 	     : "%0" ((USItype) (u)),					\ 	       "g" ((USItype) (v)));					\     __w; })
end_define

begin_define
define|#
directive|define
name|udiv_qrnnd
parameter_list|(
name|q
parameter_list|,
name|r
parameter_list|,
name|n1
parameter_list|,
name|n0
parameter_list|,
name|d
parameter_list|)
define|\
value|({union {UDItype __ll;						\ 	   struct {USItype __l, __h;} __i;				\ 	  } __xx;							\   __xx.__i.__h = (n1); __xx.__i.__l = (n0);				\   __asm__ ("deid %2,%0"							\ 	   : "=g" (__xx.__ll)						\ 	   : "0" (__xx.__ll),						\ 	     "g" ((USItype) (d)));					\   (r) = __xx.__i.__l; (q) = __xx.__i.__h; })
end_define

begin_define
define|#
directive|define
name|count_trailing_zeros
parameter_list|(
name|count
parameter_list|,
name|x
parameter_list|)
define|\
value|do {									\     __asm__ ("ffsd     %2,%0"						\             : "=r" ((USItype) (count))					\             : "0" ((USItype) 0),					\               "r" ((USItype) (x)));					\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ns32000__ */
end_comment

begin_comment
comment|/* FIXME: We should test _IBMR2 here when we add assembly support for the    system vendor compilers.    FIXME: What's needed for gcc PowerPC VxWorks?  __vxworks__ is not good    enough, since that hits ARM and m68k too.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_ARCH_PPC
argument_list|)
comment|/* AIX */
expr|\
operator|||
name|defined
argument_list|(
name|_ARCH_PWR
argument_list|)
comment|/* AIX */
expr|\
operator|||
name|defined
argument_list|(
name|_ARCH_COM
argument_list|)
comment|/* AIX */
expr|\
operator|||
name|defined
argument_list|(
name|__powerpc__
argument_list|)
comment|/* gcc */
expr|\
operator|||
name|defined
argument_list|(
name|__POWERPC__
argument_list|)
comment|/* BEOS */
expr|\
operator|||
name|defined
argument_list|(
name|__ppc__
argument_list|)
comment|/* Darwin */
expr|\
operator|||
operator|(
name|defined
argument_list|(
name|PPC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CPU_FAMILY
argument_list|)
operator|)
comment|/* gcc 2.7.x GNU&SysV */
expr|\
operator|||
operator|(
name|defined
argument_list|(
name|PPC
argument_list|)
operator|&&
name|defined
argument_list|(
name|CPU_FAMILY
argument_list|)
comment|/* VxWorks */
expr|\
operator|&&
name|CPU_FAMILY
operator|==
name|PPC
operator|)
expr|\
operator|)
operator|&&
name|W_TYPE_SIZE
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|add_ssaaaa
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
value|do {									\     if (__builtin_constant_p (bh)&& (bh) == 0)				\       __asm__ ("{a%I4|add%I4c} %1,%3,%4\n\t{aze|addze} %0,%2"		\ 	     : "=r" (sh), "=&r" (sl) : "r" (ah), "%r" (al), "rI" (bl));\     else if (__builtin_constant_p (bh)&& (bh) == ~(USItype) 0)		\       __asm__ ("{a%I4|add%I4c} %1,%3,%4\n\t{ame|addme} %0,%2"		\ 	     : "=r" (sh), "=&r" (sl) : "r" (ah), "%r" (al), "rI" (bl));\     else								\       __asm__ ("{a%I5|add%I5c} %1,%4,%5\n\t{ae|adde} %0,%2,%3"		\ 	     : "=r" (sh), "=&r" (sl)					\ 	     : "%r" (ah), "r" (bh), "%r" (al), "rI" (bl));		\   } while (0)
end_define

begin_define
define|#
directive|define
name|sub_ddmmss
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
value|do {									\     if (__builtin_constant_p (ah)&& (ah) == 0)				\       __asm__ ("{sf%I3|subf%I3c} %1,%4,%3\n\t{sfze|subfze} %0,%2"	\ 	       : "=r" (sh), "=&r" (sl) : "r" (bh), "rI" (al), "r" (bl));\     else if (__builtin_constant_p (ah)&& (ah) == ~(USItype) 0)		\       __asm__ ("{sf%I3|subf%I3c} %1,%4,%3\n\t{sfme|subfme} %0,%2"	\ 	       : "=r" (sh), "=&r" (sl) : "r" (bh), "rI" (al), "r" (bl));\     else if (__builtin_constant_p (bh)&& (bh) == 0)			\       __asm__ ("{sf%I3|subf%I3c} %1,%4,%3\n\t{ame|addme} %0,%2"		\ 	       : "=r" (sh), "=&r" (sl) : "r" (ah), "rI" (al), "r" (bl));\     else if (__builtin_constant_p (bh)&& (bh) == ~(USItype) 0)		\       __asm__ ("{sf%I3|subf%I3c} %1,%4,%3\n\t{aze|addze} %0,%2"		\ 	       : "=r" (sh), "=&r" (sl) : "r" (ah), "rI" (al), "r" (bl));\     else								\       __asm__ ("{sf%I4|subf%I4c} %1,%5,%4\n\t{sfe|subfe} %0,%3,%2"	\ 	       : "=r" (sh), "=&r" (sl)					\ 	       : "r" (ah), "r" (bh), "rI" (al), "r" (bl));		\   } while (0)
end_define

begin_define
define|#
directive|define
name|count_leading_zeros
parameter_list|(
name|count
parameter_list|,
name|x
parameter_list|)
define|\
value|__asm__ ("{cntlz|cntlzw} %0,%1" : "=r" (count) : "r" (x))
end_define

begin_define
define|#
directive|define
name|COUNT_LEADING_ZEROS_0
value|32
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_ARCH_PPC
argument_list|)
operator|||
name|defined
argument_list|(
name|__powerpc__
argument_list|)
operator|||
name|defined
argument_list|(
name|__POWERPC__
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__ppc__
argument_list|)
expr|\
operator|||
operator|(
name|defined
argument_list|(
name|PPC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CPU_FAMILY
argument_list|)
operator|)
comment|/* gcc 2.7.x GNU&SysV */
expr|\
operator|||
operator|(
name|defined
argument_list|(
name|PPC
argument_list|)
operator|&&
name|defined
argument_list|(
name|CPU_FAMILY
argument_list|)
comment|/* VxWorks */
expr|\
operator|&&
name|CPU_FAMILY
operator|==
name|PPC
operator|)
end_if

begin_define
define|#
directive|define
name|umul_ppmm
parameter_list|(
name|ph
parameter_list|,
name|pl
parameter_list|,
name|m0
parameter_list|,
name|m1
parameter_list|)
define|\
value|do {									\     USItype __m0 = (m0), __m1 = (m1);					\     __asm__ ("mulhwu %0,%1,%2" : "=r" (ph) : "%r" (m0), "r" (m1));	\     (pl) = __m0 * __m1;							\   } while (0)
end_define

begin_define
define|#
directive|define
name|UMUL_TIME
value|15
end_define

begin_define
define|#
directive|define
name|smul_ppmm
parameter_list|(
name|ph
parameter_list|,
name|pl
parameter_list|,
name|m0
parameter_list|,
name|m1
parameter_list|)
define|\
value|do {									\     SItype __m0 = (m0), __m1 = (m1);					\     __asm__ ("mulhw %0,%1,%2" : "=r" (ph) : "%r" (m0), "r" (m1));	\     (pl) = __m0 * __m1;							\   } while (0)
end_define

begin_define
define|#
directive|define
name|SMUL_TIME
value|14
end_define

begin_define
define|#
directive|define
name|UDIV_TIME
value|120
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_ARCH_PWR
argument_list|)
end_elif

begin_define
define|#
directive|define
name|UMUL_TIME
value|8
end_define

begin_define
define|#
directive|define
name|smul_ppmm
parameter_list|(
name|xh
parameter_list|,
name|xl
parameter_list|,
name|m0
parameter_list|,
name|m1
parameter_list|)
define|\
value|__asm__ ("mul %0,%2,%3" : "=r" (xh), "=q" (xl) : "r" (m0), "r" (m1))
end_define

begin_define
define|#
directive|define
name|SMUL_TIME
value|4
end_define

begin_define
define|#
directive|define
name|sdiv_qrnnd
parameter_list|(
name|q
parameter_list|,
name|r
parameter_list|,
name|nh
parameter_list|,
name|nl
parameter_list|,
name|d
parameter_list|)
define|\
value|__asm__ ("div %0,%2,%4" : "=r" (q), "=q" (r) : "r" (nh), "1" (nl), "r" (d))
end_define

begin_define
define|#
directive|define
name|UDIV_TIME
value|100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 32-bit POWER architecture variants.  */
end_comment

begin_comment
comment|/* We should test _IBMR2 here when we add assembly support for the system    vendor compilers.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_ARCH_PPC64
argument_list|)
operator|||
name|defined
argument_list|(
name|__powerpc64__
argument_list|)
operator|)
operator|&&
name|W_TYPE_SIZE
operator|==
literal|64
end_if

begin_define
define|#
directive|define
name|add_ssaaaa
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
value|do {									\     if (__builtin_constant_p (bh)&& (bh) == 0)				\       __asm__ ("{a%I4|add%I4c} %1,%3,%4\n\t{aze|addze} %0,%2"		\ 	     : "=r" (sh), "=&r" (sl) : "r" (ah), "%r" (al), "rI" (bl));\     else if (__builtin_constant_p (bh)&& (bh) == ~(UDItype) 0)		\       __asm__ ("{a%I4|add%I4c} %1,%3,%4\n\t{ame|addme} %0,%2"		\ 	     : "=r" (sh), "=&r" (sl) : "r" (ah), "%r" (al), "rI" (bl));\     else								\       __asm__ ("{a%I5|add%I5c} %1,%4,%5\n\t{ae|adde} %0,%2,%3"		\ 	     : "=r" (sh), "=&r" (sl)					\ 	     : "%r" (ah), "r" (bh), "%r" (al), "rI" (bl));		\   } while (0)
end_define

begin_define
define|#
directive|define
name|sub_ddmmss
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
value|do {									\     if (__builtin_constant_p (ah)&& (ah) == 0)				\       __asm__ ("{sf%I3|subf%I3c} %1,%4,%3\n\t{sfze|subfze} %0,%2"	\ 	       : "=r" (sh), "=&r" (sl) : "r" (bh), "rI" (al), "r" (bl));\     else if (__builtin_constant_p (ah)&& (ah) == ~(UDItype) 0)		\       __asm__ ("{sf%I3|subf%I3c} %1,%4,%3\n\t{sfme|subfme} %0,%2"	\ 	       : "=r" (sh), "=&r" (sl) : "r" (bh), "rI" (al), "r" (bl));\     else if (__builtin_constant_p (bh)&& (bh) == 0)			\       __asm__ ("{sf%I3|subf%I3c} %1,%4,%3\n\t{ame|addme} %0,%2"		\ 	       : "=r" (sh), "=&r" (sl) : "r" (ah), "rI" (al), "r" (bl));\     else if (__builtin_constant_p (bh)&& (bh) == ~(UDItype) 0)		\       __asm__ ("{sf%I3|subf%I3c} %1,%4,%3\n\t{aze|addze} %0,%2"		\ 	       : "=r" (sh), "=&r" (sl) : "r" (ah), "rI" (al), "r" (bl));\     else								\       __asm__ ("{sf%I4|subf%I4c} %1,%5,%4\n\t{sfe|subfe} %0,%3,%2"	\ 	       : "=r" (sh), "=&r" (sl)					\ 	       : "r" (ah), "r" (bh), "rI" (al), "r" (bl));		\   } while (0)
end_define

begin_define
define|#
directive|define
name|count_leading_zeros
parameter_list|(
name|count
parameter_list|,
name|x
parameter_list|)
define|\
value|__asm__ ("cntlzd %0,%1" : "=r" (count) : "r" (x))
end_define

begin_define
define|#
directive|define
name|COUNT_LEADING_ZEROS_0
value|64
end_define

begin_define
define|#
directive|define
name|umul_ppmm
parameter_list|(
name|ph
parameter_list|,
name|pl
parameter_list|,
name|m0
parameter_list|,
name|m1
parameter_list|)
define|\
value|do {									\     UDItype __m0 = (m0), __m1 = (m1);					\     __asm__ ("mulhdu %0,%1,%2" : "=r" (ph) : "%r" (m0), "r" (m1));	\     (pl) = __m0 * __m1;							\   } while (0)
end_define

begin_define
define|#
directive|define
name|UMUL_TIME
value|15
end_define

begin_define
define|#
directive|define
name|smul_ppmm
parameter_list|(
name|ph
parameter_list|,
name|pl
parameter_list|,
name|m0
parameter_list|,
name|m1
parameter_list|)
define|\
value|do {									\     DItype __m0 = (m0), __m1 = (m1);					\     __asm__ ("mulhd %0,%1,%2" : "=r" (ph) : "%r" (m0), "r" (m1));	\     (pl) = __m0 * __m1;							\   } while (0)
end_define

begin_define
define|#
directive|define
name|SMUL_TIME
value|14
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|UDIV_TIME
value|120
end_define

begin_comment
comment|/* ??? */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 64-bit PowerPC.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ibm032__
argument_list|)
comment|/* RT/ROMP */
operator|&&
name|W_TYPE_SIZE
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|add_ssaaaa
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
value|__asm__ ("a %1,%5\n\tae %0,%3"					\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "%0" ((USItype) (ah)),					\ 	     "r" ((USItype) (bh)),					\ 	     "%1" ((USItype) (al)),					\ 	     "r" ((USItype) (bl)))
end_define

begin_define
define|#
directive|define
name|sub_ddmmss
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
value|__asm__ ("s %1,%5\n\tse %0,%3"					\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "0" ((USItype) (ah)),					\ 	     "r" ((USItype) (bh)),					\ 	     "1" ((USItype) (al)),					\ 	     "r" ((USItype) (bl)))
end_define

begin_define
define|#
directive|define
name|umul_ppmm
parameter_list|(
name|ph
parameter_list|,
name|pl
parameter_list|,
name|m0
parameter_list|,
name|m1
parameter_list|)
define|\
value|do {									\     USItype __m0 = (m0), __m1 = (m1);					\     __asm__ (								\        "s	r2,r2\n"						\ "	mts	r10,%2\n"						\ "	m	r2,%3\n"						\ "	m	r2,%3\n"						\ "	m	r2,%3\n"						\ "	m	r2,%3\n"						\ "	m	r2,%3\n"						\ "	m	r2,%3\n"						\ "	m	r2,%3\n"						\ "	m	r2,%3\n"						\ "	m	r2,%3\n"						\ "	m	r2,%3\n"						\ "	m	r2,%3\n"						\ "	m	r2,%3\n"						\ "	m	r2,%3\n"						\ "	m	r2,%3\n"						\ "	m	r2,%3\n"						\ "	m	r2,%3\n"						\ "	cas	%0,r2,r0\n"						\ "	mfs	r10,%1"							\ 	     : "=r" ((USItype) (ph)),					\ 	       "=r" ((USItype) (pl))					\ 	     : "%r" (__m0),						\ 		"r" (__m1)						\ 	     : "r2");							\     (ph) += ((((SItype) __m0>> 31)& __m1)				\ 	     + (((SItype) __m1>> 31)& __m0));				\   } while (0)
end_define

begin_define
define|#
directive|define
name|UMUL_TIME
value|20
end_define

begin_define
define|#
directive|define
name|UDIV_TIME
value|200
end_define

begin_define
define|#
directive|define
name|count_leading_zeros
parameter_list|(
name|count
parameter_list|,
name|x
parameter_list|)
define|\
value|do {									\     if ((x)>= 0x10000)							\       __asm__ ("clz	%0,%1"						\ 	       : "=r" ((USItype) (count))				\ 	       : "r" ((USItype) (x)>> 16));				\     else								\       {									\ 	__asm__ ("clz	%0,%1"						\ 		 : "=r" ((USItype) (count))				\ 		 : "r" ((USItype) (x)));					\ 	(count) += 16;							\       }									\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sh2__
argument_list|)
operator|&&
name|W_TYPE_SIZE
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|umul_ppmm
parameter_list|(
name|w1
parameter_list|,
name|w0
parameter_list|,
name|u
parameter_list|,
name|v
parameter_list|)
define|\
value|__asm__ (								\        "dmulu.l	%2,%3\n\tsts	macl,%1\n\tsts	mach,%0"		\ 	   : "=r" ((USItype)(w1)),					\ 	     "=r" ((USItype)(w0))					\ 	   : "r" ((USItype)(u)),					\ 	     "r" ((USItype)(v))						\ 	   : "macl", "mach")
end_define

begin_define
define|#
directive|define
name|UMUL_TIME
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SH5__
argument_list|)
operator|&&
name|__SHMEDIA__
operator|&&
name|W_TYPE_SIZE
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|__umulsidi3
parameter_list|(
name|u
parameter_list|,
name|v
parameter_list|)
value|((UDItype)(USItype)u*(USItype)v)
end_define

begin_define
define|#
directive|define
name|count_leading_zeros
parameter_list|(
name|count
parameter_list|,
name|x
parameter_list|)
define|\
value|do									\     {									\       UDItype x_ = (USItype)(x);					\       SItype c_;							\ 									\       __asm__ ("nsb %1, %0" : "=r" (c_) : "r" (x_));			\       (count) = c_ - 31;						\     }									\   while (0)
end_define

begin_define
define|#
directive|define
name|COUNT_LEADING_ZEROS_0
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sparc__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__arch64__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__sparcv9
argument_list|)
expr|\
operator|&&
name|W_TYPE_SIZE
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|add_ssaaaa
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
value|__asm__ ("addcc %r4,%5,%1\n\taddx %r2,%3,%0"				\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "%rJ" ((USItype) (ah)),					\ 	     "rI" ((USItype) (bh)),					\ 	     "%rJ" ((USItype) (al)),					\ 	     "rI" ((USItype) (bl))					\ 	   __CLOBBER_CC)
end_define

begin_define
define|#
directive|define
name|sub_ddmmss
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
value|__asm__ ("subcc %r4,%5,%1\n\tsubx %r2,%3,%0"				\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "rJ" ((USItype) (ah)),					\ 	     "rI" ((USItype) (bh)),					\ 	     "rJ" ((USItype) (al)),					\ 	     "rI" ((USItype) (bl))					\ 	   __CLOBBER_CC)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sparc_v8__
argument_list|)
end_if

begin_define
define|#
directive|define
name|umul_ppmm
parameter_list|(
name|w1
parameter_list|,
name|w0
parameter_list|,
name|u
parameter_list|,
name|v
parameter_list|)
define|\
value|__asm__ ("umul %2,%3,%1;rd %%y,%0"					\ 	   : "=r" ((USItype) (w1)),					\ 	     "=r" ((USItype) (w0))					\ 	   : "r" ((USItype) (u)),					\ 	     "r" ((USItype) (v)))
end_define

begin_define
define|#
directive|define
name|udiv_qrnnd
parameter_list|(
name|__q
parameter_list|,
name|__r
parameter_list|,
name|__n1
parameter_list|,
name|__n0
parameter_list|,
name|__d
parameter_list|)
define|\
value|__asm__ ("mov %2,%%y;nop;nop;nop;udiv %3,%4,%0;umul %0,%4,%1;sub %3,%1,%1"\ 	   : "=&r" ((USItype) (__q)),					\ 	     "=&r" ((USItype) (__r))					\ 	   : "r" ((USItype) (__n1)),					\ 	     "r" ((USItype) (__n0)),					\ 	     "r" ((USItype) (__d)))
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sparclite__
argument_list|)
end_if

begin_comment
comment|/* This has hardware multiply but not divide.  It also has two additional    instructions scan (ffs from high bit) and divscc.  */
end_comment

begin_define
define|#
directive|define
name|umul_ppmm
parameter_list|(
name|w1
parameter_list|,
name|w0
parameter_list|,
name|u
parameter_list|,
name|v
parameter_list|)
define|\
value|__asm__ ("umul %2,%3,%1;rd %%y,%0"					\ 	   : "=r" ((USItype) (w1)),					\ 	     "=r" ((USItype) (w0))					\ 	   : "r" ((USItype) (u)),					\ 	     "r" ((USItype) (v)))
end_define

begin_define
define|#
directive|define
name|udiv_qrnnd
parameter_list|(
name|q
parameter_list|,
name|r
parameter_list|,
name|n1
parameter_list|,
name|n0
parameter_list|,
name|d
parameter_list|)
define|\
value|__asm__ ("! Inlined udiv_qrnnd\n"					\ "	wr	%%g0,%2,%%y	! Not a delayed write for sparclite\n"	\ "	tst	%%g0\n"							\ "	divscc	%3,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%%g1\n"						\ "	divscc	%%g1,%4,%0\n"						\ "	rd	%%y,%1\n"						\ "	bl,a 1f\n"							\ "	add	%1,%4,%1\n"						\ "1:	! End of inline udiv_qrnnd"					\ 	   : "=r" ((USItype) (q)),					\ 	     "=r" ((USItype) (r))					\ 	   : "r" ((USItype) (n1)),					\ 	     "r" ((USItype) (n0)),					\ 	     "rI" ((USItype) (d))					\ 	   : "g1" __AND_CLOBBER_CC)
end_define

begin_define
define|#
directive|define
name|UDIV_TIME
value|37
end_define

begin_define
define|#
directive|define
name|count_leading_zeros
parameter_list|(
name|count
parameter_list|,
name|x
parameter_list|)
define|\
value|do {                                                                  \   __asm__ ("scan %1,1,%0"                                               \            : "=r" ((USItype) (count))                                   \            : "r" ((USItype) (x)));					\   } while (0)
end_define

begin_comment
comment|/* Early sparclites return 63 for an argument of 0, but they warn that future    implementations might change this.  Therefore, leave COUNT_LEADING_ZEROS_0    undefined.  */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SPARC without integer multiplication and divide instructions.    (i.e. at least Sun4/20,40,60,65,75,110,260,280,330,360,380,470,490) */
end_comment

begin_define
define|#
directive|define
name|umul_ppmm
parameter_list|(
name|w1
parameter_list|,
name|w0
parameter_list|,
name|u
parameter_list|,
name|v
parameter_list|)
define|\
value|__asm__ ("! Inlined umul_ppmm\n"					\ "	wr	%%g0,%2,%%y	! SPARC has 0-3 delay insn after a wr\n"\ "	sra	%3,31,%%o5	! Don't move this insn\n"		\ "	and	%2,%%o5,%%o5	! Don't move this insn\n"		\ "	andcc	%%g0,0,%%g1	! Don't move this insn\n"		\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,%3,%%g1\n"						\ "	mulscc	%%g1,0,%%g1\n"						\ "	add	%%g1,%%o5,%0\n"						\ "	rd	%%y,%1"							\ 	   : "=r" ((USItype) (w1)),					\ 	     "=r" ((USItype) (w0))					\ 	   : "%rI" ((USItype) (u)),					\ 	     "r" ((USItype) (v))						\ 	   : "g1", "o5" __AND_CLOBBER_CC)
end_define

begin_define
define|#
directive|define
name|UMUL_TIME
value|39
end_define

begin_comment
comment|/* 39 instructions */
end_comment

begin_comment
comment|/* It's quite necessary to add this much assembler for the sparc.    The default udiv_qrnnd (in C) is more than 10 times slower!  */
end_comment

begin_define
define|#
directive|define
name|udiv_qrnnd
parameter_list|(
name|__q
parameter_list|,
name|__r
parameter_list|,
name|__n1
parameter_list|,
name|__n0
parameter_list|,
name|__d
parameter_list|)
define|\
value|__asm__ ("! Inlined udiv_qrnnd\n"					\ "	mov	32,%%g1\n"						\ "	subcc	%1,%2,%%g0\n"						\ "1:	bcs	5f\n"							\ "	 addxcc %0,%0,%0	! shift n1n0 and a q-bit in lsb\n"	\ "	sub	%1,%2,%1	! this kills msb of n\n"		\ "	addx	%1,%1,%1	! so this can't give carry\n"		\ "	subcc	%%g1,1,%%g1\n"						\ "2:	bne	1b\n"							\ "	 subcc	%1,%2,%%g0\n"						\ "	bcs	3f\n"							\ "	 addxcc %0,%0,%0	! shift n1n0 and a q-bit in lsb\n"	\ "	b	3f\n"							\ "	 sub	%1,%2,%1	! this kills msb of n\n"		\ "4:	sub	%1,%2,%1\n"						\ "5:	addxcc	%1,%1,%1\n"						\ "	bcc	2b\n"							\ "	 subcc	%%g1,1,%%g1\n"						\ "! Got carry from n.  Subtract next step to cancel this carry.\n"	\ "	bne	4b\n"							\ "	 addcc	%0,%0,%0	! shift n1n0 and a 0-bit in lsb\n"	\ "	sub	%1,%2,%1\n"						\ "3:	xnor	%0,0,%0\n"						\ "	! End of inline udiv_qrnnd"					\ 	   : "=&r" ((USItype) (__q)),					\ 	     "=&r" ((USItype) (__r))					\ 	   : "r" ((USItype) (__d)),					\ 	     "1" ((USItype) (__n1)),					\ 	     "0" ((USItype) (__n0)) : "g1" __AND_CLOBBER_CC)
end_define

begin_define
define|#
directive|define
name|UDIV_TIME
value|(3+7*32)
end_define

begin_comment
comment|/* 7 instructions/iteration. 32 iterations.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __sparclite__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __sparc_v8__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sparc32 */
end_comment

begin_if
if|#
directive|if
operator|(
operator|(
name|defined
argument_list|(
name|__sparc__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__arch64__
argument_list|)
operator|)
operator|||
name|defined
argument_list|(
name|__sparcv9
argument_list|)
operator|)
expr|\
operator|&&
name|W_TYPE_SIZE
operator|==
literal|64
end_if

begin_define
define|#
directive|define
name|add_ssaaaa
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
value|__asm__ ("addcc %r4,%5,%1\n\t"					\    	   "add %r2,%3,%0\n\t"						\    	   "bcs,a,pn %%xcc, 1f\n\t"					\    	   "add %0, 1, %0\n"						\ 	   "1:"								\ 	   : "=r" ((UDItype)(sh)),				      	\ 	     "=&r" ((UDItype)(sl))				      	\ 	   : "%rJ" ((UDItype)(ah)),				     	\ 	     "rI" ((UDItype)(bh)),				      	\ 	     "%rJ" ((UDItype)(al)),				     	\ 	     "rI" ((UDItype)(bl))				       	\ 	   __CLOBBER_CC)
end_define

begin_define
define|#
directive|define
name|sub_ddmmss
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
value|__asm__ ("subcc %r4,%5,%1\n\t"					\    	   "sub %r2,%3,%0\n\t"						\    	   "bcs,a,pn %%xcc, 1f\n\t"					\    	   "sub %0, 1, %0\n\t"						\ 	   "1:"								\ 	   : "=r" ((UDItype)(sh)),				      	\ 	     "=&r" ((UDItype)(sl))				      	\ 	   : "rJ" ((UDItype)(ah)),				     	\ 	     "rI" ((UDItype)(bh)),				      	\ 	     "rJ" ((UDItype)(al)),				     	\ 	     "rI" ((UDItype)(bl))				       	\ 	   __CLOBBER_CC)
end_define

begin_define
define|#
directive|define
name|umul_ppmm
parameter_list|(
name|wh
parameter_list|,
name|wl
parameter_list|,
name|u
parameter_list|,
name|v
parameter_list|)
define|\
value|do {									\ 	  UDItype tmp1, tmp2, tmp3, tmp4;				\ 	  __asm__ __volatile__ (					\ 		   "srl %7,0,%3\n\t"					\ 		   "mulx %3,%6,%1\n\t"					\ 		   "srlx %6,32,%2\n\t"					\ 		   "mulx %2,%3,%4\n\t"					\ 		   "sllx %4,32,%5\n\t"					\ 		   "srl %6,0,%3\n\t"					\ 		   "sub %1,%5,%5\n\t"					\ 		   "srlx %5,32,%5\n\t"					\ 		   "addcc %4,%5,%4\n\t"					\ 		   "srlx %7,32,%5\n\t"					\ 		   "mulx %3,%5,%3\n\t"					\ 		   "mulx %2,%5,%5\n\t"					\ 		   "sethi %%hi(0x80000000),%2\n\t"			\ 		   "addcc %4,%3,%4\n\t"					\ 		   "srlx %4,32,%4\n\t"					\ 		   "add %2,%2,%2\n\t"					\ 		   "movcc %%xcc,%%g0,%2\n\t"				\ 		   "addcc %5,%4,%5\n\t"					\ 		   "sllx %3,32,%3\n\t"					\ 		   "add %1,%3,%1\n\t"					\ 		   "add %5,%2,%0"					\ 	   : "=r" ((UDItype)(wh)),					\ 	     "=&r" ((UDItype)(wl)),					\ 	     "=&r" (tmp1), "=&r" (tmp2), "=&r" (tmp3), "=&r" (tmp4)	\ 	   : "r" ((UDItype)(u)),					\ 	     "r" ((UDItype)(v))						\ 	   __CLOBBER_CC);						\   } while (0)
end_define

begin_define
define|#
directive|define
name|UMUL_TIME
value|96
end_define

begin_define
define|#
directive|define
name|UDIV_TIME
value|230
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sparc64 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__vax__
argument_list|)
operator|&&
name|W_TYPE_SIZE
operator|==
literal|32
end_if

begin_define
define|#
directive|define
name|add_ssaaaa
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
value|__asm__ ("addl2 %5,%1\n\tadwc %3,%0"					\ 	   : "=g" ((USItype) (sh)),					\ 	     "=&g" ((USItype) (sl))					\ 	   : "%0" ((USItype) (ah)),					\ 	     "g" ((USItype) (bh)),					\ 	     "%1" ((USItype) (al)),					\ 	     "g" ((USItype) (bl)))
end_define

begin_define
define|#
directive|define
name|sub_ddmmss
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
value|__asm__ ("subl2 %5,%1\n\tsbwc %3,%0"					\ 	   : "=g" ((USItype) (sh)),					\ 	     "=&g" ((USItype) (sl))					\ 	   : "0" ((USItype) (ah)),					\ 	     "g" ((USItype) (bh)),					\ 	     "1" ((USItype) (al)),					\ 	     "g" ((USItype) (bl)))
end_define

begin_define
define|#
directive|define
name|umul_ppmm
parameter_list|(
name|xh
parameter_list|,
name|xl
parameter_list|,
name|m0
parameter_list|,
name|m1
parameter_list|)
define|\
value|do {									\     union {								\ 	UDItype __ll;							\ 	struct {USItype __l, __h;} __i;					\       } __xx;								\     USItype __m0 = (m0), __m1 = (m1);					\     __asm__ ("emul %1,%2,$0,%0"						\ 	     : "=r" (__xx.__ll)						\ 	     : "g" (__m0),						\ 	       "g" (__m1));						\     (xh) = __xx.__i.__h;						\     (xl) = __xx.__i.__l;						\     (xh) += ((((SItype) __m0>> 31)& __m1)				\ 	     + (((SItype) __m1>> 31)& __m0));				\   } while (0)
end_define

begin_define
define|#
directive|define
name|sdiv_qrnnd
parameter_list|(
name|q
parameter_list|,
name|r
parameter_list|,
name|n1
parameter_list|,
name|n0
parameter_list|,
name|d
parameter_list|)
define|\
value|do {									\     union {DItype __ll;							\ 	   struct {SItype __l, __h;} __i;				\ 	  } __xx;							\     __xx.__i.__h = n1; __xx.__i.__l = n0;				\     __asm__ ("ediv %3,%2,%0,%1"						\ 	     : "=g" (q), "=g" (r)					\ 	     : "g" (__xx.__ll), "g" (d));				\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __vax__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__z8000__
argument_list|)
operator|&&
name|W_TYPE_SIZE
operator|==
literal|16
end_if

begin_define
define|#
directive|define
name|add_ssaaaa
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
value|__asm__ ("add	%H1,%H5\n\tadc	%H0,%H3"				\ 	   : "=r" ((unsigned int)(sh)),					\ 	     "=&r" ((unsigned int)(sl))					\ 	   : "%0" ((unsigned int)(ah)),					\ 	     "r" ((unsigned int)(bh)),					\ 	     "%1" ((unsigned int)(al)),					\ 	     "rQR" ((unsigned int)(bl)))
end_define

begin_define
define|#
directive|define
name|sub_ddmmss
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
value|__asm__ ("sub	%H1,%H5\n\tsbc	%H0,%H3"				\ 	   : "=r" ((unsigned int)(sh)),					\ 	     "=&r" ((unsigned int)(sl))					\ 	   : "0" ((unsigned int)(ah)),					\ 	     "r" ((unsigned int)(bh)),					\ 	     "1" ((unsigned int)(al)),					\ 	     "rQR" ((unsigned int)(bl)))
end_define

begin_define
define|#
directive|define
name|umul_ppmm
parameter_list|(
name|xh
parameter_list|,
name|xl
parameter_list|,
name|m0
parameter_list|,
name|m1
parameter_list|)
define|\
value|do {									\     union {long int __ll;						\ 	   struct {unsigned int __h, __l;} __i;				\ 	  } __xx;							\     unsigned int __m0 = (m0), __m1 = (m1);				\     __asm__ ("mult	%S0,%H3"					\ 	     : "=r" (__xx.__i.__h),					\ 	       "=r" (__xx.__i.__l)					\ 	     : "%1" (__m0),						\ 	       "rQR" (__m1));						\     (xh) = __xx.__i.__h; (xl) = __xx.__i.__l;				\     (xh) += ((((signed int) __m0>> 15)& __m1)				\ 	     + (((signed int) __m1>> 15)& __m0));			\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __z8000__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_comment
comment|/* If this machine has no inline assembler, use C macros.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|add_ssaaaa
argument_list|)
end_if

begin_define
define|#
directive|define
name|add_ssaaaa
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
value|do {									\     UWtype __x;								\     __x = (al) + (bl);							\     (sh) = (ah) + (bh) + (__x< (al));					\     (sl) = __x;								\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|sub_ddmmss
argument_list|)
end_if

begin_define
define|#
directive|define
name|sub_ddmmss
parameter_list|(
name|sh
parameter_list|,
name|sl
parameter_list|,
name|ah
parameter_list|,
name|al
parameter_list|,
name|bh
parameter_list|,
name|bl
parameter_list|)
define|\
value|do {									\     UWtype __x;								\     __x = (al) - (bl);							\     (sh) = (ah) - (bh) - (__x> (al));					\     (sl) = __x;								\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If we lack umul_ppmm but have smul_ppmm, define umul_ppmm in terms of    smul_ppmm.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|umul_ppmm
argument_list|)
operator|&&
name|defined
argument_list|(
name|smul_ppmm
argument_list|)
end_if

begin_define
define|#
directive|define
name|umul_ppmm
parameter_list|(
name|w1
parameter_list|,
name|w0
parameter_list|,
name|u
parameter_list|,
name|v
parameter_list|)
define|\
value|do {									\     UWtype __w1;							\     UWtype __xm0 = (u), __xm1 = (v);					\     smul_ppmm (__w1, w0, __xm0, __xm1);					\     (w1) = __w1 + (-(__xm0>> (W_TYPE_SIZE - 1))& __xm1)		\ 		+ (-(__xm1>> (W_TYPE_SIZE - 1))& __xm0);		\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If we still don't have umul_ppmm, define it using plain C.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|umul_ppmm
argument_list|)
end_if

begin_define
define|#
directive|define
name|umul_ppmm
parameter_list|(
name|w1
parameter_list|,
name|w0
parameter_list|,
name|u
parameter_list|,
name|v
parameter_list|)
define|\
value|do {									\     UWtype __x0, __x1, __x2, __x3;					\     UHWtype __ul, __vl, __uh, __vh;					\ 									\     __ul = __ll_lowpart (u);						\     __uh = __ll_highpart (u);						\     __vl = __ll_lowpart (v);						\     __vh = __ll_highpart (v);						\ 									\     __x0 = (UWtype) __ul * __vl;					\     __x1 = (UWtype) __ul * __vh;					\     __x2 = (UWtype) __uh * __vl;					\     __x3 = (UWtype) __uh * __vh;					\ 									\     __x1 += __ll_highpart (__x0);
comment|/* this can't give carry */
value|\     __x1 += __x2;
comment|/* but this indeed can */
value|\     if (__x1< __x2)
comment|/* did we get it? */
value|\       __x3 += __ll_B;
comment|/* yes, add it in the proper pos.  */
value|\ 									\     (w1) = __x3 + __ll_highpart (__x1);					\     (w0) = __ll_lowpart (__x1) * __ll_B + __ll_lowpart (__x0);		\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__umulsidi3
argument_list|)
end_if

begin_define
define|#
directive|define
name|__umulsidi3
parameter_list|(
name|u
parameter_list|,
name|v
parameter_list|)
define|\
value|({DWunion __w;							\     umul_ppmm (__w.s.high, __w.s.low, u, v);				\     __w.ll; })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define this unconditionally, so it can be used for debugging.  */
end_comment

begin_define
define|#
directive|define
name|__udiv_qrnnd_c
parameter_list|(
name|q
parameter_list|,
name|r
parameter_list|,
name|n1
parameter_list|,
name|n0
parameter_list|,
name|d
parameter_list|)
define|\
value|do {									\     UWtype __d1, __d0, __q1, __q0;					\     UWtype __r1, __r0, __m;						\     __d1 = __ll_highpart (d);						\     __d0 = __ll_lowpart (d);						\ 									\     __r1 = (n1) % __d1;							\     __q1 = (n1) / __d1;							\     __m = (UWtype) __q1 * __d0;						\     __r1 = __r1 * __ll_B | __ll_highpart (n0);				\     if (__r1< __m)							\       {									\ 	__q1--, __r1 += (d);						\ 	if (__r1>= (d))
comment|/* i.e. we didn't get carry when adding to __r1 */
value|\ 	  if (__r1< __m)						\ 	    __q1--, __r1 += (d);					\       }									\     __r1 -= __m;							\ 									\     __r0 = __r1 % __d1;							\     __q0 = __r1 / __d1;							\     __m = (UWtype) __q0 * __d0;						\     __r0 = __r0 * __ll_B | __ll_lowpart (n0);				\     if (__r0< __m)							\       {									\ 	__q0--, __r0 += (d);						\ 	if (__r0>= (d))						\ 	  if (__r0< __m)						\ 	    __q0--, __r0 += (d);					\       }									\     __r0 -= __m;							\ 									\     (q) = (UWtype) __q1 * __ll_B | __q0;				\     (r) = __r0;								\   } while (0)
end_define

begin_comment
comment|/* If the processor has no udiv_qrnnd but sdiv_qrnnd, go through    __udiv_w_sdiv (defined in libgcc or elsewhere).  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|udiv_qrnnd
argument_list|)
operator|&&
name|defined
argument_list|(
name|sdiv_qrnnd
argument_list|)
end_if

begin_define
define|#
directive|define
name|udiv_qrnnd
parameter_list|(
name|q
parameter_list|,
name|r
parameter_list|,
name|nh
parameter_list|,
name|nl
parameter_list|,
name|d
parameter_list|)
define|\
value|do {									\     USItype __r;							\     (q) = __udiv_w_sdiv (&__r, nh, nl, d);				\     (r) = __r;								\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If udiv_qrnnd was not defined for this processor, use __udiv_qrnnd_c.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|udiv_qrnnd
argument_list|)
end_if

begin_define
define|#
directive|define
name|UDIV_NEEDS_NORMALIZATION
value|1
end_define

begin_define
define|#
directive|define
name|udiv_qrnnd
value|__udiv_qrnnd_c
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|count_leading_zeros
argument_list|)
end_if

begin_decl_stmt
specifier|extern
specifier|const
name|UQItype
name|__clz_tab
index|[]
name|ATTRIBUTE_HIDDEN
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|count_leading_zeros
parameter_list|(
name|count
parameter_list|,
name|x
parameter_list|)
define|\
value|do {									\     UWtype __xr = (x);							\     UWtype __a;								\ 									\     if (W_TYPE_SIZE<= 32)						\       {									\ 	__a = __xr< ((UWtype)1<<2*__BITS4)				\ 	  ? (__xr< ((UWtype)1<<__BITS4) ? 0 : __BITS4)			\ 	  : (__xr< ((UWtype)1<<3*__BITS4) ?  2*__BITS4 : 3*__BITS4);	\       }									\     else								\       {									\ 	for (__a = W_TYPE_SIZE - 8; __a> 0; __a -= 8)			\ 	  if (((__xr>> __a)& 0xff) != 0)				\ 	    break;							\       }									\ 									\     (count) = W_TYPE_SIZE - (__clz_tab[__xr>> __a] + __a);		\   } while (0)
end_define

begin_define
define|#
directive|define
name|COUNT_LEADING_ZEROS_0
value|W_TYPE_SIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|count_trailing_zeros
argument_list|)
end_if

begin_comment
comment|/* Define count_trailing_zeros using count_leading_zeros.  The latter might be    defined in asm, but if it is not, the C version above is good enough.  */
end_comment

begin_define
define|#
directive|define
name|count_trailing_zeros
parameter_list|(
name|count
parameter_list|,
name|x
parameter_list|)
define|\
value|do {									\     UWtype __ctz_x = (x);						\     UWtype __ctz_c;							\     count_leading_zeros (__ctz_c, __ctz_x& -__ctz_x);			\     (count) = W_TYPE_SIZE - 1 - __ctz_c;				\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UDIV_NEEDS_NORMALIZATION
end_ifndef

begin_define
define|#
directive|define
name|UDIV_NEEDS_NORMALIZATION
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

