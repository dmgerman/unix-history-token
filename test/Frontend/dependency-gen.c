begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// rdar://6533411
end_comment

begin_comment
comment|// RUN: clang -MD -MF %t.d -S -x c -o %t.o %s&&
end_comment

begin_comment
comment|// RUN: grep '.*dependency-gen.*:' %t.d&&
end_comment

begin_comment
comment|// RUN: grep 'dependency-gen.c' %t.d&&
end_comment

begin_comment
comment|// RUN: clang -S -M -x c %s -o %t.d&&
end_comment

begin_comment
comment|// RUN: grep '.*dependency-gen.*:' %t.d&&
end_comment

begin_comment
comment|// RUN: grep 'dependency-gen.c' %t.d
end_comment

end_unit

