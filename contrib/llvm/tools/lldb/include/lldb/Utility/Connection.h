begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Connection.h --------------------------------------------*- C++ -*-===//
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
name|liblldb_Connection_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Connection_h_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_comment
comment|// for DISALLOW_COPY_AND_ASSIGN
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_comment
comment|// for ConnectionStatus
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_comment
comment|// for IOObjectSP
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_comment
comment|// for StringRef
end_comment

begin_include
include|#
directive|include
file|<ratio>
end_include

begin_comment
comment|// for micro
end_comment

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|// for size_t
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Status
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|template
operator|<
name|typename
name|Ratio
operator|>
name|class
name|Timeout
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class Connection Connection.h "lldb/Utility/Connection.h"
comment|/// @brief A communication connection class.
comment|///
comment|/// A class that implements that actual communication functions for
comment|/// connecting/disconnecting, reading/writing, and waiting for bytes
comment|/// to become available from a two way communication connection.
comment|///
comment|/// This class is designed to only do very simple communication
comment|/// functions. Instances can be instantiated and given to a
comment|/// Communication class to perform communications where clients can
comment|/// listen for broadcasts, and perform other higher level communications.
comment|//----------------------------------------------------------------------
name|class
name|Connection
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Default constructor
comment|//------------------------------------------------------------------
name|Connection
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Virtual destructor since this class gets subclassed and handed
comment|/// to a Communication object.
comment|//------------------------------------------------------------------
name|virtual
operator|~
name|Connection
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Connect using the connect string \a url.
comment|///
comment|/// @param[in] url
comment|///     A string that contains all information needed by the
comment|///     subclass to connect to another client.
comment|///
comment|/// @param[out] error_ptr
comment|///     A pointer to an error object that should be given an
comment|///     appropriate error value if this method returns false. This
comment|///     value can be NULL if the error value should be ignored.
comment|///
comment|/// @return
comment|///     \b True if the connect succeeded, \b false otherwise. The
comment|///     internal error object should be filled in with an
comment|///     appropriate value based on the result of this function.
comment|///
comment|/// @see Status& Communication::GetError ();
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|ConnectionStatus
name|Connect
argument_list|(
argument|llvm::StringRef url
argument_list|,
argument|Status *error_ptr
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Disconnect the communications connection if one is currently
comment|/// connected.
comment|///
comment|/// @param[out] error_ptr
comment|///     A pointer to an error object that should be given an
comment|///     appropriate error value if this method returns false. This
comment|///     value can be NULL if the error value should be ignored.
comment|///
comment|/// @return
comment|///     \b True if the disconnect succeeded, \b false otherwise. The
comment|///     internal error object should be filled in with an
comment|///     appropriate value based on the result of this function.
comment|///
comment|/// @see Status& Communication::GetError ();
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|ConnectionStatus
name|Disconnect
argument_list|(
name|Status
operator|*
name|error_ptr
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Check if the connection is valid.
comment|///
comment|/// @return
comment|///     \b True if this object is currently connected, \b false
comment|///     otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|IsConnected
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// The read function that attempts to read from the connection.
comment|///
comment|/// @param[in] dst
comment|///     A destination buffer that must be at least \a dst_len bytes
comment|///     long.
comment|///
comment|/// @param[in] dst_len
comment|///     The number of bytes to attempt to read, and also the max
comment|///     number of bytes that can be placed into \a dst.
comment|///
comment|/// @param[in] timeout
comment|///     The number of microseconds to wait for the data.
comment|///
comment|/// @param[out] status
comment|///     On return, indicates whether the call was successful or terminated
comment|///     due to some error condition.
comment|///
comment|/// @param[out] error_ptr
comment|///     A pointer to an error object that should be given an
comment|///     appropriate error value if this method returns zero. This
comment|///     value can be NULL if the error value should be ignored.
comment|///
comment|/// @return
comment|///     The number of bytes actually read.
comment|///
comment|/// @see size_t Communication::Read (void *, size_t, uint32_t);
comment|//------------------------------------------------------------------
name|virtual
name|size_t
name|Read
argument_list|(
name|void
operator|*
name|dst
argument_list|,
name|size_t
name|dst_len
argument_list|,
specifier|const
name|Timeout
operator|<
name|std
operator|::
name|micro
operator|>
operator|&
name|timeout
argument_list|,
name|lldb
operator|::
name|ConnectionStatus
operator|&
name|status
argument_list|,
name|Status
operator|*
name|error_ptr
argument_list|)
init|=
literal|0
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// The actual write function that attempts to write to the
comment|/// communications protocol.
comment|///
comment|/// Subclasses must override this function.
comment|///
comment|/// @param[in] dst
comment|///     A desination buffer that must be at least \a dst_len bytes
comment|///     long.
comment|///
comment|/// @param[in] dst_len
comment|///     The number of bytes to attempt to write, and also the
comment|///     number of bytes are currently available in \a dst.
comment|///
comment|/// @param[out] error_ptr
comment|///     A pointer to an error object that should be given an
comment|///     appropriate error value if this method returns zero. This
comment|///     value can be NULL if the error value should be ignored.
comment|///
comment|/// @return
comment|///     The number of bytes actually Written.
comment|//------------------------------------------------------------------
name|virtual
name|size_t
name|Write
argument_list|(
specifier|const
name|void
operator|*
name|dst
argument_list|,
name|size_t
name|dst_len
argument_list|,
name|lldb
operator|::
name|ConnectionStatus
operator|&
name|status
argument_list|,
name|Status
operator|*
name|error_ptr
argument_list|)
init|=
literal|0
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Returns a URI that describes this connection object
comment|///
comment|/// Subclasses may override this function.
comment|///
comment|/// @return
comment|///     Returns URI or an empty string if disconnecteds
comment|//------------------------------------------------------------------
name|virtual
name|std
operator|::
name|string
name|GetURI
argument_list|()
operator|=
literal|0
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Interrupts an ongoing Read() operation.
comment|///
comment|/// If there is an ongoing read operation in another thread, this operation
comment|/// return with status == eConnectionStatusInterrupted. Note that if there
comment|/// data waiting to be read and an interrupt request is issued, the Read()
comment|/// function will return the data immediately without processing the
comment|/// interrupt request (which will remain queued for the next Read()
comment|/// operation).
comment|///
comment|/// @return
comment|///     Returns true is the interrupt request was successful.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|InterruptRead
parameter_list|()
init|=
literal|0
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Returns the underlying IOObject used by the Connection.
comment|///
comment|/// The IOObject can be used to wait for data to become available
comment|/// on the connection. If the Connection does not use IOObjects (and
comment|/// hence does not support waiting) this function should return a
comment|/// null pointer.
comment|///
comment|/// @return
comment|///     The underlying IOObject used for reading.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|IOObjectSP
name|GetReadObject
argument_list|()
block|{
return|return
name|lldb
operator|::
name|IOObjectSP
argument_list|()
return|;
block|}
name|private
label|:
comment|//------------------------------------------------------------------
comment|// For Connection only
comment|//------------------------------------------------------------------
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Connection
argument_list|)
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
comment|// liblldb_Connection_h_
end_comment

end_unit

