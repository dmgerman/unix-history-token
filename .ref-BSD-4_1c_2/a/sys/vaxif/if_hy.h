begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	if_hy.h	4.2	83/02/21	*/
end_comment

begin_comment
comment|/*  * Network Systems Corporation Hyperchannel  *	routing database  */
end_comment

begin_define
define|#
directive|define
name|HYRSIZE
value|37
end_define

begin_comment
comment|/* max number of adapters in routing tables */
end_comment

begin_struct
struct|struct
name|hyroute
block|{
name|struct
name|timeval
name|hyr_lasttime
decl_stmt|;
comment|/* last update time */
struct|struct
name|hy_hash
block|{
name|u_short
name|hyr_flags
decl_stmt|;
comment|/* status flags - see below */
name|u_short
name|hyr_key
decl_stmt|;
comment|/* desired address */
union|union
block|{
comment|/* 			 * direct entry (can get there directly) 			 */
struct|struct
block|{
name|u_short
name|hyru_dst
decl_stmt|;
comment|/* adapter number& port */
name|u_short
name|hyru_ctl
decl_stmt|;
comment|/* trunks to try */
name|u_short
name|hyru_access
decl_stmt|;
comment|/* access code (mostly unused) */
block|}
name|hyr_d
struct|;
define|#
directive|define
name|hyr_dst
value|hyr_u.hyr_d.hyru_dst
define|#
directive|define
name|hyr_ctl
value|hyr_u.hyr_d.hyru_ctl
define|#
directive|define
name|hyr_access
value|hyr_u.hyr_d.hyru_access
comment|/* 			 * indirect entry (one or more hops required) 			 */
struct|struct
block|{
name|u_char
name|hyru_pgate
decl_stmt|;
comment|/* 1st gateway slot */
name|u_char
name|hyru_egate
decl_stmt|;
comment|/* # gateways */
name|u_char
name|hyru_nextgate
decl_stmt|;
comment|/* gateway to use next */
block|}
name|hyr_i
struct|;
define|#
directive|define
name|hyr_pgate
value|hyr_u.hyr_i.hyru_pgate
define|#
directive|define
name|hyr_egate
value|hyr_u.hyr_i.hyru_egate
define|#
directive|define
name|hyr_nextgate
value|hyr_u.hyr_i.hyru_nextgate
block|}
name|hyr_u
union|;
block|}
name|hyr_hash
index|[
name|HYRSIZE
index|]
struct|;
name|u_char
name|hyr_gateway
index|[
literal|256
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|hyroute
name|hy_route
index|[
name|NHY
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HYR_INUSE
value|0x01
end_define

begin_comment
comment|/* entry in use */
end_comment

begin_define
define|#
directive|define
name|HYR_DIR
value|0x02
end_define

begin_comment
comment|/* direct entry */
end_comment

begin_define
define|#
directive|define
name|HYR_GATE
value|0x04
end_define

begin_comment
comment|/* gateway entry */
end_comment

begin_define
define|#
directive|define
name|HYRHASH
parameter_list|(
name|x
parameter_list|)
value|(((x) ^ ((x)>> 16)) % HYRSIZE)
end_define

begin_define
define|#
directive|define
name|HYSETROUTE
value|_IOW(H, 0x80, sizeof (struct hyroute))
end_define

begin_define
define|#
directive|define
name|HYGETROUTE
value|_IOR(H, 0x81, sizeof (struct hyroute))
end_define

end_unit

