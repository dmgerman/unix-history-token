begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmnLLDBUtilSBValue.h ----------------------------------*- C++ -*-===//
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
comment|// Third Party Headers:
end_comment

begin_include
include|#
directive|include
file|"lldb/API/SBValue.h"
end_include

begin_comment
comment|// In-house headers:
end_comment

begin_include
include|#
directive|include
file|"MIDataTypes.h"
end_include

begin_include
include|#
directive|include
file|"MICmnMIValueTuple.h"
end_include

begin_comment
comment|// Declarations:
end_comment

begin_decl_stmt
name|class
name|CMIUtilString
decl_stmt|;
end_decl_stmt

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: Utility helper class to lldb::SBValue. Using a lldb::SBValue extract
end_comment

begin_comment
comment|//          value object information to help form verbose debug information.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmnLLDBUtilSBValue
block|{
comment|// Methods:
name|public
label|:
comment|/* ctor */
name|CMICmnLLDBUtilSBValue
argument_list|(
argument|const lldb::SBValue&vrValue
argument_list|,
argument|const bool vbHandleCharType = false
argument_list|,
argument|const bool vbHandleArrayType = true
argument_list|)
empty_stmt|;
comment|/* dtor */
operator|~
name|CMICmnLLDBUtilSBValue
argument_list|()
expr_stmt|;
comment|//
name|CMIUtilString
name|GetName
argument_list|()
specifier|const
expr_stmt|;
name|CMIUtilString
name|GetValue
argument_list|(
specifier|const
name|bool
name|vbExpandAggregates
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
name|CMIUtilString
name|GetTypeName
argument_list|()
specifier|const
expr_stmt|;
name|CMIUtilString
name|GetTypeNameDisplay
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|IsCharType
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|IsFirstChildCharType
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|IsPointeeCharType
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|IsIntegerType
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|IsPointerType
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|IsArrayType
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|IsLLDBVariable
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|IsNameUnknown
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|IsValueUnknown
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|HasName
argument_list|()
specifier|const
expr_stmt|;
comment|// Methods:
name|private
label|:
name|template
operator|<
name|typename
name|charT
operator|>
name|CMIUtilString
name|ReadCStringFromHostMemory
argument_list|(
argument|lldb::SBValue&vrValue
argument_list|,
argument|const MIuint vnMaxLen = UINT32_MAX
argument_list|)
specifier|const
expr_stmt|;
name|bool
name|GetSimpleValue
argument_list|(
specifier|const
name|bool
name|vbHandleArrayType
argument_list|,
name|CMIUtilString
operator|&
name|vrValue
argument_list|)
decl|const
decl_stmt|;
name|bool
name|GetCompositeValue
argument_list|(
specifier|const
name|bool
name|vbPrintFieldNames
argument_list|,
name|CMICmnMIValueTuple
operator|&
name|vwrMiValueTuple
argument_list|,
specifier|const
name|MIuint
name|vnDepth
operator|=
literal|1
argument_list|)
decl|const
decl_stmt|;
name|CMIUtilString
name|GetValueSummary
argument_list|(
name|bool
name|valueOnly
argument_list|,
specifier|const
name|CMIUtilString
operator|&
name|failVal
operator|=
name|CMIUtilString
argument_list|()
argument_list|)
decl|const
decl_stmt|;
comment|// Statics:
name|private
label|:
specifier|static
name|bool
name|IsCharBasicType
argument_list|(
name|lldb
operator|::
name|BasicType
name|eType
argument_list|)
decl_stmt|;
comment|// Attributes:
name|private
label|:
name|lldb
operator|::
name|SBValue
operator|&
name|m_rValue
expr_stmt|;
specifier|const
name|char
modifier|*
name|m_pUnkwn
decl_stmt|;
specifier|const
name|char
modifier|*
name|m_pComposite
decl_stmt|;
name|bool
name|m_bValidSBValue
decl_stmt|;
comment|// True = SBValue is a valid object, false = not valid.
name|bool
name|m_bHandleCharType
decl_stmt|;
comment|// True = Yes return text molding to char type, false = just return data.
name|bool
name|m_bHandleArrayType
decl_stmt|;
comment|// True = Yes return special stub for array type, false = just return data.
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

