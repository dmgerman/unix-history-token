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
comment|// RUN: %clang -target x86_64-unknown-linux-gnu -gsplit-dwarf -c -fmodules -emit-module -fmodules-embed-all-files -fno-implicit-modules -fno-implicit-module-maps -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-NO-ACTIONS< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FIXME: This should fail using clang, except that the type of the output for
end_comment

begin_comment
comment|// an object output with modules is given as clang::driver::types::TY_PCH
end_comment

begin_comment
comment|// rather than TY_Object.
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux-gnu -gsplit-dwarf -c -fmodules -fmodule-format=obj -### %s 2> %t
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

