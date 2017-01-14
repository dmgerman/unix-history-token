begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// We support a CC1 option for disabling LLVM's passes.
end_comment

begin_comment
comment|// RUN: %clang -O2 -Xclang -disable-llvm-passes -### %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck --check-prefix=DISABLED %s
end_comment

begin_comment
comment|// DISABLED: -cc1
end_comment

begin_comment
comment|// DISABLED-NOT: "-mllvm" "-disable-llvm-passes"
end_comment

begin_comment
comment|// DISABLED: "-disable-llvm-passes"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// We also support two alternative spellings for historical reasons.
end_comment

begin_comment
comment|// RUN: %clang -O2 -Xclang -disable-llvm-optzns -### %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck --check-prefix=DISABLED-LEGACY %s
end_comment

begin_comment
comment|// RUN: %clang -O2 -mllvm -disable-llvm-optzns -### %s 2>&1 \
end_comment

begin_comment
comment|// RUN:     | FileCheck --check-prefix=DISABLED-LEGACY %s
end_comment

begin_comment
comment|// DISABLED-LEGACY: -cc1
end_comment

begin_comment
comment|// DISABLED-LEGACY-NOT: "-mllvm" "-disable-llvm-optzns"
end_comment

begin_comment
comment|// DISABLED-LEGACY: "-disable-llvm-optzns"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The main flag shouldn't be specially handled when used with '-mllvm'.
end_comment

begin_comment
comment|// RUN: %clang -O2 -mllvm -disable-llvm-passes -### %s 2>&1 | FileCheck --check-prefix=MLLVM %s
end_comment

begin_comment
comment|// MLLVM: -cc1
end_comment

begin_comment
comment|// MLLVM-NOT: -disable-llvm-passes
end_comment

begin_comment
comment|// MLLVM: "-mllvm" "-disable-llvm-passes"
end_comment

begin_comment
comment|// MLLVM-NOT: -disable-llvm-passes
end_comment

end_unit

