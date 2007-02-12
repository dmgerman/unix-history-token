begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2007, Cisco Systems, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * a) Redistributions of source code must retain the above copyright notice,  *   this list of conditions and the following disclaimer.  *  * b) Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *   the documentation and/or other materials provided with the distribution.  *  * c) Neither the name of Cisco Systems, Inc. nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $KAME: sctp_constants.h,v 1.17 2005/03/06 16:04:17 itojun Exp $	 */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|__sctp_constants_h__
end_ifndef

begin_define
define|#
directive|define
name|__sctp_constants_h__
end_define

begin_define
define|#
directive|define
name|SCTP_VERSION_STRING
value|"KAME-BSD 1.1"
end_define

begin_comment
comment|/* #define SCTP_AUDITING_ENABLED 1 used for debug/auditing */
end_comment

begin_define
define|#
directive|define
name|SCTP_AUDIT_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|SCTP_STAT_LOG_SIZE
value|80000
end_define

begin_comment
comment|/* Places that CWND log can happen from */
end_comment

begin_define
define|#
directive|define
name|SCTP_CWND_LOG_FROM_FR
value|1
end_define

begin_define
define|#
directive|define
name|SCTP_CWND_LOG_FROM_RTX
value|2
end_define

begin_define
define|#
directive|define
name|SCTP_CWND_LOG_FROM_BRST
value|3
end_define

begin_define
define|#
directive|define
name|SCTP_CWND_LOG_FROM_SS
value|4
end_define

begin_define
define|#
directive|define
name|SCTP_CWND_LOG_FROM_CA
value|5
end_define

begin_define
define|#
directive|define
name|SCTP_CWND_LOG_FROM_SAT
value|6
end_define

begin_define
define|#
directive|define
name|SCTP_BLOCK_LOG_INTO_BLK
value|7
end_define

begin_define
define|#
directive|define
name|SCTP_BLOCK_LOG_OUTOF_BLK
value|8
end_define

begin_define
define|#
directive|define
name|SCTP_BLOCK_LOG_CHECK
value|9
end_define

begin_define
define|#
directive|define
name|SCTP_STR_LOG_FROM_INTO_STRD
value|10
end_define

begin_define
define|#
directive|define
name|SCTP_STR_LOG_FROM_IMMED_DEL
value|11
end_define

begin_define
define|#
directive|define
name|SCTP_STR_LOG_FROM_INSERT_HD
value|12
end_define

begin_define
define|#
directive|define
name|SCTP_STR_LOG_FROM_INSERT_MD
value|13
end_define

begin_define
define|#
directive|define
name|SCTP_STR_LOG_FROM_INSERT_TL
value|14
end_define

begin_define
define|#
directive|define
name|SCTP_STR_LOG_FROM_MARK_TSN
value|15
end_define

begin_define
define|#
directive|define
name|SCTP_STR_LOG_FROM_EXPRS_DEL
value|16
end_define

begin_define
define|#
directive|define
name|SCTP_FR_LOG_BIGGEST_TSNS
value|17
end_define

begin_define
define|#
directive|define
name|SCTP_FR_LOG_STRIKE_TEST
value|18
end_define

begin_define
define|#
directive|define
name|SCTP_FR_LOG_STRIKE_CHUNK
value|19
end_define

begin_define
define|#
directive|define
name|SCTP_FR_T3_TIMEOUT
value|20
end_define

begin_define
define|#
directive|define
name|SCTP_MAP_PREPARE_SLIDE
value|21
end_define

begin_define
define|#
directive|define
name|SCTP_MAP_SLIDE_FROM
value|22
end_define

begin_define
define|#
directive|define
name|SCTP_MAP_SLIDE_RESULT
value|23
end_define

begin_define
define|#
directive|define
name|SCTP_MAP_SLIDE_CLEARED
value|24
end_define

begin_define
define|#
directive|define
name|SCTP_MAP_SLIDE_NONE
value|25
end_define

begin_define
define|#
directive|define
name|SCTP_FR_T3_MARK_TIME
value|26
end_define

begin_define
define|#
directive|define
name|SCTP_FR_T3_MARKED
value|27
end_define

begin_define
define|#
directive|define
name|SCTP_FR_T3_STOPPED
value|28
end_define

begin_define
define|#
directive|define
name|SCTP_FR_MARKED
value|30
end_define

begin_define
define|#
directive|define
name|SCTP_CWND_LOG_NOADV_SS
value|31
end_define

begin_define
define|#
directive|define
name|SCTP_CWND_LOG_NOADV_CA
value|32
end_define

begin_define
define|#
directive|define
name|SCTP_MAX_BURST_APPLIED
value|33
end_define

begin_define
define|#
directive|define
name|SCTP_MAX_IFP_APPLIED
value|34
end_define

begin_define
define|#
directive|define
name|SCTP_MAX_BURST_ERROR_STOP
value|35
end_define

begin_define
define|#
directive|define
name|SCTP_INCREASE_PEER_RWND
value|36
end_define

begin_define
define|#
directive|define
name|SCTP_DECREASE_PEER_RWND
value|37
end_define

begin_define
define|#
directive|define
name|SCTP_SET_PEER_RWND_VIA_SACK
value|38
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_MBCNT_INCREASE
value|39
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_MBCNT_DECREASE
value|40
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_MBCNT_CHKSET
value|41
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_NEW_SACK
value|42
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_TSN_ACKED
value|43
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_TSN_REVOKED
value|44
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_LOCK_TCB
value|45
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_LOCK_INP
value|46
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_LOCK_SOCK
value|47
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_LOCK_SOCKBUF_R
value|48
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_LOCK_SOCKBUF_S
value|49
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_LOCK_CREATE
value|50
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_INITIAL_RTT
value|51
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_RTTVAR
value|52
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_SBALLOC
value|53
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_SBFREE
value|54
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_SBRESULT
value|55
end_define

begin_define
define|#
directive|define
name|SCTP_FR_DUPED
value|56
end_define

begin_define
define|#
directive|define
name|SCTP_FR_MARKED_EARLY
value|57
end_define

begin_define
define|#
directive|define
name|SCTP_FR_CWND_REPORT
value|58
end_define

begin_define
define|#
directive|define
name|SCTP_FR_CWND_REPORT_START
value|59
end_define

begin_define
define|#
directive|define
name|SCTP_FR_CWND_REPORT_STOP
value|60
end_define

begin_define
define|#
directive|define
name|SCTP_CWND_LOG_FROM_SEND
value|61
end_define

begin_define
define|#
directive|define
name|SCTP_CWND_INITIALIZATION
value|62
end_define

begin_define
define|#
directive|define
name|SCTP_CWND_LOG_FROM_T3
value|63
end_define

begin_define
define|#
directive|define
name|SCTP_CWND_LOG_FROM_SACK
value|64
end_define

begin_define
define|#
directive|define
name|SCTP_CWND_LOG_NO_CUMACK
value|65
end_define

begin_define
define|#
directive|define
name|SCTP_CWND_LOG_FROM_RESEND
value|66
end_define

begin_define
define|#
directive|define
name|SCTP_FR_LOG_CHECK_STRIKE
value|67
end_define

begin_define
define|#
directive|define
name|SCTP_SEND_NOW_COMPLETES
value|68
end_define

begin_define
define|#
directive|define
name|SCTP_CWND_LOG_FILL_OUTQ_CALLED
value|69
end_define

begin_define
define|#
directive|define
name|SCTP_CWND_LOG_FILL_OUTQ_FILLS
value|70
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_FREE_SENT
value|71
end_define

begin_define
define|#
directive|define
name|SCTP_NAGLE_APPLIED
value|72
end_define

