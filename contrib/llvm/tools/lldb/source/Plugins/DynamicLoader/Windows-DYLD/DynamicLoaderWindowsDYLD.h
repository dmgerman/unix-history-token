begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DynamicLoaderWindowsDYLD.h ------------------------------*- C++ -*-===//
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
name|liblldb_Plugins_Process_Windows_DynamicLoaderWindowsDYLD_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Plugins_Process_Windows_DynamicLoaderWindowsDYLD_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Target/DynamicLoader.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|DynamicLoaderWindowsDYLD
range|:
name|public
name|DynamicLoader
block|{
name|public
operator|:
name|DynamicLoaderWindowsDYLD
argument_list|(
name|Process
operator|*
name|process
argument_list|)
block|;
operator|~
name|DynamicLoaderWindowsDYLD
argument_list|()
name|override
block|;
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
name|DynamicLoader
operator|*
name|CreateInstance
argument_list|(
argument|Process *process
argument_list|,
argument|bool force
argument_list|)
block|;
name|void
name|DidAttach
argument_list|()
name|override
block|;
name|void
name|DidLaunch
argument_list|()
name|override
block|;
name|Status
name|CanLoadImage
argument_list|()
name|override
block|;
name|lldb
operator|::
name|ThreadPlanSP
name|GetStepThroughTrampolinePlan
argument_list|(
argument|Thread&thread
argument_list|,
argument|bool stop
argument_list|)
name|override
block|;
name|ConstString
name|GetPluginName
argument_list|()
name|override
block|;
name|uint32_t
name|GetPluginVersion
argument_list|()
name|override
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
comment|// liblldb_Plugins_Process_Windows_DynamicLoaderWindowsDYLD_h_
end_comment

end_unit

