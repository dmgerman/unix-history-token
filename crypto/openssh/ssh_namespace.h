begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Namespace munging inspired by an equivalent hack in NetBSD's tree: add  * the "ssh_" prefix to every symbol in libssh which doesn't already have  * it.  This prevents collisions between symbols in libssh and symbols in  * other libraries or applications which link with libssh, either directly  * or indirectly (e.g. through PAM loading pam_ssh).  *  * A list of symbols which need munging is obtained as follows:  *  * nm libssh.a | awk '/[0-9a-z] [A-Z] /&& $3 !~ /^ssh_/ { print "#define", $3, "ssh_" $3 }'  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|a2port
value|ssh_a2port
end_define

begin_define
define|#
directive|define
name|a2tun
value|ssh_a2tun
end_define

begin_define
define|#
directive|define
name|acss
value|ssh_acss
end_define

begin_define
define|#
directive|define
name|acss_setkey
value|ssh_acss_setkey
end_define

begin_define
define|#
directive|define
name|acss_setsubkey
value|ssh_acss_setsubkey
end_define

begin_define
define|#
directive|define
name|add_host_to_hostfile
value|ssh_add_host_to_hostfile
end_define

begin_define
define|#
directive|define
name|add_recv_bytes
value|ssh_add_recv_bytes
end_define

begin_define
define|#
directive|define
name|addargs
value|ssh_addargs
end_define

begin_define
define|#
directive|define
name|addr_match_list
value|ssh_addr_match_list
end_define

begin_define
define|#
directive|define
name|ask_permission
value|ssh_ask_permission
end_define

begin_define
define|#
directive|define
name|atomicio
value|ssh_atomicio
end_define

begin_define
define|#
directive|define
name|atomiciov
value|ssh_atomiciov
end_define

begin_define
define|#
directive|define
name|auth_request_forwarding
value|ssh_auth_request_forwarding
end_define

begin_define
define|#
directive|define
name|buffer_append
value|ssh_buffer_append
end_define

begin_define
define|#
directive|define
name|buffer_append_space
value|ssh_buffer_append_space
end_define

begin_define
define|#
directive|define
name|buffer_check_alloc
value|ssh_buffer_check_alloc
end_define

begin_define
define|#
directive|define
name|buffer_clear
value|ssh_buffer_clear
end_define

begin_define
define|#
directive|define
name|buffer_compress
value|ssh_buffer_compress
end_define

begin_define
define|#
directive|define
name|buffer_compress_init_recv
value|ssh_buffer_compress_init_recv
end_define

begin_define
define|#
directive|define
name|buffer_compress_init_send
value|ssh_buffer_compress_init_send
end_define

begin_define
define|#
directive|define
name|buffer_compress_uninit
value|ssh_buffer_compress_uninit
end_define

begin_define
define|#
directive|define
name|buffer_consume
value|ssh_buffer_consume
end_define

begin_define
define|#
directive|define
name|buffer_consume_end
value|ssh_buffer_consume_end
end_define

begin_define
define|#
directive|define
name|buffer_consume_end_ret
value|ssh_buffer_consume_end_ret
end_define

begin_define
define|#
directive|define
name|buffer_consume_ret
value|ssh_buffer_consume_ret
end_define

begin_define
define|#
directive|define
name|buffer_dump
value|ssh_buffer_dump
end_define

begin_define
define|#
directive|define
name|buffer_free
value|ssh_buffer_free
end_define

begin_define
define|#
directive|define
name|buffer_get
value|ssh_buffer_get
end_define

begin_define
define|#
directive|define
name|buffer_get_bignum
value|ssh_buffer_get_bignum
end_define

begin_define
define|#
directive|define
name|buffer_get_bignum2
value|ssh_buffer_get_bignum2
end_define

begin_define
define|#
directive|define
name|buffer_get_bignum2_ret
value|ssh_buffer_get_bignum2_ret
end_define

begin_define
define|#
directive|define
name|buffer_get_bignum_ret
value|ssh_buffer_get_bignum_ret
end_define

begin_define
define|#
directive|define
name|buffer_get_char
value|ssh_buffer_get_char
end_define

begin_define
define|#
directive|define
name|buffer_get_char_ret
value|ssh_buffer_get_char_ret
end_define

begin_define
define|#
directive|define
name|buffer_get_int
value|ssh_buffer_get_int
end_define

begin_define
define|#
directive|define
name|buffer_get_int64
value|ssh_buffer_get_int64
end_define

begin_define
define|#
directive|define
name|buffer_get_int64_ret
value|ssh_buffer_get_int64_ret
end_define

begin_define
define|#
directive|define
name|buffer_get_int_ret
value|ssh_buffer_get_int_ret
end_define

begin_define
define|#
directive|define
name|buffer_get_ret
value|ssh_buffer_get_ret
end_define

begin_define
define|#
directive|define
name|buffer_get_short
value|ssh_buffer_get_short
end_define

begin_define
define|#
directive|define
name|buffer_get_short_ret
value|ssh_buffer_get_short_ret
end_define

begin_define
define|#
directive|define
name|buffer_get_string
value|ssh_buffer_get_string
end_define

begin_define
define|#
directive|define
name|buffer_get_string_ptr
value|ssh_buffer_get_string_ptr
end_define

begin_define
define|#
directive|define
name|buffer_get_string_ret
value|ssh_buffer_get_string_ret
end_define

begin_define
define|#
directive|define
name|buffer_init
value|ssh_buffer_init
end_define

begin_define
define|#
directive|define
name|buffer_len
value|ssh_buffer_len
end_define

begin_define
define|#
directive|define
name|buffer_ptr
value|ssh_buffer_ptr
end_define

