begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SymbolVisitorCallbacks.h ---------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_SYMBOLVISITORCALLBACKS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_SYMBOLVISITORCALLBACKS_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/SymbolRecord.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
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
block|{
name|friend
name|class
name|CVSymbolVisitor
decl_stmt|;
name|public
label|:
name|virtual
operator|~
name|SymbolVisitorCallbacks
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// Action to take on unknown symbols. By default, they are ignored.
name|virtual
name|Error
name|visitUnknownSymbol
parameter_list|(
name|CVSymbol
modifier|&
name|Record
parameter_list|)
block|{
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
comment|/// Paired begin/end actions for all symbols. Receives all record data,
comment|/// including the fixed-length record prefix.  visitSymbolBegin() should
comment|/// return
comment|/// the type of the Symbol, or an error if it cannot be determined.
name|virtual
name|Error
name|visitSymbolBegin
parameter_list|(
name|CVSymbol
modifier|&
name|Record
parameter_list|)
block|{
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
name|virtual
name|Error
name|visitSymbolEnd
parameter_list|(
name|CVSymbol
modifier|&
name|Record
parameter_list|)
block|{
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
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
value|virtual Error visitKnownRecord(CVSymbol&CVR, Name&Record) {                \     return Error::success();                                                   \   }
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
file|"llvm/DebugInfo/CodeView/CodeViewSymbols.def"
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
comment|// LLVM_DEBUGINFO_CODEVIEW_SYMBOLVISITORCALLBACKS_H
end_comment

end_unit

