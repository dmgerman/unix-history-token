begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Namespace munging inspired by an equivalent hack in NetBSD's tree: add  * the "Fssh_" prefix to every symbol in libssh which doesn't already have  * it.  This prevents collisions between symbols in libssh and symbols in  * other libraries or applications which link with libssh, either directly  * or indirectly (e.g. through PAM loading pam_ssh).  *  * A list of symbols which need munging is obtained as follows:  *  # nm libprivatessh.a | LC_ALL=C awk '      /^[0-9a-z]+ [Tt] [A-Za-z_][0-9A-Za-z_]*$/&& $3 !~ /^Fssh_/ {          printf("#define %-39s Fssh_%s\n", $3, $3)      }' | unexpand -a | LC_ALL=C sort -u  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|Blowfish_decipher
value|Fssh_Blowfish_decipher
end_define

begin_define
define|#
directive|define
name|Blowfish_encipher
value|Fssh_Blowfish_encipher
end_define

begin_define
define|#
directive|define
name|Blowfish_expand0state
value|Fssh_Blowfish_expand0state
end_define

begin_define
define|#
directive|define
name|Blowfish_expandstate
value|Fssh_Blowfish_expandstate
end_define

begin_define
define|#
directive|define
name|Blowfish_initstate
value|Fssh_Blowfish_initstate
end_define

begin_define
define|#
directive|define
name|Blowfish_stream2word
value|Fssh_Blowfish_stream2word
end_define

begin_define
define|#
directive|define
name|_ssh__compat_glob
value|Fssh__ssh__compat_glob
end_define

begin_define
define|#
directive|define
name|_ssh__compat_globfree
value|Fssh__ssh__compat_globfree
end_define

begin_define
define|#
directive|define
name|_ssh_compat_realpath
value|Fssh__ssh_compat_realpath
end_define

begin_define
define|#
directive|define
name|_ssh_exchange_banner
value|Fssh__ssh_exchange_banner
end_define

begin_define
define|#
directive|define
name|_ssh_host_key_sign
value|Fssh__ssh_host_key_sign
end_define

begin_define
define|#
directive|define
name|_ssh_host_private_key
value|Fssh__ssh_host_private_key
end_define

begin_define
define|#
directive|define
name|_ssh_host_public_key
value|Fssh__ssh_host_public_key
end_define

begin_define
define|#
directive|define
name|_ssh_order_hostkeyalgs
value|Fssh__ssh_order_hostkeyalgs
end_define

begin_define
define|#
directive|define
name|_ssh_read_banner
value|Fssh__ssh_read_banner
end_define

begin_define
define|#
directive|define
name|_ssh_send_banner
value|Fssh__ssh_send_banner
end_define

begin_define
define|#
directive|define
name|_ssh_verify_host_key
value|Fssh__ssh_verify_host_key
end_define

begin_define
define|#
directive|define
name|a2port
value|Fssh_a2port
end_define

begin_define
define|#
directive|define
name|a2tun
value|Fssh_a2tun
end_define

begin_define
define|#
directive|define
name|add_host_to_hostfile
value|Fssh_add_host_to_hostfile
end_define

begin_define
define|#
directive|define
name|add_p1p1
value|Fssh_add_p1p1
end_define

begin_define
define|#
directive|define
name|addargs
value|Fssh_addargs
end_define

begin_define
define|#
directive|define
name|addr_match_cidr_list
value|Fssh_addr_match_cidr_list
end_define

begin_define
define|#
directive|define
name|addr_match_list
value|Fssh_addr_match_list
end_define

begin_define
define|#
directive|define
name|addr_netmatch
value|Fssh_addr_netmatch
end_define

begin_define
define|#
directive|define
name|addr_pton_cidr
value|Fssh_addr_pton_cidr
end_define

begin_define
define|#
directive|define
name|ask_permission
value|Fssh_ask_permission
end_define

begin_define
define|#
directive|define
name|atomicio
value|Fssh_atomicio
end_define

begin_define
define|#
directive|define
name|atomicio6
value|Fssh_atomicio6
end_define

begin_define
define|#
directive|define
name|atomiciov
value|Fssh_atomiciov
end_define

begin_define
define|#
directive|define
name|atomiciov6
value|Fssh_atomiciov6
end_define

begin_define
define|#
directive|define
name|auth_request_forwarding
value|Fssh_auth_request_forwarding
end_define

begin_define
define|#
directive|define
name|bandwidth_limit
value|Fssh_bandwidth_limit
end_define

begin_define
define|#
directive|define
name|bandwidth_limit_init
value|Fssh_bandwidth_limit_init
end_define

begin_define
define|#
directive|define
name|barrett_reduce
value|Fssh_barrett_reduce
end_define

begin_define
define|#
directive|define
name|baud_to_speed
value|Fssh_baud_to_speed
end_define

begin_define
define|#
directive|define
name|bcrypt_hash
value|Fssh_bcrypt_hash
end_define

begin_define
define|#
directive|define
name|bcrypt_pbkdf
value|Fssh_bcrypt_pbkdf
end_define

begin_define
define|#
directive|define
name|bind_permitted
value|Fssh_bind_permitted
end_define

begin_define
define|#
directive|define
name|bitmap_clear_bit
value|Fssh_bitmap_clear_bit
end_define

begin_define
define|#
directive|define
name|bitmap_free
value|Fssh_bitmap_free
end_define

begin_define
define|#
directive|define
name|bitmap_from_string
value|Fssh_bitmap_from_string
end_define

begin_define
define|#
directive|define
name|bitmap_nbits
value|Fssh_bitmap_nbits
end_define

begin_define
define|#
directive|define
name|bitmap_nbytes
value|Fssh_bitmap_nbytes
end_define

begin_define
define|#
directive|define
name|bitmap_new
value|Fssh_bitmap_new
end_define

begin_define
define|#
directive|define
name|bitmap_set_bit
value|Fssh_bitmap_set_bit
end_define

begin_define
define|#
directive|define
name|bitmap_test_bit
value|Fssh_bitmap_test_bit
end_define

begin_define
define|#
directive|define
name|bitmap_to_string
value|Fssh_bitmap_to_string
end_define

begin_define
define|#
directive|define
name|bitmap_zero
value|Fssh_bitmap_zero
end_define

begin_define
define|#
directive|define
name|blf_cbc_decrypt
value|Fssh_blf_cbc_decrypt
end_define

begin_define
define|#
directive|define
name|blf_cbc_encrypt
value|Fssh_blf_cbc_encrypt
end_define

begin_define
define|#
directive|define
name|blf_dec
value|Fssh_blf_dec
end_define

begin_define
define|#
directive|define
name|blf_ecb_decrypt
value|Fssh_blf_ecb_decrypt
end_define

begin_define
define|#
directive|define
name|blf_ecb_encrypt
value|Fssh_blf_ecb_encrypt
end_define

begin_define
define|#
directive|define
name|blf_enc
value|Fssh_blf_enc
end_define

begin_define
define|#
directive|define
name|blf_key
value|Fssh_blf_key
end_define

begin_define
define|#
directive|define
name|buffer_append
value|Fssh_buffer_append
end_define

begin_define
define|#
directive|define
name|buffer_append_space
value|Fssh_buffer_append_space
end_define

begin_define
define|#
directive|define
name|buffer_check_alloc
value|Fssh_buffer_check_alloc
end_define

begin_define
define|#
directive|define
name|buffer_consume
value|Fssh_buffer_consume
end_define

begin_define
define|#
directive|define
name|buffer_consume_end
value|Fssh_buffer_consume_end
end_define

begin_define
define|#
directive|define
name|buffer_consume_end_ret
value|Fssh_buffer_consume_end_ret
end_define

begin_define
define|#
directive|define
name|buffer_consume_ret
value|Fssh_buffer_consume_ret
end_define

begin_define
define|#
directive|define
name|buffer_get
value|Fssh_buffer_get
end_define

begin_define
define|#
directive|define
name|buffer_get_bignum2
value|Fssh_buffer_get_bignum2
end_define

begin_define
define|#
directive|define
name|buffer_get_bignum2_ret
value|Fssh_buffer_get_bignum2_ret
end_define

begin_define
define|#
directive|define
name|buffer_get_char
value|Fssh_buffer_get_char
end_define

begin_define
define|#
directive|define
name|buffer_get_char_ret
value|Fssh_buffer_get_char_ret
end_define

begin_define
define|#
directive|define
name|buffer_get_cstring
value|Fssh_buffer_get_cstring
end_define

begin_define
define|#
directive|define
name|buffer_get_cstring_ret
value|Fssh_buffer_get_cstring_ret
end_define

begin_define
define|#
directive|define
name|buffer_get_ecpoint
value|Fssh_buffer_get_ecpoint
end_define

begin_define
define|#
directive|define
name|buffer_get_ecpoint_ret
value|Fssh_buffer_get_ecpoint_ret
end_define

begin_define
define|#
directive|define
name|buffer_get_int
value|Fssh_buffer_get_int
end_define

begin_define
define|#
directive|define
name|buffer_get_int64
value|Fssh_buffer_get_int64
end_define

begin_define
define|#
directive|define
name|buffer_get_int64_ret
value|Fssh_buffer_get_int64_ret
end_define

begin_define
define|#
directive|define
name|buffer_get_int_ret
value|Fssh_buffer_get_int_ret
end_define

begin_define
define|#
directive|define
name|buffer_get_ret
value|Fssh_buffer_get_ret
end_define

begin_define
define|#
directive|define
name|buffer_get_short
value|Fssh_buffer_get_short
end_define

begin_define
define|#
directive|define
name|buffer_get_short_ret
value|Fssh_buffer_get_short_ret
end_define

begin_define
define|#
directive|define
name|buffer_get_string
value|Fssh_buffer_get_string
end_define

begin_define
define|#
directive|define
name|buffer_get_string_ptr
value|Fssh_buffer_get_string_ptr
end_define

begin_define
define|#
directive|define
name|buffer_get_string_ptr_ret
value|Fssh_buffer_get_string_ptr_ret
end_define

begin_define
define|#
directive|define
name|buffer_get_string_ret
value|Fssh_buffer_get_string_ret
end_define

begin_define
define|#
directive|define
name|buffer_put_bignum2
value|Fssh_buffer_put_bignum2
end_define

begin_define
define|#
directive|define
name|buffer_put_bignum2_from_string
value|Fssh_buffer_put_bignum2_from_string
end_define

begin_define
define|#
directive|define
name|buffer_put_bignum2_ret
value|Fssh_buffer_put_bignum2_ret
end_define

begin_define
define|#
directive|define
name|buffer_put_char
value|Fssh_buffer_put_char
end_define

begin_define
define|#
directive|define
name|buffer_put_cstring
value|Fssh_buffer_put_cstring
end_define

begin_define
define|#
directive|define
name|buffer_put_ecpoint
value|Fssh_buffer_put_ecpoint
end_define

begin_define
define|#
directive|define
name|buffer_put_ecpoint_ret
value|Fssh_buffer_put_ecpoint_ret
end_define

begin_define
define|#
directive|define
name|buffer_put_int
value|Fssh_buffer_put_int
end_define

begin_define
define|#
directive|define
name|buffer_put_int64
value|Fssh_buffer_put_int64
end_define

begin_define
define|#
directive|define
name|buffer_put_short
value|Fssh_buffer_put_short
end_define

begin_define
define|#
directive|define
name|buffer_put_string
value|Fssh_buffer_put_string
end_define

begin_define
define|#
directive|define
name|cert_free
value|Fssh_cert_free
end_define

begin_define
define|#
directive|define
name|chacha_encrypt_bytes
value|Fssh_chacha_encrypt_bytes
end_define

begin_define
define|#
directive|define
name|chacha_ivsetup
value|Fssh_chacha_ivsetup
end_define

begin_define
define|#
directive|define
name|chacha_keysetup
value|Fssh_chacha_keysetup
end_define

begin_define
define|#
directive|define
name|chachapoly_crypt
value|Fssh_chachapoly_crypt
end_define

begin_define
define|#
directive|define
name|chachapoly_get_length
value|Fssh_chachapoly_get_length
end_define

begin_define
define|#
directive|define
name|chachapoly_init
value|Fssh_chachapoly_init
end_define

begin_define
define|#
directive|define
name|chan_ibuf_empty
value|Fssh_chan_ibuf_empty
end_define

begin_define
define|#
directive|define
name|chan_is_dead
value|Fssh_chan_is_dead
end_define

begin_define
define|#
directive|define
name|chan_mark_dead
value|Fssh_chan_mark_dead
end_define

begin_define
define|#
directive|define
name|chan_obuf_empty
value|Fssh_chan_obuf_empty
end_define

begin_define
define|#
directive|define
name|chan_rcvd_eow
value|Fssh_chan_rcvd_eow
end_define

begin_define
define|#
directive|define
name|chan_rcvd_ieof
value|Fssh_chan_rcvd_ieof
end_define

begin_define
define|#
directive|define
name|chan_rcvd_oclose
value|Fssh_chan_rcvd_oclose
end_define

