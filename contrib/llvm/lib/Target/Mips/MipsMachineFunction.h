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
file|<utility>
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/VectorExtras.h"
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
name|private
operator|:
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
name|int
name|GPFI
block|;
comment|// Index of the frame object for restoring $gp
name|mutable
name|int
name|DynAllocFI
block|;
comment|// Frame index of dynamically allocated stack area.
name|unsigned
name|MaxCallFrameSize
block|;
comment|/// AtomicFrameIndex - To implement atomic.swap and atomic.cmp.swap
comment|/// intrinsics, it is necessary to use a temporary stack location.
comment|/// This field holds the frame index of this location.
name|int
name|AtomicFrameIndex
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
name|GPFI
argument_list|(
literal|0
argument_list|)
block|,
name|DynAllocFI
argument_list|(
literal|0
argument_list|)
block|,
name|MaxCallFrameSize
argument_list|(
literal|0
argument_list|)
block|,
name|AtomicFrameIndex
argument_list|(
argument|-
literal|1
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
name|int
name|getGPFI
argument_list|()
specifier|const
block|{
return|return
name|GPFI
return|;
block|}
name|void
name|setGPFI
parameter_list|(
name|int
name|FI
parameter_list|)
block|{
name|GPFI
operator|=
name|FI
expr_stmt|;
block|}
name|bool
name|needGPSaveRestore
argument_list|()
specifier|const
block|{
return|return
name|getGPFI
argument_list|()
return|;
block|}
name|bool
name|isGPFI
argument_list|(
name|int
name|FI
argument_list|)
decl|const
block|{
return|return
name|GPFI
operator|&&
name|GPFI
operator|==
name|FI
return|;
block|}
comment|// The first call to this function creates a frame object for dynamically
comment|// allocated stack area.
name|int
name|getDynAllocFI
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|DynAllocFI
condition|)
name|DynAllocFI
operator|=
name|MF
operator|.
name|getFrameInfo
argument_list|()
operator|->
name|CreateFixedObject
argument_list|(
literal|4
argument_list|,
literal|0
argument_list|,
name|true
argument_list|)
expr_stmt|;
return|return
name|DynAllocFI
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|bool
name|isDynAllocFI
argument_list|(
name|int
name|FI
argument_list|)
decl|const
block|{
return|return
name|DynAllocFI
operator|&&
name|DynAllocFI
operator|==
name|FI
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|unsigned
name|getSRetReturnReg
argument_list|()
specifier|const
block|{
return|return
name|SRetReturnReg
return|;
block|}
end_expr_stmt

begin_function
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
end_function

begin_expr_stmt
name|unsigned
name|getGlobalBaseReg
argument_list|()
specifier|const
block|{
return|return
name|GlobalBaseReg
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setGlobalBaseReg
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
name|GlobalBaseReg
operator|=
name|Reg
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|int
name|getVarArgsFrameIndex
argument_list|()
specifier|const
block|{
return|return
name|VarArgsFrameIndex
return|;
block|}
end_expr_stmt

begin_function
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
end_function

begin_expr_stmt
name|unsigned
name|getMaxCallFrameSize
argument_list|()
specifier|const
block|{
return|return
name|MaxCallFrameSize
return|;
block|}
end_expr_stmt

begin_function
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
end_function

begin_expr_stmt
name|int
name|getAtomicFrameIndex
argument_list|()
specifier|const
block|{
return|return
name|AtomicFrameIndex
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setAtomicFrameIndex
parameter_list|(
name|int
name|Index
parameter_list|)
block|{
name|AtomicFrameIndex
operator|=
name|Index
expr_stmt|;
block|}
end_function

begin_comment
unit|};  }
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

