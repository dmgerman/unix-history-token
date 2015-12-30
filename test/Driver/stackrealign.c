begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -### %s 2>&1 | FileCheck %s -check-prefix=NO-REALIGN
end_comment

begin_comment
comment|// RUN: %clang -### -mno-stackrealign -mstackrealign %s 2>&1 | FileCheck %s -check-prefix=REALIGN
end_comment

begin_comment
comment|// RUN: %clang -### -mstackrealign -mno-stackrealign %s 2>&1 | FileCheck %s -check-prefix=NO-REALIGN
end_comment

begin_comment
comment|// REQUIRES: clang-driver
end_comment

begin_comment
comment|// REALIGN: -mstackrealign
end_comment

begin_comment
comment|// NO-REALIGN-NOT: -mstackrealign
end_comment

end_unit

