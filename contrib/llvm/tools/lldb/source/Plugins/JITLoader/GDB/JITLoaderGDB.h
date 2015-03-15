begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- JITLoaderGDB.h ------------------------------------------*- C++ -*-===//
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
name|liblldb_JITLoaderGDB_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_JITLoaderGDB_h_
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
file|<map>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"lldb/Target/JITLoader.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Process.h"
end_include

begin_decl_stmt
name|class
name|JITLoaderGDB
range|:
name|public
name|lldb_private
operator|::
name|JITLoader
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Static Functions
comment|//------------------------------------------------------------------
specifier|static
name|void
name|Initialize
argument_list|()
block|;
specifier|static
name|void
name|Terminate
argument_list|()
block|;
specifier|static
name|lldb_private
operator|::
name|ConstString
name|GetPluginNameStatic
argument_list|()
block|;
specifier|static
specifier|const
name|char
operator|*
name|GetPluginDescriptionStatic
argument_list|()
block|;
specifier|static
name|lldb
operator|::
name|JITLoaderSP
name|CreateInstance
argument_list|(
argument|lldb_private::Process *process
argument_list|,
argument|bool force
argument_list|)
block|;
name|JITLoaderGDB
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
block|;
name|virtual
operator|~
name|JITLoaderGDB
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|// PluginInterface protocol
comment|//------------------------------------------------------------------
name|virtual
name|lldb_private
operator|::
name|ConstString
name|GetPluginName
argument_list|()
block|;
name|virtual
name|uint32_t
name|GetPluginVersion
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|// JITLoader interface
comment|//------------------------------------------------------------------
name|virtual
name|void
name|DidAttach
argument_list|()
block|;
name|virtual
name|void
name|DidLaunch
argument_list|()
block|;
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
block|;
name|private
operator|:
name|lldb
operator|::
name|addr_t
name|GetSymbolAddress
argument_list|(
argument|lldb_private::ModuleList&module_list
argument_list|,
argument|const lldb_private::ConstString&name
argument_list|,
argument|lldb::SymbolType symbol_type
argument_list|)
specifier|const
block|;
name|void
name|SetJITBreakpoint
argument_list|(
name|lldb_private
operator|::
name|ModuleList
operator|&
name|module_list
argument_list|)
block|;
name|bool
name|DidSetJITBreakpoint
argument_list|()
specifier|const
block|;
name|bool
name|ReadJITDescriptor
argument_list|(
argument|bool all_entries
argument_list|)
block|;
name|template
operator|<
name|typename
name|ptr_t
operator|>
name|bool
name|ReadJITDescriptorImpl
argument_list|(
argument|bool all_entries
argument_list|)
block|;
specifier|static
name|bool
name|JITDebugBreakpointHit
argument_list|(
argument|void *baton
argument_list|,
argument|lldb_private::StoppointCallbackContext *context
argument_list|,
argument|lldb::user_id_t break_id
argument_list|,
argument|lldb::user_id_t break_loc_id
argument_list|)
block|;
specifier|static
name|void
name|ProcessStateChangedCallback
argument_list|(
argument|void *baton
argument_list|,
argument|lldb_private::Process *process
argument_list|,
argument|lldb::StateType state
argument_list|)
block|;
comment|// A collection of in-memory jitted object addresses and their corresponding modules
typedef|typedef
name|std
operator|::
name|map
operator|<
name|lldb
operator|::
name|addr_t
operator|,
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|>
name|JITObjectMap
expr_stmt|;
name|JITObjectMap
name|m_jit_objects
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|user_id_t
name|m_jit_break_id
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|addr_t
name|m_jit_descriptor_addr
expr_stmt|;
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

end_unit