begin_define
define|#
directive|define
name|SCTP_NAGLE_SKIPPED
value|73
end_define

begin_define
define|#
directive|define
name|SCTP_WAKESND_FROM_SACK
value|74
end_define

begin_define
define|#
directive|define
name|SCTP_WAKESND_FROM_FWDTSN
value|75
end_define

begin_define
define|#
directive|define
name|SCTP_NOWAKE_FROM_SACK
value|76
end_define

begin_define
define|#
directive|define
name|SCTP_CWNDLOG_PRESEND
value|77
end_define

begin_define
define|#
directive|define
name|SCTP_CWNDLOG_ENDSEND
value|78
end_define

begin_define
define|#
directive|define
name|SCTP_AT_END_OF_SACK
value|79
end_define

begin_define
define|#
directive|define
name|SCTP_REASON_FOR_SC
value|80
end_define

begin_define
define|#
directive|define
name|SCTP_BLOCK_LOG_INTO_BLKA
value|81
end_define

begin_define
define|#
directive|define
name|SCTP_ENTER_USER_RECV
value|82
end_define

begin_define
define|#
directive|define
name|SCTP_USER_RECV_SACKS
value|83
end_define

begin_define
define|#
directive|define
name|SCTP_SORECV_BLOCKSA
value|84
end_define

begin_define
define|#
directive|define
name|SCTP_SORECV_BLOCKSB
value|85
end_define

begin_define
define|#
directive|define
name|SCTP_SORECV_DONE
value|86
end_define

begin_define
define|#
directive|define
name|SCTP_SACK_RWND_UPDATE
value|87
end_define

begin_define
define|#
directive|define
name|SCTP_SORECV_ENTER
value|88
end_define

begin_define
define|#
directive|define
name|SCTP_SORECV_ENTERPL
value|89
end_define

begin_define
define|#
directive|define
name|SCTP_MBUF_INPUT
value|90
end_define

begin_define
define|#
directive|define
name|SCTP_MBUF_IALLOC
value|91
end_define

begin_define
define|#
directive|define
name|SCTP_MBUF_IFREE
value|92
end_define

begin_define
define|#
directive|define
name|SCTP_MBUF_ICOPY
value|93
end_define

begin_define
define|#
directive|define
name|SCTP_SORCV_FREECTL
value|94
end_define

begin_define
define|#
directive|define
name|SCTP_SORCV_DOESCPY
value|95
end_define

begin_define
define|#
directive|define
name|SCTP_SORCV_DOESLCK
value|96
end_define

begin_define
define|#
directive|define
name|SCTP_SORCV_DOESADJ
value|97
end_define

begin_define
define|#
directive|define
name|SCTP_SORCV_BOTWHILE
value|98
end_define

begin_define
define|#
directive|define
name|SCTP_SORCV_PASSBF
value|99
end_define

begin_define
define|#
directive|define
name|SCTP_SORCV_ADJD
value|100
end_define

begin_define
define|#
directive|define
name|SCTP_UNKNOWN_MAX
value|101
end_define

begin_define
define|#
directive|define
name|SCTP_RANDY_STUFF
value|102
end_define

begin_define
define|#
directive|define
name|SCTP_RANDY_STUFF1
value|103
end_define

begin_define
define|#
directive|define
name|SCTP_STRMOUT_LOG_ASSIGN
value|104
end_define

begin_define
define|#
directive|define
name|SCTP_STRMOUT_LOG_SEND
value|105
end_define

begin_define
define|#
directive|define
name|SCTP_FLIGHT_LOG_DOWN
value|106
end_define

begin_define
define|#
directive|define
name|SCTP_FLIGHT_LOG_UP
value|107
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_MAX_TYPES
value|108
end_define

begin_comment
comment|/*  * To turn on various logging, you must first define SCTP_STAT_LOGGING. Then  * to get something to log you define one of the logging defines i.e.  *  * SCTP_CWND_LOGGING SCTP_BLK_LOGGING SCTP_STR_LOGGING SCTP_FR_LOGGING  *  * Any one or a combination of the logging can be turned on.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_LOG_EVENT_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_EVENT_CWND
value|1
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_EVENT_BLOCK
value|2
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_EVENT_STRM
value|3
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_EVENT_FR
value|4
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_EVENT_MAP
value|5
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_EVENT_MAXBURST
value|6
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_EVENT_RWND
value|7
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_EVENT_MBCNT
value|8
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_EVENT_SACK
value|9
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_LOCK_EVENT
value|10
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_EVENT_RTT
value|11
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_EVENT_SB
value|12
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_EVENT_NAGLE
value|13
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_EVENT_WAKE
value|14
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_MISC_EVENT
value|15
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_EVENT_CLOSE
value|16
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_EVENT_MBUF
value|17
end_define

begin_define
define|#
directive|define
name|SCTP_LOG_MAX_EVENT
value|18
end_define

begin_define
define|#
directive|define
name|SCTP_LOCK_UNKNOWN
value|2
end_define

begin_comment
comment|/* number of associations by default for zone allocation */
end_comment

begin_define
define|#
directive|define
name|SCTP_MAX_NUM_OF_ASOC
value|40000
end_define

begin_comment
comment|/* how many addresses per assoc remote and local */
end_comment

begin_define
define|#
directive|define
name|SCTP_SCALE_FOR_ADDR
value|2
end_define

begin_comment
comment|/* default AUTO_ASCONF mode enable(1)/disable(0) value (sysctl) */
end_comment

begin_define
define|#
directive|define
name|SCTP_DEFAULT_AUTO_ASCONF
value|0
end_define

begin_comment
comment|/*  * Theshold for rwnd updates, we have to read (sb_hiwat>>  * SCTP_RWND_HIWAT_SHIFT) before we will look to see if we need to send a  * window update sack. When we look, we compare the last rwnd we sent vs the  * current rwnd. It too must be greater than this value. Using 3 divdes the  * hiwat by 8, so for 200k rwnd we need to read 24k. For a 64k rwnd we need  * to read 8k. This seems about right.. I hope :-D.. we do set a  * min of a MTU on it so if the rwnd is real small we will insist  * on a full MTU of 1500 bytes.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_RWND_HIWAT_SHIFT
value|3
end_define

begin_comment
comment|/* How much of the rwnd must the  * message be taking up to start partial delivery.  * We calculate this by shifing the hi_water (recv_win)  * left the following .. set to 1, when a message holds  * 1/2 the rwnd. If we set it to 2 when a message holds  * 1/4 the rwnd...etc..  */
end_comment

begin_define
define|#
directive|define
name|SCTP_PARTIAL_DELIVERY_SHIFT
value|1
end_define

begin_comment
comment|/* Minimum number of bytes read by user before we  * condsider doing a rwnd update  */
end_comment

begin_define
define|#
directive|define
name|SCTP_MIN_READ_BEFORE_CONSIDERING
value|3000
end_define

begin_comment
comment|/*  * default HMAC for cookies, etc... use one of the AUTH HMAC id's  * SCTP_HMAC is the HMAC_ID to use  * SCTP_SIGNATURE_SIZE is the digest length  */
end_comment

begin_define
define|#
directive|define
name|SCTP_HMAC
value|SCTP_AUTH_HMAC_ID_SHA1
end_define

begin_define
define|#
directive|define
name|SCTP_SIGNATURE_SIZE
value|SCTP_AUTH_DIGEST_LEN_SHA1
end_define

begin_define
define|#
directive|define
name|SCTP_SIGNATURE_ALOC_SIZE
value|SCTP_SIGNATURE_SIZE
end_define

begin_comment
comment|/* DEFINE HERE WHAT CRC YOU WANT TO USE */
end_comment

