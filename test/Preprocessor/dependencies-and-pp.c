begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -E -o %t.1 %s
end_comment

begin_comment
comment|// RUN: clang -E -MD -MF %t.d -MT foo -o %t.2 %s
end_comment

begin_comment
comment|// RUN: diff %t.1 %t.2
end_comment

begin_comment
comment|// RUN: grep "foo:" %t.d
end_comment

begin_comment
comment|// RUN: grep "dependencies-and-pp.c" %t.d
end_comment

end_unit

