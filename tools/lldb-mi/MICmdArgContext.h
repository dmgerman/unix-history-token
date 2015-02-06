begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmdArgContext.h ---------------------------------------*- C++ -*-===//
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
comment|// File:        MICmdArgContext.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:    CMICmdArgContext interface.
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
comment|// In-house headers:
end_comment

begin_include
include|#
directive|include
file|"MIUtilString.h"
end_include

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI common code class. Command arguments and options string. Holds
end_comment

begin_comment
comment|//          the context string.
end_comment

begin_comment
comment|//          Based on the Interpreter pattern.
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 14/04/2014.
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdArgContext
block|{
comment|// Methods:
name|public
label|:
comment|/* ctor */
name|CMICmdArgContext
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/* ctor */
name|CMICmdArgContext
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vrCmdLineArgsRaw
argument_list|)
expr_stmt|;
comment|//
specifier|const
name|CMIUtilString
modifier|&
name|GetArgsLeftToParse
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|MIuint
name|GetNumberArgsPresent
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|CMIUtilString
operator|::
name|VecString_t
name|GetArgs
argument_list|(
argument|void
argument_list|)
specifier|const
expr_stmt|;
name|bool
name|IsEmpty
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|bool
name|RemoveArg
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vArg
parameter_list|)
function_decl|;
name|bool
name|RemoveArgAtPos
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vArg
parameter_list|,
specifier|const
name|MIuint
name|nArgIndex
parameter_list|)
function_decl|;
comment|//
name|CMICmdArgContext
modifier|&
name|operator
init|=
operator|(
specifier|const
name|CMICmdArgContext
operator|&
name|vOther
operator|)
decl_stmt|;
comment|// Overridden:
name|public
label|:
comment|// From CMIUtilString
comment|/* dtor */
name|virtual
operator|~
name|CMICmdArgContext
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|// Attributes:
name|private
label|:
name|CMIUtilString
name|m_strCmdArgsAndOptions
decl_stmt|;
specifier|const
name|MIchar
name|m_constCharSpace
decl_stmt|;
specifier|const
name|CMIUtilString
name|m_constStrSpace
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

