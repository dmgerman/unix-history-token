begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- xray-converter.h - XRay Trace Conversion ---------------------------===//
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
comment|// Defines the TraceConverter class for turning binary traces into
end_comment

begin_comment
comment|// human-readable text and vice versa.
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
name|LLVM_TOOLS_LLVM_XRAY_XRAY_CONVERTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVM_XRAY_XRAY_CONVERTER_H
end_define

begin_include
include|#
directive|include
file|"func-id-helper.h"
end_include

begin_include
include|#
directive|include
file|"llvm/XRay/XRayRecord.h"
end_include

begin_include
include|#
directive|include
file|"llvm/XRay/Trace.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|xray
block|{
name|class
name|TraceConverter
block|{
name|FuncIdConversionHelper
modifier|&
name|FuncIdHelper
decl_stmt|;
name|bool
name|Symbolize
decl_stmt|;
name|public
label|:
name|TraceConverter
argument_list|(
argument|FuncIdConversionHelper&FuncIdHelper
argument_list|,
argument|bool Symbolize = false
argument_list|)
block|:
name|FuncIdHelper
argument_list|(
name|FuncIdHelper
argument_list|)
operator|,
name|Symbolize
argument_list|(
argument|Symbolize
argument_list|)
block|{}
name|void
name|exportAsYAML
argument_list|(
specifier|const
name|Trace
operator|&
name|Records
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|)
expr_stmt|;
name|void
name|exportAsRAWv1
parameter_list|(
specifier|const
name|Trace
modifier|&
name|Records
parameter_list|,
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
comment|// LLVM_TOOLS_LLVM_XRAY_XRAY_CONVERTER_H
end_comment

end_unit