begin_define
define|#
directive|define
name|buffer_put_bignum
value|ssh_buffer_put_bignum
end_define

begin_define
define|#
directive|define
name|buffer_put_bignum2
value|ssh_buffer_put_bignum2
end_define

begin_define
define|#
directive|define
name|buffer_put_bignum2_ret
value|ssh_buffer_put_bignum2_ret
end_define

begin_define
define|#
directive|define
name|buffer_put_bignum_ret
value|ssh_buffer_put_bignum_ret
end_define

begin_define
define|#
directive|define
name|buffer_put_char
value|ssh_buffer_put_char
end_define

begin_define
define|#
directive|define
name|buffer_put_cstring
value|ssh_buffer_put_cstring
end_define

begin_define
define|#
directive|define
name|buffer_put_int
value|ssh_buffer_put_int
end_define

begin_define
define|#
directive|define
name|buffer_put_int64
value|ssh_buffer_put_int64
end_define

begin_define
define|#
directive|define
name|buffer_put_short
value|ssh_buffer_put_short
end_define

begin_define
define|#
directive|define
name|buffer_put_string
value|ssh_buffer_put_string
end_define

begin_define
define|#
directive|define
name|buffer_uncompress
value|ssh_buffer_uncompress
end_define

begin_define
define|#
directive|define
name|chan_ibuf_empty
value|ssh_chan_ibuf_empty
end_define

begin_define
define|#
directive|define
name|chan_is_dead
value|ssh_chan_is_dead
end_define

begin_define
define|#
directive|define
name|chan_mark_dead
value|ssh_chan_mark_dead
end_define

begin_define
define|#
directive|define
name|chan_obuf_empty
value|ssh_chan_obuf_empty
end_define

begin_define
define|#
directive|define
name|chan_rcvd_eow
value|ssh_chan_rcvd_eow
end_define

begin_define
define|#
directive|define
name|chan_rcvd_ieof
value|ssh_chan_rcvd_ieof
end_define

begin_define
define|#
directive|define
name|chan_rcvd_oclose
value|ssh_chan_rcvd_oclose
end_define

begin_define
define|#
directive|define
name|chan_read_failed
value|ssh_chan_read_failed
end_define

begin_define
define|#
directive|define
name|chan_write_failed
value|ssh_chan_write_failed
end_define

begin_define
define|#
directive|define
name|channel_add_adm_permitted_opens
value|ssh_channel_add_adm_permitted_opens
end_define

begin_define
define|#
directive|define
name|channel_add_permitted_opens
value|ssh_channel_add_permitted_opens
end_define

begin_define
define|#
directive|define
name|channel_after_select
value|ssh_channel_after_select
end_define

begin_define
define|#
directive|define
name|channel_by_id
value|ssh_channel_by_id
end_define

begin_define
define|#
directive|define
name|channel_cancel_cleanup
value|ssh_channel_cancel_cleanup
end_define

begin_define
define|#
directive|define
name|channel_cancel_rport_listener
value|ssh_channel_cancel_rport_listener
end_define

begin_define
define|#
directive|define
name|channel_clear_adm_permitted_opens
value|ssh_channel_clear_adm_permitted_opens
end_define

begin_define
define|#
directive|define
name|channel_clear_permitted_opens
value|ssh_channel_clear_permitted_opens
end_define

begin_define
define|#
directive|define
name|channel_close_all
value|ssh_channel_close_all
end_define

begin_define
define|#
directive|define
name|channel_close_fd
value|ssh_channel_close_fd
end_define

begin_define
define|#
directive|define
name|channel_connect_by_listen_address
value|ssh_channel_connect_by_listen_address
end_define

begin_define
define|#
directive|define
name|channel_connect_to
value|ssh_channel_connect_to
end_define

begin_define
define|#
directive|define
name|channel_find_open
value|ssh_channel_find_open
end_define

begin_define
define|#
directive|define
name|channel_free
value|ssh_channel_free
end_define

begin_define
define|#
directive|define
name|channel_free_all
value|ssh_channel_free_all
end_define

begin_define
define|#
directive|define
name|channel_input_close
value|ssh_channel_input_close
end_define

begin_define
define|#
directive|define
name|channel_input_close_confirmation
value|ssh_channel_input_close_confirmation
end_define

begin_define
define|#
directive|define
name|channel_input_data
value|ssh_channel_input_data
end_define

begin_define
define|#
directive|define
name|channel_input_extended_data
value|ssh_channel_input_extended_data
end_define

begin_define
define|#
directive|define
name|channel_input_ieof
value|ssh_channel_input_ieof
end_define

begin_define
define|#
directive|define
name|channel_input_oclose
value|ssh_channel_input_oclose
end_define

begin_define
define|#
directive|define
name|channel_input_open_confirmation
value|ssh_channel_input_open_confirmation
end_define

begin_define
define|#
directive|define
name|channel_input_open_failure
value|ssh_channel_input_open_failure
end_define

begin_define
define|#
directive|define
name|channel_input_port_forward_request
value|ssh_channel_input_port_forward_request
end_define

begin_define
define|#
directive|define
name|channel_input_port_open
value|ssh_channel_input_port_open
end_define

begin_define
define|#
directive|define
name|channel_input_status_confirm
value|ssh_channel_input_status_confirm
end_define

begin_define
define|#
directive|define
name|channel_input_window_adjust
value|ssh_channel_input_window_adjust
end_define

begin_define
define|#
directive|define
name|channel_lookup
value|ssh_channel_lookup
end_define

begin_define
define|#
directive|define
name|channel_new
value|ssh_channel_new
end_define

