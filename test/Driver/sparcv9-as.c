begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Make sure SparcV9 does not use the integrated assembler by default.
end_comment

begin_comment
comment|// RUN: %clang -target sparcv9-linux -### -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=NO-IAS %s
end_comment

begin_comment
comment|// RUN: %clang -target sparcv9-linux -fintegrated-as -### -c %s 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=IAS %s
end_comment

begin_comment
comment|// RUN: %clang -target sparcv9-linux -fno-integrated-as -### -c %s 2>&1 \
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
comment|// RUN: %clang -no-canonical-prefixes -target sparcv9--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=v9 -no-canonical-prefixes -target sparcv9--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V9 %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=ultrasparc -no-canonical-prefixes -target sparcv9--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V9 %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=ultrasparc3 -no-canonical-prefixes -target sparcv9--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V9 %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=niagara -no-canonical-prefixes -target sparcv9--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V9B %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=niagara2 -no-canonical-prefixes -target sparcv9--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V9B %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=niagara3 -no-canonical-prefixes -target sparcv9--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V9D %s
end_comment

begin_comment
comment|// RUN: %clang -mcpu=niagara4 -no-canonical-prefixes -target sparcv9--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -### 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V9D %s
end_comment

begin_comment
comment|// SPARC: as{{.*}}" "-64" "-Av9" "-o"
end_comment

begin_comment
comment|// SPARC-V9: as{{.*}}" "-64" "-Av9" "-o"
end_comment

begin_comment
comment|// SPARC-V9B: as{{.*}}" "-64" "-Av9b" "-o"
end_comment

begin_comment
comment|// SPARC-V9D: as{{.*}}" "-64" "-Av9d" "-o"
end_comment

begin_comment
comment|// RUN: not %clang -mcpu=v8 -no-canonical-prefixes -target sparcv9--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -c 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V8 %s
end_comment

begin_comment
comment|// RUN: not %clang -mcpu=supersparc -no-canonical-prefixes -target sparcv9--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -c 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V8 %s
end_comment

begin_comment
comment|// RUN: not %clang -mcpu=sparclite -no-canonical-prefixes -target sparcv9--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -c 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V8 %s
end_comment

begin_comment
comment|// RUN: not %clang -mcpu=f934 -no-canonical-prefixes -target sparcv9--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -c 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V8 %s
end_comment

begin_comment
comment|// RUN: not %clang -mcpu=hypersparc -no-canonical-prefixes -target sparcv9--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -c 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V8 %s
end_comment

begin_comment
comment|// RUN: not %clang -mcpu=sparclite86x -no-canonical-prefixes -target sparcv9--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -c 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V8 %s
end_comment

begin_comment
comment|// RUN: not %clang -mcpu=sparclet -no-canonical-prefixes -target sparcv9--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -c 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V8 %s
end_comment

begin_comment
comment|// RUN: not %clang -mcpu=tsc701 -no-canonical-prefixes -target sparcv9--netbsd \
end_comment

begin_comment
comment|// RUN: -no-integrated-as --sysroot=%S/Inputs/basic_netbsd_tree %s -c 2>&1 \
end_comment

begin_comment
comment|// RUN: | FileCheck -check-prefix=SPARC-V8 %s
end_comment

begin_comment
comment|// SPARC-V8: error: unknown target CPU
end_comment

begin_decl_stmt
name|int
name|x
decl_stmt|;
end_decl_stmt

end_unit

