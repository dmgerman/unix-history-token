begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -ccc-host-triple i386-unknown-unknown -### -S -O0 -Os %s -o %t.s -fverbose-asm -funwind-tables 2> %t.log
end_comment

begin_comment
comment|// RUN: grep '"-triple" "i386-unknown-unknown"' %t.log
end_comment

begin_comment
comment|// RUN: grep '"-S"' %t.log
end_comment

begin_comment
comment|// RUN: grep '"-disable-free"' %t.log
end_comment

begin_comment
comment|// RUN: grep '"-mrelocation-model" "static"' %t.log
end_comment

begin_comment
comment|// RUN: grep '"-mdisable-fp-elim"' %t.log
end_comment

begin_comment
comment|// RUN: grep '"-munwind-tables"' %t.log
end_comment

begin_comment
comment|// RUN: grep '"-Os"' %t.log
end_comment

begin_comment
comment|// RUN: grep '"-o" .*clang-translation.*' %t.log
end_comment

begin_comment
comment|// RUN: grep '"-masm-verbose"' %t.log
end_comment

begin_comment
comment|// RUN: clang -ccc-host-triple i386-apple-darwin9 -### -S %s -o %t.s 2> %t.log
end_comment

begin_comment
comment|// RUN: grep '"-mcpu" "yonah"' %t.log
end_comment

begin_comment
comment|// RUN: clang -ccc-host-triple x86_64-apple-darwin9 -### -S %s -o %t.s 2> %t.log
end_comment

begin_comment
comment|// RUN: grep '"-mcpu" "core2"' %t.log
end_comment

end_unit

