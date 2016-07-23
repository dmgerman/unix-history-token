begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that by default -fnoopenmp-use-tls is passed to frontend.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang %s -### -o %t.o 2>&1 -fopenmp=libomp | FileCheck --check-prefix=CHECK-DEFAULT %s
end_comment

begin_comment
comment|// CHECK-DEFAULT: -cc1
end_comment

begin_comment
comment|// CHECK-DEFAULT-NOT: -fnoopenmp-use-tls
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang %s -### -o %t.o 2>&1 -fopenmp=libomp -fnoopenmp-use-tls | FileCheck --check-prefix=CHECK-NO-TLS %s
end_comment

begin_comment
comment|// CHECK-NO-TLS: -cc1
end_comment

begin_comment
comment|// CHECK-NO-TLS-SAME: -fnoopenmp-use-tls
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang %s -c -E -dM -fopenmp=libomp | FileCheck --check-prefix=CHECK-DEFAULT-VERSION %s
end_comment

begin_comment
comment|// RUN: %clang %s -c -E -dM -fopenmp=libomp -fopenmp-version=1 | FileCheck --check-prefix=CHECK-DEFAULT-VERSION %s
end_comment

begin_comment
comment|// RUN: %clang %s -c -E -dM -fopenmp=libomp -fopenmp-version=0 | FileCheck --check-prefix=CHECK-DEFAULT-VERSION %s
end_comment

begin_comment
comment|// RUN: %clang %s -c -E -dM -fopenmp=libomp -fopenmp-version=100 | FileCheck --check-prefix=CHECK-DEFAULT-VERSION %s
end_comment

begin_comment
comment|// RUN: %clang %s -c -E -dM -fopenmp=libomp -fopenmp-version=31 | FileCheck --check-prefix=CHECK-DEFAULT-VERSION %s
end_comment

begin_comment
comment|// CHECK-DEFAULT-VERSION: #define _OPENMP 201107
end_comment

begin_comment
comment|// RUN: %clang %s -c -E -dM -fopenmp=libomp -fopenmp-version=40 | FileCheck --check-prefix=CHECK-40-VERSION %s
end_comment

begin_comment
comment|// CHECK-40-VERSION: #define _OPENMP 201307
end_comment

begin_comment
comment|// RUN: %clang %s -c -E -dM -fopenmp=libomp -fopenmp-version=45 | FileCheck --check-prefix=CHECK-45-VERSION %s
end_comment

begin_comment
comment|// CHECK-45-VERSION: #define _OPENMP 201511
end_comment

begin_comment
comment|// RUN: %clang %s -c -E -dM -fopenmp-version=1 | FileCheck --check-prefix=CHECK-VERSION %s
end_comment

begin_comment
comment|// RUN: %clang %s -c -E -dM -fopenmp-version=31 | FileCheck --check-prefix=CHECK-VERSION %s
end_comment

begin_comment
comment|// RUN: %clang %s -c -E -dM -fopenmp-version=40 | FileCheck --check-prefix=CHECK-VERSION %s
end_comment

begin_comment
comment|// RUN: %clang %s -c -E -dM -fopenmp-version=45 | FileCheck --check-prefix=CHECK-VERSION %s
end_comment

begin_comment
comment|// CHECK-VERSION-NOT: #define _OPENMP
end_comment

end_unit

