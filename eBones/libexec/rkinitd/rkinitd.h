begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * $FreeBSD$  * $Source: /usr/src/eBones/rkinitd/RCS/rkinitd.h,v $  * $Author: dglo $  *  * This header file contains function declarations for use for rkinitd  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RKINITD_H__
end_ifndef

begin_define
define|#
directive|define
name|__RKINITD_H__
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
operator|&&
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
operator|&&
name|defined
argument_list|(
name|RCS_HDRS
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid_rkinitd_h
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint || SABER || LOCORE || RCS_HDRS */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_decl_stmt
name|int
name|get_tickets
name|RK_PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|error
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
name|setup_rpc
name|RK_PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rpc_exchange_version_info
name|RK_PROTO
argument_list|(
operator|(
name|int
operator|*
operator|,
name|int
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rpc_get_rkinit_info
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
name|void
name|rpc_send_error
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
name|void
name|rpc_send_success
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
name|rpc_exchange_tkt
name|RK_PROTO
argument_list|(
operator|(
name|KTEXT
operator|,
name|MSG_DAT
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rpc_getauth
name|RK_PROTO
argument_list|(
operator|(
name|KTEXT
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

begin_decl_stmt
name|int
name|choose_version
name|RK_PROTO
argument_list|(
operator|(
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __RKINITD_H__ */
end_comment

end_unit

