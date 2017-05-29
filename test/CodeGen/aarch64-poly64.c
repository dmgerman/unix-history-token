begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-none-linux-gnu -target-feature +neon \
end_comment

begin_comment
comment|// RUN:  -ffp-contract=fast -disable-O0-optnone -emit-llvm -o - %s | opt -S -mem2reg \
end_comment

begin_comment
comment|// RUN:  | FileCheck %s
end_comment

begin_comment
comment|// Test new aarch64 intrinsics with poly64
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vceq_p64(<1 x i64> %a,<1 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[CMP_I:%.*]] = icmp eq<1 x i64> %a, %b
end_comment

begin_comment
comment|// CHECK:   [[SEXT_I:%.*]] = sext<1 x i1> [[CMP_I]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[SEXT_I]]
end_comment

begin_function
name|uint64x1_t
name|test_vceq_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|,
name|poly64x1_t
name|b
parameter_list|)
block|{
return|return
name|vceq_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vceqq_p64(<2 x i64> %a,<2 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[CMP_I:%.*]] = icmp eq<2 x i64> %a, %b
end_comment

begin_comment
comment|// CHECK:   [[SEXT_I:%.*]] = sext<2 x i1> [[CMP_I]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SEXT_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vceqq_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|)
block|{
return|return
name|vceqq_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vtst_p64(<1 x i64> %a,<1 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = and<1 x i64> %a, %b
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = icmp ne<1 x i64> [[TMP4]], zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VTST_I:%.*]] = sext<1 x i1> [[TMP5]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[VTST_I]]
end_comment

begin_function
name|uint64x1_t
name|test_vtst_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|,
name|poly64x1_t
name|b
parameter_list|)
block|{
return|return
name|vtst_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vtstq_p64(<2 x i64> %a,<2 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = and<2 x i64> %a, %b
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = icmp ne<2 x i64> [[TMP4]], zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VTST_I:%.*]] = sext<2 x i1> [[TMP5]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VTST_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vtstq_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|)
block|{
return|return
name|vtstq_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vbsl_p64(<1 x i64> %a,<1 x i64> %b,<1 x i64> %c) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VBSL3_I:%.*]] = and<1 x i64> %a, %b
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = xor<1 x i64> %a,<i64 -1>
end_comment

begin_comment
comment|// CHECK:   [[VBSL4_I:%.*]] = and<1 x i64> [[TMP3]], %c
end_comment

begin_comment
comment|// CHECK:   [[VBSL5_I:%.*]] = or<1 x i64> [[VBSL3_I]], [[VBSL4_I]]
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[VBSL5_I]]
end_comment

begin_function
name|poly64x1_t
name|test_vbsl_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|,
name|poly64x1_t
name|b
parameter_list|,
name|poly64x1_t
name|c
parameter_list|)
block|{
return|return
name|vbsl_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vbslq_p64(<2 x i64> %a,<2 x i64> %b,<2 x i64> %c) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VBSL3_I:%.*]] = and<2 x i64> %a, %b
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = xor<2 x i64> %a,<i64 -1, i64 -1>
end_comment

begin_comment
comment|// CHECK:   [[VBSL4_I:%.*]] = and<2 x i64> [[TMP3]], %c
end_comment

begin_comment
comment|// CHECK:   [[VBSL5_I:%.*]] = or<2 x i64> [[VBSL3_I]], [[VBSL4_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VBSL5_I]]
end_comment

