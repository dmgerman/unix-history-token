begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check passing options to the assembler for MIPS targets.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS32R2-EB-AS %s
end_comment

begin_comment
comment|// RUN: %clang -target mipsel-linux-gnu -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c -EB %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS32R2-EB-AS %s
end_comment

begin_comment
comment|// MIPS32R2-EB-AS: as{{(.exe)?}}" "-march" "mips32r2" "-mabi" "32" "-mno-shared" "-call_nonpic" "-EB"
end_comment

begin_comment
comment|// MIPS32R2-EB-AS-NOT: "{{[ A-Za-z\\\/]*}}as{{(.exe)?}}{{.*}}"-KPIC"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -fPIC -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS32R2-EB-PIC %s
end_comment

begin_comment
comment|// MIPS32R2-EB-PIC: as{{(.exe)?}}" "-march" "mips32r2" "-mabi" "32" "-call_nonpic" "-EB"
end_comment

begin_comment
comment|// MIPS32R2-EB-PIC: "-KPIC"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mipsel-linux-gnu -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS32R2-DEF-EL-AS %s
end_comment

begin_comment
comment|// MIPS32R2-DEF-EL-AS: as{{(.exe)?}}" "-march" "mips32r2" "-mabi" "32" "-mno-shared" "-call_nonpic" "-EL"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -fno-pic -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS64R2-EB-AS %s
end_comment

begin_comment
comment|// MIPS64R2-EB-AS: as{{(.exe)?}}" "-march" "mips64r2" "-mabi" "64" "-mno-shared" "-EB"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS64R2-EB-AS-PIC %s
end_comment

begin_comment
comment|// MIPS64R2-EB-AS-PIC: as{{(.exe)?}}" "-march" "mips64r2" "-mabi" "64" "-EB" "-KPIC"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64el-linux-gnu -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c -fno-pic %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS64R2-DEF-EL-AS %s
end_comment

begin_comment
comment|// MIPS64R2-DEF-EL-AS: as{{(.exe)?}}" "-march" "mips64r2" "-mabi" "64"  "-mno-shared" "-EL"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64el-linux-gnu -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS64R2-DEF-EL-AS-PIC %s
end_comment

begin_comment
comment|// MIPS64R2-DEF-EL-AS-PIC: as{{(.exe)?}}" "-march" "mips64r2" "-mabi" "64" "-EL" "-KPIC"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -mabi=n32 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-N32-PIC %s
end_comment

begin_comment
comment|// MIPS-N32-PIC: as{{(.exe)?}}" "-march" "mips64r2" "-mabi" "n32" "-call_nonpic" "-EB" "-KPIC"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -mabi=n32 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s -fno-pic 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-N32 %s
end_comment

begin_comment
comment|// MIPS-N32: as{{(.exe)?}}" "-march" "mips64r2" "-mabi" "n32" "-mno-shared" "-call_nonpic" "-EB"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mipsel-linux-gnu -mabi=32 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS32R2-EL-AS %s
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mabi=32 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s -EL 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS32R2-EL-AS %s
end_comment

begin_comment
comment|// MIPS32R2-EL-AS: as{{(.exe)?}}" "-march" "mips32r2" "-mabi" "32" "-mno-shared" "-call_nonpic" "-EL"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64el-linux-gnu -mabi=64 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS64R2-EL-AS-PIC %s
end_comment

begin_comment
comment|// MIPS64R2-EL-AS-PIC: as{{(.exe)?}}" "-march" "mips64r2" "-mabi" "64" "-EL" "-KPIC"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64el-linux-gnu -mabi=64 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s -fno-pic 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS64R2-EL-AS %s
end_comment

begin_comment
comment|// MIPS64R2-EL-AS: as{{(.exe)?}}" "-march" "mips64r2" "-mabi" "64" "-mno-shared" "-EL"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -march=mips32r2 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-32R2 %s
end_comment

begin_comment
comment|// MIPS-32R2: as{{(.exe)?}}" "-march" "mips32r2" "-mabi" "32" "-mno-shared" "-call_nonpic" "-EB"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -march=p5600 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-P5600 %s
end_comment

begin_comment
comment|// MIPS-P5600: as{{(.exe)?}}" "-march" "p5600" "-mabi" "32" "-mno-shared" "-call_nonpic" "-EB"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -march=octeon -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-OCTEON-PIC %s
end_comment

