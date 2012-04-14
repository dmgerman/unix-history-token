begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### %s 2>&1 | FileCheck %s -check-prefix=NORMAL
end_comment

begin_comment
comment|// NORMAL-NOT: -force-align-stack
end_comment

begin_comment
comment|// NORMAL: -mstackrealign
end_comment

begin_comment
comment|// RUN: %clang -### -mstackrealign %s 2>&1 | FileCheck %s -check-prefix=MREALIGN
end_comment

begin_comment
comment|// MREALIGN: -force-align-stack
end_comment

begin_comment
comment|// MREALIGN: -mstackrealign
end_comment

begin_comment
comment|// RUN: %clang -### -mno-stackrealign %s 2>&1 | \
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=MNOREALIGN
end_comment

begin_comment
comment|// MNOREALIGN-NOT: -force-align-stack
end_comment

begin_comment
comment|// MNOREALIGN-NOT: -mstackrealign
end_comment

end_unit

