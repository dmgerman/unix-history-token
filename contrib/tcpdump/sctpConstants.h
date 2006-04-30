begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) $Header: /tcpdump/master/tcpdump/sctpConstants.h,v 1.4 2003/06/03 23:49:23 guy Exp $ (LBL) */
end_comment

begin_comment
comment|/* SCTP reference Implementation Copyright (C) 1999 Cisco And Motorola  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of Cisco nor of Motorola may be used  *    to endorse or promote products derived from this software without  *    specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * This file is part of the SCTP reference Implementation  *  *  * Please send any bug reports or fixes you make to one of the following email  * addresses:  *  * rstewar1@email.mot.com  * kmorneau@cisco.com  * qxie1@email.mot.com  *  * Any bugs reported given to us we will try to fix... any fixes shared will  * be incorperated into the next SCTP release.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__sctpConstants_h__
end_ifndef

begin_define
define|#
directive|define
name|__sctpConstants_h__
end_define

begin_comment
comment|/* If you wish to use MD5 instead of SLA uncomment the line    * below. Why you would like to do this:    * a) There may be IPR on SHA-1, or so the FIP-180-1 page says,    * b) MD5 is 3 times faster (has coded here).    *    * The disadvantage is, it is thought that MD5 has been    * cracked... see RFC2104.    */
end_comment

begin_comment
comment|/*#define USE_MD5 1*/
end_comment

begin_comment
comment|/* the SCTP protocol signature  * this includes the version number  * encoded in the last 4 bits of the  * signature.  */
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
comment|/* option:  * If you comment out the following you will  * receive the old behavior of obeying cwnd for  * the fast retransmit algorithm. With this defined  * a FR happens right away with-out waiting for the  * flightsize to drop below the cwnd value (which  * is reduced by the FR to 1/2 the inflight packets).  */
end_comment

begin_define
define|#
directive|define
name|SCTP_IGNORE_CWND_ON_FR
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
comment|/* Packet transmit states in the sent  * field in the SCTP_transmitOnQueue struct  */
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
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|SCTP_DATAGRAM_RESEND2
value|3
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|SCTP_DATAGRAM_RESEND3
value|4
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|SCTP_DATAGRAM_RESEND
value|5
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
name|MAX_FSID
value|64
end_define

begin_comment
comment|/* debug 5 ints used for cc dynamic tracking */
end_comment

begin_comment
comment|/* The valid defines for all message  * types know to SCTP. 0 is reserved  */
end_comment

begin_define
define|#
directive|define
name|SCTP_MSGTYPE_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|SCTP_DATA
value|0x00
end_define

begin_define
define|#
directive|define
name|SCTP_INITIATION
value|0x01
end_define

begin_define
define|#
directive|define
name|SCTP_INITIATION_ACK
value|0x02
end_define

begin_define
define|#
directive|define
name|SCTP_SELECTIVE_ACK
value|0x03
end_define

begin_define
define|#
directive|define
name|SCTP_HEARTBEAT_REQUEST
value|0x04
end_define

begin_define
define|#
directive|define
name|SCTP_HEARTBEAT_ACK
value|0x05
end_define

begin_define
define|#
directive|define
name|SCTP_ABORT_ASSOCIATION
value|0x06
end_define

begin_define
define|#
directive|define
name|SCTP_SHUTDOWN
value|0x07
end_define

begin_define
define|#
directive|define
name|SCTP_SHUTDOWN_ACK
value|0x08
end_define

begin_define
define|#
directive|define
name|SCTP_OPERATION_ERR
value|0x09
end_define

begin_define
define|#
directive|define
name|SCTP_COOKIE_ECHO
value|0x0a
end_define

begin_define
define|#
directive|define
name|SCTP_COOKIE_ACK
value|0x0b
end_define

begin_define
define|#
directive|define
name|SCTP_ECN_ECHO
value|0x0c
end_define

begin_define
define|#
directive|define
name|SCTP_ECN_CWR
value|0x0d
end_define