begin_comment
comment|// MIPS-OCTEON-PIC: as{{(.exe)?}}" "-march" "octeon" "-mabi" "64" "-EB" "-KPIC"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -march=octeon -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s -fno-pic 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-OCTEON %s
end_comment

begin_comment
comment|// MIPS-OCTEON: as{{(.exe)?}}" "-march" "octeon" "-mabi" "64" "-mno-shared" "-EB"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mips1 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ALIAS-1 %s
end_comment

begin_comment
comment|// MIPS-ALIAS-1: as{{(.exe)?}}" "-march" "mips1" "-mabi" "32" "-mno-shared" "-call_nonpic" "-EB"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mips2 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ALIAS-2 %s
end_comment

begin_comment
comment|// MIPS-ALIAS-2: as{{(.exe)?}}" "-march" "mips2" "-mabi" "32" "-mno-shared" "-call_nonpic" "-EB"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mips3 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ALIAS-3 %s
end_comment

begin_comment
comment|// MIPS-ALIAS-3: as{{(.exe)?}}" "-march" "mips3" "-mabi" "32" "-mno-shared" "-call_nonpic" "-EB"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mips4 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ALIAS-4 %s
end_comment

begin_comment
comment|// MIPS-ALIAS-4: as{{(.exe)?}}" "-march" "mips4" "-mabi" "32" "-mno-shared" "-call_nonpic" "-EB"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mips5 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ALIAS-5 %s
end_comment

begin_comment
comment|// MIPS-ALIAS-5: as{{(.exe)?}}" "-march" "mips5" "-mabi" "32" "-mno-shared" "-call_nonpic" "-EB"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mips32 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ALIAS-32 %s
end_comment

begin_comment
comment|// MIPS-ALIAS-32: as{{(.exe)?}}" "-march" "mips32" "-mabi" "32" "-mno-shared" "-call_nonpic" "-EB"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mips32r2 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ALIAS-32R2 %s
end_comment

begin_comment
comment|// MIPS-ALIAS-32R2: as{{(.exe)?}}" "-march" "mips32r2" "-mabi" "32" "-mno-shared" "-call_nonpic" "-EB"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mips32r3 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ALIAS-32R3 %s
end_comment

begin_comment
comment|// MIPS-ALIAS-32R3: as{{(.exe)?}}" "-march" "mips32r3" "-mabi" "32" "-mno-shared" "-call_nonpic" "-EB"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mips32r5 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ALIAS-32R5 %s
end_comment

begin_comment
comment|// MIPS-ALIAS-32R5: as{{(.exe)?}}" "-march" "mips32r5" "-mabi" "32" "-mno-shared" "-call_nonpic" "-EB"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mips32r6 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ALIAS-32R6 %s
end_comment

begin_comment
comment|// MIPS-ALIAS-32R6: as{{(.exe)?}}" "-march" "mips32r6" "-mabi" "32" "-mno-shared" "-call_nonpic" "-EB"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -mips64 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ALIAS-64-PIC %s
end_comment

begin_comment
comment|// MIPS-ALIAS-64-PIC: as{{(.exe)?}}" "-march" "mips64" "-mabi" "64" "-EB" "-KPIC"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -mips64 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c -fno-pic %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ALIAS-64 %s
end_comment

begin_comment
comment|// MIPS-ALIAS-64: as{{(.exe)?}}" "-march" "mips64" "-mabi" "64" "-mno-shared" "-EB"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -mips64r2 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ALIAS-64R2-PIC %s
end_comment

begin_comment
comment|// MIPS-ALIAS-64R2-PIC: as{{(.exe)?}}" "-march" "mips64r2" "-mabi" "64" "-EB" "-KPIC"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -mips64r3 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ALIAS-64R3-PIC %s
end_comment

begin_comment
comment|// MIPS-ALIAS-64R3-PIC: as{{(.exe)?}}" "-march" "mips64r3" "-mabi" "64" "-EB" "-KPIC"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -mips64r3 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s -fno-pic 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ALIAS-64R3 %s
end_comment

begin_comment
comment|// MIPS-ALIAS-64R3: as{{(.exe)?}}" "-march" "mips64r3" "-mabi" "64" "-mno-shared" "-EB"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -mips64r5 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ALIAS-64R5-PIC %s
end_comment

begin_comment
comment|// MIPS-ALIAS-64R5-PIC: as{{(.exe)?}}" "-march" "mips64r5" "-mabi" "64" "-EB" "-KPIC"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -mips64r5 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s -fno-pic 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ALIAS-64R5 %s
end_comment

