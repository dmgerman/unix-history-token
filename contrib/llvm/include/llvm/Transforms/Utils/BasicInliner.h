begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- BasicInliner.h - Basic function level inliner ------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file defines a simple function based inliner that does not use
end_comment

begin_comment
comment|// call graph information.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BASICINLINER_H
end_ifndef

begin_define
define|#
directive|define
name|BASICINLINER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/InlineCost.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Function
decl_stmt|;
name|class
name|TargetData
decl_stmt|;
struct_decl|struct
name|BasicInlinerImpl
struct_decl|;
comment|/// BasicInliner - BasicInliner provides function level inlining interface.
comment|/// Clients provide list of functions which are inline without using
comment|/// module level call graph information. Note that the BasicInliner is
comment|/// free to delete a function if it is inlined into all call sites.
name|class
name|BasicInliner
block|{
name|public
label|:
name|explicit
name|BasicInliner
parameter_list|(
name|TargetData
modifier|*
name|T
init|=
name|NULL
parameter_list|)
function_decl|;
operator|~
name|BasicInliner
argument_list|()
expr_stmt|;
comment|/// addFunction - Add function into the list of functions to process.
comment|/// All functions must be inserted using this interface before invoking
comment|/// inlineFunctions().
name|void
name|addFunction
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
comment|/// neverInlineFunction - Sometimes a function is never to be inlined
comment|/// because of one or other reason.
name|void
name|neverInlineFunction
parameter_list|(
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
comment|/// inlineFuctions - Walk all call sites in all functions supplied by
comment|/// client. Inline as many call sites as possible. Delete completely
comment|/// inlined functions.
name|void
name|inlineFunctions
parameter_list|()
function_decl|;
name|private
label|:
name|BasicInlinerImpl
modifier|*
name|Impl
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

