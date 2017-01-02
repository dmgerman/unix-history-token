begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SymbolVisitorCallbackPipeline.h --------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_SYMBOLVISITORCALLBACKPIPELINE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_SYMBOLVISITORCALLBACKPIPELINE_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/SymbolRecord.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/SymbolVisitorCallbacks.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|class
name|SymbolVisitorCallbackPipeline
range|:
name|public
name|SymbolVisitorCallbacks
block|{
name|public
operator|:
name|SymbolVisitorCallbackPipeline
argument_list|()
operator|=
expr|default
block|;
name|Error
name|visitUnknownSymbol
argument_list|(
argument|CVSymbol&Record
argument_list|)
name|override
block|{
for|for
control|(
name|auto
name|Visitor
range|:
name|Pipeline
control|)
block|{
if|if
condition|(
name|auto
name|EC
init|=
name|Visitor
operator|->
name|visitUnknownSymbol
argument_list|(
name|Record
argument_list|)
condition|)
return|return
name|EC
return|;
block|}
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
name|Error
name|visitSymbolBegin
argument_list|(
argument|CVSymbol&Record
argument_list|)
name|override
block|{
for|for
control|(
name|auto
name|Visitor
range|:
name|Pipeline
control|)
block|{
if|if
condition|(
name|auto
name|EC
init|=
name|Visitor
operator|->
name|visitSymbolBegin
argument_list|(
name|Record
argument_list|)
condition|)
return|return
name|EC
return|;
block|}
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
name|Error
name|visitSymbolEnd
argument_list|(
argument|CVSymbol&Record
argument_list|)
name|override
block|{
for|for
control|(
name|auto
name|Visitor
range|:
name|Pipeline
control|)
block|{
if|if
condition|(
name|auto
name|EC
init|=
name|Visitor
operator|->
name|visitSymbolEnd
argument_list|(
name|Record
argument_list|)
condition|)
return|return
name|EC
return|;
block|}
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
name|void
name|addCallbackToPipeline
argument_list|(
argument|SymbolVisitorCallbacks&Callbacks
argument_list|)
block|{
name|Pipeline
operator|.
name|push_back
argument_list|(
operator|&
name|Callbacks
argument_list|)
block|;   }
define|#
directive|define
name|SYMBOL_RECORD
parameter_list|(
name|EnumName
parameter_list|,
name|EnumVal
parameter_list|,
name|Name
parameter_list|)
define|\
value|Error visitKnownRecord(CVSymbol&CVR, Name&Record) override {               \     for (auto Visitor : Pipeline) {                                            \       if (auto EC = Visitor->visitKnownRecord(CVR, Record))                    \         return EC;                                                             \     }                                                                          \     return Error::success();                                                   \   }
define|#
directive|define
name|SYMBOL_RECORD_ALIAS
parameter_list|(
name|EnumName
parameter_list|,
name|EnumVal
parameter_list|,
name|Name
parameter_list|,
name|AliasName
parameter_list|)
include|#
directive|include
file|"llvm/DebugInfo/CodeView/CVSymbolTypes.def"
name|private
operator|:
name|std
operator|::
name|vector
operator|<
name|SymbolVisitorCallbacks
operator|*
operator|>
name|Pipeline
block|; }
decl_stmt|;
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
comment|// LLVM_DEBUGINFO_CODEVIEW_SYMBOLVISITORCALLBACKPIPELINE_H
end_comment

end_unit

