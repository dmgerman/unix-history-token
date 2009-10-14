begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Run lines are sensitive to line numbers and come below the code.
end_comment

begin_comment
comment|//! It all starts here.
end_comment

begin_comment
comment|/*! It's a little odd to continue line this,  *  * but we need more multi-line comments. */
end_comment

begin_comment
comment|/// This comment comes before my other comments
end_comment

begin_comment
comment|/** This is a block comment that is associated with the function f. It  *  runs for three lines.  */
end_comment

begin_function_decl
name|void
name|f
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// NOT IN THE COMMENT
end_comment

begin_comment
comment|/// This is a BCPL comment that is associated with the function g.
end_comment

begin_comment
comment|/// It has only two lines.
end_comment

begin_comment
comment|/** But there are other blocks that are part of the comment, too. */
end_comment

begin_function_decl
name|void
name|g
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|h
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|///< This is a member comment.
end_comment

begin_comment
comment|// RUN: clang-cc -emit-pch -o %t.ast %s&&
end_comment

begin_comment
comment|// RUN: index-test %t.ast -point-at %s:11:6> %t&&
end_comment

begin_comment
comment|// RUN: grep "starts here" %t&&
end_comment

begin_comment
comment|// RUN: grep "block comment" %t&&
end_comment

begin_comment
comment|// RUN: index-test %t.ast -point-at %s:17:6> %t&&
end_comment

begin_comment
comment|// RUN: grep "BCPL" %t&&
end_comment

begin_comment
comment|// RUN: grep "But" %t&&
end_comment

begin_comment
comment|// RUN: index-test %t.ast -point-at %s:19:6> %t&&
end_comment

begin_comment
comment|// RUN: grep "NOT" %t | count 0&&
end_comment

begin_comment
comment|// RUN: grep "member" %t
end_comment

end_unit

