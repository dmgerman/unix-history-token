begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// The template and inlines for the numeric_limits classes. -*- C++ -*-
end_comment

begin_comment
comment|// Copyright (C) 1999, 2000, 2001, 2002, 2003, 2005
end_comment

begin_comment
comment|// Free Software Foundation, Inc.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is part of the GNU ISO C++ Library.  This library is free
end_comment

begin_comment
comment|// software; you can redistribute it and/or modify it under the
end_comment

begin_comment
comment|// terms of the GNU General Public License as published by the
end_comment

begin_comment
comment|// Free Software Foundation; either version 2, or (at your option)
end_comment

begin_comment
comment|// any later version.
end_comment

begin_comment
comment|// This library is distributed in the hope that it will be useful,
end_comment

begin_comment
comment|// but WITHOUT ANY WARRANTY; without even the implied warranty of
end_comment

begin_comment
comment|// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
end_comment

begin_comment
comment|// GNU General Public License for more details.
end_comment

begin_comment
comment|// You should have received a copy of the GNU General Public License along
end_comment

begin_comment
comment|// with this library; see the file COPYING.  If not, write to the Free
end_comment

begin_comment
comment|// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
end_comment

begin_comment
comment|// USA.
end_comment

begin_comment
comment|// As a special exception, you may use this file as part of a free software
end_comment

begin_comment
comment|// library without restriction.  Specifically, if other files instantiate
end_comment

begin_comment
comment|// templates or use macros or inline functions from this file, or you compile
end_comment

begin_comment
comment|// this file and link it with other files to produce an executable, this
end_comment

begin_comment
comment|// file does not by itself cause the resulting executable to be covered by
end_comment

begin_comment
comment|// the GNU General Public License.  This exception does not however
end_comment

begin_comment
comment|// invalidate any other reasons why the executable file might be covered by
end_comment

begin_comment
comment|// the GNU General Public License.
end_comment

begin_comment
comment|/** @file limits  *  This is a Standard C++ Library header.  */
end_comment

begin_comment
comment|// Note: this is not a conforming implementation.
end_comment

begin_comment
comment|// Written by Gabriel Dos Reis<gdr@codesourcery.com>
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ISO 14882:1998
end_comment

begin_comment
comment|// 18.2.1
end_comment

begin_comment
comment|//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GLIBCXX_NUMERIC_LIMITS
end_ifndef

begin_define
define|#
directive|define
name|_GLIBCXX_NUMERIC_LIMITS
value|1
end_define

begin_pragma
pragma|#
directive|pragma
name|GCC
name|system_header
end_pragma

begin_include
include|#
directive|include
file|<bits/c++config.h>
end_include

begin_comment
comment|//
end_comment

begin_comment
comment|// The numeric_limits<> traits document implementation-defined aspects
end_comment

begin_comment
comment|// of fundamental arithmetic data types (integers and floating points).
end_comment

begin_comment
comment|// From Standard C++ point of view, there are 13 such types:
end_comment

begin_comment
comment|//   * integers
end_comment

begin_comment
comment|//         bool						        (1)
end_comment

begin_comment
comment|//         char, signed char, unsigned char			(3)
end_comment

begin_comment
comment|//         short, unsigned short				(2)
end_comment

begin_comment
comment|//         int, unsigned					(2)
end_comment

begin_comment
comment|//         long, unsigned long					(2)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   * floating points
end_comment

begin_comment
comment|//         float						(1)
end_comment

begin_comment
comment|//         double						(1)
end_comment

begin_comment
comment|//         long double						(1)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// GNU C++ undertstands (where supported by the host C-library)
end_comment

begin_comment
comment|//   * integer
end_comment

begin_comment
comment|//         long long, unsigned long long			(2)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// which brings us to 15 fundamental arithmetic data types in GNU C++.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Since a numeric_limits<> is a bit tricky to get right, we rely on
end_comment

begin_comment
comment|// an interface composed of macros which should be defined in config/os
end_comment

begin_comment
comment|// or config/cpu when they differ from the generic (read arbitrary)
end_comment

begin_comment
comment|// definitions given here.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// These values can be overridden in the target configuration file.
end_comment

begin_comment
comment|// The default values are appropriate for many 32-bit targets.
end_comment

begin_comment
comment|// GCC only intrinsicly supports modulo integral types.  The only remaining
end_comment

begin_comment
comment|// integral exceptional values is division by zero.  Only targets that do not
end_comment

begin_comment
comment|// signal division by zero in some "hard to ignore" way should use false.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__glibcxx_integral_traps
end_ifndef

begin_define
define|#
directive|define
name|__glibcxx_integral_traps
value|true
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// float
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Default values.  Should be overriden in configuration files if necessary.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__glibcxx_float_has_denorm_loss
end_ifndef

begin_define
define|#
directive|define
name|__glibcxx_float_has_denorm_loss
value|false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__glibcxx_float_traps
end_ifndef

begin_define
define|#
directive|define
name|__glibcxx_float_traps
value|false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__glibcxx_float_tinyness_before
end_ifndef

begin_define
define|#
directive|define
name|__glibcxx_float_tinyness_before
value|false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// double
end_comment

begin_comment
comment|// Default values.  Should be overriden in configuration files if necessary.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__glibcxx_double_has_denorm_loss
end_ifndef

begin_define
define|#
directive|define
name|__glibcxx_double_has_denorm_loss
value|false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__glibcxx_double_traps
end_ifndef

begin_define
define|#
directive|define
name|__glibcxx_double_traps
value|false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__glibcxx_double_tinyness_before
end_ifndef

