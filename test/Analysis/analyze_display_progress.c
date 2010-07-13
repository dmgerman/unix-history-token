begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -analyze -analyzer-display-progress %s 2>&1 | FileCheck %s
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|g
parameter_list|()
block|{}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|h
parameter_list|()
block|{}
end_function

begin_comment
comment|// CHECK: analyze_display_progress.c f
end_comment

begin_comment
comment|// CHECK: analyze_display_progress.c g
end_comment

begin_comment
comment|// CHECK: analyze_display_progress.c h
end_comment

end_unit

