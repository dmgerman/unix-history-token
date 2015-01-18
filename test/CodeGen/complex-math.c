begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -O1 -emit-llvm -triple x86_64-unknown-unknown -o - | FileCheck %s --check-prefix=X86
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -O1 -emit-llvm -triple x86_64-pc-win64 -o - | FileCheck %s --check-prefix=X86
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -O1 -emit-llvm -triple i686-unknown-unknown -o - | FileCheck %s --check-prefix=X86
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -O1 -emit-llvm -triple powerpc-unknown-unknown -o - | FileCheck %s --check-prefix=PPC
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -O1 -emit-llvm -triple armv7-none-linux-gnueabihf -o - | FileCheck %s --check-prefix=ARM
end_comment

begin_function
name|float
specifier|_Complex
name|add_float_rr
parameter_list|(
name|float
name|a
parameter_list|,
name|float
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @add_float_rr(
comment|// X86: fadd
comment|// X86-NOT: fadd
comment|// X86: ret
return|return
name|a
operator|+
name|b
return|;
block|}
end_function

begin_function
name|float
specifier|_Complex
name|add_float_cr
parameter_list|(
name|float
specifier|_Complex
name|a
parameter_list|,
name|float
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @add_float_cr(
comment|// X86: fadd
comment|// X86-NOT: fadd
comment|// X86: ret
return|return
name|a
operator|+
name|b
return|;
block|}
end_function

begin_function
name|float
specifier|_Complex
name|add_float_rc
parameter_list|(
name|float
name|a
parameter_list|,
name|float
specifier|_Complex
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @add_float_rc(
comment|// X86: fadd
comment|// X86-NOT: fadd
comment|// X86: ret
return|return
name|a
operator|+
name|b
return|;
block|}
end_function

begin_function
name|float
specifier|_Complex
name|add_float_cc
parameter_list|(
name|float
specifier|_Complex
name|a
parameter_list|,
name|float
specifier|_Complex
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @add_float_cc(
comment|// X86: fadd
comment|// X86: fadd
comment|// X86-NOT: fadd
comment|// X86: ret
return|return
name|a
operator|+
name|b
return|;
block|}
end_function

begin_function
name|float
specifier|_Complex
name|sub_float_rr
parameter_list|(
name|float
name|a
parameter_list|,
name|float
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @sub_float_rr(
comment|// X86: fsub
comment|// X86-NOT: fsub
comment|// X86: ret
return|return
name|a
operator|-
name|b
return|;
block|}
end_function

begin_function
name|float
specifier|_Complex
name|sub_float_cr
parameter_list|(
name|float
specifier|_Complex
name|a
parameter_list|,
name|float
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @sub_float_cr(
comment|// X86: fsub
comment|// X86-NOT: fsub
comment|// X86: ret
return|return
name|a
operator|-
name|b
return|;
block|}
end_function

begin_function
name|float
specifier|_Complex
name|sub_float_rc
parameter_list|(
name|float
name|a
parameter_list|,
name|float
specifier|_Complex
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @sub_float_rc(
comment|// X86: fsub
comment|// X86: fsub float -0.{{0+}}e+00,
comment|// X86-NOT: fsub
comment|// X86: ret
return|return
name|a
operator|-
name|b
return|;
block|}
end_function

begin_function
name|float
specifier|_Complex
name|sub_float_cc
parameter_list|(
name|float
specifier|_Complex
name|a
parameter_list|,
name|float
specifier|_Complex
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @sub_float_cc(
comment|// X86: fsub
comment|// X86: fsub
comment|// X86-NOT: fsub
comment|// X86: ret
return|return
name|a
operator|-
name|b
return|;
block|}
end_function

begin_function
name|float
specifier|_Complex
name|mul_float_rr
parameter_list|(
name|float
name|a
parameter_list|,
name|float
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @mul_float_rr(
comment|// X86: fmul
comment|// X86-NOT: fmul
comment|// X86: ret
return|return
name|a
operator|*
name|b
return|;
block|}
end_function

begin_function
name|float
specifier|_Complex
name|mul_float_cr
parameter_list|(
name|float
specifier|_Complex
name|a
parameter_list|,
name|float
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @mul_float_cr(
comment|// X86: fmul
comment|// X86: fmul
comment|// X86-NOT: fmul
comment|// X86: ret
return|return
name|a
operator|*
name|b
return|;
block|}
end_function

begin_function
name|float
specifier|_Complex
name|mul_float_rc
parameter_list|(
name|float
name|a
parameter_list|,
name|float
specifier|_Complex
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @mul_float_rc(
comment|// X86: fmul
comment|// X86: fmul
comment|// X86-NOT: fmul
comment|// X86: ret
return|return
name|a
operator|*
name|b
return|;
block|}
end_function

begin_function
name|float
specifier|_Complex
name|mul_float_cc
parameter_list|(
name|float
specifier|_Complex
name|a
parameter_list|,
name|float
specifier|_Complex
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @mul_float_cc(
comment|// X86: %[[AC:[^ ]+]] = fmul
comment|// X86: %[[BD:[^ ]+]] = fmul
comment|// X86: %[[AD:[^ ]+]] = fmul
comment|// X86: %[[BC:[^ ]+]] = fmul
comment|// X86: %[[RR:[^ ]+]] = fsub float %[[AC]], %[[BD]]
comment|// X86: %[[RI:[^ ]+]] = fadd float
comment|// X86-DAG: %[[AD]]
comment|// X86-DAG: ,
comment|// X86-DAG: %[[BC]]
comment|// X86: fcmp uno float %[[RR]]
comment|// X86: fcmp uno float %[[RI]]
comment|// X86: call {{.*}} @__mulsc3(
comment|// X86: ret
return|return
name|a
operator|*
name|b
return|;
block|}
end_function

begin_function
name|float
specifier|_Complex
name|div_float_rr
parameter_list|(
name|float
name|a
parameter_list|,
name|float
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @div_float_rr(
comment|// X86: fdiv
comment|// X86-NOT: fdiv
comment|// X86: ret
return|return
name|a
operator|/
name|b
return|;
block|}
end_function

begin_function
name|float
specifier|_Complex
name|div_float_cr
parameter_list|(
name|float
specifier|_Complex
name|a
parameter_list|,
name|float
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @div_float_cr(
comment|// X86: fdiv
comment|// X86: fdiv
comment|// X86-NOT: fdiv
comment|// X86: ret
return|return
name|a
operator|/
name|b
return|;
block|}
end_function

begin_function
name|float
specifier|_Complex
name|div_float_rc
parameter_list|(
name|float
name|a
parameter_list|,
name|float
specifier|_Complex
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @div_float_rc(
comment|// X86-NOT: fdiv
comment|// X86: call {{.*}} @__divsc3(
comment|// X86: ret
return|return
name|a
operator|/
name|b
return|;
block|}
end_function

begin_function
name|float
specifier|_Complex
name|div_float_cc
parameter_list|(
name|float
specifier|_Complex
name|a
parameter_list|,
name|float
specifier|_Complex
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @div_float_cc(
comment|// X86-NOT: fdiv
comment|// X86: call {{.*}} @__divsc3(
comment|// X86: ret
return|return
name|a
operator|/
name|b
return|;
block|}
end_function

begin_function
name|double
specifier|_Complex
name|add_double_rr
parameter_list|(
name|double
name|a
parameter_list|,
name|double
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @add_double_rr(
comment|// X86: fadd
comment|// X86-NOT: fadd
comment|// X86: ret
return|return
name|a
operator|+
name|b
return|;
block|}
end_function

begin_function
name|double
specifier|_Complex
name|add_double_cr
parameter_list|(
name|double
specifier|_Complex
name|a
parameter_list|,
name|double
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @add_double_cr(
comment|// X86: fadd
comment|// X86-NOT: fadd
comment|// X86: ret
return|return
name|a
operator|+
name|b
return|;
block|}
end_function

begin_function
name|double
specifier|_Complex
name|add_double_rc
parameter_list|(
name|double
name|a
parameter_list|,
name|double
specifier|_Complex
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @add_double_rc(
comment|// X86: fadd
comment|// X86-NOT: fadd
comment|// X86: ret
return|return
name|a
operator|+
name|b
return|;
block|}
end_function

begin_function
name|double
specifier|_Complex
name|add_double_cc
parameter_list|(
name|double
specifier|_Complex
name|a
parameter_list|,
name|double
specifier|_Complex
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @add_double_cc(
comment|// X86: fadd
comment|// X86: fadd
comment|// X86-NOT: fadd
comment|// X86: ret
return|return
name|a
operator|+
name|b
return|;
block|}
end_function

begin_function
name|double
specifier|_Complex
name|sub_double_rr
parameter_list|(
name|double
name|a
parameter_list|,
name|double
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @sub_double_rr(
comment|// X86: fsub
comment|// X86-NOT: fsub
comment|// X86: ret
return|return
name|a
operator|-
name|b
return|;
block|}
end_function

begin_function
name|double
specifier|_Complex
name|sub_double_cr
parameter_list|(
name|double
specifier|_Complex
name|a
parameter_list|,
name|double
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @sub_double_cr(
comment|// X86: fsub
comment|// X86-NOT: fsub
comment|// X86: ret
return|return
name|a
operator|-
name|b
return|;
block|}
end_function

begin_function
name|double
specifier|_Complex
name|sub_double_rc
parameter_list|(
name|double
name|a
parameter_list|,
name|double
specifier|_Complex
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @sub_double_rc(
comment|// X86: fsub
comment|// X86: fsub double -0.{{0+}}e+00,
comment|// X86-NOT: fsub
comment|// X86: ret
return|return
name|a
operator|-
name|b
return|;
block|}
end_function

begin_function
name|double
specifier|_Complex
name|sub_double_cc
parameter_list|(
name|double
specifier|_Complex
name|a
parameter_list|,
name|double
specifier|_Complex
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @sub_double_cc(
comment|// X86: fsub
comment|// X86: fsub
comment|// X86-NOT: fsub
comment|// X86: ret
return|return
name|a
operator|-
name|b
return|;
block|}
end_function

begin_function
name|double
specifier|_Complex
name|mul_double_rr
parameter_list|(
name|double
name|a
parameter_list|,
name|double
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @mul_double_rr(
comment|// X86: fmul
comment|// X86-NOT: fmul
comment|// X86: ret
return|return
name|a
operator|*
name|b
return|;
block|}
end_function

begin_function
name|double
specifier|_Complex
name|mul_double_cr
parameter_list|(
name|double
specifier|_Complex
name|a
parameter_list|,
name|double
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @mul_double_cr(
comment|// X86: fmul
comment|// X86: fmul
comment|// X86-NOT: fmul
comment|// X86: ret
return|return
name|a
operator|*
name|b
return|;
block|}
end_function

begin_function
name|double
specifier|_Complex
name|mul_double_rc
parameter_list|(
name|double
name|a
parameter_list|,
name|double
specifier|_Complex
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @mul_double_rc(
comment|// X86: fmul
comment|// X86: fmul
comment|// X86-NOT: fmul
comment|// X86: ret
return|return
name|a
operator|*
name|b
return|;
block|}
end_function

begin_function
name|double
specifier|_Complex
name|mul_double_cc
parameter_list|(
name|double
specifier|_Complex
name|a
parameter_list|,
name|double
specifier|_Complex
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @mul_double_cc(
comment|// X86: %[[AC:[^ ]+]] = fmul
comment|// X86: %[[BD:[^ ]+]] = fmul
comment|// X86: %[[AD:[^ ]+]] = fmul
comment|// X86: %[[BC:[^ ]+]] = fmul
comment|// X86: %[[RR:[^ ]+]] = fsub double %[[AC]], %[[BD]]
comment|// X86: %[[RI:[^ ]+]] = fadd double
comment|// X86-DAG: %[[AD]]
comment|// X86-DAG: ,
comment|// X86-DAG: %[[BC]]
comment|// X86: fcmp uno double %[[RR]]
comment|// X86: fcmp uno double %[[RI]]
comment|// X86: call {{.*}} @__muldc3(
comment|// X86: ret
return|return
name|a
operator|*
name|b
return|;
block|}
end_function

begin_function
name|double
specifier|_Complex
name|div_double_rr
parameter_list|(
name|double
name|a
parameter_list|,
name|double
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @div_double_rr(
comment|// X86: fdiv
comment|// X86-NOT: fdiv
comment|// X86: ret
return|return
name|a
operator|/
name|b
return|;
block|}
end_function

begin_function
name|double
specifier|_Complex
name|div_double_cr
parameter_list|(
name|double
specifier|_Complex
name|a
parameter_list|,
name|double
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @div_double_cr(
comment|// X86: fdiv
comment|// X86: fdiv
comment|// X86-NOT: fdiv
comment|// X86: ret
return|return
name|a
operator|/
name|b
return|;
block|}
end_function

begin_function
name|double
specifier|_Complex
name|div_double_rc
parameter_list|(
name|double
name|a
parameter_list|,
name|double
specifier|_Complex
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @div_double_rc(
comment|// X86-NOT: fdiv
comment|// X86: call {{.*}} @__divdc3(
comment|// X86: ret
return|return
name|a
operator|/
name|b
return|;
block|}
end_function

begin_function
name|double
specifier|_Complex
name|div_double_cc
parameter_list|(
name|double
specifier|_Complex
name|a
parameter_list|,
name|double
specifier|_Complex
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @div_double_cc(
comment|// X86-NOT: fdiv
comment|// X86: call {{.*}} @__divdc3(
comment|// X86: ret
return|return
name|a
operator|/
name|b
return|;
block|}
end_function

begin_function
name|long
name|double
specifier|_Complex
name|add_long_double_rr
parameter_list|(
name|long
name|double
name|a
parameter_list|,
name|long
name|double
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @add_long_double_rr(
comment|// X86: fadd
comment|// X86-NOT: fadd
comment|// X86: ret
return|return
name|a
operator|+
name|b
return|;
block|}
end_function

begin_function
name|long
name|double
specifier|_Complex
name|add_long_double_cr
parameter_list|(
name|long
name|double
specifier|_Complex
name|a
parameter_list|,
name|long
name|double
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @add_long_double_cr(
comment|// X86: fadd
comment|// X86-NOT: fadd
comment|// X86: ret
return|return
name|a
operator|+
name|b
return|;
block|}
end_function

begin_function
name|long
name|double
specifier|_Complex
name|add_long_double_rc
parameter_list|(
name|long
name|double
name|a
parameter_list|,
name|long
name|double
specifier|_Complex
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @add_long_double_rc(
comment|// X86: fadd
comment|// X86-NOT: fadd
comment|// X86: ret
return|return
name|a
operator|+
name|b
return|;
block|}
end_function

begin_function
name|long
name|double
specifier|_Complex
name|add_long_double_cc
parameter_list|(
name|long
name|double
specifier|_Complex
name|a
parameter_list|,
name|long
name|double
specifier|_Complex
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @add_long_double_cc(
comment|// X86: fadd
comment|// X86: fadd
comment|// X86-NOT: fadd
comment|// X86: ret
return|return
name|a
operator|+
name|b
return|;
block|}
end_function

begin_function
name|long
name|double
specifier|_Complex
name|sub_long_double_rr
parameter_list|(
name|long
name|double
name|a
parameter_list|,
name|long
name|double
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @sub_long_double_rr(
comment|// X86: fsub
comment|// X86-NOT: fsub
comment|// X86: ret
return|return
name|a
operator|-
name|b
return|;
block|}
end_function

begin_function
name|long
name|double
specifier|_Complex
name|sub_long_double_cr
parameter_list|(
name|long
name|double
specifier|_Complex
name|a
parameter_list|,
name|long
name|double
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @sub_long_double_cr(
comment|// X86: fsub
comment|// X86-NOT: fsub
comment|// X86: ret
return|return
name|a
operator|-
name|b
return|;
block|}
end_function

begin_function
name|long
name|double
specifier|_Complex
name|sub_long_double_rc
parameter_list|(
name|long
name|double
name|a
parameter_list|,
name|long
name|double
specifier|_Complex
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @sub_long_double_rc(
comment|// X86: fsub
comment|// X86: fsub x86_fp80 0xK8{{0+}},
comment|// X86-NOT: fsub
comment|// X86: ret
return|return
name|a
operator|-
name|b
return|;
block|}
end_function

begin_function
name|long
name|double
specifier|_Complex
name|sub_long_double_cc
parameter_list|(
name|long
name|double
specifier|_Complex
name|a
parameter_list|,
name|long
name|double
specifier|_Complex
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @sub_long_double_cc(
comment|// X86: fsub
comment|// X86: fsub
comment|// X86-NOT: fsub
comment|// X86: ret
return|return
name|a
operator|-
name|b
return|;
block|}
end_function

begin_function
name|long
name|double
specifier|_Complex
name|mul_long_double_rr
parameter_list|(
name|long
name|double
name|a
parameter_list|,
name|long
name|double
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @mul_long_double_rr(
comment|// X86: fmul
comment|// X86-NOT: fmul
comment|// X86: ret
return|return
name|a
operator|*
name|b
return|;
block|}
end_function

begin_function
name|long
name|double
specifier|_Complex
name|mul_long_double_cr
parameter_list|(
name|long
name|double
specifier|_Complex
name|a
parameter_list|,
name|long
name|double
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @mul_long_double_cr(
comment|// X86: fmul
comment|// X86: fmul
comment|// X86-NOT: fmul
comment|// X86: ret
return|return
name|a
operator|*
name|b
return|;
block|}
end_function

begin_function
name|long
name|double
specifier|_Complex
name|mul_long_double_rc
parameter_list|(
name|long
name|double
name|a
parameter_list|,
name|long
name|double
specifier|_Complex
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @mul_long_double_rc(
comment|// X86: fmul
comment|// X86: fmul
comment|// X86-NOT: fmul
comment|// X86: ret
return|return
name|a
operator|*
name|b
return|;
block|}
end_function

begin_function
name|long
name|double
specifier|_Complex
name|mul_long_double_cc
parameter_list|(
name|long
name|double
specifier|_Complex
name|a
parameter_list|,
name|long
name|double
specifier|_Complex
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @mul_long_double_cc(
comment|// X86: %[[AC:[^ ]+]] = fmul
comment|// X86: %[[BD:[^ ]+]] = fmul
comment|// X86: %[[AD:[^ ]+]] = fmul
comment|// X86: %[[BC:[^ ]+]] = fmul
comment|// X86: %[[RR:[^ ]+]] = fsub x86_fp80 %[[AC]], %[[BD]]
comment|// X86: %[[RI:[^ ]+]] = fadd x86_fp80
comment|// X86-DAG: %[[AD]]
comment|// X86-DAG: ,
comment|// X86-DAG: %[[BC]]
comment|// X86: fcmp uno x86_fp80 %[[RR]]
comment|// X86: fcmp uno x86_fp80 %[[RI]]
comment|// X86: call {{.*}} @__mulxc3(
comment|// X86: ret
comment|// PPC-LABEL: @mul_long_double_cc(
comment|// PPC: %[[AC:[^ ]+]] = fmul
comment|// PPC: %[[BD:[^ ]+]] = fmul
comment|// PPC: %[[AD:[^ ]+]] = fmul
comment|// PPC: %[[BC:[^ ]+]] = fmul
comment|// PPC: %[[RR:[^ ]+]] = fsub ppc_fp128 %[[AC]], %[[BD]]
comment|// PPC: %[[RI:[^ ]+]] = fadd ppc_fp128
comment|// PPC-DAG: %[[AD]]
comment|// PPC-DAG: ,
comment|// PPC-DAG: %[[BC]]
comment|// PPC: fcmp uno ppc_fp128 %[[RR]]
comment|// PPC: fcmp uno ppc_fp128 %[[RI]]
comment|// PPC: call {{.*}} @__multc3(
comment|// PPC: ret
return|return
name|a
operator|*
name|b
return|;
block|}
end_function

begin_function
name|long
name|double
specifier|_Complex
name|div_long_double_rr
parameter_list|(
name|long
name|double
name|a
parameter_list|,
name|long
name|double
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @div_long_double_rr(
comment|// X86: fdiv
comment|// X86-NOT: fdiv
comment|// X86: ret
return|return
name|a
operator|/
name|b
return|;
block|}
end_function

begin_function
name|long
name|double
specifier|_Complex
name|div_long_double_cr
parameter_list|(
name|long
name|double
specifier|_Complex
name|a
parameter_list|,
name|long
name|double
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @div_long_double_cr(
comment|// X86: fdiv
comment|// X86: fdiv
comment|// X86-NOT: fdiv
comment|// X86: ret
return|return
name|a
operator|/
name|b
return|;
block|}
end_function

begin_function
name|long
name|double
specifier|_Complex
name|div_long_double_rc
parameter_list|(
name|long
name|double
name|a
parameter_list|,
name|long
name|double
specifier|_Complex
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @div_long_double_rc(
comment|// X86-NOT: fdiv
comment|// X86: call {{.*}} @__divxc3(
comment|// X86: ret
comment|// PPC-LABEL: @div_long_double_rc(
comment|// PPC-NOT: fdiv
comment|// PPC: call {{.*}} @__divtc3(
comment|// PPC: ret
return|return
name|a
operator|/
name|b
return|;
block|}
end_function

begin_function
name|long
name|double
specifier|_Complex
name|div_long_double_cc
parameter_list|(
name|long
name|double
specifier|_Complex
name|a
parameter_list|,
name|long
name|double
specifier|_Complex
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @div_long_double_cc(
comment|// X86-NOT: fdiv
comment|// X86: call {{.*}} @__divxc3(
comment|// X86: ret
comment|// PPC-LABEL: @div_long_double_cc(
comment|// PPC-NOT: fdiv
comment|// PPC: call {{.*}} @__divtc3(
comment|// PPC: ret
return|return
name|a
operator|/
name|b
return|;
block|}
end_function

begin_comment
comment|// Comparison operators don't rely on library calls or have interseting math
end_comment

begin_comment
comment|// properties, but test that mixed types work correctly here.
end_comment

begin_function
name|_Bool
name|eq_float_cr
parameter_list|(
name|float
specifier|_Complex
name|a
parameter_list|,
name|float
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @eq_float_cr(
comment|// X86: fcmp oeq
comment|// X86: fcmp oeq
comment|// X86: and i1
comment|// X86: ret
return|return
name|a
operator|==
name|b
return|;
block|}
end_function

begin_function
name|_Bool
name|eq_float_rc
parameter_list|(
name|float
name|a
parameter_list|,
name|float
specifier|_Complex
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @eq_float_rc(
comment|// X86: fcmp oeq
comment|// X86: fcmp oeq
comment|// X86: and i1
comment|// X86: ret
return|return
name|a
operator|==
name|b
return|;
block|}
end_function

begin_function
name|_Bool
name|eq_float_cc
parameter_list|(
name|float
specifier|_Complex
name|a
parameter_list|,
name|float
specifier|_Complex
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @eq_float_cc(
comment|// X86: fcmp oeq
comment|// X86: fcmp oeq
comment|// X86: and i1
comment|// X86: ret
return|return
name|a
operator|==
name|b
return|;
block|}
end_function

begin_function
name|_Bool
name|ne_float_cr
parameter_list|(
name|float
specifier|_Complex
name|a
parameter_list|,
name|float
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @ne_float_cr(
comment|// X86: fcmp une
comment|// X86: fcmp une
comment|// X86: or i1
comment|// X86: ret
return|return
name|a
operator|!=
name|b
return|;
block|}
end_function

begin_function
name|_Bool
name|ne_float_rc
parameter_list|(
name|float
name|a
parameter_list|,
name|float
specifier|_Complex
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @ne_float_rc(
comment|// X86: fcmp une
comment|// X86: fcmp une
comment|// X86: or i1
comment|// X86: ret
return|return
name|a
operator|!=
name|b
return|;
block|}
end_function

begin_function
name|_Bool
name|ne_float_cc
parameter_list|(
name|float
specifier|_Complex
name|a
parameter_list|,
name|float
specifier|_Complex
name|b
parameter_list|)
block|{
comment|// X86-LABEL: @ne_float_cc(
comment|// X86: fcmp une
comment|// X86: fcmp une
comment|// X86: or i1
comment|// X86: ret
return|return
name|a
operator|!=
name|b
return|;
block|}
end_function

begin_comment
comment|// Check that the libcall will obtain proper calling convention on ARM
end_comment

begin_function
specifier|_Complex
name|double
name|foo
parameter_list|(
specifier|_Complex
name|double
name|a
parameter_list|,
specifier|_Complex
name|double
name|b
parameter_list|)
block|{
comment|// ARM-LABEL: @foo(
comment|// ARM: call arm_aapcscc { double, double } @__muldc3
return|return
name|a
operator|*
name|b
return|;
block|}
end_function

end_unit