begin_define
define|#
directive|define
name|SCTP_USECRC_RFC2960
value|1
end_define

begin_comment
comment|/* #define SCTP_USECRC_FLETCHER 1 */
end_comment

begin_comment
comment|/* #define SCTP_USECRC_SSHCRC32 1 */
end_comment

begin_comment
comment|/* #define SCTP_USECRC_FASTCRC32 1 */
end_comment

begin_comment
comment|/* #define SCTP_USECRC_CRC32 1 */
end_comment

begin_comment
comment|/* #define SCTP_USECRC_TCP32 1 */
end_comment

begin_comment
comment|/* #define SCTP_USECRC_CRC16SMAL 1 */
end_comment

begin_comment
comment|/* #define SCTP_USECRC_CRC16 1 */
end_comment

begin_comment
comment|/* #define SCTP_USECRC_MODADLER 1 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SCTP_ADLER32_BASE
end_ifndef

begin_define
define|#
directive|define
name|SCTP_ADLER32_BASE
value|65521
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * the SCTP protocol signature this includes the version number encoded in  * the last 4 bits of the signature.  */
end_comment

begin_define
define|#
directive|define
name|PROTO_SIGNATURE_A
value|0x30000000
end_define

begin_define
define|#
directive|define
name|SCTP_VERSION_NUMBER
value|0x3
end_define

begin_define
define|#
directive|define
name|MAX_TSN
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|MAX_SEQ
value|0xffff
end_define

begin_comment
comment|/* how many executions every N tick's */
end_comment

begin_define
define|#
directive|define
name|SCTP_ITERATOR_MAX_AT_ONCE
value|20
end_define

begin_comment
comment|/* number of clock ticks between iterator executions */
end_comment

begin_define
define|#
directive|define
name|SCTP_ITERATOR_TICKS
value|1
end_define

begin_comment
comment|/*  * option: If you comment out the following you will receive the old behavior  * of obeying cwnd for the fast retransmit algorithm. With this defined a FR  * happens right away with-out waiting for the flightsize to drop below the  * cwnd value (which is reduced by the FR to 1/2 the inflight packets).  */
end_comment

begin_define
define|#
directive|define
name|SCTP_IGNORE_CWND_ON_FR
value|1
end_define

begin_comment
comment|/*  * Adds implementors guide behavior to only use newest highest update in SACK  * gap ack's to figure out if you need to stroke a chunk for FR.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_NO_FR_UNLESS_SEGMENT_SMALLER
value|1
end_define

begin_comment
comment|/* default max I can burst out after a fast retransmit */
end_comment

begin_define
define|#
directive|define
name|SCTP_DEF_MAX_BURST
value|4
end_define

begin_comment
comment|/* IP hdr (20/40) + 12+2+2 (enet) + sctp common 12 */
end_comment

begin_define
define|#
directive|define
name|SCTP_FIRST_MBUF_RESV
value|68
end_define

begin_comment
comment|/* Packet transmit states in the sent field */
end_comment

begin_define
define|#
directive|define
name|SCTP_DATAGRAM_UNSENT
value|0
end_define

begin_define
define|#
directive|define
name|SCTP_DATAGRAM_SENT
value|1
end_define

begin_define
define|#
directive|define
name|SCTP_DATAGRAM_RESEND1
value|2
end_define

begin_comment
comment|/* not used (in code, but may 						 * hit this value) */
end_comment

begin_define
define|#
directive|define
name|SCTP_DATAGRAM_RESEND2
value|3
end_define

begin_comment
comment|/* not used (in code, but may 						 * hit this value) */
end_comment

begin_define
define|#
directive|define
name|SCTP_DATAGRAM_RESEND
value|4
end_define

begin_define
define|#
directive|define
name|SCTP_DATAGRAM_ACKED
value|10010
end_define

begin_define
define|#
directive|define
name|SCTP_DATAGRAM_INBOUND
value|10011
end_define

begin_define
define|#
directive|define
name|SCTP_READY_TO_TRANSMIT
value|10012
end_define

begin_define
define|#
directive|define
name|SCTP_DATAGRAM_MARKED
value|20010
end_define

begin_define
define|#
directive|define
name|SCTP_FORWARD_TSN_SKIP
value|30010
end_define

begin_comment
comment|/* chunk output send from locations */
end_comment

begin_define
define|#
directive|define
name|SCTP_OUTPUT_FROM_USR_SEND
value|0
end_define

begin_define
define|#
directive|define
name|SCTP_OUTPUT_FROM_T3
value|1
end_define

begin_define
define|#
directive|define
name|SCTP_OUTPUT_FROM_INPUT_ERROR
value|2
end_define

begin_define
define|#
directive|define
name|SCTP_OUTPUT_FROM_CONTROL_PROC
value|3
end_define

begin_define
define|#
directive|define
name|SCTP_OUTPUT_FROM_SACK_TMR
value|4
end_define

begin_define
define|#
directive|define
name|SCTP_OUTPUT_FROM_SHUT_TMR
value|5
end_define

begin_define
define|#
directive|define
name|SCTP_OUTPUT_FROM_HB_TMR
value|6
end_define

begin_define
define|#
directive|define
name|SCTP_OUTPUT_FROM_SHUT_ACK_TMR
value|7
end_define

begin_define
define|#
directive|define
name|SCTP_OUTPUT_FROM_ASCONF_TMR
value|8
end_define

begin_define
define|#
directive|define
name|SCTP_OUTPUT_FROM_STRRST_TMR
value|9
end_define

begin_define
define|#
directive|define
name|SCTP_OUTPUT_FROM_AUTOCLOSE_TMR
value|10
end_define

begin_define
define|#
directive|define
name|SCTP_OUTPUT_FROM_EARLY_FR_TMR
value|11
end_define

begin_define
define|#
directive|define
name|SCTP_OUTPUT_FROM_STRRST_REQ
value|12
end_define

begin_define
define|#
directive|define
name|SCTP_OUTPUT_FROM_USR_RCVD
value|13
end_define

begin_define
define|#
directive|define
name|SCTP_OUTPUT_FROM_COOKIE_ACK
value|14
end_define

begin_comment
comment|/* SCTP chunk types are moved sctp.h for application (NAT, FW) use */
end_comment

begin_comment
comment|/* align to 32-bit sizes */
end_comment

begin_define
define|#
directive|define
name|SCTP_SIZE32
parameter_list|(
name|x
parameter_list|)
value|((((x)+3)>> 2)<< 2)
end_define

begin_define
define|#
directive|define
name|IS_SCTP_CONTROL
parameter_list|(
name|a
parameter_list|)
value|((a)->chunk_type != SCTP_DATA)
end_define

begin_define
define|#
directive|define
name|IS_SCTP_DATA
parameter_list|(
name|a
parameter_list|)
value|((a)->chunk_type == SCTP_DATA)
end_define

begin_comment
comment|/* SCTP parameter types */
end_comment

begin_comment
comment|/*************0x0000 series*************/
end_comment

begin_define
define|#
directive|define
name|SCTP_HEARTBEAT_INFO
value|0x0001
end_define

begin_define
define|#
directive|define
name|SCTP_IPV4_ADDRESS
value|0x0005
end_define

begin_define
define|#
directive|define
name|SCTP_IPV6_ADDRESS
value|0x0006
end_define

begin_define
define|#
directive|define
name|SCTP_STATE_COOKIE
value|0x0007
end_define

begin_define
define|#
directive|define
name|SCTP_UNRECOG_PARAM
value|0x0008
end_define

begin_define
define|#
directive|define
name|SCTP_COOKIE_PRESERVE
value|0x0009
end_define

begin_define
define|#
directive|define
name|SCTP_HOSTNAME_ADDRESS
value|0x000b
end_define