begin_define
define|#
directive|define
name|channel_not_very_much_buffered_data
value|ssh_channel_not_very_much_buffered_data
end_define

begin_define
define|#
directive|define
name|channel_open_message
value|ssh_channel_open_message
end_define

begin_define
define|#
directive|define
name|channel_output_poll
value|ssh_channel_output_poll
end_define

begin_define
define|#
directive|define
name|channel_permit_all_opens
value|ssh_channel_permit_all_opens
end_define

begin_define
define|#
directive|define
name|channel_post
value|ssh_channel_post
end_define

begin_define
define|#
directive|define
name|channel_pre
value|ssh_channel_pre
end_define

begin_define
define|#
directive|define
name|channel_prepare_select
value|ssh_channel_prepare_select
end_define

begin_define
define|#
directive|define
name|channel_print_adm_permitted_opens
value|ssh_channel_print_adm_permitted_opens
end_define

begin_define
define|#
directive|define
name|channel_register_cleanup
value|ssh_channel_register_cleanup
end_define

begin_define
define|#
directive|define
name|channel_register_confirm
value|ssh_channel_register_confirm
end_define

begin_define
define|#
directive|define
name|channel_register_filter
value|ssh_channel_register_filter
end_define

begin_define
define|#
directive|define
name|channel_register_open_confirm
value|ssh_channel_register_open_confirm
end_define

begin_define
define|#
directive|define
name|channel_register_status_confirm
value|ssh_channel_register_status_confirm
end_define

begin_define
define|#
directive|define
name|channel_request_remote_forwarding
value|ssh_channel_request_remote_forwarding
end_define

begin_define
define|#
directive|define
name|channel_request_rforward_cancel
value|ssh_channel_request_rforward_cancel
end_define

begin_define
define|#
directive|define
name|channel_request_start
value|ssh_channel_request_start
end_define

begin_define
define|#
directive|define
name|channel_send_open
value|ssh_channel_send_open
end_define

begin_define
define|#
directive|define
name|channel_send_window_changes
value|ssh_channel_send_window_changes
end_define

begin_define
define|#
directive|define
name|channel_set_af
value|ssh_channel_set_af
end_define

begin_define
define|#
directive|define
name|channel_set_fds
value|ssh_channel_set_fds
end_define

begin_define
define|#
directive|define
name|channel_setup_local_fwd_listener
value|ssh_channel_setup_local_fwd_listener
end_define

begin_define
define|#
directive|define
name|channel_setup_remote_fwd_listener
value|ssh_channel_setup_remote_fwd_listener
end_define

begin_define
define|#
directive|define
name|channel_still_open
value|ssh_channel_still_open
end_define

begin_define
define|#
directive|define
name|channel_stop_listening
value|ssh_channel_stop_listening
end_define

begin_define
define|#
directive|define
name|check_host_in_hostfile
value|ssh_check_host_in_hostfile
end_define

begin_define
define|#
directive|define
name|choose_dh
value|ssh_choose_dh
end_define

begin_define
define|#
directive|define
name|chop
value|ssh_chop
end_define

begin_define
define|#
directive|define
name|cipher_blocksize
value|ssh_cipher_blocksize
end_define

begin_define
define|#
directive|define
name|cipher_by_name
value|ssh_cipher_by_name
end_define

begin_define
define|#
directive|define
name|cipher_by_number
value|ssh_cipher_by_number
end_define

begin_define
define|#
directive|define
name|cipher_cleanup
value|ssh_cipher_cleanup
end_define

begin_define
define|#
directive|define
name|cipher_crypt
value|ssh_cipher_crypt
end_define

begin_define
define|#
directive|define
name|cipher_get_keycontext
value|ssh_cipher_get_keycontext
end_define

begin_define
define|#
directive|define
name|cipher_get_keyiv
value|ssh_cipher_get_keyiv
end_define

begin_define
define|#
directive|define
name|cipher_get_keyiv_len
value|ssh_cipher_get_keyiv_len
end_define

begin_define
define|#
directive|define
name|cipher_get_number
value|ssh_cipher_get_number
end_define

begin_define
define|#
directive|define
name|cipher_init
value|ssh_cipher_init
end_define

begin_define
define|#
directive|define
name|cipher_is_cbc
value|ssh_cipher_is_cbc
end_define

begin_define
define|#
directive|define
name|cipher_keylen
value|ssh_cipher_keylen
end_define

begin_define
define|#
directive|define
name|cipher_mask_ssh1
value|ssh_cipher_mask_ssh1
end_define

begin_define
define|#
directive|define
name|cipher_name
value|ssh_cipher_name
end_define

begin_define
define|#
directive|define
name|cipher_number
value|ssh_cipher_number
end_define

begin_define
define|#
directive|define
name|cipher_set_key_string
value|ssh_cipher_set_key_string
end_define

begin_define
define|#
directive|define
name|cipher_set_keycontext
value|ssh_cipher_set_keycontext
end_define

begin_define
define|#
directive|define
name|cipher_set_keyiv
value|ssh_cipher_set_keyiv
end_define

begin_define
define|#
directive|define
name|ciphers
value|ssh_ciphers
end_define

begin_define
define|#
directive|define
name|ciphers_valid
value|ssh_ciphers_valid
end_define

begin_define
define|#
directive|define
name|cleanhostname
value|ssh_cleanhostname
end_define

begin_define
define|#
directive|define
name|cleanup_exit
value|ssh_cleanup_exit
end_define

begin_define
define|#
directive|define
name|clear_cached_addr
value|ssh_clear_cached_addr
end_define

begin_define
define|#
directive|define
name|colon
value|ssh_colon
end_define

