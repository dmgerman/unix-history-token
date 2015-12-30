begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmdArgValConsume.h ------------------------------------*- C++ -*-===//
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
comment|//++ ============================================================================
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
comment|//          interpret the options (context) string to find and validate a matching
end_comment

begin_comment
comment|//          argument. This type having recognised its argument name just consumes
end_comment

begin_comment
comment|//          that argument or option (ignores it). This is the so the validation
end_comment

begin_comment
comment|//          process can then ask if all arguments or options have been recognised
end_comment

begin_comment
comment|//          other an error will occurred "argument not recognised". For example
end_comment

begin_comment
comment|//          this can be used to consume the "--" text which is not an argument in
end_comment

begin_comment
comment|//          itself. Normally the GetValue() function (in base class) would return
end_comment

begin_comment
comment|//          a value for the argument but is not the case for *this argument type
end_comment

begin_comment
comment|//          object.
end_comment

begin_comment
comment|//          Based on the Interpreter pattern.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdArgValConsume
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
name|CMICmdArgValConsume
argument_list|()
block|;
comment|/* ctor */
name|CMICmdArgValConsume
argument_list|(
argument|const CMIUtilString&vrArgName
argument_list|,
argument|const bool vbMandatory
argument_list|)
block|;
comment|//
name|bool
name|IsOk
argument_list|()
specifier|const
block|;
comment|// Overridden:
name|public
operator|:
comment|// From CMICmdArgValBase
comment|/* dtor */
operator|~
name|CMICmdArgValConsume
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
block|; }
decl_stmt|;
end_decl_stmt

end_unit

