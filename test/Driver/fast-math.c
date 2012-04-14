begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that the GCC fast-math floating point flags get lowered to the correct
end_comment

begin_comment
comment|// permutation of Clang frontend flags. This is non-trivial for a few reasons.
end_comment

begin_comment
comment|// First, the GCC flags have many different and surprising effects. Second,
end_comment

begin_comment
comment|// LLVM only supports three switches which is more coarse grained than GCC's
end_comment

begin_comment
comment|// support.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -fno-honor-infinities -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-INFS %s
end_comment

begin_comment
comment|// CHECK-NO-INFS: "-cc1"
end_comment

begin_comment
comment|// CHECK-NO-INFS: "-menable-no-infs"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -fno-honor-nans -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-NANS %s
end_comment

begin_comment
comment|// CHECK-NO-NANS: "-cc1"
end_comment

begin_comment
comment|// CHECK-NO-NANS: "-menable-no-nans"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -fmath-errno -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MATH-ERRNO %s
end_comment

begin_comment
comment|// CHECK-MATH-ERRNO: "-cc1"
end_comment

begin_comment
comment|// CHECK-MATH-ERRNO: "-fmath-errno"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -fassociative-math -freciprocal-math -fno-signed-zeros \
end_comment

begin_comment
comment|// RUN:     -fno-trapping-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-UNSAFE-MATH %s
end_comment

begin_comment
comment|// CHECK-UNSAFE-MATH: "-cc1"
end_comment

begin_comment
comment|// CHECK-UNSAFE-MATH: "-menable-unsafe-fp-math"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check that various umbrella flags also enable these frontend options.
end_comment

begin_comment
comment|// RUN: %clang -### -ffast-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-INFS %s
end_comment

begin_comment
comment|// RUN: %clang -### -ffast-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-NANS %s
end_comment

begin_comment
comment|// RUN: %clang -### -ffast-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-UNSAFE-MATH %s
end_comment

begin_comment
comment|// RUN: %clang -### -ffinite-math-only -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-INFS %s
end_comment

begin_comment
comment|// RUN: %clang -### -ffinite-math-only -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-NANS %s
end_comment

begin_comment
comment|// RUN: %clang -### -funsafe-math-optimizations -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-UNSAFE-MATH %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// One umbrella flag is *really* weird and also changes the semantics of the
end_comment

begin_comment
comment|// program by adding a special preprocessor macro. Check that the frontend flag
end_comment

begin_comment
comment|// modeling this semantic change is provided. Also check that the semantic
end_comment

begin_comment
comment|// impact remains even if every optimization is disabled.
end_comment

begin_comment
comment|// RUN: %clang -### -ffast-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-FAST-MATH %s
end_comment

begin_comment
comment|// RUN: %clang -### -ffast-math -fno-finite-math-only \
end_comment

begin_comment
comment|// RUN:     -fno-unsafe-math-optimizations -fmath-errno -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-FAST-MATH %s
end_comment

begin_comment
comment|// CHECK-FAST-MATH: "-cc1"
end_comment

begin_comment
comment|// CHECK-FAST-MATH: "-ffast-math"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check various means of disabling these flags, including disabling them after
end_comment

begin_comment
comment|// they've been enabled via an umbrella flag.
end_comment

begin_comment
comment|// RUN: %clang -### -fno-honor-infinities -fhonor-infinities -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-NO-INFS %s
end_comment

begin_comment
comment|// RUN: %clang -### -ffinite-math-only -fhonor-infinities -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-NO-INFS %s
end_comment

begin_comment
comment|// RUN: %clang -### -ffinite-math-only -fno-finite-math-only -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-NO-INFS %s
end_comment

begin_comment
comment|// RUN: %clang -### -ffast-math -fhonor-infinities -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-NO-INFS %s
end_comment

begin_comment
comment|// RUN: %clang -### -ffast-math -fno-finite-math-only -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-NO-INFS %s
end_comment

begin_comment
comment|// CHECK-NO-NO-INFS: "-cc1"
end_comment

begin_comment
comment|// CHECK-NO-NO-INFS-NOT: "-menable-no-infs"
end_comment

