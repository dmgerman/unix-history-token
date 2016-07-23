begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple armv7-apple-darwin9 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// This isn't really testing anything ARM-specific; it's just a convenient
end_comment

begin_comment
comment|// 32-bit platform.
end_comment

begin_define
define|#
directive|define
name|SWIFTCALL
value|__attribute__((swiftcall))
end_define

begin_define
define|#
directive|define
name|OUT
value|__attribute__((swift_indirect_result))
end_define

begin_define
define|#
directive|define
name|ERROR
value|__attribute__((swift_error_result))
end_define

begin_define
define|#
directive|define
name|CONTEXT
value|__attribute__((swift_context))
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/****************************** PARAMETER ABIS *******************************/
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_function
name|SWIFTCALL
name|void
name|indirect_result_1
parameter_list|(
name|OUT
name|int
modifier|*
name|arg0
parameter_list|,
name|OUT
name|float
modifier|*
name|arg1
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define {{.*}} void @indirect_result_1(i32* noalias sret align 4 dereferenceable(4){{.*}}, float* noalias align 4 dereferenceable(4){{.*}})
end_comment

begin_comment
comment|// TODO: maybe this shouldn't suppress sret.
end_comment

begin_function
name|SWIFTCALL
name|int
name|indirect_result_2
parameter_list|(
name|OUT
name|int
modifier|*
name|arg0
parameter_list|,
name|OUT
name|float
modifier|*
name|arg1
parameter_list|)
block|{
name|__builtin_unreachable
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define {{.*}} i32 @indirect_result_2(i32* noalias align 4 dereferenceable(4){{.*}}, float* noalias align 4 dereferenceable(4){{.*}})
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|array
index|[
literal|1024
index|]
decl_stmt|;
block|}
name|struct_reallybig
typedef|;
end_typedef

begin_function
name|SWIFTCALL
name|struct_reallybig
name|indirect_result_3
parameter_list|(
name|OUT
name|int
modifier|*
name|arg0
parameter_list|,
name|OUT
name|float
modifier|*
name|arg1
parameter_list|)
block|{
name|__builtin_unreachable
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define {{.*}} void @indirect_result_3({{.*}}* noalias sret {{.*}}, i32* noalias align 4 dereferenceable(4){{.*}}, float* noalias align 4 dereferenceable(4){{.*}})
end_comment

begin_function
name|SWIFTCALL
name|void
name|context_1
parameter_list|(
name|CONTEXT
name|void
modifier|*
name|self
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define {{.*}} void @context_1(i8* swiftself
end_comment

begin_function
name|SWIFTCALL
name|void
name|context_2
parameter_list|(
name|void
modifier|*
name|arg0
parameter_list|,
name|CONTEXT
name|void
modifier|*
name|self
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define {{.*}} void @context_2(i8*{{.*}}, i8* swiftself
end_comment

begin_function
name|SWIFTCALL
name|void
name|context_error_1
parameter_list|(
name|CONTEXT
name|int
modifier|*
name|self
parameter_list|,
name|ERROR
name|float
modifier|*
modifier|*
name|error
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define {{.*}} void @context_error_1(i32* swiftself{{.*}}, float** swifterror)
end_comment

begin_comment
comment|// CHECK:       [[TEMP:%.*]] = alloca float*, align 4
end_comment

begin_comment
comment|// CHECK:       [[T0:%.*]] = load float*, float** [[ERRORARG:%.*]], align 4
end_comment

begin_comment
comment|// CHECK:       store float* [[T0]], float** [[TEMP]], align 4
end_comment

begin_comment
comment|// CHECK:       [[T0:%.*]] = load float*, float** [[TEMP]], align 4
end_comment

begin_comment
comment|// CHECK:       store float* [[T0]], float** [[ERRORARG]], align 4
end_comment

begin_function
name|void
name|test_context_error_1
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
name|float
modifier|*
name|error
decl_stmt|;
name|context_error_1
argument_list|(
operator|&
name|x
argument_list|,
operator|&
name|error
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_context_error_1()
end_comment

begin_comment
comment|// CHECK:       [[X:%.*]] = alloca i32, align 4
end_comment

begin_comment
comment|// CHECK:       [[ERROR:%.*]] = alloca float*, align 4
end_comment

begin_comment
comment|// CHECK:       [[TEMP:%.*]] = alloca swifterror float*, align 4
end_comment

begin_comment
comment|// CHECK:       [[T0:%.*]] = load float*, float** [[ERROR]], align 4
end_comment

begin_comment
comment|// CHECK:       store float* [[T0]], float** [[TEMP]], align 4
end_comment

begin_comment
comment|// CHECK:       call [[SWIFTCC:swiftcc]] void @context_error_1(i32* swiftself [[X]], float** swifterror [[TEMP]])
end_comment

begin_comment
comment|// CHECK:       [[T0:%.*]] = load float*, float** [[TEMP]], align 4
end_comment

begin_comment
comment|// CHECK:       store float* [[T0]], float** [[ERROR]], align 4
end_comment

begin_function
name|SWIFTCALL
name|void
name|context_error_2
parameter_list|(
name|short
name|s
parameter_list|,
name|CONTEXT
name|int
modifier|*
name|self
parameter_list|,
name|ERROR
name|float
modifier|*
modifier|*
name|error
parameter_list|)
block|{}
end_function

begin_comment
comment|// CHECK-LABEL: define {{.*}} void @context_error_2(i16{{.*}}, i32* swiftself{{.*}}, float** swifterror)
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/********************************** LOWERING *********************************/
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|float
name|float4
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(4)));
end_typedef

begin_typedef
typedef|typedef
name|float
name|float8
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(8)));
end_typedef

begin_typedef
typedef|typedef
name|double
name|double2
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(2)));
end_typedef

begin_typedef
typedef|typedef
name|double
name|double4
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(4)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|int3
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(3)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|int4
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(4)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|int5
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(5)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|int8
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(8)));
end_typedef