begin_define
define|#
directive|define
name|__glibcxx_double_tinyness_before
value|false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// long double
end_comment

begin_comment
comment|// Default values.  Should be overriden in configuration files if necessary.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__glibcxx_long_double_has_denorm_loss
end_ifndef

begin_define
define|#
directive|define
name|__glibcxx_long_double_has_denorm_loss
value|false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__glibcxx_long_double_traps
end_ifndef

begin_define
define|#
directive|define
name|__glibcxx_long_double_traps
value|false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__glibcxx_long_double_tinyness_before
end_ifndef

begin_define
define|#
directive|define
name|__glibcxx_long_double_tinyness_before
value|false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// You should not need to define any macros below this point.
end_comment

begin_define
define|#
directive|define
name|__glibcxx_signed
parameter_list|(
name|T
parameter_list|)
value|((T)(-1)< 0)
end_define

begin_define
define|#
directive|define
name|__glibcxx_min
parameter_list|(
name|T
parameter_list|)
define|\
value|(__glibcxx_signed (T) ? (T)1<< __glibcxx_digits (T) : (T)0)
end_define

begin_define
define|#
directive|define
name|__glibcxx_max
parameter_list|(
name|T
parameter_list|)
define|\
value|(__glibcxx_signed (T) ? ((T)1<< __glibcxx_digits (T)) - 1 : ~(T)0)
end_define

begin_define
define|#
directive|define
name|__glibcxx_digits
parameter_list|(
name|T
parameter_list|)
define|\
value|(sizeof(T) * __CHAR_BIT__ - __glibcxx_signed (T))
end_define

begin_comment
comment|// The fraction 643/2136 approximates log10(2) to 7 significant digits.
end_comment

begin_define
define|#
directive|define
name|__glibcxx_digits10
parameter_list|(
name|T
parameter_list|)
define|\
value|(__glibcxx_digits (T) * 643 / 2136)
end_define

