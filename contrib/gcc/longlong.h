begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* longlong.h -- definitions for mixed size 32/64 bit arithmetic.    Copyright (C) 1991, 92, 94, 95, 96, 1997, 1998 Free Software Foundation, Inc.     This definition file is free software; you can redistribute it    and/or modify it under the terms of the GNU General Public    License as published by the Free Software Foundation; either    version 2, or (at your option) any later version.     This definition file is distributed in the hope that it will be    useful, but WITHOUT ANY WARRANTY; without even the implied    warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.    See the GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SI_TYPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|SI_TYPE_SIZE
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__BITS4
value|(SI_TYPE_SIZE / 4)
end_define

begin_define
define|#
directive|define
name|__ll_B
value|(1L<< (SI_TYPE_SIZE / 2))
end_define

begin_define
define|#
directive|define
name|__ll_lowpart
parameter_list|(
name|t
parameter_list|)
value|((USItype) (t) % __ll_B)
end_define

begin_define
define|#
directive|define
name|__ll_highpart
parameter_list|(
name|t
parameter_list|)
value|((USItype) (t) / __ll_B)
end_define

begin_comment
comment|/* Define auxiliary asm macros.     1) umul_ppmm(high_prod, low_prod, multipler, multiplicand)    multiplies two USItype integers MULTIPLER and MULTIPLICAND,    and generates a two-part USItype product in HIGH_PROD and    LOW_PROD.     2) __umulsidi3(a,b) multiplies two USItype integers A and B,    and returns a UDItype product.  This is just a variant of umul_ppmm.     3) udiv_qrnnd(quotient, remainder, high_numerator, low_numerator,    denominator) divides a two-word unsigned integer, composed by the    integers HIGH_NUMERATOR and LOW_NUMERATOR, by DENOMINATOR and    places the quotient in QUOTIENT and the remainder in REMAINDER.    HIGH_NUMERATOR must be less than DENOMINATOR for correct operation.    If, in addition, the most significant bit of DENOMINATOR must be 1,    then the pre-processor symbol UDIV_NEEDS_NORMALIZATION is defined to 1.     4) sdiv_qrnnd(quotient, remainder, high_numerator, low_numerator,    denominator).  Like udiv_qrnnd but the numbers are signed.  The    quotient is rounded towards 0.     5) count_leading_zeros(count, x) counts the number of zero-bits from    the msb to the first non-zero bit.  This is the number of steps X    needs to be shifted left to set the msb.  Undefined for X == 0.     6) add_ssaaaa(high_sum, low_sum, high_addend_1, low_addend_1,    high_addend_2, low_addend_2) adds two two-word unsigned integers,    composed by HIGH_ADDEND_1 and LOW_ADDEND_1, and HIGH_ADDEND_2 and    LOW_ADDEND_2 respectively.  The result is placed in HIGH_SUM and    LOW_SUM.  Overflow (i.e. carry out) is not stored anywhere, and is    lost.     7) sub_ddmmss(high_difference, low_difference, high_minuend,    low_minuend, high_subtrahend, low_subtrahend) subtracts two    two-word unsigned integers, composed by HIGH_MINUEND_1 and    LOW_MINUEND_1, and HIGH_SUBTRAHEND_2 and LOW_SUBTRAHEND_2    respectively.  The result is placed in HIGH_DIFFERENCE and    LOW_DIFFERENCE.  Overflow (i.e. carry out) is not stored anywhere,    and is lost.     If any of these macros are left undefined for a particular CPU,    C macros are used.  */
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
name|__a29k__
argument_list|)
operator|||
name|defined
argument_list|(
name|_AM29K
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
value|__asm__ ("add %1,%4,%5 	addc %0,%2,%3"							\ 	   : "=r" ((USItype) (sh)),					\ 	    "=&r" ((USItype) (sl))					\ 	   : "%r" ((USItype) (ah)),					\ 	     "rI" ((USItype) (bh)),					\ 	     "%r" ((USItype) (al)),					\ 	     "rI" ((USItype) (bl)))
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
value|__asm__ ("sub %1,%4,%5 	subc %0,%2,%3"							\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "r" ((USItype) (ah)),					\ 	     "rI" ((USItype) (bh)),					\ 	     "r" ((USItype) (al)),					\ 	     "rI" ((USItype) (bl)))
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
value|do {									\     USItype __m0 = (m0), __m1 = (m1);					\     __asm__ ("multiplu %0,%1,%2"					\ 	     : "=r" ((USItype) (xl))					\ 	     : "r" (__m0),						\ 	       "r" (__m1));						\     __asm__ ("multmu %0,%1,%2"						\ 	     : "=r" ((USItype) (xh))					\ 	     : "r" (__m0),						\ 	       "r" (__m1));						\   } while (0)
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
value|__asm__ ("dividu %0,%3,%4"						\ 	   : "=r" ((USItype) (q)),					\ 	     "=q" ((USItype) (r))					\ 	   : "1" ((USItype) (n1)),					\ 	     "r" ((USItype) (n0)),					\ 	     "r" ((USItype) (d)))
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
value|__asm__ ("clz %0,%1"						\ 	     : "=r" ((USItype) (count))					\ 	     : "r" ((USItype) (x)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __a29k__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__arc__
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
value|__asm__ ("add.f	%1, %4, %5 	adc	%0, %2, %3"						\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "%r" ((USItype) (ah)),					\ 	     "rIJ" ((USItype) (bh)),					\ 	     "%r" ((USItype) (al)),					\ 	     "rIJ" ((USItype) (bl)))
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
value|__asm__ ("sub.f	%1, %4, %5 	sbc	%0, %2, %3"						\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "r" ((USItype) (ah)),					\ 	     "rIJ" ((USItype) (bh)),					\ 	     "r" ((USItype) (al)),					\ 	     "rIJ" ((USItype) (bl)))
end_define

begin_comment
comment|/* Call libgcc1 routine.  */
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
value|do {									\   DIunion __w;								\   __w.ll = __umulsidi3 (u, v);						\   w1 = __w.s.high;							\   w0 = __w.s.low;							\ } while (0)
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
value|__asm__ ("adds	%1, %4, %5 	adc	%0, %2, %3"						\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "%r" ((USItype) (ah)),					\ 	     "rI" ((USItype) (bh)),					\ 	     "%r" ((USItype) (al)),					\ 	     "rI" ((USItype) (bl)))
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
value|__asm__ ("subs	%1, %4, %5 	sbc	%0, %2, %3"						\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "r" ((USItype) (ah)),					\ 	     "rI" ((USItype) (bh)),					\ 	     "r" ((USItype) (al)),					\ 	     "rI" ((USItype) (bl)))
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
value|{register USItype __t0, __t1, __t2;					\   __asm__ ("%@ Inlined umul_ppmm 	mov	%2, %5, lsr #16 	mov	%0, %6, lsr #16 	bic	%3, %5, %2, lsl #16 	bic	%4, %6, %0, lsl #16 	mul	%1, %3, %4 	mul	%4, %2, %4 	mul	%3, %0, %3 	mul	%0, %2, %0 	adds	%3, %4, %3 	addcs	%0, %0, #65536 	adds	%1, %1, %3, lsl #16 	adc	%0, %0, %3, lsr #16"					\ 	   : "=&r" ((USItype) (xh)),					\ 	     "=r" ((USItype) (xl)),					\ 	     "=&r" (__t0), "=&r" (__t1), "=r" (__t2)			\ 	   : "r" ((USItype) (a)),					\ 	     "r" ((USItype) (b)));}
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
name|__clipper__
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
value|({union {UDItype __ll;						\ 	   struct {USItype __l, __h;} __i;				\ 	  } __xx;							\   __asm__ ("mulwux %2,%0"						\ 	   : "=r" (__xx.__ll)						\ 	   : "%0" ((USItype) (u)),					\ 	     "r" ((USItype) (v)));					\   (w1) = __xx.__i.__h; (w0) = __xx.__i.__l;})
end_define

begin_define
define|#
directive|define
name|smul_ppmm
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
value|({union {DItype __ll;							\ 	   struct {SItype __l, __h;} __i;				\ 	  } __xx;							\   __asm__ ("mulwx %2,%0"						\ 	   : "=r" (__xx.__ll)						\ 	   : "%0" ((SItype) (u)),					\ 	     "r" ((SItype) (v)));					\   (w1) = __xx.__i.__h; (w0) = __xx.__i.__l;})
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
value|({UDItype __w;							\     __asm__ ("mulwux %2,%0"						\ 	     : "=r" (__w)						\ 	     : "%0" ((USItype) (u)),					\ 	       "r" ((USItype) (v)));					\     __w; })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __clipper__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__gmicro__
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
value|__asm__ ("add.w %5,%1 	addx %3,%0"							\ 	   : "=g" ((USItype) (sh)),					\ 	     "=&g" ((USItype) (sl))					\ 	   : "%0" ((USItype) (ah)),					\ 	     "g" ((USItype) (bh)),					\ 	     "%1" ((USItype) (al)),					\ 	     "g" ((USItype) (bl)))
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
value|__asm__ ("sub.w %5,%1 	subx %3,%0"							\ 	   : "=g" ((USItype) (sh)),					\ 	     "=&g" ((USItype) (sl))					\ 	   : "0" ((USItype) (ah)),					\ 	     "g" ((USItype) (bh)),					\ 	     "1" ((USItype) (al)),					\ 	     "g" ((USItype) (bl)))
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
value|__asm__ ("mulx %3,%0,%1"						\ 	   : "=g" ((USItype) (ph)),					\ 	     "=r" ((USItype) (pl))					\ 	   : "%0" ((USItype) (m0)),					\ 	     "g" ((USItype) (m1)))
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
name|nh
parameter_list|,
name|nl
parameter_list|,
name|d
parameter_list|)
define|\
value|__asm__ ("divx %4,%0,%1"						\ 	   : "=g" ((USItype) (q)),					\ 	     "=r" ((USItype) (r))					\ 	   : "1" ((USItype) (nh)),					\ 	     "0" ((USItype) (nl)),					\ 	     "g" ((USItype) (d)))
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
value|__asm__ ("bsch/1 %1,%0"						\ 	   : "=g" (count)						\ 	   : "g" ((USItype) (x)),					\ 	     "0" ((USItype) 0))
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
name|__hppa
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
value|__asm__ ("add %4,%5,%1 	addc %2,%3,%0"							\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "%rM" ((USItype) (ah)),					\ 	     "rM" ((USItype) (bh)),					\ 	     "%rM" ((USItype) (al)),					\ 	     "rM" ((USItype) (bl)))
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
value|__asm__ ("sub %4,%5,%1 	subb %2,%3,%0"							\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "rM" ((USItype) (ah)),					\ 	     "rM" ((USItype) (bh)),					\ 	     "rM" ((USItype) (al)),					\ 	     "rM" ((USItype) (bl)))
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
value|do {									\     USItype __tmp;							\     __asm__ (								\        "ldi		1,%0 	extru,=		%1,15,16,%%r0		; Bits 31..16 zero? 	extru,tr	%1,15,16,%1		; No.  Shift down, skip add. 	ldo		16(%0),%0		; Yes.  Perform add. 	extru,=		%1,23,8,%%r0		; Bits 15..8 zero? 	extru,tr	%1,23,8,%1		; No.  Shift down, skip add. 	ldo		8(%0),%0		; Yes.  Perform add. 	extru,=		%1,27,4,%%r0		; Bits 7..4 zero? 	extru,tr	%1,27,4,%1		; No.  Shift down, skip add. 	ldo		4(%0),%0		; Yes.  Perform add. 	extru,=		%1,29,2,%%r0		; Bits 3..2 zero? 	extru,tr	%1,29,2,%1		; No.  Shift down, skip add. 	ldo		2(%0),%0		; Yes.  Perform add. 	extru		%1,30,1,%1		; Extract bit 1. 	sub		%0,%1,%0		; Subtract it. 	" : "=r" (count), "=r" (__tmp) : "1" (x));			\   } while (0)
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
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__i486__
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
value|__asm__ ("addl %5,%1 	adcl %3,%0"							\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "%0" ((USItype) (ah)),					\ 	     "g" ((USItype) (bh)),					\ 	     "%1" ((USItype) (al)),					\ 	     "g" ((USItype) (bl)))
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
value|__asm__ ("subl %5,%1 	sbbl %3,%0"							\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "0" ((USItype) (ah)),					\ 	     "g" ((USItype) (bh)),					\ 	     "1" ((USItype) (al)),					\ 	     "g" ((USItype) (bl)))
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
name|d
parameter_list|)
define|\
value|__asm__ ("divl %4"							\ 	   : "=a" ((USItype) (q)),					\ 	     "=d" ((USItype) (r))					\ 	   : "0" ((USItype) (n0)),					\ 	     "1" ((USItype) (n1)),					\ 	     "rm" ((USItype) (d)))
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
name|__i860__
argument_list|)
end_if

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Make sure these patterns really improve the code before    switching them on.  */
end_comment

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
value|do {									\     union								\       {									\ 	DItype __ll;							\ 	struct {USItype __l, __h;} __i;					\       }  __a, __b, __s;							\     __a.__i.__l = (al);							\     __a.__i.__h = (ah);							\     __b.__i.__l = (bl);							\     __b.__i.__h = (bh);							\     __asm__ ("fiadd.dd %1,%2,%0"					\ 	     : "=f" (__s.__ll)						\ 	     : "%f" (__a.__ll), "f" (__b.__ll));			\     (sh) = __s.__i.__h;							\     (sl) = __s.__i.__l;							\     } while (0)
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
value|do {									\     union								\       {									\ 	DItype __ll;							\ 	struct {USItype __l, __h;} __i;					\       }  __a, __b, __s;							\     __a.__i.__l = (al);							\     __a.__i.__h = (ah);							\     __b.__i.__l = (bl);							\     __b.__i.__h = (bh);							\     __asm__ ("fisub.dd %1,%2,%0"					\ 	     : "=f" (__s.__ll)						\ 	     : "%f" (__a.__ll), "f" (__b.__ll));			\     (sh) = __s.__i.__h;							\     (sl) = __s.__i.__l;							\     } while (0)
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
comment|/* __i860__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i960__
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
value|__asm__ ("cmp %0,%0 	addx %%5,%1 	addx %%3,%0"							\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "%0" ((USItype) (ah)),					\ 	     "r" ((USItype) (bh)),					\ 	     "%1" ((USItype) (al)),					\ 	     "r" ((USItype) (bl))					\ 	   : "cbit")
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
value|__asm__ ("cmp %0,%0 	subx %5,%1 	subx %3,%0"							\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "0" ((USItype) (ah)),					\ 	     "r" ((USItype) (bh)),					\ 	     "1" ((USItype) (al)),					\ 	     "r" ((USItype) (bl))					\ 	   : "cbit")
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
value|__asm__ ("add%.l %5,%1 	addx%.l %3,%0"							\ 	   : "=d" ((USItype) (sh)),					\ 	     "=&d" ((USItype) (sl))					\ 	   : "%0" ((USItype) (ah)),					\ 	     "d" ((USItype) (bh)),					\ 	     "%1" ((USItype) (al)),					\ 	     "g" ((USItype) (bl)))
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
value|__asm__ ("sub%.l %5,%1 	subx%.l %3,%0"							\ 	   : "=d" ((USItype) (sh)),					\ 	     "=&d" ((USItype) (sl))					\ 	   : "0" ((USItype) (ah)),					\ 	     "d" ((USItype) (bh)),					\ 	     "1" ((USItype) (al)),					\ 	     "g" ((USItype) (bl)))
end_define

begin_comment
comment|/* The '020, '030, '040 and CPU32 have 32x32->64 and 64/32->32q-32r. */
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
expr|\
operator|||
name|defined
argument_list|(
name|__NeXT__
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
operator|!
name|defined
argument_list|(
name|__mcf5200__
argument_list|)
end_if

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
value|__asm__ ("| Inlined umul_ppmm 	move%.l	%2,%/d0 	move%.l	%3,%/d1 	move%.l	%/d0,%/d2 	swap	%/d0 	move%.l	%/d1,%/d3 	swap	%/d1 	move%.w	%/d2,%/d4 	mulu	%/d3,%/d4 	mulu	%/d1,%/d2 	mulu	%/d0,%/d3 	mulu	%/d0,%/d1 	move%.l	%/d4,%/d0 	eor%.w	%/d0,%/d0 	swap	%/d0 	add%.l	%/d0,%/d2 	add%.l	%/d3,%/d2 	jcc	1f 	add%.l	%#65536,%/d1 1:	swap	%/d2 	moveq	%#0,%/d0 	move%.w	%/d2,%/d0 	move%.w	%/d4,%/d2 	move%.l	%/d2,%1 	add%.l	%/d1,%/d0 	move%.l	%/d0,%0"						\ 	   : "=g" ((USItype) (xh)),					\ 	     "=g" ((USItype) (xl))					\ 	   : "g" ((USItype) (a)),					\ 	     "g" ((USItype) (b))					\ 	   : "d0", "d1", "d2", "d3", "d4")
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
comment|/* not mcf5200 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not mc68020 */
end_comment

begin_comment
comment|/* The '020, '030, '040 and '060 have bitfield insns. */
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
name|__mc68060__
argument_list|)
operator|||
name|defined
argument_list|(
name|mc68060
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|__NeXT__
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
value|__asm__ ("addu.co %1,%r4,%r5 	addu.ci %0,%r2,%r3"						\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "%rJ" ((USItype) (ah)),					\ 	     "rJ" ((USItype) (bh)),					\ 	     "%rJ" ((USItype) (al)),					\ 	     "rJ" ((USItype) (bl)))
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
value|__asm__ ("subu.co %1,%r4,%r5 	subu.ci %0,%r2,%r3"						\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "rJ" ((USItype) (ah)),					\ 	     "rJ" ((USItype) (bh)),					\ 	     "rJ" ((USItype) (al)),					\ 	     "rJ" ((USItype) (bl)))
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ns32000__ */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_ARCH_PPC
argument_list|)
operator|||
name|defined
argument_list|(
name|_IBMR2
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
value|do {									\     if (__builtin_constant_p (bh)&& (bh) == 0)				\       __asm__ ("{a%I4|add%I4c} %1,%3,%4\n\t{aze|addze} %0,%2"		\ 	     : "=r" ((USItype) (sh)),					\ 	       "=&r" ((USItype) (sl))					\ 	     : "%r" ((USItype) (ah)),					\ 	       "%r" ((USItype) (al)),					\ 	       "rI" ((USItype) (bl)));					\     else if (__builtin_constant_p (bh)&& (bh) ==~(USItype) 0)		\       __asm__ ("{a%I4|add%I4c} %1,%3,%4\n\t{ame|addme} %0,%2"		\ 	     : "=r" ((USItype) (sh)),					\ 	       "=&r" ((USItype) (sl))					\ 	     : "%r" ((USItype) (ah)),					\ 	       "%r" ((USItype) (al)),					\ 	       "rI" ((USItype) (bl)));					\     else								\       __asm__ ("{a%I5|add%I5c} %1,%4,%5\n\t{ae|adde} %0,%2,%3"		\ 	     : "=r" ((USItype) (sh)),					\ 	       "=&r" ((USItype) (sl))					\ 	     : "%r" ((USItype) (ah)),					\ 	       "r" ((USItype) (bh)),					\ 	       "%r" ((USItype) (al)),					\ 	       "rI" ((USItype) (bl)));					\   } while (0)
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
value|do {									\     if (__builtin_constant_p (ah)&& (ah) == 0)				\       __asm__ ("{sf%I3|subf%I3c} %1,%4,%3\n\t{sfze|subfze} %0,%2"	\ 	       : "=r" ((USItype) (sh)),					\ 		 "=&r" ((USItype) (sl))					\ 	       : "r" ((USItype) (bh)),					\ 		 "rI" ((USItype) (al)),					\ 		 "r" ((USItype) (bl)));					\     else if (__builtin_constant_p (ah)&& (ah) ==~(USItype) 0)		\       __asm__ ("{sf%I3|subf%I3c} %1,%4,%3\n\t{sfme|subfme} %0,%2"	\ 	       : "=r" ((USItype) (sh)),					\ 		 "=&r" ((USItype) (sl))					\ 	       : "r" ((USItype) (bh)),					\ 		 "rI" ((USItype) (al)),					\ 		 "r" ((USItype) (bl)));					\     else if (__builtin_constant_p (bh)&& (bh) == 0)			\       __asm__ ("{sf%I3|subf%I3c} %1,%4,%3\n\t{ame|addme} %0,%2"		\ 	       : "=r" ((USItype) (sh)),					\ 		 "=&r" ((USItype) (sl))					\ 	       : "r" ((USItype) (ah)),					\ 		 "rI" ((USItype) (al)),					\ 		 "r" ((USItype) (bl)));					\     else if (__builtin_constant_p (bh)&& (bh) ==~(USItype) 0)		\       __asm__ ("{sf%I3|subf%I3c} %1,%4,%3\n\t{aze|addze} %0,%2"		\ 	       : "=r" ((USItype) (sh)),					\ 		 "=&r" ((USItype) (sl))					\ 	       : "r" ((USItype) (ah)),					\ 		 "rI" ((USItype) (al)),					\ 		 "r" ((USItype) (bl)));					\     else								\       __asm__ ("{sf%I4|subf%I4c} %1,%5,%4\n\t{sfe|subfe} %0,%3,%2"	\ 	       : "=r" ((USItype) (sh)),					\ 		 "=&r" ((USItype) (sl))					\ 	       : "r" ((USItype) (ah)),					\ 		 "r" ((USItype) (bh)),					\ 		 "rI" ((USItype) (al)),					\ 		 "r" ((USItype) (bl)));					\   } while (0)
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
value|__asm__ ("{cntlz|cntlzw} %0,%1"					\ 	   : "=r" ((USItype) (count))					\ 	   : "r" ((USItype) (x)))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_ARCH_PPC
argument_list|)
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
value|do {									\     USItype __m0 = (m0), __m1 = (m1);					\     __asm__ ("mulhwu %0,%1,%2"						\ 	     : "=r" ((USItype) ph)					\ 	     : "%r" (__m0),						\ 	       "r" (__m1));						\     (pl) = __m0 * __m1;							\   } while (0)
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
value|do {									\     SItype __m0 = (m0), __m1 = (m1);					\     __asm__ ("mulhw %0,%1,%2"						\ 	     : "=r" ((SItype) ph)					\ 	     : "%r" (__m0),						\ 	       "r" (__m1));						\     (pl) = __m0 * __m1;							\   } while (0)
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

