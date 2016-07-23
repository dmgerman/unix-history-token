begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: x86-registered-target
end_comment

begin_comment
comment|// RUN: env SCE_ORBIS_SDK_DIR=%S/Inputs/scei-ps4_tree %clang -target x86_64-scei-ps4 -E -v %s 2>&1 | FileCheck %s --check-prefix=ENVPS4
end_comment

begin_comment
comment|// ENVPS4: Inputs/scei-ps4_tree/target/include{{$}}
end_comment

begin_comment
comment|// ENVPS4: Inputs/scei-ps4_tree/target/include_common{{$}}
end_comment

begin_comment
comment|// RUN: %clang -isysroot %S/Inputs/scei-ps4_tree -target x86_64-scei-ps4 -E -v %s 2>&1 | FileCheck %s --check-prefix=SYSROOTPS4
end_comment

begin_comment
comment|// SYSROOTPS4: "{{[^"]*}}clang{{[^"]*}}"
end_comment

begin_comment
comment|// SYSROOTPS4: Inputs/scei-ps4_tree/target/include{{$}}
end_comment

begin_comment
comment|// SYSROOTPS4: Inputs/scei-ps4_tree/target/include_common{{$}}
end_comment

end_unit