begin_comment
comment|// MIPS-ALIAS-64R5: as{{(.exe)?}}" "-march" "mips64r5" "-mabi" "64" "-mno-shared" "-EB"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -mips64r6 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ALIAS-64R6-PIC %s
end_comment

begin_comment
comment|// MIPS-ALIAS-64R6-PIC: as{{(.exe)?}}" "-march" "mips64r6" "-mabi" "64" "-EB" "-KPIC"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -mips64r6 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s -fno-pic 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-ALIAS-64R6 %s
end_comment

begin_comment
comment|// MIPS-ALIAS-64R6: as{{(.exe)?}}" "-march" "mips64r6" "-mabi" "64" "-mno-shared" "-EB"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mno-mips16 -mips16 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-16 %s
end_comment

begin_comment
comment|// MIPS-16: as{{(.exe)?}}" "-march" "mips32r2" "-mabi" "32" "-mno-shared" "-call_nonpic" "-EB" "-mips16"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mips16 -mno-mips16 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-N16 %s
end_comment

begin_comment
comment|// MIPS-N16: as{{(.exe)?}}"
end_comment

begin_comment
comment|// MIPS-N16: -no-mips16
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mno-micromips -mmicromips -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-MICRO %s
end_comment

begin_comment
comment|// MIPS-MICRO: as{{(.exe)?}}" "-march" "mips32r2" "-mabi" "32" "-mno-shared" "-call_nonpic" "-EB" "-mmicromips"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mmicromips -mno-micromips -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-NMICRO %s
end_comment

begin_comment
comment|// MIPS-NMICRO: as{{(.exe)?}}"
end_comment

begin_comment
comment|// MIPS-NMICRO-NOT: {{[A-Za-z\\\/]*}}as{{(.exe)?}}{{.*}}"-mmicromips"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mno-dsp -mdsp -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-DSP %s
end_comment

begin_comment
comment|// MIPS-DSP: as{{(.exe)?}}" "-march" "mips32r2" "-mabi" "32" "-mno-shared" "-call_nonpic" "-EB" "-mdsp"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mdsp -mno-dsp -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-NDSP %s
end_comment

begin_comment
comment|// MIPS-NDSP: as{{(.exe)?}}"
end_comment

begin_comment
comment|// MIPS-NDSP-NOT: "{{[ A-Za-z\\\/]*}}as{{(.exe)?}}{{.*}}"-mdsp"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mno-dspr2 -mdspr2 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-DSPR2 %s
end_comment

begin_comment
comment|// MIPS-DSPR2: as{{(.exe)?}}" "-march" "mips32r2" "-mabi" "32" "-mno-shared" "-call_nonpic" "-EB" "-mdspr2"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mdspr2 -mno-dspr2 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-NDSPR2 %s
end_comment

begin_comment
comment|// MIPS-NDSPR2: as{{(.exe)?}}"
end_comment

begin_comment
comment|// MIPS-NDSPR2-NOT: "{{[ A-Za-z\\\/]*}}as{{(.exe)?}}{{.*}}"-mdspr2"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mnan=legacy -mnan=2008 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-NAN2008 %s
end_comment

begin_comment
comment|// MIPS-NAN2008: as{{(.exe)?}}" "-march" "mips32r2" "-mabi" "32" "-mno-shared" "-call_nonpic" "-EB" "-mnan=2008"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mnan=2008 -mnan=legacy -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-NAN-LEGACY %s
end_comment

begin_comment
comment|// MIPS-NAN-LEGACY: as{{(.exe)?}}"
end_comment

begin_comment
comment|// MIPS-NAN-LEGACY-NOT: "{{[ A-Za-z\\\/]*}}as{{(.exe)?}}{{.*}}"-mnan={{.*}}"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mfp64 -mfpxx -mfp32 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-MFP32 %s
end_comment

begin_comment
comment|// MIPS-MFP32: as{{(.exe)?}}" "-march" "mips32r2" "-mabi" "32" "-mno-shared" "-call_nonpic" "-EB" "-mfp32"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mfp32 -mfp64 -mfpxx -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-MFPXX %s
end_comment

begin_comment
comment|// MIPS-MFPXX: as{{(.exe)?}}" "-march" "mips32r2" "-mabi" "32" "-mno-shared" "-call_nonpic" "-EB" "-mfpxx"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mfpxx -mfp32 -mfp64 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-MFP64 %s
end_comment

