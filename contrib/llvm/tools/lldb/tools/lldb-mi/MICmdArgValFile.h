begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmdArgValFile.h ---------------------------------------*- C++ -*-===//
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
comment|//++
end_comment

begin_comment
comment|//============================================================================
end_comment

begin_comment
comment|// Details: MI common code class. Command argument class. Arguments object
end_comment

begin_comment
comment|//          needing specialization derived from the CMICmdArgValBase class.
end_comment

begin_comment
comment|//          An argument knows what type of argument it is and how it is to
end_comment

begin_comment
comment|//          interpret the options (context) string to find and validate a
end_comment

begin_comment
comment|//          matching
end_comment

begin_comment
comment|//          argument and so extract a value from it .
end_comment

begin_comment
comment|//          Based on the Interpreter pattern.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdArgValFile
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
name|CMICmdArgValFile
argument_list|()
block|;
comment|/* ctor */
name|CMICmdArgValFile
argument_list|(
argument|const CMIUtilString&vrArgName
argument_list|,
argument|const bool vbMandatory
argument_list|,
argument|const bool vbHandleByCmd
argument_list|)
block|;
comment|//
name|bool
name|IsFilePath
argument_list|(
argument|const CMIUtilString&vrFileNamePath
argument_list|)
specifier|const
block|;
name|CMIUtilString
name|GetFileNamePath
argument_list|(
argument|const CMIUtilString&vrTxt
argument_list|)
specifier|const
block|;
comment|// Overridden:
name|public
operator|:
comment|// From CMICmdArgValBase
comment|/* dtor */
operator|~
name|CMICmdArgValFile
argument_list|()
name|override
block|;
comment|// From CMICmdArgSet::IArg
name|bool
name|Validate
argument_list|(
argument|CMICmdArgContext&vwArgContext
argument_list|)
name|override
block|;
comment|// Methods:
name|private
operator|:
name|bool
name|IsValidChars
argument_list|(
argument|const CMIUtilString&vrText
argument_list|)
specifier|const
block|; }
decl_stmt|;
end_decl_stmt

end_unit

