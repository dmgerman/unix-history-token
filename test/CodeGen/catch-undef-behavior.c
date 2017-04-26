begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsanitize=alignment,null,object-size,shift-base,shift-exponent,return,signed-integer-overflow,vla-bound,float-cast-overflow,integer-divide-by-zero,bool,returns-nonnull-attribute,nonnull-attribute -fsanitize-recover=alignment,null,object-size,shift-base,shift-exponent,signed-integer-overflow,vla-bound,float-cast-overflow,integer-divide-by-zero,bool,returns-nonnull-attribute,nonnull-attribute -emit-llvm %s -o - -triple x86_64-linux-gnu | opt -instnamer -S | FileCheck %s --check-prefix=CHECK-COMMON --check-prefix=CHECK-UBSAN
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsanitize-trap=alignment,null,object-size,shift-base,shift-exponent,return,signed-integer-overflow,vla-bound,float-cast-overflow,integer-divide-by-zero,bool,returns-nonnull-attribute,nonnull-attribute -fsanitize-recover=alignment,null,object-size,shift-base,shift-exponent,signed-integer-overflow,vla-bound,float-cast-overflow,integer-divide-by-zero,bool,returns-nonnull-attribute,nonnull-attribute -fsanitize=alignment,null,object-size,shift-base,shift-exponent,return,signed-integer-overflow,vla-bound,float-cast-overflow,integer-divide-by-zero,bool,returns-nonnull-attribute,nonnull-attribute -fsanitize-recover=alignment,null,object-size,shift-base,shift-exponent,signed-integer-overflow,vla-bound,float-cast-overflow,integer-divide-by-zero,bool,returns-nonnull-attribute,nonnull-attribute -emit-llvm %s -o - -triple x86_64-linux-gnu | opt -instnamer -S | FileCheck %s --check-prefix=CHECK-COMMON --check-prefix=CHECK-TRAP
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsanitize=signed-integer-overflow -emit-llvm %s -o - -triple x86_64-linux-gnu | FileCheck %s --check-prefix=CHECK-OVERFLOW
end_comment

begin_comment
comment|// CHECK-UBSAN: @[[INT:.*]] = private unnamed_addr constant { i16, i16, [6 x i8] } { i16 0, i16 11, [6 x i8] c"'int'\00" }
end_comment

begin_comment
comment|// FIXME: When we only emit each type once, use [[INT]] more below.
end_comment

begin_comment
comment|// CHECK-UBSAN: @[[LINE_100:.*]] = private unnamed_addr global {{.*}}, i32 100, i32 5 {{.*}} @[[INT]], i8 2, i8 1
end_comment

begin_comment
comment|// CHECK-UBSAN: @[[LINE_200:.*]] = {{.*}}, i32 200, i32 10 {{.*}}, i8 2, i8 0
end_comment

begin_comment
comment|// CHECK-UBSAN: @[[LINE_300:.*]] = {{.*}}, i32 300, i32 12 {{.*}} @{{.*}}, {{.*}} @{{.*}}
end_comment

begin_comment
comment|// CHECK-UBSAN: @[[LINE_400:.*]] = {{.*}}, i32 400, i32 12 {{.*}} @{{.*}}, {{.*}} @{{.*}}
end_comment

begin_comment
comment|// CHECK-UBSAN: @[[LINE_500:.*]] = {{.*}}, i32 500, i32 10 {{.*}} @{{.*}}, i8 2, i8 0 }
end_comment

begin_comment
comment|// CHECK-UBSAN: @[[LINE_600:.*]] = {{.*}}, i32 600, i32 3 {{.*}} @{{.*}}, i8 2, i8 1 }
end_comment

begin_comment
comment|// CHECK-UBSAN: @[[STRUCT_S:.*]] = private unnamed_addr constant { i16, i16, [11 x i8] } { i16 -1, i16 0, [11 x i8] c"'struct S'\00" }
end_comment

begin_comment
comment|// CHECK-UBSAN: @[[LINE_700:.*]] = {{.*}}, i32 700, i32 14 {{.*}} @[[STRUCT_S]], i8 2, i8 3 }
end_comment