begin_define
define|#
directive|define
name|TEST
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|SWIFTCALL TYPE return_##TYPE(void) {   \     TYPE result = {};                    \     return result;                       \   }                                      \   SWIFTCALL void take_##TYPE(TYPE v) {   \   }                                      \   void test_##TYPE() {                   \     take_##TYPE(return_##TYPE());        \   }
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*********************************** STRUCTS *********************************/
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{ }
name|struct_empty
typedef|;
end_typedef

begin_expr_stmt
name|TEST
argument_list|(
name|struct_empty
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// CHECK-LABEL: define {{.*}} @return_struct_empty()
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_comment
comment|// CHECK-LABEL: define {{.*}} @take_struct_empty()
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|x
decl_stmt|;
name|char
name|c0
decl_stmt|;
name|char
name|c1
decl_stmt|;
name|float
name|f0
decl_stmt|;
name|float
name|f1
decl_stmt|;
block|}
name|struct_1
typedef|;
end_typedef

begin_expr_stmt
name|TEST
argument_list|(
name|struct_1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// CHECK-LABEL: define {{.*}} @return_struct_1()
end_comment

begin_comment
comment|// CHECK:   [[RET:%.*]] = alloca [[REC:%.*]], align 4
end_comment

begin_comment
comment|// CHECK:   [[VAR:%.*]] = alloca [[REC]], align 4
end_comment

begin_comment
comment|// CHECK:   @llvm.memset
end_comment

begin_comment
comment|// CHECK:   @llvm.memcpy
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[REC]]* [[RET]] to [[AGG:{ i32, i16, \[2 x i8\], float, float }]]*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[FIRST:%.*]] = load i32, i32* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[SECOND:%.*]] = load i16, i16* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 3
end_comment

begin_comment
comment|// CHECK:   [[THIRD:%.*]] = load float, float* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 4
end_comment

begin_comment
comment|// CHECK:   [[FOURTH:%.*]] = load float, float* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = insertvalue [[UAGG:{ i32, i16, float, float }]] undef, i32 [[FIRST]], 0
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = insertvalue [[UAGG]] [[T0]], i16 [[SECOND]], 1
end_comment

begin_comment
comment|// CHECK:   [[T2:%.*]] = insertvalue [[UAGG]] [[T1]], float [[THIRD]], 2
end_comment

begin_comment
comment|// CHECK:   [[T3:%.*]] = insertvalue [[UAGG]] [[T2]], float [[FOURTH]], 3
end_comment

begin_comment
comment|// CHECK:   ret [[UAGG]] [[T3]]
end_comment