begin_define
define|#
directive|define
name|compat13
value|ssh_compat13
end_define

begin_define
define|#
directive|define
name|compat20
value|ssh_compat20
end_define

begin_define
define|#
directive|define
name|compat_cipher_proposal
value|ssh_compat_cipher_proposal
end_define

begin_define
define|#
directive|define
name|compat_datafellows
value|ssh_compat_datafellows
end_define

begin_define
define|#
directive|define
name|convtime
value|ssh_convtime
end_define

begin_define
define|#
directive|define
name|current_keys
value|ssh_current_keys
end_define

begin_define
define|#
directive|define
name|datafellows
value|ssh_datafellows
end_define

begin_define
define|#
directive|define
name|debug
value|ssh_debug
end_define

begin_define
define|#
directive|define
name|debug
value|ssh_debug
end_define

begin_define
define|#
directive|define
name|debug2
value|ssh_debug2
end_define

begin_define
define|#
directive|define
name|debug2
value|ssh_debug2
end_define

begin_define
define|#
directive|define
name|debug3
value|ssh_debug3
end_define

begin_define
define|#
directive|define
name|debug3
value|ssh_debug3
end_define

begin_define
define|#
directive|define
name|decode_reply
value|ssh_decode_reply
end_define

begin_define
define|#
directive|define
name|deny_input_open
value|ssh_deny_input_open
end_define

begin_define
define|#
directive|define
name|derive_ssh1_session_id
value|ssh_derive_ssh1_session_id
end_define

begin_define
define|#
directive|define
name|detect_attack
value|ssh_detect_attack
end_define

begin_define
define|#
directive|define
name|dh_estimate
value|ssh_dh_estimate
end_define

begin_define
define|#
directive|define
name|dh_gen_key
value|ssh_dh_gen_key
end_define

begin_define
define|#
directive|define
name|dh_new_group
value|ssh_dh_new_group
end_define

begin_define
define|#
directive|define
name|dh_new_group1
value|ssh_dh_new_group1
end_define

begin_define
define|#
directive|define
name|dh_new_group14
value|ssh_dh_new_group14
end_define

begin_define
define|#
directive|define
name|dh_new_group_asc
value|ssh_dh_new_group_asc
end_define

begin_define
define|#
directive|define
name|dh_pub_is_valid
value|ssh_dh_pub_is_valid
end_define

begin_define
define|#
directive|define
name|dispatch
value|ssh_dispatch
end_define

begin_define
define|#
directive|define
name|dispatch_init
value|ssh_dispatch_init
end_define

begin_define
define|#
directive|define
name|dispatch_protocol_error
value|ssh_dispatch_protocol_error
end_define

begin_define
define|#
directive|define
name|dispatch_protocol_ignore
value|ssh_dispatch_protocol_ignore
end_define

begin_define
define|#
directive|define
name|dispatch_range
value|ssh_dispatch_range
end_define

begin_define
define|#
directive|define
name|dispatch_run
value|ssh_dispatch_run
end_define

begin_define
define|#
directive|define
name|dispatch_set
value|ssh_dispatch_set
end_define

begin_define
define|#
directive|define
name|do_log
value|ssh_do_log
end_define

begin_define
define|#
directive|define
name|dump_base64
value|ssh_dump_base64
end_define

begin_define
define|#
directive|define
name|enable_compat13
value|ssh_enable_compat13
end_define

begin_define
define|#
directive|define
name|enable_compat20
value|ssh_enable_compat20
end_define

begin_define
define|#
directive|define
name|error
value|ssh_error
end_define

begin_define
define|#
directive|define
name|error
value|ssh_error
end_define

begin_define
define|#
directive|define
name|evp_acss
value|ssh_evp_acss
end_define

begin_define
define|#
directive|define
name|evp_aes_128_ctr
value|ssh_evp_aes_128_ctr
end_define

begin_define
define|#
directive|define
name|evp_rijndael
value|ssh_evp_rijndael
end_define

begin_define
define|#
directive|define
name|evp_ssh1_3des
value|ssh_evp_ssh1_3des
end_define

begin_define
define|#
directive|define
name|evp_ssh1_bf
value|ssh_evp_ssh1_bf
end_define

begin_define
define|#
directive|define
name|export_dns_rr
value|ssh_export_dns_rr
end_define

begin_define
define|#
directive|define
name|fatal
value|ssh_fatal
end_define

begin_define
define|#
directive|define
name|fatal
value|ssh_fatal
end_define

begin_define
define|#
directive|define
name|fmt_scaled
value|ssh_fmt_scaled
end_define

begin_define
define|#
directive|define
name|freeargs
value|ssh_freeargs
end_define

begin_define
define|#
directive|define
name|freerrset
value|ssh_freerrset
end_define

begin_define
define|#
directive|define
name|gen_candidates
value|ssh_gen_candidates
end_define

begin_define
define|#
directive|define
name|get_canonical_hostname
value|ssh_get_canonical_hostname
end_define

begin_define
define|#
directive|define
name|get_local_ipaddr
value|ssh_get_local_ipaddr
end_define

begin_define
define|#
directive|define
name|get_local_name
value|ssh_get_local_name
end_define

begin_define
define|#
directive|define
name|get_local_port
value|ssh_get_local_port
end_define

begin_define
define|#
directive|define
name|get_peer_ipaddr
value|ssh_get_peer_ipaddr
end_define

begin_define
define|#
directive|define
name|get_peer_port
value|ssh_get_peer_port
end_define

begin_define
define|#
directive|define
name|get_recv_bytes
value|ssh_get_recv_bytes
end_define

begin_define
define|#
directive|define
name|get_remote_ipaddr
value|ssh_get_remote_ipaddr
end_define

