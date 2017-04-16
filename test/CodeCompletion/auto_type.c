begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -code-completion-at=%s:3:1 %s | FileCheck %s
end_comment

begin_function
name|void
name|func
parameter_list|()
block|{  }
end_function

begin_comment
comment|// CHECK: COMPLETION: __auto_type
end_comment

end_unit

