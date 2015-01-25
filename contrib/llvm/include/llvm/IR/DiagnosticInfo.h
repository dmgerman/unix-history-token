begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Support/DiagnosticInfo.h - Diagnostic Declaration ---*- C++ -*-===//
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
file|"llvm-c/Core.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DebugLoc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
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
name|LLVMContextImpl
decl_stmt|;
name|class
name|Twine
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|DebugLoc
decl_stmt|;
comment|/// \brief Defines the different supported severity of a diagnostic.
enum|enum
name|DiagnosticSeverity
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
name|DK_Bitcode
block|,
name|DK_InlineAsm
block|,
name|DK_StackSize
block|,
name|DK_Linker
block|,
name|DK_DebugMetadataVersion
block|,
name|DK_SampleProfile
block|,
name|DK_OptimizationRemark
block|,
name|DK_OptimizationRemarkMissed
block|,
name|DK_OptimizationRemarkAnalysis
block|,
name|DK_OptimizationFailure
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
block|{}
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
typedef|typedef
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
name|DiagnosticHandlerFunction
expr_stmt|;
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
name|LocCookie
argument_list|(
literal|0
argument_list|)
block|,
name|MsgStr
argument_list|(
name|MsgStr
argument_list|)
block|,
name|Instr
argument_list|(
argument|nullptr
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
name|MsgStr
argument_list|)
block|,
name|Instr
argument_list|(
argument|nullptr
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
comment|/// Diagnostic information for stack size reporting.
comment|/// This is basically a function and a size.
name|class
name|DiagnosticInfoStackSize
operator|:
name|public
name|DiagnosticInfo
block|{
name|private
operator|:
comment|/// The function that is concerned by this stack size diagnostic.
specifier|const
name|Function
operator|&
name|Fn
block|;
comment|/// The computed stack size.
name|unsigned
name|StackSize
block|;
name|public
operator|:
comment|/// \p The function that is concerned by this stack size diagnostic.
comment|/// \p The computed stack size.
name|DiagnosticInfoStackSize
argument_list|(
argument|const Function&Fn
argument_list|,
argument|unsigned StackSize
argument_list|,
argument|DiagnosticSeverity Severity = DS_Warning
argument_list|)
operator|:
name|DiagnosticInfo
argument_list|(
name|DK_StackSize
argument_list|,
name|Severity
argument_list|)
block|,
name|Fn
argument_list|(
name|Fn
argument_list|)
block|,
name|StackSize
argument_list|(
argument|StackSize
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
name|unsigned
name|getStackSize
argument_list|()
specifier|const
block|{
return|return
name|StackSize
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
argument|const char *FileName
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
argument|const char *FileName
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
literal|0
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
name|FileName
argument_list|(
name|nullptr
argument_list|)
block|,
name|LineNum
argument_list|(
literal|0
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
specifier|const
name|char
operator|*
name|FileName
block|;
comment|/// Line number where the diagnostic occurred. If 0, no line number will
comment|/// be emitted in the message.
name|unsigned
name|LineNum
block|;
comment|/// Message to report.
specifier|const
name|Twine
operator|&
name|Msg
block|; }
block|;
comment|/// Common features for diagnostics dealing with optimization remarks.
name|class
name|DiagnosticInfoOptimizationBase
operator|:
name|public
name|DiagnosticInfo
block|{
name|public
operator|:
comment|/// \p PassName is the name of the pass emitting this diagnostic.
comment|/// \p Fn is the function where the diagnostic is being emitted. \p DLoc is
comment|/// the location information to use in the diagnostic. If line table
comment|/// information is available, the diagnostic will include the source code
comment|/// location. \p Msg is the message to show. Note that this class does not
comment|/// copy this message, so this reference must be valid for the whole life time
comment|/// of the diagnostic.
name|DiagnosticInfoOptimizationBase
argument_list|(
argument|enum DiagnosticKind Kind
argument_list|,
argument|enum DiagnosticSeverity Severity
argument_list|,
argument|const char *PassName
argument_list|,
argument|const Function&Fn
argument_list|,
argument|const DebugLoc&DLoc
argument_list|,
argument|const Twine&Msg
argument_list|)
operator|:
name|DiagnosticInfo
argument_list|(
name|Kind
argument_list|,
name|Severity
argument_list|)
block|,
name|PassName
argument_list|(
name|PassName
argument_list|)
block|,
name|Fn
argument_list|(
name|Fn
argument_list|)
block|,
name|DLoc
argument_list|(
name|DLoc
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
name|DK_OptimizationRemark
return|;
block|}
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
comment|/// Return true if location information is available for this diagnostic.
name|bool
name|isLocationAvailable
argument_list|()
specifier|const
block|;
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
name|char
operator|*
name|getPassName
argument_list|()
specifier|const
block|{
return|return
name|PassName
return|;
block|}
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
name|DebugLoc
operator|&
name|getDebugLoc
argument_list|()
specifier|const
block|{
return|return
name|DLoc
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
comment|/// Name of the pass that triggers this report. If this matches the
comment|/// regular expression given in -Rpass=regexp, then the remark will
comment|/// be emitted.
specifier|const
name|char
operator|*
name|PassName
block|;
comment|/// Function where this diagnostic is triggered.
specifier|const
name|Function
operator|&
name|Fn
block|;
comment|/// Debug location where this diagnostic is triggered.
name|DebugLoc
name|DLoc
block|;
comment|/// Message to report.
specifier|const
name|Twine
operator|&
name|Msg
block|; }
block|;
comment|/// Diagnostic information for applied optimization remarks.
name|class
name|DiagnosticInfoOptimizationRemark
operator|:
name|public
name|DiagnosticInfoOptimizationBase
block|{
name|public
operator|:
comment|/// \p PassName is the name of the pass emitting this diagnostic. If
comment|/// this name matches the regular expression given in -Rpass=, then the
comment|/// diagnostic will be emitted. \p Fn is the function where the diagnostic
comment|/// is being emitted. \p DLoc is the location information to use in the
comment|/// diagnostic. If line table information is available, the diagnostic
comment|/// will include the source code location. \p Msg is the message to show.
comment|/// Note that this class does not copy this message, so this reference
comment|/// must be valid for the whole life time of the diagnostic.
name|DiagnosticInfoOptimizationRemark
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
name|DebugLoc
operator|&
name|DLoc
argument_list|,
specifier|const
name|Twine
operator|&
name|Msg
argument_list|)
operator|:
name|DiagnosticInfoOptimizationBase
argument_list|(
argument|DK_OptimizationRemark
argument_list|,
argument|DS_Remark
argument_list|,
argument|PassName
argument_list|,
argument|Fn
argument_list|,
argument|DLoc
argument_list|,
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
name|DK_OptimizationRemark
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
comment|/// Diagnostic information for missed-optimization remarks.
name|class
name|DiagnosticInfoOptimizationRemarkMissed
operator|:
name|public
name|DiagnosticInfoOptimizationBase
block|{
name|public
operator|:
comment|/// \p PassName is the name of the pass emitting this diagnostic. If
comment|/// this name matches the regular expression given in -Rpass-missed=, then the
comment|/// diagnostic will be emitted. \p Fn is the function where the diagnostic
comment|/// is being emitted. \p DLoc is the location information to use in the
comment|/// diagnostic. If line table information is available, the diagnostic
comment|/// will include the source code location. \p Msg is the message to show.
comment|/// Note that this class does not copy this message, so this reference
comment|/// must be valid for the whole life time of the diagnostic.
name|DiagnosticInfoOptimizationRemarkMissed
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
name|DebugLoc
operator|&
name|DLoc
argument_list|,
specifier|const
name|Twine
operator|&
name|Msg
argument_list|)
operator|:
name|DiagnosticInfoOptimizationBase
argument_list|(
argument|DK_OptimizationRemarkMissed
argument_list|,
argument|DS_Remark
argument_list|,
argument|PassName
argument_list|,
argument|Fn
argument_list|,
argument|DLoc
argument_list|,
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
name|DK_OptimizationRemarkMissed
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
comment|/// Diagnostic information for optimization analysis remarks.
name|class
name|DiagnosticInfoOptimizationRemarkAnalysis
operator|:
name|public
name|DiagnosticInfoOptimizationBase
block|{
name|public
operator|:
comment|/// \p PassName is the name of the pass emitting this diagnostic. If
comment|/// this name matches the regular expression given in -Rpass-analysis=, then
comment|/// the diagnostic will be emitted. \p Fn is the function where the diagnostic
comment|/// is being emitted. \p DLoc is the location information to use in the
comment|/// diagnostic. If line table information is available, the diagnostic will
comment|/// include the source code location. \p Msg is the message to show. Note that
comment|/// this class does not copy this message, so this reference must be valid for
comment|/// the whole life time of the diagnostic.
name|DiagnosticInfoOptimizationRemarkAnalysis
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
name|DebugLoc
operator|&
name|DLoc
argument_list|,
specifier|const
name|Twine
operator|&
name|Msg
argument_list|)
operator|:
name|DiagnosticInfoOptimizationBase
argument_list|(
argument|DK_OptimizationRemarkAnalysis
argument_list|,
argument|DS_Remark
argument_list|,
argument|PassName
argument_list|,
argument|Fn
argument_list|,
argument|DLoc
argument_list|,
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
name|DK_OptimizationRemarkAnalysis
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
comment|// Create wrappers for C Binding types (see CBindingWrapping.h).
name|DEFINE_SIMPLE_CONVERSION_FUNCTIONS
argument_list|(
argument|DiagnosticInfo
argument_list|,
argument|LLVMDiagnosticInfoRef
argument_list|)
comment|/// Emit an optimization-applied message. \p PassName is the name of the pass
comment|/// emitting the message. If -Rpass= is given and \p PassName matches the
comment|/// regular expression in -Rpass, then the remark will be emitted. \p Fn is
comment|/// the function triggering the remark, \p DLoc is the debug location where
comment|/// the diagnostic is generated. \p Msg is the message string to use.
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
name|DebugLoc
operator|&
name|DLoc
argument_list|,
specifier|const
name|Twine
operator|&
name|Msg
argument_list|)
block|;
comment|/// Emit an optimization-missed message. \p PassName is the name of the
comment|/// pass emitting the message. If -Rpass-missed= is given and \p PassName
comment|/// matches the regular expression in -Rpass, then the remark will be
comment|/// emitted. \p Fn is the function triggering the remark, \p DLoc is the
comment|/// debug location where the diagnostic is generated. \p Msg is the
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
name|DebugLoc
operator|&
name|DLoc
argument_list|,
specifier|const
name|Twine
operator|&
name|Msg
argument_list|)
block|;
comment|/// Emit an optimization analysis remark message. \p PassName is the name of
comment|/// the pass emitting the message. If -Rpass-analysis= is given and \p
comment|/// PassName matches the regular expression in -Rpass, then the remark will be
comment|/// emitted. \p Fn is the function triggering the remark, \p DLoc is the debug
comment|/// location where the diagnostic is generated. \p Msg is the message string
comment|/// to use.
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
name|DebugLoc
operator|&
name|DLoc
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
name|DiagnosticInfoOptimizationBase
block|{
name|public
operator|:
comment|/// \p Fn is the function where the diagnostic is being emitted. \p DLoc is
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
name|DebugLoc
operator|&
name|DLoc
argument_list|,
specifier|const
name|Twine
operator|&
name|Msg
argument_list|)
operator|:
name|DiagnosticInfoOptimizationBase
argument_list|(
argument|DK_OptimizationFailure
argument_list|,
argument|DS_Warning
argument_list|,
argument|nullptr
argument_list|,
argument|Fn
argument_list|,
argument|DLoc
argument_list|,
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
comment|/// Emit a warning when loop vectorization is specified but fails. \p Fn is the
comment|/// function triggering the warning, \p DLoc is the debug location where the
comment|/// diagnostic is generated. \p Msg is the message string to use.
name|void
name|emitLoopVectorizeWarning
argument_list|(
name|LLVMContext
operator|&
name|Ctx
argument_list|,
specifier|const
name|Function
operator|&
name|Fn
argument_list|,
specifier|const
name|DebugLoc
operator|&
name|DLoc
argument_list|,
specifier|const
name|Twine
operator|&
name|Msg
argument_list|)
block|;
comment|/// Emit a warning when loop interleaving is specified but fails. \p Fn is the
comment|/// function triggering the warning, \p DLoc is the debug location where the
comment|/// diagnostic is generated. \p Msg is the message string to use.
name|void
name|emitLoopInterleaveWarning
argument_list|(
name|LLVMContext
operator|&
name|Ctx
argument_list|,
specifier|const
name|Function
operator|&
name|Fn
argument_list|,
specifier|const
name|DebugLoc
operator|&
name|DLoc
argument_list|,
specifier|const
name|Twine
operator|&
name|Msg
argument_list|)
block|;  }
end_decl_stmt

begin_comment
comment|// End namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

