begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ip.h 1.11 82/12/28 */
end_comment

begin_comment
comment|/*  * Definitions for internet protocol version 4.  * Per RFC 791, September 1981.  */
end_comment

begin_define
define|#
directive|define
name|IPVERSION
value|4
end_define

begin_comment
comment|/*  * Structure of an internet header, naked of options.  *  * We declare ip_len and ip_off to be short, rather than u_short  * pragmatically since otherwise unsigned comparisons can result  * against negative integers quite easily, and fail in subtle ways.  */
end_comment

begin_struct
struct|struct
name|ip
block|{
ifdef|#
directive|ifdef
name|vax
name|u_char
name|ip_hl
range|:
literal|4
decl_stmt|,
comment|/* header length */
name|ip_v
range|:
literal|4
decl_stmt|;
comment|/* version */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|sun
name|u_char
name|ip_v
range|:
literal|4
decl_stmt|,
comment|/* version */
name|ip_hl
range|:
literal|4
decl_stmt|;
comment|/* header length */
endif|#
directive|endif
name|u_char
name|ip_tos
decl_stmt|;
comment|/* type of service */
name|short
name|ip_len
decl_stmt|;
comment|/* total length */
name|u_short
name|ip_id
decl_stmt|;
comment|/* identification */
name|short
name|ip_off
decl_stmt|;
comment|/* fragment offset field */
define|#
directive|define
name|IP_DF
value|0x4000
comment|/* dont fragment flag */
define|#
directive|define
name|IP_MF
value|0x2000
comment|/* more fragments flag */
name|u_char
name|ip_ttl
decl_stmt|;
comment|/* time to live */
name|u_char
name|ip_p
decl_stmt|;
comment|/* protocol */
name|u_short
name|ip_sum
decl_stmt|;
comment|/* checksum */
name|struct
name|in_addr
name|ip_src
decl_stmt|,
name|ip_dst
decl_stmt|;
comment|/* source and dest address */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Definitions for options.  */
end_comment

begin_define
define|#
directive|define
name|IPOPT_COPIED
parameter_list|(
name|o
parameter_list|)
value|((o)&0x80)
end_define

begin_define
define|#
directive|define
name|IPOPT_CLASS
parameter_list|(
name|o
parameter_list|)
value|((o)&0x40)
end_define

begin_define
define|#
directive|define
name|IPOPT_NUMBER
parameter_list|(
name|o
parameter_list|)
value|((o)&0x3f)
end_define

begin_define
define|#
directive|define
name|IPOPT_CONTROL
value|0x00
end_define

begin_define
define|#
directive|define
name|IPOPT_RESERVED1
value|0x10
end_define

begin_define
define|#
directive|define
name|IPOPT_DEBMEAS
value|0x20
end_define

begin_define
define|#
directive|define
name|IPOPT_RESERVED2
value|0x30
end_define

begin_define
define|#
directive|define
name|IPOPT_EOL
value|0
end_define

begin_comment
comment|/* end of option list */
end_comment

begin_define
define|#
directive|define
name|IPOPT_NOP
value|1
end_define

begin_comment
comment|/* no operation */
end_comment

begin_define
define|#
directive|define
name|IPOPT_RR
value|7
end_define

begin_comment
comment|/* record packet route */
end_comment

begin_define
define|#
directive|define
name|IPOPT_TS
value|68
end_define

begin_comment
comment|/* timestamp */
end_comment

begin_define
define|#
directive|define
name|IPOPT_SECURITY
value|130
end_define

begin_comment
comment|/* provide s,c,h,tcc */
end_comment

begin_define
define|#
directive|define
name|IPOPT_LSRR
value|131
end_define

begin_comment
comment|/* loose source route */
end_comment

begin_define
define|#
directive|define
name|IPOPT_SATID
value|136
end_define

begin_comment
comment|/* satnet id */
end_comment

begin_define
define|#
directive|define
name|IPOPT_SSRR
value|137
end_define

begin_comment
comment|/* strict source route */
end_comment

begin_comment
comment|/*  * Time stamp option structure.  */
end_comment

begin_struct
struct|struct
name|ip_timestamp
block|{
name|u_char
name|ipt_code
decl_stmt|;
comment|/* IPOPT_TS */
name|u_char
name|ipt_len
decl_stmt|;
comment|/* size of structure (variable) */
name|u_char
name|ipt_ptr
decl_stmt|;
comment|/* index of current entry */
name|u_char
name|ipt_flg
range|:
literal|4
decl_stmt|,
comment|/* flags, see below */
name|ipt_oflw
range|:
literal|4
decl_stmt|;
comment|/* overflow counter */
union|union
block|{
name|n_long
name|ipt_time
index|[
literal|1
index|]
decl_stmt|;
struct|struct
name|ipt_ta
block|{
name|struct
name|in_addr
name|ipt_addr
decl_stmt|;
name|n_long
name|ipt_time
decl_stmt|;
block|}
name|ipt_ta
index|[
literal|1
index|]
struct|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|/* flag bits for ipt_flg */
end_comment

begin_define
define|#
directive|define
name|IPOPT_TS_TSONLY
value|0
end_define

begin_comment
comment|/* timestamps only */
end_comment

begin_define
define|#
directive|define
name|IPOPT_TS_TSANDADDR
value|1
end_define

begin_comment
comment|/* timestamps and addresses */
end_comment

begin_define
define|#
directive|define
name|IPOPT_TS_PRESPEC
value|2
end_define

begin_comment
comment|/* specified modules only */
end_comment

begin_comment
comment|/* bits for security (not byte swapped) */
end_comment

begin_define
define|#
directive|define
name|IPOPT_SECUR_UNCLASS
value|0x0000
end_define

begin_define
define|#
directive|define
name|IPOPT_SECUR_CONFID
value|0xf135
end_define

begin_define
define|#
directive|define
name|IPOPT_SECUR_EFTO
value|0x789a
end_define

begin_define
define|#
directive|define
name|IPOPT_SECUR_MMMM
value|0xbc4d
end_define

begin_define
define|#
directive|define
name|IPOPT_SECUR_RESTR
value|0xaf13
end_define

begin_define
define|#
directive|define
name|IPOPT_SECUR_SECRET
value|0xd788
end_define

begin_define
define|#
directive|define
name|IPOPT_SECUR_TOPSECRET
value|0x6bc5
end_define

begin_comment
comment|/*  * Internet implementation parameters.  */
end_comment

begin_define
define|#
directive|define
name|MAXTTL
value|255
end_define

begin_comment
comment|/* maximum time to live (seconds) */
end_comment

begin_define
define|#
directive|define
name|IPFRAGTTL
value|15
end_define

begin_comment
comment|/* time to live for frag chains */
end_comment

begin_define
define|#
directive|define
name|IPTTLDEC
value|5
end_define

begin_comment
comment|/* subtracted when forwarding */
end_comment

end_unit

