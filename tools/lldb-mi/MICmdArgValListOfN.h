begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmdArgValListOfN.h ------------------------------------*- C++ -*-===//
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
comment|//          argument and so extract a value from it .
end_comment

begin_comment
comment|//          The CMICmdArgValBase objects added to *this ListOfN container belong
end_comment

begin_comment
comment|//          to this container and will be deleted when *this object goes out of
end_comment

begin_comment
comment|//          scope.
end_comment

begin_comment
comment|//          To parse arguments like 'thread-id ...' i.e. 1 10 12 13 ...
end_comment

begin_comment
comment|//          If vbMandatory argument is true it takes on the (...)+ specification
end_comment

begin_comment
comment|//          otherwise assumed to be (...)* specification.
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
name|CMICmdArgValListOfN
range|:
name|public
name|CMICmdArgValListBase
block|{
comment|// Methods:
name|public
operator|:
comment|/* ctor */
name|CMICmdArgValListOfN
argument_list|(
name|void
argument_list|)
block|;
comment|/* ctor */
name|CMICmdArgValListOfN
argument_list|(
argument|const CMIUtilString&vrArgName
argument_list|,
argument|const bool vbMandatory
argument_list|,
argument|const bool vbHandleByCmd
argument_list|,
argument|const ArgValType_e veType
argument_list|)
block|;
comment|//
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
argument_list|,
argument|const VecArgObjPtr_t::size_type vnAt =
literal|0
argument_list|)
specifier|const
block|;
comment|// Overridden:
name|public
operator|:
comment|// From CMICmdArgValBase
comment|/* dtor */
operator|~
name|CMICmdArgValListOfN
argument_list|(
argument|void
argument_list|)
name|override
block|;
comment|// From CMICmdArgSet::IArg
name|bool
name|Validate
argument_list|(
argument|CMICmdArgContext&vArgContext
argument_list|)
name|override
block|;
comment|// Methods:
name|private
operator|:
name|bool
name|IsListOfN
argument_list|(
argument|const CMIUtilString&vrTxt
argument_list|)
specifier|const
block|;
name|bool
name|CreateList
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vrTxt
argument_list|)
block|; }
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
comment|//          vnAt        - (R) Value at the specific position.
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
name|CMICmdArgValListOfN
operator|::
name|GetExpectedOption
argument_list|(
argument|T2&vrwValue
argument_list|,
argument|const VecArgObjPtr_t::size_type vnAt
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
if|if
condition|(
name|rVecOptions
operator|.
name|size
argument_list|()
operator|<=
name|vnAt
condition|)
return|return
name|MIstatus
operator|::
name|failure
return|;
name|VecArgObjPtr_t
operator|::
name|const_iterator
name|it2
operator|=
name|rVecOptions
operator|.
name|begin
argument_list|()
operator|+
name|vnAt
expr_stmt|;
end_expr_stmt

begin_if
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
end_if

begin_return
return|return
name|MIstatus
operator|::
name|failure
return|;
end_return

unit|}
end_unit

