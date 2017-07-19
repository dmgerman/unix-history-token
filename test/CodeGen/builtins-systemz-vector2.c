begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: systemz-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -target-cpu z14 -triple s390x-ibm-linux -fno-lax-vector-conversions \
end_comment

begin_comment
comment|// RUN: -Wall -Wno-unused -Werror -emit-llvm %s -o - | FileCheck %s
end_comment

begin_typedef
typedef|typedef
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
name|signed
name|char
name|vec_schar
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
name|signed
name|short
name|vec_sshort
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
name|signed
name|int
name|vec_sint
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
name|signed
name|long
name|long
name|vec_slong
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
name|char
name|vec_uchar
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
name|vec_ushort
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
name|vec_uint
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
name|long
name|long
name|vec_ulong
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
name|double
name|vec_double
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
name|float
name|vec_float
typedef|;
end_typedef

begin_decl_stmt
specifier|volatile
name|vec_schar
name|vsc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vec_sshort
name|vss
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vec_sint
name|vsi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vec_slong
name|vsl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vec_uchar
name|vuc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vec_ushort
name|vus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vec_uint
name|vui
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vec_ulong
name|vul
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vec_double
name|vd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vec_float
name|vf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|unsigned
name|int
name|len
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|void
modifier|*
specifier|volatile
name|cptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
specifier|volatile
name|ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cc
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test_core
parameter_list|(
name|void
parameter_list|)
block|{
name|vul
operator|=
name|__builtin_s390_vbperm
argument_list|(
name|vuc
argument_list|,
name|vuc
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x i64> @llvm.s390.vbperm(<16 x i8> %{{.*}},<16 x i8> %{{.*}})
name|vsc
operator|=
name|__builtin_s390_vlrl
argument_list|(
name|len
argument_list|,
name|cptr
argument_list|)
expr_stmt|;
comment|// CHECK: call<16 x i8> @llvm.s390.vlrl(i32 %{{.*}}, i8* %{{.*}})
name|__builtin_s390_vstrl
argument_list|(
name|vsc
argument_list|,
name|len
argument_list|,
name|ptr
argument_list|)
expr_stmt|;
comment|// CHECK: call void @llvm.s390.vstrl(<16 x i8> %{{.*}}, i32 %{{.*}}, i8* %{{.*}})
block|}
end_function

begin_function
name|void
name|test_integer
parameter_list|(
name|void
parameter_list|)
block|{
name|vuc
operator|=
name|__builtin_s390_vmslg
argument_list|(
name|vul
argument_list|,
name|vul
argument_list|,
name|vuc
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call<16 x i8> @llvm.s390.vmslg(<2 x i64> %{{.*}},<2 x i64> %{{.*}},<16 x i8> %{{.*}}, i32 0)
name|vuc
operator|=
name|__builtin_s390_vmslg
argument_list|(
name|vul
argument_list|,
name|vul
argument_list|,
name|vuc
argument_list|,
literal|15
argument_list|)
expr_stmt|;
comment|// CHECK: call<16 x i8> @llvm.s390.vmslg(<2 x i64> %{{.*}},<2 x i64> %{{.*}},<16 x i8> %{{.*}}, i32 15)
block|}
end_function

begin_function
name|void
name|test_float
parameter_list|(
name|void
parameter_list|)
block|{
name|vd
operator|=
name|__builtin_s390_vfmaxdb
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x double> @llvm.maxnum.v2f64(<2 x double> %{{.*}},<2 x double> %{{.*}})
name|vd
operator|=
name|__builtin_s390_vfmaxdb
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x double> @llvm.s390.vfmaxdb(<2 x double> %{{.*}},<2 x double> %{{.*}}, i32 0)
name|vd
operator|=
name|__builtin_s390_vfmaxdb
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|,
literal|15
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x double> @llvm.s390.vfmaxdb(<2 x double> %{{.*}},<2 x double> %{{.*}}, i32 15)
name|vd
operator|=
name|__builtin_s390_vfmindb
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x double> @llvm.minnum.v2f64(<2 x double> %{{.*}},<2 x double> %{{.*}})
name|vd
operator|=
name|__builtin_s390_vfmindb
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x double> @llvm.s390.vfmindb(<2 x double> %{{.*}},<2 x double> %{{.*}}, i32 0)
name|vd
operator|=
name|__builtin_s390_vfmindb
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|,
literal|15
argument_list|)
expr_stmt|;
comment|// CHECK: call<2 x double> @llvm.s390.vfmindb(<2 x double> %{{.*}},<2 x double> %{{.*}}, i32 15)
name|vd
operator|=
name|__builtin_s390_vfnmadb
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|,
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: [[RES:%[^ ]+]] = call<2 x double> @llvm.fma.v2f64(<2 x double> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}})
comment|// CHECK: fsub<2 x double><double -0.000000e+00, double -0.000000e+00>, [[RES]]
name|vd
operator|=
name|__builtin_s390_vfnmsdb
argument_list|(
name|vd
argument_list|,
name|vd
argument_list|,
name|vd
argument_list|)
expr_stmt|;
comment|// CHECK: [[NEG:%[^ ]+]] = fsub<2 x double><double -0.000000e+00, double -0.000000e+00>, %{{.*}}
comment|// CHECK: [[RES:%[^ ]+]] = call<2 x double> @llvm.fma.v2f64(<2 x double> %{{.*}},<2 x double> %{{.*}},<2 x double> [[NEG]])
comment|// CHECK: fsub<2 x double><double -0.000000e+00, double -0.000000e+00>, [[RES]]
name|vsi
operator|=
name|__builtin_s390_vfcesbs
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
operator|&
name|cc
argument_list|)
expr_stmt|;
comment|// CHECK: call {<4 x i32>, i32 } @llvm.s390.vfcesbs(<4 x float> %{{.*}},<4 x float> %{{.*}})
name|vsi
operator|=
name|__builtin_s390_vfchsbs
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
operator|&
name|cc
argument_list|)
expr_stmt|;
comment|// CHECK: call {<4 x i32>, i32 } @llvm.s390.vfchsbs(<4 x float> %{{.*}},<4 x float> %{{.*}})
name|vsi
operator|=
name|__builtin_s390_vfchesbs
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
operator|&
name|cc
argument_list|)
expr_stmt|;
comment|// CHECK: call {<4 x i32>, i32 } @llvm.s390.vfchesbs(<4 x float> %{{.*}},<4 x float> %{{.*}})
name|vsi
operator|=
name|__builtin_s390_vftcisb
argument_list|(
name|vf
argument_list|,
literal|0
argument_list|,
operator|&
name|cc
argument_list|)
expr_stmt|;
comment|// CHECK: call {<4 x i32>, i32 } @llvm.s390.vftcisb(<4 x float> %{{.*}}, i32 0)
name|vsi
operator|=
name|__builtin_s390_vftcisb
argument_list|(
name|vf
argument_list|,
literal|4095
argument_list|,
operator|&
name|cc
argument_list|)
expr_stmt|;
comment|// CHECK: call {<4 x i32>, i32 } @llvm.s390.vftcisb(<4 x float> %{{.*}}, i32 4095)
name|vf
operator|=
name|__builtin_s390_vfmaxsb
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x float> @llvm.maxnum.v4f32(<4 x float> %{{.*}},<4 x float> %{{.*}})
name|vf
operator|=
name|__builtin_s390_vfmaxsb
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x float> @llvm.s390.vfmaxsb(<4 x float> %{{.*}},<4 x float> %{{.*}}, i32 0)
name|vf
operator|=
name|__builtin_s390_vfmaxsb
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
literal|15
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x float> @llvm.s390.vfmaxsb(<4 x float> %{{.*}},<4 x float> %{{.*}}, i32 15)
name|vf
operator|=
name|__builtin_s390_vfminsb
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x float> @llvm.minnum.v4f32(<4 x float> %{{.*}},<4 x float> %{{.*}})
name|vf
operator|=
name|__builtin_s390_vfminsb
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x float> @llvm.s390.vfminsb(<4 x float> %{{.*}},<4 x float> %{{.*}}, i32 0)
name|vf
operator|=
name|__builtin_s390_vfminsb
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
literal|15
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x float> @llvm.s390.vfminsb(<4 x float> %{{.*}},<4 x float> %{{.*}}, i32 15)
name|vf
operator|=
name|__builtin_s390_vfsqsb
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x float> @llvm.sqrt.v4f32(<4 x float> %{{.*}})
name|vf
operator|=
name|__builtin_s390_vfmasb
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x float> @llvm.fma.v4f32(<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}})
name|vf
operator|=
name|__builtin_s390_vfmssb
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: [[NEG:%[^ ]+]] = fsub<4 x float><float -0.000000e+00, float -0.000000e+00, float -0.000000e+00, float -0.000000e+00>, %{{.*}}
comment|// CHECK: call<4 x float> @llvm.fma.v4f32(<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x float> [[NEG]])
name|vf
operator|=
name|__builtin_s390_vfnmasb
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: [[RES:%[^ ]+]] = call<4 x float> @llvm.fma.v4f32(<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}})
comment|// CHECK: fsub<4 x float><float -0.000000e+00, float -0.000000e+00, float -0.000000e+00, float -0.000000e+00>, [[RES]]
name|vf
operator|=
name|__builtin_s390_vfnmssb
argument_list|(
name|vf
argument_list|,
name|vf
argument_list|,
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: [[NEG:%[^ ]+]] = fsub<4 x float><float -0.000000e+00, float -0.000000e+00, float -0.000000e+00, float -0.000000e+00>, %{{.*}}
comment|// CHECK: [[RES:%[^ ]+]] = call<4 x float> @llvm.fma.v4f32(<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x float> [[NEG]])
comment|// CHECK: fsub<4 x float><float -0.000000e+00, float -0.000000e+00, float -0.000000e+00, float -0.000000e+00>, [[RES]]
name|vf
operator|=
name|__builtin_s390_vflpsb
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x float> @llvm.fabs.v4f32(<4 x float> %{{.*}})
name|vf
operator|=
name|__builtin_s390_vflnsb
argument_list|(
name|vf
argument_list|)
expr_stmt|;
comment|// CHECK: [[ABS:%[^ ]+]] = call<4 x float> @llvm.fabs.v4f32(<4 x float> %{{.*}})
comment|// CHECK: fsub<4 x float><float -0.000000e+00, float -0.000000e+00, float -0.000000e+00, float -0.000000e+00>, [[ABS]]
name|vf
operator|=
name|__builtin_s390_vfisb
argument_list|(
name|vf
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x float> @llvm.rint.v4f32(<4 x float> %{{.*}})
name|vf
operator|=
name|__builtin_s390_vfisb
argument_list|(
name|vf
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x float> @llvm.nearbyint.v4f32(<4 x float> %{{.*}})
name|vf
operator|=
name|__builtin_s390_vfisb
argument_list|(
name|vf
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x float> @llvm.round.v4f32(<4 x float> %{{.*}})
name|vf
operator|=
name|__builtin_s390_vfisb
argument_list|(
name|vf
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x float> @llvm.trunc.v4f32(<4 x float> %{{.*}})
name|vf
operator|=
name|__builtin_s390_vfisb
argument_list|(
name|vf
argument_list|,
literal|4
argument_list|,
literal|6
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x float> @llvm.ceil.v4f32(<4 x float> %{{.*}})
name|vf
operator|=
name|__builtin_s390_vfisb
argument_list|(
name|vf
argument_list|,
literal|4
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x float> @llvm.floor.v4f32(<4 x float> %{{.*}})
name|vf
operator|=
name|__builtin_s390_vfisb
argument_list|(
name|vf
argument_list|,
literal|4
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// CHECK: call<4 x float> @llvm.s390.vfisb(<4 x float> %{{.*}}, i32 4, i32 4)
block|}
end_function

end_unit

