begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $Begemot: libunimsg/netnatm/msg/uni_hdr.h,v 1.6 2004/07/08 08:22:05 brandt Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETNATM_MSG_UNI_HDR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETNATM_MSG_UNI_HDR_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/stdint.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netnatm/msg/uni_config.h>
end_include

begin_enum
enum|enum
block|{
name|UNI_PROTO
init|=
literal|0x09
block|,
comment|/* protocol discriminator */
name|PNNI_PROTO
init|=
literal|0xf0
block|,
comment|/* PNNI protocol discriminator */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Message types  */
end_comment

begin_enum
enum|enum
name|uni_msgtype
block|{
name|UNI_UNKNOWN
init|=
literal|0x100
block|,
comment|/* unknown message */
name|UNI_ALERTING
init|=
literal|0x01
block|,
comment|/* alerting */
name|UNI_CALL_PROC
init|=
literal|0x02
block|,
comment|/* call proceeding */
name|UNI_SETUP
init|=
literal|0x05
block|,
comment|/* setup */
name|UNI_CONNECT
init|=
literal|0x07
block|,
comment|/* connect */
name|UNI_CONNECT_ACK
init|=
literal|0x0f
block|,
comment|/* connect ack */
name|UNI_RESTART
init|=
literal|0x46
block|,
comment|/* restart */
name|UNI_RELEASE
init|=
literal|0x4d
block|,
comment|/* release */
name|UNI_RESTART_ACK
init|=
literal|0x4e
block|,
comment|/* restart acknowledgement */
name|UNI_RELEASE_COMPL
init|=
literal|0x5a
block|,
comment|/* release complete */
name|UNI_NOTIFY
init|=
literal|0x6e
block|,
comment|/* notify user */
name|UNI_STATUS_ENQ
init|=
literal|0x75
block|,
comment|/* status enquiry */
name|UNI_STATUS
init|=
literal|0x7d
block|,
comment|/* status */
name|UNI_ADD_PARTY
init|=
literal|0x80
block|,
comment|/* add party */
name|UNI_ADD_PARTY_ACK
init|=
literal|0x81
block|,
comment|/* add party acknowledgement */
name|UNI_ADD_PARTY_REJ
init|=
literal|0x82
block|,
comment|/* add party reject */
name|UNI_DROP_PARTY
init|=
literal|0x83
block|,
comment|/* drop party */
name|UNI_DROP_PARTY_ACK
init|=
literal|0x84
block|,
comment|/* drop party acknowledgement */
name|UNI_PARTY_ALERTING
init|=
literal|0x85
block|,
comment|/* party alerting */
name|UNI_LEAF_SETUP_FAIL
init|=
literal|0x90
block|,
comment|/* leaf setup failed */
name|UNI_LEAF_SETUP_REQ
init|=
literal|0x91
block|,
comment|/* leaf setup request */
name|UNI_COBISETUP
init|=
literal|0x15
block|,
comment|/* Q.2932 COBI-setup */
name|UNI_FACILITY
init|=
literal|0x62
block|,
comment|/* Q.2932 facility */
name|UNI_MODIFY_REQ
init|=
literal|0x88
block|,
comment|/* Q.2963 Modify request */
name|UNI_MODIFY_ACK
init|=
literal|0x89
block|,
comment|/* Q.2963 Modify acknowledgement */
name|UNI_MODIFY_REJ
init|=
literal|0x8a
block|,
comment|/* Q.2963 Modify reject */
name|UNI_CONN_AVAIL
init|=
literal|0x8b
block|,
comment|/* Q.2963 Connection available */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Information element types  */
end_comment

begin_enum
enum|enum
name|uni_ietype
block|{
name|UNI_IE_CAUSE
init|=
literal|0x08
block|,
comment|/* cause */
name|UNI_IE_CALLSTATE
init|=
literal|0x14
block|,
comment|/* call state */
name|UNI_IE_FACILITY
init|=
literal|0x1C
block|,
comment|/* Q.2932 facility IE */
name|UNI_IE_NOTIFY
init|=
literal|0x27
block|,
comment|/* UNI4.0 notify */
name|UNI_IE_EETD
init|=
literal|0x42
block|,
comment|/* UNI4.0 end-to-end transit delay */
name|UNI_IE_CONNED
init|=
literal|0x4c
block|,
comment|/* UNI4.0/Q.2951 connected address */
name|UNI_IE_CONNEDSUB
init|=
literal|0x4d
block|,
comment|/* UNI4.0/Q.2951 connected subaddress */
name|UNI_IE_EPREF
init|=
literal|0x54
block|,
comment|/* endpoint reference */
name|UNI_IE_EPSTATE
init|=
literal|0x55
block|,
comment|/* enpoint state */
name|UNI_IE_AAL
init|=
literal|0x58
block|,
comment|/* ATM adaptation layer parameters */
name|UNI_IE_TRAFFIC
init|=
literal|0x59
block|,
comment|/* ATM traffic descriptor */
name|UNI_IE_CONNID
init|=
literal|0x5a
block|,
comment|/* connection identifier */
name|UNI_IE_QOS
init|=
literal|0x5c
block|,
comment|/* quality of service parameter */
name|UNI_IE_BHLI
init|=
literal|0x5d
block|,
comment|/* broadband higher layer information */
name|UNI_IE_BEARER
init|=
literal|0x5e
block|,
comment|/* broadband bearer capability */
name|UNI_IE_BLLI
init|=
literal|0x5f
block|,
comment|/* broadband lower layer information */
name|UNI_IE_LSHIFT
init|=
literal|0x60
block|,
comment|/* broadband locking shift */
name|UNI_IE_NLSHIFT
init|=
literal|0x61
block|,
comment|/* broadband non-locking shift */
name|UNI_IE_SCOMPL
init|=
literal|0x62
block|,
comment|/* broadband sending complete */
name|UNI_IE_REPEAT
init|=
literal|0x63
block|,
comment|/* broadband repeat indicator */
name|UNI_IE_CALLING
init|=
literal|0x6c
block|,
comment|/* calling party number */
name|UNI_IE_CALLINGSUB
init|=
literal|0x6d
block|,
comment|/* calling party subaddress */
name|UNI_IE_CALLED
init|=
literal|0x70
block|,
comment|/* called party number */
name|UNI_IE_CALLEDSUB
init|=
literal|0x71
block|,
comment|/* called party subaddress */
name|UNI_IE_TNS
init|=
literal|0x78
block|,
comment|/* transit network selection */
name|UNI_IE_RESTART
init|=
literal|0x79
block|,
comment|/* restart indicator */
name|UNI_IE_UU
init|=
literal|0x7e
block|,
comment|/* UNI4.0/Q.2957 user-to-user info */
name|UNI_IE_GIT
init|=
literal|0x7f
block|,
comment|/* UNI4.0 generic identifier transport*/
name|UNI_IE_MINTRAFFIC
init|=
literal|0x81
block|,
comment|/* Q.2962 minimum traffic desc */
name|UNI_IE_ATRAFFIC
init|=
literal|0x82
block|,
comment|/* Q.2962 alternate traffic desc */
name|UNI_IE_ABRSETUP
init|=
literal|0x84
block|,
comment|/* UNI4.0 ABR setup parameters */
name|UNI_IE_REPORT
init|=
literal|0x89
block|,
comment|/* Q.2963 broadband report type */
name|UNI_IE_CALLED_SOFT
init|=
literal|0xe0
block|,
comment|/* PNNI Calling party soft PVPC */
name|UNI_IE_CRANKBACK
init|=
literal|0xe1
block|,
comment|/* PNNI Crankback */
name|UNI_IE_DTL
init|=
literal|0xe2
block|,
comment|/* PNNI designated transit list */
name|UNI_IE_CALLING_SOFT
init|=
literal|0xe3
block|,
comment|/* PNNI Called party soft PVPC */
name|UNI_IE_ABRADD
init|=
literal|0xe4
block|,
comment|/* UNI4.0 ABR additional parameters */
name|UNI_IE_LIJ_CALLID
init|=
literal|0xe8
block|,
comment|/* UNI4.0 LIF call identifier */
name|UNI_IE_LIJ_PARAM
init|=
literal|0xe9
block|,
comment|/* UNI4.0 LIF parameters */
name|UNI_IE_LIJ_SEQNO
init|=
literal|0xea
block|,
comment|/* UNI4.0 LIF sequence number */
name|UNI_IE_CSCOPE
init|=
literal|0xeb
block|,
comment|/* UNI4.0 connection scope selection */
name|UNI_IE_EXQOS
init|=
literal|0xec
block|,
comment|/* UNI4.0 extended QoS parameters */
name|UNI_IE_MDCR
init|=
literal|0xf0
block|,
comment|/* UNI4.0+ Minimum desired call rate */
name|UNI_IE_UNREC
init|=
literal|0xfe
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|uni_coding
block|{
name|UNI_CODING_ITU
init|=
literal|0x0
block|,
name|UNI_CODING_NET
init|=
literal|0x3
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|uni_msgact
block|{
name|UNI_MSGACT_CLEAR
init|=
literal|0x0
block|,
name|UNI_MSGACT_IGNORE
init|=
literal|0x1
block|,
name|UNI_MSGACT_REPORT
init|=
literal|0x2
block|,
name|UNI_MSGACT_DEFAULT
init|=
literal|0x4
block|}
enum|;
end_enum

begin_enum
enum|enum
name|uni_ieact
block|{
name|UNI_IEACT_CLEAR
init|=
literal|0x00
block|,
comment|/* clear call */
name|UNI_IEACT_IGNORE
init|=
literal|0x01
block|,
comment|/* ignore IE and proceed */
name|UNI_IEACT_REPORT
init|=
literal|0x02
block|,
comment|/* ignore IE, report and proceed */
name|UNI_IEACT_MSG_IGNORE
init|=
literal|0x05
block|,
comment|/* ignore message */
name|UNI_IEACT_MSG_REPORT
init|=
literal|0x06
block|,
comment|/* ignore message and report */
name|UNI_IEACT_DEFAULT
init|=
literal|0x08
block|}
enum|;
end_enum

begin_struct
struct|struct
name|uni_cref
block|{
name|u_int
name|flag
decl_stmt|;
name|u_int
name|cref
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Message header.  */
end_comment

begin_struct
struct|struct
name|uni_msghdr
block|{
name|struct
name|uni_cref
name|cref
decl_stmt|;
name|enum
name|uni_msgact
name|act
decl_stmt|;
comment|/* action indicator */
name|u_int
name|pass
range|:
literal|1
decl_stmt|;
comment|/* PNNI pass along request */
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|CREF_GLOBAL
init|=
literal|0
block|,
name|CREF_DUMMY
init|=
literal|0x7fffff
block|, }
enum|;
end_enum

begin_comment
comment|/*  * General information element header.  */
end_comment

begin_struct
struct|struct
name|uni_iehdr
block|{
name|enum
name|uni_coding
name|coding
decl_stmt|;
comment|/* coding standard */
name|enum
name|uni_ieact
name|act
decl_stmt|;
comment|/* action indicator */
name|u_int
name|pass
range|:
literal|1
decl_stmt|;
comment|/* PNNI pass along request */
name|u_int
name|present
decl_stmt|;
comment|/* which optional elements are present */
define|#
directive|define
name|UNI_IE_EMPTY
value|0x80000000
define|#
directive|define
name|UNI_IE_PRESENT
value|0x40000000
define|#
directive|define
name|UNI_IE_ERROR
value|0x20000000
define|#
directive|define
name|UNI_IE_XXX
value|0x10000000
define|#
directive|define
name|UNI_IE_MASK
value|0xf0000000
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IE_ISPRESENT
parameter_list|(
name|IE
parameter_list|)
define|\
value|(((IE).h.present& (UNI_IE_PRESENT|UNI_IE_EMPTY)) == UNI_IE_PRESENT)
end_define

begin_define
define|#
directive|define
name|IE_SETPRESENT
parameter_list|(
name|IE
parameter_list|)
define|\
value|((IE).h.present = ((IE).h.present& ~UNI_IE_MASK) | \ 		UNI_IE_PRESENT)
end_define

begin_define
define|#
directive|define
name|IE_ADDPRESENT
parameter_list|(
name|IE
parameter_list|)
define|\
value|((IE).h.present = ((IE).h.present& ~UNI_IE_EMPTY) | \ 		UNI_IE_PRESENT)
end_define

begin_define
define|#
directive|define
name|IE_ISEMPTY
parameter_list|(
name|IE
parameter_list|)
define|\
value|(((IE).h.present& UNI_IE_MASK) == (UNI_IE_PRESENT | UNI_IE_EMPTY))
end_define

begin_define
define|#
directive|define
name|IE_SETEMPTY
parameter_list|(
name|IE
parameter_list|)
define|\
value|((IE).h.present = ((IE).h.present& ~UNI_IE_MASK) | \ 		UNI_IE_EMPTY | UNI_IE_PRESENT)
end_define

begin_define
define|#
directive|define
name|IE_ISERROR
parameter_list|(
name|IE
parameter_list|)
define|\
value|(((IE).h.present& UNI_IE_MASK) == (UNI_IE_PRESENT | UNI_IE_ERROR))
end_define

begin_define
define|#
directive|define
name|IE_SETERROR
parameter_list|(
name|IE
parameter_list|)
define|\
value|((IE).h.present = ((IE).h.present& ~UNI_IE_MASK) | \ 		UNI_IE_ERROR | UNI_IE_PRESENT)
end_define

begin_define
define|#
directive|define
name|IE_ISGOOD
parameter_list|(
name|IE
parameter_list|)
define|\
value|(((IE).h.present& UNI_IE_MASK) == (UNI_IE_PRESENT))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

