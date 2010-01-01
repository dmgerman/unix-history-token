begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang -ccc-host-triple i386-unknown-unknown -m64 -v 2> %t
end_comment

begin_comment
comment|// RUN: grep 'Target: x86_64-unknown-unknown' %t
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple i386-apple-darwin9 -arch ppc -m64 -v 2> %t
end_comment

begin_comment
comment|// RUN: grep 'Target: powerpc64-apple-darwin9' %t
end_comment

begin_comment
comment|// RUN: %clang -ccc-host-triple i386-apple-darwin9 -arch ppc64 -m32 -v 2> %t
end_comment

begin_comment
comment|// RUN: grep 'Target: powerpc-apple-darwin9' %t
end_comment

end_unit

