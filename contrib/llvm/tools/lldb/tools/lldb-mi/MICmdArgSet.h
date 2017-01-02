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

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"MICmdArgContext.h"
end_include

begin_include
include|#
directive|include
file|"MICmnBase.h"
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
comment|//++
end_comment

begin_comment
comment|//============================================================================
end_comment

begin_comment
comment|// Details: MI common code class. Command arguments container class.
end_comment

begin_comment
comment|//          A command may have one or more arguments of which some may be
end_comment

begin_comment
comment|//          optional.
end_comment

begin_comment
comment|//          *this class contains a list of the command's arguments which are
end_comment

begin_comment
comment|//          validates against the commands argument options string (context
end_comment

begin_comment
comment|//          string).
end_comment

begin_comment
comment|//          Each argument tries to extract the value it is looking for.
end_comment

begin_comment
comment|//          Argument objects added to *this container are owned by this
end_comment

begin_comment
comment|//          container
end_comment

begin_comment
comment|//          and are deleted when this container goes out of scope. Allocate
end_comment

begin_comment
comment|//          argument
end_comment

begin_comment
comment|//          objects on the heap.
end_comment

begin_comment
comment|//          It is assumed the arguments to be parsed are read from left to right
end_comment

begin_comment
comment|//          in
end_comment

begin_comment
comment|//          order. The order added to *this container is the order they will
end_comment

begin_comment
comment|//          parsed.
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
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|GetIsHandledByCmd
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|GetIsMandatory
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|GetIsMissingOptions
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
specifier|const
name|CMIUtilString
operator|&
name|GetName
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|GetValid
argument_list|()
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
name|virtual
operator|~
name|IArg
argument_list|()
operator|=
expr|default
block|;   }
block|;
comment|// Typedefs:
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
name|CMICmdArgSet
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|Add
parameter_list|(
name|CMICmdArgValBase
modifier|*
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

begin_expr_stmt
specifier|const
name|SetCmdArgs_t
operator|&
name|GetArgsThatAreMissing
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|SetCmdArgs_t
operator|&
name|GetArgsThatInvalid
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|size_t
name|GetCount
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|IsArgContextEmpty
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|IsArgsPresentButNotHandledByCmd
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

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

begin_expr_stmt
operator|~
name|CMICmdArgSet
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Methods:
end_comment

begin_label
name|private
label|:
end_label

begin_expr_stmt
specifier|const
name|SetCmdArgs_t
operator|&
name|GetArgsNotHandledByCmd
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|Destroy
parameter_list|()
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

begin_decl_stmt
name|bool
name|m_bIsArgsPresentButNotHandledByCmd
decl_stmt|;
end_decl_stmt

begin_comment
comment|// True = The driver's client
end_comment

begin_comment
comment|// presented the command with options
end_comment

begin_comment
comment|// recognised but not handled by
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
comment|// The set of arguments that are that the command
end_comment

begin_comment
comment|// is expecting to find in the options string
end_comment

begin_decl_stmt
name|SetCmdArgs_t
name|m_setCmdArgsThatAreMissing
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The set of arguments that are
end_comment

begin_comment
comment|// required by the command but are
end_comment

begin_comment
comment|// missing
end_comment

begin_decl_stmt
name|SetCmdArgs_t
name|m_setCmdArgsThatNotValid
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The set of arguments found in the
end_comment

begin_comment
comment|// text but for some reason unable to
end_comment

begin_comment
comment|// extract a value
end_comment

begin_decl_stmt
name|SetCmdArgs_t
name|m_setCmdArgsNotHandledByCmd
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The set of arguments specified by
end_comment

begin_comment
comment|// the command which were present to
end_comment

begin_comment
comment|// the command but not handled
end_comment

begin_decl_stmt
name|SetCmdArgs_t
name|m_setCmdArgsMissingInfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The set of arguments that were
end_comment

begin_comment
comment|// present but were found to be missing
end_comment

begin_comment
comment|// additional information i.e.
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
comment|// Copy of the command's argument options
end_comment

begin_comment
comment|// text before validate takes place (empties
end_comment

begin_comment
comment|// it of content)
end_comment

begin_decl_stmt
specifier|const
name|CMIUtilString
name|m_constStrCommaSpc
decl_stmt|;
end_decl_stmt

unit|};
end_unit