begin_define
define|#
directive|define
name|get_remote_name_or_ip
value|ssh_get_remote_name_or_ip
end_define

begin_define
define|#
directive|define
name|get_remote_port
value|ssh_get_remote_port
end_define

begin_define
define|#
directive|define
name|get_sock_port
value|ssh_get_sock_port
end_define

begin_define
define|#
directive|define
name|get_u16
value|ssh_get_u16
end_define

begin_define
define|#
directive|define
name|get_u32
value|ssh_get_u32
end_define

begin_define
define|#
directive|define
name|get_u64
value|ssh_get_u64
end_define

begin_define
define|#
directive|define
name|getrrsetbyname
value|ssh_getrrsetbyname
end_define

begin_define
define|#
directive|define
name|host_hash
value|ssh_host_hash
end_define

begin_define
define|#
directive|define
name|hostfile_read_key
value|ssh_hostfile_read_key
end_define

begin_define
define|#
directive|define
name|hpdelim
value|ssh_hpdelim
end_define

begin_define
define|#
directive|define
name|incoming_stream
value|ssh_incoming_stream
end_define

begin_define
define|#
directive|define
name|init_rng
value|ssh_init_rng
end_define

begin_define
define|#
directive|define
name|ipv64_normalise_mapped
value|ssh_ipv64_normalise_mapped
end_define

begin_define
define|#
directive|define
name|kex_derive_keys
value|ssh_kex_derive_keys
end_define

begin_define
define|#
directive|define
name|kex_dh_hash
value|ssh_kex_dh_hash
end_define

begin_define
define|#
directive|define
name|kex_finish
value|ssh_kex_finish
end_define

begin_define
define|#
directive|define
name|kex_get_newkeys
value|ssh_kex_get_newkeys
end_define

begin_define
define|#
directive|define
name|kex_input_kexinit
value|ssh_kex_input_kexinit
end_define

begin_define
define|#
directive|define
name|kex_send_kexinit
value|ssh_kex_send_kexinit
end_define

begin_define
define|#
directive|define
name|kex_setup
value|ssh_kex_setup
end_define

begin_define
define|#
directive|define
name|kexdh_client
value|ssh_kexdh_client
end_define

begin_define
define|#
directive|define
name|kexgex_client
value|ssh_kexgex_client
end_define

begin_define
define|#
directive|define
name|kexgex_hash
value|ssh_kexgex_hash
end_define

begin_define
define|#
directive|define
name|key_demote
value|ssh_key_demote
end_define

begin_define
define|#
directive|define
name|key_equal
value|ssh_key_equal
end_define

begin_define
define|#
directive|define
name|key_fingerprint
value|ssh_key_fingerprint
end_define

begin_define
define|#
directive|define
name|key_fingerprint_raw
value|ssh_key_fingerprint_raw
end_define

begin_define
define|#
directive|define
name|key_free
value|ssh_key_free
end_define

begin_define
define|#
directive|define
name|key_from_blob
value|ssh_key_from_blob
end_define

begin_define
define|#
directive|define
name|key_from_private
value|ssh_key_from_private
end_define

begin_define
define|#
directive|define
name|key_generate
value|ssh_key_generate
end_define

begin_define
define|#
directive|define
name|key_load_private
value|ssh_key_load_private
end_define

begin_define
define|#
directive|define
name|key_load_private_pem
value|ssh_key_load_private_pem
end_define

begin_define
define|#
directive|define
name|key_load_private_type
value|ssh_key_load_private_type
end_define

begin_define
define|#
directive|define
name|key_load_public
value|ssh_key_load_public
end_define

begin_define
define|#
directive|define
name|key_load_public_type
value|ssh_key_load_public_type
end_define

begin_define
define|#
directive|define
name|key_names_valid2
value|ssh_key_names_valid2
end_define

begin_define
define|#
directive|define
name|key_new
value|ssh_key_new
end_define

begin_define
define|#
directive|define
name|key_new_private
value|ssh_key_new_private
end_define

begin_define
define|#
directive|define
name|key_perm_ok
value|ssh_key_perm_ok
end_define

begin_define
define|#
directive|define
name|key_read
value|ssh_key_read
end_define

begin_define
define|#
directive|define
name|key_save_private
value|ssh_key_save_private
end_define

begin_define
define|#
directive|define
name|key_sign
value|ssh_key_sign
end_define

begin_define
define|#
directive|define
name|key_size
value|ssh_key_size
end_define

begin_define
define|#
directive|define
name|key_ssh_name
value|ssh_key_ssh_name
end_define

begin_define
define|#
directive|define
name|key_to_blob
value|ssh_key_to_blob
end_define

begin_define
define|#
directive|define
name|key_type
value|ssh_key_type
end_define

begin_define
define|#
directive|define
name|key_type_from_name
value|ssh_key_type_from_name
end_define

begin_define
define|#
directive|define
name|key_verify
value|ssh_key_verify
end_define

begin_define
define|#
directive|define
name|key_write
value|ssh_key_write
end_define

begin_define
define|#
directive|define
name|log_facility_name
value|ssh_log_facility_name
end_define

begin_define
define|#
directive|define
name|log_facility_number
value|ssh_log_facility_number
end_define

begin_define
define|#
directive|define
name|log_init
value|ssh_log_init
end_define

begin_define
define|#
directive|define
name|log_level_name
value|ssh_log_level_name
end_define

begin_define
define|#
directive|define
name|log_level_number
value|ssh_log_level_number
end_define

begin_define
define|#
directive|define
name|logit
value|ssh_logit
end_define

begin_define
define|#
directive|define
name|logit
value|ssh_logit
end_define

