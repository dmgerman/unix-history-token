begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -target-cpu core2 -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -target-cpu core2 -emit-llvm -o - %s | FileCheck %s --check-prefix=X86-64
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-ios9 -target-cpu cyclone -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-ios9 -target-cpu cyclone -emit-llvm -o - %s | FileCheck %s --check-prefix=ARM64
end_comment

begin_comment
comment|// REQUIRES: aarch64-registered-target,x86-registered-target
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
comment|// CHECK: [[STRUCT2_RESULT:@.*]] = private {{.*}} constant [[STRUCT2_TYPE:%.*]] { i32 0, i8 0, i8 undef, i8 0, float 0.000000e+00, float 0.000000e+00 }
end_comment

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
comment|// CHECK:       [[TEMP:%.*]] = alloca float*, align 8
end_comment

begin_comment
comment|// CHECK:       [[T0:%.*]] = load float*, float** [[ERRORARG:%.*]], align 8
end_comment

begin_comment
comment|// CHECK:       store float* [[T0]], float** [[TEMP]], align 8
end_comment

begin_comment
comment|// CHECK:       [[T0:%.*]] = load float*, float** [[TEMP]], align 8
end_comment

begin_comment
comment|// CHECK:       store float* [[T0]], float** [[ERRORARG]], align 8
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
comment|// CHECK:       [[ERROR:%.*]] = alloca float*, align 8
end_comment

begin_comment
comment|// CHECK:       [[TEMP:%.*]] = alloca swifterror float*, align 8
end_comment

begin_comment
comment|// CHECK:       [[T0:%.*]] = load float*, float** [[ERROR]], align 8
end_comment

begin_comment
comment|// CHECK:       store float* [[T0]], float** [[TEMP]], align 8
end_comment

begin_comment
comment|// CHECK:       call [[SWIFTCC:swiftcc]] void @context_error_1(i32* swiftself [[X]], float** swifterror [[TEMP]])
end_comment

begin_comment
comment|// CHECK:       [[T0:%.*]] = load float*, float** [[TEMP]], align 8
end_comment

begin_comment
comment|// CHECK:       store float* [[T0]], float** [[ERROR]], align 8
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
name|float3
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(3)));
end_typedef

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

begin_typedef
typedef|typedef
name|char
name|char16
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|short
name|short8
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(8)));
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|long2
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(2)));
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
comment|// CHECK-LABEL: define swiftcc { i64, i64 } @return_struct_1() {{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[RET:%.*]] = alloca [[STRUCT1:%.*]], align 4
end_comment

begin_comment
comment|// CHECK:   [[VAR:%.*]] = alloca [[STRUCT1]], align 4
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memset
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy
end_comment

begin_comment
comment|// CHECK:   [[CAST:%.*]] = bitcast [[STRUCT1]]* %retval to { i64, i64 }*
end_comment

begin_comment
comment|// CHECK:   [[GEP0:%.*]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* [[CAST]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = load i64, i64* [[GEP0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[GEP1:%.*]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* [[CAST]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = load i64, i64* [[GEP1]], align 4
end_comment

begin_comment
comment|// CHECK:   [[R0:%.*]] = insertvalue { i64, i64 } undef, i64 [[T0]], 0
end_comment

begin_comment
comment|// CHECK:   [[R1:%.*]] = insertvalue { i64, i64 } [[R0]], i64 [[T1]], 1
end_comment

begin_comment
comment|// CHECK:   ret { i64, i64 } [[R1]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_1(i64, i64) {{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[V:%.*]] = alloca [[STRUCT1:%.*]], align 4
end_comment

begin_comment
comment|// CHECK:   [[CAST:%.*]] = bitcast [[STRUCT1]]* [[V]] to { i64, i64 }*
end_comment

begin_comment
comment|// CHECK:   [[GEP0:%.*]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* [[CAST]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   store i64 %0, i64* [[GEP0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[GEP1:%.*]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* [[CAST]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   store i64 %1, i64* [[GEP1]], align 4
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_comment
comment|// CHECK-LABEL: define void @test_struct_1() {{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[AGG:%.*]] = alloca [[STRUCT1:%.*]], align 4
end_comment

begin_comment
comment|// CHECK:   [[RET:%.*]] = call swiftcc { i64, i64 } @return_struct_1()
end_comment

begin_comment
comment|// CHECK:   [[CAST:%.*]] = bitcast [[STRUCT1]]* [[AGG]] to { i64, i64 }*
end_comment

begin_comment
comment|// CHECK:   [[GEP0:%.*]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* [[CAST]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[E0:%.*]] = extractvalue { i64, i64 } [[RET]], 0
end_comment

begin_comment
comment|// CHECK:   store i64 [[E0]], i64* [[GEP0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[GEP1:%.*]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* [[CAST]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[E1:%.*]] = extractvalue { i64, i64 } [[RET]], 1
end_comment

begin_comment
comment|// CHECK:   store i64 [[E1]], i64* [[GEP1]], align 4
end_comment

