begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### -c -save-temps -integrated-as %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: cc1as
end_comment

begin_comment
comment|// CHECK: -mrelax-all
end_comment

begin_comment
comment|// RUN: %clang -### -fintegrated-as -c -save-temps %s 2>&1 | FileCheck %s -check-prefix FIAS
end_comment

begin_comment
comment|// FIAS: cc1as
end_comment

begin_comment
comment|// RUN: %clang -### -fno-integrated-as -S %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck %s -check-prefix NOFIAS
end_comment

begin_comment
comment|// NOFIAS-NOT: cc1as
end_comment

begin_comment
comment|// NOFIAS: -cc1
end_comment

begin_comment
comment|// NOFIAS: -no-integrated-as
end_comment

end_unit