begin_expr_stmt
name|_GLIBCXX_BEGIN_NAMESPACE
argument_list|(
name|std
argument_list|)
comment|/**    *  @brief Describes the rounding style for floating-point types.    *    *  This is used in the std::numeric_limits class.   */
expr|enum
name|float_round_style
block|{
name|round_indeterminate
operator|=
operator|-
literal|1
block|,
comment|///< Self-explanatory.
name|round_toward_zero
operator|=
literal|0
block|,
comment|///< Self-explanatory.
name|round_to_nearest
operator|=
literal|1
block|,
comment|///< To the nearest representable value.
name|round_toward_infinity
operator|=
literal|2
block|,
comment|///< Self-explanatory.
name|round_toward_neg_infinity
operator|=
literal|3
comment|///< Self-explanatory.
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**    *  @brief Describes the denormalization for floating-point types.    *    *  These values represent the presence or absence of a variable number    *  of exponent bits.  This type is used in the std::numeric_limits class.   */
end_comment

begin_enum
enum|enum
name|float_denorm_style
block|{
comment|/// Indeterminate at compile time whether denormalized values are allowed.
name|denorm_indeterminate
init|=
operator|-
literal|1
block|,
comment|/// The type does not allow denormalized values.
name|denorm_absent
init|=
literal|0
block|,
comment|/// The type allows denormalized values.
name|denorm_present
init|=
literal|1
block|}
enum|;
end_enum

begin_comment
comment|/**    *  @brief Part of std::numeric_limits.    *    *  The @c static @c const members are usable as integral constant    *  expressions.    *    *  @note This is a seperate class for purposes of efficiency; you    *        should only access these members as part of an instantiation    *        of the std::numeric_limits class.   */
end_comment

begin_struct
struct|struct
name|__numeric_limits_base
block|{
comment|/** This will be true for all fundamental types (which have         specializations), and false for everything else.  */
specifier|static
specifier|const
name|bool
name|is_specialized
init|=
name|false
decl_stmt|;
comment|/** The number of @c radix digits that be represented without change:  for         integer types, the number of non-sign bits in the mantissa; for         floating types, the number of @c radix digits in the mantissa.  */
specifier|static
specifier|const
name|int
name|digits
init|=
literal|0
decl_stmt|;
comment|/** The number of base 10 digits that can be represented without change. */
specifier|static
specifier|const
name|int
name|digits10
init|=
literal|0
decl_stmt|;
comment|/** True if the type is signed.  */
specifier|static
specifier|const
name|bool
name|is_signed
init|=
name|false
decl_stmt|;
comment|/** True if the type is integer.      *  @if maint      *  Is this supposed to be "if the type is integral"?      *  @endif     */
specifier|static
specifier|const
name|bool
name|is_integer
init|=
name|false
decl_stmt|;
comment|/** True if the type uses an exact representation.  "All integer types are         exact, but not all exact types are integer.  For example, rational and         fixed-exponent representations are exact but not integer."         [18.2.1.2]/15  */
specifier|static
specifier|const
name|bool
name|is_exact
init|=
name|false
decl_stmt|;
comment|/** For integer types, specifies the base of the representation.  For         floating types, specifies the base of the exponent representation.  */
specifier|static
specifier|const
name|int
name|radix
init|=
literal|0
decl_stmt|;
comment|/** The minimum negative integer such that @c radix raised to the power of         (one less than that integer) is a normalized floating point number.  */
specifier|static
specifier|const
name|int
name|min_exponent
init|=
literal|0
decl_stmt|;
comment|/** The minimum negative integer such that 10 raised to that power is in         the range of normalized floating point numbers.  */
specifier|static
specifier|const
name|int
name|min_exponent10
init|=
literal|0
decl_stmt|;
comment|/** The maximum positive integer such that @c radix raised to the power of         (one less than that integer) is a representable finite floating point 	number.  */
specifier|static
specifier|const
name|int
name|max_exponent
init|=
literal|0
decl_stmt|;
comment|/** The maximum positive integer such that 10 raised to that power is in         the range of representable finite floating point numbers.  */
specifier|static
specifier|const
name|int
name|max_exponent10
init|=
literal|0
decl_stmt|;
comment|/** True if the type has a representation for positive infinity.  */
specifier|static
specifier|const
name|bool
name|has_infinity
init|=
name|false
decl_stmt|;
comment|/** True if the type has a representation for a quiet (non-signaling)         "Not a Number."  */
specifier|static
specifier|const
name|bool
name|has_quiet_NaN
init|=
name|false
decl_stmt|;
comment|/** True if the type has a representation for a signaling         "Not a Number."  */
specifier|static
specifier|const
name|bool
name|has_signaling_NaN
init|=
name|false
decl_stmt|;
comment|/** See std::float_denorm_style for more information.  */
specifier|static
specifier|const
name|float_denorm_style
name|has_denorm
init|=
name|denorm_absent
decl_stmt|;
comment|/** "True if loss of accuracy is detected as a denormalization loss,         rather than as an inexact result." [18.2.1.2]/42  */
specifier|static
specifier|const
name|bool
name|has_denorm_loss
init|=
name|false
decl_stmt|;
comment|/** True if-and-only-if the type adheres to the IEC 559 standard, also         known as IEEE 754.  (Only makes sense for floating point types.)  */
specifier|static
specifier|const
name|bool
name|is_iec559
init|=
name|false
decl_stmt|;
comment|/** "True if the set of values representable by the type is finite.   All         built-in types are bounded, this member would be false for arbitrary 	precision types." [18.2.1.2]/54  */
specifier|static
specifier|const
name|bool
name|is_bounded
init|=
name|false
decl_stmt|;
comment|/** True if the type is @e modulo, that is, if it is possible to add two         positive numbers and have a result that wraps around to a third number         that is less.  Typically false for floating types, true for unsigned         integers, and true for signed integers.  */
specifier|static
specifier|const
name|bool
name|is_modulo
init|=
name|false
decl_stmt|;
comment|/** True if trapping is implemented for this type.  */
specifier|static
specifier|const
name|bool
name|traps
init|=
name|false
decl_stmt|;
comment|/** True if tinyness is detected before rounding.  (see IEC 559)  */
specifier|static
specifier|const
name|bool
name|tinyness_before
init|=
name|false
decl_stmt|;
comment|/** See std::float_round_style for more information.  This is only         meaningful for floating types; integer types will all be 	round_toward_zero.  */
specifier|static
specifier|const
name|float_round_style
name|round_style
init|=
name|round_toward_zero
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**    *  @brief Properties of fundamental types.    *    *  This class allows a program to obtain information about the    *  representation of a fundamental type on a given platform.  For    *  non-fundamental types, the functions will return 0 and the data    *  members will all be @c false.    *    *  @if maint    *  _GLIBCXX_RESOLVE_LIB_DEFECTS:  DRs 201 and 184 (hi Gaby!) are    *  noted, but not incorporated in this documented (yet).    *  @endif   */
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|_Tp
operator|>
expr|struct
name|numeric_limits
operator|:
name|public
name|__numeric_limits_base
block|{
comment|/** The minimum finite value, or for floating types with           denormalization, the minimum positive normalized value.  */
specifier|static
name|_Tp
name|min
argument_list|()
name|throw
argument_list|()
block|{
return|return
name|static_cast
operator|<
name|_Tp
operator|>
operator|(
literal|0
operator|)
return|;
block|}
comment|/** The maximum finite value.  */
specifier|static
name|_Tp
name|max
argument_list|()
name|throw
argument_list|()
block|{
return|return
name|static_cast
operator|<
name|_Tp
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/** The @e machine @e epsilon:  the difference between 1 and the least           value greater than 1 that is representable.  */
end_comment

begin_function
specifier|static
name|_Tp
name|epsilon
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|_Tp
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/** The maximum rounding error measurement (see LIA-1).  */
end_comment

begin_function
specifier|static
name|_Tp
name|round_error
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|_Tp
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/** The representation of positive infinity, if @c has_infinity.  */
end_comment

begin_function
specifier|static
name|_Tp
name|infinity
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|_Tp
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/** The representation of a quiet "Not a Number," if @c has_quiet_NaN. */
end_comment

begin_function
specifier|static
name|_Tp
name|quiet_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|_Tp
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/** The representation of a signaling "Not a Number," if           @c has_signaling_NaN. */
end_comment

begin_function
specifier|static
name|_Tp
name|signaling_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|_Tp
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/** The minimum positive denormalized value.  For types where           @c has_denorm is false, this is the minimum positive normalized 	  value.  */
end_comment

begin_function
specifier|static
name|_Tp
name|denorm_min
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|_Tp
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
unit|};
comment|// Now there follow 15 explicit specializations.  Yes, 15.  Make sure
end_comment

begin_comment
comment|// you get the count right.
end_comment

begin_comment
comment|/// numeric_limits<bool> specialization.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|numeric_limits
operator|<
name|bool
operator|>
block|{
specifier|static
specifier|const
name|bool
name|is_specialized
operator|=
name|true
block|;
specifier|static
name|bool
name|min
argument_list|()
name|throw
argument_list|()
block|{
return|return
name|false
return|;
block|}
specifier|static
name|bool
name|max
argument_list|()
name|throw
argument_list|()
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits10
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_signed
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_integer
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_exact
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|radix
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|bool
name|epsilon
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|false
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|round_error
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|false
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent10
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent10
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_infinity
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_quiet_NaN
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_signaling_NaN
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_denorm_style
name|has_denorm
init|=
name|denorm_absent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_denorm_loss
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|bool
name|infinity
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|false
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|quiet_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|false
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|signaling_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|false
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|denorm_min
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|false
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_iec559
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_bounded
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_modulo
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_comment
comment|// It is not clear what it means for a boolean type to trap.
end_comment

begin_comment
comment|// This is a DR on the LWG issue list.  Here, I use integer
end_comment

begin_comment
comment|// promotion semantics.
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|traps
init|=
name|__glibcxx_integral_traps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|tinyness_before
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_round_style
name|round_style
init|=
name|round_toward_zero
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// numeric_limits<char> specialization.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|numeric_limits
operator|<
name|char
operator|>
block|{
specifier|static
specifier|const
name|bool
name|is_specialized
operator|=
name|true
block|;
specifier|static
name|char
name|min
argument_list|()
name|throw
argument_list|()
block|{
return|return
name|__glibcxx_min
argument_list|(
name|char
argument_list|)
return|;
block|}
specifier|static
name|char
name|max
argument_list|()
name|throw
argument_list|()
block|{
return|return
name|__glibcxx_max
argument_list|(
name|char
argument_list|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits
init|=
name|__glibcxx_digits
argument_list|(
name|char
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits10
init|=
name|__glibcxx_digits10
argument_list|(
name|char
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_signed
init|=
name|__glibcxx_signed
argument_list|(
name|char
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_integer
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_exact
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|radix
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|char
name|epsilon
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|char
name|round_error
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent10
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent10
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_infinity
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_quiet_NaN
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_signaling_NaN
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_denorm_style
name|has_denorm
init|=
name|denorm_absent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_denorm_loss
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|char
name|infinity
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|char
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|char
name|quiet_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|char
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|char
name|signaling_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|char
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|char
name|denorm_min
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|char
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_iec559
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_bounded
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_modulo
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|traps
init|=
name|__glibcxx_integral_traps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|tinyness_before
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_round_style
name|round_style
init|=
name|round_toward_zero
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// numeric_limits<signed char> specialization.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|numeric_limits
operator|<
name|signed
name|char
operator|>
block|{
specifier|static
specifier|const
name|bool
name|is_specialized
operator|=
name|true
block|;
specifier|static
name|signed
name|char
name|min
argument_list|()
name|throw
argument_list|()
block|{
return|return
operator|-
name|__SCHAR_MAX__
operator|-
literal|1
return|;
block|}
specifier|static
name|signed
name|char
name|max
argument_list|()
name|throw
argument_list|()
block|{
return|return
name|__SCHAR_MAX__
return|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits
init|=
name|__glibcxx_digits
argument_list|(
argument|signed char
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits10
init|=
name|__glibcxx_digits10
argument_list|(
argument|signed char
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_signed
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_integer
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_exact
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|radix
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|signed
name|char
name|epsilon
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|signed
name|char
name|round_error
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent10
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent10
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_infinity
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_quiet_NaN
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_signaling_NaN
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_denorm_style
name|has_denorm
init|=
name|denorm_absent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_denorm_loss
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|signed
name|char
name|infinity
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|signed
name|char
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|signed
name|char
name|quiet_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|signed
name|char
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|signed
name|char
name|signaling_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|signed
name|char
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|signed
name|char
name|denorm_min
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|signed
name|char
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_iec559
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_bounded
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_modulo
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|traps
init|=
name|__glibcxx_integral_traps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|tinyness_before
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_round_style
name|round_style
init|=
name|round_toward_zero
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// numeric_limits<unsigned char> specialization.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|numeric_limits
operator|<
name|unsigned
name|char
operator|>
block|{
specifier|static
specifier|const
name|bool
name|is_specialized
operator|=
name|true
block|;
specifier|static
name|unsigned
name|char
name|min
argument_list|()
name|throw
argument_list|()
block|{
return|return
literal|0
return|;
block|}
specifier|static
name|unsigned
name|char
name|max
argument_list|()
name|throw
argument_list|()
block|{
return|return
name|__SCHAR_MAX__
operator|*
literal|2U
operator|+
literal|1
return|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits
init|=
name|__glibcxx_digits
argument_list|(
argument|unsigned char
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits10
init|=
name|__glibcxx_digits10
argument_list|(
argument|unsigned char
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_signed
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_integer
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_exact
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|radix
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|unsigned
name|char
name|epsilon
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|char
name|round_error
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent10
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent10
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_infinity
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_quiet_NaN
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_signaling_NaN
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_denorm_style
name|has_denorm
init|=
name|denorm_absent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_denorm_loss
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|unsigned
name|char
name|infinity
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|unsigned
name|char
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|char
name|quiet_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|unsigned
name|char
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|char
name|signaling_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|unsigned
name|char
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|char
name|denorm_min
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|unsigned
name|char
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_iec559
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_bounded
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_modulo
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|traps
init|=
name|__glibcxx_integral_traps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|tinyness_before
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_round_style
name|round_style
init|=
name|round_toward_zero
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// numeric_limits<wchar_t> specialization.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|numeric_limits
operator|<
name|wchar_t
operator|>
block|{
specifier|static
specifier|const
name|bool
name|is_specialized
operator|=
name|true
block|;
specifier|static
name|wchar_t
name|min
argument_list|()
name|throw
argument_list|()
block|{
return|return
name|__glibcxx_min
argument_list|(
name|wchar_t
argument_list|)
return|;
block|}
specifier|static
name|wchar_t
name|max
argument_list|()
name|throw
argument_list|()
block|{
return|return
name|__glibcxx_max
argument_list|(
name|wchar_t
argument_list|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits
init|=
name|__glibcxx_digits
argument_list|(
name|wchar_t
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits10
init|=
name|__glibcxx_digits10
argument_list|(
name|wchar_t
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_signed
init|=
name|__glibcxx_signed
argument_list|(
name|wchar_t
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_integer
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_exact
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|radix
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|wchar_t
name|epsilon
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|wchar_t
name|round_error
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent10
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent10
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_infinity
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_quiet_NaN
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_signaling_NaN
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_denorm_style
name|has_denorm
init|=
name|denorm_absent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_denorm_loss
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|wchar_t
name|infinity
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|wchar_t
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|wchar_t
name|quiet_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|wchar_t
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|wchar_t
name|signaling_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|wchar_t
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|wchar_t
name|denorm_min
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|wchar_t
argument_list|()
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_iec559
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_bounded
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_modulo
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|traps
init|=
name|__glibcxx_integral_traps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|tinyness_before
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_round_style
name|round_style
init|=
name|round_toward_zero
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// numeric_limits<short> specialization.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|numeric_limits
operator|<
name|short
operator|>
block|{
specifier|static
specifier|const
name|bool
name|is_specialized
operator|=
name|true
block|;
specifier|static
name|short
name|min
argument_list|()
name|throw
argument_list|()
block|{
return|return
operator|-
name|__SHRT_MAX__
operator|-
literal|1
return|;
block|}
specifier|static
name|short
name|max
argument_list|()
name|throw
argument_list|()
block|{
return|return
name|__SHRT_MAX__
return|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits
init|=
name|__glibcxx_digits
argument_list|(
name|short
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits10
init|=
name|__glibcxx_digits10
argument_list|(
name|short
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_signed
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_integer
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_exact
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|radix
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|short
name|epsilon
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|short
name|round_error
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent10
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent10
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_infinity
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_quiet_NaN
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_signaling_NaN
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_denorm_style
name|has_denorm
init|=
name|denorm_absent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_denorm_loss
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|short
name|infinity
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|short
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|short
name|quiet_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|short
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|short
name|signaling_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|short
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|short
name|denorm_min
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|short
argument_list|()
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_iec559
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_bounded
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_modulo
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|traps
init|=
name|__glibcxx_integral_traps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|tinyness_before
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_round_style
name|round_style
init|=
name|round_toward_zero
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// numeric_limits<unsigned short> specialization.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|numeric_limits
operator|<
name|unsigned
name|short
operator|>
block|{
specifier|static
specifier|const
name|bool
name|is_specialized
operator|=
name|true
block|;
specifier|static
name|unsigned
name|short
name|min
argument_list|()
name|throw
argument_list|()
block|{
return|return
literal|0
return|;
block|}
specifier|static
name|unsigned
name|short
name|max
argument_list|()
name|throw
argument_list|()
block|{
return|return
name|__SHRT_MAX__
operator|*
literal|2U
operator|+
literal|1
return|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits
init|=
name|__glibcxx_digits
argument_list|(
argument|unsigned short
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits10
init|=
name|__glibcxx_digits10
argument_list|(
argument|unsigned short
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_signed
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_integer
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_exact
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|radix
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|unsigned
name|short
name|epsilon
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|short
name|round_error
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent10
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent10
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_infinity
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_quiet_NaN
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_signaling_NaN
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_denorm_style
name|has_denorm
init|=
name|denorm_absent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_denorm_loss
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|unsigned
name|short
name|infinity
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|unsigned
name|short
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|short
name|quiet_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|unsigned
name|short
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|short
name|signaling_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|unsigned
name|short
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|short
name|denorm_min
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|unsigned
name|short
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_iec559
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_bounded
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_modulo
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|traps
init|=
name|__glibcxx_integral_traps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|tinyness_before
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_round_style
name|round_style
init|=
name|round_toward_zero
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// numeric_limits<int> specialization.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|numeric_limits
operator|<
name|int
operator|>
block|{
specifier|static
specifier|const
name|bool
name|is_specialized
operator|=
name|true
block|;
specifier|static
name|int
name|min
argument_list|()
name|throw
argument_list|()
block|{
return|return
operator|-
name|__INT_MAX__
operator|-
literal|1
return|;
block|}
specifier|static
name|int
name|max
argument_list|()
name|throw
argument_list|()
block|{
return|return
name|__INT_MAX__
return|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits
init|=
name|__glibcxx_digits
argument_list|(
name|int
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits10
init|=
name|__glibcxx_digits10
argument_list|(
name|int
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_signed
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_integer
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_exact
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|radix
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|epsilon
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|round_error
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent10
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent10
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_infinity
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_quiet_NaN
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_signaling_NaN
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_denorm_style
name|has_denorm
init|=
name|denorm_absent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_denorm_loss
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|infinity
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|quiet_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|signaling_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|denorm_min
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_iec559
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_bounded
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_modulo
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|traps
init|=
name|__glibcxx_integral_traps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|tinyness_before
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_round_style
name|round_style
init|=
name|round_toward_zero
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// numeric_limits<unsigned int> specialization.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|numeric_limits
operator|<
name|unsigned
name|int
operator|>
block|{
specifier|static
specifier|const
name|bool
name|is_specialized
operator|=
name|true
block|;
specifier|static
name|unsigned
name|int
name|min
argument_list|()
name|throw
argument_list|()
block|{
return|return
literal|0
return|;
block|}
specifier|static
name|unsigned
name|int
name|max
argument_list|()
name|throw
argument_list|()
block|{
return|return
name|__INT_MAX__
operator|*
literal|2U
operator|+
literal|1
return|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits
init|=
name|__glibcxx_digits
argument_list|(
argument|unsigned int
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits10
init|=
name|__glibcxx_digits10
argument_list|(
argument|unsigned int
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_signed
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_integer
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_exact
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|radix
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|unsigned
name|int
name|epsilon
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|int
name|round_error
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent10
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent10
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_infinity
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_quiet_NaN
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_signaling_NaN
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_denorm_style
name|has_denorm
init|=
name|denorm_absent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_denorm_loss
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|unsigned
name|int
name|infinity
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|unsigned
name|int
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|int
name|quiet_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|unsigned
name|int
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|int
name|signaling_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|unsigned
name|int
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|int
name|denorm_min
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|unsigned
name|int
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_iec559
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_bounded
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_modulo
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|traps
init|=
name|__glibcxx_integral_traps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|tinyness_before
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_round_style
name|round_style
init|=
name|round_toward_zero
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// numeric_limits<long> specialization.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|numeric_limits
operator|<
name|long
operator|>
block|{
specifier|static
specifier|const
name|bool
name|is_specialized
operator|=
name|true
block|;
specifier|static
name|long
name|min
argument_list|()
name|throw
argument_list|()
block|{
return|return
operator|-
name|__LONG_MAX__
operator|-
literal|1
return|;
block|}
specifier|static
name|long
name|max
argument_list|()
name|throw
argument_list|()
block|{
return|return
name|__LONG_MAX__
return|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits
init|=
name|__glibcxx_digits
argument_list|(
name|long
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits10
init|=
name|__glibcxx_digits10
argument_list|(
name|long
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_signed
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_integer
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_exact
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|radix
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|long
name|epsilon
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|long
name|round_error
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent10
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent10
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_infinity
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_quiet_NaN
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_signaling_NaN
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_denorm_style
name|has_denorm
init|=
name|denorm_absent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_denorm_loss
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|long
name|infinity
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|long
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|long
name|quiet_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|long
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|long
name|signaling_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|long
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|long
name|denorm_min
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|long
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_iec559
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_bounded
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_modulo
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|traps
init|=
name|__glibcxx_integral_traps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|tinyness_before
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_round_style
name|round_style
init|=
name|round_toward_zero
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// numeric_limits<unsigned long> specialization.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|numeric_limits
operator|<
name|unsigned
name|long
operator|>
block|{
specifier|static
specifier|const
name|bool
name|is_specialized
operator|=
name|true
block|;
specifier|static
name|unsigned
name|long
name|min
argument_list|()
name|throw
argument_list|()
block|{
return|return
literal|0
return|;
block|}
specifier|static
name|unsigned
name|long
name|max
argument_list|()
name|throw
argument_list|()
block|{
return|return
name|__LONG_MAX__
operator|*
literal|2UL
operator|+
literal|1
return|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits
init|=
name|__glibcxx_digits
argument_list|(
argument|unsigned long
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits10
init|=
name|__glibcxx_digits10
argument_list|(
argument|unsigned long
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_signed
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_integer
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_exact
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|radix
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|unsigned
name|long
name|epsilon
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|long
name|round_error
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent10
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent10
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_infinity
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_quiet_NaN
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_signaling_NaN
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_denorm_style
name|has_denorm
init|=
name|denorm_absent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_denorm_loss
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|unsigned
name|long
name|infinity
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|unsigned
name|long
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|long
name|quiet_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|unsigned
name|long
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|long
name|signaling_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|unsigned
name|long
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|long
name|denorm_min
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|unsigned
name|long
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_iec559
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_bounded
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_modulo
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|traps
init|=
name|__glibcxx_integral_traps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|tinyness_before
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_round_style
name|round_style
init|=
name|round_toward_zero
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// numeric_limits<long long> specialization.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|numeric_limits
operator|<
name|long
name|long
operator|>
block|{
specifier|static
specifier|const
name|bool
name|is_specialized
operator|=
name|true
block|;
specifier|static
name|long
name|long
name|min
argument_list|()
name|throw
argument_list|()
block|{
return|return
operator|-
name|__LONG_LONG_MAX__
operator|-
literal|1
return|;
block|}
specifier|static
name|long
name|long
name|max
argument_list|()
name|throw
argument_list|()
block|{
return|return
name|__LONG_LONG_MAX__
return|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits
init|=
name|__glibcxx_digits
argument_list|(
argument|long long
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits10
init|=
name|__glibcxx_digits10
argument_list|(
argument|long long
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_signed
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_integer
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_exact
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|radix
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|long
name|long
name|epsilon
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|long
name|long
name|round_error
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent10
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent10
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_infinity
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_quiet_NaN
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_signaling_NaN
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_denorm_style
name|has_denorm
init|=
name|denorm_absent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_denorm_loss
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|long
name|long
name|infinity
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|long
name|long
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|long
name|long
name|quiet_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|long
name|long
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|long
name|long
name|signaling_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|long
name|long
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|long
name|long
name|denorm_min
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|long
name|long
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_iec559
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_bounded
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_modulo
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|traps
init|=
name|__glibcxx_integral_traps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|tinyness_before
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_round_style
name|round_style
init|=
name|round_toward_zero
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// numeric_limits<unsigned long long> specialization.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|numeric_limits
operator|<
name|unsigned
name|long
name|long
operator|>
block|{
specifier|static
specifier|const
name|bool
name|is_specialized
operator|=
name|true
block|;
specifier|static
name|unsigned
name|long
name|long
name|min
argument_list|()
name|throw
argument_list|()
block|{
return|return
literal|0
return|;
block|}
specifier|static
name|unsigned
name|long
name|long
name|max
argument_list|()
name|throw
argument_list|()
block|{
return|return
name|__LONG_LONG_MAX__
operator|*
literal|2ULL
operator|+
literal|1
return|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits
init|=
name|__glibcxx_digits
argument_list|(
argument|unsigned long long
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits10
init|=
name|__glibcxx_digits10
argument_list|(
argument|unsigned long long
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_signed
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_integer
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_exact
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|radix
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|unsigned
name|long
name|long
name|epsilon
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|long
name|long
name|round_error
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent10
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent10
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_infinity
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_quiet_NaN
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_signaling_NaN
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_denorm_style
name|has_denorm
init|=
name|denorm_absent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_denorm_loss
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|unsigned
name|long
name|long
name|infinity
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|unsigned
name|long
name|long
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|long
name|long
name|quiet_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|unsigned
name|long
name|long
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|long
name|long
name|signaling_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|unsigned
name|long
name|long
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|long
name|long
name|denorm_min
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|unsigned
name|long
name|long
operator|>
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_iec559
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_bounded
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_modulo
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|traps
init|=
name|__glibcxx_integral_traps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|tinyness_before
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_round_style
name|round_style
init|=
name|round_toward_zero
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// numeric_limits<float> specialization.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|numeric_limits
operator|<
name|float
operator|>
block|{
specifier|static
specifier|const
name|bool
name|is_specialized
operator|=
name|true
block|;
specifier|static
name|float
name|min
argument_list|()
name|throw
argument_list|()
block|{
return|return
name|__FLT_MIN__
return|;
block|}
specifier|static
name|float
name|max
argument_list|()
name|throw
argument_list|()
block|{
return|return
name|__FLT_MAX__
return|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits
init|=
name|__FLT_MANT_DIG__
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits10
init|=
name|__FLT_DIG__
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_signed
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_integer
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_exact
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|radix
init|=
name|__FLT_RADIX__
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|float
name|epsilon
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|__FLT_EPSILON__
return|;
block|}
end_function

begin_function
specifier|static
name|float
name|round_error
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
literal|0.5F
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent
init|=
name|__FLT_MIN_EXP__
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent10
init|=
name|__FLT_MIN_10_EXP__
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent
init|=
name|__FLT_MAX_EXP__
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent10
init|=
name|__FLT_MAX_10_EXP__
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_infinity
init|=
name|__FLT_HAS_INFINITY__
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_quiet_NaN
init|=
name|__FLT_HAS_QUIET_NAN__
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_signaling_NaN
init|=
name|has_quiet_NaN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_denorm_style
name|has_denorm
init|=
name|bool
argument_list|(
name|__FLT_HAS_DENORM__
argument_list|)
condition|?
name|denorm_present
else|:
name|denorm_absent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_denorm_loss
init|=
name|__glibcxx_float_has_denorm_loss
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|float
name|infinity
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|__builtin_huge_valf
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|float
name|quiet_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|__builtin_nanf
argument_list|(
literal|""
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|float
name|signaling_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|__builtin_nansf
argument_list|(
literal|""
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|float
name|denorm_min
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|__FLT_DENORM_MIN__
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_iec559
init|=
name|has_infinity
operator|&&
name|has_quiet_NaN
operator|&&
name|has_denorm
operator|==
name|denorm_present
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_bounded
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_modulo
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|traps
init|=
name|__glibcxx_float_traps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|tinyness_before
init|=
name|__glibcxx_float_tinyness_before
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_round_style
name|round_style
init|=
name|round_to_nearest
decl_stmt|;
end_decl_stmt

begin_undef
unit|};
undef|#
directive|undef
name|__glibcxx_float_has_denorm_loss
end_undef

begin_undef
undef|#
directive|undef
name|__glibcxx_float_traps
end_undef

begin_undef
undef|#
directive|undef
name|__glibcxx_float_tinyness_before
end_undef

begin_comment
comment|/// numeric_limits<double> specialization.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|numeric_limits
operator|<
name|double
operator|>
block|{
specifier|static
specifier|const
name|bool
name|is_specialized
operator|=
name|true
block|;
specifier|static
name|double
name|min
argument_list|()
name|throw
argument_list|()
block|{
return|return
name|__DBL_MIN__
return|;
block|}
specifier|static
name|double
name|max
argument_list|()
name|throw
argument_list|()
block|{
return|return
name|__DBL_MAX__
return|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits
init|=
name|__DBL_MANT_DIG__
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits10
init|=
name|__DBL_DIG__
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_signed
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_integer
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_exact
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|radix
init|=
name|__FLT_RADIX__
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|double
name|epsilon
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|__DBL_EPSILON__
return|;
block|}
end_function

begin_function
specifier|static
name|double
name|round_error
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
literal|0.5
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent
init|=
name|__DBL_MIN_EXP__
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent10
init|=
name|__DBL_MIN_10_EXP__
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent
init|=
name|__DBL_MAX_EXP__
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent10
init|=
name|__DBL_MAX_10_EXP__
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_infinity
init|=
name|__DBL_HAS_INFINITY__
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_quiet_NaN
init|=
name|__DBL_HAS_QUIET_NAN__
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_signaling_NaN
init|=
name|has_quiet_NaN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_denorm_style
name|has_denorm
init|=
name|bool
argument_list|(
name|__DBL_HAS_DENORM__
argument_list|)
condition|?
name|denorm_present
else|:
name|denorm_absent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_denorm_loss
init|=
name|__glibcxx_double_has_denorm_loss
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|double
name|infinity
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|__builtin_huge_val
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|double
name|quiet_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|__builtin_nan
argument_list|(
literal|""
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|double
name|signaling_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|__builtin_nans
argument_list|(
literal|""
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|double
name|denorm_min
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|__DBL_DENORM_MIN__
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_iec559
init|=
name|has_infinity
operator|&&
name|has_quiet_NaN
operator|&&
name|has_denorm
operator|==
name|denorm_present
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_bounded
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_modulo
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|traps
init|=
name|__glibcxx_double_traps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|tinyness_before
init|=
name|__glibcxx_double_tinyness_before
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_round_style
name|round_style
init|=
name|round_to_nearest
decl_stmt|;
end_decl_stmt

begin_undef
unit|};
undef|#
directive|undef
name|__glibcxx_double_has_denorm_loss
end_undef

begin_undef
undef|#
directive|undef
name|__glibcxx_double_traps
end_undef

begin_undef
undef|#
directive|undef
name|__glibcxx_double_tinyness_before
end_undef

begin_comment
comment|/// numeric_limits<long double> specialization.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|numeric_limits
operator|<
name|long
name|double
operator|>
block|{
specifier|static
specifier|const
name|bool
name|is_specialized
operator|=
name|true
block|;
specifier|static
name|long
name|double
name|min
argument_list|()
name|throw
argument_list|()
block|{
return|return
name|__LDBL_MIN__
return|;
block|}
specifier|static
name|long
name|double
name|max
argument_list|()
name|throw
argument_list|()
block|{
return|return
name|__LDBL_MAX__
return|;
block|}
end_expr_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits
init|=
name|__LDBL_MANT_DIG__
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|digits10
init|=
name|__LDBL_DIG__
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_signed
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_integer
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_exact
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|radix
init|=
name|__FLT_RADIX__
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|long
name|double
name|epsilon
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|__LDBL_EPSILON__
return|;
block|}
end_function

begin_function
specifier|static
name|long
name|double
name|round_error
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
literal|0.5L
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent
init|=
name|__LDBL_MIN_EXP__
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|min_exponent10
init|=
name|__LDBL_MIN_10_EXP__
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent
init|=
name|__LDBL_MAX_EXP__
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|max_exponent10
init|=
name|__LDBL_MAX_10_EXP__
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_infinity
init|=
name|__LDBL_HAS_INFINITY__
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_quiet_NaN
init|=
name|__LDBL_HAS_QUIET_NAN__
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_signaling_NaN
init|=
name|has_quiet_NaN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_denorm_style
name|has_denorm
init|=
name|bool
argument_list|(
name|__LDBL_HAS_DENORM__
argument_list|)
condition|?
name|denorm_present
else|:
name|denorm_absent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|has_denorm_loss
init|=
name|__glibcxx_long_double_has_denorm_loss
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|long
name|double
name|infinity
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|__builtin_huge_vall
argument_list|()
return|;
block|}
end_function

begin_function
specifier|static
name|long
name|double
name|quiet_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|__builtin_nanl
argument_list|(
literal|""
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|long
name|double
name|signaling_NaN
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|__builtin_nansl
argument_list|(
literal|""
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|long
name|double
name|denorm_min
parameter_list|()
function|throw
parameter_list|()
block|{
return|return
name|__LDBL_DENORM_MIN__
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_iec559
init|=
name|has_infinity
operator|&&
name|has_quiet_NaN
operator|&&
name|has_denorm
operator|==
name|denorm_present
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_bounded
init|=
name|true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|is_modulo
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|traps
init|=
name|__glibcxx_long_double_traps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|bool
name|tinyness_before
init|=
name|__glibcxx_long_double_tinyness_before
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|float_round_style
name|round_style
init|=
name|round_to_nearest
decl_stmt|;
end_decl_stmt

begin_undef
unit|};
undef|#
directive|undef
name|__glibcxx_long_double_has_denorm_loss
end_undef

begin_undef
undef|#
directive|undef
name|__glibcxx_long_double_traps
end_undef

begin_undef
undef|#
directive|undef
name|__glibcxx_long_double_tinyness_before
end_undef

begin_macro
name|_GLIBCXX_END_NAMESPACE
end_macro

begin_undef
undef|#
directive|undef
name|__glibcxx_signed
end_undef

begin_undef
undef|#
directive|undef
name|__glibcxx_min
end_undef

begin_undef
undef|#
directive|undef
name|__glibcxx_max
end_undef

begin_undef
undef|#
directive|undef
name|__glibcxx_digits
end_undef

begin_undef
undef|#
directive|undef
name|__glibcxx_digits10
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _GLIBCXX_NUMERIC_LIMITS
end_comment

end_unit

