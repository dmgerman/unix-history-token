begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/CodeGen/AsmPrinter.h - AsmPrinter Framework ---------*- C++ -*-===//
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
file|"llvm/ADT/MapVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/DwarfStringPoolEntry.h"
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
file|"llvm/IR/LLVMContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/SourceMgr.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
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
name|Constant
decl_stmt|;
name|class
name|ConstantArray
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|DIE
decl_stmt|;
name|class
name|DIEAbbrev
decl_stmt|;
name|class
name|DwarfDebug
decl_stmt|;
name|class
name|GCMetadataPrinter
decl_stmt|;
name|class
name|GlobalIndirectSymbol
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|GCStrategy
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineConstantPoolValue
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineJumpTableInfo
decl_stmt|;
name|class
name|MachineLoopInfo
decl_stmt|;
name|class
name|MachineModuleInfo
decl_stmt|;
name|class
name|MachineOptimizationRemarkEmitter
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
name|MCExpr
decl_stmt|;
name|class
name|MCInst
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
name|MCTargetOptions
decl_stmt|;
name|class
name|MDNode
decl_stmt|;
name|class
name|TargetLoweringObjectFile
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
comment|/// This is the context for the output file that we are streaming. This owns
comment|/// all of the global MC-related objects for the generated translation unit.
name|MCContext
operator|&
name|OutContext
block|;
comment|/// This is the MCStreamer object for the file we are generating. This
comment|/// contains the transient state for the current translation unit that we are
comment|/// generating (such as the current section etc).
name|std
operator|::
name|unique_ptr
operator|<
name|MCStreamer
operator|>
name|OutStreamer
block|;
comment|/// The current machine function.
specifier|const
name|MachineFunction
operator|*
name|MF
operator|=
name|nullptr
block|;
comment|/// This is a pointer to the current MachineModuleInfo.
name|MachineModuleInfo
operator|*
name|MMI
operator|=
name|nullptr
block|;
comment|/// Optimization remark emitter.
name|MachineOptimizationRemarkEmitter
operator|*
name|ORE
block|;
comment|/// The symbol for the current function. This is recalculated at the beginning
comment|/// of each call to runOnMachineFunction().
comment|///
name|MCSymbol
operator|*
name|CurrentFnSym
operator|=
name|nullptr
block|;
comment|/// The symbol used to represent the start of the current function for the
comment|/// purpose of calculating its size (e.g. using the .size directive). By
comment|/// default, this is equal to CurrentFnSym.
name|MCSymbol
operator|*
name|CurrentFnSymForSize
operator|=
name|nullptr
block|;
comment|/// Map global GOT equivalent MCSymbols to GlobalVariables and keep track of
comment|/// its number of uses by other globals.
typedef|typedef
name|std
operator|::
name|pair
operator|<
specifier|const
name|GlobalVariable
operator|*
operator|,
name|unsigned
operator|>
name|GOTEquivUsePair
expr_stmt|;
name|MapVector
operator|<
specifier|const
name|MCSymbol
operator|*
block|,
name|GOTEquivUsePair
operator|>
name|GlobalGOTEquivs
decl_stmt|;
comment|/// Enable print [latency:throughput] in output
name|bool
name|EnablePrintSchedInfo
init|=
name|false
decl_stmt|;
name|private
label|:
name|MCSymbol
modifier|*
name|CurrentFnBegin
init|=
name|nullptr
decl_stmt|;
name|MCSymbol
modifier|*
name|CurrentFnEnd
init|=
name|nullptr
decl_stmt|;
name|MCSymbol
modifier|*
name|CurExceptionSym
init|=
name|nullptr
decl_stmt|;
comment|// The garbage collection metadata printer table.
name|void
modifier|*
name|GCMetadataPrinters
init|=
name|nullptr
decl_stmt|;
comment|// Really a DenseMap.
comment|/// Emit comments in assembly output if this is true.
comment|///
name|bool
name|VerboseAsm
decl_stmt|;
specifier|static
name|char
name|ID
decl_stmt|;
comment|/// If VerboseAsm is set, a pointer to the loop info for this function.
name|MachineLoopInfo
modifier|*
name|LI
init|=
name|nullptr
decl_stmt|;
struct|struct
name|HandlerInfo
block|{
name|AsmPrinterHandler
modifier|*
name|Handler
decl_stmt|;
specifier|const
name|char
modifier|*
name|TimerName
decl_stmt|;
specifier|const
name|char
modifier|*
name|TimerDescription
decl_stmt|;
specifier|const
name|char
modifier|*
name|TimerGroupName
decl_stmt|;
specifier|const
name|char
modifier|*
name|TimerGroupDescription
decl_stmt|;
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
name|TimerDescription
argument_list|,
specifier|const
name|char
operator|*
name|TimerGroupName
argument_list|,
specifier|const
name|char
operator|*
name|TimerGroupDescription
argument_list|)
operator|:
name|Handler
argument_list|(
name|Handler
argument_list|)
operator|,
name|TimerName
argument_list|(
name|TimerName
argument_list|)
operator|,
name|TimerDescription
argument_list|(
name|TimerDescription
argument_list|)
operator|,
name|TimerGroupName
argument_list|(
name|TimerGroupName
argument_list|)
operator|,
name|TimerGroupDescription
argument_list|(
argument|TimerGroupDescription
argument_list|)
block|{}
block|}
struct|;
comment|/// A vector of all debug/EH info emitters we should use. This vector
comment|/// maintains ownership of the emitters.
name|SmallVector
operator|<
name|HandlerInfo
operator|,
literal|1
operator|>
name|Handlers
expr_stmt|;
name|public
label|:
struct|struct
name|SrcMgrDiagInfo
block|{
name|SourceMgr
name|SrcMgr
decl_stmt|;
name|std
operator|::
name|vector
operator|<
specifier|const
name|MDNode
operator|*
operator|>
name|LocInfos
expr_stmt|;
name|LLVMContext
operator|::
name|InlineAsmDiagHandlerTy
name|DiagHandler
expr_stmt|;
name|void
modifier|*
name|DiagContext
decl_stmt|;
block|}
struct|;
name|private
label|:
comment|/// Structure for generating diagnostics for inline assembly. Only initialised
comment|/// when necessary.
name|mutable
name|std
operator|::
name|unique_ptr
operator|<
name|SrcMgrDiagInfo
operator|>
name|DiagInfo
expr_stmt|;
comment|/// If the target supports dwarf debug info, this pointer is non-null.
name|DwarfDebug
modifier|*
name|DD
init|=
name|nullptr
decl_stmt|;
comment|/// If the current module uses dwarf CFI annotations strictly for debugging.
name|bool
name|isCFIMoveForDebugging
init|=
name|false
decl_stmt|;
name|protected
label|:
name|explicit
name|AsmPrinter
argument_list|(
name|TargetMachine
operator|&
name|TM
argument_list|,
name|std
operator|::
name|unique_ptr
operator|<
name|MCStreamer
operator|>
name|Streamer
argument_list|)
decl_stmt|;
name|public
label|:
operator|~
name|AsmPrinter
argument_list|()
name|override
expr_stmt|;
name|DwarfDebug
modifier|*
name|getDwarfDebug
parameter_list|()
block|{
return|return
name|DD
return|;
block|}
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
name|uint16_t
name|getDwarfVersion
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setDwarfVersion
parameter_list|(
name|uint16_t
name|Version
parameter_list|)
function_decl|;
name|bool
name|isPositionIndependent
argument_list|()
specifier|const
expr_stmt|;
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
expr_stmt|;
name|MCSymbol
operator|*
name|getFunctionBegin
argument_list|()
specifier|const
block|{
return|return
name|CurrentFnBegin
return|;
block|}
name|MCSymbol
operator|*
name|getFunctionEnd
argument_list|()
specifier|const
block|{
return|return
name|CurrentFnEnd
return|;
block|}
name|MCSymbol
modifier|*
name|getCurExceptionSym
parameter_list|()
function_decl|;
comment|/// Return information about object file lowering.
specifier|const
name|TargetLoweringObjectFile
operator|&
name|getObjFileLowering
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return information about data layout.
specifier|const
name|DataLayout
operator|&
name|getDataLayout
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return the pointer size from the TargetMachine
name|unsigned
name|getPointerSize
argument_list|()
specifier|const
expr_stmt|;
comment|/// Return information about subtarget.
specifier|const
name|MCSubtargetInfo
operator|&
name|getSubtargetInfo
argument_list|()
specifier|const
expr_stmt|;
name|void
name|EmitToStreamer
parameter_list|(
name|MCStreamer
modifier|&
name|S
parameter_list|,
specifier|const
name|MCInst
modifier|&
name|Inst
parameter_list|)
function_decl|;
comment|/// Return the current section we are emitting to.
specifier|const
name|MCSection
operator|*
name|getCurrentSection
argument_list|()
specifier|const
expr_stmt|;
name|void
name|getNameWithPrefix
argument_list|(
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|Name
argument_list|,
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|)
decl|const
decl_stmt|;
name|MCSymbol
modifier|*
name|getSymbol
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|)
decl|const
decl_stmt|;
comment|//===------------------------------------------------------------------===//
comment|// XRay instrumentation implementation.
comment|//===------------------------------------------------------------------===//
name|public
label|:
comment|// This describes the kind of sled we're storing in the XRay table.
name|enum
name|class
name|SledKind
range|:
name|uint8_t
block|{
name|FUNCTION_ENTER
operator|=
literal|0
block|,
name|FUNCTION_EXIT
operator|=
literal|1
block|,
name|TAIL_CALL
operator|=
literal|2
block|,
name|LOG_ARGS_ENTER
operator|=
literal|3
block|,
name|CUSTOM_EVENT
operator|=
literal|4
block|,   }
decl_stmt|;
comment|// The table will contain these structs that point to the sled, the function
comment|// containing the sled, and what kind of sled (and whether they should always
comment|// be instrumented).
struct|struct
name|XRayFunctionEntry
block|{
specifier|const
name|MCSymbol
modifier|*
name|Sled
decl_stmt|;
specifier|const
name|MCSymbol
modifier|*
name|Function
decl_stmt|;
name|SledKind
name|Kind
decl_stmt|;
name|bool
name|AlwaysInstrument
decl_stmt|;
specifier|const
name|class
name|Function
modifier|*
name|Fn
decl_stmt|;
name|void
name|emit
argument_list|(
name|int
argument_list|,
name|MCStreamer
operator|*
argument_list|,
specifier|const
name|MCSymbol
operator|*
argument_list|)
decl|const
decl_stmt|;
block|}
struct|;
comment|// All the sleds to be emitted.
name|SmallVector
operator|<
name|XRayFunctionEntry
operator|,
literal|4
operator|>
name|Sleds
expr_stmt|;
comment|// Helper function to record a given XRay sled.
name|void
name|recordSled
parameter_list|(
name|MCSymbol
modifier|*
name|Sled
parameter_list|,
specifier|const
name|MachineInstr
modifier|&
name|MI
parameter_list|,
name|SledKind
name|Kind
parameter_list|)
function_decl|;
comment|/// Emit a table with all XRay instrumentation points.
name|void
name|emitXRayTable
parameter_list|()
function_decl|;
comment|//===------------------------------------------------------------------===//
comment|// MachineFunctionPass Implementation.
comment|//===------------------------------------------------------------------===//
comment|/// Record analysis usage.
comment|///
name|void
name|getAnalysisUsage
argument_list|(
name|AnalysisUsage
operator|&
name|AU
argument_list|)
decl|const
name|override
decl_stmt|;
comment|/// Set up the AsmPrinter when we are working on a new module. If your pass
comment|/// overrides this, it must make sure to explicitly call this implementation.
name|bool
name|doInitialization
argument_list|(
name|Module
operator|&
name|M
argument_list|)
name|override
decl_stmt|;
comment|/// Shut down the asmprinter. If you override this in your pass, you must make
comment|/// sure to call it explicitly.
name|bool
name|doFinalization
argument_list|(
name|Module
operator|&
name|M
argument_list|)
name|override
decl_stmt|;
comment|/// Emit the specified function out to the OutStreamer.
name|bool
name|runOnMachineFunction
parameter_list|(
name|MachineFunction
modifier|&
name|MF
parameter_list|)
function|override
block|{
name|SetupMachineFunction
argument_list|(
name|MF
argument_list|)
expr_stmt|;
name|EmitFunctionBody
argument_list|()
expr_stmt|;
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
parameter_list|(
name|MachineFunction
modifier|&
name|MF
parameter_list|)
function_decl|;
comment|/// This method emits the body and trailer for a function.
name|void
name|EmitFunctionBody
parameter_list|()
function_decl|;
name|void
name|emitCFIInstruction
parameter_list|(
specifier|const
name|MachineInstr
modifier|&
name|MI
parameter_list|)
function_decl|;
name|void
name|emitFrameAlloc
parameter_list|(
specifier|const
name|MachineInstr
modifier|&
name|MI
parameter_list|)
function_decl|;
enum|enum
name|CFIMoveType
block|{
name|CFI_M_None
block|,
name|CFI_M_EH
block|,
name|CFI_M_Debug
block|}
enum|;
name|CFIMoveType
name|needsCFIMoves
parameter_list|()
function_decl|;
comment|/// Returns false if needsCFIMoves() == CFI_M_EH for any function
comment|/// in the module.
name|bool
name|needsOnlyDebugCFIMoves
argument_list|()
specifier|const
block|{
return|return
name|isCFIMoveForDebugging
return|;
block|}
name|bool
name|needsSEHMoves
parameter_list|()
function_decl|;
comment|/// Print to the current output stream assembly representations of the
comment|/// constants in the constant pool MCP. This is used to print out constants
comment|/// which have been "spilled to memory" by the code generator.
comment|///
name|virtual
name|void
name|EmitConstantPool
parameter_list|()
function_decl|;
comment|/// Print assembly representations of the jump tables used by the current
comment|/// function to the current output stream.
comment|///
name|virtual
name|void
name|EmitJumpTableInfo
parameter_list|()
function_decl|;
comment|/// Emit the specified global variable to the .s file.
name|virtual
name|void
name|EmitGlobalVariable
parameter_list|(
specifier|const
name|GlobalVariable
modifier|*
name|GV
parameter_list|)
function_decl|;
comment|/// Check to see if the specified global is a special global used by LLVM. If
comment|/// so, emit it and return true, otherwise do nothing and return false.
name|bool
name|EmitSpecialLLVMGlobal
parameter_list|(
specifier|const
name|GlobalVariable
modifier|*
name|GV
parameter_list|)
function_decl|;
comment|/// Emit an alignment directive to the specified power of two boundary. For
comment|/// example, if you pass in 3 here, you will get an 8 byte alignment. If a
comment|/// global value is specified, and if that global has an explicit alignment
comment|/// requested, it will override the alignment request if required for
comment|/// correctness.
comment|///
name|void
name|EmitAlignment
argument_list|(
name|unsigned
name|NumBits
argument_list|,
specifier|const
name|GlobalObject
operator|*
name|GO
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
comment|/// Lower the specified LLVM Constant to an MCExpr.
name|virtual
specifier|const
name|MCExpr
modifier|*
name|lowerConstant
parameter_list|(
specifier|const
name|Constant
modifier|*
name|CV
parameter_list|)
function_decl|;
comment|/// \brief Print a general LLVM constant to the .s file.
name|void
name|EmitGlobalConstant
parameter_list|(
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|,
specifier|const
name|Constant
modifier|*
name|CV
parameter_list|)
function_decl|;
comment|/// \brief Unnamed constant global variables solely contaning a pointer to
comment|/// another globals variable act like a global variable "proxy", or GOT
comment|/// equivalents, i.e., it's only used to hold the address of the latter. One
comment|/// optimization is to replace accesses to these proxies by using the GOT
comment|/// entry for the final global instead. Hence, we select GOT equivalent
comment|/// candidates among all the module global variables, avoid emitting them
comment|/// unnecessarily and finally replace references to them by pc relative
comment|/// accesses to GOT entries.
name|void
name|computeGlobalGOTEquivs
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|)
function_decl|;
comment|/// \brief Constant expressions using GOT equivalent globals may not be
comment|/// eligible for PC relative GOT entry conversion, in such cases we need to
comment|/// emit the proxies we previously omitted in EmitGlobalVariable.
name|void
name|emitGlobalGOTEquivs
parameter_list|()
function_decl|;
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
parameter_list|(
name|Module
modifier|&
parameter_list|)
block|{}
comment|/// This virtual method can be overridden by targets that want to emit
comment|/// something at the end of their file.
name|virtual
name|void
name|EmitEndOfAsmFile
parameter_list|(
name|Module
modifier|&
parameter_list|)
block|{}
comment|/// Targets can override this to emit stuff before the first basic block in
comment|/// the function.
name|virtual
name|void
name|EmitFunctionBodyStart
parameter_list|()
block|{}
comment|/// Targets can override this to emit stuff after the last basic block in the
comment|/// function.
name|virtual
name|void
name|EmitFunctionBodyEnd
parameter_list|()
block|{}
comment|/// Targets can override this to emit stuff at the start of a basic block.
comment|/// By default, this method prints the label for the specified
comment|/// MachineBasicBlock, an alignment (if present) and a comment describing it
comment|/// if appropriate.
name|virtual
name|void
name|EmitBasicBlockStart
argument_list|(
specifier|const
name|MachineBasicBlock
operator|&
name|MBB
argument_list|)
decl|const
decl_stmt|;
comment|/// Targets can override this to emit stuff at the end of a basic block.
name|virtual
name|void
name|EmitBasicBlockEnd
parameter_list|(
specifier|const
name|MachineBasicBlock
modifier|&
name|MBB
parameter_list|)
block|{}
comment|/// Targets should implement this to emit instructions.
name|virtual
name|void
name|EmitInstruction
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
parameter_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"EmitInstruction not implemented"
argument_list|)
expr_stmt|;
block|}
comment|/// Return the symbol for the specified constant pool entry.
name|virtual
name|MCSymbol
modifier|*
name|GetCPISymbol
argument_list|(
name|unsigned
name|CPID
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|void
name|EmitFunctionEntryLabel
parameter_list|()
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
comment|/// Targets can override this to change how global constants that are part of
comment|/// a C++ static/global constructor list are emitted.
name|virtual
name|void
name|EmitXXStructor
parameter_list|(
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|,
specifier|const
name|Constant
modifier|*
name|CV
parameter_list|)
block|{
name|EmitGlobalConstant
argument_list|(
name|DL
argument_list|,
name|CV
argument_list|)
expr_stmt|;
block|}
comment|/// Return true if the basic block has exactly one predecessor and the control
comment|/// transfer mechanism between the predecessor and this block is a
comment|/// fall-through.
name|virtual
name|bool
name|isBlockOnlyReachableByFallthrough
argument_list|(
specifier|const
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
decl|const
decl_stmt|;
comment|/// Targets can override this to customize the output of IMPLICIT_DEF
comment|/// instructions in verbose mode.
name|virtual
name|void
name|emitImplicitDef
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
decl|const
decl_stmt|;
comment|//===------------------------------------------------------------------===//
comment|// Symbol Lowering Routines.
comment|//===------------------------------------------------------------------===//
name|MCSymbol
modifier|*
name|createTempSymbol
argument_list|(
specifier|const
name|Twine
operator|&
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// Return the MCSymbol for a private symbol with global value name as its
comment|/// base, with the specified suffix.
name|MCSymbol
modifier|*
name|getSymbolWithGlobalValueBase
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|,
name|StringRef
name|Suffix
argument_list|)
decl|const
decl_stmt|;
comment|/// Return the MCSymbol for the specified ExternalSymbol.
name|MCSymbol
modifier|*
name|GetExternalSymbolSymbol
argument_list|(
name|StringRef
name|Sym
argument_list|)
decl|const
decl_stmt|;
comment|/// Return the symbol for the specified jump table entry.
name|MCSymbol
modifier|*
name|GetJTISymbol
argument_list|(
name|unsigned
name|JTID
argument_list|,
name|bool
name|isLinkerPrivate
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
comment|/// Return the symbol for the specified jump table .set
comment|/// FIXME: privatize to AsmPrinter.
name|MCSymbol
modifier|*
name|GetJTSetSymbol
argument_list|(
name|unsigned
name|UID
argument_list|,
name|unsigned
name|MBBID
argument_list|)
decl|const
decl_stmt|;
comment|/// Return the MCSymbol used to satisfy BlockAddress uses of the specified
comment|/// basic block.
name|MCSymbol
modifier|*
name|GetBlockAddressSymbol
argument_list|(
specifier|const
name|BlockAddress
operator|*
name|BA
argument_list|)
decl|const
decl_stmt|;
name|MCSymbol
modifier|*
name|GetBlockAddressSymbol
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
comment|//===------------------------------------------------------------------===//
comment|// Emission Helper Routines.
comment|//===------------------------------------------------------------------===//
comment|/// This is just convenient handler for printing offsets.
name|void
name|printOffset
argument_list|(
name|int64_t
name|Offset
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|/// Emit a byte directive and value.
comment|///
name|void
name|EmitInt8
argument_list|(
name|int
name|Value
argument_list|)
decl|const
decl_stmt|;
comment|/// Emit a short directive and value.
comment|///
name|void
name|EmitInt16
argument_list|(
name|int
name|Value
argument_list|)
decl|const
decl_stmt|;
comment|/// Emit a long directive and value.
comment|///
name|void
name|EmitInt32
argument_list|(
name|int
name|Value
argument_list|)
decl|const
decl_stmt|;
comment|/// Emit something like ".long Hi-Lo" where the size in bytes of the directive
comment|/// is specified by Size and Hi/Lo specify the labels.  This implicitly uses
comment|/// .set if it is available.
name|void
name|EmitLabelDifference
argument_list|(
specifier|const
name|MCSymbol
operator|*
name|Hi
argument_list|,
specifier|const
name|MCSymbol
operator|*
name|Lo
argument_list|,
name|unsigned
name|Size
argument_list|)
decl|const
decl_stmt|;
comment|/// Emit something like ".long Label+Offset" where the size in bytes of the
comment|/// directive is specified by Size and Label specifies the label.  This
comment|/// implicitly uses .set if it is available.
name|void
name|EmitLabelPlusOffset
argument_list|(
specifier|const
name|MCSymbol
operator|*
name|Label
argument_list|,
name|uint64_t
name|Offset
argument_list|,
name|unsigned
name|Size
argument_list|,
name|bool
name|IsSectionRelative
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
comment|/// Emit something like ".long Label" where the size in bytes of the directive
comment|/// is specified by Size and Label specifies the label.
name|void
name|EmitLabelReference
argument_list|(
specifier|const
name|MCSymbol
operator|*
name|Label
argument_list|,
name|unsigned
name|Size
argument_list|,
name|bool
name|IsSectionRelative
operator|=
name|false
argument_list|)
decl|const
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
expr_stmt|;
block|}
comment|//===------------------------------------------------------------------===//
comment|// Dwarf Emission Helper Routines
comment|//===------------------------------------------------------------------===//
comment|/// Emit the specified signed leb128 value.
name|void
name|EmitSLEB128
argument_list|(
name|int64_t
name|Value
argument_list|,
specifier|const
name|char
operator|*
name|Desc
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
comment|/// Emit the specified unsigned leb128 value.
name|void
name|EmitULEB128
argument_list|(
name|uint64_t
name|Value
argument_list|,
specifier|const
name|char
operator|*
name|Desc
operator|=
name|nullptr
argument_list|,
name|unsigned
name|PadTo
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// Emit a .byte 42 directive that corresponds to an encoding.  If verbose
comment|/// assembly output is enabled, we output comments describing the encoding.
comment|/// Desc is a string saying what the encoding is specifying (e.g. "LSDA").
name|void
name|EmitEncodingByte
argument_list|(
name|unsigned
name|Val
argument_list|,
specifier|const
name|char
operator|*
name|Desc
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
comment|/// Return the size of the encoding in bytes.
name|unsigned
name|GetSizeOfEncodedValue
argument_list|(
name|unsigned
name|Encoding
argument_list|)
decl|const
decl_stmt|;
comment|/// Emit reference to a ttype global with a specified encoding.
name|void
name|EmitTTypeReference
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|,
name|unsigned
name|Encoding
argument_list|)
decl|const
decl_stmt|;
comment|/// Emit a reference to a symbol for use in dwarf. Different object formats
comment|/// represent this in different ways. Some use a relocation others encode
comment|/// the label offset in its section.
name|void
name|emitDwarfSymbolReference
argument_list|(
specifier|const
name|MCSymbol
operator|*
name|Label
argument_list|,
name|bool
name|ForceOffset
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
comment|/// Emit the 4-byte offset of a string from the start of its section.
comment|///
comment|/// When possible, emit a DwarfStringPool section offset without any
comment|/// relocations, and without using the symbol.  Otherwise, defers to \a
comment|/// emitDwarfSymbolReference().
name|void
name|emitDwarfStringOffset
argument_list|(
name|DwarfStringPoolEntryRef
name|S
argument_list|)
decl|const
decl_stmt|;
comment|/// Get the value for DW_AT_APPLE_isa. Zero if no isa encoding specified.
name|virtual
name|unsigned
name|getISAEncoding
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
comment|/// Emit the directive and value for debug thread local expression
comment|///
comment|/// \p Value - The value to emit.
comment|/// \p Size - The size of the integer (in bytes) to emit.
name|virtual
name|void
name|EmitDebugThreadLocal
argument_list|(
specifier|const
name|MCExpr
operator|*
name|Value
argument_list|,
name|unsigned
name|Size
argument_list|)
decl|const
decl_stmt|;
comment|//===------------------------------------------------------------------===//
comment|// Dwarf Lowering Routines
comment|//===------------------------------------------------------------------===//
comment|/// \brief Emit frame instruction to describe the layout of the frame.
name|void
name|emitCFIInstruction
argument_list|(
specifier|const
name|MCCFIInstruction
operator|&
name|Inst
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Emit Dwarf abbreviation table.
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|emitDwarfAbbrevs
argument_list|(
argument|const T&Abbrevs
argument_list|)
specifier|const
block|{
comment|// For each abbreviation.
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|Abbrev
range|:
name|Abbrevs
control|)
name|emitDwarfAbbrev
argument_list|(
operator|*
name|Abbrev
argument_list|)
expr_stmt|;
comment|// Mark end of abbreviations.
name|EmitULEB128
argument_list|(
literal|0
argument_list|,
literal|"EOM(3)"
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|emitDwarfAbbrev
argument_list|(
specifier|const
name|DIEAbbrev
operator|&
name|Abbrev
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Recursively emit Dwarf DIE tree.
end_comment

begin_decl_stmt
name|void
name|emitDwarfDIE
argument_list|(
specifier|const
name|DIE
operator|&
name|Die
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|//===------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Inline Asm Support
end_comment

begin_comment
comment|//===------------------------------------------------------------------===//
end_comment

begin_comment
comment|// These are hooks that targets can override to implement inline asm
end_comment

begin_comment
comment|// support.  These should probably be moved out of AsmPrinter someday.
end_comment

begin_comment
comment|/// Print information related to the specified machine instr that is
end_comment

begin_comment
comment|/// independent of the operand, and may be independent of the instr itself.
end_comment

begin_comment
comment|/// This can be useful for portably encoding the comment character or other
end_comment

begin_comment
comment|/// bits of target-specific knowledge into the asmstrings.  The syntax used is
end_comment

begin_comment
comment|/// ${:comment}.  Targets can override this to add support for their own
end_comment

begin_comment
comment|/// strange codes.
end_comment

begin_decl_stmt
name|virtual
name|void
name|PrintSpecial
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|,
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|char
operator|*
name|Code
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Print the specified operand of MI, an INLINEASM instruction, using the
end_comment

begin_comment
comment|/// specified assembler variant.  Targets should override this to format as
end_comment

begin_comment
comment|/// appropriate.  This method can return true if the operand is erroneous.
end_comment

begin_function_decl
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
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Print the specified operand of MI, an INLINEASM instruction, using the
end_comment

begin_comment
comment|/// specified assembler variant as an address. Targets should override this to
end_comment

begin_comment
comment|/// format as appropriate.  This method can return true if the operand is
end_comment

begin_comment
comment|/// erroneous.
end_comment

begin_function_decl
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
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Let the target do anything it needs to do before emitting inlineasm.
end_comment

begin_comment
comment|/// \p StartInfo - the subtarget info before parsing inline asm
end_comment

begin_expr_stmt
name|virtual
name|void
name|emitInlineAsmStart
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Let the target do anything it needs to do after emitting inlineasm.
end_comment

begin_comment
comment|/// This callback can be used restore the original mode in case the
end_comment

begin_comment
comment|/// inlineasm contains directives to switch modes.
end_comment

begin_comment
comment|/// \p StartInfo - the original subtarget info before inline asm
end_comment

begin_comment
comment|/// \p EndInfo   - the final subtarget info after parsing the inline asm,
end_comment

begin_comment
comment|///                or NULL if the value is unknown.
end_comment

begin_decl_stmt
name|virtual
name|void
name|emitInlineAsmEnd
argument_list|(
specifier|const
name|MCSubtargetInfo
operator|&
name|StartInfo
argument_list|,
specifier|const
name|MCSubtargetInfo
operator|*
name|EndInfo
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|/// Private state for PrintSpecial()
end_comment

begin_comment
comment|// Assign a unique ID to this machine instruction.
end_comment

begin_decl_stmt
name|mutable
specifier|const
name|MachineInstr
modifier|*
name|LastMI
init|=
name|nullptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|mutable
name|unsigned
name|LastFn
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|mutable
name|unsigned
name|Counter
init|=
operator|~
literal|0U
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// This method emits the header for the current function.
end_comment

begin_function_decl
name|virtual
name|void
name|EmitFunctionHeader
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// Emit a blob of inline asm to the output streamer.
end_comment

begin_decl_stmt
name|void
name|EmitInlineAsm
argument_list|(
name|StringRef
name|Str
argument_list|,
specifier|const
name|MCSubtargetInfo
operator|&
name|STI
argument_list|,
specifier|const
name|MCTargetOptions
operator|&
name|MCOptions
argument_list|,
specifier|const
name|MDNode
operator|*
name|LocMDNode
operator|=
name|nullptr
argument_list|,
name|InlineAsm
operator|::
name|AsmDialect
name|AsmDialect
operator|=
name|InlineAsm
operator|::
name|AD_ATT
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// This method formats and emits the specified machine instruction that is an
end_comment

begin_comment
comment|/// inline asm.
end_comment

begin_decl_stmt
name|void
name|EmitInlineAsm
argument_list|(
specifier|const
name|MachineInstr
operator|*
name|MI
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|//===------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Internal Implementation Details
end_comment

begin_comment
comment|//===------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// This emits visibility information about symbol, if this is suported by the
end_comment

begin_comment
comment|/// target.
end_comment

begin_decl_stmt
name|void
name|EmitVisibility
argument_list|(
name|MCSymbol
operator|*
name|Sym
argument_list|,
name|unsigned
name|Visibility
argument_list|,
name|bool
name|IsDefinition
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitLinkage
argument_list|(
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|,
name|MCSymbol
operator|*
name|GVSym
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|EmitJumpTableEntry
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
end_decl_stmt

begin_function_decl
name|void
name|EmitLLVMUsedList
parameter_list|(
specifier|const
name|ConstantArray
modifier|*
name|InitList
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Emit llvm.ident metadata in an '.ident' directive.
end_comment

begin_function_decl
name|void
name|EmitModuleIdents
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EmitXXStructorList
parameter_list|(
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|,
specifier|const
name|Constant
modifier|*
name|List
parameter_list|,
name|bool
name|isCtor
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|GCMetadataPrinter
modifier|*
name|GetOrCreateGCPrinter
parameter_list|(
name|GCStrategy
modifier|&
name|C
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Emit GlobalAlias or GlobalIFunc.
end_comment

begin_function_decl
name|void
name|emitGlobalIndirectSymbol
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|,
specifier|const
name|GlobalIndirectSymbol
modifier|&
name|GIS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_ASMPRINTER_H
end_comment

end_unit

