begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: packet.h,v 1.33 2002/03/04 17:27:39 stevesk Exp $	*/
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  * Interface for the packet protocol functions.  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
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

begin_function_decl
name|void
name|packet_set_connection
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|packet_set_nonblocking
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|packet_get_connection_in
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|packet_get_connection_out
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|packet_close
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|packet_set_encryption_key
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|packet_set_protocol_flags
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|packet_get_protocol_flags
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|packet_start_compression
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|packet_set_interactive
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|packet_is_interactive
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|packet_start
parameter_list|(
name|u_char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|packet_put_char
parameter_list|(
name|int
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|packet_put_int
parameter_list|(
name|u_int
name|value
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|void
name|packet_put_string
parameter_list|(
specifier|const
name|void
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
name|void
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
name|packet_send
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|packet_read
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|packet_read_expect
parameter_list|(
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|packet_read_poll
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|int
name|packet_read_seqnr
parameter_list|(
name|u_int32_t
modifier|*
name|seqnr_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|packet_read_poll_seqnr
parameter_list|(
name|u_int32_t
modifier|*
name|seqnr_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|packet_get_char
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|packet_get_int
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|packet_get_bignum
parameter_list|(
name|BIGNUM
modifier|*
name|value
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|packet_get_raw
parameter_list|(
name|int
modifier|*
name|length_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|packet_get_string
parameter_list|(
name|u_int
modifier|*
name|length_ptr
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|void
name|packet_write_poll
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|packet_write_wait
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|packet_have_data_to_write
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|packet_not_very_much_data_to_write
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|int
name|packet_remaining
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|packet_send_ignore
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|packet_add_padding
parameter_list|(
name|u_char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_make_modes
parameter_list|(
name|int
parameter_list|,
name|struct
name|termios
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tty_parse_modes
parameter_list|(
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* don't allow remaining bytes after the end of the message */
end_comment

begin_define
define|#
directive|define
name|packet_check_eom
parameter_list|()
define|\
value|do { \ 	int _len = packet_remaining(); \ 	if (_len> 0) { \ 		log("Packet integrity error (%d bytes remaining) at %s:%d", \ 		    _len ,__FILE__, __LINE__); \ 		packet_disconnect("Packet integrity error."); \ 	} \ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PACKET_H */
end_comment

end_unit