begin_define
define|#
directive|define
name|lookup_key_in_hostfile_by_type
value|ssh_lookup_key_in_hostfile_by_type
end_define

begin_define
define|#
directive|define
name|mac_clear
value|ssh_mac_clear
end_define

begin_define
define|#
directive|define
name|mac_compute
value|ssh_mac_compute
end_define

begin_define
define|#
directive|define
name|mac_init
value|ssh_mac_init
end_define

begin_define
define|#
directive|define
name|mac_setup
value|ssh_mac_setup
end_define

begin_define
define|#
directive|define
name|mac_valid
value|ssh_mac_valid
end_define

begin_define
define|#
directive|define
name|macs
value|ssh_macs
end_define

begin_define
define|#
directive|define
name|match_host_and_ip
value|ssh_match_host_and_ip
end_define

begin_define
define|#
directive|define
name|match_hostname
value|ssh_match_hostname
end_define

begin_define
define|#
directive|define
name|match_list
value|ssh_match_list
end_define

begin_define
define|#
directive|define
name|match_pattern
value|ssh_match_pattern
end_define

begin_define
define|#
directive|define
name|match_pattern_list
value|ssh_match_pattern_list
end_define

begin_define
define|#
directive|define
name|match_user
value|ssh_match_user
end_define

begin_define
define|#
directive|define
name|mm_receive_fd
value|ssh_mm_receive_fd
end_define

begin_define
define|#
directive|define
name|mm_send_fd
value|ssh_mm_send_fd
end_define

begin_define
define|#
directive|define
name|ms_subtract_diff
value|ssh_ms_subtract_diff
end_define

begin_define
define|#
directive|define
name|ms_to_timeval
value|ssh_ms_to_timeval
end_define

begin_define
define|#
directive|define
name|mysignal
value|ssh_mysignal
end_define

begin_define
define|#
directive|define
name|outgoing_stream
value|ssh_outgoing_stream
end_define

begin_define
define|#
directive|define
name|packet_add_padding
value|ssh_packet_add_padding
end_define

begin_define
define|#
directive|define
name|packet_backup_state
value|ssh_packet_backup_state
end_define

begin_define
define|#
directive|define
name|packet_close
value|ssh_packet_close
end_define

begin_define
define|#
directive|define
name|packet_connection_is_ipv4
value|ssh_packet_connection_is_ipv4
end_define

begin_define
define|#
directive|define
name|packet_connection_is_on_socket
value|ssh_packet_connection_is_on_socket
end_define

begin_define
define|#
directive|define
name|packet_disconnect
value|ssh_packet_disconnect
end_define

begin_define
define|#
directive|define
name|packet_get_bignum
value|ssh_packet_get_bignum
end_define

begin_define
define|#
directive|define
name|packet_get_bignum2
value|ssh_packet_get_bignum2
end_define

begin_define
define|#
directive|define
name|packet_get_char
value|ssh_packet_get_char
end_define

begin_define
define|#
directive|define
name|packet_get_connection_in
value|ssh_packet_get_connection_in
end_define

begin_define
define|#
directive|define
name|packet_get_connection_out
value|ssh_packet_get_connection_out
end_define

begin_define
define|#
directive|define
name|packet_get_encryption_key
value|ssh_packet_get_encryption_key
end_define

begin_define
define|#
directive|define
name|packet_get_input
value|ssh_packet_get_input
end_define

begin_define
define|#
directive|define
name|packet_get_int
value|ssh_packet_get_int
end_define

begin_define
define|#
directive|define
name|packet_get_int64
value|ssh_packet_get_int64
end_define

begin_define
define|#
directive|define
name|packet_get_keycontext
value|ssh_packet_get_keycontext
end_define

begin_define
define|#
directive|define
name|packet_get_keyiv
value|ssh_packet_get_keyiv
end_define

begin_define
define|#
directive|define
name|packet_get_keyiv_len
value|ssh_packet_get_keyiv_len
end_define

begin_define
define|#
directive|define
name|packet_get_maxsize
value|ssh_packet_get_maxsize
end_define

begin_define
define|#
directive|define
name|packet_get_newkeys
value|ssh_packet_get_newkeys
end_define

begin_define
define|#
directive|define
name|packet_get_output
value|ssh_packet_get_output
end_define

begin_define
define|#
directive|define
name|packet_get_protocol_flags
value|ssh_packet_get_protocol_flags
end_define

begin_define
define|#
directive|define
name|packet_get_raw
value|ssh_packet_get_raw
end_define

begin_define
define|#
directive|define
name|packet_get_ssh1_cipher
value|ssh_packet_get_ssh1_cipher
end_define

begin_define
define|#
directive|define
name|packet_get_state
value|ssh_packet_get_state
end_define

begin_define
define|#
directive|define
name|packet_get_string
value|ssh_packet_get_string
end_define

begin_define
define|#
directive|define
name|packet_get_string_ptr
value|ssh_packet_get_string_ptr
end_define

begin_define
define|#
directive|define
name|packet_have_data_to_write
value|ssh_packet_have_data_to_write
end_define

begin_define
define|#
directive|define
name|packet_inc_alive_timeouts
value|ssh_packet_inc_alive_timeouts
end_define

begin_define
define|#
directive|define
name|packet_is_interactive
value|ssh_packet_is_interactive
end_define

begin_define
define|#
directive|define
name|packet_need_rekeying
value|ssh_packet_need_rekeying
end_define

begin_define
define|#
directive|define
name|packet_not_very_much_data_to_write
value|ssh_packet_not_very_much_data_to_write
end_define

begin_define
define|#
directive|define
name|packet_process_incoming
value|ssh_packet_process_incoming
end_define

