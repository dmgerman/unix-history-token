begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fblocks -emit-pch %S/Inputs/t1.c -o %t1.ast
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fblocks -emit-pch %S/Inputs/t2.c -o %t2.ast
end_comment

begin_comment
comment|// RUN: index-test %t1.ast %t2.ast -point-at %S/Inputs/foo.h:1:14 -print-refs> %t
end_comment

begin_comment
comment|// RUN: cat %t | count 4
end_comment

begin_comment
comment|// RUN: grep 't1.c:4:19,' %t
end_comment

begin_comment
comment|// RUN: grep 't1.c:28:40,' %t
end_comment

begin_comment
comment|// RUN: grep 't2.c:6:3,' %t
end_comment

begin_comment
comment|// RUN: grep 't2.c:7:12,' %t
end_comment

begin_comment
comment|// RUN: index-test %t1.ast %t2.ast -point-at %S/Inputs/foo.h:3:9 -print-refs> %t
end_comment

begin_comment
comment|// RUN: cat %t | count 1
end_comment

begin_comment
comment|// RUN: grep 't2.c:7:3,' %t
end_comment

begin_comment
comment|// RUN: index-test %t1.ast %t2.ast -point-at %S/Inputs/foo.h:4:9 -print-refs> %t
end_comment

begin_comment
comment|// RUN: cat %t | count 1
end_comment

begin_comment
comment|// RUN: grep 't1.c:8:3,' %t
end_comment

begin_comment
comment|// RUN: index-test %t1.ast %t2.ast -point-at %S/Inputs/t1.c:3:22 -print-refs> %t
end_comment

begin_comment
comment|// RUN: cat %t | count 1
end_comment

begin_comment
comment|// RUN: grep 't1.c:6:17,' %t
end_comment

begin_comment
comment|// RUN: index-test %t1.ast %t2.ast -point-at %S/Inputs/t1.c:4:11 -print-refs> %t
end_comment

begin_comment
comment|// RUN: cat %t | count 1
end_comment

begin_comment
comment|// RUN: grep 't1.c:6:5,' %t
end_comment

begin_comment
comment|// RUN: index-test %t1.ast %t2.ast -point-at %S/Inputs/t1.c:5:30 -print-refs> %t
end_comment

begin_comment
comment|// RUN: cat %t | count 3
end_comment

begin_comment
comment|// RUN: grep 't1.c:5:27,' %t
end_comment

begin_comment
comment|// RUN: grep 't1.c:5:44,' %t
end_comment

begin_comment
comment|// RUN: grep 't1.c:6:26,' %t
end_comment

begin_comment
comment|// field test
end_comment

begin_comment
comment|// FIXME: References point at the start of MemberExpr, make them point at the field instead.
end_comment

begin_comment
comment|// RUN: index-test %t1.ast %t2.ast -point-at %S/Inputs/t1.c:12:7 -print-refs> %t
end_comment

begin_comment
comment|// RUN: cat %t | count 1
end_comment

begin_comment
comment|// RUN: grep 't1.c:21:3,' %t
end_comment

begin_comment
comment|// RUN: index-test %t1.ast %t2.ast -point-at %S/Inputs/t1.c:16:7 -print-refs> %t
end_comment

begin_comment
comment|// RUN: cat %t | count 1
end_comment

begin_comment
comment|// RUN: grep 't1.c:22:3,' %t
end_comment

begin_comment
comment|// RUN: index-test %t1.ast %t2.ast -point-at %S/Inputs/foo.h:7:11 -print-refs> %t
end_comment

begin_comment
comment|// RUN: cat %t | count 2
end_comment

begin_comment
comment|// RUN: grep 't1.c:25:3,' %t
end_comment

begin_comment
comment|// RUN: grep 't2.c:10:3,' %t
end_comment

end_unit

