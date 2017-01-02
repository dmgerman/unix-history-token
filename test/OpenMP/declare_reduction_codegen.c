begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -fopenmp -x c -emit-llvm %s -triple %itanium_abi_triple -o - -femit-all-decls -disable-llvm-passes | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fopenmp -x c -triple %itanium_abi_triple -emit-pch -o %t %s -femit-all-decls -disable-llvm-passes
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fopenmp -x c -triple %itanium_abi_triple -include-pch %t -verify %s -emit-llvm -o - -femit-all-decls -disable-llvm-passes | FileCheck --check-prefix=CHECK-LOAD %s
end_comment

begin_comment
comment|// expected-no-diagnostics
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER
end_ifndef

begin_define
define|#
directive|define
name|HEADER
end_define

begin_comment
comment|// CHECK: [[SSS_INT:.+]] = type { i32 }
end_comment

begin_comment
comment|// CHECK-LOAD: [[SSS_INT:.+]] = type { i32 }
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|+
name|:
name|int
name|,
name|char
name|:
name|omp_out
name|*=
name|omp_in
name|)
end_pragma

begin_comment
comment|// CHECK: define internal {{.*}}void @{{[^(]+}}(i32* noalias, i32* noalias)
end_comment

begin_comment
comment|// CHECK: [[MUL:%.+]] = mul nsw i32
end_comment

begin_comment
comment|// CHECK-NEXT: store i32 [[MUL]], i32*
end_comment

begin_comment
comment|// CHECK-NEXT: ret void
end_comment

begin_comment
comment|// CHECK-NEXT: }
end_comment

begin_comment
comment|// CHECK-LOAD: define internal {{.*}}void @{{[^(]+}}(i32* noalias, i32* noalias)
end_comment

begin_comment
comment|// CHECK-LOAD: [[MUL:%.+]] = mul nsw i32
end_comment

begin_comment
comment|// CHECK-LOAD-NEXT: store i32 [[MUL]], i32*
end_comment

begin_comment
comment|// CHECK-LOAD-NEXT: ret void
end_comment

begin_comment
comment|// CHECK-LOAD-NEXT: }
end_comment

begin_comment
comment|// CHECK: define internal {{.*}}void @{{[^(]+}}(i8* noalias, i8* noalias)
end_comment

begin_comment
comment|// CHECK: sext i8
end_comment

begin_comment
comment|// CHECK: sext i8
end_comment

begin_comment
comment|// CHECK: [[MUL:%.+]] = mul nsw i32
end_comment

begin_comment
comment|// CHECK-NEXT: [[TRUNC:%.+]] = trunc i32 [[MUL]] to i8
end_comment

begin_comment
comment|// CHECK-NEXT: store i8 [[TRUNC]], i8*
end_comment

begin_comment
comment|// CHECK-NEXT: ret void
end_comment

begin_comment
comment|// CHECK-NEXT: }
end_comment

begin_comment
comment|// CHECK-LOAD: define internal {{.*}}void @{{[^(]+}}(i8* noalias, i8* noalias)
end_comment

begin_comment
comment|// CHECK-LOAD: sext i8
end_comment

begin_comment
comment|// CHECK-LOAD: sext i8
end_comment

begin_comment
comment|// CHECK-LOAD: [[MUL:%.+]] = mul nsw i32
end_comment

begin_comment
comment|// CHECK-LOAD-NEXT: [[TRUNC:%.+]] = trunc i32 [[MUL]] to i8
end_comment

begin_comment
comment|// CHECK-LOAD-NEXT: store i8 [[TRUNC]], i8*
end_comment

begin_comment
comment|// CHECK-LOAD-NEXT: ret void
end_comment

begin_comment
comment|// CHECK-LOAD-NEXT: }
end_comment

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|fun
name|:
name|float
name|:
name|omp_out
name|+=
name|omp_in
name|)
name|initializer
name|(
name|omp_priv
name|=
name|15
name|+
name|omp_orig
name|)
end_pragma

begin_comment
comment|// CHECK: define internal {{.*}}void @{{[^(]+}}(float* noalias, float* noalias)
end_comment

begin_comment
comment|// CHECK: [[ADD:%.+]] = fadd float
end_comment

begin_comment
comment|// CHECK-NEXT: store float [[ADD]], float*
end_comment

begin_comment
comment|// CHECK-NEXT: ret void
end_comment

begin_comment
comment|// CHECK-NEXT: }
end_comment

begin_comment
comment|// CHECK: define internal {{.*}}void @{{[^(]+}}(float* noalias, float* noalias)
end_comment

