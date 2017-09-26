begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- UserID.h ------------------------------------------------*- C++ -*-===//
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
name|liblldb_UserID_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_UserID_h_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_comment
comment|// for LLDB_INVALID_UID
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_comment
comment|// for user_id_t
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Stream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class UserID UserID.h "lldb/Core/UserID.h"
comment|/// @brief A mix in class that contains a generic user ID.
comment|///
comment|/// UserID is designed as a mix in class that can contain an integer
comment|/// based unique identifier for a variety of objects in lldb.
comment|///
comment|/// The value for this identifier is chosen by each parser plug-in. A
comment|/// value should be chosen that makes sense for each kind of object
comment|/// and should allow quick access to further and more in depth parsing.
comment|///
comment|/// Symbol table entries can use this to store the original symbol table
comment|/// index, functions can use it to store the symbol table index or the
comment|/// DWARF offset.
comment|//----------------------------------------------------------------------
struct|struct
name|UserID
block|{
comment|//------------------------------------------------------------------
comment|/// Construct with optional user ID.
comment|//------------------------------------------------------------------
name|UserID
argument_list|(
argument|lldb::user_id_t uid = LLDB_INVALID_UID
argument_list|)
block|:
name|m_uid
argument_list|(
argument|uid
argument_list|)
block|{}
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|//------------------------------------------------------------------
operator|~
name|UserID
argument_list|()
block|{}
comment|//------------------------------------------------------------------
comment|/// Clears the object state.
comment|///
comment|/// Clears the object contents back to a default invalid state.
comment|//------------------------------------------------------------------
name|void
name|Clear
argument_list|()
block|{
name|m_uid
operator|=
name|LLDB_INVALID_UID
block|; }
comment|//------------------------------------------------------------------
comment|/// Get accessor for the user ID.
comment|///
comment|/// @return
comment|///     The user ID.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|user_id_t
name|GetID
argument_list|()
specifier|const
block|{
return|return
name|m_uid
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Set accessor for the user ID.
comment|///
comment|/// @param[in] uid
comment|///     The new user ID.
comment|//------------------------------------------------------------------
name|void
name|SetID
argument_list|(
name|lldb
operator|::
name|user_id_t
name|uid
argument_list|)
block|{
name|m_uid
operator|=
name|uid
expr_stmt|;
block|}
comment|//------------------------------------------------------------------
comment|/// Unary predicate function object that can search for a matching
comment|/// user ID.
comment|///
comment|/// Function object that can be used on any class that inherits
comment|/// from UserID:
comment|/// \code
comment|/// iterator pos;
comment|/// pos = std::find_if (coll.begin(), coll.end(), UserID::IDMatches(blockID));
comment|/// \endcode
comment|//------------------------------------------------------------------
name|class
name|IDMatches
block|{
name|public
label|:
comment|//--------------------------------------------------------------
comment|/// Construct with the user ID to look for.
comment|//--------------------------------------------------------------
name|IDMatches
argument_list|(
argument|lldb::user_id_t uid
argument_list|)
block|:
name|m_uid
argument_list|(
argument|uid
argument_list|)
block|{}
comment|//--------------------------------------------------------------
comment|/// Unary predicate function object callback.
comment|//--------------------------------------------------------------
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|UserID
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
name|m_uid
operator|==
name|rhs
operator|.
name|GetID
argument_list|()
return|;
block|}
name|private
label|:
comment|//--------------------------------------------------------------
comment|// Member variables.
comment|//--------------------------------------------------------------
specifier|const
name|lldb
operator|::
name|user_id_t
name|m_uid
expr_stmt|;
comment|///< The user ID we are looking for
block|}
empty_stmt|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Member variables.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|user_id_t
name|m_uid
expr_stmt|;
comment|///< The user ID that uniquely identifies an object.
block|}
struct|;
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|UserID
operator|&
name|lhs
operator|,
specifier|const
name|UserID
operator|&
name|rhs
operator|)
block|{
return|return
name|lhs
operator|.
name|GetID
argument_list|()
operator|==
name|rhs
operator|.
name|GetID
argument_list|()
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|UserID
operator|&
name|lhs
operator|,
specifier|const
name|UserID
operator|&
name|rhs
operator|)
block|{
return|return
name|lhs
operator|.
name|GetID
argument_list|()
operator|!=
name|rhs
operator|.
name|GetID
argument_list|()
return|;
block|}
comment|//--------------------------------------------------------------
comment|/// Stream the UserID object to a Stream.
comment|//--------------------------------------------------------------
name|Stream
operator|&
name|operator
operator|<<
operator|(
name|Stream
operator|&
name|strm
operator|,
specifier|const
name|UserID
operator|&
name|uid
operator|)
expr_stmt|;
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
comment|// liblldb_UserID_h_
end_comment

end_unit

