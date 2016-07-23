begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -fopenmp -ast-print %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fopenmp -emit-pch -o %t %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fopenmp -include-pch %t -fsyntax-only -verify %s -ast-print | FileCheck %s
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
comment|// CHECK: #pragma omp declare reduction (+ : int : omp_out *= omp_in)
end_comment

begin_comment
comment|// CHECK-NEXT: #pragma omp declare reduction (+ : char : omp_out *= omp_in)
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
name|omp_orig
name|+
name|15
name|)
end_pragma

begin_comment
comment|// CHECK: #pragma omp declare reduction (fun : float : omp_out += omp_in) initializer(omp_priv = omp_orig + 15)
end_comment

begin_comment
comment|// CHECK: struct SSS {
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
comment|// CHECK: #pragma omp declare reduction (+ : int : omp_out *= omp_in)
comment|// CHECK-NEXT: #pragma omp declare reduction (+ : char : omp_out *= omp_in)
block|}
struct|;
end_struct

begin_comment
comment|// CHECK: };
end_comment

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
comment|// CHECK: #pragma omp declare reduction (fun : struct SSS : omp_out = omp_in) initializer(init(&omp_priv, omp_orig))
end_comment

begin_comment
comment|// CHECK: int main() {
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
comment|// CHECK: #pragma omp declare reduction (fun : struct SSS : omp_out = omp_in) initializer(init(&omp_priv, omp_orig))
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
comment|// CHECK: #pragma omp declare reduction (fun : struct SSS : omp_out = omp_in) initializer(init(&omp_priv, omp_orig))
block|}
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// CHECK: }
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