begin_comment
comment|// CHECK:   [[CAST2:%.*]] = bitcast [[STRUCT1]]* [[AGG]] to { i64, i64 }*
end_comment

begin_comment
comment|// CHECK:   [[GEP2:%.*]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* [[CAST2]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[V0:%.*]] = load i64, i64* [[GEP2]], align 4
end_comment

begin_comment
comment|// CHECK:   [[GEP3:%.*]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* [[CAST2]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[V1:%.*]] = load i64, i64* [[GEP3]], align 4
end_comment

begin_comment
comment|// CHECK:   call swiftcc void @take_struct_1(i64 [[V0]], i64 [[V1]])
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_comment
comment|// CHECK: }
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
comment|// CHECK-LABEL: define swiftcc { i64, i64 } @return_struct_2() {{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[RET:%.*]] = alloca [[STRUCT2_TYPE]], align 4
end_comment

begin_comment
comment|// CHECK:   [[VAR:%.*]] = alloca [[STRUCT2_TYPE]], align 4
end_comment

begin_comment
comment|// CHECK:   [[CASTVAR:%.*]] = bitcast {{.*}} [[VAR]]
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy{{.*}}({{.*}}[[CASTVAR]], {{.*}}[[STRUCT2_RESULT]]
end_comment

begin_comment
comment|// CHECK:   [[CASTRET:%.*]] = bitcast {{.*}} [[RET]]
end_comment

begin_comment
comment|// CHECK:   [[CASTVAR:%.*]] = bitcast {{.*}} [[VAR]]
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy{{.*}}({{.*}}[[CASTRET]], {{.*}}[[CASTVAR]]
end_comment

begin_comment
comment|// CHECK:   [[CAST:%.*]] = bitcast [[STRUCT2_TYPE]]* [[RET]] to { i64, i64 }*
end_comment

begin_comment
comment|// CHECK:   [[GEP0:%.*]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* [[CAST]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = load i64, i64* [[GEP0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[GEP1:%.*]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* [[CAST]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = load i64, i64* [[GEP1]], align 4
end_comment

begin_comment
comment|// CHECK:   [[R0:%.*]] = insertvalue { i64, i64 } undef, i64 [[T0]], 0
end_comment

begin_comment
comment|// CHECK:   [[R1:%.*]] = insertvalue { i64, i64 } [[R0]], i64 [[T1]], 1
end_comment

begin_comment
comment|// CHECK:   ret { i64, i64 } [[R1]]
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_2(i64, i64) {{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[V:%.*]] = alloca [[STRUCT:%.*]], align 4
end_comment

begin_comment
comment|// CHECK:   [[CAST:%.*]] = bitcast [[STRUCT]]* [[V]] to { i64, i64 }*
end_comment

begin_comment
comment|// CHECK:   [[GEP0:%.*]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* [[CAST]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   store i64 %0, i64* [[GEP0]], align 4
end_comment

begin_comment
comment|// CHECK:   [[GEP1:%.*]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* [[CAST]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   store i64 %1, i64* [[GEP1]], align 4
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_comment
comment|// CHECK-LABEL: define void @test_struct_2() {{.*}} {
end_comment

begin_comment
comment|// CHECK:   [[TMP:%.*]] = alloca [[STRUCT2_TYPE]], align 4
end_comment

begin_comment
comment|// CHECK:   [[CALL:%.*]] = call swiftcc { i64, i64 } @return_struct_2()
end_comment

begin_comment
comment|// CHECK:   [[CAST_TMP:%.*]] = bitcast [[STRUCT2_TYPE]]* [[TMP]] to { i64, i64 }*
end_comment

begin_comment
comment|// CHECK:   [[GEP:%.*]] = getelementptr inbounds {{.*}} [[CAST_TMP]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = extractvalue { i64, i64 } [[CALL]], 0
end_comment

begin_comment
comment|// CHECK:   store i64 [[T0]], i64* [[GEP]], align 4
end_comment

begin_comment
comment|// CHECK:   [[GEP:%.*]] = getelementptr inbounds {{.*}} [[CAST_TMP]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = extractvalue { i64, i64 } [[CALL]], 1
end_comment

begin_comment
comment|// CHECK:   store i64 [[T0]], i64* [[GEP]], align 4
end_comment

begin_comment
comment|// CHECK:   [[CAST:%.*]] = bitcast [[STRUCT2_TYPE]]* [[TMP]] to { i64, i64 }*
end_comment

begin_comment
comment|// CHECK:   [[GEP:%.*]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* [[CAST]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[R0:%.*]] = load i64, i64* [[GEP]], align 4
end_comment

begin_comment
comment|// CHECK:   [[GEP:%.*]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* [[CAST]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[R1:%.*]] = load i64, i64* [[GEP]], align 4
end_comment

begin_comment
comment|// CHECK:   call swiftcc void @take_struct_2(i64 [[R0]], i64 [[R1]])
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_comment
comment|// CHECK: }
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
comment|// CHECK-LABEL: define swiftcc i64 @return_struct_misaligned_1()
end_comment

begin_comment
comment|// CHECK:  [[RET:%.*]] = alloca [[STRUCT:%.*]], align 1
end_comment

begin_comment
comment|// CHECK:  [[RES:%.*]] = alloca [[STRUCT]], align 1
end_comment

begin_comment
comment|// CHECK:  [[CAST:%.*]] = bitcast [[STRUCT]]* [[RES]] to i8*
end_comment

begin_comment
comment|// CHECK:  call void @llvm.memset{{.*}}(i8* [[CAST]], i8 0, i64 5
end_comment

begin_comment
comment|// CHECK:  [[CASTRET:%.*]] = bitcast [[STRUCT]]* [[RET]] to i8*
end_comment

begin_comment
comment|// CHECK:  [[CASTRES:%.*]] = bitcast [[STRUCT]]* [[RES]] to i8*
end_comment

begin_comment
comment|// CHECK:  call void @llvm.memcpy{{.*}}(i8* [[CASTRET]], i8* [[CASTRES]], i64 5
end_comment

begin_comment
comment|// CHECK:  [[CAST:%.*]] = bitcast [[STRUCT]]* [[RET]] to { i64 }*
end_comment

begin_comment
comment|// CHECK:  [[GEP:%.*]] = getelementptr inbounds { i64 }, { i64 }* [[CAST]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:  [[R0:%.*]] = load i64, i64* [[GEP]], align 1
end_comment

begin_comment
comment|// CHECK:  ret i64 [[R0]]
end_comment

begin_comment
comment|// CHECK:}
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_misaligned_1(i64) {{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[V:%.*]] = alloca [[STRUCT:%.*]], align 1
end_comment

begin_comment
comment|// CHECK:   [[CAST:%.*]] = bitcast [[STRUCT]]* [[V]] to { i64 }*
end_comment

begin_comment
comment|// CHECK:   [[GEP:%.*]] = getelementptr inbounds { i64 }, { i64 }* [[CAST]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   store i64 %0, i64* [[GEP]], align 1
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_comment
comment|// CHECK: define void @test_struct_misaligned_1() {{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[AGG:%.*]] = alloca [[STRUCT:%.*]], align 1
end_comment

begin_comment
comment|// CHECK:   [[CALL:%.*]] = call swiftcc i64 @return_struct_misaligned_1()
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = bitcast [[STRUCT]]* [[AGG]] to { i64 }*
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = getelementptr inbounds { i64 }, { i64 }* [[T0]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   store i64 [[CALL]], i64* [[T1]], align 1
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = bitcast [[STRUCT]]* [[AGG]] to { i64 }*
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = getelementptr inbounds { i64 }, { i64 }* [[T0]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[P:%.*]] = load i64, i64* [[T1]], align 1
end_comment

begin_comment
comment|// CHECK:   call swiftcc void @take_struct_misaligned_1(i64 [[P]])
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_comment
comment|// Too many scalars.
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|long
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
comment|// CHECK-LABEL: define swiftcc i64 @return_union_het_fp()
end_comment

begin_comment
comment|// CHECK:  [[RET:%.*]] = alloca [[UNION:%.*]], align 8
end_comment

begin_comment
comment|// CHECK:  [[RES:%.*]] = alloca [[UNION]], align 8
end_comment

begin_comment
comment|// CHECK:  [[CAST:%.*]] = bitcast [[UNION]]* [[RES]] to i8*
end_comment

begin_comment
comment|// CHECK:  call void @llvm.memcpy{{.*}}(i8* [[CAST]]
end_comment

begin_comment
comment|// CHECK:  [[CASTRET:%.*]] = bitcast [[UNION]]* [[RET]] to i8*
end_comment

begin_comment
comment|// CHECK:  [[CASTRES:%.*]] = bitcast [[UNION]]* [[RES]] to i8*
end_comment

begin_comment
comment|// CHECK:  call void @llvm.memcpy{{.*}}(i8* [[CASTRET]], i8* [[CASTRES]]
end_comment

begin_comment
comment|// CHECK:  [[CAST:%.*]] = bitcast [[UNION]]* [[RET]] to { i64 }*
end_comment

begin_comment
comment|// CHECK:  [[GEP:%.*]] = getelementptr inbounds { i64 }, { i64 }* [[CAST]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:  [[R0:%.*]] = load i64, i64* [[GEP]], align 8
end_comment

begin_comment
comment|// CHECK:  ret i64 [[R0]]
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_union_het_fp(i64) {{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[V:%.*]] = alloca [[UNION:%.*]], align 8
end_comment

begin_comment
comment|// CHECK:   [[CAST:%.*]] = bitcast [[UNION]]* [[V]] to { i64 }*
end_comment

begin_comment
comment|// CHECK:   [[GEP:%.*]] = getelementptr inbounds { i64 }, { i64 }* [[CAST]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   store i64 %0, i64* [[GEP]], align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_comment
comment|// CHECK: }
end_comment

begin_comment
comment|// CHECK-LABEL: define void @test_union_het_fp() {{.*}}{
end_comment

begin_comment
comment|// CHECK:   [[AGG:%.*]] = alloca [[UNION:%.*]], align 8
end_comment

begin_comment
comment|// CHECK:   [[CALL:%.*]] = call swiftcc i64 @return_union_het_fp()
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = bitcast [[UNION]]* [[AGG]] to { i64 }*
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = getelementptr inbounds { i64 }, { i64 }* [[T0]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   store i64 [[CALL]], i64* [[T1]], align 8
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = bitcast [[UNION]]* [[AGG]] to { i64 }*
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = getelementptr inbounds { i64 }, { i64 }* [[T0]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[V0:%.*]] = load i64, i64* [[T1]], align 8
end_comment

begin_comment
comment|// CHECK:   call swiftcc void @take_union_het_fp(i64 [[V0]])
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_comment
comment|// CHECK: }
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
comment|// CHECK: define void @test_union_hom_fp_partial()
end_comment

begin_comment
comment|// CHECK:   [[AGG:%.*]] = alloca [[UNION:%.*]], align 16
end_comment

begin_comment
comment|// CHECK:   [[CALL:%.*]] = call swiftcc { i64, i64 } @return_union_hom_fp_partial()
end_comment

begin_comment
comment|// CHECK:   [[CAST:%.*]] = bitcast [[UNION]]* [[AGG]] to { i64, i64 }*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* [[CAST]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = extractvalue { i64, i64 } [[CALL]], 0
end_comment

begin_comment
comment|// CHECK:   store i64 [[T1]], i64* [[T0]], align 16
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* [[CAST]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = extractvalue { i64, i64 } [[CALL]], 1
end_comment

begin_comment
comment|// CHECK:   store i64 [[T1]], i64* [[T0]], align 8
end_comment

begin_comment
comment|// CHECK:   [[CAST:%.*]] = bitcast [[UNION]]* [[AGG]] to { i64, i64 }*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* [[CAST]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[V0:%.*]] = load i64, i64* [[T0]], align 16
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* [[CAST]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[V1:%.*]] = load i64, i64* [[T0]], align 8
end_comment

begin_comment
comment|// CHECK:   call swiftcc void @take_union_hom_fp_partial(i64 [[V0]], i64 [[V1]])
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_comment
comment|// CHECK: }
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
comment|// CHECK:   [[AGG:%.*]] = alloca [[UNION:%.*]], align 16
end_comment

begin_comment
comment|// CHECK:   [[CALL:%.*]] = call swiftcc { i64, i64 } @return_union_het_fpv_partial()
end_comment

begin_comment
comment|// CHECK:   [[CAST:%.*]] = bitcast [[UNION]]* [[AGG]] to { i64, i64 }*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* [[CAST]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = extractvalue { i64, i64 } [[CALL]], 0
end_comment

begin_comment
comment|// CHECK:   store i64 [[T1]], i64* [[T0]], align 16
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* [[CAST]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[T1:%.*]] = extractvalue { i64, i64 } [[CALL]], 1
end_comment

begin_comment
comment|// CHECK:   store i64 [[T1]], i64* [[T0]], align 8
end_comment

begin_comment
comment|// CHECK:   [[CAST:%.*]] = bitcast [[UNION]]* [[AGG]] to { i64, i64 }*
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* [[CAST]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[V0:%.*]] = load i64, i64* [[T0]], align 16
end_comment

begin_comment
comment|// CHECK:   [[T0:%.*]] = getelementptr inbounds { i64, i64 }, { i64, i64 }* [[CAST]], i32 0, i32 1
end_comment

begin_comment
comment|// CHECK:   [[V1:%.*]] = load i64, i64* [[T0]], align 8
end_comment

begin_comment
comment|// CHECK:   call swiftcc void @take_union_het_fpv_partial(i64 [[V0]], i64 [[V1]])
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_comment
comment|// CHECK: }
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
comment|// CHECK:   [[RET:%.*]] = alloca [[REC:<8 x i32>]], align 16
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
comment|// CHECK:   [[RET:%.*]] = alloca [[REC:<5 x i32>]], align 16
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
comment|// CHECK-LABEL: define swiftcc void @take_misaligned_int3(i64, i64)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|float
name|f0
decl_stmt|;
block|}
name|struct_f1
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_f1
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc float @return_struct_f1()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_f1(float)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|float
name|f0
decl_stmt|;
name|float
name|f1
decl_stmt|;
block|}
name|struct_f2
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_f2
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc i64 @return_struct_f2()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_f2(i64)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|float
name|f0
decl_stmt|;
name|float
name|f1
decl_stmt|;
name|float
name|f2
decl_stmt|;
block|}
name|struct_f3
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_f3
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc { i64, float } @return_struct_f3()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_f3(i64, float)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|float
name|f0
decl_stmt|;
name|float
name|f1
decl_stmt|;
name|float
name|f2
decl_stmt|;
name|float
name|f3
decl_stmt|;
block|}
name|struct_f4
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_f4
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc { i64, i64 } @return_struct_f4()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_f4(i64, i64)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|double
name|d0
decl_stmt|;
block|}
name|struct_d1
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_d1
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc double @return_struct_d1()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_d1(double)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|double
name|d0
decl_stmt|;
name|double
name|d1
decl_stmt|;
block|}
name|struct_d2
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_d2
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc { double, double } @return_struct_d2()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_d2(double, double)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|double
name|d0
decl_stmt|;
name|double
name|d1
decl_stmt|;
name|double
name|d2
decl_stmt|;
block|}
name|struct_d3
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_d3
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc { double, double, double } @return_struct_d3()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_d3(double, double, double)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|double
name|d0
decl_stmt|;
name|double
name|d1
decl_stmt|;
name|double
name|d2
decl_stmt|;
name|double
name|d3
decl_stmt|;
block|}
name|struct_d4
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_d4
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc { double, double, double, double } @return_struct_d4()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_d4(double, double, double, double)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|double
name|d0
decl_stmt|;
name|double
name|d1
decl_stmt|;
name|double
name|d2
decl_stmt|;
name|double
name|d3
decl_stmt|;
name|double
name|d4
decl_stmt|;
block|}
name|struct_d5
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_d5
argument_list|)
end_macro

