begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- BreakpointID.h ------------------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_BreakpointID_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_BreakpointID_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|// class BreakpointID
comment|//----------------------------------------------------------------------
name|class
name|BreakpointID
block|{
name|public
label|:
name|BreakpointID
argument_list|(
argument|lldb::break_id_t bp_id = LLDB_INVALID_BREAK_ID
argument_list|,
argument|lldb::break_id_t loc_id = LLDB_INVALID_BREAK_ID
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|BreakpointID
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|break_id_t
name|GetBreakpointID
argument_list|()
specifier|const
block|{
return|return
name|m_break_id
return|;
block|}
name|lldb
operator|::
name|break_id_t
name|GetLocationID
argument_list|()
specifier|const
block|{
return|return
name|m_location_id
return|;
block|}
name|void
name|SetID
argument_list|(
name|lldb
operator|::
name|break_id_t
name|bp_id
argument_list|,
name|lldb
operator|::
name|break_id_t
name|loc_id
argument_list|)
block|{
name|m_break_id
operator|=
name|bp_id
expr_stmt|;
name|m_location_id
operator|=
name|loc_id
expr_stmt|;
block|}
name|void
name|SetBreakpointID
argument_list|(
name|lldb
operator|::
name|break_id_t
name|bp_id
argument_list|)
block|{
name|m_break_id
operator|=
name|bp_id
expr_stmt|;
block|}
name|void
name|SetBreakpointLocationID
argument_list|(
name|lldb
operator|::
name|break_id_t
name|loc_id
argument_list|)
block|{
name|m_location_id
operator|=
name|loc_id
expr_stmt|;
block|}
name|void
name|GetDescription
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|lldb
operator|::
name|DescriptionLevel
name|level
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|IsRangeIdentifier
argument_list|(
name|llvm
operator|::
name|StringRef
name|str
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|IsValidIDExpression
argument_list|(
name|llvm
operator|::
name|StringRef
name|str
argument_list|)
decl_stmt|;
specifier|static
name|llvm
operator|::
name|ArrayRef
operator|<
name|llvm
operator|::
name|StringRef
operator|>
name|GetRangeSpecifiers
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Takes an input string containing the description of a breakpoint or
comment|/// breakpoint and location and returns the a BreakpointID filled out with
comment|/// the proper id and location.
comment|///
comment|/// @param[in] input
comment|///     A string containing JUST the breakpoint description.
comment|/// @return
comment|///     If \p input was not a valid breakpoint ID string, returns
comment|///     \b llvm::None.  Otherwise returns a BreakpointID with members filled
comment|///     out accordingly.
comment|//------------------------------------------------------------------
specifier|static
name|llvm
operator|::
name|Optional
operator|<
name|BreakpointID
operator|>
name|ParseCanonicalReference
argument_list|(
argument|llvm::StringRef input
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Takes an input string and checks to see whether it is a breakpoint name.
comment|/// If it is a mal-formed breakpoint name, error will be set to an appropriate
comment|/// error string.
comment|///
comment|/// @param[in] input
comment|///     A string containing JUST the breakpoint description.
comment|/// @param[out] error
comment|///     If the name is a well-formed breakpoint name, set to success,
comment|///     otherwise set to an error.
comment|/// @return
comment|///     \b true if the name is a breakpoint name (as opposed to an ID or
comment|///     range) false otherwise.
comment|//------------------------------------------------------------------
specifier|static
name|bool
name|StringIsBreakpointName
argument_list|(
name|llvm
operator|::
name|StringRef
name|str
argument_list|,
name|Status
operator|&
name|error
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Takes a breakpoint ID and the breakpoint location id and returns
comment|/// a string containing the canonical description for the breakpoint
comment|/// or breakpoint location.
comment|///
comment|/// @param[out] break_id
comment|///     This is the break id.
comment|///
comment|/// @param[out] break_loc_id
comment|///     This is breakpoint location id, or LLDB_INVALID_BREAK_ID is no
comment|///     location is to be specified.
comment|//------------------------------------------------------------------
specifier|static
name|void
name|GetCanonicalReference
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|lldb
operator|::
name|break_id_t
name|break_id
argument_list|,
name|lldb
operator|::
name|break_id_t
name|break_loc_id
argument_list|)
decl_stmt|;
name|protected
label|:
name|lldb
operator|::
name|break_id_t
name|m_break_id
expr_stmt|;
name|lldb
operator|::
name|break_id_t
name|m_location_id
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_BreakpointID_h_
end_comment

end_unit

