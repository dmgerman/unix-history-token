begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- xray-extract.h - XRay Instrumentation Map Extraction ---------------===//
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
comment|// Defines the interface for extracting the instrumentation map from an
end_comment

begin_comment
comment|// XRay-instrumented binary.
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
name|LLVM_TOOLS_XRAY_EXTRACT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_XRAY_EXTRACT_H
end_define

begin_include
include|#
directive|include
file|<deque>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<unordered_map>
end_include

begin_include
include|#
directive|include
file|"xray-sleds.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|xray
block|{
name|class
name|InstrumentationMapExtractor
block|{
name|public
label|:
typedef|typedef
name|std
operator|::
name|unordered_map
operator|<
name|int32_t
operator|,
name|uint64_t
operator|>
name|FunctionAddressMap
expr_stmt|;
typedef|typedef
name|std
operator|::
name|unordered_map
operator|<
name|uint64_t
operator|,
name|int32_t
operator|>
name|FunctionAddressReverseMap
expr_stmt|;
name|enum
name|class
name|InputFormats
block|{
name|ELF
operator|,
name|YAML
block|}
empty_stmt|;
name|private
label|:
name|std
operator|::
name|deque
operator|<
name|SledEntry
operator|>
name|Sleds
expr_stmt|;
name|FunctionAddressMap
name|FunctionAddresses
decl_stmt|;
name|FunctionAddressReverseMap
name|FunctionIds
decl_stmt|;
name|public
label|:
comment|/// Loads the instrumentation map from |Filename|. Updates |EC| in case there
comment|/// were errors encountered opening the file. |Format| defines what the input
comment|/// instrumentation map is in.
name|InstrumentationMapExtractor
argument_list|(
argument|std::string Filename
argument_list|,
argument|InputFormats Format
argument_list|,
argument|Error&EC
argument_list|)
empty_stmt|;
specifier|const
name|FunctionAddressMap
modifier|&
name|getFunctionAddresses
parameter_list|()
block|{
return|return
name|FunctionAddresses
return|;
block|}
comment|/// Exports the loaded function address map as YAML through |OS|.
name|void
name|exportAsYAML
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
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
comment|// LLVM_TOOLS_XRAY_EXTRACT_H
end_comment

end_unit