begin_define
define|#
directive|define
name|SCTP_SUPPORTED_ADDRTYPE
value|0x000c
end_define

begin_comment
comment|/* draft-ietf-stewart-strreset-xxx */
end_comment

begin_define
define|#
directive|define
name|SCTP_STR_RESET_OUT_REQUEST
value|0x000d
end_define

begin_define
define|#
directive|define
name|SCTP_STR_RESET_IN_REQUEST
value|0x000e
end_define

begin_define
define|#
directive|define
name|SCTP_STR_RESET_TSN_REQUEST
value|0x000f
end_define

begin_define
define|#
directive|define
name|SCTP_STR_RESET_RESPONSE
value|0x0010
end_define

begin_define
define|#
directive|define
name|SCTP_MAX_RESET_PARAMS
value|2
end_define

begin_define
define|#
directive|define
name|SCTP_STREAM_RESET_TSN_DELTA
value|0x1000
end_define

begin_comment
comment|/*************0x4000 series*************/
end_comment

begin_comment
comment|/*************0x8000 series*************/
end_comment

begin_define
define|#
directive|define
name|SCTP_ECN_CAPABLE
value|0x8000
end_define

begin_comment
comment|/* ECN Nonce: draft-ladha-sctp-ecn-nonce */
end_comment

begin_define
define|#
directive|define
name|SCTP_ECN_NONCE_SUPPORTED
value|0x8001
end_define

begin_comment
comment|/* draft-ietf-tsvwg-auth-xxx */
end_comment

begin_define
define|#
directive|define
name|SCTP_RANDOM
value|0x8002
end_define

begin_define
define|#
directive|define
name|SCTP_CHUNK_LIST
value|0x8003
end_define

begin_define
define|#
directive|define
name|SCTP_HMAC_LIST
value|0x8004
end_define

begin_comment
comment|/*  * draft-ietf-tsvwg-addip-sctp-xx param=0x8008  len=0xNNNN Byte | Byte | Byte  * | Byte Byte | Byte ...  *  * Where each byte is a chunk type extension supported. For example, to support  * all chunks one would have (in hex):  *  * 80 01 00 09 C0 C1 80 81 82 00 00 00  *  * Has the parameter. C0 = PR-SCTP    (RFC3758) C1, 80 = ASCONF (addip draft) 81  * = Packet Drop 82 = Stream Reset 83 = Authentication  */
end_comment

begin_define
define|#
directive|define
name|SCTP_SUPPORTED_CHUNK_EXT
value|0x8008
end_define

begin_comment
comment|/*************0xC000 series*************/
end_comment

begin_define
define|#
directive|define
name|SCTP_PRSCTP_SUPPORTED
value|0xc000
end_define

begin_comment
comment|/* draft-ietf-tsvwg-addip-sctp */
end_comment

begin_define
define|#
directive|define
name|SCTP_ADD_IP_ADDRESS
value|0xc001
end_define

begin_define
define|#
directive|define
name|SCTP_DEL_IP_ADDRESS
value|0xc002
end_define

begin_define
define|#
directive|define
name|SCTP_ERROR_CAUSE_IND
value|0xc003
end_define

begin_define
define|#
directive|define
name|SCTP_SET_PRIM_ADDR
value|0xc004
end_define

begin_define
define|#
directive|define
name|SCTP_SUCCESS_REPORT
value|0xc005
end_define

begin_define
define|#
directive|define
name|SCTP_ULP_ADAPTATION
value|0xc006
end_define

begin_comment
comment|/* Notification error codes */
end_comment

begin_define
define|#
directive|define
name|SCTP_NOTIFY_DATAGRAM_UNSENT
value|0x0001
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_DATAGRAM_SENT
value|0x0002
end_define

begin_define
define|#
directive|define
name|SCTP_FAILED_THRESHOLD
value|0x0004
end_define

begin_define
define|#
directive|define
name|SCTP_HEARTBEAT_SUCCESS
value|0x0008
end_define

begin_define
define|#
directive|define
name|SCTP_RESPONSE_TO_USER_REQ
value|0x000f
end_define

begin_define
define|#
directive|define
name|SCTP_INTERNAL_ERROR
value|0x0010
end_define

begin_define
define|#
directive|define
name|SCTP_SHUTDOWN_GUARD_EXPIRES
value|0x0020
end_define

begin_define
define|#
directive|define
name|SCTP_RECEIVED_SACK
value|0x0040
end_define

begin_define
define|#
directive|define
name|SCTP_PEER_FAULTY
value|0x0080
end_define

begin_comment
comment|/* bits for TOS field */
end_comment

begin_define
define|#
directive|define
name|SCTP_ECT0_BIT
value|0x02
end_define

begin_define
define|#
directive|define
name|SCTP_ECT1_BIT
value|0x01
end_define

begin_define
define|#
directive|define
name|SCTP_CE_BITS
value|0x03
end_define

begin_comment
comment|/* below turns off above */
end_comment

begin_define
define|#
directive|define
name|SCTP_FLEXIBLE_ADDRESS
value|0x20
end_define

begin_define
define|#
directive|define
name|SCTP_NO_HEARTBEAT
value|0x40
end_define

begin_comment
comment|/* mask to get sticky */
end_comment

begin_define
define|#
directive|define
name|SCTP_STICKY_OPTIONS_MASK
value|0x0c
end_define

begin_comment
comment|/* Chunk flags */
end_comment

begin_define
define|#
directive|define
name|SCTP_WINDOW_PROBE
value|0x01
end_define

begin_comment
comment|/*  * SCTP states for internal state machine XXX (should match "user" values)  */
end_comment

begin_define
define|#
directive|define
name|SCTP_STATE_EMPTY
value|0x0000
end_define

begin_define
define|#
directive|define
name|SCTP_STATE_INUSE
value|0x0001
end_define

begin_define
define|#
directive|define
name|SCTP_STATE_COOKIE_WAIT
value|0x0002
end_define

begin_define
define|#
directive|define
name|SCTP_STATE_COOKIE_ECHOED
value|0x0004
end_define

begin_define
define|#
directive|define
name|SCTP_STATE_OPEN
value|0x0008
end_define

begin_define
define|#
directive|define
name|SCTP_STATE_SHUTDOWN_SENT
value|0x0010
end_define

begin_define
define|#
directive|define
name|SCTP_STATE_SHUTDOWN_RECEIVED
value|0x0020
end_define

begin_define
define|#
directive|define
name|SCTP_STATE_SHUTDOWN_ACK_SENT
value|0x0040
end_define

begin_define
define|#
directive|define
name|SCTP_STATE_SHUTDOWN_PENDING
value|0x0080
end_define

begin_define
define|#
directive|define
name|SCTP_STATE_CLOSED_SOCKET
value|0x0100
end_define

begin_define
define|#
directive|define
name|SCTP_STATE_ABOUT_TO_BE_FREED
value|0x0200
end_define

begin_define
define|#
directive|define
name|SCTP_STATE_PARTIAL_MSG_LEFT
value|0x0400
end_define

begin_define
define|#
directive|define
name|SCTP_STATE_MASK
value|0x007f
end_define

begin_define
define|#
directive|define
name|SCTP_GET_STATE
parameter_list|(
name|asoc
parameter_list|)
value|((asoc)->state& SCTP_STATE_MASK)
end_define

begin_comment
comment|/* SCTP reachability state for each address */
end_comment

begin_define
define|#
directive|define
name|SCTP_ADDR_REACHABLE
value|0x001
end_define

begin_define
define|#
directive|define
name|SCTP_ADDR_NOT_REACHABLE
value|0x002
end_define

