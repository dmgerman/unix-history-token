begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * $FreeBSD$  * $Source: /usr/sww/share/src/kerberosIV.BSD/include/RCS/rkinit_private.h,v $  * $Author: dglo $  *  * Header file for rkinit library and server internal use  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RKINIT_PRIVATE_H__
end_ifndef

begin_define
define|#
directive|define
name|__RKINIT_PRIVATE_H__
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SABER
argument_list|)
end_if

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|rcsid_rkinit_private_h
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint || SABER */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|RK_PROTO
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RK_PROTO
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_define
define|#
directive|define
name|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_comment
comment|/* Lowest and highest versions supported */
end_comment

begin_define
define|#
directive|define
name|RKINIT_LVERSION
value|3
end_define

begin_define
define|#
directive|define
name|RKINIT_HVERSION
value|3
end_define

begin_comment
comment|/* Service to be used; port number to fall back on if service isn't found */
end_comment

begin_define
define|#
directive|define
name|SERVENT
value|"rkinit"
end_define

begin_define
define|#
directive|define
name|PORT
value|2108
end_define

begin_comment
comment|/* Key for kerberos authentication */
end_comment

begin_define
define|#
directive|define
name|KEY
value|"rcmd"
end_define

begin_comment
comment|/* Packet format information */
end_comment

begin_define
define|#
directive|define
name|PKT_TYPE
value|0
end_define

begin_define
define|#
directive|define
name|PKT_LEN
value|1
end_define

begin_define
define|#
directive|define
name|PKT_DATA
value|(PKT_LEN + sizeof(u_int32_t))
end_define

begin_comment
comment|/* Number of retries during message reads */
end_comment

begin_define
define|#
directive|define
name|RETRIES
value|15
end_define

begin_comment
comment|/*   * Message types for packets.  Make sure that rki_mt_to_string is right in   * rk_util.c  */
end_comment

begin_define
define|#
directive|define
name|MT_STATUS
value|0
end_define

begin_define
define|#
directive|define
name|MT_CVERSION
value|1
end_define

begin_define
define|#
directive|define
name|MT_SVERSION
value|2
end_define

begin_define
define|#
directive|define
name|MT_RKINIT_INFO
value|3
end_define

begin_define
define|#
directive|define
name|MT_SKDC
value|4
end_define

begin_define
define|#
directive|define
name|MT_CKDC
value|5
end_define

begin_define
define|#
directive|define
name|MT_AUTH
value|6
end_define

begin_define
define|#
directive|define
name|MT_DROP
value|7
end_define

begin_comment
comment|/* Miscellaneous protocol constants */
end_comment

begin_define
define|#
directive|define
name|VERSION_INFO_SIZE
value|2
end_define

begin_comment
comment|/* Useful definitions */
end_comment

begin_define
define|#
directive|define
name|BCLEAR
parameter_list|(
name|a
parameter_list|)
value|bzero((char *)(a), sizeof(a))
end_define

begin_define
define|#
directive|define
name|SBCLEAR
parameter_list|(
name|a
parameter_list|)
value|bzero((char *)&(a), sizeof(a))
end_define

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)< (b)) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)> (b)) ? (a) : (b))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_JBLEN
end_ifdef

begin_define
define|#
directive|define
name|SETJMP_TYPEDEFED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Function declarations */
end_comment

begin_decl_stmt
name|int
name|rki_key_proc
name|RK_PROTO
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
name|des_cblock
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rki_get_tickets
name|RK_PROTO
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|rkinit_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rki_send_packet
name|RK_PROTO
argument_list|(
operator|(
name|int
operator|,
name|char
operator|,
name|u_int32_t
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rki_get_packet
name|RK_PROTO
argument_list|(
operator|(
name|int
operator|,
name|u_char
operator|,
name|u_int32_t
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
name|rki_setup_rpc
name|RK_PROTO
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
name|rki_rpc_exchange_version_info
name|RK_PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rki_rpc_send_rkinit_info
name|RK_PROTO
argument_list|(
operator|(
name|rkinit_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rki_rpc_get_status
name|RK_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rki_rpc_get_ktext
name|RK_PROTO
argument_list|(
operator|(
name|int
operator|,
name|KTEXT
operator|,
name|u_char
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rki_rpc_sendauth
name|RK_PROTO
argument_list|(
operator|(
name|KTEXT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rki_rpc_get_skdc
name|RK_PROTO
argument_list|(
operator|(
name|KTEXT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rki_rpc_send_ckdc
name|RK_PROTO
argument_list|(
operator|(
name|MSG_DAT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rki_get_csaddr
name|RK_PROTO
argument_list|(
operator|(
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

begin_decl_stmt
name|void
name|rki_drop_server
name|RK_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rki_cleanup_rpc
name|RK_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rki_dmsg
name|RK_PROTO
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|rki_mt_to_string
name|RK_PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rki_choose_version
name|RK_PROTO
argument_list|(
operator|(
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rki_send_rkinit_info
name|RK_PROTO
argument_list|(
operator|(
name|int
operator|,
name|rkinit_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SETJMP_TYPEDEFED
end_ifdef

begin_macro
name|void
argument_list|(
argument|*rki_setup_timer RK_PROTO((jmp_buf env))
argument_list|)
end_macro

begin_expr_stmt
name|RK_PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|void
name|rki_restore_timer
name|RK_PROTO
argument_list|(
operator|(
name|void
argument_list|(
operator|*
name|old_alrm
argument_list|)
argument_list|(
name|int
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rki_cleanup_rpc
name|RK_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __RKINIT_PRIVATE_H__ */
end_comment

end_unit