begin_comment
comment|// CHECK: define swiftcc void @return_struct_d5([[STRUCT5:%.*]]* noalias sret
end_comment

begin_comment
comment|// CHECK: define swiftcc void @take_struct_d5([[STRUCT5]]
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|c0
decl_stmt|;
block|}
name|struct_c1
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_c1
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc i8 @return_struct_c1()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_c1(i8)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|c0
decl_stmt|;
name|char
name|c1
decl_stmt|;
block|}
name|struct_c2
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_c2
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc i16 @return_struct_c2()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_c2(i16)
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|c0
decl_stmt|;
name|char
name|c1
decl_stmt|;
name|char
name|c2
decl_stmt|;
block|}
name|struct_c3
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_c3
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc i32 @return_struct_c3()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_c3(i32)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|c0
decl_stmt|;
name|char
name|c1
decl_stmt|;
name|char
name|c2
decl_stmt|;
name|char
name|c3
decl_stmt|;
block|}
name|struct_c4
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_c4
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc i32 @return_struct_c4()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_c4(i32)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|c0
decl_stmt|;
name|char
name|c1
decl_stmt|;
name|char
name|c2
decl_stmt|;
name|char
name|c3
decl_stmt|;
name|char
name|c4
decl_stmt|;
block|}
name|struct_c5
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_c5
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc i64 @return_struct_c5()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_c5(i64)
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|c0
decl_stmt|;
name|char
name|c1
decl_stmt|;
name|char
name|c2
decl_stmt|;
name|char
name|c3
decl_stmt|;
name|char
name|c4
decl_stmt|;
name|char
name|c5
decl_stmt|;
name|char
name|c6
decl_stmt|;
name|char
name|c7
decl_stmt|;
name|char
name|c8
decl_stmt|;
block|}
name|struct_c9
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_c9
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc { i64, i8 } @return_struct_c9()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_c9(i64, i8)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|s0
decl_stmt|;
block|}
name|struct_s1
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_s1
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc i16 @return_struct_s1()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_s1(i16)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|s0
decl_stmt|;
name|short
name|s1
decl_stmt|;
block|}
name|struct_s2
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_s2
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc i32 @return_struct_s2()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_s2(i32)
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|s0
decl_stmt|;
name|short
name|s1
decl_stmt|;
name|short
name|s2
decl_stmt|;
block|}
name|struct_s3
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_s3
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc i64 @return_struct_s3()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_s3(i64)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|s0
decl_stmt|;
name|short
name|s1
decl_stmt|;
name|short
name|s2
decl_stmt|;
name|short
name|s3
decl_stmt|;
block|}
name|struct_s4
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_s4
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc i64 @return_struct_s4()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_s4(i64)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|s0
decl_stmt|;
name|short
name|s1
decl_stmt|;
name|short
name|s2
decl_stmt|;
name|short
name|s3
decl_stmt|;
name|short
name|s4
decl_stmt|;
block|}
name|struct_s5
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_s5
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc { i64, i16 } @return_struct_s5()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_s5(i64, i16)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|i0
decl_stmt|;
block|}
name|struct_i1
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_i1
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc i32 @return_struct_i1()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_i1(i32)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|i0
decl_stmt|;
name|int
name|i1
decl_stmt|;
block|}
name|struct_i2
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_i2
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc i64 @return_struct_i2()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_i2(i64)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|i0
decl_stmt|;
name|int
name|i1
decl_stmt|;
name|int
name|i2
decl_stmt|;
block|}
name|struct_i3
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_i3
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc { i64, i32 } @return_struct_i3()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_i3(i64, i32)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|i0
decl_stmt|;
name|int
name|i1
decl_stmt|;
name|int
name|i2
decl_stmt|;
name|int
name|i3
decl_stmt|;
block|}
name|struct_i4
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_i4
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc { i64, i64 } @return_struct_i4()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_i4(i64, i64)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|long
name|l0
decl_stmt|;
block|}
name|struct_l1
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_l1
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc i64 @return_struct_l1()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_l1(i64)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|long
name|l0
decl_stmt|;
name|long
name|long
name|l1
decl_stmt|;
block|}
name|struct_l2
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_l2
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc { i64, i64 } @return_struct_l2()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_l2(i64, i64)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|long
name|l0
decl_stmt|;
name|long
name|long
name|l1
decl_stmt|;
name|long
name|long
name|l2
decl_stmt|;
block|}
name|struct_l3
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_l3
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc { i64, i64, i64 } @return_struct_l3()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_l3(i64, i64, i64)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|long
name|l0
decl_stmt|;
name|long
name|long
name|l1
decl_stmt|;
name|long
name|long
name|l2
decl_stmt|;
name|long
name|long
name|l3
decl_stmt|;
block|}
name|struct_l4
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_l4
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc { i64, i64, i64, i64 } @return_struct_l4()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_l4(i64, i64, i64, i64)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|long
name|l0
decl_stmt|;
name|long
name|long
name|l1
decl_stmt|;
name|long
name|long
name|l2
decl_stmt|;
name|long
name|long
name|l3
decl_stmt|;
name|long
name|long
name|l4
decl_stmt|;
block|}
name|struct_l5
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_l5
argument_list|)
end_macro

