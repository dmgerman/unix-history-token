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
comment|// Both of them use gcc driver for as.
end_comment

begin_comment
comment|// REQUIRES: clang-driver
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
comment|// infinites [sic] is a supported alternative spelling of infinities.
end_comment

begin_comment
comment|// RUN: %clang -### -fno-honor-infinites -c %s 2>&1 \
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
comment|// RUN: %clang -### -fno-fast-math -fno-honor-infinities -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-FAST-MATH-NO-INFS %s
end_comment

begin_comment
comment|// CHECK-NO-FAST-MATH-NO-INFS: "-cc1"
end_comment

begin_comment
comment|// CHECK-NO-FAST-MATH-NO-INFS: "-menable-no-infs"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -fno-honor-infinities -fno-fast-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-INFS-NO-FAST-MATH %s
end_comment

begin_comment
comment|// CHECK-NO-INFS-NO-FAST-MATH: "-cc1"
end_comment

begin_comment
comment|// CHECK-NO-INFS-NO-FAST-MATH-NOT: "-menable-no-infs"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -fno-signed-zeros -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-SIGNED-ZEROS %s
end_comment

begin_comment
comment|// CHECK-NO-SIGNED-ZEROS: "-cc1"
end_comment

begin_comment
comment|// CHECK-NO-SIGNED-ZEROS: "-fno-signed-zeros"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -fno-fast-math -fno-signed-zeros -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-FAST-MATH-NO-SIGNED-ZEROS %s
end_comment

begin_comment
comment|// CHECK-NO-FAST-MATH-NO-SIGNED-ZEROS: "-cc1"
end_comment

begin_comment
comment|// CHECK-NO-FAST-MATH-NO-SIGNED-ZEROS: "-fno-signed-zeros"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -fno-signed-zeros -fno-fast-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-SIGNED-ZEROS-NO-FAST-MATH %s
end_comment

begin_comment
comment|// CHECK-NO-SIGNED-ZEROS-NO-FAST-MATH: "-cc1"
end_comment

begin_comment
comment|// CHECK-NO-SIGNED-ZEROS-NO-FAST-MATH-NOT: "-fno-signed-zeros"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -freciprocal-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-RECIPROCAL-MATH %s
end_comment

begin_comment
comment|// CHECK-RECIPROCAL-MATH: "-cc1"
end_comment

begin_comment
comment|// CHECK-RECIPROCAL-MATH: "-freciprocal-math"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -fno-fast-math -freciprocal-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-FAST-MATH-RECIPROCAL-MATH %s
end_comment

begin_comment
comment|// CHECK-NO-FAST-MATH-RECIPROCAL-MATH: "-cc1"
end_comment

begin_comment
comment|// CHECK-NO-FAST-MATH-RECIPROCAL-MATH: "-freciprocal-math"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -freciprocal-math -fno-fast-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-RECIPROCAL-MATH-NO-FAST-MATH %s
end_comment

begin_comment
comment|// CHECK-RECIPROCAL-MATH-NO-FAST-MATH: "-cc1"
end_comment

begin_comment
comment|// CHECK-RECIPROCAL-MATH-NO-FAST-MATH-NOT: "-freciprocal-math"
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
comment|// RUN: %clang -### -fno-fast-math -fno-honor-nans -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-FAST-MATH-NO-NANS %s
end_comment

begin_comment
comment|// CHECK-NO-FAST-MATH-NO-NANS: "-cc1"
end_comment

begin_comment
comment|// CHECK-NO-FAST-MATH-NO-NANS: "-menable-no-nans"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -fno-honor-nans -fno-fast-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-NANS-NO-FAST-MATH %s
end_comment

begin_comment
comment|// CHECK-NO-NANS-NO-FAST-MATH: "-cc1"
end_comment

begin_comment
comment|// CHECK-NO-NANS-NO-FAST-MATH-NOT: "-menable-no-nans"
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
comment|// RUN: %clang -### -fmath-errno -fno-math-errno -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-MATH-ERRNO %s
end_comment

begin_comment
comment|// CHECK-NO-MATH-ERRNO: "-cc1"
end_comment

begin_comment
comment|// CHECK-NO-MATH-ERRNO-NOT: "-fmath-errno"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Target defaults for -fmath-errno (reusing the above checks).
end_comment

begin_comment
comment|// RUN: %clang -### -target i686-unknown-linux -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MATH-ERRNO %s
end_comment

begin_comment
comment|// RUN: %clang -### -target i686-apple-darwin -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-MATH-ERRNO %s
end_comment

begin_comment
comment|// RUN: %clang -### -target x86_64-unknown-freebsd -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-MATH-ERRNO %s
end_comment

begin_comment
comment|// RUN: %clang -### -target x86_64-unknown-netbsd -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-MATH-ERRNO %s
end_comment

begin_comment
comment|// RUN: %clang -### -target x86_64-unknown-openbsd -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-MATH-ERRNO %s
end_comment