begin_comment
comment|// MIPS-MFP64: as{{(.exe)?}}" "-march" "mips32r2" "-mabi" "32" "-mno-shared" "-call_nonpic" "-EB" "-mfp64"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mno-msa -mmsa -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-MSA %s
end_comment

begin_comment
comment|// MIPS-MSA: as{{(.exe)?}}" "-march" "mips32r2" "-mabi" "32" "-mno-shared" "-call_nonpic" "-EB" "-mmsa"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mmsa -mno-msa -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-NMSA %s
end_comment

begin_comment
comment|// MIPS-NMSA: as{{(.exe)?}}"
end_comment

begin_comment
comment|// MIPS-NMSA-NOT: "{{[ A-Za-z\\\/]*}}as{{(.exe)?}}{{.*}}"-mmsa"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// We've already tested MIPS32r2 and MIPS64r2 thoroughly. Do minimal tests on
end_comment

begin_comment
comment|// the remaining CPU's since it was possible to pass on a -mabi with no value
end_comment

begin_comment
comment|// when the CPU name is absent from a StringSwitch in getMipsCPUAndABI()
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -no-integrated-as -c %s -mcpu=mips1 \
end_comment

begin_comment
comment|// RUN:   2>&1 | FileCheck -check-prefix=MIPS1-EB-AS %s
end_comment

begin_comment
comment|// MIPS1-EB-AS: as{{(.exe)?}}" "-march" "mips1" "-mabi" "32" "-mno-shared" "-call_nonpic" "-EB"
end_comment

begin_comment
comment|// MIPS1-EB-AS-NOT: "{{[ A-Za-z\\\/]*}}as{{(.exe)?}}{{.*}}"-KPIC"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -no-integrated-as -c %s -mcpu=mips2 \
end_comment

begin_comment
comment|// RUN:   2>&1 | FileCheck -check-prefix=MIPS2-EB-AS %s
end_comment

begin_comment
comment|// MIPS2-EB-AS: as{{(.exe)?}}" "-march" "mips2" "-mabi" "32" "-mno-shared" "-call_nonpic" "-EB"
end_comment

begin_comment
comment|// MIPS2-EB-AS-NOT: "{{[ A-Za-z\\\/]*}}as{{(.exe)?}}{{.*}}"-KPIC"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -### -no-integrated-as -c %s -mcpu=mips3 \
end_comment

begin_comment
comment|// RUN:   2>&1 | FileCheck -check-prefix=MIPS3-EB-AS %s
end_comment

begin_comment
comment|// MIPS3-EB-AS: as{{(.exe)?}}" "-march" "mips3" "-mabi" "64" "-EB" "-KPIC"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -### -no-integrated-as -c %s -mcpu=mips4 \
end_comment

begin_comment
comment|// RUN:   2>&1 | FileCheck -check-prefix=MIPS4-EB-AS %s
end_comment

begin_comment
comment|// MIPS4-EB-AS: as{{(.exe)?}}" "-march" "mips4" "-mabi" "64" "-EB" "-KPIC"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -### -no-integrated-as -c %s -mcpu=mips5 \
end_comment

begin_comment
comment|// RUN:   2>&1 | FileCheck -check-prefix=MIPS5-EB-AS %s
end_comment

begin_comment
comment|// MIPS5-EB-AS: as{{(.exe)?}}" "-march" "mips5" "-mabi" "64" "-EB" "-KPIC"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -no-integrated-as -c %s -mcpu=mips32 \
end_comment

begin_comment
comment|// RUN:   2>&1 | FileCheck -check-prefix=MIPS32-EB-AS %s
end_comment

begin_comment
comment|// MIPS32-EB-AS: as{{(.exe)?}}" "-march" "mips32" "-mabi" "32" "-mno-shared" "-call_nonpic" "-EB"
end_comment

begin_comment
comment|// MIPS32-EB-AS-NOT: "{{[ A-Za-z\\\/]*}}as{{(.exe)?}}{{.*}}"-KPIC"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -no-integrated-as -c %s -mcpu=mips32r6 \
end_comment

begin_comment
comment|// RUN:   2>&1 | FileCheck -check-prefix=MIPS32R6-EB-AS %s
end_comment

