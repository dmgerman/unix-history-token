begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MIUtilVariant.h -----------------------------------------*- C++ -*-===//
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
comment|// File:        MIUtilVariant.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:    CMIUtilVariant interface.
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
comment|// Gotchas:     See CMIUtilVariant class description.
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
file|"MIDataTypes.h"
end_include

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI common code utility class. The class implements behaviour of a
end_comment

begin_comment
comment|//          variant object which holds any data object of type T. A copy of the
end_comment

begin_comment
comment|//          data object specified is made and stored in *this wrapper. When the
end_comment

begin_comment
comment|//          *this object is destroyed the data object hold within calls its
end_comment

begin_comment
comment|//          destructor should it have one.
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 18/06/2014.
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMIUtilVariant
block|{
comment|// Methods:
name|public
label|:
comment|/* ctor */
name|CMIUtilVariant
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/* ctor */
name|CMIUtilVariant
argument_list|(
specifier|const
name|CMIUtilVariant
operator|&
name|vrOther
argument_list|)
expr_stmt|;
comment|/* ctor */
name|CMIUtilVariant
argument_list|(
name|CMIUtilVariant
operator|&
name|vrOther
argument_list|)
expr_stmt|;
comment|/* ctor */
name|CMIUtilVariant
argument_list|(
name|CMIUtilVariant
operator|&&
name|vrwOther
argument_list|)
expr_stmt|;
comment|/* dtor */
operator|~
name|CMIUtilVariant
argument_list|(
name|void
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|Set
argument_list|(
specifier|const
name|T
operator|&
name|vArg
argument_list|)
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|*
name|Get
argument_list|(
argument|void
argument_list|)
specifier|const
expr_stmt|;
name|CMIUtilVariant
modifier|&
name|operator
init|=
operator|(
specifier|const
name|CMIUtilVariant
operator|&
name|vrOther
operator|)
decl_stmt|;
name|CMIUtilVariant
modifier|&
name|operator
init|=
operator|(
name|CMIUtilVariant
operator|&&
name|vrwOther
operator|)
decl_stmt|;
comment|// Classes:
name|private
label|:
comment|//++ ----------------------------------------------------------------------
comment|// Details: Base class wrapper to hold the variant's data object when
comment|//          assigned to it by the Set() function. Do not use the CDataObjectBase
comment|//          to create objects, use only CDataObjectBase derived objects,
comment|//          see CDataObject() class.
comment|//--
name|class
name|CDataObjectBase
block|{
comment|// Methods:
name|public
label|:
comment|/* ctor */
name|CDataObjectBase
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/* ctor */
name|CDataObjectBase
argument_list|(
specifier|const
name|CDataObjectBase
operator|&
name|vrOther
argument_list|)
expr_stmt|;
comment|/* ctor */
name|CDataObjectBase
argument_list|(
name|CDataObjectBase
operator|&
name|vrOther
argument_list|)
expr_stmt|;
comment|/* ctor */
name|CDataObjectBase
argument_list|(
name|CDataObjectBase
operator|&&
name|vrwOther
argument_list|)
expr_stmt|;
comment|//
name|CDataObjectBase
modifier|&
name|operator
init|=
operator|(
specifier|const
name|CDataObjectBase
operator|&
name|vrOther
operator|)
decl_stmt|;
name|CDataObjectBase
modifier|&
name|operator
init|=
operator|(
name|CDataObjectBase
operator|&&
name|vrwOther
operator|)
decl_stmt|;
comment|// Overrideable:
name|public
label|:
name|virtual
operator|~
name|CDataObjectBase
argument_list|(
name|void
argument_list|)
expr_stmt|;
name|virtual
name|CDataObjectBase
modifier|*
name|CreateCopyOfSelf
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|virtual
name|bool
name|GetIsDerivedClass
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
comment|// Overrideable:
name|protected
label|:
name|virtual
name|void
name|Copy
parameter_list|(
specifier|const
name|CDataObjectBase
modifier|&
name|vrOther
parameter_list|)
function_decl|;
name|virtual
name|void
name|Destroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|//++ ----------------------------------------------------------------------
comment|// Details: Derived from CDataObjectBase, this class is the wrapper for the
comment|//          data object as it has an aggregate of type T which is a copy
comment|//          of the data object assigned to the variant object.
comment|//--
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|CDataObject
operator|:
name|public
name|CDataObjectBase
block|{
comment|// Methods:
name|public
operator|:
comment|/* ctor */
name|CDataObject
argument_list|(
name|void
argument_list|)
block|;
comment|/* ctor */
name|CDataObject
argument_list|(
specifier|const
name|T
operator|&
name|vArg
argument_list|)
block|;
comment|/* ctor */
name|CDataObject
argument_list|(
specifier|const
name|CDataObject
operator|&
name|vrOther
argument_list|)
block|;
comment|/* ctor */
name|CDataObject
argument_list|(
name|CDataObject
operator|&
name|vrOther
argument_list|)
block|;
comment|/* ctor */
name|CDataObject
argument_list|(
name|CDataObject
operator|&&
name|vrwOther
argument_list|)
block|;
comment|//
name|CDataObject
operator|&
name|operator
operator|=
operator|(
specifier|const
name|CDataObject
operator|&
name|vrOther
operator|)
block|;
name|CDataObject
operator|&
name|operator
operator|=
operator|(
name|CDataObject
operator|&&
name|vrwOther
operator|)
block|;
comment|//
name|T
operator|&
name|GetDataObject
argument_list|(
name|void
argument_list|)
block|;
comment|// Overridden:
name|public
operator|:
comment|// From CDataObjectBase
name|virtual
operator|~
name|CDataObject
argument_list|(
name|void
argument_list|)
block|;
name|virtual
name|CDataObjectBase
operator|*
name|CreateCopyOfSelf
argument_list|(
name|void
argument_list|)
block|;
name|virtual
name|bool
name|GetIsDerivedClass
argument_list|(
argument|void
argument_list|)
specifier|const
block|;
comment|// Overrideable:
name|private
operator|:
name|virtual
name|void
name|Duplicate
argument_list|(
specifier|const
name|CDataObject
operator|&
name|vrOther
argument_list|)
block|;
comment|// Overridden:
name|private
operator|:
comment|// From CDataObjectBase
name|virtual
name|void
name|Destroy
argument_list|(
name|void
argument_list|)
block|;
comment|// Attributes:
name|private
operator|:
name|T
name|m_dataObj
block|;     }
expr_stmt|;
comment|// Methods
name|private
label|:
name|void
name|Destroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
name|Copy
parameter_list|(
specifier|const
name|CMIUtilVariant
modifier|&
name|vrOther
parameter_list|)
function_decl|;
comment|// Attributes:
name|private
label|:
name|CDataObjectBase
modifier|*
name|m_pDataObject
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//---------------------------------------------------------------------------------------
end_comment

begin_comment
comment|//---------------------------------------------------------------------------------------
end_comment

begin_comment
comment|//---------------------------------------------------------------------------------------
end_comment

begin_comment
comment|//++ ------------------------------------------------------------------------------------
end_comment

begin_comment
comment|// Details: CDataObject constructor.
end_comment

begin_comment
comment|// Type:    Method.
end_comment

begin_comment
comment|// Args:    T   - The object's type.
end_comment

begin_comment
comment|// Return:  None.
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
name|CMIUtilVariant
operator|::
name|CDataObject
operator|<
name|T
operator|>
operator|::
name|CDataObject
argument_list|(
argument|void
argument_list|)
block|{ }
comment|//++ ------------------------------------------------------------------------------------
comment|// Details: CDataObject constructor.
comment|// Type:    Method.
comment|// Args:    T       - The object's type.
comment|//          vArg    - (R) The data object to be stored in the variant object.
comment|// Return:  None.
comment|// Throws:  None.
comment|//--
name|template
operator|<
name|typename
name|T
operator|>
name|CMIUtilVariant
operator|::
name|CDataObject
operator|<
name|T
operator|>
operator|::
name|CDataObject
argument_list|(
argument|const T&vArg
argument_list|)
block|{
name|m_dataObj
operator|=
name|vArg
block|; }
comment|//++ ------------------------------------------------------------------------------------
comment|// Details: CDataObject destructor.
comment|// Type:    Overridden.
comment|// Args:    T   - The object's type.
comment|// Return:  None.
comment|// Throws:  None.
comment|//--
name|template
operator|<
name|typename
name|T
operator|>
name|CMIUtilVariant
operator|::
name|CDataObject
operator|<
name|T
operator|>
operator|::
operator|~
name|CDataObject
argument_list|(
argument|void
argument_list|)
block|{
name|Destroy
argument_list|()
block|; }
comment|//++ ------------------------------------------------------------------------------------
comment|// Details: Retrieve the data object hold by *this object wrapper.
comment|// Type:    Method.
comment|// Args:    T   - The object's type.
comment|// Return:  T& - Reference to the data object.
comment|// Throws:  None.
comment|//--
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|&
name|CMIUtilVariant
operator|::
name|CDataObject
operator|<
name|T
operator|>
operator|::
name|GetDataObject
argument_list|(
argument|void
argument_list|)
block|{
return|return
name|m_dataObj
return|;
block|}
end_expr_stmt

begin_comment
comment|//++ ------------------------------------------------------------------------------------
end_comment

begin_comment
comment|// Details: Create a new copy of *this class.
end_comment

begin_comment
comment|// Type:    Overridden.
end_comment

begin_comment
comment|// Args:    T   - The object's type.
end_comment

begin_comment
comment|// Return:  CDataObjectBase *   - Pointer to a new object.
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
name|CMIUtilVariant
operator|::
name|CDataObjectBase
operator|*
name|CMIUtilVariant
operator|::
name|CDataObject
operator|<
name|T
operator|>
operator|::
name|CreateCopyOfSelf
argument_list|(
argument|void
argument_list|)
block|{
name|CDataObject
operator|*
name|pCopy
operator|=
name|new
name|CDataObject
operator|<
name|T
operator|>
operator|(
name|m_dataObj
operator|)
block|;
return|return
name|pCopy
return|;
block|}
end_expr_stmt

begin_comment
comment|//++ ------------------------------------------------------------------------------------
end_comment

begin_comment
comment|// Details: Determine if *this object is a derived from CDataObjectBase.
end_comment

begin_comment
comment|// Type:    Overridden.
end_comment

begin_comment
comment|// Args:    T   - The object's type.
end_comment

begin_comment
comment|// Return:  bool    - True = *this is derived from CDataObjectBase
end_comment

begin_comment
comment|//                  - False = *this is an instance of the base class.
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
name|CMIUtilVariant
operator|::
name|CDataObject
operator|<
name|T
operator|>
operator|::
name|GetIsDerivedClass
argument_list|(
argument|void
argument_list|)
specifier|const
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

begin_comment
comment|//++ ------------------------------------------------------------------------------------
end_comment

begin_comment
comment|// Details: Perform a bitwise copy of *this object.
end_comment

begin_comment
comment|// Type:    Overrideable.
end_comment

begin_comment
comment|// Args:    T       - The object's type.
end_comment

begin_comment
comment|//          vrOther - (R) The other object.
end_comment

begin_comment
comment|// Return:  None.
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
name|void
name|CMIUtilVariant
operator|::
name|CDataObject
operator|<
name|T
operator|>
operator|::
name|Duplicate
argument_list|(
argument|const CDataObject&vrOther
argument_list|)
block|{
name|CDataObjectBase
operator|::
name|Copy
argument_list|(
name|vrOther
argument_list|)
block|;
name|m_dataObj
operator|=
name|vrOther
operator|.
name|m_dataObj
block|; }
comment|//++ ------------------------------------------------------------------------------------
comment|// Details: Release any resources used by *this object.
comment|// Type:    Overridden.
comment|// Args:    None.
comment|// Return:  None.
comment|// Throws:  None.
comment|//--
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|CMIUtilVariant
operator|::
name|CDataObject
operator|<
name|T
operator|>
operator|::
name|Destroy
argument_list|(
argument|void
argument_list|)
block|{
name|CDataObjectBase
operator|::
name|Destroy
argument_list|()
block|; }
comment|//---------------------------------------------------------------------------------------
comment|//---------------------------------------------------------------------------------------
comment|//---------------------------------------------------------------------------------------
comment|//++ ------------------------------------------------------------------------------------
comment|// Details: Assign to the variant an object of a specified type.
comment|// Type:    Template method.
comment|// Args:    T       - The object's type.
comment|//          vArg    - (R) The object to store.
comment|// Return:  None.
comment|// Throws:  None.
comment|//--
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|CMIUtilVariant
operator|::
name|Set
argument_list|(
argument|const T&vArg
argument_list|)
block|{
name|m_pDataObject
operator|=
name|new
name|CDataObject
operator|<
name|T
operator|>
operator|(
name|vArg
operator|)
block|; }
comment|//++ ------------------------------------------------------------------------------------
comment|// Details: Retrieve the data object from *this variant.
comment|// Type:    Template method.
comment|// Args:    T   - The object's type.
comment|// Return:  T * - Pointer the data object, NULL = data object not assigned to *this variant.
comment|// Throws:  None.
comment|//--
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|*
name|CMIUtilVariant
operator|::
name|Get
argument_list|(
argument|void
argument_list|)
specifier|const
block|{
if|if
condition|(
operator|(
name|m_pDataObject
operator|!=
name|nullptr
operator|)
operator|&&
name|m_pDataObject
operator|->
name|GetIsDerivedClass
argument_list|()
condition|)
block|{
name|CDataObject
operator|<
name|T
operator|>
operator|*
name|pDataObj
operator|=
name|static_cast
operator|<
name|CDataObject
operator|<
name|T
operator|>
operator|*
operator|>
operator|(
name|m_pDataObject
operator|)
expr_stmt|;
return|return
operator|&
name|pDataObj
operator|->
name|GetDataObject
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// Do not use a CDataObjectBase object, use only CDataObjectBase derived objects
end_comment

begin_return
return|return
name|nullptr
return|;
end_return

unit|}
end_unit

