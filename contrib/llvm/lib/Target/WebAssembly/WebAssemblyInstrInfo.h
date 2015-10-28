begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- WebAssemblyInstrInfo.h - WebAssembly Instruction Information -*- C++ -*-=//
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
comment|/// TargetInstrInfo class.
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
name|LLVM_LIB_TARGET_WEBASSEMBLY_WEBASSEMBLYINSTRINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_WEBASSEMBLY_WEBASSEMBLYINSTRINFO_H
end_define

begin_include
include|#
directive|include
file|"WebAssemblyRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetInstrInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|WebAssemblySubtarget
decl_stmt|;
name|class
name|WebAssemblyInstrInfo
name|final
block|{
specifier|const
name|WebAssemblyRegisterInfo
name|RI
decl_stmt|;
name|public
label|:
name|explicit
name|WebAssemblyInstrInfo
parameter_list|(
specifier|const
name|WebAssemblySubtarget
modifier|&
name|STI
parameter_list|)
function_decl|;
specifier|const
name|WebAssemblyRegisterInfo
operator|&
name|getRegisterInfo
argument_list|()
specifier|const
block|{
return|return
name|RI
return|;
block|}
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

