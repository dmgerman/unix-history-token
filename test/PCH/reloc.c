begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 --relocatable-pch -o %t \
end_comment

begin_comment
comment|// RUN:   -isysroot %S/libroot %S/libroot/usr/include/reloc.h
end_comment

begin_comment
comment|// RUN: %clang -target x86_64-apple-darwin10 -fsyntax-only \
end_comment

begin_comment
comment|// RUN:   -include-pch %t -isysroot %S/libroot %s -Xclang -verify
end_comment

begin_comment
comment|// RUN: not %clang -target x86_64-apple-darwin10 -include-pch %t %s
end_comment

begin_include
include|#
directive|include
file|<reloc.h>
end_include

begin_decl_stmt
name|int
name|x
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{redefinition}}
end_comment

begin_decl_stmt
name|int
name|y
init|=
literal|5
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{redefinition}}
end_comment

begin_comment
comment|// expected-note@libroot/usr/include/reloc.h:13{{previous definition}}
end_comment

begin_comment
comment|// expected-note@libroot/usr/include/reloc2.h:14{{previous definition}}
end_comment

end_unit

