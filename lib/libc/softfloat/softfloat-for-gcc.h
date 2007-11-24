begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: softfloat-for-gcc.h,v 1.6 2003/07/26 19:24:51 salo Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Move private identifiers with external linkage into implementation  * namespace.  -- Klaus Klein<kleink@NetBSD.org>, May 5, 1999  */
end_comment

begin_define
define|#
directive|define
name|float_exception_flags
value|_softfloat_float_exception_flags
end_define

begin_define
define|#
directive|define
name|float_exception_mask
value|_softfloat_float_exception_mask
end_define

begin_define
define|#
directive|define
name|float_rounding_mode
value|_softfloat_float_rounding_mode
end_define

begin_define
define|#
directive|define
name|float_raise
value|_softfloat_float_raise
end_define

begin_comment
comment|/* The following batch are called by GCC through wrappers */
end_comment

begin_define
define|#
directive|define
name|float32_eq
value|_softfloat_float32_eq
end_define

begin_define
define|#
directive|define
name|float32_le
value|_softfloat_float32_le
end_define

begin_define
define|#
directive|define
name|float32_lt
value|_softfloat_float32_lt
end_define

begin_define
define|#
directive|define
name|float64_eq
value|_softfloat_float64_eq
end_define

begin_define
define|#
directive|define
name|float64_le
value|_softfloat_float64_le
end_define

begin_define
define|#
directive|define
name|float64_lt
value|_softfloat_float64_lt
end_define

begin_comment
comment|/*  * Macros to define functions with the GCC expected names  */
end_comment

begin_define
define|#
directive|define
name|float32_add
value|__addsf3
end_define

begin_define
define|#
directive|define
name|float64_add
value|__adddf3
end_define

begin_define
define|#
directive|define
name|float32_sub
value|__subsf3
end_define

begin_define
define|#
directive|define
name|float64_sub
value|__subdf3
end_define

begin_define
define|#
directive|define
name|float32_mul
value|__mulsf3
end_define

begin_define
define|#
directive|define
name|float64_mul
value|__muldf3
end_define

begin_define
define|#
directive|define
name|float32_div
value|__divsf3
end_define

begin_define
define|#
directive|define
name|float64_div
value|__divdf3
end_define

begin_define
define|#
directive|define
name|int32_to_float32
value|__floatsisf
end_define

begin_define
define|#
directive|define
name|int32_to_float64
value|__floatsidf
end_define

begin_define
define|#
directive|define
name|int64_to_float32
value|__floatdisf
end_define

begin_define
define|#
directive|define
name|int64_to_float64
value|__floatdidf
end_define

begin_define
define|#
directive|define
name|float32_to_int32_round_to_zero
value|__fixsfsi
end_define

begin_define
define|#
directive|define
name|float64_to_int32_round_to_zero
value|__fixdfsi
end_define

begin_define
define|#
directive|define
name|float32_to_int64_round_to_zero
value|__fixsfdi
end_define

begin_define
define|#
directive|define
name|float64_to_int64_round_to_zero
value|__fixdfdi
end_define

begin_define
define|#
directive|define
name|float32_to_uint32_round_to_zero
value|__fixunssfsi
end_define

begin_define
define|#
directive|define
name|float64_to_uint32_round_to_zero
value|__fixunsdfsi
end_define

begin_define
define|#
directive|define
name|float32_to_float64
value|__extendsfdf2
end_define

begin_define
define|#
directive|define
name|float64_to_float32
value|__truncdfsf2
end_define

end_unit

