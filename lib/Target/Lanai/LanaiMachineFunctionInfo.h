begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LanaiMachineFuctionInfo.h - Lanai machine func info -------*- C++ -*-==//
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
comment|// This file declares Lanai-specific per-machine-function information.
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
name|LLVM_LIB_TARGET_LANAI_LANAIMACHINEFUNCTIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_LANAI_LANAIMACHINEFUNCTIONINFO_H
end_define

begin_include
include|#
directive|include
file|"LanaiRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
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
comment|// LanaiMachineFunctionInfo - This class is derived from MachineFunction and
comment|// contains private Lanai target-specific information for each MachineFunction.
name|class
name|LanaiMachineFunctionInfo
range|:
name|public
name|MachineFunctionInfo
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|MachineFunction
operator|&
name|MF
block|;
comment|// SRetReturnReg - Lanai ABI require that sret lowering includes
comment|// returning the value of the returned struct in a register. This field
comment|// holds the virtual register into which the sret argument is passed.
name|unsigned
name|SRetReturnReg
block|;
comment|// GlobalBaseReg - keeps track of the virtual register initialized for
comment|// use as the global base register. This is used for PIC in some PIC
comment|// relocation models.
name|unsigned
name|GlobalBaseReg
block|;
comment|// VarArgsFrameIndex - FrameIndex for start of varargs area.
name|int
name|VarArgsFrameIndex
block|;
name|public
operator|:
name|explicit
name|LanaiMachineFunctionInfo
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
operator|:
name|MF
argument_list|(
name|MF
argument_list|)
block|,
name|SRetReturnReg
argument_list|(
literal|0
argument_list|)
block|,
name|GlobalBaseReg
argument_list|(
literal|0
argument_list|)
block|,
name|VarArgsFrameIndex
argument_list|(
literal|0
argument_list|)
block|{}
name|unsigned
name|getSRetReturnReg
argument_list|()
specifier|const
block|{
return|return
name|SRetReturnReg
return|;
block|}
name|void
name|setSRetReturnReg
argument_list|(
argument|unsigned Reg
argument_list|)
block|{
name|SRetReturnReg
operator|=
name|Reg
block|; }
name|unsigned
name|getGlobalBaseReg
argument_list|()
block|;
name|int
name|getVarArgsFrameIndex
argument_list|()
specifier|const
block|{
return|return
name|VarArgsFrameIndex
return|;
block|}
name|void
name|setVarArgsFrameIndex
argument_list|(
argument|int Index
argument_list|)
block|{
name|VarArgsFrameIndex
operator|=
name|Index
block|; }
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_LANAI_LANAIMACHINEFUNCTIONINFO_H
end_comment

end_unit

