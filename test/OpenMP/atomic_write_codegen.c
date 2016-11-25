begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -triple x86_64-apple-darwin10 -fopenmp -x c -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fopenmp -x c -triple x86_64-apple-darwin10 -emit-pch -o %t %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fopenmp -x c -triple x86_64-apple-darwin10 -include-pch %t -verify %s -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER
end_ifndef

begin_define
define|#
directive|define
name|HEADER
end_define

begin_decl_stmt
name|_Bool
name|bv
decl_stmt|,
name|bx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|cv
decl_stmt|,
name|cx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|char
name|ucv
decl_stmt|,
name|ucx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|sv
decl_stmt|,
name|sx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|short
name|usv
decl_stmt|,
name|usx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|iv
decl_stmt|,
name|ix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|int
name|uiv
decl_stmt|,
name|uix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|lv
decl_stmt|,
name|lx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|ulv
decl_stmt|,
name|ulx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|long
name|llv
decl_stmt|,
name|llx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|long
name|ullv
decl_stmt|,
name|ullx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|fv
decl_stmt|,
name|fx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|dv
decl_stmt|,
name|dx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|double
name|ldv
decl_stmt|,
name|ldx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|_Complex
name|int
name|civ
decl_stmt|,
name|cix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|_Complex
name|float
name|cfv
decl_stmt|,
name|cfx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|_Complex
name|double
name|cdv
decl_stmt|,
name|cdx
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
name|int4
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_decl_stmt
name|int4
name|int4x
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|BitFields
block|{
name|int
label|:
literal|32
expr_stmt|;
name|int
name|a
range|:
literal|31
decl_stmt|;
block|}
name|bfx
struct|;
end_struct

