begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ip.h 1.5 81/10/29 */
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
comment|/*  * Structure of an internet header, naked of options.  *  * SHOULD MAKE A VERSION OF THIS FOR KERNEL SO USER  * VERSION CAN BE union FREE AND INITIALIZABLE.  */
end_comment

begin_struct
struct|struct
name|ip
block|{
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
name|u_char
name|ip_tos
decl_stmt|;
comment|/* type of service */
comment|/* we copy the IP_MF to ip_tos on input */
define|#
directive|define
name|ip_mff
value|ip_tos
comment|/* more fragments flag */
comment|/* by rights, ip_len should be a u_short, but this makes operations */
comment|/* on it very dangerous as comparisons become unsigned and comparing */
comment|/* against negative numbers then fails... we don't expect any> 32767 */
comment|/* byte packets, so pragmatically delcare it to be a short */
name|short
name|ip_len
decl_stmt|;
comment|/* total length */
name|u_short
name|ip_id
decl_stmt|;
comment|/* identification */
comment|/* ip_off should also, by rights, be u_short, ala ip_len */
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
union|union
block|{
name|struct
name|socket
name|ip_s
decl_stmt|;
comment|/* source address */
name|struct
name|ip
modifier|*
name|ip_nxt
decl_stmt|;
comment|/* next fragment */
block|}
name|I_sun
union|;
define|#
directive|define
name|ip_src
value|I_sun.ip_s
define|#
directive|define
name|ip_next
value|I_sun.ip_nxt
union|union
block|{
name|struct
name|socket
name|ip_d
decl_stmt|;
comment|/* destination address */
name|struct
name|ip
modifier|*
name|ip_prv
decl_stmt|;
comment|/* prev fragment */
block|}
name|I_dun
union|;
define|#
directive|define
name|ip_dst
value|I_dun.ip_d
define|#
directive|define
name|ip_prev
value|I_dun.ip_prv
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
name|socket
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
comment|/*  * Ip reassembly queue structure.  Each fragment  * being reassambled is attached to one of these structures.  * They are timed out after ipq_ttl drops to 0, and may also  * be reclaimed if memory becomes tight.  */
end_comment

begin_struct
struct|struct
name|ipq
block|{
name|struct
name|ipq
modifier|*
name|next
decl_stmt|,
modifier|*
name|prev
decl_stmt|;
comment|/* to other reass headers */
name|u_char
name|ipq_ttl
decl_stmt|;
comment|/* time for reass q to live */
name|u_char
name|ipq_p
decl_stmt|;
comment|/* protocol of this fragment */
name|u_short
name|ipq_id
decl_stmt|;
comment|/* sequence id for reassembly */
name|struct
name|ip
modifier|*
name|ipq_next
decl_stmt|,
modifier|*
name|ipq_prev
decl_stmt|;
comment|/* to ip headers of fragments */
name|struct
name|socket
name|ipq_src
decl_stmt|,
name|ipq_dst
decl_stmt|;
block|}
struct|;
end_struct

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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|ipq
name|ipq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ip reass. queue */
end_comment

begin_function_decl
name|struct
name|ipq
modifier|*
name|ip_freef
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|u_short
name|ip_id
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ip packet ctr, for ids */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

