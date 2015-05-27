begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmdArgSet.h -------------------------------------------*- C++ -*-===//
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
comment|// File:        MICmdArgSet.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:    CMICmdArgSet interface.
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
comment|// Third party headers:
end_comment

begin_include
include|#
directive|include
file|<vector>
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
file|"MICmdArgContext.h"
end_include

begin_comment
comment|// Declarations:
end_comment

begin_decl_stmt
name|class
name|CMICmdArgValBase
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI common code class. Command arguments container class.
end_comment

begin_comment
comment|//          A command may have one or more arguments of which some may be optional.
end_comment

begin_comment
comment|//          *this class contains a list of the command's arguments which are
end_comment

begin_comment
comment|//          validates against the commands argument options string (context string).
end_comment

begin_comment
comment|//          Each argument tries to extract the value it is looking for.
end_comment

begin_comment
comment|//          Argument objects added to *this container are owned by this container
end_comment

begin_comment
comment|//          and are deleted when this container goes out of scope. Allocate argument
end_comment

begin_comment
comment|//          objects on the heap.
end_comment

begin_comment
comment|//          It is assummed the arguments to be parsed are read from left to right in
end_comment

begin_comment
comment|//          order. The order added to *this container is the order they will parsed.
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
name|CMICmdArgSet
range|:
name|public
name|CMICmnBase
block|{
comment|// Classes:
name|public
operator|:
comment|//++
comment|// Description: ArgSet's interface for command arguments to implement.
comment|//--
name|class
name|IArg
block|{
name|public
operator|:
name|virtual
name|bool
name|GetFound
argument_list|(
argument|void
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|GetIsHandledByCmd
argument_list|(
argument|void
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|GetIsMandatory
argument_list|(
argument|void
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|GetIsMissingOptions
argument_list|(
argument|void
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
specifier|const
name|CMIUtilString
operator|&
name|GetName
argument_list|(
argument|void
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|GetValid
argument_list|(
argument|void
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|Validate
argument_list|(
name|CMICmdArgContext
operator|&
name|vwArgContext
argument_list|)
operator|=
literal|0
block|;
comment|/* dtor */
name|virtual
operator|~
name|IArg
argument_list|(
argument|void
argument_list|)
block|{}
block|;     }
block|;
comment|// Typedefs:
name|public
operator|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|CMICmdArgValBase
operator|*
operator|>
name|SetCmdArgs_t
expr_stmt|;
comment|// Methods:
name|public
operator|:
comment|/* ctor */
name|CMICmdArgSet
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|Add
parameter_list|(
specifier|const
name|CMICmdArgValBase
modifier|&
name|vArg
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|bool
name|GetArg
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vArgName
argument_list|,
name|CMICmdArgValBase
operator|*
operator|&
name|vpArg
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|SetCmdArgs_t
modifier|&
name|GetArgsThatAreMissing
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|SetCmdArgs_t
modifier|&
name|GetArgsThatInvalid
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MIuint
name|GetCount
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|IsArgContextEmpty
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|IsArgsPresentButNotHandledByCmd
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|WarningArgsNotHandledbyCmdLogFile
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vrCmdName
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|Validate
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vStrMiCmd
parameter_list|,
name|CMICmdArgContext
modifier|&
name|vwCmdArgsText
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Overrideable:
end_comment

begin_label
name|public
label|:
end_label

begin_comment
comment|/* dtor */
end_comment

begin_expr_stmt
name|virtual
operator|~
name|CMICmdArgSet
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Methods:
end_comment

begin_label
name|private
label|:
end_label

begin_decl_stmt
specifier|const
name|SetCmdArgs_t
modifier|&
name|GetArgsNotHandledByCmd
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|Destroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Release resources used by *this object
end_comment

begin_function_decl
name|bool
name|ValidationFormErrorMessages
parameter_list|(
specifier|const
name|CMICmdArgContext
modifier|&
name|vwCmdArgsText
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Attributes:
end_comment

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|bool
name|m_bIsArgsPresentButNotHandledByCmd
decl_stmt|;
end_decl_stmt

begin_comment
comment|// True = The driver's client presented the command with options recognised but not handled by
end_comment

begin_comment
comment|// a command, false = all args handled
end_comment

begin_decl_stmt
name|SetCmdArgs_t
name|m_setCmdArgs
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The set of arguments that are that the command is expecting to find in the options string
end_comment

begin_decl_stmt
name|SetCmdArgs_t
name|m_setCmdArgsThatAreMissing
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The set of arguments that are required by the command but are missing
end_comment

begin_decl_stmt
name|SetCmdArgs_t
name|m_setCmdArgsThatNotValid
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The set of arguments found in the text but for some reason unable to extract a value
end_comment

begin_decl_stmt
name|SetCmdArgs_t
name|m_setCmdArgsNotHandledByCmd
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The set of arguments specified by the command which were present to the command but not handled
end_comment

begin_decl_stmt
name|SetCmdArgs_t
name|m_setCmdArgsMissingInfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The set of arguments that were present but were found to be missing additional information i.e.
end_comment

begin_comment
comment|// --thread 3 but 3 is missing
end_comment

begin_decl_stmt
name|CMICmdArgContext
name|m_cmdArgContext
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Copy of the command's argument options text before validate takes place (empties it of content)
end_comment

begin_decl_stmt
specifier|const
name|CMIUtilString
name|m_constStrCommaSpc
decl_stmt|;
end_decl_stmt

unit|};
end_unit

