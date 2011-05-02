begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: touch %t
end_comment

begin_comment
comment|// RUN: chmod 0 %t
end_comment

begin_comment
comment|// %clang -E -dependency-file bla -MT %t -MP -o %t -x c /dev/null
end_comment

begin_comment
comment|// rdar://9286457
end_comment

end_unit

