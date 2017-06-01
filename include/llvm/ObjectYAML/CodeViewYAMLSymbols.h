begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CodeViewYAMLSymbols.h - CodeView YAMLIO Symbol implementation ------===//
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
comment|// This file defines classes for handling the YAML representation of CodeView
end_comment

begin_comment
comment|// Debug Info.
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
name|LLVM_OBJECTYAML_CODEVIEWYAMLSYMBOLS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OBJECTYAML_CODEVIEWYAMLSYMBOLS_H
end_define

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
file|"llvm/ObjectYAML/YAML.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|CodeViewYAML
block|{
name|namespace
name|detail
block|{
struct_decl|struct
name|SymbolRecordBase
struct_decl|;
block|}
struct|struct
name|SymbolRecord
block|{
name|std
operator|::
name|shared_ptr
operator|<
name|detail
operator|::
name|SymbolRecordBase
operator|>
name|Symbol
expr_stmt|;
name|codeview
operator|::
name|CVSymbol
name|toCodeViewSymbol
argument_list|(
argument|BumpPtrAllocator&Allocator
argument_list|)
specifier|const
expr_stmt|;
specifier|static
name|Expected
operator|<
name|SymbolRecord
operator|>
name|fromCodeViewSymbol
argument_list|(
argument|codeview::CVSymbol Symbol
argument_list|)
expr_stmt|;
block|}
struct|;
block|}
comment|// namespace CodeViewYAML
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_macro
name|LLVM_YAML_DECLARE_MAPPING_TRAITS
argument_list|(
argument|CodeViewYAML::SymbolRecord
argument_list|)
end_macro

begin_macro
name|LLVM_YAML_IS_SEQUENCE_VECTOR
argument_list|(
argument|CodeViewYAML::SymbolRecord
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