begin_define
define|#
directive|define
name|SCTP_SHUTDOWN_COMPLETE
value|0x0e
end_define

begin_define
define|#
directive|define
name|SCTP_FORWARD_CUM_TSN
value|0xc0
end_define

begin_define
define|#
directive|define
name|SCTP_RELIABLE_CNTL
value|0xc1
end_define

begin_define
define|#
directive|define
name|SCTP_RELIABLE_CNTL_ACK
value|0xc2
end_define

begin_comment
comment|/* ABORT and SHUTDOWN COMPLETE FLAG */
end_comment

begin_define
define|#
directive|define
name|SCTP_HAD_NO_TCB
value|0x01
end_define

begin_comment
comment|/* Data Chuck Specific Flags */
end_comment

begin_define
define|#
directive|define
name|SCTP_DATA_FRAG_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|SCTP_DATA_MIDDLE_FRAG
value|0x00
end_define

begin_define
define|#
directive|define
name|SCTP_DATA_LAST_FRAG
value|0x01
end_define

begin_define
define|#
directive|define
name|SCTP_DATA_FIRST_FRAG
value|0x02
end_define

begin_define
define|#
directive|define
name|SCTP_DATA_NOT_FRAG
value|0x03
end_define

begin_define
define|#
directive|define
name|SCTP_DATA_UNORDERED
value|0x04
end_define

begin_define
define|#
directive|define
name|SCTP_CRC_ENABLE_BIT
value|0x01
end_define

begin_comment
comment|/* lower bit of reserved */
end_comment

begin_define
define|#
directive|define
name|isSCTPControl
parameter_list|(
name|a
parameter_list|)
value|(a->chunkID != SCTP_DATA)
end_define

begin_define
define|#
directive|define
name|isSCTPData
parameter_list|(
name|a
parameter_list|)
value|(a->chunkID == SCTP_DATA)
end_define

begin_comment
comment|/* sctp parameter types for init/init-ack */
end_comment

begin_define
define|#
directive|define
name|SCTP_IPV4_PARAM_TYPE
value|0x0005
end_define

begin_define
define|#
directive|define
name|SCTP_IPV6_PARAM_TYPE
value|0x0006
end_define

begin_define
define|#
directive|define
name|SCTP_RESPONDER_COOKIE
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
name|SCTP_HOSTNAME_VIA_DNS
value|0x000b
end_define

begin_define
define|#
directive|define
name|SCTP_RESTRICT_ADDR_TO
value|0x000c
end_define

begin_define
define|#
directive|define
name|SCTP_ECN_I_CAN_DO_ECN
value|0x8000
end_define

begin_define
define|#
directive|define
name|SCTP_OPERATION_SUCCEED
value|0x4001
end_define

begin_define
define|#
directive|define
name|SCTP_ERROR_NOT_EXECUTED
value|0x4002
end_define

begin_define
define|#
directive|define
name|SCTP_UNRELIABLE_STRM
value|0xc000
end_define

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
name|SCTP_STRM_FLOW_LIMIT
value|0xc003
end_define

begin_define
define|#
directive|define
name|SCTP_PARTIAL_CSUM
value|0xc004
end_define

begin_define
define|#
directive|define
name|SCTP_ERROR_CAUSE_TLV
value|0xc005
end_define

begin_define
define|#
directive|define
name|SCTP_MIT_STACK_NAME
value|0xc006
end_define

begin_define
define|#
directive|define
name|SCTP_SETADDRESS_PRIMARY
value|0xc007
end_define

begin_comment
comment|/* bits for TOS field */
end_comment

begin_define
define|#
directive|define
name|SCTP_ECT_BIT
value|0x02
end_define

begin_define
define|#
directive|define
name|SCTP_CE_BIT
value|0x01
end_define

begin_comment
comment|/* error codes */
end_comment

begin_define
define|#
directive|define
name|SCTP_OP_ERROR_NO_ERROR
value|0x0000
end_define

begin_define
define|#
directive|define
name|SCTP_OP_ERROR_INV_STRM
value|0x0001
end_define