begin_else
else|#
directive|else
end_else

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
value|do {									\     USItype __m0 = (m0), __m1 = (m1);					\     __asm__ ("mul %0,%2,%3"						\ 	     : "=r" ((USItype) (xh)),					\ 	       "=q" ((USItype) (xl))					\ 	     : "r" (__m0),						\ 	       "r" (__m1));						\     (xh) += ((((SItype) __m0>> 31)& __m1)				\ 	     + (((SItype) __m1>> 31)& __m0));				\   } while (0)
end_define

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
value|__asm__ ("mul %0,%2,%3"						\ 	   : "=r" ((SItype) (xh)),					\ 	     "=q" ((SItype) (xl))					\ 	   : "r" (m0),							\ 	     "r" (m1))
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
value|__asm__ ("div %0,%2,%4"						\ 	   : "=r" ((SItype) (q)), "=q" ((SItype) (r))			\ 	   : "r" ((SItype) (nh)), "1" ((SItype) (nl)), "r" ((SItype) (d)))
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
comment|/* Power architecture variants.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__pyr__
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
value|__asm__ ("addw	%5,%1 	addwc	%3,%0"							\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "%0" ((USItype) (ah)),					\ 	     "g" ((USItype) (bh)),					\ 	     "%1" ((USItype) (al)),					\ 	     "g" ((USItype) (bl)))
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
value|__asm__ ("subw	%5,%1 	subwb	%3,%0"							\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "0" ((USItype) (ah)),					\ 	     "g" ((USItype) (bh)),					\ 	     "1" ((USItype) (al)),					\ 	     "g" ((USItype) (bl)))
end_define

begin_comment
comment|/* This insn works on Pyramids with AP, XP, or MI CPUs, but not with SP.  */
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
value|({union {UDItype __ll;						\ 	   struct {USItype __h, __l;} __i;				\ 	  } __xx;							\   __asm__ ("movw %1,%R0 	uemul %2,%0"							\ 	   : "=&r" (__xx.__ll)						\ 	   : "g" ((USItype) (u)),					\ 	     "g" ((USItype) (v)));					\   (w1) = __xx.__i.__h; (w0) = __xx.__i.__l;})
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __pyr__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ibm032__
argument_list|)
end_if

