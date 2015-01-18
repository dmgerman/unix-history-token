begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CFGStmtMap.h - Map from Stmt* to CFGBlock* -----------*- C++ -*-===//
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
comment|//  This file defines the CFGStmtMap class, which defines a mapping from
end_comment

begin_comment
comment|//  Stmt* to CFGBlock*
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
name|LLVM_CLANG_ANALYSIS_CFGSTMTMAP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_CFGSTMTMAP_H
end_define

begin_include
include|#
directive|include
file|"clang/Analysis/CFG.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|CFG
decl_stmt|;
name|class
name|CFGBlock
decl_stmt|;
name|class
name|ParentMap
decl_stmt|;
name|class
name|Stmt
decl_stmt|;
name|class
name|CFGStmtMap
block|{
name|ParentMap
modifier|*
name|PM
decl_stmt|;
name|void
modifier|*
name|M
decl_stmt|;
name|CFGStmtMap
argument_list|(
name|ParentMap
operator|*
name|pm
argument_list|,
name|void
operator|*
name|m
argument_list|)
operator|:
name|PM
argument_list|(
name|pm
argument_list|)
operator|,
name|M
argument_list|(
argument|m
argument_list|)
block|{}
name|public
operator|:
operator|~
name|CFGStmtMap
argument_list|()
expr_stmt|;
comment|/// Returns a new CFGMap for the given CFG.  It is the caller's
comment|/// responsibility to 'delete' this object when done using it.
specifier|static
name|CFGStmtMap
modifier|*
name|Build
parameter_list|(
name|CFG
modifier|*
name|C
parameter_list|,
name|ParentMap
modifier|*
name|PM
parameter_list|)
function_decl|;
comment|/// Returns the CFGBlock the specified Stmt* appears in.  For Stmt* that
comment|/// are terminators, the CFGBlock is the block they appear as a terminator,
comment|/// and not the block they appear as a block-level expression (e.g, '&&').
comment|/// CaseStmts and LabelStmts map to the CFGBlock they label.
name|CFGBlock
modifier|*
name|getBlock
parameter_list|(
name|Stmt
modifier|*
name|S
parameter_list|)
function_decl|;
specifier|const
name|CFGBlock
modifier|*
name|getBlock
argument_list|(
specifier|const
name|Stmt
operator|*
name|S
argument_list|)
decl|const
block|{
return|return
name|const_cast
operator|<
name|CFGStmtMap
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getBlock
argument_list|(
name|const_cast
operator|<
name|Stmt
operator|*
operator|>
operator|(
name|S
operator|)
argument_list|)
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

