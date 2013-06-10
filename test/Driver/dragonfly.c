begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target x86_64-pc-dragonfly %s -### 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -input-file %t.log %s
end_comment

begin_comment
comment|// CHECK: clang{{.*}}" "-cc1" "-triple" "x86_64-pc-dragonfly"
end_comment

begin_comment
comment|// CHECK: ld{{.*}}" "--eh-frame-hdr" "-dynamic-linker" "/usr/libexec/ld-elf.so.{{.*}}" "--hash-style=both" "-o" "a.out" "{{.*}}crt1.o" "{{.*}}crti.o" "{{.*}}crtbegin.o" "{{.*}}.o" "-L{{.*}}gcc4{{.*}}" "-rpath" "{{.*}}gcc4{{.*}}" "-lc" "-lgcc" "{{.*}}crtend.o" "{{.*}}crtn.o"
end_comment

end_unit

