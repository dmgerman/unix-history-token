begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lldb-private-enumerations.h -----------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLDB_lldb_private_enumerations_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_lldb_private_enumerations_h_
end_define

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|// Thread Step Types
comment|//----------------------------------------------------------------------
typedef|typedef
enum|enum
name|StepType
block|{
name|eStepTypeNone
block|,
name|eStepTypeTrace
block|,
comment|///< Single step one instruction.
name|eStepTypeTraceOver
block|,
comment|///< Single step one instruction, stepping over.
name|eStepTypeInto
block|,
comment|///< Single step into a specified context.
name|eStepTypeOver
block|,
comment|///< Single step over a specified context.
name|eStepTypeOut
comment|///< Single step out a specified context.
block|}
name|StepType
typedef|;
comment|//----------------------------------------------------------------------
comment|// Address Types
comment|//----------------------------------------------------------------------
typedef|typedef
enum|enum
name|AddressType
block|{
name|eAddressTypeInvalid
init|=
literal|0
block|,
name|eAddressTypeFile
block|,
comment|///< Address is an address as found in an object or symbol file
name|eAddressTypeLoad
block|,
comment|///< Address is an address as in the current target inferior process
name|eAddressTypeHost
comment|///< Address is an address in the process that is running this code
block|}
name|AddressType
typedef|;
comment|//----------------------------------------------------------------------
comment|// Votes - Need a tri-state, yes, no, no opinion...
comment|//----------------------------------------------------------------------
typedef|typedef
enum|enum
name|Vote
block|{
name|eVoteNo
init|=
operator|-
literal|1
block|,
name|eVoteNoOpinion
init|=
literal|0
block|,
name|eVoteYes
init|=
literal|1
block|}
name|Vote
typedef|;
typedef|typedef
enum|enum
name|ArchitectureType
block|{
name|eArchTypeInvalid
block|,
name|eArchTypeMachO
block|,
name|eArchTypeELF
block|,
name|eArchTypeCOFF
block|,
name|kNumArchTypes
block|}
name|ArchitectureType
typedef|;
comment|//----------------------------------------------------------------------
comment|/// Settable state variable types.
comment|///
comment|//----------------------------------------------------------------------
comment|//typedef enum SettableVariableType
comment|//{
comment|//    eSetVarTypeInt,
comment|//    eSetVarTypeBoolean,
comment|//    eSetVarTypeString,
comment|//    eSetVarTypeArray,
comment|//    eSetVarTypeDictionary,
comment|//    eSetVarTypeEnum,
comment|//    eSetVarTypeNone
comment|//} SettableVariableType;
typedef|typedef
enum|enum
name|VarSetOperationType
block|{
name|eVarSetOperationReplace
block|,
name|eVarSetOperationInsertBefore
block|,
name|eVarSetOperationInsertAfter
block|,
name|eVarSetOperationRemove
block|,
name|eVarSetOperationAppend
block|,
name|eVarSetOperationClear
block|,
name|eVarSetOperationAssign
block|,
name|eVarSetOperationInvalid
block|}
name|VarSetOperationType
typedef|;
typedef|typedef
enum|enum
name|ArgumentRepetitionType
block|{
name|eArgRepeatPlain
block|,
comment|// Exactly one occurrence
name|eArgRepeatOptional
block|,
comment|// At most one occurrence, but it's optional
name|eArgRepeatPlus
block|,
comment|// One or more occurrences
name|eArgRepeatStar
block|,
comment|// Zero or more occurrences
name|eArgRepeatRange
block|,
comment|// Repetition of same argument, from 1 to n
name|eArgRepeatPairPlain
block|,
comment|// A pair of arguments that must always go together ([arg-type arg-value]), occurs exactly once
name|eArgRepeatPairOptional
block|,
comment|// A pair that occurs at most once (optional)
name|eArgRepeatPairPlus
block|,
comment|// One or more occurrences of a pair
name|eArgRepeatPairStar
block|,
comment|// Zero or more occurrences of a pair
name|eArgRepeatPairRange
block|,
comment|// A pair that repeats from 1 to n
name|eArgRepeatPairRangeOptional
comment|// A pair that repeats from 1 to n, but is optional
block|}
name|ArgumentRepetitionType
typedef|;
typedef|typedef
enum|enum
name|SortOrder
block|{
name|eSortOrderNone
block|,
name|eSortOrderByAddress
block|,
name|eSortOrderByName
block|}
name|SortOrder
typedef|;
comment|//----------------------------------------------------------------------
comment|// Used in conjunction with Host::GetLLDBPath () to find files that
comment|// are related to
comment|//----------------------------------------------------------------------
typedef|typedef
enum|enum
name|PathType
block|{
name|ePathTypeLLDBShlibDir
block|,
comment|// The directory where the lldb.so (unix) or LLDB mach-o file in LLDB.framework (MacOSX) exists
name|ePathTypeSupportExecutableDir
block|,
comment|// Find LLDB support executable directory (debugserver, etc)
name|ePathTypeHeaderDir
block|,
comment|// Find LLDB header file directory
name|ePathTypePythonDir
block|,
comment|// Find Python modules (PYTHONPATH) directory
name|ePathTypeLLDBSystemPlugins
block|,
comment|// System plug-ins directory
name|ePathTypeLLDBUserPlugins
block|,
comment|// User plug-ins directory
name|ePathTypeLLDBTempSystemDir
comment|// The LLDB temp directory for this system
block|}
name|PathType
typedef|;
comment|//----------------------------------------------------------------------
comment|// We can execute ThreadPlans on one thread with various fall-back modes
comment|// (try other threads after timeout, etc.) This enum gives the result of
comment|// thread plan executions.
comment|//----------------------------------------------------------------------
typedef|typedef
enum|enum
name|ExecutionResults
block|{
name|eExecutionSetupError
block|,
name|eExecutionCompleted
block|,
name|eExecutionDiscarded
block|,
name|eExecutionInterrupted
block|,
name|eExecutionHitBreakpoint
block|,
name|eExecutionTimedOut
block|,
name|eExecutionStoppedForDebug
block|}
name|ExecutionResults
typedef|;
typedef|typedef
enum|enum
name|ObjCRuntimeVersions
block|{
name|eObjC_VersionUnknown
init|=
literal|0
block|,
name|eAppleObjC_V1
init|=
literal|1
block|,
name|eAppleObjC_V2
init|=
literal|2
block|}
name|ObjCRuntimeVersions
typedef|;
comment|//----------------------------------------------------------------------
comment|// LazyBool is for boolean values that need to be calculated lazily.
comment|// Values start off set to eLazyBoolCalculate, and then they can be
comment|// calculated once and set to eLazyBoolNo or eLazyBoolYes.
comment|//----------------------------------------------------------------------
typedef|typedef
enum|enum
name|LazyBool
block|{
name|eLazyBoolCalculate
init|=
operator|-
literal|1
block|,
name|eLazyBoolNo
init|=
literal|0
block|,
name|eLazyBoolYes
init|=
literal|1
block|}
name|LazyBool
typedef|;
comment|//------------------------------------------------------------------
comment|/// Name matching
comment|//------------------------------------------------------------------
typedef|typedef
enum|enum
name|NameMatchType
block|{
name|eNameMatchIgnore
block|,
name|eNameMatchEquals
block|,
name|eNameMatchContains
block|,
name|eNameMatchStartsWith
block|,
name|eNameMatchEndsWith
block|,
name|eNameMatchRegularExpression
block|}
name|NameMatchType
typedef|;
comment|//------------------------------------------------------------------
comment|/// Instruction types
comment|//------------------------------------------------------------------
typedef|typedef
enum|enum
name|InstructionType
block|{
name|eInstructionTypeAny
block|,
comment|// Support for any instructions at all (at least one)
name|eInstructionTypePrologueEpilogue
block|,
comment|// All prologue and epilogue instructons that push and pop register values and modify sp/fp
name|eInstructionTypePCModifying
block|,
comment|// Any instruction that modifies the program counter/instruction pointer
name|eInstructionTypeAll
comment|// All instructions of any kind
block|}
name|InstructionType
typedef|;
comment|//------------------------------------------------------------------
comment|/// Format category entry types
comment|//------------------------------------------------------------------
typedef|typedef
enum|enum
name|FormatCategoryItem
block|{
name|eFormatCategoryItemSummary
init|=
literal|0x0001
block|,
name|eFormatCategoryItemRegexSummary
init|=
literal|0x0002
block|,
name|eFormatCategoryItemFilter
init|=
literal|0x0004
block|,
name|eFormatCategoryItemRegexFilter
init|=
literal|0x0008
block|,
name|eFormatCategoryItemSynth
init|=
literal|0x0010
block|,
name|eFormatCategoryItemRegexSynth
init|=
literal|0x0020
block|,
name|eFormatCategoryItemValue
init|=
literal|0x0040
block|,
name|eFormatCategoryItemRegexValue
init|=
literal|0x0080
block|}
name|FormatCategoryItem
typedef|;
comment|//------------------------------------------------------------------
comment|/// Expression execution policies
comment|//------------------------------------------------------------------
typedef|typedef
enum|enum
block|{
name|eExecutionPolicyOnlyWhenNeeded
block|,
name|eExecutionPolicyNever
block|,
name|eExecutionPolicyAlways
block|}
name|ExecutionPolicy
typedef|;
comment|//----------------------------------------------------------------------
comment|// Ways that the FormatManager picks a particular format for a type
comment|//----------------------------------------------------------------------
typedef|typedef
enum|enum
name|FormatterChoiceCriterion
block|{
name|eFormatterChoiceCriterionDirectChoice
init|=
literal|0x00000000
block|,
name|eFormatterChoiceCriterionStrippedPointerReference
init|=
literal|0x00000001
block|,
name|eFormatterChoiceCriterionNavigatedTypedefs
init|=
literal|0x00000002
block|,
name|eFormatterChoiceCriterionRegularExpressionSummary
init|=
literal|0x00000004
block|,
name|eFormatterChoiceCriterionRegularExpressionFilter
init|=
literal|0x00000004
block|,
name|eFormatterChoiceCriterionDynamicObjCDiscovery
init|=
literal|0x00000008
block|,
name|eFormatterChoiceCriterionStrippedBitField
init|=
literal|0x00000010
block|,
name|eFormatterChoiceCriterionWentToStaticValue
init|=
literal|0x00000020
block|}
name|FormatterChoiceCriterion
typedef|;
comment|//----------------------------------------------------------------------
comment|// Synchronicity behavior of scripted commands
comment|//----------------------------------------------------------------------
typedef|typedef
enum|enum
name|ScriptedCommandSynchronicity
block|{
name|eScriptedCommandSynchronicitySynchronous
block|,
name|eScriptedCommandSynchronicityAsynchronous
block|,
name|eScriptedCommandSynchronicityCurrentValue
comment|// use whatever the current synchronicity is
block|}
name|ScriptedCommandSynchronicity
typedef|;
comment|//----------------------------------------------------------------------
comment|// Verbosity mode of "po" output
comment|//----------------------------------------------------------------------
typedef|typedef
enum|enum
name|LanguageRuntimeDescriptionDisplayVerbosity
block|{
name|eLanguageRuntimeDescriptionDisplayVerbosityCompact
block|,
comment|// only print the description string, if any
name|eLanguageRuntimeDescriptionDisplayVerbosityFull
block|,
comment|// print the full-blown output
block|}
name|LanguageRuntimeDescriptionDisplayVerbosity
typedef|;
comment|//----------------------------------------------------------------------
comment|// Loading modules from memory
comment|//----------------------------------------------------------------------
typedef|typedef
enum|enum
name|MemoryModuleLoadLevel
block|{
name|eMemoryModuleLoadLevelMinimal
block|,
comment|// Load sections only
name|eMemoryModuleLoadLevelPartial
block|,
comment|// Load function bounds but no symbols
name|eMemoryModuleLoadLevelComplete
block|,
comment|// Load sections and all symbols
block|}
name|MemoryModuleLoadLevel
typedef|;
comment|//----------------------------------------------------------------------
comment|// Result enums for when reading multiple lines from IOHandlers
comment|//----------------------------------------------------------------------
name|enum
name|class
name|LineStatus
block|{
name|Success
operator|,
comment|// The line that was just edited if good and should be added to the lines
name|Error
operator|,
comment|// There is an error with the current line and it needs to be re-edited before it can be accepted
name|Done
comment|// Lines are complete
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_lldb_private_enumerations_h_
end_comment

end_unit

