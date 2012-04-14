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
comment|// CHECK-MIPS32-EB-AS: as{{(.exe)?}}" "-march" "mips32" "-mabi" "32" "-EB"
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
comment|// RUN:   | FileCheck -check-prefix=MIPS32-EL-AS %s
end_comment

begin_comment
comment|// CHECK-MIPS32-EL-AS: as{{(.exe)?}}" "-march" "mips32" "-mabi" "32" "-EL"
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
comment|// CHECK-MIPS64-EB-AS: as{{(.exe)?}}" "-march" "mips64" "-mabi" "64" "-EB"
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
comment|// RUN:   | FileCheck -check-prefix=MIPS64-EL-AS %s
end_comment

begin_comment
comment|// CHECK-MIPS64-EL-AS: as{{(.exe)?}}" "-march" "mips64" "-mabi" "64" "-EL"
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
comment|// CHECK-MIPS-EABI: as{{(.exe)?}}" "-march" "mips32" "-mabi" "eabi" "-EB"
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
comment|// CHECK-MIPS-N32: as{{(.exe)?}}" "-march" "mips64" "-mabi" "n32" "-EB"
end_comment

end_unit