begin_define
define|#
directive|define
name|chan_read_failed
value|Fssh_chan_read_failed
end_define

begin_define
define|#
directive|define
name|chan_send_eof2
value|Fssh_chan_send_eof2
end_define

begin_define
define|#
directive|define
name|chan_send_oclose1
value|Fssh_chan_send_oclose1
end_define

begin_define
define|#
directive|define
name|chan_shutdown_read
value|Fssh_chan_shutdown_read
end_define

begin_define
define|#
directive|define
name|chan_shutdown_write
value|Fssh_chan_shutdown_write
end_define

begin_define
define|#
directive|define
name|chan_write_failed
value|Fssh_chan_write_failed
end_define

begin_define
define|#
directive|define
name|channel_add_adm_permitted_opens
value|Fssh_channel_add_adm_permitted_opens
end_define

begin_define
define|#
directive|define
name|channel_add_permitted_opens
value|Fssh_channel_add_permitted_opens
end_define

begin_define
define|#
directive|define
name|channel_after_select
value|Fssh_channel_after_select
end_define

begin_define
define|#
directive|define
name|channel_by_id
value|Fssh_channel_by_id
end_define

begin_define
define|#
directive|define
name|channel_by_remote_id
value|Fssh_channel_by_remote_id
end_define

begin_define
define|#
directive|define
name|channel_cancel_cleanup
value|Fssh_channel_cancel_cleanup
end_define

begin_define
define|#
directive|define
name|channel_cancel_lport_listener
value|Fssh_channel_cancel_lport_listener
end_define

begin_define
define|#
directive|define
name|channel_cancel_rport_listener
value|Fssh_channel_cancel_rport_listener
end_define

begin_define
define|#
directive|define
name|channel_clear_adm_permitted_opens
value|Fssh_channel_clear_adm_permitted_opens
end_define

begin_define
define|#
directive|define
name|channel_clear_permitted_opens
value|Fssh_channel_clear_permitted_opens
end_define

begin_define
define|#
directive|define
name|channel_close_all
value|Fssh_channel_close_all
end_define

begin_define
define|#
directive|define
name|channel_close_fd
value|Fssh_channel_close_fd
end_define

begin_define
define|#
directive|define
name|channel_close_fds
value|Fssh_channel_close_fds
end_define

begin_define
define|#
directive|define
name|channel_connect_by_listen_address
value|Fssh_channel_connect_by_listen_address
end_define

begin_define
define|#
directive|define
name|channel_connect_by_listen_path
value|Fssh_channel_connect_by_listen_path
end_define

begin_define
define|#
directive|define
name|channel_connect_stdio_fwd
value|Fssh_channel_connect_stdio_fwd
end_define

begin_define
define|#
directive|define
name|channel_connect_to_path
value|Fssh_channel_connect_to_path
end_define

begin_define
define|#
directive|define
name|channel_connect_to_port
value|Fssh_channel_connect_to_port
end_define

begin_define
define|#
directive|define
name|channel_disable_adm_local_opens
value|Fssh_channel_disable_adm_local_opens
end_define

begin_define
define|#
directive|define
name|channel_find_open
value|Fssh_channel_find_open
end_define

begin_define
define|#
directive|define
name|channel_free
value|Fssh_channel_free
end_define

begin_define
define|#
directive|define
name|channel_free_all
value|Fssh_channel_free_all
end_define

begin_define
define|#
directive|define
name|channel_fwd_bind_addr
value|Fssh_channel_fwd_bind_addr
end_define

begin_define
define|#
directive|define
name|channel_handler
value|Fssh_channel_handler
end_define

begin_define
define|#
directive|define
name|channel_input_close
value|Fssh_channel_input_close
end_define

begin_define
define|#
directive|define
name|channel_input_close_confirmation
value|Fssh_channel_input_close_confirmation
end_define

begin_define
define|#
directive|define
name|channel_input_data
value|Fssh_channel_input_data
end_define

begin_define
define|#
directive|define
name|channel_input_extended_data
value|Fssh_channel_input_extended_data
end_define

begin_define
define|#
directive|define
name|channel_input_ieof
value|Fssh_channel_input_ieof
end_define

begin_define
define|#
directive|define
name|channel_input_oclose
value|Fssh_channel_input_oclose
end_define

begin_define
define|#
directive|define
name|channel_input_open_confirmation
value|Fssh_channel_input_open_confirmation
end_define

begin_define
define|#
directive|define
name|channel_input_open_failure
value|Fssh_channel_input_open_failure
end_define

begin_define
define|#
directive|define
name|channel_input_port_open
value|Fssh_channel_input_port_open
end_define

begin_define
define|#
directive|define
name|channel_input_status_confirm
value|Fssh_channel_input_status_confirm
end_define

begin_define
define|#
directive|define
name|channel_input_window_adjust
value|Fssh_channel_input_window_adjust
end_define

begin_define
define|#
directive|define
name|channel_lookup
value|Fssh_channel_lookup
end_define

begin_define
define|#
directive|define
name|channel_new
value|Fssh_channel_new
end_define

begin_define
define|#
directive|define
name|channel_not_very_much_buffered_data
value|Fssh_channel_not_very_much_buffered_data
end_define

begin_define
define|#
directive|define
name|channel_open_message
value|Fssh_channel_open_message
end_define

begin_define
define|#
directive|define
name|channel_output_poll
value|Fssh_channel_output_poll
end_define

begin_define
define|#
directive|define
name|channel_permit_all_opens
value|Fssh_channel_permit_all_opens
end_define

begin_define
define|#
directive|define
name|channel_post_auth_listener
value|Fssh_channel_post_auth_listener
end_define

begin_define
define|#
directive|define
name|channel_post_connecting
value|Fssh_channel_post_connecting
end_define

begin_define
define|#
directive|define
name|channel_post_mux_client
value|Fssh_channel_post_mux_client
end_define

begin_define
define|#
directive|define
name|channel_post_mux_listener
value|Fssh_channel_post_mux_listener
end_define

begin_define
define|#
directive|define
name|channel_post_open
value|Fssh_channel_post_open
end_define

begin_define
define|#
directive|define
name|channel_post_output_drain_13
value|Fssh_channel_post_output_drain_13
end_define

begin_define
define|#
directive|define
name|channel_post_port_listener
value|Fssh_channel_post_port_listener
end_define

begin_define
define|#
directive|define
name|channel_post_x11_listener
value|Fssh_channel_post_x11_listener
end_define

begin_define
define|#
directive|define
name|channel_pre_connecting
value|Fssh_channel_pre_connecting
end_define

begin_define
define|#
directive|define
name|channel_pre_dynamic
value|Fssh_channel_pre_dynamic
end_define

begin_define
define|#
directive|define
name|channel_pre_input_draining
value|Fssh_channel_pre_input_draining
end_define

begin_define
define|#
directive|define
name|channel_pre_listener
value|Fssh_channel_pre_listener
end_define

begin_define
define|#
directive|define
name|channel_pre_mux_client
value|Fssh_channel_pre_mux_client
end_define

begin_define
define|#
directive|define
name|channel_pre_open
value|Fssh_channel_pre_open
end_define

begin_define
define|#
directive|define
name|channel_pre_open_13
value|Fssh_channel_pre_open_13
end_define

begin_define
define|#
directive|define
name|channel_pre_output_draining
value|Fssh_channel_pre_output_draining
end_define

begin_define
define|#
directive|define
name|channel_pre_x11_open
value|Fssh_channel_pre_x11_open
end_define

begin_define
define|#
directive|define
name|channel_pre_x11_open_13
value|Fssh_channel_pre_x11_open_13
end_define

begin_define
define|#
directive|define
name|channel_prepare_select
value|Fssh_channel_prepare_select
end_define

begin_define
define|#
directive|define
name|channel_print_adm_permitted_opens
value|Fssh_channel_print_adm_permitted_opens
end_define

begin_define
define|#
directive|define
name|channel_proxy_downstream
value|Fssh_channel_proxy_downstream
end_define

begin_define
define|#
directive|define
name|channel_proxy_upstream
value|Fssh_channel_proxy_upstream
end_define

begin_define
define|#
directive|define
name|channel_register_cleanup
value|Fssh_channel_register_cleanup
end_define

begin_define
define|#
directive|define
name|channel_register_fds
value|Fssh_channel_register_fds
end_define

begin_define
define|#
directive|define
name|channel_register_filter
value|Fssh_channel_register_filter
end_define

begin_define
define|#
directive|define
name|channel_register_open_confirm
value|Fssh_channel_register_open_confirm
end_define

begin_define
define|#
directive|define
name|channel_register_status_confirm
value|Fssh_channel_register_status_confirm
end_define

begin_define
define|#
directive|define
name|channel_request_remote_forwarding
value|Fssh_channel_request_remote_forwarding
end_define

begin_define
define|#
directive|define
name|channel_request_rforward_cancel
value|Fssh_channel_request_rforward_cancel
end_define

begin_define
define|#
directive|define
name|channel_request_start
value|Fssh_channel_request_start
end_define

begin_define
define|#
directive|define
name|channel_send_open
value|Fssh_channel_send_open
end_define

begin_define
define|#
directive|define
name|channel_send_window_changes
value|Fssh_channel_send_window_changes
end_define

begin_define
define|#
directive|define
name|channel_set_af
value|Fssh_channel_set_af
end_define

begin_define
define|#
directive|define
name|channel_set_fds
value|Fssh_channel_set_fds
end_define

begin_define
define|#
directive|define
name|channel_set_x11_refuse_time
value|Fssh_channel_set_x11_refuse_time
end_define

begin_define
define|#
directive|define
name|channel_setup_fwd_listener_streamlocal
value|Fssh_channel_setup_fwd_listener_streamlocal
end_define

begin_define
define|#
directive|define
name|channel_setup_fwd_listener_tcpip
value|Fssh_channel_setup_fwd_listener_tcpip
end_define

begin_define
define|#
directive|define
name|channel_setup_local_fwd_listener
value|Fssh_channel_setup_local_fwd_listener
end_define

begin_define
define|#
directive|define
name|channel_setup_remote_fwd_listener
value|Fssh_channel_setup_remote_fwd_listener
end_define

begin_define
define|#
directive|define
name|channel_still_open
value|Fssh_channel_still_open
end_define

begin_define
define|#
directive|define
name|channel_stop_listening
value|Fssh_channel_stop_listening
end_define

begin_define
define|#
directive|define
name|channel_update_permitted_opens
value|Fssh_channel_update_permitted_opens
end_define

begin_define
define|#
directive|define
name|check_crc
value|Fssh_check_crc
end_define

begin_define
define|#
directive|define
name|check_hostkeys_by_key_or_type
value|Fssh_check_hostkeys_by_key_or_type
end_define

begin_define
define|#
directive|define
name|check_key_in_hostkeys
value|Fssh_check_key_in_hostkeys
end_define

begin_define
define|#
directive|define
name|choose_dh
value|Fssh_choose_dh
end_define

begin_define
define|#
directive|define
name|choose_t
value|Fssh_choose_t
end_define

begin_define
define|#
directive|define
name|chop
value|Fssh_chop
end_define

begin_define
define|#
directive|define
name|cipher_alg_list
value|Fssh_cipher_alg_list
end_define

begin_define
define|#
directive|define
name|cipher_authlen
value|Fssh_cipher_authlen
end_define

begin_define
define|#
directive|define
name|cipher_blocksize
value|Fssh_cipher_blocksize
end_define

begin_define
define|#
directive|define
name|cipher_by_name
value|Fssh_cipher_by_name
end_define

begin_define
define|#
directive|define
name|cipher_by_number
value|Fssh_cipher_by_number
end_define

begin_define
define|#
directive|define
name|cipher_crypt
value|Fssh_cipher_crypt
end_define

begin_define
define|#
directive|define
name|cipher_ctx_get_number
value|Fssh_cipher_ctx_get_number
end_define

begin_define
define|#
directive|define
name|cipher_ctx_is_plaintext
value|Fssh_cipher_ctx_is_plaintext
end_define

begin_define
define|#
directive|define
name|cipher_free
value|Fssh_cipher_free
end_define

begin_define
define|#
directive|define
name|cipher_get_keycontext
value|Fssh_cipher_get_keycontext
end_define

begin_define
define|#
directive|define
name|cipher_get_keyiv
value|Fssh_cipher_get_keyiv
end_define

begin_define
define|#
directive|define
name|cipher_get_keyiv_len
value|Fssh_cipher_get_keyiv_len
end_define

begin_define
define|#
directive|define
name|cipher_get_length
value|Fssh_cipher_get_length
end_define

begin_define
define|#
directive|define
name|cipher_get_number
value|Fssh_cipher_get_number
end_define

begin_define
define|#
directive|define
name|cipher_init
value|Fssh_cipher_init
end_define

begin_define
define|#
directive|define
name|cipher_is_cbc
value|Fssh_cipher_is_cbc
end_define

begin_define
define|#
directive|define
name|cipher_ivlen
value|Fssh_cipher_ivlen
end_define

begin_define
define|#
directive|define
name|cipher_keylen
value|Fssh_cipher_keylen
end_define