begin_define
define|#
directive|define
name|SCTP_OP_ERROR_MISS_PARAM
value|0x0002
end_define

begin_define
define|#
directive|define
name|SCTP_OP_ERROR_STALE_COOKIE
value|0x0003
end_define

begin_define
define|#
directive|define
name|SCTP_OP_ERROR_NO_RESOURCE
value|0x0004
end_define

begin_define
define|#
directive|define
name|SCTP_OP_ERROR_DNS_FAILED
value|0x0005
end_define

begin_define
define|#
directive|define
name|SCTP_OP_ERROR_UNK_CHUNK
value|0x0006
end_define

begin_define
define|#
directive|define
name|SCTP_OP_ERROR_INV_PARAM
value|0x0007
end_define

begin_define
define|#
directive|define
name|SCTP_OP_ERROR_UNK_PARAM
value|0x0008
end_define

begin_define
define|#
directive|define
name|SCTP_OP_ERROR_NO_USERD
value|0x0009
end_define

begin_define
define|#
directive|define
name|SCTP_OP_ERROR_COOKIE_SHUT
value|0x000a
end_define

begin_define
define|#
directive|define
name|SCTP_OP_ERROR_DELETE_LAST
value|0x000b
end_define

begin_define
define|#
directive|define
name|SCTP_OP_ERROR_RESOURCE_SHORT
value|0x000c
end_define

begin_define
define|#
directive|define
name|SCTP_MAX_ERROR_CAUSE
value|12
end_define

begin_comment
comment|/* empty error causes i.e. nothing but the cause  * are SCTP_OP_ERROR_NO_RESOURCE, SCTP_OP_ERROR_INV_PARAM,  * SCTP_OP_ERROR_COOKIE_SHUT.  */
end_comment

begin_comment
comment|/* parameter for Heart Beat */
end_comment

begin_define
define|#
directive|define
name|HEART_BEAT_PARAM
value|0x0001
end_define

begin_comment
comment|/* send options for SCTP  */
end_comment

begin_define
define|#
directive|define
name|SCTP_ORDERED_DELIVERY
value|0x01
end_define

begin_define
define|#
directive|define
name|SCTP_NON_ORDERED_DELIVERY
value|0x02
end_define

begin_define
define|#
directive|define
name|SCTP_DO_CRC16
value|0x08
end_define

begin_define
define|#
directive|define
name|SCTP_MY_ADDRESS_ONLY
value|0x10
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
comment|/* MTU discovery flags */
end_comment

begin_define
define|#
directive|define
name|SCTP_DONT_FRAGMENT
value|0x0100
end_define

begin_define
define|#
directive|define
name|SCTP_FRAGMENT_OK
value|0x0200
end_define

begin_comment
comment|/* SCTP state defines for internal state machine */
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
name|SCTP_STATE_COOKIE_SENT
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
name|SCTP_STATE_SHUTDOWN
value|0x0010
end_define

begin_define
define|#
directive|define
name|SCTP_STATE_SHUTDOWN_RECV
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
name|SCTP_STATE_SHUTDOWN_PEND
value|0x0080
end_define

begin_define
define|#
directive|define
name|SCTP_STATE_MASK
value|0x007f
end_define

begin_comment
comment|/* SCTP reachability state for each address */
end_comment

begin_define
define|#
directive|define
name|SCTP_ADDR_NOT_REACHABLE
value|1
end_define

begin_define
define|#
directive|define
name|SCTP_ADDR_REACHABLE
value|2
end_define

begin_define
define|#
directive|define
name|SCTP_ADDR_NOHB
value|4
end_define

begin_define
define|#
directive|define
name|SCTP_ADDR_BEING_DELETED
value|8
end_define

begin_comment
comment|/* How long a cookie lives */
end_comment

begin_define
define|#
directive|define
name|SCTP_DEFAULT_COOKIE_LIFE
value|60
end_define

begin_comment
comment|/* seconds */
end_comment

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
comment|/* guess at how big to make the TSN mapping array */
end_comment

