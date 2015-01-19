begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Platform.h ----------------------------------------------*- C++ -*-===//
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
comment|// File:		MICmdArgValBase.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:	CMICmdArgValBase interface.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Environment:	Compilers:	Visual C++ 12.
end_comment

begin_comment
comment|//							gcc (Ubuntu/Linaro 4.8.1-10ubuntu9) 4.8.1
end_comment

begin_comment
comment|//				Libraries:	See MIReadmetxt.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Copyright:	None.
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

begin_include
include|#
directive|include
file|"MICmdArgSet.h"
end_include

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details:	MI common code class. Command argument base class. Arguments objects
end_comment

begin_comment
comment|//			needing specialization derived from *this class. An argument knows
end_comment

begin_comment
comment|//			what type of argument it is and how it is to interpret the options
end_comment

begin_comment
comment|//			(context) string to find and validate a matching argument and so
end_comment

begin_comment
comment|//			extract a value from it.
end_comment

begin_comment
comment|//			Argument objects are added to the CMICmdArgSet container object.
end_comment

begin_comment
comment|//			Once added the container they belong to that contain and will be
end_comment

begin_comment
comment|//			deleted when the container goes out of scope. Allocate argument
end_comment

begin_comment
comment|//			objects on the heap and pass in to the Add().
end_comment

begin_comment
comment|//			Note the code is written such that a command will produce an error
end_comment

begin_comment
comment|//			should it be presented with arguments or options it does not understand.
end_comment

begin_comment
comment|//			A command can recognise an option or argument then ignore if it
end_comment

begin_comment
comment|//			wishes (a warning is sent to the MI's Log file). This is so it is
end_comment

begin_comment
comment|//			hardwired to fail and catch arguments or options that presented by
end_comment

begin_comment
comment|//			different driver clients.
end_comment

begin_comment
comment|//			Based on the Interpreter pattern.
end_comment

begin_comment
comment|// Gotchas:	None.
end_comment

begin_comment
comment|// Authors:	Illya Rudkin 14/04/2014.
end_comment

