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
file|"llvm/ADT/Twine.h"
end_include

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
name|AsmPrinterHandler
decl_stmt|;
name|class
name|BlockAddress
decl_stmt|;
name|class
name|ByteStreamer
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
name|MCInst
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
name|MCSubtargetInfo
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
comment|/// This class is intended to be used as a driving class for all asm writers.
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
comment|/// This is the context for the output file that we are streaming. This owns
comment|/// all of the global MC-related objects for the generated translation unit.
name|MCContext
operator|&
name|OutContext
block|;
comment|/// This is the MCStreamer object for the file we are generating. This
comment|/// contains the transient state for the current translation unit that we are
comment|/// generating (such as the current section etc).
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
comment|/// This is a pointer to the current MachineModuleInfo.
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
comment|/// The symbol for the current function. This is recalculated at the beginning
comment|/// of each call to runOnMachineFunction().
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
comment|// The garbage collection metadata printer table.
name|void
operator|*
name|GCMetadataPrinters
block|;
comment|// Really a DenseMap.
comment|/// Emit comments in assembly output if this is true.
comment|///
name|bool
name|VerboseAsm
block|;
specifier|static
name|char
name|ID
block|;
comment|/// If VerboseAsm is set, a pointer to the loop info for this function.
name|MachineLoopInfo
operator|*
name|LI
block|;    struct
name|HandlerInfo
block|{
name|AsmPrinterHandler
operator|*
name|Handler
block|;
specifier|const
name|char
operator|*
name|TimerName
block|,
operator|*
name|TimerGroupName
block|;
name|HandlerInfo
argument_list|(
name|AsmPrinterHandler
operator|*
name|Handler
argument_list|,
specifier|const
name|char
operator|*
name|TimerName
argument_list|,
specifier|const
name|char
operator|*
name|TimerGroupName
argument_list|)
operator|:
name|Handler
argument_list|(
name|Handler
argument_list|)
block|,
name|TimerName
argument_list|(
name|TimerName
argument_list|)
block|,
name|TimerGroupName
argument_list|(
argument|TimerGroupName
argument_list|)
block|{}
block|}
block|;
comment|/// A vector of all debug/EH info emitters we should use. This vector
comment|/// maintains ownership of the emitters.
name|SmallVector
operator|<
name|HandlerInfo
block|,
literal|1
operator|>
name|Handlers
block|;
comment|/// If the target supports dwarf debug info, this pointer is non-null.
name|DwarfDebug
operator|*
name|DD
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
name|DwarfDebug
operator|*
name|getDwarfDebug
argument_list|()
block|{
return|return
name|DD
return|;
block|}
comment|/// Return true if assembly output should contain comments.
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
comment|/// Return a unique ID for the current function.
comment|///
name|unsigned
name|getFunctionNumber
argument_list|()
specifier|const
block|;
comment|/// Return information about object file lowering.
specifier|const
name|TargetLoweringObjectFile
operator|&
name|getObjFileLowering
argument_list|()
specifier|const
block|;
comment|/// Return information about data layout.
specifier|const
name|DataLayout
operator|&
name|getDataLayout
argument_list|()
specifier|const
block|;
comment|/// Return information about subtarget.
specifier|const
name|MCSubtargetInfo
operator|&
name|getSubtargetInfo
argument_list|()
specifier|const
block|;
name|void
name|EmitToStreamer
argument_list|(
name|MCStreamer
operator|&
name|S
argument_list|,
specifier|const
name|MCInst
operator|&
name|Inst
argument_list|)
block|;
comment|/// Return the target triple string.
name|StringRef
name|getTargetTriple
argument_list|()
specifier|const
block|;
comment|/// Return the current section we are emitting to.
specifier|const
name|MCSection
operator|*
name|getCurrentSection
argument_list|()
specifier|const
block|;
name|void
name|getNameWithPrefix
argument_list|(
argument|SmallVectorImpl<char>&Name
argument_list|,
argument|const GlobalValue *GV
argument_list|)
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
comment|/// Record analysis usage.
comment|///
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|;
comment|/// Set up the AsmPrinter when we are working on a new module. If your pass
comment|/// overrides this, it must make sure to explicitly call this implementation.
name|bool
name|doInitialization
argument_list|(
argument|Module&M
argument_list|)
name|override
block|;
comment|/// Shut down the asmprinter. If you override this in your pass, you must make
comment|/// sure to call it explicitly.
name|bool
name|doFinalization
argument_list|(
argument|Module&M
argument_list|)
name|override
block|;
comment|/// Emit the specified function out to the OutStreamer.
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&MF
argument_list|)
name|override
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
comment|/// This should be called when a new MachineFunction is being processed from
comment|/// runOnMachineFunction.
name|void
name|SetupMachineFunction
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
block|;
comment|/// This method emits the header for the current function.
name|void
name|EmitFunctionHeader
argument_list|()
block|;
comment|/// This method emits the body and trailer for a function.
name|void
name|EmitFunctionBody
argument_list|()
block|;
name|void
name|emitCFIInstruction
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|)
block|;    enum
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
comment|/// Print to the current output stream assembly representations of the
comment|/// constants in the constant pool MCP. This is used to print out constants
comment|/// which have been "spilled to memory" by the code generator.
comment|///
name|virtual
name|void
name|EmitConstantPool
argument_list|()
block|;
comment|/// Print assembly representations of the jump tables used by the current
comment|/// function to the current output stream.
comment|///
name|void
name|EmitJumpTableInfo
argument_list|()
block|;
comment|/// Emit the specified global variable to the .s file.
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
comment|/// Check to see if the specified global is a special global used by LLVM. If
comment|/// so, emit it and return true, otherwise do nothing and return false.
name|bool
name|EmitSpecialLLVMGlobal
argument_list|(
specifier|const
name|GlobalVariable
operator|*
name|GV
argument_list|)
block|;
comment|/// Emit an alignment directive to the specified power of two boundary. For
comment|/// example, if you pass in 3 here, you will get an 8 byte alignment. If a
comment|/// global value is specified, and if that global has an explicit alignment
comment|/// requested, it will override the alignment request if required for
comment|/// correctness.
comment|///
name|void
name|EmitAlignment
argument_list|(
argument|unsigned NumBits
argument_list|,
argument|const GlobalObject *GO = nullptr
argument_list|)
specifier|const
block|;
comment|/// This method prints the label for the specified MachineBasicBlock, an
comment|/// alignment (if present) and a comment describing it if appropriate.
name|void
name|EmitBasicBlockStart
argument_list|(
argument|const MachineBasicBlock&MBB
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
comment|/// This virtual method can be overridden by targets that want to emit
comment|/// something at the start of their file.
name|virtual
name|void
name|EmitStartOfAsmFile
argument_list|(
argument|Module&
argument_list|)
block|{}
comment|/// This virtual method can be overridden by targets that want to emit
comment|/// something at the end of their file.
name|virtual
name|void
name|EmitEndOfAsmFile
argument_list|(
argument|Module&
argument_list|)
block|{}
comment|/// Targets can override this to emit stuff before the first basic block in
comment|/// the function.
name|virtual
name|void
name|EmitFunctionBodyStart
argument_list|()
block|{}
comment|/// Targets can override this to emit stuff after the last basic block in the
comment|/// function.
name|virtual
name|void
name|EmitFunctionBodyEnd
argument_list|()
block|{}
comment|/// Targets should implement this to emit instructions.
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
block|;   }
comment|/// Return the symbol for the specified constant pool entry.
name|virtual
name|MCSymbol
operator|*
name|GetCPISymbol
argument_list|(
argument|unsigned CPID
argument_list|)
specifier|const
block|;
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
comment|/// Targets can override this to change how global constants that are part of
comment|/// a C++ static/global constructor list are emitted.
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
block|; }
comment|/// Return true if the basic block has exactly one predecessor and the control
comment|/// transfer mechanism between the predecessor and this block is a
comment|/// fall-through.
name|virtual
name|bool
name|isBlockOnlyReachableByFallthrough
argument_list|(
argument|const MachineBasicBlock *MBB
argument_list|)
specifier|const
block|;
comment|/// Targets can override this to customize the output of IMPLICIT_DEF
comment|/// instructions in verbose mode.
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
comment|/// Return the MCSymbol corresponding to the assembler temporary label with
comment|/// the specified stem and unique ID.
name|MCSymbol
operator|*
name|GetTempSymbol
argument_list|(
argument|Twine Name
argument_list|,
argument|unsigned ID
argument_list|)
specifier|const
block|;
comment|/// Return an assembler temporary label with the specified stem.
name|MCSymbol
operator|*
name|GetTempSymbol
argument_list|(
argument|Twine Name
argument_list|)
specifier|const
block|;
comment|/// Return the MCSymbol for a private symbol with global value name as its
comment|/// base, with the specified suffix.
name|MCSymbol
operator|*
name|getSymbolWithGlobalValueBase
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|StringRef Suffix
argument_list|)
specifier|const
block|;
comment|/// Return the MCSymbol for the specified ExternalSymbol.
name|MCSymbol
operator|*
name|GetExternalSymbolSymbol
argument_list|(
argument|StringRef Sym
argument_list|)
specifier|const
block|;
comment|/// Return the symbol for the specified jump table entry.
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
comment|/// Return the symbol for the specified jump table .set
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
comment|/// Return the MCSymbol used to satisfy BlockAddress uses of the specified
comment|/// basic block.
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
comment|/// This is just convenient handler for printing offsets.
name|void
name|printOffset
argument_list|(
argument|int64_t Offset
argument_list|,
argument|raw_ostream&OS
argument_list|)
specifier|const
block|;
comment|/// Emit a byte directive and value.
comment|///
name|void
name|EmitInt8
argument_list|(
argument|int Value
argument_list|)
specifier|const
block|;
comment|/// Emit a short directive and value.
comment|///
name|void
name|EmitInt16
argument_list|(
argument|int Value
argument_list|)
specifier|const
block|;
comment|/// Emit a long directive and value.
comment|///
name|void
name|EmitInt32
argument_list|(
argument|int Value
argument_list|)
specifier|const
block|;
comment|/// Emit something like ".long Hi-Lo" where the size in bytes of the directive
comment|/// is specified by Size and Hi/Lo specify the labels.  This implicitly uses
comment|/// .set if it is available.
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
comment|/// Emit something like ".long Hi+Offset-Lo" where the size in bytes of the
comment|/// directive is specified by Size and Hi/Lo specify the labels.  This
comment|/// implicitly uses .set if it is available.
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
comment|/// Emit something like ".long Label+Offset" where the size in bytes of the
comment|/// directive is specified by Size and Label specifies the label.  This
comment|/// implicitly uses .set if it is available.
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
comment|/// Emit something like ".long Label" where the size in bytes of the directive
comment|/// is specified by Size and Label specifies the label.
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
block|;   }
comment|//===------------------------------------------------------------------===//
comment|// Dwarf Emission Helper Routines
comment|//===------------------------------------------------------------------===//
comment|/// Emit the specified signed leb128 value.
name|void
name|EmitSLEB128
argument_list|(
argument|int64_t Value
argument_list|,
argument|const char *Desc = nullptr
argument_list|)
specifier|const
block|;
comment|/// Emit the specified unsigned leb128 value.
name|void
name|EmitULEB128
argument_list|(
argument|uint64_t Value
argument_list|,
argument|const char *Desc = nullptr
argument_list|,
argument|unsigned PadTo =
literal|0
argument_list|)
specifier|const
block|;
comment|/// Emit a .byte 42 directive for a DW_CFA_xxx value.
name|void
name|EmitCFAByte
argument_list|(
argument|unsigned Val
argument_list|)
specifier|const
block|;
comment|/// Emit a .byte 42 directive that corresponds to an encoding.  If verbose
comment|/// assembly output is enabled, we output comments describing the encoding.
comment|/// Desc is a string saying what the encoding is specifying (e.g. "LSDA").
name|void
name|EmitEncodingByte
argument_list|(
argument|unsigned Val
argument_list|,
argument|const char *Desc = nullptr
argument_list|)
specifier|const
block|;
comment|/// Return the size of the encoding in bytes.
name|unsigned
name|GetSizeOfEncodedValue
argument_list|(
argument|unsigned Encoding
argument_list|)
specifier|const
block|;
comment|/// Emit reference to a ttype global with a specified encoding.
name|void
name|EmitTTypeReference
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|unsigned Encoding
argument_list|)
specifier|const
block|;
comment|/// Emit the 4-byte offset of Label from the start of its section.  This can
comment|/// be done with a special directive if the target supports it (e.g. cygwin)
comment|/// or by emitting it as an offset from a label at the start of the section.
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
comment|/// Get the value for DW_AT_APPLE_isa. Zero if no isa encoding specified.
name|virtual
name|unsigned
name|getISAEncoding
argument_list|()
block|{
return|return
literal|0
return|;
block|}
comment|/// \brief Emit a partial DWARF register operation.
comment|/// \param MLoc             the register
comment|/// \param PieceSize        size and
comment|/// \param PieceOffset      offset of the piece in bits, if this is one
comment|///                         piece of an aggregate value.
comment|///
comment|/// If size and offset is zero an operation for the entire
comment|/// register is emitted: Some targets do not provide a DWARF
comment|/// register number for every register.  If this is the case, this
comment|/// function will attempt to emit a DWARF register by emitting a
comment|/// piece of a super-register or by piecing together multiple
comment|/// subregisters that alias the register.
name|void
name|EmitDwarfRegOpPiece
argument_list|(
argument|ByteStreamer&BS
argument_list|,
argument|const MachineLocation&MLoc
argument_list|,
argument|unsigned PieceSize =
literal|0
argument_list|,
argument|unsigned PieceOffset =
literal|0
argument_list|)
specifier|const
block|;
comment|/// Emit dwarf register operation.
comment|/// \param Indirect   whether this is a register-indirect address
name|virtual
name|void
name|EmitDwarfRegOp
argument_list|(
argument|ByteStreamer&BS
argument_list|,
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
comment|/// Print information related to the specified machine instr that is
comment|/// independent of the operand, and may be independent of the instr itself.
comment|/// This can be useful for portably encoding the comment character or other
comment|/// bits of target-specific knowledge into the asmstrings.  The syntax used is
comment|/// ${:comment}.  Targets can override this to add support for their own
comment|/// strange codes.
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
comment|/// Print the specified operand of MI, an INLINEASM instruction, using the
comment|/// specified assembler variant.  Targets should override this to format as
comment|/// appropriate.  This method can return true if the operand is erroneous.
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
comment|/// Print the specified operand of MI, an INLINEASM instruction, using the
comment|/// specified assembler variant as an address. Targets should override this to
comment|/// format as appropriate.  This method can return true if the operand is
comment|/// erroneous.
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
comment|/// Let the target do anything it needs to do after emitting inlineasm.
comment|/// This callback can be used restore the original mode in case the
comment|/// inlineasm contains directives to switch modes.
comment|/// \p StartInfo - the original subtarget info before inline asm
comment|/// \p EndInfo   - the final subtarget info after parsing the inline asm,
comment|///                or NULL if the value is unknown.
name|virtual
name|void
name|emitInlineAsmEnd
argument_list|(
argument|const MCSubtargetInfo&StartInfo
argument_list|,
argument|const MCSubtargetInfo *EndInfo
argument_list|)
specifier|const
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
comment|/// Emit a blob of inline asm to the output streamer.
name|void
name|EmitInlineAsm
argument_list|(
argument|StringRef Str
argument_list|,
argument|const MDNode *LocMDNode = nullptr
argument_list|,
argument|InlineAsm::AsmDialect AsmDialect = InlineAsm::AD_ATT
argument_list|)
specifier|const
block|;
comment|/// This method formats and emits the specified machine instruction that is an
comment|/// inline asm.
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
comment|/// This emits visibility information about symbol, if this is suported by the
comment|/// target.
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
operator|&
name|C
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

