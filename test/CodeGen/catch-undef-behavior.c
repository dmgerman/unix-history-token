begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsanitize=alignment,null,object-size,shift,return,signed-integer-overflow,vla-bound,float-cast-overflow,divide-by-zero -emit-llvm %s -o - -triple x86_64-linux-gnu | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsanitize=null -emit-llvm %s -o - -triple x86_64-linux-gnu | FileCheck %s --check-prefix=CHECK-NULL
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsanitize=signed-integer-overflow -emit-llvm %s -o - -triple x86_64-linux-gnu | FileCheck %s --check-prefix=CHECK-OVERFLOW
end_comment

begin_comment
comment|// CHECK: @[[INT:.*]] = private unnamed_addr constant { i16, i16, [6 x i8] } { i16 0, i16 11, [6 x i8] c"'int'\00" }
end_comment

begin_comment
comment|// FIXME: When we only emit each type once, use [[INT]] more below.
end_comment

begin_comment
comment|// CHECK: @[[LINE_100:.*]] = private unnamed_addr constant {{.*}}, i32 100, i32 5 {{.*}} @[[INT]], i64 4, i8 1
end_comment

begin_comment
comment|// CHECK: @[[LINE_200:.*]] = {{.*}}, i32 200, i32 10 {{.*}}, i64 4, i8 0
end_comment

begin_comment
comment|// CHECK: @[[LINE_300_A:.*]] = {{.*}}, i32 300, i32 12 {{.*}} @{{.*}}, {{.*}} @{{.*}}
end_comment

begin_comment
comment|// CHECK: @[[LINE_300_B:.*]] = {{.*}}, i32 300, i32 12 {{.*}} @{{.*}}, {{.*}} @{{.*}}
end_comment

begin_comment
comment|// CHECK: @[[LINE_400:.*]] = {{.*}}, i32 400, i32 12 {{.*}} @{{.*}}, {{.*}} @{{.*}}
end_comment

begin_comment
comment|// CHECK: @[[LINE_500:.*]] = {{.*}}, i32 500, i32 10 {{.*}} @{{.*}}, i64 4, i8 0 }
end_comment

begin_comment
comment|// CHECK: @[[LINE_600:.*]] = {{.*}}, i32 600, i32 3 {{.*}} @{{.*}}, i64 4, i8 1 }
end_comment

begin_comment
comment|// CHECK: @[[STRUCT_S:.*]] = private unnamed_addr constant { i16, i16, [11 x i8] } { i16 -1, i16 0, [11 x i8] c"'struct S'\00" }
end_comment

begin_comment
comment|// CHECK: @[[LINE_700:.*]] = {{.*}}, i32 700, i32 14 {{.*}} @[[STRUCT_S]], i64 4, i8 3 }
end_comment

begin_comment
comment|// CHECK: @[[LINE_800:.*]] = {{.*}}, i32 800, i32 12 {{.*}} @{{.*}} }
end_comment

begin_comment
comment|// CHECK: @[[LINE_900:.*]] = {{.*}}, i32 900, i32 11 {{.*}} @{{.*}} }
end_comment

begin_comment
comment|// CHECK-NULL: @[[LINE_100:.*]] = private unnamed_addr constant {{.*}}, i32 100, i32 5 {{.*}}
end_comment

begin_comment
comment|// PR6805
end_comment

begin_comment
comment|// CHECK: @foo
end_comment

