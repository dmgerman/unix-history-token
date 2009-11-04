begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -E -C %s | FileCheck -strict-whitespace %s
end_comment

begin_comment
comment|// foo
end_comment

begin_comment
comment|// CHECK: // foo
end_comment

begin_comment
comment|/* bar */
end_comment

begin_comment
comment|// CHECK: /* bar */
end_comment

end_unit