begin_define
define|#
directive|define
name|SCTP_ADDR_NOHB
value|0x004
end_define

begin_define
define|#
directive|define
name|SCTP_ADDR_BEING_DELETED
value|0x008
end_define

begin_define
define|#
directive|define
name|SCTP_ADDR_NOT_IN_ASSOC
value|0x010
end_define

begin_define
define|#
directive|define
name|SCTP_ADDR_WAS_PRIMARY
value|0x020
end_define

begin_define
define|#
directive|define
name|SCTP_ADDR_SWITCH_PRIMARY
value|0x040
end_define

begin_define
define|#
directive|define
name|SCTP_ADDR_OUT_OF_SCOPE
value|0x080
end_define

begin_define
define|#
directive|define
name|SCTP_ADDR_DOUBLE_SWITCH
value|0x100
end_define

begin_define
define|#
directive|define
name|SCTP_ADDR_UNCONFIRMED
value|0x200
end_define

begin_define
define|#
directive|define
name|SCTP_REACHABLE_MASK
value|0x203
end_define

begin_comment
comment|/* bound address types (e.g. valid address types to allow) */
end_comment

begin_define
define|#
directive|define
name|SCTP_BOUND_V6
value|0x01
end_define

begin_define
define|#
directive|define
name|SCTP_BOUND_V4
value|0x02
end_define

begin_comment
comment|/*  * what is the default number of mbufs in a chain I allow before switching to  * a cluster  */
end_comment

begin_define
define|#
directive|define
name|SCTP_DEFAULT_MBUFS_IN_CHAIN
value|5
end_define

begin_comment
comment|/* How long a cookie lives in seconds */
end_comment

begin_define
define|#
directive|define
name|SCTP_DEFAULT_COOKIE_LIFE
value|60
end_define

begin_comment
comment|/* resource limit of streams */
end_comment

begin_define
define|#
directive|define
name|MAX_SCTP_STREAMS
value|2048
end_define

begin_comment
comment|/* Maximum the mapping array will  grow to (TSN mapping array) */
end_comment

begin_define
define|#
directive|define
name|SCTP_MAPPING_ARRAY
value|512
end_define

begin_comment
comment|/* size of the inital malloc on the mapping array */
end_comment

begin_define
define|#
directive|define
name|SCTP_INITIAL_MAPPING_ARRAY
value|16
end_define

begin_comment
comment|/* how much we grow the mapping array each call */
end_comment

begin_define
define|#
directive|define
name|SCTP_MAPPING_ARRAY_INCR
value|32
end_define

begin_comment
comment|/*  * Here we define the timer types used by the implementation as arguments in  * the set/get timer type calls.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_TIMER_INIT
value|0
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_RECV
value|1
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_SEND
value|2
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_HEARTBEAT
value|3
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_PMTU
value|4
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_MAXSHUTDOWN
value|5
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_SIGNATURE
value|6
end_define

begin_comment
comment|/*  * number of timer types in the base SCTP structure used in the set/get and  * has the base default.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_NUM_TMRS
value|7
end_define

begin_comment
comment|/* timer types */
end_comment

begin_define
define|#
directive|define
name|SCTP_TIMER_TYPE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_TYPE_SEND
value|1
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_TYPE_INIT
value|2
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_TYPE_RECV
value|3
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_TYPE_SHUTDOWN
value|4
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_TYPE_HEARTBEAT
value|5
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_TYPE_COOKIE
value|6
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_TYPE_NEWCOOKIE
value|7
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_TYPE_PATHMTURAISE
value|8
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_TYPE_SHUTDOWNACK
value|9
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_TYPE_ASCONF
value|10
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_TYPE_SHUTDOWNGUARD
value|11
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_TYPE_AUTOCLOSE
value|12
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_TYPE_EVENTWAKE
value|13
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_TYPE_STRRESET
value|14
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_TYPE_INPKILL
value|15
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_TYPE_ITERATOR
value|16
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_TYPE_EARLYFR
value|17
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_TYPE_ASOCKILL
value|18
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_TYPE_ADDR_WQ
value|19
end_define

begin_comment
comment|/* add new timers here - and increment LAST */
end_comment

begin_define
define|#
directive|define
name|SCTP_TIMER_TYPE_LAST
value|20
end_define

begin_define
define|#
directive|define
name|SCTP_IS_TIMER_TYPE_VALID
parameter_list|(
name|t
parameter_list|)
value|(((t)> SCTP_TIMER_TYPE_NONE)&& \ 					 ((t)< SCTP_TIMER_TYPE_LAST))
end_define

begin_comment
comment|/*  * Number of ticks before the soxwakeup() event that is delayed is sent AFTER  * the accept() call  */
end_comment

begin_define
define|#
directive|define
name|SCTP_EVENTWAKEUP_WAIT_TICKS
value|3000
end_define

begin_comment
comment|/*  * Of course we really don't collect stale cookies, being folks of decerning  * taste. However we do count them, if we get too many before the association  * comes up.. we give up. Below is the constant that dictates when we give it  * up...this is a implemenation dependent treatment. In ours we do not ask  * for a extension of time, but just retry this many times...  */
end_comment

begin_define
define|#
directive|define
name|SCTP_MAX_STALE_COOKIES_I_COLLECT
value|10
end_define

begin_comment
comment|/* max number of TSN's dup'd that I will hold */
end_comment

begin_define
define|#
directive|define
name|SCTP_MAX_DUP_TSNS
value|20
end_define

begin_comment
comment|/*  * Here we define the types used when setting the retry amounts.  */
end_comment

begin_comment
comment|/* constants for type of set */
end_comment

begin_define
define|#
directive|define
name|SCTP_MAXATTEMPT_INIT
value|2
end_define

begin_define
define|#
directive|define
name|SCTP_MAXATTEMPT_SEND
value|3
end_define

begin_comment
comment|/* Maximum TSN's we will summarize in a drop report */
end_comment

begin_define
define|#
directive|define
name|SCTP_MAX_DROP_REPORT
value|16
end_define

begin_comment
comment|/* How many drop re-attempts we make on  INIT/COOKIE-ECHO */
end_comment

begin_define
define|#
directive|define
name|SCTP_RETRY_DROPPED_THRESH
value|4
end_define

begin_comment
comment|/*  * And the max we will keep a history of in the tcb which MUST be lower than  * 256.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_MAX_DROP_SAVE_REPORT
value|16
end_define

begin_comment
comment|/*  * Here we define the default timers and the default number of attemts we  * make for each respective side (send/init).  */
end_comment

begin_comment
comment|/*  * Maxmium number of chunks a single association can have on it. Note that  * this is a squishy number since the count can run over this if the user  * sends a large message down .. the fragmented chunks don't count until  * AFTER the message is on queue.. it would be the next send that blocks  * things. This number will get tuned up at boot in the sctp_init and use the  * number of clusters as a base. This way high bandwidth environments will  * not get impacted by the lower bandwidth sending a bunch of 1 byte chunks  */
end_comment

begin_define
define|#
directive|define
name|SCTP_ASOC_MAX_CHUNKS_ON_QUEUE
value|512
end_define

begin_define
define|#
directive|define
name|MSEC_TO_TICKS
parameter_list|(
name|x
parameter_list|)
value|((hz == 1000) ? x : (((x) * hz) / 1000))
end_define

begin_define
define|#
directive|define
name|TICKS_TO_MSEC
parameter_list|(
name|x
parameter_list|)
value|((hz == 1000) ? x : (((x) * 1000) / hz))
end_define

begin_define
define|#
directive|define
name|SEC_TO_TICKS
parameter_list|(
name|x
parameter_list|)
value|((x) * hz)
end_define