begin_comment
comment|// CHECK: define swiftcc void @return_struct_l5([[STRUCT5:%.*]]* noalias sret
end_comment

begin_comment
comment|// CHECK: define swiftcc void @take_struct_l5([[STRUCT5]]*
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char16
name|c0
decl_stmt|;
block|}
name|struct_vc1
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vc1
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc<16 x i8> @return_struct_vc1()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_vc1(<16 x i8>)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char16
name|c0
decl_stmt|;
name|char16
name|c1
decl_stmt|;
block|}
name|struct_vc2
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vc2
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc {<16 x i8>,<16 x i8> } @return_struct_vc2()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_vc2(<16 x i8>,<16 x i8>)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char16
name|c0
decl_stmt|;
name|char16
name|c1
decl_stmt|;
name|char16
name|c2
decl_stmt|;
block|}
name|struct_vc3
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vc3
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc {<16 x i8>,<16 x i8>,<16 x i8> } @return_struct_vc3()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_vc3(<16 x i8>,<16 x i8>,<16 x i8>)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char16
name|c0
decl_stmt|;
name|char16
name|c1
decl_stmt|;
name|char16
name|c2
decl_stmt|;
name|char16
name|c3
decl_stmt|;
block|}
name|struct_vc4
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vc4
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc {<16 x i8>,<16 x i8>,<16 x i8>,<16 x i8> } @return_struct_vc4()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_vc4(<16 x i8>,<16 x i8>,<16 x i8>,<16 x i8>)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char16
name|c0
decl_stmt|;
name|char16
name|c1
decl_stmt|;
name|char16
name|c2
decl_stmt|;
name|char16
name|c3
decl_stmt|;
name|char16
name|c4
decl_stmt|;
block|}
name|struct_vc5
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vc5
argument_list|)
end_macro

