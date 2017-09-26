begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Target.h ------------------------------------------------*- C++ -*-===//
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
name|liblldb_Target_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Target_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<list>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Breakpoint/BreakpointList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Breakpoint/WatchpointList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ArchSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Broadcaster.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Disassembler.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ModuleList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/UserSettingsController.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/Expression.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/TypeSystem.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ExecutionContextScope.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/PathMappingList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ProcessLaunchInfo.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/SectionLoadHistory.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Timeout.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-public.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
specifier|extern
name|OptionEnumValueElement
name|g_dynamic_value_types
index|[]
decl_stmt|;
typedef|typedef
enum|enum
name|InlineStrategy
block|{
name|eInlineBreakpointsNever
init|=
literal|0
block|,
name|eInlineBreakpointsHeaders
block|,
name|eInlineBreakpointsAlways
block|}
name|InlineStrategy
typedef|;
typedef|typedef
enum|enum
name|LoadScriptFromSymFile
block|{
name|eLoadScriptFromSymFileTrue
block|,
name|eLoadScriptFromSymFileFalse
block|,
name|eLoadScriptFromSymFileWarn
block|}
name|LoadScriptFromSymFile
typedef|;
typedef|typedef
enum|enum
name|LoadCWDlldbinitFile
block|{
name|eLoadCWDlldbinitTrue
block|,
name|eLoadCWDlldbinitFalse
block|,
name|eLoadCWDlldbinitWarn
block|}
name|LoadCWDlldbinitFile
typedef|;
comment|//----------------------------------------------------------------------
comment|// TargetProperties
comment|//----------------------------------------------------------------------
name|class
name|TargetExperimentalProperties
range|:
name|public
name|Properties
block|{
name|public
operator|:
name|TargetExperimentalProperties
argument_list|()
block|; }
decl_stmt|;
name|class
name|TargetProperties
range|:
name|public
name|Properties
block|{
name|public
operator|:
name|TargetProperties
argument_list|(
name|Target
operator|*
name|target
argument_list|)
block|;
operator|~
name|TargetProperties
argument_list|()
name|override
block|;
name|ArchSpec
name|GetDefaultArchitecture
argument_list|()
specifier|const
block|;
name|void
name|SetDefaultArchitecture
argument_list|(
specifier|const
name|ArchSpec
operator|&
name|arch
argument_list|)
block|;
name|bool
name|GetMoveToNearestCode
argument_list|()
specifier|const
block|;
name|lldb
operator|::
name|DynamicValueType
name|GetPreferDynamicValue
argument_list|()
specifier|const
block|;
name|bool
name|SetPreferDynamicValue
argument_list|(
argument|lldb::DynamicValueType d
argument_list|)
block|;
name|bool
name|GetPreloadSymbols
argument_list|()
specifier|const
block|;
name|void
name|SetPreloadSymbols
argument_list|(
argument|bool b
argument_list|)
block|;
name|bool
name|GetDisableASLR
argument_list|()
specifier|const
block|;
name|void
name|SetDisableASLR
argument_list|(
argument|bool b
argument_list|)
block|;
name|bool
name|GetDetachOnError
argument_list|()
specifier|const
block|;
name|void
name|SetDetachOnError
argument_list|(
argument|bool b
argument_list|)
block|;
name|bool
name|GetDisableSTDIO
argument_list|()
specifier|const
block|;
name|void
name|SetDisableSTDIO
argument_list|(
argument|bool b
argument_list|)
block|;
specifier|const
name|char
operator|*
name|GetDisassemblyFlavor
argument_list|()
specifier|const
block|;
comment|//    void
comment|//    SetDisassemblyFlavor(const char *flavor);
name|InlineStrategy
name|GetInlineStrategy
argument_list|()
specifier|const
block|;
name|llvm
operator|::
name|StringRef
name|GetArg0
argument_list|()
specifier|const
block|;
name|void
name|SetArg0
argument_list|(
argument|llvm::StringRef arg
argument_list|)
block|;
name|bool
name|GetRunArguments
argument_list|(
argument|Args&args
argument_list|)
specifier|const
block|;
name|void
name|SetRunArguments
argument_list|(
specifier|const
name|Args
operator|&
name|args
argument_list|)
block|;
name|size_t
name|GetEnvironmentAsArgs
argument_list|(
argument|Args&env
argument_list|)
specifier|const
block|;
name|void
name|SetEnvironmentFromArgs
argument_list|(
specifier|const
name|Args
operator|&
name|env
argument_list|)
block|;
name|bool
name|GetSkipPrologue
argument_list|()
specifier|const
block|;
name|PathMappingList
operator|&
name|GetSourcePathMap
argument_list|()
specifier|const
block|;
name|FileSpecList
operator|&
name|GetExecutableSearchPaths
argument_list|()
block|;
name|FileSpecList
operator|&
name|GetDebugFileSearchPaths
argument_list|()
block|;
name|FileSpecList
operator|&
name|GetClangModuleSearchPaths
argument_list|()
block|;
name|bool
name|GetEnableAutoImportClangModules
argument_list|()
specifier|const
block|;
name|bool
name|GetEnableAutoApplyFixIts
argument_list|()
specifier|const
block|;
name|bool
name|GetEnableNotifyAboutFixIts
argument_list|()
specifier|const
block|;
name|bool
name|GetEnableSaveObjects
argument_list|()
specifier|const
block|;
name|bool
name|GetEnableSyntheticValue
argument_list|()
specifier|const
block|;
name|uint32_t
name|GetMaximumNumberOfChildrenToDisplay
argument_list|()
specifier|const
block|;
name|uint32_t
name|GetMaximumSizeOfStringSummary
argument_list|()
specifier|const
block|;
name|uint32_t
name|GetMaximumMemReadSize
argument_list|()
specifier|const
block|;
name|FileSpec
name|GetStandardInputPath
argument_list|()
specifier|const
block|;
name|FileSpec
name|GetStandardErrorPath
argument_list|()
specifier|const
block|;
name|FileSpec
name|GetStandardOutputPath
argument_list|()
specifier|const
block|;
name|void
name|SetStandardInputPath
argument_list|(
argument|llvm::StringRef path
argument_list|)
block|;
name|void
name|SetStandardOutputPath
argument_list|(
argument|llvm::StringRef path
argument_list|)
block|;
name|void
name|SetStandardErrorPath
argument_list|(
argument|llvm::StringRef path
argument_list|)
block|;
name|void
name|SetStandardInputPath
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|)
operator|=
name|delete
block|;
name|void
name|SetStandardOutputPath
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|)
operator|=
name|delete
block|;
name|void
name|SetStandardErrorPath
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|)
operator|=
name|delete
block|;
name|bool
name|GetBreakpointsConsultPlatformAvoidList
argument_list|()
block|;
name|lldb
operator|::
name|LanguageType
name|GetLanguage
argument_list|()
specifier|const
block|;
specifier|const
name|char
operator|*
name|GetExpressionPrefixContentsAsCString
argument_list|()
block|;
name|bool
name|GetUseHexImmediates
argument_list|()
specifier|const
block|;
name|bool
name|GetUseFastStepping
argument_list|()
specifier|const
block|;
name|bool
name|GetDisplayExpressionsInCrashlogs
argument_list|()
specifier|const
block|;
name|LoadScriptFromSymFile
name|GetLoadScriptFromSymbolFile
argument_list|()
specifier|const
block|;
name|LoadCWDlldbinitFile
name|GetLoadCWDlldbinitFile
argument_list|()
specifier|const
block|;
name|Disassembler
operator|::
name|HexImmediateStyle
name|GetHexImmediateStyle
argument_list|()
specifier|const
block|;
name|MemoryModuleLoadLevel
name|GetMemoryModuleLoadLevel
argument_list|()
specifier|const
block|;
name|bool
name|GetUserSpecifiedTrapHandlerNames
argument_list|(
argument|Args&args
argument_list|)
specifier|const
block|;
name|void
name|SetUserSpecifiedTrapHandlerNames
argument_list|(
specifier|const
name|Args
operator|&
name|args
argument_list|)
block|;
name|bool
name|GetNonStopModeEnabled
argument_list|()
specifier|const
block|;
name|void
name|SetNonStopModeEnabled
argument_list|(
argument|bool b
argument_list|)
block|;
name|bool
name|GetDisplayRuntimeSupportValues
argument_list|()
specifier|const
block|;
name|void
name|SetDisplayRuntimeSupportValues
argument_list|(
argument|bool b
argument_list|)
block|;
specifier|const
name|ProcessLaunchInfo
operator|&
name|GetProcessLaunchInfo
argument_list|()
block|;
name|void
name|SetProcessLaunchInfo
argument_list|(
specifier|const
name|ProcessLaunchInfo
operator|&
name|launch_info
argument_list|)
block|;
name|bool
name|GetInjectLocalVariables
argument_list|(
argument|ExecutionContext *exe_ctx
argument_list|)
specifier|const
block|;
name|void
name|SetInjectLocalVariables
argument_list|(
argument|ExecutionContext *exe_ctx
argument_list|,
argument|bool b
argument_list|)
block|;
name|private
operator|:
comment|//------------------------------------------------------------------
comment|// Callbacks for m_launch_info.
comment|//------------------------------------------------------------------
specifier|static
name|void
name|Arg0ValueChangedCallback
argument_list|(
name|void
operator|*
name|target_property_ptr
argument_list|,
name|OptionValue
operator|*
argument_list|)
block|;
specifier|static
name|void
name|RunArgsValueChangedCallback
argument_list|(
name|void
operator|*
name|target_property_ptr
argument_list|,
name|OptionValue
operator|*
argument_list|)
block|;
specifier|static
name|void
name|EnvVarsValueChangedCallback
argument_list|(
name|void
operator|*
name|target_property_ptr
argument_list|,
name|OptionValue
operator|*
argument_list|)
block|;
specifier|static
name|void
name|InheritEnvValueChangedCallback
argument_list|(
name|void
operator|*
name|target_property_ptr
argument_list|,
name|OptionValue
operator|*
argument_list|)
block|;
specifier|static
name|void
name|InputPathValueChangedCallback
argument_list|(
name|void
operator|*
name|target_property_ptr
argument_list|,
name|OptionValue
operator|*
argument_list|)
block|;
specifier|static
name|void
name|OutputPathValueChangedCallback
argument_list|(
name|void
operator|*
name|target_property_ptr
argument_list|,
name|OptionValue
operator|*
argument_list|)
block|;
specifier|static
name|void
name|ErrorPathValueChangedCallback
argument_list|(
name|void
operator|*
name|target_property_ptr
argument_list|,
name|OptionValue
operator|*
argument_list|)
block|;
specifier|static
name|void
name|DetachOnErrorValueChangedCallback
argument_list|(
name|void
operator|*
name|target_property_ptr
argument_list|,
name|OptionValue
operator|*
argument_list|)
block|;
specifier|static
name|void
name|DisableASLRValueChangedCallback
argument_list|(
name|void
operator|*
name|target_property_ptr
argument_list|,
name|OptionValue
operator|*
argument_list|)
block|;
specifier|static
name|void
name|DisableSTDIOValueChangedCallback
argument_list|(
name|void
operator|*
name|target_property_ptr
argument_list|,
name|OptionValue
operator|*
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// Member variables.
comment|//------------------------------------------------------------------
name|ProcessLaunchInfo
name|m_launch_info
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|TargetExperimentalProperties
operator|>
name|m_experimental_properties_up
block|; }
decl_stmt|;
name|class
name|EvaluateExpressionOptions
block|{
name|public
label|:
comment|// MSVC has a bug here that reports C4268: 'const' static/global data
comment|// initialized with compiler generated default constructor fills the object
comment|// with zeros.
comment|// Confirmed that MSVC is *not* zero-initializing, it's just a bogus warning.
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
pragma|#
directive|pragma
name|warning
name|(
name|push
name|)
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4268
name|)
endif|#
directive|endif
specifier|static
name|constexpr
name|std
operator|::
name|chrono
operator|::
name|milliseconds
name|default_timeout
block|{
literal|500
block|}
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
pragma|#
directive|pragma
name|warning
name|(
name|pop
name|)
endif|#
directive|endif
specifier|static
name|constexpr
name|ExecutionPolicy
name|default_execution_policy
init|=
name|eExecutionPolicyOnlyWhenNeeded
decl_stmt|;
name|EvaluateExpressionOptions
argument_list|()
operator|=
expr|default
expr_stmt|;
name|ExecutionPolicy
name|GetExecutionPolicy
argument_list|()
specifier|const
block|{
return|return
name|m_execution_policy
return|;
block|}
name|void
name|SetExecutionPolicy
parameter_list|(
name|ExecutionPolicy
name|policy
init|=
name|eExecutionPolicyAlways
parameter_list|)
block|{
name|m_execution_policy
operator|=
name|policy
expr_stmt|;
block|}
name|lldb
operator|::
name|LanguageType
name|GetLanguage
argument_list|()
specifier|const
block|{
return|return
name|m_language
return|;
block|}
name|void
name|SetLanguage
argument_list|(
name|lldb
operator|::
name|LanguageType
name|language
argument_list|)
block|{
name|m_language
operator|=
name|language
expr_stmt|;
block|}
name|bool
name|DoesCoerceToId
argument_list|()
specifier|const
block|{
return|return
name|m_coerce_to_id
return|;
block|}
specifier|const
name|char
operator|*
name|GetPrefix
argument_list|()
specifier|const
block|{
return|return
operator|(
name|m_prefix
operator|.
name|empty
argument_list|()
operator|?
name|nullptr
operator|:
name|m_prefix
operator|.
name|c_str
argument_list|()
operator|)
return|;
block|}
name|void
name|SetPrefix
parameter_list|(
specifier|const
name|char
modifier|*
name|prefix
parameter_list|)
block|{
if|if
condition|(
name|prefix
operator|&&
name|prefix
index|[
literal|0
index|]
condition|)
name|m_prefix
operator|=
name|prefix
expr_stmt|;
else|else
name|m_prefix
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|void
name|SetCoerceToId
parameter_list|(
name|bool
name|coerce
init|=
name|true
parameter_list|)
block|{
name|m_coerce_to_id
operator|=
name|coerce
expr_stmt|;
block|}
name|bool
name|DoesUnwindOnError
argument_list|()
specifier|const
block|{
return|return
name|m_unwind_on_error
return|;
block|}
name|void
name|SetUnwindOnError
parameter_list|(
name|bool
name|unwind
init|=
name|false
parameter_list|)
block|{
name|m_unwind_on_error
operator|=
name|unwind
expr_stmt|;
block|}
name|bool
name|DoesIgnoreBreakpoints
argument_list|()
specifier|const
block|{
return|return
name|m_ignore_breakpoints
return|;
block|}
name|void
name|SetIgnoreBreakpoints
parameter_list|(
name|bool
name|ignore
init|=
name|false
parameter_list|)
block|{
name|m_ignore_breakpoints
operator|=
name|ignore
expr_stmt|;
block|}
name|bool
name|DoesKeepInMemory
argument_list|()
specifier|const
block|{
return|return
name|m_keep_in_memory
return|;
block|}
name|void
name|SetKeepInMemory
parameter_list|(
name|bool
name|keep
init|=
name|true
parameter_list|)
block|{
name|m_keep_in_memory
operator|=
name|keep
expr_stmt|;
block|}
name|lldb
operator|::
name|DynamicValueType
name|GetUseDynamic
argument_list|()
specifier|const
block|{
return|return
name|m_use_dynamic
return|;
block|}
name|void
name|SetUseDynamic
argument_list|(
name|lldb
operator|::
name|DynamicValueType
name|dynamic
operator|=
name|lldb
operator|::
name|eDynamicCanRunTarget
argument_list|)
block|{
name|m_use_dynamic
operator|=
name|dynamic
expr_stmt|;
block|}
specifier|const
name|Timeout
operator|<
name|std
operator|::
name|micro
operator|>
operator|&
name|GetTimeout
argument_list|()
specifier|const
block|{
return|return
name|m_timeout
return|;
block|}
name|void
name|SetTimeout
argument_list|(
specifier|const
name|Timeout
operator|<
name|std
operator|::
name|micro
operator|>
operator|&
name|timeout
argument_list|)
block|{
name|m_timeout
operator|=
name|timeout
expr_stmt|;
block|}
specifier|const
name|Timeout
operator|<
name|std
operator|::
name|micro
operator|>
operator|&
name|GetOneThreadTimeout
argument_list|()
specifier|const
block|{
return|return
name|m_one_thread_timeout
return|;
block|}
name|void
name|SetOneThreadTimeout
argument_list|(
specifier|const
name|Timeout
operator|<
name|std
operator|::
name|micro
operator|>
operator|&
name|timeout
argument_list|)
block|{
name|m_one_thread_timeout
operator|=
name|timeout
expr_stmt|;
block|}
name|bool
name|GetTryAllThreads
argument_list|()
specifier|const
block|{
return|return
name|m_try_others
return|;
block|}
name|void
name|SetTryAllThreads
parameter_list|(
name|bool
name|try_others
init|=
name|true
parameter_list|)
block|{
name|m_try_others
operator|=
name|try_others
expr_stmt|;
block|}
name|bool
name|GetStopOthers
argument_list|()
specifier|const
block|{
return|return
name|m_stop_others
return|;
block|}
name|void
name|SetStopOthers
parameter_list|(
name|bool
name|stop_others
init|=
name|true
parameter_list|)
block|{
name|m_stop_others
operator|=
name|stop_others
expr_stmt|;
block|}
name|bool
name|GetDebug
argument_list|()
specifier|const
block|{
return|return
name|m_debug
return|;
block|}
name|void
name|SetDebug
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|m_debug
operator|=
name|b
expr_stmt|;
if|if
condition|(
name|m_debug
condition|)
name|m_generate_debug_info
operator|=
name|true
expr_stmt|;
block|}
name|bool
name|GetGenerateDebugInfo
argument_list|()
specifier|const
block|{
return|return
name|m_generate_debug_info
return|;
block|}
name|void
name|SetGenerateDebugInfo
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|m_generate_debug_info
operator|=
name|b
expr_stmt|;
block|}
name|bool
name|GetColorizeErrors
argument_list|()
specifier|const
block|{
return|return
name|m_ansi_color_errors
return|;
block|}
name|void
name|SetColorizeErrors
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|m_ansi_color_errors
operator|=
name|b
expr_stmt|;
block|}
name|bool
name|GetTrapExceptions
argument_list|()
specifier|const
block|{
return|return
name|m_trap_exceptions
return|;
block|}
name|void
name|SetTrapExceptions
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|m_trap_exceptions
operator|=
name|b
expr_stmt|;
block|}
name|bool
name|GetREPLEnabled
argument_list|()
specifier|const
block|{
return|return
name|m_repl
return|;
block|}
name|void
name|SetREPLEnabled
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|m_repl
operator|=
name|b
expr_stmt|;
block|}
name|void
name|SetCancelCallback
argument_list|(
name|lldb
operator|::
name|ExpressionCancelCallback
name|callback
argument_list|,
name|void
operator|*
name|baton
argument_list|)
block|{
name|m_cancel_callback_baton
operator|=
name|baton
expr_stmt|;
name|m_cancel_callback
operator|=
name|callback
expr_stmt|;
block|}
name|bool
name|InvokeCancelCallback
argument_list|(
name|lldb
operator|::
name|ExpressionEvaluationPhase
name|phase
argument_list|)
decl|const
block|{
return|return
operator|(
operator|(
name|m_cancel_callback
operator|!=
name|nullptr
operator|)
condition|?
name|m_cancel_callback
argument_list|(
name|phase
argument_list|,
name|m_cancel_callback_baton
argument_list|)
else|:
name|false
operator|)
return|;
block|}
comment|// Allows the expression contents to be remapped to point to the specified
comment|// file and line
comment|// using #line directives.
name|void
name|SetPoundLine
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|,
name|uint32_t
name|line
argument_list|)
decl|const
block|{
if|if
condition|(
name|path
operator|&&
name|path
index|[
literal|0
index|]
condition|)
block|{
name|m_pound_line_file
operator|=
name|path
expr_stmt|;
name|m_pound_line_line
operator|=
name|line
expr_stmt|;
block|}
else|else
block|{
name|m_pound_line_file
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_pound_line_line
operator|=
literal|0
expr_stmt|;
block|}
block|}
specifier|const
name|char
operator|*
name|GetPoundLineFilePath
argument_list|()
specifier|const
block|{
return|return
operator|(
name|m_pound_line_file
operator|.
name|empty
argument_list|()
operator|?
name|nullptr
operator|:
name|m_pound_line_file
operator|.
name|c_str
argument_list|()
operator|)
return|;
block|}
name|uint32_t
name|GetPoundLineLine
argument_list|()
specifier|const
block|{
return|return
name|m_pound_line_line
return|;
block|}
name|void
name|SetResultIsInternal
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|m_result_is_internal
operator|=
name|b
expr_stmt|;
block|}
name|bool
name|GetResultIsInternal
argument_list|()
specifier|const
block|{
return|return
name|m_result_is_internal
return|;
block|}
name|void
name|SetAutoApplyFixIts
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|m_auto_apply_fixits
operator|=
name|b
expr_stmt|;
block|}
name|bool
name|GetAutoApplyFixIts
argument_list|()
specifier|const
block|{
return|return
name|m_auto_apply_fixits
return|;
block|}
name|private
label|:
name|ExecutionPolicy
name|m_execution_policy
init|=
name|default_execution_policy
decl_stmt|;
name|lldb
operator|::
name|LanguageType
name|m_language
operator|=
name|lldb
operator|::
name|eLanguageTypeUnknown
expr_stmt|;
name|std
operator|::
name|string
name|m_prefix
expr_stmt|;
name|bool
name|m_coerce_to_id
init|=
name|false
decl_stmt|;
name|bool
name|m_unwind_on_error
init|=
name|true
decl_stmt|;
name|bool
name|m_ignore_breakpoints
init|=
name|false
decl_stmt|;
name|bool
name|m_keep_in_memory
init|=
name|false
decl_stmt|;
name|bool
name|m_try_others
init|=
name|true
decl_stmt|;
name|bool
name|m_stop_others
init|=
name|true
decl_stmt|;
name|bool
name|m_debug
init|=
name|false
decl_stmt|;
name|bool
name|m_trap_exceptions
init|=
name|true
decl_stmt|;
name|bool
name|m_repl
init|=
name|false
decl_stmt|;
name|bool
name|m_generate_debug_info
init|=
name|false
decl_stmt|;
name|bool
name|m_ansi_color_errors
init|=
name|false
decl_stmt|;
name|bool
name|m_result_is_internal
init|=
name|false
decl_stmt|;
name|bool
name|m_auto_apply_fixits
init|=
name|true
decl_stmt|;
name|lldb
operator|::
name|DynamicValueType
name|m_use_dynamic
operator|=
name|lldb
operator|::
name|eNoDynamicValues
expr_stmt|;
name|Timeout
operator|<
name|std
operator|::
name|micro
operator|>
name|m_timeout
operator|=
name|default_timeout
expr_stmt|;
name|Timeout
operator|<
name|std
operator|::
name|micro
operator|>
name|m_one_thread_timeout
operator|=
name|llvm
operator|::
name|None
expr_stmt|;
name|lldb
operator|::
name|ExpressionCancelCallback
name|m_cancel_callback
operator|=
name|nullptr
expr_stmt|;
name|void
modifier|*
name|m_cancel_callback_baton
init|=
name|nullptr
decl_stmt|;
comment|// If m_pound_line_file is not empty and m_pound_line_line is non-zero,
comment|// use #line %u "%s" before the expression content to remap where the source
comment|// originates
name|mutable
name|std
operator|::
name|string
name|m_pound_line_file
expr_stmt|;
name|mutable
name|uint32_t
name|m_pound_line_line
decl_stmt|;
block|}
empty_stmt|;
comment|//----------------------------------------------------------------------
comment|// Target
comment|//----------------------------------------------------------------------
name|class
name|Target
range|:
name|public
name|std
operator|::
name|enable_shared_from_this
operator|<
name|Target
operator|>
decl_stmt|,
name|public
name|TargetProperties
decl_stmt|,
name|public
name|Broadcaster
decl_stmt|,
name|public
name|ExecutionContextScope
decl_stmt|,
name|public
name|ModuleList
decl|::
name|Notifier
block|{
name|public
label|:
name|friend
name|class
name|TargetList
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Broadcaster event bits definitions.
comment|//------------------------------------------------------------------
enum|enum
block|{
name|eBroadcastBitBreakpointChanged
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|eBroadcastBitModulesLoaded
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|eBroadcastBitModulesUnloaded
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
name|eBroadcastBitWatchpointChanged
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
name|eBroadcastBitSymbolsLoaded
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|}
enum|;
comment|// These two functions fill out the Broadcaster interface:
specifier|static
name|ConstString
modifier|&
name|GetStaticBroadcasterClass
parameter_list|()
function_decl|;
name|ConstString
operator|&
name|GetBroadcasterClass
argument_list|()
specifier|const
name|override
block|{
return|return
name|GetStaticBroadcasterClass
argument_list|()
return|;
block|}
comment|// This event data class is for use by the TargetList to broadcast new target
comment|// notifications.
name|class
name|TargetEventData
range|:
name|public
name|EventData
block|{
name|public
operator|:
name|TargetEventData
argument_list|(
specifier|const
name|lldb
operator|::
name|TargetSP
operator|&
name|target_sp
argument_list|)
block|;
name|TargetEventData
argument_list|(
specifier|const
name|lldb
operator|::
name|TargetSP
operator|&
name|target_sp
argument_list|,
specifier|const
name|ModuleList
operator|&
name|module_list
argument_list|)
block|;
operator|~
name|TargetEventData
argument_list|()
name|override
block|;
specifier|static
specifier|const
name|ConstString
operator|&
name|GetFlavorString
argument_list|()
block|;
specifier|const
name|ConstString
operator|&
name|GetFlavor
argument_list|()
specifier|const
name|override
block|{
return|return
name|TargetEventData
operator|::
name|GetFlavorString
argument_list|()
return|;
block|}
name|void
name|Dump
argument_list|(
argument|Stream *s
argument_list|)
specifier|const
name|override
block|;
specifier|static
specifier|const
name|TargetEventData
operator|*
name|GetEventDataFromEvent
argument_list|(
specifier|const
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
specifier|static
name|lldb
operator|::
name|TargetSP
name|GetTargetFromEvent
argument_list|(
specifier|const
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
specifier|static
name|ModuleList
name|GetModuleListFromEvent
argument_list|(
specifier|const
name|Event
operator|*
name|event_ptr
argument_list|)
block|;
specifier|const
name|lldb
operator|::
name|TargetSP
operator|&
name|GetTarget
argument_list|()
specifier|const
block|{
return|return
name|m_target_sp
return|;
block|}
specifier|const
name|ModuleList
operator|&
name|GetModuleList
argument_list|()
specifier|const
block|{
return|return
name|m_module_list
return|;
block|}
name|private
operator|:
name|lldb
operator|::
name|TargetSP
name|m_target_sp
block|;
name|ModuleList
name|m_module_list
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TargetEventData
argument_list|)
block|;   }
decl_stmt|;
operator|~
name|Target
argument_list|()
name|override
expr_stmt|;
specifier|static
name|void
name|SettingsInitialize
parameter_list|()
function_decl|;
specifier|static
name|void
name|SettingsTerminate
parameter_list|()
function_decl|;
specifier|static
name|FileSpecList
name|GetDefaultExecutableSearchPaths
parameter_list|()
function_decl|;
specifier|static
name|FileSpecList
name|GetDefaultDebugFileSearchPaths
parameter_list|()
function_decl|;
specifier|static
name|FileSpecList
name|GetDefaultClangModuleSearchPaths
parameter_list|()
function_decl|;
specifier|static
name|ArchSpec
name|GetDefaultArchitecture
parameter_list|()
function_decl|;
specifier|static
name|void
name|SetDefaultArchitecture
parameter_list|(
specifier|const
name|ArchSpec
modifier|&
name|arch
parameter_list|)
function_decl|;
comment|//    void
comment|//    UpdateInstanceName ();
name|lldb
operator|::
name|ModuleSP
name|GetSharedModule
argument_list|(
specifier|const
name|ModuleSpec
operator|&
name|module_spec
argument_list|,
name|Status
operator|*
name|error_ptr
operator|=
name|nullptr
argument_list|)
expr_stmt|;
comment|//----------------------------------------------------------------------
comment|// Settings accessors
comment|//----------------------------------------------------------------------
specifier|static
specifier|const
name|lldb
operator|::
name|TargetPropertiesSP
operator|&
name|GetGlobalProperties
argument_list|()
expr_stmt|;
name|std
operator|::
name|recursive_mutex
operator|&
name|GetAPIMutex
argument_list|()
block|{
return|return
name|m_mutex
return|;
block|}
name|void
name|DeleteCurrentProcess
parameter_list|()
function_decl|;
name|void
name|CleanupProcess
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Dump a description of this object to a Stream.
comment|///
comment|/// Dump a description of the contents of this object to the
comment|/// supplied stream \a s. The dumped content will be only what has
comment|/// been loaded or parsed up to this point at which this function
comment|/// is called, so this is a good way to see what has been parsed
comment|/// in a target.
comment|///
comment|/// @param[in] s
comment|///     The stream to which to dump the object description.
comment|//------------------------------------------------------------------
name|void
name|Dump
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|lldb
operator|::
name|DescriptionLevel
name|description_level
argument_list|)
decl_stmt|;
specifier|const
name|lldb
operator|::
name|ProcessSP
operator|&
name|CreateProcess
argument_list|(
argument|lldb::ListenerSP listener
argument_list|,
argument|llvm::StringRef plugin_name
argument_list|,
argument|const FileSpec *crash_file
argument_list|)
expr_stmt|;
specifier|const
name|lldb
operator|::
name|ProcessSP
operator|&
name|GetProcessSP
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|IsValid
parameter_list|()
block|{
return|return
name|m_valid
return|;
block|}
name|void
name|Destroy
parameter_list|()
function_decl|;
name|Status
name|Launch
parameter_list|(
name|ProcessLaunchInfo
modifier|&
name|launch_info
parameter_list|,
name|Stream
modifier|*
name|stream
parameter_list|)
function_decl|;
comment|// Optional stream to receive first stop info
name|Status
name|Attach
parameter_list|(
name|ProcessAttachInfo
modifier|&
name|attach_info
parameter_list|,
name|Stream
modifier|*
name|stream
parameter_list|)
function_decl|;
comment|// Optional stream to receive first stop info
comment|//------------------------------------------------------------------
comment|// This part handles the breakpoints.
comment|//------------------------------------------------------------------
name|BreakpointList
modifier|&
name|GetBreakpointList
parameter_list|(
name|bool
name|internal
init|=
name|false
parameter_list|)
function_decl|;
specifier|const
name|BreakpointList
modifier|&
name|GetBreakpointList
argument_list|(
name|bool
name|internal
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
name|lldb
operator|::
name|BreakpointSP
name|GetLastCreatedBreakpoint
argument_list|()
block|{
return|return
name|m_last_created_breakpoint
return|;
block|}
name|lldb
operator|::
name|BreakpointSP
name|GetBreakpointByID
argument_list|(
argument|lldb::break_id_t break_id
argument_list|)
expr_stmt|;
comment|// Use this to create a file and line breakpoint to a given module or all
comment|// module it is nullptr
name|lldb
operator|::
name|BreakpointSP
name|CreateBreakpoint
argument_list|(
argument|const FileSpecList *containingModules
argument_list|,
argument|const FileSpec&file
argument_list|,
argument|uint32_t line_no
argument_list|,
argument|lldb::addr_t offset
argument_list|,
argument|LazyBool check_inlines
argument_list|,
argument|LazyBool skip_prologue
argument_list|,
argument|bool internal
argument_list|,
argument|bool request_hardware
argument_list|,
argument|LazyBool move_to_nearest_code
argument_list|)
expr_stmt|;
comment|// Use this to create breakpoint that matches regex against the source lines
comment|// in files given in source_file_list:
comment|// If function_names is non-empty, also filter by function after the matches
comment|// are made.
name|lldb
operator|::
name|BreakpointSP
name|CreateSourceRegexBreakpoint
argument_list|(
argument|const FileSpecList *containingModules
argument_list|,
argument|const FileSpecList *source_file_list
argument_list|,
argument|const std::unordered_set<std::string>&function_names
argument_list|,
argument|RegularExpression&source_regex
argument_list|,
argument|bool internal
argument_list|,
argument|bool request_hardware
argument_list|,
argument|LazyBool move_to_nearest_code
argument_list|)
expr_stmt|;
comment|// Use this to create a breakpoint from a load address
name|lldb
operator|::
name|BreakpointSP
name|CreateBreakpoint
argument_list|(
argument|lldb::addr_t load_addr
argument_list|,
argument|bool internal
argument_list|,
argument|bool request_hardware
argument_list|)
expr_stmt|;
comment|// Use this to create a breakpoint from a load address and a module file spec
name|lldb
operator|::
name|BreakpointSP
name|CreateAddressInModuleBreakpoint
argument_list|(
argument|lldb::addr_t file_addr
argument_list|,
argument|bool internal
argument_list|,
argument|const FileSpec *file_spec
argument_list|,
argument|bool request_hardware
argument_list|)
expr_stmt|;
comment|// Use this to create Address breakpoints:
name|lldb
operator|::
name|BreakpointSP
name|CreateBreakpoint
argument_list|(
argument|const Address&addr
argument_list|,
argument|bool internal
argument_list|,
argument|bool request_hardware
argument_list|)
expr_stmt|;
comment|// Use this to create a function breakpoint by regexp in
comment|// containingModule/containingSourceFiles, or all modules if it is nullptr
comment|// When "skip_prologue is set to eLazyBoolCalculate, we use the current target
comment|// setting, else we use the values passed in
name|lldb
operator|::
name|BreakpointSP
name|CreateFuncRegexBreakpoint
argument_list|(
argument|const FileSpecList *containingModules
argument_list|,
argument|const FileSpecList *containingSourceFiles
argument_list|,
argument|RegularExpression&func_regexp
argument_list|,
argument|lldb::LanguageType requested_language
argument_list|,
argument|LazyBool skip_prologue
argument_list|,
argument|bool internal
argument_list|,
argument|bool request_hardware
argument_list|)
expr_stmt|;
comment|// Use this to create a function breakpoint by name in containingModule, or
comment|// all modules if it is nullptr
comment|// When "skip_prologue is set to eLazyBoolCalculate, we use the current target
comment|// setting, else we use the values passed in.
comment|// func_name_type_mask is or'ed values from the FunctionNameType enum.
name|lldb
operator|::
name|BreakpointSP
name|CreateBreakpoint
argument_list|(
argument|const FileSpecList *containingModules
argument_list|,
argument|const FileSpecList *containingSourceFiles
argument_list|,
argument|const char *func_name
argument_list|,
argument|uint32_t func_name_type_mask
argument_list|,
argument|lldb::LanguageType language
argument_list|,
argument|lldb::addr_t offset
argument_list|,
argument|LazyBool skip_prologue
argument_list|,
argument|bool internal
argument_list|,
argument|bool request_hardware
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|BreakpointSP
name|CreateExceptionBreakpoint
argument_list|(
argument|enum lldb::LanguageType language
argument_list|,
argument|bool catch_bp
argument_list|,
argument|bool throw_bp
argument_list|,
argument|bool internal
argument_list|,
argument|Args *additional_args = nullptr
argument_list|,
argument|Status *additional_args_error = nullptr
argument_list|)
expr_stmt|;
comment|// This is the same as the func_name breakpoint except that you can specify a
comment|// vector of names.  This is cheaper
comment|// than a regular expression breakpoint in the case where you just want to set
comment|// a breakpoint on a set of names
comment|// you already know.
comment|// func_name_type_mask is or'ed values from the FunctionNameType enum.
name|lldb
operator|::
name|BreakpointSP
name|CreateBreakpoint
argument_list|(
argument|const FileSpecList *containingModules
argument_list|,
argument|const FileSpecList *containingSourceFiles
argument_list|,
argument|const char *func_names[]
argument_list|,
argument|size_t num_names
argument_list|,
argument|uint32_t func_name_type_mask
argument_list|,
argument|lldb::LanguageType language
argument_list|,
argument|lldb::addr_t offset
argument_list|,
argument|LazyBool skip_prologue
argument_list|,
argument|bool internal
argument_list|,
argument|bool request_hardware
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|BreakpointSP
name|CreateBreakpoint
argument_list|(
argument|const FileSpecList *containingModules
argument_list|,
argument|const FileSpecList *containingSourceFiles
argument_list|,
argument|const std::vector<std::string>&func_names
argument_list|,
argument|uint32_t func_name_type_mask
argument_list|,
argument|lldb::LanguageType language
argument_list|,
argument|lldb::addr_t m_offset
argument_list|,
argument|LazyBool skip_prologue
argument_list|,
argument|bool internal
argument_list|,
argument|bool request_hardware
argument_list|)
expr_stmt|;
comment|// Use this to create a general breakpoint:
name|lldb
operator|::
name|BreakpointSP
name|CreateBreakpoint
argument_list|(
argument|lldb::SearchFilterSP&filter_sp
argument_list|,
argument|lldb::BreakpointResolverSP&resolver_sp
argument_list|,
argument|bool internal
argument_list|,
argument|bool request_hardware
argument_list|,
argument|bool resolve_indirect_symbols
argument_list|)
expr_stmt|;
comment|// Use this to create a watchpoint:
name|lldb
operator|::
name|WatchpointSP
name|CreateWatchpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|size_t size
argument_list|,
argument|const CompilerType *type
argument_list|,
argument|uint32_t kind
argument_list|,
argument|Status&error
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|WatchpointSP
name|GetLastCreatedWatchpoint
argument_list|()
block|{
return|return
name|m_last_created_watchpoint
return|;
block|}
name|WatchpointList
modifier|&
name|GetWatchpointList
parameter_list|()
block|{
return|return
name|m_watchpoint_list
return|;
block|}
name|void
name|RemoveAllBreakpoints
parameter_list|(
name|bool
name|internal_also
init|=
name|false
parameter_list|)
function_decl|;
name|void
name|DisableAllBreakpoints
parameter_list|(
name|bool
name|internal_also
init|=
name|false
parameter_list|)
function_decl|;
name|void
name|EnableAllBreakpoints
parameter_list|(
name|bool
name|internal_also
init|=
name|false
parameter_list|)
function_decl|;
name|bool
name|DisableBreakpointByID
argument_list|(
name|lldb
operator|::
name|break_id_t
name|break_id
argument_list|)
decl_stmt|;
name|bool
name|EnableBreakpointByID
argument_list|(
name|lldb
operator|::
name|break_id_t
name|break_id
argument_list|)
decl_stmt|;
name|bool
name|RemoveBreakpointByID
argument_list|(
name|lldb
operator|::
name|break_id_t
name|break_id
argument_list|)
decl_stmt|;
comment|// The flag 'end_to_end', default to true, signifies that the operation is
comment|// performed end to end, for both the debugger and the debuggee.
name|bool
name|RemoveAllWatchpoints
parameter_list|(
name|bool
name|end_to_end
init|=
name|true
parameter_list|)
function_decl|;
name|bool
name|DisableAllWatchpoints
parameter_list|(
name|bool
name|end_to_end
init|=
name|true
parameter_list|)
function_decl|;
name|bool
name|EnableAllWatchpoints
parameter_list|(
name|bool
name|end_to_end
init|=
name|true
parameter_list|)
function_decl|;
name|bool
name|ClearAllWatchpointHitCounts
parameter_list|()
function_decl|;
name|bool
name|ClearAllWatchpointHistoricValues
parameter_list|()
function_decl|;
name|bool
name|IgnoreAllWatchpoints
parameter_list|(
name|uint32_t
name|ignore_count
parameter_list|)
function_decl|;
name|bool
name|DisableWatchpointByID
argument_list|(
name|lldb
operator|::
name|watch_id_t
name|watch_id
argument_list|)
decl_stmt|;
name|bool
name|EnableWatchpointByID
argument_list|(
name|lldb
operator|::
name|watch_id_t
name|watch_id
argument_list|)
decl_stmt|;
name|bool
name|RemoveWatchpointByID
argument_list|(
name|lldb
operator|::
name|watch_id_t
name|watch_id
argument_list|)
decl_stmt|;
name|bool
name|IgnoreWatchpointByID
argument_list|(
name|lldb
operator|::
name|watch_id_t
name|watch_id
argument_list|,
name|uint32_t
name|ignore_count
argument_list|)
decl_stmt|;
name|Status
name|SerializeBreakpointsToFile
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|file
parameter_list|,
specifier|const
name|BreakpointIDList
modifier|&
name|bp_ids
parameter_list|,
name|bool
name|append
parameter_list|)
function_decl|;
name|Status
name|CreateBreakpointsFromFile
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|file
parameter_list|,
name|BreakpointIDList
modifier|&
name|new_bps
parameter_list|)
function_decl|;
name|Status
name|CreateBreakpointsFromFile
argument_list|(
specifier|const
name|FileSpec
operator|&
name|file
argument_list|,
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|names
argument_list|,
name|BreakpointIDList
operator|&
name|new_bps
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get \a load_addr as a callable code load address for this target
comment|///
comment|/// Take \a load_addr and potentially add any address bits that are
comment|/// needed to make the address callable. For ARM this can set bit
comment|/// zero (if it already isn't) if \a load_addr is a thumb function.
comment|/// If \a addr_class is set to eAddressClassInvalid, then the address
comment|/// adjustment will always happen. If it is set to an address class
comment|/// that doesn't have code in it, LLDB_INVALID_ADDRESS will be
comment|/// returned.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|addr_t
name|GetCallableLoadAddress
argument_list|(
argument|lldb::addr_t load_addr
argument_list|,
argument|lldb::AddressClass addr_class = lldb::eAddressClassInvalid
argument_list|)
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get \a load_addr as an opcode for this target.
comment|///
comment|/// Take \a load_addr and potentially strip any address bits that are
comment|/// needed to make the address point to an opcode. For ARM this can
comment|/// clear bit zero (if it already isn't) if \a load_addr is a
comment|/// thumb function and load_addr is in code.
comment|/// If \a addr_class is set to eAddressClassInvalid, then the address
comment|/// adjustment will always happen. If it is set to an address class
comment|/// that doesn't have code in it, LLDB_INVALID_ADDRESS will be
comment|/// returned.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|addr_t
name|GetOpcodeLoadAddress
argument_list|(
argument|lldb::addr_t load_addr
argument_list|,
argument|lldb::AddressClass addr_class = lldb::eAddressClassInvalid
argument_list|)
specifier|const
expr_stmt|;
comment|// Get load_addr as breakable load address for this target.
comment|// Take a addr and check if for any reason there is a better address than this
comment|// to put a breakpoint on.
comment|// If there is then return that address.
comment|// For MIPS, if instruction at addr is a delay slot instruction then this
comment|// method will find the address of its
comment|// previous instruction and return that address.
name|lldb
operator|::
name|addr_t
name|GetBreakableLoadAddress
argument_list|(
argument|lldb::addr_t addr
argument_list|)
expr_stmt|;
name|void
name|ModulesDidLoad
parameter_list|(
name|ModuleList
modifier|&
name|module_list
parameter_list|)
function_decl|;
name|void
name|ModulesDidUnload
parameter_list|(
name|ModuleList
modifier|&
name|module_list
parameter_list|,
name|bool
name|delete_locations
parameter_list|)
function_decl|;
name|void
name|SymbolsDidLoad
parameter_list|(
name|ModuleList
modifier|&
name|module_list
parameter_list|)
function_decl|;
name|void
name|ClearModules
parameter_list|(
name|bool
name|delete_locations
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Called as the last function in Process::DidExec().
comment|///
comment|/// Process::DidExec() will clear a lot of state in the process,
comment|/// then try to reload a dynamic loader plugin to discover what
comment|/// binaries are currently available and then this function should
comment|/// be called to allow the target to do any cleanup after everything
comment|/// has been figured out. It can remove breakpoints that no longer
comment|/// make sense as the exec might have changed the target
comment|/// architecture, and unloaded some modules that might get deleted.
comment|//------------------------------------------------------------------
name|void
name|DidExec
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Gets the module for the main executable.
comment|///
comment|/// Each process has a notion of a main executable that is the file
comment|/// that will be executed or attached to. Executable files can have
comment|/// dependent modules that are discovered from the object files, or
comment|/// discovered at runtime as things are dynamically loaded.
comment|///
comment|/// @return
comment|///     The shared pointer to the executable module which can
comment|///     contains a nullptr Module object if no executable has been
comment|///     set.
comment|///
comment|/// @see DynamicLoader
comment|/// @see ObjectFile::GetDependentModules (FileSpecList&)
comment|/// @see Process::SetExecutableModule(lldb::ModuleSP&)
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ModuleSP
name|GetExecutableModule
argument_list|()
expr_stmt|;
name|Module
modifier|*
name|GetExecutableModulePointer
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Set the main executable module.
comment|///
comment|/// Each process has a notion of a main executable that is the file
comment|/// that will be executed or attached to. Executable files can have
comment|/// dependent modules that are discovered from the object files, or
comment|/// discovered at runtime as things are dynamically loaded.
comment|///
comment|/// Setting the executable causes any of the current dependent
comment|/// image information to be cleared and replaced with the static
comment|/// dependent image information found by calling
comment|/// ObjectFile::GetDependentModules (FileSpecList&) on the main
comment|/// executable and any modules on which it depends. Calling
comment|/// Process::GetImages() will return the newly found images that
comment|/// were obtained from all of the object files.
comment|///
comment|/// @param[in] module_sp
comment|///     A shared pointer reference to the module that will become
comment|///     the main executable for this process.
comment|///
comment|/// @param[in] get_dependent_files
comment|///     If \b true then ask the object files to track down any
comment|///     known dependent files.
comment|///
comment|/// @see ObjectFile::GetDependentModules (FileSpecList&)
comment|/// @see Process::GetImages()
comment|//------------------------------------------------------------------
name|void
name|SetExecutableModule
argument_list|(
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|,
name|bool
name|get_dependent_files
argument_list|)
decl_stmt|;
name|bool
name|LoadScriptingResources
argument_list|(
name|std
operator|::
name|list
operator|<
name|Status
operator|>
operator|&
name|errors
argument_list|,
name|Stream
operator|*
name|feedback_stream
operator|=
name|nullptr
argument_list|,
name|bool
name|continue_on_error
operator|=
name|true
argument_list|)
block|{
return|return
name|m_images
operator|.
name|LoadScriptingResourcesInTarget
argument_list|(
name|this
argument_list|,
name|errors
argument_list|,
name|feedback_stream
argument_list|,
name|continue_on_error
argument_list|)
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get accessor for the images for this process.
comment|///
comment|/// Each process has a notion of a main executable that is the file
comment|/// that will be executed or attached to. Executable files can have
comment|/// dependent modules that are discovered from the object files, or
comment|/// discovered at runtime as things are dynamically loaded. After
comment|/// a main executable has been set, the images will contain a list
comment|/// of all the files that the executable depends upon as far as the
comment|/// object files know. These images will usually contain valid file
comment|/// virtual addresses only. When the process is launched or attached
comment|/// to, the DynamicLoader plug-in will discover where these images
comment|/// were loaded in memory and will resolve the load virtual
comment|/// addresses is each image, and also in images that are loaded by
comment|/// code.
comment|///
comment|/// @return
comment|///     A list of Module objects in a module list.
comment|//------------------------------------------------------------------
specifier|const
name|ModuleList
operator|&
name|GetImages
argument_list|()
specifier|const
block|{
return|return
name|m_images
return|;
block|}
name|ModuleList
modifier|&
name|GetImages
parameter_list|()
block|{
return|return
name|m_images
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return whether this FileSpec corresponds to a module that should be
comment|/// considered for general searches.
comment|///
comment|/// This API will be consulted by the SearchFilterForUnconstrainedSearches
comment|/// and any module that returns \b true will not be searched.  Note the
comment|/// SearchFilterForUnconstrainedSearches is the search filter that
comment|/// gets used in the CreateBreakpoint calls when no modules is provided.
comment|///
comment|/// The target call at present just consults the Platform's call of the
comment|/// same name.
comment|///
comment|/// @param[in] module_sp
comment|///     A shared pointer reference to the module that checked.
comment|///
comment|/// @return \b true if the module should be excluded, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|ModuleIsExcludedForUnconstrainedSearches
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|module_spec
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Return whether this module should be considered for general searches.
comment|///
comment|/// This API will be consulted by the SearchFilterForUnconstrainedSearches
comment|/// and any module that returns \b true will not be searched.  Note the
comment|/// SearchFilterForUnconstrainedSearches is the search filter that
comment|/// gets used in the CreateBreakpoint calls when no modules is provided.
comment|///
comment|/// The target call at present just consults the Platform's call of the
comment|/// same name.
comment|///
comment|/// FIXME: When we get time we should add a way for the user to set modules
comment|/// that they
comment|/// don't want searched, in addition to or instead of the platform ones.
comment|///
comment|/// @param[in] module_sp
comment|///     A shared pointer reference to the module that checked.
comment|///
comment|/// @return \b true if the module should be excluded, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|ModuleIsExcludedForUnconstrainedSearches
argument_list|(
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|)
decl_stmt|;
specifier|const
name|ArchSpec
operator|&
name|GetArchitecture
argument_list|()
specifier|const
block|{
return|return
name|m_arch
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Set the architecture for this target.
comment|///
comment|/// If the current target has no Images read in, then this just sets the
comment|/// architecture, which will
comment|/// be used to select the architecture of the ExecutableModule when that is
comment|/// set.
comment|/// If the current target has an ExecutableModule, then calling
comment|/// SetArchitecture with a different
comment|/// architecture from the currently selected one will reset the
comment|/// ExecutableModule to that slice
comment|/// of the file backing the ExecutableModule.  If the file backing the
comment|/// ExecutableModule does not
comment|/// contain a fork of this architecture, then this code will return false, and
comment|/// the architecture
comment|/// won't be changed.
comment|/// If the input arch_spec is the same as the already set architecture, this
comment|/// is a no-op.
comment|///
comment|/// @param[in] arch_spec
comment|///     The new architecture.
comment|///
comment|/// @return
comment|///     \b true if the architecture was successfully set, \bfalse otherwise.
comment|//------------------------------------------------------------------
name|bool
name|SetArchitecture
parameter_list|(
specifier|const
name|ArchSpec
modifier|&
name|arch_spec
parameter_list|)
function_decl|;
name|bool
name|MergeArchitecture
parameter_list|(
specifier|const
name|ArchSpec
modifier|&
name|arch_spec
parameter_list|)
function_decl|;
name|Debugger
modifier|&
name|GetDebugger
parameter_list|()
block|{
return|return
name|m_debugger
return|;
block|}
name|size_t
name|ReadMemoryFromFileCache
parameter_list|(
specifier|const
name|Address
modifier|&
name|addr
parameter_list|,
name|void
modifier|*
name|dst
parameter_list|,
name|size_t
name|dst_len
parameter_list|,
name|Status
modifier|&
name|error
parameter_list|)
function_decl|;
comment|// Reading memory through the target allows us to skip going to the process
comment|// for reading memory if possible and it allows us to try and read from
comment|// any constant sections in our object files on disk. If you always want
comment|// live program memory, read straight from the process. If you possibly
comment|// want to read from const sections in object files, read from the target.
comment|// This version of ReadMemory will try and read memory from the process
comment|// if the process is alive. The order is:
comment|// 1 - if (prefer_file_cache == true) then read from object file cache
comment|// 2 - if there is a valid process, try and read from its memory
comment|// 3 - if (prefer_file_cache == false) then read from object file cache
name|size_t
name|ReadMemory
argument_list|(
specifier|const
name|Address
operator|&
name|addr
argument_list|,
name|bool
name|prefer_file_cache
argument_list|,
name|void
operator|*
name|dst
argument_list|,
name|size_t
name|dst_len
argument_list|,
name|Status
operator|&
name|error
argument_list|,
name|lldb
operator|::
name|addr_t
operator|*
name|load_addr_ptr
operator|=
name|nullptr
argument_list|)
decl_stmt|;
name|size_t
name|ReadCStringFromMemory
argument_list|(
specifier|const
name|Address
operator|&
name|addr
argument_list|,
name|std
operator|::
name|string
operator|&
name|out_str
argument_list|,
name|Status
operator|&
name|error
argument_list|)
decl_stmt|;
name|size_t
name|ReadCStringFromMemory
parameter_list|(
specifier|const
name|Address
modifier|&
name|addr
parameter_list|,
name|char
modifier|*
name|dst
parameter_list|,
name|size_t
name|dst_max_len
parameter_list|,
name|Status
modifier|&
name|result_error
parameter_list|)
function_decl|;
name|size_t
name|ReadScalarIntegerFromMemory
parameter_list|(
specifier|const
name|Address
modifier|&
name|addr
parameter_list|,
name|bool
name|prefer_file_cache
parameter_list|,
name|uint32_t
name|byte_size
parameter_list|,
name|bool
name|is_signed
parameter_list|,
name|Scalar
modifier|&
name|scalar
parameter_list|,
name|Status
modifier|&
name|error
parameter_list|)
function_decl|;
name|uint64_t
name|ReadUnsignedIntegerFromMemory
parameter_list|(
specifier|const
name|Address
modifier|&
name|addr
parameter_list|,
name|bool
name|prefer_file_cache
parameter_list|,
name|size_t
name|integer_byte_size
parameter_list|,
name|uint64_t
name|fail_value
parameter_list|,
name|Status
modifier|&
name|error
parameter_list|)
function_decl|;
name|bool
name|ReadPointerFromMemory
parameter_list|(
specifier|const
name|Address
modifier|&
name|addr
parameter_list|,
name|bool
name|prefer_file_cache
parameter_list|,
name|Status
modifier|&
name|error
parameter_list|,
name|Address
modifier|&
name|pointer_addr
parameter_list|)
function_decl|;
name|SectionLoadList
modifier|&
name|GetSectionLoadList
parameter_list|()
block|{
return|return
name|m_section_load_history
operator|.
name|GetCurrentSectionLoadList
argument_list|()
return|;
block|}
comment|//    const SectionLoadList&
comment|//    GetSectionLoadList() const
comment|//    {
comment|//        return const_cast<SectionLoadHistory
comment|//        *>(&m_section_load_history)->GetCurrentSectionLoadList();
comment|//    }
specifier|static
name|Target
modifier|*
name|GetTargetFromContexts
parameter_list|(
specifier|const
name|ExecutionContext
modifier|*
name|exe_ctx_ptr
parameter_list|,
specifier|const
name|SymbolContext
modifier|*
name|sc_ptr
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|// lldb::ExecutionContextScope pure virtual functions
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|TargetSP
name|CalculateTarget
argument_list|()
name|override
expr_stmt|;
name|lldb
operator|::
name|ProcessSP
name|CalculateProcess
argument_list|()
name|override
expr_stmt|;
name|lldb
operator|::
name|ThreadSP
name|CalculateThread
argument_list|()
name|override
expr_stmt|;
name|lldb
operator|::
name|StackFrameSP
name|CalculateStackFrame
argument_list|()
name|override
expr_stmt|;
name|void
name|CalculateExecutionContext
argument_list|(
name|ExecutionContext
operator|&
name|exe_ctx
argument_list|)
name|override
decl_stmt|;
name|PathMappingList
modifier|&
name|GetImageSearchPathList
parameter_list|()
function_decl|;
name|TypeSystem
modifier|*
name|GetScratchTypeSystemForLanguage
argument_list|(
name|Status
operator|*
name|error
argument_list|,
name|lldb
operator|::
name|LanguageType
name|language
argument_list|,
name|bool
name|create_on_demand
operator|=
name|true
argument_list|)
decl_stmt|;
name|PersistentExpressionState
modifier|*
name|GetPersistentExpressionStateForLanguage
argument_list|(
name|lldb
operator|::
name|LanguageType
name|language
argument_list|)
decl_stmt|;
comment|// Creates a UserExpression for the given language, the rest of the parameters
comment|// have the
comment|// same meaning as for the UserExpression constructor.
comment|// Returns a new-ed object which the caller owns.
name|UserExpression
modifier|*
name|GetUserExpressionForLanguage
argument_list|(
name|llvm
operator|::
name|StringRef
name|expr
argument_list|,
name|llvm
operator|::
name|StringRef
name|prefix
argument_list|,
name|lldb
operator|::
name|LanguageType
name|language
argument_list|,
name|Expression
operator|::
name|ResultType
name|desired_type
argument_list|,
specifier|const
name|EvaluateExpressionOptions
operator|&
name|options
argument_list|,
name|Status
operator|&
name|error
argument_list|)
decl_stmt|;
comment|// Creates a FunctionCaller for the given language, the rest of the parameters
comment|// have the
comment|// same meaning as for the FunctionCaller constructor.  Since a FunctionCaller
comment|// can't be
comment|// IR Interpreted, it makes no sense to call this with an
comment|// ExecutionContextScope that lacks
comment|// a Process.
comment|// Returns a new-ed object which the caller owns.
name|FunctionCaller
modifier|*
name|GetFunctionCallerForLanguage
argument_list|(
name|lldb
operator|::
name|LanguageType
name|language
argument_list|,
specifier|const
name|CompilerType
operator|&
name|return_type
argument_list|,
specifier|const
name|Address
operator|&
name|function_address
argument_list|,
specifier|const
name|ValueList
operator|&
name|arg_value_list
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|,
name|Status
operator|&
name|error
argument_list|)
decl_stmt|;
comment|// Creates a UtilityFunction for the given language, the rest of the
comment|// parameters have the
comment|// same meaning as for the UtilityFunction constructor.
comment|// Returns a new-ed object which the caller owns.
name|UtilityFunction
modifier|*
name|GetUtilityFunctionForLanguage
argument_list|(
specifier|const
name|char
operator|*
name|expr
argument_list|,
name|lldb
operator|::
name|LanguageType
name|language
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|,
name|Status
operator|&
name|error
argument_list|)
decl_stmt|;
name|ClangASTContext
modifier|*
name|GetScratchClangASTContext
parameter_list|(
name|bool
name|create_on_demand
init|=
name|true
parameter_list|)
function_decl|;
name|lldb
operator|::
name|ClangASTImporterSP
name|GetClangASTImporter
argument_list|()
expr_stmt|;
comment|//----------------------------------------------------------------------
comment|// Install any files through the platform that need be to installed
comment|// prior to launching or attaching.
comment|//----------------------------------------------------------------------
name|Status
name|Install
parameter_list|(
name|ProcessLaunchInfo
modifier|*
name|launch_info
parameter_list|)
function_decl|;
name|bool
name|ResolveFileAddress
argument_list|(
name|lldb
operator|::
name|addr_t
name|load_addr
argument_list|,
name|Address
operator|&
name|so_addr
argument_list|)
decl_stmt|;
name|bool
name|ResolveLoadAddress
argument_list|(
name|lldb
operator|::
name|addr_t
name|load_addr
argument_list|,
name|Address
operator|&
name|so_addr
argument_list|,
name|uint32_t
name|stop_id
operator|=
name|SectionLoadHistory
operator|::
name|eStopIDNow
argument_list|)
decl_stmt|;
name|bool
name|SetSectionLoadAddress
argument_list|(
specifier|const
name|lldb
operator|::
name|SectionSP
operator|&
name|section
argument_list|,
name|lldb
operator|::
name|addr_t
name|load_addr
argument_list|,
name|bool
name|warn_multiple
operator|=
name|false
argument_list|)
decl_stmt|;
name|size_t
name|UnloadModuleSections
argument_list|(
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|)
decl_stmt|;
name|size_t
name|UnloadModuleSections
parameter_list|(
specifier|const
name|ModuleList
modifier|&
name|module_list
parameter_list|)
function_decl|;
name|bool
name|SetSectionUnloaded
argument_list|(
specifier|const
name|lldb
operator|::
name|SectionSP
operator|&
name|section_sp
argument_list|)
decl_stmt|;
name|bool
name|SetSectionUnloaded
argument_list|(
specifier|const
name|lldb
operator|::
name|SectionSP
operator|&
name|section_sp
argument_list|,
name|lldb
operator|::
name|addr_t
name|load_addr
argument_list|)
decl_stmt|;
name|void
name|ClearAllLoadedSections
parameter_list|()
function_decl|;
comment|// Since expressions results can persist beyond the lifetime of a process,
comment|// and the const expression results are available after a process is gone,
comment|// we provide a way for expressions to be evaluated from the Target itself.
comment|// If an expression is going to be run, then it should have a frame filled
comment|// in in th execution context.
name|lldb
operator|::
name|ExpressionResults
name|EvaluateExpression
argument_list|(
argument|llvm::StringRef expression
argument_list|,
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|lldb::ValueObjectSP&result_valobj_sp
argument_list|,
argument|const EvaluateExpressionOptions&options = EvaluateExpressionOptions()
argument_list|,
argument|std::string *fixed_expression = nullptr
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|ExpressionVariableSP
name|GetPersistentVariable
argument_list|(
specifier|const
name|ConstString
operator|&
name|name
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|addr_t
name|GetPersistentSymbol
argument_list|(
specifier|const
name|ConstString
operator|&
name|name
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Target Stop Hooks
comment|//------------------------------------------------------------------
name|class
name|StopHook
range|:
name|public
name|UserID
block|{
name|public
operator|:
name|StopHook
argument_list|(
specifier|const
name|StopHook
operator|&
name|rhs
argument_list|)
block|;
operator|~
name|StopHook
argument_list|()
block|;
name|StringList
operator|*
name|GetCommandPointer
argument_list|()
block|{
return|return
operator|&
name|m_commands
return|;
block|}
specifier|const
name|StringList
operator|&
name|GetCommands
argument_list|()
block|{
return|return
name|m_commands
return|;
block|}
name|lldb
operator|::
name|TargetSP
operator|&
name|GetTarget
argument_list|()
block|{
return|return
name|m_target_sp
return|;
block|}
name|void
name|SetCommands
argument_list|(
argument|StringList&in_commands
argument_list|)
block|{
name|m_commands
operator|=
name|in_commands
block|; }
comment|// Set the specifier.  The stop hook will own the specifier, and is
comment|// responsible for deleting it when we're done.
name|void
name|SetSpecifier
argument_list|(
name|SymbolContextSpecifier
operator|*
name|specifier
argument_list|)
block|;
name|SymbolContextSpecifier
operator|*
name|GetSpecifier
argument_list|()
block|{
return|return
name|m_specifier_sp
operator|.
name|get
argument_list|()
return|;
block|}
comment|// Set the Thread Specifier.  The stop hook will own the thread specifier,
comment|// and is responsible for deleting it when we're done.
name|void
name|SetThreadSpecifier
argument_list|(
name|ThreadSpec
operator|*
name|specifier
argument_list|)
block|;
name|ThreadSpec
operator|*
name|GetThreadSpecifier
argument_list|()
block|{
return|return
name|m_thread_spec_ap
operator|.
name|get
argument_list|()
return|;
block|}
name|bool
name|IsActive
argument_list|()
block|{
return|return
name|m_active
return|;
block|}
name|void
name|SetIsActive
argument_list|(
argument|bool is_active
argument_list|)
block|{
name|m_active
operator|=
name|is_active
block|; }
name|void
name|GetDescription
argument_list|(
argument|Stream *s
argument_list|,
argument|lldb::DescriptionLevel level
argument_list|)
specifier|const
block|;
name|private
operator|:
name|lldb
operator|::
name|TargetSP
name|m_target_sp
block|;
name|StringList
name|m_commands
block|;
name|lldb
operator|::
name|SymbolContextSpecifierSP
name|m_specifier_sp
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|ThreadSpec
operator|>
name|m_thread_spec_ap
block|;
name|bool
name|m_active
block|;
comment|// Use CreateStopHook to make a new empty stop hook. The GetCommandPointer
comment|// and fill it with commands,
comment|// and SetSpecifier to set the specifier shared pointer (can be null, that
comment|// will match anything.)
name|StopHook
argument_list|(
argument|lldb::TargetSP target_sp
argument_list|,
argument|lldb::user_id_t uid
argument_list|)
block|;
name|friend
name|class
name|Target
block|;   }
decl_stmt|;
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|StopHook
operator|>
name|StopHookSP
expr_stmt|;
comment|// Add an empty stop hook to the Target's stop hook list, and returns a shared
comment|// pointer to it in new_hook.
comment|// Returns the id of the new hook.
name|StopHookSP
name|CreateStopHook
parameter_list|()
function_decl|;
name|void
name|RunStopHooks
parameter_list|()
function_decl|;
name|size_t
name|GetStopHookSize
parameter_list|()
function_decl|;
name|bool
name|SetSuppresStopHooks
parameter_list|(
name|bool
name|suppress
parameter_list|)
block|{
name|bool
name|old_value
init|=
name|m_suppress_stop_hooks
decl_stmt|;
name|m_suppress_stop_hooks
operator|=
name|suppress
expr_stmt|;
return|return
name|old_value
return|;
block|}
name|bool
name|GetSuppressStopHooks
parameter_list|()
block|{
return|return
name|m_suppress_stop_hooks
return|;
block|}
comment|//    StopHookSP&
comment|//    GetStopHookByIndex (size_t index);
comment|//
name|bool
name|RemoveStopHookByID
argument_list|(
name|lldb
operator|::
name|user_id_t
name|uid
argument_list|)
decl_stmt|;
name|void
name|RemoveAllStopHooks
parameter_list|()
function_decl|;
name|StopHookSP
name|GetStopHookByID
argument_list|(
name|lldb
operator|::
name|user_id_t
name|uid
argument_list|)
decl_stmt|;
name|bool
name|SetStopHookActiveStateByID
argument_list|(
name|lldb
operator|::
name|user_id_t
name|uid
argument_list|,
name|bool
name|active_state
argument_list|)
decl_stmt|;
name|void
name|SetAllStopHooksActiveState
parameter_list|(
name|bool
name|active_state
parameter_list|)
function_decl|;
name|size_t
name|GetNumStopHooks
argument_list|()
specifier|const
block|{
return|return
name|m_stop_hooks
operator|.
name|size
argument_list|()
return|;
block|}
name|StopHookSP
name|GetStopHookAtIndex
parameter_list|(
name|size_t
name|index
parameter_list|)
block|{
if|if
condition|(
name|index
operator|>=
name|GetNumStopHooks
argument_list|()
condition|)
return|return
name|StopHookSP
argument_list|()
return|;
name|StopHookCollection
operator|::
name|iterator
name|pos
operator|=
name|m_stop_hooks
operator|.
name|begin
argument_list|()
expr_stmt|;
while|while
condition|(
name|index
operator|>
literal|0
condition|)
block|{
name|pos
operator|++
expr_stmt|;
name|index
operator|--
expr_stmt|;
block|}
return|return
operator|(
operator|*
name|pos
operator|)
operator|.
name|second
return|;
block|}
name|lldb
operator|::
name|PlatformSP
name|GetPlatform
argument_list|()
block|{
return|return
name|m_platform_sp
return|;
block|}
name|void
name|SetPlatform
argument_list|(
specifier|const
name|lldb
operator|::
name|PlatformSP
operator|&
name|platform_sp
argument_list|)
block|{
name|m_platform_sp
operator|=
name|platform_sp
expr_stmt|;
block|}
name|SourceManager
modifier|&
name|GetSourceManager
parameter_list|()
function_decl|;
name|ClangModulesDeclVendor
modifier|*
name|GetClangModulesDeclVendor
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|// Methods.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SearchFilterSP
name|GetSearchFilterForModule
argument_list|(
specifier|const
name|FileSpec
operator|*
name|containingModule
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SearchFilterSP
name|GetSearchFilterForModuleList
argument_list|(
specifier|const
name|FileSpecList
operator|*
name|containingModuleList
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SearchFilterSP
name|GetSearchFilterForModuleAndCUList
argument_list|(
specifier|const
name|FileSpecList
operator|*
name|containingModules
argument_list|,
specifier|const
name|FileSpecList
operator|*
name|containingSourceFiles
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|REPLSP
name|GetREPL
argument_list|(
argument|Status&err
argument_list|,
argument|lldb::LanguageType language
argument_list|,
argument|const char *repl_options
argument_list|,
argument|bool can_create
argument_list|)
expr_stmt|;
name|void
name|SetREPL
argument_list|(
name|lldb
operator|::
name|LanguageType
name|language
argument_list|,
name|lldb
operator|::
name|REPLSP
name|repl_sp
argument_list|)
decl_stmt|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|/// Implementing of ModuleList::Notifier.
comment|//------------------------------------------------------------------
name|void
name|ModuleAdded
argument_list|(
specifier|const
name|ModuleList
operator|&
name|module_list
argument_list|,
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|)
name|override
decl_stmt|;
name|void
name|ModuleRemoved
argument_list|(
specifier|const
name|ModuleList
operator|&
name|module_list
argument_list|,
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|)
name|override
decl_stmt|;
name|void
name|ModuleUpdated
argument_list|(
specifier|const
name|ModuleList
operator|&
name|module_list
argument_list|,
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|old_module_sp
argument_list|,
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|new_module_sp
argument_list|)
name|override
decl_stmt|;
name|void
name|WillClearList
argument_list|(
specifier|const
name|ModuleList
operator|&
name|module_list
argument_list|)
name|override
decl_stmt|;
comment|//------------------------------------------------------------------
comment|// Member variables.
comment|//------------------------------------------------------------------
name|Debugger
modifier|&
name|m_debugger
decl_stmt|;
name|lldb
operator|::
name|PlatformSP
name|m_platform_sp
expr_stmt|;
comment|///< The platform for this target.
name|std
operator|::
name|recursive_mutex
name|m_mutex
expr_stmt|;
comment|///< An API mutex that is used by the lldb::SB*
comment|/// classes make the SB interface thread safe
name|ArchSpec
name|m_arch
decl_stmt|;
name|ModuleList
name|m_images
decl_stmt|;
comment|///< The list of images for this process (shared
comment|/// libraries and anything dynamically loaded).
name|SectionLoadHistory
name|m_section_load_history
decl_stmt|;
name|BreakpointList
name|m_breakpoint_list
decl_stmt|;
name|BreakpointList
name|m_internal_breakpoint_list
decl_stmt|;
name|lldb
operator|::
name|BreakpointSP
name|m_last_created_breakpoint
expr_stmt|;
name|WatchpointList
name|m_watchpoint_list
decl_stmt|;
name|lldb
operator|::
name|WatchpointSP
name|m_last_created_watchpoint
expr_stmt|;
comment|// We want to tightly control the process destruction process so
comment|// we can correctly tear down everything that we need to, so the only
comment|// class that knows about the process lifespan is this target class.
name|lldb
operator|::
name|ProcessSP
name|m_process_sp
expr_stmt|;
name|lldb
operator|::
name|SearchFilterSP
name|m_search_filter_sp
expr_stmt|;
name|PathMappingList
name|m_image_search_paths
decl_stmt|;
name|TypeSystemMap
name|m_scratch_type_system_map
decl_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|lldb
operator|::
name|LanguageType
operator|,
name|lldb
operator|::
name|REPLSP
operator|>
name|REPLMap
expr_stmt|;
name|REPLMap
name|m_repl_map
decl_stmt|;
name|lldb
operator|::
name|ClangASTImporterSP
name|m_ast_importer_sp
expr_stmt|;
name|lldb
operator|::
name|ClangModulesDeclVendorUP
name|m_clang_modules_decl_vendor_ap
expr_stmt|;
name|lldb
operator|::
name|SourceManagerUP
name|m_source_manager_ap
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|lldb
operator|::
name|user_id_t
operator|,
name|StopHookSP
operator|>
name|StopHookCollection
expr_stmt|;
name|StopHookCollection
name|m_stop_hooks
decl_stmt|;
name|lldb
operator|::
name|user_id_t
name|m_stop_hook_next_id
expr_stmt|;
name|bool
name|m_valid
decl_stmt|;
name|bool
name|m_suppress_stop_hooks
decl_stmt|;
name|bool
name|m_is_dummy_target
decl_stmt|;
specifier|static
name|void
name|ImageSearchPathsChanged
parameter_list|(
specifier|const
name|PathMappingList
modifier|&
name|path_list
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
name|private
label|:
comment|//------------------------------------------------------------------
comment|/// Construct with optional file and arch.
comment|///
comment|/// This member is private. Clients must use
comment|/// TargetList::CreateTarget(const FileSpec*, const ArchSpec*)
comment|/// so all targets can be tracked from the central target list.
comment|///
comment|/// @see TargetList::CreateTarget(const FileSpec*, const ArchSpec*)
comment|//------------------------------------------------------------------
name|Target
argument_list|(
argument|Debugger&debugger
argument_list|,
argument|const ArchSpec&target_arch
argument_list|,
argument|const lldb::PlatformSP&platform_sp
argument_list|,
argument|bool is_dummy_target
argument_list|)
empty_stmt|;
comment|// Helper function.
name|bool
name|ProcessIsValid
parameter_list|()
function_decl|;
comment|// Copy breakpoints, stop hooks and so forth from the dummy target:
name|void
name|PrimeFromDummyTarget
parameter_list|(
name|Target
modifier|*
name|dummy_target
parameter_list|)
function_decl|;
name|void
name|AddBreakpoint
argument_list|(
name|lldb
operator|::
name|BreakpointSP
name|breakpoint_sp
argument_list|,
name|bool
name|internal
argument_list|)
decl_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Target
argument_list|)
expr_stmt|;
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
comment|// liblldb_Target_h_
end_comment

end_unit

