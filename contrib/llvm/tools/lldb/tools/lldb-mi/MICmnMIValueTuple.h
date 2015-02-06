begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmnMIValueTuple.h -------------------------------------*- C++ -*-===//
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
comment|// File:        MICmnMIValueTuple.h
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Overview:    CMICmnMIValueTuple interface.
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
file|"MICmnMIValue.h"
end_include

begin_include
include|#
directive|include
file|"MICmnMIValueResult.h"
end_include

begin_include
include|#
directive|include
file|"MICmnMIValueConst.h"
end_include

begin_comment
comment|//++ ============================================================================
end_comment

begin_comment
comment|// Details: MI common code MI Result class. Part of the CMICmnMIValueTupleRecord
end_comment

begin_comment
comment|//          set of objects.
end_comment

begin_comment
comment|//          The syntax is as follows:
end_comment

begin_comment
comment|//          result-record ==>  [ token ] "^" result-class ( "," result )* nl
end_comment

begin_comment
comment|//          token = any sequence of digits
end_comment

begin_comment
comment|//          * = 0 to many
end_comment

begin_comment
comment|//          nl = CR | CR_LF
end_comment

begin_comment
comment|//          result-class ==> "done" | "running" | "connected" | "error" | "exit"
end_comment

begin_comment
comment|//          result ==> variable "=" value
end_comment

begin_comment
comment|//          value ==> const | tuple | list
end_comment

begin_comment
comment|//          const ==> c-string (7 bit iso c string content)
end_comment

begin_comment
comment|//          tuple ==>  "{}" | "{" result ( "," result )* "}"
end_comment

begin_comment
comment|//          list ==>  "[]" | "[" value ( "," value )* "]" | "[" result ( "," result )* "]"
end_comment

begin_comment
comment|//          More information see:
end_comment

begin_comment
comment|//          http://ftp.gnu.org/old-gnu/Manuals/gdb-5.1.1/html_chapter/gdb_22.html
end_comment

begin_comment
comment|// Gotchas: None.
end_comment

begin_comment
comment|// Authors: Illya Rudkin 24/02/2014.
end_comment

begin_comment
comment|// Changes: None.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmnMIValueTuple
range|:
name|public
name|CMICmnMIValue
block|{
comment|// Methods:
name|public
operator|:
comment|/* ctor */
name|CMICmnMIValueTuple
argument_list|(
name|void
argument_list|)
block|;
comment|/* ctor */
name|CMICmnMIValueTuple
argument_list|(
specifier|const
name|CMICmnMIValueResult
operator|&
name|vResult
argument_list|)
block|;
comment|/* ctor */
name|CMICmnMIValueTuple
argument_list|(
argument|const CMICmnMIValueResult&vResult
argument_list|,
argument|const bool vbUseSpacing
argument_list|)
block|;
comment|//
name|bool
name|Add
argument_list|(
specifier|const
name|CMICmnMIValueResult
operator|&
name|vResult
argument_list|)
block|;
name|bool
name|Add
argument_list|(
argument|const CMICmnMIValueResult&vResult
argument_list|,
argument|const bool vbUseSpacing
argument_list|)
block|;
name|bool
name|Add
argument_list|(
argument|const CMICmnMIValueConst&vValue
argument_list|,
argument|const bool vbUseSpacing
argument_list|)
block|;
name|CMIUtilString
name|ExtractContentNoBrackets
argument_list|(
argument|void
argument_list|)
specifier|const
block|;
comment|// Overridden:
name|public
operator|:
comment|// From CMICmnBase
comment|/* dtor */
name|virtual
operator|~
name|CMICmnMIValueTuple
argument_list|(
name|void
argument_list|)
block|;
comment|// Methods:
name|private
operator|:
name|bool
name|BuildTuple
argument_list|(
name|void
argument_list|)
block|;
name|bool
name|BuildTuple
argument_list|(
specifier|const
name|CMICmnMIValueResult
operator|&
name|vResult
argument_list|)
block|;
name|bool
name|BuildTuple
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vValue
argument_list|)
block|;
comment|// Attributes:
name|private
operator|:
name|bool
name|m_bSpaceAfterComma
block|;
comment|// True = put space seperators into the string, false = no spaces used
block|}
decl_stmt|;
end_decl_stmt

end_unit