begin_comment
comment|// CHECK-UBSAN: @[[LINE_800:.*]] = {{.*}}, i32 800, i32 12 {{.*}} @{{.*}} }
end_comment

begin_comment
comment|// CHECK-UBSAN: @[[LINE_900:.*]] = {{.*}}, i32 900, i32 11 {{.*}} @{{.*}} }
end_comment

begin_comment
comment|// CHECK-UBSAN: @[[LINE_1000:.*]] = {{.*}}, i32 1000, i32 10 {{.*}} @{{.*}} }
end_comment

begin_comment
comment|// CHECK-UBSAN: @[[FP16:.*]] = private unnamed_addr constant { i16, i16, [9 x i8] } { i16 1, i16 16, [9 x i8] c"'__fp16'\00" }
end_comment

begin_comment
comment|// CHECK-UBSAN: @[[LINE_1100:.*]] = {{.*}}, i32 1100, i32 8 {{.*}} @{{.*}} }
end_comment

begin_comment
comment|// CHECK-UBSAN: @[[LINE_1200:.*]] = {{.*}}, i32 1200, i32 10 {{.*}} @{{.*}} }
end_comment

begin_comment
comment|// CHECK-UBSAN: @[[LINE_1300:.*]] = {{.*}}, i32 1300, i32 10 {{.*}} @{{.*}} }
end_comment

begin_comment
comment|// CHECK-UBSAN: @[[LINE_1400:.*]] = {{.*}}, i32 1400, i32 10 {{.*}} @{{.*}} }
end_comment

begin_comment
comment|// Make sure we check the fp16 type_mismatch data so we can easily match the signed char float_cast_overflow
end_comment

begin_comment
comment|// CHECK-UBSAN: @[[LINE_1500:.*]] = {{.*}}, i32 1500, i32 10 {{.*}} @[[FP16]], {{.*}} }
end_comment

begin_comment
comment|// CHECK-UBSAN: @[[SCHAR:.*]] = private unnamed_addr constant { i16, i16, [14 x i8] } { i16 0, i16 7, [14 x i8] c"'signed char'\00" }
end_comment

begin_comment
comment|// CHECK-UBSAN: @[[LINE_1500:.*]] = {{.*}}, i32 1500, i32 10 {{.*}} @[[FP16]], {{.*}} }
end_comment

begin_comment
comment|// CHECK-UBSAN: @[[LINE_1600:.*]] = {{.*}}, i32 1600, i32 10 {{.*}} @{{.*}} }
end_comment

begin_comment
comment|// PR6805
end_comment

begin_comment
comment|// CHECK-COMMON-LABEL: @foo
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
union|union
block|{
name|int
name|i
decl_stmt|;
block|}
name|u
union|;
comment|// CHECK-COMMON:      %[[I8PTR:.*]] = bitcast i32* %[[PTR:.*]] to i8*
comment|// CHECK-COMMON-NEXT: %[[SIZE:.*]] = call i64 @llvm.objectsize.i64.p0i8(i8* %[[I8PTR]], i1 false, i1 false)
comment|// CHECK-COMMON-NEXT: %[[OK:.*]] = icmp uge i64 %[[SIZE]], 4
comment|// CHECK-UBSAN: br i1 %[[OK]], {{.*}} !prof ![[WEIGHT_MD:.*]], !nosanitize
comment|// CHECK-TRAP:  br i1 %[[OK]], {{.*}}
comment|// CHECK-UBSAN:      %[[ARG:.*]] = ptrtoint {{.*}} %[[PTR]] to i64
comment|// CHECK-UBSAN-NEXT: call void @__ubsan_handle_type_mismatch_v1(i8* bitcast ({{.*}} @[[LINE_100]] to i8*), i64 %[[ARG]])
comment|// CHECK-TRAP:      call void @llvm.trap() [[NR_NUW:#[0-9]+]]
comment|// CHECK-TRAP-NEXT: unreachable
line|#
directive|line
number|100
name|u
operator|.
name|i
operator|=
literal|1
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-COMMON-LABEL: @bar
end_comment