begin_comment
comment|// MIPS32R6-EB-AS: as{{(.exe)?}}" "-march" "mips32r6" "-mabi" "32" "-mno-shared" "-call_nonpic" "-EB"
end_comment

begin_comment
comment|// MIPS32R6-EB-AS-NOT: "{{[ A-Za-z\\\/]*}}as{{(.exe)?}}{{.*}}"-KPIC"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -### -no-integrated-as -c %s -mcpu=mips64 \
end_comment

begin_comment
comment|// RUN:   2>&1 | FileCheck -check-prefix=MIPS64-EB-AS %s
end_comment

begin_comment
comment|// MIPS64-EB-AS: as{{(.exe)?}}" "-march" "mips64" "-mabi" "64" "-EB" "-KPIC"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64-linux-gnu -### -no-integrated-as -c %s -mcpu=mips64r6 \
end_comment

begin_comment
comment|// RUN:   2>&1 | FileCheck -check-prefix=MIPS64R6-EB-AS %s
end_comment

begin_comment
comment|// MIPS64R6-EB-AS: as{{(.exe)?}}" "-march" "mips64r6" "-mabi" "64" "-EB" "-KPIC"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -no-integrated-as -msoft-float -mhard-float -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=HARDFLOAT --implicit-check-not=-msoft-float %s
end_comment

begin_comment
comment|// HARDFLOAT: as{{(.exe)?}}"
end_comment

begin_comment
comment|// HARDFLOAT: -mhard-float
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -no-integrated-as -mhard-float -msoft-float -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=SOFTFLOAT --implicit-check-not=-mhard-float %s
end_comment

begin_comment
comment|// SOFTFLOAT: as{{(.exe)?}}"
end_comment

begin_comment
comment|// SOFTFLOAT: -msoft-float
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -no-integrated-as -mno-odd-spreg -modd-spreg -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=ODDSPREG --implicit-check-not=-mno-odd-spreg %s
end_comment

begin_comment
comment|// ODDSPREG: as{{(.exe)?}}"
end_comment

begin_comment
comment|// ODDSPREG: -modd-spreg
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -no-integrated-as -modd-spreg -mno-odd-spreg -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=NOODDSPREG --implicit-check-not=-modd-spreg %s
end_comment

begin_comment
comment|// NOODDSPREG: as{{(.exe)?}}"
end_comment

begin_comment
comment|// NOODDSPREG: -mno-odd-spreg
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -no-integrated-as -mdouble-float -msingle-float -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=SINGLEFLOAT --implicit-check-not=-mdouble-float %s
end_comment

begin_comment
comment|// SINGLEFLOAT: as{{(.exe)?}}"
end_comment

begin_comment
comment|// SINGLEFLOAT: -msingle-float
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -no-integrated-as -msingle-float -mdouble-float -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=DOUBLEFLOAT --implicit-check-not=-msingle-float %s
end_comment

begin_comment
comment|// DOUBLEFLOAT: as{{(.exe)?}}"
end_comment

begin_comment
comment|// DOUBLEFLOAT: -mdouble-float
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -no-integrated-as -msoft-float -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=SOFTFLOAT-IMPLICIT-FPXX --implicit-check-not=-mfpxx %s
end_comment

begin_comment
comment|// SOFTFLOAT-IMPLICIT-FPXX: as{{(.exe)?}}"
end_comment

begin_comment
comment|// SOFTFLOAT-IMPLICIT-FPXX: -msoft-float
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -no-integrated-as -msoft-float -mfpxx -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=SOFTFLOAT-EXPLICIT-FPXX %s
end_comment

begin_comment
comment|// SOFTFLOAT-EXPLICIT-FPXX: as{{(.exe)?}}"
end_comment

begin_comment
comment|// SOFTFLOAT-EXPLICIT-FPXX: -mfpxx
end_comment

begin_comment
comment|// SOFTFLOAT-EXPLICIT-FPXX: -msoft-float
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-mti-linux-gnu -### -no-integrated-as -msoft-float -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MTI-SOFTFLOAT-IMPLICIT-FPXX --implicit-check-not=-mfpxx %s
end_comment

begin_comment
comment|// MTI-SOFTFLOAT-IMPLICIT-FPXX: as{{(.exe)?}}"
end_comment

begin_comment
comment|// MTI-SOFTFLOAT-IMPLICIT-FPXX: -msoft-float
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-mti-linux-gnu -### -no-integrated-as -msoft-float -mfpxx -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MTI-SOFTFLOAT-EXPLICIT-FPXX %s
end_comment