begin_define
define|#
directive|define
name|SCTP_STARTING_MAPARRAY
value|10000
end_define

begin_comment
comment|/* Here we define the timer types used  * by the implementation has  * arguments in the set/get timer type calls.  */
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
name|SCTP_TIMER_SHUTDOWN
value|3
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_HEARTBEAT
value|4
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_PMTU
value|5
end_define

begin_comment
comment|/* number of timer types in the base SCTP  * structure used in the set/get and has  * the base default.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_NUM_TMRS
value|6
end_define

begin_define
define|#
directive|define
name|SCTP_IPV4_ADDRESS
value|2
end_define

begin_define
define|#
directive|define
name|SCTP_IPV6_ADDRESS
value|4
end_define

begin_comment
comment|/* timer types */
end_comment

begin_define
define|#
directive|define
name|SctpTimerTypeNone
value|0
end_define

begin_define
define|#
directive|define
name|SctpTimerTypeSend
value|1
end_define

begin_define
define|#
directive|define
name|SctpTimerTypeInit
value|2
end_define

begin_define
define|#
directive|define
name|SctpTimerTypeRecv
value|3
end_define

begin_define
define|#
directive|define
name|SctpTimerTypeShutdown
value|4
end_define

begin_define
define|#
directive|define
name|SctpTimerTypeHeartbeat
value|5
end_define

begin_define
define|#
directive|define
name|SctpTimerTypeCookie
value|6
end_define

begin_define
define|#
directive|define
name|SctpTimerTypeNewCookie
value|7
end_define

begin_define
define|#
directive|define
name|SctpTimerTypePathMtuRaise
value|8
end_define

begin_define
define|#
directive|define
name|SctpTimerTypeShutdownAck
value|9
end_define

begin_define
define|#
directive|define
name|SctpTimerTypeRelReq
value|10
end_define

begin_comment
comment|/* Here are the timer directives given to the  * user provided function  */
end_comment

begin_define
define|#
directive|define
name|SCTP_TIMER_START
value|1
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_STOP
value|2
end_define

begin_comment
comment|/* running flag states in timer structure */
end_comment

begin_define
define|#
directive|define
name|SCTP_TIMER_IDLE
value|0x0
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_EXPIRED
value|0x1
end_define

begin_define
define|#
directive|define
name|SCTP_TIMER_RUNNING
value|0x2
end_define

begin_comment
comment|/* number of simultaneous timers running */
end_comment

begin_define
define|#
directive|define
name|SCTP_MAX_NET_TIMERS
value|6
end_define

begin_comment
comment|/* base of where net timers start */
end_comment

begin_define
define|#
directive|define
name|SCTP_NUMBER_TIMERS
value|12
end_define

begin_comment
comment|/* allows up to 6 destinations */
end_comment

begin_comment
comment|/* Of course we really don't collect stale cookies, being  * folks of decerning taste. However we do count them, if  * we get to many before the association comes up.. we  * give up. Below is the constant that dictates when  * we give it up...this is a implemenation dependant  * treatment. In ours we do not ask for a extension of  * time, but just retry this many times...  */
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
comment|/* Here we define the types used when  * setting the retry ammounts.  */
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
comment|/* Here we define the default timers and the  * default number of attemts we make for  * each respective side (send/init).  */
end_comment

begin_comment
comment|/* init timer def = 3sec  */
end_comment

begin_define
define|#
directive|define
name|SCTP_INIT_SEC
value|3
end_define

begin_define
define|#
directive|define
name|SCTP_INIT_NSEC
value|0
end_define

begin_comment
comment|/* send timer def = 3 seconds */
end_comment

begin_define
define|#
directive|define
name|SCTP_SEND_SEC
value|1
end_define

begin_define
define|#
directive|define
name|SCTP_SEND_NSEC
value|0
end_define

begin_comment
comment|/* recv timer def = 200ms (in nsec) */
end_comment

begin_define
define|#
directive|define
name|SCTP_RECV_SEC
value|0
end_define