begin_comment
comment|/* RT/ROMP */
end_comment

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
value|__asm__ ("a %1,%5 	ae %0,%3"							\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "%0" ((USItype) (ah)),					\ 	     "r" ((USItype) (bh)),					\ 	     "%1" ((USItype) (al)),					\ 	     "r" ((USItype) (bl)))
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
value|__asm__ ("s %1,%5 	se %0,%3"							\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "0" ((USItype) (ah)),					\ 	     "r" ((USItype) (bh)),					\ 	     "1" ((USItype) (al)),					\ 	     "r" ((USItype) (bl)))
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
value|do {									\     USItype __m0 = (m0), __m1 = (m1);					\     __asm__ (								\        "s	r2,r2 	mts	r10,%2 	m	r2,%3 	m	r2,%3 	m	r2,%3 	m	r2,%3 	m	r2,%3 	m	r2,%3 	m	r2,%3 	m	r2,%3 	m	r2,%3 	m	r2,%3 	m	r2,%3 	m	r2,%3 	m	r2,%3 	m	r2,%3 	m	r2,%3 	m	r2,%3 	cas	%0,r2,r0 	mfs	r10,%1"							\ 	     : "=r" ((USItype) (ph)),					\ 	       "=r" ((USItype) (pl))					\ 	     : "%r" (__m0),						\ 		"r" (__m1)						\ 	     : "r2");							\     (ph) += ((((SItype) __m0>> 31)& __m1)				\ 	     + (((SItype) __m1>> 31)& __m0));				\   } while (0)
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
name|__sparc__
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
value|__asm__ ("addcc %r4,%5,%1 	addx %r2,%3,%0"							\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "%rJ" ((USItype) (ah)),					\ 	     "rI" ((USItype) (bh)),					\ 	     "%rJ" ((USItype) (al)),					\ 	     "rI" ((USItype) (bl))					\ 	   __CLOBBER_CC)
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
value|__asm__ ("subcc %r4,%5,%1 	subx %r2,%3,%0"							\ 	   : "=r" ((USItype) (sh)),					\ 	     "=&r" ((USItype) (sl))					\ 	   : "rJ" ((USItype) (ah)),					\ 	     "rI" ((USItype) (bh)),					\ 	     "rJ" ((USItype) (al)),					\ 	     "rI" ((USItype) (bl))					\ 	   __CLOBBER_CC)
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
value|__asm__ ("mov %2,%%y;nop;nop;nop;udiv %3,%4,%0;umul %0,%4,%1;sub %3,%1,%1"\ 	   : "=&r" ((USItype) (q)),					\ 	     "=&r" ((USItype) (r))					\ 	   : "r" ((USItype) (n1)),					\ 	     "r" ((USItype) (n0)),					\ 	     "r" ((USItype) (d)))
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
value|__asm__ ("! Inlined udiv_qrnnd 	wr	%%g0,%2,%%y	! Not a delayed write for sparclite 	tst	%%g0 	divscc	%3,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%0 	rd	%%y,%1 	bl,a 1f 	add	%1,%4,%1 1:	! End of inline udiv_qrnnd"					\ 	   : "=r" ((USItype) (q)),					\ 	     "=r" ((USItype) (r))					\ 	   : "r" ((USItype) (n1)),					\ 	     "r" ((USItype) (n0)),					\ 	     "rI" ((USItype) (d))					\ 	   : "%g1" __AND_CLOBBER_CC)
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
value|__asm__ ("! Inlined umul_ppmm 	wr	%%g0,%2,%%y	! SPARC has 0-3 delay insn after a wr 	sra	%3,31,%%g2	! Don't move this insn 	and	%2,%%g2,%%g2	! Don't move this insn 	andcc	%%g0,0,%%g1	! Don't move this insn 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,0,%%g1 	add	%%g1,%%g2,%0 	rd	%%y,%1"							\ 	   : "=r" ((USItype) (w1)),					\ 	     "=r" ((USItype) (w0))					\ 	   : "%rI" ((USItype) (u)),					\ 	     "r" ((USItype) (v))						\ 	   : "%g1", "%g2" __AND_CLOBBER_CC)
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
value|__asm__ ("! Inlined udiv_qrnnd 	mov	32,%%g1 	subcc	%1,%2,%%g0 1:	bcs	5f 	 addxcc %0,%0,%0	! shift n1n0 and a q-bit in lsb 	sub	%1,%2,%1	! this kills msb of n 	addx	%1,%1,%1	! so this can't give carry 	subcc	%%g1,1,%%g1 2:	bne	1b 	 subcc	%1,%2,%%g0 	bcs	3f 	 addxcc %0,%0,%0	! shift n1n0 and a q-bit in lsb 	b	3f 	 sub	%1,%2,%1	! this kills msb of n 4:	sub	%1,%2,%1 5:	addxcc	%1,%1,%1 	bcc	2b 	 subcc	%%g1,1,%%g1 ! Got carry from n.  Subtract next step to cancel this carry. 	bne	4b 	 addcc	%0,%0,%0	! shift n1n0 and a 0-bit in lsb 	sub	%1,%2,%1 3:	xnor	%0,0,%0 	! End of inline udiv_qrnnd"					\ 	   : "=&r" ((USItype) (q)),					\ 	     "=&r" ((USItype) (r))					\ 	   : "r" ((USItype) (d)),					\ 	     "1" ((USItype) (n1)),					\ 	     "0" ((USItype) (n0)) : "%g1" __AND_CLOBBER_CC)
end_define