begin_comment
comment|// CHECK-LABEL: define {{.*}} @take_struct_1(i32, i16, float, float)
end_comment

begin_comment
comment|// CHECK:   [[V:%.*]] = alloca [[REC]], align 4
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[REC]]* [[V]] to [[AGG]]*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   store i32 %0, i32* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   store i16 %1, i16* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 3
end_comment

begin_comment
comment|// CHECK:   store float %2, float* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 4
end_comment

begin_comment
comment|// CHECK:   store float %3, float* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_comment
comment|// CHECK-LABEL: define void @test_struct_1()
end_comment

begin_comment
comment|// CHECK:   [[TMP:%.*]] = alloca [[REC]], align 4
end_comment

begin_comment
comment|// CHECK:   [[CALL:%.*]] = call [[SWIFTCC]] [[UAGG]] @return_struct_1()
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[REC]]* [[TMP]] to [[AGG]]*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = extractvalue [[UAGG]] [[CALL]], 0
end_comment

begin_comment
comment|// CHECK:   store i32 [[T1]], i32* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = extractvalue [[UAGG]] [[CALL]], 1
end_comment

begin_comment
comment|// CHECK:   store i16 [[T1]], i16* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 3
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = extractvalue [[UAGG]] [[CALL]], 2
end_comment

begin_comment
comment|// CHECK:   store float [[T1]], float* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 4
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = extractvalue [[UAGG]] [[CALL]], 3
end_comment

begin_comment
comment|// CHECK:   store float [[T1]], float* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[REC]]* [[TMP]] to [[AGG]]*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[FIRST:%.*]] = load i32, i32* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[SECOND:%.*]] = load i16, i16* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 3
end_comment

begin_comment
comment|// CHECK:   [[THIRD:%.*]] = load float, float* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 4
end_comment

begin_comment
comment|// CHECK:   [[FOURTH:%.*]] = load float, float* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   call [[SWIFTCC]] void @take_struct_1(i32 [[FIRST]], i16 [[SECOND]], float [[THIRD]], float [[FOURTH]])
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|x
decl_stmt|;
name|char
name|c0
decl_stmt|;
name|__attribute__
argument_list|(
argument|(aligned(
literal|2
argument|))
argument_list|)
name|char
name|c1
decl_stmt|;
name|float
name|f0
decl_stmt|;
name|float
name|f1
decl_stmt|;
block|}
name|struct_2
typedef|;
end_typedef

begin_expr_stmt
name|TEST
argument_list|(
name|struct_2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// CHECK-LABEL: define {{.*}} @return_struct_2()
end_comment

begin_comment
comment|// CHECK:   [[RET:%.*]] = alloca [[REC:%.*]], align 4
end_comment

begin_comment
comment|// CHECK:   [[VAR:%.*]] = alloca [[REC]], align 4
end_comment

begin_comment
comment|// CHECK:   @llvm.memcpy
end_comment

begin_comment
comment|// CHECK:   @llvm.memcpy
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[REC]]* [[RET]] to [[AGG:{ i32, i32, float, float }]]*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[FIRST:%.*]] = load i32, i32* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[SECOND:%.*]] = load i32, i32* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 2
end_comment

begin_comment
comment|// CHECK:   [[THIRD:%.*]] = load float, float* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 3
end_comment

begin_comment
comment|// CHECK:   [[FOURTH:%.*]] = load float, float* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = insertvalue [[UAGG:{ i32, i32, float, float }]] undef, i32 [[FIRST]], 0
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = insertvalue [[UAGG]] [[T0]], i32 [[SECOND]], 1
end_comment

begin_comment
comment|// CHECK:   [[T2:%.*]] = insertvalue [[UAGG]] [[T1]], float [[THIRD]], 2
end_comment

begin_comment
comment|// CHECK:   [[T3:%.*]] = insertvalue [[UAGG]] [[T2]], float [[FOURTH]], 3
end_comment

begin_comment
comment|// CHECK:   ret [[UAGG]] [[T3]]
end_comment

begin_comment
comment|// CHECK-LABEL: define {{.*}} @take_struct_2(i32, i32, float, float)
end_comment

begin_comment
comment|// CHECK:   [[V:%.*]] = alloca [[REC]], align 4
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[REC]]* [[V]] to [[AGG]]*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   store i32 %0, i32* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   store i32 %1, i32* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 2
end_comment

