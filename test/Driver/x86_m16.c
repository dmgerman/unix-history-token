begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target i386 -m16 -### -c %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: Target: i386-{{.*}}-{{.*}}-code16
end_comment

end_unit

