begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -fblocks -emit-pch %S/t1.c -o %t1.ast&&
end_comment

begin_comment
comment|// RUN: clang-cc -fblocks -emit-pch %S/t2.c -o %t2.ast&&
end_comment

begin_comment
comment|// RUN: index-test %t1.ast %t2.ast -point-at %S/t1.c:8:7 -print-decls> %t&&
end_comment

begin_comment
comment|// RUN: cat %t | count 3&&
end_comment

begin_comment
comment|// RUN: grep 'foo.h:4:6,' %t | count 2&&
end_comment

begin_comment
comment|// RUN: grep 't2.c:5:6,' %t&&
end_comment

begin_comment
comment|// RUN: index-test %t1.ast %t2.ast -point-at %S/t1.c:5:47 -print-decls> %t&&
end_comment

begin_comment
comment|// RUN: cat %t | count 1&&
end_comment

begin_comment
comment|// RUN: grep 't1.c:5:12,' %t&&
end_comment

begin_comment
comment|// RUN: index-test %t1.ast %t2.ast -point-at %S/t1.c:6:20 -print-decls> %t&&
end_comment

begin_comment
comment|// RUN: cat %t | count 1&&
end_comment

begin_comment
comment|// RUN: grep 't1.c:3:19,' %t&&
end_comment

begin_comment
comment|// field test
end_comment

begin_comment
comment|// RUN: index-test %t1.ast %t2.ast -point-at %S/t1.c:21:6 -print-decls> %t&&
end_comment

begin_comment
comment|// RUN: cat %t | count 1&&
end_comment

begin_comment
comment|// RUN: grep 't1.c:12:7,' %t&&
end_comment

begin_comment
comment|// RUN: index-test %t1.ast %t2.ast -point-at %S/t1.c:22:21 -print-decls> %t&&
end_comment

begin_comment
comment|// RUN: cat %t | count 1&&
end_comment

begin_comment
comment|// RUN: grep 't1.c:16:7,' %t
end_comment

end_unit