begin_comment
comment|// CHECK:   store float %2, float* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 3
end_comment

begin_comment
comment|// CHECK:   store float %3, float* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_comment
comment|// CHECK-LABEL: define void @test_struct_2()
end_comment

begin_comment
comment|// CHECK:   [[TMP:%.*]] = alloca [[REC]], align 4
end_comment

begin_comment
comment|// CHECK:   [[CALL:%.*]] = call [[SWIFTCC]] [[UAGG]] @return_struct_2()
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[REC]]* [[TMP]] to [[AGG]]*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = extractvalue [[UAGG]] [[CALL]], 0
end_comment

begin_comment
comment|// CHECK:   store i32 [[T1]], i32* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = extractvalue [[UAGG]] [[CALL]], 1
end_comment

begin_comment
comment|// CHECK:   store i32 [[T1]], i32* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 2
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = extractvalue [[UAGG]] [[CALL]], 2
end_comment

begin_comment
comment|// CHECK:   store float [[T1]], float* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 3
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = extractvalue [[UAGG]] [[CALL]], 3
end_comment

begin_comment
comment|// CHECK:   store float [[T1]], float* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[REC]]* [[TMP]] to [[AGG]]*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[FIRST:%.*]] = load i32, i32* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[SECOND:%.*]] = load i32, i32* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 2
end_comment

begin_comment
comment|// CHECK:   [[THIRD:%.*]] = load float, float* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 3
end_comment

begin_comment
comment|// CHECK:   [[FOURTH:%.*]] = load float, float* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   call [[SWIFTCC]] void @take_struct_2(i32 [[FIRST]], i32 [[SECOND]], float [[THIRD]], float [[FOURTH]])
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_comment
comment|// There's no way to put a field randomly in the middle of an otherwise
end_comment

begin_comment
comment|// empty storage unit in C, so that case has to be tested in C++, which
end_comment

begin_comment
comment|// can use empty structs to introduce arbitrary padding.  (In C, they end up
end_comment

begin_comment
comment|// with size 0 and so don't affect layout.)
end_comment

begin_comment
comment|// Misaligned data rule.
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|c0
decl_stmt|;
name|__attribute__
argument_list|(
argument|(packed)
argument_list|)
name|float
name|f
decl_stmt|;
block|}
name|struct_misaligned_1
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_misaligned_1
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define {{.*}} @return_struct_misaligned_1()
end_comment

begin_comment
comment|// CHECK:   [[RET:%.*]] = alloca [[REC:%.*]], align
end_comment

begin_comment
comment|// CHECK:   [[VAR:%.*]] = alloca [[REC]], align
end_comment

begin_comment
comment|// CHECK:   @llvm.memset
end_comment

begin_comment
comment|// CHECK:   @llvm.memcpy
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[REC]]* [[RET]] to [[AGG:{ i32, i8 }]]*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[FIRST:%.*]] = load i32, i32* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[SECOND:%.*]] = load i8, i8* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = insertvalue [[UAGG:{ i32, i8 }]] undef, i32 [[FIRST]], 0
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = insertvalue [[UAGG]] [[T0]], i8 [[SECOND]], 1
end_comment

begin_comment
comment|// CHECK:   ret [[UAGG]] [[T1]]
end_comment

begin_comment
comment|// CHECK-LABEL: define {{.*}} @take_struct_misaligned_1(i32, i8)
end_comment

begin_comment
comment|// CHECK:   [[V:%.*]] = alloca [[REC]], align
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[REC]]* [[V]] to [[AGG]]*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   store i32 %0, i32* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   store i8 %1, i8* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_comment
comment|// Too many scalars.
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|x
index|[
literal|5
index|]
decl_stmt|;
block|}
name|struct_big_1
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_big_1
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define {{.*}} void @return_struct_big_1({{.*}} noalias sret
end_comment

begin_comment
comment|// Should not be byval.
end_comment

begin_comment
comment|// CHECK-LABEL: define {{.*}} void @take_struct_big_1({{.*}}*{{( %.*)?}})
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/********************************* TYPE MERGING ******************************/
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|float
name|f
decl_stmt|;
name|double
name|d
decl_stmt|;
block|}
name|union_het_fp
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|union_het_fp
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define {{.*}} @return_union_het_fp()
end_comment