begin_comment
comment|// CHECK: [[ADD:%.+]] = fadd float 1.5
end_comment

begin_comment
comment|// CHECK-NEXT: store float [[ADD]], float*
end_comment

begin_comment
comment|// CHECK-NEXT: ret void
end_comment

begin_comment
comment|// CHECK-NEXT: }
end_comment

begin_comment
comment|// CHECK-LOAD: define internal {{.*}}void @{{[^(]+}}(float* noalias, float* noalias)
end_comment

begin_comment
comment|// CHECK-LOAD: [[ADD:%.+]] = fadd float
end_comment

begin_comment
comment|// CHECK-LOAD-NEXT: store float [[ADD]], float*
end_comment

begin_comment
comment|// CHECK-LOAD-NEXT: ret void
end_comment

begin_comment
comment|// CHECK-LOAD-NEXT: }
end_comment

begin_comment
comment|// CHECK-LOAD: define internal {{.*}}void @{{[^(]+}}(float* noalias, float* noalias)
end_comment

begin_comment
comment|// CHECK-LOAD: [[ADD:%.+]] = fadd float 1.5
end_comment

begin_comment
comment|// CHECK-LOAD-NEXT: store float [[ADD]], float*
end_comment

begin_comment
comment|// CHECK-LOAD-NEXT: ret void
end_comment

begin_comment
comment|// CHECK-LOAD-NEXT: }
end_comment

begin_struct
struct|struct
name|SSS
block|{
name|int
name|field
decl_stmt|;
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|+
name|:
name|int
name|,
name|char
name|:
name|omp_out
name|*=
name|omp_in
name|)
comment|// CHECK: define internal {{.*}}void @{{[^(]+}}(i32* noalias, i32* noalias)
comment|// CHECK: [[MUL:%.+]] = mul nsw i32
comment|// CHECK-NEXT: store i32 [[MUL]], i32*
comment|// CHECK-NEXT: ret void
comment|// CHECK-NEXT: }
comment|// CHECK: define internal {{.*}}void @{{[^(]+}}(i8* noalias, i8* noalias)
comment|// CHECK: sext i8
comment|// CHECK: sext i8
comment|// CHECK: [[MUL:%.+]] = mul nsw i32
comment|// CHECK-NEXT: [[TRUNC:%.+]] = trunc i32 [[MUL]] to i8
comment|// CHECK-NEXT: store i8 [[TRUNC]], i8*
comment|// CHECK-NEXT: ret void
comment|// CHECK-NEXT: }
block|}
struct|;
end_struct

begin_function_decl
name|void
name|init
parameter_list|(
name|struct
name|SSS
modifier|*
name|priv
parameter_list|,
name|struct
name|SSS
name|orig
parameter_list|)
function_decl|;
end_function_decl

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|fun
name|:
name|struct
name|SSS
name|:
name|omp_out
name|=
name|omp_in
name|)
name|initializer
name|(
name|init
name|(
name|&
name|omp_priv
name|,
name|omp_orig
name|)
name|)
end_pragma

begin_comment
comment|// CHECK: define internal {{.*}}void @{{[^(]+}}([[SSS_INT]]* noalias, [[SSS_INT]]* noalias)
end_comment

begin_comment
comment|// CHECK: call void @llvm.memcpy
end_comment

begin_comment
comment|// CHECK-NEXT: ret void
end_comment

begin_comment
comment|// CHECK-NEXT: }
end_comment

begin_comment
comment|// CHECK: define internal {{.*}}void @{{[^(]+}}([[SSS_INT]]* noalias, [[SSS_INT]]* noalias)
end_comment

begin_comment
comment|// CHECK: call void @init(
end_comment

begin_comment
comment|// CHECK-NEXT: ret void
end_comment

begin_comment
comment|// CHECK-NEXT: }
end_comment

begin_comment
comment|// CHECK-LOAD: define internal {{.*}}void @{{[^(]+}}([[SSS_INT]]* noalias, [[SSS_INT]]* noalias)
end_comment

begin_comment
comment|// CHECK-LOAD: call void @llvm.memcpy
end_comment

begin_comment
comment|// CHECK-LOAD-NEXT: ret void
end_comment

begin_comment
comment|// CHECK-LOAD-NEXT: }
end_comment

begin_comment
comment|// CHECK-LOAD: define internal {{.*}}void @{{[^(]+}}([[SSS_INT]]* noalias, [[SSS_INT]]* noalias)
end_comment

begin_comment
comment|// CHECK-LOAD: call void @init(
end_comment

begin_comment
comment|// CHECK-LOAD-NEXT: ret void
end_comment

