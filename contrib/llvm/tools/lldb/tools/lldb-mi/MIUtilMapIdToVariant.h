begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MIUtilMapIdToVariant.h ----------------------------------*- C++ -*-===//
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
comment|// File:        MIUtilMapIdToVariant.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:    CMIUtilMapIdToVariant interface.
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
file|<map>
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
file|"MICmnResources.h"
end_include

begin_include
include|#
directive|include
file|"MIUtilString.h"
end_include

begin_include
include|#
directive|include
file|"MIUtilVariant.h"
end_include

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI common code utility class. Map type container that hold general
end_comment

begin_comment
comment|//          object types (by being wrappin an variant wrapper)
end_comment

begin_comment
comment|//          objects by ID.
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 19/06/2014.
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMIUtilMapIdToVariant
range|:
name|public
name|CMICmnBase
block|{
comment|// Methods:
name|public
operator|:
comment|/* ctor */
name|CMIUtilMapIdToVariant
argument_list|(
name|void
argument_list|)
block|;
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|Add
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vId
argument_list|,
specifier|const
name|T
operator|&
name|vData
argument_list|)
block|;
name|void
name|Clear
argument_list|(
name|void
argument_list|)
block|;
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|Get
argument_list|(
argument|const CMIUtilString&vId
argument_list|,
argument|T&vrwData
argument_list|,
argument|bool&vrwbFound
argument_list|)
specifier|const
block|;
name|bool
name|HaveAlready
argument_list|(
argument|const CMIUtilString&vId
argument_list|)
specifier|const
block|;
name|bool
name|IsEmpty
argument_list|(
argument|void
argument_list|)
specifier|const
block|;
name|bool
name|Remove
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vId
argument_list|)
block|;
comment|// Overridden:
name|public
operator|:
comment|// From CMICmnBase
comment|/* dtor */
name|virtual
operator|~
name|CMIUtilMapIdToVariant
argument_list|(
name|void
argument_list|)
block|;
comment|// Typdefs:
name|private
operator|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|CMIUtilString
operator|,
name|CMIUtilVariant
operator|>
name|MapKeyToVariantValue_t
expr_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|CMIUtilString
operator|,
name|CMIUtilVariant
operator|>
name|MapPairKeyToVariantValue_t
expr_stmt|;
end_typedef

begin_comment
comment|// Methods:
end_comment

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|bool
name|IsValid
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vId
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Attributes:
end_comment

begin_decl_stmt
name|MapKeyToVariantValue_t
name|m_mapKeyToVariantValue
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|//++ ------------------------------------------------------------------------------------
end_comment

begin_comment
comment|// Details: Add to *this container a data object of general type identified by an ID.
end_comment

begin_comment
comment|//          If the data with that ID already exists in the container it is replace with
end_comment

begin_comment
comment|//          the new data specified.
end_comment

begin_comment
comment|// Type:    Method.
end_comment

begin_comment
comment|// Args:    T       - The data object's variable type.
end_comment

begin_comment
comment|//          vId     - (R) Unique ID i.e. GUID.
end_comment

begin_comment
comment|//          vData   - (R) The general data object to be stored of some type.
end_comment

begin_comment
comment|// Return:  MIstatus::success - Functional succeeded.
end_comment

