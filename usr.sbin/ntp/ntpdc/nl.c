begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(union req_data_u_tag) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|union
name|req_data_u_tag
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(u32) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|union
name|req_data_u_tag
argument_list|,
name|u32
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(data) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|union
name|req_data_u_tag
argument_list|,
name|data
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct req_pkt) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|req_pkt
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(rm_vn_mode) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|req_pkt
argument_list|,
name|rm_vn_mode
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(auth_seq) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|req_pkt
argument_list|,
name|auth_seq
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(implementation) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|req_pkt
argument_list|,
name|implementation
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(request) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|req_pkt
argument_list|,
name|request
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(err_nitems) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|req_pkt
argument_list|,
name|err_nitems
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(mbz_itemsize) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|req_pkt
argument_list|,
name|mbz_itemsize
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(u) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|req_pkt
argument_list|,
name|u
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(tstamp) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|req_pkt
argument_list|,
name|tstamp
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(keyid) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|req_pkt
argument_list|,
name|keyid
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(mac) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|req_pkt
argument_list|,
name|mac
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct req_pkt_tail) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|req_pkt_tail
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(tstamp) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|req_pkt_tail
argument_list|,
name|tstamp
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(keyid) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|req_pkt_tail
argument_list|,
name|keyid
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(mac) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|req_pkt_tail
argument_list|,
name|mac
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(union resp_pkt_u_tag) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|union
name|resp_pkt_u_tag
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(data) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|union
name|resp_pkt_u_tag
argument_list|,
name|data
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(u32) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|union
name|resp_pkt_u_tag
argument_list|,
name|u32
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct resp_pkt) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|resp_pkt
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(rm_vn_mode) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|resp_pkt
argument_list|,
name|rm_vn_mode
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(auth_seq) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|resp_pkt
argument_list|,
name|auth_seq
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(implementation) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|resp_pkt
argument_list|,
name|implementation
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(request) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|resp_pkt
argument_list|,
name|request
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(err_nitems) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|resp_pkt
argument_list|,
name|err_nitems
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(mbz_itemsize) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|resp_pkt
argument_list|,
name|mbz_itemsize
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(u) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|resp_pkt
argument_list|,
name|u
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct info_peer_list) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|info_peer_list
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(addr) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_list
argument_list|,
name|addr
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(port) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_list
argument_list|,
name|port
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(hmode) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_list
argument_list|,
name|hmode
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(flags) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_list
argument_list|,
name|flags
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(v6_flag) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_list
argument_list|,
name|v6_flag
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused1) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_list
argument_list|,
name|unused1
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(addr6) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_list
argument_list|,
name|addr6
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct info_peer_summary) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|info_peer_summary
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(dstadr) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_summary
argument_list|,
name|dstadr
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(srcadr) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_summary
argument_list|,
name|srcadr
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(srcport) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_summary
argument_list|,
name|srcport
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(stratum) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_summary
argument_list|,
name|stratum
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(hpoll) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_summary
argument_list|,
name|hpoll
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(ppoll) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_summary
argument_list|,
name|ppoll
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(reach) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_summary
argument_list|,
name|reach
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(flags) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_summary
argument_list|,
name|flags
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(hmode) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_summary
argument_list|,
name|hmode
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(delay) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_summary
argument_list|,
name|delay
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(offset) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_summary
argument_list|,
name|offset
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(dispersion) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_summary
argument_list|,
name|dispersion
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(v6_flag) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_summary
argument_list|,
name|v6_flag
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused1) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_summary
argument_list|,
name|unused1
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(dstadr6) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_summary
argument_list|,
name|dstadr6
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(srcadr6) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_summary
argument_list|,
name|srcadr6
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct info_peer) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|info_peer
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(dstadr) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|dstadr
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(srcadr) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|srcadr
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(srcport) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|srcport
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(flags) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|flags
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(leap) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|leap
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(hmode) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|hmode
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(pmode) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|pmode
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(stratum) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|stratum
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(ppoll) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|ppoll
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(hpoll) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|hpoll
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(precision) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|precision
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(version) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|version
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused8) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|unused8
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(reach) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|reach
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unreach) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|unreach
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(flash) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|flash
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(ttl) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|ttl
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(flash2) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|flash2
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(associd) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|associd
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(keyid) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|keyid
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(pkeyid) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|pkeyid
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(refid) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|refid
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(timer) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|timer
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(rootdelay) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|rootdelay
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(rootdispersion) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|rootdispersion
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(reftime) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|reftime
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(org) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|org
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(rec) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|rec
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(xmt) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|xmt
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(filtdelay) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|filtdelay
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(filtoffset) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|filtoffset
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(order) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|order
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(delay) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|delay
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(dispersion) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|dispersion
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(offset) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|offset
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(selectdisp) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|selectdisp
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused1) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|unused1
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused2) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|unused2
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused3) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|unused3
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused4) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|unused4
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused5) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|unused5
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused6) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|unused6
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused7) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|unused7
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(estbdelay) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|estbdelay
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(v6_flag) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|v6_flag
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused9) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|unused9
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(dstadr6) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|dstadr6
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(srcadr6) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer
argument_list|,
name|srcadr6
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct info_peer_stats) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(dstadr) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|,
name|dstadr
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(srcadr) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|,
name|srcadr
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(srcport) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|,
name|srcport
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(flags) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|,
name|flags
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(timereset) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|,
name|timereset
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(timereceived) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|,
name|timereceived
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(timetosend) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|,
name|timetosend
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(timereachable) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|,
name|timereachable
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(sent) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|,
name|sent
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused1) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|,
name|unused1
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(processed) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|,
name|processed
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused2) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|,
name|unused2
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(badauth) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|,
name|badauth
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(bogusorg) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|,
name|bogusorg
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(oldpkt) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|,
name|oldpkt
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused3) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|,
name|unused3
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused4) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|,
name|unused4
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(seldisp) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|,
name|seldisp
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(selbroken) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|,
name|selbroken
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused5) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|,
name|unused5
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(candidate) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|,
name|candidate
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused6) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|,
name|unused6
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused7) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|,
name|unused7
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused8) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|,
name|unused8
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(v6_flag) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|,
name|v6_flag
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused9) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|,
name|unused9
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(dstadr6) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|,
name|dstadr6
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(srcadr6) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_peer_stats
argument_list|,
name|srcadr6
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct info_loop) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|info_loop
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(last_offset) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_loop
argument_list|,
name|last_offset
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(drift_comp) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_loop
argument_list|,
name|drift_comp
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(compliance) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_loop
argument_list|,
name|compliance
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(watchdog_timer) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_loop
argument_list|,
name|watchdog_timer
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct info_sys) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|info_sys
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(peer) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys
argument_list|,
name|peer
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(peer_mode) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys
argument_list|,
name|peer_mode
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(leap) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys
argument_list|,
name|leap
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(stratum) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys
argument_list|,
name|stratum
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(precision) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys
argument_list|,
name|precision
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(rootdelay) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys
argument_list|,
name|rootdelay
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(rootdispersion) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys
argument_list|,
name|rootdispersion
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(refid) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys
argument_list|,
name|refid
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(reftime) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys
argument_list|,
name|reftime
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(poll) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys
argument_list|,
name|poll
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(flags) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys
argument_list|,
name|flags
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused1) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys
argument_list|,
name|unused1
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused2) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys
argument_list|,
name|unused2
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused3) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys
argument_list|,
name|unused3
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(bdelay) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys
argument_list|,
name|bdelay
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(frequency) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys
argument_list|,
name|frequency
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(authdelay) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys
argument_list|,
name|authdelay
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(stability) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys
argument_list|,
name|stability
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(v6_flag) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys
argument_list|,
name|v6_flag
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused4) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys
argument_list|,
name|unused4
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(peer6) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys
argument_list|,
name|peer6
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct info_sys_stats) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|info_sys_stats
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(timeup) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys_stats
argument_list|,
name|timeup
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(timereset) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys_stats
argument_list|,
name|timereset
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(denied) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys_stats
argument_list|,
name|denied
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(oldversionpkt) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys_stats
argument_list|,
name|oldversionpkt
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(newversionpkt) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys_stats
argument_list|,
name|newversionpkt
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unknownversion) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys_stats
argument_list|,
name|unknownversion
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(badlength) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys_stats
argument_list|,
name|badlength
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(processed) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys_stats
argument_list|,
name|processed
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(badauth) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys_stats
argument_list|,
name|badauth
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(received) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys_stats
argument_list|,
name|received
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(limitrejected) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_sys_stats
argument_list|,
name|limitrejected
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct old_info_sys_stats) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|old_info_sys_stats
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(timeup) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|old_info_sys_stats
argument_list|,
name|timeup
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(timereset) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|old_info_sys_stats
argument_list|,
name|timereset
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(denied) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|old_info_sys_stats
argument_list|,
name|denied
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(oldversionpkt) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|old_info_sys_stats
argument_list|,
name|oldversionpkt
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(newversionpkt) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|old_info_sys_stats
argument_list|,
name|newversionpkt
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unknownversion) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|old_info_sys_stats
argument_list|,
name|unknownversion
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(badlength) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|old_info_sys_stats
argument_list|,
name|badlength
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(processed) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|old_info_sys_stats
argument_list|,
name|processed
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(badauth) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|old_info_sys_stats
argument_list|,
name|badauth
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(wanderhold) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|old_info_sys_stats
argument_list|,
name|wanderhold
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct info_mem_stats) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|info_mem_stats
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(timereset) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_mem_stats
argument_list|,
name|timereset
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(totalpeermem) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_mem_stats
argument_list|,
name|totalpeermem
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(freepeermem) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_mem_stats
argument_list|,
name|freepeermem
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(findpeer_calls) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_mem_stats
argument_list|,
name|findpeer_calls
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(allocations) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_mem_stats
argument_list|,
name|allocations
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(demobilizations) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_mem_stats
argument_list|,
name|demobilizations
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(hashcount) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_mem_stats
argument_list|,
name|hashcount
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct info_io_stats) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|info_io_stats
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(timereset) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_io_stats
argument_list|,
name|timereset
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(totalrecvbufs) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_io_stats
argument_list|,
name|totalrecvbufs
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(freerecvbufs) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_io_stats
argument_list|,
name|freerecvbufs
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(fullrecvbufs) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_io_stats
argument_list|,
name|fullrecvbufs
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(lowwater) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_io_stats
argument_list|,
name|lowwater
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(dropped) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_io_stats
argument_list|,
name|dropped
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(ignored) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_io_stats
argument_list|,
name|ignored
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(received) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_io_stats
argument_list|,
name|received
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(sent) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_io_stats
argument_list|,
name|sent
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(notsent) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_io_stats
argument_list|,
name|notsent
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(interrupts) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_io_stats
argument_list|,
name|interrupts
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(int_received) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_io_stats
argument_list|,
name|int_received
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct info_timer_stats) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|info_timer_stats
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(timereset) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_timer_stats
argument_list|,
name|timereset
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(alarms) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_timer_stats
argument_list|,
name|alarms
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(overflows) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_timer_stats
argument_list|,
name|overflows
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(xmtcalls) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_timer_stats
argument_list|,
name|xmtcalls
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct old_conf_peer) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|old_conf_peer
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(peeraddr) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|old_conf_peer
argument_list|,
name|peeraddr
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(hmode) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|old_conf_peer
argument_list|,
name|hmode
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(version) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|old_conf_peer
argument_list|,
name|version
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(minpoll) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|old_conf_peer
argument_list|,
name|minpoll
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(maxpoll) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|old_conf_peer
argument_list|,
name|maxpoll
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(flags) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|old_conf_peer
argument_list|,
name|flags
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(ttl) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|old_conf_peer
argument_list|,
name|ttl
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|old_conf_peer
argument_list|,
name|unused
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(keyid) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|old_conf_peer
argument_list|,
name|keyid
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct conf_peer) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|conf_peer
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(peeraddr) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_peer
argument_list|,
name|peeraddr
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(hmode) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_peer
argument_list|,
name|hmode
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(version) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_peer
argument_list|,
name|version
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(minpoll) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_peer
argument_list|,
name|minpoll
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(maxpoll) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_peer
argument_list|,
name|maxpoll
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(flags) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_peer
argument_list|,
name|flags
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(ttl) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_peer
argument_list|,
name|ttl
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused1) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_peer
argument_list|,
name|unused1
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(keyid) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_peer
argument_list|,
name|keyid
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(keystr) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_peer
argument_list|,
name|keystr
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(v6_flag) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_peer
argument_list|,
name|v6_flag
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused2) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_peer
argument_list|,
name|unused2
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(peeraddr6) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_peer
argument_list|,
name|peeraddr6
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct conf_unpeer) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|conf_unpeer
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(peeraddr) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_unpeer
argument_list|,
name|peeraddr
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(v6_flag) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_unpeer
argument_list|,
name|v6_flag
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(peeraddr6) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_unpeer
argument_list|,
name|peeraddr6
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct conf_sys_flags) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|conf_sys_flags
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(flags) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_sys_flags
argument_list|,
name|flags
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct info_restrict) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|info_restrict
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(addr) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_restrict
argument_list|,
name|addr
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(mask) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_restrict
argument_list|,
name|mask
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(count) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_restrict
argument_list|,
name|count
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(flags) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_restrict
argument_list|,
name|flags
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(mflags) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_restrict
argument_list|,
name|mflags
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(v6_flag) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_restrict
argument_list|,
name|v6_flag
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused1) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_restrict
argument_list|,
name|unused1
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(addr6) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_restrict
argument_list|,
name|addr6
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(mask6) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_restrict
argument_list|,
name|mask6
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct conf_restrict) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|conf_restrict
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(addr) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_restrict
argument_list|,
name|addr
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(mask) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_restrict
argument_list|,
name|mask
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(flags) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_restrict
argument_list|,
name|flags
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(mflags) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_restrict
argument_list|,
name|mflags
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(v6_flag) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_restrict
argument_list|,
name|v6_flag
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(addr6) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_restrict
argument_list|,
name|addr6
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(mask6) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_restrict
argument_list|,
name|mask6
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct info_monitor_1) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|info_monitor_1
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(avg_int) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_monitor_1
argument_list|,
name|avg_int
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(last_int) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_monitor_1
argument_list|,
name|last_int
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(restr) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_monitor_1
argument_list|,
name|restr
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(count) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_monitor_1
argument_list|,
name|count
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(addr) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_monitor_1
argument_list|,
name|addr
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(daddr) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_monitor_1
argument_list|,
name|daddr
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(flags) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_monitor_1
argument_list|,
name|flags
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(port) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_monitor_1
argument_list|,
name|port
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(mode) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_monitor_1
argument_list|,
name|mode
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(version) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_monitor_1
argument_list|,
name|version
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(v6_flag) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_monitor_1
argument_list|,
name|v6_flag
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused1) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_monitor_1
argument_list|,
name|unused1
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(addr6) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_monitor_1
argument_list|,
name|addr6
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(daddr6) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_monitor_1
argument_list|,
name|daddr6
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct info_monitor) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|info_monitor
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(avg_int) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_monitor
argument_list|,
name|avg_int
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(last_int) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_monitor
argument_list|,
name|last_int
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(restr) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_monitor
argument_list|,
name|restr
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(count) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_monitor
argument_list|,
name|count
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(addr) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_monitor
argument_list|,
name|addr
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(port) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_monitor
argument_list|,
name|port
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(mode) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_monitor
argument_list|,
name|mode
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(version) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_monitor
argument_list|,
name|version
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(v6_flag) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_monitor
argument_list|,
name|v6_flag
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused1) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_monitor
argument_list|,
name|unused1
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(addr6) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_monitor
argument_list|,
name|addr6
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct old_info_monitor) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|old_info_monitor
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(lasttime) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|old_info_monitor
argument_list|,
name|lasttime
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(firsttime) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|old_info_monitor
argument_list|,
name|firsttime
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(count) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|old_info_monitor
argument_list|,
name|count
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(addr) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|old_info_monitor
argument_list|,
name|addr
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(port) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|old_info_monitor
argument_list|,
name|port
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(mode) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|old_info_monitor
argument_list|,
name|mode
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(version) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|old_info_monitor
argument_list|,
name|version
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(v6_flag) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|old_info_monitor
argument_list|,
name|v6_flag
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(addr6) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|old_info_monitor
argument_list|,
name|addr6
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct reset_flags) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|reset_flags
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(flags) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|reset_flags
argument_list|,
name|flags
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct info_auth) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|info_auth
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(timereset) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_auth
argument_list|,
name|timereset
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(numkeys) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_auth
argument_list|,
name|numkeys
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(numfreekeys) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_auth
argument_list|,
name|numfreekeys
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(keylookups) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_auth
argument_list|,
name|keylookups
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(keynotfound) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_auth
argument_list|,
name|keynotfound
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(encryptions) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_auth
argument_list|,
name|encryptions
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(decryptions) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_auth
argument_list|,
name|decryptions
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(expired) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_auth
argument_list|,
name|expired
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(keyuncached) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_auth
argument_list|,
name|keyuncached
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct info_trap) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|info_trap
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(local_address) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_trap
argument_list|,
name|local_address
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(trap_address) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_trap
argument_list|,
name|trap_address
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(trap_port) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_trap
argument_list|,
name|trap_port
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(sequence) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_trap
argument_list|,
name|sequence
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(settime) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_trap
argument_list|,
name|settime
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(origtime) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_trap
argument_list|,
name|origtime
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(resets) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_trap
argument_list|,
name|resets
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(flags) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_trap
argument_list|,
name|flags
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(v6_flag) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_trap
argument_list|,
name|v6_flag
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(local_address6) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_trap
argument_list|,
name|local_address6
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(trap_address6) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_trap
argument_list|,
name|trap_address6
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct conf_trap) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|conf_trap
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(local_address) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_trap
argument_list|,
name|local_address
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(trap_address) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_trap
argument_list|,
name|trap_address
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(trap_port) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_trap
argument_list|,
name|trap_port
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unused) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_trap
argument_list|,
name|unused
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(v6_flag) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_trap
argument_list|,
name|v6_flag
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(local_address6) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_trap
argument_list|,
name|local_address6
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(trap_address6) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_trap
argument_list|,
name|trap_address6
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct info_control) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|info_control
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(ctltimereset) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_control
argument_list|,
name|ctltimereset
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(numctlreq) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_control
argument_list|,
name|numctlreq
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(numctlbadpkts) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_control
argument_list|,
name|numctlbadpkts
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(numctlresponses) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_control
argument_list|,
name|numctlresponses
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(numctlfrags) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_control
argument_list|,
name|numctlfrags
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(numctlerrors) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_control
argument_list|,
name|numctlerrors
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(numctltooshort) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_control
argument_list|,
name|numctltooshort
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(numctlinputresp) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_control
argument_list|,
name|numctlinputresp
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(numctlinputfrag) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_control
argument_list|,
name|numctlinputfrag
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(numctlinputerr) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_control
argument_list|,
name|numctlinputerr
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(numctlbadoffset) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_control
argument_list|,
name|numctlbadoffset
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(numctlbadversion) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_control
argument_list|,
name|numctlbadversion
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(numctldatatooshort) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_control
argument_list|,
name|numctldatatooshort
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(numctlbadop) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_control
argument_list|,
name|numctlbadop
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(numasyncmsgs) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_control
argument_list|,
name|numasyncmsgs
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct info_clock) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|info_clock
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(clockadr) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_clock
argument_list|,
name|clockadr
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(type) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_clock
argument_list|,
name|type
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(flags) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_clock
argument_list|,
name|flags
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(lastevent) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_clock
argument_list|,
name|lastevent
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(currentstatus) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_clock
argument_list|,
name|currentstatus
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(polls) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_clock
argument_list|,
name|polls
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(noresponse) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_clock
argument_list|,
name|noresponse
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(badformat) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_clock
argument_list|,
name|badformat
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(baddata) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_clock
argument_list|,
name|baddata
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(timestarted) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_clock
argument_list|,
name|timestarted
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(fudgetime1) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_clock
argument_list|,
name|fudgetime1
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(fudgetime2) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_clock
argument_list|,
name|fudgetime2
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(fudgeval1) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_clock
argument_list|,
name|fudgeval1
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(fudgeval2) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_clock
argument_list|,
name|fudgeval2
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct conf_fudge) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|conf_fudge
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(clockadr) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_fudge
argument_list|,
name|clockadr
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(which) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_fudge
argument_list|,
name|which
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(fudgetime) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_fudge
argument_list|,
name|fudgetime
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(fudgeval_flags) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|conf_fudge
argument_list|,
name|fudgeval_flags
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct info_clkbug) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|info_clkbug
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(clockadr) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_clkbug
argument_list|,
name|clockadr
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(nvalues) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_clkbug
argument_list|,
name|nvalues
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(ntimes) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_clkbug
argument_list|,
name|ntimes
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(svalues) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_clkbug
argument_list|,
name|svalues
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(stimes) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_clkbug
argument_list|,
name|stimes
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(values) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_clkbug
argument_list|,
name|values
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(times) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_clkbug
argument_list|,
name|times
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct info_kernel) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|info_kernel
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(offset) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_kernel
argument_list|,
name|offset
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(freq) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_kernel
argument_list|,
name|freq
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(maxerror) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_kernel
argument_list|,
name|maxerror
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(esterror) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_kernel
argument_list|,
name|esterror
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(status) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_kernel
argument_list|,
name|status
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(shift) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_kernel
argument_list|,
name|shift
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(constant) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_kernel
argument_list|,
name|constant
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(precision) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_kernel
argument_list|,
name|precision
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(tolerance) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_kernel
argument_list|,
name|tolerance
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(ppsfreq) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_kernel
argument_list|,
name|ppsfreq
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(jitter) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_kernel
argument_list|,
name|jitter
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(stabil) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_kernel
argument_list|,
name|stabil
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(jitcnt) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_kernel
argument_list|,
name|jitcnt
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(calcnt) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_kernel
argument_list|,
name|calcnt
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(errcnt) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_kernel
argument_list|,
name|errcnt
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(stbcnt) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_kernel
argument_list|,
name|stbcnt
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct info_if_stats) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|info_if_stats
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unaddr) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_if_stats
argument_list|,
name|unaddr
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unbcast) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_if_stats
argument_list|,
name|unbcast
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(unmask) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_if_stats
argument_list|,
name|unmask
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(v6_flag) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_if_stats
argument_list|,
name|v6_flag
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(name) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_if_stats
argument_list|,
name|name
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(flags) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_if_stats
argument_list|,
name|flags
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(last_ttl) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_if_stats
argument_list|,
name|last_ttl
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(num_mcast) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_if_stats
argument_list|,
name|num_mcast
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(received) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_if_stats
argument_list|,
name|received
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(sent) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_if_stats
argument_list|,
name|sent
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(notsent) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_if_stats
argument_list|,
name|notsent
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(uptime) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_if_stats
argument_list|,
name|uptime
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(scopeid) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_if_stats
argument_list|,
name|scopeid
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(ifindex) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_if_stats
argument_list|,
name|ifindex
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(ifnum) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_if_stats
argument_list|,
name|ifnum
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(peercnt) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_if_stats
argument_list|,
name|peercnt
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(family) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_if_stats
argument_list|,
name|family
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(ignore_packets) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_if_stats
argument_list|,
name|ignore_packets
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(action) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_if_stats
argument_list|,
name|action
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(_filler0) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_if_stats
argument_list|,
name|_filler0
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"sizeof(struct info_dns_assoc) = %d\n"
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
argument_list|(
expr|struct
name|info_dns_assoc
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(peeraddr) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_dns_assoc
argument_list|,
name|peeraddr
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(associd) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_dns_assoc
argument_list|,
name|associd
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"offsetof(hostname) = %d\n"
argument_list|,
operator|(
name|int
operator|)
name|offsetof
argument_list|(
expr|struct
name|info_dns_assoc
argument_list|,
name|hostname
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