begin_define
define|#
directive|define
name|packet_put_bignum
value|ssh_packet_put_bignum
end_define

begin_define
define|#
directive|define
name|packet_put_bignum2
value|ssh_packet_put_bignum2
end_define

begin_define
define|#
directive|define
name|packet_put_char
value|ssh_packet_put_char
end_define

begin_define
define|#
directive|define
name|packet_put_cstring
value|ssh_packet_put_cstring
end_define

begin_define
define|#
directive|define
name|packet_put_int
value|ssh_packet_put_int
end_define

begin_define
define|#
directive|define
name|packet_put_int64
value|ssh_packet_put_int64
end_define

begin_define
define|#
directive|define
name|packet_put_raw
value|ssh_packet_put_raw
end_define

begin_define
define|#
directive|define
name|packet_put_string
value|ssh_packet_put_string
end_define

begin_define
define|#
directive|define
name|packet_read
value|ssh_packet_read
end_define

begin_define
define|#
directive|define
name|packet_read_expect
value|ssh_packet_read_expect
end_define

begin_define
define|#
directive|define
name|packet_read_poll
value|ssh_packet_read_poll
end_define

begin_define
define|#
directive|define
name|packet_read_poll_seqnr
value|ssh_packet_read_poll_seqnr
end_define

begin_define
define|#
directive|define
name|packet_read_seqnr
value|ssh_packet_read_seqnr
end_define

begin_define
define|#
directive|define
name|packet_remaining
value|ssh_packet_remaining
end_define

begin_define
define|#
directive|define
name|packet_restore_state
value|ssh_packet_restore_state
end_define

begin_define
define|#
directive|define
name|packet_send
value|ssh_packet_send
end_define

begin_define
define|#
directive|define
name|packet_send_debug
value|ssh_packet_send_debug
end_define

begin_define
define|#
directive|define
name|packet_send_ignore
value|ssh_packet_send_ignore
end_define

begin_define
define|#
directive|define
name|packet_set_alive_timeouts
value|ssh_packet_set_alive_timeouts
end_define

begin_define
define|#
directive|define
name|packet_set_authenticated
value|ssh_packet_set_authenticated
end_define

begin_define
define|#
directive|define
name|packet_set_connection
value|ssh_packet_set_connection
end_define

begin_define
define|#
directive|define
name|packet_set_encryption_key
value|ssh_packet_set_encryption_key
end_define

begin_define
define|#
directive|define
name|packet_set_interactive
value|ssh_packet_set_interactive
end_define

begin_define
define|#
directive|define
name|packet_set_iv
value|ssh_packet_set_iv
end_define

begin_define
define|#
directive|define
name|packet_set_keycontext
value|ssh_packet_set_keycontext
end_define

begin_define
define|#
directive|define
name|packet_set_maxsize
value|ssh_packet_set_maxsize
end_define

begin_define
define|#
directive|define
name|packet_set_nonblocking
value|ssh_packet_set_nonblocking
end_define

begin_define
define|#
directive|define
name|packet_set_protocol_flags
value|ssh_packet_set_protocol_flags
end_define

begin_define
define|#
directive|define
name|packet_set_rekey_limit
value|ssh_packet_set_rekey_limit
end_define

begin_define
define|#
directive|define
name|packet_set_server
value|ssh_packet_set_server
end_define

begin_define
define|#
directive|define
name|packet_set_state
value|ssh_packet_set_state
end_define

begin_define
define|#
directive|define
name|packet_set_timeout
value|ssh_packet_set_timeout
end_define

begin_define
define|#
directive|define
name|packet_start
value|ssh_packet_start
end_define

begin_define
define|#
directive|define
name|packet_start_compression
value|ssh_packet_start_compression
end_define

begin_define
define|#
directive|define
name|packet_write_poll
value|ssh_packet_write_poll
end_define

begin_define
define|#
directive|define
name|packet_write_wait
value|ssh_packet_write_wait
end_define

begin_define
define|#
directive|define
name|percent_expand
value|ssh_percent_expand
end_define

begin_define
define|#
directive|define
name|permanently_drop_suid
value|ssh_permanently_drop_suid
end_define

begin_define
define|#
directive|define
name|permanently_set_uid
value|ssh_permanently_set_uid
end_define

begin_define
define|#
directive|define
name|prime_test
value|ssh_prime_test
end_define

begin_define
define|#
directive|define
name|proto_spec
value|ssh_proto_spec
end_define

begin_define
define|#
directive|define
name|put_host_port
value|ssh_put_host_port
end_define

begin_define
define|#
directive|define
name|put_u16
value|ssh_put_u16
end_define

begin_define
define|#
directive|define
name|put_u32
value|ssh_put_u32
end_define

begin_define
define|#
directive|define
name|put_u64
value|ssh_put_u64
end_define

begin_define
define|#
directive|define
name|pwcopy
value|ssh_pwcopy
end_define

begin_define
define|#
directive|define
name|read_keyfile_line
value|ssh_read_keyfile_line
end_define

begin_define
define|#
directive|define
name|read_passphrase
value|ssh_read_passphrase
end_define

begin_define
define|#
directive|define
name|refresh_progress_meter
value|ssh_refresh_progress_meter
end_define

begin_define
define|#
directive|define
name|replacearg
value|ssh_replacearg
end_define

begin_define
define|#
directive|define
name|restore_uid
value|ssh_restore_uid
end_define

begin_define
define|#
directive|define
name|resume_in_progress
value|ssh_resume_in_progress
end_define

begin_define
define|#
directive|define
name|resume_kex
value|ssh_resume_kex
end_define

