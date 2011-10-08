begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DebugInfoProbe.h - DebugInfo Probe ----------------------*- C++ -*-===//
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
comment|// This file defines a probe, DebugInfoProbe, that can be used by pass
end_comment

begin_comment
comment|// manager to analyze how optimizer is treating debugging information.
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
name|LLVM_TRANSFORMS_UTILS_DEBUGINFOPROBE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_DEBUGINFOPROBE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Function
decl_stmt|;
name|class
name|Pass
decl_stmt|;
name|class
name|DebugInfoProbeImpl
decl_stmt|;
comment|/// DebugInfoProbe - This class provides a interface to monitor
comment|/// how an optimization pass is preserving debugging information.
name|class
name|DebugInfoProbe
block|{
name|public
label|:
name|DebugInfoProbe
argument_list|()
expr_stmt|;
operator|~
name|DebugInfoProbe
argument_list|()
expr_stmt|;
comment|/// initialize - Collect information before running an optimization pass.
name|void
name|initialize
parameter_list|(
name|StringRef
name|PName
parameter_list|,
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
comment|/// finalize - Collect information after running an optimization pass. This
comment|/// must be used after initialization.
name|void
name|finalize
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
comment|/// report - Report findings. This should be invoked after finalize.
name|void
name|report
parameter_list|()
function_decl|;
name|private
label|:
name|DebugInfoProbeImpl
modifier|*
name|pImpl
decl_stmt|;
block|}
empty_stmt|;
comment|/// DebugInfoProbeInfo - This class provides an interface that a pass manager
comment|/// can use to manage debug info probes.
name|class
name|DebugInfoProbeInfo
block|{
name|StringMap
operator|<
name|DebugInfoProbe
operator|*
operator|>
name|Probes
expr_stmt|;
name|public
label|:
name|DebugInfoProbeInfo
argument_list|()
block|{}
comment|/// ~DebugInfoProbeInfo - Report data collected by all probes before deleting
comment|/// them.
operator|~
name|DebugInfoProbeInfo
argument_list|()
expr_stmt|;
comment|/// initialize - Collect information before running an optimization pass.
name|void
name|initialize
parameter_list|(
name|Pass
modifier|*
name|P
parameter_list|,
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
comment|/// finalize - Collect information after running an optimization pass. This
comment|/// must be used after initialization.
name|void
name|finalize
parameter_list|(
name|Pass
modifier|*
name|P
parameter_list|,
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

