begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmnLLDBDebugSessionInfoVarObj.h -----------------------*- C++ -*-===//
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
comment|// File:		MICmnLLDBDebugSessionInfoVarObj.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:	CMICmnLLDBDebugSessionInfoVarObj interface.
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
comment|// Third Party Headers:
end_comment

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<lldb/API/SBValue.h>
end_include

begin_comment
comment|// In-house headers:
end_comment

begin_include
include|#
directive|include
file|"MIUtilString.h"
end_include

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details:	MI debug session variable object. The static functionality in *this
end_comment

begin_comment
comment|//			class manages a map container of *these variable objects.
end_comment

begin_comment
comment|// Gotchas:	None.
end_comment

begin_comment
comment|// Authors:	Illya Rudkin 24/03/2014.
end_comment

begin_comment
comment|// Changes:	None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmnLLDBDebugSessionInfoVarObj
block|{
comment|// Enums:
name|public
label|:
comment|//++ ----------------------------------------------------------------------
comment|// Details:	Enumeration of a variable type that is not a composite type
comment|//--
enum|enum
name|varFormat_e
block|{
comment|// CODETAG_SESSIONINFO_VARFORMAT_ENUM
comment|// *** Order is import here ***
name|eVarFormat_Invalid
init|=
literal|0
block|,
name|eVarFormat_Binary
block|,
name|eVarFormat_Octal
block|,
name|eVarFormat_Decimal
block|,
name|eVarFormat_Hex
block|,
name|eVarFormat_Natural
block|,
name|eVarFormat_count
comment|// Always last one
block|}
enum|;
comment|//++ ----------------------------------------------------------------------
comment|// Details:	Enumeration of a variable type by composite or internal type
comment|//--
enum|enum
name|varType_e
block|{
name|eVarType_InValid
init|=
literal|0
block|,
name|eVarType_Composite
block|,
comment|// i.e. struct
name|eVarType_Internal
block|,
comment|// i.e. int
name|eVarType_count
comment|// Always last one
block|}
enum|;
comment|// Statics:
name|public
label|:
specifier|static
name|varFormat_e
name|GetVarFormatForString
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vrStrFormat
parameter_list|)
function_decl|;
specifier|static
name|varFormat_e
name|GetVarFormatForChar
parameter_list|(
specifier|const
name|MIchar
modifier|&
name|vrcFormat
parameter_list|)
function_decl|;
specifier|static
name|CMIUtilString
name|GetValueStringFormatted
argument_list|(
specifier|const
name|lldb
operator|::
name|SBValue
operator|&
name|vrValue
argument_list|,
specifier|const
name|varFormat_e
name|veVarFormat
argument_list|)
decl_stmt|;
specifier|static
name|void
name|VarObjAdd
parameter_list|(
specifier|const
name|CMICmnLLDBDebugSessionInfoVarObj
modifier|&
name|vrVarObj
parameter_list|)
function_decl|;
specifier|static
name|void
name|VarObjDelete
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vrVarName
parameter_list|)
function_decl|;
specifier|static
name|bool
name|VarObjGet
parameter_list|(
specifier|const
name|CMIUtilString
modifier|&
name|vrVarName
parameter_list|,
name|CMICmnLLDBDebugSessionInfoVarObj
modifier|&
name|vrwVarObj
parameter_list|)
function_decl|;
specifier|static
name|void
name|VarObjUpdate
parameter_list|(
specifier|const
name|CMICmnLLDBDebugSessionInfoVarObj
modifier|&
name|vrVarObj
parameter_list|)
function_decl|;
specifier|static
name|void
name|VarObjIdInc
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|static
name|MIuint
name|VarObjIdGet
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|static
name|void
name|VarObjIdResetToZero
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|static
name|void
name|VarObjClear
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// Methods:
name|public
label|:
comment|/* ctor */
name|CMICmnLLDBDebugSessionInfoVarObj
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/* ctor */
name|CMICmnLLDBDebugSessionInfoVarObj
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vrStrNameReal
argument_list|,
specifier|const
name|CMIUtilString
operator|&
name|vrStrName
argument_list|,
specifier|const
name|lldb
operator|::
name|SBValue
operator|&
name|vrValue
argument_list|)
expr_stmt|;
comment|/* ctor */
name|CMICmnLLDBDebugSessionInfoVarObj
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vrStrNameReal
argument_list|,
specifier|const
name|CMIUtilString
operator|&
name|vrStrName
argument_list|,
specifier|const
name|lldb
operator|::
name|SBValue
operator|&
name|vrValue
argument_list|,
specifier|const
name|CMIUtilString
operator|&
name|vrStrVarObjParentName
argument_list|)
expr_stmt|;
comment|/* ctor */
name|CMICmnLLDBDebugSessionInfoVarObj
argument_list|(
specifier|const
name|CMICmnLLDBDebugSessionInfoVarObj
operator|&
name|vrOther
argument_list|)
expr_stmt|;
comment|/* ctor */
name|CMICmnLLDBDebugSessionInfoVarObj
argument_list|(
name|CMICmnLLDBDebugSessionInfoVarObj
operator|&
name|vrOther
argument_list|)
expr_stmt|;
comment|/* ctor */
name|CMICmnLLDBDebugSessionInfoVarObj
argument_list|(
name|CMICmnLLDBDebugSessionInfoVarObj
operator|&&
name|vrOther
argument_list|)
expr_stmt|;
comment|//
name|CMICmnLLDBDebugSessionInfoVarObj
modifier|&
name|operator
init|=
operator|(
specifier|const
name|CMICmnLLDBDebugSessionInfoVarObj
operator|&
name|vrOther
operator|)
decl_stmt|;
name|CMICmnLLDBDebugSessionInfoVarObj
modifier|&
name|operator
init|=
operator|(
name|CMICmnLLDBDebugSessionInfoVarObj
operator|&&
name|vrwOther
operator|)
decl_stmt|;
comment|//
specifier|const
name|CMIUtilString
modifier|&
name|GetName
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|CMIUtilString
modifier|&
name|GetNameReal
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|CMIUtilString
modifier|&
name|GetValueFormatted
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|lldb
operator|::
name|SBValue
operator|&
name|GetValue
argument_list|(
argument|void
argument_list|)
specifier|const
expr_stmt|;
name|varType_e
name|GetType
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|bool
name|SetVarFormat
parameter_list|(
specifier|const
name|varFormat_e
name|veVarFormat
parameter_list|)
function_decl|;
specifier|const
name|CMIUtilString
modifier|&
name|GetVarParentName
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
name|void
name|UpdateValue
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// Overridden:
name|public
label|:
comment|// From CMICmnBase
comment|/* dtor */
name|virtual
operator|~
name|CMICmnLLDBDebugSessionInfoVarObj
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|// Typedefs:
name|private
label|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|CMIUtilString
operator|,
name|CMICmnLLDBDebugSessionInfoVarObj
operator|>
name|MapKeyToVarObj_t
expr_stmt|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|CMIUtilString
operator|,
name|CMICmnLLDBDebugSessionInfoVarObj
operator|>
name|MapPairKeyToVarObj_t
expr_stmt|;
comment|// Statics:
name|private
label|:
specifier|static
name|CMIUtilString
name|GetStringFormatted
parameter_list|(
specifier|const
name|MIuint64
name|vnValue
parameter_list|,
specifier|const
name|MIchar
modifier|*
name|vpStrValueNatural
parameter_list|,
name|varFormat_e
name|veVarFormat
parameter_list|)
function_decl|;
comment|// Methods:
name|private
label|:
name|bool
name|CopyOther
parameter_list|(
specifier|const
name|CMICmnLLDBDebugSessionInfoVarObj
modifier|&
name|vrOther
parameter_list|)
function_decl|;
name|bool
name|MoveOther
parameter_list|(
name|CMICmnLLDBDebugSessionInfoVarObj
modifier|&
name|vrwOther
parameter_list|)
function_decl|;
comment|// Attributes:
name|private
label|:
specifier|static
specifier|const
name|MIchar
modifier|*
name|ms_aVarFormatStrings
index|[]
decl_stmt|;
specifier|static
specifier|const
name|MIchar
modifier|*
name|ms_aVarFormatChars
index|[]
decl_stmt|;
specifier|static
name|MapKeyToVarObj_t
name|ms_mapVarIdToVarObj
decl_stmt|;
specifier|static
name|MIuint
name|ms_nVarUniqueId
decl_stmt|;
comment|//
comment|// *** Upate the copy move constructors and assignment operator ***
name|varFormat_e
name|m_eVarFormat
decl_stmt|;
name|varType_e
name|m_eVarType
decl_stmt|;
name|CMIUtilString
name|m_strName
decl_stmt|;
name|lldb
operator|::
name|SBValue
name|m_SBValue
expr_stmt|;
name|CMIUtilString
name|m_strNameReal
decl_stmt|;
name|CMIUtilString
name|m_strFormattedValue
decl_stmt|;
name|CMIUtilString
name|m_strVarObjParentName
decl_stmt|;
comment|// *** Upate the copy move constructors and assignment operator ***
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

