begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmdFactory.h ------------------------------------------*- C++ -*-===//
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
comment|//++
end_comment

begin_comment
comment|// File:        MICmdFactory.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:    CMICmdFactory interface.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Environment: Compilers:  Visual C++ 12.
end_comment

begin_comment
comment|//                          gcc (Ubuntu/Linaro 4.8.1-10ubuntu9) 4.8.1
end_comment

begin_comment
comment|//              Libraries:  See MIReadmetxt.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Copyright:   None.
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
comment|// Third party headers
end_comment

begin_include
include|#
directive|include
file|<map>
end_include

begin_comment
comment|// In-house headers:
end_comment

begin_include
include|#
directive|include
file|"MICmnBase.h"
end_include

begin_include
include|#
directive|include
file|"MIUtilSingletonBase.h"
end_include

begin_comment
comment|// Declarations:
end_comment

begin_decl_stmt
name|class
name|CMICmdBase
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|SMICmdData
struct_decl|;
end_struct_decl

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI Command Factory. Holds a list of registered MI commands that
end_comment

begin_comment
comment|//          MI application understands to interpret. Creates commands objects.
end_comment

begin_comment
comment|//          The Command Factory is carried out in the main thread.
end_comment

begin_comment
comment|//          A singleton class.
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 19/02/2014.
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdFactory
range|:
name|public
name|CMICmnBase
decl_stmt|,
name|public
name|MI
decl|::
name|ISingleton
decl|<
name|CMICmdFactory
decl|>
block|{
name|friend
name|class
name|MI
operator|::
name|ISingleton
operator|<
name|CMICmdFactory
operator|>
expr_stmt|;
comment|// Typedefs:
name|public
label|:
typedef|typedef
name|CMICmdBase
modifier|*
function_decl|(
modifier|*
name|CmdCreatorFnPtr
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// Class:
name|public
label|:
comment|//++
comment|// Description: Command's factory's interface for commands to implement.
comment|//--
name|class
name|ICmd
block|{
name|public
label|:
name|virtual
specifier|const
name|CMIUtilString
modifier|&
name|GetMiCmd
argument_list|(
name|void
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|CmdCreatorFnPtr
name|GetCmdCreatorFn
argument_list|(
name|void
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|// virtual CMICmdBase *         CreateSelf( void ) = 0;             // Not possible as require a static creator
comment|// function in the command class, here for awareness
comment|/* dtor */
name|virtual
operator|~
name|ICmd
argument_list|(
argument|void
argument_list|)
block|{}
expr_stmt|;
block|}
empty_stmt|;
comment|// Methods:
name|public
label|:
name|bool
name|Initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|bool
name|Shutdown
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|bool
name|CmdRegister
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vMiCmd
parameter_list|,
name|CmdCreatorFnPtr
name|vCmdCreateFn
parameter_list|)
function_decl|;
name|bool
name|CmdCreate
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vMiCmd
parameter_list|,
specifier|const
name|SMICmdData
modifier|&
name|vCmdData
parameter_list|,
name|CMICmdBase
modifier|*
modifier|&
name|vpNewCmd
parameter_list|)
function_decl|;
name|bool
name|CmdExist
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vMiCmd
argument_list|)
decl|const
decl_stmt|;
comment|// Methods:
name|private
label|:
comment|/* ctor */
name|CMICmdFactory
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/* ctor */
name|CMICmdFactory
argument_list|(
specifier|const
name|CMICmdFactory
operator|&
argument_list|)
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|CMICmdFactory
operator|&
operator|)
decl_stmt|;
name|bool
name|HaveAlready
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vMiCmd
argument_list|)
decl|const
decl_stmt|;
name|bool
name|IsValid
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vMiCmd
argument_list|)
decl|const
decl_stmt|;
comment|// Overridden:
name|private
label|:
comment|// From CMICmnBase
comment|/* dtor */
name|virtual
operator|~
name|CMICmdFactory
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|// Typedefs:
name|private
label|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|CMIUtilString
operator|,
name|CmdCreatorFnPtr
operator|>
name|MapMiCmdToCmdCreatorFn_t
expr_stmt|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|CMIUtilString
operator|,
name|CmdCreatorFnPtr
operator|>
name|MapPairMiCmdToCmdCreatorFn_t
expr_stmt|;
comment|// Attributes:
name|private
label|:
name|MapMiCmdToCmdCreatorFn_t
name|m_mapMiCmdToCmdCreatorFn
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

