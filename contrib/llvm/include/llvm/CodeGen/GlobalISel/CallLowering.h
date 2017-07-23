begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/CodeGen/GlobalISel/CallLowering.h - Call lowering ---*- C++ -*-===//
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
comment|/// This file describes how to lower LLVM calls to machine code calls.
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
name|LLVM_CODEGEN_GLOBALISEL_CALLLOWERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_GLOBALISEL_CALLLOWERING_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/CallingConvLower.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineValueType.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CallSite.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CallingConv.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetCallingConv.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DataLayout
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|MachineIRBuilder
decl_stmt|;
name|class
name|MachineOperand
decl_stmt|;
struct_decl|struct
name|MachinePointerInfo
struct_decl|;
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|TargetLowering
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|CallLowering
block|{
specifier|const
name|TargetLowering
modifier|*
name|TLI
decl_stmt|;
name|public
label|:
struct|struct
name|ArgInfo
block|{
name|unsigned
name|Reg
decl_stmt|;
name|Type
modifier|*
name|Ty
decl_stmt|;
name|ISD
operator|::
name|ArgFlagsTy
name|Flags
expr_stmt|;
name|bool
name|IsFixed
decl_stmt|;
name|ArgInfo
argument_list|(
argument|unsigned Reg
argument_list|,
argument|Type *Ty
argument_list|,
argument|ISD::ArgFlagsTy Flags = ISD::ArgFlagsTy{}
argument_list|,
argument|bool IsFixed = true
argument_list|)
block|:
name|Reg
argument_list|(
name|Reg
argument_list|)
operator|,
name|Ty
argument_list|(
name|Ty
argument_list|)
operator|,
name|Flags
argument_list|(
name|Flags
argument_list|)
operator|,
name|IsFixed
argument_list|(
argument|IsFixed
argument_list|)
block|{}
block|}
struct|;
comment|/// Argument handling is mostly uniform between the four places that
comment|/// make these decisions: function formal arguments, call
comment|/// instruction args, call instruction returns and function
comment|/// returns. However, once a decision has been made on where an
comment|/// arugment should go, exactly what happens can vary slightly. This
comment|/// class abstracts the differences.
struct|struct
name|ValueHandler
block|{
name|ValueHandler
argument_list|(
name|MachineIRBuilder
operator|&
name|MIRBuilder
argument_list|,
name|MachineRegisterInfo
operator|&
name|MRI
argument_list|,
name|CCAssignFn
operator|*
name|AssignFn
argument_list|)
operator|:
name|MIRBuilder
argument_list|(
name|MIRBuilder
argument_list|)
operator|,
name|MRI
argument_list|(
name|MRI
argument_list|)
operator|,
name|AssignFn
argument_list|(
argument|AssignFn
argument_list|)
block|{}
name|virtual
operator|~
name|ValueHandler
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// Materialize a VReg containing the address of the specified
comment|/// stack-based object. This is either based on a FrameIndex or
comment|/// direct SP manipulation, depending on the context. \p MPO
comment|/// should be initialized to an appropriate description of the
comment|/// address created.
name|virtual
name|unsigned
name|getStackAddress
parameter_list|(
name|uint64_t
name|Size
parameter_list|,
name|int64_t
name|Offset
parameter_list|,
name|MachinePointerInfo
modifier|&
name|MPO
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// The specified value has been assigned to a physical register,
comment|/// handle the appropriate COPY (either to or from) and mark any
comment|/// relevant uses/defines as needed.
name|virtual
name|void
name|assignValueToReg
parameter_list|(
name|unsigned
name|ValVReg
parameter_list|,
name|unsigned
name|PhysReg
parameter_list|,
name|CCValAssign
modifier|&
name|VA
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// The specified value has been assigned to a stack
comment|/// location. Load or store it there, with appropriate extension
comment|/// if necessary.
name|virtual
name|void
name|assignValueToAddress
parameter_list|(
name|unsigned
name|ValVReg
parameter_list|,
name|unsigned
name|Addr
parameter_list|,
name|uint64_t
name|Size
parameter_list|,
name|MachinePointerInfo
modifier|&
name|MPO
parameter_list|,
name|CCValAssign
modifier|&
name|VA
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Handle custom values, which may be passed into one or more of \p VAs.
comment|/// \return The number of \p VAs that have been assigned after the first
comment|///         one, and which should therefore be skipped from further
comment|///         processing.
name|virtual
name|unsigned
name|assignCustomValue
argument_list|(
specifier|const
name|ArgInfo
operator|&
name|Arg
argument_list|,
name|ArrayRef
operator|<
name|CCValAssign
operator|>
name|VAs
argument_list|)
block|{
comment|// This is not a pure virtual method because not all targets need to worry
comment|// about custom values.
name|llvm_unreachable
argument_list|(
literal|"Custom values not supported"
argument_list|)
expr_stmt|;
block|}
name|unsigned
name|extendRegister
parameter_list|(
name|unsigned
name|ValReg
parameter_list|,
name|CCValAssign
modifier|&
name|VA
parameter_list|)
function_decl|;
name|virtual
name|bool
name|assignArg
argument_list|(
name|unsigned
name|ValNo
argument_list|,
name|MVT
name|ValVT
argument_list|,
name|MVT
name|LocVT
argument_list|,
name|CCValAssign
operator|::
name|LocInfo
name|LocInfo
argument_list|,
specifier|const
name|ArgInfo
operator|&
name|Info
argument_list|,
name|CCState
operator|&
name|State
argument_list|)
block|{
return|return
name|AssignFn
argument_list|(
name|ValNo
argument_list|,
name|ValVT
argument_list|,
name|LocVT
argument_list|,
name|LocInfo
argument_list|,
name|Info
operator|.
name|Flags
argument_list|,
name|State
argument_list|)
return|;
block|}
name|MachineIRBuilder
modifier|&
name|MIRBuilder
decl_stmt|;
name|MachineRegisterInfo
modifier|&
name|MRI
decl_stmt|;
name|CCAssignFn
modifier|*
name|AssignFn
decl_stmt|;
block|}
struct|;
name|protected
label|:
comment|/// Getter for generic TargetLowering class.
specifier|const
name|TargetLowering
operator|*
name|getTLI
argument_list|()
specifier|const
block|{
return|return
name|TLI
return|;
block|}
comment|/// Getter for target specific TargetLowering class.
name|template
operator|<
name|class
name|XXXTargetLowering
operator|>
specifier|const
name|XXXTargetLowering
operator|*
name|getTLI
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
specifier|const
name|XXXTargetLowering
operator|*
operator|>
operator|(
name|TLI
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|FuncInfoTy
operator|>
name|void
name|setArgFlags
argument_list|(
argument|ArgInfo&Arg
argument_list|,
argument|unsigned OpNum
argument_list|,
argument|const DataLayout&DL
argument_list|,
argument|const FuncInfoTy&FuncInfo
argument_list|)
specifier|const
expr_stmt|;
comment|/// Invoke Handler::assignArg on each of the given \p Args and then use
comment|/// \p Callback to move them to the assigned locations.
comment|///
comment|/// \return True if everything has succeeded, false otherwise.
name|bool
name|handleAssignments
argument_list|(
name|MachineIRBuilder
operator|&
name|MIRBuilder
argument_list|,
name|ArrayRef
operator|<
name|ArgInfo
operator|>
name|Args
argument_list|,
name|ValueHandler
operator|&
name|Callback
argument_list|)
decl|const
decl_stmt|;
name|public
label|:
name|CallLowering
argument_list|(
specifier|const
name|TargetLowering
operator|*
name|TLI
argument_list|)
operator|:
name|TLI
argument_list|(
argument|TLI
argument_list|)
block|{}
name|virtual
operator|~
name|CallLowering
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// This hook must be implemented to lower outgoing return values, described
comment|/// by \p Val, into the specified virtual register \p VReg.
comment|/// This hook is used by GlobalISel.
comment|///
comment|/// \return True if the lowering succeeds, false otherwise.
name|virtual
name|bool
name|lowerReturn
argument_list|(
name|MachineIRBuilder
operator|&
name|MIRBuilder
argument_list|,
specifier|const
name|Value
operator|*
name|Val
argument_list|,
name|unsigned
name|VReg
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// This hook must be implemented to lower the incoming (formal)
comment|/// arguments, described by \p Args, for GlobalISel. Each argument
comment|/// must end up in the related virtual register described by VRegs.
comment|/// In other words, the first argument should end up in VRegs[0],
comment|/// the second in VRegs[1], and so on.
comment|/// \p MIRBuilder is set to the proper insertion for the argument
comment|/// lowering.
comment|///
comment|/// \return True if the lowering succeeded, false otherwise.
name|virtual
name|bool
name|lowerFormalArguments
argument_list|(
name|MachineIRBuilder
operator|&
name|MIRBuilder
argument_list|,
specifier|const
name|Function
operator|&
name|F
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|VRegs
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// This hook must be implemented to lower the given call instruction,
comment|/// including argument and return value marshalling.
comment|///
comment|/// \p CallConv is the calling convention to be used for the call.
comment|///
comment|/// \p Callee is the destination of the call. It should be either a register,
comment|/// globaladdress, or externalsymbol.
comment|///
comment|/// \p ResTy is the type returned by the function
comment|///
comment|/// \p ResReg is the generic virtual register that the returned
comment|/// value should be lowered into.
comment|///
comment|/// \p ArgTys is a list of the types each member of \p ArgRegs has; used by
comment|/// the target to decide which register/stack slot should be allocated.
comment|///
comment|/// \p ArgRegs is a list of virtual registers containing each argument that
comment|/// needs to be passed.
comment|///
comment|/// \return true if the lowering succeeded, false otherwise.
name|virtual
name|bool
name|lowerCall
argument_list|(
name|MachineIRBuilder
operator|&
name|MIRBuilder
argument_list|,
name|CallingConv
operator|::
name|ID
name|CallConv
argument_list|,
specifier|const
name|MachineOperand
operator|&
name|Callee
argument_list|,
specifier|const
name|ArgInfo
operator|&
name|OrigRet
argument_list|,
name|ArrayRef
operator|<
name|ArgInfo
operator|>
name|OrigArgs
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Lower the given call instruction, including argument and return value
comment|/// marshalling.
comment|///
comment|/// \p CI is the call/invoke instruction.
comment|///
comment|/// \p ResReg is a register where the call's return value should be stored (or
comment|/// 0 if there is no return value).
comment|///
comment|/// \p ArgRegs is a list of virtual registers containing each argument that
comment|/// needs to be passed.
comment|///
comment|/// \p GetCalleeReg is a callback to materialize a register for the callee if
comment|/// the target determines it cannot jump to the destination based purely on \p
comment|/// CI. This might be because \p CI is indirect, or because of the limited
comment|/// range of an immediate jump.
comment|///
comment|/// \return true if the lowering succeeded, false otherwise.
name|bool
name|lowerCall
argument_list|(
name|MachineIRBuilder
operator|&
name|MIRBuilder
argument_list|,
name|ImmutableCallSite
name|CS
argument_list|,
name|unsigned
name|ResReg
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|ArgRegs
argument_list|,
name|std
operator|::
name|function
operator|<
name|unsigned
argument_list|()
operator|>
name|GetCalleeReg
argument_list|)
decl|const
decl_stmt|;
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

begin_comment
comment|// LLVM_CODEGEN_GLOBALISEL_CALLLOWERING_H
end_comment

end_unit

