begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// PR13529: Don't crash.
end_comment

begin_comment
comment|// RUN: %clang_cpp -lfoo -M %s 2>&1 | FileCheck --check-prefix=CHECK-PR13529 %s
end_comment

begin_comment
comment|// CHECK-PR13529: warning: -lfoo: 'linker' input unused in cpp mode
end_comment

end_unit