begin_define
define|#
directive|define
name|cipher_mask_ssh1
value|Fssh_cipher_mask_ssh1
end_define

begin_define
define|#
directive|define
name|cipher_name
value|Fssh_cipher_name
end_define

begin_define
define|#
directive|define
name|cipher_number
value|Fssh_cipher_number
end_define

begin_define
define|#
directive|define
name|cipher_seclen
value|Fssh_cipher_seclen
end_define

begin_define
define|#
directive|define
name|cipher_set_key_string
value|Fssh_cipher_set_key_string
end_define

begin_define
define|#
directive|define
name|cipher_set_keycontext
value|Fssh_cipher_set_keycontext
end_define

begin_define
define|#
directive|define
name|cipher_set_keyiv
value|Fssh_cipher_set_keyiv
end_define

begin_define
define|#
directive|define
name|cipher_warning_message
value|Fssh_cipher_warning_message
end_define

begin_define
define|#
directive|define
name|ciphers_valid
value|Fssh_ciphers_valid
end_define

begin_define
define|#
directive|define
name|cleanhostname
value|Fssh_cleanhostname
end_define

begin_define
define|#
directive|define
name|cleanup_exit
value|Fssh_cleanup_exit
end_define

begin_define
define|#
directive|define
name|colon
value|Fssh_colon
end_define

begin_define
define|#
directive|define
name|compare
value|Fssh_compare
end_define

begin_define
define|#
directive|define
name|compare_gps
value|Fssh_compare_gps
end_define

begin_define
define|#
directive|define
name|compat_cipher_proposal
value|Fssh_compat_cipher_proposal
end_define

begin_define
define|#
directive|define
name|compat_datafellows
value|Fssh_compat_datafellows
end_define

begin_define
define|#
directive|define
name|compat_kex_proposal
value|Fssh_compat_kex_proposal
end_define

begin_define
define|#
directive|define
name|compat_pkalg_proposal
value|Fssh_compat_pkalg_proposal
end_define

begin_define
define|#
directive|define
name|compress_buffer
value|Fssh_compress_buffer
end_define

begin_define
define|#
directive|define
name|connect_next
value|Fssh_connect_next
end_define

begin_define
define|#
directive|define
name|connect_to_reason
value|Fssh_connect_to_reason
end_define

begin_define
define|#
directive|define
name|convtime
value|Fssh_convtime
end_define

begin_define
define|#
directive|define
name|crypto_hash_sha512
value|Fssh_crypto_hash_sha512
end_define

begin_define
define|#
directive|define
name|crypto_hashblocks_sha512
value|Fssh_crypto_hashblocks_sha512
end_define

begin_define
define|#
directive|define
name|crypto_scalarmult_curve25519
value|Fssh_crypto_scalarmult_curve25519
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519
value|Fssh_crypto_sign_ed25519
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_keypair
value|Fssh_crypto_sign_ed25519_keypair
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_open
value|Fssh_crypto_sign_ed25519_open
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_double_scalarmult_vartime
value|Fssh_crypto_sign_ed25519_ref_double_scalarmult_vartime
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_fe25519_add
value|Fssh_crypto_sign_ed25519_ref_fe25519_add
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_fe25519_cmov
value|Fssh_crypto_sign_ed25519_ref_fe25519_cmov
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_fe25519_freeze
value|Fssh_crypto_sign_ed25519_ref_fe25519_freeze
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_fe25519_getparity
value|Fssh_crypto_sign_ed25519_ref_fe25519_getparity
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_fe25519_invert
value|Fssh_crypto_sign_ed25519_ref_fe25519_invert
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_fe25519_iseq_vartime
value|Fssh_crypto_sign_ed25519_ref_fe25519_iseq_vartime
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_fe25519_iszero
value|Fssh_crypto_sign_ed25519_ref_fe25519_iszero
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_fe25519_mul
value|Fssh_crypto_sign_ed25519_ref_fe25519_mul
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_fe25519_neg
value|Fssh_crypto_sign_ed25519_ref_fe25519_neg
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_fe25519_pack
value|Fssh_crypto_sign_ed25519_ref_fe25519_pack
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_fe25519_pow2523
value|Fssh_crypto_sign_ed25519_ref_fe25519_pow2523
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_fe25519_setone
value|Fssh_crypto_sign_ed25519_ref_fe25519_setone
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_fe25519_setzero
value|Fssh_crypto_sign_ed25519_ref_fe25519_setzero
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_fe25519_square
value|Fssh_crypto_sign_ed25519_ref_fe25519_square
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_fe25519_sub
value|Fssh_crypto_sign_ed25519_ref_fe25519_sub
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_fe25519_unpack
value|Fssh_crypto_sign_ed25519_ref_fe25519_unpack
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_isneutral_vartime
value|Fssh_crypto_sign_ed25519_ref_isneutral_vartime
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_pack
value|Fssh_crypto_sign_ed25519_ref_pack
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_sc25519_2interleave2
value|Fssh_crypto_sign_ed25519_ref_sc25519_2interleave2
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_sc25519_add
value|Fssh_crypto_sign_ed25519_ref_sc25519_add
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_sc25519_from32bytes
value|Fssh_crypto_sign_ed25519_ref_sc25519_from32bytes
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_sc25519_from64bytes
value|Fssh_crypto_sign_ed25519_ref_sc25519_from64bytes
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_sc25519_from_shortsc
value|Fssh_crypto_sign_ed25519_ref_sc25519_from_shortsc
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_sc25519_isshort_vartime
value|Fssh_crypto_sign_ed25519_ref_sc25519_isshort_vartime
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_sc25519_iszero_vartime
value|Fssh_crypto_sign_ed25519_ref_sc25519_iszero_vartime
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_sc25519_lt_vartime
value|Fssh_crypto_sign_ed25519_ref_sc25519_lt_vartime
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_sc25519_mul
value|Fssh_crypto_sign_ed25519_ref_sc25519_mul
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_sc25519_mul_shortsc
value|Fssh_crypto_sign_ed25519_ref_sc25519_mul_shortsc
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_sc25519_sub_nored
value|Fssh_crypto_sign_ed25519_ref_sc25519_sub_nored
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_sc25519_to32bytes
value|Fssh_crypto_sign_ed25519_ref_sc25519_to32bytes
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_sc25519_window3
value|Fssh_crypto_sign_ed25519_ref_sc25519_window3
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_sc25519_window5
value|Fssh_crypto_sign_ed25519_ref_sc25519_window5
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_scalarmult_base
value|Fssh_crypto_sign_ed25519_ref_scalarmult_base
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_shortsc25519_from16bytes
value|Fssh_crypto_sign_ed25519_ref_shortsc25519_from16bytes
end_define

begin_define
define|#
directive|define
name|crypto_sign_ed25519_ref_unpackneg_vartime
value|Fssh_crypto_sign_ed25519_ref_unpackneg_vartime
end_define

begin_define
define|#
directive|define
name|crypto_verify_32
value|Fssh_crypto_verify_32
end_define

begin_define
define|#
directive|define
name|daemonized
value|Fssh_daemonized
end_define

begin_define
define|#
directive|define
name|dbl_p1p1
value|Fssh_dbl_p1p1
end_define

begin_define
define|#
directive|define
name|deattack_init
value|Fssh_deattack_init
end_define

begin_define
define|#
directive|define
name|debug
value|Fssh_debug
end_define

begin_define
define|#
directive|define
name|debug2
value|Fssh_debug2
end_define

begin_define
define|#
directive|define
name|debug3
value|Fssh_debug3
end_define

begin_define
define|#
directive|define
name|deny_input_open
value|Fssh_deny_input_open
end_define

begin_define
define|#
directive|define
name|detect_attack
value|Fssh_detect_attack
end_define

begin_define
define|#
directive|define
name|dh_estimate
value|Fssh_dh_estimate
end_define

begin_define
define|#
directive|define
name|dh_gen_key
value|Fssh_dh_gen_key
end_define

begin_define
define|#
directive|define
name|dh_new_group
value|Fssh_dh_new_group
end_define

begin_define
define|#
directive|define
name|dh_new_group1
value|Fssh_dh_new_group1
end_define

begin_define
define|#
directive|define
name|dh_new_group14
value|Fssh_dh_new_group14
end_define

begin_define
define|#
directive|define
name|dh_new_group16
value|Fssh_dh_new_group16
end_define

begin_define
define|#
directive|define
name|dh_new_group18
value|Fssh_dh_new_group18
end_define

begin_define
define|#
directive|define
name|dh_new_group_asc
value|Fssh_dh_new_group_asc
end_define

begin_define
define|#
directive|define
name|dh_new_group_fallback
value|Fssh_dh_new_group_fallback
end_define

begin_define
define|#
directive|define
name|dh_pub_is_valid
value|Fssh_dh_pub_is_valid
end_define

begin_define
define|#
directive|define
name|dispatch_protocol_error
value|Fssh_dispatch_protocol_error
end_define

begin_define
define|#
directive|define
name|dispatch_protocol_ignore
value|Fssh_dispatch_protocol_ignore
end_define

begin_define
define|#
directive|define
name|dns_read_key
value|Fssh_dns_read_key
end_define

begin_define
define|#
directive|define
name|do_log
value|Fssh_do_log
end_define

begin_define
define|#
directive|define
name|do_log2
value|Fssh_do_log2
end_define

begin_define
define|#
directive|define
name|dump_base64
value|Fssh_dump_base64
end_define

begin_define
define|#
directive|define
name|enable_compat13
value|Fssh_enable_compat13
end_define

begin_define
define|#
directive|define
name|enable_compat20
value|Fssh_enable_compat20
end_define

begin_define
define|#
directive|define
name|error
value|Fssh_error
end_define

begin_define
define|#
directive|define
name|export_dns_rr
value|Fssh_export_dns_rr
end_define

begin_define
define|#
directive|define
name|fatal
value|Fssh_fatal
end_define

begin_define
define|#
directive|define
name|fingerprint_b64
value|Fssh_fingerprint_b64
end_define

begin_define
define|#
directive|define
name|fingerprint_hex
value|Fssh_fingerprint_hex
end_define

begin_define
define|#
directive|define
name|fmprintf
value|Fssh_fmprintf
end_define

begin_define
define|#
directive|define
name|fmt_scaled
value|Fssh_fmt_scaled
end_define

begin_define
define|#
directive|define
name|forward_equals
value|Fssh_forward_equals
end_define

begin_define
define|#
directive|define
name|free_hostkeys
value|Fssh_free_hostkeys
end_define

begin_define
define|#
directive|define
name|freeargs
value|Fssh_freeargs
end_define

begin_define
define|#
directive|define
name|freerrset
value|Fssh_freerrset
end_define

begin_define
define|#
directive|define
name|gen_candidates
value|Fssh_gen_candidates
end_define

begin_define
define|#
directive|define
name|get_hram
value|Fssh_get_hram
end_define

begin_define
define|#
directive|define
name|get_local_ipaddr
value|Fssh_get_local_ipaddr
end_define

begin_define
define|#
directive|define
name|get_local_name
value|Fssh_get_local_name
end_define

begin_define
define|#
directive|define
name|get_local_port
value|Fssh_get_local_port
end_define

begin_define
define|#
directive|define
name|get_peer_ipaddr
value|Fssh_get_peer_ipaddr
end_define

begin_define
define|#
directive|define
name|get_peer_port
value|Fssh_get_peer_port
end_define

begin_define
define|#
directive|define
name|get_sock_port
value|Fssh_get_sock_port
end_define

begin_define
define|#
directive|define
name|get_socket_address
value|Fssh_get_socket_address
end_define

begin_define
define|#
directive|define
name|get_u16
value|Fssh_get_u16
end_define

begin_define
define|#
directive|define
name|get_u32
value|Fssh_get_u32
end_define

begin_define
define|#
directive|define
name|get_u32_le
value|Fssh_get_u32_le
end_define

begin_define
define|#
directive|define
name|get_u64
value|Fssh_get_u64
end_define

begin_define
define|#
directive|define
name|getrrsetbyname
value|Fssh_getrrsetbyname
end_define

begin_define
define|#
directive|define
name|glob0
value|Fssh_glob0
end_define

begin_define
define|#
directive|define
name|glob2
value|Fssh_glob2
end_define

begin_define
define|#
directive|define
name|globexp1
value|Fssh_globexp1
end_define

begin_define
define|#
directive|define
name|globextend
value|Fssh_globextend
end_define

begin_define
define|#
directive|define
name|host_delete
value|Fssh_host_delete
end_define

begin_define
define|#
directive|define
name|host_hash
value|Fssh_host_hash
end_define

begin_define
define|#
directive|define
name|hostfile_read_key
value|Fssh_hostfile_read_key
end_define

begin_define
define|#
directive|define
name|hostfile_replace_entries
value|Fssh_hostfile_replace_entries
end_define

begin_define
define|#
directive|define
name|hostkeys_foreach
value|Fssh_hostkeys_foreach
end_define

begin_define
define|#
directive|define
name|hpdelim
value|Fssh_hpdelim
end_define

