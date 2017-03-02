begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MICmnLog.h ----------------------------------------------*- C++ -*-===//
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
file|"MIUtilSingletonBase.h"
end_include

begin_include
include|#
directive|include
file|"MIUtilString.h"
end_include

begin_comment
comment|//++
end_comment

begin_comment
comment|//============================================================================
end_comment

begin_comment
comment|// Details: MI common code implementation class. Handle application trace
end_comment

begin_comment
comment|//          activity logging. Medium objects derived from the Medium abstract
end_comment

begin_comment
comment|///          class are registered with this logger. The function Write is called
end_comment

begin_comment
comment|//          by a client callee to log information. That information is given to
end_comment

begin_comment
comment|//          registered relevant mediums. The medium file is registered during
end_comment

begin_comment
comment|//          *this logs initialization so it will always have a file log for the
end_comment

begin_comment
comment|//          application.
end_comment

begin_comment
comment|//          Singleton class.
end_comment

begin_comment
comment|//--
end_comment

begin_decl_stmt
name|class
name|CMICmnLog
range|:
name|public
name|MI
operator|::
name|ISingleton
operator|<
name|CMICmnLog
operator|>
block|{
name|friend
name|MI
operator|::
name|ISingleton
operator|<
name|CMICmnLog
operator|>
block|;
comment|// Enumeration:
name|public
operator|:
comment|//++
comment|// Description: Data given to the Logger can be of several types. The Logger
comment|// can be
comment|//              set at levels of verbosity. Can determine how data is sent to
comment|//              one or
comment|//              mediums.
comment|//--
expr|enum
name|ELogVerbosity
block|{
comment|// Descriptions of what 'may' occur, depends ultimately
comment|// on the medium itself. See the medium.
name|eLogVerbosity_FnTrace
operator|=
literal|0x00000004
block|,
comment|// Debug function stack call tracing
name|eLogVerbosity_DbgOp
operator|=
literal|0x00000008
block|,
comment|// Send a string to the debugger for
comment|// display (not implemented)
name|eLogVerbosity_ClientMsg
operator|=
literal|0x00000010
block|,
comment|// A client using MI can insert
comment|// messages into the log (not
comment|// implemented)
name|eLogVerbosity_Log
operator|=
literal|0x00000020
comment|// Send to only the Log file.
block|}
block|;
comment|// Class:
name|public
operator|:
comment|//++
comment|// Description: Register a medium derived from this interface which will be
comment|//              called writing log trace data i.e. a file or a console.
comment|//              Medium objects registered are not owned by *this logger.
comment|//--
name|class
name|IMedium
block|{
name|public
operator|:
name|virtual
name|bool
name|Initialize
argument_list|()
operator|=
literal|0
block|;
name|virtual
specifier|const
name|CMIUtilString
operator|&
name|GetName
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|Write
argument_list|(
argument|const CMIUtilString&vData
argument_list|,
argument|const ELogVerbosity veType
argument_list|)
operator|=
literal|0
block|;
name|virtual
specifier|const
name|CMIUtilString
operator|&
name|GetError
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|Shutdown
argument_list|()
operator|=
literal|0
block|;
comment|// Not part of the interface, ignore
comment|// AD:  This virtual destructor seems to hit a bug in the stdlib
comment|//      where vector delete is incorrectly called.  Workaround is
comment|//      to comment this out while I investigate.
comment|/* dtor */
name|virtual
operator|~
name|IMedium
argument_list|()
block|{}
block|}
block|;
comment|// Statics:
name|public
operator|:
specifier|static
name|bool
name|WriteLog
argument_list|(
specifier|const
name|CMIUtilString
operator|&
name|vData
argument_list|)
block|;
comment|// Methods:
name|public
operator|:
name|bool
name|RegisterMedium
argument_list|(
specifier|const
name|IMedium
operator|&
name|vrMedium
argument_list|)
block|;
name|bool
name|UnregisterMedium
argument_list|(
specifier|const
name|IMedium
operator|&
name|vrMedium
argument_list|)
block|;
name|bool
name|Write
argument_list|(
argument|const CMIUtilString&vData
argument_list|,
argument|const ELogVerbosity veType
argument_list|)
block|;
name|bool
name|SetEnabled
argument_list|(
argument|const bool vbYes
argument_list|)
block|;
name|bool
name|GetEnabled
argument_list|()
specifier|const
block|;
comment|// MI common object handling - duplicate of CMICmnBase functions, necessary
comment|// for LINUX build
comment|// Done to stop locking on object construction init circular dependency.
specifier|const
name|CMIUtilString
operator|&
name|GetErrorDescription
argument_list|()
specifier|const
block|;
name|void
name|SetErrorDescription
argument_list|(
argument|const CMIUtilString&vrTxt
argument_list|)
specifier|const
block|;
name|void
name|ClrErrorDescription
argument_list|()
specifier|const
block|;
comment|// Overridden:
name|public
operator|:
comment|// From MI::ISingleton
name|bool
name|Initialize
argument_list|()
name|override
block|;
name|bool
name|Shutdown
argument_list|()
name|override
block|;
comment|// Methods:
name|private
operator|:
comment|/* ctor */
name|CMICmnLog
argument_list|()
block|;
comment|/* ctor */
name|CMICmnLog
argument_list|(
specifier|const
name|CMICmnLog
operator|&
argument_list|)
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|CMICmnLog
operator|&
operator|)
block|;
comment|// Overridden:
name|private
operator|:
comment|// From CMICmnBase
comment|/* dtor */
operator|~
name|CMICmnLog
argument_list|()
name|override
block|;
comment|// Typedef:
name|private
operator|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|IMedium
operator|*
operator|,
name|CMIUtilString
operator|>
name|MapMediumToName_t
expr_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|IMedium
operator|*
operator|,
name|CMIUtilString
operator|>
name|MapPairMediumToName_t
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
name|HaveMediumAlready
argument_list|(
specifier|const
name|IMedium
operator|&
name|vrMedium
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_function_decl
name|bool
name|UnregisterMediumAll
parameter_list|()
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
name|bool
name|m_bRecursiveDive
decl_stmt|;
end_decl_stmt

begin_comment
comment|// True = yes recursive, false = no
end_comment

begin_decl_stmt
name|MapMediumToName_t
name|m_mapMediumToName
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_bEnabled
decl_stmt|;
end_decl_stmt

begin_comment
comment|// True = Logger enabled for writing to mediums, false =
end_comment

begin_comment
comment|// medium not written to
end_comment

begin_decl_stmt
name|bool
name|m_bInitializingATM
decl_stmt|;
end_decl_stmt

begin_comment
comment|// True = Yes in process of initing *this logger,
end_comment

begin_comment
comment|// false = not initing
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MI common object handling - duplicate of CMICmnBase functions, necessary
end_comment

begin_comment
comment|// for LINUX build
end_comment

begin_decl_stmt
name|bool
name|m_bInitialized
decl_stmt|;
end_decl_stmt

begin_comment
comment|// True = yes successfully initialized, false = no yet or
end_comment

begin_comment
comment|// failed
end_comment

begin_decl_stmt
name|mutable
name|CMIUtilString
name|m_strMILastErrorDescription
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MIint
name|m_clientUsageRefCnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Count of client using *this object so not
end_comment

begin_comment
comment|// shutdown() object to early
end_comment

unit|};
end_unit

