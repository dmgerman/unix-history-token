begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fblocks -emit-pch %S/Inputs/t1.c -o %t1.ast
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fblocks -emit-pch %S/Inputs/t2.c -o %t2.ast
end_comment

begin_comment
comment|// RUN: index-test %t1.ast %t2.ast -point-at %S/Inputs/foo.h:1:14 -print-defs> %t
end_comment

begin_comment
comment|// RUN: cat %t | count 1
end_comment

begin_comment
comment|// RUN: grep 't2.c:3:5,' %t
end_comment

begin_comment
comment|// RUN: index-test %t1.ast %t2.ast -point-at %S/Inputs/foo.h:3:9 -print-defs> %t
end_comment

begin_comment
comment|// RUN: cat %t | count 1
end_comment

begin_comment
comment|// RUN: grep 't1.c:3:6,' %t
end_comment

begin_comment
comment|// RUN: index-test %t1.ast %t2.ast -point-at %S/Inputs/foo.h:4:9 -print-defs> %t
end_comment

begin_comment
comment|// RUN: cat %t | count 1
end_comment

begin_comment
comment|// RUN: grep 't2.c:5:6,' %t
end_comment

begin_comment
comment|// RUN: index-test %t1.ast %t2.ast -point-at %S/Inputs/t1.c:8:7 -print-defs> %t
end_comment

begin_comment
comment|// RUN: cat %t | count 1
end_comment

begin_comment
comment|// RUN: grep 't2.c:5:6,' %t
end_comment

end_unit