begin_define
define|#
directive|define
name|init_hostkeys
value|Fssh_init_hostkeys
end_define

begin_define
define|#
directive|define
name|input_kex_c25519_init
value|Fssh_input_kex_c25519_init
end_define

begin_define
define|#
directive|define
name|input_kex_c25519_reply
value|Fssh_input_kex_c25519_reply
end_define

begin_define
define|#
directive|define
name|input_kex_dh
value|Fssh_input_kex_dh
end_define

begin_define
define|#
directive|define
name|input_kex_dh_gex_group
value|Fssh_input_kex_dh_gex_group
end_define

begin_define
define|#
directive|define
name|input_kex_dh_gex_init
value|Fssh_input_kex_dh_gex_init
end_define

begin_define
define|#
directive|define
name|input_kex_dh_gex_reply
value|Fssh_input_kex_dh_gex_reply
end_define

begin_define
define|#
directive|define
name|input_kex_dh_gex_request
value|Fssh_input_kex_dh_gex_request
end_define

begin_define
define|#
directive|define
name|input_kex_dh_init
value|Fssh_input_kex_dh_init
end_define

begin_define
define|#
directive|define
name|input_kex_ecdh_init
value|Fssh_input_kex_ecdh_init
end_define

begin_define
define|#
directive|define
name|input_kex_ecdh_reply
value|Fssh_input_kex_ecdh_reply
end_define

begin_define
define|#
directive|define
name|iptos2str
value|Fssh_iptos2str
end_define

begin_define
define|#
directive|define
name|ipv64_normalise_mapped
value|Fssh_ipv64_normalise_mapped
end_define

begin_define
define|#
directive|define
name|is_key_revoked
value|Fssh_is_key_revoked
end_define

begin_define
define|#
directive|define
name|kex_alg_by_name
value|Fssh_kex_alg_by_name
end_define

begin_define
define|#
directive|define
name|kex_alg_list
value|Fssh_kex_alg_list
end_define

begin_define
define|#
directive|define
name|kex_assemble_names
value|Fssh_kex_assemble_names
end_define

begin_define
define|#
directive|define
name|kex_buf2prop
value|Fssh_kex_buf2prop
end_define

begin_define
define|#
directive|define
name|kex_c25519_hash
value|Fssh_kex_c25519_hash
end_define

begin_define
define|#
directive|define
name|kex_derive_keys
value|Fssh_kex_derive_keys
end_define

begin_define
define|#
directive|define
name|kex_derive_keys_bn
value|Fssh_kex_derive_keys_bn
end_define

begin_define
define|#
directive|define
name|kex_dh_hash
value|Fssh_kex_dh_hash
end_define

begin_define
define|#
directive|define
name|kex_ecdh_hash
value|Fssh_kex_ecdh_hash
end_define

begin_define
define|#
directive|define
name|kex_free
value|Fssh_kex_free
end_define

begin_define
define|#
directive|define
name|kex_free_newkeys
value|Fssh_kex_free_newkeys
end_define

begin_define
define|#
directive|define
name|kex_input_ext_info
value|Fssh_kex_input_ext_info
end_define

begin_define
define|#
directive|define
name|kex_input_kexinit
value|Fssh_kex_input_kexinit
end_define

begin_define
define|#
directive|define
name|kex_input_newkeys
value|Fssh_kex_input_newkeys
end_define

begin_define
define|#
directive|define
name|kex_names_cat
value|Fssh_kex_names_cat
end_define

begin_define
define|#
directive|define
name|kex_names_valid
value|Fssh_kex_names_valid
end_define

begin_define
define|#
directive|define
name|kex_new
value|Fssh_kex_new
end_define

begin_define
define|#
directive|define
name|kex_prop2buf
value|Fssh_kex_prop2buf
end_define

begin_define
define|#
directive|define
name|kex_prop_free
value|Fssh_kex_prop_free
end_define

begin_define
define|#
directive|define
name|kex_protocol_error
value|Fssh_kex_protocol_error
end_define

begin_define
define|#
directive|define
name|kex_send_kexinit
value|Fssh_kex_send_kexinit
end_define

begin_define
define|#
directive|define
name|kex_send_newkeys
value|Fssh_kex_send_newkeys
end_define

begin_define
define|#
directive|define
name|kex_setup
value|Fssh_kex_setup
end_define

begin_define
define|#
directive|define
name|kex_start_rekex
value|Fssh_kex_start_rekex
end_define

begin_define
define|#
directive|define
name|kexc25519_client
value|Fssh_kexc25519_client
end_define

begin_define
define|#
directive|define
name|kexc25519_keygen
value|Fssh_kexc25519_keygen
end_define

begin_define
define|#
directive|define
name|kexc25519_server
value|Fssh_kexc25519_server
end_define

begin_define
define|#
directive|define
name|kexc25519_shared_key
value|Fssh_kexc25519_shared_key
end_define

begin_define
define|#
directive|define
name|kexdh_client
value|Fssh_kexdh_client
end_define

begin_define
define|#
directive|define
name|kexdh_server
value|Fssh_kexdh_server
end_define

begin_define
define|#
directive|define
name|kexecdh_client
value|Fssh_kexecdh_client
end_define

begin_define
define|#
directive|define
name|kexecdh_server
value|Fssh_kexecdh_server
end_define

begin_define
define|#
directive|define
name|kexgex_client
value|Fssh_kexgex_client
end_define

begin_define
define|#
directive|define
name|kexgex_hash
value|Fssh_kexgex_hash
end_define

begin_define
define|#
directive|define
name|kexgex_server
value|Fssh_kexgex_server
end_define

begin_define
define|#
directive|define
name|key_add_private
value|Fssh_key_add_private
end_define

begin_define
define|#
directive|define
name|key_cert_check_authority
value|Fssh_key_cert_check_authority
end_define

begin_define
define|#
directive|define
name|key_cert_copy
value|Fssh_key_cert_copy
end_define

begin_define
define|#
directive|define
name|key_certify
value|Fssh_key_certify
end_define

begin_define
define|#
directive|define
name|key_demote
value|Fssh_key_demote
end_define

begin_define
define|#
directive|define
name|key_drop_cert
value|Fssh_key_drop_cert
end_define

begin_define
define|#
directive|define
name|key_ec_validate_private
value|Fssh_key_ec_validate_private
end_define

begin_define
define|#
directive|define
name|key_ec_validate_public
value|Fssh_key_ec_validate_public
end_define

begin_define
define|#
directive|define
name|key_from_blob
value|Fssh_key_from_blob
end_define

begin_define
define|#
directive|define
name|key_from_private
value|Fssh_key_from_private
end_define

begin_define
define|#
directive|define
name|key_generate
value|Fssh_key_generate
end_define

begin_define
define|#
directive|define
name|key_load_cert
value|Fssh_key_load_cert
end_define

begin_define
define|#
directive|define
name|key_load_file
value|Fssh_key_load_file
end_define

begin_define
define|#
directive|define
name|key_load_private
value|Fssh_key_load_private
end_define

begin_define
define|#
directive|define
name|key_load_private_cert
value|Fssh_key_load_private_cert
end_define

begin_define
define|#
directive|define
name|key_load_private_type
value|Fssh_key_load_private_type
end_define

begin_define
define|#
directive|define
name|key_load_public
value|Fssh_key_load_public
end_define

begin_define
define|#
directive|define
name|key_new_private
value|Fssh_key_new_private
end_define

begin_define
define|#
directive|define
name|key_perm_ok
value|Fssh_key_perm_ok
end_define

begin_define
define|#
directive|define
name|key_private_deserialize
value|Fssh_key_private_deserialize
end_define

begin_define
define|#
directive|define
name|key_private_serialize
value|Fssh_key_private_serialize
end_define

begin_define
define|#
directive|define
name|key_read
value|Fssh_key_read
end_define

begin_define
define|#
directive|define
name|key_save_private
value|Fssh_key_save_private
end_define

begin_define
define|#
directive|define
name|key_sign
value|Fssh_key_sign
end_define

begin_define
define|#
directive|define
name|key_to_blob
value|Fssh_key_to_blob
end_define

begin_define
define|#
directive|define
name|key_to_certified
value|Fssh_key_to_certified
end_define

begin_define
define|#
directive|define
name|key_verify
value|Fssh_key_verify
end_define

begin_define
define|#
directive|define
name|key_write
value|Fssh_key_write
end_define

begin_define
define|#
directive|define
name|load_hostkeys
value|Fssh_load_hostkeys
end_define

begin_define
define|#
directive|define
name|log_change_level
value|Fssh_log_change_level
end_define

begin_define
define|#
directive|define
name|log_facility_name
value|Fssh_log_facility_name
end_define

begin_define
define|#
directive|define
name|log_facility_number
value|Fssh_log_facility_number
end_define

begin_define
define|#
directive|define
name|log_init
value|Fssh_log_init
end_define

begin_define
define|#
directive|define
name|log_is_on_stderr
value|Fssh_log_is_on_stderr
end_define

begin_define
define|#
directive|define
name|log_level_name
value|Fssh_log_level_name
end_define

begin_define
define|#
directive|define
name|log_level_number
value|Fssh_log_level_number
end_define

begin_define
define|#
directive|define
name|log_redirect_stderr_to
value|Fssh_log_redirect_stderr_to
end_define

begin_define
define|#
directive|define
name|logdie
value|Fssh_logdie
end_define

begin_define
define|#
directive|define
name|logit
value|Fssh_logit
end_define

begin_define
define|#
directive|define
name|lookup_key_in_hostkeys_by_type
value|Fssh_lookup_key_in_hostkeys_by_type
end_define

begin_define
define|#
directive|define
name|lowercase
value|Fssh_lowercase
end_define

begin_define
define|#
directive|define
name|mac_alg_list
value|Fssh_mac_alg_list
end_define

begin_define
define|#
directive|define
name|mac_check
value|Fssh_mac_check
end_define

begin_define
define|#
directive|define
name|mac_clear
value|Fssh_mac_clear
end_define

begin_define
define|#
directive|define
name|mac_compute
value|Fssh_mac_compute
end_define

begin_define
define|#
directive|define
name|mac_init
value|Fssh_mac_init
end_define

begin_define
define|#
directive|define
name|mac_setup
value|Fssh_mac_setup
end_define

begin_define
define|#
directive|define
name|mac_valid
value|Fssh_mac_valid
end_define

begin_define
define|#
directive|define
name|match
value|Fssh_match
end_define

begin_define
define|#
directive|define
name|match_filter_list
value|Fssh_match_filter_list
end_define

begin_define
define|#
directive|define
name|match_host_and_ip
value|Fssh_match_host_and_ip
end_define

begin_define
define|#
directive|define
name|match_hostname
value|Fssh_match_hostname
end_define

begin_define
define|#
directive|define
name|match_list
value|Fssh_match_list
end_define

begin_define
define|#
directive|define
name|match_pattern
value|Fssh_match_pattern
end_define

begin_define
define|#
directive|define
name|match_pattern_list
value|Fssh_match_pattern_list
end_define

begin_define
define|#
directive|define
name|match_user
value|Fssh_match_user
end_define

begin_define
define|#
directive|define
name|mktemp_proto
value|Fssh_mktemp_proto
end_define

begin_define
define|#
directive|define
name|mm_choose_dh
value|Fssh_mm_choose_dh
end_define

begin_define
define|#
directive|define
name|mm_receive_fd
value|Fssh_mm_receive_fd
end_define

begin_define
define|#
directive|define
name|mm_send_fd
value|Fssh_mm_send_fd
end_define

begin_define
define|#
directive|define
name|mm_sshkey_sign
value|Fssh_mm_sshkey_sign
end_define

begin_define
define|#
directive|define
name|monotime
value|Fssh_monotime
end_define

begin_define
define|#
directive|define
name|monotime_double
value|Fssh_monotime_double
end_define

begin_define
define|#
directive|define
name|mprintf
value|Fssh_mprintf
end_define

begin_define
define|#
directive|define
name|ms_subtract_diff
value|Fssh_ms_subtract_diff
end_define

begin_define
define|#
directive|define
name|ms_to_timeval
value|Fssh_ms_to_timeval
end_define

begin_define
define|#
directive|define
name|msetlocale
value|Fssh_msetlocale
end_define

begin_define
define|#
directive|define
name|mysignal
value|Fssh_mysignal
end_define

begin_define
define|#
directive|define
name|newkeys_from_blob
value|Fssh_newkeys_from_blob
end_define

begin_define
define|#
directive|define
name|newkeys_to_blob
value|Fssh_newkeys_to_blob
end_define

begin_define
define|#
directive|define
name|nh_aux
value|Fssh_nh_aux
end_define

begin_define
define|#
directive|define
name|nh_final
value|Fssh_nh_final
end_define

begin_define
define|#
directive|define
name|packet_close
value|Fssh_packet_close
end_define

begin_define
define|#
directive|define
name|packet_disconnect
value|Fssh_packet_disconnect
end_define

begin_define
define|#
directive|define
name|packet_get_char
value|Fssh_packet_get_char
end_define

