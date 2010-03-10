begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -S -v -o %t %s        2>&1 | not grep -w -- -g
end_comment

begin_comment
comment|// RUN: %clang -S -v -o %t %s -g     2>&1 | grep -w -- -g
end_comment

begin_comment
comment|// RUN: %clang -S -v -o %t %s -g0    2>&1 | not grep -w -- -g
end_comment

begin_comment
comment|// RUN: %clang -S -v -o %t %s -g -g0 2>&1 | not grep -w -- -g
end_comment

begin_comment
comment|// RUN: %clang -S -v -o %t %s -g0 -g 2>&1 | grep -w -- -g
end_comment

end_unit

