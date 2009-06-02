begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: env CCC_ADD_ARGS="-ccc-echo,-ccc-print-options,,-v" clang -### 2> %t&&
end_comment

begin_comment
comment|// RUN: grep -F 'Option 0 - Name: "-v", Values: {}' %t&&
end_comment

begin_comment
comment|// RUN: grep -F 'Option 1 - Name: "-###", Values: {}' %t
end_comment

end_unit

