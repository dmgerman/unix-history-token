begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple s390x-linux-gnu -target-cpu z13 -fzvector -emit-llvm -o - -W -Wall -Werror %s | opt -S -mem2reg | FileCheck %s
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

begin_comment
comment|// CHECK-LABEL: define void @test_assign() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[TMP0]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[TMP1]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[TMP2]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[TMP3]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[TMP4]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[TMP5]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[TMP6]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[TMP7]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<2 x double>,<2 x double>* @fd2, align 8
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x double> [[TMP8]],<2 x double>* @fd, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_assign
parameter_list|(
name|void
parameter_list|)
block|{
name|sc
operator|=
name|sc2
expr_stmt|;
name|uc
operator|=
name|uc2
expr_stmt|;
name|ss
operator|=
name|ss2
expr_stmt|;
name|us
operator|=
name|us2
expr_stmt|;
name|si
operator|=
name|si2
expr_stmt|;
name|ui
operator|=
name|ui2
expr_stmt|;
name|sl
operator|=
name|sl2
expr_stmt|;
name|ul
operator|=
name|ul2
expr_stmt|;
name|fd
operator|=
name|fd2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_pos() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[TMP0]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[TMP1]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[TMP2]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[TMP3]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[TMP4]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[TMP5]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[TMP6]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[TMP7]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<2 x double>,<2 x double>* @fd2, align 8
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x double> [[TMP8]],<2 x double>* @fd, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_pos
parameter_list|(
name|void
parameter_list|)
block|{
name|sc
operator|=
operator|+
name|sc2
expr_stmt|;
name|uc
operator|=
operator|+
name|uc2
expr_stmt|;
name|ss
operator|=
operator|+
name|ss2
expr_stmt|;
name|us
operator|=
operator|+
name|us2
expr_stmt|;
name|si
operator|=
operator|+
name|si2
expr_stmt|;
name|ui
operator|=
operator|+
name|ui2
expr_stmt|;
name|sl
operator|=
operator|+
name|sl2
expr_stmt|;
name|ul
operator|=
operator|+
name|ul2
expr_stmt|;
name|fd
operator|=
operator|+
name|fd2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_neg() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<16 x i8> zeroinitializer, [[TMP0]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SUB]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB1:%.*]] = sub<8 x i16> zeroinitializer, [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SUB1]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB2:%.*]] = sub<4 x i32> zeroinitializer, [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SUB2]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB3:%.*]] = sub<2 x i64> zeroinitializer, [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SUB3]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<2 x double>,<2 x double>* @fd2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB4:%.*]] = fsub<2 x double><double -0.000000e+00, double -0.000000e+00>, [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x double> [[SUB4]],<2 x double>* @fd, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_neg
parameter_list|(
name|void
parameter_list|)
block|{
name|sc
operator|=
operator|-
name|sc2
expr_stmt|;
name|ss
operator|=
operator|-
name|ss2
expr_stmt|;
name|si
operator|=
operator|-
name|si2
expr_stmt|;
name|sl
operator|=
operator|-
name|sl2
expr_stmt|;
name|fd
operator|=
operator|-
name|fd2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_preinc() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[INC:%.*]] = add<16 x i8> [[TMP0]],<i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[INC]],<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[INC1:%.*]] = add<16 x i8> [[TMP1]],<i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[INC1]],<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[INC2:%.*]] = add<8 x i16> [[TMP2]],<i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[INC2]],<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[INC3:%.*]] = add<8 x i16> [[TMP3]],<i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[INC3]],<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[INC4:%.*]] = add<4 x i32> [[TMP4]],<i32 1, i32 1, i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[INC4]],<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[INC5:%.*]] = add<4 x i32> [[TMP5]],<i32 1, i32 1, i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[INC5]],<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[INC6:%.*]] = add<2 x i64> [[TMP6]],<i64 1, i64 1>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[INC6]],<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[INC7:%.*]] = add<2 x i64> [[TMP7]],<i64 1, i64 1>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[INC7]],<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<2 x double>,<2 x double>* @fd2, align 8
end_comment

begin_comment
comment|// CHECK:   [[INC8:%.*]] = fadd<2 x double> [[TMP8]],<double 1.000000e+00, double 1.000000e+00>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x double> [[INC8]],<2 x double>* @fd2, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_preinc
parameter_list|(
name|void
parameter_list|)
block|{
operator|++
name|sc2
expr_stmt|;
operator|++
name|uc2
expr_stmt|;
operator|++
name|ss2
expr_stmt|;
operator|++
name|us2
expr_stmt|;
operator|++
name|si2
expr_stmt|;
operator|++
name|ui2
expr_stmt|;
operator|++
name|sl2
expr_stmt|;
operator|++
name|ul2
expr_stmt|;
operator|++
name|fd2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_postinc() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[INC:%.*]] = add<16 x i8> [[TMP0]],<i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[INC]],<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[INC1:%.*]] = add<16 x i8> [[TMP1]],<i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[INC1]],<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[INC2:%.*]] = add<8 x i16> [[TMP2]],<i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[INC2]],<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[INC3:%.*]] = add<8 x i16> [[TMP3]],<i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[INC3]],<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[INC4:%.*]] = add<4 x i32> [[TMP4]],<i32 1, i32 1, i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[INC4]],<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[INC5:%.*]] = add<4 x i32> [[TMP5]],<i32 1, i32 1, i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[INC5]],<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[INC6:%.*]] = add<2 x i64> [[TMP6]],<i64 1, i64 1>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[INC6]],<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[INC7:%.*]] = add<2 x i64> [[TMP7]],<i64 1, i64 1>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[INC7]],<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<2 x double>,<2 x double>* @fd2, align 8
end_comment

begin_comment
comment|// CHECK:   [[INC8:%.*]] = fadd<2 x double> [[TMP8]],<double 1.000000e+00, double 1.000000e+00>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x double> [[INC8]],<2 x double>* @fd2, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_postinc
parameter_list|(
name|void
parameter_list|)
block|{
name|sc2
operator|++
expr_stmt|;
name|uc2
operator|++
expr_stmt|;
name|ss2
operator|++
expr_stmt|;
name|us2
operator|++
expr_stmt|;
name|si2
operator|++
expr_stmt|;
name|ui2
operator|++
expr_stmt|;
name|sl2
operator|++
expr_stmt|;
name|ul2
operator|++
expr_stmt|;
name|fd2
operator|++
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_predec() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[DEC:%.*]] = add<16 x i8> [[TMP0]],<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[DEC]],<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[DEC1:%.*]] = add<16 x i8> [[TMP1]],<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[DEC1]],<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[DEC2:%.*]] = add<8 x i16> [[TMP2]],<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[DEC2]],<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[DEC3:%.*]] = add<8 x i16> [[TMP3]],<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[DEC3]],<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[DEC4:%.*]] = add<4 x i32> [[TMP4]],<i32 -1, i32 -1, i32 -1, i32 -1>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[DEC4]],<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[DEC5:%.*]] = add<4 x i32> [[TMP5]],<i32 -1, i32 -1, i32 -1, i32 -1>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[DEC5]],<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[DEC6:%.*]] = add<2 x i64> [[TMP6]],<i64 -1, i64 -1>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[DEC6]],<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[DEC7:%.*]] = add<2 x i64> [[TMP7]],<i64 -1, i64 -1>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[DEC7]],<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<2 x double>,<2 x double>* @fd2, align 8
end_comment

begin_comment
comment|// CHECK:   [[DEC8:%.*]] = fadd<2 x double> [[TMP8]],<double -1.000000e+00, double -1.000000e+00>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x double> [[DEC8]],<2 x double>* @fd2, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_predec
parameter_list|(
name|void
parameter_list|)
block|{
operator|--
name|sc2
expr_stmt|;
operator|--
name|uc2
expr_stmt|;
operator|--
name|ss2
expr_stmt|;
operator|--
name|us2
expr_stmt|;
operator|--
name|si2
expr_stmt|;
operator|--
name|ui2
expr_stmt|;
operator|--
name|sl2
expr_stmt|;
operator|--
name|ul2
expr_stmt|;
operator|--
name|fd2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_postdec() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[DEC:%.*]] = add<16 x i8> [[TMP0]],<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[DEC]],<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[DEC1:%.*]] = add<16 x i8> [[TMP1]],<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[DEC1]],<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[DEC2:%.*]] = add<8 x i16> [[TMP2]],<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[DEC2]],<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[DEC3:%.*]] = add<8 x i16> [[TMP3]],<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[DEC3]],<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[DEC4:%.*]] = add<4 x i32> [[TMP4]],<i32 -1, i32 -1, i32 -1, i32 -1>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[DEC4]],<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[DEC5:%.*]] = add<4 x i32> [[TMP5]],<i32 -1, i32 -1, i32 -1, i32 -1>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[DEC5]],<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[DEC6:%.*]] = add<2 x i64> [[TMP6]],<i64 -1, i64 -1>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[DEC6]],<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[DEC7:%.*]] = add<2 x i64> [[TMP7]],<i64 -1, i64 -1>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[DEC7]],<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<2 x double>,<2 x double>* @fd2, align 8
end_comment

begin_comment
comment|// CHECK:   [[DEC8:%.*]] = fadd<2 x double> [[TMP8]],<double -1.000000e+00, double -1.000000e+00>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x double> [[DEC8]],<2 x double>* @fd2, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_postdec
parameter_list|(
name|void
parameter_list|)
block|{
name|sc2
operator|--
expr_stmt|;
name|uc2
operator|--
expr_stmt|;
name|ss2
operator|--
expr_stmt|;
name|us2
operator|--
expr_stmt|;
name|si2
operator|--
expr_stmt|;
name|ui2
operator|--
expr_stmt|;
name|sl2
operator|--
expr_stmt|;
name|ul2
operator|--
expr_stmt|;
name|fd2
operator|--
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_add() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<16 x i8> [[TMP0]], [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[ADD]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD1:%.*]] = add<16 x i8> [[TMP2]], [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[ADD1]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD2:%.*]] = add<16 x i8> [[TMP4]], [[TMP5]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[ADD2]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD3:%.*]] = add<16 x i8> [[TMP6]], [[TMP7]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[ADD3]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD4:%.*]] = add<16 x i8> [[TMP8]], [[TMP9]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[ADD4]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD5:%.*]] = add<16 x i8> [[TMP10]], [[TMP11]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[ADD5]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP12:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP13:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD6:%.*]] = add<8 x i16> [[TMP12]], [[TMP13]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[ADD6]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP14:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP15:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD7:%.*]] = add<8 x i16> [[TMP14]], [[TMP15]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[ADD7]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP16:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP17:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD8:%.*]] = add<8 x i16> [[TMP16]], [[TMP17]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[ADD8]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP18:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP19:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD9:%.*]] = add<8 x i16> [[TMP18]], [[TMP19]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[ADD9]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP20:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP21:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD10:%.*]] = add<8 x i16> [[TMP20]], [[TMP21]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[ADD10]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP22:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP23:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD11:%.*]] = add<8 x i16> [[TMP22]], [[TMP23]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[ADD11]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP24:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP25:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD12:%.*]] = add<4 x i32> [[TMP24]], [[TMP25]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[ADD12]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP26:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP27:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD13:%.*]] = add<4 x i32> [[TMP26]], [[TMP27]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[ADD13]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP28:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP29:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD14:%.*]] = add<4 x i32> [[TMP28]], [[TMP29]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[ADD14]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP30:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP31:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD15:%.*]] = add<4 x i32> [[TMP30]], [[TMP31]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[ADD15]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP32:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP33:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD16:%.*]] = add<4 x i32> [[TMP32]], [[TMP33]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[ADD16]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP34:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP35:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD17:%.*]] = add<4 x i32> [[TMP34]], [[TMP35]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[ADD17]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP36:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP37:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD18:%.*]] = add<2 x i64> [[TMP36]], [[TMP37]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[ADD18]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP38:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP39:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD19:%.*]] = add<2 x i64> [[TMP38]], [[TMP39]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[ADD19]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP40:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP41:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD20:%.*]] = add<2 x i64> [[TMP40]], [[TMP41]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[ADD20]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP42:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP43:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD21:%.*]] = add<2 x i64> [[TMP42]], [[TMP43]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[ADD21]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP44:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP45:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD22:%.*]] = add<2 x i64> [[TMP44]], [[TMP45]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[ADD22]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP46:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP47:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD23:%.*]] = add<2 x i64> [[TMP46]], [[TMP47]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[ADD23]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP48:%.*]] = load volatile<2 x double>,<2 x double>* @fd, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP49:%.*]] = load volatile<2 x double>,<2 x double>* @fd2, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD24:%.*]] = fadd<2 x double> [[TMP48]], [[TMP49]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x double> [[ADD24]],<2 x double>* @fd, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_add
parameter_list|(
name|void
parameter_list|)
block|{
name|sc
operator|=
name|sc
operator|+
name|sc2
expr_stmt|;
name|sc
operator|=
name|sc
operator|+
name|bc2
expr_stmt|;
name|sc
operator|=
name|bc
operator|+
name|sc2
expr_stmt|;
name|uc
operator|=
name|uc
operator|+
name|uc2
expr_stmt|;
name|uc
operator|=
name|uc
operator|+
name|bc2
expr_stmt|;
name|uc
operator|=
name|bc
operator|+
name|uc2
expr_stmt|;
name|ss
operator|=
name|ss
operator|+
name|ss2
expr_stmt|;
name|ss
operator|=
name|ss
operator|+
name|bs2
expr_stmt|;
name|ss
operator|=
name|bs
operator|+
name|ss2
expr_stmt|;
name|us
operator|=
name|us
operator|+
name|us2
expr_stmt|;
name|us
operator|=
name|us
operator|+
name|bs2
expr_stmt|;
name|us
operator|=
name|bs
operator|+
name|us2
expr_stmt|;
name|si
operator|=
name|si
operator|+
name|si2
expr_stmt|;
name|si
operator|=
name|si
operator|+
name|bi2
expr_stmt|;
name|si
operator|=
name|bi
operator|+
name|si2
expr_stmt|;
name|ui
operator|=
name|ui
operator|+
name|ui2
expr_stmt|;
name|ui
operator|=
name|ui
operator|+
name|bi2
expr_stmt|;
name|ui
operator|=
name|bi
operator|+
name|ui2
expr_stmt|;
name|sl
operator|=
name|sl
operator|+
name|sl2
expr_stmt|;
name|sl
operator|=
name|sl
operator|+
name|bl2
expr_stmt|;
name|sl
operator|=
name|bl
operator|+
name|sl2
expr_stmt|;
name|ul
operator|=
name|ul
operator|+
name|ul2
expr_stmt|;
name|ul
operator|=
name|ul
operator|+
name|bl2
expr_stmt|;
name|ul
operator|=
name|bl
operator|+
name|ul2
expr_stmt|;
name|fd
operator|=
name|fd
operator|+
name|fd2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_add_assign() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<16 x i8> [[TMP1]], [[TMP0]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[ADD]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD1:%.*]] = add<16 x i8> [[TMP3]], [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[ADD1]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD2:%.*]] = add<16 x i8> [[TMP5]], [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[ADD2]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD3:%.*]] = add<16 x i8> [[TMP7]], [[TMP6]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[ADD3]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD4:%.*]] = add<8 x i16> [[TMP9]], [[TMP8]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[ADD4]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD5:%.*]] = add<8 x i16> [[TMP11]], [[TMP10]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[ADD5]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP12:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP13:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD6:%.*]] = add<8 x i16> [[TMP13]], [[TMP12]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[ADD6]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP14:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP15:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD7:%.*]] = add<8 x i16> [[TMP15]], [[TMP14]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[ADD7]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP16:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP17:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD8:%.*]] = add<4 x i32> [[TMP17]], [[TMP16]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[ADD8]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP18:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP19:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD9:%.*]] = add<4 x i32> [[TMP19]], [[TMP18]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[ADD9]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP20:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP21:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD10:%.*]] = add<4 x i32> [[TMP21]], [[TMP20]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[ADD10]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP22:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP23:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD11:%.*]] = add<4 x i32> [[TMP23]], [[TMP22]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[ADD11]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP24:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP25:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD12:%.*]] = add<2 x i64> [[TMP25]], [[TMP24]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[ADD12]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP26:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP27:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD13:%.*]] = add<2 x i64> [[TMP27]], [[TMP26]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[ADD13]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP28:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP29:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD14:%.*]] = add<2 x i64> [[TMP29]], [[TMP28]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[ADD14]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP30:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP31:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD15:%.*]] = add<2 x i64> [[TMP31]], [[TMP30]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[ADD15]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP32:%.*]] = load volatile<2 x double>,<2 x double>* @fd2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP33:%.*]] = load volatile<2 x double>,<2 x double>* @fd, align 8
end_comment

