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
file|"llvm/Support/Dwarf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/UniqueVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineLocation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/GlobalValue.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Metadata.h"
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
name|MDNode
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
name|Module
decl_stmt|;
name|class
name|PointerType
decl_stmt|;
name|class
name|StructType
decl_stmt|;
comment|/// MachineModuleInfoImpl - This class can be derived from and used by targets
comment|/// to hold private target-specific information for each Module.  Objects of
comment|/// type are accessed/created with MMI::getInfo and destroyed when the
comment|/// MachineModuleInfo is destroyed.
name|class
name|MachineModuleInfoImpl
block|{
name|public
label|:
name|virtual
operator|~
name|MachineModuleInfoImpl
argument_list|()
expr_stmt|;
block|}
empty_stmt|;
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
name|unsigned
operator|,
literal|1
operator|>
name|BeginLabels
expr_stmt|;
comment|// Labels prior to invoke.
name|SmallVector
operator|<
name|unsigned
operator|,
literal|1
operator|>
name|EndLabels
expr_stmt|;
comment|// Labels after invoke.
name|unsigned
name|LandingPadLabel
decl_stmt|;
comment|// Label at beginning of landing pad.
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
argument|NULL
argument_list|)
block|{}
block|}
struct|;
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
comment|/// ObjFileMMI - This is the object-file-format-specific implementation of
comment|/// MachineModuleInfoImpl, which lets targets accumulate whatever info they
comment|/// want.
name|MachineModuleInfoImpl
operator|*
name|ObjFileMMI
block|;
comment|// LabelIDList - One entry per assigned label.  Normally the entry is equal to
comment|// the list index(+1).  If the entry is zero then the label has been deleted.
comment|// Any other value indicates the label has been deleted by is mapped to
comment|// another label.
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|LabelIDList
block|;
comment|// FrameMoves - List of moves done by a function's prolog.  Used to construct
comment|// frame maps by debug and exception handling consumers.
name|std
operator|::
name|vector
operator|<
name|MachineMove
operator|>
name|FrameMoves
block|;
comment|// LandingPads - List of LandingPadInfo describing the landing pad information
comment|// in the current function.
name|std
operator|::
name|vector
operator|<
name|LandingPadInfo
operator|>
name|LandingPads
block|;
comment|// TypeInfos - List of C++ TypeInfo used in the current function.
comment|//
name|std
operator|::
name|vector
operator|<
name|GlobalVariable
operator|*
operator|>
name|TypeInfos
block|;
comment|// FilterIds - List of typeids encoding filters used in the current function.
comment|//
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|FilterIds
block|;
comment|// FilterEnds - List of the indices in FilterIds corresponding to filter
comment|// terminators.
comment|//
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|FilterEnds
block|;
comment|// Personalities - Vector of all personality functions ever seen. Used to emit
comment|// common EH frames.
name|std
operator|::
name|vector
operator|<
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
comment|/// UsedDbgLabels - labels are used by debug info entries.
name|SmallSet
operator|<
name|unsigned
block|,
literal|8
operator|>
name|UsedDbgLabels
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
name|TrackingVH
operator|<
name|MDNode
operator|>
expr|>
name|UnsignedAndMDNodePair
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
name|UnsignedAndMDNodePair
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
operator|~
name|MachineModuleInfo
argument_list|()
expr_stmt|;
name|bool
name|doInitialization
parameter_list|()
function_decl|;
name|bool
name|doFinalization
parameter_list|()
function_decl|;
comment|/// BeginFunction - Begin gathering function meta information.
comment|///
name|void
name|BeginFunction
parameter_list|(
name|MachineFunction
modifier|*
parameter_list|)
block|{}
comment|/// EndFunction - Discard function meta information.
comment|///
name|void
name|EndFunction
parameter_list|()
function_decl|;
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
name|assert
argument_list|(
operator|(
name|void
operator|*
operator|)
name|dynamic_cast
operator|<
name|Ty
operator|*
operator|>
operator|(
name|ObjFileMMI
operator|)
operator|==
operator|(
name|void
operator|*
operator|)
name|ObjFileMMI
operator|&&
literal|"Invalid concrete type or multiple inheritence for getInfo"
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
name|true
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

begin_comment
comment|/// NextLabelID - Return the next unique label id.
end_comment

begin_comment
comment|///
end_comment

begin_function
name|unsigned
name|NextLabelID
parameter_list|()
block|{
name|unsigned
name|ID
init|=
operator|(
name|unsigned
operator|)
name|LabelIDList
operator|.
name|size
argument_list|()
operator|+
literal|1
decl_stmt|;
name|LabelIDList
operator|.
name|push_back
argument_list|(
name|ID
argument_list|)
expr_stmt|;
return|return
name|ID
return|;
block|}
end_function

begin_comment
comment|/// InvalidateLabel - Inhibit use of the specified label # from
end_comment

begin_comment
comment|/// MachineModuleInfo, for example because the code was deleted.
end_comment

begin_function
name|void
name|InvalidateLabel
parameter_list|(
name|unsigned
name|LabelID
parameter_list|)
block|{
comment|// Remap to zero to indicate deletion.
name|RemapLabel
argument_list|(
name|LabelID
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// RemapLabel - Indicate that a label has been merged into another.
end_comment

begin_comment
comment|///
end_comment

begin_function
name|void
name|RemapLabel
parameter_list|(
name|unsigned
name|OldLabelID
parameter_list|,
name|unsigned
name|NewLabelID
parameter_list|)
block|{
name|assert
argument_list|(
literal|0
operator|<
name|OldLabelID
operator|&&
name|OldLabelID
operator|<=
name|LabelIDList
operator|.
name|size
argument_list|()
operator|&&
literal|"Old label ID out of range."
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|NewLabelID
operator|<=
name|LabelIDList
operator|.
name|size
argument_list|()
operator|&&
literal|"New label ID out of range."
argument_list|)
expr_stmt|;
name|LabelIDList
index|[
name|OldLabelID
operator|-
literal|1
index|]
operator|=
name|NewLabelID
expr_stmt|;
block|}
end_function

begin_comment
comment|/// MappedLabel - Find out the label's final ID.  Zero indicates deletion.
end_comment

begin_comment
comment|/// ID != Mapped ID indicates that the label was folded into another label.
end_comment

begin_decl_stmt
name|unsigned
name|MappedLabel
argument_list|(
name|unsigned
name|LabelID
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|LabelID
operator|<=
name|LabelIDList
operator|.
name|size
argument_list|()
operator|&&
literal|"Debug label ID out of range."
argument_list|)
expr_stmt|;
return|return
name|LabelID
condition|?
name|LabelIDList
index|[
name|LabelID
operator|-
literal|1
index|]
else|:
literal|0
return|;
block|}
end_decl_stmt

begin_comment
comment|/// isDbgLabelUsed - Return true if label with LabelID is used by
end_comment

begin_comment
comment|/// DwarfWriter.
end_comment

begin_function
name|bool
name|isDbgLabelUsed
parameter_list|(
name|unsigned
name|LabelID
parameter_list|)
block|{
return|return
name|UsedDbgLabels
operator|.
name|count
argument_list|(
name|LabelID
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// RecordUsedDbgLabel - Mark label with LabelID as used. This is used
end_comment

begin_comment
comment|/// by DwarfWriter to inform DebugLabelFolder that certain labels are
end_comment

begin_comment
comment|/// not to be deleted.
end_comment

begin_function
name|void
name|RecordUsedDbgLabel
parameter_list|(
name|unsigned
name|LabelID
parameter_list|)
block|{
name|UsedDbgLabels
operator|.
name|insert
argument_list|(
name|LabelID
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// getFrameMoves - Returns a reference to a list of moves done in the current
end_comment

begin_comment
comment|/// function's prologue.  Used to construct frame maps for debug and exception
end_comment

begin_comment
comment|/// handling comsumers.
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|MachineMove
operator|>
operator|&
name|getFrameMoves
argument_list|()
block|{
return|return
name|FrameMoves
return|;
block|}
end_expr_stmt

begin_comment
comment|//===-EH-----------------------------------------------------------------===//
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
name|unsigned
name|BeginLabel
parameter_list|,
name|unsigned
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
name|unsigned
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

begin_function
name|bool
name|isUsedFunction
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|)
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
end_function

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
name|std
operator|::
name|vector
operator|<
name|GlobalVariable
operator|*
operator|>
operator|&
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
name|std
operator|::
name|vector
operator|<
name|GlobalVariable
operator|*
operator|>
operator|&
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

begin_function_decl
name|void
name|TidyLandingPads
parameter_list|()
function_decl|;
end_function_decl

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
name|Function
operator|*
name|getPersonality
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// setVariableDbgInfo - Collect information used to emit debugging information
end_comment

begin_comment
comment|/// of a variable.
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
name|MDNode
modifier|*
name|Scope
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
name|Scope
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