begin_comment
comment|// MTI-SOFTFLOAT-EXPLICIT-FPXX: as{{(.exe)?}}"
end_comment

begin_comment
comment|// MTI-SOFTFLOAT-EXPLICIT-FPXX: -mfpxx
end_comment

begin_comment
comment|// MTI-SOFTFLOAT-EXPLICIT-FPXX: -msoft-float
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-img-linux-gnu -### -no-integrated-as -msoft-float -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=IMG-SOFTFLOAT-IMPLICIT-FPXX --implicit-check-not=-mfpxx %s
end_comment

begin_comment
comment|// IMG-SOFTFLOAT-IMPLICIT-FPXX: as{{(.exe)?}}"
end_comment

begin_comment
comment|// IMG-SOFTFLOAT-IMPLICIT-FPXX: -msoft-float
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-img-linux-gnu -### -no-integrated-as -msoft-float -mfpxx -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=IMG-SOFTFLOAT-EXPLICIT-FPXX %s
end_comment

begin_comment
comment|// IMG-SOFTFLOAT-EXPLICIT-FPXX: as{{(.exe)?}}"
end_comment

begin_comment
comment|// IMG-SOFTFLOAT-EXPLICIT-FPXX: -mfpxx
end_comment

begin_comment
comment|// IMG-SOFTFLOAT-EXPLICIT-FPXX: -msoft-float
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -no-integrated-as -msingle-float -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=SINGLEFLOAT-IMPLICIT-FPXX --implicit-check-not=-mfpxx %s
end_comment

begin_comment
comment|// SINGLEFLOAT-IMPLICIT-FPXX: as{{(.exe)?}}"
end_comment

begin_comment
comment|// SINGLEFLOAT-IMPLICIT-FPXX: -msingle-float
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -### -no-integrated-as -msingle-float -mfpxx -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=SINGLEFLOAT-EXPLICIT-FPXX %s
end_comment

begin_comment
comment|// SINGLEFLOAT-EXPLICIT-FPXX: as{{(.exe)?}}"
end_comment

begin_comment
comment|// SINGLEFLOAT-EXPLICIT-FPXX: -mfpxx
end_comment

begin_comment
comment|// SINGLEFLOAT-EXPLICIT-FPXX: -msingle-float
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-mti-linux-gnu -### -no-integrated-as -msingle-float -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MTI-SINGLEFLOAT-IMPLICIT-FPXX --implicit-check-not=-mfpxx %s
end_comment

begin_comment
comment|// MTI-SINGLEFLOAT-IMPLICIT-FPXX: as{{(.exe)?}}"
end_comment

begin_comment
comment|// MTI-SINGLEFLOAT-IMPLICIT-FPXX: -msingle-float
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-mti-linux-gnu -### -no-integrated-as -msingle-float -mfpxx -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MTI-SINGLEFLOAT-EXPLICIT-FPXX %s
end_comment

begin_comment
comment|// MTI-SINGLEFLOAT-EXPLICIT-FPXX: as{{(.exe)?}}"
end_comment

begin_comment
comment|// MTI-SINGLEFLOAT-EXPLICIT-FPXX: -mfpxx
end_comment

begin_comment
comment|// MTI-SINGLEFLOAT-EXPLICIT-FPXX: -msingle-float
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-img-linux-gnu -### -no-integrated-as -msingle-float -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=IMG-SINGLEFLOAT-IMPLICIT-FPXX --implicit-check-not=-mfpxx %s
end_comment

begin_comment
comment|// IMG-SINGLEFLOAT-IMPLICIT-FPXX: as{{(.exe)?}}"
end_comment

begin_comment
comment|// IMG-SINGLEFLOAT-IMPLICIT-FPXX: -msingle-float
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-img-linux-gnu -### -no-integrated-as -msingle-float -mfpxx -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=IMG-SINGLEFLOAT-EXPLICIT-FPXX %s
end_comment

begin_comment
comment|// IMG-SINGLEFLOAT-EXPLICIT-FPXX: as{{(.exe)?}}"
end_comment

begin_comment
comment|// IMG-SINGLEFLOAT-EXPLICIT-FPXX: -mfpxx
end_comment

begin_comment
comment|// IMG-SINGLEFLOAT-EXPLICIT-FPXX: -msingle-float
end_comment

end_unit

