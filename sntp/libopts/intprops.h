begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* intprops.h -- properties of integer types     Copyright (C) 2001-2005, 2009-2014 Free Software Foundation, Inc.     This program is free software: you can redistribute it and/or modify    it under the terms of the GNU Lesser General Public License as published by    the Free Software Foundation; either version 2.1 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU Lesser General Public License for more details.     You should have received a copy of the GNU Lesser General Public License    along with this program.  If not, see<http://www.gnu.org/licenses/>.  */
end_comment

begin_comment
comment|/* Written by Paul Eggert.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GL_INTPROPS_H
end_ifndef

begin_define
define|#
directive|define
name|_GL_INTPROPS_H
end_define

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_comment
comment|/* Return an integer value, converted to the same type as the integer    expression E after integer type promotion.  V is the unconverted value.  */
end_comment

begin_define
define|#
directive|define
name|_GL_INT_CONVERT
parameter_list|(
name|e
parameter_list|,
name|v
parameter_list|)
value|(0 * (e) + (v))
end_define

begin_comment
comment|/* Act like _GL_INT_CONVERT (E, -V) but work around a bug in IRIX 6.5 cc; see<http://lists.gnu.org/archive/html/bug-gnulib/2011-05/msg00406.html>.  */
end_comment

begin_define
define|#
directive|define
name|_GL_INT_NEGATE_CONVERT
parameter_list|(
name|e
parameter_list|,
name|v
parameter_list|)
value|(0 * (e) - (v))
end_define

begin_comment
comment|/* The extra casts in the following macros work around compiler bugs,    e.g., in Cray C 5.0.3.0.  */
end_comment

begin_comment
comment|/* True if the arithmetic type T is an integer type.  bool counts as    an integer.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_IS_INTEGER
parameter_list|(
name|t
parameter_list|)
value|((t) 1.5 == 1)
end_define

begin_comment
comment|/* True if negative values of the signed integer type T use two's    complement, ones' complement, or signed magnitude representation,    respectively.  Much GNU code assumes two's complement, but some    people like to be portable to all possible C hosts.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_TWOS_COMPLEMENT
parameter_list|(
name|t
parameter_list|)
value|((t) ~ (t) 0 == (t) -1)
end_define

begin_define
define|#
directive|define
name|TYPE_ONES_COMPLEMENT
parameter_list|(
name|t
parameter_list|)
value|((t) ~ (t) 0 == 0)
end_define

begin_define
define|#
directive|define
name|TYPE_SIGNED_MAGNITUDE
parameter_list|(
name|t
parameter_list|)
value|((t) ~ (t) 0< (t) -1)
end_define

begin_comment
comment|/* True if the signed integer expression E uses two's complement.  */
end_comment

begin_define
define|#
directive|define
name|_GL_INT_TWOS_COMPLEMENT
parameter_list|(
name|e
parameter_list|)
value|(~ _GL_INT_CONVERT (e, 0) == -1)
end_define

begin_comment
comment|/* True if the arithmetic type T is signed.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_SIGNED
parameter_list|(
name|t
parameter_list|)
value|(! ((t) 0< (t) -1))
end_define

begin_comment
comment|/* Return 1 if the integer expression E, after integer promotion, has    a signed type.  */
end_comment

begin_define
define|#
directive|define
name|_GL_INT_SIGNED
parameter_list|(
name|e
parameter_list|)
value|(_GL_INT_NEGATE_CONVERT (e, 1)< 0)
end_define

begin_comment
comment|/* Minimum and maximum values for integer types and expressions.  These    macros have undefined behavior if T is signed and has padding bits.    If this is a problem for you, please let us know how to fix it for    your host.  */
end_comment