begin_comment
comment|// CHECK:   [[ADD16:%.*]] = fadd<2 x double> [[TMP33]], [[TMP32]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x double> [[ADD16]],<2 x double>* @fd, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_add_assign
parameter_list|(
name|void
parameter_list|)
block|{
name|sc
operator|+=
name|sc2
expr_stmt|;
name|sc
operator|+=
name|bc2
expr_stmt|;
name|uc
operator|+=
name|uc2
expr_stmt|;
name|uc
operator|+=
name|bc2
expr_stmt|;
name|ss
operator|+=
name|ss2
expr_stmt|;
name|ss
operator|+=
name|bs2
expr_stmt|;
name|us
operator|+=
name|us2
expr_stmt|;
name|us
operator|+=
name|bs2
expr_stmt|;
name|si
operator|+=
name|si2
expr_stmt|;
name|si
operator|+=
name|bi2
expr_stmt|;
name|ui
operator|+=
name|ui2
expr_stmt|;
name|ui
operator|+=
name|bi2
expr_stmt|;
name|sl
operator|+=
name|sl2
expr_stmt|;
name|sl
operator|+=
name|bl2
expr_stmt|;
name|ul
operator|+=
name|ul2
expr_stmt|;
name|ul
operator|+=
name|bl2
expr_stmt|;
name|fd
operator|+=
name|fd2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_sub() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<16 x i8> [[TMP0]], [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SUB]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB1:%.*]] = sub<16 x i8> [[TMP2]], [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SUB1]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB2:%.*]] = sub<16 x i8> [[TMP4]], [[TMP5]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SUB2]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB3:%.*]] = sub<16 x i8> [[TMP6]], [[TMP7]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SUB3]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB4:%.*]] = sub<16 x i8> [[TMP8]], [[TMP9]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SUB4]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB5:%.*]] = sub<16 x i8> [[TMP10]], [[TMP11]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SUB5]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP12:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP13:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB6:%.*]] = sub<8 x i16> [[TMP12]], [[TMP13]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SUB6]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP14:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP15:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB7:%.*]] = sub<8 x i16> [[TMP14]], [[TMP15]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SUB7]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP16:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP17:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB8:%.*]] = sub<8 x i16> [[TMP16]], [[TMP17]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SUB8]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP18:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP19:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB9:%.*]] = sub<8 x i16> [[TMP18]], [[TMP19]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SUB9]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP20:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP21:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB10:%.*]] = sub<8 x i16> [[TMP20]], [[TMP21]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SUB10]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP22:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP23:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB11:%.*]] = sub<8 x i16> [[TMP22]], [[TMP23]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SUB11]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP24:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP25:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB12:%.*]] = sub<4 x i32> [[TMP24]], [[TMP25]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SUB12]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP26:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP27:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB13:%.*]] = sub<4 x i32> [[TMP26]], [[TMP27]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SUB13]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP28:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP29:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB14:%.*]] = sub<4 x i32> [[TMP28]], [[TMP29]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SUB14]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP30:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP31:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB15:%.*]] = sub<4 x i32> [[TMP30]], [[TMP31]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SUB15]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP32:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP33:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB16:%.*]] = sub<4 x i32> [[TMP32]], [[TMP33]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SUB16]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP34:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP35:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB17:%.*]] = sub<4 x i32> [[TMP34]], [[TMP35]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SUB17]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP36:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP37:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB18:%.*]] = sub<2 x i64> [[TMP36]], [[TMP37]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SUB18]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP38:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP39:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB19:%.*]] = sub<2 x i64> [[TMP38]], [[TMP39]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SUB19]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP40:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP41:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB20:%.*]] = sub<2 x i64> [[TMP40]], [[TMP41]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SUB20]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP42:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP43:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB21:%.*]] = sub<2 x i64> [[TMP42]], [[TMP43]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SUB21]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP44:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP45:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB22:%.*]] = sub<2 x i64> [[TMP44]], [[TMP45]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SUB22]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP46:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP47:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB23:%.*]] = sub<2 x i64> [[TMP46]], [[TMP47]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SUB23]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP48:%.*]] = load volatile<2 x double>,<2 x double>* @fd, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP49:%.*]] = load volatile<2 x double>,<2 x double>* @fd2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB24:%.*]] = fsub<2 x double> [[TMP48]], [[TMP49]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x double> [[SUB24]],<2 x double>* @fd, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_sub
parameter_list|(
name|void
parameter_list|)
block|{
name|sc
operator|=
name|sc
operator|-
name|sc2
expr_stmt|;
name|sc
operator|=
name|sc
operator|-
name|bc2
expr_stmt|;
name|sc
operator|=
name|bc
operator|-
name|sc2
expr_stmt|;
name|uc
operator|=
name|uc
operator|-
name|uc2
expr_stmt|;
name|uc
operator|=
name|uc
operator|-
name|bc2
expr_stmt|;
name|uc
operator|=
name|bc
operator|-
name|uc2
expr_stmt|;
name|ss
operator|=
name|ss
operator|-
name|ss2
expr_stmt|;
name|ss
operator|=
name|ss
operator|-
name|bs2
expr_stmt|;
name|ss
operator|=
name|bs
operator|-
name|ss2
expr_stmt|;
name|us
operator|=
name|us
operator|-
name|us2
expr_stmt|;
name|us
operator|=
name|us
operator|-
name|bs2
expr_stmt|;
name|us
operator|=
name|bs
operator|-
name|us2
expr_stmt|;
name|si
operator|=
name|si
operator|-
name|si2
expr_stmt|;
name|si
operator|=
name|si
operator|-
name|bi2
expr_stmt|;
name|si
operator|=
name|bi
operator|-
name|si2
expr_stmt|;
name|ui
operator|=
name|ui
operator|-
name|ui2
expr_stmt|;
name|ui
operator|=
name|ui
operator|-
name|bi2
expr_stmt|;
name|ui
operator|=
name|bi
operator|-
name|ui2
expr_stmt|;
name|sl
operator|=
name|sl
operator|-
name|sl2
expr_stmt|;
name|sl
operator|=
name|sl
operator|-
name|bl2
expr_stmt|;
name|sl
operator|=
name|bl
operator|-
name|sl2
expr_stmt|;
name|ul
operator|=
name|ul
operator|-
name|ul2
expr_stmt|;
name|ul
operator|=
name|ul
operator|-
name|bl2
expr_stmt|;
name|ul
operator|=
name|bl
operator|-
name|ul2
expr_stmt|;
name|fd
operator|=
name|fd
operator|-
name|fd2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_sub_assign() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<16 x i8> [[TMP1]], [[TMP0]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SUB]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB1:%.*]] = sub<16 x i8> [[TMP3]], [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SUB1]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB2:%.*]] = sub<16 x i8> [[TMP5]], [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SUB2]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB3:%.*]] = sub<16 x i8> [[TMP7]], [[TMP6]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SUB3]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB4:%.*]] = sub<8 x i16> [[TMP9]], [[TMP8]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SUB4]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB5:%.*]] = sub<8 x i16> [[TMP11]], [[TMP10]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SUB5]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP12:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP13:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB6:%.*]] = sub<8 x i16> [[TMP13]], [[TMP12]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SUB6]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP14:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP15:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB7:%.*]] = sub<8 x i16> [[TMP15]], [[TMP14]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SUB7]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP16:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP17:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB8:%.*]] = sub<4 x i32> [[TMP17]], [[TMP16]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SUB8]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP18:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP19:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB9:%.*]] = sub<4 x i32> [[TMP19]], [[TMP18]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SUB9]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP20:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP21:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB10:%.*]] = sub<4 x i32> [[TMP21]], [[TMP20]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SUB10]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP22:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP23:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB11:%.*]] = sub<4 x i32> [[TMP23]], [[TMP22]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SUB11]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP24:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP25:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB12:%.*]] = sub<2 x i64> [[TMP25]], [[TMP24]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SUB12]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP26:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP27:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB13:%.*]] = sub<2 x i64> [[TMP27]], [[TMP26]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SUB13]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP28:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP29:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB14:%.*]] = sub<2 x i64> [[TMP29]], [[TMP28]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SUB14]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP30:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP31:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB15:%.*]] = sub<2 x i64> [[TMP31]], [[TMP30]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SUB15]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP32:%.*]] = load volatile<2 x double>,<2 x double>* @fd2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP33:%.*]] = load volatile<2 x double>,<2 x double>* @fd, align 8
end_comment

begin_comment
comment|// CHECK:   [[SUB16:%.*]] = fsub<2 x double> [[TMP33]], [[TMP32]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x double> [[SUB16]],<2 x double>* @fd, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_sub_assign
parameter_list|(
name|void
parameter_list|)
block|{
name|sc
operator|-=
name|sc2
expr_stmt|;
name|sc
operator|-=
name|bc2
expr_stmt|;
name|uc
operator|-=
name|uc2
expr_stmt|;
name|uc
operator|-=
name|bc2
expr_stmt|;
name|ss
operator|-=
name|ss2
expr_stmt|;
name|ss
operator|-=
name|bs2
expr_stmt|;
name|us
operator|-=
name|us2
expr_stmt|;
name|us
operator|-=
name|bs2
expr_stmt|;
name|si
operator|-=
name|si2
expr_stmt|;
name|si
operator|-=
name|bi2
expr_stmt|;
name|ui
operator|-=
name|ui2
expr_stmt|;
name|ui
operator|-=
name|bi2
expr_stmt|;
name|sl
operator|-=
name|sl2
expr_stmt|;
name|sl
operator|-=
name|bl2
expr_stmt|;
name|ul
operator|-=
name|ul2
expr_stmt|;
name|ul
operator|-=
name|bl2
expr_stmt|;
name|fd
operator|-=
name|fd2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_mul() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<16 x i8> [[TMP0]], [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[MUL]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[MUL1:%.*]] = mul<16 x i8> [[TMP2]], [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[MUL1]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[MUL2:%.*]] = mul<8 x i16> [[TMP4]], [[TMP5]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[MUL2]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[MUL3:%.*]] = mul<8 x i16> [[TMP6]], [[TMP7]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[MUL3]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[MUL4:%.*]] = mul<4 x i32> [[TMP8]], [[TMP9]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[MUL4]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[MUL5:%.*]] = mul<4 x i32> [[TMP10]], [[TMP11]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[MUL5]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP12:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP13:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[MUL6:%.*]] = mul<2 x i64> [[TMP12]], [[TMP13]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[MUL6]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP14:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP15:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[MUL7:%.*]] = mul<2 x i64> [[TMP14]], [[TMP15]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[MUL7]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP16:%.*]] = load volatile<2 x double>,<2 x double>* @fd, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP17:%.*]] = load volatile<2 x double>,<2 x double>* @fd2, align 8
end_comment

begin_comment
comment|// CHECK:   [[MUL8:%.*]] = fmul<2 x double> [[TMP16]], [[TMP17]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x double> [[MUL8]],<2 x double>* @fd, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_mul
parameter_list|(
name|void
parameter_list|)
block|{
name|sc
operator|=
name|sc
operator|*
name|sc2
expr_stmt|;
name|uc
operator|=
name|uc
operator|*
name|uc2
expr_stmt|;
name|ss
operator|=
name|ss
operator|*
name|ss2
expr_stmt|;
name|us
operator|=
name|us
operator|*
name|us2
expr_stmt|;
name|si
operator|=
name|si
operator|*
name|si2
expr_stmt|;
name|ui
operator|=
name|ui
operator|*
name|ui2
expr_stmt|;
name|sl
operator|=
name|sl
operator|*
name|sl2
expr_stmt|;
name|ul
operator|=
name|ul
operator|*
name|ul2
expr_stmt|;
name|fd
operator|=
name|fd
operator|*
name|fd2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_mul_assign() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<16 x i8> [[TMP1]], [[TMP0]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[MUL]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[MUL1:%.*]] = mul<16 x i8> [[TMP3]], [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[MUL1]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[MUL2:%.*]] = mul<8 x i16> [[TMP5]], [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[MUL2]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[MUL3:%.*]] = mul<8 x i16> [[TMP7]], [[TMP6]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[MUL3]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[MUL4:%.*]] = mul<4 x i32> [[TMP9]], [[TMP8]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[MUL4]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[MUL5:%.*]] = mul<4 x i32> [[TMP11]], [[TMP10]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[MUL5]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP12:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP13:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[MUL6:%.*]] = mul<2 x i64> [[TMP13]], [[TMP12]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[MUL6]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP14:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP15:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[MUL7:%.*]] = mul<2 x i64> [[TMP15]], [[TMP14]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[MUL7]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP16:%.*]] = load volatile<2 x double>,<2 x double>* @fd2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP17:%.*]] = load volatile<2 x double>,<2 x double>* @fd, align 8
end_comment

begin_comment
comment|// CHECK:   [[MUL8:%.*]] = fmul<2 x double> [[TMP17]], [[TMP16]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x double> [[MUL8]],<2 x double>* @fd, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_mul_assign
parameter_list|(
name|void
parameter_list|)
block|{
name|sc
operator|*=
name|sc2
expr_stmt|;
name|uc
operator|*=
name|uc2
expr_stmt|;
name|ss
operator|*=
name|ss2
expr_stmt|;
name|us
operator|*=
name|us2
expr_stmt|;
name|si
operator|*=
name|si2
expr_stmt|;
name|ui
operator|*=
name|ui2
expr_stmt|;
name|sl
operator|*=
name|sl2
expr_stmt|;
name|ul
operator|*=
name|ul2
expr_stmt|;
name|fd
operator|*=
name|fd2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_div() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[DIV:%.*]] = sdiv<16 x i8> [[TMP0]], [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[DIV]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[DIV1:%.*]] = udiv<16 x i8> [[TMP2]], [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[DIV1]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[DIV2:%.*]] = sdiv<8 x i16> [[TMP4]], [[TMP5]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[DIV2]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[DIV3:%.*]] = udiv<8 x i16> [[TMP6]], [[TMP7]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[DIV3]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[DIV4:%.*]] = sdiv<4 x i32> [[TMP8]], [[TMP9]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[DIV4]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[DIV5:%.*]] = udiv<4 x i32> [[TMP10]], [[TMP11]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[DIV5]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP12:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP13:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[DIV6:%.*]] = sdiv<2 x i64> [[TMP12]], [[TMP13]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[DIV6]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP14:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP15:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[DIV7:%.*]] = udiv<2 x i64> [[TMP14]], [[TMP15]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[DIV7]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP16:%.*]] = load volatile<2 x double>,<2 x double>* @fd, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP17:%.*]] = load volatile<2 x double>,<2 x double>* @fd2, align 8
end_comment

begin_comment
comment|// CHECK:   [[DIV8:%.*]] = fdiv<2 x double> [[TMP16]], [[TMP17]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x double> [[DIV8]],<2 x double>* @fd, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_div
parameter_list|(
name|void
parameter_list|)
block|{
name|sc
operator|=
name|sc
operator|/
name|sc2
expr_stmt|;
name|uc
operator|=
name|uc
operator|/
name|uc2
expr_stmt|;
name|ss
operator|=
name|ss
operator|/
name|ss2
expr_stmt|;
name|us
operator|=
name|us
operator|/
name|us2
expr_stmt|;
name|si
operator|=
name|si
operator|/
name|si2
expr_stmt|;
name|ui
operator|=
name|ui
operator|/
name|ui2
expr_stmt|;
name|sl
operator|=
name|sl
operator|/
name|sl2
expr_stmt|;
name|ul
operator|=
name|ul
operator|/
name|ul2
expr_stmt|;
name|fd
operator|=
name|fd
operator|/
name|fd2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_div_assign() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[DIV:%.*]] = sdiv<16 x i8> [[TMP1]], [[TMP0]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[DIV]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[DIV1:%.*]] = udiv<16 x i8> [[TMP3]], [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[DIV1]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[DIV2:%.*]] = sdiv<8 x i16> [[TMP5]], [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[DIV2]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[DIV3:%.*]] = udiv<8 x i16> [[TMP7]], [[TMP6]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[DIV3]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[DIV4:%.*]] = sdiv<4 x i32> [[TMP9]], [[TMP8]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[DIV4]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[DIV5:%.*]] = udiv<4 x i32> [[TMP11]], [[TMP10]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[DIV5]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP12:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP13:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[DIV6:%.*]] = sdiv<2 x i64> [[TMP13]], [[TMP12]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[DIV6]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP14:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP15:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[DIV7:%.*]] = udiv<2 x i64> [[TMP15]], [[TMP14]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[DIV7]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP16:%.*]] = load volatile<2 x double>,<2 x double>* @fd2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP17:%.*]] = load volatile<2 x double>,<2 x double>* @fd, align 8
end_comment