begin_comment
comment|// CHECK-NULL: @foo
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
comment|// CHECK:      %[[CHECK0:.*]] = icmp ne {{.*}}* %[[PTR:.*]], null
comment|// CHECK:      %[[I8PTR:.*]] = bitcast i32* %[[PTR]] to i8*
comment|// CHECK-NEXT: %[[SIZE:.*]] = call i64 @llvm.objectsize.i64(i8* %[[I8PTR]], i1 false)
comment|// CHECK-NEXT: %[[CHECK1:.*]] = icmp uge i64 %[[SIZE]], 4
comment|// CHECK-NEXT: %[[CHECK01:.*]] = and i1 %[[CHECK0]], %[[CHECK1]]
comment|// CHECK:      %[[PTRTOINT:.*]] = ptrtoint {{.*}}* %[[PTR]] to i64
comment|// CHECK-NEXT: %[[MISALIGN:.*]] = and i64 %[[PTRTOINT]], 3
comment|// CHECK-NEXT: %[[CHECK2:.*]] = icmp eq i64 %[[MISALIGN]], 0
comment|// CHECK:      %[[OK:.*]] = and i1 %[[CHECK01]], %[[CHECK2]]
comment|// CHECK-NEXT: br i1 %[[OK]]
comment|// CHECK:      %[[ARG:.*]] = ptrtoint {{.*}} %[[PTR]] to i64
comment|// CHECK-NEXT: call void @__ubsan_handle_type_mismatch(i8* bitcast ({{.*}} @[[LINE_100]] to i8*), i64 %[[ARG]]) noreturn nounwind
comment|// With -fsanitize=null, only perform the null check.
comment|// CHECK-NULL: %[[NULL:.*]] = icmp ne {{.*}}, null
comment|// CHECK-NULL: br i1 %[[NULL]]
comment|// CHECK-NULL: call void @__ubsan_handle_type_mismatch(i8* bitcast ({{.*}} @[[LINE_100]] to i8*), i64 %{{.*}}) noreturn nounwind
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
comment|// CHECK: @bar
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
comment|// CHECK:      %[[SIZE:.*]] = call i64 @llvm.objectsize.i64
comment|// CHECK-NEXT: icmp uge i64 %[[SIZE]], 4
comment|// CHECK:      %[[PTRINT:.*]] = ptrtoint
comment|// CHECK-NEXT: %[[MISALIGN:.*]] = and i64 %[[PTRINT]], 3
comment|// CHECK-NEXT: icmp eq i64 %[[MISALIGN]], 0
comment|// CHECK:      %[[ARG:.*]] = ptrtoint
comment|// CHECK-NEXT: call void @__ubsan_handle_type_mismatch(i8* bitcast ({{.*}} @[[LINE_200]] to i8*), i64 %[[ARG]]) noreturn nounwind
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
comment|// CHECK: @addr_space
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
comment|// CHECK-NOT: __ubsan
return|return
operator|*
name|a
return|;
block|}
end_decl_stmt

