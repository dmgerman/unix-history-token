begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmdArgValOptionShort.h --------------------------------*- C++ -*-===//
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
comment|// File:		MICmdArgValOptionShort.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:	CMICmdArgValOptionShort interface.
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
file|"MICmdArgValOptionLong.h"
end_include

begin_comment
comment|// Declarations:
end_comment

begin_decl_stmt
name|class
name|CMICmdArgContext
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|CMIUtilString
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details:	MI common code class. Command argument class. Arguments object
end_comment

begin_comment
comment|//			needing specialization derived from the CMICmdArgValOptionLong class.
end_comment

begin_comment
comment|//			An argument knows what type of argument it is and how it is to
end_comment

begin_comment
comment|//			interpret the options (context) string to find and validate a matching
end_comment

begin_comment
comment|//			argument and so extract a value from it.
end_comment

begin_comment
comment|//			If *this argument has expected options following it the option objects
end_comment

begin_comment
comment|//			created to hold each of those option's values belong to *this argument
end_comment

begin_comment
comment|//			object and so are deleted when *this object goes out of scope.
end_comment

begin_comment
comment|//			Based on the Interpreter pattern.
end_comment

begin_comment
comment|// Gotchas:	None.
end_comment

begin_comment
comment|// Authors:	Illya Rudkin 16/04/2014.
end_comment

begin_comment
comment|// Changes:	None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdArgValOptionShort
range|:
name|public
name|CMICmdArgValOptionLong
block|{
comment|// Methods:
name|public
operator|:
comment|/* ctor */
name|CMICmdArgValOptionShort
argument_list|(
name|void
argument_list|)
block|;
comment|/* ctor */
name|CMICmdArgValOptionShort
argument_list|(
argument|const CMIUtilString& vrArgName
argument_list|,
argument|const bool vbMandatory
argument_list|,
argument|const bool vbHandleByCmd
argument_list|)
block|;
comment|/* ctor */
name|CMICmdArgValOptionShort
argument_list|(
argument|const CMIUtilString& vrArgName
argument_list|,
argument|const bool vbMandatory
argument_list|,
argument|const bool vbHandleByCmd
argument_list|,
argument|const ArgValType_e veType
argument_list|,
argument|const MIuint vnExpectingNOptions
argument_list|)
block|;
comment|//
name|bool
name|IsArgShortOption
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
name|CMICmdArgValOptionShort
argument_list|(
name|void
argument_list|)
block|;
comment|// Overridden:
name|private
operator|:
comment|// From CMICmdArgValOptionLong
name|virtual
name|bool
name|IsArgOptionCorrect
argument_list|(
argument|const CMIUtilString& vrTxt
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|ArgNameMatch
argument_list|(
argument|const CMIUtilString& vrTxt
argument_list|)
specifier|const
block|; }
decl_stmt|;
end_decl_stmt

end_unit

