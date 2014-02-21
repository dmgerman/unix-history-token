begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/AsmPrinter.h - AsmPrinter Framework --------*- C++ -*-===//
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
comment|// This file contains a class to be used as the base class for target specific
end_comment

begin_comment
comment|// asm writers.  This class primarily handles common functionality used by
end_comment

begin_comment
comment|// all asm writers.
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
name|LLVM_CODEGEN_ASMPRINTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_ASMPRINTER_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/InlineAsm.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BlockAddress
decl_stmt|;
name|class
name|GCStrategy
decl_stmt|;
name|class
name|Constant
decl_stmt|;
name|class
name|ConstantArray
decl_stmt|;
name|class
name|GCMetadataPrinter
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineLocation
decl_stmt|;
name|class
name|MachineLoopInfo
decl_stmt|;
name|class
name|MachineLoop
decl_stmt|;
name|class
name|MachineConstantPoolValue
decl_stmt|;
name|class
name|MachineJumpTableInfo
decl_stmt|;
name|class
name|MachineModuleInfo
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|MCCFIInstruction
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MCInstrInfo
decl_stmt|;
name|class
name|MCSection
decl_stmt|;
name|class
name|MCStreamer
decl_stmt|;
name|class
name|MCSymbol
decl_stmt|;
name|class
name|MDNode
decl_stmt|;
name|class
name|DwarfDebug
decl_stmt|;
name|class
name|DwarfException
decl_stmt|;
name|class
name|Mangler
decl_stmt|;
name|class
name|TargetLoweringObjectFile
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
comment|/// AsmPrinter - This class is intended to be used as a driving class for all
comment|/// asm writers.
name|class
name|AsmPrinter
range|:
name|public
name|MachineFunctionPass
block|{
name|public
operator|:
comment|/// Target machine description.
comment|///
name|TargetMachine
operator|&
name|TM
block|;
comment|/// Target Asm Printer information.
comment|///
specifier|const
name|MCAsmInfo
operator|*
name|MAI
block|;
specifier|const
name|MCInstrInfo
operator|*
name|MII
block|;
comment|/// OutContext - This is the context for the output file that we are
comment|/// streaming.  This owns all of the global MC-related objects for the
comment|/// generated translation unit.
name|MCContext
operator|&
name|OutContext
block|;
comment|/// OutStreamer - This is the MCStreamer object for the file we are
comment|/// generating.  This contains the transient state for the current
comment|/// translation unit that we are generating (such as the current section
comment|/// etc).
name|MCStreamer
operator|&
name|OutStreamer
block|;
comment|/// The current machine function.
specifier|const
name|MachineFunction
operator|*
name|MF
block|;
comment|/// MMI - This is a pointer to the current MachineModuleInfo.
name|MachineModuleInfo
operator|*
name|MMI
block|;
comment|/// Name-mangler for global names.
comment|///
name|Mangler
operator|*
name|Mang
block|;
comment|/// The symbol for the current function. This is recalculated at the
comment|/// beginning of each call to runOnMachineFunction().
comment|///
name|MCSymbol
operator|*
name|CurrentFnSym
block|;
comment|/// The symbol used to represent the start of the current function for the
comment|/// purpose of calculating its size (e.g. using the .size directive). By
comment|/// default, this is equal to CurrentFnSym.
name|MCSymbol
operator|*
name|CurrentFnSymForSize
block|;
name|private
operator|:
comment|// GCMetadataPrinters - The garbage collection metadata printer table.
name|void
operator|*
name|GCMetadataPrinters
block|;
comment|// Really a DenseMap.
comment|/// VerboseAsm - Emit comments in assembly output if this is true.
comment|///
name|bool
name|VerboseAsm
block|;
specifier|static
name|char
name|ID
block|;
comment|/// If VerboseAsm is set, a pointer to the loop info for this
comment|/// function.
name|MachineLoopInfo
operator|*
name|LI
block|;
comment|/// DD - If the target supports dwarf debug info, this pointer is non-null.
name|DwarfDebug
operator|*
name|DD
block|;
comment|/// DE - If the target supports dwarf exception info, this pointer is
comment|/// non-null.
name|DwarfException
operator|*
name|DE
block|;
name|protected
operator|:
name|explicit
name|AsmPrinter
argument_list|(
name|TargetMachine
operator|&
name|TM
argument_list|,
name|MCStreamer
operator|&
name|Streamer
argument_list|)
block|;
name|public
operator|:
name|virtual
operator|~
name|AsmPrinter
argument_list|()
block|;
specifier|const
name|DwarfDebug
operator|*
name|getDwarfDebug
argument_list|()
specifier|const
block|{
return|return
name|DD
return|;
block|}
comment|/// isVerbose - Return true if assembly output should contain comments.
comment|///
name|bool
name|isVerbose
argument_list|()
specifier|const
block|{
return|return
name|VerboseAsm
return|;
block|}
comment|/// getFunctionNumber - Return a unique ID for the current function.
comment|///
name|unsigned
name|getFunctionNumber
argument_list|()
specifier|const
block|;
comment|/// getObjFileLowering - Return information about object file lowering.
specifier|const
name|TargetLoweringObjectFile
operator|&
name|getObjFileLowering
argument_list|()
specifier|const
block|;
comment|/// getDataLayout - Return information about data layout.
specifier|const
name|DataLayout
operator|&
name|getDataLayout
argument_list|()
specifier|const
block|;
comment|/// getTargetTriple - Return the target triple string.
name|StringRef
name|getTargetTriple
argument_list|()
specifier|const
block|;
comment|/// getCurrentSection() - Return the current section we are emitting to.
specifier|const
name|MCSection
operator|*
name|getCurrentSection
argument_list|()
specifier|const
block|;
name|MCSymbol
operator|*
name|getSymbol
argument_list|(
argument|const GlobalValue *GV
argument_list|)
specifier|const
block|;
comment|//===------------------------------------------------------------------===//
comment|// MachineFunctionPass Implementation.
comment|//===------------------------------------------------------------------===//
comment|/// getAnalysisUsage - Record analysis usage.
comment|///
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
block|;
comment|/// doInitialization - Set up the AsmPrinter when we are working on a new
comment|/// module.  If your pass overrides this, it must make sure to explicitly
comment|/// call this implementation.
name|bool
name|doInitialization
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
comment|/// doFinalization - Shut down the asmprinter.  If you override this in your
comment|/// pass, you must make sure to call it explicitly.
name|bool
name|doFinalization
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
comment|/// runOnMachineFunction - Emit the specified function out to the
comment|/// OutStreamer.
name|virtual
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&MF
argument_list|)
block|{
name|SetupMachineFunction
argument_list|(
name|MF
argument_list|)
block|;
name|EmitFunctionHeader
argument_list|()
block|;
name|EmitFunctionBody
argument_list|()
block|;
return|return
name|false
return|;
block|}
comment|//===------------------------------------------------------------------===//
comment|// Coarse grained IR lowering routines.
comment|//===------------------------------------------------------------------===//
comment|/// SetupMachineFunction - This should be called when a new MachineFunction
comment|/// is being processed from runOnMachineFunction.
name|void
name|SetupMachineFunction
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
comment|/// EmitFunctionHeader - This method emits the header for the current
comment|/// function.
name|void
name|EmitFunctionHeader
argument_list|()
block|;
comment|/// EmitFunctionBody - This method emits the body and trailer for a
comment|/// function.
name|void
name|EmitFunctionBody
argument_list|()
block|;
name|void
name|emitPrologLabel
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|)
block|;      enum
name|CFIMoveType
block|{
name|CFI_M_None
block|,
name|CFI_M_EH
block|,
name|CFI_M_Debug
block|}
block|;
name|CFIMoveType
name|needsCFIMoves
argument_list|()
block|;
name|bool
name|needsSEHMoves
argument_list|()
block|;
comment|/// needsRelocationsForDwarfStringPool - Specifies whether the object format
comment|/// expects to use relocations to refer to debug entries. Alternatively we
comment|/// emit section offsets in bytes from the start of the string pool.
name|bool
name|needsRelocationsForDwarfStringPool
argument_list|()
specifier|const
block|;
comment|/// EmitConstantPool - Print to the current output stream assembly
comment|/// representations of the constants in the constant pool MCP. This is
comment|/// used to print out constants which have been "spilled to memory" by
comment|/// the code generator.
comment|///
name|virtual
name|void
name|EmitConstantPool
argument_list|()
block|;
comment|/// EmitJumpTableInfo - Print assembly representations of the jump tables
comment|/// used by the current function to the current output stream.
comment|///
name|void
name|EmitJumpTableInfo
argument_list|()
block|;
comment|/// EmitGlobalVariable - Emit the specified global variable to the .s file.
name|virtual
name|void
name|EmitGlobalVariable
argument_list|(
specifier|const
name|GlobalVariable
operator|*
name|GV
argument_list|)
block|;
comment|/// EmitSpecialLLVMGlobal - Check to see if the specified global is a
comment|/// special global used by LLVM.  If so, emit it and return true, otherwise
comment|/// do nothing and return false.
name|bool
name|EmitSpecialLLVMGlobal
argument_list|(
specifier|const
name|GlobalVariable
operator|*
name|GV
argument_list|)
block|;
comment|/// EmitAlignment - Emit an alignment directive to the specified power of
comment|/// two boundary.  For example, if you pass in 3 here, you will get an 8
comment|/// byte alignment.  If a global value is specified, and if that global has
comment|/// an explicit alignment requested, it will override the alignment request
comment|/// if required for correctness.
comment|///
name|void
name|EmitAlignment
argument_list|(
argument|unsigned NumBits
argument_list|,
argument|const GlobalValue *GV =
literal|0
argument_list|)
specifier|const
block|;
comment|/// EmitBasicBlockStart - This method prints the label for the specified
comment|/// MachineBasicBlock, an alignment (if present) and a comment describing
comment|/// it if appropriate.
name|void
name|EmitBasicBlockStart
argument_list|(
argument|const MachineBasicBlock *MBB
argument_list|)
specifier|const
block|;
comment|/// \brief Print a general LLVM constant to the .s file.
name|void
name|EmitGlobalConstant
argument_list|(
specifier|const
name|Constant
operator|*
name|CV
argument_list|)
block|;
comment|//===------------------------------------------------------------------===//
comment|// Overridable Hooks
comment|//===------------------------------------------------------------------===//
comment|// Targets can, or in the case of EmitInstruction, must implement these to
comment|// customize output.
comment|/// EmitStartOfAsmFile - This virtual method can be overridden by targets
comment|/// that want to emit something at the start of their file.
name|virtual
name|void
name|EmitStartOfAsmFile
argument_list|(
argument|Module&
argument_list|)
block|{}
comment|/// EmitEndOfAsmFile - This virtual method can be overridden by targets that
comment|/// want to emit something at the end of their file.
name|virtual
name|void
name|EmitEndOfAsmFile
argument_list|(
argument|Module&
argument_list|)
block|{}
comment|/// EmitFunctionBodyStart - Targets can override this to emit stuff before
comment|/// the first basic block in the function.
name|virtual
name|void
name|EmitFunctionBodyStart
argument_list|()
block|{}
comment|/// EmitFunctionBodyEnd - Targets can override this to emit stuff after
comment|/// the last basic block in the function.
name|virtual
name|void
name|EmitFunctionBodyEnd
argument_list|()
block|{}
comment|/// EmitInstruction - Targets should implement this to emit instructions.
name|virtual
name|void
name|EmitInstruction
argument_list|(
argument|const MachineInstr *
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"EmitInstruction not implemented"
argument_list|)
block|;     }
name|virtual
name|void
name|EmitFunctionEntryLabel
argument_list|()
block|;
name|virtual
name|void
name|EmitMachineConstantPoolValue
argument_list|(
name|MachineConstantPoolValue
operator|*
name|MCPV
argument_list|)
block|;
comment|/// EmitXXStructor - Targets can override this to change how global
comment|/// constants that are part of a C++ static/global constructor list are
comment|/// emitted.
name|virtual
name|void
name|EmitXXStructor
argument_list|(
argument|const Constant *CV
argument_list|)
block|{
name|EmitGlobalConstant
argument_list|(
name|CV
argument_list|)
block|;     }
comment|/// isBlockOnlyReachableByFallthough - Return true if the basic block has
comment|/// exactly one predecessor and the control transfer mechanism between
comment|/// the predecessor and this block is a fall-through.
name|virtual
name|bool
name|isBlockOnlyReachableByFallthrough
argument_list|(
argument|const MachineBasicBlock *MBB
argument_list|)
specifier|const
block|;
comment|/// emitImplicitDef - Targets can override this to customize the output of
comment|/// IMPLICIT_DEF instructions in verbose mode.
name|virtual
name|void
name|emitImplicitDef
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
comment|//===------------------------------------------------------------------===//
comment|// Symbol Lowering Routines.
comment|//===------------------------------------------------------------------===//
name|public
operator|:
comment|/// GetTempSymbol - Return the MCSymbol corresponding to the assembler
comment|/// temporary label with the specified stem and unique ID.
name|MCSymbol
operator|*
name|GetTempSymbol
argument_list|(
argument|StringRef Name
argument_list|,
argument|unsigned ID
argument_list|)
specifier|const
block|;
comment|/// GetTempSymbol - Return an assembler temporary label with the specified
comment|/// stem.
name|MCSymbol
operator|*
name|GetTempSymbol
argument_list|(
argument|StringRef Name
argument_list|)
specifier|const
block|;
comment|/// GetSymbolWithGlobalValueBase - Return the MCSymbol for a symbol with
comment|/// global value name as its base, with the specified suffix, and where the
comment|/// symbol is forced to have private linkage if ForcePrivate is true.
name|MCSymbol
operator|*
name|GetSymbolWithGlobalValueBase
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|StringRef Suffix
argument_list|,
argument|bool ForcePrivate = true
argument_list|)
specifier|const
block|;
comment|/// GetExternalSymbolSymbol - Return the MCSymbol for the specified
comment|/// ExternalSymbol.
name|MCSymbol
operator|*
name|GetExternalSymbolSymbol
argument_list|(
argument|StringRef Sym
argument_list|)
specifier|const
block|;
comment|/// GetCPISymbol - Return the symbol for the specified constant pool entry.
name|MCSymbol
operator|*
name|GetCPISymbol
argument_list|(
argument|unsigned CPID
argument_list|)
specifier|const
block|;
comment|/// GetJTISymbol - Return the symbol for the specified jump table entry.
name|MCSymbol
operator|*
name|GetJTISymbol
argument_list|(
argument|unsigned JTID
argument_list|,
argument|bool isLinkerPrivate = false
argument_list|)
specifier|const
block|;
comment|/// GetJTSetSymbol - Return the symbol for the specified jump table .set
comment|/// FIXME: privatize to AsmPrinter.
name|MCSymbol
operator|*
name|GetJTSetSymbol
argument_list|(
argument|unsigned UID
argument_list|,
argument|unsigned MBBID
argument_list|)
specifier|const
block|;
comment|/// GetBlockAddressSymbol - Return the MCSymbol used to satisfy BlockAddress
comment|/// uses of the specified basic block.
name|MCSymbol
operator|*
name|GetBlockAddressSymbol
argument_list|(
argument|const BlockAddress *BA
argument_list|)
specifier|const
block|;
name|MCSymbol
operator|*
name|GetBlockAddressSymbol
argument_list|(
argument|const BasicBlock *BB
argument_list|)
specifier|const
block|;
comment|//===------------------------------------------------------------------===//
comment|// Emission Helper Routines.
comment|//===------------------------------------------------------------------===//
name|public
operator|:
comment|/// printOffset - This is just convenient handler for printing offsets.
name|void
name|printOffset
argument_list|(
argument|int64_t Offset
argument_list|,
argument|raw_ostream&OS
argument_list|)
specifier|const
block|;
comment|/// EmitInt8 - Emit a byte directive and value.
comment|///
name|void
name|EmitInt8
argument_list|(
argument|int Value
argument_list|)
specifier|const
block|;
comment|/// EmitInt16 - Emit a short directive and value.
comment|///
name|void
name|EmitInt16
argument_list|(
argument|int Value
argument_list|)
specifier|const
block|;
comment|/// EmitInt32 - Emit a long directive and value.
comment|///
name|void
name|EmitInt32
argument_list|(
argument|int Value
argument_list|)
specifier|const
block|;
comment|/// EmitLabelDifference - Emit something like ".long Hi-Lo" where the size
comment|/// in bytes of the directive is specified by Size and Hi/Lo specify the
comment|/// labels.  This implicitly uses .set if it is available.
name|void
name|EmitLabelDifference
argument_list|(
argument|const MCSymbol *Hi
argument_list|,
argument|const MCSymbol *Lo
argument_list|,
argument|unsigned Size
argument_list|)
specifier|const
block|;
comment|/// EmitLabelOffsetDifference - Emit something like ".long Hi+Offset-Lo"
comment|/// where the size in bytes of the directive is specified by Size and Hi/Lo
comment|/// specify the labels.  This implicitly uses .set if it is available.
name|void
name|EmitLabelOffsetDifference
argument_list|(
argument|const MCSymbol *Hi
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|const MCSymbol *Lo
argument_list|,
argument|unsigned Size
argument_list|)
specifier|const
block|;
comment|/// EmitLabelPlusOffset - Emit something like ".long Label+Offset"
comment|/// where the size in bytes of the directive is specified by Size and Label
comment|/// specifies the label.  This implicitly uses .set if it is available.
name|void
name|EmitLabelPlusOffset
argument_list|(
argument|const MCSymbol *Label
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|unsigned Size
argument_list|,
argument|bool IsSectionRelative = false
argument_list|)
specifier|const
block|;
comment|/// EmitLabelReference - Emit something like ".long Label"
comment|/// where the size in bytes of the directive is specified by Size and Label
comment|/// specifies the label.
name|void
name|EmitLabelReference
argument_list|(
argument|const MCSymbol *Label
argument_list|,
argument|unsigned Size
argument_list|,
argument|bool IsSectionRelative = false
argument_list|)
specifier|const
block|{
name|EmitLabelPlusOffset
argument_list|(
name|Label
argument_list|,
literal|0
argument_list|,
name|Size
argument_list|,
name|IsSectionRelative
argument_list|)
block|;     }
comment|//===------------------------------------------------------------------===//
comment|// Dwarf Emission Helper Routines
comment|//===------------------------------------------------------------------===//
comment|/// EmitSLEB128 - emit the specified signed leb128 value.
name|void
name|EmitSLEB128
argument_list|(
argument|int64_t Value
argument_list|,
argument|const char *Desc =
literal|0
argument_list|)
specifier|const
block|;
comment|/// EmitULEB128 - emit the specified unsigned leb128 value.
name|void
name|EmitULEB128
argument_list|(
argument|uint64_t Value
argument_list|,
argument|const char *Desc =
literal|0
argument_list|,
argument|unsigned PadTo =
literal|0
argument_list|)
specifier|const
block|;
comment|/// EmitCFAByte - Emit a .byte 42 directive for a DW_CFA_xxx value.
name|void
name|EmitCFAByte
argument_list|(
argument|unsigned Val
argument_list|)
specifier|const
block|;
comment|/// EmitEncodingByte - Emit a .byte 42 directive that corresponds to an
comment|/// encoding.  If verbose assembly output is enabled, we output comments
comment|/// describing the encoding.  Desc is a string saying what the encoding is
comment|/// specifying (e.g. "LSDA").
name|void
name|EmitEncodingByte
argument_list|(
argument|unsigned Val
argument_list|,
argument|const char *Desc =
literal|0
argument_list|)
specifier|const
block|;
comment|/// GetSizeOfEncodedValue - Return the size of the encoding in bytes.
name|unsigned
name|GetSizeOfEncodedValue
argument_list|(
argument|unsigned Encoding
argument_list|)
specifier|const
block|;
comment|/// EmitReference - Emit reference to a ttype global with a specified encoding.
name|void
name|EmitTTypeReference
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|unsigned Encoding
argument_list|)
specifier|const
block|;
comment|/// EmitSectionOffset - Emit the 4-byte offset of Label from the start of
comment|/// its section.  This can be done with a special directive if the target
comment|/// supports it (e.g. cygwin) or by emitting it as an offset from a label at
comment|/// the start of the section.
comment|///
comment|/// SectionLabel is a temporary label emitted at the start of the section
comment|/// that Label lives in.
name|void
name|EmitSectionOffset
argument_list|(
argument|const MCSymbol *Label
argument_list|,
argument|const MCSymbol *SectionLabel
argument_list|)
specifier|const
block|;
comment|/// getISAEncoding - Get the value for DW_AT_APPLE_isa. Zero if no isa
comment|/// encoding specified.
name|virtual
name|unsigned
name|getISAEncoding
argument_list|()
block|{
return|return
literal|0
return|;
block|}
comment|/// EmitDwarfRegOp - Emit dwarf register operation.
name|virtual
name|void
name|EmitDwarfRegOp
argument_list|(
argument|const MachineLocation&MLoc
argument_list|,
argument|bool Indirect
argument_list|)
specifier|const
block|;
comment|//===------------------------------------------------------------------===//
comment|// Dwarf Lowering Routines
comment|//===------------------------------------------------------------------===//
comment|/// \brief Emit frame instruction to describe the layout of the frame.
name|void
name|emitCFIInstruction
argument_list|(
argument|const MCCFIInstruction&Inst
argument_list|)
specifier|const
block|;
comment|//===------------------------------------------------------------------===//
comment|// Inline Asm Support
comment|//===------------------------------------------------------------------===//
name|public
operator|:
comment|// These are hooks that targets can override to implement inline asm
comment|// support.  These should probably be moved out of AsmPrinter someday.
comment|/// PrintSpecial - Print information related to the specified machine instr
comment|/// that is independent of the operand, and may be independent of the instr
comment|/// itself.  This can be useful for portably encoding the comment character
comment|/// or other bits of target-specific knowledge into the asmstrings.  The
comment|/// syntax used is ${:comment}.  Targets can override this to add support
comment|/// for their own strange codes.
name|virtual
name|void
name|PrintSpecial
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|raw_ostream&OS
argument_list|,
argument|const char *Code
argument_list|)
specifier|const
block|;
comment|/// PrintAsmOperand - Print the specified operand of MI, an INLINEASM
comment|/// instruction, using the specified assembler variant.  Targets should
comment|/// override this to format as appropriate.  This method can return true if
comment|/// the operand is erroneous.
name|virtual
name|bool
name|PrintAsmOperand
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|unsigned AsmVariant
argument_list|,
argument|const char *ExtraCode
argument_list|,
argument|raw_ostream&OS
argument_list|)
block|;
comment|/// PrintAsmMemoryOperand - Print the specified operand of MI, an INLINEASM
comment|/// instruction, using the specified assembler variant as an address.
comment|/// Targets should override this to format as appropriate.  This method can
comment|/// return true if the operand is erroneous.
name|virtual
name|bool
name|PrintAsmMemoryOperand
argument_list|(
argument|const MachineInstr *MI
argument_list|,
argument|unsigned OpNo
argument_list|,
argument|unsigned AsmVariant
argument_list|,
argument|const char *ExtraCode
argument_list|,
argument|raw_ostream&OS
argument_list|)
block|;
name|private
operator|:
comment|/// Private state for PrintSpecial()
comment|// Assign a unique ID to this machine instruction.
name|mutable
specifier|const
name|MachineInstr
operator|*
name|LastMI
block|;
name|mutable
name|unsigned
name|LastFn
block|;
name|mutable
name|unsigned
name|Counter
block|;
name|mutable
name|unsigned
name|SetCounter
block|;
comment|/// EmitInlineAsm - Emit a blob of inline asm to the output streamer.
name|void
name|EmitInlineAsm
argument_list|(
argument|StringRef Str
argument_list|,
argument|const MDNode *LocMDNode =
literal|0
argument_list|,
argument|InlineAsm::AsmDialect AsmDialect =                            InlineAsm::AD_ATT
argument_list|)
specifier|const
block|;
comment|/// EmitInlineAsm - This method formats and emits the specified machine
comment|/// instruction that is an inline asm.
name|void
name|EmitInlineAsm
argument_list|(
argument|const MachineInstr *MI
argument_list|)
specifier|const
block|;
comment|//===------------------------------------------------------------------===//
comment|// Internal Implementation Details
comment|//===------------------------------------------------------------------===//
comment|/// EmitVisibility - This emits visibility information about symbol, if
comment|/// this is suported by the target.
name|void
name|EmitVisibility
argument_list|(
argument|MCSymbol *Sym
argument_list|,
argument|unsigned Visibility
argument_list|,
argument|bool IsDefinition = true
argument_list|)
specifier|const
block|;
name|void
name|EmitLinkage
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|MCSymbol *GVSym
argument_list|)
specifier|const
block|;
name|void
name|EmitJumpTableEntry
argument_list|(
argument|const MachineJumpTableInfo *MJTI
argument_list|,
argument|const MachineBasicBlock *MBB
argument_list|,
argument|unsigned uid
argument_list|)
specifier|const
block|;
name|void
name|EmitLLVMUsedList
argument_list|(
specifier|const
name|ConstantArray
operator|*
name|InitList
argument_list|)
block|;
comment|/// Emit llvm.ident metadata in an '.ident' directive.
name|void
name|EmitModuleIdents
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
name|void
name|EmitXXStructorList
argument_list|(
argument|const Constant *List
argument_list|,
argument|bool isCtor
argument_list|)
block|;
name|GCMetadataPrinter
operator|*
name|GetOrCreateGCPrinter
argument_list|(
name|GCStrategy
operator|*
name|C
argument_list|)
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

