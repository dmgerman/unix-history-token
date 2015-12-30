begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ScriptInterpreterNone.h ---------------------------------*- C++ -*-===//
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
name|liblldb_ScriptInterpreterNone_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ScriptInterpreterNone_h_
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
file|"lldb/Interpreter/ScriptInterpreter.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ScriptInterpreterNone
range|:
name|public
name|ScriptInterpreter
block|{
name|public
operator|:
name|ScriptInterpreterNone
argument_list|(
name|CommandInterpreter
operator|&
name|interpreter
argument_list|)
block|;
operator|~
name|ScriptInterpreterNone
argument_list|()
name|override
block|;
name|bool
name|ExecuteOneLine
argument_list|(
argument|const char *command
argument_list|,
argument|CommandReturnObject *result
argument_list|,
argument|const ExecuteScriptOptions&options = ExecuteScriptOptions()
argument_list|)
name|override
block|;
name|void
name|ExecuteInterpreterLoop
argument_list|()
name|override
block|;
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
name|lldb
operator|::
name|ScriptInterpreterSP
name|CreateInstance
argument_list|(
name|CommandInterpreter
operator|&
name|interpreter
argument_list|)
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
comment|//------------------------------------------------------------------
comment|// PluginInterface protocol
comment|//------------------------------------------------------------------
name|lldb_private
operator|::
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
comment|// liblldb_ScriptInterpreterNone_h_
end_comment

end_unit