begin_comment
comment|// CHECK: define swiftcc void @return_struct_vc5([[STRUCT:%.*]]* noalias sret
end_comment

begin_comment
comment|// CHECK: define swiftcc void @take_struct_vc5([[STRUCT]]
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short8
name|c0
decl_stmt|;
block|}
name|struct_vs1
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vs1
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc<8 x i16> @return_struct_vs1()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_vs1(<8 x i16>)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short8
name|c0
decl_stmt|;
name|short8
name|c1
decl_stmt|;
block|}
name|struct_vs2
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vs2
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc {<8 x i16>,<8 x i16> } @return_struct_vs2()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_vs2(<8 x i16>,<8 x i16>)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short8
name|c0
decl_stmt|;
name|short8
name|c1
decl_stmt|;
name|short8
name|c2
decl_stmt|;
block|}
name|struct_vs3
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vs3
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc {<8 x i16>,<8 x i16>,<8 x i16> } @return_struct_vs3()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_vs3(<8 x i16>,<8 x i16>,<8 x i16>)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short8
name|c0
decl_stmt|;
name|short8
name|c1
decl_stmt|;
name|short8
name|c2
decl_stmt|;
name|short8
name|c3
decl_stmt|;
block|}
name|struct_vs4
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vs4
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc {<8 x i16>,<8 x i16>,<8 x i16>,<8 x i16> } @return_struct_vs4()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_vs4(<8 x i16>,<8 x i16>,<8 x i16>,<8 x i16>)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short8
name|c0
decl_stmt|;
name|short8
name|c1
decl_stmt|;
name|short8
name|c2
decl_stmt|;
name|short8
name|c3
decl_stmt|;
name|short8
name|c4
decl_stmt|;
block|}
name|struct_vs5
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vs5
argument_list|)
end_macro

