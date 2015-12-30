begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not %clang_cc1 %s -include "/abspath/missing file with spaces.h" 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: file not found
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{ }
end_function

end_unit

