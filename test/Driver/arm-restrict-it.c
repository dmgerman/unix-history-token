begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target arm-none-gnueabi -mrestrict-it -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-RESTRICTED< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8a-none-gnueabi -mrestrict-it -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-RESTRICTED< %t %s
end_comment

begin_comment
comment|// CHECK-RESTRICTED: "-backend-option" "-arm-restrict-it"
end_comment

begin_comment
comment|// RUN: %clang -target arm-none-gnueabi -mno-restrict-it -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-NO-RESTRICTED< %t %s
end_comment

begin_comment
comment|// RUN: %clang -target armv8a-none-gnueabi -mno-restrict-it -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-NO-RESTRICTED< %t %s
end_comment

begin_comment
comment|// CHECK-NO-RESTRICTED: "-backend-option" "-arm-no-restrict-it"
end_comment

end_unit

