begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- YamlSymbolDumper.h ------------------------------------- *- C++ --*-===//
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
name|LLVM_TOOLS_LLVMPDBDUMP_YAMLSYMBOLDUMPER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVMPDBDUMP_YAMLSYMBOLDUMPER_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/CodeView.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/SymbolVisitorCallbacks.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/YAMLTraits.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|pdb
block|{
name|namespace
name|yaml
block|{
struct_decl|struct
name|SerializationContext
struct_decl|;
block|}
block|}
name|namespace
name|codeview
block|{
name|namespace
name|yaml
block|{
name|class
name|YamlSymbolDumper
range|:
name|public
name|SymbolVisitorCallbacks
block|{
name|public
operator|:
name|YamlSymbolDumper
argument_list|(
name|llvm
operator|::
name|yaml
operator|::
name|IO
operator|&
name|IO
argument_list|)
operator|:
name|YamlIO
argument_list|(
argument|IO
argument_list|)
block|{}
name|virtual
name|Error
name|visitSymbolBegin
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
value|Error visitKnownRecord(CVSymbol&CVR, Name&Record) override {               \     visitKnownRecordImpl(#Name, CVR, Record);                                  \     return Error::success();                                                   \   }
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
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|visitKnownRecordImpl
argument_list|(
argument|const char *Name
argument_list|,
argument|CVSymbol&Type
argument_list|,
argument|T&Record
argument_list|)
block|{
name|YamlIO
operator|.
name|mapRequired
argument_list|(
name|Name
argument_list|,
name|Record
argument_list|)
block|;   }
name|llvm
operator|::
name|yaml
operator|::
name|IO
operator|&
name|YamlIO
block|; }
decl_stmt|;
block|}
block|}
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|yaml
block|{
name|template
operator|<
operator|>
expr|struct
name|ScalarEnumerationTraits
operator|<
name|codeview
operator|::
name|SymbolKind
operator|>
block|{
specifier|static
name|void
name|enumeration
argument_list|(
name|IO
operator|&
name|io
argument_list|,
name|codeview
operator|::
name|SymbolKind
operator|&
name|Value
argument_list|)
block|; }
expr_stmt|;
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
value|template<> struct MappingTraits<codeview::Name> {                           \     static void mapping(IO&IO, codeview::Name&Obj);                          \   };
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
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

