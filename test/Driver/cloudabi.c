begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang %s -### -target x86_64-unknown-cloudabi 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: "-cc1" "-triple" "x86_64-unknown-cloudabi" {{.*}} "-ffunction-sections" "-fdata-sections"
end_comment

begin_comment
comment|// CHECK: "-Bstatic" "--eh-frame-hdr" "--gc-sections" "-o" "a.out" "crt0.o" "crtbegin.o" "{{.*}}" "{{.*}}" "-lc" "-lcompiler_rt" "crtend.o"
end_comment

end_unit

