begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*                                                                        */
end_comment

begin_comment
comment|/*    there seems to exist no standard for the contents of HMP traps      */
end_comment

begin_comment
comment|/*  RFC 869 simply says that it should "usually contain an identifier,..  */
end_comment

begin_comment
comment|/*  the local time..., and data pertinent to the event."                  */
end_comment

begin_comment
comment|/*                                                                        */
end_comment

begin_comment
comment|/* Being unwilling to create a defacto (non)standard, since I am not a    */
end_comment

begin_comment
comment|/* montoring wizard, I mostly punted.  There is a trap routine which will */
end_comment

begin_comment
comment|/* send message with the structure below at the start of the data section,*/
end_comment

begin_comment
comment|/* followed by whatever data you passed to it up to the size of one mbuf  */
end_comment

begin_comment
comment|/*                                                                        */
end_comment

begin_comment
comment|/* I've also included some trap codes -- which I believe are descended    */
end_comment

begin_comment
comment|/* from 4.1??   You will find them used in the code but commented out..   */
end_comment

begin_comment
comment|/*                                                                        */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_if
if|#
directive|if
name|HMP
operator|&&
name|HMPTRAPS
end_if

begin_struct
struct|struct
name|hmp_trap
block|{
name|u_long
name|ht_type
decl_stmt|;
name|u_long
name|ht_time
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * need more host information traps -- like if the machine is going down  */
end_comment

begin_define
define|#
directive|define
name|T_MEM_DROP
value|0x0
end_define

begin_comment
comment|/* packet drop due to memory */
end_comment

begin_define
define|#
directive|define
name|T_IP_CKSUM
value|0x10
end_define

begin_comment
comment|/* IP checksum */
end_comment

begin_define
define|#
directive|define
name|T_IP_ADDRS
value|0x11
end_define

begin_comment
comment|/* address error */
end_comment

begin_define
define|#
directive|define
name|T_IP_FDROP
value|0x12
end_define

begin_comment
comment|/* fragment dropped (timeout) */
end_comment

begin_define
define|#
directive|define
name|T_IP_TRUNC
value|0x13
end_define

begin_comment
comment|/* truncated packet */
end_comment

begin_define
define|#
directive|define
name|T_IP_OVFLO
value|0x14
end_define

begin_comment
comment|/* header overflow */
end_comment

begin_define
define|#
directive|define
name|T_IP_HLEN
value|0x15
end_define

begin_comment
comment|/* header length */
end_comment

begin_define
define|#
directive|define
name|T_MEM_FGLEAN
value|0x16
end_define

begin_comment
comment|/* IP frag reclaimed for memory */
end_comment

begin_define
define|#
directive|define
name|T_TCP_CKSUM
value|0x20
end_define

begin_comment
comment|/* TCP checksum */
end_comment

begin_define
define|#
directive|define
name|T_TCP_OVFLO
value|0x21
end_define

begin_comment
comment|/* header overflow */
end_comment

begin_define
define|#
directive|define
name|T_TCP_HLEN
value|0x22
end_define

begin_comment
comment|/* header length */
end_comment

begin_define
define|#
directive|define
name|T_TCP_REXMTTL
value|0x23
end_define

begin_comment
comment|/* retransmit too long */
end_comment

begin_define
define|#
directive|define
name|T_TCP_DUP
value|0x24
end_define

begin_comment
comment|/* duplicate drop */
end_comment

begin_define
define|#
directive|define
name|T_TCP_ORDER
value|0x25
end_define

begin_comment
comment|/* out of order receipt */
end_comment

begin_define
define|#
directive|define
name|T_TCP_WINDOW
value|0x26
end_define

begin_comment
comment|/* out of window receipt */
end_comment

begin_define
define|#
directive|define
name|T_TCP_RDROP
value|0x27
end_define

begin_comment
comment|/* "" end of new segment */
end_comment

begin_define
define|#
directive|define
name|T_TCP_UDROP
value|0x28
end_define

begin_comment
comment|/* data dropped from end of q */
end_comment

begin_define
define|#
directive|define
name|T_MEM_TGLEAN
value|0x29
end_define

begin_comment
comment|/* TCP unacked segment "" */
end_comment

begin_define
define|#
directive|define
name|T_UDP_CKSUM
value|0x30
end_define

begin_comment
comment|/* UDP checksum */
end_comment

begin_define
define|#
directive|define
name|T_ICMP_CKSUM
value|0x40
end_define

begin_comment
comment|/* ICMP checksum */
end_comment

begin_define
define|#
directive|define
name|T_ICMP_SRCQ
value|0x41
end_define

begin_comment
comment|/* source quench rcvd */
end_comment

begin_define
define|#
directive|define
name|T_ICMP_REDIR
value|0x42
end_define

begin_comment
comment|/* redirect rcvd */
end_comment

begin_define
define|#
directive|define
name|T_ICMP_TIMEX
value|0x43
end_define

begin_comment
comment|/* time exceeded */
end_comment

begin_define
define|#
directive|define
name|T_ICMP_PARM
value|0x44
end_define

begin_comment
comment|/* parameter problem */
end_comment

begin_define
define|#
directive|define
name|T_HMP_CKSUM
value|0x50
end_define

begin_comment
comment|/* HMP checksum */
end_comment

begin_define
define|#
directive|define
name|T_HMP_STYPE
value|0x51
end_define

begin_comment
comment|/* wrong system type */
end_comment

begin_define
define|#
directive|define
name|T_HMP_MTYPE
value|0x52
end_define

begin_comment
comment|/* bad message type */
end_comment

begin_define
define|#
directive|define
name|T_HMP_PASSWD
value|0x53
end_define

begin_comment
comment|/* bad password */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

