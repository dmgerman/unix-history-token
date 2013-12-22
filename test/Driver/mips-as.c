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
comment|// RUN:   | FileCheck -check-prefix=MIPS32-EB-AS %s
end_comment

begin_comment
comment|// MIPS32-EB-AS: as{{(.exe)?}}" "-march" "mips32" "-mabi" "32" "-EB"
end_comment

begin_comment
comment|// MIPS32-EB-AS-NOT: "-KPIC"
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
comment|// RUN:   | FileCheck -check-prefix=MIPS32-EB-PIC %s
end_comment

begin_comment
comment|// MIPS32-EB-PIC: as{{(.exe)?}}" "-march" "mips32" "-mabi" "32" "-EB"
end_comment

begin_comment
comment|// MIPS32-EB-PIC: "-KPIC"
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
comment|// RUN:   | FileCheck -check-prefix=MIPS32-DEF-EL-AS %s
end_comment

begin_comment
comment|// MIPS32-DEF-EL-AS: as{{(.exe)?}}" "-march" "mips32" "-mabi" "32" "-EL"
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
comment|// RUN:   | FileCheck -check-prefix=MIPS64-EB-AS %s
end_comment

begin_comment
comment|// MIPS64-EB-AS: as{{(.exe)?}}" "-march" "mips64" "-mabi" "64" "-EB"
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
comment|// RUN:   | FileCheck -check-prefix=MIPS64-DEF-EL-AS %s
end_comment

begin_comment
comment|// MIPS64-DEF-EL-AS: as{{(.exe)?}}" "-march" "mips64" "-mabi" "64" "-EL"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mabi=eabi -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-EABI %s
end_comment

begin_comment
comment|// MIPS-EABI: as{{(.exe)?}}" "-march" "mips32" "-mabi" "eabi" "-EB"
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
comment|// RUN:   | FileCheck -check-prefix=MIPS-N32 %s
end_comment

begin_comment
comment|// MIPS-N32: as{{(.exe)?}}" "-march" "mips64" "-mabi" "n32" "-EB"
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
comment|// RUN:   | FileCheck -check-prefix=MIPS32-EL-AS %s
end_comment

begin_comment
comment|// MIPS32-EL-AS: as{{(.exe)?}}" "-march" "mips32" "-mabi" "32" "-EL"
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
comment|// RUN:   | FileCheck -check-prefix=MIPS64-EL-AS %s
end_comment

begin_comment
comment|// MIPS64-EL-AS: as{{(.exe)?}}" "-march" "mips64" "-mabi" "64" "-EL"
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
comment|// MIPS-32R2: as{{(.exe)?}}" "-march" "mips32r2" "-mabi" "32" "-EB"
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
comment|// MIPS-ALIAS-32: as{{(.exe)?}}" "-march" "mips32" "-mabi" "32" "-EB"
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
comment|// MIPS-ALIAS-32R2: as{{(.exe)?}}" "-march" "mips32r2" "-mabi" "32" "-EB"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mips64 -### \
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
comment|// RUN: %clang -target mips-linux-gnu -mips64r2 -### \
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
comment|// MIPS-16: as{{(.exe)?}}" "-march" "mips32" "-mabi" "32" "-EB" "-mips16"
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
comment|// MIPS-N16-NOT: "-mips16"
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
comment|// MIPS-MICRO: as{{(.exe)?}}" "-march" "mips32" "-mabi" "32" "-EB" "-mmicromips"
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
comment|// MIPS-NMICRO-NOT: "-mmicromips"
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
comment|// MIPS-DSP: as{{(.exe)?}}" "-march" "mips32" "-mabi" "32" "-EB" "-mdsp"
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
comment|// MIPS-NDSP-NOT: "-mdsp"
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
comment|// MIPS-DSPR2: as{{(.exe)?}}" "-march" "mips32" "-mabi" "32" "-EB" "-mdspr2"
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
comment|// MIPS-NDSPR2-NOT: "-mdspr2"
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
comment|// MIPS-NAN2008: as{{(.exe)?}}" "-march" "mips32" "-mabi" "32" "-EB" "-mnan=2008"
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
comment|// MIPS-NAN_LEGACY-NOT: "-mnan={{.*}}"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mfp64 -mfp32 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-MFP32 %s
end_comment

begin_comment
comment|// MIPS-MFP32: as{{(.exe)?}}" "-march" "mips32" "-mabi" "32" "-EB" "-mfp32"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips-linux-gnu -mfp32 -mfp64 -### \
end_comment

begin_comment
comment|// RUN:   -no-integrated-as -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN:   | FileCheck -check-prefix=MIPS-MFP64 %s
end_comment

begin_comment
comment|// MIPS-MFP64: as{{(.exe)?}}" "-march" "mips32" "-mabi" "32" "-EB" "-mfp64"
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
comment|// MIPS-MSA: as{{(.exe)?}}" "-march" "mips32" "-mabi" "32" "-EB" "-mmsa"
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
comment|// MIPS-NMSA-NOT: "-mmsa"
end_comment

end_unit

