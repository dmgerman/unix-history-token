begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/IR/DiagnosticInfo.h - Diagnostic Declaration --------*- C++ -*-===//
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
comment|// This file declares the different classes involved in low level diagnostics.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Diagnostics reporting is still done as part of the LLVMContext.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_IR_DIAGNOSTICINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_DIAGNOSTICINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
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
file|"llvm/IR/DebugLoc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CBindingWrapping.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/YAMLTraits.h"
end_include

begin_include
include|#
directive|include
file|"llvm-c/Types.h"
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Forward declarations.
name|class
name|DiagnosticPrinter
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|SMDiagnostic
decl_stmt|;
comment|/// \brief Defines the different supported severity of a diagnostic.
enum|enum
name|DiagnosticSeverity
enum|:
name|char
block|{
name|DS_Error
block|,
name|DS_Warning
block|,
name|DS_Remark
block|,
comment|// A note attaches additional information to one of the previous diagnostic
comment|// types.
name|DS_Note
block|}
enum|;
comment|/// \brief Defines the different supported kind of a diagnostic.
comment|/// This enum should be extended with a new ID for each added concrete subclass.
enum|enum
name|DiagnosticKind
block|{
name|DK_InlineAsm
block|,
name|DK_ResourceLimit
block|,
name|DK_StackSize
block|,
name|DK_Linker
block|,
name|DK_DebugMetadataVersion
block|,
name|DK_DebugMetadataInvalid
block|,
name|DK_ISelFallback
block|,
name|DK_SampleProfile
block|,
name|DK_OptimizationRemark
block|,
name|DK_OptimizationRemarkMissed
block|,
name|DK_OptimizationRemarkAnalysis
block|,
name|DK_OptimizationRemarkAnalysisFPCommute
block|,
name|DK_OptimizationRemarkAnalysisAliasing
block|,
name|DK_OptimizationFailure
block|,
name|DK_FirstRemark
init|=
name|DK_OptimizationRemark
block|,
name|DK_LastRemark
init|=
name|DK_OptimizationFailure
block|,
name|DK_MachineOptimizationRemark
block|,
name|DK_MachineOptimizationRemarkMissed
block|,
name|DK_MachineOptimizationRemarkAnalysis
block|,
name|DK_FirstMachineRemark
init|=
name|DK_MachineOptimizationRemark
block|,
name|DK_LastMachineRemark
init|=
name|DK_MachineOptimizationRemarkAnalysis
block|,
name|DK_MIRParser
block|,
name|DK_PGOProfile
block|,
name|DK_Unsupported
block|,
name|DK_FirstPluginKind
block|}
enum|;
comment|/// \brief Get the next available kind ID for a plugin diagnostic.
comment|/// Each time this function is called, it returns a different number.
comment|/// Therefore, a plugin that wants to "identify" its own classes
comment|/// with a dynamic identifier, just have to use this method to get a new ID
comment|/// and assign it to each of its classes.
comment|/// The returned ID will be greater than or equal to DK_FirstPluginKind.
comment|/// Thus, the plugin identifiers will not conflict with the
comment|/// DiagnosticKind values.
name|int
name|getNextAvailablePluginDiagnosticKind
parameter_list|()
function_decl|;
comment|/// \brief This is the base abstract class for diagnostic reporting in
comment|/// the backend.
comment|/// The print method must be overloaded by the subclasses to print a
comment|/// user-friendly message in the client of the backend (let us call it a
comment|/// frontend).
name|class
name|DiagnosticInfo
block|{
name|private
label|:
comment|/// Kind defines the kind of report this is about.
specifier|const
comment|/* DiagnosticKind */
name|int
name|Kind
decl_stmt|;
comment|/// Severity gives the severity of the diagnostic.
specifier|const
name|DiagnosticSeverity
name|Severity
decl_stmt|;
name|public
label|:
name|DiagnosticInfo
argument_list|(
comment|/* DiagnosticKind */
argument|int Kind
argument_list|,
argument|DiagnosticSeverity Severity
argument_list|)
block|:
name|Kind
argument_list|(
name|Kind
argument_list|)
operator|,
name|Severity
argument_list|(
argument|Severity
argument_list|)
block|{}
name|virtual
operator|~
name|DiagnosticInfo
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/* DiagnosticKind */
name|int
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
name|DiagnosticSeverity
name|getSeverity
argument_list|()
specifier|const
block|{
return|return
name|Severity
return|;
block|}
comment|/// Print using the given \p DP a user-friendly message.
comment|/// This is the default message that will be printed to the user.
comment|/// It is used when the frontend does not directly take advantage
comment|/// of the information contained in fields of the subclasses.
comment|/// The printed message must not end with '.' nor start with a severity
comment|/// keyword.
name|virtual
name|void
name|print
argument_list|(
name|DiagnosticPrinter
operator|&
name|DP
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
name|using
name|DiagnosticHandlerFunction
init|=
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
specifier|const
name|DiagnosticInfo
operator|&
argument_list|)
operator|>
decl_stmt|;
comment|/// Diagnostic information for inline asm reporting.
comment|/// This is basically a message and an optional location.
name|class
name|DiagnosticInfoInlineAsm
range|:
name|public
name|DiagnosticInfo
block|{
name|private
operator|:
comment|/// Optional line information. 0 if not set.
name|unsigned
name|LocCookie
operator|=
literal|0
block|;
comment|/// Message to be reported.
specifier|const
name|Twine
operator|&
name|MsgStr
block|;
comment|/// Optional origin of the problem.
specifier|const
name|Instruction
operator|*
name|Instr
operator|=
name|nullptr
block|;
name|public
operator|:
comment|/// \p MsgStr is the message to be reported to the frontend.
comment|/// This class does not copy \p MsgStr, therefore the reference must be valid
comment|/// for the whole life time of the Diagnostic.
name|DiagnosticInfoInlineAsm
argument_list|(
argument|const Twine&MsgStr
argument_list|,
argument|DiagnosticSeverity Severity = DS_Error
argument_list|)
operator|:
name|DiagnosticInfo
argument_list|(
name|DK_InlineAsm
argument_list|,
name|Severity
argument_list|)
block|,
name|MsgStr
argument_list|(
argument|MsgStr
argument_list|)
block|{}
comment|/// \p LocCookie if non-zero gives the line number for this report.
comment|/// \p MsgStr gives the message.
comment|/// This class does not copy \p MsgStr, therefore the reference must be valid
comment|/// for the whole life time of the Diagnostic.
name|DiagnosticInfoInlineAsm
argument_list|(
argument|unsigned LocCookie
argument_list|,
argument|const Twine&MsgStr
argument_list|,
argument|DiagnosticSeverity Severity = DS_Error
argument_list|)
operator|:
name|DiagnosticInfo
argument_list|(
name|DK_InlineAsm
argument_list|,
name|Severity
argument_list|)
block|,
name|LocCookie
argument_list|(
name|LocCookie
argument_list|)
block|,
name|MsgStr
argument_list|(
argument|MsgStr
argument_list|)
block|{}
comment|/// \p Instr gives the original instruction that triggered the diagnostic.
comment|/// \p MsgStr gives the message.
comment|/// This class does not copy \p MsgStr, therefore the reference must be valid
comment|/// for the whole life time of the Diagnostic.
comment|/// Same for \p I.
name|DiagnosticInfoInlineAsm
argument_list|(
argument|const Instruction&I
argument_list|,
argument|const Twine&MsgStr
argument_list|,
argument|DiagnosticSeverity Severity = DS_Error
argument_list|)
block|;
name|unsigned
name|getLocCookie
argument_list|()
specifier|const
block|{
return|return
name|LocCookie
return|;
block|}
specifier|const
name|Twine
operator|&
name|getMsgStr
argument_list|()
specifier|const
block|{
return|return
name|MsgStr
return|;
block|}
specifier|const
name|Instruction
operator|*
name|getInstruction
argument_list|()
specifier|const
block|{
return|return
name|Instr
return|;
block|}
comment|/// \see DiagnosticInfo::print.
name|void
name|print
argument_list|(
argument|DiagnosticPrinter&DP
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const DiagnosticInfo *DI
argument_list|)
block|{
return|return
name|DI
operator|->
name|getKind
argument_list|()
operator|==
name|DK_InlineAsm
return|;
block|}
expr|}
block|;
comment|/// Diagnostic information for stack size etc. reporting.
comment|/// This is basically a function and a size.
name|class
name|DiagnosticInfoResourceLimit
operator|:
name|public
name|DiagnosticInfo
block|{
name|private
operator|:
comment|/// The function that is concerned by this resource limit diagnostic.
specifier|const
name|Function
operator|&
name|Fn
block|;
comment|/// Description of the resource type (e.g. stack size)
specifier|const
name|char
operator|*
name|ResourceName
block|;
comment|/// The computed size usage
name|uint64_t
name|ResourceSize
block|;
comment|// Threshould passed
name|uint64_t
name|ResourceLimit
block|;
name|public
operator|:
comment|/// \p The function that is concerned by this stack size diagnostic.
comment|/// \p The computed stack size.
name|DiagnosticInfoResourceLimit
argument_list|(
argument|const Function&Fn
argument_list|,
argument|const char *ResourceName
argument_list|,
argument|uint64_t ResourceSize
argument_list|,
argument|DiagnosticSeverity Severity = DS_Warning
argument_list|,
argument|DiagnosticKind Kind = DK_ResourceLimit
argument_list|,
argument|uint64_t ResourceLimit =
literal|0
argument_list|)
operator|:
name|DiagnosticInfo
argument_list|(
name|Kind
argument_list|,
name|Severity
argument_list|)
block|,
name|Fn
argument_list|(
name|Fn
argument_list|)
block|,
name|ResourceName
argument_list|(
name|ResourceName
argument_list|)
block|,
name|ResourceSize
argument_list|(
name|ResourceSize
argument_list|)
block|,
name|ResourceLimit
argument_list|(
argument|ResourceLimit
argument_list|)
block|{}
specifier|const
name|Function
operator|&
name|getFunction
argument_list|()
specifier|const
block|{
return|return
name|Fn
return|;
block|}
specifier|const
name|char
operator|*
name|getResourceName
argument_list|()
specifier|const
block|{
return|return
name|ResourceName
return|;
block|}
name|uint64_t
name|getResourceSize
argument_list|()
specifier|const
block|{
return|return
name|ResourceSize
return|;
block|}
name|uint64_t
name|getResourceLimit
argument_list|()
specifier|const
block|{
return|return
name|ResourceLimit
return|;
block|}
comment|/// \see DiagnosticInfo::print.
name|void
name|print
argument_list|(
argument|DiagnosticPrinter&DP
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const DiagnosticInfo *DI
argument_list|)
block|{
return|return
name|DI
operator|->
name|getKind
argument_list|()
operator|==
name|DK_ResourceLimit
operator|||
name|DI
operator|->
name|getKind
argument_list|()
operator|==
name|DK_StackSize
return|;
block|}
expr|}
block|;
name|class
name|DiagnosticInfoStackSize
operator|:
name|public
name|DiagnosticInfoResourceLimit
block|{
name|public
operator|:
name|DiagnosticInfoStackSize
argument_list|(
argument|const Function&Fn
argument_list|,
argument|uint64_t StackSize
argument_list|,
argument|DiagnosticSeverity Severity = DS_Warning
argument_list|,
argument|uint64_t StackLimit =
literal|0
argument_list|)
operator|:
name|DiagnosticInfoResourceLimit
argument_list|(
argument|Fn
argument_list|,
literal|"stack size"
argument_list|,
argument|StackSize
argument_list|,
argument|Severity
argument_list|,
argument|DK_StackSize
argument_list|,
argument|StackLimit
argument_list|)
block|{}
name|uint64_t
name|getStackSize
argument_list|()
specifier|const
block|{
return|return
name|getResourceSize
argument_list|()
return|;
block|}
name|uint64_t
name|getStackLimit
argument_list|()
specifier|const
block|{
return|return
name|getResourceLimit
argument_list|()
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const DiagnosticInfo *DI
argument_list|)
block|{
return|return
name|DI
operator|->
name|getKind
argument_list|()
operator|==
name|DK_StackSize
return|;
block|}
expr|}
block|;
comment|/// Diagnostic information for debug metadata version reporting.
comment|/// This is basically a module and a version.
name|class
name|DiagnosticInfoDebugMetadataVersion
operator|:
name|public
name|DiagnosticInfo
block|{
name|private
operator|:
comment|/// The module that is concerned by this debug metadata version diagnostic.
specifier|const
name|Module
operator|&
name|M
block|;
comment|/// The actual metadata version.
name|unsigned
name|MetadataVersion
block|;
name|public
operator|:
comment|/// \p The module that is concerned by this debug metadata version diagnostic.
comment|/// \p The actual metadata version.
name|DiagnosticInfoDebugMetadataVersion
argument_list|(
argument|const Module&M
argument_list|,
argument|unsigned MetadataVersion
argument_list|,
argument|DiagnosticSeverity Severity = DS_Warning
argument_list|)
operator|:
name|DiagnosticInfo
argument_list|(
name|DK_DebugMetadataVersion
argument_list|,
name|Severity
argument_list|)
block|,
name|M
argument_list|(
name|M
argument_list|)
block|,
name|MetadataVersion
argument_list|(
argument|MetadataVersion
argument_list|)
block|{}
specifier|const
name|Module
operator|&
name|getModule
argument_list|()
specifier|const
block|{
return|return
name|M
return|;
block|}
name|unsigned
name|getMetadataVersion
argument_list|()
specifier|const
block|{
return|return
name|MetadataVersion
return|;
block|}
comment|/// \see DiagnosticInfo::print.
name|void
name|print
argument_list|(
argument|DiagnosticPrinter&DP
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const DiagnosticInfo *DI
argument_list|)
block|{
return|return
name|DI
operator|->
name|getKind
argument_list|()
operator|==
name|DK_DebugMetadataVersion
return|;
block|}
expr|}
block|;
comment|/// Diagnostic information for stripping invalid debug metadata.
name|class
name|DiagnosticInfoIgnoringInvalidDebugMetadata
operator|:
name|public
name|DiagnosticInfo
block|{
name|private
operator|:
comment|/// The module that is concerned by this debug metadata version diagnostic.
specifier|const
name|Module
operator|&
name|M
block|;
name|public
operator|:
comment|/// \p The module that is concerned by this debug metadata version diagnostic.
name|DiagnosticInfoIgnoringInvalidDebugMetadata
argument_list|(
argument|const Module&M
argument_list|,
argument|DiagnosticSeverity Severity = DS_Warning
argument_list|)
operator|:
name|DiagnosticInfo
argument_list|(
name|DK_DebugMetadataVersion
argument_list|,
name|Severity
argument_list|)
block|,
name|M
argument_list|(
argument|M
argument_list|)
block|{}
specifier|const
name|Module
operator|&
name|getModule
argument_list|()
specifier|const
block|{
return|return
name|M
return|;
block|}
comment|/// \see DiagnosticInfo::print.
name|void
name|print
argument_list|(
argument|DiagnosticPrinter&DP
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const DiagnosticInfo *DI
argument_list|)
block|{
return|return
name|DI
operator|->
name|getKind
argument_list|()
operator|==
name|DK_DebugMetadataInvalid
return|;
block|}
expr|}
block|;
comment|/// Diagnostic information for the sample profiler.
name|class
name|DiagnosticInfoSampleProfile
operator|:
name|public
name|DiagnosticInfo
block|{
name|public
operator|:
name|DiagnosticInfoSampleProfile
argument_list|(
argument|StringRef FileName
argument_list|,
argument|unsigned LineNum
argument_list|,
argument|const Twine&Msg
argument_list|,
argument|DiagnosticSeverity Severity = DS_Error
argument_list|)
operator|:
name|DiagnosticInfo
argument_list|(
name|DK_SampleProfile
argument_list|,
name|Severity
argument_list|)
block|,
name|FileName
argument_list|(
name|FileName
argument_list|)
block|,
name|LineNum
argument_list|(
name|LineNum
argument_list|)
block|,
name|Msg
argument_list|(
argument|Msg
argument_list|)
block|{}
name|DiagnosticInfoSampleProfile
argument_list|(
argument|StringRef FileName
argument_list|,
argument|const Twine&Msg
argument_list|,
argument|DiagnosticSeverity Severity = DS_Error
argument_list|)
operator|:
name|DiagnosticInfo
argument_list|(
name|DK_SampleProfile
argument_list|,
name|Severity
argument_list|)
block|,
name|FileName
argument_list|(
name|FileName
argument_list|)
block|,
name|Msg
argument_list|(
argument|Msg
argument_list|)
block|{}
name|DiagnosticInfoSampleProfile
argument_list|(
argument|const Twine&Msg
argument_list|,
argument|DiagnosticSeverity Severity = DS_Error
argument_list|)
operator|:
name|DiagnosticInfo
argument_list|(
name|DK_SampleProfile
argument_list|,
name|Severity
argument_list|)
block|,
name|Msg
argument_list|(
argument|Msg
argument_list|)
block|{}
comment|/// \see DiagnosticInfo::print.
name|void
name|print
argument_list|(
argument|DiagnosticPrinter&DP
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const DiagnosticInfo *DI
argument_list|)
block|{
return|return
name|DI
operator|->
name|getKind
argument_list|()
operator|==
name|DK_SampleProfile
return|;
block|}
name|StringRef
name|getFileName
argument_list|()
specifier|const
block|{
return|return
name|FileName
return|;
block|}
name|unsigned
name|getLineNum
argument_list|()
specifier|const
block|{
return|return
name|LineNum
return|;
block|}
specifier|const
name|Twine
operator|&
name|getMsg
argument_list|()
specifier|const
block|{
return|return
name|Msg
return|;
block|}
name|private
operator|:
comment|/// Name of the input file associated with this diagnostic.
name|StringRef
name|FileName
block|;
comment|/// Line number where the diagnostic occurred. If 0, no line number will
comment|/// be emitted in the message.
name|unsigned
name|LineNum
operator|=
literal|0
block|;
comment|/// Message to report.
specifier|const
name|Twine
operator|&
name|Msg
block|; }
block|;
comment|/// Diagnostic information for the PGO profiler.
name|class
name|DiagnosticInfoPGOProfile
operator|:
name|public
name|DiagnosticInfo
block|{
name|public
operator|:
name|DiagnosticInfoPGOProfile
argument_list|(
argument|const char *FileName
argument_list|,
argument|const Twine&Msg
argument_list|,
argument|DiagnosticSeverity Severity = DS_Error
argument_list|)
operator|:
name|DiagnosticInfo
argument_list|(
name|DK_PGOProfile
argument_list|,
name|Severity
argument_list|)
block|,
name|FileName
argument_list|(
name|FileName
argument_list|)
block|,
name|Msg
argument_list|(
argument|Msg
argument_list|)
block|{}
comment|/// \see DiagnosticInfo::print.
name|void
name|print
argument_list|(
argument|DiagnosticPrinter&DP
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const DiagnosticInfo *DI
argument_list|)
block|{
return|return
name|DI
operator|->
name|getKind
argument_list|()
operator|==
name|DK_PGOProfile
return|;
block|}
specifier|const
name|char
operator|*
name|getFileName
argument_list|()
specifier|const
block|{
return|return
name|FileName
return|;
block|}
specifier|const
name|Twine
operator|&
name|getMsg
argument_list|()
specifier|const
block|{
return|return
name|Msg
return|;
block|}
name|private
operator|:
comment|/// Name of the input file associated with this diagnostic.
specifier|const
name|char
operator|*
name|FileName
block|;
comment|/// Message to report.
specifier|const
name|Twine
operator|&
name|Msg
block|; }
block|;
name|class
name|DiagnosticLocation
block|{
name|StringRef
name|Filename
block|;
name|unsigned
name|Line
operator|=
literal|0
block|;
name|unsigned
name|Column
operator|=
literal|0
block|;
name|public
operator|:
name|DiagnosticLocation
argument_list|()
operator|=
expr|default
block|;
name|DiagnosticLocation
argument_list|(
specifier|const
name|DebugLoc
operator|&
name|DL
argument_list|)
block|;
name|DiagnosticLocation
argument_list|(
specifier|const
name|DISubprogram
operator|*
name|SP
argument_list|)
block|;
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Filename
operator|.
name|empty
argument_list|()
return|;
block|}
name|StringRef
name|getFilename
argument_list|()
specifier|const
block|{
return|return
name|Filename
return|;
block|}
name|unsigned
name|getLine
argument_list|()
specifier|const
block|{
return|return
name|Line
return|;
block|}
name|unsigned
name|getColumn
argument_list|()
specifier|const
block|{
return|return
name|Column
return|;
block|}
expr|}
block|;
comment|/// Common features for diagnostics with an associated location.
name|class
name|DiagnosticInfoWithLocationBase
operator|:
name|public
name|DiagnosticInfo
block|{
name|public
operator|:
comment|/// \p Fn is the function where the diagnostic is being emitted. \p Loc is
comment|/// the location information to use in the diagnostic.
name|DiagnosticInfoWithLocationBase
argument_list|(
argument|enum DiagnosticKind Kind
argument_list|,
argument|enum DiagnosticSeverity Severity
argument_list|,
argument|const Function&Fn
argument_list|,
argument|const DiagnosticLocation&Loc
argument_list|)
operator|:
name|DiagnosticInfo
argument_list|(
name|Kind
argument_list|,
name|Severity
argument_list|)
block|,
name|Fn
argument_list|(
name|Fn
argument_list|)
block|,
name|Loc
argument_list|(
argument|Loc
argument_list|)
block|{}
comment|/// Return true if location information is available for this diagnostic.
name|bool
name|isLocationAvailable
argument_list|()
specifier|const
block|{
return|return
name|Loc
operator|.
name|isValid
argument_list|()
return|;
block|}
comment|/// Return a string with the location information for this diagnostic
comment|/// in the format "file:line:col". If location information is not available,
comment|/// it returns "<unknown>:0:0".
specifier|const
name|std
operator|::
name|string
name|getLocationStr
argument_list|()
specifier|const
block|;
comment|/// Return location information for this diagnostic in three parts:
comment|/// the source file name, line number and column.
name|void
name|getLocation
argument_list|(
argument|StringRef *Filename
argument_list|,
argument|unsigned *Line
argument_list|,
argument|unsigned *Column
argument_list|)
specifier|const
block|;
specifier|const
name|Function
operator|&
name|getFunction
argument_list|()
specifier|const
block|{
return|return
name|Fn
return|;
block|}
name|DiagnosticLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|Loc
return|;
block|}
name|private
operator|:
comment|/// Function where this diagnostic is triggered.
specifier|const
name|Function
operator|&
name|Fn
block|;
comment|/// Debug location where this diagnostic is triggered.
name|DiagnosticLocation
name|Loc
block|; }
block|;
comment|/// \brief Common features for diagnostics dealing with optimization remarks
comment|/// that are used by both IR and MIR passes.
name|class
name|DiagnosticInfoOptimizationBase
operator|:
name|public
name|DiagnosticInfoWithLocationBase
block|{
name|public
operator|:
comment|/// \brief Used to set IsVerbose via the stream interface.
expr|struct
name|setIsVerbose
block|{}
block|;
comment|/// \brief When an instance of this is inserted into the stream, the arguments
comment|/// following will not appear in the remark printed in the compiler output
comment|/// (-Rpass) but only in the optimization record file
comment|/// (-fsave-optimization-record).
block|struct
name|setExtraArgs
block|{}
block|;
comment|/// \brief Used in the streaming interface as the general argument type.  It
comment|/// internally converts everything into a key-value pair.
block|struct
name|Argument
block|{
name|StringRef
name|Key
block|;
name|std
operator|::
name|string
name|Val
block|;
comment|// If set, the debug location corresponding to the value.
name|DiagnosticLocation
name|Loc
block|;
name|explicit
name|Argument
argument_list|(
argument|StringRef Str =
literal|""
argument_list|)
operator|:
name|Key
argument_list|(
literal|"String"
argument_list|)
block|,
name|Val
argument_list|(
argument|Str
argument_list|)
block|{}
name|Argument
argument_list|(
argument|StringRef Key
argument_list|,
argument|const Value *V
argument_list|)
block|;
name|Argument
argument_list|(
argument|StringRef Key
argument_list|,
argument|const Type *T
argument_list|)
block|;
name|Argument
argument_list|(
argument|StringRef Key
argument_list|,
argument|int N
argument_list|)
block|;
name|Argument
argument_list|(
argument|StringRef Key
argument_list|,
argument|unsigned N
argument_list|)
block|;
name|Argument
argument_list|(
argument|StringRef Key
argument_list|,
argument|bool B
argument_list|)
operator|:
name|Key
argument_list|(
name|Key
argument_list|)
block|,
name|Val
argument_list|(
argument|B ?
literal|"true"
argument|:
literal|"false"
argument_list|)
block|{}
block|}
block|;
comment|/// \p PassName is the name of the pass emitting this diagnostic. \p
comment|/// RemarkName is a textual identifier for the remark (single-word,
comment|/// camel-case). \p Fn is the function where the diagnostic is being emitted.
comment|/// \p Loc is the location information to use in the diagnostic. If line table
comment|/// information is available, the diagnostic will include the source code
comment|/// location.
name|DiagnosticInfoOptimizationBase
argument_list|(
argument|enum DiagnosticKind Kind
argument_list|,
argument|enum DiagnosticSeverity Severity
argument_list|,
argument|const char *PassName
argument_list|,
argument|StringRef RemarkName
argument_list|,
argument|const Function&Fn
argument_list|,
argument|const DiagnosticLocation&Loc
argument_list|)
operator|:
name|DiagnosticInfoWithLocationBase
argument_list|(
name|Kind
argument_list|,
name|Severity
argument_list|,
name|Fn
argument_list|,
name|Loc
argument_list|)
block|,
name|PassName
argument_list|(
name|PassName
argument_list|)
block|,
name|RemarkName
argument_list|(
argument|RemarkName
argument_list|)
block|{}
name|DiagnosticInfoOptimizationBase
operator|&
name|operator
operator|<<
operator|(
name|StringRef
name|S
operator|)
block|;
name|DiagnosticInfoOptimizationBase
operator|&
name|operator
operator|<<
operator|(
name|Argument
name|A
operator|)
block|;
name|DiagnosticInfoOptimizationBase
operator|&
name|operator
operator|<<
operator|(
name|setIsVerbose
name|V
operator|)
block|;
name|DiagnosticInfoOptimizationBase
operator|&
name|operator
operator|<<
operator|(
name|setExtraArgs
name|EA
operator|)
block|;
comment|/// \see DiagnosticInfo::print.
name|void
name|print
argument_list|(
argument|DiagnosticPrinter&DP
argument_list|)
specifier|const
name|override
block|;
comment|/// Return true if this optimization remark is enabled by one of
comment|/// of the LLVM command line flags (-pass-remarks, -pass-remarks-missed,
comment|/// or -pass-remarks-analysis). Note that this only handles the LLVM
comment|/// flags. We cannot access Clang flags from here (they are handled
comment|/// in BackendConsumer::OptimizationRemarkHandler).
name|virtual
name|bool
name|isEnabled
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|StringRef
name|getPassName
argument_list|()
specifier|const
block|{
return|return
name|PassName
return|;
block|}
name|std
operator|::
name|string
name|getMsg
argument_list|()
specifier|const
block|;
name|Optional
operator|<
name|uint64_t
operator|>
name|getHotness
argument_list|()
specifier|const
block|{
return|return
name|Hotness
return|;
block|}
name|void
name|setHotness
argument_list|(
argument|Optional<uint64_t> H
argument_list|)
block|{
name|Hotness
operator|=
name|H
block|; }
name|bool
name|isVerbose
argument_list|()
specifier|const
block|{
return|return
name|IsVerbose
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const DiagnosticInfo *DI
argument_list|)
block|{
return|return
operator|(
name|DI
operator|->
name|getKind
argument_list|()
operator|>=
name|DK_FirstRemark
operator|&&
name|DI
operator|->
name|getKind
argument_list|()
operator|<=
name|DK_LastRemark
operator|)
operator|||
operator|(
name|DI
operator|->
name|getKind
argument_list|()
operator|>=
name|DK_FirstMachineRemark
operator|&&
name|DI
operator|->
name|getKind
argument_list|()
operator|<=
name|DK_LastMachineRemark
operator|)
return|;
block|}
name|bool
name|isPassed
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getKind
argument_list|()
operator|==
name|DK_OptimizationRemark
operator|||
name|getKind
argument_list|()
operator|==
name|DK_MachineOptimizationRemark
operator|)
return|;
block|}
name|bool
name|isMissed
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getKind
argument_list|()
operator|==
name|DK_OptimizationRemarkMissed
operator|||
name|getKind
argument_list|()
operator|==
name|DK_MachineOptimizationRemarkMissed
operator|)
return|;
block|}
name|bool
name|isAnalysis
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getKind
argument_list|()
operator|==
name|DK_OptimizationRemarkAnalysis
operator|||
name|getKind
argument_list|()
operator|==
name|DK_MachineOptimizationRemarkAnalysis
operator|)
return|;
block|}
name|protected
operator|:
comment|/// Name of the pass that triggers this report. If this matches the
comment|/// regular expression given in -Rpass=regexp, then the remark will
comment|/// be emitted.
specifier|const
name|char
operator|*
name|PassName
block|;
comment|/// Textual identifier for the remark (single-word, camel-case). Can be used
comment|/// by external tools reading the YAML output file for optimization remarks to
comment|/// identify the remark.
name|StringRef
name|RemarkName
block|;
comment|/// If profile information is available, this is the number of times the
comment|/// corresponding code was executed in a profile instrumentation run.
name|Optional
operator|<
name|uint64_t
operator|>
name|Hotness
block|;
comment|/// Arguments collected via the streaming interface.
name|SmallVector
operator|<
name|Argument
block|,
literal|4
operator|>
name|Args
block|;
comment|/// The remark is expected to be noisy.
name|bool
name|IsVerbose
operator|=
name|false
block|;
comment|/// \brief If positive, the index of the first argument that only appear in
comment|/// the optimization records and not in the remark printed in the compiler
comment|/// output.
name|int
name|FirstExtraArgIndex
operator|=
operator|-
literal|1
block|;
name|friend
expr|struct
name|yaml
operator|::
name|MappingTraits
operator|<
name|DiagnosticInfoOptimizationBase
operator|*
operator|>
block|; }
block|;
comment|/// \brief Common features for diagnostics dealing with optimization remarks
comment|/// that are used by IR passes.
name|class
name|DiagnosticInfoIROptimization
operator|:
name|public
name|DiagnosticInfoOptimizationBase
block|{
name|public
operator|:
comment|/// \p PassName is the name of the pass emitting this diagnostic. \p
comment|/// RemarkName is a textual identifier for the remark (single-word,
comment|/// camel-case). \p Fn is the function where the diagnostic is being emitted.
comment|/// \p Loc is the location information to use in the diagnostic. If line table
comment|/// information is available, the diagnostic will include the source code
comment|/// location. \p CodeRegion is IR value (currently basic block) that the
comment|/// optimization operates on. This is currently used to provide run-time
comment|/// hotness information with PGO.
name|DiagnosticInfoIROptimization
argument_list|(
argument|enum DiagnosticKind Kind
argument_list|,
argument|enum DiagnosticSeverity Severity
argument_list|,
argument|const char *PassName
argument_list|,
argument|StringRef RemarkName
argument_list|,
argument|const Function&Fn
argument_list|,
argument|const DiagnosticLocation&Loc
argument_list|,
argument|const Value *CodeRegion = nullptr
argument_list|)
operator|:
name|DiagnosticInfoOptimizationBase
argument_list|(
name|Kind
argument_list|,
name|Severity
argument_list|,
name|PassName
argument_list|,
name|RemarkName
argument_list|,
name|Fn
argument_list|,
name|Loc
argument_list|)
block|,
name|CodeRegion
argument_list|(
argument|CodeRegion
argument_list|)
block|{}
comment|/// \brief This is ctor variant allows a pass to build an optimization remark
comment|/// from an existing remark.
comment|///
comment|/// This is useful when a transformation pass (e.g LV) wants to emit a remark
comment|/// (\p Orig) generated by one of its analyses (e.g. LAA) as its own analysis
comment|/// remark.  The string \p Prepend will be emitted before the original
comment|/// message.
name|DiagnosticInfoIROptimization
argument_list|(
argument|const char *PassName
argument_list|,
argument|StringRef Prepend
argument_list|,
argument|const DiagnosticInfoIROptimization&Orig
argument_list|)
operator|:
name|DiagnosticInfoOptimizationBase
argument_list|(
operator|(
name|DiagnosticKind
operator|)
name|Orig
operator|.
name|getKind
argument_list|()
argument_list|,
name|Orig
operator|.
name|getSeverity
argument_list|()
argument_list|,
name|PassName
argument_list|,
name|Orig
operator|.
name|RemarkName
argument_list|,
name|Orig
operator|.
name|getFunction
argument_list|()
argument_list|,
name|Orig
operator|.
name|getLocation
argument_list|()
argument_list|)
block|,
name|CodeRegion
argument_list|(
argument|Orig.getCodeRegion()
argument_list|)
block|{
operator|*
name|this
operator|<<
name|Prepend
block|;
name|std
operator|::
name|copy
argument_list|(
name|Orig
operator|.
name|Args
operator|.
name|begin
argument_list|()
argument_list|,
name|Orig
operator|.
name|Args
operator|.
name|end
argument_list|()
argument_list|,
name|std
operator|::
name|back_inserter
argument_list|(
name|Args
argument_list|)
argument_list|)
block|;   }
comment|/// Legacy interface.
comment|/// \p PassName is the name of the pass emitting this diagnostic.
comment|/// \p Fn is the function where the diagnostic is being emitted. \p Loc is
comment|/// the location information to use in the diagnostic. If line table
comment|/// information is available, the diagnostic will include the source code
comment|/// location. \p Msg is the message to show. Note that this class does not
comment|/// copy this message, so this reference must be valid for the whole life time
comment|/// of the diagnostic.
name|DiagnosticInfoIROptimization
argument_list|(
argument|enum DiagnosticKind Kind
argument_list|,
argument|enum DiagnosticSeverity Severity
argument_list|,
argument|const char *PassName
argument_list|,
argument|const Function&Fn
argument_list|,
argument|const DiagnosticLocation&Loc
argument_list|,
argument|const Twine&Msg
argument_list|)
operator|:
name|DiagnosticInfoOptimizationBase
argument_list|(
argument|Kind
argument_list|,
argument|Severity
argument_list|,
argument|PassName
argument_list|,
literal|""
argument_list|,
argument|Fn
argument_list|,
argument|Loc
argument_list|)
block|{
operator|*
name|this
operator|<<
name|Msg
operator|.
name|str
argument_list|()
block|;   }
specifier|const
name|Value
operator|*
name|getCodeRegion
argument_list|()
specifier|const
block|{
return|return
name|CodeRegion
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const DiagnosticInfo *DI
argument_list|)
block|{
return|return
name|DI
operator|->
name|getKind
argument_list|()
operator|>=
name|DK_FirstRemark
operator|&&
name|DI
operator|->
name|getKind
argument_list|()
operator|<=
name|DK_LastRemark
return|;
block|}
name|private
operator|:
comment|/// The IR value (currently basic block) that the optimization operates on.
comment|/// This is currently used to provide run-time hotness information with PGO.
specifier|const
name|Value
operator|*
name|CodeRegion
block|; }
block|;
comment|/// Diagnostic information for applied optimization remarks.
name|class
name|OptimizationRemark
operator|:
name|public
name|DiagnosticInfoIROptimization
block|{
name|public
operator|:
comment|/// \p PassName is the name of the pass emitting this diagnostic. If this name
comment|/// matches the regular expression given in -Rpass=, then the diagnostic will
comment|/// be emitted. \p RemarkName is a textual identifier for the remark (single-
comment|/// word, camel-case). \p Loc is the debug location and \p CodeRegion is the
comment|/// region that the optimization operates on (currently only block is
comment|/// supported).
name|OptimizationRemark
argument_list|(
argument|const char *PassName
argument_list|,
argument|StringRef RemarkName
argument_list|,
argument|const DiagnosticLocation&Loc
argument_list|,
argument|const Value *CodeRegion
argument_list|)
block|;
comment|/// Same as above, but the debug location and code region are derived from \p
comment|/// Instr.
name|OptimizationRemark
argument_list|(
argument|const char *PassName
argument_list|,
argument|StringRef RemarkName
argument_list|,
argument|const Instruction *Inst
argument_list|)
block|;
comment|/// Same as above, but the debug location and code region are derived from \p
comment|/// Func.
name|OptimizationRemark
argument_list|(
argument|const char *PassName
argument_list|,
argument|StringRef RemarkName
argument_list|,
argument|const Function *Func
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const DiagnosticInfo *DI
argument_list|)
block|{
return|return
name|DI
operator|->
name|getKind
argument_list|()
operator|==
name|DK_OptimizationRemark
return|;
block|}
specifier|static
name|bool
name|isEnabled
argument_list|(
argument|StringRef PassName
argument_list|)
block|;
comment|/// \see DiagnosticInfoOptimizationBase::isEnabled.
name|bool
name|isEnabled
argument_list|()
specifier|const
name|override
block|{
return|return
name|isEnabled
argument_list|(
name|getPassName
argument_list|()
argument_list|)
return|;
block|}
name|private
operator|:
comment|/// This is deprecated now and only used by the function API below.
comment|/// \p PassName is the name of the pass emitting this diagnostic. If
comment|/// this name matches the regular expression given in -Rpass=, then the
comment|/// diagnostic will be emitted. \p Fn is the function where the diagnostic
comment|/// is being emitted. \p Loc is the location information to use in the
comment|/// diagnostic. If line table information is available, the diagnostic
comment|/// will include the source code location. \p Msg is the message to show.
comment|/// Note that this class does not copy this message, so this reference
comment|/// must be valid for the whole life time of the diagnostic.
name|OptimizationRemark
argument_list|(
specifier|const
name|char
operator|*
name|PassName
argument_list|,
specifier|const
name|Function
operator|&
name|Fn
argument_list|,
specifier|const
name|DiagnosticLocation
operator|&
name|Loc
argument_list|,
specifier|const
name|Twine
operator|&
name|Msg
argument_list|)
operator|:
name|DiagnosticInfoIROptimization
argument_list|(
argument|DK_OptimizationRemark
argument_list|,
argument|DS_Remark
argument_list|,
argument|PassName
argument_list|,
argument|Fn
argument_list|,
argument|Loc
argument_list|,
argument|Msg
argument_list|)
block|{}
name|friend
name|void
name|emitOptimizationRemark
argument_list|(
name|LLVMContext
operator|&
name|Ctx
argument_list|,
specifier|const
name|char
operator|*
name|PassName
argument_list|,
specifier|const
name|Function
operator|&
name|Fn
argument_list|,
specifier|const
name|DiagnosticLocation
operator|&
name|Loc
argument_list|,
specifier|const
name|Twine
operator|&
name|Msg
argument_list|)
block|; }
block|;
comment|/// Diagnostic information for missed-optimization remarks.
name|class
name|OptimizationRemarkMissed
operator|:
name|public
name|DiagnosticInfoIROptimization
block|{
name|public
operator|:
comment|/// \p PassName is the name of the pass emitting this diagnostic. If this name
comment|/// matches the regular expression given in -Rpass-missed=, then the
comment|/// diagnostic will be emitted. \p RemarkName is a textual identifier for the
comment|/// remark (single-word, camel-case). \p Loc is the debug location and \p
comment|/// CodeRegion is the region that the optimization operates on (currently only
comment|/// block is supported).
name|OptimizationRemarkMissed
argument_list|(
argument|const char *PassName
argument_list|,
argument|StringRef RemarkName
argument_list|,
argument|const DiagnosticLocation&Loc
argument_list|,
argument|const Value *CodeRegion
argument_list|)
block|;
comment|/// \brief Same as above but \p Inst is used to derive code region and debug
comment|/// location.
name|OptimizationRemarkMissed
argument_list|(
argument|const char *PassName
argument_list|,
argument|StringRef RemarkName
argument_list|,
argument|const Instruction *Inst
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const DiagnosticInfo *DI
argument_list|)
block|{
return|return
name|DI
operator|->
name|getKind
argument_list|()
operator|==
name|DK_OptimizationRemarkMissed
return|;
block|}
specifier|static
name|bool
name|isEnabled
argument_list|(
argument|StringRef PassName
argument_list|)
block|;
comment|/// \see DiagnosticInfoOptimizationBase::isEnabled.
name|bool
name|isEnabled
argument_list|()
specifier|const
name|override
block|{
return|return
name|isEnabled
argument_list|(
name|getPassName
argument_list|()
argument_list|)
return|;
block|}
name|private
operator|:
comment|/// This is deprecated now and only used by the function API below.
comment|/// \p PassName is the name of the pass emitting this diagnostic. If
comment|/// this name matches the regular expression given in -Rpass-missed=, then the
comment|/// diagnostic will be emitted. \p Fn is the function where the diagnostic
comment|/// is being emitted. \p Loc is the location information to use in the
comment|/// diagnostic. If line table information is available, the diagnostic
comment|/// will include the source code location. \p Msg is the message to show.
comment|/// Note that this class does not copy this message, so this reference
comment|/// must be valid for the whole life time of the diagnostic.
name|OptimizationRemarkMissed
argument_list|(
specifier|const
name|char
operator|*
name|PassName
argument_list|,
specifier|const
name|Function
operator|&
name|Fn
argument_list|,
specifier|const
name|DiagnosticLocation
operator|&
name|Loc
argument_list|,
specifier|const
name|Twine
operator|&
name|Msg
argument_list|)
operator|:
name|DiagnosticInfoIROptimization
argument_list|(
argument|DK_OptimizationRemarkMissed
argument_list|,
argument|DS_Remark
argument_list|,
argument|PassName
argument_list|,
argument|Fn
argument_list|,
argument|Loc
argument_list|,
argument|Msg
argument_list|)
block|{}
name|friend
name|void
name|emitOptimizationRemarkMissed
argument_list|(
name|LLVMContext
operator|&
name|Ctx
argument_list|,
specifier|const
name|char
operator|*
name|PassName
argument_list|,
specifier|const
name|Function
operator|&
name|Fn
argument_list|,
specifier|const
name|DiagnosticLocation
operator|&
name|Loc
argument_list|,
specifier|const
name|Twine
operator|&
name|Msg
argument_list|)
block|; }
block|;
comment|/// Diagnostic information for optimization analysis remarks.
name|class
name|OptimizationRemarkAnalysis
operator|:
name|public
name|DiagnosticInfoIROptimization
block|{
name|public
operator|:
comment|/// \p PassName is the name of the pass emitting this diagnostic. If this name
comment|/// matches the regular expression given in -Rpass-analysis=, then the
comment|/// diagnostic will be emitted. \p RemarkName is a textual identifier for the
comment|/// remark (single-word, camel-case). \p Loc is the debug location and \p
comment|/// CodeRegion is the region that the optimization operates on (currently only
comment|/// block is supported).
name|OptimizationRemarkAnalysis
argument_list|(
argument|const char *PassName
argument_list|,
argument|StringRef RemarkName
argument_list|,
argument|const DiagnosticLocation&Loc
argument_list|,
argument|const Value *CodeRegion
argument_list|)
block|;
comment|/// \brief This is ctor variant allows a pass to build an optimization remark
comment|/// from an existing remark.
comment|///
comment|/// This is useful when a transformation pass (e.g LV) wants to emit a remark
comment|/// (\p Orig) generated by one of its analyses (e.g. LAA) as its own analysis
comment|/// remark.  The string \p Prepend will be emitted before the original
comment|/// message.
name|OptimizationRemarkAnalysis
argument_list|(
argument|const char *PassName
argument_list|,
argument|StringRef Prepend
argument_list|,
argument|const OptimizationRemarkAnalysis&Orig
argument_list|)
operator|:
name|DiagnosticInfoIROptimization
argument_list|(
argument|PassName
argument_list|,
argument|Prepend
argument_list|,
argument|Orig
argument_list|)
block|{}
comment|/// \brief Same as above but \p Inst is used to derive code region and debug
comment|/// location.
name|OptimizationRemarkAnalysis
argument_list|(
argument|const char *PassName
argument_list|,
argument|StringRef RemarkName
argument_list|,
argument|const Instruction *Inst
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const DiagnosticInfo *DI
argument_list|)
block|{
return|return
name|DI
operator|->
name|getKind
argument_list|()
operator|==
name|DK_OptimizationRemarkAnalysis
return|;
block|}
specifier|static
name|bool
name|isEnabled
argument_list|(
argument|StringRef PassName
argument_list|)
block|;
comment|/// \see DiagnosticInfoOptimizationBase::isEnabled.
name|bool
name|isEnabled
argument_list|()
specifier|const
name|override
block|{
return|return
name|shouldAlwaysPrint
argument_list|()
operator|||
name|isEnabled
argument_list|(
name|getPassName
argument_list|()
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|char
operator|*
name|AlwaysPrint
block|;
name|bool
name|shouldAlwaysPrint
argument_list|()
specifier|const
block|{
return|return
name|getPassName
argument_list|()
operator|==
name|AlwaysPrint
return|;
block|}
name|protected
operator|:
name|OptimizationRemarkAnalysis
argument_list|(
argument|enum DiagnosticKind Kind
argument_list|,
argument|const char *PassName
argument_list|,
argument|const Function&Fn
argument_list|,
argument|const DiagnosticLocation&Loc
argument_list|,
argument|const Twine&Msg
argument_list|)
operator|:
name|DiagnosticInfoIROptimization
argument_list|(
argument|Kind
argument_list|,
argument|DS_Remark
argument_list|,
argument|PassName
argument_list|,
argument|Fn
argument_list|,
argument|Loc
argument_list|,
argument|Msg
argument_list|)
block|{}
name|OptimizationRemarkAnalysis
argument_list|(
argument|enum DiagnosticKind Kind
argument_list|,
argument|const char *PassName
argument_list|,
argument|StringRef RemarkName
argument_list|,
argument|const DiagnosticLocation&Loc
argument_list|,
argument|const Value *CodeRegion
argument_list|)
block|;
name|private
operator|:
comment|/// This is deprecated now and only used by the function API below.
comment|/// \p PassName is the name of the pass emitting this diagnostic. If
comment|/// this name matches the regular expression given in -Rpass-analysis=, then
comment|/// the diagnostic will be emitted. \p Fn is the function where the diagnostic
comment|/// is being emitted. \p Loc is the location information to use in the
comment|/// diagnostic. If line table information is available, the diagnostic will
comment|/// include the source code location. \p Msg is the message to show. Note that
comment|/// this class does not copy this message, so this reference must be valid for
comment|/// the whole life time of the diagnostic.
name|OptimizationRemarkAnalysis
argument_list|(
specifier|const
name|char
operator|*
name|PassName
argument_list|,
specifier|const
name|Function
operator|&
name|Fn
argument_list|,
specifier|const
name|DiagnosticLocation
operator|&
name|Loc
argument_list|,
specifier|const
name|Twine
operator|&
name|Msg
argument_list|)
operator|:
name|DiagnosticInfoIROptimization
argument_list|(
argument|DK_OptimizationRemarkAnalysis
argument_list|,
argument|DS_Remark
argument_list|,
argument|PassName
argument_list|,
argument|Fn
argument_list|,
argument|Loc
argument_list|,
argument|Msg
argument_list|)
block|{}
name|friend
name|void
name|emitOptimizationRemarkAnalysis
argument_list|(
name|LLVMContext
operator|&
name|Ctx
argument_list|,
specifier|const
name|char
operator|*
name|PassName
argument_list|,
specifier|const
name|Function
operator|&
name|Fn
argument_list|,
specifier|const
name|DiagnosticLocation
operator|&
name|Loc
argument_list|,
specifier|const
name|Twine
operator|&
name|Msg
argument_list|)
block|; }
block|;
comment|/// Diagnostic information for optimization analysis remarks related to
comment|/// floating-point non-commutativity.
name|class
name|OptimizationRemarkAnalysisFPCommute
operator|:
name|public
name|OptimizationRemarkAnalysis
block|{
name|public
operator|:
comment|/// \p PassName is the name of the pass emitting this diagnostic. If this name
comment|/// matches the regular expression given in -Rpass-analysis=, then the
comment|/// diagnostic will be emitted. \p RemarkName is a textual identifier for the
comment|/// remark (single-word, camel-case). \p Loc is the debug location and \p
comment|/// CodeRegion is the region that the optimization operates on (currently only
comment|/// block is supported). The front-end will append its own message related to
comment|/// options that address floating-point non-commutativity.
name|OptimizationRemarkAnalysisFPCommute
argument_list|(
argument|const char *PassName
argument_list|,
argument|StringRef RemarkName
argument_list|,
argument|const DiagnosticLocation&Loc
argument_list|,
argument|const Value *CodeRegion
argument_list|)
operator|:
name|OptimizationRemarkAnalysis
argument_list|(
argument|DK_OptimizationRemarkAnalysisFPCommute
argument_list|,
argument|PassName
argument_list|,
argument|RemarkName
argument_list|,
argument|Loc
argument_list|,
argument|CodeRegion
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const DiagnosticInfo *DI
argument_list|)
block|{
return|return
name|DI
operator|->
name|getKind
argument_list|()
operator|==
name|DK_OptimizationRemarkAnalysisFPCommute
return|;
block|}
name|private
operator|:
comment|/// This is deprecated now and only used by the function API below.
comment|/// \p PassName is the name of the pass emitting this diagnostic. If
comment|/// this name matches the regular expression given in -Rpass-analysis=, then
comment|/// the diagnostic will be emitted. \p Fn is the function where the diagnostic
comment|/// is being emitted. \p Loc is the location information to use in the
comment|/// diagnostic. If line table information is available, the diagnostic will
comment|/// include the source code location. \p Msg is the message to show. The
comment|/// front-end will append its own message related to options that address
comment|/// floating-point non-commutativity. Note that this class does not copy this
comment|/// message, so this reference must be valid for the whole life time of the
comment|/// diagnostic.
name|OptimizationRemarkAnalysisFPCommute
argument_list|(
specifier|const
name|char
operator|*
name|PassName
argument_list|,
specifier|const
name|Function
operator|&
name|Fn
argument_list|,
specifier|const
name|DiagnosticLocation
operator|&
name|Loc
argument_list|,
specifier|const
name|Twine
operator|&
name|Msg
argument_list|)
operator|:
name|OptimizationRemarkAnalysis
argument_list|(
argument|DK_OptimizationRemarkAnalysisFPCommute
argument_list|,
argument|PassName
argument_list|,
argument|Fn
argument_list|,
argument|Loc
argument_list|,
argument|Msg
argument_list|)
block|{}
name|friend
name|void
name|emitOptimizationRemarkAnalysisFPCommute
argument_list|(
name|LLVMContext
operator|&
name|Ctx
argument_list|,
specifier|const
name|char
operator|*
name|PassName
argument_list|,
specifier|const
name|Function
operator|&
name|Fn
argument_list|,
specifier|const
name|DiagnosticLocation
operator|&
name|Loc
argument_list|,
specifier|const
name|Twine
operator|&
name|Msg
argument_list|)
block|; }
block|;
comment|/// Diagnostic information for optimization analysis remarks related to
comment|/// pointer aliasing.
name|class
name|OptimizationRemarkAnalysisAliasing
operator|:
name|public
name|OptimizationRemarkAnalysis
block|{
name|public
operator|:
comment|/// \p PassName is the name of the pass emitting this diagnostic. If this name
comment|/// matches the regular expression given in -Rpass-analysis=, then the
comment|/// diagnostic will be emitted. \p RemarkName is a textual identifier for the
comment|/// remark (single-word, camel-case). \p Loc is the debug location and \p
comment|/// CodeRegion is the region that the optimization operates on (currently only
comment|/// block is supported). The front-end will append its own message related to
comment|/// options that address pointer aliasing legality.
name|OptimizationRemarkAnalysisAliasing
argument_list|(
argument|const char *PassName
argument_list|,
argument|StringRef RemarkName
argument_list|,
argument|const DiagnosticLocation&Loc
argument_list|,
argument|const Value *CodeRegion
argument_list|)
operator|:
name|OptimizationRemarkAnalysis
argument_list|(
argument|DK_OptimizationRemarkAnalysisAliasing
argument_list|,
argument|PassName
argument_list|,
argument|RemarkName
argument_list|,
argument|Loc
argument_list|,
argument|CodeRegion
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const DiagnosticInfo *DI
argument_list|)
block|{
return|return
name|DI
operator|->
name|getKind
argument_list|()
operator|==
name|DK_OptimizationRemarkAnalysisAliasing
return|;
block|}
name|private
operator|:
comment|/// This is deprecated now and only used by the function API below.
comment|/// \p PassName is the name of the pass emitting this diagnostic. If
comment|/// this name matches the regular expression given in -Rpass-analysis=, then
comment|/// the diagnostic will be emitted. \p Fn is the function where the diagnostic
comment|/// is being emitted. \p Loc is the location information to use in the
comment|/// diagnostic. If line table information is available, the diagnostic will
comment|/// include the source code location. \p Msg is the message to show. The
comment|/// front-end will append its own message related to options that address
comment|/// pointer aliasing legality. Note that this class does not copy this
comment|/// message, so this reference must be valid for the whole life time of the
comment|/// diagnostic.
name|OptimizationRemarkAnalysisAliasing
argument_list|(
specifier|const
name|char
operator|*
name|PassName
argument_list|,
specifier|const
name|Function
operator|&
name|Fn
argument_list|,
specifier|const
name|DiagnosticLocation
operator|&
name|Loc
argument_list|,
specifier|const
name|Twine
operator|&
name|Msg
argument_list|)
operator|:
name|OptimizationRemarkAnalysis
argument_list|(
argument|DK_OptimizationRemarkAnalysisAliasing
argument_list|,
argument|PassName
argument_list|,
argument|Fn
argument_list|,
argument|Loc
argument_list|,
argument|Msg
argument_list|)
block|{}
name|friend
name|void
name|emitOptimizationRemarkAnalysisAliasing
argument_list|(
name|LLVMContext
operator|&
name|Ctx
argument_list|,
specifier|const
name|char
operator|*
name|PassName
argument_list|,
specifier|const
name|Function
operator|&
name|Fn
argument_list|,
specifier|const
name|DiagnosticLocation
operator|&
name|Loc
argument_list|,
specifier|const
name|Twine
operator|&
name|Msg
argument_list|)
block|; }
block|;
comment|/// Diagnostic information for machine IR parser.
name|class
name|DiagnosticInfoMIRParser
operator|:
name|public
name|DiagnosticInfo
block|{
specifier|const
name|SMDiagnostic
operator|&
name|Diagnostic
block|;
name|public
operator|:
name|DiagnosticInfoMIRParser
argument_list|(
argument|DiagnosticSeverity Severity
argument_list|,
argument|const SMDiagnostic&Diagnostic
argument_list|)
operator|:
name|DiagnosticInfo
argument_list|(
name|DK_MIRParser
argument_list|,
name|Severity
argument_list|)
block|,
name|Diagnostic
argument_list|(
argument|Diagnostic
argument_list|)
block|{}
specifier|const
name|SMDiagnostic
operator|&
name|getDiagnostic
argument_list|()
specifier|const
block|{
return|return
name|Diagnostic
return|;
block|}
name|void
name|print
argument_list|(
argument|DiagnosticPrinter&DP
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const DiagnosticInfo *DI
argument_list|)
block|{
return|return
name|DI
operator|->
name|getKind
argument_list|()
operator|==
name|DK_MIRParser
return|;
block|}
expr|}
block|;
comment|/// Diagnostic information for ISel fallback path.
name|class
name|DiagnosticInfoISelFallback
operator|:
name|public
name|DiagnosticInfo
block|{
comment|/// The function that is concerned by this diagnostic.
specifier|const
name|Function
operator|&
name|Fn
block|;
name|public
operator|:
name|DiagnosticInfoISelFallback
argument_list|(
argument|const Function&Fn
argument_list|,
argument|DiagnosticSeverity Severity = DS_Warning
argument_list|)
operator|:
name|DiagnosticInfo
argument_list|(
name|DK_ISelFallback
argument_list|,
name|Severity
argument_list|)
block|,
name|Fn
argument_list|(
argument|Fn
argument_list|)
block|{}
specifier|const
name|Function
operator|&
name|getFunction
argument_list|()
specifier|const
block|{
return|return
name|Fn
return|;
block|}
name|void
name|print
argument_list|(
argument|DiagnosticPrinter&DP
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const DiagnosticInfo *DI
argument_list|)
block|{
return|return
name|DI
operator|->
name|getKind
argument_list|()
operator|==
name|DK_ISelFallback
return|;
block|}
expr|}
block|;
comment|// Create wrappers for C Binding types (see CBindingWrapping.h).
name|DEFINE_SIMPLE_CONVERSION_FUNCTIONS
argument_list|(
argument|DiagnosticInfo
argument_list|,
argument|LLVMDiagnosticInfoRef
argument_list|)
comment|/// \brief Legacy interface to emit an optimization-applied message.  Use
comment|/// (Machine)OptimizationRemarkEmitter instead.
comment|///
comment|/// \p PassName is the name of the pass emitting the message. If -Rpass= is
comment|/// given and \p PassName matches the regular expression in -Rpass, then the
comment|/// remark will be emitted. \p Fn is the function triggering the remark, \p Loc
comment|/// is the debug location where the diagnostic is generated. \p Msg is the
comment|/// message string to use.
name|void
name|emitOptimizationRemark
argument_list|(
name|LLVMContext
operator|&
name|Ctx
argument_list|,
specifier|const
name|char
operator|*
name|PassName
argument_list|,
specifier|const
name|Function
operator|&
name|Fn
argument_list|,
specifier|const
name|DiagnosticLocation
operator|&
name|Loc
argument_list|,
specifier|const
name|Twine
operator|&
name|Msg
argument_list|)
block|;
comment|/// \brief Legacy interface to emit an optimization-missed message.  Use
comment|/// (Machine)OptimizationRemarkEmitter instead.
comment|///
comment|/// \p PassName is the name of the pass emitting the message. If -Rpass-missed=
comment|/// is given and \p PassName matches the regular expression in -Rpass, then the
comment|/// remark will be emitted. \p Fn is the function triggering the remark, \p Loc
comment|/// is the debug location where the diagnostic is generated. \p Msg is the
comment|/// message string to use.
name|void
name|emitOptimizationRemarkMissed
argument_list|(
name|LLVMContext
operator|&
name|Ctx
argument_list|,
specifier|const
name|char
operator|*
name|PassName
argument_list|,
specifier|const
name|Function
operator|&
name|Fn
argument_list|,
specifier|const
name|DiagnosticLocation
operator|&
name|Loc
argument_list|,
specifier|const
name|Twine
operator|&
name|Msg
argument_list|)
block|;
comment|/// \brief Legacy interface to emit an optimization analysis remark message.
comment|/// Use (Machine)OptimizationRemarkEmitter instead.
comment|///
comment|/// \p PassName is the name of the pass emitting the message. If
comment|/// -Rpass-analysis= is given and \p PassName matches the regular expression in
comment|/// -Rpass, then the remark will be emitted. \p Fn is the function triggering
comment|/// the remark, \p Loc is the debug location where the diagnostic is
comment|/// generated. \p Msg is the message string to use.
name|void
name|emitOptimizationRemarkAnalysis
argument_list|(
name|LLVMContext
operator|&
name|Ctx
argument_list|,
specifier|const
name|char
operator|*
name|PassName
argument_list|,
specifier|const
name|Function
operator|&
name|Fn
argument_list|,
specifier|const
name|DiagnosticLocation
operator|&
name|Loc
argument_list|,
specifier|const
name|Twine
operator|&
name|Msg
argument_list|)
block|;
comment|/// \brief Legacy interface to emit an optimization analysis remark related to
comment|/// messages about floating-point non-commutativity.  Use
comment|/// (Machine)OptimizationRemarkEmitter instead.
comment|///
comment|/// \p PassName is the name of the pass emitting the message. If
comment|/// -Rpass-analysis= is given and \p PassName matches the regular expression in
comment|/// -Rpass, then the remark will be emitted. \p Fn is the function triggering
comment|/// the remark, \p Loc is the debug location where the diagnostic is
comment|/// generated. \p Msg is the message string to use.
name|void
name|emitOptimizationRemarkAnalysisFPCommute
argument_list|(
name|LLVMContext
operator|&
name|Ctx
argument_list|,
specifier|const
name|char
operator|*
name|PassName
argument_list|,
specifier|const
name|Function
operator|&
name|Fn
argument_list|,
specifier|const
name|DiagnosticLocation
operator|&
name|Loc
argument_list|,
specifier|const
name|Twine
operator|&
name|Msg
argument_list|)
block|;
comment|/// \brief Legacy interface to emit an optimization analysis remark related to
comment|/// messages about pointer aliasing.  Use (Machine)OptimizationRemarkEmitter
comment|/// instead.
comment|///
comment|/// \p PassName is the name of the pass emitting the message.
comment|/// If -Rpass-analysis= is given and \p PassName matches the regular expression
comment|/// in -Rpass, then the remark will be emitted. \p Fn is the function triggering
comment|/// the remark, \p Loc is the debug location where the diagnostic is generated.
comment|/// \p Msg is the message string to use.
name|void
name|emitOptimizationRemarkAnalysisAliasing
argument_list|(
name|LLVMContext
operator|&
name|Ctx
argument_list|,
specifier|const
name|char
operator|*
name|PassName
argument_list|,
specifier|const
name|Function
operator|&
name|Fn
argument_list|,
specifier|const
name|DiagnosticLocation
operator|&
name|Loc
argument_list|,
specifier|const
name|Twine
operator|&
name|Msg
argument_list|)
block|;
comment|/// Diagnostic information for optimization failures.
name|class
name|DiagnosticInfoOptimizationFailure
operator|:
name|public
name|DiagnosticInfoIROptimization
block|{
name|public
operator|:
comment|/// \p Fn is the function where the diagnostic is being emitted. \p Loc is
comment|/// the location information to use in the diagnostic. If line table
comment|/// information is available, the diagnostic will include the source code
comment|/// location. \p Msg is the message to show. Note that this class does not
comment|/// copy this message, so this reference must be valid for the whole life time
comment|/// of the diagnostic.
name|DiagnosticInfoOptimizationFailure
argument_list|(
specifier|const
name|Function
operator|&
name|Fn
argument_list|,
specifier|const
name|DiagnosticLocation
operator|&
name|Loc
argument_list|,
specifier|const
name|Twine
operator|&
name|Msg
argument_list|)
operator|:
name|DiagnosticInfoIROptimization
argument_list|(
argument|DK_OptimizationFailure
argument_list|,
argument|DS_Warning
argument_list|,
argument|nullptr
argument_list|,
argument|Fn
argument_list|,
argument|Loc
argument_list|,
argument|Msg
argument_list|)
block|{}
comment|/// \p PassName is the name of the pass emitting this diagnostic.  \p
comment|/// RemarkName is a textual identifier for the remark (single-word,
comment|/// camel-case).  \p Loc is the debug location and \p CodeRegion is the
comment|/// region that the optimization operates on (currently basic block is
comment|/// supported).
name|DiagnosticInfoOptimizationFailure
argument_list|(
argument|const char *PassName
argument_list|,
argument|StringRef RemarkName
argument_list|,
argument|const DiagnosticLocation&Loc
argument_list|,
argument|const Value *CodeRegion
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const DiagnosticInfo *DI
argument_list|)
block|{
return|return
name|DI
operator|->
name|getKind
argument_list|()
operator|==
name|DK_OptimizationFailure
return|;
block|}
comment|/// \see DiagnosticInfoOptimizationBase::isEnabled.
name|bool
name|isEnabled
argument_list|()
specifier|const
name|override
block|; }
block|;
comment|/// Diagnostic information for unsupported feature in backend.
name|class
name|DiagnosticInfoUnsupported
operator|:
name|public
name|DiagnosticInfoWithLocationBase
block|{
name|private
operator|:
name|Twine
name|Msg
block|;
name|public
operator|:
comment|/// \p Fn is the function where the diagnostic is being emitted. \p Loc is
comment|/// the location information to use in the diagnostic. If line table
comment|/// information is available, the diagnostic will include the source code
comment|/// location. \p Msg is the message to show. Note that this class does not
comment|/// copy this message, so this reference must be valid for the whole life time
comment|/// of the diagnostic.
name|DiagnosticInfoUnsupported
argument_list|(
argument|const Function&Fn
argument_list|,
argument|const Twine&Msg
argument_list|,
argument|const DiagnosticLocation&Loc = DiagnosticLocation()
argument_list|,
argument|DiagnosticSeverity Severity = DS_Error
argument_list|)
operator|:
name|DiagnosticInfoWithLocationBase
argument_list|(
name|DK_Unsupported
argument_list|,
name|Severity
argument_list|,
name|Fn
argument_list|,
name|Loc
argument_list|)
block|,
name|Msg
argument_list|(
argument|Msg
argument_list|)
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const DiagnosticInfo *DI
argument_list|)
block|{
return|return
name|DI
operator|->
name|getKind
argument_list|()
operator|==
name|DK_Unsupported
return|;
block|}
specifier|const
name|Twine
operator|&
name|getMessage
argument_list|()
specifier|const
block|{
return|return
name|Msg
return|;
block|}
name|void
name|print
argument_list|(
argument|DiagnosticPrinter&DP
argument_list|)
specifier|const
name|override
block|; }
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_DIAGNOSTICINFO_H
end_comment

end_unit

