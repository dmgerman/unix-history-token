begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  * Interface for the packet protocol functions.  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_comment
comment|/* RCSID("$OpenBSD: packet.h,v 1.22 2001/04/14 16:33:20 stevesk Exp $"); */
end_comment

begin_comment
comment|/* RCSID("$FreeBSD$"); */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PACKET_H
end_ifndef

begin_define
define|#
directive|define
name|PACKET_H
end_define

begin_include
include|#
directive|include
file|<openssl/bn.h>
end_include

begin_comment
comment|/*  * Sets the socket used for communication.  Disables encryption until  * packet_set_encryption_key is called.  It is permissible that fd_in and  * fd_out are the same descriptor; in that case it is assumed to be a socket.  */
end_comment

begin_function_decl
name|void
name|packet_set_connection
parameter_list|(
name|int
name|fd_in
parameter_list|,
name|int
name|fd_out
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Puts the connection file descriptors into non-blocking mode. */
end_comment

begin_function_decl
name|void
name|packet_set_nonblocking
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns the file descriptor used for input. */
end_comment

begin_function_decl
name|int
name|packet_get_connection_in
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns the file descriptor used for output. */
end_comment

begin_function_decl
name|int
name|packet_get_connection_out
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Closes the connection (both descriptors) and clears and frees internal  * data structures.  */
end_comment

begin_function_decl
name|void
name|packet_close
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Causes any further packets to be encrypted using the given key.  The same  * key is used for both sending and reception.  However, both directions are  * encrypted independently of each other.  Cipher types are defined in ssh.h.  */
end_comment

begin_function_decl
name|void
name|packet_set_encryption_key
parameter_list|(
specifier|const
name|u_char
modifier|*
name|key
parameter_list|,
name|u_int
name|keylen
parameter_list|,
name|int
name|cipher_type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Sets remote side protocol flags for the current connection.  This can be  * called at any time.  */
end_comment

begin_function_decl
name|void
name|packet_set_protocol_flags
parameter_list|(
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns the remote protocol flags set earlier by the above function. */
end_comment

begin_function_decl
name|u_int
name|packet_get_protocol_flags
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Enables compression in both directions starting from the next packet. */
end_comment

begin_function_decl
name|void
name|packet_start_compression
parameter_list|(
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Informs that the current session is interactive.  Sets IP flags for  * optimal performance in interactive use.  */
end_comment

begin_function_decl
name|void
name|packet_set_interactive
parameter_list|(
name|int
name|interactive
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns true if the current connection is interactive. */
end_comment

begin_function_decl
name|int
name|packet_is_interactive
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Starts constructing a packet to send. */
end_comment

begin_function_decl
name|void
name|packet_start
parameter_list|(
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Appends a character to the packet data. */
end_comment

begin_function_decl
name|void
name|packet_put_char
parameter_list|(
name|int
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Appends an integer to the packet data. */
end_comment

begin_function_decl
name|void
name|packet_put_int
parameter_list|(
name|u_int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Appends an arbitrary precision integer to packet data. */
end_comment

begin_function_decl
name|void
name|packet_put_bignum
parameter_list|(
name|BIGNUM
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|packet_put_bignum2
parameter_list|(
name|BIGNUM
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Appends a string to packet data. */
end_comment

begin_function_decl
name|void
name|packet_put_string
parameter_list|(
specifier|const
name|char
modifier|*
name|buf
parameter_list|,
name|u_int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|packet_put_cstring
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|packet_put_raw
parameter_list|(
specifier|const
name|char
modifier|*
name|buf
parameter_list|,
name|u_int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Finalizes and sends the packet.  If the encryption key has been set,  * encrypts the packet before sending.  */
end_comment

begin_function_decl
name|void
name|packet_send
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Waits until a packet has been received, and returns its type. */
end_comment

begin_function_decl
name|int
name|packet_read
parameter_list|(
name|int
modifier|*
name|payload_len_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Waits until a packet has been received, verifies that its type matches  * that given, and gives a fatal error and exits if there is a mismatch.  */
end_comment

begin_function_decl
name|void
name|packet_read_expect
parameter_list|(
name|int
modifier|*
name|payload_len_ptr
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Checks if a full packet is available in the data received so far via  * packet_process_incoming.  If so, reads the packet; otherwise returns  * SSH_MSG_NONE.  This does not wait for data from the connection.  * SSH_MSG_DISCONNECT is handled specially here.  Also, SSH_MSG_IGNORE  * messages are skipped by this function and are never returned to higher  * levels.  */
end_comment

begin_function_decl
name|int
name|packet_read_poll
parameter_list|(
name|int
modifier|*
name|packet_len_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Buffers the given amount of input characters.  This is intended to be used  * together with packet_read_poll.  */
end_comment

begin_function_decl
name|void
name|packet_process_incoming
parameter_list|(
specifier|const
name|char
modifier|*
name|buf
parameter_list|,
name|u_int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns a character (0-255) from the packet data. */
end_comment

begin_function_decl
name|u_int
name|packet_get_char
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns an integer from the packet data. */
end_comment

begin_function_decl
name|u_int
name|packet_get_int
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns an arbitrary precision integer from the packet data.  The integer  * must have been initialized before this call.  */
end_comment

begin_function_decl
name|void
name|packet_get_bignum
parameter_list|(
name|BIGNUM
modifier|*
name|value
parameter_list|,
name|int
modifier|*
name|length_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|packet_get_bignum2
parameter_list|(
name|BIGNUM
modifier|*
name|value
parameter_list|,
name|int
modifier|*
name|length_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|packet_get_raw
parameter_list|(
name|int
modifier|*
name|length_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns a string from the packet data.  The string is allocated using  * xmalloc; it is the responsibility of the calling program to free it when  * no longer needed.  The length_ptr argument may be NULL, or point to an  * integer into which the length of the string is stored.  */
end_comment

begin_function_decl
name|char
modifier|*
name|packet_get_string
parameter_list|(
name|u_int
modifier|*
name|length_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Logs the error in syslog using LOG_INFO, constructs and sends a disconnect  * packet, closes the connection, and exits.  This function never returns.  * The error message should not contain a newline.  The total length of the  * message must not exceed 1024 bytes.  */
end_comment

begin_function_decl
name|void
name|packet_disconnect
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * Sends a diagnostic message to the other side.  This message can be sent at  * any time (but not while constructing another message). The message is  * printed immediately, but only if the client is being executed in verbose  * mode.  These messages are primarily intended to ease debugging  * authentication problems.  The total length of the message must not exceed  * 1024 bytes.  This will automatically call packet_write_wait.  If the  * remote side protocol flags do not indicate that it supports SSH_MSG_DEBUG,  * this will do nothing.  */
end_comment

begin_function_decl
name|void
name|packet_send_debug
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Checks if there is any buffered output, and tries to write some of the output. */
end_comment

begin_function_decl
name|void
name|packet_write_poll
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Waits until all pending output data has been written. */
end_comment

begin_function_decl
name|void
name|packet_write_wait
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns true if there is buffered data to write to the connection. */
end_comment

begin_function_decl
name|int
name|packet_have_data_to_write
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns true if there is not too much data to write to the connection. */
end_comment

begin_function_decl
name|int
name|packet_not_very_much_data_to_write
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* maximum packet size, requested by client with SSH_CMSG_MAX_PACKET_SIZE */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|max_packet_size
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|packet_set_maxsize
parameter_list|(
name|int
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|packet_get_maxsize
parameter_list|()
value|max_packet_size
end_define

begin_comment
comment|/* Stores tty modes from the fd or tiop into current packet. */
end_comment

begin_function_decl
name|void
name|tty_make_modes
parameter_list|(
name|int
name|fd
parameter_list|,
name|struct
name|termios
modifier|*
name|tiop
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Parses tty modes for the fd from the current packet. */
end_comment

begin_function_decl
name|void
name|tty_parse_modes
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
modifier|*
name|n_bytes_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|packet_integrity_check
parameter_list|(
name|payload_len
parameter_list|,
name|expected_len
parameter_list|,
name|type
parameter_list|)
define|\
value|do { \   int _p = (payload_len), _e = (expected_len); \   if (_p != _e) { \     log("Packet integrity error (%d != %d) at %s:%d", \ 	_p, _e, __FILE__, __LINE__); \     packet_disconnect("Packet integrity error. (%d)", (type)); \   } \ } while (0)
end_define

begin_define
define|#
directive|define
name|packet_done
parameter_list|()
define|\
value|do { \ 	int _len = packet_remaining(); \ 	if (_len> 0) { \ 		log("Packet integrity error (%d bytes remaining) at %s:%d", \ 		    _len ,__FILE__, __LINE__); \ 		packet_disconnect("Packet integrity error."); \ 	} \ } while (0)
end_define

begin_comment
comment|/* remote host is connected via a socket/ipv4 */
end_comment

begin_function_decl
name|int
name|packet_connection_is_on_socket
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|packet_connection_is_ipv4
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* enable SSH2 packet format */
end_comment

begin_function_decl
name|void
name|packet_set_ssh2_format
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* returns remaining payload bytes */
end_comment

begin_function_decl
name|int
name|packet_remaining
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* append an ignore message */
end_comment

begin_function_decl
name|void
name|packet_send_ignore
parameter_list|(
name|int
name|nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* add an ignore message and make sure size (current+ignore) = n*sumlen */
end_comment

begin_function_decl
name|void
name|packet_inject_ignore
parameter_list|(
name|int
name|sumlen
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PACKET_H */
end_comment

end_unit

