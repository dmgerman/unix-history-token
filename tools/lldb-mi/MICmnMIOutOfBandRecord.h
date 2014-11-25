begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmnMIOutOfBandRecord.h --------------------------------*- C++ -*-===//
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
comment|// File:		MICmnMIOutOfBandRecord.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:	CMICmnMIOutOfBandRecord interface.
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
comment|// Details:	MI common code MI Out-of-band (Async) Record class. A class that encapsulates
end_comment

begin_comment
comment|//			MI result record data and the forming/format of data added to it.
end_comment

begin_comment
comment|//			Out-of-band records are used to notify the GDB/MI client of additional
end_comment

begin_comment
comment|//			changes that have occurred. Those changes can either be a consequence
end_comment

begin_comment
comment|//			of GDB/MI (e.g., a breakpoint modified) or a result of target activity
end_comment

begin_comment
comment|//			(e.g., target stopped).
end_comment

begin_comment
comment|//			The syntax is as follows:
end_comment

begin_comment
comment|//			"*" type ( "," result )*
end_comment

begin_comment
comment|//			type ==> running | stopped
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//			The Out-of-band record can be retrieve at any time *this object is
end_comment

begin_comment
comment|//			instantiated so unless work is done on *this Out-of-band record then it is
end_comment

begin_comment
comment|//			possible to return a malformed Out-of-band record. If nothing has been set
end_comment

begin_comment
comment|//			or added to *this MI Out-of-band record object then text "<Invalid>" will
end_comment

begin_comment
comment|//			be returned.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//			More information see:
end_comment

begin_comment
comment|//			http://ftp.gnu.org/old-gnu/Manuals/gdb-5.1.1/html_chapter/gdb_22.html//
end_comment

begin_comment
comment|//			Gotchas:	None.
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
name|CMICmnMIOutOfBandRecord
range|:
name|public
name|CMICmnBase
block|{
comment|// Enumerations:
name|public
operator|:
comment|//++
comment|// Details:	Enumeration of the type of Out-of-band for *this Out-of-band record
comment|//--
expr|enum
name|OutOfBand_e
block|{
name|eOutOfBand_Running
operator|=
literal|0
block|,
name|eOutOfBand_Stopped
block|,
name|eOutOfBand_BreakPointCreated
block|,
name|eOutOfBand_BreakPointModified
block|,
name|eOutOfBand_Thread
block|,
name|eOutOfBand_ThreadGroupAdded
block|,
name|eOutOfBand_ThreadGroupExited
block|,
name|eOutOfBand_ThreadGroupRemoved
block|,
name|eOutOfBand_ThreadGroupStarted
block|,
name|eOutOfBand_ThreadCreated
block|,
name|eOutOfBand_ThreadExited
block|,
name|eOutOfBand_ThreadSelected
block|,
name|eOutOfBand_count
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
name|OutOfBand_e
operator|,
name|CMIUtilString
operator|>
name|MapOutOfBandToOutOfBandText_t
expr_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|map
operator|<
name|OutOfBand_e
operator|,
name|CMIUtilString
operator|>
name|MapOutOfBandToToken_t
expr_stmt|;
end_typedef

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
name|CMICmnMIOutOfBandRecord
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* ctor */
end_comment

begin_macro
name|CMICmnMIOutOfBandRecord
argument_list|(
argument|const OutOfBand_e veType
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* ctor */
end_comment

begin_macro
name|CMICmnMIOutOfBandRecord
argument_list|(
argument|const OutOfBand_e veType
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
name|CMICmnMIOutOfBandRecord
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
name|BuildAsyncRecord
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
name|MapOutOfBandToOutOfBandText_t
name|ms_constMapOutOfBandToAsyncRecordText
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|MapOutOfBandToToken_t
name|ms_constMapOutOfBandTextToToken
decl_stmt|;
end_decl_stmt

begin_comment
comment|//
end_comment

begin_decl_stmt
name|OutOfBand_e
name|m_eResultAsyncRecordClass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CMIUtilString
name|m_strAsyncRecord
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

