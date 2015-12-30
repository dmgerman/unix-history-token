begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AMDGPUDiagnosticInfoUnsupported.h - Error reporting -----*- C++ -*-===//
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
name|LLVM_LIB_TARGET_AMDGPU_AMDGPUDIAGNOSTICINFOUNSUPPORTED_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_AMDGPU_AMDGPUDIAGNOSTICINFOUNSUPPORTED_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/DiagnosticInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DiagnosticPrinter.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Diagnostic information for unimplemented or unsupported feature reporting.
name|class
name|DiagnosticInfoUnsupported
range|:
name|public
name|DiagnosticInfo
block|{
name|private
operator|:
specifier|const
name|Twine
operator|&
name|Description
block|;
specifier|const
name|Function
operator|&
name|Fn
block|;
specifier|static
name|int
name|KindID
block|;
specifier|static
name|int
name|getKindID
argument_list|()
block|{
if|if
condition|(
name|KindID
operator|==
literal|0
condition|)
name|KindID
operator|=
name|llvm
operator|::
name|getNextAvailablePluginDiagnosticKind
argument_list|()
expr_stmt|;
return|return
name|KindID
return|;
block|}
name|public
label|:
name|DiagnosticInfoUnsupported
argument_list|(
argument|const Function&Fn
argument_list|,
argument|const Twine&Desc
argument_list|,
argument|DiagnosticSeverity Severity = DS_Error
argument_list|)
empty_stmt|;
specifier|const
name|Function
operator|&
name|getFunction
argument_list|()
specifier|const
block|{
return|return
name|Fn
return|;
block|}
specifier|const
name|Twine
operator|&
name|getDescription
argument_list|()
specifier|const
block|{
return|return
name|Description
return|;
block|}
name|void
name|print
argument_list|(
name|DiagnosticPrinter
operator|&
name|DP
argument_list|)
decl|const
name|override
decl_stmt|;
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|DiagnosticInfo
modifier|*
name|DI
parameter_list|)
block|{
return|return
name|DI
operator|->
name|getKind
argument_list|()
operator|==
name|getKindID
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