begin_comment
comment|// CHECK:   [[DIV8:%.*]] = fdiv<2 x double> [[TMP17]], [[TMP16]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x double> [[DIV8]],<2 x double>* @fd, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_div_assign
parameter_list|(
name|void
parameter_list|)
block|{
name|sc
operator|/=
name|sc2
expr_stmt|;
name|uc
operator|/=
name|uc2
expr_stmt|;
name|ss
operator|/=
name|ss2
expr_stmt|;
name|us
operator|/=
name|us2
expr_stmt|;
name|si
operator|/=
name|si2
expr_stmt|;
name|ui
operator|/=
name|ui2
expr_stmt|;
name|sl
operator|/=
name|sl2
expr_stmt|;
name|ul
operator|/=
name|ul2
expr_stmt|;
name|fd
operator|/=
name|fd2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_rem() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[REM:%.*]] = srem<16 x i8> [[TMP0]], [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[REM]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[REM1:%.*]] = urem<16 x i8> [[TMP2]], [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[REM1]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[REM2:%.*]] = srem<8 x i16> [[TMP4]], [[TMP5]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[REM2]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[REM3:%.*]] = urem<8 x i16> [[TMP6]], [[TMP7]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[REM3]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[REM4:%.*]] = srem<4 x i32> [[TMP8]], [[TMP9]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[REM4]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[REM5:%.*]] = urem<4 x i32> [[TMP10]], [[TMP11]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[REM5]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP12:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP13:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[REM6:%.*]] = srem<2 x i64> [[TMP12]], [[TMP13]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[REM6]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP14:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP15:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[REM7:%.*]] = urem<2 x i64> [[TMP14]], [[TMP15]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[REM7]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_rem
parameter_list|(
name|void
parameter_list|)
block|{
name|sc
operator|=
name|sc
operator|%
name|sc2
expr_stmt|;
name|uc
operator|=
name|uc
operator|%
name|uc2
expr_stmt|;
name|ss
operator|=
name|ss
operator|%
name|ss2
expr_stmt|;
name|us
operator|=
name|us
operator|%
name|us2
expr_stmt|;
name|si
operator|=
name|si
operator|%
name|si2
expr_stmt|;
name|ui
operator|=
name|ui
operator|%
name|ui2
expr_stmt|;
name|sl
operator|=
name|sl
operator|%
name|sl2
expr_stmt|;
name|ul
operator|=
name|ul
operator|%
name|ul2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_rem_assign() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[REM:%.*]] = srem<16 x i8> [[TMP1]], [[TMP0]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[REM]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[REM1:%.*]] = urem<16 x i8> [[TMP3]], [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[REM1]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[REM2:%.*]] = srem<8 x i16> [[TMP5]], [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[REM2]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[REM3:%.*]] = urem<8 x i16> [[TMP7]], [[TMP6]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[REM3]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[REM4:%.*]] = srem<4 x i32> [[TMP9]], [[TMP8]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[REM4]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[REM5:%.*]] = urem<4 x i32> [[TMP11]], [[TMP10]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[REM5]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP12:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP13:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[REM6:%.*]] = srem<2 x i64> [[TMP13]], [[TMP12]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[REM6]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP14:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP15:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[REM7:%.*]] = urem<2 x i64> [[TMP15]], [[TMP14]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[REM7]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_rem_assign
parameter_list|(
name|void
parameter_list|)
block|{
name|sc
operator|%=
name|sc2
expr_stmt|;
name|uc
operator|%=
name|uc2
expr_stmt|;
name|ss
operator|%=
name|ss2
expr_stmt|;
name|us
operator|%=
name|us2
expr_stmt|;
name|si
operator|%=
name|si2
expr_stmt|;
name|ui
operator|%=
name|ui2
expr_stmt|;
name|sl
operator|%=
name|sl2
expr_stmt|;
name|ul
operator|%=
name|ul2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_not() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[NEG:%.*]] = xor<16 x i8> [[TMP0]],<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[NEG]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[NEG1:%.*]] = xor<16 x i8> [[TMP1]],<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[NEG1]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[NEG2:%.*]] = xor<16 x i8> [[TMP2]],<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[NEG2]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[NEG3:%.*]] = xor<8 x i16> [[TMP3]],<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[NEG3]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[NEG4:%.*]] = xor<8 x i16> [[TMP4]],<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[NEG4]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[NEG5:%.*]] = xor<8 x i16> [[TMP5]],<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[NEG5]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[NEG6:%.*]] = xor<4 x i32> [[TMP6]],<i32 -1, i32 -1, i32 -1, i32 -1>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[NEG6]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[NEG7:%.*]] = xor<4 x i32> [[TMP7]],<i32 -1, i32 -1, i32 -1, i32 -1>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[NEG7]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[NEG8:%.*]] = xor<4 x i32> [[TMP8]],<i32 -1, i32 -1, i32 -1, i32 -1>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[NEG8]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[NEG9:%.*]] = xor<2 x i64> [[TMP9]],<i64 -1, i64 -1>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[NEG9]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[NEG10:%.*]] = xor<2 x i64> [[TMP10]],<i64 -1, i64 -1>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[NEG10]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[NEG11:%.*]] = xor<2 x i64> [[TMP11]],<i64 -1, i64 -1>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[NEG11]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_not
parameter_list|(
name|void
parameter_list|)
block|{
name|sc
operator|=
operator|~
name|sc2
expr_stmt|;
name|uc
operator|=
operator|~
name|uc2
expr_stmt|;
name|bc
operator|=
operator|~
name|bc2
expr_stmt|;
name|ss
operator|=
operator|~
name|ss2
expr_stmt|;
name|us
operator|=
operator|~
name|us2
expr_stmt|;
name|bs
operator|=
operator|~
name|bs2
expr_stmt|;
name|si
operator|=
operator|~
name|si2
expr_stmt|;
name|ui
operator|=
operator|~
name|ui2
expr_stmt|;
name|bi
operator|=
operator|~
name|bi2
expr_stmt|;
name|sl
operator|=
operator|~
name|sl2
expr_stmt|;
name|ul
operator|=
operator|~
name|ul2
expr_stmt|;
name|bl
operator|=
operator|~
name|bl2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_and() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND:%.*]] = and<16 x i8> [[TMP0]], [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[AND]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND1:%.*]] = and<16 x i8> [[TMP2]], [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[AND1]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND2:%.*]] = and<16 x i8> [[TMP4]], [[TMP5]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[AND2]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND3:%.*]] = and<16 x i8> [[TMP6]], [[TMP7]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[AND3]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND4:%.*]] = and<16 x i8> [[TMP8]], [[TMP9]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[AND4]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND5:%.*]] = and<16 x i8> [[TMP10]], [[TMP11]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[AND5]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP12:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP13:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND6:%.*]] = and<16 x i8> [[TMP12]], [[TMP13]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[AND6]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP14:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP15:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND7:%.*]] = and<8 x i16> [[TMP14]], [[TMP15]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[AND7]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP16:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP17:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND8:%.*]] = and<8 x i16> [[TMP16]], [[TMP17]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[AND8]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP18:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP19:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND9:%.*]] = and<8 x i16> [[TMP18]], [[TMP19]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[AND9]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP20:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP21:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND10:%.*]] = and<8 x i16> [[TMP20]], [[TMP21]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[AND10]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP22:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP23:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND11:%.*]] = and<8 x i16> [[TMP22]], [[TMP23]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[AND11]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP24:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP25:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND12:%.*]] = and<8 x i16> [[TMP24]], [[TMP25]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[AND12]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP26:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP27:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND13:%.*]] = and<8 x i16> [[TMP26]], [[TMP27]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[AND13]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP28:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP29:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND14:%.*]] = and<4 x i32> [[TMP28]], [[TMP29]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[AND14]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP30:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP31:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND15:%.*]] = and<4 x i32> [[TMP30]], [[TMP31]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[AND15]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP32:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP33:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND16:%.*]] = and<4 x i32> [[TMP32]], [[TMP33]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[AND16]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP34:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP35:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND17:%.*]] = and<4 x i32> [[TMP34]], [[TMP35]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[AND17]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP36:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP37:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND18:%.*]] = and<4 x i32> [[TMP36]], [[TMP37]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[AND18]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP38:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP39:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND19:%.*]] = and<4 x i32> [[TMP38]], [[TMP39]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[AND19]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP40:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP41:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND20:%.*]] = and<4 x i32> [[TMP40]], [[TMP41]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[AND20]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP42:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP43:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND21:%.*]] = and<2 x i64> [[TMP42]], [[TMP43]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[AND21]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP44:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP45:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND22:%.*]] = and<2 x i64> [[TMP44]], [[TMP45]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[AND22]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP46:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP47:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND23:%.*]] = and<2 x i64> [[TMP46]], [[TMP47]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[AND23]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP48:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP49:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND24:%.*]] = and<2 x i64> [[TMP48]], [[TMP49]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[AND24]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP50:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP51:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND25:%.*]] = and<2 x i64> [[TMP50]], [[TMP51]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[AND25]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP52:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP53:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND26:%.*]] = and<2 x i64> [[TMP52]], [[TMP53]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[AND26]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP54:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP55:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND27:%.*]] = and<2 x i64> [[TMP54]], [[TMP55]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[AND27]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_and
parameter_list|(
name|void
parameter_list|)
block|{
name|sc
operator|=
name|sc
operator|&
name|sc2
expr_stmt|;
name|sc
operator|=
name|sc
operator|&
name|bc2
expr_stmt|;
name|sc
operator|=
name|bc
operator|&
name|sc2
expr_stmt|;
name|uc
operator|=
name|uc
operator|&
name|uc2
expr_stmt|;
name|uc
operator|=
name|uc
operator|&
name|bc2
expr_stmt|;
name|uc
operator|=
name|bc
operator|&
name|uc2
expr_stmt|;
name|bc
operator|=
name|bc
operator|&
name|bc2
expr_stmt|;
name|ss
operator|=
name|ss
operator|&
name|ss2
expr_stmt|;
name|ss
operator|=
name|ss
operator|&
name|bs2
expr_stmt|;
name|ss
operator|=
name|bs
operator|&
name|ss2
expr_stmt|;
name|us
operator|=
name|us
operator|&
name|us2
expr_stmt|;
name|us
operator|=
name|us
operator|&
name|bs2
expr_stmt|;
name|us
operator|=
name|bs
operator|&
name|us2
expr_stmt|;
name|bs
operator|=
name|bs
operator|&
name|bs2
expr_stmt|;
name|si
operator|=
name|si
operator|&
name|si2
expr_stmt|;
name|si
operator|=
name|si
operator|&
name|bi2
expr_stmt|;
name|si
operator|=
name|bi
operator|&
name|si2
expr_stmt|;
name|ui
operator|=
name|ui
operator|&
name|ui2
expr_stmt|;
name|ui
operator|=
name|ui
operator|&
name|bi2
expr_stmt|;
name|ui
operator|=
name|bi
operator|&
name|ui2
expr_stmt|;
name|bi
operator|=
name|bi
operator|&
name|bi2
expr_stmt|;
name|sl
operator|=
name|sl
operator|&
name|sl2
expr_stmt|;
name|sl
operator|=
name|sl
operator|&
name|bl2
expr_stmt|;
name|sl
operator|=
name|bl
operator|&
name|sl2
expr_stmt|;
name|ul
operator|=
name|ul
operator|&
name|ul2
expr_stmt|;
name|ul
operator|=
name|ul
operator|&
name|bl2
expr_stmt|;
name|ul
operator|=
name|bl
operator|&
name|ul2
expr_stmt|;
name|bl
operator|=
name|bl
operator|&
name|bl2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_and_assign() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND:%.*]] = and<16 x i8> [[TMP1]], [[TMP0]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[AND]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND1:%.*]] = and<16 x i8> [[TMP3]], [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[AND1]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND2:%.*]] = and<16 x i8> [[TMP5]], [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[AND2]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND3:%.*]] = and<16 x i8> [[TMP7]], [[TMP6]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[AND3]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND4:%.*]] = and<16 x i8> [[TMP9]], [[TMP8]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[AND4]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND5:%.*]] = and<8 x i16> [[TMP11]], [[TMP10]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[AND5]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP12:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP13:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND6:%.*]] = and<8 x i16> [[TMP13]], [[TMP12]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[AND6]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP14:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP15:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND7:%.*]] = and<8 x i16> [[TMP15]], [[TMP14]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[AND7]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP16:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP17:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND8:%.*]] = and<8 x i16> [[TMP17]], [[TMP16]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[AND8]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP18:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP19:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND9:%.*]] = and<8 x i16> [[TMP19]], [[TMP18]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[AND9]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP20:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP21:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND10:%.*]] = and<4 x i32> [[TMP21]], [[TMP20]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[AND10]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP22:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP23:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND11:%.*]] = and<4 x i32> [[TMP23]], [[TMP22]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[AND11]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP24:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP25:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND12:%.*]] = and<4 x i32> [[TMP25]], [[TMP24]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[AND12]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP26:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP27:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND13:%.*]] = and<4 x i32> [[TMP27]], [[TMP26]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[AND13]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP28:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP29:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND14:%.*]] = and<4 x i32> [[TMP29]], [[TMP28]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[AND14]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP30:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP31:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND15:%.*]] = and<2 x i64> [[TMP31]], [[TMP30]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[AND15]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP32:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP33:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND16:%.*]] = and<2 x i64> [[TMP33]], [[TMP32]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[AND16]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP34:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP35:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND17:%.*]] = and<2 x i64> [[TMP35]], [[TMP34]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[AND17]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP36:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP37:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND18:%.*]] = and<2 x i64> [[TMP37]], [[TMP36]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[AND18]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP38:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP39:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[AND19:%.*]] = and<2 x i64> [[TMP39]], [[TMP38]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[AND19]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_and_assign
parameter_list|(
name|void
parameter_list|)
block|{
name|sc
operator|&=
name|sc2
expr_stmt|;
name|sc
operator|&=
name|bc2
expr_stmt|;
name|uc
operator|&=
name|uc2
expr_stmt|;
name|uc
operator|&=
name|bc2
expr_stmt|;
name|bc
operator|&=
name|bc2
expr_stmt|;
name|ss
operator|&=
name|ss2
expr_stmt|;
name|ss
operator|&=
name|bs2
expr_stmt|;
name|us
operator|&=
name|us2
expr_stmt|;
name|us
operator|&=
name|bs2
expr_stmt|;
name|bs
operator|&=
name|bs2
expr_stmt|;
name|si
operator|&=
name|si2
expr_stmt|;
name|si
operator|&=
name|bi2
expr_stmt|;
name|ui
operator|&=
name|ui2
expr_stmt|;
name|ui
operator|&=
name|bi2
expr_stmt|;
name|bi
operator|&=
name|bi2
expr_stmt|;
name|sl
operator|&=
name|sl2
expr_stmt|;
name|sl
operator|&=
name|bl2
expr_stmt|;
name|ul
operator|&=
name|ul2
expr_stmt|;
name|ul
operator|&=
name|bl2
expr_stmt|;
name|bl
operator|&=
name|bl2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_or() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR:%.*]] = or<16 x i8> [[TMP0]], [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[OR]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR1:%.*]] = or<16 x i8> [[TMP2]], [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[OR1]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR2:%.*]] = or<16 x i8> [[TMP4]], [[TMP5]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[OR2]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR3:%.*]] = or<16 x i8> [[TMP6]], [[TMP7]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[OR3]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR4:%.*]] = or<16 x i8> [[TMP8]], [[TMP9]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[OR4]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR5:%.*]] = or<16 x i8> [[TMP10]], [[TMP11]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[OR5]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP12:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP13:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR6:%.*]] = or<16 x i8> [[TMP12]], [[TMP13]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[OR6]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP14:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP15:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR7:%.*]] = or<8 x i16> [[TMP14]], [[TMP15]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[OR7]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP16:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP17:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR8:%.*]] = or<8 x i16> [[TMP16]], [[TMP17]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[OR8]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP18:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP19:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR9:%.*]] = or<8 x i16> [[TMP18]], [[TMP19]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[OR9]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP20:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP21:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR10:%.*]] = or<8 x i16> [[TMP20]], [[TMP21]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[OR10]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP22:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP23:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR11:%.*]] = or<8 x i16> [[TMP22]], [[TMP23]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[OR11]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP24:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP25:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR12:%.*]] = or<8 x i16> [[TMP24]], [[TMP25]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[OR12]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP26:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP27:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR13:%.*]] = or<8 x i16> [[TMP26]], [[TMP27]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[OR13]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP28:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP29:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR14:%.*]] = or<4 x i32> [[TMP28]], [[TMP29]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[OR14]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP30:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP31:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR15:%.*]] = or<4 x i32> [[TMP30]], [[TMP31]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[OR15]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP32:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP33:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR16:%.*]] = or<4 x i32> [[TMP32]], [[TMP33]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[OR16]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP34:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP35:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR17:%.*]] = or<4 x i32> [[TMP34]], [[TMP35]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[OR17]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP36:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP37:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR18:%.*]] = or<4 x i32> [[TMP36]], [[TMP37]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[OR18]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP38:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP39:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR19:%.*]] = or<4 x i32> [[TMP38]], [[TMP39]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[OR19]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP40:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP41:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR20:%.*]] = or<4 x i32> [[TMP40]], [[TMP41]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[OR20]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP42:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP43:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR21:%.*]] = or<2 x i64> [[TMP42]], [[TMP43]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[OR21]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP44:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP45:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR22:%.*]] = or<2 x i64> [[TMP44]], [[TMP45]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[OR22]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP46:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP47:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR23:%.*]] = or<2 x i64> [[TMP46]], [[TMP47]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[OR23]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP48:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP49:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR24:%.*]] = or<2 x i64> [[TMP48]], [[TMP49]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[OR24]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP50:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP51:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR25:%.*]] = or<2 x i64> [[TMP50]], [[TMP51]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[OR25]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP52:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP53:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR26:%.*]] = or<2 x i64> [[TMP52]], [[TMP53]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[OR26]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP54:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP55:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR27:%.*]] = or<2 x i64> [[TMP54]], [[TMP55]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[OR27]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_or
parameter_list|(
name|void
parameter_list|)
block|{
name|sc
operator|=
name|sc
operator||
name|sc2
expr_stmt|;
name|sc
operator|=
name|sc
operator||
name|bc2
expr_stmt|;
name|sc
operator|=
name|bc
operator||
name|sc2
expr_stmt|;
name|uc
operator|=
name|uc
operator||
name|uc2
expr_stmt|;
name|uc
operator|=
name|uc
operator||
name|bc2
expr_stmt|;
name|uc
operator|=
name|bc
operator||
name|uc2
expr_stmt|;
name|bc
operator|=
name|bc
operator||
name|bc2
expr_stmt|;
name|ss
operator|=
name|ss
operator||
name|ss2
expr_stmt|;
name|ss
operator|=
name|ss
operator||
name|bs2
expr_stmt|;
name|ss
operator|=
name|bs
operator||
name|ss2
expr_stmt|;
name|us
operator|=
name|us
operator||
name|us2
expr_stmt|;
name|us
operator|=
name|us
operator||
name|bs2
expr_stmt|;
name|us
operator|=
name|bs
operator||
name|us2
expr_stmt|;
name|bs
operator|=
name|bs
operator||
name|bs2
expr_stmt|;
name|si
operator|=
name|si
operator||
name|si2
expr_stmt|;
name|si
operator|=
name|si
operator||
name|bi2
expr_stmt|;
name|si
operator|=
name|bi
operator||
name|si2
expr_stmt|;
name|ui
operator|=
name|ui
operator||
name|ui2
expr_stmt|;
name|ui
operator|=
name|ui
operator||
name|bi2
expr_stmt|;
name|ui
operator|=
name|bi
operator||
name|ui2
expr_stmt|;
name|bi
operator|=
name|bi
operator||
name|bi2
expr_stmt|;
name|sl
operator|=
name|sl
operator||
name|sl2
expr_stmt|;
name|sl
operator|=
name|sl
operator||
name|bl2
expr_stmt|;
name|sl
operator|=
name|bl
operator||
name|sl2
expr_stmt|;
name|ul
operator|=
name|ul
operator||
name|ul2
expr_stmt|;
name|ul
operator|=
name|ul
operator||
name|bl2
expr_stmt|;
name|ul
operator|=
name|bl
operator||
name|ul2
expr_stmt|;
name|bl
operator|=
name|bl
operator||
name|bl2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_or_assign() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR:%.*]] = or<16 x i8> [[TMP1]], [[TMP0]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[OR]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR1:%.*]] = or<16 x i8> [[TMP3]], [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[OR1]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR2:%.*]] = or<16 x i8> [[TMP5]], [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[OR2]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR3:%.*]] = or<16 x i8> [[TMP7]], [[TMP6]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[OR3]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR4:%.*]] = or<16 x i8> [[TMP9]], [[TMP8]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[OR4]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR5:%.*]] = or<8 x i16> [[TMP11]], [[TMP10]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[OR5]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP12:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP13:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR6:%.*]] = or<8 x i16> [[TMP13]], [[TMP12]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[OR6]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP14:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP15:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR7:%.*]] = or<8 x i16> [[TMP15]], [[TMP14]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[OR7]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP16:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP17:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR8:%.*]] = or<8 x i16> [[TMP17]], [[TMP16]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[OR8]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP18:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP19:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR9:%.*]] = or<8 x i16> [[TMP19]], [[TMP18]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[OR9]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP20:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP21:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR10:%.*]] = or<4 x i32> [[TMP21]], [[TMP20]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[OR10]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP22:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP23:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR11:%.*]] = or<4 x i32> [[TMP23]], [[TMP22]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[OR11]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP24:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP25:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR12:%.*]] = or<4 x i32> [[TMP25]], [[TMP24]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[OR12]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP26:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP27:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR13:%.*]] = or<4 x i32> [[TMP27]], [[TMP26]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[OR13]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP28:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP29:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR14:%.*]] = or<4 x i32> [[TMP29]], [[TMP28]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[OR14]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP30:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP31:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR15:%.*]] = or<2 x i64> [[TMP31]], [[TMP30]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[OR15]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP32:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP33:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR16:%.*]] = or<2 x i64> [[TMP33]], [[TMP32]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[OR16]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP34:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP35:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR17:%.*]] = or<2 x i64> [[TMP35]], [[TMP34]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[OR17]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP36:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP37:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR18:%.*]] = or<2 x i64> [[TMP37]], [[TMP36]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[OR18]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP38:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP39:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[OR19:%.*]] = or<2 x i64> [[TMP39]], [[TMP38]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[OR19]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_or_assign
parameter_list|(
name|void
parameter_list|)
block|{
name|sc
operator||=
name|sc2
expr_stmt|;
name|sc
operator||=
name|bc2
expr_stmt|;
name|uc
operator||=
name|uc2
expr_stmt|;
name|uc
operator||=
name|bc2
expr_stmt|;
name|bc
operator||=
name|bc2
expr_stmt|;
name|ss
operator||=
name|ss2
expr_stmt|;
name|ss
operator||=
name|bs2
expr_stmt|;
name|us
operator||=
name|us2
expr_stmt|;
name|us
operator||=
name|bs2
expr_stmt|;
name|bs
operator||=
name|bs2
expr_stmt|;
name|si
operator||=
name|si2
expr_stmt|;
name|si
operator||=
name|bi2
expr_stmt|;
name|ui
operator||=
name|ui2
expr_stmt|;
name|ui
operator||=
name|bi2
expr_stmt|;
name|bi
operator||=
name|bi2
expr_stmt|;
name|sl
operator||=
name|sl2
expr_stmt|;
name|sl
operator||=
name|bl2
expr_stmt|;
name|ul
operator||=
name|ul2
expr_stmt|;
name|ul
operator||=
name|bl2
expr_stmt|;
name|bl
operator||=
name|bl2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_xor() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR:%.*]] = xor<16 x i8> [[TMP0]], [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[XOR]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR1:%.*]] = xor<16 x i8> [[TMP2]], [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[XOR1]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR2:%.*]] = xor<16 x i8> [[TMP4]], [[TMP5]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[XOR2]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR3:%.*]] = xor<16 x i8> [[TMP6]], [[TMP7]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[XOR3]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR4:%.*]] = xor<16 x i8> [[TMP8]], [[TMP9]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[XOR4]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR5:%.*]] = xor<16 x i8> [[TMP10]], [[TMP11]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[XOR5]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP12:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP13:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR6:%.*]] = xor<16 x i8> [[TMP12]], [[TMP13]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[XOR6]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP14:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP15:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR7:%.*]] = xor<8 x i16> [[TMP14]], [[TMP15]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[XOR7]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP16:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP17:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR8:%.*]] = xor<8 x i16> [[TMP16]], [[TMP17]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[XOR8]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP18:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP19:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR9:%.*]] = xor<8 x i16> [[TMP18]], [[TMP19]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[XOR9]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP20:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP21:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR10:%.*]] = xor<8 x i16> [[TMP20]], [[TMP21]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[XOR10]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP22:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP23:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR11:%.*]] = xor<8 x i16> [[TMP22]], [[TMP23]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[XOR11]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP24:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP25:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR12:%.*]] = xor<8 x i16> [[TMP24]], [[TMP25]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[XOR12]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP26:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP27:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR13:%.*]] = xor<8 x i16> [[TMP26]], [[TMP27]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[XOR13]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP28:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP29:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR14:%.*]] = xor<4 x i32> [[TMP28]], [[TMP29]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[XOR14]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP30:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP31:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR15:%.*]] = xor<4 x i32> [[TMP30]], [[TMP31]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[XOR15]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP32:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP33:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR16:%.*]] = xor<4 x i32> [[TMP32]], [[TMP33]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[XOR16]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP34:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP35:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR17:%.*]] = xor<4 x i32> [[TMP34]], [[TMP35]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[XOR17]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP36:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP37:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR18:%.*]] = xor<4 x i32> [[TMP36]], [[TMP37]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[XOR18]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP38:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP39:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR19:%.*]] = xor<4 x i32> [[TMP38]], [[TMP39]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[XOR19]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP40:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP41:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR20:%.*]] = xor<4 x i32> [[TMP40]], [[TMP41]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[XOR20]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP42:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP43:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR21:%.*]] = xor<2 x i64> [[TMP42]], [[TMP43]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[XOR21]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP44:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP45:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR22:%.*]] = xor<2 x i64> [[TMP44]], [[TMP45]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[XOR22]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP46:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP47:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR23:%.*]] = xor<2 x i64> [[TMP46]], [[TMP47]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[XOR23]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP48:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP49:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR24:%.*]] = xor<2 x i64> [[TMP48]], [[TMP49]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[XOR24]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP50:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP51:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR25:%.*]] = xor<2 x i64> [[TMP50]], [[TMP51]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[XOR25]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP52:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP53:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR26:%.*]] = xor<2 x i64> [[TMP52]], [[TMP53]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[XOR26]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP54:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP55:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR27:%.*]] = xor<2 x i64> [[TMP54]], [[TMP55]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[XOR27]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_xor
parameter_list|(
name|void
parameter_list|)
block|{
name|sc
operator|=
name|sc
operator|^
name|sc2
expr_stmt|;
name|sc
operator|=
name|sc
operator|^
name|bc2
expr_stmt|;
name|sc
operator|=
name|bc
operator|^
name|sc2
expr_stmt|;
name|uc
operator|=
name|uc
operator|^
name|uc2
expr_stmt|;
name|uc
operator|=
name|uc
operator|^
name|bc2
expr_stmt|;
name|uc
operator|=
name|bc
operator|^
name|uc2
expr_stmt|;
name|bc
operator|=
name|bc
operator|^
name|bc2
expr_stmt|;
name|ss
operator|=
name|ss
operator|^
name|ss2
expr_stmt|;
name|ss
operator|=
name|ss
operator|^
name|bs2
expr_stmt|;
name|ss
operator|=
name|bs
operator|^
name|ss2
expr_stmt|;
name|us
operator|=
name|us
operator|^
name|us2
expr_stmt|;
name|us
operator|=
name|us
operator|^
name|bs2
expr_stmt|;
name|us
operator|=
name|bs
operator|^
name|us2
expr_stmt|;
name|bs
operator|=
name|bs
operator|^
name|bs2
expr_stmt|;
name|si
operator|=
name|si
operator|^
name|si2
expr_stmt|;
name|si
operator|=
name|si
operator|^
name|bi2
expr_stmt|;
name|si
operator|=
name|bi
operator|^
name|si2
expr_stmt|;
name|ui
operator|=
name|ui
operator|^
name|ui2
expr_stmt|;
name|ui
operator|=
name|ui
operator|^
name|bi2
expr_stmt|;
name|ui
operator|=
name|bi
operator|^
name|ui2
expr_stmt|;
name|bi
operator|=
name|bi
operator|^
name|bi2
expr_stmt|;
name|sl
operator|=
name|sl
operator|^
name|sl2
expr_stmt|;
name|sl
operator|=
name|sl
operator|^
name|bl2
expr_stmt|;
name|sl
operator|=
name|bl
operator|^
name|sl2
expr_stmt|;
name|ul
operator|=
name|ul
operator|^
name|ul2
expr_stmt|;
name|ul
operator|=
name|ul
operator|^
name|bl2
expr_stmt|;
name|ul
operator|=
name|bl
operator|^
name|ul2
expr_stmt|;
name|bl
operator|=
name|bl
operator|^
name|bl2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_xor_assign() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR:%.*]] = xor<16 x i8> [[TMP1]], [[TMP0]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[XOR]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR1:%.*]] = xor<16 x i8> [[TMP3]], [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[XOR1]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR2:%.*]] = xor<16 x i8> [[TMP5]], [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[XOR2]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR3:%.*]] = xor<16 x i8> [[TMP7]], [[TMP6]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[XOR3]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR4:%.*]] = xor<16 x i8> [[TMP9]], [[TMP8]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[XOR4]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR5:%.*]] = xor<8 x i16> [[TMP11]], [[TMP10]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[XOR5]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP12:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP13:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR6:%.*]] = xor<8 x i16> [[TMP13]], [[TMP12]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[XOR6]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP14:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP15:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR7:%.*]] = xor<8 x i16> [[TMP15]], [[TMP14]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[XOR7]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP16:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP17:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR8:%.*]] = xor<8 x i16> [[TMP17]], [[TMP16]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[XOR8]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP18:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP19:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR9:%.*]] = xor<8 x i16> [[TMP19]], [[TMP18]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[XOR9]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP20:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP21:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR10:%.*]] = xor<4 x i32> [[TMP21]], [[TMP20]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[XOR10]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP22:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP23:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR11:%.*]] = xor<4 x i32> [[TMP23]], [[TMP22]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[XOR11]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP24:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP25:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR12:%.*]] = xor<4 x i32> [[TMP25]], [[TMP24]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[XOR12]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP26:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP27:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR13:%.*]] = xor<4 x i32> [[TMP27]], [[TMP26]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[XOR13]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP28:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP29:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR14:%.*]] = xor<4 x i32> [[TMP29]], [[TMP28]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[XOR14]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP30:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP31:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR15:%.*]] = xor<2 x i64> [[TMP31]], [[TMP30]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[XOR15]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP32:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP33:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR16:%.*]] = xor<2 x i64> [[TMP33]], [[TMP32]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[XOR16]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP34:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP35:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR17:%.*]] = xor<2 x i64> [[TMP35]], [[TMP34]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[XOR17]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP36:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP37:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR18:%.*]] = xor<2 x i64> [[TMP37]], [[TMP36]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[XOR18]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP38:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP39:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[XOR19:%.*]] = xor<2 x i64> [[TMP39]], [[TMP38]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[XOR19]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_xor_assign
parameter_list|(
name|void
parameter_list|)
block|{
name|sc
operator|^=
name|sc2
expr_stmt|;
name|sc
operator|^=
name|bc2
expr_stmt|;
name|uc
operator|^=
name|uc2
expr_stmt|;
name|uc
operator|^=
name|bc2
expr_stmt|;
name|bc
operator|^=
name|bc2
expr_stmt|;
name|ss
operator|^=
name|ss2
expr_stmt|;
name|ss
operator|^=
name|bs2
expr_stmt|;
name|us
operator|^=
name|us2
expr_stmt|;
name|us
operator|^=
name|bs2
expr_stmt|;
name|bs
operator|^=
name|bs2
expr_stmt|;
name|si
operator|^=
name|si2
expr_stmt|;
name|si
operator|^=
name|bi2
expr_stmt|;
name|ui
operator|^=
name|ui2
expr_stmt|;
name|ui
operator|^=
name|bi2
expr_stmt|;
name|bi
operator|^=
name|bi2
expr_stmt|;
name|sl
operator|^=
name|sl2
expr_stmt|;
name|sl
operator|^=
name|bl2
expr_stmt|;
name|ul
operator|^=
name|ul2
expr_stmt|;
name|ul
operator|^=
name|bl2
expr_stmt|;
name|bl
operator|^=
name|bl2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_sl() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL:%.*]] = shl<16 x i8> [[TMP0]], [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHL]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL1:%.*]] = shl<16 x i8> [[TMP2]], [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHL1]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT:%.*]] = insertelement<16 x i32> undef, i32 [[TMP5]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT:%.*]] = shufflevector<16 x i32> [[SPLAT_SPLAT:%.*]]insert,<16 x i32> undef,<16 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[SH_PROM:%.*]] = trunc<16 x i32> [[SPLAT_SPLAT]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[SHL2:%.*]] = shl<16 x i8> [[TMP4]], [[SH_PROM]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHL2]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL3:%.*]] = shl<16 x i8> [[TMP6]],<i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHL3]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL4:%.*]] = shl<16 x i8> [[TMP7]], [[TMP8]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHL4]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL5:%.*]] = shl<16 x i8> [[TMP9]], [[TMP10]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHL5]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP12:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT6:%.*]] = insertelement<16 x i32> undef, i32 [[TMP12]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT7:%.*]] = shufflevector<16 x i32> [[SPLAT_SPLATINSERT6]],<16 x i32> undef,<16 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[SH_PROM8:%.*]] = trunc<16 x i32> [[SPLAT_SPLAT7]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[SHL9:%.*]] = shl<16 x i8> [[TMP11]], [[SH_PROM8]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHL9]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP13:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL10:%.*]] = shl<16 x i8> [[TMP13]],<i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHL10]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP14:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP15:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL11:%.*]] = shl<8 x i16> [[TMP14]], [[TMP15]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHL11]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP16:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP17:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL12:%.*]] = shl<8 x i16> [[TMP16]], [[TMP17]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHL12]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP18:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP19:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT13:%.*]] = insertelement<8 x i32> undef, i32 [[TMP19]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT14:%.*]] = shufflevector<8 x i32> [[SPLAT_SPLATINSERT13]],<8 x i32> undef,<8 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[SH_PROM15:%.*]] = trunc<8 x i32> [[SPLAT_SPLAT14]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[SHL16:%.*]] = shl<8 x i16> [[TMP18]], [[SH_PROM15]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHL16]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP20:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL17:%.*]] = shl<8 x i16> [[TMP20]],<i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHL17]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP21:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP22:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL18:%.*]] = shl<8 x i16> [[TMP21]], [[TMP22]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHL18]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP23:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP24:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL19:%.*]] = shl<8 x i16> [[TMP23]], [[TMP24]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHL19]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP25:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP26:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT20:%.*]] = insertelement<8 x i32> undef, i32 [[TMP26]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT21:%.*]] = shufflevector<8 x i32> [[SPLAT_SPLATINSERT20]],<8 x i32> undef,<8 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[SH_PROM22:%.*]] = trunc<8 x i32> [[SPLAT_SPLAT21]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[SHL23:%.*]] = shl<8 x i16> [[TMP25]], [[SH_PROM22]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHL23]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP27:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL24:%.*]] = shl<8 x i16> [[TMP27]],<i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHL24]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP28:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP29:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL25:%.*]] = shl<4 x i32> [[TMP28]], [[TMP29]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHL25]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP30:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP31:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL26:%.*]] = shl<4 x i32> [[TMP30]], [[TMP31]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHL26]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP32:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP33:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT27:%.*]] = insertelement<4 x i32> undef, i32 [[TMP33]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT28:%.*]] = shufflevector<4 x i32> [[SPLAT_SPLATINSERT27]],<4 x i32> undef,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[SHL29:%.*]] = shl<4 x i32> [[TMP32]], [[SPLAT_SPLAT28]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHL29]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP34:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL30:%.*]] = shl<4 x i32> [[TMP34]],<i32 5, i32 5, i32 5, i32 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHL30]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP35:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP36:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL31:%.*]] = shl<4 x i32> [[TMP35]], [[TMP36]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHL31]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP37:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP38:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL32:%.*]] = shl<4 x i32> [[TMP37]], [[TMP38]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHL32]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP39:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP40:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT33:%.*]] = insertelement<4 x i32> undef, i32 [[TMP40]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT34:%.*]] = shufflevector<4 x i32> [[SPLAT_SPLATINSERT33]],<4 x i32> undef,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[SHL35:%.*]] = shl<4 x i32> [[TMP39]], [[SPLAT_SPLAT34]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHL35]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP41:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL36:%.*]] = shl<4 x i32> [[TMP41]],<i32 5, i32 5, i32 5, i32 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHL36]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP42:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP43:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL37:%.*]] = shl<2 x i64> [[TMP42]], [[TMP43]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHL37]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP44:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP45:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL38:%.*]] = shl<2 x i64> [[TMP44]], [[TMP45]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHL38]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP46:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP47:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT39:%.*]] = insertelement<2 x i32> undef, i32 [[TMP47]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT40:%.*]] = shufflevector<2 x i32> [[SPLAT_SPLATINSERT39]],<2 x i32> undef,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[SH_PROM41:%.*]] = zext<2 x i32> [[SPLAT_SPLAT40]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[SHL42:%.*]] = shl<2 x i64> [[TMP46]], [[SH_PROM41]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHL42]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP48:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL43:%.*]] = shl<2 x i64> [[TMP48]],<i64 5, i64 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHL43]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP49:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP50:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL44:%.*]] = shl<2 x i64> [[TMP49]], [[TMP50]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHL44]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP51:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP52:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL45:%.*]] = shl<2 x i64> [[TMP51]], [[TMP52]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHL45]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP53:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP54:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT46:%.*]] = insertelement<2 x i32> undef, i32 [[TMP54]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT47:%.*]] = shufflevector<2 x i32> [[SPLAT_SPLATINSERT46]],<2 x i32> undef,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[SH_PROM48:%.*]] = zext<2 x i32> [[SPLAT_SPLAT47]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[SHL49:%.*]] = shl<2 x i64> [[TMP53]], [[SH_PROM48]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHL49]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP55:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL50:%.*]] = shl<2 x i64> [[TMP55]],<i64 5, i64 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHL50]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_sl
parameter_list|(
name|void
parameter_list|)
block|{
name|sc
operator|=
name|sc
operator|<<
name|sc2
expr_stmt|;
name|sc
operator|=
name|sc
operator|<<
name|uc2
expr_stmt|;
name|sc
operator|=
name|sc
operator|<<
name|cnt
expr_stmt|;
name|sc
operator|=
name|sc
operator|<<
literal|5
expr_stmt|;
name|uc
operator|=
name|uc
operator|<<
name|sc2
expr_stmt|;
name|uc
operator|=
name|uc
operator|<<
name|uc2
expr_stmt|;
name|uc
operator|=
name|uc
operator|<<
name|cnt
expr_stmt|;
name|uc
operator|=
name|uc
operator|<<
literal|5
expr_stmt|;
name|ss
operator|=
name|ss
operator|<<
name|ss2
expr_stmt|;
name|ss
operator|=
name|ss
operator|<<
name|us2
expr_stmt|;
name|ss
operator|=
name|ss
operator|<<
name|cnt
expr_stmt|;
name|ss
operator|=
name|ss
operator|<<
literal|5
expr_stmt|;
name|us
operator|=
name|us
operator|<<
name|ss2
expr_stmt|;
name|us
operator|=
name|us
operator|<<
name|us2
expr_stmt|;
name|us
operator|=
name|us
operator|<<
name|cnt
expr_stmt|;
name|us
operator|=
name|us
operator|<<
literal|5
expr_stmt|;
name|si
operator|=
name|si
operator|<<
name|si2
expr_stmt|;
name|si
operator|=
name|si
operator|<<
name|ui2
expr_stmt|;
name|si
operator|=
name|si
operator|<<
name|cnt
expr_stmt|;
name|si
operator|=
name|si
operator|<<
literal|5
expr_stmt|;
name|ui
operator|=
name|ui
operator|<<
name|si2
expr_stmt|;
name|ui
operator|=
name|ui
operator|<<
name|ui2
expr_stmt|;
name|ui
operator|=
name|ui
operator|<<
name|cnt
expr_stmt|;
name|ui
operator|=
name|ui
operator|<<
literal|5
expr_stmt|;
name|sl
operator|=
name|sl
operator|<<
name|sl2
expr_stmt|;
name|sl
operator|=
name|sl
operator|<<
name|ul2
expr_stmt|;
name|sl
operator|=
name|sl
operator|<<
name|cnt
expr_stmt|;
name|sl
operator|=
name|sl
operator|<<
literal|5
expr_stmt|;
name|ul
operator|=
name|ul
operator|<<
name|sl2
expr_stmt|;
name|ul
operator|=
name|ul
operator|<<
name|ul2
expr_stmt|;
name|ul
operator|=
name|ul
operator|<<
name|cnt
expr_stmt|;
name|ul
operator|=
name|ul
operator|<<
literal|5
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_sl_assign() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL:%.*]] = shl<16 x i8> [[TMP1]], [[TMP0]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHL]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL1:%.*]] = shl<16 x i8> [[TMP3]], [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHL1]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT:%.*]] = insertelement<16 x i32> undef, i32 [[TMP4]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT:%.*]] = shufflevector<16 x i32> [[SPLAT_SPLAT:%.*]]insert,<16 x i32> undef,<16 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[SH_PROM:%.*]] = trunc<16 x i32> [[SPLAT_SPLAT]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[SHL2:%.*]] = shl<16 x i8> [[TMP5]], [[SH_PROM]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHL2]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL3:%.*]] = shl<16 x i8> [[TMP6]],<i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHL3]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL4:%.*]] = shl<16 x i8> [[TMP8]], [[TMP7]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHL4]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL5:%.*]] = shl<16 x i8> [[TMP10]], [[TMP9]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHL5]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT6:%.*]] = insertelement<16 x i32> undef, i32 [[TMP11]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT7:%.*]] = shufflevector<16 x i32> [[SPLAT_SPLATINSERT6]],<16 x i32> undef,<16 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP12:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[SH_PROM8:%.*]] = trunc<16 x i32> [[SPLAT_SPLAT7]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[SHL9:%.*]] = shl<16 x i8> [[TMP12]], [[SH_PROM8]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHL9]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP13:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL10:%.*]] = shl<16 x i8> [[TMP13]],<i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHL10]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP14:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP15:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL11:%.*]] = shl<8 x i16> [[TMP15]], [[TMP14]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHL11]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP16:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP17:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL12:%.*]] = shl<8 x i16> [[TMP17]], [[TMP16]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHL12]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP18:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT13:%.*]] = insertelement<8 x i32> undef, i32 [[TMP18]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT14:%.*]] = shufflevector<8 x i32> [[SPLAT_SPLATINSERT13]],<8 x i32> undef,<8 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP19:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[SH_PROM15:%.*]] = trunc<8 x i32> [[SPLAT_SPLAT14]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[SHL16:%.*]] = shl<8 x i16> [[TMP19]], [[SH_PROM15]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHL16]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP20:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL17:%.*]] = shl<8 x i16> [[TMP20]],<i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHL17]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP21:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP22:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL18:%.*]] = shl<8 x i16> [[TMP22]], [[TMP21]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHL18]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP23:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP24:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL19:%.*]] = shl<8 x i16> [[TMP24]], [[TMP23]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHL19]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP25:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT20:%.*]] = insertelement<8 x i32> undef, i32 [[TMP25]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT21:%.*]] = shufflevector<8 x i32> [[SPLAT_SPLATINSERT20]],<8 x i32> undef,<8 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP26:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[SH_PROM22:%.*]] = trunc<8 x i32> [[SPLAT_SPLAT21]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[SHL23:%.*]] = shl<8 x i16> [[TMP26]], [[SH_PROM22]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHL23]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP27:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL24:%.*]] = shl<8 x i16> [[TMP27]],<i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHL24]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP28:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP29:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL25:%.*]] = shl<4 x i32> [[TMP29]], [[TMP28]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHL25]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP30:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP31:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL26:%.*]] = shl<4 x i32> [[TMP31]], [[TMP30]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHL26]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP32:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT27:%.*]] = insertelement<4 x i32> undef, i32 [[TMP32]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT28:%.*]] = shufflevector<4 x i32> [[SPLAT_SPLATINSERT27]],<4 x i32> undef,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP33:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL29:%.*]] = shl<4 x i32> [[TMP33]], [[SPLAT_SPLAT28]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHL29]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP34:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL30:%.*]] = shl<4 x i32> [[TMP34]],<i32 5, i32 5, i32 5, i32 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHL30]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP35:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP36:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL31:%.*]] = shl<4 x i32> [[TMP36]], [[TMP35]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHL31]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP37:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP38:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL32:%.*]] = shl<4 x i32> [[TMP38]], [[TMP37]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHL32]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP39:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT33:%.*]] = insertelement<4 x i32> undef, i32 [[TMP39]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT34:%.*]] = shufflevector<4 x i32> [[SPLAT_SPLATINSERT33]],<4 x i32> undef,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP40:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL35:%.*]] = shl<4 x i32> [[TMP40]], [[SPLAT_SPLAT34]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHL35]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP41:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL36:%.*]] = shl<4 x i32> [[TMP41]],<i32 5, i32 5, i32 5, i32 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHL36]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP42:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP43:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL37:%.*]] = shl<2 x i64> [[TMP43]], [[TMP42]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHL37]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP44:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP45:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL38:%.*]] = shl<2 x i64> [[TMP45]], [[TMP44]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHL38]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP46:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT39:%.*]] = insertelement<2 x i32> undef, i32 [[TMP46]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT40:%.*]] = shufflevector<2 x i32> [[SPLAT_SPLATINSERT39]],<2 x i32> undef,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP47:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[SH_PROM41:%.*]] = zext<2 x i32> [[SPLAT_SPLAT40]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[SHL42:%.*]] = shl<2 x i64> [[TMP47]], [[SH_PROM41]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHL42]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP48:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL43:%.*]] = shl<2 x i64> [[TMP48]],<i64 5, i64 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHL43]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP49:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP50:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL44:%.*]] = shl<2 x i64> [[TMP50]], [[TMP49]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHL44]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP51:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP52:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL45:%.*]] = shl<2 x i64> [[TMP52]], [[TMP51]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHL45]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP53:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT46:%.*]] = insertelement<2 x i32> undef, i32 [[TMP53]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT47:%.*]] = shufflevector<2 x i32> [[SPLAT_SPLATINSERT46]],<2 x i32> undef,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP54:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[SH_PROM48:%.*]] = zext<2 x i32> [[SPLAT_SPLAT47]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[SHL49:%.*]] = shl<2 x i64> [[TMP54]], [[SH_PROM48]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHL49]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP55:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHL50:%.*]] = shl<2 x i64> [[TMP55]],<i64 5, i64 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHL50]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_sl_assign
parameter_list|(
name|void
parameter_list|)
block|{
name|sc
operator|<<=
name|sc2
expr_stmt|;
name|sc
operator|<<=
name|uc2
expr_stmt|;
name|sc
operator|<<=
name|cnt
expr_stmt|;
name|sc
operator|<<=
literal|5
expr_stmt|;
name|uc
operator|<<=
name|sc2
expr_stmt|;
name|uc
operator|<<=
name|uc2
expr_stmt|;
name|uc
operator|<<=
name|cnt
expr_stmt|;
name|uc
operator|<<=
literal|5
expr_stmt|;
name|ss
operator|<<=
name|ss2
expr_stmt|;
name|ss
operator|<<=
name|us2
expr_stmt|;
name|ss
operator|<<=
name|cnt
expr_stmt|;
name|ss
operator|<<=
literal|5
expr_stmt|;
name|us
operator|<<=
name|ss2
expr_stmt|;
name|us
operator|<<=
name|us2
expr_stmt|;
name|us
operator|<<=
name|cnt
expr_stmt|;
name|us
operator|<<=
literal|5
expr_stmt|;
name|si
operator|<<=
name|si2
expr_stmt|;
name|si
operator|<<=
name|ui2
expr_stmt|;
name|si
operator|<<=
name|cnt
expr_stmt|;
name|si
operator|<<=
literal|5
expr_stmt|;
name|ui
operator|<<=
name|si2
expr_stmt|;
name|ui
operator|<<=
name|ui2
expr_stmt|;
name|ui
operator|<<=
name|cnt
expr_stmt|;
name|ui
operator|<<=
literal|5
expr_stmt|;
name|sl
operator|<<=
name|sl2
expr_stmt|;
name|sl
operator|<<=
name|ul2
expr_stmt|;
name|sl
operator|<<=
name|cnt
expr_stmt|;
name|sl
operator|<<=
literal|5
expr_stmt|;
name|ul
operator|<<=
name|sl2
expr_stmt|;
name|ul
operator|<<=
name|ul2
expr_stmt|;
name|ul
operator|<<=
name|cnt
expr_stmt|;
name|ul
operator|<<=
literal|5
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_sr() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR:%.*]] = ashr<16 x i8> [[TMP0]], [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHR]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR1:%.*]] = ashr<16 x i8> [[TMP2]], [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHR1]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT:%.*]] = insertelement<16 x i32> undef, i32 [[TMP5]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT:%.*]] = shufflevector<16 x i32> [[SPLAT_SPLAT:%.*]]insert,<16 x i32> undef,<16 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[SH_PROM:%.*]] = trunc<16 x i32> [[SPLAT_SPLAT]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[SHR2:%.*]] = ashr<16 x i8> [[TMP4]], [[SH_PROM]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHR2]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR3:%.*]] = ashr<16 x i8> [[TMP6]],<i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHR3]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR4:%.*]] = lshr<16 x i8> [[TMP7]], [[TMP8]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHR4]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR5:%.*]] = lshr<16 x i8> [[TMP9]], [[TMP10]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHR5]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP12:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT6:%.*]] = insertelement<16 x i32> undef, i32 [[TMP12]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT7:%.*]] = shufflevector<16 x i32> [[SPLAT_SPLATINSERT6]],<16 x i32> undef,<16 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[SH_PROM8:%.*]] = trunc<16 x i32> [[SPLAT_SPLAT7]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[SHR9:%.*]] = lshr<16 x i8> [[TMP11]], [[SH_PROM8]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHR9]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP13:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR10:%.*]] = lshr<16 x i8> [[TMP13]],<i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHR10]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP14:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP15:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR11:%.*]] = ashr<8 x i16> [[TMP14]], [[TMP15]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHR11]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP16:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP17:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR12:%.*]] = ashr<8 x i16> [[TMP16]], [[TMP17]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHR12]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP18:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP19:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT13:%.*]] = insertelement<8 x i32> undef, i32 [[TMP19]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT14:%.*]] = shufflevector<8 x i32> [[SPLAT_SPLATINSERT13]],<8 x i32> undef,<8 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[SH_PROM15:%.*]] = trunc<8 x i32> [[SPLAT_SPLAT14]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[SHR16:%.*]] = ashr<8 x i16> [[TMP18]], [[SH_PROM15]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHR16]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP20:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR17:%.*]] = ashr<8 x i16> [[TMP20]],<i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHR17]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP21:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP22:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR18:%.*]] = lshr<8 x i16> [[TMP21]], [[TMP22]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHR18]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP23:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP24:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR19:%.*]] = lshr<8 x i16> [[TMP23]], [[TMP24]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHR19]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP25:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP26:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT20:%.*]] = insertelement<8 x i32> undef, i32 [[TMP26]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT21:%.*]] = shufflevector<8 x i32> [[SPLAT_SPLATINSERT20]],<8 x i32> undef,<8 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[SH_PROM22:%.*]] = trunc<8 x i32> [[SPLAT_SPLAT21]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[SHR23:%.*]] = lshr<8 x i16> [[TMP25]], [[SH_PROM22]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHR23]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP27:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR24:%.*]] = lshr<8 x i16> [[TMP27]],<i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHR24]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP28:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP29:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR25:%.*]] = ashr<4 x i32> [[TMP28]], [[TMP29]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHR25]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP30:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP31:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR26:%.*]] = ashr<4 x i32> [[TMP30]], [[TMP31]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHR26]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP32:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP33:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT27:%.*]] = insertelement<4 x i32> undef, i32 [[TMP33]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT28:%.*]] = shufflevector<4 x i32> [[SPLAT_SPLATINSERT27]],<4 x i32> undef,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[SHR29:%.*]] = ashr<4 x i32> [[TMP32]], [[SPLAT_SPLAT28]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHR29]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP34:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR30:%.*]] = ashr<4 x i32> [[TMP34]],<i32 5, i32 5, i32 5, i32 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHR30]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP35:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP36:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR31:%.*]] = lshr<4 x i32> [[TMP35]], [[TMP36]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHR31]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP37:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP38:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR32:%.*]] = lshr<4 x i32> [[TMP37]], [[TMP38]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHR32]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP39:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP40:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT33:%.*]] = insertelement<4 x i32> undef, i32 [[TMP40]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT34:%.*]] = shufflevector<4 x i32> [[SPLAT_SPLATINSERT33]],<4 x i32> undef,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[SHR35:%.*]] = lshr<4 x i32> [[TMP39]], [[SPLAT_SPLAT34]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHR35]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP41:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR36:%.*]] = lshr<4 x i32> [[TMP41]],<i32 5, i32 5, i32 5, i32 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHR36]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP42:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP43:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR37:%.*]] = ashr<2 x i64> [[TMP42]], [[TMP43]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHR37]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP44:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP45:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR38:%.*]] = ashr<2 x i64> [[TMP44]], [[TMP45]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHR38]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP46:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP47:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT39:%.*]] = insertelement<2 x i32> undef, i32 [[TMP47]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT40:%.*]] = shufflevector<2 x i32> [[SPLAT_SPLATINSERT39]],<2 x i32> undef,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[SH_PROM41:%.*]] = zext<2 x i32> [[SPLAT_SPLAT40]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[SHR42:%.*]] = ashr<2 x i64> [[TMP46]], [[SH_PROM41]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHR42]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP48:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR43:%.*]] = ashr<2 x i64> [[TMP48]],<i64 5, i64 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHR43]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP49:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP50:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR44:%.*]] = lshr<2 x i64> [[TMP49]], [[TMP50]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHR44]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP51:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP52:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR45:%.*]] = lshr<2 x i64> [[TMP51]], [[TMP52]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHR45]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP53:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP54:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT46:%.*]] = insertelement<2 x i32> undef, i32 [[TMP54]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT47:%.*]] = shufflevector<2 x i32> [[SPLAT_SPLATINSERT46]],<2 x i32> undef,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[SH_PROM48:%.*]] = zext<2 x i32> [[SPLAT_SPLAT47]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[SHR49:%.*]] = lshr<2 x i64> [[TMP53]], [[SH_PROM48]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHR49]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP55:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR50:%.*]] = lshr<2 x i64> [[TMP55]],<i64 5, i64 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHR50]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_sr
parameter_list|(
name|void
parameter_list|)
block|{
name|sc
operator|=
name|sc
operator|>>
name|sc2
expr_stmt|;
name|sc
operator|=
name|sc
operator|>>
name|uc2
expr_stmt|;
name|sc
operator|=
name|sc
operator|>>
name|cnt
expr_stmt|;
name|sc
operator|=
name|sc
operator|>>
literal|5
expr_stmt|;
name|uc
operator|=
name|uc
operator|>>
name|sc2
expr_stmt|;
name|uc
operator|=
name|uc
operator|>>
name|uc2
expr_stmt|;
name|uc
operator|=
name|uc
operator|>>
name|cnt
expr_stmt|;
name|uc
operator|=
name|uc
operator|>>
literal|5
expr_stmt|;
name|ss
operator|=
name|ss
operator|>>
name|ss2
expr_stmt|;
name|ss
operator|=
name|ss
operator|>>
name|us2
expr_stmt|;
name|ss
operator|=
name|ss
operator|>>
name|cnt
expr_stmt|;
name|ss
operator|=
name|ss
operator|>>
literal|5
expr_stmt|;
name|us
operator|=
name|us
operator|>>
name|ss2
expr_stmt|;
name|us
operator|=
name|us
operator|>>
name|us2
expr_stmt|;
name|us
operator|=
name|us
operator|>>
name|cnt
expr_stmt|;
name|us
operator|=
name|us
operator|>>
literal|5
expr_stmt|;
name|si
operator|=
name|si
operator|>>
name|si2
expr_stmt|;
name|si
operator|=
name|si
operator|>>
name|ui2
expr_stmt|;
name|si
operator|=
name|si
operator|>>
name|cnt
expr_stmt|;
name|si
operator|=
name|si
operator|>>
literal|5
expr_stmt|;
name|ui
operator|=
name|ui
operator|>>
name|si2
expr_stmt|;
name|ui
operator|=
name|ui
operator|>>
name|ui2
expr_stmt|;
name|ui
operator|=
name|ui
operator|>>
name|cnt
expr_stmt|;
name|ui
operator|=
name|ui
operator|>>
literal|5
expr_stmt|;
name|sl
operator|=
name|sl
operator|>>
name|sl2
expr_stmt|;
name|sl
operator|=
name|sl
operator|>>
name|ul2
expr_stmt|;
name|sl
operator|=
name|sl
operator|>>
name|cnt
expr_stmt|;
name|sl
operator|=
name|sl
operator|>>
literal|5
expr_stmt|;
name|ul
operator|=
name|ul
operator|>>
name|sl2
expr_stmt|;
name|ul
operator|=
name|ul
operator|>>
name|ul2
expr_stmt|;
name|ul
operator|=
name|ul
operator|>>
name|cnt
expr_stmt|;
name|ul
operator|=
name|ul
operator|>>
literal|5
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_sr_assign() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR:%.*]] = ashr<16 x i8> [[TMP1]], [[TMP0]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHR]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR1:%.*]] = ashr<16 x i8> [[TMP3]], [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHR1]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT:%.*]] = insertelement<16 x i32> undef, i32 [[TMP4]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT:%.*]] = shufflevector<16 x i32> [[SPLAT_SPLAT:%.*]]insert,<16 x i32> undef,<16 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[SH_PROM:%.*]] = trunc<16 x i32> [[SPLAT_SPLAT]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[SHR2:%.*]] = ashr<16 x i8> [[TMP5]], [[SH_PROM]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHR2]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR3:%.*]] = ashr<16 x i8> [[TMP6]],<i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHR3]],<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR4:%.*]] = lshr<16 x i8> [[TMP8]], [[TMP7]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHR4]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR5:%.*]] = lshr<16 x i8> [[TMP10]], [[TMP9]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHR5]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT6:%.*]] = insertelement<16 x i32> undef, i32 [[TMP11]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT7:%.*]] = shufflevector<16 x i32> [[SPLAT_SPLATINSERT6]],<16 x i32> undef,<16 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP12:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[SH_PROM8:%.*]] = trunc<16 x i32> [[SPLAT_SPLAT7]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[SHR9:%.*]] = lshr<16 x i8> [[TMP12]], [[SH_PROM8]]
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHR9]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP13:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR10:%.*]] = lshr<16 x i8> [[TMP13]],<i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5, i8 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SHR10]],<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP14:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP15:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR11:%.*]] = ashr<8 x i16> [[TMP15]], [[TMP14]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHR11]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP16:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP17:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR12:%.*]] = ashr<8 x i16> [[TMP17]], [[TMP16]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHR12]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP18:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT13:%.*]] = insertelement<8 x i32> undef, i32 [[TMP18]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT14:%.*]] = shufflevector<8 x i32> [[SPLAT_SPLATINSERT13]],<8 x i32> undef,<8 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP19:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[SH_PROM15:%.*]] = trunc<8 x i32> [[SPLAT_SPLAT14]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[SHR16:%.*]] = ashr<8 x i16> [[TMP19]], [[SH_PROM15]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHR16]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP20:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR17:%.*]] = ashr<8 x i16> [[TMP20]],<i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHR17]],<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP21:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP22:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR18:%.*]] = lshr<8 x i16> [[TMP22]], [[TMP21]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHR18]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP23:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP24:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR19:%.*]] = lshr<8 x i16> [[TMP24]], [[TMP23]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHR19]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP25:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT20:%.*]] = insertelement<8 x i32> undef, i32 [[TMP25]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT21:%.*]] = shufflevector<8 x i32> [[SPLAT_SPLATINSERT20]],<8 x i32> undef,<8 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP26:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[SH_PROM22:%.*]] = trunc<8 x i32> [[SPLAT_SPLAT21]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[SHR23:%.*]] = lshr<8 x i16> [[TMP26]], [[SH_PROM22]]
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHR23]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP27:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR24:%.*]] = lshr<8 x i16> [[TMP27]],<i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5, i16 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SHR24]],<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP28:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP29:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR25:%.*]] = ashr<4 x i32> [[TMP29]], [[TMP28]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHR25]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP30:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP31:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR26:%.*]] = ashr<4 x i32> [[TMP31]], [[TMP30]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHR26]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP32:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT27:%.*]] = insertelement<4 x i32> undef, i32 [[TMP32]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT28:%.*]] = shufflevector<4 x i32> [[SPLAT_SPLATINSERT27]],<4 x i32> undef,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP33:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR29:%.*]] = ashr<4 x i32> [[TMP33]], [[SPLAT_SPLAT28]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHR29]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP34:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR30:%.*]] = ashr<4 x i32> [[TMP34]],<i32 5, i32 5, i32 5, i32 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHR30]],<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP35:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP36:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR31:%.*]] = lshr<4 x i32> [[TMP36]], [[TMP35]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHR31]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP37:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP38:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR32:%.*]] = lshr<4 x i32> [[TMP38]], [[TMP37]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHR32]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP39:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT33:%.*]] = insertelement<4 x i32> undef, i32 [[TMP39]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT34:%.*]] = shufflevector<4 x i32> [[SPLAT_SPLATINSERT33]],<4 x i32> undef,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP40:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR35:%.*]] = lshr<4 x i32> [[TMP40]], [[SPLAT_SPLAT34]]
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHR35]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP41:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR36:%.*]] = lshr<4 x i32> [[TMP41]],<i32 5, i32 5, i32 5, i32 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SHR36]],<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP42:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP43:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR37:%.*]] = ashr<2 x i64> [[TMP43]], [[TMP42]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHR37]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP44:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP45:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR38:%.*]] = ashr<2 x i64> [[TMP45]], [[TMP44]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHR38]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP46:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT39:%.*]] = insertelement<2 x i32> undef, i32 [[TMP46]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT40:%.*]] = shufflevector<2 x i32> [[SPLAT_SPLATINSERT39]],<2 x i32> undef,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP47:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[SH_PROM41:%.*]] = zext<2 x i32> [[SPLAT_SPLAT40]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[SHR42:%.*]] = ashr<2 x i64> [[TMP47]], [[SH_PROM41]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHR42]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP48:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR43:%.*]] = ashr<2 x i64> [[TMP48]],<i64 5, i64 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHR43]],<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP49:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP50:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR44:%.*]] = lshr<2 x i64> [[TMP50]], [[TMP49]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHR44]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP51:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP52:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR45:%.*]] = lshr<2 x i64> [[TMP52]], [[TMP51]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHR45]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP53:%.*]] = load volatile i32, i32* @cnt, align 4
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLATINSERT46:%.*]] = insertelement<2 x i32> undef, i32 [[TMP53]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[SPLAT_SPLAT47:%.*]] = shufflevector<2 x i32> [[SPLAT_SPLATINSERT46]],<2 x i32> undef,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP54:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[SH_PROM48:%.*]] = zext<2 x i32> [[SPLAT_SPLAT47]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[SHR49:%.*]] = lshr<2 x i64> [[TMP54]], [[SH_PROM48]]
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHR49]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP55:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[SHR50:%.*]] = lshr<2 x i64> [[TMP55]],<i64 5, i64 5>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SHR50]],<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_sr_assign
parameter_list|(
name|void
parameter_list|)
block|{
name|sc
operator|>>=
name|sc2
expr_stmt|;
name|sc
operator|>>=
name|uc2
expr_stmt|;
name|sc
operator|>>=
name|cnt
expr_stmt|;
name|sc
operator|>>=
literal|5
expr_stmt|;
name|uc
operator|>>=
name|sc2
expr_stmt|;
name|uc
operator|>>=
name|uc2
expr_stmt|;
name|uc
operator|>>=
name|cnt
expr_stmt|;
name|uc
operator|>>=
literal|5
expr_stmt|;
name|ss
operator|>>=
name|ss2
expr_stmt|;
name|ss
operator|>>=
name|us2
expr_stmt|;
name|ss
operator|>>=
name|cnt
expr_stmt|;
name|ss
operator|>>=
literal|5
expr_stmt|;
name|us
operator|>>=
name|ss2
expr_stmt|;
name|us
operator|>>=
name|us2
expr_stmt|;
name|us
operator|>>=
name|cnt
expr_stmt|;
name|us
operator|>>=
literal|5
expr_stmt|;
name|si
operator|>>=
name|si2
expr_stmt|;
name|si
operator|>>=
name|ui2
expr_stmt|;
name|si
operator|>>=
name|cnt
expr_stmt|;
name|si
operator|>>=
literal|5
expr_stmt|;
name|ui
operator|>>=
name|si2
expr_stmt|;
name|ui
operator|>>=
name|ui2
expr_stmt|;
name|ui
operator|>>=
name|cnt
expr_stmt|;
name|ui
operator|>>=
literal|5
expr_stmt|;
name|sl
operator|>>=
name|sl2
expr_stmt|;
name|sl
operator|>>=
name|ul2
expr_stmt|;
name|sl
operator|>>=
name|cnt
expr_stmt|;
name|sl
operator|>>=
literal|5
expr_stmt|;
name|ul
operator|>>=
name|sl2
expr_stmt|;
name|ul
operator|>>=
name|ul2
expr_stmt|;
name|ul
operator|>>=
name|cnt
expr_stmt|;
name|ul
operator|>>=
literal|5
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_cmpeq() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP:%.*]] = icmp eq<16 x i8> [[TMP0]], [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT:%.*]] = sext<16 x i1> [[CMP]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SEXT]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP1:%.*]] = icmp eq<16 x i8> [[TMP2]], [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT2:%.*]] = sext<16 x i1> [[CMP1]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SEXT2]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP3:%.*]] = icmp eq<16 x i8> [[TMP4]], [[TMP5]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT4:%.*]] = sext<16 x i1> [[CMP3]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SEXT4]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP5:%.*]] = icmp eq<16 x i8> [[TMP6]], [[TMP7]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT6:%.*]] = sext<16 x i1> [[CMP5]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SEXT6]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP7:%.*]] = icmp eq<16 x i8> [[TMP8]], [[TMP9]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT8:%.*]] = sext<16 x i1> [[CMP7]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SEXT8]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP9:%.*]] = icmp eq<16 x i8> [[TMP10]], [[TMP11]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT10:%.*]] = sext<16 x i1> [[CMP9]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SEXT10]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP12:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP13:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP11:%.*]] = icmp eq<16 x i8> [[TMP12]], [[TMP13]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT12:%.*]] = sext<16 x i1> [[CMP11]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SEXT12]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP14:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP15:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP13:%.*]] = icmp eq<8 x i16> [[TMP14]], [[TMP15]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT14:%.*]] = sext<8 x i1> [[CMP13]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SEXT14]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP16:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP17:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP15:%.*]] = icmp eq<8 x i16> [[TMP16]], [[TMP17]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT16:%.*]] = sext<8 x i1> [[CMP15]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SEXT16]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP18:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP19:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP17:%.*]] = icmp eq<8 x i16> [[TMP18]], [[TMP19]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT18:%.*]] = sext<8 x i1> [[CMP17]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SEXT18]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP20:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP21:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP19:%.*]] = icmp eq<8 x i16> [[TMP20]], [[TMP21]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT20:%.*]] = sext<8 x i1> [[CMP19]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SEXT20]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP22:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP23:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP21:%.*]] = icmp eq<8 x i16> [[TMP22]], [[TMP23]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT22:%.*]] = sext<8 x i1> [[CMP21]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SEXT22]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP24:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP25:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP23:%.*]] = icmp eq<8 x i16> [[TMP24]], [[TMP25]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT24:%.*]] = sext<8 x i1> [[CMP23]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SEXT24]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP26:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP27:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP25:%.*]] = icmp eq<8 x i16> [[TMP26]], [[TMP27]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT26:%.*]] = sext<8 x i1> [[CMP25]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SEXT26]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP28:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP29:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP27:%.*]] = icmp eq<4 x i32> [[TMP28]], [[TMP29]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT28:%.*]] = sext<4 x i1> [[CMP27]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SEXT28]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP30:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP31:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP29:%.*]] = icmp eq<4 x i32> [[TMP30]], [[TMP31]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT30:%.*]] = sext<4 x i1> [[CMP29]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SEXT30]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP32:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP33:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP31:%.*]] = icmp eq<4 x i32> [[TMP32]], [[TMP33]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT32:%.*]] = sext<4 x i1> [[CMP31]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SEXT32]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP34:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP35:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP33:%.*]] = icmp eq<4 x i32> [[TMP34]], [[TMP35]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT34:%.*]] = sext<4 x i1> [[CMP33]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SEXT34]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP36:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP37:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP35:%.*]] = icmp eq<4 x i32> [[TMP36]], [[TMP37]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT36:%.*]] = sext<4 x i1> [[CMP35]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SEXT36]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP38:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP39:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP37:%.*]] = icmp eq<4 x i32> [[TMP38]], [[TMP39]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT38:%.*]] = sext<4 x i1> [[CMP37]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SEXT38]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP40:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP41:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP39:%.*]] = icmp eq<4 x i32> [[TMP40]], [[TMP41]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT40:%.*]] = sext<4 x i1> [[CMP39]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SEXT40]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP42:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP43:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP41:%.*]] = icmp eq<2 x i64> [[TMP42]], [[TMP43]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT42:%.*]] = sext<2 x i1> [[CMP41]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT42]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP44:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP45:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP43:%.*]] = icmp eq<2 x i64> [[TMP44]], [[TMP45]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT44:%.*]] = sext<2 x i1> [[CMP43]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT44]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP46:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP47:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP45:%.*]] = icmp eq<2 x i64> [[TMP46]], [[TMP47]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT46:%.*]] = sext<2 x i1> [[CMP45]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT46]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP48:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP49:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP47:%.*]] = icmp eq<2 x i64> [[TMP48]], [[TMP49]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT48:%.*]] = sext<2 x i1> [[CMP47]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT48]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP50:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP51:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP49:%.*]] = icmp eq<2 x i64> [[TMP50]], [[TMP51]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT50:%.*]] = sext<2 x i1> [[CMP49]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT50]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP52:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP53:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP51:%.*]] = icmp eq<2 x i64> [[TMP52]], [[TMP53]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT52:%.*]] = sext<2 x i1> [[CMP51]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT52]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP54:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP55:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP53:%.*]] = icmp eq<2 x i64> [[TMP54]], [[TMP55]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT54:%.*]] = sext<2 x i1> [[CMP53]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT54]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP56:%.*]] = load volatile<2 x double>,<2 x double>* @fd, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP57:%.*]] = load volatile<2 x double>,<2 x double>* @fd2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP55:%.*]] = fcmp oeq<2 x double> [[TMP56]], [[TMP57]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT56:%.*]] = sext<2 x i1> [[CMP55]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT56]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_cmpeq
parameter_list|(
name|void
parameter_list|)
block|{
name|bc
operator|=
name|sc
operator|==
name|sc2
expr_stmt|;
name|bc
operator|=
name|sc
operator|==
name|bc2
expr_stmt|;
name|bc
operator|=
name|bc
operator|==
name|sc2
expr_stmt|;
name|bc
operator|=
name|uc
operator|==
name|uc2
expr_stmt|;
name|bc
operator|=
name|uc
operator|==
name|bc2
expr_stmt|;
name|bc
operator|=
name|bc
operator|==
name|uc2
expr_stmt|;
name|bc
operator|=
name|bc
operator|==
name|bc2
expr_stmt|;
name|bs
operator|=
name|ss
operator|==
name|ss2
expr_stmt|;
name|bs
operator|=
name|ss
operator|==
name|bs2
expr_stmt|;
name|bs
operator|=
name|bs
operator|==
name|ss2
expr_stmt|;
name|bs
operator|=
name|us
operator|==
name|us2
expr_stmt|;
name|bs
operator|=
name|us
operator|==
name|bs2
expr_stmt|;
name|bs
operator|=
name|bs
operator|==
name|us2
expr_stmt|;
name|bs
operator|=
name|bs
operator|==
name|bs2
expr_stmt|;
name|bi
operator|=
name|si
operator|==
name|si2
expr_stmt|;
name|bi
operator|=
name|si
operator|==
name|bi2
expr_stmt|;
name|bi
operator|=
name|bi
operator|==
name|si2
expr_stmt|;
name|bi
operator|=
name|ui
operator|==
name|ui2
expr_stmt|;
name|bi
operator|=
name|ui
operator|==
name|bi2
expr_stmt|;
name|bi
operator|=
name|bi
operator|==
name|ui2
expr_stmt|;
name|bi
operator|=
name|bi
operator|==
name|bi2
expr_stmt|;
name|bl
operator|=
name|sl
operator|==
name|sl2
expr_stmt|;
name|bl
operator|=
name|sl
operator|==
name|bl2
expr_stmt|;
name|bl
operator|=
name|bl
operator|==
name|sl2
expr_stmt|;
name|bl
operator|=
name|ul
operator|==
name|ul2
expr_stmt|;
name|bl
operator|=
name|ul
operator|==
name|bl2
expr_stmt|;
name|bl
operator|=
name|bl
operator|==
name|ul2
expr_stmt|;
name|bl
operator|=
name|bl
operator|==
name|bl2
expr_stmt|;
name|bl
operator|=
name|fd
operator|==
name|fd2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_cmpne() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP:%.*]] = icmp ne<16 x i8> [[TMP0]], [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT:%.*]] = sext<16 x i1> [[CMP]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SEXT]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP1:%.*]] = icmp ne<16 x i8> [[TMP2]], [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT2:%.*]] = sext<16 x i1> [[CMP1]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SEXT2]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP3:%.*]] = icmp ne<16 x i8> [[TMP4]], [[TMP5]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT4:%.*]] = sext<16 x i1> [[CMP3]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SEXT4]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP5:%.*]] = icmp ne<16 x i8> [[TMP6]], [[TMP7]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT6:%.*]] = sext<16 x i1> [[CMP5]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SEXT6]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP7:%.*]] = icmp ne<16 x i8> [[TMP8]], [[TMP9]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT8:%.*]] = sext<16 x i1> [[CMP7]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SEXT8]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP9:%.*]] = icmp ne<16 x i8> [[TMP10]], [[TMP11]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT10:%.*]] = sext<16 x i1> [[CMP9]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SEXT10]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP12:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP13:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP11:%.*]] = icmp ne<16 x i8> [[TMP12]], [[TMP13]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT12:%.*]] = sext<16 x i1> [[CMP11]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SEXT12]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP14:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP15:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP13:%.*]] = icmp ne<8 x i16> [[TMP14]], [[TMP15]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT14:%.*]] = sext<8 x i1> [[CMP13]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SEXT14]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP16:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP17:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP15:%.*]] = icmp ne<8 x i16> [[TMP16]], [[TMP17]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT16:%.*]] = sext<8 x i1> [[CMP15]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SEXT16]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP18:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP19:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP17:%.*]] = icmp ne<8 x i16> [[TMP18]], [[TMP19]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT18:%.*]] = sext<8 x i1> [[CMP17]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SEXT18]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP20:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP21:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP19:%.*]] = icmp ne<8 x i16> [[TMP20]], [[TMP21]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT20:%.*]] = sext<8 x i1> [[CMP19]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SEXT20]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP22:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP23:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP21:%.*]] = icmp ne<8 x i16> [[TMP22]], [[TMP23]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT22:%.*]] = sext<8 x i1> [[CMP21]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SEXT22]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP24:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP25:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP23:%.*]] = icmp ne<8 x i16> [[TMP24]], [[TMP25]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT24:%.*]] = sext<8 x i1> [[CMP23]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SEXT24]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP26:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP27:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP25:%.*]] = icmp ne<8 x i16> [[TMP26]], [[TMP27]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT26:%.*]] = sext<8 x i1> [[CMP25]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SEXT26]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP28:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP29:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP27:%.*]] = icmp ne<4 x i32> [[TMP28]], [[TMP29]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT28:%.*]] = sext<4 x i1> [[CMP27]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SEXT28]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP30:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP31:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP29:%.*]] = icmp ne<4 x i32> [[TMP30]], [[TMP31]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT30:%.*]] = sext<4 x i1> [[CMP29]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SEXT30]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP32:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP33:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP31:%.*]] = icmp ne<4 x i32> [[TMP32]], [[TMP33]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT32:%.*]] = sext<4 x i1> [[CMP31]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SEXT32]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP34:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP35:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP33:%.*]] = icmp ne<4 x i32> [[TMP34]], [[TMP35]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT34:%.*]] = sext<4 x i1> [[CMP33]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SEXT34]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP36:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP37:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP35:%.*]] = icmp ne<4 x i32> [[TMP36]], [[TMP37]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT36:%.*]] = sext<4 x i1> [[CMP35]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SEXT36]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP38:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP39:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP37:%.*]] = icmp ne<4 x i32> [[TMP38]], [[TMP39]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT38:%.*]] = sext<4 x i1> [[CMP37]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SEXT38]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP40:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP41:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP39:%.*]] = icmp ne<4 x i32> [[TMP40]], [[TMP41]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT40:%.*]] = sext<4 x i1> [[CMP39]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SEXT40]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP42:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP43:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP41:%.*]] = icmp ne<2 x i64> [[TMP42]], [[TMP43]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT42:%.*]] = sext<2 x i1> [[CMP41]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT42]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP44:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP45:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP43:%.*]] = icmp ne<2 x i64> [[TMP44]], [[TMP45]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT44:%.*]] = sext<2 x i1> [[CMP43]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT44]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP46:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP47:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP45:%.*]] = icmp ne<2 x i64> [[TMP46]], [[TMP47]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT46:%.*]] = sext<2 x i1> [[CMP45]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT46]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP48:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP49:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP47:%.*]] = icmp ne<2 x i64> [[TMP48]], [[TMP49]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT48:%.*]] = sext<2 x i1> [[CMP47]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT48]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP50:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP51:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP49:%.*]] = icmp ne<2 x i64> [[TMP50]], [[TMP51]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT50:%.*]] = sext<2 x i1> [[CMP49]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT50]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP52:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP53:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP51:%.*]] = icmp ne<2 x i64> [[TMP52]], [[TMP53]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT52:%.*]] = sext<2 x i1> [[CMP51]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT52]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP54:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP55:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP53:%.*]] = icmp ne<2 x i64> [[TMP54]], [[TMP55]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT54:%.*]] = sext<2 x i1> [[CMP53]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT54]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP56:%.*]] = load volatile<2 x double>,<2 x double>* @fd, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP57:%.*]] = load volatile<2 x double>,<2 x double>* @fd2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP55:%.*]] = fcmp une<2 x double> [[TMP56]], [[TMP57]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT56:%.*]] = sext<2 x i1> [[CMP55]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT56]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_cmpne
parameter_list|(
name|void
parameter_list|)
block|{
name|bc
operator|=
name|sc
operator|!=
name|sc2
expr_stmt|;
name|bc
operator|=
name|sc
operator|!=
name|bc2
expr_stmt|;
name|bc
operator|=
name|bc
operator|!=
name|sc2
expr_stmt|;
name|bc
operator|=
name|uc
operator|!=
name|uc2
expr_stmt|;
name|bc
operator|=
name|uc
operator|!=
name|bc2
expr_stmt|;
name|bc
operator|=
name|bc
operator|!=
name|uc2
expr_stmt|;
name|bc
operator|=
name|bc
operator|!=
name|bc2
expr_stmt|;
name|bs
operator|=
name|ss
operator|!=
name|ss2
expr_stmt|;
name|bs
operator|=
name|ss
operator|!=
name|bs2
expr_stmt|;
name|bs
operator|=
name|bs
operator|!=
name|ss2
expr_stmt|;
name|bs
operator|=
name|us
operator|!=
name|us2
expr_stmt|;
name|bs
operator|=
name|us
operator|!=
name|bs2
expr_stmt|;
name|bs
operator|=
name|bs
operator|!=
name|us2
expr_stmt|;
name|bs
operator|=
name|bs
operator|!=
name|bs2
expr_stmt|;
name|bi
operator|=
name|si
operator|!=
name|si2
expr_stmt|;
name|bi
operator|=
name|si
operator|!=
name|bi2
expr_stmt|;
name|bi
operator|=
name|bi
operator|!=
name|si2
expr_stmt|;
name|bi
operator|=
name|ui
operator|!=
name|ui2
expr_stmt|;
name|bi
operator|=
name|ui
operator|!=
name|bi2
expr_stmt|;
name|bi
operator|=
name|bi
operator|!=
name|ui2
expr_stmt|;
name|bi
operator|=
name|bi
operator|!=
name|bi2
expr_stmt|;
name|bl
operator|=
name|sl
operator|!=
name|sl2
expr_stmt|;
name|bl
operator|=
name|sl
operator|!=
name|bl2
expr_stmt|;
name|bl
operator|=
name|bl
operator|!=
name|sl2
expr_stmt|;
name|bl
operator|=
name|ul
operator|!=
name|ul2
expr_stmt|;
name|bl
operator|=
name|ul
operator|!=
name|bl2
expr_stmt|;
name|bl
operator|=
name|bl
operator|!=
name|ul2
expr_stmt|;
name|bl
operator|=
name|bl
operator|!=
name|bl2
expr_stmt|;
name|bl
operator|=
name|fd
operator|!=
name|fd2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_cmpge() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP:%.*]] = icmp sge<16 x i8> [[TMP0]], [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT:%.*]] = sext<16 x i1> [[CMP]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SEXT]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP1:%.*]] = icmp uge<16 x i8> [[TMP2]], [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT2:%.*]] = sext<16 x i1> [[CMP1]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SEXT2]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP3:%.*]] = icmp uge<16 x i8> [[TMP4]], [[TMP5]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT4:%.*]] = sext<16 x i1> [[CMP3]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SEXT4]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP5:%.*]] = icmp sge<8 x i16> [[TMP6]], [[TMP7]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT6:%.*]] = sext<8 x i1> [[CMP5]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SEXT6]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP7:%.*]] = icmp uge<8 x i16> [[TMP8]], [[TMP9]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT8:%.*]] = sext<8 x i1> [[CMP7]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SEXT8]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP9:%.*]] = icmp uge<8 x i16> [[TMP10]], [[TMP11]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT10:%.*]] = sext<8 x i1> [[CMP9]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SEXT10]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP12:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP13:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP11:%.*]] = icmp sge<4 x i32> [[TMP12]], [[TMP13]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT12:%.*]] = sext<4 x i1> [[CMP11]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SEXT12]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP14:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP15:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP13:%.*]] = icmp uge<4 x i32> [[TMP14]], [[TMP15]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT14:%.*]] = sext<4 x i1> [[CMP13]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SEXT14]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP16:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP17:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP15:%.*]] = icmp uge<4 x i32> [[TMP16]], [[TMP17]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT16:%.*]] = sext<4 x i1> [[CMP15]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SEXT16]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP18:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP19:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP17:%.*]] = icmp sge<2 x i64> [[TMP18]], [[TMP19]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT18:%.*]] = sext<2 x i1> [[CMP17]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT18]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP20:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP21:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP19:%.*]] = icmp uge<2 x i64> [[TMP20]], [[TMP21]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT20:%.*]] = sext<2 x i1> [[CMP19]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT20]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP22:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP23:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP21:%.*]] = icmp uge<2 x i64> [[TMP22]], [[TMP23]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT22:%.*]] = sext<2 x i1> [[CMP21]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT22]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP24:%.*]] = load volatile<2 x double>,<2 x double>* @fd, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP25:%.*]] = load volatile<2 x double>,<2 x double>* @fd2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP23:%.*]] = fcmp oge<2 x double> [[TMP24]], [[TMP25]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT24:%.*]] = sext<2 x i1> [[CMP23]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT24]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_cmpge
parameter_list|(
name|void
parameter_list|)
block|{
name|bc
operator|=
name|sc
operator|>=
name|sc2
expr_stmt|;
name|bc
operator|=
name|uc
operator|>=
name|uc2
expr_stmt|;
name|bc
operator|=
name|bc
operator|>=
name|bc2
expr_stmt|;
name|bs
operator|=
name|ss
operator|>=
name|ss2
expr_stmt|;
name|bs
operator|=
name|us
operator|>=
name|us2
expr_stmt|;
name|bs
operator|=
name|bs
operator|>=
name|bs2
expr_stmt|;
name|bi
operator|=
name|si
operator|>=
name|si2
expr_stmt|;
name|bi
operator|=
name|ui
operator|>=
name|ui2
expr_stmt|;
name|bi
operator|=
name|bi
operator|>=
name|bi2
expr_stmt|;
name|bl
operator|=
name|sl
operator|>=
name|sl2
expr_stmt|;
name|bl
operator|=
name|ul
operator|>=
name|ul2
expr_stmt|;
name|bl
operator|=
name|bl
operator|>=
name|bl2
expr_stmt|;
name|bl
operator|=
name|fd
operator|>=
name|fd2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_cmpgt() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP:%.*]] = icmp sgt<16 x i8> [[TMP0]], [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT:%.*]] = sext<16 x i1> [[CMP]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SEXT]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP1:%.*]] = icmp ugt<16 x i8> [[TMP2]], [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT2:%.*]] = sext<16 x i1> [[CMP1]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SEXT2]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP3:%.*]] = icmp ugt<16 x i8> [[TMP4]], [[TMP5]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT4:%.*]] = sext<16 x i1> [[CMP3]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SEXT4]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP5:%.*]] = icmp sgt<8 x i16> [[TMP6]], [[TMP7]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT6:%.*]] = sext<8 x i1> [[CMP5]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SEXT6]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP7:%.*]] = icmp ugt<8 x i16> [[TMP8]], [[TMP9]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT8:%.*]] = sext<8 x i1> [[CMP7]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SEXT8]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP9:%.*]] = icmp ugt<8 x i16> [[TMP10]], [[TMP11]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT10:%.*]] = sext<8 x i1> [[CMP9]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SEXT10]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP12:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP13:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP11:%.*]] = icmp sgt<4 x i32> [[TMP12]], [[TMP13]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT12:%.*]] = sext<4 x i1> [[CMP11]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SEXT12]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP14:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP15:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP13:%.*]] = icmp ugt<4 x i32> [[TMP14]], [[TMP15]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT14:%.*]] = sext<4 x i1> [[CMP13]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SEXT14]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP16:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP17:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP15:%.*]] = icmp ugt<4 x i32> [[TMP16]], [[TMP17]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT16:%.*]] = sext<4 x i1> [[CMP15]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SEXT16]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP18:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP19:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP17:%.*]] = icmp sgt<2 x i64> [[TMP18]], [[TMP19]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT18:%.*]] = sext<2 x i1> [[CMP17]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT18]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP20:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP21:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP19:%.*]] = icmp ugt<2 x i64> [[TMP20]], [[TMP21]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT20:%.*]] = sext<2 x i1> [[CMP19]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT20]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP22:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP23:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP21:%.*]] = icmp ugt<2 x i64> [[TMP22]], [[TMP23]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT22:%.*]] = sext<2 x i1> [[CMP21]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT22]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP24:%.*]] = load volatile<2 x double>,<2 x double>* @fd, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP25:%.*]] = load volatile<2 x double>,<2 x double>* @fd2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP23:%.*]] = fcmp ogt<2 x double> [[TMP24]], [[TMP25]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT24:%.*]] = sext<2 x i1> [[CMP23]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT24]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_cmpgt
parameter_list|(
name|void
parameter_list|)
block|{
name|bc
operator|=
name|sc
operator|>
name|sc2
expr_stmt|;
name|bc
operator|=
name|uc
operator|>
name|uc2
expr_stmt|;
name|bc
operator|=
name|bc
operator|>
name|bc2
expr_stmt|;
name|bs
operator|=
name|ss
operator|>
name|ss2
expr_stmt|;
name|bs
operator|=
name|us
operator|>
name|us2
expr_stmt|;
name|bs
operator|=
name|bs
operator|>
name|bs2
expr_stmt|;
name|bi
operator|=
name|si
operator|>
name|si2
expr_stmt|;
name|bi
operator|=
name|ui
operator|>
name|ui2
expr_stmt|;
name|bi
operator|=
name|bi
operator|>
name|bi2
expr_stmt|;
name|bl
operator|=
name|sl
operator|>
name|sl2
expr_stmt|;
name|bl
operator|=
name|ul
operator|>
name|ul2
expr_stmt|;
name|bl
operator|=
name|bl
operator|>
name|bl2
expr_stmt|;
name|bl
operator|=
name|fd
operator|>
name|fd2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_cmple() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP:%.*]] = icmp sle<16 x i8> [[TMP0]], [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT:%.*]] = sext<16 x i1> [[CMP]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SEXT]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP1:%.*]] = icmp ule<16 x i8> [[TMP2]], [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT2:%.*]] = sext<16 x i1> [[CMP1]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SEXT2]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP3:%.*]] = icmp ule<16 x i8> [[TMP4]], [[TMP5]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT4:%.*]] = sext<16 x i1> [[CMP3]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SEXT4]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP5:%.*]] = icmp sle<8 x i16> [[TMP6]], [[TMP7]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT6:%.*]] = sext<8 x i1> [[CMP5]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SEXT6]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP7:%.*]] = icmp ule<8 x i16> [[TMP8]], [[TMP9]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT8:%.*]] = sext<8 x i1> [[CMP7]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SEXT8]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP9:%.*]] = icmp ule<8 x i16> [[TMP10]], [[TMP11]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT10:%.*]] = sext<8 x i1> [[CMP9]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SEXT10]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP12:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP13:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP11:%.*]] = icmp sle<4 x i32> [[TMP12]], [[TMP13]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT12:%.*]] = sext<4 x i1> [[CMP11]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SEXT12]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP14:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP15:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP13:%.*]] = icmp ule<4 x i32> [[TMP14]], [[TMP15]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT14:%.*]] = sext<4 x i1> [[CMP13]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SEXT14]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP16:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP17:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP15:%.*]] = icmp ule<4 x i32> [[TMP16]], [[TMP17]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT16:%.*]] = sext<4 x i1> [[CMP15]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SEXT16]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP18:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP19:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP17:%.*]] = icmp sle<2 x i64> [[TMP18]], [[TMP19]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT18:%.*]] = sext<2 x i1> [[CMP17]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT18]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP20:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP21:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP19:%.*]] = icmp ule<2 x i64> [[TMP20]], [[TMP21]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT20:%.*]] = sext<2 x i1> [[CMP19]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT20]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP22:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP23:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP21:%.*]] = icmp ule<2 x i64> [[TMP22]], [[TMP23]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT22:%.*]] = sext<2 x i1> [[CMP21]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT22]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP24:%.*]] = load volatile<2 x double>,<2 x double>* @fd, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP25:%.*]] = load volatile<2 x double>,<2 x double>* @fd2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP23:%.*]] = fcmp ole<2 x double> [[TMP24]], [[TMP25]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT24:%.*]] = sext<2 x i1> [[CMP23]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT24]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_cmple
parameter_list|(
name|void
parameter_list|)
block|{
name|bc
operator|=
name|sc
operator|<=
name|sc2
expr_stmt|;
name|bc
operator|=
name|uc
operator|<=
name|uc2
expr_stmt|;
name|bc
operator|=
name|bc
operator|<=
name|bc2
expr_stmt|;
name|bs
operator|=
name|ss
operator|<=
name|ss2
expr_stmt|;
name|bs
operator|=
name|us
operator|<=
name|us2
expr_stmt|;
name|bs
operator|=
name|bs
operator|<=
name|bs2
expr_stmt|;
name|bi
operator|=
name|si
operator|<=
name|si2
expr_stmt|;
name|bi
operator|=
name|ui
operator|<=
name|ui2
expr_stmt|;
name|bi
operator|=
name|bi
operator|<=
name|bi2
expr_stmt|;
name|bl
operator|=
name|sl
operator|<=
name|sl2
expr_stmt|;
name|bl
operator|=
name|ul
operator|<=
name|ul2
expr_stmt|;
name|bl
operator|=
name|bl
operator|<=
name|bl2
expr_stmt|;
name|bl
operator|=
name|fd
operator|<=
name|fd2
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_cmplt() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load volatile<16 x i8>,<16 x i8>* @sc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP:%.*]] = icmp slt<16 x i8> [[TMP0]], [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT:%.*]] = sext<16 x i1> [[CMP]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SEXT]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load volatile<16 x i8>,<16 x i8>* @uc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP1:%.*]] = icmp ult<16 x i8> [[TMP2]], [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT2:%.*]] = sext<16 x i1> [[CMP1]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SEXT2]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load volatile<16 x i8>,<16 x i8>* @bc2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP3:%.*]] = icmp ult<16 x i8> [[TMP4]], [[TMP5]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT4:%.*]] = sext<16 x i1> [[CMP3]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   store volatile<16 x i8> [[SEXT4]],<16 x i8>* @bc, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load volatile<8 x i16>,<8 x i16>* @ss2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP5:%.*]] = icmp slt<8 x i16> [[TMP6]], [[TMP7]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT6:%.*]] = sext<8 x i1> [[CMP5]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SEXT6]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load volatile<8 x i16>,<8 x i16>* @us, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load volatile<8 x i16>,<8 x i16>* @us2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP7:%.*]] = icmp ult<8 x i16> [[TMP8]], [[TMP9]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT8:%.*]] = sext<8 x i1> [[CMP7]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SEXT8]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = load volatile<8 x i16>,<8 x i16>* @bs2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP9:%.*]] = icmp ult<8 x i16> [[TMP10]], [[TMP11]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT10:%.*]] = sext<8 x i1> [[CMP9]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   store volatile<8 x i16> [[SEXT10]],<8 x i16>* @bs, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP12:%.*]] = load volatile<4 x i32>,<4 x i32>* @si, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP13:%.*]] = load volatile<4 x i32>,<4 x i32>* @si2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP11:%.*]] = icmp slt<4 x i32> [[TMP12]], [[TMP13]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT12:%.*]] = sext<4 x i1> [[CMP11]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SEXT12]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP14:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP15:%.*]] = load volatile<4 x i32>,<4 x i32>* @ui2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP13:%.*]] = icmp ult<4 x i32> [[TMP14]], [[TMP15]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT14:%.*]] = sext<4 x i1> [[CMP13]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SEXT14]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP16:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP17:%.*]] = load volatile<4 x i32>,<4 x i32>* @bi2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP15:%.*]] = icmp ult<4 x i32> [[TMP16]], [[TMP17]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT16:%.*]] = sext<4 x i1> [[CMP15]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   store volatile<4 x i32> [[SEXT16]],<4 x i32>* @bi, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP18:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP19:%.*]] = load volatile<2 x i64>,<2 x i64>* @sl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP17:%.*]] = icmp slt<2 x i64> [[TMP18]], [[TMP19]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT18:%.*]] = sext<2 x i1> [[CMP17]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT18]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP20:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP21:%.*]] = load volatile<2 x i64>,<2 x i64>* @ul2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP19:%.*]] = icmp ult<2 x i64> [[TMP20]], [[TMP21]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT20:%.*]] = sext<2 x i1> [[CMP19]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT20]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP22:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP23:%.*]] = load volatile<2 x i64>,<2 x i64>* @bl2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP21:%.*]] = icmp ult<2 x i64> [[TMP22]], [[TMP23]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT22:%.*]] = sext<2 x i1> [[CMP21]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT22]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP24:%.*]] = load volatile<2 x double>,<2 x double>* @fd, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP25:%.*]] = load volatile<2 x double>,<2 x double>* @fd2, align 8
end_comment

