begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Preamble detection test: header with an include guard.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_H
end_ifndef

begin_define
define|#
directive|define
name|HEADER_H
end_define

begin_include
include|#
directive|include
file|"foo"
end_include

begin_decl_stmt
name|int
name|bar
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// This test checks for detection of the preamble of a file, which
end_comment

begin_comment
comment|// includes all of the starting comments and #includes.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -print-preamble %s> %t
end_comment

begin_comment
comment|// RUN: echo END.>> %t
end_comment

begin_comment
comment|// RUN: FileCheck< %t %s
end_comment

begin_comment
comment|// CHECK: // Preamble detection test: header with an include guard.
end_comment

begin_comment
comment|// CHECK-NEXT: #ifndef HEADER_H
end_comment

begin_comment
comment|// CHECK-NEXT: #define HEADER_H
end_comment

begin_comment
comment|// CHECK-NEXT: #include "foo"
end_comment

begin_comment
comment|// CHECK-NEXT: END.
end_comment

end_unit