begin_define
define|#
directive|define
name|packet_get_int
value|Fssh_packet_get_int
end_define

begin_define
define|#
directive|define
name|packet_process_incoming
value|Fssh_packet_process_incoming
end_define

begin_define
define|#
directive|define
name|packet_read_expect
value|Fssh_packet_read_expect
end_define

begin_define
define|#
directive|define
name|packet_read_poll_seqnr
value|Fssh_packet_read_poll_seqnr
end_define

begin_define
define|#
directive|define
name|packet_read_seqnr
value|Fssh_packet_read_seqnr
end_define

begin_define
define|#
directive|define
name|packet_send_debug
value|Fssh_packet_send_debug
end_define

begin_define
define|#
directive|define
name|packet_set_connection
value|Fssh_packet_set_connection
end_define

begin_define
define|#
directive|define
name|packet_write_poll
value|Fssh_packet_write_poll
end_define

begin_define
define|#
directive|define
name|packet_write_wait
value|Fssh_packet_write_wait
end_define

begin_define
define|#
directive|define
name|parse_ipqos
value|Fssh_parse_ipqos
end_define

begin_define
define|#
directive|define
name|parse_prime
value|Fssh_parse_prime
end_define

begin_define
define|#
directive|define
name|parse_user_host_port
value|Fssh_parse_user_host_port
end_define

begin_define
define|#
directive|define
name|percent_expand
value|Fssh_percent_expand
end_define

begin_define
define|#
directive|define
name|permanently_drop_suid
value|Fssh_permanently_drop_suid
end_define

begin_define
define|#
directive|define
name|permanently_set_uid
value|Fssh_permanently_set_uid
end_define

begin_define
define|#
directive|define
name|permitopen_port
value|Fssh_permitopen_port
end_define

begin_define
define|#
directive|define
name|pkcs11_add_provider
value|Fssh_pkcs11_add_provider
end_define

begin_define
define|#
directive|define
name|pkcs11_del_provider
value|Fssh_pkcs11_del_provider
end_define

begin_define
define|#
directive|define
name|pkcs11_fetch_keys_filter
value|Fssh_pkcs11_fetch_keys_filter
end_define

begin_define
define|#
directive|define
name|pkcs11_find
value|Fssh_pkcs11_find
end_define

begin_define
define|#
directive|define
name|pkcs11_init
value|Fssh_pkcs11_init
end_define

begin_define
define|#
directive|define
name|pkcs11_provider_finalize
value|Fssh_pkcs11_provider_finalize
end_define

begin_define
define|#
directive|define
name|pkcs11_rsa_finish
value|Fssh_pkcs11_rsa_finish
end_define

begin_define
define|#
directive|define
name|pkcs11_rsa_private_decrypt
value|Fssh_pkcs11_rsa_private_decrypt
end_define

begin_define
define|#
directive|define
name|pkcs11_rsa_private_encrypt
value|Fssh_pkcs11_rsa_private_encrypt
end_define

begin_define
define|#
directive|define
name|pkcs11_terminate
value|Fssh_pkcs11_terminate
end_define

begin_define
define|#
directive|define
name|plain_key_blob
value|Fssh_plain_key_blob
end_define

begin_define
define|#
directive|define
name|platform_disable_tracing
value|Fssh_platform_disable_tracing
end_define

begin_define
define|#
directive|define
name|platform_pledge_agent
value|Fssh_platform_pledge_agent
end_define

begin_define
define|#
directive|define
name|platform_pledge_mux
value|Fssh_platform_pledge_mux
end_define

begin_define
define|#
directive|define
name|platform_pledge_sftp_server
value|Fssh_platform_pledge_sftp_server
end_define

begin_define
define|#
directive|define
name|pledge
value|Fssh_pledge
end_define

begin_define
define|#
directive|define
name|poly1305_auth
value|Fssh_poly1305_auth
end_define

begin_define
define|#
directive|define
name|poly64
value|Fssh_poly64
end_define

begin_define
define|#
directive|define
name|poly_hash
value|Fssh_poly_hash
end_define

begin_define
define|#
directive|define
name|port_open_helper
value|Fssh_port_open_helper
end_define

begin_define
define|#
directive|define
name|prime_test
value|Fssh_prime_test
end_define

begin_define
define|#
directive|define
name|proto_spec
value|Fssh_proto_spec
end_define

begin_define
define|#
directive|define
name|put_host_port
value|Fssh_put_host_port
end_define

begin_define
define|#
directive|define
name|put_u16
value|Fssh_put_u16
end_define

begin_define
define|#
directive|define
name|put_u32
value|Fssh_put_u32
end_define

begin_define
define|#
directive|define
name|put_u32_le
value|Fssh_put_u32_le
end_define

begin_define
define|#
directive|define
name|put_u64
value|Fssh_put_u64
end_define

begin_define
define|#
directive|define
name|pwcopy
value|Fssh_pwcopy
end_define

begin_define
define|#
directive|define
name|qfileout
value|Fssh_qfileout
end_define

begin_define
define|#
directive|define
name|read_keyfile_line
value|Fssh_read_keyfile_line
end_define

begin_define
define|#
directive|define
name|read_mux
value|Fssh_read_mux
end_define

begin_define
define|#
directive|define
name|read_passphrase
value|Fssh_read_passphrase
end_define

begin_define
define|#
directive|define
name|recip
value|Fssh_recip
end_define

begin_define
define|#
directive|define
name|record_hostkey
value|Fssh_record_hostkey
end_define

begin_define
define|#
directive|define
name|reduce_add_sub
value|Fssh_reduce_add_sub
end_define

begin_define
define|#
directive|define
name|refresh_progress_meter
value|Fssh_refresh_progress_meter
end_define

begin_define
define|#
directive|define
name|replacearg
value|Fssh_replacearg
end_define

begin_define
define|#
directive|define
name|restore_uid
value|Fssh_restore_uid
end_define

begin_define
define|#
directive|define
name|revoke_blob
value|Fssh_revoke_blob
end_define

begin_define
define|#
directive|define
name|revoked_blob_tree_RB_REMOVE
value|Fssh_revoked_blob_tree_RB_REMOVE
end_define

begin_define
define|#
directive|define
name|revoked_certs_for_ca_key
value|Fssh_revoked_certs_for_ca_key
end_define

begin_define
define|#
directive|define
name|revoked_serial_tree_RB_REMOVE
value|Fssh_revoked_serial_tree_RB_REMOVE
end_define

begin_define
define|#
directive|define
name|rijndaelEncrypt
value|Fssh_rijndaelEncrypt
end_define

begin_define
define|#
directive|define
name|rijndaelKeySetupEnc
value|Fssh_rijndaelKeySetupEnc
end_define

begin_define
define|#
directive|define
name|rsa_generate_additional_parameters
value|Fssh_rsa_generate_additional_parameters
end_define

begin_define
define|#
directive|define
name|rsa_private_decrypt
value|Fssh_rsa_private_decrypt
end_define

begin_define
define|#
directive|define
name|rsa_public_encrypt
value|Fssh_rsa_public_encrypt
end_define

begin_define
define|#
directive|define
name|sanitise_stdfd
value|Fssh_sanitise_stdfd
end_define

begin_define
define|#
directive|define
name|scan_scaled
value|Fssh_scan_scaled
end_define

begin_define
define|#
directive|define
name|seed_rng
value|Fssh_seed_rng
end_define

begin_define
define|#
directive|define
name|set_log_handler
value|Fssh_set_log_handler
end_define

begin_define
define|#
directive|define
name|set_nodelay
value|Fssh_set_nodelay
end_define

begin_define
define|#
directive|define
name|set_nonblock
value|Fssh_set_nonblock
end_define

begin_define
define|#
directive|define
name|shadow_pw
value|Fssh_shadow_pw
end_define

begin_define
define|#
directive|define
name|sieve_large
value|Fssh_sieve_large
end_define

begin_define
define|#
directive|define
name|sig_winch
value|Fssh_sig_winch
end_define

begin_define
define|#
directive|define
name|sigdie
value|Fssh_sigdie
end_define

begin_define
define|#
directive|define
name|snmprintf
value|Fssh_snmprintf
end_define

begin_define
define|#
directive|define
name|sock_set_v6only
value|Fssh_sock_set_v6only
end_define

begin_define
define|#
directive|define
name|speed_to_baud
value|Fssh_speed_to_baud
end_define

begin_define
define|#
directive|define
name|ssh_OpenSSL_add_all_algorithms
value|Fssh_ssh_OpenSSL_add_all_algorithms
end_define

begin_define
define|#
directive|define
name|ssh_add_hostkey
value|Fssh_ssh_add_hostkey
end_define

begin_define
define|#
directive|define
name|ssh_add_identity_constrained
value|Fssh_ssh_add_identity_constrained
end_define

begin_define
define|#
directive|define
name|ssh_agent_sign
value|Fssh_ssh_agent_sign
end_define

begin_define
define|#
directive|define
name|ssh_alloc_session_state
value|Fssh_ssh_alloc_session_state
end_define

begin_define
define|#
directive|define
name|ssh_close_authentication_socket
value|Fssh_ssh_close_authentication_socket
end_define

begin_define
define|#
directive|define
name|ssh_compatible_openssl
value|Fssh_ssh_compatible_openssl
end_define

begin_define
define|#
directive|define
name|ssh_crc32
value|Fssh_ssh_crc32
end_define

begin_define
define|#
directive|define
name|ssh_digest_alg_by_name
value|Fssh_ssh_digest_alg_by_name
end_define

begin_define
define|#
directive|define
name|ssh_digest_alg_name
value|Fssh_ssh_digest_alg_name
end_define

begin_define
define|#
directive|define
name|ssh_digest_blocksize
value|Fssh_ssh_digest_blocksize
end_define

begin_define
define|#
directive|define
name|ssh_digest_buffer
value|Fssh_ssh_digest_buffer
end_define

begin_define
define|#
directive|define
name|ssh_digest_bytes
value|Fssh_ssh_digest_bytes
end_define

begin_define
define|#
directive|define
name|ssh_digest_copy_state
value|Fssh_ssh_digest_copy_state
end_define

begin_define
define|#
directive|define
name|ssh_digest_final
value|Fssh_ssh_digest_final
end_define

begin_define
define|#
directive|define
name|ssh_digest_free
value|Fssh_ssh_digest_free
end_define

begin_define
define|#
directive|define
name|ssh_digest_memory
value|Fssh_ssh_digest_memory
end_define

begin_define
define|#
directive|define
name|ssh_digest_start
value|Fssh_ssh_digest_start
end_define

begin_define
define|#
directive|define
name|ssh_digest_update
value|Fssh_ssh_digest_update
end_define

begin_define
define|#
directive|define
name|ssh_digest_update_buffer
value|Fssh_ssh_digest_update_buffer
end_define

begin_define
define|#
directive|define
name|ssh_dispatch_init
value|Fssh_ssh_dispatch_init
end_define

begin_define
define|#
directive|define
name|ssh_dispatch_range
value|Fssh_ssh_dispatch_range
end_define

begin_define
define|#
directive|define
name|ssh_dispatch_run
value|Fssh_ssh_dispatch_run
end_define

begin_define
define|#
directive|define
name|ssh_dispatch_run_fatal
value|Fssh_ssh_dispatch_run_fatal
end_define

begin_define
define|#
directive|define
name|ssh_dispatch_set
value|Fssh_ssh_dispatch_set
end_define

begin_define
define|#
directive|define
name|ssh_dss_sign
value|Fssh_ssh_dss_sign
end_define

begin_define
define|#
directive|define
name|ssh_dss_verify
value|Fssh_ssh_dss_verify
end_define

begin_define
define|#
directive|define
name|ssh_ecdsa_sign
value|Fssh_ssh_ecdsa_sign
end_define

begin_define
define|#
directive|define
name|ssh_ecdsa_verify
value|Fssh_ssh_ecdsa_verify
end_define

begin_define
define|#
directive|define
name|ssh_ed25519_sign
value|Fssh_ssh_ed25519_sign
end_define

begin_define
define|#
directive|define
name|ssh_ed25519_verify
value|Fssh_ssh_ed25519_verify
end_define

begin_define
define|#
directive|define
name|ssh_err
value|Fssh_ssh_err
end_define

begin_define
define|#
directive|define
name|ssh_fetch_identitylist
value|Fssh_ssh_fetch_identitylist
end_define

begin_define
define|#
directive|define
name|ssh_free
value|Fssh_ssh_free
end_define

begin_define
define|#
directive|define
name|ssh_free_identitylist
value|Fssh_ssh_free_identitylist
end_define

begin_define
define|#
directive|define
name|ssh_gai_strerror
value|Fssh_ssh_gai_strerror
end_define

begin_define
define|#
directive|define
name|ssh_get_app_data
value|Fssh_ssh_get_app_data
end_define

begin_define
define|#
directive|define
name|ssh_get_authentication_socket
value|Fssh_ssh_get_authentication_socket
end_define

begin_define
define|#
directive|define
name|ssh_get_progname
value|Fssh_ssh_get_progname
end_define