begin_define
define|#
directive|define
name|UDIV_TIME
value|(3+7*32)
end_define

begin_comment
comment|/* 7 instructions/iteration. 32 iterations. */
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
comment|/* __sparc__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__vax__
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
value|__asm__ ("addl2 %5,%1 	adwc %3,%0"							\ 	   : "=g" ((USItype) (sh)),					\ 	     "=&g" ((USItype) (sl))					\ 	   : "%0" ((USItype) (ah)),					\ 	     "g" ((USItype) (bh)),					\ 	     "%1" ((USItype) (al)),					\ 	     "g" ((USItype) (bl)))
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
value|__asm__ ("subl2 %5,%1 	sbwc %3,%0"							\ 	   : "=g" ((USItype) (sh)),					\ 	     "=&g" ((USItype) (sl))					\ 	   : "0" ((USItype) (ah)),					\ 	     "g" ((USItype) (bh)),					\ 	     "1" ((USItype) (al)),					\ 	     "g" ((USItype) (bl)))
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
value|do {									\     USItype __x;							\     __x = (al) + (bl);							\     (sh) = (ah) + (bh) + (__x< (al));					\     (sl) = __x;								\   } while (0)
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
value|do {									\     USItype __x;							\     __x = (al) - (bl);							\     (sh) = (ah) - (bh) - (__x> (al));					\     (sl) = __x;								\   } while (0)
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
value|do {									\     USItype __x0, __x1, __x2, __x3;					\     USItype __ul, __vl, __uh, __vh;					\ 									\     __ul = __ll_lowpart (u);						\     __uh = __ll_highpart (u);						\     __vl = __ll_lowpart (v);						\     __vh = __ll_highpart (v);						\ 									\     __x0 = (USItype) __ul * __vl;					\     __x1 = (USItype) __ul * __vh;					\     __x2 = (USItype) __uh * __vl;					\     __x3 = (USItype) __uh * __vh;					\ 									\     __x1 += __ll_highpart (__x0);
comment|/* this can't give carry */
value|\     __x1 += __x2;
comment|/* but this indeed can */
value|\     if (__x1< __x2)
comment|/* did we get it? */
value|\       __x3 += __ll_B;
comment|/* yes, add it in the proper pos. */
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
value|({DIunion __w;							\     umul_ppmm (__w.s.high, __w.s.low, u, v);				\     __w.ll; })
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
value|do {									\     USItype __d1, __d0, __q1, __q0;					\     USItype __r1, __r0, __m;						\     __d1 = __ll_highpart (d);						\     __d0 = __ll_lowpart (d);						\ 									\     __r1 = (n1) % __d1;							\     __q1 = (n1) / __d1;							\     __m = (USItype) __q1 * __d0;					\     __r1 = __r1 * __ll_B | __ll_highpart (n0);				\     if (__r1< __m)							\       {									\ 	__q1--, __r1 += (d);						\ 	if (__r1>= (d))
comment|/* i.e. we didn't get carry when adding to __r1 */
value|\ 	  if (__r1< __m)						\ 	    __q1--, __r1 += (d);					\       }									\     __r1 -= __m;							\ 									\     __r0 = __r1 % __d1;							\     __q0 = __r1 / __d1;							\     __m = (USItype) __q0 * __d0;					\     __r0 = __r0 * __ll_B | __ll_lowpart (n0);				\     if (__r0< __m)							\       {									\ 	__q0--, __r0 += (d);						\ 	if (__r0>= (d))						\ 	  if (__r0< __m)						\ 	    __q0--, __r0 += (d);					\       }									\     __r0 -= __m;							\ 									\     (q) = (USItype) __q1 * __ll_B | __q0;				\     (r) = __r0;								\   } while (0)
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
value|do {									\     USItype __xr = (x);							\     USItype __a;							\ 									\     if (SI_TYPE_SIZE<= 32)						\       {									\ 	__a = __xr< ((USItype)1<<2*__BITS4)				\ 	  ? (__xr< ((USItype)1<<__BITS4) ? 0 : __BITS4)		\ 	  : (__xr< ((USItype)1<<3*__BITS4) ?  2*__BITS4 : 3*__BITS4);	\       }									\     else								\       {									\ 	for (__a = SI_TYPE_SIZE - 8; __a> 0; __a -= 8)			\ 	  if (((__xr>> __a)& 0xff) != 0)				\ 	    break;							\       }									\ 									\     (count) = SI_TYPE_SIZE - (__clz_tab[__xr>> __a] + __a);		\   } while (0)
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

