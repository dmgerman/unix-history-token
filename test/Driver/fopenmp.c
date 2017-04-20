begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fopenmp=libomp -c %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-CC1-OPENMP
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fopenmp=libgomp -c %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-CC1-NO-OPENMP
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fopenmp=libiomp5 -c %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-CC1-OPENMP
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -fopenmp=libomp -c %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-CC1-OPENMP
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -fopenmp=libgomp -c %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-CC1-NO-OPENMP
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin -fopenmp=libiomp5 -c %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-CC1-OPENMP
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-freebsd -fopenmp=libomp -c %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-CC1-OPENMP
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-freebsd -fopenmp=libgomp -c %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-CC1-NO-OPENMP
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-freebsd -fopenmp=libiomp5 -c %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-CC1-OPENMP
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-netbsd -fopenmp=libomp -c %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-CC1-OPENMP
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-netbsd -fopenmp=libgomp -c %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-CC1-NO-OPENMP
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-netbsd -fopenmp=libiomp5 -c %s -### 2>&1 | FileCheck %s --check-prefix=CHECK-CC1-OPENMP
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-CC1-OPENMP: "-cc1"
end_comment

begin_comment
comment|// CHECK-CC1-OPENMP: "-fopenmp"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-CC1-NO-OPENMP: "-cc1"
end_comment

begin_comment
comment|// CHECK-CC1-NO-OPENMP-NOT: "-fopenmp"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fopenmp=libomp %s -o %t -### 2>&1 | FileCheck %s --check-prefix=CHECK-LD-OMP
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fopenmp=libgomp %s -o %t -### 2>&1 | FileCheck %s --check-prefix=CHECK-LD-GOMP --check-prefix=CHECK-LD-GOMP-RT
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fopenmp=libiomp5 %s -o %t -### 2>&1 | FileCheck %s --check-prefix=CHECK-LD-IOMP5
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -nostdlib -target x86_64-linux-gnu -fopenmp=libomp %s -o %t -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-OMP
end_comment

begin_comment
comment|// RUN: %clang -nostdlib -target x86_64-linux-gnu -fopenmp=libgomp %s -o %t -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-GOMP
end_comment

begin_comment
comment|// RUN: %clang -nostdlib -target x86_64-linux-gnu -fopenmp=libiomp5 %s -o %t -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-IOMP5
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-darwin -fopenmp=libomp %s -o %t -### 2>&1 | FileCheck %s --check-prefix=CHECK-LD-OMP
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-darwin -fopenmp=libgomp %s -o %t -### 2>&1 | FileCheck %s --check-prefix=CHECK-LD-GOMP --check-prefix=CHECK-LD-GOMP-NO-RT
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-darwin -fopenmp=libiomp5 %s -o %t -### 2>&1 | FileCheck %s --check-prefix=CHECK-LD-IOMP5
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -nostdlib -target x86_64-darwin -fopenmp=libomp %s -o %t -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-OMP
end_comment

begin_comment
comment|// RUN: %clang -nostdlib -target x86_64-darwin -fopenmp=libgomp %s -o %t -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-GOMP
end_comment

begin_comment
comment|// RUN: %clang -nostdlib -target x86_64-darwin -fopenmp=libiomp5 %s -o %t -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-IOMP5
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-freebsd -fopenmp=libomp %s -o %t -### 2>&1 | FileCheck %s --check-prefix=CHECK-LD-OMP
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-freebsd -fopenmp=libgomp %s -o %t -### 2>&1 | FileCheck %s --check-prefix=CHECK-LD-GOMP --check-prefix=CHECK-LD-GOMP-NO-RT
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-freebsd -fopenmp=libiomp5 %s -o %t -### 2>&1 | FileCheck %s --check-prefix=CHECK-LD-IOMP5
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -nostdlib -target x86_64-freebsd -fopenmp=libomp %s -o %t -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-OMP
end_comment

begin_comment
comment|// RUN: %clang -nostdlib -target x86_64-freebsd -fopenmp=libgomp %s -o %t -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-GOMP
end_comment

begin_comment
comment|// RUN: %clang -nostdlib -target x86_64-freebsd -fopenmp=libiomp5 %s -o %t -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-IOMP5
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-netbsd -fopenmp=libomp %s -o %t -### 2>&1 | FileCheck %s --check-prefix=CHECK-LD-OMP
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-netbsd -fopenmp=libgomp %s -o %t -### 2>&1 | FileCheck %s --check-prefix=CHECK-LD-GOMP --check-prefix=CHECK-LD-GOMP-NO-RT
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-netbsd -fopenmp=libiomp5 %s -o %t -### 2>&1 | FileCheck %s --check-prefix=CHECK-LD-IOMP5
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -nostdlib -target x86_64-netbsd -fopenmp=libomp %s -o %t -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-OMP
end_comment

begin_comment
comment|// RUN: %clang -nostdlib -target x86_64-netbsd -fopenmp=libgomp %s -o %t -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-GOMP
end_comment

begin_comment
comment|// RUN: %clang -nostdlib -target x86_64-netbsd -fopenmp=libiomp5 %s -o %t -### 2>&1 | FileCheck %s --check-prefix=CHECK-NO-IOMP5
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LD-OMP: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-LD-OMP: "-lomp"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LD-GOMP: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-LD-GOMP: "-lgomp"
end_comment

begin_comment
comment|// CHECK-LD-GOMP-RT: "-lrt"
end_comment

begin_comment
comment|// CHECK-LD-GOMP-NO-RT-NOT: "-lrt"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LD-IOMP5: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-LD-IOMP5: "-liomp5"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-NO-OMP: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-NO-OMP-NOT: "-lomp"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-NO-GOMP: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-NO-GOMP-NOT: "-lgomp"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-NO-IOMP5: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-NO-IOMP5-NOT: "-liomp5"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// We'd like to check that the default is sane, but until we have the ability
end_comment

begin_comment
comment|// to *always* semantically analyze OpenMP without always generating runtime
end_comment

begin_comment
comment|// calls (in the event of an unsupported runtime), we don't have a good way to
end_comment

begin_comment
comment|// test the CC1 invocation. Instead, just ensure we do eventually link *some*
end_comment

begin_comment
comment|// OpenMP runtime.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-linux-gnu -fopenmp %s -o %t -### 2>&1 | FileCheck %s --check-prefix=CHECK-LD-ANY
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-darwin -fopenmp %s -o %t -### 2>&1 | FileCheck %s --check-prefix=CHECK-LD-ANY
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-freebsd -fopenmp %s -o %t -### 2>&1 | FileCheck %s --check-prefix=CHECK-LD-ANY
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-netbsd -fopenmp %s -o %t -### 2>&1 | FileCheck %s --check-prefix=CHECK-LD-ANY
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LD-ANY: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-LD-ANY: "-l{{(omp|gomp|iomp5)}}"
end_comment

end_unit

