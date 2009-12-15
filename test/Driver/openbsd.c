begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -ccc-clang-archs "" -ccc-host-triple i686-pc-openbsd %s -### 2> %t.log
end_comment

begin_comment
comment|// RUN: FileCheck -input-file %t.log %s
end_comment

begin_comment
comment|// CHECK: clang{{.*}}" "-cc1" "-triple" "i686-pc-openbsd"
end_comment

begin_comment
comment|// CHECK: as{{.*}}" "-o" "{{.*}}.o" "{{.*}}.s
end_comment

begin_comment
comment|// CHECK: ld{{.*}}" "-e" "__start" "--eh-frame-hdr" "-Bdynamic" "-dynamic-linker" "{{.*}}ld.so" "-o" "a.out" "{{.*}}crt0.o" "{{.*}}crtbegin.o" "{{.*}}.o" "-lgcc" "-lc" "-lgcc" "{{.*}}crtend.o"
end_comment

end_unit