begin_function
name|poly64x2_t
name|test_vbslq_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|,
name|poly64x2_t
name|c
parameter_list|)
block|{
return|return
name|vbslq_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_vget_lane_p64(<1 x i64> %v) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x i64> %v to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<1 x i64> [[TMP1]], i32 0
end_comment

begin_comment
comment|// CHECK:   ret i64 [[VGET_LANE]]
end_comment

begin_function
name|poly64_t
name|test_vget_lane_p64
parameter_list|(
name|poly64x1_t
name|v
parameter_list|)
block|{
return|return
name|vget_lane_p64
argument_list|(
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_vgetq_lane_p64(<2 x i64> %v) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %v to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<2 x i64> [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   ret i64 [[VGETQ_LANE]]
end_comment

begin_function
name|poly64_t
name|test_vgetq_lane_p64
parameter_list|(
name|poly64x2_t
name|v
parameter_list|)
block|{
return|return
name|vgetq_lane_p64
argument_list|(
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vset_lane_p64(i64 %a,<1 x i64> %v) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x i64> %v to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<1 x i64> [[TMP1]], i64 %a, i32 0
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[VSET_LANE]]
end_comment

begin_function
name|poly64x1_t
name|test_vset_lane_p64
parameter_list|(
name|poly64_t
name|a
parameter_list|,
name|poly64x1_t
name|v
parameter_list|)
block|{
return|return
name|vset_lane_p64
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vsetq_lane_p64(i64 %a,<2 x i64> %v) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %v to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<2 x i64> [[TMP1]], i64 %a, i32 1
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VSET_LANE]]
end_comment

begin_function
name|poly64x2_t
name|test_vsetq_lane_p64
parameter_list|(
name|poly64_t
name|a
parameter_list|,
name|poly64x2_t
name|v
parameter_list|)
block|{
return|return
name|vsetq_lane_p64
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vcopy_lane_p64(<1 x i64> %a,<1 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x i64> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<1 x i64> [[TMP1]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<1 x i64> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP2]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<1 x i64> [[TMP3]], i64 [[VGET_LANE]], i32 0
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[VSET_LANE]]
end_comment

begin_function
name|poly64x1_t
name|test_vcopy_lane_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|,
name|poly64x1_t
name|b
parameter_list|)
block|{
return|return
name|vcopy_lane_p64
argument_list|(
name|a
argument_list|,
literal|0
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vcopyq_lane_p64(<2 x i64> %a,<1 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x i64> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<1 x i64> [[TMP1]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP2]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<2 x i64> [[TMP3]], i64 [[VGET_LANE]], i32 1
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VSET_LANE]]
end_comment

begin_function
name|poly64x2_t
name|test_vcopyq_lane_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x1_t
name|b
parameter_list|)
block|{
return|return
name|vcopyq_lane_p64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vcopyq_laneq_p64(<2 x i64> %a,<2 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<2 x i64> [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP2]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<2 x i64> [[TMP3]], i64 [[VGETQ_LANE]], i32 1
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VSET_LANE]]
end_comment

begin_function
name|poly64x2_t
name|test_vcopyq_laneq_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|)
block|{
return|return
name|vcopyq_laneq_p64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vcreate_p64(i64 %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast i64 %a to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[TMP0]]
end_comment

begin_function
name|poly64x1_t
name|test_vcreate_p64
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
return|return
name|vcreate_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vdup_n_p64(i64 %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<1 x i64> undef, i64 %a, i32 0
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[VECINIT_I]]
end_comment

begin_function
name|poly64x1_t
name|test_vdup_n_p64
parameter_list|(
name|poly64_t
name|a
parameter_list|)
block|{
return|return
name|vdup_n_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vdupq_n_p64(i64 %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x i64> undef, i64 %a, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x i64> [[VECINIT_I]], i64 %a, i32 1
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VECINIT1_I]]
end_comment

begin_function
name|poly64x2_t
name|test_vdupq_n_p64
parameter_list|(
name|poly64_t
name|a
parameter_list|)
block|{
return|return
name|vdupq_n_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vmov_n_p64(i64 %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<1 x i64> undef, i64 %a, i32 0
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[VECINIT_I]]
end_comment

begin_function
name|poly64x1_t
name|test_vmov_n_p64
parameter_list|(
name|poly64_t
name|a
parameter_list|)
block|{
return|return
name|vmov_n_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vmovq_n_p64(i64 %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x i64> undef, i64 %a, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x i64> [[VECINIT_I]], i64 %a, i32 1
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VECINIT1_I]]
end_comment

begin_function
name|poly64x2_t
name|test_vmovq_n_p64
parameter_list|(
name|poly64_t
name|a
parameter_list|)
block|{
return|return
name|vmovq_n_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vdup_lane_p64(<1 x i64> %vec) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<1 x i64> %vec,<1 x i64> %vec,<1 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[SHUFFLE]]
end_comment

begin_function
name|poly64x1_t
name|test_vdup_lane_p64
parameter_list|(
name|poly64x1_t
name|vec
parameter_list|)
block|{
return|return
name|vdup_lane_p64
argument_list|(
name|vec
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vdupq_lane_p64(<1 x i64> %vec) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<1 x i64> %vec,<1 x i64> %vec,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SHUFFLE]]
end_comment

begin_function
name|poly64x2_t
name|test_vdupq_lane_p64
parameter_list|(
name|poly64x1_t
name|vec
parameter_list|)
block|{
return|return
name|vdupq_lane_p64
argument_list|(
name|vec
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vdupq_laneq_p64(<2 x i64> %vec) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i64> %vec,<2 x i64> %vec,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SHUFFLE]]
end_comment

begin_function
name|poly64x2_t
name|test_vdupq_laneq_p64
parameter_list|(
name|poly64x2_t
name|vec
parameter_list|)
block|{
return|return
name|vdupq_laneq_p64
argument_list|(
name|vec
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vcombine_p64(<1 x i64> %low,<1 x i64> %high) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<1 x i64> %low,<1 x i64> %high,<2 x i32><i32 0, i32 1>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SHUFFLE_I]]
end_comment

begin_function
name|poly64x2_t
name|test_vcombine_p64
parameter_list|(
name|poly64x1_t
name|low
parameter_list|,
name|poly64x1_t
name|high
parameter_list|)
block|{
return|return
name|vcombine_p64
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vld1_p64(i64* %ptr) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast i64* %ptr to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i8* [[TMP0]] to<1 x i64>*
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load<1 x i64>,<1 x i64>* [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[TMP2]]
end_comment

begin_function
name|poly64x1_t
name|test_vld1_p64
parameter_list|(
name|poly64_t
specifier|const
modifier|*
name|ptr
parameter_list|)
block|{
return|return
name|vld1_p64
argument_list|(
name|ptr
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vld1q_p64(i64* %ptr) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast i64* %ptr to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i8* [[TMP0]] to<2 x i64>*
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load<2 x i64>,<2 x i64>* [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[TMP2]]
end_comment

begin_function
name|poly64x2_t
name|test_vld1q_p64
parameter_list|(
name|poly64_t
specifier|const
modifier|*
name|ptr
parameter_list|)
block|{
return|return
name|vld1q_p64
argument_list|(
name|ptr
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_vst1_p64(i64* %ptr,<1 x i64> %val) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast i64* %ptr to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<1 x i64> %val to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast i8* [[TMP0]] to<1 x i64>*
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP1]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   store<1 x i64> [[TMP3]],<1 x i64>* [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_vst1_p64
parameter_list|(
name|poly64_t
modifier|*
name|ptr
parameter_list|,
name|poly64x1_t
name|val
parameter_list|)
block|{
return|return
name|vst1_p64
argument_list|(
name|ptr
argument_list|,
name|val
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_vst1q_p64(i64* %ptr,<2 x i64> %val) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast i64* %ptr to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i64> %val to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast i8* [[TMP0]] to<2 x i64>*
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP1]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   store<2 x i64> [[TMP3]],<2 x i64>* [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_vst1q_p64
parameter_list|(
name|poly64_t
modifier|*
name|ptr
parameter_list|,
name|poly64x2_t
name|val
parameter_list|)
block|{
return|return
name|vst1q_p64
argument_list|(
name|ptr
argument_list|,
name|val
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define %struct.poly64x1x2_t @test_vld2_p64(i64* %ptr) #0 {
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.poly64x1x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET:%.*]] = alloca %struct.poly64x1x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.poly64x1x2_t* [[__RET]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i64* %ptr to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast i8* [[TMP1]] to<1 x i64>*
end_comment

begin_comment
comment|// CHECK:   [[VLD2:%.*]] = call {<1 x i64>,<1 x i64> } @llvm.aarch64.neon.ld2.v1i64.p0v1i64(<1 x i64>* [[TMP2]])
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to {<1 x i64>,<1 x i64> }*
end_comment

begin_comment
comment|// CHECK:   store {<1 x i64>,<1 x i64> } [[VLD2]], {<1 x i64>,<1 x i64> }* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast %struct.poly64x1x2_t* [[RETVAL]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.poly64x1x2_t* [[__RET]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP4]], i8* [[TMP5]], i64 16, i32 8, i1 false)
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load %struct.poly64x1x2_t, %struct.poly64x1x2_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.poly64x1x2_t [[TMP6]]
end_comment

begin_function
name|poly64x1x2_t
name|test_vld2_p64
parameter_list|(
name|poly64_t
specifier|const
modifier|*
name|ptr
parameter_list|)
block|{
return|return
name|vld2_p64
argument_list|(
name|ptr
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define %struct.poly64x2x2_t @test_vld2q_p64(i64* %ptr) #0 {
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.poly64x2x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET:%.*]] = alloca %struct.poly64x2x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.poly64x2x2_t* [[__RET]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i64* %ptr to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast i8* [[TMP1]] to<2 x i64>*
end_comment

begin_comment
comment|// CHECK:   [[VLD2:%.*]] = call {<2 x i64>,<2 x i64> } @llvm.aarch64.neon.ld2.v2i64.p0v2i64(<2 x i64>* [[TMP2]])
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to {<2 x i64>,<2 x i64> }*
end_comment

begin_comment
comment|// CHECK:   store {<2 x i64>,<2 x i64> } [[VLD2]], {<2 x i64>,<2 x i64> }* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast %struct.poly64x2x2_t* [[RETVAL]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.poly64x2x2_t* [[__RET]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP4]], i8* [[TMP5]], i64 32, i32 16, i1 false)
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load %struct.poly64x2x2_t, %struct.poly64x2x2_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.poly64x2x2_t [[TMP6]]
end_comment

begin_function
name|poly64x2x2_t
name|test_vld2q_p64
parameter_list|(
name|poly64_t
specifier|const
modifier|*
name|ptr
parameter_list|)
block|{
return|return
name|vld2q_p64
argument_list|(
name|ptr
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define %struct.poly64x1x3_t @test_vld3_p64(i64* %ptr) #0 {
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.poly64x1x3_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET:%.*]] = alloca %struct.poly64x1x3_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.poly64x1x3_t* [[__RET]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i64* %ptr to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast i8* [[TMP1]] to<1 x i64>*
end_comment

begin_comment
comment|// CHECK:   [[VLD3:%.*]] = call {<1 x i64>,<1 x i64>,<1 x i64> } @llvm.aarch64.neon.ld3.v1i64.p0v1i64(<1 x i64>* [[TMP2]])
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to {<1 x i64>,<1 x i64>,<1 x i64> }*
end_comment

begin_comment
comment|// CHECK:   store {<1 x i64>,<1 x i64>,<1 x i64> } [[VLD3]], {<1 x i64>,<1 x i64>,<1 x i64> }* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast %struct.poly64x1x3_t* [[RETVAL]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.poly64x1x3_t* [[__RET]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP4]], i8* [[TMP5]], i64 24, i32 8, i1 false)
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load %struct.poly64x1x3_t, %struct.poly64x1x3_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.poly64x1x3_t [[TMP6]]
end_comment

begin_function
name|poly64x1x3_t
name|test_vld3_p64
parameter_list|(
name|poly64_t
specifier|const
modifier|*
name|ptr
parameter_list|)
block|{
return|return
name|vld3_p64
argument_list|(
name|ptr
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define %struct.poly64x2x3_t @test_vld3q_p64(i64* %ptr) #0 {
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.poly64x2x3_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET:%.*]] = alloca %struct.poly64x2x3_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.poly64x2x3_t* [[__RET]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i64* %ptr to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast i8* [[TMP1]] to<2 x i64>*
end_comment

begin_comment
comment|// CHECK:   [[VLD3:%.*]] = call {<2 x i64>,<2 x i64>,<2 x i64> } @llvm.aarch64.neon.ld3.v2i64.p0v2i64(<2 x i64>* [[TMP2]])
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to {<2 x i64>,<2 x i64>,<2 x i64> }*
end_comment

begin_comment
comment|// CHECK:   store {<2 x i64>,<2 x i64>,<2 x i64> } [[VLD3]], {<2 x i64>,<2 x i64>,<2 x i64> }* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast %struct.poly64x2x3_t* [[RETVAL]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.poly64x2x3_t* [[__RET]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP4]], i8* [[TMP5]], i64 48, i32 16, i1 false)
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load %struct.poly64x2x3_t, %struct.poly64x2x3_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.poly64x2x3_t [[TMP6]]
end_comment

begin_function
name|poly64x2x3_t
name|test_vld3q_p64
parameter_list|(
name|poly64_t
specifier|const
modifier|*
name|ptr
parameter_list|)
block|{
return|return
name|vld3q_p64
argument_list|(
name|ptr
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define %struct.poly64x1x4_t @test_vld4_p64(i64* %ptr) #0 {
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.poly64x1x4_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET:%.*]] = alloca %struct.poly64x1x4_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.poly64x1x4_t* [[__RET]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i64* %ptr to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast i8* [[TMP1]] to<1 x i64>*
end_comment

begin_comment
comment|// CHECK:   [[VLD4:%.*]] = call {<1 x i64>,<1 x i64>,<1 x i64>,<1 x i64> } @llvm.aarch64.neon.ld4.v1i64.p0v1i64(<1 x i64>* [[TMP2]])
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to {<1 x i64>,<1 x i64>,<1 x i64>,<1 x i64> }*
end_comment

begin_comment
comment|// CHECK:   store {<1 x i64>,<1 x i64>,<1 x i64>,<1 x i64> } [[VLD4]], {<1 x i64>,<1 x i64>,<1 x i64>,<1 x i64> }* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast %struct.poly64x1x4_t* [[RETVAL]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.poly64x1x4_t* [[__RET]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP4]], i8* [[TMP5]], i64 32, i32 8, i1 false)
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load %struct.poly64x1x4_t, %struct.poly64x1x4_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.poly64x1x4_t [[TMP6]]
end_comment

begin_function
name|poly64x1x4_t
name|test_vld4_p64
parameter_list|(
name|poly64_t
specifier|const
modifier|*
name|ptr
parameter_list|)
block|{
return|return
name|vld4_p64
argument_list|(
name|ptr
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define %struct.poly64x2x4_t @test_vld4q_p64(i64* %ptr) #0 {
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.poly64x2x4_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET:%.*]] = alloca %struct.poly64x2x4_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.poly64x2x4_t* [[__RET]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i64* %ptr to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast i8* [[TMP1]] to<2 x i64>*
end_comment

begin_comment
comment|// CHECK:   [[VLD4:%.*]] = call {<2 x i64>,<2 x i64>,<2 x i64>,<2 x i64> } @llvm.aarch64.neon.ld4.v2i64.p0v2i64(<2 x i64>* [[TMP2]])
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to {<2 x i64>,<2 x i64>,<2 x i64>,<2 x i64> }*
end_comment

begin_comment
comment|// CHECK:   store {<2 x i64>,<2 x i64>,<2 x i64>,<2 x i64> } [[VLD4]], {<2 x i64>,<2 x i64>,<2 x i64>,<2 x i64> }* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast %struct.poly64x2x4_t* [[RETVAL]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.poly64x2x4_t* [[__RET]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP4]], i8* [[TMP5]], i64 64, i32 16, i1 false)
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = load %struct.poly64x2x4_t, %struct.poly64x2x4_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.poly64x2x4_t [[TMP6]]
end_comment

begin_function
name|poly64x2x4_t
name|test_vld4q_p64
parameter_list|(
name|poly64_t
specifier|const
modifier|*
name|ptr
parameter_list|)
block|{
return|return
name|vld4q_p64
argument_list|(
name|ptr
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_vst2_p64(i64* %ptr, [2 x<1 x i64>] %val.coerce) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VAL:%.*]] = alloca %struct.poly64x1x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__S1:%.*]] = alloca %struct.poly64x1x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly64x1x2_t, %struct.poly64x1x2_t* [[VAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<1 x i64>] [[VAL]].coerce, [2 x<1 x i64>]* [[COERCE_DIVE]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.poly64x1x2_t* [[__S1]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast %struct.poly64x1x2_t* [[VAL]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP0]], i8* [[TMP1]], i64 16, i32 8, i1 false)
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast i64* %ptr to i8*
end_comment

begin_comment
comment|// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly64x1x2_t, %struct.poly64x1x2_t* [[__S1]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x<1 x i64>], [2 x<1 x i64>]* [[VAL1]], i64 0, i64 0
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load<1 x i64>,<1 x i64>* [[ARRAYIDX]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast<1 x i64> [[TMP3]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VAL2:%.*]] = getelementptr inbounds %struct.poly64x1x2_t, %struct.poly64x1x2_t* [[__S1]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[ARRAYIDX3:%.*]] = getelementptr inbounds [2 x<1 x i64>], [2 x<1 x i64>]* [[VAL2]], i64 0, i64 1
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load<1 x i64>,<1 x i64>* [[ARRAYIDX3]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast<1 x i64> [[TMP5]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = bitcast<8 x i8> [[TMP4]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = bitcast<8 x i8> [[TMP6]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   call void @llvm.aarch64.neon.st2.v1i64.p0i8(<1 x i64> [[TMP7]],<1 x i64> [[TMP8]], i8* [[TMP2]])
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_vst2_p64
parameter_list|(
name|poly64_t
modifier|*
name|ptr
parameter_list|,
name|poly64x1x2_t
name|val
parameter_list|)
block|{
return|return
name|vst2_p64
argument_list|(
name|ptr
argument_list|,
name|val
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_vst2q_p64(i64* %ptr, [2 x<2 x i64>] %val.coerce) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VAL:%.*]] = alloca %struct.poly64x2x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__S1:%.*]] = alloca %struct.poly64x2x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly64x2x2_t, %struct.poly64x2x2_t* [[VAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<2 x i64>] [[VAL]].coerce, [2 x<2 x i64>]* [[COERCE_DIVE]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.poly64x2x2_t* [[__S1]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast %struct.poly64x2x2_t* [[VAL]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP0]], i8* [[TMP1]], i64 32, i32 16, i1 false)
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast i64* %ptr to i8*
end_comment

begin_comment
comment|// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly64x2x2_t, %struct.poly64x2x2_t* [[__S1]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [2 x<2 x i64>], [2 x<2 x i64>]* [[VAL1]], i64 0, i64 0
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load<2 x i64>,<2 x i64>* [[ARRAYIDX]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast<2 x i64> [[TMP3]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VAL2:%.*]] = getelementptr inbounds %struct.poly64x2x2_t, %struct.poly64x2x2_t* [[__S1]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[ARRAYIDX3:%.*]] = getelementptr inbounds [2 x<2 x i64>], [2 x<2 x i64>]* [[VAL2]], i64 0, i64 1
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load<2 x i64>,<2 x i64>* [[ARRAYIDX3]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast<2 x i64> [[TMP5]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = bitcast<16 x i8> [[TMP4]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = bitcast<16 x i8> [[TMP6]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   call void @llvm.aarch64.neon.st2.v2i64.p0i8(<2 x i64> [[TMP7]],<2 x i64> [[TMP8]], i8* [[TMP2]])
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_vst2q_p64
parameter_list|(
name|poly64_t
modifier|*
name|ptr
parameter_list|,
name|poly64x2x2_t
name|val
parameter_list|)
block|{
return|return
name|vst2q_p64
argument_list|(
name|ptr
argument_list|,
name|val
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_vst3_p64(i64* %ptr, [3 x<1 x i64>] %val.coerce) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VAL:%.*]] = alloca %struct.poly64x1x3_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__S1:%.*]] = alloca %struct.poly64x1x3_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly64x1x3_t, %struct.poly64x1x3_t* [[VAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   store [3 x<1 x i64>] [[VAL]].coerce, [3 x<1 x i64>]* [[COERCE_DIVE]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.poly64x1x3_t* [[__S1]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast %struct.poly64x1x3_t* [[VAL]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP0]], i8* [[TMP1]], i64 24, i32 8, i1 false)
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast i64* %ptr to i8*
end_comment

begin_comment
comment|// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly64x1x3_t, %struct.poly64x1x3_t* [[__S1]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x<1 x i64>], [3 x<1 x i64>]* [[VAL1]], i64 0, i64 0
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load<1 x i64>,<1 x i64>* [[ARRAYIDX]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast<1 x i64> [[TMP3]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VAL2:%.*]] = getelementptr inbounds %struct.poly64x1x3_t, %struct.poly64x1x3_t* [[__S1]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[ARRAYIDX3:%.*]] = getelementptr inbounds [3 x<1 x i64>], [3 x<1 x i64>]* [[VAL2]], i64 0, i64 1
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load<1 x i64>,<1 x i64>* [[ARRAYIDX3]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast<1 x i64> [[TMP5]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VAL4:%.*]] = getelementptr inbounds %struct.poly64x1x3_t, %struct.poly64x1x3_t* [[__S1]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[ARRAYIDX5:%.*]] = getelementptr inbounds [3 x<1 x i64>], [3 x<1 x i64>]* [[VAL4]], i64 0, i64 2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load<1 x i64>,<1 x i64>* [[ARRAYIDX5]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = bitcast<1 x i64> [[TMP7]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = bitcast<8 x i8> [[TMP4]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = bitcast<8 x i8> [[TMP6]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = bitcast<8 x i8> [[TMP8]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   call void @llvm.aarch64.neon.st3.v1i64.p0i8(<1 x i64> [[TMP9]],<1 x i64> [[TMP10]],<1 x i64> [[TMP11]], i8* [[TMP2]])
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_vst3_p64
parameter_list|(
name|poly64_t
modifier|*
name|ptr
parameter_list|,
name|poly64x1x3_t
name|val
parameter_list|)
block|{
return|return
name|vst3_p64
argument_list|(
name|ptr
argument_list|,
name|val
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_vst3q_p64(i64* %ptr, [3 x<2 x i64>] %val.coerce) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VAL:%.*]] = alloca %struct.poly64x2x3_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__S1:%.*]] = alloca %struct.poly64x2x3_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly64x2x3_t, %struct.poly64x2x3_t* [[VAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   store [3 x<2 x i64>] [[VAL]].coerce, [3 x<2 x i64>]* [[COERCE_DIVE]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.poly64x2x3_t* [[__S1]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast %struct.poly64x2x3_t* [[VAL]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP0]], i8* [[TMP1]], i64 48, i32 16, i1 false)
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast i64* %ptr to i8*
end_comment

begin_comment
comment|// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly64x2x3_t, %struct.poly64x2x3_t* [[__S1]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [3 x<2 x i64>], [3 x<2 x i64>]* [[VAL1]], i64 0, i64 0
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load<2 x i64>,<2 x i64>* [[ARRAYIDX]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast<2 x i64> [[TMP3]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VAL2:%.*]] = getelementptr inbounds %struct.poly64x2x3_t, %struct.poly64x2x3_t* [[__S1]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[ARRAYIDX3:%.*]] = getelementptr inbounds [3 x<2 x i64>], [3 x<2 x i64>]* [[VAL2]], i64 0, i64 1
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load<2 x i64>,<2 x i64>* [[ARRAYIDX3]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast<2 x i64> [[TMP5]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VAL4:%.*]] = getelementptr inbounds %struct.poly64x2x3_t, %struct.poly64x2x3_t* [[__S1]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[ARRAYIDX5:%.*]] = getelementptr inbounds [3 x<2 x i64>], [3 x<2 x i64>]* [[VAL4]], i64 0, i64 2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load<2 x i64>,<2 x i64>* [[ARRAYIDX5]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = bitcast<2 x i64> [[TMP7]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = bitcast<16 x i8> [[TMP4]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = bitcast<16 x i8> [[TMP6]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = bitcast<16 x i8> [[TMP8]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   call void @llvm.aarch64.neon.st3.v2i64.p0i8(<2 x i64> [[TMP9]],<2 x i64> [[TMP10]],<2 x i64> [[TMP11]], i8* [[TMP2]])
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_vst3q_p64
parameter_list|(
name|poly64_t
modifier|*
name|ptr
parameter_list|,
name|poly64x2x3_t
name|val
parameter_list|)
block|{
return|return
name|vst3q_p64
argument_list|(
name|ptr
argument_list|,
name|val
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_vst4_p64(i64* %ptr, [4 x<1 x i64>] %val.coerce) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VAL:%.*]] = alloca %struct.poly64x1x4_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__S1:%.*]] = alloca %struct.poly64x1x4_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly64x1x4_t, %struct.poly64x1x4_t* [[VAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   store [4 x<1 x i64>] [[VAL]].coerce, [4 x<1 x i64>]* [[COERCE_DIVE]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.poly64x1x4_t* [[__S1]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast %struct.poly64x1x4_t* [[VAL]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP0]], i8* [[TMP1]], i64 32, i32 8, i1 false)
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast i64* %ptr to i8*
end_comment

begin_comment
comment|// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly64x1x4_t, %struct.poly64x1x4_t* [[__S1]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x<1 x i64>], [4 x<1 x i64>]* [[VAL1]], i64 0, i64 0
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load<1 x i64>,<1 x i64>* [[ARRAYIDX]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast<1 x i64> [[TMP3]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VAL2:%.*]] = getelementptr inbounds %struct.poly64x1x4_t, %struct.poly64x1x4_t* [[__S1]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[ARRAYIDX3:%.*]] = getelementptr inbounds [4 x<1 x i64>], [4 x<1 x i64>]* [[VAL2]], i64 0, i64 1
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load<1 x i64>,<1 x i64>* [[ARRAYIDX3]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast<1 x i64> [[TMP5]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VAL4:%.*]] = getelementptr inbounds %struct.poly64x1x4_t, %struct.poly64x1x4_t* [[__S1]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[ARRAYIDX5:%.*]] = getelementptr inbounds [4 x<1 x i64>], [4 x<1 x i64>]* [[VAL4]], i64 0, i64 2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load<1 x i64>,<1 x i64>* [[ARRAYIDX5]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = bitcast<1 x i64> [[TMP7]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VAL6:%.*]] = getelementptr inbounds %struct.poly64x1x4_t, %struct.poly64x1x4_t* [[__S1]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[ARRAYIDX7:%.*]] = getelementptr inbounds [4 x<1 x i64>], [4 x<1 x i64>]* [[VAL6]], i64 0, i64 3
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load<1 x i64>,<1 x i64>* [[ARRAYIDX7]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = bitcast<1 x i64> [[TMP9]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = bitcast<8 x i8> [[TMP4]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   [[TMP12:%.*]] = bitcast<8 x i8> [[TMP6]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   [[TMP13:%.*]] = bitcast<8 x i8> [[TMP8]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   [[TMP14:%.*]] = bitcast<8 x i8> [[TMP10]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   call void @llvm.aarch64.neon.st4.v1i64.p0i8(<1 x i64> [[TMP11]],<1 x i64> [[TMP12]],<1 x i64> [[TMP13]],<1 x i64> [[TMP14]], i8* [[TMP2]])
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_vst4_p64
parameter_list|(
name|poly64_t
modifier|*
name|ptr
parameter_list|,
name|poly64x1x4_t
name|val
parameter_list|)
block|{
return|return
name|vst4_p64
argument_list|(
name|ptr
argument_list|,
name|val
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_vst4q_p64(i64* %ptr, [4 x<2 x i64>] %val.coerce) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VAL:%.*]] = alloca %struct.poly64x2x4_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__S1:%.*]] = alloca %struct.poly64x2x4_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[COERCE_DIVE:%.*]] = getelementptr inbounds %struct.poly64x2x4_t, %struct.poly64x2x4_t* [[VAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   store [4 x<2 x i64>] [[VAL]].coerce, [4 x<2 x i64>]* [[COERCE_DIVE]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.poly64x2x4_t* [[__S1]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast %struct.poly64x2x4_t* [[VAL]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP0]], i8* [[TMP1]], i64 64, i32 16, i1 false)
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast i64* %ptr to i8*
end_comment

begin_comment
comment|// CHECK:   [[VAL1:%.*]] = getelementptr inbounds %struct.poly64x2x4_t, %struct.poly64x2x4_t* [[__S1]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[ARRAYIDX:%.*]] = getelementptr inbounds [4 x<2 x i64>], [4 x<2 x i64>]* [[VAL1]], i64 0, i64 0
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = load<2 x i64>,<2 x i64>* [[ARRAYIDX]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast<2 x i64> [[TMP3]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VAL2:%.*]] = getelementptr inbounds %struct.poly64x2x4_t, %struct.poly64x2x4_t* [[__S1]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[ARRAYIDX3:%.*]] = getelementptr inbounds [4 x<2 x i64>], [4 x<2 x i64>]* [[VAL2]], i64 0, i64 1
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load<2 x i64>,<2 x i64>* [[ARRAYIDX3]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast<2 x i64> [[TMP5]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VAL4:%.*]] = getelementptr inbounds %struct.poly64x2x4_t, %struct.poly64x2x4_t* [[__S1]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[ARRAYIDX5:%.*]] = getelementptr inbounds [4 x<2 x i64>], [4 x<2 x i64>]* [[VAL4]], i64 0, i64 2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load<2 x i64>,<2 x i64>* [[ARRAYIDX5]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = bitcast<2 x i64> [[TMP7]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VAL6:%.*]] = getelementptr inbounds %struct.poly64x2x4_t, %struct.poly64x2x4_t* [[__S1]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[ARRAYIDX7:%.*]] = getelementptr inbounds [4 x<2 x i64>], [4 x<2 x i64>]* [[VAL6]], i64 0, i64 3
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = load<2 x i64>,<2 x i64>* [[ARRAYIDX7]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = bitcast<2 x i64> [[TMP9]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP11:%.*]] = bitcast<16 x i8> [[TMP4]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[TMP12:%.*]] = bitcast<16 x i8> [[TMP6]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[TMP13:%.*]] = bitcast<16 x i8> [[TMP8]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[TMP14:%.*]] = bitcast<16 x i8> [[TMP10]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   call void @llvm.aarch64.neon.st4.v2i64.p0i8(<2 x i64> [[TMP11]],<2 x i64> [[TMP12]],<2 x i64> [[TMP13]],<2 x i64> [[TMP14]], i8* [[TMP2]])
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_vst4q_p64
parameter_list|(
name|poly64_t
modifier|*
name|ptr
parameter_list|,
name|poly64x2x4_t
name|val
parameter_list|)
block|{
return|return
name|vst4q_p64
argument_list|(
name|ptr
argument_list|,
name|val
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vext_p64(<1 x i64> %a,<1 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x i64> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<1 x i64> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<8 x i8> [[TMP0]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP1]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VEXT:%.*]] = shufflevector<1 x i64> [[TMP2]],<1 x i64> [[TMP3]],<1 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[VEXT]]
end_comment

begin_function
name|poly64x1_t
name|test_vext_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|,
name|poly64x1_t
name|b
parameter_list|)
block|{
return|return
name|vext_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vextq_p64(<2 x i64> %a,<2 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i64> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<16 x i8> [[TMP0]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP1]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VEXT:%.*]] = shufflevector<2 x i64> [[TMP2]],<2 x i64> [[TMP3]],<2 x i32><i32 1, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VEXT]]
end_comment

begin_function
name|poly64x2_t
name|test_vextq_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|)
block|{
return|return
name|vextq_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vzip1q_p64(<2 x i64> %a,<2 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i64> %a,<2 x i64> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SHUFFLE_I]]
end_comment

begin_function
name|poly64x2_t
name|test_vzip1q_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|)
block|{
return|return
name|vzip1q_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vzip2q_p64(<2 x i64> %a,<2 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i64> %a,<2 x i64> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SHUFFLE_I]]
end_comment

begin_function
name|poly64x2_t
name|test_vzip2q_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|)
block|{
return|return
name|vzip2q_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vuzp1q_p64(<2 x i64> %a,<2 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i64> %a,<2 x i64> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SHUFFLE_I]]
end_comment

begin_function
name|poly64x2_t
name|test_vuzp1q_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|)
block|{
return|return
name|vuzp1q_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vuzp2q_p64(<2 x i64> %a,<2 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i64> %a,<2 x i64> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SHUFFLE_I]]
end_comment

begin_function
name|poly64x2_t
name|test_vuzp2q_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|)
block|{
return|return
name|vuzp2q_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vtrn1q_p64(<2 x i64> %a,<2 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i64> %a,<2 x i64> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SHUFFLE_I]]
end_comment

begin_function
name|poly64x2_t
name|test_vtrn1q_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|)
block|{
return|return
name|vtrn1q_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vtrn2q_p64(<2 x i64> %a,<2 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i64> %a,<2 x i64> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SHUFFLE_I]]
end_comment

begin_function
name|poly64x2_t
name|test_vtrn2q_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|)
block|{
return|return
name|vtrn2q_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vsri_n_p64(<1 x i64> %a,<1 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x i64> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<1 x i64> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VSRI_N:%.*]] = bitcast<8 x i8> [[TMP0]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VSRI_N1:%.*]] = bitcast<8 x i8> [[TMP1]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VSRI_N2:%.*]] = call<1 x i64> @llvm.aarch64.neon.vsri.v1i64(<1 x i64> [[VSRI_N]],<1 x i64> [[VSRI_N1]], i32 33)
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[VSRI_N2]]
end_comment

begin_function
name|poly64x1_t
name|test_vsri_n_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|,
name|poly64x1_t
name|b
parameter_list|)
block|{
return|return
name|vsri_n_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|33
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vsriq_n_p64(<2 x i64> %a,<2 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i64> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VSRI_N:%.*]] = bitcast<16 x i8> [[TMP0]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VSRI_N1:%.*]] = bitcast<16 x i8> [[TMP1]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VSRI_N2:%.*]] = call<2 x i64> @llvm.aarch64.neon.vsri.v2i64(<2 x i64> [[VSRI_N]],<2 x i64> [[VSRI_N1]], i32 64)
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VSRI_N2]]
end_comment

begin_function
name|poly64x2_t
name|test_vsriq_n_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|)
block|{
return|return
name|vsriq_n_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|64
argument_list|)
return|;
block|}
end_function

end_unit