begin_define
define|#
directive|define
name|rijndael_decrypt
value|ssh_rijndael_decrypt
end_define

begin_define
define|#
directive|define
name|rijndael_encrypt
value|ssh_rijndael_encrypt
end_define

begin_define
define|#
directive|define
name|rijndael_set_key
value|ssh_rijndael_set_key
end_define

begin_define
define|#
directive|define
name|roaming_read
value|ssh_roaming_read
end_define

begin_define
define|#
directive|define
name|roaming_write
value|ssh_roaming_write
end_define

begin_define
define|#
directive|define
name|rsa_generate_additional_parameters
value|ssh_rsa_generate_additional_parameters
end_define

begin_define
define|#
directive|define
name|rsa_private_decrypt
value|ssh_rsa_private_decrypt
end_define

begin_define
define|#
directive|define
name|rsa_public_encrypt
value|ssh_rsa_public_encrypt
end_define

begin_define
define|#
directive|define
name|sanitise_stdfd
value|ssh_sanitise_stdfd
end_define

begin_define
define|#
directive|define
name|scan_scaled
value|ssh_scan_scaled
end_define

begin_define
define|#
directive|define
name|schnorr_sign
value|ssh_schnorr_sign
end_define

begin_define
define|#
directive|define
name|schnorr_verify
value|ssh_schnorr_verify
end_define

begin_define
define|#
directive|define
name|seed_rng
value|ssh_seed_rng
end_define

begin_define
define|#
directive|define
name|set_newkeys
value|ssh_set_newkeys
end_define

begin_define
define|#
directive|define
name|set_nodelay
value|ssh_set_nodelay
end_define

begin_define
define|#
directive|define
name|set_nonblock
value|ssh_set_nonblock
end_define

begin_define
define|#
directive|define
name|shadow_pw
value|ssh_shadow_pw
end_define

begin_define
define|#
directive|define
name|sigdie
value|ssh_sigdie
end_define

begin_define
define|#
directive|define
name|ssh1_3des_iv
value|ssh_ssh1_3des_iv
end_define

begin_define
define|#
directive|define
name|start_progress_meter
value|ssh_start_progress_meter
end_define

begin_define
define|#
directive|define
name|stop_progress_meter
value|ssh_stop_progress_meter
end_define

begin_define
define|#
directive|define
name|strdelim
value|ssh_strdelim
end_define

begin_define
define|#
directive|define
name|strnvis
value|ssh_strnvis
end_define

begin_define
define|#
directive|define
name|strvis
value|ssh_strvis
end_define

begin_define
define|#
directive|define
name|strvisx
value|ssh_strvisx
end_define

begin_define
define|#
directive|define
name|sys_tun_open
value|ssh_sys_tun_open
end_define

begin_define
define|#
directive|define
name|temporarily_use_uid
value|ssh_temporarily_use_uid
end_define

begin_define
define|#
directive|define
name|tilde_expand_filename
value|ssh_tilde_expand_filename
end_define

begin_define
define|#
directive|define
name|tohex
value|ssh_tohex
end_define

begin_define
define|#
directive|define
name|tty_make_modes
value|ssh_tty_make_modes
end_define

begin_define
define|#
directive|define
name|tty_parse_modes
value|ssh_tty_parse_modes
end_define

begin_define
define|#
directive|define
name|tun_open
value|ssh_tun_open
end_define

begin_define
define|#
directive|define
name|umac_ctx
value|ssh_umac_ctx
end_define

begin_define
define|#
directive|define
name|umac_delete
value|ssh_umac_delete
end_define

begin_define
define|#
directive|define
name|umac_final
value|ssh_umac_final
end_define

begin_define
define|#
directive|define
name|umac_new
value|ssh_umac_new
end_define

begin_define
define|#
directive|define
name|umac_update
value|ssh_umac_update
end_define

begin_define
define|#
directive|define
name|unset_nonblock
value|ssh_unset_nonblock
end_define

begin_define
define|#
directive|define
name|uudecode
value|ssh_uudecode
end_define

begin_define
define|#
directive|define
name|uuencode
value|ssh_uuencode
end_define

begin_define
define|#
directive|define
name|verbose
value|ssh_verbose
end_define

begin_define
define|#
directive|define
name|verbose
value|ssh_verbose
end_define

begin_define
define|#
directive|define
name|verify_host_key_dns
value|ssh_verify_host_key_dns
end_define

begin_define
define|#
directive|define
name|vis
value|ssh_vis
end_define

begin_define
define|#
directive|define
name|x11_connect_display
value|ssh_x11_connect_display
end_define

begin_define
define|#
directive|define
name|x11_create_display_inet
value|ssh_x11_create_display_inet
end_define

begin_define
define|#
directive|define
name|x11_input_open
value|ssh_x11_input_open
end_define

begin_define
define|#
directive|define
name|x11_request_forwarding_with_spoofing
value|ssh_x11_request_forwarding_with_spoofing
end_define

begin_define
define|#
directive|define
name|xasprintf
value|ssh_xasprintf
end_define

begin_define
define|#
directive|define
name|xcalloc
value|ssh_xcalloc
end_define

begin_define
define|#
directive|define
name|xcrypt
value|ssh_xcrypt
end_define

begin_define
define|#
directive|define
name|xfree
value|ssh_xfree
end_define

begin_define
define|#
directive|define
name|xmalloc
value|ssh_xmalloc
end_define

begin_define
define|#
directive|define
name|xmmap
value|ssh_xmmap
end_define

begin_define
define|#
directive|define
name|xrealloc
value|ssh_xrealloc
end_define

begin_define
define|#
directive|define
name|xstrdup
value|ssh_xstrdup
end_define

end_unit

