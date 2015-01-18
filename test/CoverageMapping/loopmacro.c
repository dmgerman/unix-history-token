begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fprofile-instr-generate -fcoverage-mapping -dump-coverage-mapping -emit-llvm-only -main-file-name loopmacro.c %s | FileCheck %s
end_comment

begin_define
define|#
directive|define
name|HASH_BITS
value|15
end_define

begin_define
define|#
directive|define
name|MIN_MATCH
value|3
end_define

begin_define
define|#
directive|define
name|H_SHIFT
value|((HASH_BITS+MIN_MATCH-1)/MIN_MATCH)
end_define

begin_define
define|#
directive|define
name|WMASK
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|HASH_MASK
value|0xFFFF
end_define

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

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// CHECK: File 0, [[@LINE]]:12 -> [[@LINE+12]]:2 = #0 (HasCodeBefore = 0)
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
comment|// CHECK-NEXT: File 0, [[@LINE]]:6 -> [[@LINE+3]]:30 = (#0 + #1) (HasCodeBefore = 0)
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
comment|// CHECK-NEXT: Expansion,File 0, [[@LINE]]:7 -> [[@LINE]]:20 = (#0 + #1) (HasCodeBefore = 0, Expanded file = 1)
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

begin_comment
comment|// CHECK-NEXT: File 0, 24:21 -> 24:29 = (#0 + #1) (HasCodeBefore = 0)
end_comment

begin_comment
comment|// CHECK-NEXT: File 0, 24:21 -> 24:29 = (#0 + #1) (HasCodeBefore = 0)
end_comment

begin_comment
comment|// CHECK-NEXT: File 0, 24:21 -> 24:29 = (#0 + #1) (HasCodeBefore = 0)
end_comment

begin_comment
comment|// CHECK-NEXT: File 0, 24:31 -> 24:40 = (#0 + #1) (HasCodeBefore = 0)
end_comment

begin_comment
comment|// CHECK-NEXT: File 1, 10:4 -> 12:23 = (#0 + #1) (HasCodeBefore = 0)
end_comment

begin_comment
comment|// CHECK-NEXT: Expansion,File 1, 10:5 -> 10:16 = (#0 + #1) (HasCodeBefore = 0, Expanded file = 2)
end_comment

begin_comment
comment|// CHECK-NEXT: File 1, 10:17 -> 10:22 = (#0 + #1) (HasCodeBefore = 0)
end_comment

begin_comment
comment|// CHECK-NEXT: File 1, 10:17 -> 10:22 = (#0 + #1) (HasCodeBefore = 0)
end_comment

begin_comment
comment|// CHECK-NEXT: File 1, 10:24 -> 10:32 = (#0 + #1) (HasCodeBefore = 0)
end_comment

begin_comment
comment|// CHECK-NEXT: File 1, 10:33 -> 10:36 = (#0 + #1) (HasCodeBefore = 0)
end_comment

begin_comment
comment|// CHECK-NEXT: File 1, 10:46 -> 10:49 = (#0 + #1) (HasCodeBefore = 0)
end_comment

begin_comment
comment|// CHECK-NEXT: File 2, 8:26 -> 8:66 = (#0 + #1) (HasCodeBefore = 0)
end_comment

begin_comment
comment|// CHECK-NEXT: Expansion,File 2, 8:38 -> 8:45 = (#0 + #1) (HasCodeBefore = 0, Expanded file = 3)
end_comment

begin_comment
comment|// CHECK-NEXT: File 3, 5:18 -> 5:53 = (#0 + #1) (HasCodeBefore = 0)
end_comment

end_unit

