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
file|"MICmnMIValueConst.h"
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
comment|// Details: MI common code MI Out-of-band (Async) Record class. A class that encapsulates
end_comment

begin_comment
comment|//          MI result record data and the forming/format of data added to it.
end_comment

begin_comment
comment|//          Out-of-band records are used to notify the GDB/MI client of additional
end_comment

begin_comment
comment|//          changes that have occurred. Those changes can either be a consequence
end_comment

begin_comment
comment|//          of GDB/MI (e.g., a breakpoint modified) or a result of target activity
end_comment

begin_comment
comment|//          (e.g., target stopped).
end_comment

begin_comment
comment|//          The syntax is as follows:
end_comment

begin_comment
comment|//          "*" type ( "," result )*
end_comment

begin_comment
comment|//          type ==> running | stopped
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//          The Out-of-band record can be retrieve at any time *this object is
end_comment

begin_comment
comment|//          instantiated so unless work is done on *this Out-of-band record then it is
end_comment

begin_comment
comment|//          possible to return a malformed Out-of-band record. If nothing has been set
end_comment

begin_comment
comment|//          or added to *this MI Out-of-band record object then text "<Invalid>" will
end_comment

begin_comment
comment|//          be returned.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//          More information see:
end_comment

begin_comment
comment|//          http://ftp.gnu.org/old-gnu/Manuals/gdb-5.1.1/html_chapter/gdb_22.html//
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
comment|// Details: Enumeration of the type of Out-of-band for *this Out-of-band record
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
name|eOutOfBand_TargetModuleLoaded
block|,
name|eOutOfBand_TargetModuleUnloaded
block|,
name|eOutOfBand_TargetStreamOutput
block|}
block|;
comment|// Methods:
name|public
operator|:
comment|/* ctor */
name|CMICmnMIOutOfBandRecord
argument_list|()
block|;
comment|/* ctor */
name|CMICmnMIOutOfBandRecord
argument_list|(
argument|OutOfBand_e veType
argument_list|)
block|;
comment|/* ctor */
name|CMICmnMIOutOfBandRecord
argument_list|(
argument|OutOfBand_e veType
argument_list|,
argument|const CMICmnMIValueConst&vConst
argument_list|)
block|;
comment|/* ctor */
name|CMICmnMIOutOfBandRecord
argument_list|(
argument|OutOfBand_e veType
argument_list|,
argument|const CMICmnMIValueResult&vResult
argument_list|)
block|;
comment|//
specifier|const
name|CMIUtilString
operator|&
name|GetString
argument_list|()
specifier|const
block|;
name|void
name|Add
argument_list|(
specifier|const
name|CMICmnMIValueResult
operator|&
name|vResult
argument_list|)
block|;
comment|// Overridden:
name|public
operator|:
comment|// From CMICmnBase
comment|/* dtor */
operator|~
name|CMICmnMIOutOfBandRecord
argument_list|()
name|override
block|;
comment|// Attributes:
name|private
operator|:
name|CMIUtilString
name|m_strAsyncRecord
block|;
comment|// Holds the text version of the result record to date
block|}
decl_stmt|;
end_decl_stmt

end_unit