begin_define
define|#
directive|define
name|ssh_hmac_bytes
value|Fssh_ssh_hmac_bytes
end_define

begin_define
define|#
directive|define
name|ssh_hmac_final
value|Fssh_ssh_hmac_final
end_define

begin_define
define|#
directive|define
name|ssh_hmac_free
value|Fssh_ssh_hmac_free
end_define

begin_define
define|#
directive|define
name|ssh_hmac_init
value|Fssh_ssh_hmac_init
end_define

begin_define
define|#
directive|define
name|ssh_hmac_start
value|Fssh_ssh_hmac_start
end_define

begin_define
define|#
directive|define
name|ssh_hmac_update
value|Fssh_ssh_hmac_update
end_define

begin_define
define|#
directive|define
name|ssh_hmac_update_buffer
value|Fssh_ssh_hmac_update_buffer
end_define

begin_define
define|#
directive|define
name|ssh_init
value|Fssh_ssh_init
end_define

begin_define
define|#
directive|define
name|ssh_input_append
value|Fssh_ssh_input_append
end_define

begin_define
define|#
directive|define
name|ssh_input_space
value|Fssh_ssh_input_space
end_define

begin_define
define|#
directive|define
name|ssh_krl_check_key
value|Fssh_ssh_krl_check_key
end_define

begin_define
define|#
directive|define
name|ssh_krl_file_contains_key
value|Fssh_ssh_krl_file_contains_key
end_define

begin_define
define|#
directive|define
name|ssh_krl_free
value|Fssh_ssh_krl_free
end_define

begin_define
define|#
directive|define
name|ssh_krl_from_blob
value|Fssh_ssh_krl_from_blob
end_define

begin_define
define|#
directive|define
name|ssh_krl_init
value|Fssh_ssh_krl_init
end_define

begin_define
define|#
directive|define
name|ssh_krl_revoke_cert_by_key_id
value|Fssh_ssh_krl_revoke_cert_by_key_id
end_define

begin_define
define|#
directive|define
name|ssh_krl_revoke_cert_by_serial
value|Fssh_ssh_krl_revoke_cert_by_serial
end_define

begin_define
define|#
directive|define
name|ssh_krl_revoke_cert_by_serial_range
value|Fssh_ssh_krl_revoke_cert_by_serial_range
end_define

begin_define
define|#
directive|define
name|ssh_krl_revoke_key
value|Fssh_ssh_krl_revoke_key
end_define

begin_define
define|#
directive|define
name|ssh_krl_revoke_key_explicit
value|Fssh_ssh_krl_revoke_key_explicit
end_define

begin_define
define|#
directive|define
name|ssh_krl_revoke_key_sha1
value|Fssh_ssh_krl_revoke_key_sha1
end_define

begin_define
define|#
directive|define
name|ssh_krl_set_comment
value|Fssh_ssh_krl_set_comment
end_define

begin_define
define|#
directive|define
name|ssh_krl_set_version
value|Fssh_ssh_krl_set_version
end_define

begin_define
define|#
directive|define
name|ssh_krl_to_blob
value|Fssh_ssh_krl_to_blob
end_define

begin_define
define|#
directive|define
name|ssh_local_ipaddr
value|Fssh_ssh_local_ipaddr
end_define

begin_define
define|#
directive|define
name|ssh_local_port
value|Fssh_ssh_local_port
end_define

begin_define
define|#
directive|define
name|ssh_lock_agent
value|Fssh_ssh_lock_agent
end_define

begin_define
define|#
directive|define
name|ssh_malloc_init
value|Fssh_ssh_malloc_init
end_define

begin_define
define|#
directive|define
name|ssh_msg_recv
value|Fssh_ssh_msg_recv
end_define

begin_define
define|#
directive|define
name|ssh_msg_send
value|Fssh_ssh_msg_send
end_define

begin_define
define|#
directive|define
name|ssh_output_consume
value|Fssh_ssh_output_consume
end_define

begin_define
define|#
directive|define
name|ssh_output_ptr
value|Fssh_ssh_output_ptr
end_define

begin_define
define|#
directive|define
name|ssh_output_space
value|Fssh_ssh_output_space
end_define

begin_define
define|#
directive|define
name|ssh_packet_close
value|Fssh_ssh_packet_close
end_define

begin_define
define|#
directive|define
name|ssh_packet_connection_af
value|Fssh_ssh_packet_connection_af
end_define

begin_define
define|#
directive|define
name|ssh_packet_connection_is_on_socket
value|Fssh_ssh_packet_connection_is_on_socket
end_define

begin_define
define|#
directive|define
name|ssh_packet_disconnect
value|Fssh_ssh_packet_disconnect
end_define

begin_define
define|#
directive|define
name|ssh_packet_enable_delayed_compress
value|Fssh_ssh_packet_enable_delayed_compress
end_define

begin_define
define|#
directive|define
name|ssh_packet_get_bignum2
value|Fssh_ssh_packet_get_bignum2
end_define

begin_define
define|#
directive|define
name|ssh_packet_get_bytes
value|Fssh_ssh_packet_get_bytes
end_define

begin_define
define|#
directive|define
name|ssh_packet_get_char
value|Fssh_ssh_packet_get_char
end_define

begin_define
define|#
directive|define
name|ssh_packet_get_connection_in
value|Fssh_ssh_packet_get_connection_in
end_define

begin_define
define|#
directive|define
name|ssh_packet_get_connection_out
value|Fssh_ssh_packet_get_connection_out
end_define

begin_define
define|#
directive|define
name|ssh_packet_get_cstring
value|Fssh_ssh_packet_get_cstring
end_define

begin_define
define|#
directive|define
name|ssh_packet_get_ecpoint
value|Fssh_ssh_packet_get_ecpoint
end_define

begin_define
define|#
directive|define
name|ssh_packet_get_input
value|Fssh_ssh_packet_get_input
end_define

begin_define
define|#
directive|define
name|ssh_packet_get_int
value|Fssh_ssh_packet_get_int
end_define

begin_define
define|#
directive|define
name|ssh_packet_get_int64
value|Fssh_ssh_packet_get_int64
end_define

begin_define
define|#
directive|define
name|ssh_packet_get_maxsize
value|Fssh_ssh_packet_get_maxsize
end_define

begin_define
define|#
directive|define
name|ssh_packet_get_mux
value|Fssh_ssh_packet_get_mux
end_define

begin_define
define|#
directive|define
name|ssh_packet_get_output
value|Fssh_ssh_packet_get_output
end_define

begin_define
define|#
directive|define
name|ssh_packet_get_protocol_flags
value|Fssh_ssh_packet_get_protocol_flags
end_define

begin_define
define|#
directive|define
name|ssh_packet_get_rekey_timeout
value|Fssh_ssh_packet_get_rekey_timeout
end_define

begin_define
define|#
directive|define
name|ssh_packet_get_state
value|Fssh_ssh_packet_get_state
end_define

begin_define
define|#
directive|define
name|ssh_packet_get_string
value|Fssh_ssh_packet_get_string
end_define

begin_define
define|#
directive|define
name|ssh_packet_get_string_ptr
value|Fssh_ssh_packet_get_string_ptr
end_define

begin_define
define|#
directive|define
name|ssh_packet_have_data_to_write
value|Fssh_ssh_packet_have_data_to_write
end_define

begin_define
define|#
directive|define
name|ssh_packet_inc_alive_timeouts
value|Fssh_ssh_packet_inc_alive_timeouts
end_define

begin_define
define|#
directive|define
name|ssh_packet_is_interactive
value|Fssh_ssh_packet_is_interactive
end_define

begin_define
define|#
directive|define
name|ssh_packet_is_rekeying
value|Fssh_ssh_packet_is_rekeying
end_define

begin_define
define|#
directive|define
name|ssh_packet_log_type
value|Fssh_ssh_packet_log_type
end_define

begin_define
define|#
directive|define
name|ssh_packet_need_rekeying
value|Fssh_ssh_packet_need_rekeying
end_define

begin_define
define|#
directive|define
name|ssh_packet_next
value|Fssh_ssh_packet_next
end_define

begin_define
define|#
directive|define
name|ssh_packet_not_very_much_data_to_write
value|Fssh_ssh_packet_not_very_much_data_to_write
end_define

begin_define
define|#
directive|define
name|ssh_packet_payload
value|Fssh_ssh_packet_payload
end_define

begin_define
define|#
directive|define
name|ssh_packet_process_incoming
value|Fssh_ssh_packet_process_incoming
end_define

begin_define
define|#
directive|define
name|ssh_packet_put
value|Fssh_ssh_packet_put
end_define

begin_define
define|#
directive|define
name|ssh_packet_put_bignum2
value|Fssh_ssh_packet_put_bignum2
end_define

begin_define
define|#
directive|define
name|ssh_packet_put_char
value|Fssh_ssh_packet_put_char
end_define

begin_define
define|#
directive|define
name|ssh_packet_put_cstring
value|Fssh_ssh_packet_put_cstring
end_define

begin_define
define|#
directive|define
name|ssh_packet_put_ecpoint
value|Fssh_ssh_packet_put_ecpoint
end_define

begin_define
define|#
directive|define
name|ssh_packet_put_int
value|Fssh_ssh_packet_put_int
end_define

begin_define
define|#
directive|define
name|ssh_packet_put_int64
value|Fssh_ssh_packet_put_int64
end_define

begin_define
define|#
directive|define
name|ssh_packet_put_raw
value|Fssh_ssh_packet_put_raw
end_define

begin_define
define|#
directive|define
name|ssh_packet_put_string
value|Fssh_ssh_packet_put_string
end_define

begin_define
define|#
directive|define
name|ssh_packet_read
value|Fssh_ssh_packet_read
end_define

begin_define
define|#
directive|define
name|ssh_packet_read_expect
value|Fssh_ssh_packet_read_expect
end_define

begin_define
define|#
directive|define
name|ssh_packet_read_poll1
value|Fssh_ssh_packet_read_poll1
end_define

begin_define
define|#
directive|define
name|ssh_packet_read_poll2
value|Fssh_ssh_packet_read_poll2
end_define

begin_define
define|#
directive|define
name|ssh_packet_read_poll_seqnr
value|Fssh_ssh_packet_read_poll_seqnr
end_define

begin_define
define|#
directive|define
name|ssh_packet_read_seqnr
value|Fssh_ssh_packet_read_seqnr
end_define

begin_define
define|#
directive|define
name|ssh_packet_remaining
value|Fssh_ssh_packet_remaining
end_define

begin_define
define|#
directive|define
name|ssh_packet_send
value|Fssh_ssh_packet_send
end_define

begin_define
define|#
directive|define
name|ssh_packet_send1
value|Fssh_ssh_packet_send1
end_define

begin_define
define|#
directive|define
name|ssh_packet_send2
value|Fssh_ssh_packet_send2
end_define

begin_define
define|#
directive|define
name|ssh_packet_send2_wrapped
value|Fssh_ssh_packet_send2_wrapped
end_define

begin_define
define|#
directive|define
name|ssh_packet_send_debug
value|Fssh_ssh_packet_send_debug
end_define

begin_define
define|#
directive|define
name|ssh_packet_send_ignore
value|Fssh_ssh_packet_send_ignore
end_define

begin_define
define|#
directive|define
name|ssh_packet_set_alive_timeouts
value|Fssh_ssh_packet_set_alive_timeouts
end_define

begin_define
define|#
directive|define
name|ssh_packet_set_authenticated
value|Fssh_ssh_packet_set_authenticated
end_define

begin_define
define|#
directive|define
name|ssh_packet_set_connection
value|Fssh_ssh_packet_set_connection
end_define

begin_define
define|#
directive|define
name|ssh_packet_set_encryption_key
value|Fssh_ssh_packet_set_encryption_key
end_define

begin_define
define|#
directive|define
name|ssh_packet_set_input_hook
value|Fssh_ssh_packet_set_input_hook
end_define

begin_define
define|#
directive|define
name|ssh_packet_set_interactive
value|Fssh_ssh_packet_set_interactive
end_define

begin_define
define|#
directive|define
name|ssh_packet_set_log_preamble
value|Fssh_ssh_packet_set_log_preamble
end_define

begin_define
define|#
directive|define
name|ssh_packet_set_maxsize
value|Fssh_ssh_packet_set_maxsize
end_define

begin_define
define|#
directive|define
name|ssh_packet_set_mux
value|Fssh_ssh_packet_set_mux
end_define

begin_define
define|#
directive|define
name|ssh_packet_set_nonblocking
value|Fssh_ssh_packet_set_nonblocking
end_define

begin_define
define|#
directive|define
name|ssh_packet_set_protocol_flags
value|Fssh_ssh_packet_set_protocol_flags
end_define

begin_define
define|#
directive|define
name|ssh_packet_set_rekey_limits
value|Fssh_ssh_packet_set_rekey_limits
end_define

begin_define
define|#
directive|define
name|ssh_packet_set_server
value|Fssh_ssh_packet_set_server
end_define

begin_define
define|#
directive|define
name|ssh_packet_set_state
value|Fssh_ssh_packet_set_state
end_define

