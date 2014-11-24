begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 CINDEXTEST_COMPLETION_BRIEF_COMMENTS=1 LIBCLANG_DISABLE_CRASH_RECOVERY=1 \
end_comment

begin_comment
comment|// RUN:   c-index-test -test-load-source-reparse 2 all -remap-file-0="%S/test.h,%S/test.h-0" -remap-file-1="%S/test.h,%S/test.h-1" -- %s
end_comment

begin_include
include|#
directive|include
file|"test.h"
end_include

begin_function
name|void
name|foo
parameter_list|()
block|{
name|bar
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

