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
name|simd
name|aligned
name|(
name|b
name|:
name|64
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|simd
name|simdlen
name|(
name|32
name|)
name|aligned
name|(
name|d
name|,
name|b
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|simd
name|inbranch
name|,
name|uniform
name|(
name|d
name|)
name|linear
name|(
name|val
name|(
name|s1
name|,
name|s2
name|)
name|:
name|32
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|omp
name|declare
name|simd
name|notinbranch
name|simdlen
name|(
name|2
name|)
name|,
name|uniform
name|(
name|s1
name|,
name|s2
name|)
name|linear
name|(
name|d
name|:
name|s1
name|)
end_pragma

begin_function_decl
name|void
name|add_1
parameter_list|(
name|float
modifier|*
name|d
parameter_list|,
name|int
name|s1
parameter_list|,
name|float
modifier|*
name|s2
parameter_list|,
name|double
name|b
index|[]
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(cold
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// CHECK: #pragma omp declare simd notinbranch simdlen(2) uniform(s1, s2) linear(val(d): s1)
end_comment

begin_comment
comment|// CHECK-NEXT: #pragma omp declare simd inbranch uniform(d) linear(val(s1): 32) linear(val(s2): 32)
end_comment

begin_comment
comment|// CHECK-NEXT: #pragma omp declare simd simdlen(32) aligned(d) aligned(b)
end_comment

begin_comment
comment|// CHECK-NEXT: #pragma omp declare simd aligned(b: 64)
end_comment

begin_comment
comment|// CHECK-NEXT: void add_1(float *d, int s1, float *s2, double b[]) __attribute__((cold))
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