begin_define
define|#
directive|define
name|ssh_packet_set_timeout
value|Fssh_ssh_packet_set_timeout
end_define

begin_define
define|#
directive|define
name|ssh_packet_set_tos
value|Fssh_ssh_packet_set_tos
end_define

begin_define
define|#
directive|define
name|ssh_packet_start
value|Fssh_ssh_packet_start
end_define

begin_define
define|#
directive|define
name|ssh_packet_start_compression
value|Fssh_ssh_packet_start_compression
end_define

begin_define
define|#
directive|define
name|ssh_packet_start_discard
value|Fssh_ssh_packet_start_discard
end_define

begin_define
define|#
directive|define
name|ssh_packet_stop_discard
value|Fssh_ssh_packet_stop_discard
end_define

begin_define
define|#
directive|define
name|ssh_packet_write_poll
value|Fssh_ssh_packet_write_poll
end_define

begin_define
define|#
directive|define
name|ssh_packet_write_wait
value|Fssh_ssh_packet_write_wait
end_define

begin_define
define|#
directive|define
name|ssh_remote_ipaddr
value|Fssh_ssh_remote_ipaddr
end_define

begin_define
define|#
directive|define
name|ssh_remote_port
value|Fssh_ssh_remote_port
end_define

begin_define
define|#
directive|define
name|ssh_remove_all_identities
value|Fssh_ssh_remove_all_identities
end_define

begin_define
define|#
directive|define
name|ssh_remove_identity
value|Fssh_ssh_remove_identity
end_define

begin_define
define|#
directive|define
name|ssh_request_reply
value|Fssh_ssh_request_reply
end_define

begin_define
define|#
directive|define
name|ssh_rsa_sign
value|Fssh_ssh_rsa_sign
end_define

begin_define
define|#
directive|define
name|ssh_rsa_verify
value|Fssh_ssh_rsa_verify
end_define

begin_define
define|#
directive|define
name|ssh_set_app_data
value|Fssh_ssh_set_app_data
end_define

begin_define
define|#
directive|define
name|ssh_set_newkeys
value|Fssh_ssh_set_newkeys
end_define

begin_define
define|#
directive|define
name|ssh_set_verify_host_key_callback
value|Fssh_ssh_set_verify_host_key_callback
end_define

begin_define
define|#
directive|define
name|ssh_update_card
value|Fssh_ssh_update_card
end_define

begin_define
define|#
directive|define
name|sshbuf_alloc
value|Fssh_sshbuf_alloc
end_define

begin_define
define|#
directive|define
name|sshbuf_allocate
value|Fssh_sshbuf_allocate
end_define

begin_define
define|#
directive|define
name|sshbuf_avail
value|Fssh_sshbuf_avail
end_define

begin_define
define|#
directive|define
name|sshbuf_b64tod
value|Fssh_sshbuf_b64tod
end_define

begin_define
define|#
directive|define
name|sshbuf_check_reserve
value|Fssh_sshbuf_check_reserve
end_define

begin_define
define|#
directive|define
name|sshbuf_consume
value|Fssh_sshbuf_consume
end_define

begin_define
define|#
directive|define
name|sshbuf_consume_end
value|Fssh_sshbuf_consume_end
end_define

begin_define
define|#
directive|define
name|sshbuf_dtob16
value|Fssh_sshbuf_dtob16
end_define

begin_define
define|#
directive|define
name|sshbuf_dtob64
value|Fssh_sshbuf_dtob64
end_define

begin_define
define|#
directive|define
name|sshbuf_dump
value|Fssh_sshbuf_dump
end_define

begin_define
define|#
directive|define
name|sshbuf_dump_data
value|Fssh_sshbuf_dump_data
end_define

begin_define
define|#
directive|define
name|sshbuf_dup_string
value|Fssh_sshbuf_dup_string
end_define

begin_define
define|#
directive|define
name|sshbuf_free
value|Fssh_sshbuf_free
end_define

begin_define
define|#
directive|define
name|sshbuf_from
value|Fssh_sshbuf_from
end_define

begin_define
define|#
directive|define
name|sshbuf_fromb
value|Fssh_sshbuf_fromb
end_define

begin_define
define|#
directive|define
name|sshbuf_froms
value|Fssh_sshbuf_froms
end_define

begin_define
define|#
directive|define
name|sshbuf_get
value|Fssh_sshbuf_get
end_define

begin_define
define|#
directive|define
name|sshbuf_get_bignum1
value|Fssh_sshbuf_get_bignum1
end_define

begin_define
define|#
directive|define
name|sshbuf_get_bignum2
value|Fssh_sshbuf_get_bignum2
end_define

begin_define
define|#
directive|define
name|sshbuf_get_bignum2_bytes_direct
value|Fssh_sshbuf_get_bignum2_bytes_direct
end_define

begin_define
define|#
directive|define
name|sshbuf_get_cstring
value|Fssh_sshbuf_get_cstring
end_define

begin_define
define|#
directive|define
name|sshbuf_get_ec
value|Fssh_sshbuf_get_ec
end_define

begin_define
define|#
directive|define
name|sshbuf_get_eckey
value|Fssh_sshbuf_get_eckey
end_define

begin_define
define|#
directive|define
name|sshbuf_get_string
value|Fssh_sshbuf_get_string
end_define

begin_define
define|#
directive|define
name|sshbuf_get_string_direct
value|Fssh_sshbuf_get_string_direct
end_define

begin_define
define|#
directive|define
name|sshbuf_get_stringb
value|Fssh_sshbuf_get_stringb
end_define

begin_define
define|#
directive|define
name|sshbuf_get_u16
value|Fssh_sshbuf_get_u16
end_define

begin_define
define|#
directive|define
name|sshbuf_get_u32
value|Fssh_sshbuf_get_u32
end_define

begin_define
define|#
directive|define
name|sshbuf_get_u64
value|Fssh_sshbuf_get_u64
end_define

begin_define
define|#
directive|define
name|sshbuf_get_u8
value|Fssh_sshbuf_get_u8
end_define

begin_define
define|#
directive|define
name|sshbuf_init
value|Fssh_sshbuf_init
end_define

begin_define
define|#
directive|define
name|sshbuf_len
value|Fssh_sshbuf_len
end_define

begin_define
define|#
directive|define
name|sshbuf_max_size
value|Fssh_sshbuf_max_size
end_define

begin_define
define|#
directive|define
name|sshbuf_mutable_ptr
value|Fssh_sshbuf_mutable_ptr
end_define

begin_define
define|#
directive|define
name|sshbuf_new
value|Fssh_sshbuf_new
end_define

begin_define
define|#
directive|define
name|sshbuf_parent
value|Fssh_sshbuf_parent
end_define

begin_define
define|#
directive|define
name|sshbuf_peek_string_direct
value|Fssh_sshbuf_peek_string_direct
end_define

begin_define
define|#
directive|define
name|sshbuf_ptr
value|Fssh_sshbuf_ptr
end_define

begin_define
define|#
directive|define
name|sshbuf_put
value|Fssh_sshbuf_put
end_define

begin_define
define|#
directive|define
name|sshbuf_put_bignum1
value|Fssh_sshbuf_put_bignum1
end_define

begin_define
define|#
directive|define
name|sshbuf_put_bignum2
value|Fssh_sshbuf_put_bignum2
end_define

begin_define
define|#
directive|define
name|sshbuf_put_bignum2_bytes
value|Fssh_sshbuf_put_bignum2_bytes
end_define

begin_define
define|#
directive|define
name|sshbuf_put_cstring
value|Fssh_sshbuf_put_cstring
end_define

begin_define
define|#
directive|define
name|sshbuf_put_ec
value|Fssh_sshbuf_put_ec
end_define

begin_define
define|#
directive|define
name|sshbuf_put_eckey
value|Fssh_sshbuf_put_eckey
end_define

begin_define
define|#
directive|define
name|sshbuf_put_string
value|Fssh_sshbuf_put_string
end_define

begin_define
define|#
directive|define
name|sshbuf_put_stringb
value|Fssh_sshbuf_put_stringb
end_define

begin_define
define|#
directive|define
name|sshbuf_put_u16
value|Fssh_sshbuf_put_u16
end_define

begin_define
define|#
directive|define
name|sshbuf_put_u32
value|Fssh_sshbuf_put_u32
end_define

begin_define
define|#
directive|define
name|sshbuf_put_u64
value|Fssh_sshbuf_put_u64
end_define

begin_define
define|#
directive|define
name|sshbuf_put_u8
value|Fssh_sshbuf_put_u8
end_define

begin_define
define|#
directive|define
name|sshbuf_putb
value|Fssh_sshbuf_putb
end_define

begin_define
define|#
directive|define
name|sshbuf_putf
value|Fssh_sshbuf_putf
end_define

begin_define
define|#
directive|define
name|sshbuf_putfv
value|Fssh_sshbuf_putfv
end_define

begin_define
define|#
directive|define
name|sshbuf_refcount
value|Fssh_sshbuf_refcount
end_define

begin_define
define|#
directive|define
name|sshbuf_reserve
value|Fssh_sshbuf_reserve
end_define

begin_define
define|#
directive|define
name|sshbuf_reset
value|Fssh_sshbuf_reset
end_define

begin_define
define|#
directive|define
name|sshbuf_set_max_size
value|Fssh_sshbuf_set_max_size
end_define

begin_define
define|#
directive|define
name|sshbuf_set_parent
value|Fssh_sshbuf_set_parent
end_define

begin_define
define|#
directive|define
name|sshkey_add_private
value|Fssh_sshkey_add_private
end_define

begin_define
define|#
directive|define
name|sshkey_alg_list
value|Fssh_sshkey_alg_list
end_define

begin_define
define|#
directive|define
name|sshkey_cert_check_authority
value|Fssh_sshkey_cert_check_authority
end_define

begin_define
define|#
directive|define
name|sshkey_cert_copy
value|Fssh_sshkey_cert_copy
end_define

begin_define
define|#
directive|define
name|sshkey_cert_type
value|Fssh_sshkey_cert_type
end_define

begin_define
define|#
directive|define
name|sshkey_certify
value|Fssh_sshkey_certify
end_define

begin_define
define|#
directive|define
name|sshkey_check_revoked
value|Fssh_sshkey_check_revoked
end_define

begin_define
define|#
directive|define
name|sshkey_curve_name_to_nid
value|Fssh_sshkey_curve_name_to_nid
end_define

begin_define
define|#
directive|define
name|sshkey_curve_nid_to_bits
value|Fssh_sshkey_curve_nid_to_bits
end_define

begin_define
define|#
directive|define
name|sshkey_curve_nid_to_name
value|Fssh_sshkey_curve_nid_to_name
end_define

begin_define
define|#
directive|define
name|sshkey_demote
value|Fssh_sshkey_demote
end_define

begin_define
define|#
directive|define
name|sshkey_drop_cert
value|Fssh_sshkey_drop_cert
end_define

begin_define
define|#
directive|define
name|sshkey_dump_ec_key
value|Fssh_sshkey_dump_ec_key
end_define

begin_define
define|#
directive|define
name|sshkey_dump_ec_point
value|Fssh_sshkey_dump_ec_point
end_define

begin_define
define|#
directive|define
name|sshkey_ec_nid_to_hash_alg
value|Fssh_sshkey_ec_nid_to_hash_alg
end_define

begin_define
define|#
directive|define
name|sshkey_ec_validate_private
value|Fssh_sshkey_ec_validate_private
end_define

begin_define
define|#
directive|define
name|sshkey_ec_validate_public
value|Fssh_sshkey_ec_validate_public
end_define

begin_define
define|#
directive|define
name|sshkey_ecdsa_bits_to_nid
value|Fssh_sshkey_ecdsa_bits_to_nid
end_define

begin_define
define|#
directive|define
name|sshkey_ecdsa_key_to_nid
value|Fssh_sshkey_ecdsa_key_to_nid
end_define

begin_define
define|#
directive|define
name|sshkey_ecdsa_nid_from_name
value|Fssh_sshkey_ecdsa_nid_from_name
end_define

begin_define
define|#
directive|define
name|sshkey_equal
value|Fssh_sshkey_equal
end_define

begin_define
define|#
directive|define
name|sshkey_equal_public
value|Fssh_sshkey_equal_public
end_define

begin_define
define|#
directive|define
name|sshkey_fingerprint
value|Fssh_sshkey_fingerprint
end_define

begin_define
define|#
directive|define
name|sshkey_fingerprint_raw
value|Fssh_sshkey_fingerprint_raw
end_define

begin_define
define|#
directive|define
name|sshkey_format_cert_validity
value|Fssh_sshkey_format_cert_validity
end_define

begin_define
define|#
directive|define
name|sshkey_free
value|Fssh_sshkey_free
end_define

begin_define
define|#
directive|define
name|sshkey_from_blob
value|Fssh_sshkey_from_blob
end_define

begin_define
define|#
directive|define
name|sshkey_from_blob_internal
value|Fssh_sshkey_from_blob_internal
end_define

