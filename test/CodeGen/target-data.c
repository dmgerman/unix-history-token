begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i686-unknown-unknown -emit-llvm -o - %s | \
end_comment

begin_comment
comment|// RUN:     FileCheck --check-prefix=I686-UNKNOWN %s
end_comment

begin_comment
comment|// I686-UNKNOWN: target datalayout = "e-m:e-p:32:32-f64:32:64-f80:32-n8:16:32-S128"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-apple-darwin9 -emit-llvm -o - %s | \
end_comment

begin_comment
comment|// RUN:     FileCheck --check-prefix=I686-DARWIN %s
end_comment

begin_comment
comment|// I686-DARWIN: target datalayout = "e-m:o-p:32:32-f64:32:64-f80:128-n8:16:32-S128"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-unknown-win32 -emit-llvm -o - %s | \
end_comment

begin_comment
comment|// RUN:     FileCheck --check-prefix=I686-WIN32 %s
end_comment

begin_comment
comment|// I686-WIN32: target datalayout = "e-m:x-p:32:32-i64:64-f80:32-n8:16:32-a:0:32-S32"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-unknown-cygwin -emit-llvm -o - %s | \
end_comment

begin_comment
comment|// RUN:     FileCheck --check-prefix=I686-CYGWIN %s
end_comment

begin_comment
comment|// I686-CYGWIN: target datalayout = "e-m:x-p:32:32-i64:64-f80:32-n8:16:32-a:0:32-S32"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm -o - %s | \
end_comment

begin_comment
comment|// RUN:     FileCheck --check-prefix=X86_64 %s
end_comment

begin_comment
comment|// X86_64: target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple xcore-unknown-unknown -emit-llvm -o - %s | \
end_comment

begin_comment
comment|// RUN:     FileCheck --check-prefix=XCORE %s
end_comment

begin_comment
comment|// XCORE: target datalayout = "e-m:e-p:32:32-i1:8:32-i8:8:32-i16:16:32-i64:32-f64:32-a:0:32-n32"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple sparc-sun-solaris -emit-llvm -o - %s | \
end_comment

begin_comment
comment|// RUN:     FileCheck %s --check-prefix=SPARC-V8
end_comment

begin_comment
comment|// SPARC-V8: target datalayout = "E-m:e-p:32:32-i64:64-f128:64-n32-S64"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple sparcv9-sun-solaris -emit-llvm -o - %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s --check-prefix=SPARC-V9
end_comment

begin_comment
comment|// SPARC-V9: target datalayout = "E-m:e-i64:64-n32:64-S128"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mipsel-linux-gnu -o - -emit-llvm %s |     \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=MIPS-32EL
end_comment

begin_comment
comment|// MIPS-32EL: target datalayout = "e-m:m-p:32:32-i8:8:32-i16:16:32-i64:64-n32-S64"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips-linux-gnu -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=MIPS-32EB
end_comment

begin_comment
comment|// MIPS-32EB: target datalayout = "E-m:m-p:32:32-i8:8:32-i16:16:32-i64:64-n32-S64"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips64el-linux-gnu -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=MIPS-64EL
end_comment

begin_comment
comment|// MIPS-64EL: target datalayout = "e-m:e-i8:8:32-i16:16:32-i64:64-n32:64-S128"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips64el-linux-gnu -o - -emit-llvm -target-abi n32 \
end_comment

begin_comment
comment|// RUN: %s | FileCheck %s -check-prefix=MIPS-64EL-N32
end_comment

begin_comment
comment|// MIPS-64EL-N32: target datalayout = "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32:64-S128"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips64-linux-gnu -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=MIPS-64EB
end_comment

begin_comment
comment|// MIPS-64EB: target datalayout = "E-m:e-i8:8:32-i16:16:32-i64:64-n32:64-S128"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mips64-linux-gnu -o - -emit-llvm %s -target-abi n32 \
end_comment

begin_comment
comment|// RUN: | FileCheck %s -check-prefix=MIPS-64EB-N32
end_comment

begin_comment
comment|// MIPS-64EB-N32: target datalayout = "E-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32:64-S128"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-lv2 -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=PS3
end_comment

begin_comment
comment|// PS3: target datalayout = "E-m:e-p:32:32-i64:64-n32:64"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i686-nacl -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=I686-NACL
end_comment

