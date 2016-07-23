begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Make sure Sparc does not use the integrated assembler by default.
end_comment

begin_comment
comment|// RUN: %clang -target sparc-linux -### -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=NO-IAS %s
end_comment

begin_comment
comment|// RUN: %clang -target sparc-linux -fintegrated-as -### -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=IAS %s
end_comment

begin_comment
comment|// RUN: %clang -target sparc-linux -fno-integrated-as -### -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=NO-IAS %s
end_comment

begin_comment
comment|// IAS-NOT: "-no-integrated-as"
end_comment

begin_comment
comment|// NO-IAS: "-no-integrated-as"
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes -target sparc--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=v8 -no-canonical-prefixes -target sparc--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V8 %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=supersparc -no-canonical-prefixes -target sparc--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V8 %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=sparclite -no-canonical-prefixes -target sparc--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-SPARCLITE %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=f934 -no-canonical-prefixes -target sparc--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-SPARCLITE %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=hypersparc -no-canonical-prefixes -target sparc--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V8 %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=sparclite86x -no-canonical-prefixes -target sparc--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-SPARCLITE %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=sparclet -no-canonical-prefixes -target sparc--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-SPARCLET %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=tsc701 -no-canonical-prefixes -target sparc--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-SPARCLET %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=v9 -no-canonical-prefixes -target sparc--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V8PLUS %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=ultrasparc -no-canonical-prefixes -target sparc--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V8PLUS %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=ultrasparc3 -no-canonical-prefixes -target sparc--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V8PLUS %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=niagara -no-canonical-prefixes -target sparc--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V8PLUSB %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=niagara2 -no-canonical-prefixes -target sparc--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V8PLUSB %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=niagara3 -no-canonical-prefixes -target sparc--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V8PLUSD %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=niagara4 -no-canonical-prefixes -target sparc--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V8PLUSD %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=leon2 -no-canonical-prefixes -target sparc \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V8 %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=at697e -no-canonical-prefixes -target sparc \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V8 %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=at697f -no-canonical-prefixes -target sparc \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V8 %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=leon3 -no-canonical-prefixes -target sparc \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V8 %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=ut699 -no-canonical-prefixes -target sparc \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V8 %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=gr712rc -no-canonical-prefixes -target sparc \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V8 %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=leon4 -no-canonical-prefixes -target sparc \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V8 %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=gr740 -no-canonical-prefixes -target sparc \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V8 %s
end_comment

begin_comment
comment|// SPARC: as{{.*}}" "-32" "-Av8" "-o"
end_comment

begin_comment
comment|// SPARC-V8: as{{.*}}" "-32" "-Av8" "-o"
end_comment

begin_comment
comment|// SPARC-SPARCLITE: as{{.*}}" "-32" "-Asparclite" "-o"
end_comment

begin_comment
comment|// SPARC-SPARCLET: as{{.*}}" "-32" "-Asparclet" "-o"
end_comment

begin_comment
comment|// SPARC-V8PLUS: as{{.*}}" "-32" "-Av8plus" "-o"
end_comment

begin_comment
comment|// SPARC-V8PLUSB: as{{.*}}" "-32" "-Av8plusb" "-o"
end_comment

begin_comment
comment|// SPARC-V8PLUSD: as{{.*}}" "-32" "-Av8plusd" "-o"
end_comment

end_unit

