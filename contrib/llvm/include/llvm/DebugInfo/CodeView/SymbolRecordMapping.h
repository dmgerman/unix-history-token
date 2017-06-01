begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SymbolRecordMapping.h ------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_SYMBOLRECORDMAPPING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_SYMBOLRECORDMAPPING_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/CodeViewRecordIO.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/SymbolVisitorCallbacks.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BinaryStreamReader
decl_stmt|;
name|class
name|BinaryStreamWriter
decl_stmt|;
name|namespace
name|codeview
block|{
name|class
name|SymbolRecordMapping
range|:
name|public
name|SymbolVisitorCallbacks
block|{
name|public
operator|:
name|explicit
name|SymbolRecordMapping
argument_list|(
name|BinaryStreamReader
operator|&
name|Reader
argument_list|)
operator|:
name|IO
argument_list|(
argument|Reader
argument_list|)
block|{}
name|explicit
name|SymbolRecordMapping
argument_list|(
name|BinaryStreamWriter
operator|&
name|Writer
argument_list|)
operator|:
name|IO
argument_list|(
argument|Writer
argument_list|)
block|{}
name|Error
name|visitSymbolBegin
argument_list|(
argument|CVSymbol&Record
argument_list|)
name|override
block|;
name|Error
name|visitSymbolEnd
argument_list|(
argument|CVSymbol&Record
argument_list|)
name|override
block|;
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
value|Error visitKnownRecord(CVSymbol&CVR, Name&Record) override;
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
name|private
operator|:
name|Optional
operator|<
name|SymbolKind
operator|>
name|Kind
block|;
name|CodeViewRecordIO
name|IO
block|; }
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

