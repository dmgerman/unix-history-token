begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: not clang -ccc-host-triple i386-pc-linux-gnu -emit-llvm -o %t %s 2> %t.log
end_comment

begin_comment
comment|// RUN: grep 'unable to pass LLVM bit-code files to linker' %t.log
end_comment

end_unit