begin_comment
comment|// CHECK:   [[RET:%.*]] = alloca [[REC:%.*]], align 4
end_comment

begin_comment
comment|// CHECK:   [[VAR:%.*]] = alloca [[REC]], align 4
end_comment

begin_comment
comment|// CHECK:   @llvm.memcpy
end_comment

begin_comment
comment|// CHECK:   @llvm.memcpy
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[REC]]* [[RET]] to [[AGG:{ i32, i32 }]]*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[FIRST:%.*]] = load i32, i32* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[SECOND:%.*]] = load i32, i32* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = insertvalue [[UAGG:{ i32, i32 }]] undef, i32 [[FIRST]], 0
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = insertvalue [[UAGG]] [[T0]], i32 [[SECOND]], 1
end_comment

begin_comment
comment|// CHECK:   ret [[UAGG]] [[T1]]
end_comment

begin_comment
comment|// CHECK-LABEL: define {{.*}} @take_union_het_fp(i32, i32)
end_comment

begin_comment
comment|// CHECK:   [[V:%.*]] = alloca [[REC]], align 4
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[REC]]* [[V]] to [[AGG]]*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   store i32 %0, i32* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   store i32 %1, i32* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_comment
comment|// CHECK-LABEL: define void @test_union_het_fp()
end_comment

begin_comment
comment|// CHECK:   [[TMP:%.*]] = alloca [[REC]], align 4
end_comment

begin_comment
comment|// CHECK:   [[CALL:%.*]] = call [[SWIFTCC]] [[UAGG]] @return_union_het_fp()
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[REC]]* [[TMP]] to [[AGG]]*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = extractvalue [[UAGG]] [[CALL]], 0
end_comment

begin_comment
comment|// CHECK:   store i32 [[T1]], i32* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = extractvalue [[UAGG]] [[CALL]], 1
end_comment

begin_comment
comment|// CHECK:   store i32 [[T1]], i32* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[REC]]* [[TMP]] to [[AGG]]*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[FIRST:%.*]] = load i32, i32* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[SECOND:%.*]] = load i32, i32* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   call [[SWIFTCC]] void @take_union_het_fp(i32 [[FIRST]], i32 [[SECOND]])
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|float
name|f1
decl_stmt|;
name|float
name|f2
decl_stmt|;
block|}
name|union_hom_fp
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|union_hom_fp
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define void @test_union_hom_fp()
end_comment

begin_comment
comment|// CHECK:   [[TMP:%.*]] = alloca [[REC:%.*]], align 4
end_comment

begin_comment
comment|// CHECK:   [[CALL:%.*]] = call [[SWIFTCC]] float @return_union_hom_fp()
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[REC]]* [[TMP]] to [[AGG:{ float }]]*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   store float [[CALL]], float* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[REC]]* [[TMP]] to [[AGG]]*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[FIRST:%.*]] = load float, float* [[T0]], align 4
end_comment

begin_comment
comment|// CHECK:   call [[SWIFTCC]] void @take_union_hom_fp(float [[FIRST]])
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|float
name|f1
decl_stmt|;
name|float4
name|fv2
decl_stmt|;
block|}
name|union_hom_fp_partial
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|union_hom_fp_partial
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define void @test_union_hom_fp_partial()
end_comment

begin_comment
comment|// CHECK:   [[TMP:%.*]] = alloca [[REC:%.*]], align 16
end_comment

begin_comment
comment|// CHECK:   [[CALL:%.*]] = call [[SWIFTCC]] [[UAGG:{ float, float, float, float }]] @return_union_hom_fp_partial()
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[REC]]* [[TMP]] to [[AGG:{ float, float, float, float }]]*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = extractvalue [[UAGG]] [[CALL]], 0
end_comment

begin_comment
comment|// CHECK:   store float [[T1]], float* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = extractvalue [[UAGG]] [[CALL]], 1
end_comment

begin_comment
comment|// CHECK:   store float [[T1]], float* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 2
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = extractvalue [[UAGG]] [[CALL]], 2
end_comment

begin_comment
comment|// CHECK:   store float [[T1]], float* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 3
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = extractvalue [[UAGG]] [[CALL]], 3
end_comment