begin_comment
comment|// I686-NACL: target datalayout = "e-m:e-p:32:32-i64:64-n8:16:32-S128"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-nacl -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=X86_64-NACL
end_comment

begin_comment
comment|// X86_64-NACL: target datalayout = "e-m:e-p:32:32-i64:64-n8:16:32:64-S128"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm-nacl -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=ARM-NACL
end_comment

begin_comment
comment|// ARM-NACL: target datalayout = "e-m:e-p:32:32-i64:64-v128:64:128-a:0:32-n32-S128"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple mipsel-nacl -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=MIPS-NACL
end_comment

begin_comment
comment|// MIPS-NACL: target datalayout = "e-m:m-p:32:32-i8:8:32-i16:16:32-i64:64-n32-S64"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple le32-nacl -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=LE32-NACL
end_comment

begin_comment
comment|// LE32-NACL: target datalayout = "e-p:32:32-i64:64"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple wasm32-unknown-unknown -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=WEBASSEMBLY32
end_comment

begin_comment
comment|// WEBASSEMBLY32: target datalayout = "e-m:e-p:32:32-i64:64-n32:64-S128"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple wasm64-unknown-unknown -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=WEBASSEMBLY64
end_comment

begin_comment
comment|// WEBASSEMBLY64: target datalayout = "e-m:e-p:64:64-i64:64-n32:64-S128"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple lanai-unknown-unknown -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=LANAI
end_comment

begin_comment
comment|// LANAI: target datalayout = "E-m:e-p:32:32-i64:64-a:0:32-n32-S64"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc-unknown -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=PPC
end_comment

begin_comment
comment|// PPC: target datalayout = "E-m:e-p:32:32-i64:64-n32"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-freebsd -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=PPC64-FREEBSD
end_comment

begin_comment
comment|// PPC64-FREEBSD: target datalayout = "E-m:e-i64:64-n32:64"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-linux -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=PPC64-LINUX
end_comment

begin_comment
comment|// PPC64-LINUX: target datalayout = "E-m:e-i64:64-n32:64"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64le-linux -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=PPC64LE-LINUX
end_comment

begin_comment
comment|// PPC64LE-LINUX: target datalayout = "e-m:e-i64:64-n32:64"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc-darwin -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=PPC32-DARWIN
end_comment

begin_comment
comment|// PPC32-DARWIN: target datalayout = "E-m:o-p:32:32-f64:32:64-n32"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple powerpc64-darwin -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=PPC64-DARWIN
end_comment

begin_comment
comment|// PPC64-DARWIN: target datalayout = "E-m:o-i64:64-n32:64"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple nvptx-unknown -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=NVPTX
end_comment

begin_comment
comment|// NVPTX: target datalayout = "e-p:32:32-i64:64-v16:16-v32:32-n16:32:64"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple nvptx64-unknown -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=NVPTX64
end_comment

begin_comment
comment|// NVPTX64: target datalayout = "e-i64:64-v16:16-v32:32-n16:32:64"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple r600-unknown -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=R600
end_comment

begin_comment
comment|// R600: target datalayout = "e-p:32:32-i64:64-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024-v2048:2048-n32:64"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple r600-unknown -target-cpu cayman -o - -emit-llvm %s \
end_comment

begin_comment
comment|// RUN: | FileCheck %s -check-prefix=R600D
end_comment

begin_comment
comment|// R600D: target datalayout = "e-p:32:32-i64:64-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024-v2048:2048-n32:64"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple amdgcn-unknown -target-cpu hawaii -o - -emit-llvm %s \
end_comment

begin_comment
comment|// RUN: | FileCheck %s -check-prefix=R600SI
end_comment

begin_comment
comment|// R600SI: target datalayout = "e-p:32:32-p1:64:64-p2:64:64-p3:32:32-p4:64:64-p5:32:32-i64:64-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024-v2048:2048-n32:64"
end_comment

begin_comment
comment|// Test default -target-cpu
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple amdgcn-unknown -o - -emit-llvm %s \
end_comment

begin_comment
comment|// RUN: | FileCheck %s -check-prefix=R600SIDefault
end_comment

begin_comment
comment|// R600SIDefault: target datalayout = "e-p:32:32-p1:64:64-p2:64:64-p3:32:32-p4:64:64-p5:32:32-i64:64-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024-v2048:2048-n32:64"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-unknown -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=AARCH64
end_comment

