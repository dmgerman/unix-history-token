begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test the that the driver produces reasonable linker invocations with
end_comment

begin_comment
comment|// -fopenmp or -fopenmp|libgomp.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FIXME: Replace DEFAULT_OPENMP_LIB below with the value chosen at configure time.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -fopenmp -target i386-unknown-linux -rtlib=platform \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD-32 %s
end_comment

begin_comment
comment|// CHECK-LD-32: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-LD-32: "-l[[DEFAULT_OPENMP_LIB:[^"]*]]"
end_comment

begin_comment
comment|// CHECK-LD-32: "-lpthread" "-lc"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -fopenmp -target x86_64-unknown-linux -rtlib=platform \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD-64 %s
end_comment

begin_comment
comment|// CHECK-LD-64: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-LD-64: "-l[[DEFAULT_OPENMP_LIB:[^"]*]]"
end_comment

begin_comment
comment|// CHECK-LD-64: "-lpthread" "-lc"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -fopenmp=libgomp -target i386-unknown-linux -rtlib=platform \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-GOMP-LD-32 %s
end_comment

begin_comment
comment|// CHECK-GOMP-LD-32: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-GOMP-LD-32: "-lgomp" "-lrt"
end_comment

begin_comment
comment|// CHECK-GOMP-LD-32: "-lpthread" "-lc"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -fopenmp=libgomp -target x86_64-unknown-linux -rtlib=platform \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-GOMP-LD-64 %s
end_comment

begin_comment
comment|// CHECK-GOMP-LD-64: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-GOMP-LD-64: "-lgomp" "-lrt"
end_comment

begin_comment
comment|// CHECK-GOMP-LD-64: "-lpthread" "-lc"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -fopenmp -target i386-unknown-linux -rtlib=platform \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-IOMP5-LD-32 %s
end_comment

begin_comment
comment|// CHECK-IOMP5-LD-32: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-IOMP5-LD-32: "-l[[DEFAULT_OPENMP_LIB:[^"]*]]"
end_comment

begin_comment
comment|// CHECK-IOMP5-LD-32: "-lpthread" "-lc"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -fopenmp -target x86_64-unknown-linux -rtlib=platform \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-IOMP5-LD-64 %s
end_comment

begin_comment
comment|// CHECK-IOMP5-LD-64: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-IOMP5-LD-64: "-l[[DEFAULT_OPENMP_LIB:[^"]*]]"
end_comment

begin_comment
comment|// CHECK-IOMP5-LD-64: "-lpthread" "-lc"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -fopenmp=lib -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LIB-LD-32 %s
end_comment

begin_comment
comment|// CHECK-LIB-LD-32: error: unsupported argument 'lib' to option 'fopenmp='
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -fopenmp=lib -target x86_64-unknown-linux \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LIB-LD-64 %s
end_comment

begin_comment
comment|// CHECK-LIB-LD-64: error: unsupported argument 'lib' to option 'fopenmp='
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -fopenmp -fopenmp=libgomp -target i386-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -rtlib=platform \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD-OVERRIDE-32 %s
end_comment

begin_comment
comment|// CHECK-LD-OVERRIDE-32: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-LD-OVERRIDE-32: "-lgomp" "-lrt"
end_comment

begin_comment
comment|// CHECK-LD-OVERRIDE-32: "-lpthread" "-lc"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -fopenmp -fopenmp=libgomp -target x86_64-unknown-linux \
end_comment

begin_comment
comment|// RUN:     -rtlib=platform \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD-OVERRIDE-64 %s
end_comment

begin_comment
comment|// CHECK-LD-OVERRIDE-64: "{{.*}}ld{{(.exe)?}}"
end_comment

begin_comment
comment|// CHECK-LD-OVERRIDE-64: "-lgomp" "-lrt"
end_comment

begin_comment
comment|// CHECK-LD-OVERRIDE-64: "-lpthread" "-lc"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -fopenmp=libomp -target x86_64-msvc-win32 -rtlib=platform \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MSVC-LINK-64 %s
end_comment

begin_comment
comment|// CHECK-MSVC-LINK-64: link.exe
end_comment

begin_comment
comment|// CHECK-MSVC-LINK-64-SAME: -nodefaultlib:vcomp.lib
end_comment

begin_comment
comment|// CHECK-MSVC-LINK-64-SAME: -nodefaultlib:vcompd.lib
end_comment

begin_comment
comment|// CHECK-MSVC-LINK-64-SAME: -libpath:{{.+}}/../lib
end_comment

begin_comment
comment|// CHECK-MSVC-LINK-64-SAME: -defaultlib:libomp.lib
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     -fopenmp=libiomp5 -target x86_64-msvc-win32 -rtlib=platform \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-MSVC-ILINK-64 %s
end_comment

begin_comment
comment|// CHECK-MSVC-ILINK-64: link.exe
end_comment

begin_comment
comment|// CHECK-MSVC-ILINK-64-SAME: -nodefaultlib:vcomp.lib
end_comment

begin_comment
comment|// CHECK-MSVC-ILINK-64-SAME: -nodefaultlib:vcompd.lib
end_comment

begin_comment
comment|// CHECK-MSVC-ILINK-64-SAME: -libpath:{{.+}}/../lib
end_comment

begin_comment
comment|// CHECK-MSVC-ILINK-64-SAME: -defaultlib:libiomp5md.lib
end_comment

begin_comment
comment|//
end_comment

end_unit