begin_comment
comment|// RUN: %clang -### -target x86_64-unknown-dragonfly -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-MATH-ERRNO %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check that -ffast-math disables -fmath-errno, and -fno-fast-math merely
end_comment

begin_comment
comment|// preserves the target default. Also check various flag set operations between
end_comment

begin_comment
comment|// the two flags. (Resuses above checks.)
end_comment

begin_comment
comment|// RUN: %clang -### -ffast-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-MATH-ERRNO %s
end_comment

begin_comment
comment|// RUN: %clang -### -fmath-errno -ffast-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-MATH-ERRNO %s
end_comment

begin_comment
comment|// RUN: %clang -### -ffast-math -fmath-errno -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MATH-ERRNO %s
end_comment

begin_comment
comment|// RUN: %clang -### -target i686-unknown-linux -fno-fast-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MATH-ERRNO %s
end_comment

begin_comment
comment|// RUN: %clang -### -target i686-unknown-linux -fno-math-errno -fno-fast-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MATH-ERRNO %s
end_comment

begin_comment
comment|// RUN: %clang -### -target i686-apple-darwin -fno-fast-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-MATH-ERRNO %s
end_comment

begin_comment
comment|// RUN: %clang -### -target i686-apple-darwin -fno-math-errno -fno-fast-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-MATH-ERRNO %s
end_comment

begin_comment
comment|// RUN: %clang -### -fno-fast-math -fno-math-errno -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-MATH-ERRNO %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -fno-math-errno -fassociative-math -freciprocal-math \
end_comment

begin_comment
comment|// RUN:     -fno-signed-zeros -fno-trapping-math -c %s 2>&1 \
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
comment|// RUN: %clang -### -fno-fast-math -fno-math-errno -fassociative-math -freciprocal-math \
end_comment

begin_comment
comment|// RUN:     -fno-signed-zeros -fno-trapping-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-FAST-MATH-UNSAFE-MATH %s
end_comment

begin_comment
comment|// CHECK-NO-FAST-MATH-UNSAFE-MATH: "-cc1"
end_comment

begin_comment
comment|// CHECK-NO-FAST-MATH-UNSAFE-MATH: "-menable-unsafe-fp-math"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -fno-fast-math -fno-math-errno -fassociative-math -freciprocal-math \
end_comment

begin_comment
comment|// RUN:     -fno-fast-math -fno-signed-zeros -fno-trapping-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-UNSAFE-MATH-NO-FAST-MATH %s
end_comment

begin_comment
comment|// CHECK-UNSAFE-MATH-NO-FAST-MATH: "-cc1"
end_comment

begin_comment
comment|// CHECK-UNSAFE-MATH-NO-FAST-MATH-NOT: "-menable-unsafe-fp-math"
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
comment|// RUN: %clang -### -funsafe-math-optimizations -fno-math-errno -c %s 2>&1 \
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
comment|// modeling this semantic change is provided. Also check that the flag is not
end_comment

begin_comment
comment|// present if any of the optimization is disabled.
end_comment

begin_comment
comment|// RUN: %clang -### -ffast-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-FAST-MATH %s
end_comment

begin_comment
comment|// RUN: %clang -### -fno-fast-math -ffast-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-FAST-MATH %s
end_comment

begin_comment
comment|// RUN: %clang -### -funsafe-math-optimizations -ffinite-math-only \
end_comment

begin_comment
comment|// RUN:     -fno-math-errno -ffp-contract=fast -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-FAST-MATH %s
end_comment

begin_comment
comment|// RUN: %clang -### -fno-honor-infinities -fno-honor-nans -fno-math-errno \
end_comment

begin_comment
comment|// RUN:     -fassociative-math -freciprocal-math -fno-signed-zeros \
end_comment

begin_comment
comment|// RUN:     -fno-trapping-math -ffp-contract=fast -c %s 2>&1 \
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
comment|// CHECK-FAST-MATH: "-ffinite-math-only"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -ffast-math -fno-fast-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-FAST-MATH %s
end_comment

begin_comment
comment|// RUN: %clang -### -ffast-math -fno-finite-math-only -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-FAST-MATH %s
end_comment

begin_comment
comment|// RUN: %clang -### -ffast-math -fno-unsafe-math-optimizations -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-FAST-MATH %s
end_comment

begin_comment
comment|// RUN: %clang -### -ffast-math -fmath-errno -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-FAST-MATH %s
end_comment

begin_comment
comment|// CHECK-NO-FAST-MATH: "-cc1"
end_comment

begin_comment
comment|// CHECK-NO-FAST-MATH-NOT: "-ffast-math"
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
comment|// CHECK-NO-NO-INFS-NOT: "-ffinite-math-only"
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
comment|// CHECK-NO-NO-NANS-NOT: "-ffinite-math-only"
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

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -### -ftrapping-math -fno-trapping-math -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-NO-TRAPPING-MATH %s
end_comment

begin_comment
comment|// CHECK-NO-TRAPPING-MATH: "-fno-trapping-math"
end_comment

end_unit

