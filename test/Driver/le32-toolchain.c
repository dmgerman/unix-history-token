begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### -target le32-unknown-nacl %s 2>&1 | FileCheck -check-prefix=CHECK-DEFAULT %s
end_comment

begin_comment
comment|// CHECK-DEFAULT: "-cc1" {{.*}} "-fno-math-builtin"
end_comment

end_unit