begin_comment
comment|// CHECK:   [[CMP23:%.*]] = fcmp olt<2 x double> [[TMP24]], [[TMP25]]
end_comment

begin_comment
comment|// CHECK:   [[SEXT24:%.*]] = sext<2 x i1> [[CMP23]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store volatile<2 x i64> [[SEXT24]],<2 x i64>* @bl, align 8
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_cmplt
parameter_list|(
name|void
parameter_list|)
block|{
name|bc
operator|=
name|sc
operator|<
name|sc2
expr_stmt|;
name|bc
operator|=
name|uc
operator|<
name|uc2
expr_stmt|;
name|bc
operator|=
name|bc
operator|<
name|bc2
expr_stmt|;
name|bs
operator|=
name|ss
operator|<
name|ss2
expr_stmt|;
name|bs
operator|=
name|us
operator|<
name|us2
expr_stmt|;
name|bs
operator|=
name|bs
operator|<
name|bs2
expr_stmt|;
name|bi
operator|=
name|si
operator|<
name|si2
expr_stmt|;
name|bi
operator|=
name|ui
operator|<
name|ui2
expr_stmt|;
name|bi
operator|=
name|bi
operator|<
name|bi2
expr_stmt|;
name|bl
operator|=
name|sl
operator|<
name|sl2
expr_stmt|;
name|bl
operator|=
name|ul
operator|<
name|ul2
expr_stmt|;
name|bl
operator|=
name|bl
operator|<
name|bl2
expr_stmt|;
name|bl
operator|=
name|fd
operator|<
name|fd2
expr_stmt|;
block|}
end_function

end_unit

