begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1  -Wno-error-vec-elem-size -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1  -Wno-error-vec-elem-size -DEXT -emit-llvm %s -o - | FileCheck %s
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|EXT
end_ifdef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(__ext_vector_type__(
literal|8
argument|))
argument_list|)
name|char
name|vector_char8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(__ext_vector_type__(
literal|8
argument|))
argument_list|)
name|short
name|vector_short8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(__ext_vector_type__(
literal|8
argument|))
argument_list|)
name|int
name|vector_int8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(__ext_vector_type__(
literal|8
argument|))
argument_list|)
name|unsigned
name|char
name|vector_uchar8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(__ext_vector_type__(
literal|8
argument|))
argument_list|)
name|unsigned
name|short
name|vector_ushort8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(__ext_vector_type__(
literal|8
argument|))
argument_list|)
name|unsigned
name|int
name|vector_uint8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(__ext_vector_type__(
literal|4
argument|))
argument_list|)
name|char
name|vector_char4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(__ext_vector_type__(
literal|4
argument|))
argument_list|)
name|short
name|vector_short4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(__ext_vector_type__(
literal|4
argument|))
argument_list|)
name|int
name|vector_int4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(__ext_vector_type__(
literal|4
argument|))
argument_list|)
name|unsigned
name|char
name|vector_uchar4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(__ext_vector_type__(
literal|4
argument|))
argument_list|)
name|unsigned
name|short
name|vector_ushort4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(__ext_vector_type__(
literal|4
argument|))
argument_list|)
name|unsigned
name|int
name|vector_uint4
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|8
argument|))
argument_list|)
name|char
name|vector_char8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|short
name|vector_short8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|32
argument|))
argument_list|)
name|int
name|vector_int8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|8
argument|))
argument_list|)
name|unsigned
name|char
name|vector_uchar8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|unsigned
name|short
name|vector_ushort8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|32
argument|))
argument_list|)
name|unsigned
name|int
name|vector_uint8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|4
argument|))
argument_list|)
name|char
name|vector_char4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|4
argument|))
argument_list|)
name|short
name|vector_short4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|int
name|vector_int4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|4
argument|))
argument_list|)
name|unsigned
name|char
name|vector_uchar4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|8
argument|))
argument_list|)
name|unsigned
name|short
name|vector_ushort4
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|unsigned
name|int
name|vector_uint4
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|short
name|s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|i
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|char
name|uc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|short
name|us
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|int
name|ui
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector_char8
name|vc8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector_short8
name|vs8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector_int8
name|vi8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector_uchar8
name|vuc8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector_ushort8
name|vus8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector_uint8
name|vui8
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector_char4
name|vc4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector_short4
name|vs4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector_int4
name|vi4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector_uchar4
name|vuc4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector_ushort4
name|vus4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|vector_uint4
name|vui4
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo
parameter_list|()
block|{
name|vc8
operator|=
literal|1
operator|<<
name|vc8
expr_stmt|;
comment|// CHECK: [[t0:%.+]] = load<8 x i8>,<8 x i8>* {{@.+}},
comment|// CHECK: shl<8 x i8><i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>, [[t0]]
name|vuc8
operator|=
literal|1
operator|<<
name|vuc8
expr_stmt|;
comment|// CHECK: [[t1:%.+]] = load<8 x i8>,<8 x i8>* {{@.+}},
comment|// CHECK: shl<8 x i8><i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>, [[t1]]
name|vi8
operator|=
literal|1
operator|<<
name|vi8
expr_stmt|;
comment|// CHECK: [[t2:%.+]] = load<8 x i32>,<8 x i32>* {{@.+}},
comment|// CHECK: shl<8 x i32><i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1>, [[t2]]
name|vui8
operator|=
literal|1
operator|<<
name|vui8
expr_stmt|;
comment|// CHECK: [[t3:%.+]] = load<8 x i32>,<8 x i32>* {{@.+}},
comment|// CHECK: shl<8 x i32><i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1, i32 1>, [[t3]]
name|vs8
operator|=
literal|1
operator|<<
name|vs8
expr_stmt|;
comment|// CHECK: [[t4:%.+]] = load<8 x i16>,<8 x i16>* {{@.+}},
comment|// CHECK: shl<8 x i16><i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>, [[t4]]
name|vus8
operator|=
literal|1
operator|<<
name|vus8
expr_stmt|;
comment|// CHECK: [[t5:%.+]] = load<8 x i16>,<8 x i16>* {{@.+}},
comment|// CHECK: shl<8 x i16><i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>, [[t5]]
name|vc8
operator|=
name|c
operator|<<
name|vc8
expr_stmt|;
comment|// CHECK: [[t6:%.+]] = load i8, i8* @c,
comment|// CHECK: [[splat_splatinsert:%.+]] = insertelement<8 x i8> undef, i8 [[t6]], i32 0
comment|// CHECK: [[splat_splat:%.+]] = shufflevector<8 x i8> [[splat_splatinsert]],<8 x i8> undef,<8 x i32> zeroinitializer
comment|// CHECK: [[t7:%.+]] = load<8 x i8>,<8 x i8>* {{@.+}},
comment|// CHECK: shl<8 x i8> [[splat_splat]], [[t7]]
name|vuc8
operator|=
name|i
operator|<<
name|vuc8
expr_stmt|;
comment|// CHECK: [[t8:%.+]] = load i32, i32* @i,
comment|// CHECK: [[tconv:%.+]] = trunc i32 [[t8]] to i8
comment|// CHECK: [[splat_splatinsert7:%.+]] = insertelement<8 x i8> undef, i8 [[tconv]], i32 0
comment|// CHECK: [[splat_splat8:%.+]] = shufflevector<8 x i8> [[splat_splatinsert7]],<8 x i8> undef,<8 x i32> zeroinitializer
comment|// CHECK: [[t9:%.+]] = load<8 x i8>,<8 x i8>* {{@.+}},
comment|// CHECK: shl<8 x i8> [[splat_splat8]], [[t9]]
name|vi8
operator|=
name|uc
operator|<<
name|vi8
expr_stmt|;
comment|// CHECK: [[t10:%.+]] = load i8, i8* @uc,
comment|// CHECK: [[conv10:%.+]] = zext i8 [[t10]] to i32
comment|// CHECK: [[splat_splatinsert11:%.+]] = insertelement<8 x i32> undef, i32 [[conv10]], i32 0
comment|// CHECK: [[splat_splat12:%.+]] = shufflevector<8 x i32> [[splat_splatinsert11]],<8 x i32> undef,<8 x i32> zeroinitializer
comment|// CHECK: [[t11:%.+]] = load<8 x i32>,<8 x i32>* {{@.+}},
comment|// CHECK: shl<8 x i32> [[splat_splat12]], [[t11]]
name|vui8
operator|=
name|us
operator|<<
name|vui8
expr_stmt|;
comment|// CHECK: [[t12:%.+]] = load i16, i16* @us,
comment|// CHECK: [[conv14:%.+]] = zext i16 [[t12]] to i32
comment|// CHECK: [[splat_splatinsert15:%.+]] = insertelement<8 x i32> undef, i32 [[conv14]], i32 0
comment|// CHECK: [[splat_splat16:%.+]] = shufflevector<8 x i32> [[splat_splatinsert15]],<8 x i32> undef,<8 x i32> zeroinitializer
comment|// CHECK: [[t13:%.+]] = load<8 x i32>,<8 x i32>* {{@.+}},
comment|// CHECK: shl<8 x i32> [[splat_splat16]], [[t13]]
name|vs8
operator|=
name|ui
operator|<<
name|vs8
expr_stmt|;
comment|// CHECK: [[t14:%.+]] = load i32, i32* @ui,
comment|// CHECK: [[conv18:%.+]] = trunc i32 [[t14]] to i16
comment|// CHECK: [[splat_splatinsert19:%.+]] = insertelement<8 x i16> undef, i16 [[conv18]], i32 0
comment|// CHECK: [[splat_splat20:%.+]] = shufflevector<8 x i16> [[splat_splatinsert19]],<8 x i16> undef,<8 x i32> zeroinitializer
comment|// CHECK: [[t15:%.+]] = load<8 x i16>,<8 x i16>* {{@.+}},
comment|// CHECK: shl<8 x i16> [[splat_splat20]], [[t15]]
name|vus8
operator|=
literal|1
operator|<<
name|vus8
expr_stmt|;
comment|// CHECK: [[t16:%.+]] = load<8 x i16>,<8 x i16>* {{@.+}},
comment|// CHECK: [[shl22:%.+]] = shl<8 x i16><i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>, [[t16]]
name|vc8
operator|=
name|vc8
operator|<<
name|vc8
expr_stmt|;
comment|// CHECK: [[t17:%.+]] = load<8 x i8>,<8 x i8>* {{@.+}},
comment|// CHECK: [[t18:%.+]] = load<8 x i8>,<8 x i8>* {{@.+}},
comment|// CHECK: shl<8 x i8> [[t17]], [[t18]]
name|vi8
operator|=
name|vi8
operator|<<
name|vuc8
expr_stmt|;
comment|// CHECK: [[t19:%.+]] = load<8 x i32>,<8 x i32>* {{@.+}},
comment|// CHECK: [[t20:%.+]] = load<8 x i8>,<8 x i8>* {{@.+}},
comment|// CHECK: [[shprom:%.+]] = zext<8 x i8> [[t20]] to<8 x i32>
comment|// CHECK: shl<8 x i32> [[t19]], [[shprom]]
name|vuc8
operator|=
name|vuc8
operator|<<
name|vi8
expr_stmt|;
comment|// CHECK: [[t21:%.+]] = load<8 x i8>,<8 x i8>* {{@.+}},
comment|// CHECK: [[t22:%.+]] = load<8 x i32>,<8 x i32>* {{@.+}},
comment|// CHECK: [[sh_prom25:%.+]] = trunc<8 x i32> [[t22]] to<8 x i8>
comment|// CHECK: shl<8 x i8> [[t21]], [[sh_prom25]]
name|vus8
operator|=
name|vus8
operator|<<
name|vui8
expr_stmt|;
comment|// CHECK: [[t23:%.+]] = load<8 x i16>,<8 x i16>* {{@.+}},
comment|// CHECK: [[t24:%.+]] = load<8 x i32>,<8 x i32>* {{@.+}},
comment|// CHECK: [[sh_prom27:%.+]] = trunc<8 x i32> [[t24]] to<8 x i16>
comment|// CHECK: shl<8 x i16> [[t23]], [[sh_prom27]]
name|vui8
operator|=
name|vui8
operator|<<
name|vs8
expr_stmt|;
comment|// CHECK: [[t25:%.+]] = load<8 x i32>,<8 x i32>* {{@.+}},
comment|// CHECK: [[t26:%.+]] = load<8 x i16>,<8 x i16>* {{@.+}},
comment|// CHECK: [[sh_prom29:%.+]] = zext<8 x i16> [[t26]] to<8 x i32>
comment|// CHECK: shl<8 x i32> [[t25]], [[sh_prom29]]
name|vui8
operator|<<=
name|s
expr_stmt|;
comment|// CHECK: [[t27:%.+]] = load i16, i16* @s,
comment|// CHECK: [[conv40:%.+]] = sext i16 [[t27]] to i32
comment|// CHECK: [[splat_splatinsert41:%.+]] = insertelement<8 x i32> undef, i32 [[conv40]], i32 0
comment|// CHECK: [[splat_splat42:%.+]] = shufflevector<8 x i32> [[splat_splatinsert41]],<8 x i32> undef,<8 x i32> zeroinitializer
comment|// CHECK: [[t28:%.+]] = load<8 x i32>,<8 x i32>* {{@.+}},
comment|// CHECK: shl<8 x i32> [[t28]], [[splat_splat42]]
name|vi8
operator|<<=
name|us
expr_stmt|;
comment|// CHECK: [[t29:%.+]] = load i16, i16* @us,
comment|// CHECK: [[conv44:%.+]] = zext i16 [[t29]] to i32
comment|// CHECK: [[splat_splatinsert45:%.+]] = insertelement<8 x i32> undef, i32 [[conv44]], i32 0
comment|// CHECK: [[splat_splat46:%.+]] = shufflevector<8 x i32> [[splat_splatinsert45]],<8 x i32> undef,<8 x i32> zeroinitializer
comment|// CHECK: [[t30:%.+]] = load<8 x i32>,<8 x i32>* {{@.+}},
comment|// CHECK: shl<8 x i32> [[t30]], [[splat_splat46]]
name|vus8
operator|<<=
name|i
expr_stmt|;
comment|// CHECK: [[t31:%.+]] = load i32, i32* @i,
comment|// CHECK: [[splat_splatinsert48:%.+]] = insertelement<8 x i32> undef, i32 [[t31]], i32 0
comment|// CHECK: [[splat_splat49:%.+]] = shufflevector<8 x i32> [[splat_splatinsert48]],<8 x i32> undef,<8 x i32> zeroinitializer
comment|// CHECK: [[t32:%.+]] = load<8 x i16>,<8 x i16>* {{@.+}},
comment|// CHECK: [[sh_prom50:%.+]] = trunc<8 x i32> [[splat_splat49]] to<8 x i16>
comment|// CHECK: shl<8 x i16> [[t32]], [[sh_prom50]]
name|vs8
operator|<<=
name|ui
expr_stmt|;
comment|// CHECK: [[t33:%.+]] = load i32, i32* @ui,
comment|// CHECK: [[splat_splatinsert52:%.+]] = insertelement<8 x i32> undef, i32 [[t33]], i32 0
comment|// CHECK: [[splat_splat53:%.+]] = shufflevector<8 x i32> [[splat_splatinsert52]],<8 x i32> undef,<8 x i32> zeroinitializer
comment|// CHECK: [[t34:%.+]] = load<8 x i16>,<8 x i16>* {{@.+}},
comment|// CHECK: [[sh_prom54:%.+]] = trunc<8 x i32> [[splat_splat53]] to<8 x i16>
comment|// CHECK: shl<8 x i16> [[t34]], [[sh_prom54]]
block|}
end_function

end_unit

