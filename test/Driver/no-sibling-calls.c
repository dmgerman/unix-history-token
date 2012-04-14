begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### %s -fno-optimize-sibling-calls 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-NOSC< %t %s
end_comment

begin_comment
comment|// CHECK-NOSC: "-mdisable-tail-calls"
end_comment

begin_comment
comment|// RUN: %clang -### -foptimize-sibling-calls %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck --check-prefix=CHECK-OSC< %t %s
end_comment

begin_comment
comment|// CHECK-OSC-NOT: "-mdisable-tail-calls"
end_comment

end_unit

