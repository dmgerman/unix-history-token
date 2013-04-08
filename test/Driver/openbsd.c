begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target i686-pc-openbsd %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD %s
end_comment

begin_comment
comment|// CHECK-LD: clang{{.*}}" "-cc1" "-triple" "i686-pc-openbsd"
end_comment

begin_comment
comment|// CHECK-LD: ld{{.*}}" "-e" "__start" "--eh-frame-hdr" "-Bdynamic" "-dynamic-linker" "{{.*}}ld.so" "-o" "a.out" "{{.*}}crt0.o" "{{.*}}crtbegin.o" "{{.*}}.o" "-lgcc" "-lc" "-lgcc" "{{.*}}crtend.o"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target i686-pc-openbsd -pg -pthread %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-PG %s
end_comment

begin_comment
comment|// CHECK-PG: clang{{.*}}" "-cc1" "-triple" "i686-pc-openbsd"
end_comment

begin_comment
comment|// CHECK-PG: ld{{.*}}" "-e" "__start" "--eh-frame-hdr" "-Bdynamic" "-dynamic-linker" "{{.*}}ld.so" "-o" "a.out" "{{.*}}gcrt0.o" "{{.*}}crtbegin.o" "{{.*}}.o" "-lgcc" "-lpthread_p" "-lc_p" "-lgcc" "{{.*}}crtend.o"
end_comment

begin_comment
comment|// Check that the new linker flags are passed to OpenBSD
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target i686-pc-openbsd -r %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD-R %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target i686-pc-openbsd -s %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD-S %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target i686-pc-openbsd -t %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD-T %s
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target i686-pc-openbsd -Z %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LD-Z %s
end_comment

begin_comment
comment|// CHECK-LD-R: clang{{.*}}" "-cc1" "-triple" "i686-pc-openbsd"
end_comment

begin_comment
comment|// CHECK-LD-R: ld{{.*}}" "-e" "__start" "--eh-frame-hdr" "-Bdynamic" "-dynamic-linker" "{{.*}}ld.so" "-o" "a.out" "{{.*}}crt0.o" "{{.*}}crtbegin.o" "-L{{.*}}" "-r" "{{.*}}.o" "-lgcc" "-lc" "-lgcc" "{{.*}}crtend.o"
end_comment

begin_comment
comment|// CHECK-LD-S: clang{{.*}}" "-cc1" "-triple" "i686-pc-openbsd"
end_comment

begin_comment
comment|// CHECK-LD-S: ld{{.*}}" "-e" "__start" "--eh-frame-hdr" "-Bdynamic" "-dynamic-linker" "{{.*}}ld.so" "-o" "a.out" "{{.*}}crt0.o" "{{.*}}crtbegin.o" "-L{{.*}}" "-s" "{{.*}}.o" "-lgcc" "-lc" "-lgcc" "{{.*}}crtend.o"
end_comment

begin_comment
comment|// CHECK-LD-T: clang{{.*}}" "-cc1" "-triple" "i686-pc-openbsd"
end_comment

begin_comment
comment|// CHECK-LD-T: ld{{.*}}" "-e" "__start" "--eh-frame-hdr" "-Bdynamic" "-dynamic-linker" "{{.*}}ld.so" "-o" "a.out" "{{.*}}crt0.o" "{{.*}}crtbegin.o" "-L{{.*}}" "-t" "{{.*}}.o" "-lgcc" "-lc" "-lgcc" "{{.*}}crtend.o"
end_comment

begin_comment
comment|// CHECK-LD-Z: clang{{.*}}" "-cc1" "-triple" "i686-pc-openbsd"
end_comment

begin_comment
comment|// CHECK-LD-Z: ld{{.*}}" "-e" "__start" "--eh-frame-hdr" "-Bdynamic" "-dynamic-linker" "{{.*}}ld.so" "-o" "a.out" "{{.*}}crt0.o" "{{.*}}crtbegin.o" "-L{{.*}}" "-Z" "{{.*}}.o" "-lgcc" "-lc" "-lgcc" "{{.*}}crtend.o"
end_comment

end_unit

