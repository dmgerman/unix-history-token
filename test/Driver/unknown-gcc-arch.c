begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -ccc-host-triple x86_64-unknown-unknown -c -x assembler %s -### 2> %t.log
end_comment

begin_comment
comment|// RUN: grep '.*gcc.*"-m64"' %t.log
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple x86_64-unknown-unknown -c -x assembler %s -### -m32 2> %t.log
end_comment

begin_comment
comment|// RUN: grep '.*gcc.*"-m32"' %t.log
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple i386-unknown-unknown -c -x assembler %s -### 2> %t.log
end_comment

begin_comment
comment|// RUN: grep '.*gcc.*"-m32"' %t.log
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple i386-unknown-unknown -c -x assembler %s -### -m64 2> %t.log
end_comment

begin_comment
comment|// RUN: grep '.*gcc.*"-m64"' %t.log
end_comment

end_unit