begin_function
name|int
name|bar
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON:      %[[SIZE:.*]] = call i64 @llvm.objectsize.i64
comment|// CHECK-COMMON-NEXT: icmp uge i64 %[[SIZE]], 4
comment|// CHECK-COMMON:      %[[PTRINT:.*]] = ptrtoint
comment|// CHECK-COMMON-NEXT: %[[MISALIGN:.*]] = and i64 %[[PTRINT]], 3
comment|// CHECK-COMMON-NEXT: icmp eq i64 %[[MISALIGN]], 0
comment|// CHECK-UBSAN:      %[[ARG:.*]] = ptrtoint
comment|// CHECK-UBSAN-NEXT: call void @__ubsan_handle_type_mismatch_v1(i8* bitcast ({{.*}} @[[LINE_200]] to i8*), i64 %[[ARG]])
comment|// CHECK-TRAP:      call void @llvm.trap() [[NR_NUW]]
comment|// CHECK-TRAP-NEXT: unreachable
line|#
directive|line
number|200
return|return
operator|*
name|a
return|;
block|}
end_function

begin_comment
comment|// CHECK-UBSAN-LABEL: @addr_space
end_comment

begin_decl_stmt
name|int
name|addr_space
argument_list|(
name|int
name|__attribute__
argument_list|(
operator|(
name|address_space
argument_list|(
literal|256
argument_list|)
operator|)
argument_list|)
operator|*
name|a
argument_list|)
block|{
comment|// CHECK-UBSAN-NOT: __ubsan
return|return
operator|*
name|a
return|;
block|}
end_decl_stmt

begin_comment
comment|// CHECK-COMMON-LABEL: @lsh_overflow
end_comment

begin_function
name|int
name|lsh_overflow
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
comment|// CHECK-COMMON:      %[[RHS_INBOUNDS:.*]] = icmp ule i32 %[[RHS:.*]], 31
comment|// CHECK-COMMON-NEXT: br i1 %[[RHS_INBOUNDS]], label %[[CHECK_BB:.*]], label %[[CONT_BB:.*]],
comment|// CHECK-COMMON:      [[CHECK_BB]]:
comment|// CHECK-COMMON-NEXT: %[[SHIFTED_OUT_WIDTH:.*]] = sub nuw nsw i32 31, %[[RHS]]
comment|// CHECK-COMMON-NEXT: %[[SHIFTED_OUT:.*]] = lshr i32 %[[LHS:.*]], %[[SHIFTED_OUT_WIDTH]]
comment|// CHECK-COMMON-NEXT: %[[NO_OVERFLOW:.*]] = icmp eq i32 %[[SHIFTED_OUT]], 0
comment|// CHECK-COMMON-NEXT: br label %[[CONT_BB]]
comment|// CHECK-COMMON:      [[CONT_BB]]:
comment|// CHECK-COMMON-NEXT: %[[VALID_BASE:.*]] = phi i1 [ true, {{.*}} ], [ %[[NO_OVERFLOW]], %[[CHECK_BB]] ]
comment|// CHECK-COMMON-NEXT: %[[VALID:.*]] = and i1 %[[RHS_INBOUNDS]], %[[VALID_BASE]]
comment|// CHECK-UBSAN: br i1 %[[VALID]], {{.*}} !prof ![[WEIGHT_MD]]
comment|// CHECK-TRAP:  br i1 %[[VALID]]
comment|// CHECK-UBSAN:      %[[ARG1:.*]] = zext
comment|// CHECK-UBSAN-NEXT: %[[ARG2:.*]] = zext
comment|// CHECK-UBSAN-NEXT: call void @__ubsan_handle_shift_out_of_bounds(i8* bitcast ({{.*}} @[[LINE_300]] to i8*), i64 %[[ARG1]], i64 %[[ARG2]])
comment|// CHECK-UBSAN-NOT:  call void @__ubsan_handle_shift_out_of_bounds
comment|// CHECK-TRAP:      call void @llvm.trap() [[NR_NUW]]
comment|// CHECK-TRAP:      unreachable
comment|// CHECK-TRAP-NOT:  call void @llvm.trap()
comment|// CHECK-COMMON:      %[[RET:.*]] = shl i32 %[[LHS]], %[[RHS]]
comment|// CHECK-COMMON-NEXT: ret i32 %[[RET]]
line|#
directive|line
number|300
return|return
name|a
operator|<<
name|b
return|;
block|}
end_function

