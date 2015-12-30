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

begin_decl_stmt
name|int
name|notdoxy7
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Not a Doxygen juxtaposed comment.  notdoxy7 NOT_DOXYGEN
end_comment

begin_decl_stmt
name|int
name|notdoxy8
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Not a Doxygen juxtaposed comment.  notdoxy8 NOT_DOXYGEN
end_comment

begin_decl_stmt
name|int
name|trdoxy9
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// A Doxygen non-trailing comment.  trdoxyA IS_DOXYGEN_SINGLE
end_comment

begin_decl_stmt
name|int
name|trdoxyA
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|trdoxyB
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Not a Doxygen trailing comment.  PART_ONE
end_comment

begin_comment
comment|// It's a multiline one too.  trdoxyB NOT_DOXYGEN
end_comment

begin_decl_stmt
name|int
name|trdoxyC
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|trdoxyD
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Not a Doxygen trailing comment.   trdoxyD NOT_DOXYGEN
end_comment

begin_comment
comment|/// This comment doesn't get merged.   trdoxyE IS_DOXYGEN
end_comment

begin_decl_stmt
name|int
name|trdoxyE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|trdoxyF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// A Doxygen non-trailing comment that gets dropped on the floor.
end_comment

begin_comment
comment|// This comment will also be dropped.
end_comment

begin_decl_stmt
name|int
name|trdoxyG
decl_stmt|;
end_decl_stmt

begin_comment
comment|// This one won't.  trdoxyG NOT_DOXYGEN
end_comment

begin_decl_stmt
name|int
name|trdoxyH
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< A Doxygen trailing comment.  PART_ONE
end_comment

begin_comment
comment|// This one gets merged with it.  trdoxyH SOME_DOXYGEN
end_comment

begin_decl_stmt
name|int
name|trdoxyI
decl_stmt|;
end_decl_stmt

begin_comment
comment|// This one doesn't.  trdoxyI NOT_DOXYGEN
end_comment

begin_decl_stmt
name|int
name|trdoxyJ
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Not a Doxygen trailing comment.  PART_ONE
end_comment

begin_comment
comment|///< This one gets merged with it.  trdoxyJ SOME_DOXYGEN
end_comment

begin_decl_stmt
name|int
name|trdoxyK
decl_stmt|;
end_decl_stmt

begin_comment
comment|// This one doesn't.  trdoxyK NOT_DOXYGEN
end_comment

begin_decl_stmt
name|int
name|trdoxyL
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Not a Doxygen trailing comment.  trdoxyL NOT_DOXYGEN
end_comment

begin_comment
comment|// This one shouldn't get merged.  trdoxyM NOT_DOXYGEN
end_comment

begin_decl_stmt
name|int
name|trdoxyM
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|trdoxyN
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< A Doxygen trailing comment.  trdoxyN IS_DOXYGEN
end_comment

begin_comment
comment|// This one shouldn't get merged.  trdoxyO NOT_DOXYGEN
end_comment

begin_decl_stmt
name|int
name|trdoxyO
decl_stmt|;
end_decl_stmt

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
comment|// RUN: c-index-test -write-pch %t/out.pch -fparse-all-comments -x c++ -std=c++11 %s
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

begin_comment
comment|// CHECK: parse-all-comments.c:36:5: VarDecl=notdoxy7:{{.*}} notdoxy7 NOT_DOXYGEN
end_comment

begin_comment
comment|// CHECK: parse-all-comments.c:37:5: VarDecl=notdoxy8:{{.*}} notdoxy8 NOT_DOXYGEN
end_comment

begin_comment
comment|// CHECK-NOT: parse-all-comments.c:39:5: VarDecl=trdoxy9:{{.*}} trdoxyA IS_DOXYGEN_SINGLE
end_comment

begin_comment
comment|// CHECK: parse-all-comments.c:40:5: VarDecl=trdoxyA:{{.*}} trdoxyA IS_DOXYGEN_SINGLE
end_comment

begin_comment
comment|// CHECK: parse-all-comments.c:42:5: VarDecl=trdoxyB:{{.*}} PART_ONE {{.*}} trdoxyB NOT_DOXYGEN
end_comment

begin_comment
comment|// CHECK-NOT: parse-all-comments.c:44:5: VarDecl=trdoxyC:{{.*}} trdoxyB NOT_DOXYGEN
end_comment

begin_comment
comment|// CHECK: parse-all-comments.c:46:5: VarDecl=trdoxyD:{{.*}} trdoxyD NOT_DOXYGEN
end_comment

begin_comment
comment|// CHECK: parse-all-comments.c:48:5: VarDecl=trdoxyE:{{.*}} trdoxyE IS_DOXYGEN
end_comment

begin_comment
comment|// CHECK-NOT: parse-all-comments.c:50:5: VarDecl=trdoxyF:{{.*}} RawComment
end_comment

begin_comment
comment|// CHECK: parse-all-comments.c:52:5: VarDecl=trdoxyG:{{.*}} trdoxyG NOT_DOXYGEN
end_comment

begin_comment
comment|// CHECK: parse-all-comments.c:54:5: VarDecl=trdoxyH:{{.*}} PART_ONE {{.*}} trdoxyH SOME_DOXYGEN
end_comment

begin_comment
comment|// CHECK: parse-all-comments.c:56:5: VarDecl=trdoxyI:{{.*}} trdoxyI NOT_DOXYGEN
end_comment

begin_comment
comment|// CHECK: parse-all-comments.c:58:5: VarDecl=trdoxyJ:{{.*}} PART_ONE {{.*}} trdoxyJ SOME_DOXYGEN
end_comment

begin_comment
comment|// CHECK: parse-all-comments.c:60:5: VarDecl=trdoxyK:{{.*}} trdoxyK NOT_DOXYGEN
end_comment

begin_comment
comment|// CHECK: parse-all-comments.c:62:5: VarDecl=trdoxyL:{{.*}} trdoxyL NOT_DOXYGEN
end_comment

begin_comment
comment|// CHECK: parse-all-comments.c:64:5: VarDecl=trdoxyM:{{.*}} trdoxyM NOT_DOXYGEN
end_comment

begin_comment
comment|// CHECK: parse-all-comments.c:66:5: VarDecl=trdoxyN:{{.*}} trdoxyN IS_DOXYGEN
end_comment

begin_comment
comment|// CHECK: parse-all-comments.c:68:5: VarDecl=trdoxyO:{{.*}} trdoxyO NOT_DOXYGEN
end_comment

end_unit