begin_comment
comment|/* The maximum and minimum values for the integer type T.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_MINIMUM
parameter_list|(
name|t
parameter_list|)
define|\
value|((t) (! TYPE_SIGNED (t)                                               \         ? (t) 0                                                         \         : TYPE_SIGNED_MAGNITUDE (t)                                     \         ? ~ (t) 0                                                       \         : ~ TYPE_MAXIMUM (t)))
end_define

begin_define
define|#
directive|define
name|TYPE_MAXIMUM
parameter_list|(
name|t
parameter_list|)
define|\
value|((t) (! TYPE_SIGNED (t)                                               \         ? (t) -1                                                        \         : ((((t) 1<< (sizeof (t) * CHAR_BIT - 2)) - 1) * 2 + 1)))
end_define

begin_comment
comment|/* The maximum and minimum values for the type of the expression E,    after integer promotion.  E should not have side effects.  */
end_comment

begin_define
define|#
directive|define
name|_GL_INT_MINIMUM
parameter_list|(
name|e
parameter_list|)
define|\
value|(_GL_INT_SIGNED (e)                                                   \    ? - _GL_INT_TWOS_COMPLEMENT (e) - _GL_SIGNED_INT_MAXIMUM (e)         \    : _GL_INT_CONVERT (e, 0))
end_define

begin_define
define|#
directive|define
name|_GL_INT_MAXIMUM
parameter_list|(
name|e
parameter_list|)
define|\
value|(_GL_INT_SIGNED (e)                                                   \    ? _GL_SIGNED_INT_MAXIMUM (e)                                         \    : _GL_INT_NEGATE_CONVERT (e, 1))
end_define

begin_define
define|#
directive|define
name|_GL_SIGNED_INT_MAXIMUM
parameter_list|(
name|e
parameter_list|)
define|\
value|(((_GL_INT_CONVERT (e, 1)<< (sizeof ((e) + 0) * CHAR_BIT - 2)) - 1) * 2 + 1)
end_define

begin_comment
comment|/* Return 1 if the __typeof__ keyword works.  This could be done by    'configure', but for now it's easier to do it by hand.  */
end_comment