begin_comment
comment|// CHECK:   store float [[T1]], float* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[REC]]* [[TMP]] to [[AGG]]*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[FIRST:%.*]] = load float, float* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[SECOND:%.*]] = load float, float* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 2
end_comment

begin_comment
comment|// CHECK:   [[THIRD:%.*]] = load float, float* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 3
end_comment

begin_comment
comment|// CHECK:   [[FOURTH:%.*]] = load float, float* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   call [[SWIFTCC]] void @take_union_hom_fp_partial(float [[FIRST]], float [[SECOND]], float [[THIRD]], float [[FOURTH]])
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
name|f1
struct|;
name|float4
name|fv2
decl_stmt|;
block|}
name|union_het_fpv_partial
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|union_het_fpv_partial
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define void @test_union_het_fpv_partial()
end_comment

begin_comment
comment|// CHECK:   [[TMP:%.*]] = alloca [[REC:%.*]], align 16
end_comment

begin_comment
comment|// CHECK:   [[CALL:%.*]] = call [[SWIFTCC]] [[UAGG:{ i32, i32, float, float }]] @return_union_het_fpv_partial()
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[REC]]* [[TMP]] to [[AGG:{ i32, i32, float, float }]]*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = extractvalue [[UAGG]] [[CALL]], 0
end_comment

begin_comment
comment|// CHECK:   store i32 [[T1]], i32* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = extractvalue [[UAGG]] [[CALL]], 1
end_comment

begin_comment
comment|// CHECK:   store i32 [[T1]], i32* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 2
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = extractvalue [[UAGG]] [[CALL]], 2
end_comment

begin_comment
comment|// CHECK:   store float [[T1]], float* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 3
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = extractvalue [[UAGG]] [[CALL]], 3
end_comment

begin_comment
comment|// CHECK:   store float [[T1]], float* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[REC]]* [[TMP]] to [[AGG]]*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[FIRST:%.*]] = load i32, i32* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[SECOND:%.*]] = load i32, i32* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 2
end_comment

begin_comment
comment|// CHECK:   [[THIRD:%.*]] = load float, float* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 3
end_comment

begin_comment
comment|// CHECK:   [[FOURTH:%.*]] = load float, float* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   call [[SWIFTCC]] void @take_union_het_fpv_partial(i32 [[FIRST]], i32 [[SECOND]], float [[THIRD]], float [[FOURTH]])
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/****************************** VECTOR LEGALIZATION **************************/
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_macro
name|TEST
argument_list|(
argument|int4
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define {{.*}}<4 x i32> @return_int4()
end_comment

begin_comment
comment|// CHECK-LABEL: define {{.*}} @take_int4(<4 x i32>
end_comment

begin_macro
name|TEST
argument_list|(
argument|int8
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define {{.*}} @return_int8()
end_comment

begin_comment
comment|// CHECK:   [[RET:%.*]] = alloca [[REC:<8 x i32>]], align 32
end_comment

begin_comment
comment|// CHECK:   [[VAR:%.*]] = alloca [[REC]], align
end_comment

begin_comment
comment|// CHECK:   store
end_comment

begin_comment
comment|// CHECK:   load
end_comment

begin_comment
comment|// CHECK:   store
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[REC]]* [[RET]] to [[AGG:{<4 x i32>,<4 x i32> }]]*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[FIRST:%.*]] = load<4 x i32>,<4 x i32>* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[SECOND:%.*]] = load<4 x i32>,<4 x i32>* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = insertvalue [[UAGG:{<4 x i32>,<4 x i32> }]] undef,<4 x i32> [[FIRST]], 0
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = insertvalue [[UAGG]] [[T0]],<4 x i32> [[SECOND]], 1
end_comment

begin_comment
comment|// CHECK:   ret [[UAGG]] [[T1]]
end_comment

begin_comment
comment|// CHECK-LABEL: define {{.*}} @take_int8(<4 x i32>,<4 x i32>)
end_comment

begin_comment
comment|// CHECK:   [[V:%.*]] = alloca [[REC]], align
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[REC]]* [[V]] to [[AGG]]*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   store<4 x i32> %0,<4 x i32>* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   store<4 x i32> %1,<4 x i32>* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_comment
comment|// CHECK-LABEL: define void @test_int8()
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = alloca [[REC]], align
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = alloca [[REC]], align
end_comment

