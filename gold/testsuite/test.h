begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// test.h -- simplistic test framework for gold unittests -*- C++ -*-
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GOLD_TESTSUITE_TEST_H
end_ifndef

begin_define
define|#
directive|define
name|GOLD_TESTSUITE_TEST_H
end_define

begin_decl_stmt
name|namespace
name|gold_testsuite
block|{
name|class
name|Test_report
decl_stmt|;
comment|// This class handles basic test framework functionality.
name|class
name|Test_framework
block|{
name|public
label|:
name|Test_framework
argument_list|()
operator|:
name|testname_
argument_list|(
name|NULL
argument_list|)
operator|,
name|current_fail_
argument_list|(
literal|0
argument_list|)
operator|,
name|passes_
argument_list|(
literal|0
argument_list|)
operator|,
name|failures_
argument_list|(
literal|0
argument_list|)
block|{ }
comment|// Return number of failures.
name|unsigned
name|int
name|failures
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|failures_
return|;
block|}
comment|// Run a test.
name|void
name|run
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|bool
function_decl|(
modifier|*
name|pfn
function_decl|)
parameter_list|(
name|Test_report
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
comment|// Get the current Test_report.  This is used by the test support
comment|// macros.
specifier|static
name|Test_report
modifier|*
name|report
parameter_list|()
block|{
return|return
name|Test_framework
operator|::
name|current_report
return|;
block|}
name|private
label|:
name|friend
name|class
name|Test_report
decl_stmt|;
comment|// Cause the current test to fail.
name|void
name|fail
parameter_list|()
block|{
operator|++
name|this
operator|->
name|current_fail_
operator|=
name|true
expr_stmt|;
block|}
comment|// Report an error from the current test.
name|void
name|error
parameter_list|(
specifier|const
name|char
modifier|*
name|message
parameter_list|)
function_decl|;
comment|// Current Test_report.  This is a static variable valid while a
comment|// test is being run.
specifier|static
name|Test_report
modifier|*
name|current_report
decl_stmt|;
comment|// Current test being run.
specifier|const
name|char
modifier|*
name|testname_
decl_stmt|;
comment|// Whether the current test is failing.
name|bool
name|current_fail_
decl_stmt|;
comment|// Total number of passeed tests.
name|unsigned
name|int
name|passes_
decl_stmt|;
comment|// Total number of failed tests.
name|unsigned
name|int
name|failures_
decl_stmt|;
block|}
empty_stmt|;
comment|// An instance of this class is passed to each test function.
name|class
name|Test_report
block|{
name|public
label|:
name|Test_report
argument_list|(
name|Test_framework
operator|*
name|tf
argument_list|)
operator|:
name|tf_
argument_list|(
argument|tf
argument_list|)
block|{ }
comment|// Mark the test as failing.
name|void
name|fail
argument_list|()
block|{
name|this
operator|->
name|tf_
operator|->
name|fail
argument_list|()
block|; }
comment|// Report an error.
name|void
name|error
argument_list|(
argument|const char* message
argument_list|)
block|{
name|this
operator|->
name|tf_
operator|->
name|error
argument_list|(
name|message
argument_list|)
block|; }
name|private
operator|:
name|Test_framework
operator|*
name|tf_
expr_stmt|;
block|}
empty_stmt|;
comment|// This class registers a test function so that the testsuite runs it.
name|class
name|Register_test
block|{
name|public
label|:
name|Register_test
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
name|bool
argument_list|(
operator|*
name|pfn
argument_list|)
argument_list|(
name|Test_report
operator|*
argument_list|)
argument_list|)
expr_stmt|;
comment|// Run all registered tests.
specifier|static
name|void
name|run_tests
parameter_list|(
name|Test_framework
modifier|*
parameter_list|)
function_decl|;
name|private
label|:
comment|// Linked list of all tests.
specifier|static
name|Register_test
modifier|*
name|all_tests
decl_stmt|;
comment|// Test name.
specifier|const
name|char
modifier|*
name|name_
decl_stmt|;
comment|// Function to call.  It should return true if the test passes,
comment|// false if it fails.
name|bool
function_decl|(
modifier|*
name|pfn_
function_decl|)
parameter_list|(
name|Test_report
modifier|*
parameter_list|)
function_decl|;
comment|// Next test in linked list.
name|Register_test
modifier|*
name|next_
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace gold_testsuite.
end_comment

begin_comment
comment|// These macros are for convenient use in tests.
end_comment

begin_comment
comment|// Check that a condition is true.  If it is false, report a failure.
end_comment

begin_define
define|#
directive|define
name|CHECK
parameter_list|(
name|cond
parameter_list|)
define|\
value|((cond) ? 0 : (::gold_testsuite::Test_framework::report()->fail(), 0))
end_define

begin_comment
comment|// Report an error during a test.
end_comment

begin_define
define|#
directive|define
name|ERROR
parameter_list|(
name|msg
parameter_list|)
value|(::gold_testsuite::Test_framework::report()->error(msg))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(GOLD_TESTSUITE_TEST_H)
end_comment

end_unit

