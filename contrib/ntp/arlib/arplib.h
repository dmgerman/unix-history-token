begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * arplib.h (C)opyright 1992 Darren Reed.  */
end_comment

begin_define
define|#
directive|define
name|MAXPACKET
value|1024
end_define

begin_define
define|#
directive|define
name|MAXALIASES
value|35
end_define

begin_define
define|#
directive|define
name|MAXADDRS
value|35
end_define

begin_define
define|#
directive|define
name|RES_CHECKPTR
value|0x0400
end_define

begin_struct
struct|struct
name|hent
block|{
name|char
modifier|*
name|h_name
decl_stmt|;
comment|/* official name of host */
name|char
modifier|*
name|h_aliases
index|[
name|MAXALIASES
index|]
decl_stmt|;
comment|/* alias list */
name|int
name|h_addrtype
decl_stmt|;
comment|/* host address type */
name|int
name|h_length
decl_stmt|;
comment|/* length of address */
comment|/* list of addresses from name server */
name|struct
name|in_addr
name|h_addr_list
index|[
name|MAXADDRS
index|]
decl_stmt|;
define|#
directive|define
name|h_addr
value|h_addr_list[0]
comment|/* address, for backward compatiblity */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|resinfo
block|{
name|char
modifier|*
name|ri_ptr
decl_stmt|;
name|int
name|ri_size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|reslist
block|{
name|int
name|re_id
decl_stmt|;
name|char
name|re_type
decl_stmt|;
name|char
name|re_retries
decl_stmt|;
name|char
name|re_resend
decl_stmt|;
comment|/* send flag. 0 == dont resend */
name|char
name|re_sends
decl_stmt|;
name|char
name|re_srch
decl_stmt|;
name|int
name|re_sent
decl_stmt|;
name|u_long
name|re_sentat
decl_stmt|;
name|u_long
name|re_timeout
decl_stmt|;
name|struct
name|in_addr
name|re_addr
decl_stmt|;
name|struct
name|resinfo
name|re_rinfo
decl_stmt|;
name|struct
name|hent
name|re_he
decl_stmt|;
name|struct
name|reslist
modifier|*
name|re_next
decl_stmt|,
modifier|*
name|re_prev
decl_stmt|;
name|char
name|re_name
index|[
literal|65
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (b) : (a))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

