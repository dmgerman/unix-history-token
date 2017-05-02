begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
name|a
name|bc
end_expr_stmt

begin_comment
comment|// RUN: echo "[{\"file\": \"%/s\", \"offset\": 1, \"remove\": 2, }]"> %t.remap
end_comment

begin_comment
comment|// RUN: c-arcmt-test %t.remap | arcmt-test -verify-transformed-files %s.result
end_comment

end_unit

