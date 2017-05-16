begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- StructuredDataPlugin.h ----------------------------------*- C++ -*-===//
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
name|StructuredDataPlugin_h
end_ifndef

begin_define
define|#
directive|define
name|StructuredDataPlugin_h
end_define

begin_include
include|#
directive|include
file|"lldb/Core/PluginInterface.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/StructuredData.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|CommandObjectMultiword
decl_stmt|;
comment|// -----------------------------------------------------------------------------
comment|/// Plugin that supports process-related structured data sent asynchronously
comment|/// from the debug monitor (e.g. debugserver, lldb-server, etc.)
comment|///
comment|/// This plugin type is activated by a Process-derived instance when that
comment|/// instance detects that a given structured data feature is available.
comment|///
comment|/// StructuredDataPlugin instances are inherently tied to a process.  The
comment|/// main functionality they support is the ability to consume asynchronously-
comment|/// delivered structured data from the process monitor, and do something
comment|/// reasonable with it.  Something reasonable can include broadcasting a
comment|/// StructuredData event, which other parts of the system can then do with
comment|/// as they please.  An IDE could use this facility to retrieve CPU usage,
comment|/// memory usage, and other run-time aspects of the process.  That data
comment|/// can then be displayed meaningfully to the user through the IDE.
comment|/// For command-line LLDB, the Debugger instance listens for the structured
comment|/// data events raised by the plugin, and give the plugin both the output
comment|/// and error streams such that the plugin can display something about the
comment|/// event, at a time when the debugger ensures it is safe to write to the
comment|/// output or error streams.
comment|// -----------------------------------------------------------------------------
name|class
name|StructuredDataPlugin
range|:
name|public
name|PluginInterface
decl_stmt|,
name|public
name|std
decl|::
name|enable_shared_from_this
decl|<
name|StructuredDataPlugin
decl|>
block|{
name|public
label|:
name|virtual
operator|~
name|StructuredDataPlugin
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|ProcessSP
name|GetProcess
argument_list|()
specifier|const
expr_stmt|;
comment|// -------------------------------------------------------------------------
comment|// Public instance API
comment|// -------------------------------------------------------------------------
comment|// -------------------------------------------------------------------------
comment|/// Return whether this plugin supports the given StructuredData feature.
comment|///
comment|/// When Process is informed of a list of process-monitor-supported
comment|/// structured data features, Process will go through the list of plugins,
comment|/// one at a time, and have the first plugin that supports a given feature
comment|/// be the plugin instantiated to handle that feature.  There is a 1-1
comment|/// correspondence between a Process instance and a StructuredDataPlugin
comment|/// mapped to that process.  A plugin can support handling multiple
comment|/// features, and if that happens, there is a single plugin instance
comment|/// created covering all of the mapped features for a given process.
comment|///
comment|/// @param[in] type_name
comment|///     The name of the feature tag supported by a process.
comment|///     e.g. "darwin-log".
comment|///
comment|/// @return
comment|///     true if the plugin supports the feature; otherwise, false.
comment|// -------------------------------------------------------------------------
name|virtual
name|bool
name|SupportsStructuredDataType
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|type_name
parameter_list|)
init|=
literal|0
function_decl|;
comment|// -------------------------------------------------------------------------
comment|/// Handle the arrival of asynchronous structured data from the process.
comment|///
comment|/// When asynchronous structured data arrives from the process monitor,
comment|/// it is immediately delivered to the plugin mapped for that feature
comment|/// if one exists.  The structured data that arrives from a process
comment|/// monitor must be a dictionary, and it must have a string field named
comment|/// "type" that must contain the StructuredData feature name set as the
comment|/// value.  This is the manner in which the data is routed to the proper
comment|/// plugin instance.
comment|///
comment|/// @param[in] process
comment|///     The process instance that just received the structured data.
comment|///     This will always be the same process for a given instance of
comment|///     a plugin.
comment|///
comment|/// @param[in] type_name
comment|///     The name of the feature tag for the asynchronous structured data.
comment|///     Note this data will also be present in the \b object_sp dictionary
comment|///     under the string value with key "type".
comment|///
comment|/// @param[in] object_sp
comment|///     A shared pointer to the structured data that arrived.  This must
comment|///     be a dictionary.  The only key required is the aforementioned
comment|///     key named "type" that must be a string value containing the
comment|///     structured data type name.
comment|// -------------------------------------------------------------------------
name|virtual
name|void
name|HandleArrivalOfStructuredData
argument_list|(
name|Process
operator|&
name|process
argument_list|,
specifier|const
name|ConstString
operator|&
name|type_name
argument_list|,
specifier|const
name|StructuredData
operator|::
name|ObjectSP
operator|&
name|object_sp
argument_list|)
init|=
literal|0
decl_stmt|;
comment|// -------------------------------------------------------------------------
comment|/// Get a human-readable description of the contents of the data.
comment|///
comment|/// In command-line LLDB, this method will be called by the Debugger
comment|/// instance for each structured data event generated, and the output
comment|/// will be printed to the LLDB console.  If nothing is added to the stream,
comment|/// nothing will be printed; otherwise, a newline will be added to the end
comment|/// when displayed.
comment|///
comment|/// @param[in] object_sp
comment|///     A shared pointer to the structured data to format.
comment|///
comment|/// @param[in] stream
comment|///     The stream where the structured data should be pretty printed.
comment|///
comment|/// @return
comment|///     The error if formatting the object contents failed; otherwise,
comment|///     success.
comment|// -------------------------------------------------------------------------
name|virtual
name|Status
name|GetDescription
argument_list|(
specifier|const
name|StructuredData
operator|::
name|ObjectSP
operator|&
name|object_sp
argument_list|,
name|lldb_private
operator|::
name|Stream
operator|&
name|stream
argument_list|)
init|=
literal|0
decl_stmt|;
comment|// -------------------------------------------------------------------------
comment|/// Returns whether the plugin's features are enabled.
comment|///
comment|/// This is a convenience method for plugins that can enable or disable
comment|/// their functionality.  It allows retrieval of this state without
comment|/// requiring a cast.
comment|///
comment|/// @param[in] type_name
comment|///     The name of the feature tag for the asynchronous structured data.
comment|///     This is needed for plugins that support more than one feature.
comment|// -------------------------------------------------------------------------
name|virtual
name|bool
name|GetEnabled
argument_list|(
specifier|const
name|ConstString
operator|&
name|type_name
argument_list|)
decl|const
decl_stmt|;
comment|// -------------------------------------------------------------------------
comment|/// Allow the plugin to do work related to modules that loaded in the
comment|/// the corresponding process.
comment|///
comment|/// This method defaults to doing nothing.  Plugins can override it
comment|/// if they have any behavior they want to enable/modify based on loaded
comment|/// modules.
comment|///
comment|/// @param[in] process
comment|///     The process that just was notified of modules having been loaded.
comment|///     This will always be the same process for a given instance of
comment|///     a plugin.
comment|///
comment|/// @param[in] module_list
comment|///     The list of modules that the process registered as having just
comment|///     loaded.  See \b Process::ModulesDidLoad(...).
comment|// -------------------------------------------------------------------------
name|virtual
name|void
name|ModulesDidLoad
parameter_list|(
name|Process
modifier|&
name|process
parameter_list|,
name|ModuleList
modifier|&
name|module_list
parameter_list|)
function_decl|;
name|protected
label|:
comment|// -------------------------------------------------------------------------
comment|// Derived-class API
comment|// -------------------------------------------------------------------------
name|StructuredDataPlugin
argument_list|(
specifier|const
name|lldb
operator|::
name|ProcessWP
operator|&
name|process_wp
argument_list|)
expr_stmt|;
comment|// -------------------------------------------------------------------------
comment|/// Derived classes must call this before attempting to hook up commands
comment|/// to the 'plugin structured-data' tree.
comment|///
comment|/// This ensures the relevant command and options hook points for all
comment|/// StructuredDataPlugin derived classes are available for this debugger.
comment|/// If this has already happened, this call is a no-op.
comment|///
comment|/// @param[in] debugger
comment|///     The Debugger instance for which we're creating the required shared
comment|///     components for the StructuredDataPlugin derived classes.
comment|// -------------------------------------------------------------------------
specifier|static
name|void
name|InitializeBasePluginForDebugger
parameter_list|(
name|Debugger
modifier|&
name|debugger
parameter_list|)
function_decl|;
name|private
label|:
name|lldb
operator|::
name|ProcessWP
name|m_process_wp
expr_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|StructuredDataPlugin
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

