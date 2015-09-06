begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple s390x-linux-gnu -target-cpu z13 -fzvector \
end_comment

begin_comment
comment|// RUN:  -O -emit-llvm -o - -W -Wall -Werror %s | FileCheck %s
end_comment

begin_decl_stmt
specifier|volatile
name|vector
name|signed
name|char
name|sc
decl_stmt|,
name|sc2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vector
name|unsigned
name|char
name|uc
decl_stmt|,
name|uc2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vector
name|bool
name|char
name|bc
decl_stmt|,
name|bc2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vector
name|signed
name|short
name|ss
decl_stmt|,
name|ss2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vector
name|unsigned
name|short
name|us
decl_stmt|,
name|us2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vector
name|bool
name|short
name|bs
decl_stmt|,
name|bs2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vector
name|signed
name|int
name|si
decl_stmt|,
name|si2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vector
name|unsigned
name|int
name|ui
decl_stmt|,
name|ui2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vector
name|bool
name|int
name|bi
decl_stmt|,
name|bi2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vector
name|signed
name|long
name|long
name|sl
decl_stmt|,
name|sl2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vector
name|unsigned
name|long
name|long
name|ul
decl_stmt|,
name|ul2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vector
name|bool
name|long
name|long
name|bl
decl_stmt|,
name|bl2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vector
name|double
name|fd
decl_stmt|,
name|fd2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|int
name|cnt
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test_assign
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_assign
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: store volatile<16 x i8> [[VAL]],<16 x i8>* @sc
name|sc
operator|=
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: store volatile<16 x i8> [[VAL]],<16 x i8>* @uc
name|uc
operator|=
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: store volatile<8 x i16> [[VAL]],<8 x i16>* @ss
name|ss
operator|=
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: store volatile<8 x i16> [[VAL]],<8 x i16>* @us
name|us
operator|=
name|us2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: store volatile<4 x i32> [[VAL]],<4 x i32>* @si
name|si
operator|=
name|si2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: store volatile<4 x i32> [[VAL]],<4 x i32>* @ui
name|ui
operator|=
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: store volatile<2 x i64> [[VAL]],<2 x i64>* @sl
name|sl
operator|=
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: store volatile<2 x i64> [[VAL]],<2 x i64>* @ul
name|ul
operator|=
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd2
comment|// CHECK: store volatile<2 x double> [[VAL]],<2 x double>* @fd
name|fd
operator|=
name|fd2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_pos
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_pos
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: store volatile<16 x i8> [[VAL]],<16 x i8>* @sc
name|sc
operator|=
operator|+
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: store volatile<16 x i8> [[VAL]],<16 x i8>* @uc
name|uc
operator|=
operator|+
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: store volatile<8 x i16> [[VAL]],<8 x i16>* @ss
name|ss
operator|=
operator|+
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: store volatile<8 x i16> [[VAL]],<8 x i16>* @us
name|us
operator|=
operator|+
name|us2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: store volatile<4 x i32> [[VAL]],<4 x i32>* @si
name|si
operator|=
operator|+
name|si2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: store volatile<4 x i32> [[VAL]],<4 x i32>* @ui
name|ui
operator|=
operator|+
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: store volatile<2 x i64> [[VAL]],<2 x i64>* @sl
name|sl
operator|=
operator|+
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: store volatile<2 x i64> [[VAL]],<2 x i64>* @ul
name|ul
operator|=
operator|+
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd2
comment|// CHECK: store volatile<2 x double> [[VAL]],<2 x double>* @fd
name|fd
operator|=
operator|+
name|fd2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_neg
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_neg
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: %{{.*}} = sub<16 x i8> zeroinitializer, [[VAL]]
name|sc
operator|=
operator|-
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: %{{.*}} = sub<8 x i16> zeroinitializer, [[VAL]]
name|ss
operator|=
operator|-
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: %{{.*}} = sub<4 x i32> zeroinitializer, [[VAL]]
name|si
operator|=
operator|-
name|si2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: %{{.*}} = sub<2 x i64> zeroinitializer, [[VAL]]
name|sl
operator|=
operator|-
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd2
comment|// CHECK: %{{.*}} = fsub<2 x double><double -0.000000e+00, double -0.000000e+00>, [[VAL]]
name|fd
operator|=
operator|-
name|fd2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_preinc
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_preinc
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: %{{.*}} = add<16 x i8> [[VAL]],<i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>
operator|++
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: %{{.*}} = add<16 x i8> [[VAL]],<i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>
operator|++
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: %{{.*}} = add<8 x i16> [[VAL]],<i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>
operator|++
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: %{{.*}} = add<8 x i16> [[VAL]],<i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>
operator|++
name|us2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: %{{.*}} = add<4 x i32> [[VAL]],<i32 1, i32 1, i32 1, i32 1>
operator|++
name|si2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: %{{.*}} = add<4 x i32> [[VAL]],<i32 1, i32 1, i32 1, i32 1>
operator|++
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: %{{.*}} = add<2 x i64> [[VAL]],<i64 1, i64 1>
operator|++
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: %{{.*}} = add<2 x i64> [[VAL]],<i64 1, i64 1>
operator|++
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd2
comment|// CHECK: %{{.*}} = fadd<2 x double> [[VAL]],<double 1.000000e+00, double 1.000000e+00>
operator|++
name|fd2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_postinc
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_postinc
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: %{{.*}} = add<16 x i8> [[VAL]],<i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>
name|sc2
operator|++
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: %{{.*}} = add<16 x i8> [[VAL]],<i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>
name|uc2
operator|++
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: %{{.*}} = add<8 x i16> [[VAL]],<i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>
name|ss2
operator|++
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: %{{.*}} = add<8 x i16> [[VAL]],<i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>
name|us2
operator|++
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: %{{.*}} = add<4 x i32> [[VAL]],<i32 1, i32 1, i32 1, i32 1>
name|si2
operator|++
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: %{{.*}} = add<4 x i32> [[VAL]],<i32 1, i32 1, i32 1, i32 1>
name|ui2
operator|++
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: %{{.*}} = add<2 x i64> [[VAL]],<i64 1, i64 1>
name|sl2
operator|++
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: %{{.*}} = add<2 x i64> [[VAL]],<i64 1, i64 1>
name|ul2
operator|++
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd2
comment|// CHECK: %{{.*}} = fadd<2 x double> [[VAL]],<double 1.000000e+00, double 1.000000e+00>
name|fd2
operator|++
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_predec
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_predec
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: %{{.*}} = add<16 x i8> [[VAL]],<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
operator|--
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: %{{.*}} = add<16 x i8> [[VAL]],<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
operator|--
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: %{{.*}} = add<8 x i16> [[VAL]],<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
operator|--
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: %{{.*}} = add<8 x i16> [[VAL]],<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
operator|--
name|us2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: %{{.*}} = add<4 x i32> [[VAL]],<i32 -1, i32 -1, i32 -1, i32 -1>
operator|--
name|si2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: %{{.*}} = add<4 x i32> [[VAL]],<i32 -1, i32 -1, i32 -1, i32 -1>
operator|--
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: %{{.*}} = add<2 x i64> [[VAL]],<i64 -1, i64 -1>
operator|--
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: %{{.*}} = add<2 x i64> [[VAL]],<i64 -1, i64 -1>
operator|--
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd2
comment|// CHECK: %{{.*}} = fadd<2 x double> [[VAL]],<double -1.000000e+00, double -1.000000e+00>
operator|--
name|fd2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_postdec
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_postdec
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: %{{.*}} = add<16 x i8> [[VAL]],<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
name|sc2
operator|--
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: %{{.*}} = add<16 x i8> [[VAL]],<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
name|uc2
operator|--
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: %{{.*}} = add<8 x i16> [[VAL]],<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
name|ss2
operator|--
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: %{{.*}} = add<8 x i16> [[VAL]],<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
name|us2
operator|--
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: %{{.*}} = add<4 x i32> [[VAL]],<i32 -1, i32 -1, i32 -1, i32 -1>
name|si2
operator|--
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: %{{.*}} = add<4 x i32> [[VAL]],<i32 -1, i32 -1, i32 -1, i32 -1>
name|ui2
operator|--
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: %{{.*}} = add<2 x i64> [[VAL]],<i64 -1, i64 -1>
name|sl2
operator|--
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: %{{.*}} = add<2 x i64> [[VAL]],<i64 -1, i64 -1>
name|ul2
operator|--
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd2
comment|// CHECK: %{{.*}} = fadd<2 x double> [[VAL]],<double -1.000000e+00, double -1.000000e+00>
name|fd2
operator|--
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_add
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_add
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: %{{.*}} = add<16 x i8> [[VAL2]], [[VAL1]]
name|sc
operator|=
name|sc
operator|+
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: %{{.*}} = add<16 x i8> [[VAL2]], [[VAL1]]
name|sc
operator|=
name|sc
operator|+
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: %{{.*}} = add<16 x i8> [[VAL2]], [[VAL1]]
name|sc
operator|=
name|bc
operator|+
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: %{{.*}} = add<16 x i8> [[VAL2]], [[VAL1]]
name|uc
operator|=
name|uc
operator|+
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: %{{.*}} = add<16 x i8> [[VAL2]], [[VAL1]]
name|uc
operator|=
name|uc
operator|+
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: %{{.*}} = add<16 x i8> [[VAL2]], [[VAL1]]
name|uc
operator|=
name|bc
operator|+
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: %{{.*}} = add<8 x i16> [[VAL2]], [[VAL1]]
name|ss
operator|=
name|ss
operator|+
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: %{{.*}} = add<8 x i16> [[VAL2]], [[VAL1]]
name|ss
operator|=
name|ss
operator|+
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: %{{.*}} = add<8 x i16> [[VAL2]], [[VAL1]]
name|ss
operator|=
name|bs
operator|+
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: %{{.*}} = add<8 x i16> [[VAL2]], [[VAL1]]
name|us
operator|=
name|us
operator|+
name|us2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: %{{.*}} = add<8 x i16> [[VAL2]], [[VAL1]]
name|us
operator|=
name|us
operator|+
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: %{{.*}} = add<8 x i16> [[VAL2]], [[VAL1]]
name|us
operator|=
name|bs
operator|+
name|us2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: %{{.*}} = add<4 x i32> [[VAL2]], [[VAL1]]
name|si
operator|=
name|si
operator|+
name|si2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: %{{.*}} = add<4 x i32> [[VAL2]], [[VAL1]]
name|si
operator|=
name|si
operator|+
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: %{{.*}} = add<4 x i32> [[VAL2]], [[VAL1]]
name|si
operator|=
name|bi
operator|+
name|si2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: %{{.*}} = add<4 x i32> [[VAL2]], [[VAL1]]
name|ui
operator|=
name|ui
operator|+
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: %{{.*}} = add<4 x i32> [[VAL2]], [[VAL1]]
name|ui
operator|=
name|ui
operator|+
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: %{{.*}} = add<4 x i32> [[VAL2]], [[VAL1]]
name|ui
operator|=
name|bi
operator|+
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: %{{.*}} = add<2 x i64> [[VAL2]], [[VAL1]]
name|sl
operator|=
name|sl
operator|+
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: %{{.*}} = add<2 x i64> [[VAL2]], [[VAL1]]
name|sl
operator|=
name|sl
operator|+
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: %{{.*}} = add<2 x i64> [[VAL2]], [[VAL1]]
name|sl
operator|=
name|bl
operator|+
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: %{{.*}} = add<2 x i64> [[VAL2]], [[VAL1]]
name|ul
operator|=
name|ul
operator|+
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: %{{.*}} = add<2 x i64> [[VAL2]], [[VAL1]]
name|ul
operator|=
name|ul
operator|+
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: %{{.*}} = add<2 x i64> [[VAL2]], [[VAL1]]
name|ul
operator|=
name|bl
operator|+
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd2
comment|// CHECK: %{{.*}} = fadd<2 x double> [[VAL1]], [[VAL2]]
name|fd
operator|=
name|fd
operator|+
name|fd2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_add_assign
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_add_assign
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: %{{.*}} = add<16 x i8> [[VAL1]], [[VAL2]]
name|sc
operator|+=
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: %{{.*}} = add<16 x i8> [[VAL1]], [[VAL2]]
name|sc
operator|+=
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: %{{.*}} = add<16 x i8> [[VAL1]], [[VAL2]]
name|uc
operator|+=
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: %{{.*}} = add<16 x i8> [[VAL1]], [[VAL2]]
name|uc
operator|+=
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: %{{.*}} = add<8 x i16> [[VAL1]], [[VAL2]]
name|ss
operator|+=
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: %{{.*}} = add<8 x i16> [[VAL1]], [[VAL2]]
name|ss
operator|+=
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: %{{.*}} = add<8 x i16> [[VAL1]], [[VAL2]]
name|us
operator|+=
name|us2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: %{{.*}} = add<8 x i16> [[VAL1]], [[VAL2]]
name|us
operator|+=
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: %{{.*}} = add<4 x i32> [[VAL1]], [[VAL2]]
name|si
operator|+=
name|si2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: %{{.*}} = add<4 x i32> [[VAL1]], [[VAL2]]
name|si
operator|+=
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: %{{.*}} = add<4 x i32> [[VAL1]], [[VAL2]]
name|ui
operator|+=
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: %{{.*}} = add<4 x i32> [[VAL1]], [[VAL2]]
name|ui
operator|+=
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: %{{.*}} = add<2 x i64> [[VAL1]], [[VAL2]]
name|sl
operator|+=
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: %{{.*}} = add<2 x i64> [[VAL1]], [[VAL2]]
name|sl
operator|+=
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: %{{.*}} = add<2 x i64> [[VAL1]], [[VAL2]]
name|ul
operator|+=
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: %{{.*}} = add<2 x i64> [[VAL1]], [[VAL2]]
name|ul
operator|+=
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd
comment|// CHECK: %{{.*}} = fadd<2 x double> [[VAL2]], [[VAL1]]
name|fd
operator|+=
name|fd2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_sub
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_sub
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: %{{.*}} = sub<16 x i8> [[VAL1]], [[VAL2]]
name|sc
operator|=
name|sc
operator|-
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: %{{.*}} = sub<16 x i8> [[VAL1]], [[VAL2]]
name|sc
operator|=
name|sc
operator|-
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: %{{.*}} = sub<16 x i8> [[VAL1]], [[VAL2]]
name|sc
operator|=
name|bc
operator|-
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: %{{.*}} = sub<16 x i8> [[VAL1]], [[VAL2]]
name|uc
operator|=
name|uc
operator|-
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: %{{.*}} = sub<16 x i8> [[VAL1]], [[VAL2]]
name|uc
operator|=
name|uc
operator|-
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: %{{.*}} = sub<16 x i8> [[VAL1]], [[VAL2]]
name|uc
operator|=
name|bc
operator|-
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: %{{.*}} = sub<8 x i16> [[VAL1]], [[VAL2]]
name|ss
operator|=
name|ss
operator|-
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: %{{.*}} = sub<8 x i16> [[VAL1]], [[VAL2]]
name|ss
operator|=
name|ss
operator|-
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: %{{.*}} = sub<8 x i16> [[VAL1]], [[VAL2]]
name|ss
operator|=
name|bs
operator|-
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: %{{.*}} = sub<8 x i16> [[VAL1]], [[VAL2]]
name|us
operator|=
name|us
operator|-
name|us2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: %{{.*}} = sub<8 x i16> [[VAL1]], [[VAL2]]
name|us
operator|=
name|us
operator|-
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: %{{.*}} = sub<8 x i16> [[VAL1]], [[VAL2]]
name|us
operator|=
name|bs
operator|-
name|us2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: %{{.*}} = sub<4 x i32> [[VAL1]], [[VAL2]]
name|si
operator|=
name|si
operator|-
name|si2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: %{{.*}} = sub<4 x i32> [[VAL1]], [[VAL2]]
name|si
operator|=
name|si
operator|-
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: %{{.*}} = sub<4 x i32> [[VAL1]], [[VAL2]]
name|si
operator|=
name|bi
operator|-
name|si2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: %{{.*}} = sub<4 x i32> [[VAL1]], [[VAL2]]
name|ui
operator|=
name|ui
operator|-
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: %{{.*}} = sub<4 x i32> [[VAL1]], [[VAL2]]
name|ui
operator|=
name|ui
operator|-
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: %{{.*}} = sub<4 x i32> [[VAL1]], [[VAL2]]
name|ui
operator|=
name|bi
operator|-
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: %{{.*}} = sub<2 x i64> [[VAL1]], [[VAL2]]
name|sl
operator|=
name|sl
operator|-
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: %{{.*}} = sub<2 x i64> [[VAL1]], [[VAL2]]
name|sl
operator|=
name|sl
operator|-
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: %{{.*}} = sub<2 x i64> [[VAL1]], [[VAL2]]
name|sl
operator|=
name|bl
operator|-
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: %{{.*}} = sub<2 x i64> [[VAL1]], [[VAL2]]
name|ul
operator|=
name|ul
operator|-
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: %{{.*}} = sub<2 x i64> [[VAL1]], [[VAL2]]
name|ul
operator|=
name|ul
operator|-
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: %{{.*}} = sub<2 x i64> [[VAL1]], [[VAL2]]
name|ul
operator|=
name|bl
operator|-
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd2
comment|// CHECK: %{{.*}} = fsub<2 x double> [[VAL1]], [[VAL2]]
name|fd
operator|=
name|fd
operator|-
name|fd2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_sub_assign
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_sub_assign
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: %{{.*}} = sub<16 x i8> [[VAL1]], [[VAL2]]
name|sc
operator|-=
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: %{{.*}} = sub<16 x i8> [[VAL1]], [[VAL2]]
name|sc
operator|-=
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: %{{.*}} = sub<16 x i8> [[VAL1]], [[VAL2]]
name|uc
operator|-=
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: %{{.*}} = sub<16 x i8> [[VAL1]], [[VAL2]]
name|uc
operator|-=
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: %{{.*}} = sub<8 x i16> [[VAL1]], [[VAL2]]
name|ss
operator|-=
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: %{{.*}} = sub<8 x i16> [[VAL1]], [[VAL2]]
name|ss
operator|-=
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: %{{.*}} = sub<8 x i16> [[VAL1]], [[VAL2]]
name|us
operator|-=
name|us2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: %{{.*}} = sub<8 x i16> [[VAL1]], [[VAL2]]
name|us
operator|-=
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: %{{.*}} = sub<4 x i32> [[VAL1]], [[VAL2]]
name|si
operator|-=
name|si2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: %{{.*}} = sub<4 x i32> [[VAL1]], [[VAL2]]
name|si
operator|-=
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: %{{.*}} = sub<4 x i32> [[VAL1]], [[VAL2]]
name|ui
operator|-=
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: %{{.*}} = sub<4 x i32> [[VAL1]], [[VAL2]]
name|ui
operator|-=
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: %{{.*}} = sub<2 x i64> [[VAL1]], [[VAL2]]
name|sl
operator|-=
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: %{{.*}} = sub<2 x i64> [[VAL1]], [[VAL2]]
name|sl
operator|-=
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: %{{.*}} = sub<2 x i64> [[VAL1]], [[VAL2]]
name|ul
operator|-=
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: %{{.*}} = sub<2 x i64> [[VAL1]], [[VAL2]]
name|ul
operator|-=
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd
comment|// CHECK: %{{.*}} = fsub<2 x double> [[VAL1]], [[VAL2]]
name|fd
operator|-=
name|fd2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mul
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mul
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: %{{.*}} = mul<16 x i8> [[VAL2]], [[VAL1]]
name|sc
operator|=
name|sc
operator|*
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: %{{.*}} = mul<16 x i8> [[VAL2]], [[VAL1]]
name|uc
operator|=
name|uc
operator|*
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: %{{.*}} = mul<8 x i16> [[VAL2]], [[VAL1]]
name|ss
operator|=
name|ss
operator|*
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: %{{.*}} = mul<8 x i16> [[VAL2]], [[VAL1]]
name|us
operator|=
name|us
operator|*
name|us2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: %{{.*}} = mul<4 x i32> [[VAL2]], [[VAL1]]
name|si
operator|=
name|si
operator|*
name|si2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: %{{.*}} = mul<4 x i32> [[VAL2]], [[VAL1]]
name|ui
operator|=
name|ui
operator|*
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: %{{.*}} = mul<2 x i64> [[VAL2]], [[VAL1]]
name|sl
operator|=
name|sl
operator|*
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: %{{.*}} = mul<2 x i64> [[VAL2]], [[VAL1]]
name|ul
operator|=
name|ul
operator|*
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd2
comment|// CHECK: %{{.*}} = fmul<2 x double> [[VAL1]], [[VAL2]]
name|fd
operator|=
name|fd
operator|*
name|fd2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mul_assign
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mul_assign
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: %{{.*}} = mul<16 x i8> [[VAL1]], [[VAL2]]
name|sc
operator|*=
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: %{{.*}} = mul<16 x i8> [[VAL1]], [[VAL2]]
name|uc
operator|*=
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: %{{.*}} = mul<8 x i16> [[VAL1]], [[VAL2]]
name|ss
operator|*=
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: %{{.*}} = mul<8 x i16> [[VAL1]], [[VAL2]]
name|us
operator|*=
name|us2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: %{{.*}} = mul<4 x i32> [[VAL1]], [[VAL2]]
name|si
operator|*=
name|si2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: %{{.*}} = mul<4 x i32> [[VAL1]], [[VAL2]]
name|ui
operator|*=
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: %{{.*}} = mul<2 x i64> [[VAL1]], [[VAL2]]
name|sl
operator|*=
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: %{{.*}} = mul<2 x i64> [[VAL1]], [[VAL2]]
name|ul
operator|*=
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd
comment|// CHECK: %{{.*}} = fmul<2 x double> [[VAL2]], [[VAL1]]
name|fd
operator|*=
name|fd2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_div
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_div
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: %{{.*}} = sdiv<16 x i8> [[VAL1]], [[VAL2]]
name|sc
operator|=
name|sc
operator|/
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: %{{.*}} = udiv<16 x i8> [[VAL1]], [[VAL2]]
name|uc
operator|=
name|uc
operator|/
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: %{{.*}} = sdiv<8 x i16> [[VAL1]], [[VAL2]]
name|ss
operator|=
name|ss
operator|/
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: %{{.*}} = udiv<8 x i16> [[VAL1]], [[VAL2]]
name|us
operator|=
name|us
operator|/
name|us2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: %{{.*}} = sdiv<4 x i32> [[VAL1]], [[VAL2]]
name|si
operator|=
name|si
operator|/
name|si2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: %{{.*}} = udiv<4 x i32> [[VAL1]], [[VAL2]]
name|ui
operator|=
name|ui
operator|/
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: %{{.*}} = sdiv<2 x i64> [[VAL1]], [[VAL2]]
name|sl
operator|=
name|sl
operator|/
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: %{{.*}} = udiv<2 x i64> [[VAL1]], [[VAL2]]
name|ul
operator|=
name|ul
operator|/
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd2
comment|// CHECK: %{{.*}} = fdiv<2 x double> [[VAL1]], [[VAL2]]
name|fd
operator|=
name|fd
operator|/
name|fd2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_div_assign
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_div_assign
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: %{{.*}} = sdiv<16 x i8> [[VAL1]], [[VAL2]]
name|sc
operator|/=
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: %{{.*}} = udiv<16 x i8> [[VAL1]], [[VAL2]]
name|uc
operator|/=
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: %{{.*}} = sdiv<8 x i16> [[VAL1]], [[VAL2]]
name|ss
operator|/=
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: %{{.*}} = udiv<8 x i16> [[VAL1]], [[VAL2]]
name|us
operator|/=
name|us2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: %{{.*}} = sdiv<4 x i32> [[VAL1]], [[VAL2]]
name|si
operator|/=
name|si2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: %{{.*}} = udiv<4 x i32> [[VAL1]], [[VAL2]]
name|ui
operator|/=
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: %{{.*}} = sdiv<2 x i64> [[VAL1]], [[VAL2]]
name|sl
operator|/=
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: %{{.*}} = udiv<2 x i64> [[VAL1]], [[VAL2]]
name|ul
operator|/=
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd
comment|// CHECK: %{{.*}} = fdiv<2 x double> [[VAL1]], [[VAL2]]
name|fd
operator|/=
name|fd2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_rem
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_rem
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: %{{.*}} = srem<16 x i8> [[VAL1]], [[VAL2]]
name|sc
operator|=
name|sc
operator|%
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: %{{.*}} = urem<16 x i8> [[VAL1]], [[VAL2]]
name|uc
operator|=
name|uc
operator|%
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: %{{.*}} = srem<8 x i16> [[VAL1]], [[VAL2]]
name|ss
operator|=
name|ss
operator|%
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: %{{.*}} = urem<8 x i16> [[VAL1]], [[VAL2]]
name|us
operator|=
name|us
operator|%
name|us2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: %{{.*}} = srem<4 x i32> [[VAL1]], [[VAL2]]
name|si
operator|=
name|si
operator|%
name|si2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: %{{.*}} = urem<4 x i32> [[VAL1]], [[VAL2]]
name|ui
operator|=
name|ui
operator|%
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: %{{.*}} = srem<2 x i64> [[VAL1]], [[VAL2]]
name|sl
operator|=
name|sl
operator|%
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: %{{.*}} = urem<2 x i64> [[VAL1]], [[VAL2]]
name|ul
operator|=
name|ul
operator|%
name|ul2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_rem_assign
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_rem_assign
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: %{{.*}} = srem<16 x i8> [[VAL1]], [[VAL2]]
name|sc
operator|%=
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: %{{.*}} = urem<16 x i8> [[VAL1]], [[VAL2]]
name|uc
operator|%=
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: %{{.*}} = srem<8 x i16> [[VAL1]], [[VAL2]]
name|ss
operator|%=
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: %{{.*}} = urem<8 x i16> [[VAL1]], [[VAL2]]
name|us
operator|%=
name|us2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: %{{.*}} = srem<4 x i32> [[VAL1]], [[VAL2]]
name|si
operator|%=
name|si2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: %{{.*}} = urem<4 x i32> [[VAL1]], [[VAL2]]
name|ui
operator|%=
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: %{{.*}} = srem<2 x i64> [[VAL1]], [[VAL2]]
name|sl
operator|%=
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: %{{.*}} = urem<2 x i64> [[VAL1]], [[VAL2]]
name|ul
operator|%=
name|ul2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_not
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_not
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: %{{.*}} = xor<16 x i8> [[VAL]],<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
name|sc
operator|=
operator|~
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: %{{.*}} = xor<16 x i8> [[VAL]],<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
name|uc
operator|=
operator|~
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: %{{.*}} = xor<16 x i8> [[VAL]],<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
name|bc
operator|=
operator|~
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: %{{.*}} = xor<8 x i16> [[VAL]],<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
name|ss
operator|=
operator|~
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: %{{.*}} = xor<8 x i16> [[VAL]],<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
name|us
operator|=
operator|~
name|us2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: %{{.*}} = xor<8 x i16> [[VAL]],<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
name|bs
operator|=
operator|~
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: %{{.*}} = xor<4 x i32> [[VAL]],<i32 -1, i32 -1, i32 -1, i32 -1>
name|si
operator|=
operator|~
name|si2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: %{{.*}} = xor<4 x i32> [[VAL]],<i32 -1, i32 -1, i32 -1, i32 -1>
name|ui
operator|=
operator|~
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: %{{.*}} = xor<4 x i32> [[VAL]],<i32 -1, i32 -1, i32 -1, i32 -1>
name|bi
operator|=
operator|~
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: %{{.*}} = xor<2 x i64> [[VAL]],<i64 -1, i64 -1>
name|sl
operator|=
operator|~
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: %{{.*}} = xor<2 x i64> [[VAL]],<i64 -1, i64 -1>
name|ul
operator|=
operator|~
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: %{{.*}} = xor<2 x i64> [[VAL]],<i64 -1, i64 -1>
name|bl
operator|=
operator|~
name|bl2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_and
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_and
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: %{{.*}} = and<16 x i8> [[VAL2]], [[VAL1]]
name|sc
operator|=
name|sc
operator|&
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: %{{.*}} = and<16 x i8> [[VAL2]], [[VAL1]]
name|sc
operator|=
name|sc
operator|&
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: %{{.*}} = and<16 x i8> [[VAL2]], [[VAL1]]
name|sc
operator|=
name|bc
operator|&
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: %{{.*}} = and<16 x i8> [[VAL2]], [[VAL1]]
name|uc
operator|=
name|uc
operator|&
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: %{{.*}} = and<16 x i8> [[VAL2]], [[VAL1]]
name|uc
operator|=
name|uc
operator|&
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: %{{.*}} = and<16 x i8> [[VAL2]], [[VAL1]]
name|uc
operator|=
name|bc
operator|&
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: %{{.*}} = and<16 x i8> [[VAL2]], [[VAL1]]
name|bc
operator|=
name|bc
operator|&
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: %{{.*}} = and<8 x i16> [[VAL2]], [[VAL1]]
name|ss
operator|=
name|ss
operator|&
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: %{{.*}} = and<8 x i16> [[VAL2]], [[VAL1]]
name|ss
operator|=
name|ss
operator|&
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: %{{.*}} = and<8 x i16> [[VAL2]], [[VAL1]]
name|ss
operator|=
name|bs
operator|&
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: %{{.*}} = and<8 x i16> [[VAL2]], [[VAL1]]
name|us
operator|=
name|us
operator|&
name|us2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: %{{.*}} = and<8 x i16> [[VAL2]], [[VAL1]]
name|us
operator|=
name|us
operator|&
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: %{{.*}} = and<8 x i16> [[VAL2]], [[VAL1]]
name|us
operator|=
name|bs
operator|&
name|us2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: %{{.*}} = and<8 x i16> [[VAL2]], [[VAL1]]
name|bs
operator|=
name|bs
operator|&
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: %{{.*}} = and<4 x i32> [[VAL2]], [[VAL1]]
name|si
operator|=
name|si
operator|&
name|si2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: %{{.*}} = and<4 x i32> [[VAL2]], [[VAL1]]
name|si
operator|=
name|si
operator|&
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: %{{.*}} = and<4 x i32> [[VAL2]], [[VAL1]]
name|si
operator|=
name|bi
operator|&
name|si2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: %{{.*}} = and<4 x i32> [[VAL2]], [[VAL1]]
name|ui
operator|=
name|ui
operator|&
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: %{{.*}} = and<4 x i32> [[VAL2]], [[VAL1]]
name|ui
operator|=
name|ui
operator|&
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: %{{.*}} = and<4 x i32> [[VAL2]], [[VAL1]]
name|ui
operator|=
name|bi
operator|&
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: %{{.*}} = and<4 x i32> [[VAL2]], [[VAL1]]
name|bi
operator|=
name|bi
operator|&
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: %{{.*}} = and<2 x i64> [[VAL2]], [[VAL1]]
name|sl
operator|=
name|sl
operator|&
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: %{{.*}} = and<2 x i64> [[VAL2]], [[VAL1]]
name|sl
operator|=
name|sl
operator|&
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: %{{.*}} = and<2 x i64> [[VAL2]], [[VAL1]]
name|sl
operator|=
name|bl
operator|&
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: %{{.*}} = and<2 x i64> [[VAL2]], [[VAL1]]
name|ul
operator|=
name|ul
operator|&
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: %{{.*}} = and<2 x i64> [[VAL2]], [[VAL1]]
name|ul
operator|=
name|ul
operator|&
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: %{{.*}} = and<2 x i64> [[VAL2]], [[VAL1]]
name|ul
operator|=
name|bl
operator|&
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: %{{.*}} = and<2 x i64> [[VAL2]], [[VAL1]]
name|bl
operator|=
name|bl
operator|&
name|bl2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_and_assign
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_and_assign
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: %{{.*}} = and<16 x i8> [[VAL1]], [[VAL2]]
name|sc
operator|&=
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: %{{.*}} = and<16 x i8> [[VAL1]], [[VAL2]]
name|sc
operator|&=
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: %{{.*}} = and<16 x i8> [[VAL1]], [[VAL2]]
name|uc
operator|&=
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: %{{.*}} = and<16 x i8> [[VAL1]], [[VAL2]]
name|uc
operator|&=
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc
comment|// CHECK: %{{.*}} = and<16 x i8> [[VAL1]], [[VAL2]]
name|bc
operator|&=
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: %{{.*}} = and<8 x i16> [[VAL1]], [[VAL2]]
name|ss
operator|&=
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: %{{.*}} = and<8 x i16> [[VAL1]], [[VAL2]]
name|ss
operator|&=
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: %{{.*}} = and<8 x i16> [[VAL1]], [[VAL2]]
name|us
operator|&=
name|us2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: %{{.*}} = and<8 x i16> [[VAL1]], [[VAL2]]
name|us
operator|&=
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs
comment|// CHECK: %{{.*}} = and<8 x i16> [[VAL1]], [[VAL2]]
name|bs
operator|&=
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: %{{.*}} = and<4 x i32> [[VAL1]], [[VAL2]]
name|si
operator|&=
name|si2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: %{{.*}} = and<4 x i32> [[VAL1]], [[VAL2]]
name|si
operator|&=
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: %{{.*}} = and<4 x i32> [[VAL1]], [[VAL2]]
name|ui
operator|&=
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: %{{.*}} = and<4 x i32> [[VAL1]], [[VAL2]]
name|ui
operator|&=
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi
comment|// CHECK: %{{.*}} = and<4 x i32> [[VAL1]], [[VAL2]]
name|bi
operator|&=
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: %{{.*}} = and<2 x i64> [[VAL1]], [[VAL2]]
name|sl
operator|&=
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: %{{.*}} = and<2 x i64> [[VAL1]], [[VAL2]]
name|sl
operator|&=
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: %{{.*}} = and<2 x i64> [[VAL1]], [[VAL2]]
name|ul
operator|&=
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: %{{.*}} = and<2 x i64> [[VAL1]], [[VAL2]]
name|ul
operator|&=
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl
comment|// CHECK: %{{.*}} = and<2 x i64> [[VAL1]], [[VAL2]]
name|bl
operator|&=
name|bl2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_or
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_or
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: %{{.*}} = or<16 x i8> [[VAL2]], [[VAL1]]
name|sc
operator|=
name|sc
operator||
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: %{{.*}} = or<16 x i8> [[VAL2]], [[VAL1]]
name|sc
operator|=
name|sc
operator||
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: %{{.*}} = or<16 x i8> [[VAL2]], [[VAL1]]
name|sc
operator|=
name|bc
operator||
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: %{{.*}} = or<16 x i8> [[VAL2]], [[VAL1]]
name|uc
operator|=
name|uc
operator||
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: %{{.*}} = or<16 x i8> [[VAL2]], [[VAL1]]
name|uc
operator|=
name|uc
operator||
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: %{{.*}} = or<16 x i8> [[VAL2]], [[VAL1]]
name|uc
operator|=
name|bc
operator||
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: %{{.*}} = or<16 x i8> [[VAL2]], [[VAL1]]
name|bc
operator|=
name|bc
operator||
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: %{{.*}} = or<8 x i16> [[VAL2]], [[VAL1]]
name|ss
operator|=
name|ss
operator||
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: %{{.*}} = or<8 x i16> [[VAL2]], [[VAL1]]
name|ss
operator|=
name|ss
operator||
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: %{{.*}} = or<8 x i16> [[VAL2]], [[VAL1]]
name|ss
operator|=
name|bs
operator||
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: %{{.*}} = or<8 x i16> [[VAL2]], [[VAL1]]
name|us
operator|=
name|us
operator||
name|us2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: %{{.*}} = or<8 x i16> [[VAL2]], [[VAL1]]
name|us
operator|=
name|us
operator||
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: %{{.*}} = or<8 x i16> [[VAL2]], [[VAL1]]
name|us
operator|=
name|bs
operator||
name|us2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: %{{.*}} = or<8 x i16> [[VAL2]], [[VAL1]]
name|bs
operator|=
name|bs
operator||
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: %{{.*}} = or<4 x i32> [[VAL2]], [[VAL1]]
name|si
operator|=
name|si
operator||
name|si2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: %{{.*}} = or<4 x i32> [[VAL2]], [[VAL1]]
name|si
operator|=
name|si
operator||
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: %{{.*}} = or<4 x i32> [[VAL2]], [[VAL1]]
name|si
operator|=
name|bi
operator||
name|si2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: %{{.*}} = or<4 x i32> [[VAL2]], [[VAL1]]
name|ui
operator|=
name|ui
operator||
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: %{{.*}} = or<4 x i32> [[VAL2]], [[VAL1]]
name|ui
operator|=
name|ui
operator||
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: %{{.*}} = or<4 x i32> [[VAL2]], [[VAL1]]
name|ui
operator|=
name|bi
operator||
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: %{{.*}} = or<4 x i32> [[VAL2]], [[VAL1]]
name|bi
operator|=
name|bi
operator||
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: %{{.*}} = or<2 x i64> [[VAL2]], [[VAL1]]
name|sl
operator|=
name|sl
operator||
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: %{{.*}} = or<2 x i64> [[VAL2]], [[VAL1]]
name|sl
operator|=
name|sl
operator||
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: %{{.*}} = or<2 x i64> [[VAL2]], [[VAL1]]
name|sl
operator|=
name|bl
operator||
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: %{{.*}} = or<2 x i64> [[VAL2]], [[VAL1]]
name|ul
operator|=
name|ul
operator||
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: %{{.*}} = or<2 x i64> [[VAL2]], [[VAL1]]
name|ul
operator|=
name|ul
operator||
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: %{{.*}} = or<2 x i64> [[VAL2]], [[VAL1]]
name|ul
operator|=
name|bl
operator||
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: %{{.*}} = or<2 x i64> [[VAL2]], [[VAL1]]
name|bl
operator|=
name|bl
operator||
name|bl2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_or_assign
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_or_assign
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: %{{.*}} = or<16 x i8> [[VAL1]], [[VAL2]]
name|sc
operator||=
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: %{{.*}} = or<16 x i8> [[VAL1]], [[VAL2]]
name|sc
operator||=
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: %{{.*}} = or<16 x i8> [[VAL1]], [[VAL2]]
name|uc
operator||=
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: %{{.*}} = or<16 x i8> [[VAL1]], [[VAL2]]
name|uc
operator||=
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc
comment|// CHECK: %{{.*}} = or<16 x i8> [[VAL1]], [[VAL2]]
name|bc
operator||=
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: %{{.*}} = or<8 x i16> [[VAL1]], [[VAL2]]
name|ss
operator||=
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: %{{.*}} = or<8 x i16> [[VAL1]], [[VAL2]]
name|ss
operator||=
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: %{{.*}} = or<8 x i16> [[VAL1]], [[VAL2]]
name|us
operator||=
name|us2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: %{{.*}} = or<8 x i16> [[VAL1]], [[VAL2]]
name|us
operator||=
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs
comment|// CHECK: %{{.*}} = or<8 x i16> [[VAL1]], [[VAL2]]
name|bs
operator||=
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: %{{.*}} = or<4 x i32> [[VAL1]], [[VAL2]]
name|si
operator||=
name|si2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: %{{.*}} = or<4 x i32> [[VAL1]], [[VAL2]]
name|si
operator||=
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: %{{.*}} = or<4 x i32> [[VAL1]], [[VAL2]]
name|ui
operator||=
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: %{{.*}} = or<4 x i32> [[VAL1]], [[VAL2]]
name|ui
operator||=
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi
comment|// CHECK: %{{.*}} = or<4 x i32> [[VAL1]], [[VAL2]]
name|bi
operator||=
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: %{{.*}} = or<2 x i64> [[VAL1]], [[VAL2]]
name|sl
operator||=
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: %{{.*}} = or<2 x i64> [[VAL1]], [[VAL2]]
name|sl
operator||=
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: %{{.*}} = or<2 x i64> [[VAL1]], [[VAL2]]
name|ul
operator||=
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: %{{.*}} = or<2 x i64> [[VAL1]], [[VAL2]]
name|ul
operator||=
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl
comment|// CHECK: %{{.*}} = or<2 x i64> [[VAL1]], [[VAL2]]
name|bl
operator||=
name|bl2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_xor
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_xor
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: %{{.*}} = xor<16 x i8> [[VAL1]], [[VAL2]]
name|sc
operator|=
name|sc
operator|^
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: %{{.*}} = xor<16 x i8> [[VAL1]], [[VAL2]]
name|sc
operator|=
name|sc
operator|^
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: %{{.*}} = xor<16 x i8> [[VAL1]], [[VAL2]]
name|sc
operator|=
name|bc
operator|^
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: %{{.*}} = xor<16 x i8> [[VAL1]], [[VAL2]]
name|uc
operator|=
name|uc
operator|^
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: %{{.*}} = xor<16 x i8> [[VAL1]], [[VAL2]]
name|uc
operator|=
name|uc
operator|^
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: %{{.*}} = xor<16 x i8> [[VAL1]], [[VAL2]]
name|uc
operator|=
name|bc
operator|^
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: %{{.*}} = xor<16 x i8> [[VAL1]], [[VAL2]]
name|bc
operator|=
name|bc
operator|^
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: %{{.*}} = xor<8 x i16> [[VAL1]], [[VAL2]]
name|ss
operator|=
name|ss
operator|^
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: %{{.*}} = xor<8 x i16> [[VAL1]], [[VAL2]]
name|ss
operator|=
name|ss
operator|^
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: %{{.*}} = xor<8 x i16> [[VAL1]], [[VAL2]]
name|ss
operator|=
name|bs
operator|^
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: %{{.*}} = xor<8 x i16> [[VAL1]], [[VAL2]]
name|us
operator|=
name|us
operator|^
name|us2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: %{{.*}} = xor<8 x i16> [[VAL1]], [[VAL2]]
name|us
operator|=
name|us
operator|^
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: %{{.*}} = xor<8 x i16> [[VAL1]], [[VAL2]]
name|us
operator|=
name|bs
operator|^
name|us2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: %{{.*}} = xor<8 x i16> [[VAL1]], [[VAL2]]
name|bs
operator|=
name|bs
operator|^
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: %{{.*}} = xor<4 x i32> [[VAL1]], [[VAL2]]
name|si
operator|=
name|si
operator|^
name|si2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: %{{.*}} = xor<4 x i32> [[VAL1]], [[VAL2]]
name|si
operator|=
name|si
operator|^
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: %{{.*}} = xor<4 x i32> [[VAL1]], [[VAL2]]
name|si
operator|=
name|bi
operator|^
name|si2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: %{{.*}} = xor<4 x i32> [[VAL1]], [[VAL2]]
name|ui
operator|=
name|ui
operator|^
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: %{{.*}} = xor<4 x i32> [[VAL1]], [[VAL2]]
name|ui
operator|=
name|ui
operator|^
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: %{{.*}} = xor<4 x i32> [[VAL1]], [[VAL2]]
name|ui
operator|=
name|bi
operator|^
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: %{{.*}} = xor<4 x i32> [[VAL1]], [[VAL2]]
name|bi
operator|=
name|bi
operator|^
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: %{{.*}} = xor<2 x i64> [[VAL1]], [[VAL2]]
name|sl
operator|=
name|sl
operator|^
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: %{{.*}} = xor<2 x i64> [[VAL1]], [[VAL2]]
name|sl
operator|=
name|sl
operator|^
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: %{{.*}} = xor<2 x i64> [[VAL1]], [[VAL2]]
name|sl
operator|=
name|bl
operator|^
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: %{{.*}} = xor<2 x i64> [[VAL1]], [[VAL2]]
name|ul
operator|=
name|ul
operator|^
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: %{{.*}} = xor<2 x i64> [[VAL1]], [[VAL2]]
name|ul
operator|=
name|ul
operator|^
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: %{{.*}} = xor<2 x i64> [[VAL1]], [[VAL2]]
name|ul
operator|=
name|bl
operator|^
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: %{{.*}} = xor<2 x i64> [[VAL1]], [[VAL2]]
name|bl
operator|=
name|bl
operator|^
name|bl2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_xor_assign
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_xor_assign
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: %{{.*}} = xor<16 x i8> [[VAL2]], [[VAL1]]
name|sc
operator|^=
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: %{{.*}} = xor<16 x i8> [[VAL2]], [[VAL1]]
name|sc
operator|^=
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: %{{.*}} = xor<16 x i8> [[VAL2]], [[VAL1]]
name|uc
operator|^=
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: %{{.*}} = xor<16 x i8> [[VAL2]], [[VAL1]]
name|uc
operator|^=
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc
comment|// CHECK: %{{.*}} = xor<16 x i8> [[VAL2]], [[VAL1]]
name|bc
operator|^=
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: %{{.*}} = xor<8 x i16> [[VAL2]], [[VAL1]]
name|ss
operator|^=
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: %{{.*}} = xor<8 x i16> [[VAL2]], [[VAL1]]
name|ss
operator|^=
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: %{{.*}} = xor<8 x i16> [[VAL2]], [[VAL1]]
name|us
operator|^=
name|us2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: %{{.*}} = xor<8 x i16> [[VAL2]], [[VAL1]]
name|us
operator|^=
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs
comment|// CHECK: %{{.*}} = xor<8 x i16> [[VAL2]], [[VAL1]]
name|bs
operator|^=
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: %{{.*}} = xor<4 x i32> [[VAL2]], [[VAL1]]
name|si
operator|^=
name|si2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: %{{.*}} = xor<4 x i32> [[VAL2]], [[VAL1]]
name|si
operator|^=
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: %{{.*}} = xor<4 x i32> [[VAL2]], [[VAL1]]
name|ui
operator|^=
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: %{{.*}} = xor<4 x i32> [[VAL2]], [[VAL1]]
name|ui
operator|^=
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi
comment|// CHECK: %{{.*}} = xor<4 x i32> [[VAL2]], [[VAL1]]
name|bi
operator|^=
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: %{{.*}} = xor<2 x i64> [[VAL2]], [[VAL1]]
name|sl
operator|^=
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: %{{.*}} = xor<2 x i64> [[VAL2]], [[VAL1]]
name|sl
operator|^=
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: %{{.*}} = xor<2 x i64> [[VAL2]], [[VAL1]]
name|ul
operator|^=
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: %{{.*}} = xor<2 x i64> [[VAL2]], [[VAL1]]
name|ul
operator|^=
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl
comment|// CHECK: %{{.*}} = xor<2 x i64> [[VAL2]], [[VAL1]]
name|bl
operator|^=
name|bl2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_sl
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_sl
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: %{{.*}} = shl<16 x i8> [[VAL]], [[CNT]]
name|sc
operator|=
name|sc
operator|<<
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: %{{.*}} = shl<16 x i8> [[VAL]], [[CNT]]
name|sc
operator|=
name|sc
operator|<<
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T2:%[^ ]+]] = insertelement<16 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[T3:%[^ ]+]] = shufflevector<16 x i32> [[T2]],<16 x i32> undef,<16 x i32> zeroinitializer
comment|// CHECK: [[CNT:%[^ ]+]] = trunc<16 x i32> [[T3]] to<16 x i8>
comment|// CHECK: %{{.*}} = shl<16 x i8> [[VAL]], [[CNT]]
name|sc
operator|=
name|sc
operator|<<
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: %{{.*}} = shl<16 x i8> [[VAL]],<i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5>
name|sc
operator|=
name|sc
operator|<<
literal|5
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: %{{.*}} = shl<16 x i8> [[VAL]], [[CNT]]
name|uc
operator|=
name|uc
operator|<<
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: %{{.*}} = shl<16 x i8> [[VAL]], [[CNT]]
name|uc
operator|=
name|uc
operator|<<
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T2:%[^ ]+]] = insertelement<16 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[T3:%[^ ]+]] = shufflevector<16 x i32> [[T2]],<16 x i32> undef,<16 x i32> zeroinitializer
comment|// CHECK: [[CNT:%[^ ]+]] = trunc<16 x i32> [[T3]] to<16 x i8>
comment|// CHECK: %{{.*}} = shl<16 x i8> [[VAL]], [[CNT]]
name|uc
operator|=
name|uc
operator|<<
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: %{{.*}} = shl<16 x i8> [[VAL]],<i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5>
name|uc
operator|=
name|uc
operator|<<
literal|5
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: %{{.*}} = shl<8 x i16> [[VAL]], [[CNT]]
name|ss
operator|=
name|ss
operator|<<
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: %{{.*}} = shl<8 x i16> [[VAL]], [[CNT]]
name|ss
operator|=
name|ss
operator|<<
name|us2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T2:%[^ ]+]] = insertelement<8 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[T3:%[^ ]+]] = shufflevector<8 x i32> [[T2]],<8 x i32> undef,<8 x i32> zeroinitializer
comment|// CHECK: [[CNT:%[^ ]+]] = trunc<8 x i32> [[T3]] to<8 x i16>
comment|// CHECK: %{{.*}} = shl<8 x i16> [[VAL]], [[CNT]]
name|ss
operator|=
name|ss
operator|<<
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: %{{.*}} = shl<8 x i16> [[VAL]],<i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5>
name|ss
operator|=
name|ss
operator|<<
literal|5
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: %{{.*}} = shl<8 x i16> [[VAL]], [[CNT]]
name|us
operator|=
name|us
operator|<<
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: %{{.*}} = shl<8 x i16> [[VAL]], [[CNT]]
name|us
operator|=
name|us
operator|<<
name|us2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T2:%[^ ]+]] = insertelement<8 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[T3:%[^ ]+]] = shufflevector<8 x i32> [[T2]],<8 x i32> undef,<8 x i32> zeroinitializer
comment|// CHECK: [[CNT:%[^ ]+]] = trunc<8 x i32> [[T3]] to<8 x i16>
comment|// CHECK: %{{.*}} = shl<8 x i16> [[VAL]], [[CNT]]
name|us
operator|=
name|us
operator|<<
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: %{{.*}} = shl<8 x i16> [[VAL]],<i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5>
name|us
operator|=
name|us
operator|<<
literal|5
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: %{{.*}} = shl<4 x i32> [[VAL]], [[CNT]]
name|si
operator|=
name|si
operator|<<
name|si2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: %{{.*}} = shl<4 x i32> [[VAL]], [[CNT]]
name|si
operator|=
name|si
operator|<<
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T3:%[^ ]+]] = insertelement<4 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[CNT:%[^ ]+]] = shufflevector<4 x i32> [[T3]],<4 x i32> undef,<4 x i32> zeroinitializer
comment|// CHECK: %{{.*}} = shl<4 x i32> [[VAL]], [[CNT]]
name|si
operator|=
name|si
operator|<<
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: %{{.*}} = shl<4 x i32> [[VAL]],<i32 5, i32 5, i32 5, i32 5>
name|si
operator|=
name|si
operator|<<
literal|5
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: %{{.*}} = shl<4 x i32> [[VAL]], [[CNT]]
name|ui
operator|=
name|ui
operator|<<
name|si2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: %{{.*}} = shl<4 x i32> [[VAL]], [[CNT]]
name|ui
operator|=
name|ui
operator|<<
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T3:%[^ ]+]] = insertelement<4 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[CNT:%[^ ]+]] = shufflevector<4 x i32> [[T3]],<4 x i32> undef,<4 x i32> zeroinitializer
comment|// CHECK: %{{.*}} = shl<4 x i32> [[VAL]], [[CNT]]
name|ui
operator|=
name|ui
operator|<<
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: %{{.*}} = shl<4 x i32> [[VAL]],<i32 5, i32 5, i32 5, i32 5>
name|ui
operator|=
name|ui
operator|<<
literal|5
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: %{{.*}} = shl<2 x i64> [[VAL]], [[CNT]]
name|sl
operator|=
name|sl
operator|<<
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: %{{.*}} = shl<2 x i64> [[VAL]], [[CNT]]
name|sl
operator|=
name|sl
operator|<<
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T2:%[^ ]+]] = insertelement<2 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[T3:%[^ ]+]] = shufflevector<2 x i32> [[T2]],<2 x i32> undef,<2 x i32> zeroinitializer
comment|// CHECK: [[CNT:%[^ ]+]] = zext<2 x i32> [[T3]] to<2 x i64>
comment|// CHECK: %{{.*}} = shl<2 x i64> [[VAL]], [[CNT]]
name|sl
operator|=
name|sl
operator|<<
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: %{{.*}} = shl<2 x i64> [[VAL]],<i64 5, i64 5>
name|sl
operator|=
name|sl
operator|<<
literal|5
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: %{{.*}} = shl<2 x i64> [[VAL]], [[CNT]]
name|ul
operator|=
name|ul
operator|<<
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: %{{.*}} = shl<2 x i64> [[VAL]], [[CNT]]
name|ul
operator|=
name|ul
operator|<<
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T2:%[^ ]+]] = insertelement<2 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[T3:%[^ ]+]] = shufflevector<2 x i32> [[T2]],<2 x i32> undef,<2 x i32> zeroinitializer
comment|// CHECK: [[CNT:%[^ ]+]] = zext<2 x i32> [[T3]] to<2 x i64>
comment|// CHECK: %{{.*}} = shl<2 x i64> [[VAL]], [[CNT]]
name|ul
operator|=
name|ul
operator|<<
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: %{{.*}} = shl<2 x i64> [[VAL]],<i64 5, i64 5>
name|ul
operator|=
name|ul
operator|<<
literal|5
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_sl_assign
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_sl_assign
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: %{{.*}} = shl<16 x i8> [[VAL]], [[CNT]]
name|sc
operator|<<=
name|sc2
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: %{{.*}} = shl<16 x i8> [[VAL]], [[CNT]]
name|sc
operator|<<=
name|uc2
expr_stmt|;
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T2:%[^ ]+]] = insertelement<16 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[T3:%[^ ]+]] = shufflevector<16 x i32> [[T2]],<16 x i32> undef,<16 x i32> zeroinitializer
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[CNT:%[^ ]+]] = trunc<16 x i32> [[T3]] to<16 x i8>
comment|// CHECK: %{{.*}} = shl<16 x i8> [[VAL]], [[CNT]]
name|sc
operator|<<=
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: %{{.*}} = shl<16 x i8> [[VAL]],<i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5>
name|sc
operator|<<=
literal|5
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: %{{.*}} = shl<16 x i8> [[VAL]], [[CNT]]
name|uc
operator|<<=
name|sc2
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: %{{.*}} = shl<16 x i8> [[VAL]], [[CNT]]
name|uc
operator|<<=
name|uc2
expr_stmt|;
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T2:%[^ ]+]] = insertelement<16 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[T3:%[^ ]+]] = shufflevector<16 x i32> [[T2]],<16 x i32> undef,<16 x i32> zeroinitializer
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[CNT:%[^ ]+]] = trunc<16 x i32> [[T3]] to<16 x i8>
comment|// CHECK: %{{.*}} = shl<16 x i8> [[VAL]], [[CNT]]
name|uc
operator|<<=
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: %{{.*}} = shl<16 x i8> [[VAL]],<i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5>
name|uc
operator|<<=
literal|5
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: %{{.*}} = shl<8 x i16> [[VAL]], [[CNT]]
name|ss
operator|<<=
name|ss2
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: %{{.*}} = shl<8 x i16> [[VAL]], [[CNT]]
name|ss
operator|<<=
name|us2
expr_stmt|;
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T2:%[^ ]+]] = insertelement<8 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[T3:%[^ ]+]] = shufflevector<8 x i32> [[T2]],<8 x i32> undef,<8 x i32> zeroinitializer
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[CNT:%[^ ]+]] = trunc<8 x i32> [[T3]] to<8 x i16>
comment|// CHECK: %{{.*}} = shl<8 x i16> [[VAL]], [[CNT]]
name|ss
operator|<<=
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: %{{.*}} = shl<8 x i16> [[VAL]],<i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5>
name|ss
operator|<<=
literal|5
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: %{{.*}} = shl<8 x i16> [[VAL]], [[CNT]]
name|us
operator|<<=
name|ss2
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: %{{.*}} = shl<8 x i16> [[VAL]], [[CNT]]
name|us
operator|<<=
name|us2
expr_stmt|;
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T2:%[^ ]+]] = insertelement<8 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[T3:%[^ ]+]] = shufflevector<8 x i32> [[T2]],<8 x i32> undef,<8 x i32> zeroinitializer
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[CNT:%[^ ]+]] = trunc<8 x i32> [[T3]] to<8 x i16>
comment|// CHECK: %{{.*}} = shl<8 x i16> [[VAL]], [[CNT]]
name|us
operator|<<=
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: %{{.*}} = shl<8 x i16> [[VAL]],<i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5>
name|us
operator|<<=
literal|5
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: %{{.*}} = shl<4 x i32> [[VAL]], [[CNT]]
name|si
operator|<<=
name|si2
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: %{{.*}} = shl<4 x i32> [[VAL]], [[CNT]]
name|si
operator|<<=
name|ui2
expr_stmt|;
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T3:%[^ ]+]] = insertelement<4 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[CNT:%[^ ]+]] = shufflevector<4 x i32> [[T3]],<4 x i32> undef,<4 x i32> zeroinitializer
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: %{{.*}} = shl<4 x i32> [[VAL]], [[CNT]]
name|si
operator|<<=
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: %{{.*}} = shl<4 x i32> [[VAL]],<i32 5, i32 5, i32 5, i32 5>
name|si
operator|<<=
literal|5
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: %{{.*}} = shl<4 x i32> [[VAL]], [[CNT]]
name|ui
operator|<<=
name|si2
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: %{{.*}} = shl<4 x i32> [[VAL]], [[CNT]]
name|ui
operator|<<=
name|ui2
expr_stmt|;
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T3:%[^ ]+]] = insertelement<4 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[CNT:%[^ ]+]] = shufflevector<4 x i32> [[T3]],<4 x i32> undef,<4 x i32> zeroinitializer
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: %{{.*}} = shl<4 x i32> [[VAL]], [[CNT]]
name|ui
operator|<<=
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: %{{.*}} = shl<4 x i32> [[VAL]],<i32 5, i32 5, i32 5, i32 5>
name|ui
operator|<<=
literal|5
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: %{{.*}} = shl<2 x i64> [[VAL]], [[CNT]]
name|sl
operator|<<=
name|sl2
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: %{{.*}} = shl<2 x i64> [[VAL]], [[CNT]]
name|sl
operator|<<=
name|ul2
expr_stmt|;
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T2:%[^ ]+]] = insertelement<2 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[T3:%[^ ]+]] = shufflevector<2 x i32> [[T2]],<2 x i32> undef,<2 x i32> zeroinitializer
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[CNT:%[^ ]+]] = zext<2 x i32> [[T3]] to<2 x i64>
comment|// CHECK: %{{.*}} = shl<2 x i64> [[VAL]], [[CNT]]
name|sl
operator|<<=
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: %{{.*}} = shl<2 x i64> [[VAL]],<i64 5, i64 5>
name|sl
operator|<<=
literal|5
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: %{{.*}} = shl<2 x i64> [[VAL]], [[CNT]]
name|ul
operator|<<=
name|sl2
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: %{{.*}} = shl<2 x i64> [[VAL]], [[CNT]]
name|ul
operator|<<=
name|ul2
expr_stmt|;
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T2:%[^ ]+]] = insertelement<2 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[T3:%[^ ]+]] = shufflevector<2 x i32> [[T2]],<2 x i32> undef,<2 x i32> zeroinitializer
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[CNT:%[^ ]+]] = zext<2 x i32> [[T3]] to<2 x i64>
comment|// CHECK: %{{.*}} = shl<2 x i64> [[VAL]], [[CNT]]
name|ul
operator|<<=
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: %{{.*}} = shl<2 x i64> [[VAL]],<i64 5, i64 5>
name|ul
operator|<<=
literal|5
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_sr
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_sr
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: %{{.*}} = ashr<16 x i8> [[VAL]], [[CNT]]
name|sc
operator|=
name|sc
operator|>>
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: %{{.*}} = ashr<16 x i8> [[VAL]], [[CNT]]
name|sc
operator|=
name|sc
operator|>>
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T2:%[^ ]+]] = insertelement<16 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[T3:%[^ ]+]] = shufflevector<16 x i32> [[T2]],<16 x i32> undef,<16 x i32> zeroinitializer
comment|// CHECK: [[CNT:%[^ ]+]] = trunc<16 x i32> [[T3]] to<16 x i8>
comment|// CHECK: %{{.*}} = ashr<16 x i8> [[VAL]], [[CNT]]
name|sc
operator|=
name|sc
operator|>>
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: %{{.*}} = ashr<16 x i8> [[VAL]],<i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5>
name|sc
operator|=
name|sc
operator|>>
literal|5
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: %{{.*}} = lshr<16 x i8> [[VAL]], [[CNT]]
name|uc
operator|=
name|uc
operator|>>
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: %{{.*}} = lshr<16 x i8> [[VAL]], [[CNT]]
name|uc
operator|=
name|uc
operator|>>
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T2:%[^ ]+]] = insertelement<16 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[T3:%[^ ]+]] = shufflevector<16 x i32> [[T2]],<16 x i32> undef,<16 x i32> zeroinitializer
comment|// CHECK: [[CNT:%[^ ]+]] = trunc<16 x i32> [[T3]] to<16 x i8>
comment|// CHECK: %{{.*}} = lshr<16 x i8> [[VAL]], [[CNT]]
name|uc
operator|=
name|uc
operator|>>
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: %{{.*}} = lshr<16 x i8> [[VAL]],<i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5>
name|uc
operator|=
name|uc
operator|>>
literal|5
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: %{{.*}} = ashr<8 x i16> [[VAL]], [[CNT]]
name|ss
operator|=
name|ss
operator|>>
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: %{{.*}} = ashr<8 x i16> [[VAL]], [[CNT]]
name|ss
operator|=
name|ss
operator|>>
name|us2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T2:%[^ ]+]] = insertelement<8 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[T3:%[^ ]+]] = shufflevector<8 x i32> [[T2]],<8 x i32> undef,<8 x i32> zeroinitializer
comment|// CHECK: [[CNT:%[^ ]+]] = trunc<8 x i32> [[T3]] to<8 x i16>
comment|// CHECK: %{{.*}} = ashr<8 x i16> [[VAL]], [[CNT]]
name|ss
operator|=
name|ss
operator|>>
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: %{{.*}} = ashr<8 x i16> [[VAL]],<i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5>
name|ss
operator|=
name|ss
operator|>>
literal|5
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: %{{.*}} = lshr<8 x i16> [[VAL]], [[CNT]]
name|us
operator|=
name|us
operator|>>
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: %{{.*}} = lshr<8 x i16> [[VAL]], [[CNT]]
name|us
operator|=
name|us
operator|>>
name|us2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T2:%[^ ]+]] = insertelement<8 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[T3:%[^ ]+]] = shufflevector<8 x i32> [[T2]],<8 x i32> undef,<8 x i32> zeroinitializer
comment|// CHECK: [[CNT:%[^ ]+]] = trunc<8 x i32> [[T3]] to<8 x i16>
comment|// CHECK: %{{.*}} = lshr<8 x i16> [[VAL]], [[CNT]]
name|us
operator|=
name|us
operator|>>
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: %{{.*}} = lshr<8 x i16> [[VAL]],<i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5>
name|us
operator|=
name|us
operator|>>
literal|5
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: %{{.*}} = ashr<4 x i32> [[VAL]], [[CNT]]
name|si
operator|=
name|si
operator|>>
name|si2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: %{{.*}} = ashr<4 x i32> [[VAL]], [[CNT]]
name|si
operator|=
name|si
operator|>>
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T3:%[^ ]+]] = insertelement<4 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[CNT:%[^ ]+]] = shufflevector<4 x i32> [[T3]],<4 x i32> undef,<4 x i32> zeroinitializer
comment|// CHECK: %{{.*}} = ashr<4 x i32> [[VAL]], [[CNT]]
name|si
operator|=
name|si
operator|>>
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: %{{.*}} = ashr<4 x i32> [[VAL]],<i32 5, i32 5, i32 5, i32 5>
name|si
operator|=
name|si
operator|>>
literal|5
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: %{{.*}} = lshr<4 x i32> [[VAL]], [[CNT]]
name|ui
operator|=
name|ui
operator|>>
name|si2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: %{{.*}} = lshr<4 x i32> [[VAL]], [[CNT]]
name|ui
operator|=
name|ui
operator|>>
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T3:%[^ ]+]] = insertelement<4 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[CNT:%[^ ]+]] = shufflevector<4 x i32> [[T3]],<4 x i32> undef,<4 x i32> zeroinitializer
comment|// CHECK: %{{.*}} = lshr<4 x i32> [[VAL]], [[CNT]]
name|ui
operator|=
name|ui
operator|>>
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: %{{.*}} = lshr<4 x i32> [[VAL]],<i32 5, i32 5, i32 5, i32 5>
name|ui
operator|=
name|ui
operator|>>
literal|5
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: %{{.*}} = ashr<2 x i64> [[VAL]], [[CNT]]
name|sl
operator|=
name|sl
operator|>>
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: %{{.*}} = ashr<2 x i64> [[VAL]], [[CNT]]
name|sl
operator|=
name|sl
operator|>>
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T2:%[^ ]+]] = insertelement<2 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[T3:%[^ ]+]] = shufflevector<2 x i32> [[T2]],<2 x i32> undef,<2 x i32> zeroinitializer
comment|// CHECK: [[CNT:%[^ ]+]] = zext<2 x i32> [[T3]] to<2 x i64>
comment|// CHECK: %{{.*}} = ashr<2 x i64> [[VAL]], [[CNT]]
name|sl
operator|=
name|sl
operator|>>
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: %{{.*}} = ashr<2 x i64> [[VAL]],<i64 5, i64 5>
name|sl
operator|=
name|sl
operator|>>
literal|5
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: %{{.*}} = lshr<2 x i64> [[VAL]], [[CNT]]
name|ul
operator|=
name|ul
operator|>>
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: %{{.*}} = lshr<2 x i64> [[VAL]], [[CNT]]
name|ul
operator|=
name|ul
operator|>>
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T2:%[^ ]+]] = insertelement<2 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[T3:%[^ ]+]] = shufflevector<2 x i32> [[T2]],<2 x i32> undef,<2 x i32> zeroinitializer
comment|// CHECK: [[CNT:%[^ ]+]] = zext<2 x i32> [[T3]] to<2 x i64>
comment|// CHECK: %{{.*}} = lshr<2 x i64> [[VAL]], [[CNT]]
name|ul
operator|=
name|ul
operator|>>
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: %{{.*}} = lshr<2 x i64> [[VAL]],<i64 5, i64 5>
name|ul
operator|=
name|ul
operator|>>
literal|5
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_sr_assign
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_sr_assign
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: %{{.*}} = ashr<16 x i8> [[VAL]], [[CNT]]
name|sc
operator|>>=
name|sc2
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: %{{.*}} = ashr<16 x i8> [[VAL]], [[CNT]]
name|sc
operator|>>=
name|uc2
expr_stmt|;
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T2:%[^ ]+]] = insertelement<16 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[T3:%[^ ]+]] = shufflevector<16 x i32> [[T2]],<16 x i32> undef,<16 x i32> zeroinitializer
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[CNT:%[^ ]+]] = trunc<16 x i32> [[T3]] to<16 x i8>
comment|// CHECK: %{{.*}} = ashr<16 x i8> [[VAL]], [[CNT]]
name|sc
operator|>>=
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: %{{.*}} = ashr<16 x i8> [[VAL]],<i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5>
name|sc
operator|>>=
literal|5
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: %{{.*}} = lshr<16 x i8> [[VAL]], [[CNT]]
name|uc
operator|>>=
name|sc2
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: %{{.*}} = lshr<16 x i8> [[VAL]], [[CNT]]
name|uc
operator|>>=
name|uc2
expr_stmt|;
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T2:%[^ ]+]] = insertelement<16 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[T3:%[^ ]+]] = shufflevector<16 x i32> [[T2]],<16 x i32> undef,<16 x i32> zeroinitializer
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[CNT:%[^ ]+]] = trunc<16 x i32> [[T3]] to<16 x i8>
comment|// CHECK: %{{.*}} = lshr<16 x i8> [[VAL]], [[CNT]]
name|uc
operator|>>=
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: %{{.*}} = lshr<16 x i8> [[VAL]],<i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5>
name|uc
operator|>>=
literal|5
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: %{{.*}} = ashr<8 x i16> [[VAL]], [[CNT]]
name|ss
operator|>>=
name|ss2
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: %{{.*}} = ashr<8 x i16> [[VAL]], [[CNT]]
name|ss
operator|>>=
name|us2
expr_stmt|;
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T2:%[^ ]+]] = insertelement<8 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[T3:%[^ ]+]] = shufflevector<8 x i32> [[T2]],<8 x i32> undef,<8 x i32> zeroinitializer
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[CNT:%[^ ]+]] = trunc<8 x i32> [[T3]] to<8 x i16>
comment|// CHECK: %{{.*}} = ashr<8 x i16> [[VAL]], [[CNT]]
name|ss
operator|>>=
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: %{{.*}} = ashr<8 x i16> [[VAL]],<i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5>
name|ss
operator|>>=
literal|5
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: %{{.*}} = lshr<8 x i16> [[VAL]], [[CNT]]
name|us
operator|>>=
name|ss2
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: %{{.*}} = lshr<8 x i16> [[VAL]], [[CNT]]
name|us
operator|>>=
name|us2
expr_stmt|;
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T2:%[^ ]+]] = insertelement<8 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[T3:%[^ ]+]] = shufflevector<8 x i32> [[T2]],<8 x i32> undef,<8 x i32> zeroinitializer
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[CNT:%[^ ]+]] = trunc<8 x i32> [[T3]] to<8 x i16>
comment|// CHECK: %{{.*}} = lshr<8 x i16> [[VAL]], [[CNT]]
name|us
operator|>>=
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: %{{.*}} = lshr<8 x i16> [[VAL]],<i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5>
name|us
operator|>>=
literal|5
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: %{{.*}} = ashr<4 x i32> [[VAL]], [[CNT]]
name|si
operator|>>=
name|si2
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: %{{.*}} = ashr<4 x i32> [[VAL]], [[CNT]]
name|si
operator|>>=
name|ui2
expr_stmt|;
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T3:%[^ ]+]] = insertelement<4 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[CNT:%[^ ]+]] = shufflevector<4 x i32> [[T3]],<4 x i32> undef,<4 x i32> zeroinitializer
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: %{{.*}} = ashr<4 x i32> [[VAL]], [[CNT]]
name|si
operator|>>=
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: %{{.*}} = ashr<4 x i32> [[VAL]],<i32 5, i32 5, i32 5, i32 5>
name|si
operator|>>=
literal|5
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: %{{.*}} = lshr<4 x i32> [[VAL]], [[CNT]]
name|ui
operator|>>=
name|si2
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: %{{.*}} = lshr<4 x i32> [[VAL]], [[CNT]]
name|ui
operator|>>=
name|ui2
expr_stmt|;
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T3:%[^ ]+]] = insertelement<4 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[CNT:%[^ ]+]] = shufflevector<4 x i32> [[T3]],<4 x i32> undef,<4 x i32> zeroinitializer
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: %{{.*}} = lshr<4 x i32> [[VAL]], [[CNT]]
name|ui
operator|>>=
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: %{{.*}} = lshr<4 x i32> [[VAL]],<i32 5, i32 5, i32 5, i32 5>
name|ui
operator|>>=
literal|5
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: %{{.*}} = ashr<2 x i64> [[VAL]], [[CNT]]
name|sl
operator|>>=
name|sl2
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: %{{.*}} = ashr<2 x i64> [[VAL]], [[CNT]]
name|sl
operator|>>=
name|ul2
expr_stmt|;
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T2:%[^ ]+]] = insertelement<2 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[T3:%[^ ]+]] = shufflevector<2 x i32> [[T2]],<2 x i32> undef,<2 x i32> zeroinitializer
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[CNT:%[^ ]+]] = zext<2 x i32> [[T3]] to<2 x i64>
comment|// CHECK: %{{.*}} = ashr<2 x i64> [[VAL]], [[CNT]]
name|sl
operator|>>=
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: %{{.*}} = ashr<2 x i64> [[VAL]],<i64 5, i64 5>
name|sl
operator|>>=
literal|5
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: %{{.*}} = lshr<2 x i64> [[VAL]], [[CNT]]
name|ul
operator|>>=
name|sl2
expr_stmt|;
comment|// CHECK: [[CNT:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: %{{.*}} = lshr<2 x i64> [[VAL]], [[CNT]]
name|ul
operator|>>=
name|ul2
expr_stmt|;
comment|// CHECK: [[T1:%[^ ]+]] = load volatile i32, i32* @cnt
comment|// CHECK: [[T2:%[^ ]+]] = insertelement<2 x i32> undef, i32 [[T1]], i32 0
comment|// CHECK: [[T3:%[^ ]+]] = shufflevector<2 x i32> [[T2]],<2 x i32> undef,<2 x i32> zeroinitializer
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[CNT:%[^ ]+]] = zext<2 x i32> [[T3]] to<2 x i64>
comment|// CHECK: %{{.*}} = lshr<2 x i64> [[VAL]], [[CNT]]
name|ul
operator|>>=
name|cnt
expr_stmt|;
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: %{{.*}} = lshr<2 x i64> [[VAL]],<i64 5, i64 5>
name|ul
operator|>>=
literal|5
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_cmpeq
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_cmpeq
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp eq<16 x i8> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<16 x i1> [[CMP]] to<16 x i8>
name|bc
operator|=
name|sc
operator|==
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp eq<16 x i8> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<16 x i1> [[CMP]] to<16 x i8>
name|bc
operator|=
name|sc
operator|==
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp eq<16 x i8> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<16 x i1> [[CMP]] to<16 x i8>
name|bc
operator|=
name|bc
operator|==
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp eq<16 x i8> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<16 x i1> [[CMP]] to<16 x i8>
name|bc
operator|=
name|uc
operator|==
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp eq<16 x i8> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<16 x i1> [[CMP]] to<16 x i8>
name|bc
operator|=
name|uc
operator|==
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp eq<16 x i8> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<16 x i1> [[CMP]] to<16 x i8>
name|bc
operator|=
name|bc
operator|==
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp eq<16 x i8> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<16 x i1> [[CMP]] to<16 x i8>
name|bc
operator|=
name|bc
operator|==
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp eq<8 x i16> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<8 x i1> [[CMP]] to<8 x i16>
name|bs
operator|=
name|ss
operator|==
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp eq<8 x i16> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<8 x i1> [[CMP]] to<8 x i16>
name|bs
operator|=
name|ss
operator|==
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp eq<8 x i16> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<8 x i1> [[CMP]] to<8 x i16>
name|bs
operator|=
name|bs
operator|==
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp eq<8 x i16> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<8 x i1> [[CMP]] to<8 x i16>
name|bs
operator|=
name|us
operator|==
name|us2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp eq<8 x i16> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<8 x i1> [[CMP]] to<8 x i16>
name|bs
operator|=
name|us
operator|==
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp eq<8 x i16> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<8 x i1> [[CMP]] to<8 x i16>
name|bs
operator|=
name|bs
operator|==
name|us2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp eq<8 x i16> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<8 x i1> [[CMP]] to<8 x i16>
name|bs
operator|=
name|bs
operator|==
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp eq<4 x i32> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|si
operator|==
name|si2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp eq<4 x i32> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|si
operator|==
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp eq<4 x i32> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|bi
operator|==
name|si2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp eq<4 x i32> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|ui
operator|==
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp eq<4 x i32> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|ui
operator|==
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp eq<4 x i32> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|bi
operator|==
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp eq<4 x i32> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|bi
operator|==
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp eq<2 x i64> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|sl
operator|==
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp eq<2 x i64> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|sl
operator|==
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp eq<2 x i64> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|bl
operator|==
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp eq<2 x i64> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|ul
operator|==
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp eq<2 x i64> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|ul
operator|==
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp eq<2 x i64> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|bl
operator|==
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp eq<2 x i64> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|bl
operator|==
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd2
comment|// CHECK: [[CMP:%[^ ]+]] = fcmp oeq<2 x double> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|fd
operator|==
name|fd2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_cmpne
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_cmpne
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ne<16 x i8> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<16 x i1> [[CMP]] to<16 x i8>
name|bc
operator|=
name|sc
operator|!=
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ne<16 x i8> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<16 x i1> [[CMP]] to<16 x i8>
name|bc
operator|=
name|sc
operator|!=
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ne<16 x i8> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<16 x i1> [[CMP]] to<16 x i8>
name|bc
operator|=
name|bc
operator|!=
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ne<16 x i8> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<16 x i1> [[CMP]] to<16 x i8>
name|bc
operator|=
name|uc
operator|!=
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ne<16 x i8> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<16 x i1> [[CMP]] to<16 x i8>
name|bc
operator|=
name|uc
operator|!=
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ne<16 x i8> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<16 x i1> [[CMP]] to<16 x i8>
name|bc
operator|=
name|bc
operator|!=
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ne<16 x i8> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<16 x i1> [[CMP]] to<16 x i8>
name|bc
operator|=
name|bc
operator|!=
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ne<8 x i16> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<8 x i1> [[CMP]] to<8 x i16>
name|bs
operator|=
name|ss
operator|!=
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ne<8 x i16> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<8 x i1> [[CMP]] to<8 x i16>
name|bs
operator|=
name|ss
operator|!=
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ne<8 x i16> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<8 x i1> [[CMP]] to<8 x i16>
name|bs
operator|=
name|bs
operator|!=
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ne<8 x i16> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<8 x i1> [[CMP]] to<8 x i16>
name|bs
operator|=
name|us
operator|!=
name|us2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ne<8 x i16> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<8 x i1> [[CMP]] to<8 x i16>
name|bs
operator|=
name|us
operator|!=
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ne<8 x i16> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<8 x i1> [[CMP]] to<8 x i16>
name|bs
operator|=
name|bs
operator|!=
name|us2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ne<8 x i16> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<8 x i1> [[CMP]] to<8 x i16>
name|bs
operator|=
name|bs
operator|!=
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ne<4 x i32> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|si
operator|!=
name|si2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ne<4 x i32> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|si
operator|!=
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ne<4 x i32> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|bi
operator|!=
name|si2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ne<4 x i32> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|ui
operator|!=
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ne<4 x i32> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|ui
operator|!=
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ne<4 x i32> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|bi
operator|!=
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ne<4 x i32> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|bi
operator|!=
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ne<2 x i64> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|sl
operator|!=
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ne<2 x i64> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|sl
operator|!=
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ne<2 x i64> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|bl
operator|!=
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ne<2 x i64> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|ul
operator|!=
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ne<2 x i64> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|ul
operator|!=
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ne<2 x i64> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|bl
operator|!=
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ne<2 x i64> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|bl
operator|!=
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd2
comment|// CHECK: [[CMP:%[^ ]+]] = fcmp une<2 x double> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|fd
operator|!=
name|fd2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_cmpge
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_cmpge
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp sge<16 x i8> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<16 x i1> [[CMP]] to<16 x i8>
name|bc
operator|=
name|sc
operator|>=
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp uge<16 x i8> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<16 x i1> [[CMP]] to<16 x i8>
name|bc
operator|=
name|uc
operator|>=
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp uge<16 x i8> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<16 x i1> [[CMP]] to<16 x i8>
name|bc
operator|=
name|bc
operator|>=
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp sge<8 x i16> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<8 x i1> [[CMP]] to<8 x i16>
name|bs
operator|=
name|ss
operator|>=
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp uge<8 x i16> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<8 x i1> [[CMP]] to<8 x i16>
name|bs
operator|=
name|us
operator|>=
name|us2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp uge<8 x i16> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<8 x i1> [[CMP]] to<8 x i16>
name|bs
operator|=
name|bs
operator|>=
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp sge<4 x i32> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|si
operator|>=
name|si2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp uge<4 x i32> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|ui
operator|>=
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp uge<4 x i32> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|bi
operator|>=
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp sge<2 x i64> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|sl
operator|>=
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp uge<2 x i64> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|ul
operator|>=
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp uge<2 x i64> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|bl
operator|>=
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd2
comment|// CHECK: [[CMP:%[^ ]+]] = fcmp oge<2 x double> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|fd
operator|>=
name|fd2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_cmpgt
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_cmpgt
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp sgt<16 x i8> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<16 x i1> [[CMP]] to<16 x i8>
name|bc
operator|=
name|sc
operator|>
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ugt<16 x i8> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<16 x i1> [[CMP]] to<16 x i8>
name|bc
operator|=
name|uc
operator|>
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ugt<16 x i8> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<16 x i1> [[CMP]] to<16 x i8>
name|bc
operator|=
name|bc
operator|>
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp sgt<8 x i16> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<8 x i1> [[CMP]] to<8 x i16>
name|bs
operator|=
name|ss
operator|>
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ugt<8 x i16> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<8 x i1> [[CMP]] to<8 x i16>
name|bs
operator|=
name|us
operator|>
name|us2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ugt<8 x i16> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<8 x i1> [[CMP]] to<8 x i16>
name|bs
operator|=
name|bs
operator|>
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp sgt<4 x i32> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|si
operator|>
name|si2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ugt<4 x i32> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|ui
operator|>
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ugt<4 x i32> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|bi
operator|>
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp sgt<2 x i64> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|sl
operator|>
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ugt<2 x i64> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|ul
operator|>
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ugt<2 x i64> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|bl
operator|>
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd2
comment|// CHECK: [[CMP:%[^ ]+]] = fcmp ogt<2 x double> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|fd
operator|>
name|fd2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_cmple
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_cmple
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp sle<16 x i8> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<16 x i1> [[CMP]] to<16 x i8>
name|bc
operator|=
name|sc
operator|<=
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ule<16 x i8> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<16 x i1> [[CMP]] to<16 x i8>
name|bc
operator|=
name|uc
operator|<=
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ule<16 x i8> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<16 x i1> [[CMP]] to<16 x i8>
name|bc
operator|=
name|bc
operator|<=
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp sle<8 x i16> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<8 x i1> [[CMP]] to<8 x i16>
name|bs
operator|=
name|ss
operator|<=
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ule<8 x i16> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<8 x i1> [[CMP]] to<8 x i16>
name|bs
operator|=
name|us
operator|<=
name|us2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ule<8 x i16> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<8 x i1> [[CMP]] to<8 x i16>
name|bs
operator|=
name|bs
operator|<=
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp sle<4 x i32> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|si
operator|<=
name|si2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ule<4 x i32> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|ui
operator|<=
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ule<4 x i32> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|bi
operator|<=
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp sle<2 x i64> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|sl
operator|<=
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ule<2 x i64> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|ul
operator|<=
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ule<2 x i64> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|bl
operator|<=
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd2
comment|// CHECK: [[CMP:%[^ ]+]] = fcmp ole<2 x double> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|fd
operator|<=
name|fd2
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_cmplt
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: test_cmplt
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @sc2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp slt<16 x i8> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<16 x i1> [[CMP]] to<16 x i8>
name|bc
operator|=
name|sc
operator|<
name|sc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @uc2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ult<16 x i8> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<16 x i1> [[CMP]] to<16 x i8>
name|bc
operator|=
name|uc
operator|<
name|uc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<16 x i8>,<16 x i8>* @bc2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ult<16 x i8> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<16 x i1> [[CMP]] to<16 x i8>
name|bc
operator|=
name|bc
operator|<
name|bc2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @ss2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp slt<8 x i16> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<8 x i1> [[CMP]] to<8 x i16>
name|bs
operator|=
name|ss
operator|<
name|ss2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @us2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ult<8 x i16> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<8 x i1> [[CMP]] to<8 x i16>
name|bs
operator|=
name|us
operator|<
name|us2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<8 x i16>,<8 x i16>* @bs2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ult<8 x i16> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<8 x i1> [[CMP]] to<8 x i16>
name|bs
operator|=
name|bs
operator|<
name|bs2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @si2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp slt<4 x i32> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|si
operator|<
name|si2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @ui2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ult<4 x i32> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|ui
operator|<
name|ui2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x i32>,<4 x i32>* @bi2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ult<4 x i32> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|bi
operator|<
name|bi2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @sl2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp slt<2 x i64> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|sl
operator|<
name|sl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @ul2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ult<2 x i64> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|ul
operator|<
name|ul2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x i64>,<2 x i64>* @bl2
comment|// CHECK: [[CMP:%[^ ]+]] = icmp ult<2 x i64> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|bl
operator|<
name|bl2
expr_stmt|;
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<2 x double>,<2 x double>* @fd2
comment|// CHECK: [[CMP:%[^ ]+]] = fcmp olt<2 x double> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<2 x i1> [[CMP]] to<2 x i64>
name|bl
operator|=
name|fd
operator|<
name|fd2
expr_stmt|;
block|}
end_function

end_unit

