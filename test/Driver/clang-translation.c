begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -ccc-host-triple i386-unknown-unknown -### -S -O0 -Os %s -o %t.s -fverbose-asm 2> %t.log
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
comment|// RUN: grep '"--relocation-model" "static"' %t.log
end_comment

begin_comment
comment|// RUN: grep '"--disable-fp-elim"' %t.log
end_comment

begin_comment
comment|// RUN: grep '"--unwind-tables=0"' %t.log
end_comment

begin_comment
comment|// RUN: grep '"--fmath-errno=1"' %t.log
end_comment

begin_comment
comment|// RUN: grep '"-Os"' %t.log
end_comment

begin_comment
comment|// RUN: grep '"-o" .*clang-translation.*' %t.log
end_comment

begin_comment
comment|// RUN: grep '"--asm-verbose"' %t.log
end_comment

begin_comment
comment|// RUN: clang -ccc-host-triple i386-apple-darwin9 -### -S %s -o %t.s 2> %t.log
end_comment

begin_comment
comment|// RUN: grep '"--mcpu" "yonah"' %t.log
end_comment

begin_comment
comment|// RUN: clang -ccc-host-triple x86_64-apple-darwin9 -### -S %s -o %t.s 2> %t.log
end_comment

begin_comment
comment|// RUN: grep '"--mcpu" "core2"' %t.log
end_comment

end_unit

