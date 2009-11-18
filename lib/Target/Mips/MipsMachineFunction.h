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
comment|/// Holds for each function where on the stack the Frame Pointer must be
comment|/// saved. This is used on Prologue and Epilogue to emit FP save/restore
name|int
name|FPStackOffset
block|;
comment|/// Holds for each function where on the stack the Return Address must be
comment|/// saved. This is used on Prologue and Epilogue to emit RA save/restore
name|int
name|RAStackOffset
block|;
comment|/// At each function entry, two special bitmask directives must be emitted
comment|/// to help debugging, for CPU and FPU callee saved registers. Both need
comment|/// the negative offset from the final stack size and its higher registers
comment|/// location on the stack.
name|int
name|CPUTopSavedRegOff
block|;
name|int
name|FPUTopSavedRegOff
block|;
comment|/// MipsFIHolder - Holds a FrameIndex and it's Stack Pointer Offset
block|struct
name|MipsFIHolder
block|{
name|int
name|FI
block|;
name|int
name|SPOffset
block|;
name|MipsFIHolder
argument_list|(
argument|int FrameIndex
argument_list|,
argument|int StackPointerOffset
argument_list|)
operator|:
name|FI
argument_list|(
name|FrameIndex
argument_list|)
block|,
name|SPOffset
argument_list|(
argument|StackPointerOffset
argument_list|)
block|{}
block|}
block|;
comment|/// When PIC is used the GP must be saved on the stack on the function
comment|/// prologue and must be reloaded from this stack location after every
comment|/// call. A reference to its stack location and frame index must be kept
comment|/// to be used on emitPrologue and processFunctionBeforeFrameFinalized.
name|MipsFIHolder
name|GPHolder
block|;
comment|/// On LowerFormalArguments the stack size is unknown, so the Stack
comment|/// Pointer Offset calculation of "not in register arguments" must be
comment|/// postponed to emitPrologue.
name|SmallVector
operator|<
name|MipsFIHolder
block|,
literal|16
operator|>
name|FnLoadArgs
block|;
name|bool
name|HasLoadArgs
block|;
comment|// When VarArgs, we must write registers back to caller stack, preserving
comment|// on register arguments. Since the stack size is unknown on
comment|// LowerFormalArguments, the Stack Pointer Offset calculation must be
comment|// postponed to emitPrologue.
name|SmallVector
operator|<
name|MipsFIHolder
block|,
literal|4
operator|>
name|FnStoreVarArgs
block|;
name|bool
name|HasStoreVarArgs
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
name|public
operator|:
name|MipsFunctionInfo
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
operator|:
name|FPStackOffset
argument_list|(
literal|0
argument_list|)
block|,
name|RAStackOffset
argument_list|(
literal|0
argument_list|)
block|,
name|CPUTopSavedRegOff
argument_list|(
literal|0
argument_list|)
block|,
name|FPUTopSavedRegOff
argument_list|(
literal|0
argument_list|)
block|,
name|GPHolder
argument_list|(
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
block|,
name|HasLoadArgs
argument_list|(
name|false
argument_list|)
block|,
name|HasStoreVarArgs
argument_list|(
name|false
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
block|{}
name|int
name|getFPStackOffset
argument_list|()
specifier|const
block|{
return|return
name|FPStackOffset
return|;
block|}
name|void
name|setFPStackOffset
argument_list|(
argument|int Off
argument_list|)
block|{
name|FPStackOffset
operator|=
name|Off
block|; }
name|int
name|getRAStackOffset
argument_list|()
specifier|const
block|{
return|return
name|RAStackOffset
return|;
block|}
name|void
name|setRAStackOffset
argument_list|(
argument|int Off
argument_list|)
block|{
name|RAStackOffset
operator|=
name|Off
block|; }
name|int
name|getCPUTopSavedRegOff
argument_list|()
specifier|const
block|{
return|return
name|CPUTopSavedRegOff
return|;
block|}
name|void
name|setCPUTopSavedRegOff
argument_list|(
argument|int Off
argument_list|)
block|{
name|CPUTopSavedRegOff
operator|=
name|Off
block|; }
name|int
name|getFPUTopSavedRegOff
argument_list|()
specifier|const
block|{
return|return
name|FPUTopSavedRegOff
return|;
block|}
name|void
name|setFPUTopSavedRegOff
argument_list|(
argument|int Off
argument_list|)
block|{
name|FPUTopSavedRegOff
operator|=
name|Off
block|; }
name|int
name|getGPStackOffset
argument_list|()
specifier|const
block|{
return|return
name|GPHolder
operator|.
name|SPOffset
return|;
block|}
name|int
name|getGPFI
argument_list|()
specifier|const
block|{
return|return
name|GPHolder
operator|.
name|FI
return|;
block|}
name|void
name|setGPStackOffset
argument_list|(
argument|int Off
argument_list|)
block|{
name|GPHolder
operator|.
name|SPOffset
operator|=
name|Off
block|; }
name|void
name|setGPFI
argument_list|(
argument|int FI
argument_list|)
block|{
name|GPHolder
operator|.
name|FI
operator|=
name|FI
block|; }
name|bool
name|needGPSaveRestore
argument_list|()
specifier|const
block|{
return|return
name|GPHolder
operator|.
name|SPOffset
operator|!=
operator|-
literal|1
return|;
block|}
name|bool
name|hasLoadArgs
argument_list|()
specifier|const
block|{
return|return
name|HasLoadArgs
return|;
block|}
name|bool
name|hasStoreVarArgs
argument_list|()
specifier|const
block|{
return|return
name|HasStoreVarArgs
return|;
block|}
name|void
name|recordLoadArgsFI
argument_list|(
argument|int FI
argument_list|,
argument|int SPOffset
argument_list|)
block|{
if|if
condition|(
operator|!
name|HasLoadArgs
condition|)
name|HasLoadArgs
operator|=
name|true
expr_stmt|;
name|FnLoadArgs
operator|.
name|push_back
argument_list|(
name|MipsFIHolder
argument_list|(
name|FI
argument_list|,
name|SPOffset
argument_list|)
argument_list|)
block|;   }
name|void
name|recordStoreVarArgsFI
argument_list|(
argument|int FI
argument_list|,
argument|int SPOffset
argument_list|)
block|{
if|if
condition|(
operator|!
name|HasStoreVarArgs
condition|)
name|HasStoreVarArgs
operator|=
name|true
expr_stmt|;
name|FnStoreVarArgs
operator|.
name|push_back
argument_list|(
name|MipsFIHolder
argument_list|(
name|FI
argument_list|,
name|SPOffset
argument_list|)
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|adjustLoadArgsFI
argument_list|(
name|MachineFrameInfo
operator|*
name|MFI
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|hasLoadArgs
argument_list|()
condition|)
return|return;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|FnLoadArgs
operator|.
name|size
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
name|MFI
operator|->
name|setObjectOffset
argument_list|(
name|FnLoadArgs
index|[
name|i
index|]
operator|.
name|FI
argument_list|,
name|FnLoadArgs
index|[
name|i
index|]
operator|.
name|SPOffset
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|adjustStoreVarArgsFI
argument_list|(
name|MachineFrameInfo
operator|*
name|MFI
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|hasStoreVarArgs
argument_list|()
condition|)
return|return;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|FnStoreVarArgs
operator|.
name|size
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
name|MFI
operator|->
name|setObjectOffset
argument_list|(
name|FnStoreVarArgs
index|[
name|i
index|]
operator|.
name|FI
argument_list|,
name|FnStoreVarArgs
index|[
name|i
index|]
operator|.
name|SPOffset
argument_list|)
expr_stmt|;
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

