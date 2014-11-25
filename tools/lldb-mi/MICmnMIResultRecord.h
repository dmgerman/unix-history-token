begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmnMIResultRecord.h -----------------------------------*- C++ -*-===//
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
comment|// File:		MICmnMIResultRecord.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:	CMICmnMIResultRecord interface.
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
file|"MIUtilString.h"
end_include

begin_include
include|#
directive|include
file|"MICmnMIValueResult.h"
end_include

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details:	MI common code MI Result Record class. A class that encapsulates
end_comment

begin_comment
comment|//			MI result record data and the forming/format of data added to it.
end_comment

begin_comment
comment|//			The syntax is as follows:
end_comment

begin_comment
comment|//			result-record ==>  [ token ] "^" result-class ( "," result )* nl
end_comment

begin_comment
comment|//			token = any sequence of digits
end_comment

begin_comment
comment|//			* = 0 to many
end_comment

begin_comment
comment|//			nl = CR | CR_LF
end_comment

begin_comment
comment|//			result-class ==> "done" | "running" | "connected" | "error" | "exit"
end_comment

begin_comment
comment|//			result ==> variable "=" value
end_comment

begin_comment
comment|//			value ==> const | tuple | list
end_comment

begin_comment
comment|//			const ==> c-string (7 bit iso c string content) i.e. "all" inc quotes
end_comment

begin_comment
comment|//			tuple ==>  "{}" | "{" result ( "," result )* "}"
end_comment

begin_comment
comment|//			list ==>  "[]" | "[" value ( "," value )* "]" | "[" result ( "," result )* "]"
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//			The result record can be retrieve at any time *this object is
end_comment

begin_comment
comment|//			instantiated so unless work is done on *this result record then it is
end_comment

begin_comment
comment|//			possible to return a malformed result record. If nothing has been set
end_comment

begin_comment
comment|//			or added to *this MI result record object then text "<Invalid>" will
end_comment

begin_comment
comment|//			be returned.
end_comment

begin_comment
comment|//			More information see:
end_comment

begin_comment
comment|//			http://ftp.gnu.org/old-gnu/Manuals/gdb-5.1.1/html_chapter/gdb_22.html
end_comment

begin_comment
comment|// Gotchas:	None.
end_comment

begin_comment
comment|// Authors:	Illya Rudkin 24/02/2014.
end_comment

begin_comment
comment|// Changes:	None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmnMIResultRecord
range|:
name|public
name|CMICmnBase
block|{
comment|// Enumerations:
name|public
operator|:
comment|//++
comment|// Details:	Enumeration of the result class for *this result record
comment|//--
expr|enum
name|ResultClass_e
block|{
name|eResultClass_Done
operator|=
literal|0
block|,
name|eResultClass_Running
block|,
name|eResultClass_Connected
block|,
name|eResultClass_Error
block|,
name|eResultClass_Exit
block|,
name|eResultClass_count
comment|// Always the last one
block|}
block|;
comment|// Typedefs:
name|public
operator|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|ResultClass_e
operator|,
name|CMIUtilString
operator|>
name|MapResultClassToResultClassText_t
expr_stmt|;
comment|// Methods:
name|public
operator|:
comment|/* ctor */
name|CMICmnMIResultRecord
argument_list|(
name|void
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ctor */
end_comment

begin_macro
name|CMICmnMIResultRecord
argument_list|(
argument|const CMIUtilString& vrToken
argument_list|,
argument|const ResultClass_e veType
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* ctor */
end_comment

begin_macro
name|CMICmnMIResultRecord
argument_list|(
argument|const CMIUtilString& vrToken
argument_list|,
argument|const ResultClass_e veType
argument_list|,
argument|const CMICmnMIValueResult& vValue
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//
end_comment

begin_decl_stmt
specifier|const
name|CMIUtilString
modifier|&
name|GetString
argument_list|(
name|void
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|Add
parameter_list|(
specifier|const
name|CMICmnMIValue
modifier|&
name|vMIValue
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Overridden:
end_comment

begin_label
name|public
label|:
end_label

begin_comment
comment|// From CMICmnBase
end_comment

begin_comment
comment|/* dtor */
end_comment

begin_expr_stmt
name|virtual
operator|~
name|CMICmnMIResultRecord
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Methods:
end_comment

begin_label
name|private
label|:
end_label

begin_function_decl
name|bool
name|BuildResultRecord
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Attributes:
end_comment

begin_label
name|private
label|:
end_label

begin_decl_stmt
specifier|static
specifier|const
name|CMIUtilString
name|ms_constStrResultRecordHat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|MapResultClassToResultClassText_t
name|ms_constMapResultClassToResultClassText
decl_stmt|;
end_decl_stmt

begin_comment
comment|//
end_comment

begin_decl_stmt
name|CMIUtilString
name|m_strResultRecordToken
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ResultClass_e
name|m_eResultRecordResultClass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CMIUtilString
name|m_strResultRecord
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Holds the text version of the result record to date
end_comment

begin_decl_stmt
name|CMICmnMIValueResult
name|m_partResult
decl_stmt|;
end_decl_stmt

unit|};
end_unit

