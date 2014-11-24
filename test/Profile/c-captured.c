begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.9 -main-file-name c-captured.c %s -o - -emit-llvm -fprofile-instr-generate | FileCheck -check-prefix=PGOGEN -check-prefix=PGOALL %s
end_comment

begin_comment
comment|// RUN: llvm-profdata merge %S/Inputs/c-captured.proftext -o %t.profdata
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-macosx10.9 -main-file-name c-captured.c %s -o - -emit-llvm -fprofile-instr-use=%t.profdata | FileCheck -check-prefix=PGOUSE -check-prefix=PGOALL %s
end_comment

begin_comment
comment|// PGOGEN: @[[DCC:__llvm_profile_counters_debug_captured]] = hidden global [3 x i64] zeroinitializer
end_comment

begin_comment
comment|// PGOGEN: @[[CSC:__llvm_profile_counters___captured_stmt]] = internal global [2 x i64] zeroinitializer
end_comment

begin_comment
comment|// PGOGEN: @[[C1C:__llvm_profile_counters___captured_stmt1]] = internal global [3 x i64] zeroinitializer
end_comment

begin_comment
comment|// PGOALL-LABEL: define void @debug_captured()
end_comment

begin_comment
comment|// PGOGEN: store {{.*}} @[[DCC]], i64 0, i64 0
end_comment

begin_function
name|void
name|debug_captured
parameter_list|()
block|{
name|int
name|x
init|=
literal|10
decl_stmt|;
comment|// Check both debug_captured counters, so we can do this all in one pass
comment|// PGOGEN: store {{.*}} @[[DCC]], i64 0, i64 1
comment|// PGOUSE: br {{.*}} !prof ![[DC1:[0-9]+]]
comment|// PGOGEN: store {{.*}} @[[DCC]], i64 0, i64 2
comment|// PGOUSE: br {{.*}} !prof ![[DC2:[0-9]+]]
comment|// PGOALL: ret
comment|// PGOALL-LABEL: define internal void @__captured_stmt(
comment|// PGOGEN: store {{.*}} @[[CSC]], i64 0, i64 0
pragma|#
directive|pragma
name|clang
name|__debug
name|captured
block|{
comment|// PGOGEN: store {{.*}} @[[CSC]], i64 0, i64 1
comment|// PGOUSE: br {{.*}} !prof ![[CS1:[0-9]+]]
if|if
condition|(
name|x
condition|)
block|{}
comment|// PGOALL: ret
block|}
if|if
condition|(
name|x
condition|)
block|{}
comment|// This is DC1. Checked above.
comment|// PGOALL-LABEL: define internal void @__captured_stmt1(
comment|// PGOGEN: store {{.*}} @[[C1C]], i64 0, i64 0
pragma|#
directive|pragma
name|clang
name|__debug
name|captured
block|{
comment|// PGOGEN: store {{.*}} @[[C1C]], i64 0, i64 1
comment|// PGOUSE: br {{.*}} !prof ![[C11:[0-9]+]]
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|x
condition|;
operator|++
name|i
control|)
block|{}
comment|// PGOGEN: store {{.*}} @[[C1C]], i64 0, i64 2
comment|// PGOUSE: br {{.*}} !prof ![[C12:[0-9]+]]
if|if
condition|(
name|x
condition|)
block|{}
comment|// PGOALL: ret
block|}
if|if
condition|(
name|x
condition|)
block|{}
comment|// This is DC2. Checked above.
block|}
end_function

begin_comment
comment|// PGOUSE-DAG: ![[DC1]] = metadata !{metadata !"branch_weights", i32 2, i32 1}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[DC2]] = metadata !{metadata !"branch_weights", i32 2, i32 1}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[CS1]] = metadata !{metadata !"branch_weights", i32 2, i32 1}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[C11]] = metadata !{metadata !"branch_weights", i32 11, i32 2}
end_comment

begin_comment
comment|// PGOUSE-DAG: ![[C12]] = metadata !{metadata !"branch_weights", i32 2, i32 1}
end_comment

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|debug_captured
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

