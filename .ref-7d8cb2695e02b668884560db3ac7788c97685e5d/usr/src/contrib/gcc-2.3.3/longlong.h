begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* longlong.h -- definitions for mixed size 32/64 bit arithmetic.    Copyright (C) 1991, 1992 Free Software Foundation, Inc.     This definition file is free software; you can redistribute it    and/or modify it under the terms of the GNU General Public    License as published by the Free Software Foundation; either    version 2, or (at your option) any later version.     This definition file is distributed in the hope that it will be    useful, but WITHOUT ANY WARRANTY; without even the implied    warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.    See the GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
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
comment|/* The CPUs come in alphabetical order below.     Please add support for more CPUs here, or improve the current support    for the CPUs below!    (E.g. WE32100, i960, IBM360.)  */
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
name|___AM29K__
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
value|__asm__ ("add %1,%4,%5 	addc %0,%2,%3"							\ 	   : "=r" ((USItype)(sh)),					\ 	    "=&r" ((USItype)(sl))					\ 	   : "%r" ((USItype)(ah)),					\ 	     "rI" ((USItype)(bh)),					\ 	     "%r" ((USItype)(al)),					\ 	     "rI" ((USItype)(bl)))
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
value|__asm__ ("sub %1,%4,%5 	subc %0,%2,%3"							\ 	   : "=r" ((USItype)(sh)),					\ 	     "=&r" ((USItype)(sl))					\ 	   : "r" ((USItype)(ah)),					\ 	     "rI" ((USItype)(bh)),					\ 	     "r" ((USItype)(al)),					\ 	     "rI" ((USItype)(bl)))
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
value|do {									\     USItype __m0 = (m0), __m1 = (m1);					\     __asm__ ("multiplu %0,%1,%2"					\ 	     : "=r" ((USItype)(xl))					\ 	     : "r" (__m0),						\ 	       "r" (__m1));						\     __asm__ ("multmu %0,%1,%2"						\ 	     : "=r" ((USItype)(xh))					\ 	     : "r" (__m0),						\ 	       "r" (__m1));						\   } while (0)
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
value|__asm__ ("dividu %0,%3,%4"						\ 	   : "=r" ((USItype)(q)),					\ 	     "=q" ((USItype)(r))					\ 	   : "1" ((USItype)(n1)),					\ 	     "r" ((USItype)(n0)),					\ 	     "r" ((USItype)(d)))
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
value|__asm__ ("clz %0,%1"						\ 	     : "=r" ((USItype)(count))					\ 	     : "r" ((USItype)(x)))
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
value|__asm__ ("adds %1,%4,%5 	adc %0,%2,%3"							\ 	   : "=r" ((USItype)(sh)),					\ 	     "=&r" ((USItype)(sl))					\ 	   : "%r" ((USItype)(ah)),					\ 	     "rI" ((USItype)(bh)),					\ 	     "%r" ((USItype)(al)),					\ 	     "rI" ((USItype)(bl)))
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
value|__asm__ ("subs %1,%4,%5 	sbc %0,%2,%3"							\ 	   : "=r" ((USItype)(sh)),					\ 	     "=&r" ((USItype)(sl))					\ 	   : "r" ((USItype)(ah)),					\ 	     "rI" ((USItype)(bh)),					\ 	     "r" ((USItype)(al)),					\ 	     "rI" ((USItype)(bl)))
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
value|__asm__ ("add.w %5,%1 	addx %3,%0"							\ 	   : "=g" ((USItype)(sh)),					\ 	     "=&g" ((USItype)(sl))					\ 	   : "%0" ((USItype)(ah)),					\ 	     "g" ((USItype)(bh)),					\ 	     "%1" ((USItype)(al)),					\ 	     "g" ((USItype)(bl)))
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
value|__asm__ ("sub.w %5,%1 	subx %3,%0"							\ 	   : "=g" ((USItype)(sh)),					\ 	     "=&g" ((USItype)(sl))					\ 	   : "0" ((USItype)(ah)),					\ 	     "g" ((USItype)(bh)),					\ 	     "1" ((USItype)(al)),					\ 	     "g" ((USItype)(bl)))
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
value|__asm__ ("mulx %3,%0,%1"						\ 	   : "=g" ((USItype)(ph)),					\ 	     "=r" ((USItype)(pl))					\ 	   : "%0" ((USItype)(m0)),					\ 	     "g" ((USItype)(m1)))
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
value|__asm__ ("divx %4,%0,%1"						\ 	   : "=g" ((USItype)(q)),					\ 	     "=r" ((USItype)(r))					\ 	   : "1" ((USItype)(nh)),					\ 	     "0" ((USItype)(nl)),					\ 	     "g" ((USItype)(d)))
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
value|__asm__ ("bsch/1 %1,%0"						\ 	   : "=g" (count)						\ 	   : "g" ((USItype)(x)),					\ 	     "0" ((USItype)0))
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
value|__asm__ ("add %4,%5,%1 	addc %2,%3,%0"							\ 	   : "=r" ((USItype)(sh)),					\ 	     "=&r" ((USItype)(sl))					\ 	   : "%rM" ((USItype)(ah)),					\ 	     "rM" ((USItype)(bh)),					\ 	     "%rM" ((USItype)(al)),					\ 	     "rM" ((USItype)(bl)))
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
value|__asm__ ("sub %4,%5,%1 	subb %2,%3,%0"							\ 	   : "=r" ((USItype)(sh)),					\ 	     "=&r" ((USItype)(sl))					\ 	   : "rM" ((USItype)(ah)),					\ 	     "rM" ((USItype)(bh)),					\ 	     "rM" ((USItype)(al)),					\ 	     "rM" ((USItype)(bl)))
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
value|do {									\     union								\       {									\ 	UDItype __f;							\ 	struct {USItype __w1, __w0;} __w1w0;				\       } __t;								\     __asm__ ("xmpyu %1,%2,%0"						\ 	     : "=x" (__t.__f)						\ 	     : "x" ((USItype)(u)),					\ 	       "x" ((USItype)(v)));					\     (w1) = __t.__w1w0.__w1;						\     (w0) = __t.__w1w0.__w0;						\      } while (0)
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
value|__asm__ ("addl %5,%1 	adcl %3,%0"							\ 	   : "=r" ((USItype)(sh)),					\ 	     "=&r" ((USItype)(sl))					\ 	   : "%0" ((USItype)(ah)),					\ 	     "g" ((USItype)(bh)),					\ 	     "%1" ((USItype)(al)),					\ 	     "g" ((USItype)(bl)))
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
value|__asm__ ("subl %5,%1 	sbbl %3,%0"							\ 	   : "=r" ((USItype)(sh)),					\ 	     "=&r" ((USItype)(sl))					\ 	   : "0" ((USItype)(ah)),					\ 	     "g" ((USItype)(bh)),					\ 	     "1" ((USItype)(al)),					\ 	     "g" ((USItype)(bl)))
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
value|__asm__ ("mull %3"							\ 	   : "=a" ((USItype)(w0)),					\ 	     "=d" ((USItype)(w1))					\ 	   : "%0" ((USItype)(u)),					\ 	     "rm" ((USItype)(v)))
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
value|__asm__ ("divl %4"							\ 	   : "=a" ((USItype)(q)),					\ 	     "=d" ((USItype)(r))					\ 	   : "0" ((USItype)(n0)),					\ 	     "1" ((USItype)(n1)),					\ 	     "rm" ((USItype)(d)))
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
value|do {									\     USItype __cbtmp;							\     __asm__ ("bsrl %1,%0"						\ 	     : "=r" (__cbtmp) : "rm" ((USItype)(x)));			\     (count) = __cbtmp ^ 31;						\   } while (0)
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
name|___IBMR2__
argument_list|)
end_if