begin_comment
comment|// CHECK: define swiftcc void @return_struct_vs5([[STRUCT:%.*]]* noalias sret
end_comment

begin_comment
comment|// CHECK: define swiftcc void @take_struct_vs5([[STRUCT]]
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int4
name|c0
decl_stmt|;
block|}
name|struct_vi1
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vi1
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc<4 x i32> @return_struct_vi1()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_vi1(<4 x i32>)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int4
name|c0
decl_stmt|;
name|int4
name|c1
decl_stmt|;
block|}
name|struct_vi2
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vi2
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc {<4 x i32>,<4 x i32> } @return_struct_vi2()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_vi2(<4 x i32>,<4 x i32>)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int4
name|c0
decl_stmt|;
name|int4
name|c1
decl_stmt|;
name|int4
name|c2
decl_stmt|;
block|}
name|struct_vi3
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vi3
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc {<4 x i32>,<4 x i32>,<4 x i32> } @return_struct_vi3()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_vi3(<4 x i32>,<4 x i32>,<4 x i32>)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int4
name|c0
decl_stmt|;
name|int4
name|c1
decl_stmt|;
name|int4
name|c2
decl_stmt|;
name|int4
name|c3
decl_stmt|;
block|}
name|struct_vi4
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vi4
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc {<4 x i32>,<4 x i32>,<4 x i32>,<4 x i32> } @return_struct_vi4()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_vi4(<4 x i32>,<4 x i32>,<4 x i32>,<4 x i32>)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int4
name|c0
decl_stmt|;
name|int4
name|c1
decl_stmt|;
name|int4
name|c2
decl_stmt|;
name|int4
name|c3
decl_stmt|;
name|int4
name|c4
decl_stmt|;
block|}
name|struct_vi5
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vi5
argument_list|)
end_macro

