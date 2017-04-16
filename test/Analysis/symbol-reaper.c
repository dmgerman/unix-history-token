begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=debug.ExprInspection -verify %s
end_comment

begin_function_decl
name|void
name|clang_analyzer_eval
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clang_analyzer_warnOnDeadSymbol
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clang_analyzer_numTimesReached
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|conjure_index
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|test_that_expr_inspection_works
parameter_list|()
block|{
do|do
block|{
name|int
name|x
init|=
name|conjure_index
argument_list|()
decl_stmt|;
name|clang_analyzer_warnOnDeadSymbol
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
literal|0
condition|)
do|;
comment|// expected-warning{{SYMBOL DEAD}}
comment|// Make sure we don't accidentally split state in ExprInspection.
name|clang_analyzer_numTimesReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{1}}
block|}
end_function

begin_comment
comment|// These tests verify the reaping of symbols that are only referenced as
end_comment

begin_comment
comment|// index values in element regions. Most of the time, depending on where
end_comment

begin_comment
comment|// the element region, as Loc value, is stored, it is possible to
end_comment

begin_comment
comment|// recover the index symbol in checker code, which is also demonstrated
end_comment

begin_comment
comment|// in the return_ptr_range.c test file.
end_comment

begin_decl_stmt
name|int
name|arr
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|int
modifier|*
name|test_element_index_lifetime_in_environment_values
parameter_list|()
block|{
name|int
modifier|*
name|ptr
decl_stmt|;
do|do
block|{
name|int
name|x
init|=
name|conjure_index
argument_list|()
decl_stmt|;
name|clang_analyzer_warnOnDeadSymbol
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|ptr
operator|=
name|arr
operator|+
name|x
expr_stmt|;
block|}
do|while
condition|(
literal|0
condition|)
do|;
return|return
name|ptr
return|;
block|}
end_function

begin_function
name|void
name|test_element_index_lifetime_in_store_keys
parameter_list|()
block|{
do|do
block|{
name|int
name|x
init|=
name|conjure_index
argument_list|()
decl_stmt|;
name|clang_analyzer_warnOnDeadSymbol
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|arr
index|[
name|x
index|]
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|x
condition|)
block|{}
block|}
do|while
condition|(
literal|0
condition|)
do|;
comment|// no-warning
block|}
end_function

begin_decl_stmt
name|int
modifier|*
name|ptr
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test_element_index_lifetime_in_store_values
parameter_list|()
block|{
do|do
block|{
name|int
name|x
init|=
name|conjure_index
argument_list|()
decl_stmt|;
name|clang_analyzer_warnOnDeadSymbol
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|ptr
operator|=
name|arr
operator|+
name|x
expr_stmt|;
block|}
do|while
condition|(
literal|0
condition|)
do|;
comment|// no-warning
block|}
end_function

begin_struct
struct|struct
name|S1
block|{
name|int
name|field
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|S2
block|{
name|struct
name|S1
name|array
index|[
literal|5
index|]
decl_stmt|;
block|}
name|s2
struct|;
end_struct

begin_function
name|void
name|test_element_index_lifetime_with_complicated_hierarchy_of_regions
parameter_list|()
block|{
do|do
block|{
name|int
name|x
init|=
name|conjure_index
argument_list|()
decl_stmt|;
name|clang_analyzer_warnOnDeadSymbol
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|s2
operator|.
name|array
index|[
name|x
index|]
operator|.
name|field
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|x
condition|)
block|{}
block|}
do|while
condition|(
literal|0
condition|)
do|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// Test below checks lifetime of SymbolRegionValue in certain conditions.
end_comment

begin_decl_stmt
name|int
modifier|*
modifier|*
name|ptrptr
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test_region_lifetime_as_store_value
parameter_list|(
name|int
modifier|*
name|x
parameter_list|)
block|{
name|clang_analyzer_warnOnDeadSymbol
argument_list|(
operator|(
name|int
operator|)
name|x
argument_list|)
expr_stmt|;
operator|*
name|x
operator|=
literal|1
expr_stmt|;
name|ptrptr
operator|=
operator|&
name|x
expr_stmt|;
operator|(
name|void
operator|)
literal|0
expr_stmt|;
comment|// No-op; make sure the environment forgets things and the GC runs.
name|clang_analyzer_eval
argument_list|(
operator|*
operator|*
name|ptrptr
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
block|}
end_function

begin_comment
comment|// no-warning
end_comment

end_unit