begin_comment
comment|// CHECK-LOAD-NEXT: }
end_comment

begin_comment
comment|// CHECK-LABEL: @main
end_comment

begin_comment
comment|// CHECK-LOAD-LABEL: @main
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|fun
name|:
name|struct
name|SSS
name|:
name|omp_out
name|=
name|omp_in
name|)
name|initializer
name|(
name|init
name|(
name|&
name|omp_priv
name|,
name|omp_orig
name|)
name|)
comment|// CHECK: define internal {{.*}}void @{{[^(]+}}([[SSS_INT]]* noalias, [[SSS_INT]]* noalias)
comment|// CHECK: call void @llvm.memcpy
comment|// CHECK-NEXT: ret void
comment|// CHECK-NEXT: }
comment|// CHECK: define internal {{.*}}void @{{[^(]+}}([[SSS_INT]]* noalias, [[SSS_INT]]* noalias)
comment|// CHECK: call void @init(
comment|// CHECK-NEXT: ret void
comment|// CHECK-NEXT: }
comment|// CHECK-LOAD: define internal {{.*}}void @{{[^(]+}}([[SSS_INT]]* noalias, [[SSS_INT]]* noalias)
comment|// CHECK-LOAD: call void @llvm.memcpy
comment|// CHECK-LOAD-NEXT: ret void
comment|// CHECK-LOAD-NEXT: }
comment|// CHECK-LOAD: define internal {{.*}}void @{{[^(]+}}([[SSS_INT]]* noalias, [[SSS_INT]]* noalias)
comment|// CHECK-LOAD: call void @init(
comment|// CHECK-LOAD-NEXT: ret void
comment|// CHECK-LOAD-NEXT: }
block|{
pragma|#
directive|pragma
name|omp
name|declare
name|reduction
name|(
name|fun
name|:
name|struct
name|SSS
name|:
name|omp_out
name|=
name|omp_in
name|)
name|initializer
name|(
name|init
name|(
name|&
name|omp_priv
name|,
name|omp_orig
name|)
name|)
comment|// CHECK: define internal {{.*}}void @{{[^(]+}}([[SSS_INT]]* noalias, [[SSS_INT]]* noalias)
comment|// CHECK: call void @llvm.memcpy
comment|// CHECK-NEXT: ret void
comment|// CHECK-NEXT: }
comment|// CHECK: define internal {{.*}}void @{{[^(]+}}([[SSS_INT]]* noalias, [[SSS_INT]]* noalias)
comment|// CHECK: call void @init(
comment|// CHECK-NEXT: ret void
comment|// CHECK-NEXT: }
comment|// CHECK-LOAD: define internal {{.*}}void @{{[^(]+}}([[SSS_INT]]* noalias, [[SSS_INT]]* noalias)
comment|// CHECK-LOAD: call void @llvm.memcpy
comment|// CHECK-LOAD-NEXT: ret void
comment|// CHECK-LOAD-NEXT: }
comment|// CHECK-LOAD: define internal {{.*}}void @{{[^(]+}}([[SSS_INT]]* noalias, [[SSS_INT]]* noalias)
comment|// CHECK-LOAD: call void @init(
comment|// CHECK-LOAD-NEXT: ret void
comment|// CHECK-LOAD-NEXT: }
block|}
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK-LOAD: define internal {{.*}}void @{{[^(]+}}(i32* noalias, i32* noalias)
end_comment

begin_comment
comment|// CHECK-LOAD: [[MUL:%.+]] = mul nsw i32
end_comment

begin_comment
comment|// CHECK-LOAD-NEXT: store i32 [[MUL]], i32*
end_comment

begin_comment
comment|// CHECK-LOAD-NEXT: ret void
end_comment

begin_comment
comment|// CHECK-LOAD-NEXT: }
end_comment

begin_comment
comment|// CHECK-LOAD: define internal {{.*}}void @{{[^(]+}}(i8* noalias, i8* noalias)
end_comment

begin_comment
comment|// CHECK-LOAD: sext i8
end_comment

begin_comment
comment|// CHECK-LOAD: sext i8
end_comment

begin_comment
comment|// CHECK-LOAD: [[MUL:%.+]] = mul nsw i32
end_comment

begin_comment
comment|// CHECK-LOAD-NEXT: [[TRUNC:%.+]] = trunc i32 [[MUL]] to i8
end_comment

begin_comment
comment|// CHECK-LOAD-NEXT: store i8 [[TRUNC]], i8*
end_comment

begin_comment
comment|// CHECK-LOAD-NEXT: ret void
end_comment

begin_comment
comment|// CHECK-LOAD-NEXT: }
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

