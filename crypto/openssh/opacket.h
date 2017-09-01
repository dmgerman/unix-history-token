begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_OPACKET_H
end_ifndef

begin_comment
comment|/* Written by Markus Friedl. Placed in the public domain.  */
end_comment

begin_comment
comment|/* Map old to new API */
end_comment

begin_function_decl
name|void
name|ssh_packet_start
parameter_list|(
name|struct
name|ssh
modifier|*
parameter_list|,
name|u_char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_packet_put_char
parameter_list|(
name|struct
name|ssh
modifier|*
parameter_list|,
name|int
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_packet_put_int
parameter_list|(
name|struct
name|ssh
modifier|*
parameter_list|,
name|u_int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_packet_put_int64
parameter_list|(
name|struct
name|ssh
modifier|*
parameter_list|,
name|u_int64_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_packet_put_bignum
parameter_list|(
name|struct
name|ssh
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_packet_put_bignum2
parameter_list|(
name|struct
name|ssh
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_packet_put_ecpoint
parameter_list|(
name|struct
name|ssh
modifier|*
parameter_list|,
specifier|const
name|EC_GROUP
modifier|*
parameter_list|,
specifier|const
name|EC_POINT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_packet_put_string
parameter_list|(
name|struct
name|ssh
modifier|*
parameter_list|,
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
name|ssh_packet_put_cstring
parameter_list|(
name|struct
name|ssh
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_packet_put_raw
parameter_list|(
name|struct
name|ssh
modifier|*
parameter_list|,
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
name|ssh_packet_send
parameter_list|(
name|struct
name|ssh
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|ssh_packet_get_char
parameter_list|(
name|struct
name|ssh
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|ssh_packet_get_int
parameter_list|(
name|struct
name|ssh
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int64_t
name|ssh_packet_get_int64
parameter_list|(
name|struct
name|ssh
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_packet_get_bignum
parameter_list|(
name|struct
name|ssh
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_packet_get_bignum2
parameter_list|(
name|struct
name|ssh
modifier|*
parameter_list|,
name|BIGNUM
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_packet_get_ecpoint
parameter_list|(
name|struct
name|ssh
modifier|*
parameter_list|,
specifier|const
name|EC_GROUP
modifier|*
parameter_list|,
name|EC_POINT
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|ssh_packet_get_string
parameter_list|(
name|struct
name|ssh
modifier|*
parameter_list|,
name|u_int
modifier|*
name|length_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ssh_packet_get_cstring
parameter_list|(
name|struct
name|ssh
modifier|*
parameter_list|,
name|u_int
modifier|*
name|length_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* don't allow remaining bytes after the end of the message */
end_comment

begin_define
define|#
directive|define
name|ssh_packet_check_eom
parameter_list|(
name|ssh
parameter_list|)
define|\
value|do { \ 	int _len = ssh_packet_remaining(ssh); \ 	if (_len> 0) { \ 		logit("Packet integrity error (%d bytes remaining) at %s:%d", \ 		    _len ,__FILE__, __LINE__); \ 		ssh_packet_disconnect(ssh, \ 		    "Packet integrity error."); \ 	} \ } while (0)
end_define

begin_comment
comment|/* old API */
end_comment

begin_function_decl
name|void
name|packet_close
parameter_list|(
name|void
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
name|packet_set_connection
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|packet_read_seqnr
parameter_list|(
name|u_int32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|packet_read_poll_seqnr
parameter_list|(
name|u_int32_t
modifier|*
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
name|void
name|packet_write_wait
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
name|packet_read_expect
parameter_list|(
name|int
name|expected_type
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|packet_set_timeout
parameter_list|(
name|timeout
parameter_list|,
name|count
parameter_list|)
define|\
value|ssh_packet_set_timeout(active_state, (timeout), (count))
end_define

begin_define
define|#
directive|define
name|packet_connection_is_on_socket
parameter_list|()
define|\
value|ssh_packet_connection_is_on_socket(active_state)
end_define

begin_define
define|#
directive|define
name|packet_set_nonblocking
parameter_list|()
define|\
value|ssh_packet_set_nonblocking(active_state)
end_define

begin_define
define|#
directive|define
name|packet_get_connection_in
parameter_list|()
define|\
value|ssh_packet_get_connection_in(active_state)
end_define

begin_define
define|#
directive|define
name|packet_get_connection_out
parameter_list|()
define|\
value|ssh_packet_get_connection_out(active_state)
end_define

begin_define
define|#
directive|define
name|packet_set_protocol_flags
parameter_list|(
name|protocol_flags
parameter_list|)
define|\
value|ssh_packet_set_protocol_flags(active_state, (protocol_flags))
end_define

begin_define
define|#
directive|define
name|packet_get_protocol_flags
parameter_list|()
define|\
value|ssh_packet_get_protocol_flags(active_state)
end_define

begin_define
define|#
directive|define
name|packet_start_compression
parameter_list|(
name|level
parameter_list|)
define|\
value|ssh_packet_start_compression(active_state, (level))
end_define

begin_define
define|#
directive|define
name|packet_set_encryption_key
parameter_list|(
name|key
parameter_list|,
name|keylen
parameter_list|,
name|number
parameter_list|)
define|\
value|ssh_packet_set_encryption_key(active_state, (key), (keylen), (number))
end_define

begin_define
define|#
directive|define
name|packet_start
parameter_list|(
name|type
parameter_list|)
define|\
value|ssh_packet_start(active_state, (type))
end_define

begin_define
define|#
directive|define
name|packet_put_char
parameter_list|(
name|value
parameter_list|)
define|\
value|ssh_packet_put_char(active_state, (value))
end_define

begin_define
define|#
directive|define
name|packet_put_int
parameter_list|(
name|value
parameter_list|)
define|\
value|ssh_packet_put_int(active_state, (value))
end_define

begin_define
define|#
directive|define
name|packet_put_int64
parameter_list|(
name|value
parameter_list|)
define|\
value|ssh_packet_put_int64(active_state, (value))
end_define

begin_define
define|#
directive|define
name|packet_put_string
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|)
define|\
value|ssh_packet_put_string(active_state, (buf), (len))
end_define

begin_define
define|#
directive|define
name|packet_put_cstring
parameter_list|(
name|str
parameter_list|)
define|\
value|ssh_packet_put_cstring(active_state, (str))
end_define

begin_define
define|#
directive|define
name|packet_put_raw
parameter_list|(
name|buf
parameter_list|,
name|len
parameter_list|)
define|\
value|ssh_packet_put_raw(active_state, (buf), (len))
end_define

begin_define
define|#
directive|define
name|packet_put_bignum
parameter_list|(
name|value
parameter_list|)
define|\
value|ssh_packet_put_bignum(active_state, (value))
end_define

begin_define
define|#
directive|define
name|packet_put_bignum2
parameter_list|(
name|value
parameter_list|)
define|\
value|ssh_packet_put_bignum2(active_state, (value))
end_define

begin_define
define|#
directive|define
name|packet_send
parameter_list|()
define|\
value|ssh_packet_send(active_state)
end_define

begin_define
define|#
directive|define
name|packet_read
parameter_list|()
define|\
value|ssh_packet_read(active_state)
end_define

begin_define
define|#
directive|define
name|packet_get_int64
parameter_list|()
define|\
value|ssh_packet_get_int64(active_state)
end_define

begin_define
define|#
directive|define
name|packet_get_bignum
parameter_list|(
name|value
parameter_list|)
define|\
value|ssh_packet_get_bignum(active_state, (value))
end_define

begin_define
define|#
directive|define
name|packet_get_bignum2
parameter_list|(
name|value
parameter_list|)
define|\
value|ssh_packet_get_bignum2(active_state, (value))
end_define

begin_define
define|#
directive|define
name|packet_remaining
parameter_list|()
define|\
value|ssh_packet_remaining(active_state)
end_define

begin_define
define|#
directive|define
name|packet_get_string
parameter_list|(
name|length_ptr
parameter_list|)
define|\
value|ssh_packet_get_string(active_state, (length_ptr))
end_define

begin_define
define|#
directive|define
name|packet_get_string_ptr
parameter_list|(
name|length_ptr
parameter_list|)
define|\
value|ssh_packet_get_string_ptr(active_state, (length_ptr))
end_define

begin_define
define|#
directive|define
name|packet_get_cstring
parameter_list|(
name|length_ptr
parameter_list|)
define|\
value|ssh_packet_get_cstring(active_state, (length_ptr))
end_define

begin_function_decl
name|void
name|packet_send_debug
parameter_list|(
specifier|const
name|char
modifier|*
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
name|packet_disconnect
parameter_list|(
specifier|const
name|char
modifier|*
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

begin_expr_stmt
unit|)))
name|__attribute__
argument_list|(
operator|(
name|noreturn
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|packet_have_data_to_write
parameter_list|()
define|\
value|ssh_packet_have_data_to_write(active_state)
end_define

begin_define
define|#
directive|define
name|packet_not_very_much_data_to_write
parameter_list|()
define|\
value|ssh_packet_not_very_much_data_to_write(active_state)
end_define

begin_define
define|#
directive|define
name|packet_set_interactive
parameter_list|(
name|interactive
parameter_list|,
name|qos_interactive
parameter_list|,
name|qos_bulk
parameter_list|)
define|\
value|ssh_packet_set_interactive(active_state, (interactive), (qos_interactive), (qos_bulk))
end_define

begin_define
define|#
directive|define
name|packet_is_interactive
parameter_list|()
define|\
value|ssh_packet_is_interactive(active_state)
end_define

begin_define
define|#
directive|define
name|packet_set_maxsize
parameter_list|(
name|s
parameter_list|)
define|\
value|ssh_packet_set_maxsize(active_state, (s))
end_define

begin_define
define|#
directive|define
name|packet_inc_alive_timeouts
parameter_list|()
define|\
value|ssh_packet_inc_alive_timeouts(active_state)
end_define

begin_define
define|#
directive|define
name|packet_set_alive_timeouts
parameter_list|(
name|ka
parameter_list|)
define|\
value|ssh_packet_set_alive_timeouts(active_state, (ka))
end_define

begin_define
define|#
directive|define
name|packet_get_maxsize
parameter_list|()
define|\
value|ssh_packet_get_maxsize(active_state)
end_define

begin_define
define|#
directive|define
name|packet_add_padding
parameter_list|(
name|pad
parameter_list|)
define|\
value|sshpkt_add_padding(active_state, (pad))
end_define

begin_define
define|#
directive|define
name|packet_send_ignore
parameter_list|(
name|nbytes
parameter_list|)
define|\
value|ssh_packet_send_ignore(active_state, (nbytes))
end_define

begin_define
define|#
directive|define
name|packet_set_server
parameter_list|()
define|\
value|ssh_packet_set_server(active_state)
end_define

begin_define
define|#
directive|define
name|packet_set_authenticated
parameter_list|()
define|\
value|ssh_packet_set_authenticated(active_state)
end_define

begin_define
define|#
directive|define
name|packet_get_input
parameter_list|()
define|\
value|ssh_packet_get_input(active_state)
end_define

begin_define
define|#
directive|define
name|packet_get_output
parameter_list|()
define|\
value|ssh_packet_get_output(active_state)
end_define

begin_define
define|#
directive|define
name|packet_set_compress_hooks
parameter_list|(
name|ctx
parameter_list|,
name|allocfunc
parameter_list|,
name|freefunc
parameter_list|)
define|\
value|ssh_packet_set_compress_hooks(active_state, ctx, \ 	    allocfunc, freefunc);
end_define

begin_define
define|#
directive|define
name|packet_check_eom
parameter_list|()
define|\
value|ssh_packet_check_eom(active_state)
end_define

begin_define
define|#
directive|define
name|set_newkeys
parameter_list|(
name|mode
parameter_list|)
define|\
value|ssh_set_newkeys(active_state, (mode))
end_define

begin_define
define|#
directive|define
name|packet_get_state
parameter_list|(
name|m
parameter_list|)
define|\
value|ssh_packet_get_state(active_state, m)
end_define

begin_define
define|#
directive|define
name|packet_set_state
parameter_list|(
name|m
parameter_list|)
define|\
value|ssh_packet_set_state(active_state, m)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|get_remote_ipaddr
parameter_list|()
define|\
value|ssh_remote_ipaddr(active_state)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|packet_get_raw
parameter_list|(
name|lenp
parameter_list|)
define|\
value|sshpkt_ptr(active_state, lenp)
end_define

begin_define
define|#
directive|define
name|packet_get_ecpoint
parameter_list|(
name|c
parameter_list|,
name|p
parameter_list|)
define|\
value|ssh_packet_get_ecpoint(active_state, c, p)
end_define

begin_define
define|#
directive|define
name|packet_put_ecpoint
parameter_list|(
name|c
parameter_list|,
name|p
parameter_list|)
define|\
value|ssh_packet_put_ecpoint(active_state, c, p)
end_define

begin_define
define|#
directive|define
name|packet_get_rekey_timeout
parameter_list|()
define|\
value|ssh_packet_get_rekey_timeout(active_state)
end_define

begin_define
define|#
directive|define
name|packet_set_rekey_limits
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|ssh_packet_set_rekey_limits(active_state, x, y)
end_define

begin_define
define|#
directive|define
name|packet_get_bytes
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|ssh_packet_get_bytes(active_state, x, y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OPACKET_H */
end_comment

end_unit

