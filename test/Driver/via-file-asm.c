begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Should save and read back the assembly from a file
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-linux-gnueabi -integrated-as -via-file-asm %s -### 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: "-cc1"
end_comment

begin_comment
comment|// CHECK: "-o" "[[TMP:[^"]*]]"
end_comment

begin_comment
comment|// CHECK: -cc1as
end_comment

begin_comment
comment|// CHECK: [[TMP]]
end_comment

begin_comment
comment|// Should not force using the integrated assembler
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-linux-gnueabi -no-integrated-as -via-file-asm %s -### 2>&1 | FileCheck --check-prefix=NO_IAS %s
end_comment

begin_comment
comment|// NO_IAS-NOT: "-cc1as"
end_comment

end_unit