begin_comment
comment|// CHECK-COMMON-LABEL: @rsh_inbounds
end_comment

begin_function
name|int
name|rsh_inbounds
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
comment|// CHECK-COMMON:      %[[INBOUNDS:.*]] = icmp ule i32 %[[RHS:.*]], 31
comment|// CHECK-COMMON:      br i1 %[[INBOUNDS]]
comment|// CHECK-UBSAN:      %[[ARG1:.*]] = zext
comment|// CHECK-UBSAN-NEXT: %[[ARG2:.*]] = zext
comment|// CHECK-UBSAN-NEXT: call void @__ubsan_handle_shift_out_of_bounds(i8* bitcast ({{.*}} @[[LINE_400]] to i8*), i64 %[[ARG1]], i64 %[[ARG2]])
comment|// CHECK-TRAP:      call void @llvm.trap() [[NR_NUW]]
comment|// CHECK-TRAP-NEXT: unreachable
comment|// CHECK-COMMON:      %[[RET:.*]] = ashr i32 {{.*}}, %[[RHS]]
comment|// CHECK-COMMON-NEXT: ret i32 %[[RET]]
line|#
directive|line
number|400
return|return
name|a
operator|>>
name|b
return|;
block|}
end_function

begin_comment
comment|// CHECK-COMMON-LABEL: @load
end_comment

begin_function
name|int
name|load
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK-UBSAN: call void @__ubsan_handle_type_mismatch_v1(i8* bitcast ({{.*}} @[[LINE_500]] to i8*), i64 %{{.*}})
comment|// CHECK-TRAP:      call void @llvm.trap() [[NR_NUW]]
comment|// CHECK-TRAP-NEXT: unreachable
line|#
directive|line
number|500
return|return
operator|*
name|p
return|;
block|}
end_function

begin_comment
comment|// CHECK-COMMON-LABEL: @store
end_comment

begin_function
name|void
name|store
parameter_list|(
name|int
modifier|*
name|p
parameter_list|,
name|int
name|q
parameter_list|)
block|{
comment|// CHECK-UBSAN: call void @__ubsan_handle_type_mismatch_v1(i8* bitcast ({{.*}} @[[LINE_600]] to i8*), i64 %{{.*}})
comment|// CHECK-TRAP:      call void @llvm.trap() [[NR_NUW]]
comment|// CHECK-TRAP-NEXT: unreachable
line|#
directive|line
number|600
operator|*
name|p
operator|=
name|q
expr_stmt|;
block|}
end_function

begin_struct
struct|struct
name|S
block|{
name|int
name|k
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// CHECK-COMMON-LABEL: @member_access
end_comment

begin_function
name|int
modifier|*
name|member_access
parameter_list|(
name|struct
name|S
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK-UBSAN: call void @__ubsan_handle_type_mismatch_v1(i8* bitcast ({{.*}} @[[LINE_700]] to i8*), i64 %{{.*}})
comment|// CHECK-TRAP:      call void @llvm.trap() [[NR_NUW]]
comment|// CHECK-TRAP-NEXT: unreachable
line|#
directive|line
number|700
return|return
operator|&
name|p
operator|->
name|k
return|;
block|}
end_function

begin_comment
comment|// CHECK-COMMON-LABEL: @signed_overflow
end_comment

begin_function
name|int
name|signed_overflow
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
comment|// CHECK-UBSAN:      %[[ARG1:.*]] = zext
comment|// CHECK-UBSAN-NEXT: %[[ARG2:.*]] = zext
comment|// CHECK-UBSAN-NEXT: call void @__ubsan_handle_add_overflow(i8* bitcast ({{.*}} @[[LINE_800]] to i8*), i64 %[[ARG1]], i64 %[[ARG2]])
comment|// CHECK-TRAP:      call void @llvm.trap() [[NR_NUW]]
comment|// CHECK-TRAP-NEXT: unreachable
line|#
directive|line
number|800
return|return
name|a
operator|+
name|b
return|;
block|}
end_function

begin_comment
comment|// CHECK-COMMON-LABEL: @no_return
end_comment

