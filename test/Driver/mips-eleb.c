begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: mips-registered-target
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Check that -EL/-EB options adjust the toolchain flags.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-unknown-linux-gnu -### \
end_comment

begin_comment
comment|// RUN:        -EL -no-integrated-as %s 2>&1 \
end_comment

begin_comment
comment|// RUN:        | FileCheck -check-prefix=MIPS32-EL %s
end_comment

begin_comment
comment|// MIPS32-EL: "{{.*}}clang{{.*}}" "-cc1" "-triple" "mipsel-unknown-linux-gnu"
end_comment

begin_comment
comment|// MIPS32-EL: "{{.*}}as{{(.exe)?}}" "-march" "mips32" "-mabi" "32" "-EL"
end_comment

begin_comment
comment|// MIPS32-EL: "{{.*}}ld{{(.exe)?}}" {{.*}} "-m" "elf32ltsmip"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-unknown-linux-gnu -### \
end_comment

begin_comment
comment|// RUN:        -EL -no-integrated-as %s 2>&1 \
end_comment

begin_comment
comment|// RUN:        | FileCheck -check-prefix=MIPS64-EL %s
end_comment

begin_comment
comment|// MIPS64-EL: "{{.*}}clang{{.*}}" "-cc1" "-triple" "mips64el-unknown-linux-gnu"
end_comment

begin_comment
comment|// MIPS64-EL: "{{.*}}as{{(.exe)?}}" "-march" "mips64" "-mabi" "64" "-EL"
end_comment

begin_comment
comment|// MIPS64-EL: "{{.*}}ld{{(.exe)?}}" {{.*}} "-m" "elf64ltsmip"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mipsel-unknown-linux-gnu -### \
end_comment

begin_comment
comment|// RUN:        -EB -no-integrated-as %s 2>&1 \
end_comment

begin_comment
comment|// RUN:        | FileCheck -check-prefix=MIPS32-EB %s
end_comment

begin_comment
comment|// MIPS32-EB: "{{.*}}clang{{.*}}" "-cc1" "-triple" "mips-unknown-linux-gnu"
end_comment

begin_comment
comment|// MIPS32-EB: "{{.*}}as{{(.exe)?}}" "-march" "mips32" "-mabi" "32" "-EB"
end_comment

begin_comment
comment|// MIPS32-EB: "{{.*}}ld{{(.exe)?}}" {{.*}} "-m" "elf32btsmip"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64el-unknown-linux-gnu -### \
end_comment

begin_comment
comment|// RUN:        -EB -no-integrated-as %s 2>&1 \
end_comment

begin_comment
comment|// RUN:        | FileCheck -check-prefix=MIPS64-EB %s
end_comment

begin_comment
comment|// MIPS64-EB: "{{.*}}clang{{.*}}" "-cc1" "-triple" "mips64-unknown-linux-gnu"
end_comment

begin_comment
comment|// MIPS64-EB: "{{.*}}as{{(.exe)?}}" "-march" "mips64" "-mabi" "64" "-EB"
end_comment

begin_comment
comment|// MIPS64-EB: "{{.*}}ld{{(.exe)?}}" {{.*}} "-m" "elf64btsmip"
end_comment

end_unit

