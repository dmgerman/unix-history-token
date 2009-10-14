begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// rdar://6533411
end_comment

begin_comment
comment|// RUN: clang -MD -MF %t.d -c -x c -o %t.o /dev/null&&
end_comment

begin_comment
comment|// RUN: grep '.*dependency-gen.*:' %t.d&&
end_comment

begin_comment
comment|// RUN: grep '/dev/null' %t.d&&
end_comment

begin_comment
comment|// RUN: clang -M -x c /dev/null -o %t.deps&&
end_comment

begin_comment
comment|// RUN: grep 'null.o: /dev/null' %t.deps
end_comment

end_unit