begin_function
name|int
name|no_return
parameter_list|()
block|{
comment|// Reaching the end of a noreturn function is fine in C.
comment|// FIXME: If the user explicitly requests -fsanitize=return, we should catch
comment|//        that here even though it's not undefined behavior.
comment|// CHECK-COMMON-NOT: call
comment|// CHECK-COMMON-NOT: unreachable
comment|// CHECK-COMMON: ret i32
block|}
end_function

begin_comment
comment|// CHECK-UBSAN-LABEL: @vla_bound
end_comment

begin_function
name|void
name|vla_bound
parameter_list|(
name|int
name|n
parameter_list|)
block|{
comment|// CHECK-UBSAN:      icmp sgt i32 %[[PARAM:.*]], 0
comment|//
comment|// CHECK-UBSAN:      %[[ARG:.*]] = zext i32 %[[PARAM]] to i64
comment|// CHECK-UBSAN-NEXT: call void @__ubsan_handle_vla_bound_not_positive(i8* bitcast ({{.*}} @[[LINE_900]] to i8*), i64 %[[ARG]])
line|#
directive|line
number|900
name|int
name|arr
index|[
name|n
operator|*
literal|3
index|]
decl_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-UBSAN-LABEL: @int_float_no_overflow
end_comment

begin_function
name|float
name|int_float_no_overflow
parameter_list|(
name|__int128
name|n
parameter_list|)
block|{
comment|// CHECK-UBSAN-NOT: call void @__ubsan_handle
return|return
name|n
return|;
block|}
end_function

begin_comment
comment|// CHECK-COMMON-LABEL: @int_float_overflow
end_comment

begin_function
name|float
name|int_float_overflow
parameter_list|(
name|unsigned
name|__int128
name|n
parameter_list|)
block|{
comment|// This is 2**104. FLT_MAX is 2**128 - 2**104.
comment|// CHECK-COMMON: %[[INBOUNDS:.*]] = icmp ule i128 %{{.*}}, -20282409603651670423947251286016
comment|// CHECK-COMMON-NEXT: br i1 %[[INBOUNDS]]
comment|// CHECK-UBSAN: call void @__ubsan_handle_float_cast_overflow(i8* bitcast ({{.*}} @[[LINE_1000]] to i8*),
comment|// CHECK-TRAP:      call void @llvm.trap() [[NR_NUW]]
comment|// CHECK-TRAP-NEXT: unreachable
line|#
directive|line
number|1000
return|return
name|n
return|;
block|}
end_function

begin_comment
comment|// CHECK-COMMON-LABEL: @int_fp16_overflow
end_comment

begin_function
name|void
name|int_fp16_overflow
parameter_list|(
name|int
name|n
parameter_list|,
name|__fp16
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK-COMMON: %[[GE:.*]] = icmp sge i32 %{{.*}}, -65504
comment|// CHECK-COMMON: %[[LE:.*]] = icmp sle i32 %{{.*}}, 65504
comment|// CHECK-COMMON: %[[INBOUNDS:.*]] = and i1 %[[GE]], %[[LE]]
comment|// CHECK-COMMON-NEXT: br i1 %[[INBOUNDS]]
comment|// CHECK-UBSAN: call void @__ubsan_handle_float_cast_overflow(i8* bitcast ({{.*}} @[[LINE_1100]] to i8*),
comment|// CHECK-TRAP:      call void @llvm.trap() [[NR_NUW]]
comment|// CHECK-TRAP-NEXT: unreachable
line|#
directive|line
number|1100
operator|*
name|p
operator|=
name|n
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-COMMON-LABEL: @float_int_overflow
end_comment

begin_function
name|int
name|float_int_overflow
parameter_list|(
name|float
name|f
parameter_list|)
block|{
comment|// CHECK-COMMON: %[[GE:.*]] = fcmp ogt float %[[F:.*]], 0xC1E0000020000000
comment|// CHECK-COMMON: %[[LE:.*]] = fcmp olt float %[[F]], 0x41E0000000000000
comment|// CHECK-COMMON: %[[INBOUNDS:.*]] = and i1 %[[GE]], %[[LE]]
comment|// CHECK-COMMON-NEXT: br i1 %[[INBOUNDS]]
comment|// CHECK-UBSAN: %[[CAST:.*]] = bitcast float %[[F]] to i32
comment|// CHECK-UBSAN: %[[ARG:.*]] = zext i32 %[[CAST]] to i64
comment|// CHECK-UBSAN: call void @__ubsan_handle_float_cast_overflow(i8* bitcast ({{.*}} @[[LINE_1200]] to i8*), i64 %[[ARG]]
comment|// CHECK-TRAP:      call void @llvm.trap() [[NR_NUW]]
comment|// CHECK-TRAP-NEXT: unreachable
line|#
directive|line
number|1200
return|return
name|f
return|;
block|}
end_function

begin_comment
comment|// CHECK-COMMON-LABEL: @long_double_int_overflow
end_comment

begin_function
name|int
name|long_double_int_overflow
parameter_list|(
name|long
name|double
name|ld
parameter_list|)
block|{
comment|// CHECK-UBSAN: alloca x86_fp80
comment|// CHECK-COMMON: %[[GE:.*]] = fcmp ogt x86_fp80 %[[F:.*]], 0xKC01E800000010000000
comment|// CHECK-COMMON: %[[LE:.*]] = fcmp olt x86_fp80 %[[F]], 0xK401E800000000000000
comment|// CHECK-COMMON: %[[INBOUNDS:.*]] = and i1 %[[GE]], %[[LE]]
comment|// CHECK-COMMON-NEXT: br i1 %[[INBOUNDS]]
comment|// CHECK-UBSAN: store x86_fp80 %[[F]], x86_fp80* %[[ALLOCA:.*]], align 16, !nosanitize
comment|// CHECK-UBSAN: %[[ARG:.*]] = ptrtoint x86_fp80* %[[ALLOCA]] to i64
comment|// CHECK-UBSAN: call void @__ubsan_handle_float_cast_overflow(i8* bitcast ({{.*}} @[[LINE_1300]] to i8*), i64 %[[ARG]]
comment|// CHECK-TRAP:      call void @llvm.trap() [[NR_NUW]]
comment|// CHECK-TRAP-NEXT: unreachable
line|#
directive|line
number|1300
return|return
name|ld
return|;
block|}
end_function

begin_comment
comment|// CHECK-COMMON-LABEL: @float_uint_overflow
end_comment

begin_function
name|unsigned
name|float_uint_overflow
parameter_list|(
name|float
name|f
parameter_list|)
block|{
comment|// CHECK-COMMON: %[[GE:.*]] = fcmp ogt float %[[F:.*]], -1.{{0*}}e+00
comment|// CHECK-COMMON: %[[LE:.*]] = fcmp olt float %[[F]], 0x41F0000000000000
comment|// CHECK-COMMON: %[[INBOUNDS:.*]] = and i1 %[[GE]], %[[LE]]
comment|// CHECK-COMMON-NEXT: br i1 %[[INBOUNDS]]
comment|// CHECK-UBSAN: call void @__ubsan_handle_float_cast_overflow(i8* bitcast ({{.*}} @[[LINE_1400]] to i8*),
comment|// CHECK-TRAP:      call void @llvm.trap() [[NR_NUW]]
comment|// CHECK-TRAP-NEXT: unreachable
line|#
directive|line
number|1400
return|return
name|f
return|;
block|}
end_function

begin_comment
comment|// CHECK-COMMON-LABEL: @fp16_char_overflow
end_comment

begin_function
name|signed
name|char
name|fp16_char_overflow
parameter_list|(
name|__fp16
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK-COMMON: %[[GE:.*]] = fcmp ogt float %[[F:.*]], -1.29{{0*}}e+02
comment|// CHECK-COMMON: %[[LE:.*]] = fcmp olt float %[[F]], 1.28{{0*}}e+02
comment|// CHECK-COMMON: %[[INBOUNDS:.*]] = and i1 %[[GE]], %[[LE]]
comment|// CHECK-COMMON-NEXT: br i1 %[[INBOUNDS]]
comment|// CHECK-UBSAN: call void @__ubsan_handle_float_cast_overflow(i8* bitcast ({{.*}} @[[LINE_1500]] to i8*),
comment|// CHECK-TRAP:      call void @llvm.trap() [[NR_NUW]]
comment|// CHECK-TRAP-NEXT: unreachable
line|#
directive|line
number|1500
return|return
operator|*
name|p
return|;
block|}
end_function

begin_comment
comment|// CHECK-COMMON-LABEL: @float_float_overflow
end_comment

begin_function
name|float
name|float_float_overflow
parameter_list|(
name|double
name|f
parameter_list|)
block|{
comment|// CHECK-COMMON: %[[F:.*]] = call double @llvm.fabs.f64(
comment|// CHECK-COMMON: %[[GE:.*]] = fcmp ogt double %[[F]], 0x47EFFFFFE0000000
comment|// CHECK-COMMON: %[[LE:.*]] = fcmp olt double %[[F]], 0x7FF0000000000000
comment|// CHECK-COMMON: %[[OUTOFBOUNDS:.*]] = and i1 %[[GE]], %[[LE]]
comment|// CHECK-COMMON: %[[INBOUNDS:.*]] = xor i1 %[[OUTOFBOUNDS]], true
comment|// CHECK-COMMON-NEXT: br i1 %[[INBOUNDS]]
comment|// CHECK-UBSAN: call void @__ubsan_handle_float_cast_overflow(i8* bitcast ({{.*}} @[[LINE_1600]] to i8*),
comment|// CHECK-TRAP:      call void @llvm.trap() [[NR_NUW]]
comment|// CHECK-TRAP-NEXT: unreachable
line|#
directive|line
number|1600
return|return
name|f
return|;
block|}
end_function

begin_comment
comment|// CHECK-COMMON-LABEL:   @int_divide_overflow
end_comment

begin_comment
comment|// CHECK-OVERFLOW-LABEL: @int_divide_overflow
end_comment

begin_function
name|int
name|int_divide_overflow
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
comment|// CHECK-COMMON:         %[[ZERO:.*]] = icmp ne i32 %[[B:.*]], 0
comment|// CHECK-OVERFLOW-NOT:  icmp ne i32 %{{.*}}, 0
comment|// CHECK-COMMON:               %[[AOK:.*]] = icmp ne i32 %[[A:.*]], -2147483648
comment|// CHECK-COMMON-NEXT:          %[[BOK:.*]] = icmp ne i32 %[[B]], -1
comment|// CHECK-COMMON-NEXT:          %[[OVER:.*]] = or i1 %[[AOK]], %[[BOK]]
comment|// CHECK-COMMON:         %[[OK:.*]] = and i1 %[[ZERO]], %[[OVER]]
comment|// CHECK-COMMON:         br i1 %[[OK]]
comment|// CHECK-OVERFLOW:      %[[AOK:.*]] = icmp ne i32 %[[A:.*]], -2147483648
comment|// CHECK-OVERFLOW-NEXT: %[[BOK:.*]] = icmp ne i32 %[[B:.*]], -1
comment|// CHECK-OVERFLOW-NEXT: %[[OK:.*]] = or i1 %[[AOK]], %[[BOK]]
comment|// CHECK-OVERFLOW:      br i1 %[[OK]]
comment|// CHECK-TRAP: call void @llvm.trap() [[NR_NUW]]
comment|// CHECK-TRAP: unreachable
return|return
name|a
operator|/
name|b
return|;
comment|// CHECK-COMMON:          }
comment|// CHECK-OVERFLOW: }
block|}
end_function

begin_comment
comment|// CHECK-COMMON-LABEL: @sour_bool
end_comment

begin_function
name|_Bool
name|sour_bool
parameter_list|(
name|_Bool
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK-COMMON: %[[OK:.*]] = icmp ule i8 {{.*}}, 1
comment|// CHECK-COMMON: br i1 %[[OK]]
comment|// CHECK-UBSAN: call void @__ubsan_handle_load_invalid_value(i8* bitcast ({{.*}}), i64 {{.*}})
comment|// CHECK-TRAP: call void @llvm.trap() [[NR_NUW]]
comment|// CHECK-TRAP: unreachable
return|return
operator|*
name|p
return|;
block|}
end_function

begin_comment
comment|// CHECK-COMMON-LABEL: @ret_nonnull
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(returns_nonnull)
argument_list|)
end_macro

