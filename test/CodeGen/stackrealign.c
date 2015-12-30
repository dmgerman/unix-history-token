begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -mstackrealign | FileCheck %s -check-prefix=REALIGN
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - | FileCheck %s -check-prefix=NO-REALIGN
end_comment

begin_comment
comment|// REALIGN: attributes #{{[0-9]+}} = {{{.*}} "stackrealign"
end_comment

begin_comment
comment|// NO-REALIGN-NOT: attributes #{{[0-9]+}} = {{{.*}} "stackrealign"
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{ }
end_function

end_unit