begin_comment
comment|// CHECK: @lsh_overflow
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
comment|// CHECK:      %[[INBOUNDS:.*]] = icmp ule i32 %[[RHS:.*]], 31
comment|// CHECK-NEXT: br i1 %[[INBOUNDS]]
comment|// FIXME: Only emit one trap block here.
comment|// CHECK:      %[[ARG1:.*]] = zext
comment|// CHECK-NEXT: %[[ARG2:.*]] = zext
comment|// CHECK-NEXT: call void @__ubsan_handle_shift_out_of_bounds(i8* bitcast ({{.*}} @[[LINE_300_A]] to i8*), i64 %[[ARG1]], i64 %[[ARG2]]) noreturn nounwind
comment|// CHECK:      %[[SHIFTED_OUT_WIDTH:.*]] = sub nuw nsw i32 31, %[[RHS]]
comment|// CHECK-NEXT: %[[SHIFTED_OUT:.*]] = lshr i32 %[[LHS:.*]], %[[SHIFTED_OUT_WIDTH]]
comment|// CHECK-NEXT: %[[NO_OVERFLOW:.*]] = icmp eq i32 %[[SHIFTED_OUT]], 0
comment|// CHECK-NEXT: br i1 %[[NO_OVERFLOW]]
comment|// CHECK:      %[[ARG1:.*]] = zext
comment|// CHECK-NEXT: %[[ARG2:.*]] = zext
comment|// CHECK-NEXT: call void @__ubsan_handle_shift_out_of_bounds(i8* bitcast ({{.*}} @[[LINE_300_B]] to i8*), i64 %[[ARG1]], i64 %[[ARG2]]) noreturn nounwind
comment|// CHECK:      %[[RET:.*]] = shl i32 %[[LHS]], %[[RHS]]
comment|// CHECK-NEXT: ret i32 %[[RET]]
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
comment|// CHECK: @rsh_inbounds
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
comment|// CHECK:      %[[INBOUNDS:.*]] = icmp ult i32 %[[RHS:.*]], 32
comment|// CHECK:      br i1 %[[INBOUNDS]]
comment|// CHECK:      %[[ARG1:.*]] = zext
comment|// CHECK-NEXT: %[[ARG2:.*]] = zext
comment|// CHECK-NEXT: call void @__ubsan_handle_shift_out_of_bounds(i8* bitcast ({{.*}} @[[LINE_400]] to i8*), i64 %[[ARG1]], i64 %[[ARG2]]) noreturn nounwind
comment|// CHECK:      %[[RET:.*]] = ashr i32 %[[LHS]], %[[RHS]]
comment|// CHECK-NEXT: ret i32 %[[RET]]
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
comment|// CHECK: @load
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
comment|// CHECK: call void @__ubsan_handle_type_mismatch(i8* bitcast ({{.*}} @[[LINE_500]] to i8*), i64 %{{.*}}) noreturn nounwind
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
comment|// CHECK: @store
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
comment|// CHECK: call void @__ubsan_handle_type_mismatch(i8* bitcast ({{.*}} @[[LINE_600]] to i8*), i64 %{{.*}}) noreturn nounwind
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
comment|// CHECK: @member_access
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
comment|// CHECK: call void @__ubsan_handle_type_mismatch(i8* bitcast ({{.*}} @[[LINE_700]] to i8*), i64 %{{.*}}) noreturn nounwind
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
comment|// CHECK: @signed_overflow
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
comment|// CHECK:      %[[ARG1:.*]] = zext
comment|// CHECK-NEXT: %[[ARG2:.*]] = zext
comment|// CHECK-NEXT: call void @__ubsan_handle_add_overflow(i8* bitcast ({{.*}} @[[LINE_800]] to i8*), i64 %[[ARG1]], i64 %[[ARG2]]) noreturn nounwind
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
comment|// CHECK: @no_return
end_comment

begin_function
name|int
name|no_return
parameter_list|()
block|{
comment|// Reaching the end of a noreturn function is fine in C.
comment|// FIXME: If the user explicitly requests -fsanitize=return, we should catch
comment|//        that here even though it's not undefined behavior.
comment|// CHECK-NOT: call
comment|// CHECK-NOT: unreachable
comment|// CHECK: ret i32
block|}
end_function

begin_comment
comment|// CHECK: @vla_bound
end_comment

begin_function
name|void
name|vla_bound
parameter_list|(
name|int
name|n
parameter_list|)
block|{
comment|// CHECK:      icmp sgt i32 %[[PARAM:.*]], 0
comment|//
comment|// CHECK:      %[[ARG:.*]] = zext i32 %[[PARAM]] to i64
comment|// CHECK-NEXT: call void @__ubsan_handle_vla_bound_not_positive(i8* bitcast ({{.*}} @[[LINE_900]] to i8*), i64 %[[ARG]]) noreturn nounwind
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
comment|// CHECK: @int_float_no_overflow
end_comment

begin_function
name|float
name|int_float_no_overflow
parameter_list|(
name|__int128
name|n
parameter_list|)
block|{
comment|// CHECK-NOT: call void @__ubsan_handle
return|return
name|n
return|;
block|}
end_function

begin_comment
comment|// CHECK: @int_float_overflow
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
comment|// CHECK: icmp ule i128 %{{.*}}, -20282409603651670423947251286016
comment|// CHECK: call void @__ubsan_handle_float_cast_overflow(
return|return
name|n
return|;
block|}
end_function

begin_comment
comment|// CHECK: @int_fp16_overflow
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
comment|// CHECK: %[[GE:.*]] = icmp sge i32 %{{.*}}, -65504
comment|// CHECK: %[[LE:.*]] = icmp sle i32 %{{.*}}, 65504
comment|// CHECK: and i1 %[[GE]], %[[LE]]
comment|// CHECK: call void @__ubsan_handle_float_cast_overflow(
operator|*
name|p
operator|=
name|n
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: @float_int_overflow
end_comment

