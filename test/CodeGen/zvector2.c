begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple s390x-linux-gnu -target-cpu z14 -fzvector \
end_comment

begin_comment
comment|// RUN:  -O -emit-llvm -o - -W -Wall -Werror %s | FileCheck %s
end_comment

begin_decl_stmt
specifier|volatile
name|vector
name|float
name|ff
decl_stmt|,
name|ff2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|vector
name|bool
name|int
name|bi
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
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff2
comment|// CHECK: store volatile<4 x float> [[VAL]],<4 x float>* @ff
name|ff
operator|=
name|ff2
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
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff2
comment|// CHECK: store volatile<4 x float> [[VAL]],<4 x float>* @ff
name|ff
operator|=
operator|+
name|ff2
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
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff2
comment|// CHECK: %{{.*}} = fsub<4 x float><float -0.000000e+00, float -0.000000e+00, float -0.000000e+00, float -0.000000e+00>, [[VAL]]
name|ff
operator|=
operator|-
name|ff2
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
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff2
comment|// CHECK: %{{.*}} = fadd<4 x float> [[VAL]],<float 1.000000e+00, float 1.000000e+00, float 1.000000e+00, float 1.000000e+00>
operator|++
name|ff2
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
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff2
comment|// CHECK: %{{.*}} = fadd<4 x float> [[VAL]],<float 1.000000e+00, float 1.000000e+00, float 1.000000e+00, float 1.000000e+00>
name|ff2
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
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff2
comment|// CHECK: %{{.*}} = fadd<4 x float> [[VAL]],<float -1.000000e+00, float -1.000000e+00, float -1.000000e+00, float -1.000000e+00>
operator|--
name|ff2
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
comment|// CHECK: [[VAL:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff2
comment|// CHECK: %{{.*}} = fadd<4 x float> [[VAL]],<float -1.000000e+00, float -1.000000e+00, float -1.000000e+00, float -1.000000e+00>
name|ff2
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
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff2
comment|// CHECK: %{{.*}} = fadd<4 x float> [[VAL1]], [[VAL2]]
name|ff
operator|=
name|ff
operator|+
name|ff2
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
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff
comment|// CHECK: %{{.*}} = fadd<4 x float> [[VAL2]], [[VAL1]]
name|ff
operator|+=
name|ff2
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
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff2
comment|// CHECK: %{{.*}} = fsub<4 x float> [[VAL1]], [[VAL2]]
name|ff
operator|=
name|ff
operator|-
name|ff2
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
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff
comment|// CHECK: %{{.*}} = fsub<4 x float> [[VAL1]], [[VAL2]]
name|ff
operator|-=
name|ff2
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
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff2
comment|// CHECK: %{{.*}} = fmul<4 x float> [[VAL1]], [[VAL2]]
name|ff
operator|=
name|ff
operator|*
name|ff2
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
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff
comment|// CHECK: %{{.*}} = fmul<4 x float> [[VAL2]], [[VAL1]]
name|ff
operator|*=
name|ff2
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
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff2
comment|// CHECK: %{{.*}} = fdiv<4 x float> [[VAL1]], [[VAL2]]
name|ff
operator|=
name|ff
operator|/
name|ff2
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
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff2
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff
comment|// CHECK: %{{.*}} = fdiv<4 x float> [[VAL1]], [[VAL2]]
name|ff
operator|/=
name|ff2
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
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff2
comment|// CHECK: [[CMP:%[^ ]+]] = fcmp oeq<4 x float> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|ff
operator|==
name|ff2
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
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff2
comment|// CHECK: [[CMP:%[^ ]+]] = fcmp une<4 x float> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|ff
operator|!=
name|ff2
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
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff2
comment|// CHECK: [[CMP:%[^ ]+]] = fcmp oge<4 x float> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|ff
operator|>=
name|ff2
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
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff2
comment|// CHECK: [[CMP:%[^ ]+]] = fcmp ogt<4 x float> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|ff
operator|>
name|ff2
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
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff2
comment|// CHECK: [[CMP:%[^ ]+]] = fcmp ole<4 x float> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|ff
operator|<=
name|ff2
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
comment|// CHECK: [[VAL1:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff
comment|// CHECK: [[VAL2:%[^ ]+]] = load volatile<4 x float>,<4 x float>* @ff2
comment|// CHECK: [[CMP:%[^ ]+]] = fcmp olt<4 x float> [[VAL1]], [[VAL2]]
comment|// CHECK: %{{.*}} = sext<4 x i1> [[CMP]] to<4 x i32>
name|bi
operator|=
name|ff
operator|<
name|ff2
expr_stmt|;
block|}
end_function

end_unit

