begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - -triple arm-none-linux-gnueabi %s | FileCheck %s
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|cond_t
typedef|;
end_typedef

begin_decl_stmt
specifier|volatile
name|cond_t
name|test
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|__fp16
name|h0
init|=
literal|0.0
decl_stmt|,
name|h1
init|=
literal|1.0
decl_stmt|,
name|h2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|volatile
name|float
name|f0
decl_stmt|,
name|f1
decl_stmt|,
name|f2
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @foo()
comment|// Check unary ops
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK fptoi float
name|test
operator|=
operator|(
name|h0
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fcmp une float
name|test
operator|=
operator|(
operator|!
name|h1
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fsub float
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h1
operator|=
operator|-
name|h1
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h1
operator|=
operator|+
name|h1
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fadd float
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h1
operator|++
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fadd float
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
operator|++
name|h1
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fadd float
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
operator|--
name|h1
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fadd float
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h1
operator|--
expr_stmt|;
comment|// Check binary ops with various operands
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fmul float
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h1
operator|=
name|h0
operator|*
name|h2
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fmul float
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h1
operator|=
name|h0
operator|*
operator|(
name|__fp16
operator|)
operator|-
literal|2.0
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fmul float
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h1
operator|=
name|h0
operator|*
name|f2
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fmul float
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h1
operator|=
name|f0
operator|*
name|h2
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fdiv float
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h1
operator|=
operator|(
name|h0
operator|/
name|h2
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fdiv float
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h1
operator|=
operator|(
name|h0
operator|/
operator|(
name|__fp16
operator|)
operator|-
literal|2.0
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fdiv float
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h1
operator|=
operator|(
name|h0
operator|/
name|f2
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fdiv float
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h1
operator|=
operator|(
name|f0
operator|/
name|h2
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fadd float
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h1
operator|=
operator|(
name|h2
operator|+
name|h0
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fadd float
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h1
operator|=
operator|(
operator|(
name|__fp16
operator|)
operator|-
literal|2.0
operator|+
name|h0
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fadd float
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h1
operator|=
operator|(
name|h2
operator|+
name|f0
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fadd float
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h1
operator|=
operator|(
name|f2
operator|+
name|h0
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fsub float
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h1
operator|=
operator|(
name|h2
operator|-
name|h0
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fsub float
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h1
operator|=
operator|(
operator|(
name|__fp16
operator|)
operator|-
literal|2.0
operator|-
name|h0
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fsub float
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h1
operator|=
operator|(
name|h2
operator|-
name|f0
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fsub float
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h1
operator|=
operator|(
name|f2
operator|-
name|h0
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fcmp olt
name|test
operator|=
operator|(
name|h2
operator|<
name|h0
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fcmp olt
name|test
operator|=
operator|(
name|h2
operator|<
operator|(
name|__fp16
operator|)
literal|42.0
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fcmp olt
name|test
operator|=
operator|(
name|h2
operator|<
name|f0
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fcmp olt
name|test
operator|=
operator|(
name|f2
operator|<
name|h0
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fcmp ogt
name|test
operator|=
operator|(
name|h0
operator|>
name|h2
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fcmp ogt
name|test
operator|=
operator|(
operator|(
name|__fp16
operator|)
literal|42.0
operator|>
name|h2
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fcmp ogt
name|test
operator|=
operator|(
name|h0
operator|>
name|f2
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fcmp ogt
name|test
operator|=
operator|(
name|f0
operator|>
name|h2
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fcmp ole
name|test
operator|=
operator|(
name|h2
operator|<=
name|h0
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fcmp ole
name|test
operator|=
operator|(
name|h2
operator|<=
operator|(
name|__fp16
operator|)
literal|42.0
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fcmp ole
name|test
operator|=
operator|(
name|h2
operator|<=
name|f0
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fcmp ole
name|test
operator|=
operator|(
name|f2
operator|<=
name|h0
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fcmp oge
name|test
operator|=
operator|(
name|h0
operator|>=
name|h2
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fcmp oge
name|test
operator|=
operator|(
name|h0
operator|>=
operator|(
name|__fp16
operator|)
operator|-
literal|2.0
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fcmp oge
name|test
operator|=
operator|(
name|h0
operator|>=
name|f2
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fcmp oge
name|test
operator|=
operator|(
name|f0
operator|>=
name|h2
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fcmp oeq
name|test
operator|=
operator|(
name|h1
operator|==
name|h2
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fcmp oeq
name|test
operator|=
operator|(
name|h1
operator|==
operator|(
name|__fp16
operator|)
literal|1.0
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fcmp oeq
name|test
operator|=
operator|(
name|h1
operator|==
name|f1
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fcmp oeq
name|test
operator|=
operator|(
name|f1
operator|==
name|h1
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fcmp une
name|test
operator|=
operator|(
name|h1
operator|!=
name|h2
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fcmp une
name|test
operator|=
operator|(
name|h1
operator|!=
operator|(
name|__fp16
operator|)
literal|1.0
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fcmp une
name|test
operator|=
operator|(
name|h1
operator|!=
name|f1
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fcmp une
name|test
operator|=
operator|(
name|f1
operator|!=
name|h1
operator|)
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fcmp une
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h1
operator|=
operator|(
name|h1
condition|?
name|h2
else|:
name|h0
operator|)
expr_stmt|;
comment|// Check assignments (inc. compound)
name|h0
operator|=
name|h1
expr_stmt|;
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h0
operator|=
operator|(
name|__fp16
operator|)
operator|-
literal|2.0
expr_stmt|;
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h0
operator|=
name|f0
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fadd float
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h0
operator|+=
name|h1
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fadd
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h0
operator|+=
operator|(
name|__fp16
operator|)
literal|1.0
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fadd
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h0
operator|+=
name|f2
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fsub
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h0
operator|-=
name|h1
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fsub
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h0
operator|-=
operator|(
name|__fp16
operator|)
literal|1.0
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fsub
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h0
operator|-=
name|f2
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fmul
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h0
operator|*=
name|h1
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fmul
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h0
operator|*=
operator|(
name|__fp16
operator|)
literal|1.0
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fmul
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h0
operator|*=
name|f2
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fdiv
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h0
operator|/=
name|h1
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fdiv
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h0
operator|/=
operator|(
name|__fp16
operator|)
literal|1.0
expr_stmt|;
comment|// CHECK: call float @llvm.convert.from.fp16.f32(
comment|// CHECK: fdiv
comment|// CHECK: call i16 @llvm.convert.to.fp16.f32(
name|h0
operator|/=
name|f2
expr_stmt|;
block|}
end_function

end_unit