begin_if
if|#
directive|if
operator|(
literal|2
operator|<=
name|__GNUC__
operator|||
name|defined
name|__IBM__TYPEOF__
expr|\
operator|||
operator|(
literal|0x5110
operator|<=
name|__SUNPRO_C
operator|&&
operator|!
name|__STDC__
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|_GL_HAVE___TYPEOF__
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_GL_HAVE___TYPEOF__
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Return 1 if the integer type or expression T might be signed.  Return 0    if it is definitely unsigned.  This macro does not evaluate its argument,    and expands to an integer constant expression.  */
end_comment

begin_if
if|#
directive|if
name|_GL_HAVE___TYPEOF__
end_if

begin_define
define|#
directive|define
name|_GL_SIGNED_TYPE_OR_EXPR
parameter_list|(
name|t
parameter_list|)
value|TYPE_SIGNED (__typeof__ (t))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_GL_SIGNED_TYPE_OR_EXPR
parameter_list|(
name|t
parameter_list|)
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Bound on length of the string representing an unsigned integer    value representable in B bits.  log10 (2.0)< 146/485.  The    smallest value of B where this bound is not tight is 2621.  */
end_comment

begin_define
define|#
directive|define
name|INT_BITS_STRLEN_BOUND
parameter_list|(
name|b
parameter_list|)
value|(((b) * 146 + 484) / 485)
end_define

begin_comment
comment|/* Bound on length of the string representing an integer type or expression T.    Subtract 1 for the sign bit if T is signed, and then add 1 more for    a minus sign if needed.     Because _GL_SIGNED_TYPE_OR_EXPR sometimes returns 0 when its argument is    signed, this macro may overestimate the true bound by one byte when    applied to unsigned types of size 2, 4, 16, ... bytes.  */
end_comment

begin_define
define|#
directive|define
name|INT_STRLEN_BOUND
parameter_list|(
name|t
parameter_list|)
define|\
value|(INT_BITS_STRLEN_BOUND (sizeof (t) * CHAR_BIT                 \                           - _GL_SIGNED_TYPE_OR_EXPR (t))        \    + _GL_SIGNED_TYPE_OR_EXPR (t))
end_define

begin_comment
comment|/* Bound on buffer size needed to represent an integer type or expression T,    including the terminating null.  */
end_comment

begin_define
define|#
directive|define
name|INT_BUFSIZE_BOUND
parameter_list|(
name|t
parameter_list|)
value|(INT_STRLEN_BOUND (t) + 1)
end_define

begin_comment
comment|/* Range overflow checks.     The INT_<op>_RANGE_OVERFLOW macros return 1 if the corresponding C    operators might not yield numerically correct answers due to    arithmetic overflow.  They do not rely on undefined or    implementation-defined behavior.  Their implementations are simple    and straightforward, but they are a bit harder to use than the    INT_<op>_OVERFLOW macros described below.     Example usage:       long int i = ...;      long int j = ...;      if (INT_MULTIPLY_RANGE_OVERFLOW (i, j, LONG_MIN, LONG_MAX))        printf ("multiply would overflow");      else        printf ("product is %ld", i * j);     Restrictions on *_RANGE_OVERFLOW macros:     These macros do not check for all possible numerical problems or    undefined or unspecified behavior: they do not check for division    by zero, for bad shift counts, or for shifting negative numbers.     These macros may evaluate their arguments zero or multiple times,    so the arguments should not have side effects.  The arithmetic    arguments (including the MIN and MAX arguments) must be of the same    integer type after the usual arithmetic conversions, and the type    must have minimum value MIN and maximum MAX.  Unsigned types should    use a zero MIN of the proper type.     These macros are tuned for constant MIN and MAX.  For commutative    operations such as A + B, they are also tuned for constant B.  */
end_comment

begin_comment
comment|/* Return 1 if A + B would overflow in [MIN,MAX] arithmetic.    See above for restrictions.  */
end_comment

begin_define
define|#
directive|define
name|INT_ADD_RANGE_OVERFLOW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|min
parameter_list|,
name|max
parameter_list|)
define|\
value|((b)< 0                                              \    ? (a)< (min) - (b)                                  \    : (max) - (b)< (a))
end_define

begin_comment
comment|/* Return 1 if A - B would overflow in [MIN,MAX] arithmetic.    See above for restrictions.  */
end_comment

begin_define
define|#
directive|define
name|INT_SUBTRACT_RANGE_OVERFLOW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|min
parameter_list|,
name|max
parameter_list|)
define|\
value|((b)< 0                                              \    ? (max) + (b)< (a)                                  \    : (a)< (min) + (b))
end_define

begin_comment
comment|/* Return 1 if - A would overflow in [MIN,MAX] arithmetic.    See above for restrictions.  */
end_comment

begin_define
define|#
directive|define
name|INT_NEGATE_RANGE_OVERFLOW
parameter_list|(
name|a
parameter_list|,
name|min
parameter_list|,
name|max
parameter_list|)
define|\
value|((min)< 0                                            \    ? (a)< - (max)                                      \    : 0< (a))
end_define

begin_comment
comment|/* Return 1 if A * B would overflow in [MIN,MAX] arithmetic.    See above for restrictions.  Avoid&& and || as they tickle    bugs in Sun C 5.11 2010/08/13 and other compilers; see<http://lists.gnu.org/archive/html/bug-gnulib/2011-05/msg00401.html>.  */
end_comment

begin_define
define|#
directive|define
name|INT_MULTIPLY_RANGE_OVERFLOW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|min
parameter_list|,
name|max
parameter_list|)
define|\
value|((b)< 0                                              \    ? ((a)< 0                                           \       ? (a)< (max) / (b)                               \       : (b) == -1                                       \       ? 0                                               \       : (min) / (b)< (a))                              \    : (b) == 0                                           \    ? 0                                                  \    : ((a)< 0                                           \       ? (a)< (min) / (b)                               \       : (max) / (b)< (a)))
end_define

begin_comment
comment|/* Return 1 if A / B would overflow in [MIN,MAX] arithmetic.    See above for restrictions.  Do not check for division by zero.  */
end_comment

