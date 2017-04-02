begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- xray-account.h - XRay Function Call Accounting ---------------------===//
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
comment|// This file defines the interface for performing some basic function call
end_comment

begin_comment
comment|// accounting from an XRay trace.
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
name|LLVM_TOOLS_LLVM_XRAY_XRAY_ACCOUNT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVM_XRAY_XRAY_ACCOUNT_H
end_define

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"func-id-helper.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Program.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|"llvm/XRay/XRayRecord.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|xray
block|{
name|class
name|LatencyAccountant
block|{
name|public
label|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|int32_t
operator|,
name|std
operator|::
name|vector
operator|<
name|uint64_t
operator|>>
name|FunctionLatencyMap
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|llvm
operator|::
name|sys
operator|::
name|ProcessInfo
operator|::
name|ProcessId
operator|,
name|std
operator|::
name|pair
operator|<
name|uint64_t
operator|,
name|uint64_t
operator|>>
name|PerThreadMinMaxTSCMap
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|uint8_t
operator|,
name|std
operator|::
name|pair
operator|<
name|uint64_t
operator|,
name|uint64_t
operator|>>
name|PerCPUMinMaxTSCMap
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|int32_t
operator|,
name|uint64_t
operator|>>
name|FunctionStack
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|llvm
operator|::
name|sys
operator|::
name|ProcessInfo
operator|::
name|ProcessId
operator|,
name|FunctionStack
operator|>
name|PerThreadFunctionStackMap
expr_stmt|;
name|private
label|:
name|PerThreadFunctionStackMap
name|PerThreadFunctionStack
decl_stmt|;
name|FunctionLatencyMap
name|FunctionLatencies
decl_stmt|;
name|PerThreadMinMaxTSCMap
name|PerThreadMinMaxTSC
decl_stmt|;
name|PerCPUMinMaxTSCMap
name|PerCPUMinMaxTSC
decl_stmt|;
name|FuncIdConversionHelper
modifier|&
name|FuncIdHelper
decl_stmt|;
name|bool
name|DeduceSiblingCalls
init|=
name|false
decl_stmt|;
name|uint64_t
name|CurrentMaxTSC
init|=
literal|0
decl_stmt|;
name|void
name|recordLatency
parameter_list|(
name|int32_t
name|FuncId
parameter_list|,
name|uint64_t
name|Latency
parameter_list|)
block|{
name|FunctionLatencies
index|[
name|FuncId
index|]
operator|.
name|push_back
argument_list|(
name|Latency
argument_list|)
expr_stmt|;
block|}
name|public
label|:
name|explicit
name|LatencyAccountant
argument_list|(
argument|FuncIdConversionHelper&FuncIdHelper
argument_list|,
argument|bool DeduceSiblingCalls
argument_list|)
block|:
name|FuncIdHelper
argument_list|(
name|FuncIdHelper
argument_list|)
operator|,
name|DeduceSiblingCalls
argument_list|(
argument|DeduceSiblingCalls
argument_list|)
block|{}
specifier|const
name|FunctionLatencyMap
operator|&
name|getFunctionLatencies
argument_list|()
specifier|const
block|{
return|return
name|FunctionLatencies
return|;
block|}
specifier|const
name|PerThreadMinMaxTSCMap
operator|&
name|getPerThreadMinMaxTSC
argument_list|()
specifier|const
block|{
return|return
name|PerThreadMinMaxTSC
return|;
block|}
specifier|const
name|PerCPUMinMaxTSCMap
operator|&
name|getPerCPUMinMaxTSC
argument_list|()
specifier|const
block|{
return|return
name|PerCPUMinMaxTSC
return|;
block|}
comment|/// Returns false in case we fail to account the provided record. This happens
comment|/// in the following cases:
comment|///
comment|///   - An exit record does not match any entry records for the same function.
comment|///     If we've been set to deduce sibling calls, we try walking up the stack
comment|///     and recording times for the higher level functions.
comment|///   - A record has a TSC that's before the latest TSC that has been
comment|///     recorded. We still record the TSC for the min-max.
comment|///
name|bool
name|accountRecord
parameter_list|(
specifier|const
name|XRayRecord
modifier|&
name|Record
parameter_list|)
function_decl|;
specifier|const
name|FunctionStack
modifier|*
name|getThreadFunctionStack
argument_list|(
name|llvm
operator|::
name|sys
operator|::
name|ProcessInfo
operator|::
name|ProcessId
name|TId
argument_list|)
decl|const
block|{
name|auto
name|I
init|=
name|PerThreadFunctionStack
operator|.
name|find
argument_list|(
name|TId
argument_list|)
decl_stmt|;
if|if
condition|(
name|I
operator|==
name|PerThreadFunctionStack
operator|.
name|end
argument_list|()
condition|)
return|return
name|nullptr
return|;
return|return
operator|&
name|I
operator|->
name|second
return|;
block|}
specifier|const
name|PerThreadFunctionStackMap
operator|&
name|getPerThreadFunctionStack
argument_list|()
specifier|const
block|{
return|return
name|PerThreadFunctionStack
return|;
block|}
comment|// Output Functions
comment|// ================
name|void
name|exportStatsAsText
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|XRayFileHeader
operator|&
name|Header
argument_list|)
decl|const
decl_stmt|;
name|void
name|exportStatsAsCSV
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|XRayFileHeader
operator|&
name|Header
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
comment|// Internal helper to implement common parts of the exportStatsAs...
comment|// functions.
name|template
operator|<
name|class
name|F
operator|>
name|void
name|exportStats
argument_list|(
argument|const XRayFileHeader&Header
argument_list|,
argument|F fn
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
comment|// LLVM_TOOLS_LLVM_XRAY_XRAY_ACCOUNT_H
end_comment

end_unit