begin_comment
comment|// CHECK: define swiftcc void @return_struct_vi5([[STRUCT:%.*]]* noalias sret
end_comment

begin_comment
comment|// CHECK: define swiftcc void @take_struct_vi5([[STRUCT]]
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long2
name|c0
decl_stmt|;
block|}
name|struct_vl1
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vl1
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc<2 x i64> @return_struct_vl1()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_vl1(<2 x i64>)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long2
name|c0
decl_stmt|;
name|long2
name|c1
decl_stmt|;
name|long2
name|c2
decl_stmt|;
name|long2
name|c3
decl_stmt|;
block|}
name|struct_vl4
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vl4
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc {<2 x i64>,<2 x i64>,<2 x i64>,<2 x i64> } @return_struct_vl4()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_vl4(<2 x i64>,<2 x i64>,<2 x i64>,<2 x i64>)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long2
name|c0
decl_stmt|;
name|long2
name|c1
decl_stmt|;
name|long2
name|c2
decl_stmt|;
name|long2
name|c3
decl_stmt|;
name|long2
name|c4
decl_stmt|;
block|}
name|struct_vl5
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vl5
argument_list|)
end_macro

begin_comment
comment|// CHECK: define swiftcc void @return_struct_vl5([[STRUCT:%.*]]* noalias sret
end_comment

begin_comment
comment|// CHECK: define swiftcc void @take_struct_vl5([[STRUCT]]
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|double2
name|c0
decl_stmt|;
block|}
name|struct_vd1
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vd1
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc<2 x double> @return_struct_vd1()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_vd1(<2 x double>)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|double2
name|c0
decl_stmt|;
name|double2
name|c1
decl_stmt|;
name|double2
name|c2
decl_stmt|;
name|double2
name|c3
decl_stmt|;
block|}
name|struct_vd4
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vd4
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc {<2 x double>,<2 x double>,<2 x double>,<2 x double> } @return_struct_vd4()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_vd4(<2 x double>,<2 x double>,<2 x double>,<2 x double>)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|double2
name|c0
decl_stmt|;
name|double2
name|c1
decl_stmt|;
name|double2
name|c2
decl_stmt|;
name|double2
name|c3
decl_stmt|;
name|double2
name|c4
decl_stmt|;
block|}
name|struct_vd5
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vd5
argument_list|)
end_macro

begin_comment
comment|// CHECK: define swiftcc void @return_struct_vd5([[STRUCT:%.*]]* noalias sret
end_comment