begin_define
define|#
directive|define
name|INT_DIVIDE_RANGE_OVERFLOW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|min
parameter_list|,
name|max
parameter_list|)
define|\
value|((min)< 0&& (b) == -1&& (a)< - (max))
end_define

begin_comment
comment|/* Return 1 if A % B would overflow in [MIN,MAX] arithmetic.    See above for restrictions.  Do not check for division by zero.    Mathematically, % should never overflow, but on x86-like hosts    INT_MIN % -1 traps, and the C standard permits this, so treat this    as an overflow too.  */
end_comment

begin_define
define|#
directive|define
name|INT_REMAINDER_RANGE_OVERFLOW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|min
parameter_list|,
name|max
parameter_list|)
define|\
value|INT_DIVIDE_RANGE_OVERFLOW (a, b, min, max)
end_define

begin_comment
comment|/* Return 1 if A<< B would overflow in [MIN,MAX] arithmetic.    See above for restrictions.  Here, MIN and MAX are for A only, and B need    not be of the same type as the other arguments.  The C standard says that    behavior is undefined for shifts unless 0<= B< wordwidth, and that when    A is negative then A<< B has undefined behavior and A>> B has    implementation-defined behavior, but do not check these other    restrictions.  */
end_comment

begin_define
define|#
directive|define
name|INT_LEFT_SHIFT_RANGE_OVERFLOW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|min
parameter_list|,
name|max
parameter_list|)
define|\
value|((a)< 0                                              \    ? (a)< (min)>> (b)                                 \    : (max)>> (b)< (a))
end_define

begin_comment
comment|/* The _GL*_OVERFLOW macros have the same restrictions as the    *_RANGE_OVERFLOW macros, except that they do not assume that operands    (e.g., A and B) have the same type as MIN and MAX.  Instead, they assume    that the result (e.g., A + B) has that type.  */
end_comment

begin_define
define|#
directive|define
name|_GL_ADD_OVERFLOW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|min
parameter_list|,
name|max
parameter_list|)
define|\
value|((min)< 0 ? INT_ADD_RANGE_OVERFLOW (a, b, min, max)                  \    : (a)< 0 ? (b)<= (a) + (b)                                         \    : (b)< 0 ? (a)<= (a) + (b)                                         \    : (a) + (b)< (b))
end_define

begin_define
define|#
directive|define
name|_GL_SUBTRACT_OVERFLOW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|min
parameter_list|,
name|max
parameter_list|)
define|\
value|((min)< 0 ? INT_SUBTRACT_RANGE_OVERFLOW (a, b, min, max)             \    : (a)< 0 ? 1                                                        \    : (b)< 0 ? (a) - (b)<= (a)                                         \    : (a)< (b))
end_define

begin_define
define|#
directive|define
name|_GL_MULTIPLY_OVERFLOW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|min
parameter_list|,
name|max
parameter_list|)
define|\
value|(((min) == 0&& (((a)< 0&& 0< (b)) || ((b)< 0&& 0< (a))))       \    || INT_MULTIPLY_RANGE_OVERFLOW (a, b, min, max))
end_define

begin_define
define|#
directive|define
name|_GL_DIVIDE_OVERFLOW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|min
parameter_list|,
name|max
parameter_list|)
define|\
value|((min)< 0 ? (b) == _GL_INT_NEGATE_CONVERT (min, 1)&& (a)< - (max)  \    : (a)< 0 ? (b)<= (a) + (b) - 1                                     \    : (b)< 0&& (a) + (b)<= (a))
end_define

begin_define
define|#
directive|define
name|_GL_REMAINDER_OVERFLOW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|min
parameter_list|,
name|max
parameter_list|)
define|\
value|((min)< 0 ? (b) == _GL_INT_NEGATE_CONVERT (min, 1)&& (a)< - (max)  \    : (a)< 0 ? (a) % (b) != ((max) - (b) + 1) % (b)                     \    : (b)< 0&& ! _GL_UNSIGNED_NEG_MULTIPLE (a, b, max))
end_define

