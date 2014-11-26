begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmdArgValString.h -------------------------------------*- C++ -*-===//
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
comment|// File:		MICmdArgValString.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:	CMICmdArgValString interface.
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
file|"MICmdArgValBase.h"
end_include

begin_comment
comment|// Declarations:
end_comment

begin_decl_stmt
name|class
name|CMICmdArgContext
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details:	MI common code class. Command argument class. Arguments object
end_comment

begin_comment
comment|//			needing specialization derived from the CMICmdArgValBase class.
end_comment

begin_comment
comment|//			An argument knows what type of argument it is and how it is to
end_comment

begin_comment
comment|//			interpret the options (context) string to find and validate a matching
end_comment

begin_comment
comment|//			argument and so extract a value from it .
end_comment

begin_comment
comment|//			Based on the Interpreter pattern.
end_comment

begin_comment
comment|// Gotchas:	None.
end_comment

begin_comment
comment|// Authors:	Illya Rudkin 15/04/2014.
end_comment

begin_comment
comment|// Changes:	None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdArgValString
range|:
name|public
name|CMICmdArgValBaseTemplate
operator|<
name|CMIUtilString
operator|>
block|{
comment|// Methods:
name|public
operator|:
comment|/* ctor */
name|CMICmdArgValString
argument_list|(
name|void
argument_list|)
block|;
comment|/* ctor */
name|CMICmdArgValString
argument_list|(
argument|const bool vbAnything
argument_list|)
block|;
comment|/* ctor */
name|CMICmdArgValString
argument_list|(
argument|const bool vbHandleQuotes
argument_list|,
argument|const bool vbAcceptNumbers
argument_list|,
argument|const bool vbHandleDirPaths
argument_list|)
block|;
comment|/* ctor */
name|CMICmdArgValString
argument_list|(
argument|const CMIUtilString& vrArgName
argument_list|,
argument|const bool vbMandatory
argument_list|,
argument|const bool vbHandleByCmd
argument_list|,
argument|const bool vbHandleQuotes = false
argument_list|,
argument|const bool vbAcceptNumbers = false
argument_list|)
block|;
comment|//
name|bool
name|IsStringArg
argument_list|(
argument|const CMIUtilString& vrTxt
argument_list|)
specifier|const
block|;
comment|// Overridden:
name|public
operator|:
comment|// From CMICmdArgValBase
comment|/* dtor */
name|virtual
operator|~
name|CMICmdArgValString
argument_list|(
name|void
argument_list|)
block|;
comment|// From CMICmdArgSet::IArg
name|virtual
name|bool
name|Validate
argument_list|(
name|CMICmdArgContext
operator|&
name|vrwArgContext
argument_list|)
block|;
comment|// Methods:
name|private
operator|:
name|bool
name|ValidateSingleText
argument_list|(
name|CMICmdArgContext
operator|&
name|vrwArgContext
argument_list|)
block|;
name|bool
name|ValidateQuotedText
argument_list|(
name|CMICmdArgContext
operator|&
name|vrwArgContext
argument_list|)
block|;
name|bool
name|ValidateQuotedTextEmbedded
argument_list|(
name|CMICmdArgContext
operator|&
name|vrwArgContext
argument_list|)
block|;
name|bool
name|ValidateQuotedQuotedTextEmbedded
argument_list|(
name|CMICmdArgContext
operator|&
name|vrwArgContext
argument_list|)
block|;
name|bool
name|IsStringArgSingleText
argument_list|(
argument|const CMIUtilString& vrTxt
argument_list|)
specifier|const
block|;
name|bool
name|IsStringArgQuotedText
argument_list|(
argument|const CMIUtilString& vrTxt
argument_list|)
specifier|const
block|;
name|bool
name|IsStringArgQuotedTextEmbedded
argument_list|(
argument|const CMIUtilString& vrTxt
argument_list|)
specifier|const
block|;
name|bool
name|IsStringArgQuotedQuotedTextEmbedded
argument_list|(
argument|const CMIUtilString& vrTxt
argument_list|)
specifier|const
block|;
comment|// Attribute:
name|private
operator|:
name|bool
name|m_bHandleQuotedString
block|;
comment|// True = Parse a string surrounded by quotes spaces are not delimitors, false = only text up to next delimiting space character
name|bool
name|m_bAcceptNumbers
block|;
comment|// True = Parse a string and accept as a number if number, false = numbers not recognised as string types
name|bool
name|m_bHandleDirPaths
block|;
comment|// True = Parse a string and accept directory file style string if present, false = directory file path not accepted
name|bool
name|m_bHandleAnything
block|;
comment|// True = Parse a string and accept anything if present, false = validate for criteria matches
block|}
decl_stmt|;
end_decl_stmt

end_unit

