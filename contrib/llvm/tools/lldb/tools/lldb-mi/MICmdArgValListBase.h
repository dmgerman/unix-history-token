begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmdArgValListBase.h -----------------------------------*- C++ -*-===//
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
comment|// File:		MICmdArgValListBase.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:	CMICmdArgValListBase interface.
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
comment|// Details:	MI common code class. Command argument with addition options class.
end_comment

begin_comment
comment|//			For example --recurse 1 2 4 [group ...]. Arguments object that
end_comment

begin_comment
comment|//			require a list of options associated with them derive from the
end_comment

begin_comment
comment|//			CMICmdArgValListBase class. Additional options are also extracted from
end_comment

begin_comment
comment|//			the command arguments text string.
end_comment

begin_comment
comment|//			An argument knows what type of argument it is and how it is to
end_comment

begin_comment
comment|//			interpret the options (context) string to find and validate a matching
end_comment

begin_comment
comment|//			options and so extract a values from it .
end_comment

begin_comment
comment|//			The CMICmdArgValBase objects are added to the derived argument class's
end_comment

begin_comment
comment|//			container. The option arguments belong to that derived class and will
end_comment

begin_comment
comment|//			be deleted that object goes out of scope.
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
name|CMICmdArgValListBase
range|:
name|public
name|CMICmdArgValBaseTemplate
operator|<
name|std
operator|::
name|vector
operator|<
name|CMICmdArgValBase
operator|*
operator|>
expr|>
block|{
comment|// Typedef:
name|public
operator|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|CMICmdArgValBase
operator|*
operator|>
name|VecArgObjPtr_t
expr_stmt|;
comment|// Enums:
name|public
operator|:
comment|//++ ---------------------------------------------------------------------------------
comment|// Details:	CMICmdArgValListBase needs to know what type of argument to look for in
comment|//			the command options text. It also needs to create argument objects of
comment|//			a specific type.
comment|//--
block|enum
name|ArgValType_e
block|{
name|eArgValType_File
operator|=
literal|0
block|,
name|eArgValType_Consume
block|,
name|eArgValType_Number
block|,
name|eArgValType_OptionLong
block|,
name|eArgValType_OptionShort
block|,
name|eArgValType_String
block|,
name|eArgValType_StringQuoted
block|,
name|eArgValType_StringQuotedNumber
block|,
name|eArgValType_StringQuotedNumberPath
block|,
name|eArgValType_StringAnything
block|,
comment|// Accept any words for a string 'type' even if they look like --longOptions for example
name|eArgValType_ThreadGrp
block|,
name|eArgValType_count
block|,
comment|// Always the last one
name|eArgValType_invalid
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Methods:
end_comment

begin_label
name|public
label|:
end_label

begin_comment
comment|/* ctor */
end_comment

begin_expr_stmt
name|CMICmdArgValListBase
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* ctor */
end_comment

begin_macro
name|CMICmdArgValListBase
argument_list|(
argument|const CMIUtilString& vrArgName
argument_list|,
argument|const bool vbMandatory
argument_list|,
argument|const bool vbHandleByCmd
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* ctor */
end_comment

begin_macro
name|CMICmdArgValListBase
argument_list|(
argument|const CMIUtilString& vrArgName
argument_list|,
argument|const bool vbMandatory
argument_list|,
argument|const bool vbHandleByCmd
argument_list|,
argument|const ArgValType_e veType
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Overridden:
end_comment

begin_label
name|public
label|:
end_label

begin_comment
comment|// From CMICmdArgValBase
end_comment

begin_comment
comment|/* dtor */
end_comment

begin_expr_stmt
name|virtual
operator|~
name|CMICmdArgValListBase
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Methods:
end_comment

begin_label
name|protected
label|:
end_label

begin_decl_stmt
name|bool
name|IsExpectedCorrectType
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vrTxt
argument_list|,
specifier|const
name|ArgValType_e
name|veType
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CMICmdArgValBase
modifier|*
name|CreationObj
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vrTxt
argument_list|,
specifier|const
name|ArgValType_e
name|veType
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Attributes:
end_comment

begin_label
name|protected
label|:
end_label

begin_decl_stmt
name|ArgValType_e
name|m_eArgType
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Methods:
end_comment

begin_label
name|private
label|:
end_label

begin_function_decl
name|void
name|Destroy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

unit|};
end_unit

