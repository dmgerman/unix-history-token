begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: c-index-test -test-load-source all -ccc-host-triple x86_64-apple-darwin10.0.0 -msse4.1 %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: c-index-test -test-load-source-reparse 1 all -ccc-host-triple x86_64-apple-darwin10.0.0 -msse4.1 %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// RUN: c-index-test -test-load-source-reparse 5 all -ccc-host-triple x86_64-apple-darwin10.0.0 -msse4.1 %s 2>&1 | FileCheck %s
end_comment

begin_comment
comment|// CHECK: error: #error SSE4_1 used
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SSE4_1__
argument_list|)
end_if

begin_error
error|#
directive|error
error|SSE4_1 used
end_error

begin_endif
endif|#
directive|endif
end_endif

end_unit

