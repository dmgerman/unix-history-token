begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// WebAssemblyRegisterInfo.h - WebAssembly Register Information Impl -*- C++ -*-
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief This file contains the WebAssembly implementation of the
end_comment

begin_comment
comment|/// WebAssemblyRegisterInfo class.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_WEBASSEMBLY_WEBASSEMBLYREGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_WEBASSEMBLY_WEBASSEMBLYREGISTERINFO_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineFunction
decl_stmt|;
name|class
name|RegScavenger
decl_stmt|;
name|class
name|TargetRegisterClass
decl_stmt|;
name|class
name|Triple
decl_stmt|;
name|class
name|WebAssemblyRegisterInfo
name|final
block|{
specifier|const
name|Triple
modifier|&
name|TT
decl_stmt|;
name|public
label|:
name|explicit
name|WebAssemblyRegisterInfo
parameter_list|(
specifier|const
name|Triple
modifier|&
name|TT
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

