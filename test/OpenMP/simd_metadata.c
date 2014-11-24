begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fopenmp=libiomp5 -emit-llvm %s -o - | FileCheck %s
end_comment

begin_function
name|void
name|h1
parameter_list|(
name|float
modifier|*
name|c
parameter_list|,
name|float
modifier|*
name|a
parameter_list|,
name|float
modifier|*
name|b
parameter_list|,
name|int
name|size
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @h1
name|int
name|t
init|=
literal|0
decl_stmt|;
pragma|#
directive|pragma
name|omp
name|simd
name|safelen
name|(
name|16
name|)
name|linear
name|(
name|t
name|)
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|size
condition|;
operator|++
name|i
control|)
block|{
name|c
index|[
name|i
index|]
operator|=
name|a
index|[
name|i
index|]
operator|*
name|a
index|[
name|i
index|]
operator|+
name|b
index|[
name|i
index|]
operator|*
name|b
index|[
name|t
index|]
expr_stmt|;
operator|++
name|t
expr_stmt|;
comment|// do not emit parallel_loop_access metadata due to usage of safelen clause.
comment|// CHECK-NOT: store float {{.+}}, float* {{.+}}, align {{.+}}, !llvm.mem.parallel_loop_access {{![0-9]+}}
block|}
block|}
end_function

begin_function
name|void
name|h2
parameter_list|(
name|float
modifier|*
name|c
parameter_list|,
name|float
modifier|*
name|a
parameter_list|,
name|float
modifier|*
name|b
parameter_list|,
name|int
name|size
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @h2
name|int
name|t
init|=
literal|0
decl_stmt|;
pragma|#
directive|pragma
name|omp
name|simd
name|linear
name|(
name|t
name|)
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|size
condition|;
operator|++
name|i
control|)
block|{
name|c
index|[
name|i
index|]
operator|=
name|a
index|[
name|i
index|]
operator|*
name|a
index|[
name|i
index|]
operator|+
name|b
index|[
name|i
index|]
operator|*
name|b
index|[
name|t
index|]
expr_stmt|;
operator|++
name|t
expr_stmt|;
comment|// CHECK: store float {{.+}}, float* {{.+}}, align {{.+}}, !llvm.mem.parallel_loop_access [[LOOP_H2_HEADER:![0-9]+]]
block|}
block|}
end_function

begin_function
name|void
name|h3
parameter_list|(
name|float
modifier|*
name|c
parameter_list|,
name|float
modifier|*
name|a
parameter_list|,
name|float
modifier|*
name|b
parameter_list|,
name|int
name|size
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @h3
pragma|#
directive|pragma
name|omp
name|simd
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|size
condition|;
operator|++
name|i
control|)
block|{
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|size
condition|;
operator|++
name|j
control|)
block|{
name|c
index|[
name|j
operator|*
name|i
index|]
operator|=
name|a
index|[
name|i
index|]
operator|*
name|b
index|[
name|j
index|]
expr_stmt|;
block|}
block|}
comment|// do not emit parallel_loop_access for nested loop.
comment|// CHECK-NOT: store float {{.+}}, float* {{.+}}, align {{.+}}, !llvm.mem.parallel_loop_access {{![0-9]+}}
block|}
end_function

begin_comment
comment|// Metadata for h1:
end_comment

begin_comment
comment|// CHECK: [[LOOP_H1_HEADER:![0-9]+]] = metadata !{metadata [[LOOP_H1_HEADER]], metadata [[LOOP_WIDTH_16:![0-9]+]], metadata [[LOOP_VEC_ENABLE:![0-9]+]]}
end_comment

begin_comment
comment|// CHECK: [[LOOP_WIDTH_16]] = metadata !{metadata !"llvm.loop.vectorize.width", i32 16}
end_comment

begin_comment
comment|// CHECK: [[LOOP_VEC_ENABLE]] = metadata !{metadata !"llvm.loop.vectorize.enable", i1 true}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Metadata for h2:
end_comment

begin_comment
comment|// CHECK: [[LOOP_H2_HEADER]] = metadata !{metadata [[LOOP_H2_HEADER]], metadata [[LOOP_VEC_ENABLE]]}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Metadata for h3:
end_comment

begin_comment
comment|// CHECK: [[LOOP_H3_HEADER:![0-9]+]] = metadata !{metadata [[LOOP_H3_HEADER]], metadata [[LOOP_VEC_ENABLE]]}
end_comment

begin_comment
comment|//
end_comment

end_unit

