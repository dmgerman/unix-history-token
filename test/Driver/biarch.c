begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target i386--netbsd -m32 %s -### 2> %t
end_comment

begin_comment
comment|// RUN: grep '"-cc1" "-triple" "i386--netbsd"' %t
end_comment

begin_comment
comment|// RUN: %clang -target i386--netbsd -m64 %s -### 2> %t
end_comment

begin_comment
comment|// RUN: grep '"-cc1" "-triple" "x86_64--netbsd"' %t
end_comment

begin_comment
comment|// RUN: %clang -target x86_64--netbsd -m32 %s -### 2> %t
end_comment

begin_comment
comment|// RUN: grep '"-cc1" "-triple" "i386--netbsd"' %t
end_comment

begin_comment
comment|// RUN: %clang -target x86_64--netbsd -m64 %s -### 2> %t
end_comment

begin_comment
comment|// RUN: grep '"-cc1" "-triple" "x86_64--netbsd"' %t
end_comment

begin_comment
comment|// RUN: %clang -target armv6--netbsd-eabihf -m32 %s -### 2> %t
end_comment

begin_comment
comment|// RUN: grep '"-cc1" "-triple" "armv6--netbsd-eabihf"' %t
end_comment

begin_comment
comment|// RUN: %clang -target sparcv9--netbsd -m32 %s -### 2> %t
end_comment

begin_comment
comment|// RUN: grep '"-cc1" "-triple" "sparc--netbsd"' %t
end_comment

begin_comment
comment|// RUN: %clang -target sparcv9--netbsd -m64 %s -### 2> %t
end_comment

begin_comment
comment|// RUN: grep '"-cc1" "-triple" "sparcv9--netbsd"' %t
end_comment

begin_comment
comment|// RUN: %clang -target sparc64--netbsd -m64 %s -### 2> %t
end_comment

begin_comment
comment|// RUN: grep '"-cc1" "-triple" "sparc64--netbsd"' %t
end_comment

begin_comment
comment|// RUN: %clang -target sparc--netbsd -m32 %s -### 2> %t
end_comment

begin_comment
comment|// RUN: grep '"-cc1" "-triple" "sparc--netbsd"' %t
end_comment

begin_comment
comment|// RUN: %clang -target sparc--netbsd -m64 %s -### 2> %t
end_comment

begin_comment
comment|// RUN: grep '"-cc1" "-triple" "sparcv9--netbsd"' %t
end_comment

begin_comment
comment|// RUN: %clang -target mips64--netbsd -m32 %s -### 2> %t
end_comment

begin_comment
comment|// RUN: grep '"-cc1" "-triple" "mips--netbsd"' %t
end_comment

begin_comment
comment|// RUN: %clang -target mips64--netbsd -m64 %s -### 2> %t
end_comment

begin_comment
comment|// RUN: grep '"-cc1" "-triple" "mips64--netbsd"' %t
end_comment

begin_comment
comment|// RUN: %clang -target mips--netbsd -m32 %s -### 2> %t
end_comment

begin_comment
comment|// RUN: grep '"-cc1" "-triple" "mips--netbsd"' %t
end_comment

begin_comment
comment|// RUN: %clang -target mips--netbsd -m64 %s -### 2> %t
end_comment

begin_comment
comment|// RUN: grep '"-cc1" "-triple" "mips64--netbsd"' %t
end_comment

end_unit

