begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/MachineModuleInfo.h ------------------------*- C++ -*-===//
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
comment|// Collect meta information for a module.  This information should be in a
end_comment

begin_comment
comment|// neutral form that can be used by different debugging and exception handling
end_comment

begin_comment
comment|// schemes.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The organization of information is primarily clustered around the source
end_comment

begin_comment
comment|// compile units.  The main exception is source line correspondence where
end_comment

begin_comment
comment|// inlining may interleave code from various compile units.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The following information can be retrieved from the MachineModuleInfo.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  -- Source directories - Directories are uniqued based on their canonical
end_comment

begin_comment
comment|//     string and assigned a sequential numeric ID (base 1.)
end_comment

begin_comment
comment|//  -- Source files - Files are also uniqued based on their name and directory
end_comment

begin_comment
comment|//     ID.  A file ID is sequential number (base 1.)
end_comment

begin_comment
comment|//  -- Source line correspondence - A vector of file ID, line#, column# triples.
end_comment

begin_comment
comment|//     A DEBUG_LOCATION instruction is generated  by the DAG Legalizer
end_comment

begin_comment
comment|//     corresponding to each entry in the source line list.  This allows a debug
end_comment

begin_comment
comment|//     emitter to generate labels referenced by debug information tables.
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
name|LLVM_CODEGEN_MACHINEMODULEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINEMODULEINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Metadata.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MachineLocation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DebugLoc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Dwarf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ValueHandle.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|//===----------------------------------------------------------------------===//
comment|// Forward declarations.
name|class
name|Constant
decl_stmt|;
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|MDNode
decl_stmt|;
name|class
name|MMIAddrLabelMap
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|PointerType
decl_stmt|;
name|class
name|StructType
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// LandingPadInfo - This structure is used to retain landing pad info for
comment|/// the current function.
comment|///
struct|struct
name|LandingPadInfo
block|{
name|MachineBasicBlock
modifier|*
name|LandingPadBlock
decl_stmt|;
comment|// Landing pad block.
name|SmallVector
operator|<
name|MCSymbol
operator|*
operator|,
literal|1
operator|>
name|BeginLabels
expr_stmt|;
comment|// Labels prior to invoke.
name|SmallVector
operator|<
name|MCSymbol
operator|*
operator|,
literal|1
operator|>
name|EndLabels
expr_stmt|;
comment|// Labels after invoke.
name|MCSymbol
modifier|*
name|LandingPadLabel
decl_stmt|;
comment|// Label at beginning of landing pad.
specifier|const
name|Function
modifier|*
name|Personality
decl_stmt|;
comment|// Personality function.
name|std
operator|::
name|vector
operator|<
name|int
operator|>
name|TypeIds
expr_stmt|;
comment|// List of type ids (filters negative)
name|explicit
name|LandingPadInfo
argument_list|(
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
operator|:
name|LandingPadBlock
argument_list|(
name|MBB
argument_list|)
operator|,
name|LandingPadLabel
argument_list|(
literal|0
argument_list|)
operator|,
name|Personality
argument_list|(
literal|0
argument_list|)
block|{}
block|}
struct|;
comment|//===----------------------------------------------------------------------===//
comment|/// MachineModuleInfoImpl - This class can be derived from and used by targets
comment|/// to hold private target-specific information for each Module.  Objects of
comment|/// type are accessed/created with MMI::getInfo and destroyed when the
comment|/// MachineModuleInfo is destroyed.
comment|///
name|class
name|MachineModuleInfoImpl
block|{
name|public
label|:
typedef|typedef
name|PointerIntPair
operator|<
name|MCSymbol
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
name|StubValueTy
expr_stmt|;
name|virtual
operator|~
name|MachineModuleInfoImpl
argument_list|()
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|MCSymbol
operator|*
operator|,
name|StubValueTy
operator|>
expr|>
name|SymbolListTy
expr_stmt|;
name|protected
label|:
specifier|static
name|SymbolListTy
name|GetSortedStubs
argument_list|(
specifier|const
name|DenseMap
operator|<
name|MCSymbol
operator|*
argument_list|,
name|StubValueTy
operator|>
operator|&
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// MachineModuleInfo - This class contains meta information specific to a
comment|/// module.  Queries can be made by different debugging and exception handling
comment|/// schemes and reformated for specific use.
comment|///
name|class
name|MachineModuleInfo
range|:
name|public
name|ImmutablePass
block|{
comment|/// Context - This is the MCContext used for the entire code generator.
name|MCContext
name|Context
block|;
comment|/// TheModule - This is the LLVM Module being worked on.
specifier|const
name|Module
operator|*
name|TheModule
block|;
comment|/// ObjFileMMI - This is the object-file-format-specific implementation of
comment|/// MachineModuleInfoImpl, which lets targets accumulate whatever info they
comment|/// want.
name|MachineModuleInfoImpl
operator|*
name|ObjFileMMI
block|;
comment|/// List of moves done by a function's prolog.  Used to construct frame maps
comment|/// by debug and exception handling consumers.
name|std
operator|::
name|vector
operator|<
name|MCCFIInstruction
operator|>
name|FrameInstructions
block|;
comment|/// CompactUnwindEncoding - If the target supports it, this is the compact
comment|/// unwind encoding. It replaces a function's CIE and FDE.
name|uint32_t
name|CompactUnwindEncoding
block|;
comment|/// LandingPads - List of LandingPadInfo describing the landing pad
comment|/// information in the current function.
name|std
operator|::
name|vector
operator|<
name|LandingPadInfo
operator|>
name|LandingPads
block|;
comment|/// LPadToCallSiteMap - Map a landing pad's EH symbol to the call site
comment|/// indexes.
name|DenseMap
operator|<
name|MCSymbol
operator|*
block|,
name|SmallVector
operator|<
name|unsigned
block|,
literal|4
operator|>
expr|>
name|LPadToCallSiteMap
block|;
comment|/// CallSiteMap - Map of invoke call site index values to associated begin
comment|/// EH_LABEL for the current function.
name|DenseMap
operator|<
name|MCSymbol
operator|*
block|,
name|unsigned
operator|>
name|CallSiteMap
block|;
comment|/// CurCallSite - The current call site index being processed, if any. 0 if
comment|/// none.
name|unsigned
name|CurCallSite
block|;
comment|/// TypeInfos - List of C++ TypeInfo used in the current function.
name|std
operator|::
name|vector
operator|<
specifier|const
name|GlobalVariable
operator|*
operator|>
name|TypeInfos
block|;
comment|/// FilterIds - List of typeids encoding filters used in the current function.
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|FilterIds
block|;
comment|/// FilterEnds - List of the indices in FilterIds corresponding to filter
comment|/// terminators.
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|FilterEnds
block|;
comment|/// Personalities - Vector of all personality functions ever seen. Used to
comment|/// emit common EH frames.
name|std
operator|::
name|vector
operator|<
specifier|const
name|Function
operator|*
operator|>
name|Personalities
block|;
comment|/// UsedFunctions - The functions in the @llvm.used list in a more easily
comment|/// searchable format.  This does not include the functions in
comment|/// llvm.compiler.used.
name|SmallPtrSet
operator|<
specifier|const
name|Function
operator|*
block|,
literal|32
operator|>
name|UsedFunctions
block|;
comment|/// AddrLabelSymbols - This map keeps track of which symbol is being used for
comment|/// the specified basic block's address of label.
name|MMIAddrLabelMap
operator|*
name|AddrLabelSymbols
block|;
name|bool
name|CallsEHReturn
block|;
name|bool
name|CallsUnwindInit
block|;
comment|/// DbgInfoAvailable - True if debugging information is available
comment|/// in this module.
name|bool
name|DbgInfoAvailable
block|;
comment|/// UsesVAFloatArgument - True if this module calls VarArg function with
comment|/// floating-point arguments.  This is used to emit an undefined reference
comment|/// to _fltused on Windows targets.
name|bool
name|UsesVAFloatArgument
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Pass identification, replacement for typeid
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|DebugLoc
operator|>
name|UnsignedDebugLocPair
expr_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|TrackingVH
operator|<
name|MDNode
operator|>
operator|,
name|UnsignedDebugLocPair
operator|>
operator|,
literal|4
operator|>
name|VariableDbgInfoMapTy
expr_stmt|;
name|VariableDbgInfoMapTy
name|VariableDbgInfo
decl_stmt|;
name|MachineModuleInfo
argument_list|()
expr_stmt|;
comment|// DUMMY CONSTRUCTOR, DO NOT CALL.
comment|// Real constructor.
name|MachineModuleInfo
argument_list|(
specifier|const
name|MCAsmInfo
operator|&
name|MAI
argument_list|,
specifier|const
name|MCRegisterInfo
operator|&
name|MRI
argument_list|,
specifier|const
name|MCObjectFileInfo
operator|*
name|MOFI
argument_list|)
expr_stmt|;
operator|~
name|MachineModuleInfo
argument_list|()
expr_stmt|;
comment|// Initialization and Finalization
name|virtual
name|bool
name|doInitialization
parameter_list|(
name|Module
modifier|&
parameter_list|)
function_decl|;
name|virtual
name|bool
name|doFinalization
parameter_list|(
name|Module
modifier|&
parameter_list|)
function_decl|;
comment|/// EndFunction - Discard function meta information.
comment|///
name|void
name|EndFunction
parameter_list|()
function_decl|;
specifier|const
name|MCContext
operator|&
name|getContext
argument_list|()
specifier|const
block|{
return|return
name|Context
return|;
block|}
name|MCContext
modifier|&
name|getContext
parameter_list|()
block|{
return|return
name|Context
return|;
block|}
name|void
name|setModule
parameter_list|(
specifier|const
name|Module
modifier|*
name|M
parameter_list|)
block|{
name|TheModule
operator|=
name|M
expr_stmt|;
block|}
specifier|const
name|Module
operator|*
name|getModule
argument_list|()
specifier|const
block|{
return|return
name|TheModule
return|;
block|}
comment|/// getInfo - Keep track of various per-function pieces of information for
comment|/// backends that would like to do so.
comment|///
name|template
operator|<
name|typename
name|Ty
operator|>
name|Ty
operator|&
name|getObjFileInfo
argument_list|()
block|{
if|if
condition|(
name|ObjFileMMI
operator|==
literal|0
condition|)
name|ObjFileMMI
operator|=
name|new
name|Ty
argument_list|(
operator|*
name|this
argument_list|)
expr_stmt|;
return|return
operator|*
name|static_cast
operator|<
name|Ty
operator|*
operator|>
operator|(
name|ObjFileMMI
operator|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|Ty
operator|>
specifier|const
name|Ty
operator|&
name|getObjFileInfo
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|MachineModuleInfo
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getObjFileInfo
operator|<
name|Ty
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// AnalyzeModule - Scan the module for global debug information.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|void
name|AnalyzeModule
parameter_list|(
specifier|const
name|Module
modifier|&
name|M
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// hasDebugInfo - Returns true if valid debug info is present.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|bool
name|hasDebugInfo
argument_list|()
specifier|const
block|{
return|return
name|DbgInfoAvailable
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setDebugInfoAvailability
parameter_list|(
name|bool
name|avail
parameter_list|)
block|{
name|DbgInfoAvailable
operator|=
name|avail
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|bool
name|callsEHReturn
argument_list|()
specifier|const
block|{
return|return
name|CallsEHReturn
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setCallsEHReturn
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|CallsEHReturn
operator|=
name|b
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|bool
name|callsUnwindInit
argument_list|()
specifier|const
block|{
return|return
name|CallsUnwindInit
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setCallsUnwindInit
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|CallsUnwindInit
operator|=
name|b
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|bool
name|usesVAFloatArgument
argument_list|()
specifier|const
block|{
return|return
name|UsesVAFloatArgument
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setUsesVAFloatArgument
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|UsesVAFloatArgument
operator|=
name|b
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Returns a reference to a list of cfi instructions in the current
end_comment

begin_comment
comment|/// function's prologue.  Used to construct frame maps for debug and exception
end_comment

begin_comment
comment|/// handling comsumers.
end_comment

begin_expr_stmt
specifier|const
name|std
operator|::
name|vector
operator|<
name|MCCFIInstruction
operator|>
operator|&
name|getFrameInstructions
argument_list|()
specifier|const
block|{
return|return
name|FrameInstructions
return|;
block|}
end_expr_stmt

begin_function
name|void
name|addFrameInst
parameter_list|(
specifier|const
name|MCCFIInstruction
modifier|&
name|Inst
parameter_list|)
block|{
name|FrameInstructions
operator|.
name|push_back
argument_list|(
name|Inst
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// getCompactUnwindEncoding - Returns the compact unwind encoding for a
end_comment

begin_comment
comment|/// function if the target supports the encoding. This encoding replaces a
end_comment

begin_comment
comment|/// function's CIE and FDE.
end_comment

begin_expr_stmt
name|uint32_t
name|getCompactUnwindEncoding
argument_list|()
specifier|const
block|{
return|return
name|CompactUnwindEncoding
return|;
block|}
end_expr_stmt

begin_comment
comment|/// setCompactUnwindEncoding - Set the compact unwind encoding for a function
end_comment

begin_comment
comment|/// if the target supports the encoding.
end_comment

begin_function
name|void
name|setCompactUnwindEncoding
parameter_list|(
name|uint32_t
name|Enc
parameter_list|)
block|{
name|CompactUnwindEncoding
operator|=
name|Enc
expr_stmt|;
block|}
end_function

begin_comment
comment|/// getAddrLabelSymbol - Return the symbol to be used for the specified basic
end_comment

begin_comment
comment|/// block when its address is taken.  This cannot be its normal LBB label
end_comment

begin_comment
comment|/// because the block may be accessed outside its containing function.
end_comment

begin_function_decl
name|MCSymbol
modifier|*
name|getAddrLabelSymbol
parameter_list|(
specifier|const
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getAddrLabelSymbolToEmit - Return the symbol to be used for the specified
end_comment

begin_comment
comment|/// basic block when its address is taken.  If other blocks were RAUW'd to
end_comment

begin_comment
comment|/// this one, we may have to emit them as well, return the whole set.
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|MCSymbol
operator|*
operator|>
name|getAddrLabelSymbolToEmit
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// takeDeletedSymbolsForFunction - If the specified function has had any
end_comment

begin_comment
comment|/// references to address-taken blocks generated, but the block got deleted,
end_comment

begin_comment
comment|/// return the symbol now so we can emit it.  This prevents emitting a
end_comment

begin_comment
comment|/// reference to a symbol that has no definition.
end_comment

begin_decl_stmt
name|void
name|takeDeletedSymbolsForFunction
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|,
name|std
operator|::
name|vector
operator|<
name|MCSymbol
operator|*
operator|>
operator|&
name|Result
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//===- EH ---------------------------------------------------------------===//
end_comment

begin_comment
comment|/// getOrCreateLandingPadInfo - Find or create an LandingPadInfo for the
end_comment

begin_comment
comment|/// specified MachineBasicBlock.
end_comment

begin_function_decl
name|LandingPadInfo
modifier|&
name|getOrCreateLandingPadInfo
parameter_list|(
name|MachineBasicBlock
modifier|*
name|LandingPad
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// addInvoke - Provide the begin and end labels of an invoke style call and
end_comment

begin_comment
comment|/// associate it with a try landing pad block.
end_comment

begin_function_decl
name|void
name|addInvoke
parameter_list|(
name|MachineBasicBlock
modifier|*
name|LandingPad
parameter_list|,
name|MCSymbol
modifier|*
name|BeginLabel
parameter_list|,
name|MCSymbol
modifier|*
name|EndLabel
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// addLandingPad - Add a new panding pad.  Returns the label ID for the
end_comment

begin_comment
comment|/// landing pad entry.
end_comment

begin_function_decl
name|MCSymbol
modifier|*
name|addLandingPad
parameter_list|(
name|MachineBasicBlock
modifier|*
name|LandingPad
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// addPersonality - Provide the personality function for the exception
end_comment

begin_comment
comment|/// information.
end_comment

begin_function_decl
name|void
name|addPersonality
parameter_list|(
name|MachineBasicBlock
modifier|*
name|LandingPad
parameter_list|,
specifier|const
name|Function
modifier|*
name|Personality
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getPersonalityIndex - Get index of the current personality function inside
end_comment

begin_comment
comment|/// Personalitites array
end_comment

begin_expr_stmt
name|unsigned
name|getPersonalityIndex
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// getPersonalities - Return array of personality functions ever seen.
end_comment

begin_expr_stmt
specifier|const
name|std
operator|::
name|vector
operator|<
specifier|const
name|Function
operator|*
operator|>
operator|&
name|getPersonalities
argument_list|()
specifier|const
block|{
return|return
name|Personalities
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isUsedFunction - Return true if the functions in the llvm.used list.  This
end_comment

begin_comment
comment|/// does not return true for things in llvm.compiler.used unless they are also
end_comment

begin_comment
comment|/// in llvm.used.
end_comment

begin_decl_stmt
name|bool
name|isUsedFunction
argument_list|(
specifier|const
name|Function
operator|*
name|F
argument_list|)
decl|const
block|{
return|return
name|UsedFunctions
operator|.
name|count
argument_list|(
name|F
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// addCatchTypeInfo - Provide the catch typeinfo for a landing pad.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|void
name|addCatchTypeInfo
argument_list|(
name|MachineBasicBlock
operator|*
name|LandingPad
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|GlobalVariable
operator|*
operator|>
name|TyInfo
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// addFilterTypeInfo - Provide the filter typeinfo for a landing pad.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|void
name|addFilterTypeInfo
argument_list|(
name|MachineBasicBlock
operator|*
name|LandingPad
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|GlobalVariable
operator|*
operator|>
name|TyInfo
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// addCleanup - Add a cleanup action for a landing pad.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|void
name|addCleanup
parameter_list|(
name|MachineBasicBlock
modifier|*
name|LandingPad
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getTypeIDFor - Return the type id for the specified typeinfo.  This is
end_comment

begin_comment
comment|/// function wide.
end_comment

begin_function_decl
name|unsigned
name|getTypeIDFor
parameter_list|(
specifier|const
name|GlobalVariable
modifier|*
name|TI
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getFilterIDFor - Return the id of the filter encoded by TyIds.  This is
end_comment

begin_comment
comment|/// function wide.
end_comment

begin_decl_stmt
name|int
name|getFilterIDFor
argument_list|(
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
operator|&
name|TyIds
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// TidyLandingPads - Remap landing pad labels and remove any deleted landing
end_comment

begin_comment
comment|/// pads.
end_comment

begin_decl_stmt
name|void
name|TidyLandingPads
argument_list|(
name|DenseMap
operator|<
name|MCSymbol
operator|*
argument_list|,
name|uintptr_t
operator|>
operator|*
name|LPMap
operator|=
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getLandingPads - Return a reference to the landing pad info for the
end_comment

begin_comment
comment|/// current function.
end_comment

begin_expr_stmt
specifier|const
name|std
operator|::
name|vector
operator|<
name|LandingPadInfo
operator|>
operator|&
name|getLandingPads
argument_list|()
specifier|const
block|{
return|return
name|LandingPads
return|;
block|}
end_expr_stmt

begin_comment
comment|/// setCallSiteLandingPad - Map the landing pad's EH symbol to the call
end_comment

begin_comment
comment|/// site indexes.
end_comment

begin_decl_stmt
name|void
name|setCallSiteLandingPad
argument_list|(
name|MCSymbol
operator|*
name|Sym
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|Sites
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// getCallSiteLandingPad - Get the call site indexes for a landing pad EH
end_comment

begin_comment
comment|/// symbol.
end_comment

begin_expr_stmt
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|&
name|getCallSiteLandingPad
argument_list|(
argument|MCSymbol *Sym
argument_list|)
block|{
name|assert
argument_list|(
name|hasCallSiteLandingPad
argument_list|(
name|Sym
argument_list|)
operator|&&
literal|"missing call site number for landing pad!"
argument_list|)
block|;
return|return
name|LPadToCallSiteMap
index|[
name|Sym
index|]
return|;
block|}
end_expr_stmt

begin_comment
comment|/// hasCallSiteLandingPad - Return true if the landing pad Eh symbol has an
end_comment

begin_comment
comment|/// associated call site.
end_comment

begin_function
name|bool
name|hasCallSiteLandingPad
parameter_list|(
name|MCSymbol
modifier|*
name|Sym
parameter_list|)
block|{
return|return
operator|!
name|LPadToCallSiteMap
index|[
name|Sym
index|]
operator|.
name|empty
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// setCallSiteBeginLabel - Map the begin label for a call site.
end_comment

begin_function
name|void
name|setCallSiteBeginLabel
parameter_list|(
name|MCSymbol
modifier|*
name|BeginLabel
parameter_list|,
name|unsigned
name|Site
parameter_list|)
block|{
name|CallSiteMap
index|[
name|BeginLabel
index|]
operator|=
name|Site
expr_stmt|;
block|}
end_function

begin_comment
comment|/// getCallSiteBeginLabel - Get the call site number for a begin label.
end_comment

begin_function
name|unsigned
name|getCallSiteBeginLabel
parameter_list|(
name|MCSymbol
modifier|*
name|BeginLabel
parameter_list|)
block|{
name|assert
argument_list|(
name|hasCallSiteBeginLabel
argument_list|(
name|BeginLabel
argument_list|)
operator|&&
literal|"Missing call site number for EH_LABEL!"
argument_list|)
expr_stmt|;
return|return
name|CallSiteMap
index|[
name|BeginLabel
index|]
return|;
block|}
end_function

begin_comment
comment|/// hasCallSiteBeginLabel - Return true if the begin label has a call site
end_comment

begin_comment
comment|/// number associated with it.
end_comment

begin_function
name|bool
name|hasCallSiteBeginLabel
parameter_list|(
name|MCSymbol
modifier|*
name|BeginLabel
parameter_list|)
block|{
return|return
name|CallSiteMap
index|[
name|BeginLabel
index|]
operator|!=
literal|0
return|;
block|}
end_function

begin_comment
comment|/// setCurrentCallSite - Set the call site currently being processed.
end_comment

begin_function
name|void
name|setCurrentCallSite
parameter_list|(
name|unsigned
name|Site
parameter_list|)
block|{
name|CurCallSite
operator|=
name|Site
expr_stmt|;
block|}
end_function

begin_comment
comment|/// getCurrentCallSite - Get the call site currently being processed, if any.
end_comment

begin_comment
comment|/// return zero if none.
end_comment

begin_function
name|unsigned
name|getCurrentCallSite
parameter_list|()
block|{
return|return
name|CurCallSite
return|;
block|}
end_function

begin_comment
comment|/// getTypeInfos - Return a reference to the C++ typeinfo for the current
end_comment

begin_comment
comment|/// function.
end_comment

begin_expr_stmt
specifier|const
name|std
operator|::
name|vector
operator|<
specifier|const
name|GlobalVariable
operator|*
operator|>
operator|&
name|getTypeInfos
argument_list|()
specifier|const
block|{
return|return
name|TypeInfos
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getFilterIds - Return a reference to the typeids encoding filters used in
end_comment

begin_comment
comment|/// the current function.
end_comment

begin_expr_stmt
specifier|const
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
operator|&
name|getFilterIds
argument_list|()
specifier|const
block|{
return|return
name|FilterIds
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getPersonality - Return a personality function if available.  The presence
end_comment

begin_comment
comment|/// of one is required to emit exception handling info.
end_comment

begin_expr_stmt
specifier|const
name|Function
operator|*
name|getPersonality
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// setVariableDbgInfo - Collect information used to emit debugging
end_comment

begin_comment
comment|/// information of a variable.
end_comment

begin_function
name|void
name|setVariableDbgInfo
parameter_list|(
name|MDNode
modifier|*
name|N
parameter_list|,
name|unsigned
name|Slot
parameter_list|,
name|DebugLoc
name|Loc
parameter_list|)
block|{
name|VariableDbgInfo
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|N
argument_list|,
name|std
operator|::
name|make_pair
argument_list|(
name|Slot
argument_list|,
name|Loc
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|VariableDbgInfoMapTy
modifier|&
name|getVariableDbgInfo
parameter_list|()
block|{
return|return
name|VariableDbgInfo
return|;
block|}
end_function

begin_comment
unit|};
comment|// End class MachineModuleInfo
end_comment

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

