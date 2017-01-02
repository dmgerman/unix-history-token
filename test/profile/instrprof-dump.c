begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RUN: rm -fr %t.profdir RUN: %clang_profgen=%t.profdir/default_%m.profraw -o %t -O2 %s RUN: %run %t  2>&1 | FileCheck %s --check-prefix=NO_EXIT_WRITE RUN: llvm-profdata merge -o %t.profdata %t.profdir RUN: %clang_profuse=%t.profdata -o - -S -emit-llvm %s | FileCheck %s  --check-prefix=PROF  NO_EXIT_WRITE: Profile data not written to file: already written */
end_comment

begin_function_decl
name|int
name|__llvm_profile_dump
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__llvm_profile_reset_counters
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|foo
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bar
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|skip
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

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
name|int
name|Ret
init|=
name|foo
argument_list|(
literal|0
argument_list|)
decl_stmt|;
comment|/* region 1 */
name|__llvm_profile_dump
argument_list|()
expr_stmt|;
comment|/* not profiled -- cleared later. */
name|skip
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* skipped region */
name|__llvm_profile_reset_counters
argument_list|()
expr_stmt|;
name|Ret
operator|+=
name|bar
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* region 2 */
name|__llvm_profile_dump
argument_list|()
expr_stmt|;
name|skip
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|__llvm_profile_reset_counters
argument_list|()
expr_stmt|;
comment|/* foo's profile will be merged.  */
name|foo
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* region 3 */
name|__llvm_profile_dump
argument_list|()
expr_stmt|;
return|return
name|Ret
return|;
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|int
name|foo
parameter_list|(
name|int
name|X
parameter_list|)
block|{
comment|/* PROF: define {{.*}} @foo({{.*}}!prof ![[ENT:[0-9]+]]      PROF: br i1 %{{.*}}, label %{{.*}}, label %{{.*}}, !prof ![[PD1:[0-9]+]]   */
return|return
name|X
operator|<=
literal|0
condition|?
operator|-
name|X
else|:
name|X
return|;
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|int
name|skip
parameter_list|(
name|int
name|X
parameter_list|)
block|{
comment|/* PROF: define {{.*}} @skip(      PROF: br i1 %{{.*}}, label %{{.*}}, label %{{[^,]+$}}   */
return|return
name|X
operator|<=
literal|0
condition|?
operator|-
name|X
else|:
name|X
return|;
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(noinline)
argument_list|)
end_macro

begin_function
name|int
name|bar
parameter_list|(
name|int
name|X
parameter_list|)
block|{
comment|/* PROF-LABEL: define {{.*}} @bar(      PROF: br i1 %{{.*}}, label %{{.*}}, label %{{.*}}, !prof ![[PD2:[0-9]+]]   */
return|return
name|X
operator|<=
literal|0
condition|?
operator|-
name|X
else|:
name|X
return|;
block|}
end_function

begin_comment
comment|/* PROF: ![[ENT]] = !{!"function_entry_count", i64 2}   PROF: ![[PD1]] = !{!"branch_weights", i32 2, i32 2} */
end_comment

end_unit

