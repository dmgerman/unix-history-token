begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-pc-win32-macho -### -S %s -o %t.s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// Do not add function attribute "uwtable" for macho targets.
end_comment

begin_comment
comment|// CHECK-NOT: -munwind-tables
end_comment

end_unit