begin_comment
comment|// CHECK-NO-NO-INFS: "-o"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -fno-honor-nans -fhonor-nans -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-NO-NANS %s
end_comment

begin_comment
comment|// RUN: %clang -### -ffinite-math-only -fhonor-nans -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-NO-NANS %s
end_comment

begin_comment
comment|// RUN: %clang -### -ffinite-math-only -fno-finite-math-only -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-NO-NANS %s
end_comment

begin_comment
comment|// RUN: %clang -### -ffast-math -fhonor-nans -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-NO-NANS %s
end_comment

begin_comment
comment|// RUN: %clang -### -ffast-math -fno-finite-math-only -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-NO-NANS %s
end_comment

begin_comment
comment|// CHECK-NO-NO-NANS: "-cc1"
end_comment

begin_comment
comment|// CHECK-NO-NO-NANS-NOT: "-menable-no-nans"
end_comment

begin_comment
comment|// CHECK-NO-NO-NANS: "-o"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -fassociative-math -freciprocal-math -fno-signed-zeros \
end_comment

begin_comment
comment|// RUN:     -fno-trapping-math -fno-associative-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-UNSAFE-MATH %s
end_comment

begin_comment
comment|// RUN: %clang -### -fassociative-math -freciprocal-math -fno-signed-zeros \
end_comment

begin_comment
comment|// RUN:     -fno-trapping-math -fno-reciprocal-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-UNSAFE-MATH %s
end_comment

begin_comment
comment|// RUN: %clang -### -fassociative-math -freciprocal-math -fno-signed-zeros \
end_comment

begin_comment
comment|// RUN:     -fno-trapping-math -fsigned-zeros -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-UNSAFE-MATH %s
end_comment

begin_comment
comment|// RUN: %clang -### -fassociative-math -freciprocal-math -fno-signed-zeros \
end_comment

begin_comment
comment|// RUN:     -fno-trapping-math -ftrapping-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-UNSAFE-MATH %s
end_comment

begin_comment
comment|// RUN: %clang -### -funsafe-math-optimizations -fno-associative-math -c %s \
end_comment

begin_comment
comment|// RUN:   2>&1 | FileCheck --check-prefix=CHECK-NO-UNSAFE-MATH %s
end_comment

begin_comment
comment|// RUN: %clang -### -funsafe-math-optimizations -fno-reciprocal-math -c %s \
end_comment

begin_comment
comment|// RUN:   2>&1 | FileCheck --check-prefix=CHECK-NO-UNSAFE-MATH %s
end_comment

begin_comment
comment|// RUN: %clang -### -funsafe-math-optimizations -fsigned-zeros -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-UNSAFE-MATH %s
end_comment

begin_comment
comment|// RUN: %clang -### -funsafe-math-optimizations -ftrapping-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-UNSAFE-MATH %s
end_comment

begin_comment
comment|// RUN: %clang -### -funsafe-math-optimizations -fno-unsafe-math-optimizations \
end_comment

begin_comment
comment|// RUN:     -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-UNSAFE-MATH %s
end_comment

begin_comment
comment|// RUN: %clang -### -ffast-math -fno-associative-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-UNSAFE-MATH %s
end_comment

begin_comment
comment|// RUN: %clang -### -ffast-math -fno-reciprocal-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-UNSAFE-MATH %s
end_comment

begin_comment
comment|// RUN: %clang -### -ffast-math -fsigned-zeros -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-UNSAFE-MATH %s
end_comment

begin_comment
comment|// RUN: %clang -### -ffast-math -ftrapping-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-UNSAFE-MATH %s
end_comment

begin_comment
comment|// RUN: %clang -### -ffast-math -fno-unsafe-math-optimizations -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-UNSAFE-MATH %s
end_comment

begin_comment
comment|// CHECK-NO-UNSAFE-MATH: "-cc1"
end_comment

begin_comment
comment|// CHECK-NO-UNSAFE-MATH-NOT: "-menable-unsafe-fp-math"
end_comment

begin_comment
comment|// CHECK-NO-UNSAFE-MATH: "-o"
end_comment

end_unit