begin_struct
struct|struct
name|BitFields_packed
block|{
name|int
label|:
literal|32
expr_stmt|;
name|int
name|a
range|:
literal|31
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
name|bfx_packed
struct|;
end_struct

begin_struct
struct|struct
name|BitFields2
block|{
name|int
label|:
literal|31
expr_stmt|;
name|int
name|a
range|:
literal|1
decl_stmt|;
block|}
name|bfx2
struct|;
end_struct

begin_struct
struct|struct
name|BitFields2_packed
block|{
name|int
label|:
literal|31
expr_stmt|;
name|int
name|a
range|:
literal|1
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
name|bfx2_packed
struct|;
end_struct

begin_struct
struct|struct
name|BitFields3
block|{
name|int
label|:
literal|11
expr_stmt|;
name|int
name|a
range|:
literal|14
decl_stmt|;
block|}
name|bfx3
struct|;
end_struct

begin_struct
struct|struct
name|BitFields3_packed
block|{
name|int
label|:
literal|11
expr_stmt|;
name|int
name|a
range|:
literal|14
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
name|bfx3_packed
struct|;
end_struct

begin_struct
struct|struct
name|BitFields4
block|{
name|short
label|:
literal|16
expr_stmt|;
name|int
name|a
range|:
literal|1
decl_stmt|;
name|long
name|b
range|:
literal|7
decl_stmt|;
block|}
name|bfx4
struct|;
end_struct

begin_struct
struct|struct
name|BitFields4_packed
block|{
name|short
label|:
literal|16
expr_stmt|;
name|int
name|a
range|:
literal|1
decl_stmt|;
name|long
name|b
range|:
literal|7
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
name|bfx4_packed
struct|;
end_struct

begin_typedef
typedef|typedef
name|float
name|float2
name|__attribute__
typedef|((
name|ext_vector_type
typedef|(2)));
end_typedef

begin_decl_stmt
name|float2
name|float2x
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Register "0" is currently an invalid register for global register variables.
end_comment

begin_comment
comment|// Use "esp" instead of "0".
end_comment

begin_comment
comment|// register int rix __asm__("0");
end_comment

begin_decl_stmt
specifier|register
name|int
name|rix
name|__asm__
argument_list|(
literal|"esp"
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// CHECK: store atomic i32 1, i32* getelementptr inbounds ({ i32, i32 }, { i32, i32 }* @civ, i32 0, i32 1) monotonic,
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|__imag
argument_list|(
name|civ
argument_list|)
operator|=
literal|1
expr_stmt|;
comment|// CHECK: load i8, i8*
comment|// CHECK: store atomic i8
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|bx
operator|=
name|bv
expr_stmt|;
comment|// CHECK: load i8, i8*
comment|// CHECK: store atomic i8
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|cx
operator|=
name|cv
expr_stmt|;
comment|// CHECK: load i8, i8*
comment|// CHECK: store atomic i8
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|ucx
operator|=
name|ucv
expr_stmt|;
comment|// CHECK: load i16, i16*
comment|// CHECK: store atomic i16
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|sx
operator|=
name|sv
expr_stmt|;
comment|// CHECK: load i16, i16*
comment|// CHECK: store atomic i16
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|usx
operator|=
name|usv
expr_stmt|;
comment|// CHECK: load i32, i32*
comment|// CHECK: store atomic i32
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|ix
operator|=
name|iv
expr_stmt|;
comment|// CHECK: load i32, i32*
comment|// CHECK: store atomic i32
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|uix
operator|=
name|uiv
expr_stmt|;
comment|// CHECK: load i64, i64*
comment|// CHECK: store atomic i64
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|lx
operator|=
name|lv
expr_stmt|;
comment|// CHECK: load i64, i64*
comment|// CHECK: store atomic i64
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|ulx
operator|=
name|ulv
expr_stmt|;
comment|// CHECK: load i64, i64*
comment|// CHECK: store atomic i64
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|llx
operator|=
name|llv
expr_stmt|;
comment|// CHECK: load i64, i64*
comment|// CHECK: store atomic i64
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|ullx
operator|=
name|ullv
expr_stmt|;
comment|// CHECK: load float, float*
comment|// CHECK: bitcast float {{.*}} to i32
comment|// CHECK: store atomic i32 {{.*}}, i32* bitcast (float*
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|fx
operator|=
name|fv
expr_stmt|;
comment|// CHECK: load double, double*
comment|// CHECK: bitcast double {{.*}} to i64
comment|// CHECK: store atomic i64 {{.*}}, i64* bitcast (double*
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|dx
operator|=
name|dv
expr_stmt|;
comment|// CHECK: [[LD:%.+]] = load x86_fp80, x86_fp80*
comment|// CHECK: [[BITCAST:%.+]] = bitcast x86_fp80* [[LDTEMP:%.*]] to i8*
comment|// CHECK: call void @llvm.memset.p0i8.i64(i8* [[BITCAST]], i8 0, i64 16, i32 16, i1 false)
comment|// CHECK: store x86_fp80 [[LD]], x86_fp80* [[LDTEMP]]
comment|// CHECK: [[BITCAST:%.+]] = bitcast x86_fp80* [[LDTEMP:%.*]] to i128*
comment|// CHECK: [[LD:%.+]] = load i128, i128* [[BITCAST]]
comment|// CHECK: store atomic i128 [[LD]], i128* bitcast (x86_fp80*
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|ldx
operator|=
name|ldv
expr_stmt|;
comment|// CHECK: [[REAL_VAL:%.+]] = load i32, i32* getelementptr inbounds ({ i32, i32 }, { i32, i32 }* @{{.*}}, i32 0, i32 0)
comment|// CHECK: [[IMG_VAL:%.+]] = load i32, i32* getelementptr inbounds ({ i32, i32 }, { i32, i32 }* @{{.*}}, i32 0, i32 1)
comment|// CHECK: [[TEMP_REAL_REF:%.+]] = getelementptr inbounds { i32, i32 }, { i32, i32 }* [[TEMP:%.+]], i32 0, i32 0
comment|// CHECK: [[TEMP_IMG_REF:%.+]] = getelementptr inbounds { i32, i32 }, { i32, i32 }* [[TEMP]], i32 0, i32 1
comment|// CHECK: store i32 [[REAL_VAL]], i32* [[TEMP_REAL_REF]]
comment|// CHECK: store i32 [[IMG_VAL]], i32* [[TEMP_IMG_REF]]
comment|// CHECK: [[BITCAST:%.+]] = bitcast { i32, i32 }* [[TEMP]] to i8*
comment|// CHECK: call void @__atomic_store(i64 8, i8* bitcast ({ i32, i32 }* @{{.*}} to i8*), i8* [[BITCAST]], i32 0)
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|cix
operator|=
name|civ
expr_stmt|;
comment|// CHECK: [[REAL_VAL:%.+]] = load float, float* getelementptr inbounds ({ float, float }, { float, float }* @{{.*}}, i32 0, i32 0)
comment|// CHECK: [[IMG_VAL:%.+]] = load float, float* getelementptr inbounds ({ float, float }, { float, float }* @{{.*}}, i32 0, i32 1)
comment|// CHECK: [[TEMP_REAL_REF:%.+]] = getelementptr inbounds { float, float }, { float, float }* [[TEMP:%.+]], i32 0, i32 0
comment|// CHECK: [[TEMP_IMG_REF:%.+]] = getelementptr inbounds { float, float }, { float, float }* [[TEMP]], i32 0, i32 1
comment|// CHECK: store float [[REAL_VAL]], float* [[TEMP_REAL_REF]]
comment|// CHECK: store float [[IMG_VAL]], float* [[TEMP_IMG_REF]]
comment|// CHECK: [[BITCAST:%.+]] = bitcast { float, float }* [[TEMP]] to i8*
comment|// CHECK: call void @__atomic_store(i64 8, i8* bitcast ({ float, float }* @{{.*}} to i8*), i8* [[BITCAST]], i32 0)
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|cfx
operator|=
name|cfv
expr_stmt|;
comment|// CHECK: [[REAL_VAL:%.+]] = load double, double* getelementptr inbounds ({ double, double }, { double, double }* @{{.*}}, i32 0, i32 0)
comment|// CHECK: [[IMG_VAL:%.+]] = load double, double* getelementptr inbounds ({ double, double }, { double, double }* @{{.*}}, i32 0, i32 1)
comment|// CHECK: [[TEMP_REAL_REF:%.+]] = getelementptr inbounds { double, double }, { double, double }* [[TEMP:%.+]], i32 0, i32 0
comment|// CHECK: [[TEMP_IMG_REF:%.+]] = getelementptr inbounds { double, double }, { double, double }* [[TEMP]], i32 0, i32 1
comment|// CHECK: store double [[REAL_VAL]], double* [[TEMP_REAL_REF]]
comment|// CHECK: store double [[IMG_VAL]], double* [[TEMP_IMG_REF]]
comment|// CHECK: [[BITCAST:%.+]] = bitcast { double, double }* [[TEMP]] to i8*
comment|// CHECK: call void @__atomic_store(i64 16, i8* bitcast ({ double, double }* @{{.*}} to i8*), i8* [[BITCAST]], i32 5)
comment|// CHECK: call{{.*}} @__kmpc_flush(
pragma|#
directive|pragma
name|omp
name|atomic
name|seq_cst
name|write
name|cdx
operator|=
name|cdv
expr_stmt|;
comment|// CHECK: load i8, i8*
comment|// CHECK: store atomic i64
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|ulx
operator|=
name|bv
expr_stmt|;
comment|// CHECK: load i8, i8*
comment|// CHECK: store atomic i8
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|bx
operator|=
name|cv
expr_stmt|;
comment|// CHECK: load i8, i8*
comment|// CHECK: store atomic i8
comment|// CHECK: call{{.*}} @__kmpc_flush(
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|,
name|seq_cst
name|cx
operator|=
name|ucv
expr_stmt|;
comment|// CHECK: load i16, i16*
comment|// CHECK: store atomic i64
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|ulx
operator|=
name|sv
expr_stmt|;
comment|// CHECK: load i16, i16*
comment|// CHECK: store atomic i64
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|lx
operator|=
name|usv
expr_stmt|;
comment|// CHECK: load i32, i32*
comment|// CHECK: store atomic i32
comment|// CHECK: call{{.*}} @__kmpc_flush(
pragma|#
directive|pragma
name|omp
name|atomic
name|seq_cst
name|,
name|write
name|uix
operator|=
name|iv
expr_stmt|;
comment|// CHECK: load i32, i32*
comment|// CHECK: store atomic i32
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|ix
operator|=
name|uiv
expr_stmt|;
comment|// CHECK: load i64, i64*
comment|// CHECK: [[VAL:%.+]] = trunc i64 %{{.*}} to i32
comment|// CHECK: [[TEMP_REAL_REF:%.+]] = getelementptr inbounds { i32, i32 }, { i32, i32 }* [[TEMP:%.+]], i32 0, i32 0
comment|// CHECK: [[TEMP_IMG_REF:%.+]] = getelementptr inbounds { i32, i32 }, { i32, i32 }* [[TEMP]], i32 0, i32 1
comment|// CHECK: store i32 [[VAL]], i32* [[TEMP_REAL_REF]]
comment|// CHECK: store i32 0, i32* [[TEMP_IMG_REF]]
comment|// CHECK: [[BITCAST:%.+]] = bitcast { i32, i32 }* [[TEMP]] to i8*
comment|// CHECK: call void @__atomic_store(i64 8, i8* bitcast ({ i32, i32 }* @{{.+}} to i8*), i8* [[BITCAST]], i32 0)
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|cix
operator|=
name|lv
expr_stmt|;
comment|// CHECK: load i64, i64*
comment|// CHECK: store atomic i32 %{{.+}}, i32* bitcast (float*
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|fx
operator|=
name|ulv
expr_stmt|;
comment|// CHECK: load i64, i64*
comment|// CHECK: store atomic i64 %{{.+}}, i64* bitcast (double*
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|dx
operator|=
name|llv
expr_stmt|;
comment|// CHECK: load i64, i64*
comment|// CHECK: [[VAL:%.+]] = uitofp i64 %{{.+}} to x86_fp80
comment|// CHECK: [[BITCAST:%.+]] = bitcast x86_fp80* [[TEMP:%.+]] to i8*
comment|// CHECK: call void @llvm.memset.p0i8.i64(i8* [[BITCAST]], i8 0, i64 16, i32 16, i1 false)
comment|// CHECK: store x86_fp80 [[VAL]], x86_fp80* [[TEMP]]
comment|// CHECK: [[BITCAST:%.+]] = bitcast x86_fp80* [[TEMP]] to i128*
comment|// CHECK: [[VAL:%.+]] = load i128, i128* [[BITCAST]]
comment|// CHECK: store atomic i128 [[VAL]], i128* bitcast (x86_fp80*
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|ldx
operator|=
name|ullv
expr_stmt|;
comment|// CHECK: load float, float*
comment|// CHECK: [[VAL:%.+]] = fptosi float %{{.*}} to i32
comment|// CHECK: [[TEMP_REAL_REF:%.+]] = getelementptr inbounds { i32, i32 }, { i32, i32 }* [[TEMP:%.+]], i32 0, i32 0
comment|// CHECK: [[TEMP_IMG_REF:%.+]] = getelementptr inbounds { i32, i32 }, { i32, i32 }* [[TEMP]], i32 0, i32 1
comment|// CHECK: store i32 [[VAL]], i32* [[TEMP_REAL_REF]]
comment|// CHECK: store i32 0, i32* [[TEMP_IMG_REF]]
comment|// CHECK: [[BITCAST:%.+]] = bitcast { i32, i32 }* [[TEMP]] to i8*
comment|// CHECK: call void @__atomic_store(i64 8, i8* bitcast ({ i32, i32 }* @{{.+}} to i8*), i8* [[BITCAST]], i32 0)
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|cix
operator|=
name|fv
expr_stmt|;
comment|// CHECK: load double, double*
comment|// CHECK: store atomic i16
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|sx
operator|=
name|dv
expr_stmt|;
comment|// CHECK: load x86_fp80, x86_fp80*
comment|// CHECK: store atomic i8
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|bx
operator|=
name|ldv
expr_stmt|;
comment|// CHECK: load i32, i32* getelementptr inbounds ({ i32, i32 }, { i32, i32 }* @{{.+}}, i32 0, i32 0)
comment|// CHECK: load i32, i32* getelementptr inbounds ({ i32, i32 }, { i32, i32 }* @{{.+}}, i32 0, i32 1)
comment|// CHECK: icmp ne i32 %{{.+}}, 0
comment|// CHECK: icmp ne i32 %{{.+}}, 0
comment|// CHECK: or i1
comment|// CHECK: store atomic i8
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|bx
operator|=
name|civ
expr_stmt|;
comment|// CHECK: load float, float* getelementptr inbounds ({ float, float }, { float, float }* @{{.*}}, i32 0, i32 0)
comment|// CHECK: store atomic i16
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|usx
operator|=
name|cfv
expr_stmt|;
comment|// CHECK: load double, double* getelementptr inbounds ({ double, double }, { double, double }* @{{.+}}, i32 0, i32 0)
comment|// CHECK: store atomic i64
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|llx
operator|=
name|cdv
expr_stmt|;
comment|// CHECK-DAG: [[IDX:%.+]] = load i16, i16* @{{.+}}
comment|// CHECK-DAG: load i8, i8*
comment|// CHECK-DAG: [[VEC_ITEM_VAL:%.+]] = zext i1 %{{.+}} to i32
comment|// CHECK: [[I128VAL:%.+]] = load atomic i128, i128* bitcast (<4 x i32>* [[DEST:@.+]] to i128*) monotonic
comment|// CHECK: br label %[[CONT:.+]]
comment|// CHECK: [[CONT]]
comment|// CHECK: [[OLD_I128:%.+]] = phi i128 [ [[I128VAL]], %{{.+}} ], [ [[FAILED_I128_OLD_VAL:%.+]], %[[CONT]] ]
comment|// CHECK: [[BITCAST:%.+]] = bitcast<4 x i32>* [[LDTEMP:%.+]] to i128*
comment|// CHECK: store i128 [[OLD_I128]], i128* [[BITCAST]],
comment|// CHECK: [[VEC_VAL:%.+]] = load<4 x i32>,<4 x i32>* [[LDTEMP]]
comment|// CHECK: [[NEW_VEC_VAL:%.+]] = insertelement<4 x i32> [[VEC_VAL]], i32 [[VEC_ITEM_VAL]], i16 [[IDX]]
comment|// CHECK: store<4 x i32> [[NEW_VEC_VAL]],<4 x i32>* [[LDTEMP]]
comment|// CHECK: [[NEW_I128:%.+]] = load i128, i128* [[BITCAST]]
comment|// CHECK: [[RES:%.+]] = cmpxchg i128* bitcast (<4 x i32>* [[DEST]] to i128*), i128 [[OLD_I128]], i128 [[NEW_I128]] monotonic monotonic
comment|// CHECK: [[FAILED_I128_OLD_VAL:%.+]] = extractvalue { i128, i1 } [[RES]], 0
comment|// CHECK: [[FAIL_SUCCESS:%.+]] = extractvalue { i128, i1 } [[RES]], 1
comment|// CHECK: br i1 [[FAIL_SUCCESS]], label %[[EXIT:.+]], label %[[CONT]]
comment|// CHECK: [[EXIT]]
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|int4x
index|[
name|sv
index|]
operator|=
name|bv
expr_stmt|;
comment|// CHECK: load x86_fp80, x86_fp80* @{{.+}}
comment|// CHECK: [[NEW_VAL:%.+]] = fptosi x86_fp80 %{{.+}} to i32
comment|// CHECK: [[PREV_VALUE:%.+]] = load atomic i32, i32* bitcast (i8* getelementptr (i8, i8* bitcast (%struct.BitFields* @{{.+}} to i8*), i64 4) to i32*) monotonic
comment|// CHECK: br label %[[CONT:.+]]
comment|// CHECK: [[CONT]]
comment|// CHECK: [[OLD_BF_VALUE:%.+]] = phi i32 [ [[PREV_VALUE]], %[[EXIT]] ], [ [[FAILED_OLD_VAL:%.+]], %[[CONT]] ]
comment|// CHECK: [[BF_VALUE:%.+]] = and i32 [[NEW_VAL]], 2147483647
comment|// CHECK: [[BF_CLEAR:%.+]] = and i32 %{{.+}}, -2147483648
comment|// CHECK: or i32 [[BF_CLEAR]], [[BF_VALUE]]
comment|// CHECK: store i32 %{{.+}}, i32* [[LDTEMP:%.+]]
comment|// CHECK: [[NEW_BF_VALUE:%.+]] = load i32, i32* [[LDTEMP]]
comment|// CHECK: [[RES:%.+]] = cmpxchg i32* bitcast (i8* getelementptr (i8, i8* bitcast (%struct.BitFields* @{{.+}} to i8*), i64 4) to i32*), i32 [[OLD_BF_VALUE]], i32 [[NEW_BF_VALUE]] monotonic monotonic
comment|// CHECK: [[FAILED_OLD_VAL]] = extractvalue { i32, i1 } [[RES]], 0
comment|// CHECK: [[FAIL_SUCCESS:%.+]] = extractvalue { i32, i1 } [[RES]], 1
comment|// CHECK: br i1 [[FAIL_SUCCESS]], label %[[EXIT:.+]], label %[[CONT]]
comment|// CHECK: [[EXIT]]
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|bfx
operator|.
name|a
operator|=
name|ldv
expr_stmt|;
comment|// CHECK: load x86_fp80, x86_fp80* @{{.+}}
comment|// CHECK: [[NEW_VAL:%.+]] = fptosi x86_fp80 %{{.+}} to i32
comment|// CHECK: [[BITCAST:%.+]] = bitcast i32* [[LDTEMP:%.+]] to i8*
comment|// CHECK: call void @__atomic_load(i64 4, i8* getelementptr (i8, i8* bitcast (%struct.BitFields_packed* @{{.+}} to i8*), i64 4), i8* [[BITCAST]], i32 0)
comment|// CHECK: br label %[[CONT:.+]]
comment|// CHECK: [[CONT]]
comment|// CHECK: [[OLD_BF_VALUE:%.+]] = load i32, i32* [[LDTEMP]],
comment|// CHECK: store i32 [[OLD_BF_VALUE]], i32* [[LDTEMP1:%.+]],
comment|// CHECK: [[OLD_BF_VALUE:%.+]] = load i32, i32* [[LDTEMP1]],
comment|// CHECK: [[BF_VALUE:%.+]] = and i32 [[NEW_VAL]], 2147483647
comment|// CHECK: [[BF_CLEAR:%.+]] = and i32 [[OLD_BF_VALUE]], -2147483648
comment|// CHECK: or i32 [[BF_CLEAR]], [[BF_VALUE]]
comment|// CHECK: store i32 %{{.+}}, i32* [[LDTEMP1]]
comment|// CHECK: [[BITCAST_TEMP_OLD_BF_ADDR:%.+]] = bitcast i32* [[LDTEMP]] to i8*
comment|// CHECK: [[BITCAST_TEMP_NEW_BF_ADDR:%.+]] = bitcast i32* [[LDTEMP1]] to i8*
comment|// CHECK: [[FAIL_SUCCESS:%.+]] = call zeroext i1 @__atomic_compare_exchange(i64 4, i8* getelementptr (i8, i8* bitcast (%struct.BitFields_packed* @{{.+}} to i8*), i64 4), i8* [[BITCAST_TEMP_OLD_BF_ADDR]], i8* [[BITCAST_TEMP_NEW_BF_ADDR]], i32 0, i32 0)
comment|// CHECK: br i1 [[FAIL_SUCCESS]], label %[[EXIT:.+]], label %[[CONT]]
comment|// CHECK: [[EXIT]]
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|bfx_packed
operator|.
name|a
operator|=
name|ldv
expr_stmt|;
comment|// CHECK: load x86_fp80, x86_fp80* @{{.+}}
comment|// CHECK: [[NEW_VAL:%.+]] = fptosi x86_fp80 %{{.+}} to i32
comment|// CHECK: [[PREV_VALUE:%.+]] = load atomic i32, i32* getelementptr inbounds (%struct.BitFields2, %struct.BitFields2* @{{.+}}, i32 0, i32 0) monotonic
comment|// CHECK: br label %[[CONT:.+]]
comment|// CHECK: [[CONT]]
comment|// CHECK: [[OLD_BF_VALUE:%.+]] = phi i32 [ [[PREV_VALUE]], %[[EXIT]] ], [ [[FAILED_OLD_VAL:%.+]], %[[CONT]] ]
comment|// CHECK: [[BF_AND:%.+]] = and i32 [[NEW_VAL]], 1
comment|// CHECK: [[BF_VALUE:%.+]] = shl i32 [[BF_AND]], 31
comment|// CHECK: [[BF_CLEAR:%.+]] = and i32 %{{.+}}, 2147483647
comment|// CHECK: or i32 [[BF_CLEAR]], [[BF_VALUE]]
comment|// CHECK: store i32 %{{.+}}, i32* [[LDTEMP:%.+]]
comment|// CHECK: [[NEW_BF_VALUE:%.+]] = load i32, i32* [[LDTEMP]]
comment|// CHECK: [[RES:%.+]] = cmpxchg i32* getelementptr inbounds (%struct.BitFields2, %struct.BitFields2* @{{.+}}, i32 0, i32 0), i32 [[OLD_BF_VALUE]], i32 [[NEW_BF_VALUE]] monotonic monotonic
comment|// CHECK: [[FAILED_OLD_VAL]] = extractvalue { i32, i1 } [[RES]], 0
comment|// CHECK: [[FAIL_SUCCESS:%.+]] = extractvalue { i32, i1 } [[RES]], 1
comment|// CHECK: br i1 [[FAIL_SUCCESS]], label %[[EXIT:.+]], label %[[CONT]]
comment|// CHECK: [[EXIT]]
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|bfx2
operator|.
name|a
operator|=
name|ldv
expr_stmt|;
comment|// CHECK: load x86_fp80, x86_fp80* @{{.+}}
comment|// CHECK: [[NEW_VAL:%.+]] = fptosi x86_fp80 %{{.+}} to i32
comment|// CHECK: [[PREV_VALUE:%.+]] = load atomic i8, i8* getelementptr (i8, i8* bitcast (%struct.BitFields2_packed* @{{.+}} to i8*), i64 3) monotonic
comment|// CHECK: br label %[[CONT:.+]]
comment|// CHECK: [[CONT]]
comment|// CHECK: [[OLD_BF_VALUE:%.+]] = phi i8 [ [[PREV_VALUE]], %[[EXIT]] ], [ [[FAILED_OLD_VAL:%.+]], %[[CONT]] ]
comment|// CHECK: [[TRUNC:%.+]] = trunc i32 [[NEW_VAL]] to i8
comment|// CHECK: [[BF_AND:%.+]] = and i8 [[TRUNC]], 1
comment|// CHECK: [[BF_VALUE:%.+]] = shl i8 [[BF_AND]], 7
comment|// CHECK: [[BF_CLEAR:%.+]] = and i8 %{{.+}}, 127
comment|// CHECK: or i8 [[BF_CLEAR]], [[BF_VALUE]]
comment|// CHECK: store i8 %{{.+}}, i8* [[LDTEMP:%.+]]
comment|// CHECK: [[NEW_BF_VALUE:%.+]] = load i8, i8* [[LDTEMP]]
comment|// CHECK: [[RES:%.+]] = cmpxchg i8* getelementptr (i8, i8* bitcast (%struct.BitFields2_packed* @{{.+}} to i8*), i64 3), i8 [[OLD_BF_VALUE]], i8 [[NEW_BF_VALUE]] monotonic monotonic
comment|// CHECK: [[FAILED_OLD_VAL]] = extractvalue { i8, i1 } [[RES]], 0
comment|// CHECK: [[FAIL_SUCCESS:%.+]] = extractvalue { i8, i1 } [[RES]], 1
comment|// CHECK: br i1 [[FAIL_SUCCESS]], label %[[EXIT:.+]], label %[[CONT]]
comment|// CHECK: [[EXIT]]
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|bfx2_packed
operator|.
name|a
operator|=
name|ldv
expr_stmt|;
comment|// CHECK: load x86_fp80, x86_fp80* @{{.+}}
comment|// CHECK: [[NEW_VAL:%.+]] = fptosi x86_fp80 %{{.+}} to i32
comment|// CHECK: [[PREV_VALUE:%.+]] = load atomic i32, i32* getelementptr inbounds (%struct.BitFields3, %struct.BitFields3* @{{.+}}, i32 0, i32 0) monotonic
comment|// CHECK: br label %[[CONT:.+]]
comment|// CHECK: [[CONT]]
comment|// CHECK: [[OLD_BF_VALUE:%.+]] = phi i32 [ [[PREV_VALUE]], %[[EXIT]] ], [ [[FAILED_OLD_VAL:%.+]], %[[CONT]] ]
comment|// CHECK: [[BF_AND:%.+]] = and i32 [[NEW_VAL]], 16383
comment|// CHECK: [[BF_VALUE:%.+]] = shl i32 [[BF_AND]], 11
comment|// CHECK: [[BF_CLEAR:%.+]] = and i32 %{{.+}}, -33552385
comment|// CHECK: or i32 [[BF_CLEAR]], [[BF_VALUE]]
comment|// CHECK: store i32 %{{.+}}, i32* [[LDTEMP:%.+]]
comment|// CHECK: [[NEW_BF_VALUE:%.+]] = load i32, i32* [[LDTEMP]]
comment|// CHECK: [[RES:%.+]] = cmpxchg i32* getelementptr inbounds (%struct.BitFields3, %struct.BitFields3* @{{.+}}, i32 0, i32 0), i32 [[OLD_BF_VALUE]], i32 [[NEW_BF_VALUE]] monotonic monotonic
comment|// CHECK: [[FAILED_OLD_VAL]] = extractvalue { i32, i1 } [[RES]], 0
comment|// CHECK: [[FAIL_SUCCESS:%.+]] = extractvalue { i32, i1 } [[RES]], 1
comment|// CHECK: br i1 [[FAIL_SUCCESS]], label %[[EXIT:.+]], label %[[CONT]]
comment|// CHECK: [[EXIT]]
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|bfx3
operator|.
name|a
operator|=
name|ldv
expr_stmt|;
comment|// CHECK: load x86_fp80, x86_fp80* @{{.+}}
comment|// CHECK: [[NEW_VAL:%.+]] = fptosi x86_fp80 %{{.+}} to i32
comment|// CHECK: [[LDTEMP:%.+]] = bitcast i32* %{{.+}} to i24*
comment|// CHECK: [[BITCAST:%.+]] = bitcast i24* %{{.+}} to i8*
comment|// CHECK: call void @__atomic_load(i64 3, i8* getelementptr (i8, i8* bitcast (%struct.BitFields3_packed* @{{.+}} to i8*), i64 1), i8* [[BITCAST]], i32 0)
comment|// CHECK: br label %[[CONT:.+]]
comment|// CHECK: [[CONT]]
comment|// CHECK: [[OLD_VAL:%.+]] = load i24, i24* %{{.+}},
comment|// CHECK: store i24 [[OLD_VAL]], i24* [[TEMP:%.+]],
comment|// CHECK: [[TRUNC:%.+]] = trunc i32 [[NEW_VAL]] to i24
comment|// CHECK: [[BF_AND:%.+]] = and i24 [[TRUNC]], 16383
comment|// CHECK: [[BF_VALUE:%.+]] = shl i24 [[BF_AND]], 3
comment|// CHECK: [[BF_CLEAR:%.+]] = and i24 %{{.+}}, -131065
comment|// CHECK: or i24 [[BF_CLEAR]], [[BF_VALUE]]
comment|// CHECK: store i24 %{{.+}}, i24* [[TEMP]]
comment|// CHECK: [[BITCAST_TEMP_OLD_BF_ADDR:%.+]] = bitcast i24* [[LDTEMP]] to i8*
comment|// CHECK: [[BITCAST_TEMP_NEW_BF_ADDR:%.+]] = bitcast i24* [[TEMP]] to i8*
comment|// CHECK: [[FAIL_SUCCESS:%.+]] = call zeroext i1 @__atomic_compare_exchange(i64 3, i8* getelementptr (i8, i8* bitcast (%struct.BitFields3_packed* @{{.+}} to i8*), i64 1), i8* [[BITCAST_TEMP_OLD_BF_ADDR]], i8* [[BITCAST_TEMP_NEW_BF_ADDR]], i32 0, i32 0)
comment|// CHECK: br i1 [[FAIL_SUCCESS]], label %[[EXIT:.+]], label %[[CONT]]
comment|// CHECK: [[EXIT]]
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|bfx3_packed
operator|.
name|a
operator|=
name|ldv
expr_stmt|;
comment|// CHECK: load x86_fp80, x86_fp80* @{{.+}}
comment|// CHECK: [[NEW_VAL:%.+]] = fptosi x86_fp80 %{{.+}} to i32
comment|// CHECK: [[PREV_VALUE:%.+]] = load atomic i64, i64* bitcast (%struct.BitFields4* @{{.+}} to i64*) monotonic
comment|// CHECK: br label %[[CONT:.+]]
comment|// CHECK: [[CONT]]
comment|// CHECK: [[OLD_BF_VALUE:%.+]] = phi i64 [ [[PREV_VALUE]], %[[EXIT]] ], [ [[FAILED_OLD_VAL:%.+]], %[[CONT]] ]
comment|// CHECK: [[ZEXT:%.+]] = zext i32 [[NEW_VAL]] to i64
comment|// CHECK: [[BF_AND:%.+]] = and i64 [[ZEXT]], 1
comment|// CHECK: [[BF_VALUE:%.+]] = shl i64 [[BF_AND]], 16
comment|// CHECK: [[BF_CLEAR:%.+]] = and i64 %{{.+}}, -65537
comment|// CHECK: or i64 [[BF_CLEAR]], [[BF_VALUE]]
comment|// CHECK: store i64 %{{.+}}, i64* [[LDTEMP:%.+]]
comment|// CHECK: [[NEW_BF_VALUE:%.+]] = load i64, i64* [[LDTEMP]]
comment|// CHECK: [[RES:%.+]] = cmpxchg i64* bitcast (%struct.BitFields4* @{{.+}} to i64*), i64 [[OLD_BF_VALUE]], i64 [[NEW_BF_VALUE]] monotonic monotonic
comment|// CHECK: [[FAILED_OLD_VAL]] = extractvalue { i64, i1 } [[RES]], 0
comment|// CHECK: [[FAIL_SUCCESS:%.+]] = extractvalue { i64, i1 } [[RES]], 1
comment|// CHECK: br i1 [[FAIL_SUCCESS]], label %[[EXIT:.+]], label %[[CONT]]
comment|// CHECK: [[EXIT]]
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|bfx4
operator|.
name|a
operator|=
name|ldv
expr_stmt|;
comment|// CHECK: load x86_fp80, x86_fp80* @{{.+}}
comment|// CHECK: [[NEW_VAL:%.+]] = fptosi x86_fp80 %{{.+}} to i32
comment|// CHECK: [[PREV_VALUE:%.+]] = load atomic i8, i8* getelementptr inbounds (%struct.BitFields4_packed, %struct.BitFields4_packed* @{{.+}}, i32 0, i32 0, i64 2) monotonic
comment|// CHECK: br label %[[CONT:.+]]
comment|// CHECK: [[CONT]]
comment|// CHECK: [[OLD_BF_VALUE:%.+]] = phi i8 [ [[PREV_VALUE]], %[[EXIT]] ], [ [[FAILED_OLD_VAL:%.+]], %[[CONT]] ]
comment|// CHECK: [[TRUNC:%.+]] = trunc i32 [[NEW_VAL]] to i8
comment|// CHECK: [[BF_VALUE:%.+]] = and i8 [[TRUNC]], 1
comment|// CHECK: [[BF_CLEAR:%.+]] = and i8 %{{.+}}, -2
comment|// CHECK: or i8 [[BF_CLEAR]], [[BF_VALUE]]
comment|// CHECK: store i8 %{{.+}}, i8* [[LDTEMP:%.+]]
comment|// CHECK: [[NEW_BF_VALUE:%.+]] = load i8, i8* [[LDTEMP]]
comment|// CHECK: [[RES:%.+]] = cmpxchg i8* getelementptr inbounds (%struct.BitFields4_packed, %struct.BitFields4_packed* @{{.+}}, i32 0, i32 0, i64 2), i8 [[OLD_BF_VALUE]], i8 [[NEW_BF_VALUE]] monotonic monotonic
comment|// CHECK: [[FAILED_OLD_VAL]] = extractvalue { i8, i1 } [[RES]], 0
comment|// CHECK: [[FAIL_SUCCESS:%.+]] = extractvalue { i8, i1 } [[RES]], 1
comment|// CHECK: br i1 [[FAIL_SUCCESS]], label %[[EXIT:.+]], label %[[CONT]]
comment|// CHECK: [[EXIT]]
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|bfx4_packed
operator|.
name|a
operator|=
name|ldv
expr_stmt|;
comment|// CHECK: load x86_fp80, x86_fp80* @{{.+}}
comment|// CHECK: [[NEW_VAL:%.+]] = fptosi x86_fp80 %{{.+}} to i64
comment|// CHECK: [[PREV_VALUE:%.+]] = load atomic i64, i64* bitcast (%struct.BitFields4* @{{.+}} to i64*) monotonic
comment|// CHECK: br label %[[CONT:.+]]
comment|// CHECK: [[CONT]]
comment|// CHECK: [[OLD_BF_VALUE:%.+]] = phi i64 [ [[PREV_VALUE]], %[[EXIT]] ], [ [[FAILED_OLD_VAL:%.+]], %[[CONT]] ]
comment|// CHECK: [[BF_AND:%.+]] = and i64 [[NEW_VAL]], 127
comment|// CHECK: [[BF_VALUE:%.+]] = shl i64 [[BF_AND]], 17
comment|// CHECK: [[BF_CLEAR:%.+]] = and i64 %{{.+}}, -16646145
comment|// CHECK: or i64 [[BF_CLEAR]], [[BF_VALUE]]
comment|// CHECK: store i64 %{{.+}}, i64* [[LDTEMP:%.+]]
comment|// CHECK: [[NEW_BF_VALUE:%.+]] = load i64, i64* [[LDTEMP]]
comment|// CHECK: [[RES:%.+]] = cmpxchg i64* bitcast (%struct.BitFields4* @{{.+}} to i64*), i64 [[OLD_BF_VALUE]], i64 [[NEW_BF_VALUE]] monotonic monotonic
comment|// CHECK: [[FAILED_OLD_VAL]] = extractvalue { i64, i1 } [[RES]], 0
comment|// CHECK: [[FAIL_SUCCESS:%.+]] = extractvalue { i64, i1 } [[RES]], 1
comment|// CHECK: br i1 [[FAIL_SUCCESS]], label %[[EXIT:.+]], label %[[CONT]]
comment|// CHECK: [[EXIT]]
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|bfx4
operator|.
name|b
operator|=
name|ldv
expr_stmt|;
comment|// CHECK: load x86_fp80, x86_fp80* @{{.+}}
comment|// CHECK: [[NEW_VAL:%.+]] = fptosi x86_fp80 %{{.+}} to i64
comment|// CHECK: [[PREV_VALUE:%.+]] = load atomic i8, i8* getelementptr inbounds (%struct.BitFields4_packed, %struct.BitFields4_packed* @{{.+}}, i32 0, i32 0, i64 2) monotonic
comment|// CHECK: br label %[[CONT:.+]]
comment|// CHECK: [[CONT]]
comment|// CHECK: [[OLD_BF_VALUE:%.+]] = phi i8 [ [[PREV_VALUE]], %[[EXIT]] ], [ [[FAILED_OLD_VAL:%.+]], %[[CONT]] ]
comment|// CHECK: [[TRUNC:%.+]] = trunc i64 [[NEW_VAL]] to i8
comment|// CHECK: [[BF_AND:%.+]] = and i8 [[TRUNC]], 127
comment|// CHECK: [[BF_VALUE:%.+]] = shl i8 [[BF_AND]], 1
comment|// CHECK: [[BF_CLEAR:%.+]] = and i8 %{{.+}}, 1
comment|// CHECK: or i8 [[BF_CLEAR]], [[BF_VALUE]]
comment|// CHECK: store i8 %{{.+}}, i8* [[LDTEMP:%.+]]
comment|// CHECK: [[NEW_BF_VALUE:%.+]] = load i8, i8* [[LDTEMP]]
comment|// CHECK: [[RES:%.+]] = cmpxchg i8* getelementptr inbounds (%struct.BitFields4_packed, %struct.BitFields4_packed* @{{.+}}, i32 0, i32 0, i64 2), i8 [[OLD_BF_VALUE]], i8 [[NEW_BF_VALUE]] monotonic monotonic
comment|// CHECK: [[FAILED_OLD_VAL]] = extractvalue { i8, i1 } [[RES]], 0
comment|// CHECK: [[FAIL_SUCCESS:%.+]] = extractvalue { i8, i1 } [[RES]], 1
comment|// CHECK: br i1 [[FAIL_SUCCESS]], label %[[EXIT:.+]], label %[[CONT]]
comment|// CHECK: [[EXIT]]
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|bfx4_packed
operator|.
name|b
operator|=
name|ldv
expr_stmt|;
comment|// CHECK: load i64, i64*
comment|// CHECK: [[VEC_ITEM_VAL:%.+]] = uitofp i64 %{{.+}} to float
comment|// CHECK: [[I64VAL:%.+]] = load atomic i64, i64* bitcast (<2 x float>* [[DEST:@.+]] to i64*) monotonic
comment|// CHECK: br label %[[CONT:.+]]
comment|// CHECK: [[CONT]]
comment|// CHECK: [[OLD_I64:%.+]] = phi i64 [ [[I64VAL]], %{{.+}} ], [ [[FAILED_I64_OLD_VAL:%.+]], %[[CONT]] ]
comment|// CHECK: [[BITCAST:%.+]] = bitcast<2 x float>* [[LDTEMP:%.+]] to i64*
comment|// CHECK: store i64 [[OLD_I64]], i64* [[BITCAST]],
comment|// CHECK: [[VEC_VAL:%.+]] = load<2 x float>,<2 x float>* [[LDTEMP]]
comment|// CHECK: [[NEW_VEC_VAL:%.+]] = insertelement<2 x float> [[VEC_VAL]], float [[VEC_ITEM_VAL]], i64 0
comment|// CHECK: store<2 x float> [[NEW_VEC_VAL]],<2 x float>* [[LDTEMP]]
comment|// CHECK: [[NEW_I64:%.+]] = load i64, i64* [[BITCAST]]
comment|// CHECK: [[RES:%.+]] = cmpxchg i64* bitcast (<2 x float>* [[DEST]] to i64*), i64 [[OLD_I64]], i64 [[NEW_I64]] monotonic monotonic
comment|// CHECK: [[FAILED_I64_OLD_VAL:%.+]] = extractvalue { i64, i1 } [[RES]], 0
comment|// CHECK: [[FAIL_SUCCESS:%.+]] = extractvalue { i64, i1 } [[RES]], 1
comment|// CHECK: br i1 [[FAIL_SUCCESS]], label %[[EXIT:.+]], label %[[CONT]]
comment|// CHECK: [[EXIT]]
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|float2x
operator|.
name|x
operator|=
name|ulv
expr_stmt|;
comment|// CHECK: call i32 @llvm.read_register.i32(
comment|// CHECK: sitofp i32 %{{.+}} to double
comment|// CHECK: bitcast double %{{.+}} to i64
comment|// CHECK: store atomic i64 %{{.+}}, i64* bitcast (double* @{{.+}} to i64*) seq_cst
comment|// CHECK: call{{.*}} @__kmpc_flush(
pragma|#
directive|pragma
name|omp
name|atomic
name|write
name|seq_cst
name|dv
operator|=
name|rix
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

