begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instrument=clang -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only -main-file-name loopmacro.c %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: main
end_comment

begin_comment
comment|// CHECK-NEXT: File 0, {{[0-9]+}}:12 -> {{[0-9]+}}:2 = #0
end_comment

begin_comment
comment|// CHECK-NEXT: File 0, {{[0-9]+}}:6 -> {{[0-9]+}}:4 = (#0 + #1)
end_comment

begin_comment
comment|// CHECK-NEXT: Expansion,File 0, {{[0-9]+}}:7 -> {{[0-9]+}}:20 = (#0 + #1)
end_comment

begin_comment
comment|// CHECK-NEXT: File 0, {{[0-9]+}}:12 -> {{[0-9]+}}:30 = (#0 + #1)
end_comment

begin_comment
comment|// CHECK-NEXT: File 1, [[@LINE+4]]:4 -> [[@LINE+6]]:23 = (#0 + #1)
end_comment

begin_comment
comment|// CHECK-NEXT: Expansion,File 1, [[@LINE+3]]:5 -> [[@LINE+3]]:16 = (#0 + #1)
end_comment

begin_comment
comment|// CHECK-NEXT: Expansion,File 1, [[@LINE+3]]:16 -> [[@LINE+3]]:21 = (#0 + #1)
end_comment

begin_define
define|#
directive|define
name|INSERT_STRING
parameter_list|(
name|s
parameter_list|,
name|match_head
parameter_list|)
define|\
value|(UPDATE_HASH(ins_h, window[(s) + MIN_MATCH-1]), \     prev[(s)& WMASK] = match_head = head[ins_h], \     head[ins_h] = (s))
end_define

begin_comment
comment|// CHECK-NEXT: File 2, [[@LINE+3]]:26 -> [[@LINE+3]]:66 = (#0 + #1)
end_comment

begin_comment
comment|// CHECK-NEXT: Expansion,File 2, [[@LINE+2]]:38 -> [[@LINE+2]]:45 = (#0 + #1)
end_comment

begin_comment
comment|// CHECK-NEXT: Expansion,File 2, [[@LINE+1]]:56 -> [[@LINE+1]]:65 = (#0 + #1)
end_comment

begin_define
define|#
directive|define
name|UPDATE_HASH
parameter_list|(
name|h
parameter_list|,
name|c
parameter_list|)
value|(h = (((h)<<H_SHIFT) ^ (c))& HASH_MASK)
end_define

begin_comment
comment|// CHECK-NEXT: File 3, [[@LINE+1]]:15 -> [[@LINE+1]]:21 = (#0 + #1)
end_comment

begin_define
define|#
directive|define
name|WMASK
value|0xFFFF
end_define

begin_comment
comment|// CHECK-NEXT: File 4, [[@LINE+4]]:18 -> [[@LINE+4]]:53 = (#0 + #1)
end_comment

begin_comment
comment|// CHECK-NEXT: Expansion,File 4, [[@LINE+3]]:20 -> [[@LINE+3]]:29 = (#0 + #1)
end_comment

begin_comment
comment|// CHECK-NEXT: Expansion,File 4, [[@LINE+2]]:30 -> [[@LINE+2]]:39 = (#0 + #1)
end_comment

begin_comment
comment|// CHECK-NEXT: Expansion,File 4, [[@LINE+1]]:43 -> [[@LINE+1]]:52 = (#0 + #1)
end_comment

begin_define
define|#
directive|define
name|H_SHIFT
value|((HASH_BITS+MIN_MATCH-1)/MIN_MATCH)
end_define

begin_comment
comment|// CHECK-NEXT: File 5, [[@LINE+1]]:19 -> [[@LINE+1]]:25 = (#0 + #1)
end_comment

begin_define
define|#
directive|define
name|HASH_MASK
value|0xFFFF
end_define

begin_comment
comment|// CHECK-NEXT: File 6, [[@LINE+1]]:20 -> [[@LINE+1]]:22 = (#0 + #1)
end_comment

begin_define
define|#
directive|define
name|HASH_BITS
value|15
end_define

begin_comment
comment|// CHECK-NEXT: File 7, [[@LINE+2]]:20 -> [[@LINE+2]]:21 = (#0 + #1)
end_comment

begin_comment
comment|// CHECK-NEXT: File 8, [[@LINE+1]]:20 -> [[@LINE+1]]:21 = (#0 + #1)
end_comment

begin_define
define|#
directive|define
name|MIN_MATCH
value|3
end_define

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
name|strstart
init|=
literal|0
decl_stmt|;
name|int
name|hash_head
init|=
literal|2
decl_stmt|;
name|int
name|prev_length
init|=
literal|5
decl_stmt|;
name|int
name|ins_h
init|=
literal|1
decl_stmt|;
name|int
name|prev
index|[
literal|32
operator|<<
literal|10
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
name|int
name|head
index|[
literal|32
operator|<<
literal|10
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
name|int
name|window
index|[
literal|1024
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
do|do
block|{
name|strstart
operator|++
expr_stmt|;
name|INSERT_STRING
argument_list|(
name|strstart
argument_list|,
name|hash_head
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
operator|--
name|prev_length
operator|!=
literal|0
condition|)
do|;
block|}
end_function

end_unit

