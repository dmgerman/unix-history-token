begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1990 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gxfixed.h */
end_comment

begin_comment
comment|/* Fixed-point arithmetic for GhostScript */
end_comment

begin_comment
comment|/*  * Coordinates are generally represented internally by fixed-point  * quantities: integers lose accuracy in crucial places,  * and floating point arithmetic is slow.  */
end_comment

begin_typedef
typedef|typedef
name|long
name|fixed
typedef|;
end_typedef

begin_define
define|#
directive|define
name|max_fixed
value|0x7fffffffL
end_define

begin_define
define|#
directive|define
name|min_fixed
value|(~max_fixed)
end_define

begin_comment
comment|/*  * 12 bits of fraction provides both the necessary accuracy and  * a sufficiently large range of coordinates.  */
end_comment

begin_define
define|#
directive|define
name|_fixed_shift
value|12
end_define

begin_define
define|#
directive|define
name|_fixed_scale
value|(1<<_fixed_shift)
end_define

begin_define
define|#
directive|define
name|_fixed_rshift
parameter_list|(
name|x
parameter_list|)
value|arith_rshift(x,_fixed_shift)
end_define

begin_define
define|#
directive|define
name|_fixed_round_v
value|(_fixed_scale>>1)
end_define

begin_define
define|#
directive|define
name|_fixed_fraction_v
value|(_fixed_scale-1)
end_define

begin_comment
comment|/*  * Most operations can be done directly on fixed-point quantities:  * addition, subtraction, shifting, multiplication or division by  * (integer) constants; assignment, assignment with zero;  * comparison, comparison against zero.  * Multiplication and division by floats is OK if the result is  * explicitly cast back to fixed.  * Conversion to and from int and float types must be done explicitly.  * Note that if we are casting a fixed to a float in a context where  * only ratios and not actual values are involved, we don't need to take  * the scale factor into account: we can simply cast to float directly.  */
end_comment

begin_define
define|#
directive|define
name|int2fixed
parameter_list|(
name|i
parameter_list|)
value|((fixed)(i)<<_fixed_shift)
end_define

begin_comment
comment|/* Define some useful constants. */
end_comment

begin_define
define|#
directive|define
name|fixed_0
value|int2fixed(0)
end_define

begin_define
define|#
directive|define
name|fixed_1
value|int2fixed(1)
end_define

begin_comment
comment|/*  * On 16-bit systems, we can convert fixed variables to ints more efficiently  * than general fixed quantities.  For this reason, we define two separate  * sets of conversion macros.  */
end_comment

begin_define
define|#
directive|define
name|fixed2int
parameter_list|(
name|x
parameter_list|)
value|((int)_fixed_rshift(x))
end_define

begin_define
define|#
directive|define
name|fixed2int_rounded
parameter_list|(
name|x
parameter_list|)
value|((int)_fixed_rshift((x)+_fixed_round_v))
end_define

begin_define
define|#
directive|define
name|fixed2int_ceiling
parameter_list|(
name|x
parameter_list|)
value|((int)_fixed_rshift((x)+_fixed_fraction_v))
end_define

begin_if
if|#
directive|if
name|arch_ints_are_short
operator|&
operator|!
name|arch_is_big_endian
end_if

begin_comment
comment|/* Do some of the shifting and extraction ourselves. */
end_comment

begin_define
define|#
directive|define
name|_fixed_hi
parameter_list|(
name|x
parameter_list|)
value|*((uint *)&(x)+1)
end_define

begin_define
define|#
directive|define
name|_fixed_lo
parameter_list|(
name|x
parameter_list|)
value|*((uint *)&(x))
end_define

begin_define
define|#
directive|define
name|fixed2int_var
parameter_list|(
name|x
parameter_list|)
define|\
value|((int)((_fixed_hi(x)<< (16-_fixed_shift)) +\ 	       (_fixed_lo(x)>> _fixed_shift)))
end_define

begin_define
define|#
directive|define
name|fixed2int_var_rounded
parameter_list|(
name|x
parameter_list|)
define|\
value|((int)((_fixed_hi(x)<< (16-_fixed_shift)) +\ 	       (((_fixed_lo(x)>> (_fixed_shift-1))+1)>>1)))
end_define

begin_define
define|#
directive|define
name|fixed2int_var_ceiling
parameter_list|(
name|x
parameter_list|)
define|\
value|(fixed2int_var(x) -\ 	 arith_rshift((int)-(_fixed_lo(x)& _fixed_fraction_v), _fixed_shift))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Use reasonable definitions. */
end_comment

begin_define
define|#
directive|define
name|fixed2int_var
parameter_list|(
name|x
parameter_list|)
value|fixed2int(x)
end_define

begin_define
define|#
directive|define
name|fixed2int_var_rounded
parameter_list|(
name|x
parameter_list|)
value|fixed2int_rounded(x)
end_define

begin_define
define|#
directive|define
name|fixed2int_var_ceiling
parameter_list|(
name|x
parameter_list|)
value|fixed2int_ceiling(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|fixed2long
parameter_list|(
name|x
parameter_list|)
value|((long)_fixed_rshift(x))
end_define

begin_define
define|#
directive|define
name|fixed2long_rounded
parameter_list|(
name|x
parameter_list|)
value|((long)_fixed_rshift((x)+_fixed_round_v))
end_define

begin_define
define|#
directive|define
name|fixed2long_ceiling
parameter_list|(
name|x
parameter_list|)
value|((long)_fixed_rshift((x)+_fixed_fraction_v))
end_define

begin_define
define|#
directive|define
name|float2fixed
parameter_list|(
name|f
parameter_list|)
value|((fixed)((f)*(float)_fixed_scale))
end_define

begin_define
define|#
directive|define
name|fixed2float
parameter_list|(
name|x
parameter_list|)
value|((float)((x)*(1.0/_fixed_scale)))
end_define

begin_comment
comment|/* Rounding and truncation on fixeds */
end_comment

begin_define
define|#
directive|define
name|fixed_truncated
parameter_list|(
name|x
parameter_list|)
value|((x)&(-1L<<_fixed_shift))
end_define

begin_define
define|#
directive|define
name|fixed_rounded
parameter_list|(
name|x
parameter_list|)
value|(((x)+_fixed_round_v)&(-1L<<_fixed_shift))
end_define

begin_define
define|#
directive|define
name|fixed_ceiling
parameter_list|(
name|x
parameter_list|)
value|(((x)+_fixed_fraction_v)&(-1L<<_fixed_shift))
end_define

begin_define
define|#
directive|define
name|fixed_fraction
parameter_list|(
name|x
parameter_list|)
value|((x)&_fixed_fraction_v)
end_define

begin_comment
comment|/* A point with fixed coordinates */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|gs_fixed_point_s
block|{
name|fixed
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
name|gs_fixed_point
typedef|;
end_typedef

begin_comment
comment|/* A rectangle with fixed coordinates */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|gs_fixed_rect_s
block|{
name|gs_fixed_point
name|p
decl_stmt|,
name|q
decl_stmt|;
block|}
name|gs_fixed_rect
typedef|;
end_typedef

end_unit

