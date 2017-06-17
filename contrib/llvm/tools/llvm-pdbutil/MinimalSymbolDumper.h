begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MinimalSymbolDumper.h ---------------------------------- *- C++ --*-===//
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
name|LLVM_TOOLS_LLVMPDBUTIL_MINIMAL_SYMBOL_DUMPER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVMPDBUTIL_MINIMAL_SYMBOL_DUMPER_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/SymbolVisitorCallbacks.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|class
name|LazyRandomTypeCollection
decl_stmt|;
block|}
name|namespace
name|pdb
block|{
name|class
name|LinePrinter
decl_stmt|;
name|class
name|MinimalSymbolDumper
range|:
name|public
name|codeview
operator|::
name|SymbolVisitorCallbacks
block|{
name|public
operator|:
name|MinimalSymbolDumper
argument_list|(
argument|LinePrinter&P
argument_list|,
argument|bool RecordBytes
argument_list|,
argument|codeview::LazyRandomTypeCollection&Types
argument_list|)
operator|:
name|P
argument_list|(
name|P
argument_list|)
block|,
name|Types
argument_list|(
argument|Types
argument_list|)
block|{}
name|Error
name|visitSymbolBegin
argument_list|(
argument|codeview::CVSymbol&Record
argument_list|)
name|override
block|;
name|Error
name|visitSymbolEnd
argument_list|(
argument|codeview::CVSymbol&Record
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
value|virtual Error visitKnownRecord(codeview::CVSymbol&CVR,                      \                                  codeview::Name&Record) override;
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
name|std
operator|::
name|string
name|typeIndex
argument_list|(
argument|codeview::TypeIndex TI
argument_list|)
specifier|const
block|;
name|LinePrinter
operator|&
name|P
block|;
name|codeview
operator|::
name|LazyRandomTypeCollection
operator|&
name|Types
block|; }
decl_stmt|;
block|}
comment|// namespace pdb
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

