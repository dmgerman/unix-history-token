begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- func-id-helper.h - XRay Function ID Conversion Helpers -------------===//
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
comment|// Defines helper tools dealing with XRay-generated function ids.
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
name|LLVM_TOOLS_LLVM_XRAY_FUNC_ID_HELPER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVM_XRAY_FUNC_ID_HELPER_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/Symbolize/Symbolize.h"
end_include

begin_include
include|#
directive|include
file|<unordered_map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|xray
block|{
comment|// This class consolidates common operations related to Function IDs.
name|class
name|FuncIdConversionHelper
block|{
name|public
label|:
name|using
name|FunctionAddressMap
init|=
name|std
operator|::
name|unordered_map
operator|<
name|int32_t
decl_stmt|,
name|uint64_t
decl|>
decl_stmt|;
name|private
label|:
name|std
operator|::
name|string
name|BinaryInstrMap
expr_stmt|;
name|symbolize
operator|::
name|LLVMSymbolizer
operator|&
name|Symbolizer
expr_stmt|;
specifier|const
name|FunctionAddressMap
modifier|&
name|FunctionAddresses
decl_stmt|;
name|public
label|:
name|FuncIdConversionHelper
argument_list|(
argument|std::string BinaryInstrMap
argument_list|,
argument|symbolize::LLVMSymbolizer&Symbolizer
argument_list|,
argument|const FunctionAddressMap&FunctionAddresses
argument_list|)
block|:
name|BinaryInstrMap
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|BinaryInstrMap
argument_list|)
argument_list|)
operator|,
name|Symbolizer
argument_list|(
name|Symbolizer
argument_list|)
operator|,
name|FunctionAddresses
argument_list|(
argument|FunctionAddresses
argument_list|)
block|{}
comment|// Returns the symbol or a string representation of the function id.
name|std
operator|::
name|string
name|SymbolOrNumber
argument_list|(
argument|int32_t FuncId
argument_list|)
specifier|const
expr_stmt|;
comment|// Returns the file and column from debug info for the given function id.
name|std
operator|::
name|string
name|FileLineAndColumn
argument_list|(
argument|int32_t FuncId
argument_list|)
specifier|const
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// namespace xray
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TOOLS_LLVM_XRAY_FUNC_ID_HELPER_H
end_comment

end_unit

