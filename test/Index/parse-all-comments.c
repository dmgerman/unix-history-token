begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Run lines are sensitive to line numbers and come below the code.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER
end_ifndef

begin_define
define|#
directive|define
name|HEADER
end_define

begin_comment
comment|// Not a Doxygen comment.  notdoxy1 NOT_DOXYGEN
end_comment

begin_function_decl
name|void
name|notdoxy1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Not a Doxygen comment.  notdoxy2 NOT_DOXYGEN */
end_comment

begin_function_decl
name|void
name|notdoxy2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*/ Not a Doxygen comment.  notdoxy3 NOT_DOXYGEN */
end_comment

begin_function_decl
name|void
name|notdoxy3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** Doxygen comment.  isdoxy4 IS_DOXYGEN_SINGLE */
end_comment

begin_function_decl
name|void
name|isdoxy4
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*! Doxygen comment.  isdoxy5 IS_DOXYGEN_SINGLE */
end_comment

begin_function_decl
name|void
name|isdoxy5
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Doxygen comment.  isdoxy6 IS_DOXYGEN_SINGLE
end_comment

begin_function_decl
name|void
name|isdoxy6
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* BLOCK_ORDINARY_COMMENT */
end_comment

begin_comment
comment|// ORDINARY COMMENT
end_comment

begin_comment
comment|/// This is a BCPL comment. IS_DOXYGEN_START
end_comment

begin_comment
comment|/// It has only two lines.
end_comment

begin_comment
comment|/** But there are other blocks that are part of the comment, too.  IS_DOXYGEN_END */
end_comment

begin_function_decl
name|void
name|multi_line_comment_plus_ordinary
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// MULTILINE COMMENT
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// WITH EMPTY LINE
end_comment

begin_function_decl
name|void
name|multi_line_comment_empty_line
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// RUN: rm -rf %t
end_comment

begin_comment
comment|// RUN: mkdir %t
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fparse-all-comments -x c++ -std=c++11 -emit-pch -o %t/out.pch %s
end_comment

begin_comment
comment|// RUN: c-index-test -test-load-source all -comments-xml-schema=%S/../../bindings/xml/comment-xml-schema.rng %s -std=c++11 -fparse-all-comments> %t/out.c-index-direct
end_comment

begin_comment
comment|// RUN: c-index-test -test-load-tu %t/out.pch all> %t/out.c-index-pch
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=WRONG< %t/out.c-index-direct
end_comment

begin_comment
comment|// RUN: FileCheck %s -check-prefix=WRONG< %t/out.c-index-pch
end_comment

begin_comment
comment|// Ensure that XML is not invalid
end_comment

begin_comment
comment|// WRONG-NOT: CommentXMLInvalid
end_comment

begin_comment
comment|// RUN: FileCheck %s< %t/out.c-index-direct
end_comment

begin_comment
comment|// RUN: FileCheck %s< %t/out.c-index-pch
end_comment

begin_comment
comment|// CHECK: parse-all-comments.c:7:6: FunctionDecl=notdoxy1:{{.*}} notdoxy1 NOT_DOXYGEN
end_comment

begin_comment
comment|// CHECK: parse-all-comments.c:10:6: FunctionDecl=notdoxy2:{{.*}} notdoxy2 NOT_DOXYGEN
end_comment

begin_comment
comment|// CHECK: parse-all-comments.c:13:6: FunctionDecl=notdoxy3:{{.*}} notdoxy3 NOT_DOXYGEN
end_comment

begin_comment
comment|// CHECK: parse-all-comments.c:16:6: FunctionDecl=isdoxy4:{{.*}} isdoxy4 IS_DOXYGEN_SINGLE
end_comment

begin_comment
comment|// CHECK: parse-all-comments.c:19:6: FunctionDecl=isdoxy5:{{.*}} isdoxy5 IS_DOXYGEN_SINGLE
end_comment

begin_comment
comment|// CHECK: parse-all-comments.c:22:6: FunctionDecl=isdoxy6:{{.*}} isdoxy6 IS_DOXYGEN_SINGLE
end_comment

begin_comment
comment|// CHECK: parse-all-comments.c:29:6: FunctionDecl=multi_line_comment_plus_ordinary:{{.*}} BLOCK_ORDINARY_COMMENT {{.*}} ORDINARY COMMENT {{.*}} IS_DOXYGEN_START {{.*}} IS_DOXYGEN_END
end_comment

begin_comment
comment|// CHECK: parse-all-comments.c:34:6: FunctionDecl=multi_line_comment_empty_line:{{.*}} MULTILINE COMMENT{{.*}}\n{{.*}}\n{{.*}} WITH EMPTY LINE
end_comment

end_unit

