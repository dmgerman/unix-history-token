begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PPC.h - Top-level interface for PowerPC Target ----------*- C++ -*-===//
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
comment|// This file contains the entry points for global functions defined in the LLVM
end_comment

begin_comment
comment|// PowerPC back-end.
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
name|LLVM_LIB_TARGET_POWERPC_PPC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_POWERPC_PPC_H
end_define

begin_include
include|#
directive|include
file|"MCTargetDesc/PPCMCTargetDesc.h"
end_include

begin_comment
comment|// GCC #defines PPC on Linux but we use it as our namespace name
end_comment

begin_undef
undef|#
directive|undef
name|PPC
end_undef

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|PPCTargetMachine
decl_stmt|;
name|class
name|PassRegistry
decl_stmt|;
name|class
name|FunctionPass
decl_stmt|;
name|class
name|ImmutablePass
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|AsmPrinter
decl_stmt|;
name|class
name|MCInst
decl_stmt|;
name|FunctionPass
modifier|*
name|createPPCCTRLoops
parameter_list|(
name|PPCTargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|NDEBUG
name|FunctionPass
modifier|*
name|createPPCCTRLoopsVerify
parameter_list|()
function_decl|;
endif|#
directive|endif
name|FunctionPass
modifier|*
name|createPPCLoopPreIncPrepPass
parameter_list|(
name|PPCTargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createPPCTOCRegDepsPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createPPCEarlyReturnPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createPPCVSXCopyPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createPPCVSXFMAMutatePass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createPPCVSXSwapRemovalPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createPPCMIPeepholePass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createPPCBranchSelectionPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createPPCQPXLoadSplatPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createPPCISelDag
parameter_list|(
name|PPCTargetMachine
modifier|&
name|TM
parameter_list|)
function_decl|;
name|FunctionPass
modifier|*
name|createPPCTLSDynamicCallPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createPPCBoolRetToIntPass
parameter_list|()
function_decl|;
name|FunctionPass
modifier|*
name|createPPCExpandISELPass
parameter_list|()
function_decl|;
name|void
name|LowerPPCMachineInstrToMCInst
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|,
name|MCInst
modifier|&
name|OutMI
parameter_list|,
name|AsmPrinter
modifier|&
name|AP
parameter_list|,
name|bool
name|isDarwin
parameter_list|)
function_decl|;
name|void
name|initializePPCVSXFMAMutatePass
parameter_list|(
name|PassRegistry
modifier|&
parameter_list|)
function_decl|;
name|void
name|initializePPCBoolRetToIntPass
parameter_list|(
name|PassRegistry
modifier|&
parameter_list|)
function_decl|;
name|void
name|initializePPCExpandISELPass
parameter_list|(
name|PassRegistry
modifier|&
parameter_list|)
function_decl|;
specifier|extern
name|char
modifier|&
name|PPCVSXFMAMutateID
decl_stmt|;
name|namespace
name|PPCII
block|{
comment|/// Target Operand Flag enum.
enum|enum
name|TOF
block|{
comment|//===------------------------------------------------------------------===//
comment|// PPC Specific MachineOperand flags.
name|MO_NO_FLAG
block|,
comment|/// On a symbol operand "FOO", this indicates that the reference is actually
comment|/// to "FOO@plt".  This is used for calls and jumps to external functions on
comment|/// for PIC calls on Linux and ELF systems.
name|MO_PLT
init|=
literal|1
block|,
comment|/// MO_PIC_FLAG - If this bit is set, the symbol reference is relative to
comment|/// the function's picbase, e.g. lo16(symbol-picbase).
name|MO_PIC_FLAG
init|=
literal|2
block|,
comment|/// MO_NLP_FLAG - If this bit is set, the symbol reference is actually to
comment|/// the non_lazy_ptr for the global, e.g. lo16(symbol$non_lazy_ptr-picbase).
name|MO_NLP_FLAG
init|=
literal|4
block|,
comment|/// MO_NLP_HIDDEN_FLAG - If this bit is set, the symbol reference is to a
comment|/// symbol with hidden visibility.  This causes a different kind of
comment|/// non-lazy-pointer to be generated.
name|MO_NLP_HIDDEN_FLAG
init|=
literal|8
block|,
comment|/// The next are not flags but distinct values.
name|MO_ACCESS_MASK
init|=
literal|0xf0
block|,
comment|/// MO_LO, MO_HA - lo16(symbol) and ha16(symbol)
name|MO_LO
init|=
literal|1
operator|<<
literal|4
block|,
name|MO_HA
init|=
literal|2
operator|<<
literal|4
block|,
name|MO_TPREL_LO
init|=
literal|4
operator|<<
literal|4
block|,
name|MO_TPREL_HA
init|=
literal|3
operator|<<
literal|4
block|,
comment|/// These values identify relocations on immediates folded
comment|/// into memory operations.
name|MO_DTPREL_LO
init|=
literal|5
operator|<<
literal|4
block|,
name|MO_TLSLD_LO
init|=
literal|6
operator|<<
literal|4
block|,
name|MO_TOC_LO
init|=
literal|7
operator|<<
literal|4
block|,
comment|// Symbol for VK_PPC_TLS fixup attached to an ADD instruction
name|MO_TLS
init|=
literal|8
operator|<<
literal|4
block|}
enum|;
block|}
comment|// end namespace PPCII
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm;
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

