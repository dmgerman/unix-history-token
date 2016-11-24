begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SystemLifetimeManager.h -------------------------------*- C++ -*-===//
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
name|LLDB_INITIALIZATION_SYSTEM_LIFETIME_MANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLDB_INITIALIZATION_SYSTEM_LIFETIME_MANAGER_H
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-private-types.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|SystemInitializer
decl_stmt|;
name|class
name|SystemLifetimeManager
block|{
name|public
label|:
name|SystemLifetimeManager
argument_list|()
expr_stmt|;
operator|~
name|SystemLifetimeManager
argument_list|()
expr_stmt|;
name|void
name|Initialize
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|SystemInitializer
operator|>
name|initializer
argument_list|,
name|LoadPluginCallbackType
name|plugin_callback
argument_list|)
decl_stmt|;
name|void
name|Terminate
parameter_list|()
function_decl|;
name|private
label|:
name|std
operator|::
name|recursive_mutex
name|m_mutex
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|SystemInitializer
operator|>
name|m_initializer
expr_stmt|;
name|bool
name|m_initialized
decl_stmt|;
comment|// Noncopyable.
name|SystemLifetimeManager
argument_list|(
specifier|const
name|SystemLifetimeManager
operator|&
name|other
argument_list|)
operator|=
name|delete
expr_stmt|;
name|SystemLifetimeManager
modifier|&
name|operator
init|=
operator|(
specifier|const
name|SystemLifetimeManager
operator|&
name|other
operator|)
operator|=
name|delete
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

