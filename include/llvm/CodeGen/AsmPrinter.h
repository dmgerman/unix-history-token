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
file|"llvm/Support/DebugLoc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
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
name|ConstantFP
decl_stmt|;
name|class
name|ConstantInt
decl_stmt|;
name|class
name|ConstantStruct
decl_stmt|;
name|class
name|ConstantVector
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
name|MachineLoopInfo
decl_stmt|;
name|class
name|MachineLoop
decl_stmt|;
name|class
name|MachineConstantPool
decl_stmt|;
name|class
name|MachineConstantPoolEntry
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
name|MCInst
decl_stmt|;
name|class
name|MCContext
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
name|DwarfWriter
decl_stmt|;
name|class
name|Mangler
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|TargetLoweringObjectFile
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|formatted_raw_ostream
decl_stmt|;
comment|/// AsmPrinter - This class is intended to be used as a driving class for all
comment|/// asm writers.
name|class
name|AsmPrinter
range|:
name|public
name|MachineFunctionPass
block|{
specifier|static
name|char
name|ID
block|;
comment|/// FunctionNumber - This provides a unique ID for each function emitted in
comment|/// this translation unit.  It is autoincremented by SetupMachineFunction,
comment|/// and can be accessed with getFunctionNumber() and
comment|/// IncrementFunctionNumber().
comment|///
name|unsigned
name|FunctionNumber
block|;
comment|// GCMetadataPrinters - The garbage collection metadata printer table.
typedef|typedef
name|DenseMap
operator|<
name|GCStrategy
operator|*
operator|,
name|GCMetadataPrinter
operator|*
operator|>
name|gcp_map_type
expr_stmt|;
typedef|typedef
name|gcp_map_type
operator|::
name|iterator
name|gcp_iterator
expr_stmt|;
name|gcp_map_type
name|GCMetadataPrinters
decl_stmt|;
comment|/// If VerboseAsm is set, a pointer to the loop info for this
comment|/// function.
comment|///
name|MachineLoopInfo
modifier|*
name|LI
decl_stmt|;
name|public
label|:
comment|/// MMI - If available, this is a pointer to the current MachineModuleInfo.
name|MachineModuleInfo
modifier|*
name|MMI
decl_stmt|;
name|protected
label|:
comment|/// DW - If available, this is a pointer to the current dwarf writer.
name|DwarfWriter
modifier|*
name|DW
decl_stmt|;
name|public
label|:
comment|/// Output stream on which we're printing assembly code.
comment|///
name|formatted_raw_ostream
modifier|&
name|O
decl_stmt|;
comment|/// Target machine description.
comment|///
name|TargetMachine
modifier|&
name|TM
decl_stmt|;
comment|/// getObjFileLowering - Return information about object file lowering.
name|TargetLoweringObjectFile
operator|&
name|getObjFileLowering
argument_list|()
specifier|const
expr_stmt|;
comment|/// Target Asm Printer information.
comment|///
specifier|const
name|MCAsmInfo
modifier|*
name|MAI
decl_stmt|;
comment|/// Target Register Information.
comment|///
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
decl_stmt|;
comment|/// OutContext - This is the context for the output file that we are
comment|/// streaming.  This owns all of the global MC-related objects for the
comment|/// generated translation unit.
name|MCContext
modifier|&
name|OutContext
decl_stmt|;
comment|/// OutStreamer - This is the MCStreamer object for the file we are
comment|/// generating.  This contains the transient state for the current
comment|/// translation unit that we are generating (such as the current section
comment|/// etc).
name|MCStreamer
modifier|&
name|OutStreamer
decl_stmt|;
comment|/// The current machine function.
specifier|const
name|MachineFunction
modifier|*
name|MF
decl_stmt|;
comment|/// Name-mangler for global names.
comment|///
name|Mangler
modifier|*
name|Mang
decl_stmt|;
comment|/// Cache of mangled name for current function. This is recalculated at the
comment|/// beginning of each call to runOnMachineFunction().
comment|///
name|std
operator|::
name|string
name|CurrentFnName
expr_stmt|;
comment|/// getCurrentSection() - Return the current section we are emitting to.
specifier|const
name|MCSection
operator|*
name|getCurrentSection
argument_list|()
specifier|const
expr_stmt|;
comment|/// VerboseAsm - Emit comments in assembly output if this is true.
comment|///
name|bool
name|VerboseAsm
decl_stmt|;
comment|/// Private state for PrintSpecial()
comment|// Assign a unique ID to this machine instruction.
name|mutable
specifier|const
name|MachineInstr
modifier|*
name|LastMI
decl_stmt|;
name|mutable
specifier|const
name|Function
modifier|*
name|LastFn
decl_stmt|;
name|mutable
name|unsigned
name|Counter
decl_stmt|;
comment|// Private state for processDebugLoc()
name|mutable
name|DebugLocTuple
name|PrevDLT
decl_stmt|;
name|protected
label|:
name|explicit
name|AsmPrinter
parameter_list|(
name|formatted_raw_ostream
modifier|&
name|o
parameter_list|,
name|TargetMachine
modifier|&
name|TM
parameter_list|,
specifier|const
name|MCAsmInfo
modifier|*
name|T
parameter_list|,
name|bool
name|V
parameter_list|)
function_decl|;
name|public
label|:
name|virtual
operator|~
name|AsmPrinter
argument_list|()
expr_stmt|;
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
block|{
return|return
name|FunctionNumber
return|;
block|}
name|protected
label|:
comment|/// getAnalysisUsage - Record analysis usage.
comment|///
name|void
name|getAnalysisUsage
argument_list|(
name|AnalysisUsage
operator|&
name|AU
argument_list|)
decl|const
decl_stmt|;
comment|/// doInitialization - Set up the AsmPrinter when we are working on a new
comment|/// module.  If your pass overrides this, it must make sure to explicitly
comment|/// call this implementation.
name|bool
name|doInitialization
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|)
function_decl|;
comment|/// EmitStartOfAsmFile - This virtual method can be overridden by targets
comment|/// that want to emit something at the start of their file.
name|virtual
name|void
name|EmitStartOfAsmFile
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|)
block|{}
comment|/// EmitEndOfAsmFile - This virtual method can be overridden by targets that
comment|/// want to emit something at the end of their file.
name|virtual
name|void
name|EmitEndOfAsmFile
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|)
block|{}
comment|/// doFinalization - Shut down the asmprinter.  If you override this in your
comment|/// pass, you must make sure to call it explicitly.
name|bool
name|doFinalization
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|)
function_decl|;
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
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
specifier|const
name|char
operator|*
name|Code
argument_list|)
decl|const
decl_stmt|;
comment|/// PrintAsmOperand - Print the specified operand of MI, an INLINEASM
comment|/// instruction, using the specified assembler variant.  Targets should
comment|/// override this to format as appropriate.  This method can return true if
comment|/// the operand is erroneous.
name|virtual
name|bool
name|PrintAsmOperand
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|,
name|unsigned
name|OpNo
parameter_list|,
name|unsigned
name|AsmVariant
parameter_list|,
specifier|const
name|char
modifier|*
name|ExtraCode
parameter_list|)
function_decl|;
comment|/// PrintAsmMemoryOperand - Print the specified operand of MI, an INLINEASM
comment|/// instruction, using the specified assembler variant as an address.
comment|/// Targets should override this to format as appropriate.  This method can
comment|/// return true if the operand is erroneous.
name|virtual
name|bool
name|PrintAsmMemoryOperand
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|,
name|unsigned
name|OpNo
parameter_list|,
name|unsigned
name|AsmVariant
parameter_list|,
specifier|const
name|char
modifier|*
name|ExtraCode
parameter_list|)
function_decl|;
comment|/// PrintGlobalVariable - Emit the specified global variable and its
comment|/// initializer to the output stream.
name|virtual
name|void
name|PrintGlobalVariable
parameter_list|(
specifier|const
name|GlobalVariable
modifier|*
name|GV
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// SetupMachineFunction - This should be called when a new MachineFunction
comment|/// is being processed from runOnMachineFunction.
name|void
name|SetupMachineFunction
parameter_list|(
name|MachineFunction
modifier|&
name|MF
parameter_list|)
function_decl|;
comment|/// IncrementFunctionNumber - Increase Function Number.  AsmPrinters should
comment|/// not normally call this, as the counter is automatically bumped by
comment|/// SetupMachineFunction.
name|void
name|IncrementFunctionNumber
parameter_list|()
block|{
name|FunctionNumber
operator|++
expr_stmt|;
block|}
comment|/// EmitConstantPool - Print to the current output stream assembly
comment|/// representations of the constants in the constant pool MCP. This is
comment|/// used to print out constants which have been "spilled to memory" by
comment|/// the code generator.
comment|///
name|void
name|EmitConstantPool
parameter_list|(
name|MachineConstantPool
modifier|*
name|MCP
parameter_list|)
function_decl|;
comment|/// EmitJumpTableInfo - Print assembly representations of the jump tables
comment|/// used by the current function to the current output stream.
comment|///
name|void
name|EmitJumpTableInfo
parameter_list|(
name|MachineJumpTableInfo
modifier|*
name|MJTI
parameter_list|,
name|MachineFunction
modifier|&
name|MF
parameter_list|)
function_decl|;
comment|/// EmitSpecialLLVMGlobal - Check to see if the specified global is a
comment|/// special global used by LLVM.  If so, emit it and return true, otherwise
comment|/// do nothing and return false.
name|bool
name|EmitSpecialLLVMGlobal
parameter_list|(
specifier|const
name|GlobalVariable
modifier|*
name|GV
parameter_list|)
function_decl|;
name|public
label|:
comment|//===------------------------------------------------------------------===//
comment|/// LEB 128 number encoding.
comment|/// PrintULEB128 - Print a series of hexidecimal values(separated by commas)
comment|/// representing an unsigned leb128 value.
name|void
name|PrintULEB128
argument_list|(
name|unsigned
name|Value
argument_list|)
decl|const
decl_stmt|;
comment|/// PrintSLEB128 - Print a series of hexidecimal values(separated by commas)
comment|/// representing a signed leb128 value.
name|void
name|PrintSLEB128
argument_list|(
name|int
name|Value
argument_list|)
decl|const
decl_stmt|;
comment|//===------------------------------------------------------------------===//
comment|// Emission and print routines
comment|//
comment|/// PrintHex - Print a value as a hexidecimal value.
comment|///
name|void
name|PrintHex
argument_list|(
name|int
name|Value
argument_list|)
decl|const
decl_stmt|;
comment|/// EOL - Print a newline character to asm stream.  If a comment is present
comment|/// then it will be printed first.  Comments should not contain '\n'.
name|void
name|EOL
argument_list|()
specifier|const
expr_stmt|;
name|void
name|EOL
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Comment
argument_list|)
decl|const
decl_stmt|;
name|void
name|EOL
argument_list|(
specifier|const
name|char
operator|*
name|Comment
argument_list|)
decl|const
decl_stmt|;
name|void
name|EOL
argument_list|(
specifier|const
name|char
operator|*
name|Comment
argument_list|,
name|unsigned
name|Encoding
argument_list|)
decl|const
decl_stmt|;
comment|/// EmitULEB128Bytes - Emit an assembler byte data directive to compose an
comment|/// unsigned leb128 value.
name|void
name|EmitULEB128Bytes
argument_list|(
name|unsigned
name|Value
argument_list|)
decl|const
decl_stmt|;
comment|/// EmitSLEB128Bytes - print an assembler byte data directive to compose a
comment|/// signed leb128 value.
name|void
name|EmitSLEB128Bytes
argument_list|(
name|int
name|Value
argument_list|)
decl|const
decl_stmt|;
comment|/// EmitInt8 - Emit a byte directive and value.
comment|///
name|void
name|EmitInt8
argument_list|(
name|int
name|Value
argument_list|)
decl|const
decl_stmt|;
comment|/// EmitInt16 - Emit a short directive and value.
comment|///
name|void
name|EmitInt16
argument_list|(
name|int
name|Value
argument_list|)
decl|const
decl_stmt|;
comment|/// EmitInt32 - Emit a long directive and value.
comment|///
name|void
name|EmitInt32
argument_list|(
name|int
name|Value
argument_list|)
decl|const
decl_stmt|;
comment|/// EmitInt64 - Emit a long long directive and value.
comment|///
name|void
name|EmitInt64
argument_list|(
name|uint64_t
name|Value
argument_list|)
decl|const
decl_stmt|;
comment|/// EmitString - Emit a string with quotes and a null terminator.
comment|/// Special characters are emitted properly.
comment|/// @verbatim (Eg. '\t') @endverbatim
name|void
name|EmitString
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|String
argument_list|)
decl|const
decl_stmt|;
name|void
name|EmitString
argument_list|(
specifier|const
name|char
operator|*
name|String
argument_list|,
name|unsigned
name|Size
argument_list|)
decl|const
decl_stmt|;
comment|/// EmitFile - Emit a .file directive.
name|void
name|EmitFile
argument_list|(
name|unsigned
name|Number
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|//===------------------------------------------------------------------===//
comment|/// EmitAlignment - Emit an alignment directive to the specified power of
comment|/// two boundary.  For example, if you pass in 3 here, you will get an 8
comment|/// byte alignment.  If a global value is specified, and if that global has
comment|/// an explicit alignment requested, it will unconditionally override the
comment|/// alignment request.  However, if ForcedAlignBits is specified, this value
comment|/// has final say: the ultimate alignment will be the max of ForcedAlignBits
comment|/// and the alignment computed with NumBits and the global.  If UseFillExpr
comment|/// is true, it also emits an optional second value FillValue which the
comment|/// assembler uses to fill gaps to match alignment for text sections if the
comment|/// has specified a non-zero fill value.
comment|///
comment|/// The algorithm is:
comment|///     Align = NumBits;
comment|///     if (GV&& GV->hasalignment) Align = GV->getalignment();
comment|///     Align = std::max(Align, ForcedAlignBits);
comment|///
name|void
name|EmitAlignment
argument_list|(
name|unsigned
name|NumBits
argument_list|,
specifier|const
name|GlobalValue
operator|*
name|GV
operator|=
literal|0
argument_list|,
name|unsigned
name|ForcedAlignBits
operator|=
literal|0
argument_list|,
name|bool
name|UseFillExpr
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
comment|/// printLabel - This method prints a local label used by debug and
comment|/// exception handling tables.
name|void
name|printLabel
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
decl|const
decl_stmt|;
name|void
name|printLabel
argument_list|(
name|unsigned
name|Id
argument_list|)
decl|const
decl_stmt|;
comment|/// printDeclare - This method prints a local variable declaration used by
comment|/// debug tables.
name|void
name|printDeclare
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
decl|const
decl_stmt|;
comment|/// EmitComments - Pretty-print comments for instructions
name|void
name|EmitComments
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|)
decl|const
decl_stmt|;
comment|/// EmitComments - Pretty-print comments for basic blocks
name|void
name|EmitComments
argument_list|(
specifier|const
name|MachineBasicBlock
operator|&
name|MBB
argument_list|)
decl|const
decl_stmt|;
comment|/// GetMBBSymbol - Return the MCSymbol corresponding to the specified basic
comment|/// block label.
name|MCSymbol
modifier|*
name|GetMBBSymbol
argument_list|(
name|unsigned
name|MBBID
argument_list|)
decl|const
decl_stmt|;
comment|/// EmitBasicBlockStart - This method prints the label for the specified
comment|/// MachineBasicBlock, an alignment (if present) and a comment describing
comment|/// it if appropriate.
name|void
name|EmitBasicBlockStart
argument_list|(
specifier|const
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
comment|/// EmitZeros - Emit a block of zeros.
comment|///
name|void
name|EmitZeros
argument_list|(
name|uint64_t
name|NumZeros
argument_list|,
name|unsigned
name|AddrSpace
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// EmitString - Emit a zero-byte-terminated string constant.
comment|///
name|virtual
name|void
name|EmitString
argument_list|(
specifier|const
name|ConstantArray
operator|*
name|CVA
argument_list|)
decl|const
decl_stmt|;
comment|/// EmitConstantValueOnly - Print out the specified constant, without a
comment|/// storage class.  Only constants of first-class type are allowed here.
name|void
name|EmitConstantValueOnly
parameter_list|(
specifier|const
name|Constant
modifier|*
name|CV
parameter_list|)
function_decl|;
comment|/// EmitGlobalConstant - Print a general LLVM constant to the .s file.
name|void
name|EmitGlobalConstant
parameter_list|(
specifier|const
name|Constant
modifier|*
name|CV
parameter_list|,
name|unsigned
name|AddrSpace
init|=
literal|0
parameter_list|)
function_decl|;
name|virtual
name|void
name|EmitMachineConstantPoolValue
parameter_list|(
name|MachineConstantPoolValue
modifier|*
name|MCPV
parameter_list|)
function_decl|;
comment|/// processDebugLoc - Processes the debug information of each machine
comment|/// instruction's DebugLoc.
name|void
name|processDebugLoc
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
name|MI
parameter_list|,
name|bool
name|BeforePrintingInsn
parameter_list|)
function_decl|;
comment|/// printInlineAsm - This method formats and prints the specified machine
comment|/// instruction that is an inline asm.
name|void
name|printInlineAsm
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
decl|const
decl_stmt|;
comment|/// printImplicitDef - This method prints the specified machine instruction
comment|/// that is an implicit def.
name|virtual
name|void
name|printImplicitDef
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
decl|const
decl_stmt|;
comment|/// printPICJumpTableSetLabel - This method prints a set label for the
comment|/// specified MachineBasicBlock for a jumptable entry.
name|virtual
name|void
name|printPICJumpTableSetLabel
argument_list|(
name|unsigned
name|uid
argument_list|,
specifier|const
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|void
name|printPICJumpTableSetLabel
argument_list|(
name|unsigned
name|uid
argument_list|,
name|unsigned
name|uid2
argument_list|,
specifier|const
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|void
name|printPICJumpTableEntry
argument_list|(
specifier|const
name|MachineJumpTableInfo
operator|*
name|MJTI
argument_list|,
specifier|const
name|MachineBasicBlock
operator|*
name|MBB
argument_list|,
name|unsigned
name|uid
argument_list|)
decl|const
decl_stmt|;
comment|/// printDataDirective - This method prints the asm directive for the
comment|/// specified type.
name|void
name|printDataDirective
parameter_list|(
specifier|const
name|Type
modifier|*
name|type
parameter_list|,
name|unsigned
name|AddrSpace
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// printVisibility - This prints visibility information about symbol, if
comment|/// this is suported by the target.
name|void
name|printVisibility
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|,
name|unsigned
name|Visibility
argument_list|)
decl|const
decl_stmt|;
comment|/// printOffset - This is just convenient handler for printing offsets.
name|void
name|printOffset
argument_list|(
name|int64_t
name|Offset
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|void
name|EmitLLVMUsedList
parameter_list|(
name|Constant
modifier|*
name|List
parameter_list|)
function_decl|;
name|void
name|EmitXXStructorList
parameter_list|(
name|Constant
modifier|*
name|List
parameter_list|)
function_decl|;
name|void
name|EmitGlobalConstantStruct
parameter_list|(
specifier|const
name|ConstantStruct
modifier|*
name|CVS
parameter_list|,
name|unsigned
name|AddrSpace
parameter_list|)
function_decl|;
name|void
name|EmitGlobalConstantArray
parameter_list|(
specifier|const
name|ConstantArray
modifier|*
name|CVA
parameter_list|,
name|unsigned
name|AddrSpace
parameter_list|)
function_decl|;
name|void
name|EmitGlobalConstantVector
parameter_list|(
specifier|const
name|ConstantVector
modifier|*
name|CP
parameter_list|)
function_decl|;
name|void
name|EmitGlobalConstantFP
parameter_list|(
specifier|const
name|ConstantFP
modifier|*
name|CFP
parameter_list|,
name|unsigned
name|AddrSpace
parameter_list|)
function_decl|;
name|void
name|EmitGlobalConstantLargeInt
parameter_list|(
specifier|const
name|ConstantInt
modifier|*
name|CI
parameter_list|,
name|unsigned
name|AddrSpace
parameter_list|)
function_decl|;
name|GCMetadataPrinter
modifier|*
name|GetOrCreateGCPrinter
parameter_list|(
name|GCStrategy
modifier|*
name|C
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

