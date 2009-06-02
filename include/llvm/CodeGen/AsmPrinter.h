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
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|<set>
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
name|GlobalVariable
decl_stmt|;
name|class
name|MachineConstantPoolEntry
decl_stmt|;
name|class
name|MachineConstantPoolValue
decl_stmt|;
name|class
name|DwarfWriter
decl_stmt|;
name|class
name|Mangler
decl_stmt|;
name|class
name|Section
decl_stmt|;
name|class
name|TargetAsmInfo
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|raw_ostream
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
name|protected
label|:
comment|/// DW -This is needed because printDeclare() has to insert
comment|/// DbgVariable entries into the dwarf table. This is a short term hack
comment|/// that ought be fixed soon.
name|DwarfWriter
modifier|*
name|DW
decl_stmt|;
comment|// Necessary for external weak linkage support
name|std
operator|::
name|set
operator|<
specifier|const
name|GlobalValue
operator|*
operator|>
name|ExtWeakSymbols
expr_stmt|;
comment|/// OptLevel - Generating code at a specific optimization level.
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
expr_stmt|;
name|public
label|:
comment|/// Output stream on which we're printing assembly code.
comment|///
name|raw_ostream
modifier|&
name|O
decl_stmt|;
comment|/// Target machine description.
comment|///
name|TargetMachine
modifier|&
name|TM
decl_stmt|;
comment|/// Target Asm Printer information.
comment|///
specifier|const
name|TargetAsmInfo
modifier|*
name|TAI
decl_stmt|;
comment|/// Target Register Information.
comment|///
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
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
comment|/// CurrentSection - The current section we are emitting to.  This is
comment|/// controlled and used by the SwitchSection method.
name|std
operator|::
name|string
name|CurrentSection
expr_stmt|;
specifier|const
name|Section
modifier|*
name|CurrentSection_
decl_stmt|;
comment|/// IsInTextSection - True if the current section we are emitting to is a
comment|/// text section.
name|bool
name|IsInTextSection
decl_stmt|;
comment|/// VerboseAsm - Emit comments in assembly output if this is true.
comment|///
name|bool
name|VerboseAsm
decl_stmt|;
name|protected
label|:
name|explicit
name|AsmPrinter
argument_list|(
name|raw_ostream
operator|&
name|o
argument_list|,
name|TargetMachine
operator|&
name|TM
argument_list|,
specifier|const
name|TargetAsmInfo
operator|*
name|T
argument_list|,
name|CodeGenOpt
operator|::
name|Level
name|OL
argument_list|,
name|bool
name|V
argument_list|)
decl_stmt|;
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
comment|/// SwitchToTextSection - Switch to the specified section of the executable
comment|/// if we are not already in it!  If GV is non-null and if the global has an
comment|/// explicitly requested section, we switch to the section indicated for the
comment|/// global instead of NewSection.
comment|///
comment|/// If the new section is an empty string, this method forgets what the
comment|/// current section is, but does not emit a .section directive.
comment|///
comment|/// This method is used when about to emit executable code.
comment|///
name|void
name|SwitchToTextSection
parameter_list|(
specifier|const
name|char
modifier|*
name|NewSection
parameter_list|,
specifier|const
name|GlobalValue
modifier|*
name|GV
init|=
name|NULL
parameter_list|)
function_decl|;
comment|/// SwitchToDataSection - Switch to the specified section of the executable
comment|/// if we are not already in it!  If GV is non-null and if the global has an
comment|/// explicitly requested section, we switch to the section indicated for the
comment|/// global instead of NewSection.
comment|///
comment|/// If the new section is an empty string, this method forgets what the
comment|/// current section is, but does not emit a .section directive.
comment|///
comment|/// This method is used when about to emit data.  For most assemblers, this
comment|/// is the same as the SwitchToTextSection method, but not all assemblers
comment|/// are the same.
comment|///
name|void
name|SwitchToDataSection
parameter_list|(
specifier|const
name|char
modifier|*
name|NewSection
parameter_list|,
specifier|const
name|GlobalValue
modifier|*
name|GV
init|=
name|NULL
parameter_list|)
function_decl|;
comment|/// SwitchToSection - Switch to the specified section of the executable if
comment|/// we are not already in it!
name|void
name|SwitchToSection
parameter_list|(
specifier|const
name|Section
modifier|*
name|NS
parameter_list|)
function_decl|;
comment|/// getGlobalLinkName - Returns the asm/link name of of the specified
comment|/// global variable.  Should be overridden by each target asm printer to
comment|/// generate the appropriate value.
name|virtual
specifier|const
name|std
operator|::
name|string
operator|&
name|getGlobalLinkName
argument_list|(
argument|const GlobalVariable *GV
argument_list|,
argument|std::string&LinkName
argument_list|)
specifier|const
expr_stmt|;
comment|/// EmitExternalGlobal - Emit the external reference to a global variable.
comment|/// Should be overridden if an indirect reference should be used.
name|virtual
name|void
name|EmitExternalGlobal
parameter_list|(
specifier|const
name|GlobalVariable
modifier|*
name|GV
parameter_list|)
function_decl|;
comment|/// getCurrentFunctionEHName - Called to return (and cache) the
comment|/// CurrentFnEHName.
comment|///
specifier|const
name|std
operator|::
name|string
operator|&
name|getCurrentFunctionEHName
argument_list|(
argument|const MachineFunction *MF
argument_list|,
argument|std::string&FuncEHName
argument_list|)
specifier|const
expr_stmt|;
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
name|DebugLoc
name|DL
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
comment|/// printBasicBlockLabel - This method prints the label for the specified
comment|/// MachineBasicBlock
name|virtual
name|void
name|printBasicBlockLabel
argument_list|(
specifier|const
name|MachineBasicBlock
operator|*
name|MBB
argument_list|,
name|bool
name|printAlign
operator|=
name|false
argument_list|,
name|bool
name|printColon
operator|=
name|false
argument_list|,
name|bool
name|printComment
operator|=
name|true
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
comment|/// printSuffixedName - This prints a name with preceding
comment|/// getPrivateGlobalPrefix and the specified suffix, handling quoted names
comment|/// correctly.
name|void
name|printSuffixedName
parameter_list|(
specifier|const
name|char
modifier|*
name|Name
parameter_list|,
specifier|const
name|char
modifier|*
name|Suffix
parameter_list|,
specifier|const
name|char
modifier|*
name|Prefix
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|printSuffixedName
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|,
specifier|const
name|char
operator|*
name|Suffix
argument_list|)
decl_stmt|;
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
specifier|const
name|GlobalValue
modifier|*
name|findGlobalValue
parameter_list|(
specifier|const
name|Constant
modifier|*
name|CV
parameter_list|)
function_decl|;
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

