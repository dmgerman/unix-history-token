begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- JITLoader.h ---------------------------------------------*- C++ -*-===//
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
name|liblldb_JITLoader_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_JITLoader_h_
end_define

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"lldb/Core/PluginInterface.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/JITLoaderList.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class JITLoader JITLoader.h "lldb/Target/JITLoader.h"
comment|/// @brief A plug-in interface definition class for JIT loaders.
comment|///
comment|/// Plugins of this kind listen for code generated at runtime in the
comment|/// target. They are very similar to dynamic loader, with the difference
comment|/// that they do not have information about the target's dyld and
comment|/// that there may be multiple JITLoader plugins per process, while
comment|/// there is at most one DynamicLoader.
comment|//----------------------------------------------------------------------
name|class
name|JITLoader
range|:
name|public
name|PluginInterface
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|/// Find a JIT loader plugin for a given process.
comment|///
comment|/// Scans the installed DynamicLoader plug-ins and tries to find
comment|/// all applicable instances for the current process.
comment|///
comment|/// @param[in] process
comment|///     The process for which to try and locate a JIT loader
comment|///     plug-in instance.
comment|///
comment|//------------------------------------------------------------------
specifier|static
name|void
name|LoadPlugins
argument_list|(
name|Process
operator|*
name|process
argument_list|,
name|lldb_private
operator|::
name|JITLoaderList
operator|&
name|list
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Construct with a process.
comment|//------------------------------------------------------------------
name|JITLoader
argument_list|(
name|Process
operator|*
name|process
argument_list|)
block|;
name|virtual
operator|~
name|JITLoader
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Called after attaching a process.
comment|///
comment|/// Allow JITLoader plug-ins to execute some code after
comment|/// attaching to a process.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|DidAttach
argument_list|()
operator|=
literal|0
block|;
comment|//------------------------------------------------------------------
comment|/// Called after launching a process.
comment|///
comment|/// Allow JITLoader plug-ins to execute some code after
comment|/// the process has stopped for the first time on launch.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|DidLaunch
argument_list|()
operator|=
literal|0
block|;
comment|//------------------------------------------------------------------
comment|/// Called after a new shared object has been loaded so that it can
comment|/// be probed for JIT entry point hooks.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|ModulesDidLoad
argument_list|(
name|lldb_private
operator|::
name|ModuleList
operator|&
name|module_list
argument_list|)
operator|=
literal|0
block|;
name|protected
operator|:
comment|//------------------------------------------------------------------
comment|// Member variables.
comment|//------------------------------------------------------------------
name|Process
operator|*
name|m_process
block|; }
decl_stmt|;
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
comment|// liblldb_JITLoader_h_
end_comment

end_unit