begin_function
name|int
name|float_int_overflow
parameter_list|(
name|float
name|f
parameter_list|)
block|{
comment|// CHECK: %[[GE:.*]] = fcmp oge float %[[F:.*]], 0xC1E0000000000000
comment|// CHECK: %[[LE:.*]] = fcmp ole float %[[F]], 0x41DFFFFFE0000000
comment|// CHECK: and i1 %[[GE]], %[[LE]]
comment|// CHECK: call void @__ubsan_handle_float_cast_overflow(
return|return
name|f
return|;
block|}
end_function

begin_comment
comment|// CHECK: @float_uint_overflow
end_comment

begin_function
name|unsigned
name|float_uint_overflow
parameter_list|(
name|float
name|f
parameter_list|)
block|{
comment|// CHECK: %[[GE:.*]] = fcmp oge float %[[F:.*]], 0.{{0*}}e+00
comment|// CHECK: %[[LE:.*]] = fcmp ole float %[[F]], 0x41EFFFFFE0000000
comment|// CHECK: and i1 %[[GE]], %[[LE]]
comment|// CHECK: call void @__ubsan_handle_float_cast_overflow(
return|return
name|f
return|;
block|}
end_function

begin_comment
comment|// CHECK: @fp16_char_overflow
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
comment|// CHECK: %[[GE:.*]] = fcmp oge float %[[F:.*]], -1.28{{0*}}e+02
comment|// CHECK: %[[LE:.*]] = fcmp ole float %[[F]], 1.27{{0*}}e+02
comment|// CHECK: and i1 %[[GE]], %[[LE]]
comment|// CHECK: call void @__ubsan_handle_float_cast_overflow(
return|return
operator|*
name|p
return|;
block|}
end_function

begin_comment
comment|// CHECK: @float_float_overflow
end_comment

begin_function
name|float
name|float_float_overflow
parameter_list|(
name|double
name|f
parameter_list|)
block|{
comment|// CHECK: %[[GE:.*]] = fcmp oge double %[[F:.*]], 0xC7EFFFFFE0000000
comment|// CHECK: %[[LE:.*]] = fcmp ole double %[[F]], 0x47EFFFFFE0000000
comment|// CHECK: and i1 %[[GE]], %[[LE]]
comment|// CHECK: call void @__ubsan_handle_float_cast_overflow(
return|return
name|f
return|;
block|}
end_function

begin_comment
comment|// CHECK:          @int_divide_overflow
end_comment

begin_comment
comment|// CHECK-OVERFLOW: @int_divide_overflow
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
comment|// CHECK:               %[[ZERO:.*]] = icmp ne i32 %[[B:.*]], 0
comment|// CHECK-OVERFLOW-NOT:  icmp ne i32 %{{.*}}, 0
comment|// CHECK:               %[[AOK:.*]] = icmp ne i32 %[[A:.*]], -2147483648
comment|// CHECK-NEXT:          %[[BOK:.*]] = icmp ne i32 %[[B]], -1
comment|// CHECK-NEXT:          %[[OVER:.*]] = or i1 %[[AOK]], %[[BOK]]
comment|// CHECK-OVERFLOW:      %[[AOK:.*]] = icmp ne i32 %[[A:.*]], -2147483648
comment|// CHECK-OVERFLOW-NEXT: %[[BOK:.*]] = icmp ne i32 %[[B:.*]], -1
comment|// CHECK-OVERFLOW-NEXT: %[[OK:.*]] = or i1 %[[AOK]], %[[BOK]]
comment|// CHECK:               %[[OK:.*]] = and i1 %[[ZERO]], %[[OVER]]
comment|// CHECK:               br i1 %[[OK]]
comment|// CHECK-OVERFLOW:      br i1 %[[OK]]
return|return
name|a
operator|/
name|b
return|;
comment|// CHECK:          }
comment|// CHECK-OVERFLOW: }
block|}
end_function

end_unit

