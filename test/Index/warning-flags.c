begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_function
name|int
name|foo
parameter_list|()
block|{ }
end_function

begin_function
name|int
modifier|*
name|bar
parameter_list|(
name|float
modifier|*
name|f
parameter_list|)
block|{
return|return
name|f
return|;
block|}
end_function

begin_comment
comment|// RUN: c-index-test -test-load-source all %s 2>&1|FileCheck -check-prefix=CHECK-BOTH-WARNINGS %s
end_comment

begin_comment
comment|// RUN: c-index-test -test-load-source-reparse 5 all %s 2>&1|FileCheck -check-prefix=CHECK-BOTH-WARNINGS %s
end_comment

begin_comment
comment|// RUN: c-index-test -test-load-source all -Wno-return-type  %s 2>&1|FileCheck -check-prefix=CHECK-SECOND-WARNING %s
end_comment

begin_comment
comment|// RUN: c-index-test -test-load-source-reparse 5 all -Wno-return-type %s 2>&1|FileCheck -check-prefix=CHECK-SECOND-WARNING %s
end_comment

begin_comment
comment|// RUN: c-index-test -test-load-source all -w %s 2>&1|not grep warning:
end_comment

begin_comment
comment|// RUN: c-index-test -test-load-source-reparse 5 all -w %s 2>&1|not grep warning:
end_comment

begin_comment
comment|// CHECK-BOTH-WARNINGS: warning: control reaches end of non-void function
end_comment

begin_comment
comment|// CHECK-BOTH-WARNINGS: warning: incompatible pointer types returning 'float *' from a function with result type 'int *'
end_comment

begin_comment
comment|// CHECK-SECOND-WARNING-NOT:control reaches end of non-void
end_comment

begin_comment
comment|// CHECK-SECOND-WARNING: warning: incompatible pointer types returning 'float *' from a function with result type 'int *'
end_comment

end_unit

