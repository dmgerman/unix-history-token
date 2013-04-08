begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### -c -save-temps -integrated-as %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// gcc is invoked instead of clang-cc1as with gcc-driver -save-temps.
end_comment

begin_comment
comment|// REQUIRES: clang-driver
end_comment

begin_comment
comment|// CHECK: cc1as
end_comment

begin_comment
comment|// CHECK: -relax-all
end_comment

end_unit