begin_comment
comment|/* IBM RS6000 */
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
value|__asm__ ("a%I5 %1,%4,%5 	ae %0,%2,%3"							\ 	   : "=r" ((USItype)(sh)),					\ 	     "=&r" ((USItype)(sl))					\ 	   : "%r" ((USItype)(ah)),					\ 	     "r" ((USItype)(bh)),					\ 	     "%r" ((USItype)(al)),					\ 	     "rI" ((USItype)(bl)))
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
value|__asm__ ("sf%I4 %1,%5,%4 	sfe %0,%3,%2"							\ 	   : "=r" ((USItype)(sh)),					\ 	     "=&r" ((USItype)(sl))					\ 	   : "r" ((USItype)(ah)),					\ 	     "r" ((USItype)(bh)),					\ 	     "rI" ((USItype)(al)),					\ 	     "r" ((USItype)(bl)))
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
value|do {									\     USItype __m0 = (m0), __m1 = (m1);					\     __asm__ ("mul %0,%2,%3"						\ 	     : "=r" ((USItype)(xh)),					\ 	       "=q" ((USItype)(xl))					\ 	     : "r" (__m0),						\ 	       "r" (__m1));						\     (xh) += ((((SItype) __m0>> 31)& __m1)				\ 	     + (((SItype) __m1>> 31)& __m0));				\   } while (0)
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
value|__asm__ ("mul %0,%2,%3"						\ 	   : "=r" ((USItype)(xh)),					\ 	     "=q" ((USItype)(xl))					\ 	   : "r" ((USItype)(m0)),					\ 	     "r" ((USItype)(m1)))
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
value|__asm__ ("div %0,%2,%4"						\ 	   : "=r" ((USItype)(q)), "=q" ((USItype)(r))			\ 	   : "r" ((USItype)(nh)), "1" ((USItype)(nl)), "r" ((USItype)(d)))
end_define

