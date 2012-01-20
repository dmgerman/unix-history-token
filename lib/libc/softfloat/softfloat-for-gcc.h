begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: softfloat-for-gcc.h,v 1.8 2009/12/14 01:07:42 matt Exp $ */
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
value|__softfloat_float_exception_flags
end_define

begin_define
define|#
directive|define
name|float_exception_mask
value|__softfloat_float_exception_mask
end_define

begin_define
define|#
directive|define
name|float_rounding_mode
value|__softfloat_float_rounding_mode
end_define

begin_define
define|#
directive|define
name|float_raise
value|__softfloat_float_raise
end_define

begin_comment
comment|/* The following batch are called by GCC through wrappers */
end_comment

begin_define
define|#
directive|define
name|float32_eq
value|__softfloat_float32_eq
end_define

begin_define
define|#
directive|define
name|float32_le
value|__softfloat_float32_le
end_define

begin_define
define|#
directive|define
name|float32_lt
value|__softfloat_float32_lt
end_define

begin_define
define|#
directive|define
name|float64_eq
value|__softfloat_float64_eq
end_define

begin_define
define|#
directive|define
name|float64_le
value|__softfloat_float64_le
end_define

begin_define
define|#
directive|define
name|float64_lt
value|__softfloat_float64_lt
end_define

begin_define
define|#
directive|define
name|float128_eq
value|__softfloat_float128_eq
end_define

begin_define
define|#
directive|define
name|float128_le
value|__softfloat_float128_le
end_define

begin_define
define|#
directive|define
name|float128_lt
value|__softfloat_float128_lt
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
name|floatx80_add
value|__addxf3
end_define

begin_define
define|#
directive|define
name|float128_add
value|__addtf3
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
name|floatx80_sub
value|__subxf3
end_define

begin_define
define|#
directive|define
name|float128_sub
value|__subtf3
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
name|floatx80_mul
value|__mulxf3
end_define

begin_define
define|#
directive|define
name|float128_mul
value|__multf3
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
name|floatx80_div
value|__divxf3
end_define

begin_define
define|#
directive|define
name|float128_div
value|__divtf3
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|float32_neg
value|__negsf2
end_define

begin_define
define|#
directive|define
name|float64_neg
value|__negdf2
end_define

begin_define
define|#
directive|define
name|floatx80_neg
value|__negxf2
end_define

begin_define
define|#
directive|define
name|float128_neg
value|__negtf2
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|int32_to_floatx80
value|__floatsixf
end_define

begin_define
define|#
directive|define
name|int32_to_float128
value|__floatsitf
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
name|int64_to_floatx80
value|__floatdixf
end_define

begin_define
define|#
directive|define
name|int64_to_float128
value|__floatditf
end_define

begin_define
define|#
directive|define
name|int128_to_float32
value|__floattisf
end_define

begin_define
define|#
directive|define
name|int128_to_float64
value|__floattidf
end_define

begin_define
define|#
directive|define
name|int128_to_floatx80
value|__floattixf
end_define

begin_define
define|#
directive|define
name|int128_to_float128
value|__floattitf
end_define

begin_define
define|#
directive|define
name|uint32_to_float32
value|__floatunsisf
end_define

begin_define
define|#
directive|define
name|uint32_to_float64
value|__floatunsidf
end_define

begin_define
define|#
directive|define
name|uint32_to_floatx80
value|__floatunsixf
end_define

begin_define
define|#
directive|define
name|uint32_to_float128
value|__floatunsitf
end_define

begin_define
define|#
directive|define
name|uint64_to_float32
value|__floatundisf
end_define

begin_define
define|#
directive|define
name|uint64_to_float64
value|__floatundidf
end_define

begin_define
define|#
directive|define
name|uint64_to_floatx80
value|__floatundixf
end_define

begin_define
define|#
directive|define
name|uint64_to_float128
value|__floatunditf
end_define

begin_define
define|#
directive|define
name|uint128_to_float32
value|__floatuntisf
end_define

begin_define
define|#
directive|define
name|uint128_to_float64
value|__floatuntidf
end_define

begin_define
define|#
directive|define
name|uint128_to_floatx80
value|__floatuntixf
end_define

begin_define
define|#
directive|define
name|uint128_to_float128
value|__floatuntitf
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
name|floatx80_to_int32_round_to_zero
value|__fixxfsi
end_define

begin_define
define|#
directive|define
name|float128_to_int32_round_to_zero
value|__fixtfsi
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
name|floatx80_to_int64_round_to_zero
value|__fixxfdi
end_define

begin_define
define|#
directive|define
name|float128_to_int64_round_to_zero
value|__fixtfdi
end_define

begin_define
define|#
directive|define
name|float32_to_int128_round_to_zero
value|__fixsfti
end_define

begin_define
define|#
directive|define
name|float64_to_int128_round_to_zero
value|__fixdfti
end_define

begin_define
define|#
directive|define
name|floatx80_to_int128_round_to_zero
value|__fixxfti
end_define