begin_comment
comment|// Changes:	None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdArgValBase
range|:
name|public
name|CMICmdArgSet
operator|::
name|IArg
block|{
comment|// Methods:
name|public
operator|:
comment|/* ctor */
name|CMICmdArgValBase
argument_list|(
name|void
argument_list|)
block|;
comment|/* ctor */
name|CMICmdArgValBase
argument_list|(
argument|const CMIUtilString& vrArgName
argument_list|,
argument|const bool vbMandatory
argument_list|,
argument|const bool vbHandleByCmd
argument_list|)
block|;
comment|// Overrideable:
name|public
operator|:
comment|/* dtor */
name|virtual
operator|~
name|CMICmdArgValBase
argument_list|(
name|void
argument_list|)
block|;
comment|// Overridden:
name|public
operator|:
comment|// From CMICmdArgSet::IArg
name|virtual
name|bool
name|GetFound
argument_list|(
argument|void
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|GetIsHandledByCmd
argument_list|(
argument|void
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|GetIsMandatory
argument_list|(
argument|void
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|GetIsMissingOptions
argument_list|(
argument|void
argument_list|)
specifier|const
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
block|;
name|virtual
name|bool
name|GetValid
argument_list|(
argument|void
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|Validate
argument_list|(
name|CMICmdArgContext
operator|&
name|vwArgContext
argument_list|)
block|;
comment|// Attributes:
name|protected
operator|:
name|bool
name|m_bFound
block|;
comment|// True = yes found in arguments options text, false = not found
name|bool
name|m_bValid
block|;
comment|// True = yes argument parsed and valid, false = not valid
name|bool
name|m_bMandatory
block|;
comment|// True = yes arg must be present, false = optional argument
name|CMIUtilString
name|m_strArgName
block|;
name|bool
name|m_bHandled
block|;
comment|// True = Command processes *this option, false = not handled
name|bool
name|m_bIsMissingOptions
block|;
comment|// True = Command needs more information, false = ok
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details:	MI common code class. Templated command argument base class.
end_comment

begin_comment
comment|// Gotchas:	None.
end_comment

begin_comment
comment|// Authors:	Illya Rudkin 14/04/2014.
end_comment

begin_comment
comment|// Changes:	None.
end_comment

begin_comment
comment|//--
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|CMICmdArgValBaseTemplate
operator|:
name|public
name|CMICmdArgValBase
block|{
comment|// Methods:
name|public
operator|:
comment|/* ctor */
name|CMICmdArgValBaseTemplate
argument_list|(
name|void
argument_list|)
block|;
comment|/* ctor */
name|CMICmdArgValBaseTemplate
argument_list|(
argument|const CMIUtilString& vrArgName
argument_list|,
argument|const bool vbMandatory
argument_list|,
argument|const bool vbHandleByCmd
argument_list|)
block|;
comment|//
specifier|const
name|T
operator|&
name|GetValue
argument_list|(
argument|void
argument_list|)
specifier|const
block|;
comment|// Overrideable:
name|public
operator|:
comment|/* dtor */
name|virtual
operator|~
name|CMICmdArgValBaseTemplate
argument_list|(
name|void
argument_list|)
block|;
comment|// Attributes:
name|protected
operator|:
name|T
name|m_argValue
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
comment|//++ ------------------------------------------------------------------------------------
end_comment

begin_comment
comment|// Details:	CMICmdArgValBaseTemplate constructor.
end_comment

begin_comment
comment|// Type:	Method.
end_comment

begin_comment
comment|// Args:	None.
end_comment

begin_comment
comment|// Return:	None.
end_comment

begin_comment
comment|// Throws:	None.
end_comment

begin_comment
comment|//--
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|CMICmdArgValBaseTemplate
operator|<
name|T
operator|>
operator|::
name|CMICmdArgValBaseTemplate
argument_list|(
argument|void
argument_list|)
block|{ }
comment|//++ ------------------------------------------------------------------------------------
comment|// Details:	CMICmdArgValBaseTemplate constructor.
comment|// Type:	Method.
comment|// Args:	vrArgName		- (R) Argument's name to search by.
comment|//			vbMandatory		- (R) True = Yes must be present, false = optional argument.
comment|//			vbHandleByCmd	- (R) True = Command processes *this option, false = not handled.
comment|// Return:	None.
comment|// Throws:	None.
comment|//--
name|template
operator|<
name|class
name|T
operator|>
name|CMICmdArgValBaseTemplate
operator|<
name|T
operator|>
operator|::
name|CMICmdArgValBaseTemplate
argument_list|(
argument|const CMIUtilString& vrArgName
argument_list|,
argument|const bool vbMandatory
argument_list|,
argument|const bool vbHandleByCmd
argument_list|)
operator|:
name|CMICmdArgValBase
argument_list|(
argument|vrArgName
argument_list|,
argument|vbMandatory
argument_list|,
argument|vbHandleByCmd
argument_list|)
block|{ }
comment|//++ ------------------------------------------------------------------------------------
comment|// Details:	CMICmdArgValBaseTemplate destructor.
comment|// Type:	Overrideable.
comment|// Args:	None.
comment|// Return:	None.
comment|// Throws:	None.
comment|//--
name|template
operator|<
name|class
name|T
operator|>
name|CMICmdArgValBaseTemplate
operator|<
name|T
operator|>
operator|::
operator|~
name|CMICmdArgValBaseTemplate
argument_list|(
argument|void
argument_list|)
block|{ }
comment|//++ ------------------------------------------------------------------------------------
comment|// Details:	Retrieve the value the argument parsed from the command's argument / options
comment|//			text string.
comment|// Type:	Method.
comment|// Args:	None.
comment|// Return:	Template type&	- The arg value of *this object.
comment|// Throws:	None.
comment|//--
name|template
operator|<
name|class
name|T
operator|>
specifier|const
name|T
operator|&
name|CMICmdArgValBaseTemplate
operator|<
name|T
operator|>
operator|::
name|GetValue
argument_list|(
argument|void
argument_list|)
specifier|const
block|{
return|return
name|m_argValue
return|;
block|}
end_expr_stmt

end_unit

