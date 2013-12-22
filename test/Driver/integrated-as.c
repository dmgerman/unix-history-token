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

end_unit

