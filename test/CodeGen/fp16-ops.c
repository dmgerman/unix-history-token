begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - -triple arm-none-linux-gnueabi %s | FileCheck %s --check-prefix=NOHALF --check-prefix=CHECK
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - -triple aarch64-none-linux-gnueabi %s | FileCheck %s --check-prefix=NOHALF --check-prefix=CHECK
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - -triple arm-none-linux-gnueabi -fallow-half-arguments-and-returns %s | FileCheck %s --check-prefix=HALF --check-prefix=CHECK
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - -triple aarch64-none-linux-gnueabi -fallow-half-arguments-and-returns %s | FileCheck %s --check-prefix=HALF --check-prefix=CHECK
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - -triple arm-none-linux-gnueabi -fnative-half-type %s \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=NATIVE-HALF
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - -triple aarch64-none-linux-gnueabi -fnative-half-type %s \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=NATIVE-HALF
end_comment

begin_comment
comment|// RUN: %clang_cc1 -emit-llvm -o - -x renderscript %s \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=NATIVE-HALF
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
name|int
name|i0
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

begin_decl_stmt
specifier|volatile
name|double
name|d0
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
comment|// NOHALF: [[F16TOF32:call float @llvm.convert.from.fp16.f32]]
comment|// HALF: [[F16TOF32:fpext half]]
comment|// CHECK: fptoui float
comment|// NATIVE-HALF: fptoui half
name|test
operator|=
operator|(
name|h0
operator|)
expr_stmt|;
comment|// CHECK: uitofp i32
comment|// NOHALF: [[F32TOF16:call i16 @llvm.convert.to.fp16.f32]]
comment|// HALF: [[F32TOF16:fptrunc float]]
comment|// NATIVE-HALF: uitofp i32 {{.*}} to half
name|h0
operator|=
operator|(
name|test
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp une float
comment|// NATIVE-HALF: fcmp une half
name|test
operator|=
operator|(
operator|!
name|h1
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fsub float
comment|// NOHALF: [[F32TOF16]]
comment|// HALF: [[F32TOF16]]
comment|// NATIVE-HALF: fsub half
name|h1
operator|=
operator|-
name|h1
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: load volatile half
comment|// NATIVE-HALF-NEXT: store volatile half
name|h1
operator|=
operator|+
name|h1
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fadd float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fadd half
name|h1
operator|++
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fadd float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fadd half
operator|++
name|h1
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fadd float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fadd half
operator|--
name|h1
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fadd float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fadd half
name|h1
operator|--
expr_stmt|;
comment|// Check binary ops with various operands
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fmul float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fmul half
name|h1
operator|=
name|h0
operator|*
name|h2
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// NOHALF: [[F32TOF16]]
comment|// NOHALF: [[F16TOF32]]
comment|// CHECK: fmul float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fmul half
name|h1
operator|=
name|h0
operator|*
operator|(
name|__fp16
operator|)
operator|-
literal|2.0f
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fmul float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fpext half
comment|// NATIVE-HALF: fmul float
name|h1
operator|=
name|h0
operator|*
name|f2
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fmul float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fpext half
comment|// NATIVE-HALF: fmul float
name|h1
operator|=
name|f0
operator|*
name|h2
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fmul float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fmul half
name|h1
operator|=
name|h0
operator|*
name|i0
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fdiv float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fdiv half
name|h1
operator|=
operator|(
name|h0
operator|/
name|h2
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// NOHALF: [[F16TOF32]]
comment|// CHECK: fdiv float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fdiv half
name|h1
operator|=
operator|(
name|h0
operator|/
operator|(
name|__fp16
operator|)
operator|-
literal|2.0f
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fdiv float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fpext half
comment|// NATIVE-HALF: fdiv float
name|h1
operator|=
operator|(
name|h0
operator|/
name|f2
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fdiv float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fpext half
comment|// NATIVE-HALF: fdiv float
name|h1
operator|=
operator|(
name|f0
operator|/
name|h2
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fdiv float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fdiv half
name|h1
operator|=
operator|(
name|h0
operator|/
name|i0
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fadd float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fadd half
name|h1
operator|=
operator|(
name|h2
operator|+
name|h0
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// NOHALF: [[F16TOF32]]
comment|// CHECK: fadd float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fadd half
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
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fadd float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fpext half
comment|// NATIVE-HALF: fadd float
name|h1
operator|=
operator|(
name|h2
operator|+
name|f0
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fadd float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fpext half
comment|// NATIVE-HALF: fadd float
name|h1
operator|=
operator|(
name|f2
operator|+
name|h0
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fadd float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fadd half
name|h1
operator|=
operator|(
name|h0
operator|+
name|i0
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fsub float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fsub half
name|h1
operator|=
operator|(
name|h2
operator|-
name|h0
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// NOHALF: [[F16TOF32]]
comment|// CHECK: fsub float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fsub half
name|h1
operator|=
operator|(
operator|(
name|__fp16
operator|)
operator|-
literal|2.0f
operator|-
name|h0
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fsub float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fpext half
comment|// NATIVE-HALF: fsub float
name|h1
operator|=
operator|(
name|h2
operator|-
name|f0
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fsub float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fpext half
comment|// NATIVE-HALF: fsub float
name|h1
operator|=
operator|(
name|f2
operator|-
name|h0
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fsub float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fsub half
name|h1
operator|=
operator|(
name|h0
operator|-
name|i0
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp olt float
comment|// NATIVE-HALF: fcmp olt half
name|test
operator|=
operator|(
name|h2
operator|<
name|h0
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// NOHALF: [[F16TOF32]]
comment|// CHECK: fcmp olt float
comment|// NATIVE-HALF: fcmp olt half
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
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp olt float
comment|// NATIVE-HALF: fpext half
comment|// NATIVE-HALF: fcmp olt float
name|test
operator|=
operator|(
name|h2
operator|<
name|f0
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp olt float
comment|// NATIVE-HALF: fpext half
comment|// NATIVE-HALF: fcmp olt float
name|test
operator|=
operator|(
name|f2
operator|<
name|h0
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp olt float
comment|// NATIVE-HALF: fcmp olt half
name|test
operator|=
operator|(
name|i0
operator|<
name|h0
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp olt float
comment|// NATIVE-HALF: fcmp olt half
name|test
operator|=
operator|(
name|h0
operator|<
name|i0
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp ogt float
comment|// NATIVE-HALF: fcmp ogt half
name|test
operator|=
operator|(
name|h0
operator|>
name|h2
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// NOHALF: [[F16TOF32]]
comment|// CHECK: fcmp ogt float
comment|// NATIVE-HALF: fcmp ogt half
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
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp ogt float
comment|// NATIVE-HALF: fpext half
comment|// NATIVE-HALF: fcmp ogt float
name|test
operator|=
operator|(
name|h0
operator|>
name|f2
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp ogt float
comment|// NATIVE-HALF: fpext half
comment|// NATIVE-HALF: fcmp ogt float
name|test
operator|=
operator|(
name|f0
operator|>
name|h2
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp ogt float
comment|// NATIVE-HALF: fcmp ogt half
name|test
operator|=
operator|(
name|i0
operator|>
name|h0
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp ogt float
comment|// NATIVE-HALF: fcmp ogt half
name|test
operator|=
operator|(
name|h0
operator|>
name|i0
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp ole float
comment|// NATIVE-HALF: fcmp ole half
name|test
operator|=
operator|(
name|h2
operator|<=
name|h0
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// NOHALF: [[F16TOF32]]
comment|// CHECK: fcmp ole float
comment|// NATIVE-HALF: fcmp ole half
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
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp ole float
comment|// NATIVE-HALF: fpext half
comment|// NATIVE-HALF: fcmp ole float
name|test
operator|=
operator|(
name|h2
operator|<=
name|f0
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp ole float
comment|// NATIVE-HALF: fpext half
comment|// NATIVE-HALF: fcmp ole float
name|test
operator|=
operator|(
name|f2
operator|<=
name|h0
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp ole float
comment|// NATIVE-HALF: fcmp ole half
name|test
operator|=
operator|(
name|i0
operator|<=
name|h0
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp ole float
comment|// NATIVE-HALF: fcmp ole half
name|test
operator|=
operator|(
name|h0
operator|<=
name|i0
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp oge float
comment|// NATIVE-HALF: fcmp oge half
name|test
operator|=
operator|(
name|h0
operator|>=
name|h2
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// NOHALF: [[F16TOF32]]
comment|// CHECK: fcmp oge float
comment|// NATIVE-HALF: fcmp oge half
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
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp oge float
comment|// NATIVE-HALF: fpext half
comment|// NATIVE-HALF: fcmp oge float
name|test
operator|=
operator|(
name|h0
operator|>=
name|f2
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp oge float
comment|// NATIVE-HALF: fpext half
comment|// NATIVE-HALF: fcmp oge float
name|test
operator|=
operator|(
name|f0
operator|>=
name|h2
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp oge float
comment|// NATIVE-HALF: fcmp oge half
name|test
operator|=
operator|(
name|i0
operator|>=
name|h0
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp oge float
comment|// NATIVE-HALF: fcmp oge half
name|test
operator|=
operator|(
name|h0
operator|>=
name|i0
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp oeq float
comment|// NATIVE-HALF: fcmp oeq half
name|test
operator|=
operator|(
name|h1
operator|==
name|h2
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// NOHALF: [[F16TOF32]]
comment|// CHECK: fcmp oeq float
comment|// NATIVE-HALF: fcmp oeq half
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
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp oeq float
comment|// NATIVE-HALF: fpext half
comment|// NATIVE-HALF: fcmp oeq float
name|test
operator|=
operator|(
name|h1
operator|==
name|f1
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp oeq float
comment|// NATIVE-HALF: fpext half
comment|// NATIVE-HALF: fcmp oeq float
name|test
operator|=
operator|(
name|f1
operator|==
name|h1
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp oeq float
comment|// NATIVE-HALF: fcmp oeq half
name|test
operator|=
operator|(
name|i0
operator|==
name|h0
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp oeq float
comment|// NATIVE-HALF: fcmp oeq half
name|test
operator|=
operator|(
name|h0
operator|==
name|i0
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp une float
comment|// NATIVE-HALF: fcmp une half
name|test
operator|=
operator|(
name|h1
operator|!=
name|h2
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// NOHALF: [[F16TOF32]]
comment|// CHECK: fcmp une float
comment|// NATIVE-HALF: fcmp une half
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
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp une float
comment|// NATIVE-HALF: fpext half
comment|// NATIVE-HALF: fcmp une float
name|test
operator|=
operator|(
name|h1
operator|!=
name|f1
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp une float
comment|// NATIVE-HALF: fpext half
comment|// NATIVE-HALF: fcmp une float
name|test
operator|=
operator|(
name|f1
operator|!=
name|h1
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp une float
comment|// NATIVE-HALF: fcmp une half
name|test
operator|=
operator|(
name|i0
operator|!=
name|h0
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp une float
comment|// NATIVE-HALF: fcmp une half
name|test
operator|=
operator|(
name|h0
operator|!=
name|i0
operator|)
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fcmp une float
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fcmp une half {{.*}}, 0xH0000
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
comment|// NOHALF: [[F32TOF16]]
comment|// HALF: store {{.*}} half 0xHC000
comment|// NATIVE-HALF: store {{.*}} half 0xHC000
name|h0
operator|=
operator|(
name|__fp16
operator|)
operator|-
literal|2.0f
expr_stmt|;
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fptrunc float
name|h0
operator|=
name|f0
expr_stmt|;
comment|// CHECK: sitofp i32 {{.*}} to float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: sitofp i32 {{.*}} to half
name|h0
operator|=
name|i0
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fptosi float {{.*}} to i32
comment|// NATIVE-HALF: fptosi half {{.*}} to i32
name|i0
operator|=
name|h0
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fadd float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fadd half
name|h0
operator|+=
name|h1
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// NOHALF: [[F16TOF32]]
comment|// CHECK: fadd float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fadd half
name|h0
operator|+=
operator|(
name|__fp16
operator|)
literal|1.0f
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fadd float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fpext half
comment|// NATIVE-HALF: fadd float
comment|// NATIVE-HALF: fptrunc float
name|h0
operator|+=
name|f2
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: sitofp i32 {{.*}} to float
comment|// CHECK: fadd float
comment|// CHECK: fptosi float {{.*}} to i32
comment|// NATIVE-HALF: sitofp i32 {{.*}} to half
comment|// NATIVE-HALF: fadd half
comment|// NATIVE-HALF: fptosi half {{.*}} to i32
name|i0
operator|+=
name|h0
expr_stmt|;
comment|// CHECK: sitofp i32 {{.*}} to float
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fadd float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: sitofp i32 {{.*}} to half
comment|// NATIVE-HALF: fadd half
name|h0
operator|+=
name|i0
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fsub float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fsub half
name|h0
operator|-=
name|h1
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// NOHALF: [[F16TOF32]]
comment|// CHECK: fsub float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fsub half
name|h0
operator|-=
operator|(
name|__fp16
operator|)
literal|1.0
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fsub float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fpext half
comment|// NATIVE-HALF: fsub float
comment|// NATIVE-HALF: fptrunc float
name|h0
operator|-=
name|f2
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: sitofp i32 {{.*}} to float
comment|// CHECK: fsub float
comment|// CHECK: fptosi float {{.*}} to i32
comment|// NATIVE-HALF: sitofp i32 {{.*}} to half
comment|// NATIVE-HALF: fsub half
comment|// NATIVE-HALF: fptosi half {{.*}} to i32
name|i0
operator|-=
name|h0
expr_stmt|;
comment|// CHECK: sitofp i32 {{.*}} to float
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fsub float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: sitofp i32 {{.*}} to half
comment|// NATIVE-HALF: fsub half
name|h0
operator|-=
name|i0
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fmul float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fmul half
name|h0
operator|*=
name|h1
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// NOHALF: [[F16TOF32]]
comment|// CHECK: fmul float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fmul half
name|h0
operator|*=
operator|(
name|__fp16
operator|)
literal|1.0
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fmul float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fpext half
comment|// NATIVE-HALF: fmul float
comment|// NATIVE-HALF: fptrunc float
name|h0
operator|*=
name|f2
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: sitofp i32 {{.*}} to float
comment|// CHECK: fmul float
comment|// CHECK: fptosi float {{.*}} to i32
comment|// NATIVE-HALF: sitofp i32 {{.*}} to half
comment|// NATIVE-HALF: fmul half
comment|// NATIVE-HALF: fptosi half {{.*}} to i32
name|i0
operator|*=
name|h0
expr_stmt|;
comment|// CHECK: sitofp i32 {{.*}} to float
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fmul float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: sitofp i32 {{.*}} to half
comment|// NATIVE-HALF: fmul half
name|h0
operator|*=
name|i0
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fdiv float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fdiv half
name|h0
operator|/=
name|h1
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// NOHALF: [[F16TOF32]]
comment|// CHECK: fdiv float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fdiv half
name|h0
operator|/=
operator|(
name|__fp16
operator|)
literal|1.0
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fdiv float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: fpext half
comment|// NATIVE-HALF: fdiv float
comment|// NATIVE-HALF: fptrunc float
name|h0
operator|/=
name|f2
expr_stmt|;
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: sitofp i32 {{.*}} to float
comment|// CHECK: fdiv float
comment|// CHECK: fptosi float {{.*}} to i32
comment|// NATIVE-HALF: sitofp i32 {{.*}} to half
comment|// NATIVE-HALF: fdiv half
comment|// NATIVE-HALF: fptosi half {{.*}} to i32
name|i0
operator|/=
name|h0
expr_stmt|;
comment|// CHECK: sitofp i32 {{.*}} to float
comment|// CHECK: [[F16TOF32]]
comment|// CHECK: fdiv float
comment|// CHECK: [[F32TOF16]]
comment|// NATIVE-HALF: sitofp i32 {{.*}} to half
comment|// NATIVE-HALF: fdiv half
name|h0
operator|/=
name|i0
expr_stmt|;
comment|// Check conversions to/from double
comment|// NOHALF: call i16 @llvm.convert.to.fp16.f64(
comment|// HALF: fptrunc double {{.*}} to half
comment|// NATIVE-HALF: fptrunc double {{.*}} to half
name|h0
operator|=
name|d0
expr_stmt|;
comment|// CHECK: [[MID:%.*]] = fptrunc double {{%.*}} to float
comment|// NOHALF: call i16 @llvm.convert.to.fp16.f32(float [[MID]])
comment|// HALF: fptrunc float [[MID]] to half
comment|// NATIVE-HALF: [[MID:%.*]] = fptrunc double {{%.*}} to float
comment|// NATIVE-HALF: fptrunc float {{.*}} to half
name|h0
operator|=
operator|(
name|float
operator|)
name|d0
expr_stmt|;
comment|// NOHALF: call double @llvm.convert.from.fp16.f64(
comment|// HALF: fpext half {{.*}} to double
comment|// NATIVE-HALF: fpext half {{.*}} to double
name|d0
operator|=
name|h0
expr_stmt|;
comment|// NOHALF: [[MID:%.*]] = call float @llvm.convert.from.fp16.f32(
comment|// HALF: [[MID:%.*]] = fpext half {{.*}} to float
comment|// CHECK: fpext float [[MID]] to double
comment|// NATIVE-HALF: [[MID:%.*]] = fpext half {{.*}} to float
comment|// NATIVE-HALF: fpext float [[MID]] to double
name|d0
operator|=
operator|(
name|float
operator|)
name|h0
expr_stmt|;
block|}
end_function

end_unit