begin_define
define|#
directive|define
name|sshkey_from_private
value|Fssh_sshkey_from_private
end_define

begin_define
define|#
directive|define
name|sshkey_fromb
value|Fssh_sshkey_fromb
end_define

begin_define
define|#
directive|define
name|sshkey_froms
value|Fssh_sshkey_froms
end_define

begin_define
define|#
directive|define
name|sshkey_generate
value|Fssh_sshkey_generate
end_define

begin_define
define|#
directive|define
name|sshkey_in_file
value|Fssh_sshkey_in_file
end_define

begin_define
define|#
directive|define
name|sshkey_is_cert
value|Fssh_sshkey_is_cert
end_define

begin_define
define|#
directive|define
name|sshkey_load_cert
value|Fssh_sshkey_load_cert
end_define

begin_define
define|#
directive|define
name|sshkey_load_file
value|Fssh_sshkey_load_file
end_define

begin_define
define|#
directive|define
name|sshkey_load_private
value|Fssh_sshkey_load_private
end_define

begin_define
define|#
directive|define
name|sshkey_load_private_cert
value|Fssh_sshkey_load_private_cert
end_define

begin_define
define|#
directive|define
name|sshkey_load_private_type
value|Fssh_sshkey_load_private_type
end_define

begin_define
define|#
directive|define
name|sshkey_load_private_type_fd
value|Fssh_sshkey_load_private_type_fd
end_define

begin_define
define|#
directive|define
name|sshkey_load_public
value|Fssh_sshkey_load_public
end_define

begin_define
define|#
directive|define
name|sshkey_names_valid2
value|Fssh_sshkey_names_valid2
end_define

begin_define
define|#
directive|define
name|sshkey_new
value|Fssh_sshkey_new
end_define

begin_define
define|#
directive|define
name|sshkey_new_private
value|Fssh_sshkey_new_private
end_define

begin_define
define|#
directive|define
name|sshkey_parse_private2
value|Fssh_sshkey_parse_private2
end_define

begin_define
define|#
directive|define
name|sshkey_parse_private_fileblob
value|Fssh_sshkey_parse_private_fileblob
end_define

begin_define
define|#
directive|define
name|sshkey_parse_private_fileblob_type
value|Fssh_sshkey_parse_private_fileblob_type
end_define

begin_define
define|#
directive|define
name|sshkey_parse_private_pem_fileblob
value|Fssh_sshkey_parse_private_pem_fileblob
end_define

begin_define
define|#
directive|define
name|sshkey_perm_ok
value|Fssh_sshkey_perm_ok
end_define

begin_define
define|#
directive|define
name|sshkey_plain_to_blob
value|Fssh_sshkey_plain_to_blob
end_define

begin_define
define|#
directive|define
name|sshkey_private_deserialize
value|Fssh_sshkey_private_deserialize
end_define

begin_define
define|#
directive|define
name|sshkey_private_serialize
value|Fssh_sshkey_private_serialize
end_define

begin_define
define|#
directive|define
name|sshkey_private_to_blob2
value|Fssh_sshkey_private_to_blob2
end_define

begin_define
define|#
directive|define
name|sshkey_private_to_fileblob
value|Fssh_sshkey_private_to_fileblob
end_define

begin_define
define|#
directive|define
name|sshkey_putb
value|Fssh_sshkey_putb
end_define

begin_define
define|#
directive|define
name|sshkey_putb_plain
value|Fssh_sshkey_putb_plain
end_define

begin_define
define|#
directive|define
name|sshkey_puts
value|Fssh_sshkey_puts
end_define

begin_define
define|#
directive|define
name|sshkey_read
value|Fssh_sshkey_read
end_define

begin_define
define|#
directive|define
name|sshkey_save_private
value|Fssh_sshkey_save_private
end_define

begin_define
define|#
directive|define
name|sshkey_sign
value|Fssh_sshkey_sign
end_define

begin_define
define|#
directive|define
name|sshkey_size
value|Fssh_sshkey_size
end_define

begin_define
define|#
directive|define
name|sshkey_ssh_name
value|Fssh_sshkey_ssh_name
end_define

begin_define
define|#
directive|define
name|sshkey_ssh_name_plain
value|Fssh_sshkey_ssh_name_plain
end_define

begin_define
define|#
directive|define
name|sshkey_to_base64
value|Fssh_sshkey_to_base64
end_define

begin_define
define|#
directive|define
name|sshkey_to_blob
value|Fssh_sshkey_to_blob
end_define

begin_define
define|#
directive|define
name|sshkey_to_certified
value|Fssh_sshkey_to_certified
end_define

begin_define
define|#
directive|define
name|sshkey_try_load_public
value|Fssh_sshkey_try_load_public
end_define

begin_define
define|#
directive|define
name|sshkey_type
value|Fssh_sshkey_type
end_define

begin_define
define|#
directive|define
name|sshkey_type_from_name
value|Fssh_sshkey_type_from_name
end_define

begin_define
define|#
directive|define
name|sshkey_type_is_cert
value|Fssh_sshkey_type_is_cert
end_define

begin_define
define|#
directive|define
name|sshkey_type_plain
value|Fssh_sshkey_type_plain
end_define

begin_define
define|#
directive|define
name|sshkey_verify
value|Fssh_sshkey_verify
end_define

begin_define
define|#
directive|define
name|sshkey_write
value|Fssh_sshkey_write
end_define

begin_define
define|#
directive|define
name|sshpkt_add_padding
value|Fssh_sshpkt_add_padding
end_define

begin_define
define|#
directive|define
name|sshpkt_disconnect
value|Fssh_sshpkt_disconnect
end_define

begin_define
define|#
directive|define
name|sshpkt_fatal
value|Fssh_sshpkt_fatal
end_define

begin_define
define|#
directive|define
name|sshpkt_get
value|Fssh_sshpkt_get
end_define

begin_define
define|#
directive|define
name|sshpkt_get_bignum2
value|Fssh_sshpkt_get_bignum2
end_define

begin_define
define|#
directive|define
name|sshpkt_get_cstring
value|Fssh_sshpkt_get_cstring
end_define

begin_define
define|#
directive|define
name|sshpkt_get_ec
value|Fssh_sshpkt_get_ec
end_define

begin_define
define|#
directive|define
name|sshpkt_get_end
value|Fssh_sshpkt_get_end
end_define

begin_define
define|#
directive|define
name|sshpkt_get_string
value|Fssh_sshpkt_get_string
end_define

begin_define
define|#
directive|define
name|sshpkt_get_string_direct
value|Fssh_sshpkt_get_string_direct
end_define

begin_define
define|#
directive|define
name|sshpkt_get_u32
value|Fssh_sshpkt_get_u32
end_define

begin_define
define|#
directive|define
name|sshpkt_get_u64
value|Fssh_sshpkt_get_u64
end_define

begin_define
define|#
directive|define
name|sshpkt_get_u8
value|Fssh_sshpkt_get_u8
end_define

begin_define
define|#
directive|define
name|sshpkt_ptr
value|Fssh_sshpkt_ptr
end_define

begin_define
define|#
directive|define
name|sshpkt_put
value|Fssh_sshpkt_put
end_define

begin_define
define|#
directive|define
name|sshpkt_put_bignum2
value|Fssh_sshpkt_put_bignum2
end_define

begin_define
define|#
directive|define
name|sshpkt_put_cstring
value|Fssh_sshpkt_put_cstring
end_define

begin_define
define|#
directive|define
name|sshpkt_put_ec
value|Fssh_sshpkt_put_ec
end_define

begin_define
define|#
directive|define
name|sshpkt_put_string
value|Fssh_sshpkt_put_string
end_define

begin_define
define|#
directive|define
name|sshpkt_put_stringb
value|Fssh_sshpkt_put_stringb
end_define

begin_define
define|#
directive|define
name|sshpkt_put_u32
value|Fssh_sshpkt_put_u32
end_define

begin_define
define|#
directive|define
name|sshpkt_put_u64
value|Fssh_sshpkt_put_u64
end_define

begin_define
define|#
directive|define
name|sshpkt_put_u8
value|Fssh_sshpkt_put_u8
end_define

begin_define
define|#
directive|define
name|sshpkt_putb
value|Fssh_sshpkt_putb
end_define

begin_define
define|#
directive|define
name|sshpkt_send
value|Fssh_sshpkt_send
end_define

begin_define
define|#
directive|define
name|sshpkt_start
value|Fssh_sshpkt_start
end_define

begin_define
define|#
directive|define
name|start_progress_meter
value|Fssh_start_progress_meter
end_define

begin_define
define|#
directive|define
name|stop_progress_meter
value|Fssh_stop_progress_meter
end_define

begin_define
define|#
directive|define
name|stravis
value|Fssh_stravis
end_define

begin_define
define|#
directive|define
name|strdelim
value|Fssh_strdelim
end_define

begin_define
define|#
directive|define
name|strnvis
value|Fssh_strnvis
end_define

begin_define
define|#
directive|define
name|strvis
value|Fssh_strvis
end_define

begin_define
define|#
directive|define
name|strvisx
value|Fssh_strvisx
end_define

begin_define
define|#
directive|define
name|sys_tun_open
value|Fssh_sys_tun_open
end_define

begin_define
define|#
directive|define
name|temporarily_use_uid
value|Fssh_temporarily_use_uid
end_define

begin_define
define|#
directive|define
name|tilde_expand_filename
value|Fssh_tilde_expand_filename
end_define

begin_define
define|#
directive|define
name|to_blob
value|Fssh_to_blob
end_define

begin_define
define|#
directive|define
name|to_blob_buf
value|Fssh_to_blob_buf
end_define

begin_define
define|#
directive|define
name|tohex
value|Fssh_tohex
end_define

begin_define
define|#
directive|define
name|tty_make_modes
value|Fssh_tty_make_modes
end_define

begin_define
define|#
directive|define
name|tty_parse_modes
value|Fssh_tty_parse_modes
end_define

begin_define
define|#
directive|define
name|tun_open
value|Fssh_tun_open
end_define

begin_define
define|#
directive|define
name|umac128_delete
value|Fssh_umac128_delete
end_define

begin_define
define|#
directive|define
name|umac128_final
value|Fssh_umac128_final
end_define

begin_define
define|#
directive|define
name|umac128_new
value|Fssh_umac128_new
end_define

begin_define
define|#
directive|define
name|umac128_update
value|Fssh_umac128_update
end_define

begin_define
define|#
directive|define
name|umac_delete
value|Fssh_umac_delete
end_define

begin_define
define|#
directive|define
name|umac_final
value|Fssh_umac_final
end_define

begin_define
define|#
directive|define
name|umac_new
value|Fssh_umac_new
end_define

begin_define
define|#
directive|define
name|umac_update
value|Fssh_umac_update
end_define

begin_define
define|#
directive|define
name|uncompress_buffer
value|Fssh_uncompress_buffer
end_define

begin_define
define|#
directive|define
name|unix_listener
value|Fssh_unix_listener
end_define

begin_define
define|#
directive|define
name|unset_nonblock
value|Fssh_unset_nonblock
end_define

begin_define
define|#
directive|define
name|update_progress_meter
value|Fssh_update_progress_meter
end_define

begin_define
define|#
directive|define
name|uudecode
value|Fssh_uudecode
end_define

begin_define
define|#
directive|define
name|uuencode
value|Fssh_uuencode
end_define

begin_define
define|#
directive|define
name|vasnmprintf
value|Fssh_vasnmprintf
end_define

begin_define
define|#
directive|define
name|verbose
value|Fssh_verbose
end_define

begin_define
define|#
directive|define
name|verify_host_key_dns
value|Fssh_verify_host_key_dns
end_define

begin_define
define|#
directive|define
name|vfmprintf
value|Fssh_vfmprintf
end_define

begin_define
define|#
directive|define
name|vis
value|Fssh_vis
end_define

begin_define
define|#
directive|define
name|write_host_entry
value|Fssh_write_host_entry
end_define

begin_define
define|#
directive|define
name|x11_connect_display
value|Fssh_x11_connect_display
end_define

begin_define
define|#
directive|define
name|x11_create_display_inet
value|Fssh_x11_create_display_inet
end_define

begin_define
define|#
directive|define
name|x11_input_open
value|Fssh_x11_input_open
end_define

begin_define
define|#
directive|define
name|x11_open_helper
value|Fssh_x11_open_helper
end_define

begin_define
define|#
directive|define
name|x11_request_forwarding_with_spoofing
value|Fssh_x11_request_forwarding_with_spoofing
end_define

begin_define
define|#
directive|define
name|xasprintf
value|Fssh_xasprintf
end_define

begin_define
define|#
directive|define
name|xcalloc
value|Fssh_xcalloc
end_define

begin_define
define|#
directive|define
name|xcrypt
value|Fssh_xcrypt
end_define

begin_define
define|#
directive|define
name|xmalloc
value|Fssh_xmalloc
end_define

begin_define
define|#
directive|define
name|xreallocarray
value|Fssh_xreallocarray
end_define

begin_define
define|#
directive|define
name|xstrdup
value|Fssh_xstrdup
end_define

end_unit

