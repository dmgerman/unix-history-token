begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Make sure the driver is correctly passing -fno-inline-functions
end_comment

begin_comment
comment|// rdar://10972766
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 \
end_comment

begin_comment
comment|// RUN:   -fno-inline -fno-inline-functions -### -fsyntax-only %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK< %t %s
end_comment

begin_comment
comment|// CHECK: clang
end_comment

begin_comment
comment|// CHECK: "-fno-inline"
end_comment

begin_comment
comment|// CHECK: "-fno-inline-functions"
end_comment

end_unit

