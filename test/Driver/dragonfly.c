begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -ccc-host-triple amd64-pc-dragonfly %s -### 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -input-file %t.log %s
end_comment

begin_comment
comment|// CHECK: clang{{.*}}" "-cc1" "-triple" "amd64-pc-dragonfly"
end_comment

begin_comment
comment|// CHECK: as{{.*}}" "-o" "{{.*}}.o" "{{.*}}.s
end_comment

begin_comment
comment|// CHECK: ld{{.*}}" "-dynamic-linker" "{{.*}}ld-elf.{{.*}}" "-o" "a.out" "{{.*}}crt1.o" "{{.*}}crti.o" "{{.*}}crtbegin.o" "{{.*}}.o" "-L{{.*}}/gcc{{.*}}" {{.*}} "-lc" "-lgcc" "{{.*}}crtend.o" "{{.*}}crtn.o"
end_comment

end_unit