begin_define
define|#
directive|define
name|SCTP_RECV_NSEC
value|200000000
end_define

begin_comment
comment|/* 30 seconds + RTO */
end_comment

begin_define
define|#
directive|define
name|SCTP_HB_SEC
value|30
end_define

begin_define
define|#
directive|define
name|SCTP_HB_NSEC
value|0
end_define

begin_comment
comment|/* 300 ms */
end_comment

begin_define
define|#
directive|define
name|SCTP_SHUTDOWN_SEC
value|0
end_define

begin_define
define|#
directive|define
name|SCTP_SHUTDOWN_NSEC
value|300000000
end_define

begin_define
define|#
directive|define
name|SCTP_RTO_UPPER_BOUND
value|60000000
end_define

begin_comment
comment|/* 60 sec in micro-second's */
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
value|1000000
end_define

begin_comment
comment|/* 1 sec in micro-sec's */
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
name|SCTP_DEF_PMTU_RAISE
value|600
end_define

begin_comment
comment|/* 10 Minutes between raise attempts */
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

begin_comment
comment|/* Events that SCTP will look for, these  * are or'd together to declare what SCTP  * wants. Each select mask/poll list should be  * set for the fd, if the bit is on.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_EVENT_READ
value|0x000001
end_define

begin_define
define|#
directive|define
name|SCTP_EVENT_WRITE
value|0x000002
end_define

begin_define
define|#
directive|define
name|SCTP_EVENT_EXCEPT
value|0x000004
end_define

begin_comment
comment|/* The following constant is a value for this  * particular implemenation. It is quite arbitrary and  * is used to limit how much data will be queued up to  * a sender, waiting for cwnd to be larger than flightSize.  * All implementations will need this protection is some  * way due to buffer size constraints.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_MAX_OUTSTANDING_DG
value|10000
end_define

begin_comment
comment|/* This constant (SCTP_MAX_READBUFFER) define  * how big the read/write buffer is  * when we enter the fd event notification  * the buffer is put on the stack, so the bigger  * it is the more stack you chew up, however it  * has got to be big enough to handle the bigest  * message this O/S will send you. In solaris  * with sockets (not TLI) we end up at a value  * of 64k. In TLI we could do partial reads to  * get it all in with less hassel.. but we  * write to sockets for generality.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_MAX_READBUFFER
value|65536
end_define

begin_define
define|#
directive|define
name|SCTP_ADDRMAX
value|60
end_define

begin_comment
comment|/* amount peer is obligated to have in rwnd or  * I will abort  */
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
comment|/* biggest I can grow rwnd to 				 * My playing around suggests a 				 * value greater than 64k does not 				 * do much, I guess via the kernel 				 * limitations on the stream/socket. 				 */
end_comment

begin_define
define|#
directive|define
name|SCTP_MAX_BUNDLE_UP
value|256
end_define

begin_comment
comment|/* max number of chunks I can bundle */
end_comment

begin_comment
comment|/*  I can handle a 1meg re-assembly */
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
name|SCTP_DEFAULT_MAXWINDOW
value|32768
end_define

begin_comment
comment|/* default rwnd size */
end_comment

begin_define
define|#
directive|define
name|SCTP_DEFAULT_MAXSEGMENT
value|1500
end_define

begin_comment
comment|/* MTU size, this is the default                                          * to which we set the smallestMTU 					 * size to. This governs what is the 					 * largest size we will use, of course 					 * PMTU will raise this up to 					 * the largest interface MTU or the 					 * ceiling below if there is no 					 * SIOCGIFMTU. 					 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LYNX
end_ifdef

begin_define
define|#
directive|define
name|DEFAULT_MTU_CEILING
value|1500
end_define

begin_comment
comment|/* Since Lynx O/S is brain dead 					 * in the way it handles the 					 * raw IP socket, insisting 					 * on makeing its own IP 					 * header, we limit the growth 					 * to that of the e-net size 					 */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEFAULT_MTU_CEILING
value|2048
end_define

