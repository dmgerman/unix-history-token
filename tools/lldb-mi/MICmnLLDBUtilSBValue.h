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

begin_comment
comment|//++
end_comment

begin_comment
comment|// File:        MICmnLLDBUtilSBValue.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:    CMICmnLLDBUtilSBValue interface.
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

begin_comment
comment|// Declerations:
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
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 08/07/2014.
end_comment

begin_comment
comment|// Changes: None.
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
argument_list|)
empty_stmt|;
comment|/* dtor */
operator|~
name|CMICmnLLDBUtilSBValue
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|//
name|CMIUtilString
name|GetName
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|CMIUtilString
name|GetValue
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|CMIUtilString
name|GetValueCString
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|CMIUtilString
name|GetChildValueCString
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|CMIUtilString
name|GetTypeName
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|CMIUtilString
name|GetTypeNameDisplay
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|bool
name|IsCharType
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|bool
name|IsChildCharType
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|bool
name|IsLLDBVariable
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|bool
name|IsNameUnknown
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|bool
name|IsValueUnknown
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|bool
name|IsValid
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|bool
name|HasName
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
comment|// Methods:
name|private
label|:
name|CMIUtilString
name|ReadCStringFromHostMemory
argument_list|(
specifier|const
name|lldb
operator|::
name|SBValue
operator|&
name|vrValueObj
argument_list|)
decl|const
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
name|MIchar
modifier|*
name|m_pUnkwn
decl_stmt|;
name|bool
name|m_bValidSBValue
decl_stmt|;
comment|// True = SBValue is a valid object, false = not valid.
name|bool
name|m_bHandleCharType
decl_stmt|;
comment|// True = Yes return text molding to char type, false = just return data.
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

