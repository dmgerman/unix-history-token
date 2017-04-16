begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Communication.h -----------------------------------------*- C++ -*-===//
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
name|liblldb_Communication_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Communication_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/Broadcaster.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/HostThread.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Timeout.h"
end_include

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
comment|// for ConnectionStatus, FLAGS_ANONYMOU...
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_comment
comment|// for ConnectionSP
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_comment
comment|// for thread_arg_t, thread_result_t
end_comment

begin_include
include|#
directive|include
file|<atomic>
end_include

begin_include
include|#
directive|include
file|<mutex>
end_include

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

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// for uint8_t
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Connection
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ConstString
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Error
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class Communication Communication.h "lldb/Core/Communication.h"
comment|/// @brief An abstract communications class.
comment|///
comment|/// Communication is an class that handles data communication
comment|/// between two data sources. It uses a Connection class to do the
comment|/// real communication. This approach has a couple of advantages: it
comment|/// allows a single instance of this class to be used even though its
comment|/// connection can change. Connections could negotiate for different
comment|/// connections based on abilities like starting with Bluetooth and
comment|/// negotiating up to WiFi if available. It also allows this class to be
comment|/// subclassed by any interfaces that don't want to give bytes but want
comment|/// to validate and give out packets. This can be done by overriding:
comment|///
comment|/// AppendBytesToCache (const uint8_t *src, size_t src_len, bool broadcast);
comment|///
comment|/// Communication inherits from Broadcaster which means it can be
comment|/// used in conjunction with Listener to wait for multiple broadcaster
comment|/// objects and multiple events from each of those objects.
comment|/// Communication defines a set of pre-defined event bits (see
comment|/// enumerations definitions that start with "eBroadcastBit" below).
comment|///
comment|/// There are two modes in which communications can occur:
comment|///     @li single-threaded
comment|///     @li multi-threaded
comment|///
comment|/// In single-threaded mode, all reads and writes happen synchronously
comment|/// on the calling thread.
comment|///
comment|/// In multi-threaded mode, a read thread is spawned that continually
comment|/// reads data and caches any received bytes. To start the read thread
comment|/// clients call:
comment|///
comment|///     bool Communication::StartReadThread (Error *);
comment|///
comment|/// If true is returned a read thread has been spawned that will
comment|/// continually execute a call to the pure virtual DoRead function:
comment|///
comment|///     size_t Communication::ReadFromConnection (void *, size_t, uint32_t);
comment|///
comment|/// When bytes are received the data gets cached in \a m_bytes and this
comment|/// class will broadcast a \b eBroadcastBitReadThreadGotBytes event.
comment|/// Clients that want packet based communication should override
comment|/// AppendBytesToCache. The subclasses can choose to call the
comment|/// built in AppendBytesToCache with the \a broadcast parameter set to
comment|/// false. This will cause the \b eBroadcastBitReadThreadGotBytes event
comment|/// not get broadcast, and then the subclass can post a \b
comment|/// eBroadcastBitPacketAvailable event when a full packet of data has
comment|/// been received.
comment|///
comment|/// If the connection is disconnected a \b eBroadcastBitDisconnected
comment|/// event gets broadcast. If the read thread exits a \b
comment|/// eBroadcastBitReadThreadDidExit event will be broadcast. Clients
comment|/// can also post a \b eBroadcastBitReadThreadShouldExit event to this
comment|/// object which will cause the read thread to exit.
comment|//----------------------------------------------------------------------
name|class
name|Communication
range|:
name|public
name|Broadcaster
block|{
name|public
operator|:
name|FLAGS_ANONYMOUS_ENUM
argument_list|()
block|{
name|eBroadcastBitDisconnected
operator|=
operator|(
literal|1u
operator|<<
literal|0
operator|)
block|,
comment|///< Sent when the communications connection is lost.
name|eBroadcastBitReadThreadGotBytes
operator|=
operator|(
literal|1u
operator|<<
literal|1
operator|)
block|,
comment|///< Sent by the read thread when bytes become available.
name|eBroadcastBitReadThreadDidExit
operator|=
operator|(
literal|1u
operator|<<
literal|2
operator|)
block|,
comment|///< Sent by the read thread when it exits to inform clients.
name|eBroadcastBitReadThreadShouldExit
operator|=
operator|(
literal|1u
operator|<<
literal|3
operator|)
block|,
comment|///< Sent by clients that need to cancel the read thread.
name|eBroadcastBitPacketAvailable
operator|=
operator|(
literal|1u
operator|<<
literal|4
operator|)
block|,
comment|///< Sent when data received makes a complete packet.
name|eBroadcastBitNoMorePendingInput
operator|=
operator|(
literal|1u
operator|<<
literal|5
operator|)
block|,
comment|///< Sent by the read thread
comment|///to indicate all pending
comment|///input has been processed.
name|kLoUserBroadcastBit
operator|=
operator|(
literal|1u
operator|<<
literal|16
operator|)
block|,
comment|///< Subclasses can used bits 31:16 for any needed events.
name|kHiUserBroadcastBit
operator|=
operator|(
literal|1u
operator|<<
literal|31
operator|)
block|,
name|eAllEventBits
operator|=
literal|0xffffffff
block|}
block|;
typedef|typedef
name|void
function_decl|(
modifier|*
name|ReadThreadBytesReceived
function_decl|)
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|size_t
name|src_len
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Construct the Communication object with the specified name for
comment|/// the Broadcaster that this object inherits from.
comment|///
comment|/// @param[in] broadcaster_name
comment|///     The name of the broadcaster object.  This name should be as
comment|///     complete as possible to uniquely identify this object. The
comment|///     broadcaster name can be updated after the connect function
comment|///     is called.
comment|//------------------------------------------------------------------
name|Communication
argument_list|(
specifier|const
name|char
operator|*
name|broadcaster_name
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|///
comment|/// The destructor is virtual since this class gets subclassed.
comment|//------------------------------------------------------------------
operator|~
name|Communication
argument_list|()
name|override
expr_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Connect using the current connection by passing \a url to its
comment|/// connect function.
comment|/// string.
comment|///
comment|/// @param[in] url
comment|///     A string that contains all information needed by the
comment|///     subclass to connect to another client.
comment|///
comment|/// @return
comment|///     \b True if the connect succeeded, \b false otherwise. The
comment|///     internal error object should be filled in with an
comment|///     appropriate value based on the result of this function.
comment|///
comment|/// @see Error& Communication::GetError ();
comment|/// @see bool Connection::Connect (const char *url);
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ConnectionStatus
name|Connect
argument_list|(
specifier|const
name|char
operator|*
name|url
argument_list|,
name|Error
operator|*
name|error_ptr
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Disconnect the communications connection if one is currently
comment|/// connected.
comment|///
comment|/// @return
comment|///     \b True if the disconnect succeeded, \b false otherwise. The
comment|///     internal error object should be filled in with an
comment|///     appropriate value based on the result of this function.
comment|///
comment|/// @see Error& Communication::GetError ();
comment|/// @see bool Connection::Disconnect ();
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ConnectionStatus
name|Disconnect
argument_list|(
name|Error
operator|*
name|error_ptr
operator|=
name|nullptr
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Check if the connection is valid.
comment|///
comment|/// @return
comment|///     \b True if this object is currently connected, \b false
comment|///     otherwise.
comment|//------------------------------------------------------------------
name|bool
name|IsConnected
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|HasConnection
argument_list|()
specifier|const
expr_stmt|;
name|lldb_private
operator|::
name|Connection
operator|*
name|GetConnection
argument_list|()
block|{
return|return
name|m_connection_sp
operator|.
name|get
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Read bytes from the current connection.
comment|///
comment|/// If no read thread is running, this function call the
comment|/// connection's Connection::Read(...) function to get any available.
comment|///
comment|/// If a read thread has been started, this function will check for
comment|/// any cached bytes that have already been read and return any
comment|/// currently available bytes. If no bytes are cached, it will wait
comment|/// for the bytes to become available by listening for the \a
comment|/// eBroadcastBitReadThreadGotBytes event. If this function consumes
comment|/// all of the bytes in the cache, it will reset the
comment|/// \a eBroadcastBitReadThreadGotBytes event bit.
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
comment|///     A timeout value or llvm::None for no timeout.
comment|///
comment|/// @return
comment|///     The number of bytes actually read.
comment|///
comment|/// @see size_t Connection::Read (void *, size_t);
comment|//------------------------------------------------------------------
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
name|Error
operator|*
name|error_ptr
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// The actual write function that attempts to write to the
comment|/// communications protocol.
comment|///
comment|/// Subclasses must override this function.
comment|///
comment|/// @param[in] src
comment|///     A source buffer that must be at least \a src_len bytes
comment|///     long.
comment|///
comment|/// @param[in] src_len
comment|///     The number of bytes to attempt to write, and also the
comment|///     number of bytes are currently available in \a src.
comment|///
comment|/// @return
comment|///     The number of bytes actually Written.
comment|//------------------------------------------------------------------
name|size_t
name|Write
argument_list|(
specifier|const
name|void
operator|*
name|src
argument_list|,
name|size_t
name|src_len
argument_list|,
name|lldb
operator|::
name|ConnectionStatus
operator|&
name|status
argument_list|,
name|Error
operator|*
name|error_ptr
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Sets the connection that it to be used by this class.
comment|///
comment|/// By making a communication class that uses different connections
comment|/// it allows a single communication interface to negotiate and
comment|/// change its connection without any interruption to the client.
comment|/// It also allows the Communication class to be subclassed for
comment|/// packet based communication.
comment|///
comment|/// @param[in] connection
comment|///     A connection that this class will own and destroy.
comment|///
comment|/// @see
comment|///     class Connection
comment|//------------------------------------------------------------------
name|void
name|SetConnection
parameter_list|(
name|Connection
modifier|*
name|connection
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Starts a read thread whose sole purpose it to read bytes from
comment|/// the current connection. This function will call connection's
comment|/// read function:
comment|///
comment|/// size_t Connection::Read (void *, size_t);
comment|///
comment|/// When bytes are read and cached, this function will call:
comment|///
comment|/// Communication::AppendBytesToCache (const uint8_t * bytes, size_t len, bool
comment|/// broadcast);
comment|///
comment|/// Subclasses should override this function if they wish to override
comment|/// the default action of caching the bytes and broadcasting a \b
comment|/// eBroadcastBitReadThreadGotBytes event.
comment|///
comment|/// @return
comment|///     \b True if the read thread was successfully started, \b
comment|///     false otherwise.
comment|///
comment|/// @see size_t Connection::Read (void *, size_t);
comment|/// @see void Communication::AppendBytesToCache (const uint8_t * bytes, size_t
comment|/// len, bool broadcast);
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|StartReadThread
parameter_list|(
name|Error
modifier|*
name|error_ptr
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Stops the read thread by cancelling it.
comment|///
comment|/// @return
comment|///     \b True if the read thread was successfully canceled, \b
comment|///     false otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|StopReadThread
parameter_list|(
name|Error
modifier|*
name|error_ptr
init|=
name|nullptr
parameter_list|)
function_decl|;
name|virtual
name|bool
name|JoinReadThread
parameter_list|(
name|Error
modifier|*
name|error_ptr
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Checks if there is a currently running read thread.
comment|///
comment|/// @return
comment|///     \b True if the read thread is running, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|ReadThreadIsRunning
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// The static read thread function. This function will call
comment|/// the "DoRead" function continuously and wait for data to become
comment|/// available. When data is received it will append the available
comment|/// data to the internal cache and broadcast a
comment|/// \b eBroadcastBitReadThreadGotBytes event.
comment|///
comment|/// @param[in] comm_ptr
comment|///     A pointer to an instance of this class.
comment|///
comment|/// @return
comment|///     \b NULL.
comment|///
comment|/// @see void Communication::ReadThreadGotBytes (const uint8_t *, size_t);
comment|//------------------------------------------------------------------
specifier|static
name|lldb
operator|::
name|thread_result_t
name|ReadThread
argument_list|(
argument|lldb::thread_arg_t comm_ptr
argument_list|)
expr_stmt|;
name|void
name|SetReadThreadBytesReceivedCallback
parameter_list|(
name|ReadThreadBytesReceived
name|callback
parameter_list|,
name|void
modifier|*
name|callback_baton
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Wait for the read thread to process all outstanding data.
comment|///
comment|/// After this function returns, the read thread has processed all data that
comment|/// has been waiting in the Connection queue.
comment|///
comment|//------------------------------------------------------------------
name|void
name|SynchronizeWithReadThread
parameter_list|()
function_decl|;
specifier|static
specifier|const
name|char
modifier|*
name|ConnectionStatusAsCString
argument_list|(
name|lldb
operator|::
name|ConnectionStatus
name|status
argument_list|)
decl_stmt|;
name|bool
name|GetCloseOnEOF
argument_list|()
specifier|const
block|{
return|return
name|m_close_on_eof
return|;
block|}
name|void
name|SetCloseOnEOF
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|m_close_on_eof
operator|=
name|b
expr_stmt|;
block|}
specifier|static
name|ConstString
modifier|&
name|GetStaticBroadcasterClass
parameter_list|()
function_decl|;
name|ConstString
operator|&
name|GetBroadcasterClass
argument_list|()
specifier|const
name|override
block|{
return|return
name|GetStaticBroadcasterClass
argument_list|()
return|;
block|}
name|protected
label|:
name|lldb
operator|::
name|ConnectionSP
name|m_connection_sp
expr_stmt|;
comment|///< The connection that is current in use
comment|///by this communications class.
name|HostThread
name|m_read_thread
decl_stmt|;
comment|///< The read thread handle in case we need to
comment|///cancel the thread.
name|std
operator|::
name|atomic
operator|<
name|bool
operator|>
name|m_read_thread_enabled
expr_stmt|;
name|std
operator|::
name|atomic
operator|<
name|bool
operator|>
name|m_read_thread_did_exit
expr_stmt|;
name|std
operator|::
name|string
name|m_bytes
expr_stmt|;
comment|///< A buffer to cache bytes read in the ReadThread function.
name|std
operator|::
name|recursive_mutex
name|m_bytes_mutex
expr_stmt|;
comment|///< A mutex to protect multi-threaded
comment|///access to the cached bytes.
name|std
operator|::
name|mutex
name|m_write_mutex
expr_stmt|;
comment|///< Don't let multiple threads write at the same time...
name|std
operator|::
name|mutex
name|m_synchronize_mutex
expr_stmt|;
name|ReadThreadBytesReceived
name|m_callback
decl_stmt|;
name|void
modifier|*
name|m_callback_baton
decl_stmt|;
name|bool
name|m_close_on_eof
decl_stmt|;
name|size_t
name|ReadFromConnection
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
name|Error
operator|*
name|error_ptr
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Append new bytes that get read from the read thread into the
comment|/// internal object byte cache. This will cause a \b
comment|/// eBroadcastBitReadThreadGotBytes event to be broadcast if \a
comment|/// broadcast is true.
comment|///
comment|/// Subclasses can override this function in order to inspect the
comment|/// received data and check if a packet is available.
comment|///
comment|/// Subclasses can also still call this function from the
comment|/// overridden method to allow the caching to correctly happen and
comment|/// suppress the broadcasting of the \a eBroadcastBitReadThreadGotBytes
comment|/// event by setting \a broadcast to false.
comment|///
comment|/// @param[in] src
comment|///     A source buffer that must be at least \a src_len bytes
comment|///     long.
comment|///
comment|/// @param[in] src_len
comment|///     The number of bytes to append to the cache.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|AppendBytesToCache
argument_list|(
specifier|const
name|uint8_t
operator|*
name|src
argument_list|,
name|size_t
name|src_len
argument_list|,
name|bool
name|broadcast
argument_list|,
name|lldb
operator|::
name|ConnectionStatus
name|status
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get any available bytes from our data cache. If this call
comment|/// empties the data cache, the \b eBroadcastBitReadThreadGotBytes event
comment|/// will be reset to signify no more bytes are available.
comment|///
comment|/// @param[in] dst
comment|///     A destination buffer that must be at least \a dst_len bytes
comment|///     long.
comment|///
comment|/// @param[in] dst_len
comment|///     The number of bytes to attempt to read from the cache,
comment|///     and also the max number of bytes that can be placed into
comment|///     \a dst.
comment|///
comment|/// @return
comment|///     The number of bytes extracted from the data cache.
comment|//------------------------------------------------------------------
name|size_t
name|GetCachedBytes
parameter_list|(
name|void
modifier|*
name|dst
parameter_list|,
name|size_t
name|dst_len
parameter_list|)
function_decl|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Communication
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_Communication_h_
end_comment

end_unit