begin_comment
comment|/* If no SIOCGIFMTU, highest value 					 * to raise the PMTU to, i.e. 					 * don't try to raise above this 					 * value. Tune this per your 					 * largest MTU interface if your 					 * system does not support the 					 * SIOCGIFMTU ioctl. 					 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/* This is how long a secret lives, NOT how long a cookie lives */
end_comment

begin_define
define|#
directive|define
name|SCTP_HOW_LONG_COOKIE_LIVE
value|3600
end_define

begin_comment
comment|/* how many seconds the current secret will live */
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

begin_ifdef
ifdef|#
directive|ifdef
name|USE_MD5
end_ifdef

begin_define
define|#
directive|define
name|SCTP_SIGNATURE_SIZE
value|16
end_define

begin_comment
comment|/* size of a MD5 signature */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SCTP_SIGNATURE_SIZE
value|20
end_define

begin_comment
comment|/* size of a SLA-1 signature */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Here are the notification constants  * that the code and upper layer will get  */
end_comment

begin_comment
comment|/* association is up */
end_comment

begin_define
define|#
directive|define
name|SCTP_NOTIFY_ASSOC_UP
value|1
end_define

begin_comment
comment|/* association is down */
end_comment

begin_define
define|#
directive|define
name|SCTP_NOTIFY_ASSOC_DOWN
value|2
end_define

begin_comment
comment|/* interface on a association is down  * and out of consideration for selection.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_NOTIFY_INTF_DOWN
value|3
end_define

begin_comment
comment|/* interface on a association is up  * and now back in consideration for selection.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_NOTIFY_INTF_UP
value|4
end_define

begin_comment
comment|/* The given datagram cannot be delivered  * to the peer, this will probably be followed  * by a SCTP_NOTFIY_ASSOC_DOWN.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_NOTIFY_DG_FAIL
value|5
end_define

begin_comment
comment|/* Sent dg on non-open stream extreme code error!  */
end_comment

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

begin_comment
comment|/* The stream ones are not used yet, but could  * be when a association opens.  */
end_comment

begin_define
define|#
directive|define
name|SCTP_NOTIFY_PEER_OPENED_STR
value|8
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_STREAM_OPENED_OK
value|9
end_define

begin_comment
comment|/* association sees a restart event */
end_comment

begin_define
define|#
directive|define
name|SCTP_NOTIFY_ASSOC_RESTART
value|10
end_define

begin_comment
comment|/* a user requested HB returned */
end_comment

begin_define
define|#
directive|define
name|SCTP_NOTIFY_HB_RESP
value|11
end_define

begin_comment
comment|/* a result from a REL-REQ */
end_comment

begin_define
define|#
directive|define
name|SCTP_NOTIFY_RELREQ_RESULT_OK
value|12
end_define

begin_define
define|#
directive|define
name|SCTP_NOTIFY_RELREQ_RESULT_FAILED
value|13
end_define

begin_comment
comment|/* clock variance is 10ms or 10,000 us's */
end_comment

begin_define
define|#
directive|define
name|SCTP_CLOCK_GRAINULARITY
value|10000
end_define

begin_define
define|#
directive|define
name|IP_HDR_SIZE
value|40
end_define

begin_comment
comment|/* we use the size of a IP6 header here 				 * this detracts a small amount for ipv4 				 * but it simplifies the ipv6 addition 				 */
end_comment

begin_define
define|#
directive|define
name|SCTP_NUM_FDS
value|3
end_define

begin_comment
comment|/* raw IP filedescriptor */
end_comment

begin_define
define|#
directive|define
name|SCTP_FD_IP
value|0
end_define

begin_comment
comment|/* raw ICMP filedescriptor */
end_comment

begin_define
define|#
directive|define
name|SCTP_FD_ICMP
value|1
end_define

begin_comment
comment|/* processes contact me for requests here */
end_comment

begin_define
define|#
directive|define
name|SCTP_REQUEST
value|2
end_define

begin_define
define|#
directive|define
name|SCTP_DEAMON_PORT
value|9899
end_define

