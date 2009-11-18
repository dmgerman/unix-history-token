begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang -ccc-host-triple i386-unknown-unknown -static -dM -E -o %t %s
end_comment

begin_comment
comment|// RUN: grep '#define __PIC__' %t | count 0
end_comment

begin_comment
comment|// RUN: grep '#define __pic__' %t | count 0
end_comment

begin_comment
comment|// RUN: clang -ccc-host-triple i386-unknown-unknown -fpic -dM -E -o %t %s
end_comment

begin_comment
comment|// RUN: grep '#define __PIC__ 1' %t | count 1
end_comment

begin_comment
comment|// RUN: grep '#define __pic__ 1' %t | count 1
end_comment

begin_comment
comment|// RUN: clang -ccc-host-triple i386-unknown-unknown -fPIC -dM -E -o %t %s
end_comment

begin_comment
comment|// RUN: grep '#define __PIC__ 2' %t | count 1
end_comment

begin_comment
comment|// RUN: grep '#define __pic__ 2' %t | count 1
end_comment

end_unit

