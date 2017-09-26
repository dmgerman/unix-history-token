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
name|std
operator|::
name|vector
operator|<
name|MVT
operator|>
name|Results
block|;
name|std
operator|::
name|vector
operator|<
name|MVT
operator|>
name|Locals
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
comment|// A virtual register holding the pointer to the vararg buffer for vararg
comment|// functions. It is created and set in TLI::LowerFormalArguments and read by
comment|// TLI::LowerVASTART
name|unsigned
name|VarargVreg
operator|=
operator|-
literal|1U
block|;
comment|// A virtual register holding the base pointer for functions that have
comment|// overaligned values on the user stack.
name|unsigned
name|BasePtrVreg
operator|=
operator|-
literal|1U
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
block|{}
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
name|void
name|addResult
argument_list|(
argument|MVT VT
argument_list|)
block|{
name|Results
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
name|getResults
argument_list|()
specifier|const
block|{
return|return
name|Results
return|;
block|}
name|void
name|setNumLocals
argument_list|(
argument|size_t NumLocals
argument_list|)
block|{
name|Locals
operator|.
name|resize
argument_list|(
name|NumLocals
argument_list|,
name|MVT
operator|::
name|i32
argument_list|)
block|; }
name|void
name|setLocal
argument_list|(
argument|size_t i
argument_list|,
argument|MVT VT
argument_list|)
block|{
name|Locals
index|[
name|i
index|]
operator|=
name|VT
block|; }
name|void
name|addLocal
argument_list|(
argument|MVT VT
argument_list|)
block|{
name|Locals
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
name|getLocals
argument_list|()
specifier|const
block|{
return|return
name|Locals
return|;
block|}
name|unsigned
name|getVarargBufferVreg
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|VarargVreg
operator|!=
operator|-
literal|1U
operator|&&
literal|"Vararg vreg hasn't been set"
argument_list|)
block|;
return|return
name|VarargVreg
return|;
block|}
name|void
name|setVarargBufferVreg
argument_list|(
argument|unsigned Reg
argument_list|)
block|{
name|VarargVreg
operator|=
name|Reg
block|; }
name|unsigned
name|getBasePointerVreg
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|BasePtrVreg
operator|!=
operator|-
literal|1U
operator|&&
literal|"Base ptr vreg hasn't been set"
argument_list|)
block|;
return|return
name|BasePtrVreg
return|;
block|}
name|void
name|setBasePointerVreg
argument_list|(
argument|unsigned Reg
argument_list|)
block|{
name|BasePtrVreg
operator|=
name|Reg
block|; }
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
name|assert
argument_list|(
name|MF
operator|.
name|getRegInfo
argument_list|()
operator|.
name|getUniqueVRegDef
argument_list|(
name|VReg
argument_list|)
argument_list|)
block|;
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
end_decl_stmt

begin_comment
comment|// For a given stackified WAReg, return the id number to print with push/pop.
end_comment

begin_function
specifier|static
name|unsigned
name|getWARegStackId
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
name|assert
argument_list|(
name|Reg
operator|&
name|INT32_MIN
argument_list|)
expr_stmt|;
return|return
name|Reg
operator|&
name|INT32_MAX
return|;
block|}
end_function

begin_decl_stmt
unit|};
name|void
name|ComputeLegalValueVTs
argument_list|(
specifier|const
name|Function
operator|&
name|F
argument_list|,
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|,
name|Type
operator|*
name|Ty
argument_list|,
name|SmallVectorImpl
operator|<
name|MVT
operator|>
operator|&
name|ValueVTs
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ComputeSignatureVTs
argument_list|(
specifier|const
name|Function
operator|&
name|F
argument_list|,
specifier|const
name|TargetMachine
operator|&
name|TM
argument_list|,
name|SmallVectorImpl
operator|<
name|MVT
operator|>
operator|&
name|Params
argument_list|,
name|SmallVectorImpl
operator|<
name|MVT
operator|>
operator|&
name|Results
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