begin_define
define|#
directive|define
name|TICKS_TO_SEC
parameter_list|(
name|x
parameter_list|)
value|((x) / hz)
end_define

begin_comment
comment|/*  * Basically the minimum amount of time before I do a early FR. Making this  * value to low will cause duplicate retransmissions.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_MINFR_MSEC_TIMER
value|250
end_define

begin_comment
comment|/* The floor this value is allowed to fall to when starting a timer. */
end_comment

begin_define
define|#
directive|define
name|SCTP_MINFR_MSEC_FLOOR
value|20
end_define

begin_comment
comment|/* init timer def = 1 sec */
end_comment

begin_define
define|#
directive|define
name|SCTP_INIT_SEC
value|1
end_define

begin_comment
comment|/* send timer def = 1 seconds */
end_comment

begin_define
define|#
directive|define
name|SCTP_SEND_SEC
value|1
end_define

begin_comment
comment|/* recv timer def = 200ms  */
end_comment

begin_define
define|#
directive|define
name|SCTP_RECV_MSEC
value|200
end_define

begin_comment
comment|/* 30 seconds + RTO (in ms) */
end_comment

begin_define
define|#
directive|define
name|SCTP_HB_DEFAULT_MSEC
value|30000
end_define

begin_comment
comment|/* Max time I will wait for Shutdown to complete */
end_comment

begin_define
define|#
directive|define
name|SCTP_DEF_MAX_SHUTDOWN_SEC
value|180
end_define

begin_comment
comment|/*  * This is how long a secret lives, NOT how long a cookie lives how many  * ticks the current secret will live.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_DEFAULT_SECRET_LIFE_SEC
value|3600
end_define

begin_define
define|#
directive|define
name|SCTP_RTO_UPPER_BOUND
value|(60000)
end_define

begin_comment
comment|/* 60 sec in ms */
end_comment

begin_define
define|#
directive|define
name|SCTP_RTO_UPPER_BOUND_SEC
value|60
end_define

begin_comment
comment|/* for the init timer */
end_comment

begin_define
define|#
directive|define
name|SCTP_RTO_LOWER_BOUND
value|(1000)
end_define

begin_comment
comment|/* 1 sec in ms */
end_comment

begin_define
define|#
directive|define
name|SCTP_RTO_INITIAL
value|(3000)
end_define

begin_comment
comment|/* 3 sec in ms */
end_comment

begin_define
define|#
directive|define
name|SCTP_INP_KILL_TIMEOUT
value|20
end_define

begin_comment
comment|/* number of ms to retry kill of inpcb */
end_comment

begin_define
define|#
directive|define
name|SCTP_ASOC_KILL_TIMEOUT
value|10
end_define

begin_comment
comment|/* number of ms to retry kill of inpcb */
end_comment

begin_define
define|#
directive|define
name|SCTP_DEF_MAX_INIT
value|8
end_define

begin_define
define|#
directive|define
name|SCTP_DEF_MAX_SEND
value|10
end_define

begin_define
define|#
directive|define
name|SCTP_DEF_MAX_PATH_RTX
value|4
end_define

begin_define
define|#
directive|define
name|SCTP_DEF_PMTU_RAISE_SEC
value|600
end_define

begin_comment
comment|/* 10 min between raise attempts */
end_comment

begin_define
define|#
directive|define
name|SCTP_DEF_PMTU_MIN
value|600
end_define

begin_define
define|#
directive|define
name|SCTP_MSEC_IN_A_SEC
value|1000
end_define

begin_define
define|#
directive|define
name|SCTP_USEC_IN_A_SEC
value|1000000
end_define

begin_define
define|#
directive|define
name|SCTP_NSEC_IN_A_SEC
value|1000000000
end_define

begin_define
define|#
directive|define
name|SCTP_MAX_OUTSTANDING_DG
value|10000
end_define

begin_comment
comment|/* How many streams I request initally by default */
end_comment

begin_define
define|#
directive|define
name|SCTP_OSTREAM_INITIAL
value|10
end_define

begin_comment
comment|/*  * How many smallest_mtu's need to increase before a window update sack is  * sent (should be a power of 2).  */
end_comment

begin_define
define|#
directive|define
name|SCTP_SEG_TO_RWND_UPD
value|32
end_define

begin_comment
comment|/* Send window update (incr * this> hiwat). Should be a power of 2 */
end_comment

begin_define
define|#
directive|define
name|SCTP_SCALE_OF_RWND_TO_UPD
value|4
end_define

begin_define
define|#
directive|define
name|SCTP_MINIMAL_RWND
value|(4096)
end_define

begin_comment
comment|/* minimal rwnd */
end_comment

begin_define
define|#
directive|define
name|SCTP_ADDRMAX
value|20
end_define

begin_comment
comment|/* SCTP DEBUG Switch parameters */
end_comment

begin_define
define|#
directive|define
name|SCTP_DEBUG_TIMER1
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_TIMER2
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_TIMER3
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_TIMER4
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_OUTPUT1
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_OUTPUT2
value|0x00000020
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_OUTPUT3
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_OUTPUT4
value|0x00000080
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_UTIL1
value|0x00000100
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_UTIL2
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_AUTH1
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_AUTH2
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_INPUT1
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_INPUT2
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_INPUT3
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_INPUT4
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_ASCONF1
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_ASCONF2
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_OUTPUT5
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_XXX
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_PCB1
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_PCB2
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_PCB3
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_PCB4
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_INDATA1
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_INDATA2
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_INDATA3
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_INDATA4
value|0x08000000
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_USRREQ1
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_USRREQ2
value|0x20000000
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_PEEL1
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_XXXXX
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_ALL
value|0x7ff3ffff
end_define

begin_define
define|#
directive|define
name|SCTP_DEBUG_NOISY
value|0x00040000
end_define

begin_comment
comment|/* What sender needs to see to avoid SWS or we consider peers rwnd 0 */
end_comment

begin_define
define|#
directive|define
name|SCTP_SWS_SENDER_DEF
value|1420
end_define

begin_comment
comment|/*  * SWS is scaled to the sb_hiwat of the socket. A value of 2 is hiwat/4, 1  * would be hiwat/2 etc.  */
end_comment

begin_comment
comment|/* What receiver needs to see in sockbuf or we tell peer its 1 */
end_comment

begin_define
define|#
directive|define
name|SCTP_SWS_RECEIVER_DEF
value|3000
end_define

begin_define
define|#
directive|define
name|SCTP_INITIAL_CWND
value|4380
end_define

begin_comment
comment|/* amount peer is obligated to have in rwnd or I will abort */
end_comment

begin_define
define|#
directive|define
name|SCTP_MIN_RWND
value|1500
end_define

begin_define
define|#
directive|define
name|SCTP_WINDOW_MIN
value|1500
end_define

begin_comment
comment|/* smallest rwnd can be */
end_comment

begin_define
define|#
directive|define
name|SCTP_WINDOW_MAX
value|1048576
end_define

begin_comment
comment|/* biggest I can grow rwnd to My playing 				 * around suggests a value greater than 64k 				 * does not do much, I guess via the kernel 				 * limitations on the stream/socket. */
end_comment

begin_comment
comment|/* I can handle a 1meg re-assembly */
end_comment

begin_define
define|#
directive|define
name|SCTP_DEFAULT_MAXMSGREASM
value|1048576
end_define

begin_define
define|#
directive|define
name|SCTP_DEFAULT_MAXSEGMENT
value|65535
end_define

begin_define
define|#
directive|define
name|SCTP_CHUNK_BUFFER_SIZE
value|2048
end_define

begin_define
define|#
directive|define
name|SCTP_PARAM_BUFFER_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|SCTP_DEFAULT_MINSEGMENT
value|512
end_define

