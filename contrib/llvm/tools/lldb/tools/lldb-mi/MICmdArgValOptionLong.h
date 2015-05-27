begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmdArgValOptionLong.h ---------------------------------*- C++ -*-===//
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
comment|// File:        MICmdArgValOptionLong.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:    CMICmdArgValOptionLong interface.
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
file|"MICmdArgValListBase.h"
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
comment|//          argument and so extract a value from it.
end_comment

begin_comment
comment|//          If *this argument has expected options following it the option objects
end_comment

begin_comment
comment|//          created to hold each of those option's values belong to *this argument
end_comment

begin_comment
comment|//          object and so are deleted when *this object goes out of scope.
end_comment

begin_comment
comment|//          Based on the Interpreter pattern.
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 16/04/2014.
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmdArgValOptionLong
range|:
name|public
name|CMICmdArgValListBase
block|{
comment|// Methods:
name|public
operator|:
comment|/* ctor */
name|CMICmdArgValOptionLong
argument_list|(
name|void
argument_list|)
block|;
comment|/* ctor */
name|CMICmdArgValOptionLong
argument_list|(
argument|const CMIUtilString&vrArgName
argument_list|,
argument|const bool vbMandatory
argument_list|,
argument|const bool vbHandleByCmd
argument_list|)
block|;
comment|/* ctor */
name|CMICmdArgValOptionLong
argument_list|(
argument|const CMIUtilString&vrArgName
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
name|IsArgLongOption
argument_list|(
argument|const CMIUtilString&vrTxt
argument_list|)
specifier|const
block|;
specifier|const
name|VecArgObjPtr_t
operator|&
name|GetExpectedOptions
argument_list|(
argument|void
argument_list|)
specifier|const
block|;
name|template
operator|<
name|class
name|T1
block|,
name|typename
name|T2
operator|>
name|bool
name|GetExpectedOption
argument_list|(
argument|T2&vrwValue
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
name|CMICmdArgValOptionLong
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
name|vArgContext
argument_list|)
block|;
comment|// Methods:
name|protected
operator|:
name|bool
name|ExtractExpectedOptions
argument_list|(
argument|CMICmdArgContext&vrwTxt
argument_list|,
argument|const MIuint nArgIndex
argument_list|)
block|;
comment|// Overrideable:
name|protected
operator|:
name|virtual
name|bool
name|IsArgOptionCorrect
argument_list|(
argument|const CMIUtilString&vrTxt
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|ArgNameMatch
argument_list|(
argument|const CMIUtilString&vrTxt
argument_list|)
specifier|const
block|;
comment|// Methods:
name|private
operator|:
name|void
name|Destroy
argument_list|(
name|void
argument_list|)
block|;
comment|// Attributes:
name|private
operator|:
name|MIuint
name|m_nExpectingNOptions
block|;
comment|// The number of options expected to read following *this argument
name|VecArgObjPtr_t
name|m_vecArgsExpected
block|;
comment|// The option objects holding the value extracted following *this argument
name|ArgValType_e
name|m_eExpectingOptionType
block|;
comment|// The type of options expected to read following *this argument
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++ ------------------------------------------------------------------------------------
end_comment

begin_comment
comment|// Details: Retrieve the first argument or option value from the list of 1 or more options
end_comment

begin_comment
comment|//          parsed from the command's options string.
end_comment

begin_comment
comment|// Type:    Template method.
end_comment

begin_comment
comment|// Args:    vrwValue    - (W) Templated type return value.
end_comment

begin_comment
comment|//          T1          - The argument value's class type of the data hold in the list of options.
end_comment

begin_comment
comment|//          T2          - The type pf the variable which holds the value wanted.
end_comment

begin_comment
comment|// Return:  MIstatus::success - Functional succeeded.
end_comment

begin_comment
comment|//          MIstatus::failure - Functional failed. List of object was empty.
end_comment

begin_comment
comment|// Throws:  None.
end_comment

begin_comment
comment|//--
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T1
operator|,
name|typename
name|T2
operator|>
name|bool
name|CMICmdArgValOptionLong
operator|::
name|GetExpectedOption
argument_list|(
argument|T2&vrwValue
argument_list|)
specifier|const
block|{
specifier|const
name|VecArgObjPtr_t
operator|&
name|rVecOptions
argument_list|(
name|GetExpectedOptions
argument_list|()
argument_list|)
block|;
name|VecArgObjPtr_t
operator|::
name|const_iterator
name|it2
operator|=
name|rVecOptions
operator|.
name|begin
argument_list|()
block|;
if|if
condition|(
name|it2
operator|!=
name|rVecOptions
operator|.
name|end
argument_list|()
condition|)
block|{
specifier|const
name|T1
modifier|*
name|pOption
init|=
name|static_cast
operator|<
name|T1
operator|*
operator|>
operator|(
operator|*
name|it2
operator|)
decl_stmt|;
name|vrwValue
operator|=
name|pOption
operator|->
name|GetValue
argument_list|()
expr_stmt|;
return|return
name|MIstatus
operator|::
name|success
return|;
block|}
end_expr_stmt

begin_return
return|return
name|MIstatus
operator|::
name|failure
return|;
end_return

unit|}
end_unit