begin_comment
comment|//          MIstatus::failure - Functional failed.
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
name|typename
name|T
operator|>
name|bool
name|CMIUtilMapIdToVariant
operator|::
name|Add
argument_list|(
argument|const CMIUtilString&vId
argument_list|,
argument|const T&vData
argument_list|)
block|{
if|if
condition|(
operator|!
name|IsValid
argument_list|(
name|vId
argument_list|)
condition|)
block|{
name|SetErrorDescription
argument_list|(
name|CMIUtilString
operator|::
name|Format
argument_list|(
name|MIRSRC
argument_list|(
name|IDS_VARIANT_ERR_MAP_KEY_INVALID
argument_list|)
argument_list|,
name|vId
operator|.
name|c_str
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|MIstatus
operator|::
name|failure
return|;
block|}
specifier|const
name|bool
name|bOk
operator|=
name|HaveAlready
argument_list|(
name|vId
argument_list|)
condition|?
name|Remove
argument_list|(
name|vId
argument_list|)
else|:
name|MIstatus
operator|::
name|success
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|bOk
condition|)
block|{
name|CMIUtilVariant
name|data
decl_stmt|;
name|data
operator|.
name|Set
operator|<
name|T
operator|>
operator|(
name|vData
operator|)
expr_stmt|;
name|MapPairKeyToVariantValue_t
name|pr
parameter_list|(
name|vId
parameter_list|,
name|data
parameter_list|)
function_decl|;
name|m_mapKeyToVariantValue
operator|.
name|insert
argument_list|(
name|pr
argument_list|)
expr_stmt|;
block|}
end_if

begin_return
return|return
name|bOk
return|;
end_return

begin_comment
unit|}
comment|//++ ------------------------------------------------------------------------------------
end_comment

begin_comment
comment|// Details: Retrieve a data object from *this container identified by the specified ID.
end_comment

begin_comment
comment|// Type:    Method.
end_comment

begin_comment
comment|// Args:    T           - The data object's variable type.
end_comment

begin_comment
comment|//          vId         - (R) Unique ID i.e. GUID.
end_comment

begin_comment
comment|//          vrwData     - (W) Copy of the data object held.
end_comment

begin_comment
comment|//          vrwbFound   - (W) True = data found, false = data not found.
end_comment

begin_comment
comment|// Return:  MIstatus::success - Functional succeeded.
end_comment

begin_comment
comment|//          MIstatus::failure - Functional failed.
end_comment

begin_comment
comment|// Throws:  None.
end_comment

begin_comment
comment|//--
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
name|bool
name|CMIUtilMapIdToVariant
operator|::
name|Get
argument_list|(
argument|const CMIUtilString&vId
argument_list|,
argument|T&vrwData
argument_list|,
argument|bool&vrwbFound
argument_list|)
specifier|const
block|{
name|vrwbFound
operator|=
name|false
block|;
if|if
condition|(
operator|!
name|IsValid
argument_list|(
name|vId
argument_list|)
condition|)
block|{
name|SetErrorDescription
argument_list|(
name|CMIUtilString
operator|::
name|Format
argument_list|(
name|MIRSRC
argument_list|(
name|IDS_VARIANT_ERR_MAP_KEY_INVALID
argument_list|)
argument_list|,
name|vId
operator|.
name|c_str
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|MIstatus
operator|::
name|failure
return|;
block|}
specifier|const
name|MapKeyToVariantValue_t
operator|::
name|const_iterator
name|it
operator|=
name|m_mapKeyToVariantValue
operator|.
name|find
argument_list|(
name|vId
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|it
operator|!=
name|m_mapKeyToVariantValue
operator|.
name|end
argument_list|()
condition|)
block|{
specifier|const
name|CMIUtilVariant
modifier|&
name|rData
init|=
operator|(
operator|*
name|it
operator|)
operator|.
name|second
decl_stmt|;
specifier|const
name|T
modifier|*
name|pDataObj
init|=
name|rData
operator|.
name|Get
operator|<
name|T
operator|>
operator|(
operator|)
decl_stmt|;
if|if
condition|(
name|pDataObj
operator|!=
name|nullptr
condition|)
block|{
name|vrwbFound
operator|=
name|true
expr_stmt|;
name|vrwData
operator|=
operator|*
name|pDataObj
expr_stmt|;
return|return
name|MIstatus
operator|::
name|success
return|;
block|}
else|else
block|{
name|SetErrorDescription
argument_list|(
name|MIRSRC
argument_list|(
name|IDS_VARIANT_ERR_USED_BASECLASS
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|MIstatus
operator|::
name|failure
return|;
block|}
block|}
end_if

begin_return
return|return
name|MIstatus
operator|::
name|success
return|;
end_return

unit|}
end_unit