begin_comment
comment|// CHECK: define swiftcc void @take_struct_vd5([[STRUCT]]
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|double4
name|c0
decl_stmt|;
block|}
name|struct_vd41
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vd41
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc {<2 x double>,<2 x double> } @return_struct_vd41()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_vd41(<2 x double>,<2 x double>)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|double4
name|c0
decl_stmt|;
name|double4
name|c1
decl_stmt|;
block|}
name|struct_vd42
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vd42
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc {<2 x double>,<2 x double>,<2 x double>,<2 x double> } @return_struct_vd42()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_vd42(<2 x double>,<2 x double>,<2 x double>,<2 x double>)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|double4
name|c0
decl_stmt|;
name|double4
name|c1
decl_stmt|;
name|double4
name|c2
decl_stmt|;
block|}
name|struct_vd43
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vd43
argument_list|)
end_macro

begin_comment
comment|// CHECK: define swiftcc void @return_struct_vd43([[STRUCT:%.*]]* noalias sret
end_comment

begin_comment
comment|// CHECK: define swiftcc void @take_struct_vd43([[STRUCT]]
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|float4
name|c0
decl_stmt|;
block|}
name|struct_vf1
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vf1
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc<4 x float> @return_struct_vf1()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_vf1(<4 x float>)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|float4
name|c0
decl_stmt|;
name|float4
name|c1
decl_stmt|;
block|}
name|struct_vf2
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vf2
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc {<4 x float>,<4 x float> } @return_struct_vf2()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_vf2(<4 x float>,<4 x float>)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|float4
name|c0
decl_stmt|;
name|float4
name|c1
decl_stmt|;
name|float4
name|c2
decl_stmt|;
name|float4
name|c3
decl_stmt|;
block|}
name|struct_vf4
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vf4
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc {<4 x float>,<4 x float>,<4 x float>,<4 x float> } @return_struct_vf4()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_vf4(<4 x float>,<4 x float>,<4 x float>,<4 x float>)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|float4
name|c0
decl_stmt|;
name|float4
name|c1
decl_stmt|;
name|float4
name|c2
decl_stmt|;
name|float4
name|c3
decl_stmt|;
name|float4
name|c4
decl_stmt|;
block|}
name|struct_vf5
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vf5
argument_list|)
end_macro

begin_comment
comment|// CHECK: define swiftcc void @return_struct_vf5([[STRUCT:%.*]]* noalias sret
end_comment

begin_comment
comment|// CHECK: define swiftcc void @take_struct_vf5([[STRUCT]]
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|float8
name|c0
decl_stmt|;
block|}
name|struct_vf81
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_vf81
argument_list|)
end_macro

begin_comment
comment|// CHECK-LABEL: define swiftcc {<4 x float>,<4 x float> } @return_struct_vf81()
end_comment

begin_comment
comment|// CHECK-LABEL: define swiftcc void @take_struct_vf81(<4 x float>,<4 x float>)
end_comment

begin_comment
comment|// Don't crash.
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|int4
name|v
index|[
literal|2
index|]
decl_stmt|;
struct|struct
block|{
name|int
name|LSW
decl_stmt|;
name|int
name|d7
decl_stmt|;
name|int
name|d6
decl_stmt|;
name|int
name|d5
decl_stmt|;
name|int
name|d4
decl_stmt|;
name|int
name|d3
decl_stmt|;
name|int
name|d2
decl_stmt|;
name|int
name|MSW
decl_stmt|;
block|}
name|s
struct|;
block|}
name|union_het_vecint
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|union_het_vecint
argument_list|)
end_macro

begin_comment
comment|// CHECK: define swiftcc void @return_union_het_vecint([[UNION:%.*]]* noalias sret
end_comment

begin_comment
comment|// CHECK: define swiftcc void @take_union_het_vecint([[UNION]]*
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|float3
name|f3
decl_stmt|;
block|}
name|struct_v1f3
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|struct_v1f3
argument_list|)
end_macro

begin_comment
comment|// ARM64-LABEL: define swiftcc {<2 x float>, float } @return_struct_v1f3()
end_comment

begin_comment
comment|// ARM64-LABEL: define swiftcc void @take_struct_v1f3(<2 x float>, float)
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int3
name|vect
decl_stmt|;
name|unsigned
name|long
name|long
name|val
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|padded_alloc_size_vector
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|padded_alloc_size_vector
argument_list|)
end_macro

begin_comment
comment|// X86-64-LABEL: take_padded_alloc_size_vector(<3 x i32>, i64)
end_comment

begin_comment
comment|// X86-64-NOT: [4 x i8]
end_comment

begin_comment
comment|// x86-64: ret void
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|float
name|f1
decl_stmt|;
name|float3
name|fv2
decl_stmt|;
block|}
name|union_hom_fp_partial2
typedef|;
end_typedef

begin_macro
name|TEST
argument_list|(
argument|union_hom_fp_partial2
argument_list|)
end_macro

begin_comment
comment|// X86-64-LABEL: take_union_hom_fp_partial2(i64, float)
end_comment

begin_comment
comment|// ARM64-LABEL: take_union_hom_fp_partial2(i64, float)
end_comment

end_unit

