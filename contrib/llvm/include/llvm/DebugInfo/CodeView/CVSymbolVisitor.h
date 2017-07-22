begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CVSymbolVisitor.h ----------------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_DEBUGINFO_CODEVIEW_CVSYMBOLVISITOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_CVSYMBOLVISITOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/CVRecord.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/CodeView.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/SymbolRecord.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/SymbolVisitorDelegate.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorOr.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|class
name|SymbolVisitorCallbacks
decl_stmt|;
name|class
name|CVSymbolVisitor
block|{
name|public
label|:
name|CVSymbolVisitor
argument_list|(
name|SymbolVisitorCallbacks
operator|&
name|Callbacks
argument_list|)
expr_stmt|;
name|Error
name|visitSymbolRecord
parameter_list|(
name|CVSymbol
modifier|&
name|Record
parameter_list|)
function_decl|;
name|Error
name|visitSymbolRecord
parameter_list|(
name|CVSymbol
modifier|&
name|Record
parameter_list|,
name|uint32_t
name|Offset
parameter_list|)
function_decl|;
name|Error
name|visitSymbolStream
parameter_list|(
specifier|const
name|CVSymbolArray
modifier|&
name|Symbols
parameter_list|)
function_decl|;
name|Error
name|visitSymbolStream
parameter_list|(
specifier|const
name|CVSymbolArray
modifier|&
name|Symbols
parameter_list|,
name|uint32_t
name|InitialOffset
parameter_list|)
function_decl|;
name|private
label|:
name|SymbolVisitorCallbacks
modifier|&
name|Callbacks
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace codeview
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_CODEVIEW_CVSYMBOLVISITOR_H
end_comment

end_unit

