begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that we split debug output properly
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux-gnu -gsplit-dwarf -c -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-ACTIONS< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-ACTIONS: objcopy{{.*}}--extract-dwo{{.*}}"split-debug.dwo"
end_comment

begin_comment
comment|// CHECK-ACTIONS: objcopy{{.*}}--strip-dwo{{.*}}"split-debug.o"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-macosx -gsplit-dwarf -c -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-NO-ACTIONS< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-NO-ACTIONS-NOT: -split-dwarf
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux-gnu -gsplit-dwarf -o Bad.x -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-BAD< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-BAD-NOT: "Bad.dwo"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux-gnu -gsplit-dwarf -c -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-OPTION< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-OPTION: "-split-dwarf-file" "split-debug.dwo"
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux-gnu -gsplit-dwarf -S -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-ASM< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-ASM-NOT: objcopy
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-unknown-linux-gnu -no-integrated-as -gsplit-dwarf -c -### %s 2> %t
end_comment

begin_comment
comment|// RUN: FileCheck -check-prefix=CHECK-IAS< %t %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-IAS: objcopy
end_comment

end_unit

