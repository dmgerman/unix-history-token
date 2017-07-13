begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: diagtool find-diagnostic-id warn_unused_variable | FileCheck %s
end_comment

begin_comment
comment|// RUN: not diagtool find-diagnostic-id warn_unused_vars 2>&1 | FileCheck --check-prefix=ERROR %s
end_comment

begin_comment
comment|// CHECK: {{^[0-9]+$}}
end_comment

begin_comment
comment|// ERROR: error: invalid diagnostic 'warn_unused_vars'
end_comment

end_unit

