begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target mipsel-unknown-linux -mnan=2008 -march=mips2 -emit-llvm -S %s -o - 2>%t | FileCheck -check-prefix=CHECK-NANLEGACY %s
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-MIPS2 %s< %t
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64el-unknown-linux -mnan=2008 -march=mips3 -emit-llvm -S %s -o - 2>%t | FileCheck -check-prefix=CHECK-NANLEGACY %s
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-MIPS3 %s< %t
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64el-unknown-linux -mnan=2008 -march=mips4 -emit-llvm -S %s -o - 2>%t | FileCheck -check-prefix=CHECK-NANLEGACY %s
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-MIPS4 %s< %t
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mipsel-unknown-linux -mnan=2008 -march=mips32 -emit-llvm -S %s -o - 2>%t | FileCheck -check-prefix=CHECK-NANLEGACY %s
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-MIPS32 %s< %t
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mipsel-unknown-linux -mnan=2008 -march=mips32r2 -emit-llvm -S %s -o - 2>%t | FileCheck -check-prefix=CHECK-NAN2008 %s
end_comment

begin_comment
comment|// RUN: FileCheck -allow-empty -check-prefix=NO-WARNINGS %s< %t
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mipsel-unknown-linux -mnan=2008 -march=mips32r3 -emit-llvm -S %s -o - 2>%t | FileCheck -check-prefix=CHECK-NAN2008 %s
end_comment

begin_comment
comment|// RUN: FileCheck -allow-empty -check-prefix=NO-WARNINGS %s< %t
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mipsel-unknown-linux -mnan=legacy -march=mips32r6 -emit-llvm -S %s -o - 2>%t | FileCheck -check-prefix=CHECK-NAN2008 %s
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-MIPS32R6 %s< %t
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64el-unknown-linux -mnan=2008 -march=mips64 -emit-llvm -S %s -o - 2>%t | FileCheck -check-prefix=CHECK-NANLEGACY %s
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-MIPS64 %s< %t
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64el-unknown-linux -mnan=2008 -march=mips64r2 -emit-llvm -S %s -o - 2>%t | FileCheck -check-prefix=CHECK-NAN2008 %s
end_comment

begin_comment
comment|// RUN: FileCheck -allow-empty -check-prefix=NO-WARNINGS %s< %t
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target mips64el-unknown-linux -mnan=legacy -march=mips64r6 -emit-llvm -S %s -o - 2>%t | FileCheck -check-prefix=CHECK-NAN2008 %s
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-MIPS64R6 %s< %t
end_comment

begin_comment
comment|// NO-WARNINGS-NOT: warning: ignoring '-mnan=legacy' option
end_comment

begin_comment
comment|// NO-WARNINGS-NOT: warning: ignoring '-mnan=2008' option
end_comment

begin_comment
comment|// CHECK-MIPS2: warning: ignoring '-mnan=2008' option because the 'mips2' architecture does not support it
end_comment

begin_comment
comment|// CHECK-MIPS3: warning: ignoring '-mnan=2008' option because the 'mips3' architecture does not support it
end_comment

begin_comment
comment|// CHECK-MIPS4: warning: ignoring '-mnan=2008' option because the 'mips4' architecture does not support it
end_comment

begin_comment
comment|// CHECK-MIPS32: warning: ignoring '-mnan=2008' option because the 'mips32' architecture does not support it
end_comment

begin_comment
comment|// CHECK-MIPS32R6: warning: ignoring '-mnan=legacy' option because the 'mips32r6' architecture does not support it
end_comment

begin_comment
comment|// CHECK-MIPS64: warning: ignoring '-mnan=2008' option because the 'mips64' architecture does not support it
end_comment

begin_comment
comment|// CHECK-MIPS64R6: warning: ignoring '-mnan=legacy' option because the 'mips64r6' architecture does not support it
end_comment

begin_comment
comment|// CHECK-NANLEGACY: float 0x7FF4000000000000
end_comment

begin_comment
comment|// CHECK-NAN2008: float 0x7FF8000000000000
end_comment

begin_decl_stmt
name|float
name|f
init|=
name|__builtin_nan
argument_list|(
literal|""
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

