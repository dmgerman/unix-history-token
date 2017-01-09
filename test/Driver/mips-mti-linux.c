begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check frontend and linker invocations on GPL-free MIPS toolchain.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FIXME: Using --sysroot with this toolchain/triple isn't supported. We use
end_comment

begin_comment
comment|//        it here to test that we are producing the correct paths/flags.
end_comment

begin_comment
comment|//        Ideally, we'd like to have an --llvm-toolchain option similar to
end_comment

begin_comment
comment|//        the --gcc-toolchain one.
end_comment

begin_comment
comment|// REQUIRES: mips-registered-target
end_comment

begin_comment
comment|// = Big-endian, mips32r2, hard float
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mips-mti-linux -mips32r2 -mhard-float -rtlib=platform -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/mips_mti_linux/sysroot \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-BE-HF-32R2 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-BE-HF-32R2: "{{[^"]*}}clang{{[^"]*}}" {{.*}} "-triple" "mips-mti-linux"
end_comment

begin_comment
comment|// CHECK-BE-HF-32R2-SAME: "-fuse-init-array" "-target-cpu" "mips32r2"
end_comment

begin_comment
comment|// CHECK-BE-HF-32R2-SAME: "-isysroot" "{{.*}}mips_mti_linux/sysroot"
end_comment

begin_comment
comment|// CHECK-BE-HF-32R2: "{{[^"]*}}lld{{[^"]*}}" "-flavor" "old-gnu" "-target" "mips-mti-linux"
end_comment

begin_comment
comment|// CHECK-BE-HF-32R2-SAME: "--sysroot=[[SYSROOT:[^"]+]]" {{.*}} "-dynamic-linker" "/lib/ld-musl-mips.so.1"
end_comment

begin_comment
comment|// CHECK-BE-HF-32R2-SAME: "[[SYSROOT]]/mips-r2-hard-musl/usr/lib{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK-BE-HF-32R2-SAME: "[[SYSROOT]]/mips-r2-hard-musl/usr/lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// CHECK-BE-HF-32R2-SAME: "-L[[SYSROOT]]/mips-r2-hard-musl/usr/lib"
end_comment

begin_comment
comment|// CHECK-BE-HF-32R2-SAME: "{{[^"]+}}/mips-r2-hard-musl{{/|\\\\}}lib{{/|\\\\}}linux{{/|\\\\}}libclang_rt.builtins-mips.a"
end_comment

begin_comment
comment|// CHECK-BE-HF-32R2-SAME: "-lc"
end_comment

begin_comment
comment|// CHECK-BE-HF-32R2-SAME: "[[SYSROOT]]/mips-r2-hard-musl/usr/lib{{/|\\\\}}crtn.o"
end_comment

begin_comment
comment|// = Little-endian, mips32r2, hard float
end_comment

begin_comment
comment|// RUN: %clang -no-canonical-prefixes %s -### -o %t.o 2>&1 \
end_comment

begin_comment
comment|// RUN:     --target=mips-mti-linux -mips32r2 -EL -mhard-float -rtlib=platform -fuse-ld=ld \
end_comment

begin_comment
comment|// RUN:     --sysroot=%S/Inputs/mips_mti_linux/sysroot \
end_comment

begin_comment
comment|// RUN:   | FileCheck --check-prefix=CHECK-LE-HF-32R2 %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LE-HF-32R2: "{{[^"]*}}clang{{[^"]*}}" {{.*}} "-triple" "mipsel-mti-linux"
end_comment

begin_comment
comment|// CHECK-LE-HF-32R2-SAME: "-fuse-init-array" "-target-cpu" "mips32r2"
end_comment

begin_comment
comment|// CHECK-LE-HF-32R2-SAME: "-isysroot" "{{.*}}mips_mti_linux/sysroot"
end_comment

begin_comment
comment|// CHECK-LE-HF-32R2: "{{[^"]*}}lld{{[^"]*}}" "-flavor" "old-gnu" "-target" "mipsel-mti-linux"
end_comment

begin_comment
comment|// CHECK-LE-HF-32R2-SAME: "--sysroot=[[SYSROOT:[^"]+]]" {{.*}} "-dynamic-linker" "/lib/ld-musl-mipsel.so.1"
end_comment

begin_comment
comment|// CHECK-LE-HF-32R2-SAME: "[[SYSROOT]]/mipsel-r2-hard-musl/usr/lib{{/|\\\\}}crt1.o"
end_comment

begin_comment
comment|// CHECK-LE-HF-32R2-SAME: "[[SYSROOT]]/mipsel-r2-hard-musl/usr/lib{{/|\\\\}}crti.o"
end_comment

begin_comment
comment|// CHECK-LE-HF-32R2-SAME: "-L[[SYSROOT]]/mipsel-r2-hard-musl/usr/lib"
end_comment

begin_comment
comment|// CHECK-LE-HF-32R2-SAME: "{{[^"]+}}/mipsel-r2-hard-musl{{/|\\\\}}lib{{/|\\\\}}linux{{/|\\\\}}libclang_rt.builtins-mips.a"
end_comment

begin_comment
comment|// CHECK-LE-HF-32R2-SAME: "-lc"
end_comment

begin_comment
comment|// CHECK-LE-HF-32R2-SAME: "[[SYSROOT]]/mipsel-r2-hard-musl/usr/lib{{/|\\\\}}crtn.o"
end_comment

end_unit

