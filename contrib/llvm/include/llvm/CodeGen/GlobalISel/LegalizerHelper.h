begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== llvm/CodeGen/GlobalISel/LegalizerHelper.h ---------------- -*- C++ -*-==//
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
comment|/// \file A pass to convert the target-illegal operations created by IR -> MIR
end_comment

begin_comment
comment|/// translation into ones the target expects to be able to select. This may
end_comment

begin_comment
comment|/// occur in multiple phases, for example G_ADD<2 x i8> -> G_ADD<2 x i16> ->
end_comment

begin_comment
comment|/// G_ADD<4 x i16>.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The LegalizerHelper class is where most of the work happens, and is
end_comment

begin_comment
comment|/// designed to be callable from other passes that find themselves with an
end_comment

begin_comment
comment|/// illegal instruction.
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
name|LLVM_CODEGEN_GLOBALISEL_MACHINELEGALIZEHELPER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_GLOBALISEL_MACHINELEGALIZEHELPER_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/GlobalISel/CallLowering.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/GlobalISel/MachineIRBuilder.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/LowLevelType.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/RuntimeLibcalls.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Forward declarations.
name|class
name|LegalizerInfo
decl_stmt|;
name|class
name|Legalizer
decl_stmt|;
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|LegalizerHelper
block|{
name|public
label|:
enum|enum
name|LegalizeResult
block|{
comment|/// Instruction was already legal and no change was made to the
comment|/// MachineFunction.
name|AlreadyLegal
block|,
comment|/// Instruction has been legalized and the MachineFunction changed.
name|Legalized
block|,
comment|/// Some kind of error has occurred and we could not legalize this
comment|/// instruction.
name|UnableToLegalize
block|,   }
enum|;
name|LegalizerHelper
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
expr_stmt|;
comment|/// Replace \p MI by a sequence of legal instructions that can implement the
comment|/// same operation. Note that this means \p MI may be deleted, so any iterator
comment|/// steps should be performed before calling this function. \p Helper should
comment|/// be initialized to the MachineFunction containing \p MI.
comment|///
comment|/// Considered as an opaque blob, the legal code will use and define the same
comment|/// registers as \p MI.
name|LegalizeResult
name|legalizeInstrStep
parameter_list|(
name|MachineInstr
modifier|&
name|MI
parameter_list|)
function_decl|;
comment|/// Legalize an instruction by emiting a runtime library call instead.
name|LegalizeResult
name|libcall
parameter_list|(
name|MachineInstr
modifier|&
name|MI
parameter_list|)
function_decl|;
comment|/// Legalize an instruction by reducing the width of the underlying scalar
comment|/// type.
name|LegalizeResult
name|narrowScalar
parameter_list|(
name|MachineInstr
modifier|&
name|MI
parameter_list|,
name|unsigned
name|TypeIdx
parameter_list|,
name|LLT
name|NarrowTy
parameter_list|)
function_decl|;
comment|/// Legalize an instruction by performing the operation on a wider scalar type
comment|/// (for example a 16-bit addition can be safely performed at 32-bits
comment|/// precision, ignoring the unused bits).
name|LegalizeResult
name|widenScalar
parameter_list|(
name|MachineInstr
modifier|&
name|MI
parameter_list|,
name|unsigned
name|TypeIdx
parameter_list|,
name|LLT
name|WideTy
parameter_list|)
function_decl|;
comment|/// Legalize an instruction by splitting it into simpler parts, hopefully
comment|/// understood by the target.
name|LegalizeResult
name|lower
parameter_list|(
name|MachineInstr
modifier|&
name|MI
parameter_list|,
name|unsigned
name|TypeIdx
parameter_list|,
name|LLT
name|Ty
parameter_list|)
function_decl|;
comment|/// Legalize a vector instruction by splitting into multiple components, each
comment|/// acting on the same scalar type as the original but with fewer elements.
name|LegalizeResult
name|fewerElementsVector
parameter_list|(
name|MachineInstr
modifier|&
name|MI
parameter_list|,
name|unsigned
name|TypeIdx
parameter_list|,
name|LLT
name|NarrowTy
parameter_list|)
function_decl|;
comment|/// Legalize a vector instruction by increasing the number of vector elements
comment|/// involved and ignoring the added elements later.
name|LegalizeResult
name|moreElementsVector
parameter_list|(
name|MachineInstr
modifier|&
name|MI
parameter_list|,
name|unsigned
name|TypeIdx
parameter_list|,
name|LLT
name|WideTy
parameter_list|)
function_decl|;
comment|/// Expose MIRBuilder so clients can set their own RecordInsertInstruction
comment|/// functions
name|MachineIRBuilder
name|MIRBuilder
decl_stmt|;
name|private
label|:
comment|/// Helper function to split a wide generic register into bitwise blocks with
comment|/// the given Type (which implies the number of blocks needed). The generic
comment|/// registers created are appended to Ops, starting at bit 0 of Reg.
name|void
name|extractParts
argument_list|(
name|unsigned
name|Reg
argument_list|,
name|LLT
name|Ty
argument_list|,
name|int
name|NumParts
argument_list|,
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|Ops
argument_list|)
decl_stmt|;
name|MachineRegisterInfo
modifier|&
name|MRI
decl_stmt|;
specifier|const
name|LegalizerInfo
modifier|&
name|LI
decl_stmt|;
block|}
empty_stmt|;
comment|/// Helper function that replaces \p MI with a libcall.
name|LegalizerHelper
operator|::
name|LegalizeResult
name|replaceWithLibcall
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|,
argument|RTLIB::Libcall Libcall
argument_list|,
argument|const CallLowering::ArgInfo&Result
argument_list|,
argument|ArrayRef<CallLowering::ArgInfo> Args
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