begin_function
name|int
modifier|*
name|ret_nonnull
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON: [[OK:%.*]] = icmp ne i32* {{.*}}, null
comment|// CHECK-COMMON: br i1 [[OK]]
comment|// CHECK-UBSAN: call void @__ubsan_handle_nonnull_return
comment|// CHECK-TRAP: call void @llvm.trap() [[NR_NUW]]
comment|// CHECK-TRAP: unreachable
return|return
name|a
return|;
block|}
end_function

begin_comment
comment|// CHECK-COMMON-LABEL: @call_decl_nonnull
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(nonnull)
argument_list|)
end_macro

begin_function_decl
name|void
name|decl_nonnull
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|call_decl_nonnull
parameter_list|(
name|int
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON: [[OK:%.*]] = icmp ne i32* {{.*}}, null
comment|// CHECK-COMMON: br i1 [[OK]]
comment|// CHECK-UBSAN: call void @__ubsan_handle_nonnull_arg
comment|// CHECK-TRAP: call void @llvm.trap() [[NR_NUW]]
comment|// CHECK-TRAP: unreachable
name|decl_nonnull
argument_list|(
name|a
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|extern
name|void
modifier|*
name|memcpy
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(nonnull
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK-COMMON-LABEL: @call_memcpy_nonnull
end_comment

begin_function
name|void
name|call_memcpy_nonnull
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|void
modifier|*
name|q
parameter_list|,
name|int
name|sz
parameter_list|)
block|{
comment|// CHECK-COMMON: icmp ne i8* {{.*}}, null
comment|// CHECK-UBSAN: call void @__ubsan_handle_nonnull_arg
comment|// CHECK-TRAP: call void @llvm.trap()
comment|// CHECK-COMMON: icmp ne i8* {{.*}}, null
comment|// CHECK-UBSAN: call void @__ubsan_handle_nonnull_arg
comment|// CHECK-TRAP: call void @llvm.trap()
name|memcpy
argument_list|(
name|p
argument_list|,
name|q
argument_list|,
name|sz
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|extern
name|void
modifier|*
name|memmove
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(nonnull
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK-COMMON-LABEL: @call_memmove_nonnull
end_comment

begin_function
name|void
name|call_memmove_nonnull
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|void
modifier|*
name|q
parameter_list|,
name|int
name|sz
parameter_list|)
block|{
comment|// CHECK-COMMON: icmp ne i8* {{.*}}, null
comment|// CHECK-UBSAN: call void @__ubsan_handle_nonnull_arg
comment|// CHECK-TRAP: call void @llvm.trap()
comment|// CHECK-COMMON: icmp ne i8* {{.*}}, null
comment|// CHECK-UBSAN: call void @__ubsan_handle_nonnull_arg
comment|// CHECK-TRAP: call void @llvm.trap()
name|memmove
argument_list|(
name|p
argument_list|,
name|q
argument_list|,
name|sz
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-COMMON-LABEL: @call_nonnull_variadic
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(nonnull)
argument_list|)
end_macro

begin_function_decl
name|void
name|nonnull_variadic
parameter_list|(
name|int
name|a
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|call_nonnull_variadic
parameter_list|(
name|int
name|a
parameter_list|,
name|int
modifier|*
name|b
parameter_list|)
block|{
comment|// CHECK-COMMON: [[OK:%.*]] = icmp ne i32* {{.*}}, null
comment|// CHECK-COMMON: br i1 [[OK]]
comment|// CHECK-UBSAN: call void @__ubsan_handle_nonnull_arg
comment|// CHECK-UBSAN-NOT: __ubsan_handle_nonnull_arg
comment|// CHECK-COMMON: call void (i32, ...) @nonnull_variadic
name|nonnull_variadic
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-UBSAN: ![[WEIGHT_MD]] = !{!"branch_weights", i32 1048575, i32 1}
end_comment

begin_comment
comment|// CHECK-TRAP: attributes [[NR_NUW]] = { noreturn nounwind }
end_comment

end_unit