begin_comment
comment|/* Deamon registration message types/responses */
end_comment

begin_define
define|#
directive|define
name|DEAMON_REGISTER
value|0x01
end_define

begin_define
define|#
directive|define
name|DEAMON_REGISTER_ACK
value|0x02
end_define

begin_define
define|#
directive|define
name|DEAMON_DEREGISTER
value|0x03
end_define

begin_define
define|#
directive|define
name|DEAMON_DEREGISTER_ACK
value|0x04
end_define

begin_define
define|#
directive|define
name|DEAMON_CHECKADDR_LIST
value|0x05
end_define

begin_define
define|#
directive|define
name|DEAMON_MAGIC_VER_LEN
value|0xff
end_define

begin_comment
comment|/* max times I will attempt to send a message to deamon */
end_comment

begin_define
define|#
directive|define
name|SCTP_MAX_ATTEMPTS_AT_DEAMON
value|5
end_define

begin_define
define|#
directive|define
name|SCTP_TIMEOUT_IN_POLL_FOR_DEAMON
value|1500
end_define

begin_comment
comment|/* 1.5 seconds */
end_comment

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
value|((a> b)&& ((a - b)< (M>> 1))) || \               ((b> a)&& ((b - a)> (M>> 1)))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TIMEVAL_TO_TIMESPEC
end_ifndef

begin_define
define|#
directive|define
name|TIMEVAL_TO_TIMESPEC
parameter_list|(
name|tv
parameter_list|,
name|ts
parameter_list|)
define|\
value|{							\     (ts)->tv_sec  = (tv)->tv_sec;			\     (ts)->tv_nsec = (tv)->tv_usec * 1000;		\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* pegs */
end_comment

begin_define
define|#
directive|define
name|SCTP_NUMBER_OF_PEGS
value|21
end_define

begin_comment
comment|/* peg index's */
end_comment

begin_define
define|#
directive|define
name|SCTP_PEG_SACKS_SEEN
value|0
end_define

begin_define
define|#
directive|define
name|SCTP_PEG_SACKS_SENT
value|1
end_define

begin_define
define|#
directive|define
name|SCTP_PEG_TSNS_SENT
value|2
end_define

begin_define
define|#
directive|define
name|SCTP_PEG_TSNS_RCVD
value|3
end_define

begin_define
define|#
directive|define
name|SCTP_DATAGRAMS_SENT
value|4
end_define

begin_define
define|#
directive|define
name|SCTP_DATAGRAMS_RCVD
value|5
end_define

begin_define
define|#
directive|define
name|SCTP_RETRANTSN_SENT
value|6
end_define

begin_define
define|#
directive|define
name|SCTP_DUPTSN_RECVD
value|7
end_define

begin_define
define|#
directive|define
name|SCTP_HBR_RECV
value|8
end_define

begin_define
define|#
directive|define
name|SCTP_HBA_RECV
value|9
end_define

begin_define
define|#
directive|define
name|SCTP_HB_SENT
value|10
end_define

begin_define
define|#
directive|define
name|SCTP_DATA_DG_SENT
value|11
end_define

begin_define
define|#
directive|define
name|SCTP_DATA_DG_RECV
value|12
end_define

begin_define
define|#
directive|define
name|SCTP_TMIT_TIMER
value|13
end_define

begin_define
define|#
directive|define
name|SCTP_RECV_TIMER
value|14
end_define

begin_define
define|#
directive|define
name|SCTP_HB_TIMER
value|15
end_define

begin_define
define|#
directive|define
name|SCTP_FAST_RETRAN
value|16
end_define

begin_define
define|#
directive|define
name|SCTP_PEG_TSNS_READ
value|17
end_define

begin_define
define|#
directive|define
name|SCTP_NONE_LFT_TO
value|18
end_define

begin_define
define|#
directive|define
name|SCTP_NONE_LFT_RWND
value|19
end_define

begin_define
define|#
directive|define
name|SCTP_NONE_LFT_CWND
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

