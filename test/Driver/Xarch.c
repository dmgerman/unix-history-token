begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -ccc-host-triple i386-apple-darwin9 -m32 -Xarch_i386 -O2 %s -S -### 2> %t.log
end_comment

begin_comment
comment|// RUN: grep ' "-O2" ' %t.log | count 1
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple i386-apple-darwin9 -m64 -Xarch_i386 -O2 %s -S -### 2> %t.log
end_comment

begin_comment
comment|// RUN: grep ' "-O2" ' %t.log | count 0
end_comment

begin_comment
comment|// RUN: grep "argument unused during compilation: '-Xarch_i386 -O2'" %t.log
end_comment

begin_comment
comment|// RUN: not %clang -ccc-host-triple i386-apple-darwin9 -m32 -Xarch_i386 -o -Xarch_i386 -S %s -S -Xarch_i386 -o 2> %t.log
end_comment

begin_comment
comment|// RUN: grep "error: invalid Xarch argument: '-Xarch_i386 -o'" %t.log | count 2
end_comment

begin_comment
comment|// RUN: grep "error: invalid Xarch argument: '-Xarch_i386 -S'" %t.log
end_comment

end_unit