begin_comment
comment|// CHECK:   [[CALL:%.*]] = call [[SWIFTCC]] [[UAGG]] @return_int8()
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[REC]]* [[TMP1]] to [[AGG]]*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = extractvalue [[UAGG]] [[CALL]], 0
end_comment

begin_comment
comment|// CHECK:   store<4 x i32> [[T1]],<4 x i32>* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = extractvalue [[UAGG]] [[CALL]], 1
end_comment

begin_comment
comment|// CHECK:   store<4 x i32> [[T1]],<4 x i32>* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[V:%.*]] = load [[REC]], [[REC]]* [[TMP1]], align
end_comment

begin_comment
comment|// CHECK:   store [[REC]] [[V]], [[REC]]* [[TMP2]], align
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[REC]]* [[TMP2]] to [[AGG]]*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[FIRST:%.*]] = load<4 x i32>,<4 x i32>* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[SECOND:%.*]] = load<4 x i32>,<4 x i32>* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   call [[SWIFTCC]] void @take_int8(<4 x i32> [[FIRST]],<4 x i32> [[SECOND]])
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_macro
name|TEST
argument_list|(
argument|int5
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define {{.*}} @return_int5()
end_comment

begin_comment
comment|// CHECK:   [[RET:%.*]] = alloca [[REC:<5 x i32>]], align 32
end_comment

begin_comment
comment|// CHECK:   [[VAR:%.*]] = alloca [[REC]], align
end_comment

begin_comment
comment|// CHECK:   store
end_comment

begin_comment
comment|// CHECK:   load
end_comment

begin_comment
comment|// CHECK:   store
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[REC]]* [[RET]] to [[AGG:{<4 x i32>, i32 }]]*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[FIRST:%.*]] = load<4 x i32>,<4 x i32>* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[SECOND:%.*]] = load i32, i32* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = insertvalue [[UAGG:{<4 x i32>, i32 }]] undef,<4 x i32> [[FIRST]], 0
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = insertvalue [[UAGG]] [[T0]], i32 [[SECOND]], 1
end_comment

begin_comment
comment|// CHECK:   ret [[UAGG]] [[T1]]
end_comment

begin_comment
comment|// CHECK-LABEL: define {{.*}} @take_int5(<4 x i32>, i32)
end_comment

begin_comment
comment|// CHECK:   [[V:%.*]] = alloca [[REC]], align
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[REC]]* [[V]] to [[AGG]]*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   store<4 x i32> %0,<4 x i32>* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   store i32 %1, i32* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_comment
comment|// CHECK-LABEL: define void @test_int5()
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = alloca [[REC]], align
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = alloca [[REC]], align
end_comment

begin_comment
comment|// CHECK:   [[CALL:%.*]] = call [[SWIFTCC]] [[UAGG]] @return_int5()
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[REC]]* [[TMP1]] to [[AGG]]*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = extractvalue [[UAGG]] [[CALL]], 0
end_comment

begin_comment
comment|// CHECK:   store<4 x i32> [[T1]],<4 x i32>* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = extractvalue [[UAGG]] [[CALL]], 1
end_comment

begin_comment
comment|// CHECK:   store i32 [[T1]], i32* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[V:%.*]] = load [[REC]], [[REC]]* [[TMP1]], align
end_comment

begin_comment
comment|// CHECK:   store [[REC]] [[V]], [[REC]]* [[TMP2]], align
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[REC]]* [[TMP2]] to [[AGG]]*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[FIRST:%.*]] = load<4 x i32>,<4 x i32>* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds [[AGG]], [[AGG]]* [[CAST_TMP]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[SECOND:%.*]] = load i32, i32* [[T0]], align
end_comment

begin_comment
comment|// CHECK:   call [[SWIFTCC]] void @take_int5(<4 x i32> [[FIRST]], i32 [[SECOND]])
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|x
decl_stmt|;
name|int3
name|v
name|__attribute__
decl|((
name|packed
decl_stmt|)
block|)
struct|;
end_typedef

begin_empty_stmt
unit|} misaligned_int3
empty_stmt|;
end_empty_stmt

begin_macro
name|TEST
argument_list|(
argument|misaligned_int3
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define {{.*}} @take_misaligned_int3(i32, i32, i32, i32)
end_comment

end_unit