begin_comment
comment|/* Return a nonzero value if A is a mathematical multiple of B, where    A is unsigned, B is negative, and MAX is the maximum value of A's    type.  A's type must be the same as (A % B)'s type.  Normally (A %    -B == 0) suffices, but things get tricky if -B would overflow.  */
end_comment

begin_define
define|#
directive|define
name|_GL_UNSIGNED_NEG_MULTIPLE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|max
parameter_list|)
define|\
value|(((b)< -_GL_SIGNED_INT_MAXIMUM (b)                                   \     ? (_GL_SIGNED_INT_MAXIMUM (b) == (max)                              \        ? (a)                                                            \        : (a) % (_GL_INT_CONVERT (a, _GL_SIGNED_INT_MAXIMUM (b)) + 1))   \     : (a) % - (b))                                                      \    == 0)
end_define

begin_comment
comment|/* Integer overflow checks.     The INT_<op>_OVERFLOW macros return 1 if the corresponding C operators    might not yield numerically correct answers due to arithmetic overflow.    They work correctly on all known practical hosts, and do not rely    on undefined behavior due to signed arithmetic overflow.     Example usage:       long int i = ...;      long int j = ...;      if (INT_MULTIPLY_OVERFLOW (i, j))        printf ("multiply would overflow");      else        printf ("product is %ld", i * j);     These macros do not check for all possible numerical problems or    undefined or unspecified behavior: they do not check for division    by zero, for bad shift counts, or for shifting negative numbers.     These macros may evaluate their arguments zero or multiple times, so the    arguments should not have side effects.     These macros are tuned for their last argument being a constant.     Return 1 if the integer expressions A * B, A - B, -A, A * B, A / B,    A % B, and A<< B would overflow, respectively.  */
end_comment

begin_define
define|#
directive|define
name|INT_ADD_OVERFLOW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|_GL_BINARY_OP_OVERFLOW (a, b, _GL_ADD_OVERFLOW)
end_define

begin_define
define|#
directive|define
name|INT_SUBTRACT_OVERFLOW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|_GL_BINARY_OP_OVERFLOW (a, b, _GL_SUBTRACT_OVERFLOW)
end_define

begin_define
define|#
directive|define
name|INT_NEGATE_OVERFLOW
parameter_list|(
name|a
parameter_list|)
define|\
value|INT_NEGATE_RANGE_OVERFLOW (a, _GL_INT_MINIMUM (a), _GL_INT_MAXIMUM (a))
end_define

begin_define
define|#
directive|define
name|INT_MULTIPLY_OVERFLOW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|_GL_BINARY_OP_OVERFLOW (a, b, _GL_MULTIPLY_OVERFLOW)
end_define

begin_define
define|#
directive|define
name|INT_DIVIDE_OVERFLOW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|_GL_BINARY_OP_OVERFLOW (a, b, _GL_DIVIDE_OVERFLOW)
end_define

begin_define
define|#
directive|define
name|INT_REMAINDER_OVERFLOW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|_GL_BINARY_OP_OVERFLOW (a, b, _GL_REMAINDER_OVERFLOW)
end_define

begin_define
define|#
directive|define
name|INT_LEFT_SHIFT_OVERFLOW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|INT_LEFT_SHIFT_RANGE_OVERFLOW (a, b, \                                  _GL_INT_MINIMUM (a), _GL_INT_MAXIMUM (a))
end_define

begin_comment
comment|/* Return 1 if the expression A<op> B would overflow,    where OP_RESULT_OVERFLOW (A, B, MIN, MAX) does the actual test,    assuming MIN and MAX are the minimum and maximum for the result type.    Arguments should be free of side effects.  */
end_comment

begin_define
define|#
directive|define
name|_GL_BINARY_OP_OVERFLOW
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|op_result_overflow
parameter_list|)
define|\
value|op_result_overflow (a, b,                                     \                       _GL_INT_MINIMUM (0 * (b) + (a)),          \                       _GL_INT_MAXIMUM (0 * (b) + (a)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GL_INTPROPS_H */
end_comment

end_unit

