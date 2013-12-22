begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin9 -target-cpu corei7-avx -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin9 -target-cpu corei7-avx -emit-llvm -x c++ %s -o - | FileCheck %s
end_comment

begin_typedef
typedef|typedef
name|double
name|vector8double
name|__attribute__
typedef|((
name|__vector_size__
typedef|(64)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|vector8float
name|__attribute__
typedef|((
name|__vector_size__
typedef|(32)));
end_typedef

begin_typedef
typedef|typedef
name|long
name|vector8long
name|__attribute__
typedef|((
name|__vector_size__
typedef|(64)));
end_typedef

begin_typedef
typedef|typedef
name|short
name|vector8short
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|vector8ulong
name|__attribute__
typedef|((
name|__vector_size__
typedef|(64)));
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|vector8ushort
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|BOOL
value|bool
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BOOL
value|_Bool
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|BOOL
name|vector8bool
name|__attribute__
typedef|((
name|__ext_vector_type__
typedef|(8)));
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
name|vector8float
name|flt_trunc
parameter_list|(
name|vector8double
name|x
parameter_list|)
block|{
return|return
name|__builtin_convertvector
argument_list|(
name|x
argument_list|,
name|vector8float
argument_list|)
return|;
comment|// CHECK-LABEL: @flt_trunc
comment|// CHECK: fptrunc<8 x double> %{{[^ ]}} to<8 x float>
block|}
name|vector8double
name|flt_ext
parameter_list|(
name|vector8float
name|x
parameter_list|)
block|{
return|return
name|__builtin_convertvector
argument_list|(
name|x
argument_list|,
name|vector8double
argument_list|)
return|;
comment|// CHECK-LABEL: @flt_ext
comment|// CHECK: fpext<8 x float> %{{[^ ]}} to<8 x double>
block|}
name|vector8bool
name|flt_tobool
parameter_list|(
name|vector8float
name|x
parameter_list|)
block|{
return|return
name|__builtin_convertvector
argument_list|(
name|x
argument_list|,
name|vector8bool
argument_list|)
return|;
comment|// CHECK-LABEL: @flt_tobool
comment|// CHECK-NOT: fptoui<8 x float> %{{[^ ]}} to<8 x i1>
comment|// CHECK: fcmp une<8 x float> %{{[^ ]}}, zeroinitializer
block|}
name|vector8long
name|flt_tosi
parameter_list|(
name|vector8float
name|x
parameter_list|)
block|{
return|return
name|__builtin_convertvector
argument_list|(
name|x
argument_list|,
name|vector8long
argument_list|)
return|;
comment|// CHECK-LABEL: @flt_tosi
comment|// CHECK: fptosi<8 x float> %{{[^ ]}} to<8 x i64>
block|}
name|vector8ulong
name|flt_toui
parameter_list|(
name|vector8float
name|x
parameter_list|)
block|{
return|return
name|__builtin_convertvector
argument_list|(
name|x
argument_list|,
name|vector8ulong
argument_list|)
return|;
comment|// CHECK-LABEL: @flt_toui
comment|// CHECK: fptoui<8 x float> %{{[^ ]}} to<8 x i64>
block|}
name|vector8ulong
name|fltd_toui
parameter_list|(
name|vector8double
name|x
parameter_list|)
block|{
return|return
name|__builtin_convertvector
argument_list|(
name|x
argument_list|,
name|vector8ulong
argument_list|)
return|;
comment|// CHECK-LABEL: @fltd_toui
comment|// CHECK: fptoui<8 x double> %{{[^ ]}} to<8 x i64>
block|}
name|vector8ulong
name|int_zext
parameter_list|(
name|vector8ushort
name|x
parameter_list|)
block|{
return|return
name|__builtin_convertvector
argument_list|(
name|x
argument_list|,
name|vector8ulong
argument_list|)
return|;
comment|// CHECK-LABEL: @int_zext
comment|// CHECK: zext<8 x i16> %{{[^ ]}} to<8 x i64>
block|}
name|vector8long
name|int_sext
parameter_list|(
name|vector8short
name|x
parameter_list|)
block|{
return|return
name|__builtin_convertvector
argument_list|(
name|x
argument_list|,
name|vector8long
argument_list|)
return|;
comment|// CHECK-LABEL: @int_sext
comment|// CHECK: sext<8 x i16> %{{[^ ]}} to<8 x i64>
block|}
name|vector8bool
name|int_tobool
parameter_list|(
name|vector8short
name|x
parameter_list|)
block|{
return|return
name|__builtin_convertvector
argument_list|(
name|x
argument_list|,
name|vector8bool
argument_list|)
return|;
comment|// CHECK-LABEL: @int_tobool
comment|// CHECK-NOT: trunc<8 x i16> %{{[^ ]}} to<8 x i1>
comment|// CHECK: icmp ne<8 x i16> %{{[^ ]}}, zeroinitializer
block|}
name|vector8float
name|int_tofp
parameter_list|(
name|vector8short
name|x
parameter_list|)
block|{
return|return
name|__builtin_convertvector
argument_list|(
name|x
argument_list|,
name|vector8float
argument_list|)
return|;
comment|// CHECK-LABEL: @int_tofp
comment|// CHECK: sitofp<8 x i16> %{{[^ ]}} to<8 x float>
block|}
name|vector8float
name|uint_tofp
parameter_list|(
name|vector8ushort
name|x
parameter_list|)
block|{
return|return
name|__builtin_convertvector
argument_list|(
name|x
argument_list|,
name|vector8float
argument_list|)
return|;
comment|// CHECK-LABEL: @uint_tofp
comment|// CHECK: uitofp<8 x i16> %{{[^ ]}} to<8 x float>
block|}
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|int_toT
argument_list|(
argument|vector8long x
argument_list|)
block|{
return|return
name|__builtin_convertvector
argument_list|(
name|x
argument_list|,
name|T
argument_list|)
return|;
block|}
end_expr_stmt

begin_extern
extern|extern
literal|"C"
block|{
name|vector8double
name|int_toT_fp
parameter_list|(
name|vector8long
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: @int_toT_fp
comment|// CHECK: sitofp<8 x i64> %{{[^ ]}} to<8 x double>
return|return
name|int_toT
operator|<
name|vector8double
operator|>
operator|(
name|x
operator|)
return|;
block|}
block|}
end_extern

begin_else
else|#
directive|else
end_else

begin_function
name|vector8double
name|int_toT_fp
parameter_list|(
name|vector8long
name|x
parameter_list|)
block|{
return|return
name|__builtin_convertvector
argument_list|(
name|x
argument_list|,
name|vector8double
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

