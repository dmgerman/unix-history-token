begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmdMgrSetCmdDeleteCallback.h --------------------------*- C++ -*-===//
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
comment|//--
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_comment
comment|// Third party headers:
end_comment

begin_include
include|#
directive|include
file|<set>
end_include

begin_comment
comment|// In-house headers:
end_comment

begin_include
include|#
directive|include
file|"MICmnBase.h"
end_include

begin_comment
comment|// Declarations:
end_comment

begin_struct_decl
struct_decl|struct
name|SMICmdData
struct_decl|;
end_struct_decl

begin_decl_stmt
name|namespace
name|CMICmdMgrSetCmdDeleteCallback
block|{
comment|//++
comment|//============================================================================
comment|// Details: MI Command Manager interface for client call back.
comment|//          Objects that want to be notified of a command being deleted
comment|//          inherit this interface and register interest in command object
comment|//          deletion. An object deleting a command must not do it itself but
comment|//          call
comment|//          the Command Manager CmdDelete() function to delete a command object.
comment|//--
name|class
name|ICallback
block|{
name|public
label|:
name|virtual
name|void
name|Delete
parameter_list|(
name|SMICmdData
modifier|&
name|vCmd
parameter_list|)
init|=
literal|0
function_decl|;
comment|/* dtor */
name|virtual
operator|~
name|ICallback
argument_list|()
block|{}
block|}
empty_stmt|;
comment|//++
comment|//============================================================================
comment|// Details: MI Command Manager container for clients registered interest in
comment|// command
comment|//          objects being deleted. Objects register an interest so when a
comment|//          command
comment|//          is to be deleted that object wanting the delete calls the Command
comment|//          Manager to delete the command object. In so do all other registered
comment|//          objects get called to about the deletion including the object
comment|//          wanting
comment|//          to do the delete in the first place.
comment|//--
name|class
name|CSetClients
range|:
name|public
name|std
operator|::
name|set
operator|<
name|class
name|ICallback
operator|*
operator|>
decl_stmt|,
name|public
name|CMICmnBase
block|{
comment|// Methods:
name|public
label|:
comment|/* ctor */
name|CSetClients
argument_list|()
expr_stmt|;
name|bool
name|Register
parameter_list|(
name|class
name|ICallback
modifier|&
name|vObject
parameter_list|)
function_decl|;
name|bool
name|Unregister
parameter_list|(
name|class
name|ICallback
modifier|&
name|vObject
parameter_list|)
function_decl|;
name|void
name|Delete
parameter_list|(
name|SMICmdData
modifier|&
name|vCmdData
parameter_list|)
function_decl|;
comment|// Overridden:
name|public
label|:
comment|// From CMICmnBase
comment|/* dtor */
operator|~
name|CSetClients
argument_list|()
name|override
expr_stmt|;
comment|// Attributes:
name|private
label|:
name|bool
name|m_bClientUnregistered
decl_stmt|;
comment|// True = yes while deleting a client
comment|// unregistered, false = no client unregistered
comment|// during deletion
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace CMICmdMgrSetCmdDeleteCallback
end_comment

end_unit

