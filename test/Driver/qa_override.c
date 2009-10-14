begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: env QA_OVERRIDE_GCC3_OPTIONS="#+-Os +-Oz +-O +-O3 +-Oignore +a +b +c xb Xa Omagic ^-ccc-print-options  " clang x -O2 b -O3 2> %t&&
end_comment

begin_comment
comment|// RUN: grep '### ' %t | count 0&&
end_comment

begin_comment
comment|// RUN: grep -F 'Option 0 - Name: "<input>", Values: {"x"}' %t&&
end_comment

begin_comment
comment|// RUN: grep -F 'Option 1 - Name: "-O", Values: {"ignore"}' %t&&
end_comment

begin_comment
comment|// RUN: grep -F 'Option 2 - Name: "-O", Values: {"magic"}' %t&&
end_comment

begin_comment
comment|// RUN: true
end_comment

end_unit

