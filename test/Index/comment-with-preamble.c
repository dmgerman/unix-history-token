begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Make sure the preable does not truncate comments.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BAZ
end_ifndef

begin_define
define|#
directive|define
name|BAZ
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//! Fooâs description.
end_comment

begin_function_decl
name|void
name|Foo
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// RUN: c-index-test -test-load-source-reparse 1 local %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: env CINDEXTEST_EDITING=1 c-index-test -test-load-source-reparse 1 local %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: FunctionDecl=Foo:8:6 RawComment=[//! Fooâs description.] RawCommentRange=[7:1 - 7:25] BriefComment=[Fooâs description.]
end_comment

end_unit

