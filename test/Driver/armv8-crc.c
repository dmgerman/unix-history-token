begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target armv8 -mcrc -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-V8-CRC< %t %s
end_comment

begin_comment
comment|// CHECK-V8-CRC: "-target-feature" "+crc"
end_comment

begin_comment
comment|// RUN: %clang -target armv8 -mnocrc -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-V8-NOCRC< %t %s
end_comment

begin_comment
comment|// CHECK-V8-NOCRC: "-target-feature" "-crc"
end_comment

end_unit