begin_define
define|#
directive|define
name|UDIV_TIME
value|40
end_define

begin_define
define|#
directive|define
name|UDIV_NEEDS_NORMALIZATION
value|1
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
value|__asm__ ("cntlz %0,%1"						\ 	   : "=r" ((USItype)(count))					\ 	   : "r" ((USItype)(x)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ___IBMR2__ */
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
value|__asm__ ("add%.l %5,%1 	addx%.l %3,%0"							\ 	   : "=d" ((USItype)(sh)),					\ 	     "=&d" ((USItype)(sl))					\ 	   : "%0" ((USItype)(ah)),					\ 	     "d" ((USItype)(bh)),					\ 	     "%1" ((USItype)(al)),					\ 	     "g" ((USItype)(bl)))
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
value|__asm__ ("sub%.l %5,%1 	subx%.l %3,%0"							\ 	   : "=d" ((USItype)(sh)),					\ 	     "=&d" ((USItype)(sl))					\ 	   : "0" ((USItype)(ah)),					\ 	     "d" ((USItype)(bh)),					\ 	     "1" ((USItype)(al)),					\ 	     "g" ((USItype)(bl)))
end_define

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
name|__NeXT__
argument_list|)
operator|||
name|defined
argument_list|(
name|mc68020
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
value|__asm__ ("mulu%.l %3,%1:%0"						\ 	   : "=d" ((USItype)(w0)),					\ 	     "=d" ((USItype)(w1))					\ 	   : "%0" ((USItype)(u)),					\ 	     "dmi" ((USItype)(v)))
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
value|__asm__ ("divu%.l %4,%1:%0"						\ 	   : "=d" ((USItype)(q)),					\ 	     "=d" ((USItype)(r))					\ 	   : "0" ((USItype)(n0)),					\ 	     "1" ((USItype)(n1)),					\ 	     "dmi" ((USItype)(d)))
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
value|__asm__ ("divs%.l %4,%1:%0"						\ 	   : "=d" ((USItype)(q)),					\ 	     "=d" ((USItype)(r))					\ 	   : "0" ((USItype)(n0)),					\ 	     "1" ((USItype)(n1)),					\ 	     "dmi" ((USItype)(d)))
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
value|__asm__ ("bfffo %1{%b2:%b2},%0"					\ 	   : "=d" ((USItype)(count))					\ 	   : "od" ((USItype)(x)), "n" (0))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not mc68020 */
end_comment

begin_comment
comment|/* %/ inserts REGISTER_PREFIX.  */
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
value|__asm__ ("| Inlined umul_ppmm 	movel	%2,%/d0 	movel	%3,%/d1 	movel	%/d0,%/d2 	swap	%/d0 	movel	%/d1,%/d3 	swap	%/d1 	movew	%/d2,%/d4 	mulu	%/d3,%/d4 	mulu	%/d1,%/d2 	mulu	%/d0,%/d3 	mulu	%/d0,%/d1 	movel	%/d4,%/d0 	eorw	%/d0,%/d0 	swap	%/d0 	addl	%/d0,%/d2 	addl	%/d3,%/d2 	jcc	1f 	addl	#65536,%/d1 1:	swap	%/d2 	moveq	#0,%/d0 	movew	%/d2,%/d0 	movew	%/d4,%/d2 	movel	%/d2,%1 	addl	%/d1,%/d0 	movel	%/d0,%0"						\ 	   : "=g" ((USItype)(xh)),					\ 	     "=g" ((USItype)(xl))					\ 	   : "g" ((USItype)(a)),					\ 	     "g" ((USItype)(b))						\ 	   : "d0", "d1", "d2", "d3", "d4")
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
comment|/* not mc68020 */
end_comment

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
value|__asm__ ("addu.co %1,%r4,%r5 	addu.ci %0,%r2,%r3"						\ 	   : "=r" ((USItype)(sh)),					\ 	     "=&r" ((USItype)(sl))					\ 	   : "%rJ" ((USItype)(ah)),					\ 	     "rJ" ((USItype)(bh)),					\ 	     "%rJ" ((USItype)(al)),					\ 	     "rJ" ((USItype)(bl)))
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
value|__asm__ ("subu.co %1,%r4,%r5 	subu.ci %0,%r2,%r3"						\ 	   : "=r" ((USItype)(sh)),					\ 	     "=&r" ((USItype)(sl))					\ 	   : "rJ" ((USItype)(ah)),					\ 	     "rJ" ((USItype)(bh)),					\ 	     "rJ" ((USItype)(al)),					\ 	     "rJ" ((USItype)(bl)))
end_define

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
value|do {									\     USItype __cbtmp;							\     __asm__ ("ff1 %0,%1"						\ 	     : "=r" (__cbtmp)						\ 	     : "r" ((USItype)(x)));					\     (count) = __cbtmp ^ 31;						\   } while (0)
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
name|w1
parameter_list|,
name|w0
parameter_list|,
name|u
parameter_list|,
name|v
parameter_list|)
define|\
value|__asm__ ("mulu.d	r10,%2,%3 	or	%0,r10,0 	or	%1,r11,0"						\ 	   : "=r" (w1),							\ 	     "=r" (w0)							\ 	   : "r" ((USItype)(u)),					\ 	     "r" ((USItype)(v))						\ 	   : "r10", "r11")
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
value|__asm__ ("or	r10,%2,0 	or	r11,%3,0 	divu.d	r10,r10,%4 	mulu	%1,%4,r11 	subu	%1,%3,%1 	or	%0,r11,0"						\ 	   : "=r" (q),							\ 	     "=&r" (r)							\ 	   : "r" ((USItype)(n1)),					\ 	     "r" ((USItype)(n0)),					\ 	     "r" ((USItype)(d))						\ 	   : "r10", "r11")
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
value|__asm__ ("multu %2,%3 	mflo %0 	mfhi %1"							\ 	   : "=d" ((USItype)(w0)),					\ 	     "=d" ((USItype)(w1))					\ 	   : "d" ((USItype)(u)),					\ 	     "d" ((USItype)(v)))
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
name|__umulsidi3
parameter_list|(
name|u
parameter_list|,
name|v
parameter_list|)
define|\
value|({UDItype __w;							\     __asm__ ("meid %2,%0"						\ 	     : "=g" (__w)						\ 	     : "%0" ((USItype)(u)),					\ 	       "g" ((USItype)(v)));					\     __w; })
end_define

begin_define
define|#
directive|define
name|div_qrnnd
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
value|__asm__ ("movd %2,r0 	movd %3,r1 	deid %4,r0 	movd r1,%0 	movd r0,%1"							\ 	   : "=g" ((USItype)(q)),					\ 	     "=g" ((USItype)(r))					\ 	   : "g" ((USItype)(n0)),					\ 	     "g" ((USItype)(n1)),					\ 	     "g" ((USItype)(d))						\ 	   : "r0", "r1")
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
value|__asm__ ("addw	%5,%1 	addwc	%3,%0"							\ 	   : "=r" ((USItype)(sh)),					\ 	     "=&r" ((USItype)(sl))					\ 	   : "%0" ((USItype)(ah)),					\ 	     "g" ((USItype)(bh)),					\ 	     "%1" ((USItype)(al)),					\ 	     "g" ((USItype)(bl)))
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
value|__asm__ ("subw	%5,%1 	subwb	%3,%0"							\ 	   : "=r" ((USItype)(sh)),					\ 	     "=&r" ((USItype)(sl))					\ 	   : "0" ((USItype)(ah)),					\ 	     "g" ((USItype)(bh)),					\ 	     "1" ((USItype)(al)),					\ 	     "g" ((USItype)(bl)))
end_define

begin_comment
comment|/* This insn doesn't work on ancient pyramids.  */
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
value|({union {								\ 	UDItype __ll;							\ 	struct {USItype __h, __l;} __i;					\      } __xx;								\   __xx.__i.__l = u;							\   __asm__ ("uemul %3,%0"						\ 	   : "=r" (__xx.__i.__h),					\ 	     "=r" (__xx.__i.__l)					\ 	   : "1" (__xx.__i.__l),					\ 	     "g" ((UDItype)(v)));					\   (w1) = __xx.__i.__h;							\   (w0) = __xx.__i.__l;})
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
value|__asm__ ("a %1,%5 	ae %0,%3"							\ 	   : "=r" ((USItype)(sh)),					\ 	     "=&r" ((USItype)(sl))					\ 	   : "%0" ((USItype)(ah)),					\ 	     "r" ((USItype)(bh)),					\ 	     "%1" ((USItype)(al)),					\ 	     "r" ((USItype)(bl)))
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
value|__asm__ ("s %1,%5 	se %0,%3"							\ 	   : "=r" ((USItype)(sh)),					\ 	     "=&r" ((USItype)(sl))					\ 	   : "0" ((USItype)(ah)),					\ 	     "r" ((USItype)(bh)),					\ 	     "1" ((USItype)(al)),					\ 	     "r" ((USItype)(bl)))
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
value|do {									\     USItype __m0 = (m0), __m1 = (m1);					\     __asm__ (								\        "s	r2,r2 	mts	r10,%2 	m	r2,%3 	m	r2,%3 	m	r2,%3 	m	r2,%3 	m	r2,%3 	m	r2,%3 	m	r2,%3 	m	r2,%3 	m	r2,%3 	m	r2,%3 	m	r2,%3 	m	r2,%3 	m	r2,%3 	m	r2,%3 	m	r2,%3 	m	r2,%3 	cas	%0,r2,r0 	mfs	r10,%1"							\ 	     : "=r" ((USItype)(ph)),					\ 	       "=r" ((USItype)(pl))					\ 	     : "%r" (__m0),						\ 		"r" (__m1)						\ 	     : "r2");							\     (ph) += ((((SItype) __m0>> 31)& __m1)				\ 	     + (((SItype) __m1>> 31)& __m0));				\   } while (0)
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
value|do {									\     if ((x)>= 0x10000)							\       __asm__ ("clz	%0,%1"						\ 	       : "=r" ((USItype)(count))				\ 	       : "r" ((USItype)(x)>> 16));				\     else								\       {									\ 	__asm__ ("clz	%0,%1"						\ 		 : "=r" ((USItype)(count))				\ 		 : "r" ((USItype)(x)));					\ 	(count) += 16;							\       }									\   } while (0)
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
value|__asm__ ("addcc %4,%5,%1 	addx %2,%3,%0"							\ 	   : "=r" ((USItype)(sh)),					\ 	     "=&r" ((USItype)(sl))					\ 	   : "%r" ((USItype)(ah)),					\ 	     "rI" ((USItype)(bh)),					\ 	     "%r" ((USItype)(al)),					\ 	     "rI" ((USItype)(bl))					\ 	   __CLOBBER_CC)
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
value|__asm__ ("subcc %4,%5,%1 	subx %2,%3,%0"							\ 	   : "=r" ((USItype)(sh)),					\ 	     "=&r" ((USItype)(sl))					\ 	   : "r" ((USItype)(ah)),					\ 	     "rI" ((USItype)(bh)),					\ 	     "r" ((USItype)(al)),					\ 	     "rI" ((USItype)(bl))					\ 	   __CLOBBER_CC)
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
value|__asm__ ("umul %2,%3,%1;rd %%y,%0"					\ 	   : "=r" ((USItype)(w1)),					\ 	     "=r" ((USItype)(w0))					\ 	   : "r" ((USItype)(u)),					\ 	     "r" ((USItype)(v)))
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
value|__asm__ ("mov %2,%%y;nop;nop;nop;udiv %3,%4,%0;umul %0,%4,%1;sub %3,%1,%1"\ 	   : "=&r" ((USItype)(q)),					\ 	     "=&r" ((USItype)(r))					\ 	   : "r" ((USItype)(n1)),					\ 	     "r" ((USItype)(n0)),					\ 	     "r" ((USItype)(d)))
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
value|__asm__ ("umul %2,%3,%1;rd %%y,%0"					\ 	   : "=r" ((USItype)(w1)),					\ 	     "=r" ((USItype)(w0))					\ 	   : "r" ((USItype)(u)),					\ 	     "r" ((USItype)(v)))
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
value|__asm__ ("! Inlined udiv_qrnnd 	wr	%%g0,%2,%%y	! Not a delayed write for sparclite 	tst	%%g0 	divscc	%3,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%%g1 	divscc	%%g1,%4,%0 	rd	%%y,%1 	bl,a 1f 	add	%1,%4,%1 1:	! End of inline udiv_qrnnd"					\ 	   : "=r" ((USItype)(q)),					\ 	     "=r" ((USItype)(r))					\ 	   : "r" ((USItype)(n1)),					\ 	     "r" ((USItype)(n0)),					\ 	     "rI" ((USItype)(d))					\ 	   : "%g1" __AND_CLOBBER_CC)
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
value|__asm__ ("scan %1,0,%0"						\ 	   : "=r" ((USItype)(x))					\ 	   : "r" ((USItype)(count)))
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
value|__asm__ ("! Inlined umul_ppmm 	wr	%%g0,%2,%%y	! SPARC has 0-3 delay insn after a wr 	sra	%3,31,%%g2	! Don't move this insn 	and	%2,%%g2,%%g2	! Don't move this insn 	andcc	%%g0,0,%%g1	! Don't move this insn 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,%3,%%g1 	mulscc	%%g1,0,%%g1 	add	%%g1,%%g2,%0 	rd	%%y,%1"							\ 	   : "=r" ((USItype)(w1)),					\ 	     "=r" ((USItype)(w0))					\ 	   : "%rI" ((USItype)(u)),					\ 	     "r" ((USItype)(v))						\ 	   : "%g1", "%g2" __AND_CLOBBER_CC)
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
value|__asm__ ("! Inlined udiv_qrnnd 	mov	32,%%g1 	subcc	%1,%2,%%g0 1:	bcs	5f 	 addxcc %0,%0,%0	! shift n1n0 and a q-bit in lsb 	sub	%1,%2,%1	! this kills msb of n 	addx	%1,%1,%1	! so this can't give carry 	subcc	%%g1,1,%%g1 2:	bne	1b 	 subcc	%1,%2,%%g0 	bcs	3f 	 addxcc %0,%0,%0	! shift n1n0 and a q-bit in lsb 	b	3f 	 sub	%1,%2,%1	! this kills msb of n 4:	sub	%1,%2,%1 5:	addxcc	%1,%1,%1 	bcc	2b 	 subcc	%%g1,1,%%g1 ! Got carry from n.  Subtract next step to cancel this carry. 	bne	4b 	 addcc	%0,%0,%0	! shift n1n0 and a 0-bit in lsb 	sub	%1,%2,%1 3:	xnor	%0,0,%0 	! End of inline udiv_qrnnd"					\ 	   : "=&r" ((USItype)(q)),					\ 	     "=&r" ((USItype)(r))					\ 	   : "r" ((USItype)(d)),					\ 	     "1" ((USItype)(n1)),					\ 	     "0" ((USItype)(n0)) : "%g1" __AND_CLOBBER_CC)
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
value|__asm__ ("addl2 %5,%1 	adwc %3,%0"							\ 	   : "=g" ((USItype)(sh)),					\ 	     "=&g" ((USItype)(sl))					\ 	   : "%0" ((USItype)(ah)),					\ 	     "g" ((USItype)(bh)),					\ 	     "%1" ((USItype)(al)),					\ 	     "g" ((USItype)(bl)))
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
value|__asm__ ("subl2 %5,%1 	sbwc %3,%0"							\ 	   : "=g" ((USItype)(sh)),					\ 	     "=&g" ((USItype)(sl))					\ 	   : "0" ((USItype)(ah)),					\ 	     "g" ((USItype)(bh)),					\ 	     "1" ((USItype)(al)),					\ 	     "g" ((USItype)(bl)))
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
value|do {									\     USItype __xr = (x);							\     USItype __a;							\ 									\     if (SI_TYPE_SIZE<= 32)						\       {									\ 	__a = __xr< (1<<2*__BITS4)					\ 	  ? (__xr< (1<<__BITS4) ? 0 : __BITS4)				\ 	  : (__xr< (1<<3*__BITS4) ?  2*__BITS4 : 3*__BITS4);		\       }									\     else								\       {									\ 	for (__a = SI_TYPE_SIZE - 8; __a> 0; __a -= 8)		\ 	  if (((__xr>> __a)& 0xff) != 0)				\ 	    break;							\       }									\ 									\     (count) = SI_TYPE_SIZE - (__clz_tab[__xr>> __a] + __a);		\   } while (0)
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

