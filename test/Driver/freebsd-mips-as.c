begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check passing options to the assembler for MIPS targets.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-unknown-freebsd -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS32-EB-AS %s
end_comment

begin_comment
comment|// MIPS32-EB-AS: as{{(.exe)?}}" "-march" "mips32r2" "-mabi" "32" "-EB"
end_comment

begin_comment
comment|// MIPS32-EB-AS-NOT: "-KPIC"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-unknown-freebsd -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -fPIC -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS32-EB-PIC %s
end_comment

begin_comment
comment|// MIPS32-EB-PIC: as{{(.exe)?}}" "-march" "mips32r2" "-mabi" "32" "-EB"
end_comment

begin_comment
comment|// MIPS32-EB-PIC: "-KPIC"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-unknown-freebsd -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -fpic -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS32-EB-PIC-SMALL %s
end_comment

begin_comment
comment|// MIPS32-EB-PIC-SMALL: as{{(.exe)?}}" "-march" "mips32r2" "-mabi" "32" "-EB"
end_comment

begin_comment
comment|// MIPS32-EB-PIC-SMALL: "-KPIC"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-unknown-freebsd -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -fPIE -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS32-EB-PIE %s
end_comment

begin_comment
comment|// MIPS32-EB-PIE: as{{(.exe)?}}" "-march" "mips32r2" "-mabi" "32" "-EB"
end_comment

begin_comment
comment|// MIPS32-EB-PIE: "-KPIC"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-unknown-freebsd -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -fpie -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS32-EB-PIE-SMALL %s
end_comment

begin_comment
comment|// MIPS32-EB-PIE-SMALL: as{{(.exe)?}}" "-march" "mips32r2" "-mabi" "32" "-EB"
end_comment

begin_comment
comment|// MIPS32-EB-PIE-SMALL: "-KPIC"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mipsel-unknown-freebsd -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS32-DEF-EL-AS %s
end_comment

begin_comment
comment|// MIPS32-DEF-EL-AS: as{{(.exe)?}}" "-march" "mips32r2" "-mabi" "32" "-EL"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-unknown-freebsd -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS64-EB-AS %s
end_comment

begin_comment
comment|// MIPS64-EB-AS: as{{(.exe)?}}" "-march" "mips64r2" "-mabi" "64" "-EB"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64el-unknown-freebsd -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS64-DEF-EL-AS %s
end_comment

begin_comment
comment|// MIPS64-DEF-EL-AS: as{{(.exe)?}}" "-march" "mips64r2" "-mabi" "64" "-EL"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-unknown-freebsd -mabi=eabi -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-EABI %s
end_comment

begin_comment
comment|// MIPS-EABI: as{{(.exe)?}}" "-march" "mips32r2" "-mabi" "eabi" "-EB"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-unknown-freebsd -mabi=n32 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-N32 %s
end_comment

begin_comment
comment|// MIPS-N32: as{{(.exe)?}}" "-march" "mips64r2" "-mabi" "n32" "-EB"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mipsel-unknown-freebsd -mabi=32 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS32-EL-AS %s
end_comment

begin_comment
comment|// MIPS32-EL-AS: as{{(.exe)?}}" "-march" "mips32r2" "-mabi" "32" "-EL"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64el-unknown-freebsd -mabi=64 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS64-EL-AS %s
end_comment

begin_comment
comment|// MIPS64-EL-AS: as{{(.exe)?}}" "-march" "mips64r2" "-mabi" "64" "-EL"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-freebsd -march=mips32r2 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-32R2 %s
end_comment

begin_comment
comment|// MIPS-32R2: as{{(.exe)?}}" "-march" "mips32r2" "-mabi" "32" "-EB"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-unknown-freebsd -mips32 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ALIAS-32 %s
end_comment

begin_comment
comment|// MIPS-ALIAS-32: as{{(.exe)?}}" "-march" "mips32" "-mabi" "32" "-EB"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-unknown-freebsd -mips32r2 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ALIAS-32R2 %s
end_comment

begin_comment
comment|// MIPS-ALIAS-32R2: as{{(.exe)?}}" "-march" "mips32r2" "-mabi" "32" "-EB"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-unknown-freebsd -mips64 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ALIAS-64 %s
end_comment

begin_comment
comment|// MIPS-ALIAS-64: as{{(.exe)?}}" "-march" "mips64" "-mabi" "64" "-EB"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-unknown-freebsd -mips64r2 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ALIAS-64R2 %s
end_comment

begin_comment
comment|// MIPS-ALIAS-64R2: as{{(.exe)?}}" "-march" "mips64r2" "-mabi" "64" "-EB"
end_comment

end_unit

