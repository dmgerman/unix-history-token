begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core,unix.Malloc,debug.ExprInspection -analyzer-config max-nodes=12 -verify %s
end_comment

begin_comment
comment|// Here we test how "suppress on sink" feature of certain bugtypes interacts
end_comment

begin_comment
comment|// with reaching analysis limits.
end_comment

begin_comment
comment|// If we report a warning of a bug-type with "suppress on sink" attribute set
end_comment

begin_comment
comment|// (such as MallocChecker's memory leak warning), then failing to reach the
end_comment

begin_comment
comment|// reason for the sink (eg. no-return function such as "exit()") due to analysis
end_comment

begin_comment
comment|// limits (eg. max-nodes option), we may produce a false positive.
end_comment

begin_typedef
typedef|typedef
name|__typeof
argument_list|(
argument|sizeof(int)
argument_list|)
name|size_t
expr_stmt|;
end_typedef

begin_function_decl
name|void
modifier|*
name|malloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|exit
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__noreturn__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|clang_analyzer_warnIfReached
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|test_single_cfg_block_sink
parameter_list|()
block|{
name|void
modifier|*
name|p
init|=
name|malloc
argument_list|(
literal|1
argument_list|)
decl_stmt|;
comment|// no-warning (wherever the leak warning may occur here)
comment|// Due to max-nodes option in the run line, we should reach the first call
comment|// but bail out before the second call.
comment|// If the test on these two lines starts failing, see if modifying
comment|// the max-nodes run-line helps.
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// expected-warning{{REACHABLE}}
name|clang_analyzer_warnIfReached
argument_list|()
expr_stmt|;
comment|// no-warning
comment|// Even though we do not reach this line, we should still suppress
comment|// the leak report.
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