begin_comment
comment|/* MTU size ... if no mtu disc */
end_comment

begin_define
define|#
directive|define
name|SCTP_HOW_MANY_SECRETS
value|2
end_define

begin_comment
comment|/* how many secrets I keep */
end_comment

begin_define
define|#
directive|define
name|SCTP_NUMBER_OF_SECRETS
value|8
end_define

begin_comment
comment|/* or 8 * 4 = 32 octets */
end_comment

begin_define
define|#
directive|define
name|SCTP_SECRET_SIZE
value|32
end_define

begin_comment
comment|/* number of octets in a 256 bits */
end_comment

begin_comment
comment|/*  * SCTP upper layer notifications  */
end_comment

begin_define
define|#
directive|define
name|SCTP_NOTIFY_ASSOC_UP
value|1
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_ASSOC_DOWN
value|2
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_INTERFACE_DOWN
value|3
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_INTERFACE_UP
value|4
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_DG_FAIL
value|5
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_STRDATA_ERR
value|6
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_ASSOC_ABORTED
value|7
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_PEER_OPENED_STREAM
value|8
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_STREAM_OPENED_OK
value|9
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_ASSOC_RESTART
value|10
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_HB_RESP
value|11
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_ASCONF_SUCCESS
value|12
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_ASCONF_FAILED
value|13
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_PEER_SHUTDOWN
value|14
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_ASCONF_ADD_IP
value|15
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_ASCONF_DELETE_IP
value|16
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_ASCONF_SET_PRIMARY
value|17
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_PARTIAL_DELVIERY_INDICATION
value|18
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_ADAPTATION_INDICATION
value|19
end_define

begin_comment
comment|/* same as above */
end_comment

begin_define
define|#
directive|define
name|SCTP_NOTIFY_ADAPTION_INDICATION
value|19
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_INTERFACE_CONFIRMED
value|20
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_STR_RESET_RECV
value|21
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_STR_RESET_SEND
value|22
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_STR_RESET_FAILED_OUT
value|23
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_STR_RESET_FAILED_IN
value|24
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_AUTH_NEW_KEY
value|25
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_AUTH_KEY_CONFLICT
value|26
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_SPECIAL_SP_FAIL
value|27
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_MAX
value|27
end_define

begin_comment
comment|/* This is the value for messages that are NOT completely  * copied down where we will start to split the message.  * So, with our default, we split only if the piece we  * want to take will fill up a full MTU (assuming  * a 1500 byte MTU).  */
end_comment

begin_define
define|#
directive|define
name|SCTP_DEFAULT_SPLIT_POINT_MIN
value|1452
end_define

begin_comment
comment|/* ABORT CODES and other tell-tale location  * codes are generated by adding the below  * to the instance id.  */
end_comment

begin_comment
comment|/* File defines */
end_comment

begin_define
define|#
directive|define
name|SCTP_FROM_SCTP_INPUT
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SCTP_FROM_SCTP_PCB
value|0x20000000
end_define

begin_define
define|#
directive|define
name|SCTP_FROM_SCTP_INDATA
value|0x30000000
end_define

begin_define
define|#
directive|define
name|SCTP_FROM_SCTP_TIMER
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SCTP_FROM_SCTP_USRREQ
value|0x50000000
end_define

begin_define
define|#
directive|define
name|SCTP_FROM_SCTPUTIL
value|0x60000000
end_define

begin_define
define|#
directive|define
name|SCTP_FROM_SCTP6_USRREQ
value|0x70000000
end_define

begin_define
define|#
directive|define
name|SCTP_FROM_SCTP_ASCONF
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SCTP_FROM_SCTP_OUTPUT
value|0x90000000
end_define

begin_define
define|#
directive|define
name|SCTP_FROM_SCTP_PEELOFF
value|0xa0000000
end_define

begin_comment
comment|/* Location ID's */
end_comment

begin_define
define|#
directive|define
name|SCTP_LOC_1
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_2
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_3
value|0x00000003
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_4
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_5
value|0x00000005
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_6
value|0x00000006
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_7
value|0x00000007
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_8
value|0x00000008
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_9
value|0x00000009
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_10
value|0x0000000a
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_11
value|0x0000000b
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_12
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_13
value|0x0000000d
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_14
value|0x0000000e
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_15
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_16
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_17
value|0x00000011
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_18
value|0x00000012
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_19
value|0x00000013
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_20
value|0x00000014
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_21
value|0x00000015
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_22
value|0x00000016
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_23
value|0x00000017
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_24
value|0x00000018
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_25
value|0x00000019
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_26
value|0x0000001a
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_27
value|0x0000001b
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_28
value|0x0000001c
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_29
value|0x0000001d
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_30
value|0x0000001e
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_31
value|0x0000001f
end_define

begin_define
define|#
directive|define
name|SCTP_LOC_32
value|0x00000020
end_define

begin_comment
comment|/* Free assoc codes */
end_comment

begin_define
define|#
directive|define
name|SCTP_NORMAL_PROC
value|0
end_define

begin_define
define|#
directive|define
name|SCTP_PCBFREE_NOFORCE
value|1
end_define

begin_define
define|#
directive|define
name|SCTP_PCBFREE_FORCE
value|2
end_define

begin_comment
comment|/* From codes for adding addresses */
end_comment

begin_define
define|#
directive|define
name|SCTP_ADDR_IS_CONFIRMED
value|8
end_define

begin_define
define|#
directive|define
name|SCTP_ADDR_DYNAMIC_ADDED
value|6
end_define

begin_define
define|#
directive|define
name|SCTP_IN_COOKIE_PROC
value|100
end_define

begin_define
define|#
directive|define
name|SCTP_ALLOC_ASOC
value|1
end_define

begin_define
define|#
directive|define
name|SCTP_LOAD_ADDR_2
value|2
end_define

begin_define
define|#
directive|define
name|SCTP_LOAD_ADDR_3
value|3
end_define

begin_define
define|#
directive|define
name|SCTP_LOAD_ADDR_4
value|4
end_define

begin_define
define|#
directive|define
name|SCTP_LOAD_ADDR_5
value|5
end_define

begin_define
define|#
directive|define
name|SCTP_DONOT_SETSCOPE
value|0
end_define

begin_define
define|#
directive|define
name|SCTP_DO_SETSCOPE
value|1
end_define

begin_comment
comment|/* This value determines the default for when  * we try to add more on the send queue., if  * there is room. This prevents us from cycling  * into the copy_resume routine to often if  * we have not got enough space to add a decent  * enough size message. Note that if we have enough  * space to complete the message copy we will always  * add to the message, no matter what the size. Its  * only when we reach the point that we have some left  * to add, there is only room for part of it that we  * will use this threshold. Its also a sysctl.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_DEFAULT_ADD_MORE
value|1452
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SCTP_PCBHASHSIZE
end_ifndef

begin_comment
comment|/* default number of association hash buckets in each endpoint */
end_comment

begin_define
define|#
directive|define
name|SCTP_PCBHASHSIZE
value|256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SCTP_TCBHASHSIZE
end_ifndef

begin_define
define|#
directive|define
name|SCTP_TCBHASHSIZE
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SCTP_CHUNKQUEUE_SCALE
end_ifndef

begin_define
define|#
directive|define
name|SCTP_CHUNKQUEUE_SCALE
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* clock variance is 1 ms */
end_comment

begin_define
define|#
directive|define
name|SCTP_CLOCK_GRANULARITY
value|1
end_define

begin_define
define|#
directive|define
name|IP_HDR_SIZE
value|40
end_define

begin_comment
comment|/* we use the size of a IP6 header here this 				 * detracts a small amount for ipv4 but it 				 * simplifies the ipv6 addition */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IPPROTO_SCTP
end_ifndef

