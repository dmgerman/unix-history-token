begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test -MT and -E flags, PR4063
end_comment

begin_comment
comment|// RUN: %clang -E -o %t.1 %s
end_comment

begin_comment
comment|// RUN: %clang -E -MD -MF %t.d -MT foo -o %t.2 %s
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

begin_comment
comment|// Test -MQ flag without quoting
end_comment

begin_comment
comment|// RUN: %clang -E -MD -MF %t.d -MQ foo -o %t %s
end_comment

begin_comment
comment|// RUN: grep "foo:" %t.d
end_comment

begin_comment
comment|// Test -MQ flag with quoting
end_comment

begin_comment
comment|// RUN: %clang -E -MD -MF %t.d -MQ '$fo\ooo ooo\ ooo\\ ooo#oo' -o %t %s
end_comment

begin_comment
comment|// RUN: fgrep '$$fo\ooo\ ooo\\\ ooo\\\\\ ooo\#oo:' %t.d
end_comment

begin_comment
comment|// Test consecutive -MT flags
end_comment

begin_comment
comment|// RUN: %clang -E -MD -MF %t.d -MT foo -MT bar -MT baz -o %t %s
end_comment

begin_comment
comment|// RUN: diff %t.1 %t
end_comment

begin_comment
comment|// RUN: fgrep "foo bar baz:" %t.d
end_comment

begin_comment
comment|// Test consecutive -MT and -MQ flags
end_comment

begin_comment
comment|// RUN: %clang -E -MD -MF %t.d -MT foo -MQ '$(bar)' -MT 'b az' -MQ 'qu ux' -MQ ' space' -o %t %s
end_comment

begin_comment
comment|// RUN: fgrep 'foo $$(bar) b az qu\ ux \ space:' %t.d
end_comment

begin_comment
comment|// TODO: Test default target without quoting
end_comment

begin_comment
comment|// TODO: Test default target with quoting
end_comment

end_unit

