begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|P
parameter_list|(
name|s
parameter_list|)
value|s
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P
parameter_list|(
name|s
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* add_ticket.c */
end_comment

begin_decl_stmt
name|int
name|add_ticket
name|P
argument_list|(
operator|(
name|KTEXT
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|KTEXT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* cr_err_reply.c */
end_comment

begin_decl_stmt
name|void
name|cr_err_reply
name|P
argument_list|(
operator|(
name|KTEXT
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|u_long
operator|,
name|u_long
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* create_auth_reply.c */
end_comment

begin_decl_stmt
name|KTEXT
name|create_auth_reply
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|long
operator|,
name|int
operator|,
name|unsigned
name|long
operator|,
name|int
operator|,
name|KTEXT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* create_ciph.c */
end_comment

begin_decl_stmt
name|int
name|create_ciph
name|P
argument_list|(
operator|(
name|KTEXT
operator|,
name|C_Block
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|unsigned
name|long
operator|,
name|int
operator|,
name|KTEXT
operator|,
name|unsigned
name|long
operator|,
name|C_Block
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* create_death_packet.c */
end_comment

begin_decl_stmt
name|KTEXT
name|krb_create_death_packet
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* create_ticket.c */
end_comment

begin_decl_stmt
name|int
name|krb_create_ticket
name|P
argument_list|(
operator|(
name|KTEXT
operator|,
name|unsigned
name|int
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|long
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|long
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|C_Block
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debug_decl.c */
end_comment

begin_comment
comment|/* decomp_ticket.c */
end_comment

begin_decl_stmt
name|int
name|decomp_ticket
name|P
argument_list|(
operator|(
name|KTEXT
operator|,
name|unsigned
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|unsigned
name|long
operator|*
operator|,
name|C_Block
operator|,
name|int
operator|*
operator|,
name|unsigned
name|long
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|C_Block
operator|,
name|Key_schedule
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dest_tkt.c */
end_comment

begin_decl_stmt
name|int
name|dest_tkt
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* extract_ticket.c */
end_comment

begin_decl_stmt
name|int
name|extract_ticket
name|P
argument_list|(
operator|(
name|KTEXT
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|*
operator|,
name|char
operator|*
operator|,
name|KTEXT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* fgetst.c */
end_comment

begin_decl_stmt
name|int
name|fgetst
name|P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* get_ad_tkt.c */
end_comment

begin_decl_stmt
name|int
name|get_ad_tkt
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* get_admhst.c */
end_comment

begin_decl_stmt
name|int
name|krb_get_admhst
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* get_cred.c */
end_comment

begin_decl_stmt
name|int
name|krb_get_cred
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|CREDENTIALS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* get_in_tkt.c */
end_comment

begin_decl_stmt
name|int
name|krb_get_pw_in_tkt
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|placebo_read_password
name|P
argument_list|(
operator|(
name|des_cblock
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|placebo_read_pw_string
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* get_krbhst.c */
end_comment

begin_decl_stmt
name|int
name|krb_get_krbhst
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* get_krbrlm.c */
end_comment

begin_decl_stmt
name|int
name|krb_get_lrealm
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* get_phost.c */
end_comment

begin_decl_stmt
name|char
modifier|*
name|krb_get_phost
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* get_pw_tkt.c */
end_comment

begin_decl_stmt
name|int
name|get_pw_tkt
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* get_request.c */
end_comment

begin_decl_stmt
name|int
name|get_request
name|P
argument_list|(
operator|(
name|KTEXT
operator|,
name|int
operator|,
name|char
operator|*
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* get_svc_in_tkt.c */
end_comment

begin_decl_stmt
name|int
name|krb_get_svc_in_tkt
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* get_tf_fullname.c */
end_comment

begin_decl_stmt
name|int
name|krb_get_tf_fullname
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* get_tf_realm.c */
end_comment

begin_decl_stmt
name|int
name|krb_get_tf_realm
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* getopt.c */
end_comment

begin_decl_stmt
name|int
name|getopt
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* getrealm.c */
end_comment

begin_decl_stmt
name|char
modifier|*
name|krb_realmofhost
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* getst.c */
end_comment

begin_decl_stmt
name|int
name|getst
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in_tkt.c */
end_comment

begin_decl_stmt
name|int
name|in_tkt
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* k_gethostname.c */
end_comment

begin_decl_stmt
name|int
name|k_gethostname
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* klog.c */
end_comment

begin_decl_stmt
name|char
modifier|*
name|klog
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|kset_logfile
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kname_parse.c */
end_comment

begin_decl_stmt
name|int
name|kname_parse
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|k_isname
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|k_isinst
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|k_isrealm
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kntoln.c */
end_comment

begin_decl_stmt
name|int
name|krb_kntoln
name|P
argument_list|(
operator|(
name|AUTH_DAT
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* krb_err_txt.c */
end_comment

begin_comment
comment|/* krb_get_in_tkt.c */
end_comment

begin_decl_stmt
name|int
name|krb_get_in_tkt
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|int
argument_list|(
operator|*
name|key_proc
argument_list|)
argument_list|()
operator|,
name|int
argument_list|(
operator|*
name|decrypt_proc
argument_list|)
argument_list|()
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* kuserok.c */
end_comment

begin_decl_stmt
name|int
name|kuserok
name|P
argument_list|(
operator|(
name|AUTH_DAT
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* log.c */
end_comment

begin_decl_stmt
name|void
name|log
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|set_logfile
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|new_log
name|P
argument_list|(
operator|(
name|long
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mk_err.c */
end_comment

begin_decl_stmt
name|long
name|krb_mk_err
name|P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|long
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mk_priv.c */
end_comment

begin_decl_stmt
name|long
name|krb_mk_priv
name|P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|u_char
operator|*
operator|,
name|u_long
operator|,
name|Key_schedule
operator|,
name|C_Block
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mk_req.c */
end_comment

begin_decl_stmt
name|int
name|krb_mk_req
name|P
argument_list|(
operator|(
name|KTEXT
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_set_lifetime
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mk_safe.c */
end_comment

begin_decl_stmt
name|long
name|krb_mk_safe
name|P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|u_char
operator|*
operator|,
name|u_long
operator|,
name|C_Block
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* month_sname.c */
end_comment

begin_decl_stmt
name|char
modifier|*
name|month_sname
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* netread.c */
end_comment

begin_decl_stmt
name|int
name|krb_net_read
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* netwrite.c */
end_comment

begin_decl_stmt
name|int
name|krb_net_write
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* one.c */
end_comment

begin_comment
comment|/* pkt_cipher.c */
end_comment

begin_decl_stmt
name|KTEXT
name|pkt_cipher
name|P
argument_list|(
operator|(
name|KTEXT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pkt_clen.c */
end_comment

begin_decl_stmt
name|int
name|pkt_clen
name|P
argument_list|(
operator|(
name|KTEXT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rd_err.c */
end_comment

begin_decl_stmt
name|int
name|krb_rd_err
name|P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|u_long
operator|,
name|long
operator|*
operator|,
name|MSG_DAT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rd_priv.c */
end_comment

begin_decl_stmt
name|long
name|krb_rd_priv
name|P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|u_long
operator|,
name|Key_schedule
operator|,
name|C_Block
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
name|MSG_DAT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rd_req.c */
end_comment

begin_decl_stmt
name|int
name|krb_set_key
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_rd_req
name|P
argument_list|(
operator|(
name|KTEXT
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|long
operator|,
name|AUTH_DAT
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rd_safe.c */
end_comment

begin_decl_stmt
name|long
name|krb_rd_safe
name|P
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|u_long
operator|,
name|C_Block
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
name|MSG_DAT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* read_service_key.c */
end_comment

begin_decl_stmt
name|int
name|read_service_key
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* recvauth.c */
end_comment

begin_decl_stmt
name|int
name|krb_recvauth
name|P
argument_list|(
operator|(
name|long
operator|,
name|int
operator|,
name|KTEXT
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
name|AUTH_DAT
operator|*
operator|,
name|char
operator|*
operator|,
name|Key_schedule
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* save_credentials.c */
end_comment

begin_decl_stmt
name|int
name|save_credentials
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|C_Block
operator|,
name|int
operator|,
name|int
operator|,
name|KTEXT
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* send_to_kdc.c */
end_comment

begin_decl_stmt
name|int
name|send_to_kdc
name|P
argument_list|(
operator|(
name|KTEXT
operator|,
name|KTEXT
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sendauth.c */
end_comment

begin_decl_stmt
name|int
name|krb_sendauth
name|P
argument_list|(
operator|(
name|long
operator|,
name|int
operator|,
name|KTEXT
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|u_long
operator|,
name|MSG_DAT
operator|*
operator|,
name|CREDENTIALS
operator|*
operator|,
name|Key_schedule
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_sendsvc
name|P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* setenv.c */
end_comment

begin_decl_stmt
name|int
name|setenv
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|unsetenv
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|getenv
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|_findenv
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stime.c */
end_comment

begin_decl_stmt
name|char
modifier|*
name|stime
name|P
argument_list|(
operator|(
name|long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tf_shm.c */
end_comment

begin_decl_stmt
name|int
name|krb_shm_create
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_is_diskless
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|krb_shm_dest
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tf_util.c */
end_comment

begin_decl_stmt
name|int
name|tf_init
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tf_get_pname
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tf_get_pinst
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tf_get_cred
name|P
argument_list|(
operator|(
name|CREDENTIALS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tf_close
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tf_save_cred
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|C_Block
operator|,
name|int
operator|,
name|int
operator|,
name|KTEXT
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tkt_string.c */
end_comment

begin_decl_stmt
name|char
modifier|*
name|tkt_string
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|krb_set_tkt_string
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* util.c */
end_comment

begin_decl_stmt
name|int
name|ad_print
name|P
argument_list|(
operator|(
name|AUTH_DAT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|placebo_cblock_print
name|P
argument_list|(
operator|(
name|des_cblock
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|P
end_undef

end_unit

