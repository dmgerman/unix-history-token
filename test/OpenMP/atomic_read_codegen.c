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
comment|// CHECK: load atomic i8, i8*
comment|// CHECK: store i8
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|bv
operator|=
name|bx
expr_stmt|;
comment|// CHECK: load atomic i8, i8*
comment|// CHECK: store i8
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|cv
operator|=
name|cx
expr_stmt|;
comment|// CHECK: load atomic i8, i8*
comment|// CHECK: store i8
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|ucv
operator|=
name|ucx
expr_stmt|;
comment|// CHECK: load atomic i16, i16*
comment|// CHECK: store i16
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|sv
operator|=
name|sx
expr_stmt|;
comment|// CHECK: load atomic i16, i16*
comment|// CHECK: store i16
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|usv
operator|=
name|usx
expr_stmt|;
comment|// CHECK: load atomic i32, i32*
comment|// CHECK: store i32
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|iv
operator|=
name|ix
expr_stmt|;
comment|// CHECK: load atomic i32, i32*
comment|// CHECK: store i32
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|uiv
operator|=
name|uix
expr_stmt|;
comment|// CHECK: load atomic i64, i64*
comment|// CHECK: store i64
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|lv
operator|=
name|lx
expr_stmt|;
comment|// CHECK: load atomic i64, i64*
comment|// CHECK: store i64
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|ulv
operator|=
name|ulx
expr_stmt|;
comment|// CHECK: load atomic i64, i64*
comment|// CHECK: store i64
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|llv
operator|=
name|llx
expr_stmt|;
comment|// CHECK: load atomic i64, i64*
comment|// CHECK: store i64
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|ullv
operator|=
name|ullx
expr_stmt|;
comment|// CHECK: load atomic i32, i32* bitcast (float*
comment|// CHECK: bitcast i32 {{.*}} to float
comment|// CHECK: store float
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|fv
operator|=
name|fx
expr_stmt|;
comment|// CHECK: load atomic i64, i64* bitcast (double*
comment|// CHECK: bitcast i64 {{.*}} to double
comment|// CHECK: store double
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|dv
operator|=
name|dx
expr_stmt|;
comment|// CHECK: [[LD:%.+]] = load atomic i128, i128* bitcast (x86_fp80*
comment|// CHECK: [[BITCAST:%.+]] = bitcast x86_fp80* [[LDTEMP:%.*]] to i128*
comment|// CHECK: store i128 [[LD]], i128* [[BITCAST]]
comment|// CHECK: [[LD:%.+]] = load x86_fp80, x86_fp80* [[LDTEMP]]
comment|// CHECK: store x86_fp80 [[LD]]
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|ldv
operator|=
name|ldx
expr_stmt|;
comment|// CHECK: call{{.*}} void @__atomic_load(i64 8,
comment|// CHECK: store i32
comment|// CHECK: store i32
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|civ
operator|=
name|cix
expr_stmt|;
comment|// CHECK: call{{.*}} void @__atomic_load(i64 8,
comment|// CHECK: store float
comment|// CHECK: store float
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|cfv
operator|=
name|cfx
expr_stmt|;
comment|// CHECK: call{{.*}} void @__atomic_load(i64 16,
comment|// CHECK: call{{.*}} @__kmpc_flush(
comment|// CHECK: store double
comment|// CHECK: store double
pragma|#
directive|pragma
name|omp
name|atomic
name|seq_cst
name|read
name|cdv
operator|=
name|cdx
expr_stmt|;
comment|// CHECK: load atomic i64, i64*
comment|// CHECK: store i8
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|bv
operator|=
name|ulx
expr_stmt|;
comment|// CHECK: load atomic i8, i8*
comment|// CHECK: store i8
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|cv
operator|=
name|bx
expr_stmt|;
comment|// CHECK: load atomic i8, i8*
comment|// CHECK: call{{.*}} @__kmpc_flush(
comment|// CHECK: store i8
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|,
name|seq_cst
name|ucv
operator|=
name|cx
expr_stmt|;
comment|// CHECK: load atomic i64, i64*
comment|// CHECK: store i16
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|sv
operator|=
name|ulx
expr_stmt|;
comment|// CHECK: load atomic i64, i64*
comment|// CHECK: store i16
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|usv
operator|=
name|lx
expr_stmt|;
comment|// CHECK: load atomic i32, i32*
comment|// CHECK: call{{.*}} @__kmpc_flush(
comment|// CHECK: store i32
pragma|#
directive|pragma
name|omp
name|atomic
name|seq_cst
name|,
name|read
name|iv
operator|=
name|uix
expr_stmt|;
comment|// CHECK: load atomic i32, i32*
comment|// CHECK: store i32
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|uiv
operator|=
name|ix
expr_stmt|;
comment|// CHECK: call{{.*}} void @__atomic_load(i64 8,
comment|// CHECK: store i64
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|lv
operator|=
name|cix
expr_stmt|;
comment|// CHECK: load atomic i32, i32*
comment|// CHECK: store i64
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|ulv
operator|=
name|fx
expr_stmt|;
comment|// CHECK: load atomic i64, i64*
comment|// CHECK: store i64
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|llv
operator|=
name|dx
expr_stmt|;
comment|// CHECK: load atomic i128, i128*
comment|// CHECK: store i64
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|ullv
operator|=
name|ldx
expr_stmt|;
comment|// CHECK: call{{.*}} void @__atomic_load(i64 8,
comment|// CHECK: store float
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|fv
operator|=
name|cix
expr_stmt|;
comment|// CHECK: load atomic i16, i16*
comment|// CHECK: store double
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|dv
operator|=
name|sx
expr_stmt|;
comment|// CHECK: load atomic i8, i8*
comment|// CHECK: store x86_fp80
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|ldv
operator|=
name|bx
expr_stmt|;
comment|// CHECK: load atomic i8, i8*
comment|// CHECK: store i32
comment|// CHECK: store i32
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|civ
operator|=
name|bx
expr_stmt|;
comment|// CHECK: load atomic i16, i16*
comment|// CHECK: store float
comment|// CHECK: store float
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|cfv
operator|=
name|usx
expr_stmt|;
comment|// CHECK: load atomic i64, i64*
comment|// CHECK: store double
comment|// CHECK: store double
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|cdv
operator|=
name|llx
expr_stmt|;
comment|// CHECK: [[I128VAL:%.+]] = load atomic i128, i128* bitcast (<4 x i32>* @{{.+}} to i128*) monotonic
comment|// CHECK: [[I128PTR:%.+]] = bitcast<4 x i32>* [[LDTEMP:%.+]] to i128*
comment|// CHECK: store i128 [[I128VAL]], i128* [[I128PTR]]
comment|// CHECK: [[LD:%.+]] = load<4 x i32>,<4 x i32>* [[LDTEMP]]
comment|// CHECK: extractelement<4 x i32> [[LD]]
comment|// CHECK: store i8
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|bv
operator|=
name|int4x
index|[
literal|0
index|]
expr_stmt|;
comment|// CHECK: [[LD:%.+]] = load atomic i32, i32* bitcast (i8* getelementptr (i8, i8* bitcast (%{{.+}}* @{{.+}} to i8*), i64 4) to i32*) monotonic
comment|// CHECK: store i32 [[LD]], i32* [[LDTEMP:%.+]]
comment|// CHECK: [[LD:%.+]] = load i32, i32* [[LDTEMP]]
comment|// CHECK: [[SHL:%.+]] = shl i32 [[LD]], 1
comment|// CHECK: ashr i32 [[SHL]], 1
comment|// CHECK: store x86_fp80
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|ldv
operator|=
name|bfx
operator|.
name|a
expr_stmt|;
comment|// CHECK: [[LDTEMP_VOID_PTR:%.+]] = bitcast i32* [[LDTEMP:%.+]] to i8*
comment|// CHECK: call void @__atomic_load(i64 4, i8* getelementptr (i8, i8* bitcast (%struct.BitFields_packed* @bfx_packed to i8*), i64 4), i8* [[LDTEMP_VOID_PTR]], i32 0)
comment|// CHECK: [[LD:%.+]] = load i32, i32* [[LDTEMP]]
comment|// CHECK: [[SHL:%.+]] = shl i32 [[LD]], 1
comment|// CHECK: ashr i32 [[SHL]], 1
comment|// CHECK: store x86_fp80
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|ldv
operator|=
name|bfx_packed
operator|.
name|a
expr_stmt|;
comment|// CHECK: [[LD:%.+]] = load atomic i32, i32* getelementptr inbounds (%struct.BitFields2, %struct.BitFields2* @bfx2, i32 0, i32 0) monotonic
comment|// CHECK: store i32 [[LD]], i32* [[LDTEMP:%.+]]
comment|// CHECK: [[LD:%.+]] = load i32, i32* [[LDTEMP]]
comment|// CHECK: ashr i32 [[LD]], 31
comment|// CHECK: store x86_fp80
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|ldv
operator|=
name|bfx2
operator|.
name|a
expr_stmt|;
comment|// CHECK: [[LD:%.+]] = load atomic i8, i8* getelementptr (i8, i8* bitcast (%struct.BitFields2_packed* @bfx2_packed to i8*), i64 3) monotonic
comment|// CHECK: store i8 [[LD]], i8* [[LDTEMP:%.+]]
comment|// CHECK: [[LD:%.+]] = load i8, i8* [[LDTEMP]]
comment|// CHECK: ashr i8 [[LD]], 7
comment|// CHECK: store x86_fp80
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|ldv
operator|=
name|bfx2_packed
operator|.
name|a
expr_stmt|;
comment|// CHECK: [[LD:%.+]] = load atomic i32, i32* getelementptr inbounds (%struct.BitFields3, %struct.BitFields3* @bfx3, i32 0, i32 0) monotonic
comment|// CHECK: store i32 [[LD]], i32* [[LDTEMP:%.+]]
comment|// CHECK: [[LD:%.+]] = load i32, i32* [[LDTEMP]]
comment|// CHECK: [[SHL:%.+]] = shl i32 [[LD]], 7
comment|// CHECK: ashr i32 [[SHL]], 18
comment|// CHECK: store x86_fp80
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|ldv
operator|=
name|bfx3
operator|.
name|a
expr_stmt|;
comment|// CHECK: [[LDTEMP_VOID_PTR:%.+]] = bitcast i24* [[LDTEMP:%.+]] to i8*
comment|// CHECK: call void @__atomic_load(i64 3, i8* getelementptr (i8, i8* bitcast (%struct.BitFields3_packed* @bfx3_packed to i8*), i64 1), i8* [[LDTEMP_VOID_PTR]], i32 0)
comment|// CHECK: [[LD:%.+]] = load i24, i24* [[LDTEMP]]
comment|// CHECK: [[SHL:%.+]] = shl i24 [[LD]], 7
comment|// CHECK: [[ASHR:%.+]] = ashr i24 [[SHL]], 10
comment|// CHECK: sext i24 [[ASHR]] to i32
comment|// CHECK: store x86_fp80
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|ldv
operator|=
name|bfx3_packed
operator|.
name|a
expr_stmt|;
comment|// CHECK: [[LD:%.+]] = load atomic i64, i64* bitcast (%struct.BitFields4* @bfx4 to i64*) monotonic
comment|// CHECK: store i64 [[LD]], i64* [[LDTEMP:%.+]]
comment|// CHECK: [[LD:%.+]] = load i64, i64* [[LDTEMP]]
comment|// CHECK: [[SHL:%.+]] = shl i64 [[LD]], 47
comment|// CHECK: [[ASHR:%.+]] = ashr i64 [[SHL]], 63
comment|// CHECK: trunc i64 [[ASHR]] to i32
comment|// CHECK: store x86_fp80
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|ldv
operator|=
name|bfx4
operator|.
name|a
expr_stmt|;
comment|// CHECK: [[LD:%.+]] = load atomic i8, i8* getelementptr inbounds (%struct.BitFields4_packed, %struct.BitFields4_packed* @bfx4_packed, i32 0, i32 0, i64 2) monotonic
comment|// CHECK: store i8 [[LD]], i8* [[LDTEMP:%.+]]
comment|// CHECK: [[LD:%.+]] = load i8, i8* [[LDTEMP]]
comment|// CHECK: [[SHL:%.+]] = shl i8 [[LD]], 7
comment|// CHECK: [[ASHR:%.+]] = ashr i8 [[SHL]], 7
comment|// CHECK: sext i8 [[ASHR]] to i32
comment|// CHECK: store x86_fp80
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|ldv
operator|=
name|bfx4_packed
operator|.
name|a
expr_stmt|;
comment|// CHECK: [[LD:%.+]] = load atomic i64, i64* bitcast (%struct.BitFields4* @bfx4 to i64*) monotonic
comment|// CHECK: store i64 [[LD]], i64* [[LDTEMP:%.+]]
comment|// CHECK: [[LD:%.+]] = load i64, i64* [[LDTEMP]]
comment|// CHECK: [[SHL:%.+]] = shl i64 [[LD]], 40
comment|// CHECK: [[ASHR:%.+]] = ashr i64 [[SHL]], 57
comment|// CHECK: store x86_fp80
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|ldv
operator|=
name|bfx4
operator|.
name|b
expr_stmt|;
comment|// CHECK: [[LD:%.+]] = load atomic i8, i8* getelementptr inbounds (%struct.BitFields4_packed, %struct.BitFields4_packed* @bfx4_packed, i32 0, i32 0, i64 2) monotonic
comment|// CHECK: store i8 [[LD]], i8* [[LDTEMP:%.+]]
comment|// CHECK: [[LD:%.+]] = load i8, i8* [[LDTEMP]]
comment|// CHECK: [[ASHR:%.+]] = ashr i8 [[LD]], 1
comment|// CHECK: sext i8 [[ASHR]] to i64
comment|// CHECK: store x86_fp80
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|ldv
operator|=
name|bfx4_packed
operator|.
name|b
expr_stmt|;
comment|// CHECK: [[LD:%.+]] = load atomic i64, i64* bitcast (<2 x float>* @{{.+}} to i64*) monotonic
comment|// CHECK: [[BITCAST:%.+]] = bitcast<2 x float>* [[LDTEMP:%.+]] to i64*
comment|// CHECK: store i64 [[LD]], i64* [[BITCAST]]
comment|// CHECK: [[LD:%.+]] = load<2 x float>,<2 x float>* [[LDTEMP]]
comment|// CHECK: extractelement<2 x float> [[LD]]
comment|// CHECK: store i64
pragma|#
directive|pragma
name|omp
name|atomic
name|read
name|ulv
operator|=
name|float2x
operator|.
name|x
expr_stmt|;
comment|// CHECK: call{{.*}} i{{[0-9]+}} @llvm.read_register
comment|// CHECK: call{{.*}} @__kmpc_flush(
comment|// CHECK: store double
pragma|#
directive|pragma
name|omp
name|atomic
name|read
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

