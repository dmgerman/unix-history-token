begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// WebAssemblyMachineFunctionInfo.h-WebAssembly machine function info-*- C++ -*-
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
comment|/// \brief This file declares WebAssembly-specific per-machine-function
end_comment

begin_comment
comment|/// information.
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
name|LLVM_LIB_TARGET_WEBASSEMBLY_WEBASSEMBLYMACHINEFUNCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_WEBASSEMBLY_WEBASSEMBLYMACHINEFUNCTIONINFO_H
end_define

begin_include
include|#
directive|include
file|"MCTargetDesc/WebAssemblyMCTargetDesc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineRegisterInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// This class is derived from MachineFunctionInfo and contains private
comment|/// WebAssembly-specific information for each MachineFunction.
name|class
name|WebAssemblyFunctionInfo
name|final
range|:
name|public
name|MachineFunctionInfo
block|{
name|MachineFunction
operator|&
name|MF
block|;
name|std
operator|::
name|vector
operator|<
name|MVT
operator|>
name|Params
block|;
comment|/// A mapping from CodeGen vreg index to WebAssembly register number.
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|WARegs
block|;
comment|/// A mapping from CodeGen vreg index to a boolean value indicating whether
comment|/// the given register is considered to be "stackified", meaning it has been
comment|/// determined or made to meet the stack requirements:
comment|///   - single use (per path)
comment|///   - single def (per path)
comment|///   - defined and used in LIFO order with other stack registers
name|BitVector
name|VRegStackified
block|;
comment|// One entry for each possible target reg. we expect it to be small.
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|PhysRegs
block|;
name|public
operator|:
name|explicit
name|WebAssemblyFunctionInfo
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
operator|:
name|MF
argument_list|(
argument|MF
argument_list|)
block|{
name|PhysRegs
operator|.
name|resize
argument_list|(
name|WebAssembly
operator|::
name|NUM_TARGET_REGS
argument_list|,
operator|-
literal|1U
argument_list|)
block|;   }
operator|~
name|WebAssemblyFunctionInfo
argument_list|()
name|override
block|;
name|void
name|addParam
argument_list|(
argument|MVT VT
argument_list|)
block|{
name|Params
operator|.
name|push_back
argument_list|(
name|VT
argument_list|)
block|; }
specifier|const
name|std
operator|::
name|vector
operator|<
name|MVT
operator|>
operator|&
name|getParams
argument_list|()
specifier|const
block|{
return|return
name|Params
return|;
block|}
specifier|static
specifier|const
name|unsigned
name|UnusedReg
operator|=
operator|-
literal|1u
block|;
name|void
name|stackifyVReg
argument_list|(
argument|unsigned VReg
argument_list|)
block|{
if|if
condition|(
name|TargetRegisterInfo
operator|::
name|virtReg2Index
argument_list|(
name|VReg
argument_list|)
operator|>=
name|VRegStackified
operator|.
name|size
argument_list|()
condition|)
name|VRegStackified
operator|.
name|resize
argument_list|(
name|TargetRegisterInfo
operator|::
name|virtReg2Index
argument_list|(
name|VReg
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
name|VRegStackified
operator|.
name|set
argument_list|(
name|TargetRegisterInfo
operator|::
name|virtReg2Index
argument_list|(
name|VReg
argument_list|)
argument_list|)
block|;   }
name|bool
name|isVRegStackified
argument_list|(
argument|unsigned VReg
argument_list|)
specifier|const
block|{
if|if
condition|(
name|TargetRegisterInfo
operator|::
name|virtReg2Index
argument_list|(
name|VReg
argument_list|)
operator|>=
name|VRegStackified
operator|.
name|size
argument_list|()
condition|)
return|return
name|false
return|;
return|return
name|VRegStackified
operator|.
name|test
argument_list|(
name|TargetRegisterInfo
operator|::
name|virtReg2Index
argument_list|(
name|VReg
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_function_decl
name|void
name|initWARegs
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|setWAReg
parameter_list|(
name|unsigned
name|VReg
parameter_list|,
name|unsigned
name|WAReg
parameter_list|)
block|{
name|assert
argument_list|(
name|WAReg
operator|!=
name|UnusedReg
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|TargetRegisterInfo
operator|::
name|virtReg2Index
argument_list|(
name|VReg
argument_list|)
operator|<
name|WARegs
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|WARegs
index|[
name|TargetRegisterInfo
operator|::
name|virtReg2Index
argument_list|(
name|VReg
argument_list|)
index|]
operator|=
name|WAReg
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|unsigned
name|getWAReg
argument_list|(
name|unsigned
name|Reg
argument_list|)
decl|const
block|{
if|if
condition|(
name|TargetRegisterInfo
operator|::
name|isVirtualRegister
argument_list|(
name|Reg
argument_list|)
condition|)
block|{
name|assert
argument_list|(
name|TargetRegisterInfo
operator|::
name|virtReg2Index
argument_list|(
name|Reg
argument_list|)
operator|<
name|WARegs
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|WARegs
index|[
name|TargetRegisterInfo
operator|::
name|virtReg2Index
argument_list|(
name|Reg
argument_list|)
index|]
return|;
block|}
return|return
name|PhysRegs
index|[
name|Reg
index|]
return|;
block|}
end_decl_stmt

begin_comment
comment|// If new virtual registers are created after initWARegs has been called,
end_comment

begin_comment
comment|// this function can be used to add WebAssembly register mappings for them.
end_comment

begin_function
name|void
name|addWAReg
parameter_list|(
name|unsigned
name|VReg
parameter_list|,
name|unsigned
name|WAReg
parameter_list|)
block|{
name|assert
argument_list|(
name|VReg
operator|=
name|WARegs
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|WARegs
operator|.
name|push_back
argument_list|(
name|WAReg
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|addPReg
parameter_list|(
name|unsigned
name|PReg
parameter_list|,
name|unsigned
name|WAReg
parameter_list|)
block|{
name|assert
argument_list|(
name|PReg
operator|<
name|WebAssembly
operator|::
name|NUM_TARGET_REGS
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|WAReg
operator|<
operator|-
literal|1U
argument_list|)
expr_stmt|;
name|PhysRegs
index|[
name|PReg
index|]
operator|=
name|WAReg
expr_stmt|;
block|}
end_function

begin_expr_stmt
specifier|const
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
operator|&
name|getPhysRegs
argument_list|()
specifier|const
block|{
return|return
name|PhysRegs
return|;
block|}
end_expr_stmt

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

