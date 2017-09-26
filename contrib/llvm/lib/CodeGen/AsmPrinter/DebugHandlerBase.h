begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/lib/CodeGen/AsmPrinter/DebugHandlerBase.h --------*- C++ -*--===//
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
comment|// Common functionality for different debug information format backends.
end_comment

begin_comment
comment|// LLVM currently supports DWARF and CodeView.
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
name|LLVM_LIB_CODEGEN_ASMPRINTER_DEBUGHANDLERBASE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_ASMPRINTER_DEBUGHANDLERBASE_H
end_define

begin_include
include|#
directive|include
file|"AsmPrinterHandler.h"
end_include

begin_include
include|#
directive|include
file|"DbgValueHistoryCalculator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/LexicalScopes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineInstr.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AsmPrinter
decl_stmt|;
name|class
name|MachineModuleInfo
decl_stmt|;
comment|/// Base class for debug information backends. Common functionality related to
comment|/// tracking which variables and scopes are alive at a given PC live here.
name|class
name|DebugHandlerBase
range|:
name|public
name|AsmPrinterHandler
block|{
name|protected
operator|:
name|DebugHandlerBase
argument_list|(
name|AsmPrinter
operator|*
name|A
argument_list|)
block|;
comment|/// Target of debug info emission.
name|AsmPrinter
operator|*
name|Asm
block|;
comment|/// Collected machine module information.
name|MachineModuleInfo
operator|*
name|MMI
block|;
comment|/// Previous instruction's location information. This is used to
comment|/// determine label location to indicate scope boundaries in debug info.
comment|/// We track the previous instruction's source location (if not line 0),
comment|/// whether it was a label, and its parent BB.
name|DebugLoc
name|PrevInstLoc
block|;
name|MCSymbol
operator|*
name|PrevLabel
operator|=
name|nullptr
block|;
specifier|const
name|MachineBasicBlock
operator|*
name|PrevInstBB
operator|=
name|nullptr
block|;
comment|/// This location indicates end of function prologue and beginning of
comment|/// function body.
name|DebugLoc
name|PrologEndLoc
block|;
comment|/// If nonnull, stores the current machine instruction we're processing.
specifier|const
name|MachineInstr
operator|*
name|CurMI
operator|=
name|nullptr
block|;
name|LexicalScopes
name|LScopes
block|;
comment|/// History of DBG_VALUE and clobber instructions for each user
comment|/// variable.  Variables are listed in order of appearance.
name|DbgValueHistoryMap
name|DbgValues
block|;
comment|/// Maps instruction with label emitted before instruction.
comment|/// FIXME: Make this private from DwarfDebug, we have the necessary accessors
comment|/// for it.
name|DenseMap
operator|<
specifier|const
name|MachineInstr
operator|*
block|,
name|MCSymbol
operator|*
operator|>
name|LabelsBeforeInsn
block|;
comment|/// Maps instruction with label emitted after instruction.
name|DenseMap
operator|<
specifier|const
name|MachineInstr
operator|*
block|,
name|MCSymbol
operator|*
operator|>
name|LabelsAfterInsn
block|;
comment|/// Indentify instructions that are marking the beginning of or
comment|/// ending of a scope.
name|void
name|identifyScopeMarkers
argument_list|()
block|;
comment|/// Ensure that a label will be emitted before MI.
name|void
name|requestLabelBeforeInsn
argument_list|(
argument|const MachineInstr *MI
argument_list|)
block|{
name|LabelsBeforeInsn
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|MI
argument_list|,
name|nullptr
argument_list|)
argument_list|)
block|;   }
comment|/// Ensure that a label will be emitted after MI.
name|void
name|requestLabelAfterInsn
argument_list|(
argument|const MachineInstr *MI
argument_list|)
block|{
name|LabelsAfterInsn
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|MI
argument_list|,
name|nullptr
argument_list|)
argument_list|)
block|;   }
name|virtual
name|void
name|beginFunctionImpl
argument_list|(
specifier|const
name|MachineFunction
operator|*
name|MF
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|endFunctionImpl
argument_list|(
specifier|const
name|MachineFunction
operator|*
name|MF
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|skippedNonDebugFunction
argument_list|()
block|{}
comment|// AsmPrinterHandler overrides.
name|public
operator|:
name|void
name|beginInstruction
argument_list|(
argument|const MachineInstr *MI
argument_list|)
name|override
block|;
name|void
name|endInstruction
argument_list|()
name|override
block|;
name|void
name|beginFunction
argument_list|(
argument|const MachineFunction *MF
argument_list|)
name|override
block|;
name|void
name|endFunction
argument_list|(
argument|const MachineFunction *MF
argument_list|)
name|override
block|;
comment|/// Return Label preceding the instruction.
name|MCSymbol
operator|*
name|getLabelBeforeInsn
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
block|;
comment|/// Return Label immediately following the instruction.
name|MCSymbol
operator|*
name|getLabelAfterInsn
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
block|;
comment|/// Determine the relative position of the fragments described by P1 and P2.
comment|/// Returns -1 if P1 is entirely before P2, 0 if P1 and P2 overlap, 1 if P1 is
comment|/// entirely after P2.
specifier|static
name|int
name|fragmentCmp
argument_list|(
specifier|const
name|DIExpression
operator|*
name|P1
argument_list|,
specifier|const
name|DIExpression
operator|*
name|P2
argument_list|)
block|;
comment|/// Determine whether two variable fragments overlap.
specifier|static
name|bool
name|fragmentsOverlap
argument_list|(
specifier|const
name|DIExpression
operator|*
name|P1
argument_list|,
specifier|const
name|DIExpression
operator|*
name|P2
argument_list|)
block|;
comment|/// If this type is derived from a base type then return base type size.
specifier|static
name|uint64_t
name|getBaseTypeSize
argument_list|(
argument|const DITypeRef TyRef
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