begin_define
define|#
directive|define
name|float128_to_int128_round_to_zero
value|__fixtfti
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
name|floatx80_to_uint32_round_to_zero
value|__fixunsxfsi
end_define

begin_define
define|#
directive|define
name|float128_to_uint32_round_to_zero
value|__fixunstfsi
end_define

begin_define
define|#
directive|define
name|float32_to_uint64_round_to_zero
value|__fixunssfdi
end_define

begin_define
define|#
directive|define
name|float64_to_uint64_round_to_zero
value|__fixunsdfdi
end_define

begin_define
define|#
directive|define
name|floatx80_to_uint64_round_to_zero
value|__fixunsxfdi
end_define

begin_define
define|#
directive|define
name|float128_to_uint64_round_to_zero
value|__fixunstfdi
end_define

begin_define
define|#
directive|define
name|float32_to_uint128_round_to_zero
value|__fixunssfti
end_define

begin_define
define|#
directive|define
name|float64_to_uint128_round_to_zero
value|__fixunsdfti
end_define

begin_define
define|#
directive|define
name|floatx80_to_uint128_round_to_zero
value|__fixunsxfti
end_define

begin_define
define|#
directive|define
name|float128_to_uint128_round_to_zero
value|__fixunstfti
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
name|float32_to_floatx80
value|__extendsfxf2
end_define

begin_define
define|#
directive|define
name|float32_to_float128
value|__extendsftf2
end_define

begin_define
define|#
directive|define
name|float64_to_floatx80
value|__extenddfxf2
end_define

begin_define
define|#
directive|define
name|float64_to_float128
value|__extenddftf2
end_define

begin_define
define|#
directive|define
name|float128_to_float64
value|__trunctfdf2
end_define

begin_define
define|#
directive|define
name|floatx80_to_float64
value|__truncxfdf2
end_define

begin_define
define|#
directive|define
name|float128_to_float32
value|__trunctfsf2
end_define

begin_define
define|#
directive|define
name|floatx80_to_float32
value|__truncxfsf2
end_define

begin_define
define|#
directive|define
name|float64_to_float32
value|__truncdfsf2
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|float32_cmp
value|__cmpsf2
end_define

begin_define
define|#
directive|define
name|float32_unord
value|__unordsf2
end_define

begin_define
define|#
directive|define
name|float32_eq
value|__eqsf2
end_define

begin_define
define|#
directive|define
name|float32_ne
value|__nesf2
end_define

begin_define
define|#
directive|define
name|float32_ge
value|__gesf2
end_define

begin_define
define|#
directive|define
name|float32_lt
value|__ltsf2
end_define

begin_define
define|#
directive|define
name|float32_le
value|__lesf2
end_define

begin_define
define|#
directive|define
name|float32_gt
value|__gtsf2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|float64_cmp
value|__cmpdf2
end_define

begin_define
define|#
directive|define
name|float64_unord
value|__unorddf2
end_define

begin_define
define|#
directive|define
name|float64_eq
value|__eqdf2
end_define

begin_define
define|#
directive|define
name|float64_ne
value|__nedf2
end_define

begin_define
define|#
directive|define
name|float64_ge
value|__gedf2
end_define

begin_define
define|#
directive|define
name|float64_lt
value|__ltdf2
end_define

begin_define
define|#
directive|define
name|float64_le
value|__ledf2
end_define

begin_define
define|#
directive|define
name|float64_gt
value|__gtdf2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XXX not in libgcc */
end_comment

begin_if
if|#
directive|if
literal|1
end_if

begin_define
define|#
directive|define
name|floatx80_cmp
value|__cmpxf2
end_define

begin_define
define|#
directive|define
name|floatx80_unord
value|__unordxf2
end_define

begin_define
define|#
directive|define
name|floatx80_eq
value|__eqxf2
end_define

begin_define
define|#
directive|define
name|floatx80_ne
value|__nexf2
end_define

begin_define
define|#
directive|define
name|floatx80_ge
value|__gexf2
end_define

begin_define
define|#
directive|define
name|floatx80_lt
value|__ltxf2
end_define

begin_define
define|#
directive|define
name|floatx80_le
value|__lexf2
end_define

begin_define
define|#
directive|define
name|floatx80_gt
value|__gtxf2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|float128_cmp
value|__cmptf2
end_define

begin_define
define|#
directive|define
name|float128_unord
value|__unordtf2
end_define

begin_define
define|#
directive|define
name|float128_eq
value|__eqtf2
end_define

begin_define
define|#
directive|define
name|float128_ne
value|__netf2
end_define

begin_define
define|#
directive|define
name|float128_ge
value|__getf2
end_define

begin_define
define|#
directive|define
name|float128_lt
value|__lttf2
end_define

begin_define
define|#
directive|define
name|float128_le
value|__letf2
end_define

begin_define
define|#
directive|define
name|float128_gt
value|__gttf2
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