begin_comment
comment|// AARCH64: target datalayout = "e-m:e-i8:8:32-i16:16:32-i64:64-i128:128-n32:64-S128"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumb-unknown-gnueabi -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=THUMB
end_comment

begin_comment
comment|// THUMB: target datalayout = "e-m:e-p:32:32-i64:64-v128:64:128-a:0:32-n32-S64"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm-unknown-gnueabi -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=ARM
end_comment

begin_comment
comment|// ARM: target datalayout = "e-m:e-p:32:32-i64:64-v128:64:128-a:0:32-n32-S64"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumb-unknown -o - -emit-llvm -target-abi apcs-gnu \
end_comment

begin_comment
comment|// RUN: %s | FileCheck %s -check-prefix=THUMB-GNU
end_comment

begin_comment
comment|// THUMB-GNU: target datalayout = "e-m:e-p:32:32-f64:32:64-v64:32:64-v128:32:128-a:0:32-n32-S32"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm-unknown -o - -emit-llvm -target-abi apcs-gnu \
end_comment

begin_comment
comment|// RUN: %s | FileCheck %s -check-prefix=ARM-GNU
end_comment

begin_comment
comment|// ARM-GNU: target datalayout = "e-m:e-p:32:32-f64:32:64-v64:32:64-v128:32:128-a:0:32-n32-S32"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple hexagon-unknown -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=HEXAGON
end_comment

begin_comment
comment|// HEXAGON: target datalayout = "e-m:e-p:32:32:32-a:0-n16:32-i64:64:64-i32:32:32-i16:16:16-i1:8:8-f32:32:32-f64:64:64-v32:32:32-v64:64:64-v512:512:512-v1024:1024:1024-v2048:2048:2048"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple s390x-unknown -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=SYSTEMZ
end_comment

begin_comment
comment|// SYSTEMZ: target datalayout = "E-m:e-i1:8:16-i8:8:16-i64:64-f128:64-a:8:16-n32:64"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple s390x-unknown -target-cpu z13 -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=SYSTEMZ-VECTOR
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple s390x-unknown -target-cpu arch11 -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=SYSTEMZ-VECTOR
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple s390x-unknown -target-cpu z14 -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=SYSTEMZ-VECTOR
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple s390x-unknown -target-cpu arch12 -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=SYSTEMZ-VECTOR
end_comment

begin_comment
comment|// SYSTEMZ-VECTOR: target datalayout = "E-m:e-i1:8:16-i8:8:16-i64:64-f128:64-v128:64-a:8:16-n32:64"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple msp430-unknown -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=MSP430
end_comment

begin_comment
comment|// MSP430: target datalayout = "e-m:e-p:16:16-i32:16-i64:16-f32:16-f64:16-a:8-n8:16-S16"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple tce-unknown -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=TCE
end_comment

begin_comment
comment|// TCE: target datalayout = "E-p:32:32:32-i1:8:8-i8:8:32-i16:16:32-i32:32:32-i64:32:32-f32:32:32-f64:32:32-v64:32:32-v128:32:32-v256:32:32-v512:32:32-v1024:32:32-a0:0:32-n32"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple tcele-unknown -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=TCELE
end_comment

begin_comment
comment|// TCELE: target datalayout = "e-p:32:32:32-i1:8:8-i8:8:32-i16:16:32-i32:32:32-i64:32:32-f32:32:32-f64:32:32-v64:32:32-v128:32:32-v256:32:32-v512:32:32-v1024:32:32-a0:0:32-n32"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple spir-unknown -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=SPIR
end_comment

begin_comment
comment|// SPIR: target datalayout = "e-p:32:32-i64:64-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple spir64-unknown -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=SPIR64
end_comment

begin_comment
comment|// SPIR64: target datalayout = "e-i64:64-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple bpfel -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=BPFEL
end_comment

begin_comment
comment|// BPFEL: target datalayout = "e-m:e-p:64:64-i64:64-n32:64-S128"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple bpfeb -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=BPFEB
end_comment

begin_comment
comment|// BPFEB: target datalayout = "E-m:e-p:64:64-i64:64-n32:64-S128"
end_comment

end_unit

