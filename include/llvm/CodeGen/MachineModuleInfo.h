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
file|"llvm/Support/DataTypes.h"
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
name|private
operator|:
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
comment|// UsedFunctions - the functions in the llvm.used list in a more easily
comment|// searchable format.
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
name|MachineModuleInfo
argument_list|()
block|;
operator|~
name|MachineModuleInfo
argument_list|()
block|;
comment|/// doInitialization - Initialize the state for a new module.
comment|///
name|bool
name|doInitialization
argument_list|()
block|;
comment|/// doFinalization - Tear down the state after completion of a module.
comment|///
name|bool
name|doFinalization
argument_list|()
block|;
comment|/// BeginFunction - Begin gathering function meta information.
comment|///
name|void
name|BeginFunction
argument_list|(
name|MachineFunction
operator|*
name|MF
argument_list|)
block|;
comment|/// EndFunction - Discard function meta information.
comment|///
name|void
name|EndFunction
argument_list|()
block|;
comment|/// AnalyzeModule - Scan the module for global debug information.
comment|///
name|void
name|AnalyzeModule
argument_list|(
name|Module
operator|&
name|M
argument_list|)
block|;
comment|/// hasDebugInfo - Returns true if valid debug info is present.
comment|///
name|bool
name|hasDebugInfo
argument_list|()
specifier|const
block|{
return|return
name|DbgInfoAvailable
return|;
block|}
name|void
name|setDebugInfoAvailability
argument_list|(
argument|bool avail
argument_list|)
block|{
name|DbgInfoAvailable
operator|=
name|true
block|; }
name|bool
name|callsEHReturn
argument_list|()
specifier|const
block|{
return|return
name|CallsEHReturn
return|;
block|}
name|void
name|setCallsEHReturn
argument_list|(
argument|bool b
argument_list|)
block|{
name|CallsEHReturn
operator|=
name|b
block|; }
name|bool
name|callsUnwindInit
argument_list|()
specifier|const
block|{
return|return
name|CallsUnwindInit
return|;
block|}
name|void
name|setCallsUnwindInit
argument_list|(
argument|bool b
argument_list|)
block|{
name|CallsUnwindInit
operator|=
name|b
block|; }
comment|/// NextLabelID - Return the next unique label id.
comment|///
name|unsigned
name|NextLabelID
argument_list|()
block|{
name|unsigned
name|ID
operator|=
operator|(
name|unsigned
operator|)
name|LabelIDList
operator|.
name|size
argument_list|()
operator|+
literal|1
block|;
name|LabelIDList
operator|.
name|push_back
argument_list|(
name|ID
argument_list|)
block|;
return|return
name|ID
return|;
block|}
comment|/// InvalidateLabel - Inhibit use of the specified label # from
comment|/// MachineModuleInfo, for example because the code was deleted.
name|void
name|InvalidateLabel
argument_list|(
argument|unsigned LabelID
argument_list|)
block|{
comment|// Remap to zero to indicate deletion.
name|RemapLabel
argument_list|(
name|LabelID
argument_list|,
literal|0
argument_list|)
block|;   }
comment|/// RemapLabel - Indicate that a label has been merged into another.
comment|///
name|void
name|RemapLabel
argument_list|(
argument|unsigned OldLabelID
argument_list|,
argument|unsigned NewLabelID
argument_list|)
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
block|;
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
block|;
name|LabelIDList
index|[
name|OldLabelID
operator|-
literal|1
index|]
operator|=
name|NewLabelID
block|;   }
comment|/// MappedLabel - Find out the label's final ID.  Zero indicates deletion.
comment|/// ID != Mapped ID indicates that the label was folded into another label.
name|unsigned
name|MappedLabel
argument_list|(
argument|unsigned LabelID
argument_list|)
specifier|const
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
block|;
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
comment|/// isDbgLabelUsed - Return true if label with LabelID is used by
comment|/// DwarfWriter.
name|bool
name|isDbgLabelUsed
argument_list|(
argument|unsigned LabelID
argument_list|)
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
comment|/// RecordUsedDbgLabel - Mark label with LabelID as used. This is used
comment|/// by DwarfWriter to inform DebugLabelFolder that certain labels are
comment|/// not to be deleted.
name|void
name|RecordUsedDbgLabel
argument_list|(
argument|unsigned LabelID
argument_list|)
block|{
name|UsedDbgLabels
operator|.
name|insert
argument_list|(
name|LabelID
argument_list|)
block|;   }
comment|/// getFrameMoves - Returns a reference to a list of moves done in the current
comment|/// function's prologue.  Used to construct frame maps for debug and exception
comment|/// handling comsumers.
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
comment|//===-EH-----------------------------------------------------------------===//
comment|/// getOrCreateLandingPadInfo - Find or create an LandingPadInfo for the
comment|/// specified MachineBasicBlock.
name|LandingPadInfo
operator|&
name|getOrCreateLandingPadInfo
argument_list|(
name|MachineBasicBlock
operator|*
name|LandingPad
argument_list|)
block|;
comment|/// addInvoke - Provide the begin and end labels of an invoke style call and
comment|/// associate it with a try landing pad block.
name|void
name|addInvoke
argument_list|(
argument|MachineBasicBlock *LandingPad
argument_list|,
argument|unsigned BeginLabel
argument_list|,
argument|unsigned EndLabel
argument_list|)
block|;
comment|/// addLandingPad - Add a new panding pad.  Returns the label ID for the
comment|/// landing pad entry.
name|unsigned
name|addLandingPad
argument_list|(
name|MachineBasicBlock
operator|*
name|LandingPad
argument_list|)
block|;
comment|/// addPersonality - Provide the personality function for the exception
comment|/// information.
name|void
name|addPersonality
argument_list|(
name|MachineBasicBlock
operator|*
name|LandingPad
argument_list|,
name|Function
operator|*
name|Personality
argument_list|)
block|;
comment|/// getPersonalityIndex - Get index of the current personality function inside
comment|/// Personalitites array
name|unsigned
name|getPersonalityIndex
argument_list|()
specifier|const
block|;
comment|/// getPersonalities - Return array of personality functions ever seen.
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
comment|// UsedFunctions - Return set of the functions in the llvm.used list.
specifier|const
name|SmallPtrSet
operator|<
specifier|const
name|Function
operator|*
block|,
literal|32
operator|>
operator|&
name|getUsedFunctions
argument_list|()
specifier|const
block|{
return|return
name|UsedFunctions
return|;
block|}
comment|/// addCatchTypeInfo - Provide the catch typeinfo for a landing pad.
comment|///
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
block|;
comment|/// addFilterTypeInfo - Provide the filter typeinfo for a landing pad.
comment|///
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
block|;
comment|/// addCleanup - Add a cleanup action for a landing pad.
comment|///
name|void
name|addCleanup
argument_list|(
name|MachineBasicBlock
operator|*
name|LandingPad
argument_list|)
block|;
comment|/// getTypeIDFor - Return the type id for the specified typeinfo.  This is
comment|/// function wide.
name|unsigned
name|getTypeIDFor
argument_list|(
name|GlobalVariable
operator|*
name|TI
argument_list|)
block|;
comment|/// getFilterIDFor - Return the id of the filter encoded by TyIds.  This is
comment|/// function wide.
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
block|;
comment|/// TidyLandingPads - Remap landing pad labels and remove any deleted landing
comment|/// pads.
name|void
name|TidyLandingPads
argument_list|()
block|;
comment|/// getLandingPads - Return a reference to the landing pad info for the
comment|/// current function.
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
comment|/// getTypeInfos - Return a reference to the C++ typeinfo for the current
comment|/// function.
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
comment|/// getFilterIds - Return a reference to the typeids encoding filters used in
comment|/// the current function.
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
comment|/// getPersonality - Return a personality function if available.  The presence
comment|/// of one is required to emit exception handling info.
name|Function
operator|*
name|getPersonality
argument_list|()
specifier|const
block|;  }
decl_stmt|;
comment|// End class MachineModuleInfo
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