begin_define
define|#
directive|define
name|IPPROTO_SCTP
value|132
end_define

begin_comment
comment|/* the Official IANA number :-) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !IPPROTO_SCTP */
end_comment

begin_define
define|#
directive|define
name|SCTP_MAX_DATA_BUNDLING
value|256
end_define

begin_define
define|#
directive|define
name|SCTP_MAX_CONTROL_BUNDLING
value|20
end_define

begin_comment
comment|/* modular comparison */
end_comment

begin_comment
comment|/* True if a> b (mod = M) */
end_comment

begin_define
define|#
directive|define
name|compare_with_wrap
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|M
parameter_list|)
value|(((a> b)&& ((a - b)< ((M>> 1) + 1))) || \               ((b> a)&& ((b - a)> ((M>> 1) + 1))))
end_define

begin_comment
comment|/* Mapping array manipulation routines */
end_comment

begin_define
define|#
directive|define
name|SCTP_IS_TSN_PRESENT
parameter_list|(
name|arry
parameter_list|,
name|gap
parameter_list|)
value|((arry[(gap>> 3)]>> (gap& 0x07))& 0x01)
end_define

begin_define
define|#
directive|define
name|SCTP_SET_TSN_PRESENT
parameter_list|(
name|arry
parameter_list|,
name|gap
parameter_list|)
value|(arry[(gap>> 3)] |= (0x01<< ((gap& 0x07))))
end_define

begin_define
define|#
directive|define
name|SCTP_UNSET_TSN_PRESENT
parameter_list|(
name|arry
parameter_list|,
name|gap
parameter_list|)
value|(arry[(gap>> 3)]&= ((~(0x01<< ((gap& 0x07))))& 0xff))
end_define

begin_comment
comment|/*  * This value defines the number of vtag block time wait entry's per list  * element.  Each entry will take 2 4 byte ints (and of course the overhead  * of the next pointer as well). Using 15 as an example will yield * ((8 *  * 15) + 8) or 128 bytes of overhead for each timewait block that gets  * initialized. Increasing it to 31 would yeild 256 bytes per block.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_NUMBER_IN_VTAG_BLOCK
value|15
end_define

begin_comment
comment|/*  * If we use the STACK option, we have an array of this size head pointers.  * This array is mod'd the with the size to find which bucket and then all  * entries must be searched to see if the tag is in timed wait. If so we  * reject it.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_STACK_VTAG_HASH_SIZE
value|31
end_define

begin_comment
comment|/*  * If we use the per-endpoint model than we do not have a hash table of  * entries but instead have a single head pointer and we must crawl through  * the entire list.  */
end_comment

begin_comment
comment|/*  * Number of seconds of time wait, tied to MSL value (2 minutes), so 2 * MSL  * = 4 minutes or 480 seconds.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_TIME_WAIT
value|480
end_define

begin_comment
comment|/* This time wait is the same as the default cookie life  * since we now enter a tag in every time we send a cookie.  * We want this shorter to avoid vtag depletion.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_TIME_WAIT_SHORT
value|60
end_define

begin_comment
comment|/* The system retains a cache of free chunks such to  * cut down on calls the memory allocation system. There  * is a per association limit of free items and a overall  * system limit. If either one gets hit then the resource  * stops being cached.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_DEF_ASOC_RESC_LIMIT
value|10
end_define

begin_define
define|#
directive|define
name|SCTP_DEF_SYSTEM_RESC_LIMIT
value|1000
end_define

begin_define
define|#
directive|define
name|IN4_ISPRIVATE_ADDRESS
parameter_list|(
name|a
parameter_list|)
define|\
value|((((uint8_t *)&(a)->s_addr)[0] == 10) || \     ((((uint8_t *)&(a)->s_addr)[0] == 172)&& \      (((uint8_t *)&(a)->s_addr)[1]>= 16)&& \      (((uint8_t *)&(a)->s_addr)[1]<= 32)) || \     ((((uint8_t *)&(a)->s_addr)[0] == 192)&& \      (((uint8_t *)&(a)->s_addr)[1] == 168)))
end_define

begin_define
define|#
directive|define
name|IN4_ISLOOPBACK_ADDRESS
parameter_list|(
name|a
parameter_list|)
define|\
value|((((uint8_t *)&(a)->s_addr)[0] == 127)&& \      (((uint8_t *)&(a)->s_addr)[1] == 0)&& \      (((uint8_t *)&(a)->s_addr)[2] == 0)&& \      (((uint8_t *)&(a)->s_addr)[3] == 1))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_define
define|#
directive|define
name|SCTP_GETTIME_TIMEVAL
parameter_list|(
name|x
parameter_list|)
value|(getmicrouptime(x))
end_define

begin_define
define|#
directive|define
name|SCTP_GETPTIME_TIMEVAL
parameter_list|(
name|x
parameter_list|)
value|(microuptime(x))
end_define

begin_comment
comment|/*#if defined(__FreeBSD__) || defined(__APPLE__)*/
end_comment

begin_comment
comment|/*#define SCTP_GETTIME_TIMEVAL(x) { \*/
end_comment

begin_comment
comment|/*	(x)->tv_sec = ticks / 1000; \*/
end_comment

begin_comment
comment|/*	(x)->tv_usec = (ticks % 1000) * 1000; \*/
end_comment

begin_comment
comment|/*}*/
end_comment

begin_comment
comment|/*#else*/
end_comment

begin_comment
comment|/*#define SCTP_GETTIME_TIMEVAL(x)	(microtime(x))*/
end_comment

begin_comment
comment|/*#endif				 __FreeBSD__ */
end_comment

begin_define
define|#
directive|define
name|sctp_sowwakeup
parameter_list|(
name|inp
parameter_list|,
name|so
parameter_list|)
define|\
value|do { \ 	if (inp->sctp_flags& SCTP_PCB_FLAGS_DONT_WAKE) { \ 		inp->sctp_flags |= SCTP_PCB_FLAGS_WAKEOUTPUT; \ 	} else { \ 		sowwakeup(so); \ 	} \ } while (0)
end_define

begin_define
define|#
directive|define
name|sctp_sowwakeup_locked
parameter_list|(
name|inp
parameter_list|,
name|so
parameter_list|)
define|\
value|do { \ 	if (inp->sctp_flags& SCTP_PCB_FLAGS_DONT_WAKE) { \                 SOCKBUF_UNLOCK(&((so)->so_snd)); \ 		inp->sctp_flags |= SCTP_PCB_FLAGS_WAKEOUTPUT; \ 	} else { \ 		sowwakeup_locked(so); \ 	} \ } while (0)
end_define

begin_define
define|#
directive|define
name|sctp_sorwakeup
parameter_list|(
name|inp
parameter_list|,
name|so
parameter_list|)
define|\
value|do { \ 	if (inp->sctp_flags& SCTP_PCB_FLAGS_DONT_WAKE) { \ 		inp->sctp_flags |= SCTP_PCB_FLAGS_WAKEINPUT; \ 	} else { \ 		sorwakeup(so); \ 	} \ } while (0)
end_define

begin_define
define|#
directive|define
name|sctp_sorwakeup_locked
parameter_list|(
name|inp
parameter_list|,
name|so
parameter_list|)
define|\
value|do { \ 	if (inp->sctp_flags& SCTP_PCB_FLAGS_DONT_WAKE) { \ 		inp->sctp_flags |= SCTP_PCB_FLAGS_WAKEINPUT; \                 SOCKBUF_UNLOCK(&((so)->so_rcv)); \ 	} else { \ 		sorwakeup_locked(so); \ 	} \ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

