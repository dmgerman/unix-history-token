begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that we aren't splitting debug output for modules builds that don't produce object files.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux-gnu -gsplit-dwarf -c -fmodules -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-NO-ACTIONS< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-NO-ACTIONS-NOT: objcopy
end_comment

end_unit

