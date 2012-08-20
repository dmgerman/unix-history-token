begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MipsMachineFunctionInfo.h - Private data used for Mips ----*- C++ -*-=//
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
comment|// This file declares the Mips specific subclass of MachineFunctionInfo.
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
name|MIPS_MACHINE_FUNCTION_INFO_H
end_ifndef

begin_define
define|#
directive|define
name|MIPS_MACHINE_FUNCTION_INFO_H
end_define

begin_include
include|#
directive|include
file|"MipsSubtarget.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFrameInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetFrameLowering.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// MipsFunctionInfo - This class is derived from MachineFunction private
comment|/// Mips target-specific information for each MachineFunction.
name|class
name|MipsFunctionInfo
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
comment|/// SRetReturnReg - Some subtargets require that sret lowering includes
comment|/// returning the value of the returned struct in a register. This field
comment|/// holds the virtual register into which the sret argument is passed.
name|unsigned
name|SRetReturnReg
block|;
comment|/// GlobalBaseReg - keeps track of the virtual register initialized for
comment|/// use as the global base register. This is used for PIC in some PIC
comment|/// relocation models.
name|unsigned
name|GlobalBaseReg
block|;
comment|/// VarArgsFrameIndex - FrameIndex for start of varargs area.
name|int
name|VarArgsFrameIndex
block|;
comment|// Range of frame object indices.
comment|// InArgFIRange: Range of indices of all frame objects created during call to
comment|//               LowerFormalArguments.
comment|// OutArgFIRange: Range of indices of all frame objects created during call to
comment|//                LowerCall except for the frame object for restoring $gp.
name|std
operator|::
name|pair
operator|<
name|int
block|,
name|int
operator|>
name|InArgFIRange
block|,
name|OutArgFIRange
block|;
name|unsigned
name|MaxCallFrameSize
block|;
name|bool
name|EmitNOAT
block|;
name|public
operator|:
name|MipsFunctionInfo
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
block|,
name|InArgFIRange
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
argument_list|)
block|,
name|OutArgFIRange
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
argument_list|)
block|,
name|MaxCallFrameSize
argument_list|(
literal|0
argument_list|)
block|,
name|EmitNOAT
argument_list|(
argument|false
argument_list|)
block|{}
name|bool
name|isInArgFI
argument_list|(
argument|int FI
argument_list|)
specifier|const
block|{
return|return
name|FI
operator|<=
name|InArgFIRange
operator|.
name|first
operator|&&
name|FI
operator|>=
name|InArgFIRange
operator|.
name|second
return|;
block|}
name|void
name|setLastInArgFI
argument_list|(
argument|int FI
argument_list|)
block|{
name|InArgFIRange
operator|.
name|second
operator|=
name|FI
block|; }
name|bool
name|isOutArgFI
argument_list|(
argument|int FI
argument_list|)
specifier|const
block|{
return|return
name|FI
operator|<=
name|OutArgFIRange
operator|.
name|first
operator|&&
name|FI
operator|>=
name|OutArgFIRange
operator|.
name|second
return|;
block|}
name|void
name|extendOutArgFIRange
argument_list|(
argument|int FirstFI
argument_list|,
argument|int LastFI
argument_list|)
block|{
if|if
condition|(
operator|!
name|OutArgFIRange
operator|.
name|second
condition|)
comment|// this must be the first time this function was called.
name|OutArgFIRange
operator|.
name|first
operator|=
name|FirstFI
expr_stmt|;
name|OutArgFIRange
operator|.
name|second
operator|=
name|LastFI
block|;   }
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
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
name|SRetReturnReg
operator|=
name|Reg
expr_stmt|;
block|}
name|bool
name|globalBaseRegSet
argument_list|()
specifier|const
expr_stmt|;
name|unsigned
name|getGlobalBaseReg
parameter_list|()
function_decl|;
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
parameter_list|(
name|int
name|Index
parameter_list|)
block|{
name|VarArgsFrameIndex
operator|=
name|Index
expr_stmt|;
block|}
name|unsigned
name|getMaxCallFrameSize
argument_list|()
specifier|const
block|{
return|return
name|MaxCallFrameSize
return|;
block|}
name|void
name|setMaxCallFrameSize
parameter_list|(
name|unsigned
name|S
parameter_list|)
block|{
name|MaxCallFrameSize
operator|=
name|S
expr_stmt|;
block|}
name|bool
name|getEmitNOAT
argument_list|()
specifier|const
block|{
return|return
name|EmitNOAT
return|;
block|}
name|void
name|setEmitNOAT
parameter_list|()
block|{
name|EmitNOAT
operator|=
name|true
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end of namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// MIPS_MACHINE_FUNCTION_INFO_H
end_comment

end_unit

