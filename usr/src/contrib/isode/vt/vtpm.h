begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* vtpm.h - VTPM: definitions */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/vt/RCS/vtpm.h,v 7.1 91/02/22 09:48:32 mrose Interim $  *  *  * $Log:	vtpm.h,v $  * Revision 7.1  91/02/22  09:48:32  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  22:31:58  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"acsap.h"
end_include

begin_comment
comment|/* definitions for AcS-USERs */
end_comment

begin_include
include|#
directive|include
file|"logger.h"
end_include

begin_comment
comment|/* Make sure this is here in new versions */
end_comment

begin_comment
comment|/*#include "sector1.h"*/
end_comment

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|ERR
value|-1
end_define

begin_define
define|#
directive|define
name|E_ERROR
value|-1
end_define

begin_define
define|#
directive|define
name|E_EOF
value|-2
end_define

begin_define
define|#
directive|define
name|E_NOEVENT
value|1
end_define

begin_define
define|#
directive|define
name|E_READ
value|2
end_define

begin_define
define|#
directive|define
name|INPUT
value|1
end_define

begin_define
define|#
directive|define
name|OUTPUT
value|2
end_define

begin_define
define|#
directive|define
name|DEFINED
value|1
end_define

begin_define
define|#
directive|define
name|UNDEFINED
value|0
end_define

begin_define
define|#
directive|define
name|BASIC
value|1
end_define

begin_define
define|#
directive|define
name|WACI_WACA
value|0
end_define

begin_define
define|#
directive|define
name|WAVAR
value|1
end_define

begin_define
define|#
directive|define
name|FAILURE
value|0
end_define

begin_define
define|#
directive|define
name|SUCCESS
value|1
end_define

begin_define
define|#
directive|define
name|WARNING
value|2
end_define

begin_define
define|#
directive|define
name|ECHO_NOW
value|0
end_define

begin_define
define|#
directive|define
name|NOT_ECHO_NOW
value|1
end_define

begin_define
define|#
directive|define
name|DISPLAY
value|0
end_define

begin_define
define|#
directive|define
name|CONTROL
value|2
end_define

begin_define
define|#
directive|define
name|SEQUENCED
value|1
end_define

begin_define
define|#
directive|define
name|NONSEQUENCED
value|2
end_define

begin_define
define|#
directive|define
name|COLL_DET
value|1
end_define

begin_define
define|#
directive|define
name|PROFILE_NG
value|4
end_define

begin_define
define|#
directive|define
name|TEXT
value|5
end_define

begin_define
define|#
directive|define
name|WOULDBLOCK
value|-3
end_define

begin_comment
comment|/*  type identifiers  */
end_comment

begin_define
define|#
directive|define
name|G_COLLISION_WINNER
value|1
end_define

begin_define
define|#
directive|define
name|G_PARM_VLIST
value|6
end_define

begin_define
define|#
directive|define
name|G_RESULT3
value|11
end_define

begin_comment
comment|/*  Incoming Events -- Table 25, ISO 9041           */
end_comment

begin_define
define|#
directive|define
name|VASSreq
value|1
end_define

begin_comment
comment|/*VT-ASSOCIATE request*/
end_comment

begin_define
define|#
directive|define
name|VASSrsp
value|2
end_define

begin_comment
comment|/*VT-ASSOCIATE response*/
end_comment

begin_define
define|#
directive|define
name|VBRKreq
value|3
end_define

begin_comment
comment|/*VT-BREAK request*/
end_comment

begin_define
define|#
directive|define
name|VBRKrsp
value|4
end_define

begin_comment
comment|/*VT-BREAK response*/
end_comment

begin_define
define|#
directive|define
name|VDACKreq
value|5
end_define

begin_comment
comment|/*VT-ACK-RECEIPT request*/
end_comment

begin_define
define|#
directive|define
name|VDATreq_u
value|6
end_define

begin_comment
comment|/*VT-DATA request urgent priority*/
end_comment

begin_define
define|#
directive|define
name|VDATreq_h
value|7
end_define

begin_comment
comment|/*VT-DATA request high priority*/
end_comment

begin_define
define|#
directive|define
name|VDATreq_n
value|8
end_define

begin_comment
comment|/*VT-DATA request normal*/
end_comment

begin_define
define|#
directive|define
name|VDATreq_sqtr
value|9
end_define

begin_comment
comment|/*VT-DATA request trigger control*/
end_comment

begin_define
define|#
directive|define
name|VDELreq
value|10
end_define

begin_comment
comment|/*VT-DELIVER request*/
end_comment

begin_define
define|#
directive|define
name|VENEGreq
value|11
end_define

begin_comment
comment|/*VT-END-NEG request*/
end_comment

begin_define
define|#
directive|define
name|VENEGrsp
value|12
end_define

begin_comment
comment|/*VT-END-NEG response*/
end_comment

begin_define
define|#
directive|define
name|VGVTreq
value|13
end_define

begin_comment
comment|/*VT-GIVE-TOKENS request*/
end_comment

begin_define
define|#
directive|define
name|VNACCreq
value|14
end_define

begin_comment
comment|/*VT-NEG-ACCEPT (negotiation accept)*/
end_comment

begin_define
define|#
directive|define
name|VNINVreq
value|15
end_define

begin_comment
comment|/*Negotiation Invitaion*/
end_comment

begin_define
define|#
directive|define
name|VNOFFreq
value|16
end_define

begin_comment
comment|/*Negotiation Offer*/
end_comment

begin_define
define|#
directive|define
name|VNREJreq
value|17
end_define

begin_comment
comment|/*Negotiation Reject*/
end_comment

begin_define
define|#
directive|define
name|VRELreq
value|18
end_define

begin_comment
comment|/*VT-RELEASE request*/
end_comment

begin_define
define|#
directive|define
name|VRELrsp
value|19
end_define

begin_comment
comment|/*VT-RELEASE response*/
end_comment

begin_define
define|#
directive|define
name|VRQTreq
value|20
end_define

begin_comment
comment|/*VT-REQUEST-TOKENS request*/
end_comment

begin_define
define|#
directive|define
name|VSNEGreq
value|21
end_define

begin_comment
comment|/*Start Negotiation request*/
end_comment

begin_define
define|#
directive|define
name|VSNEGrsp
value|22
end_define

begin_comment
comment|/*Start Negotiation response*/
end_comment

begin_define
define|#
directive|define
name|VSWPreq
value|23
end_define

begin_comment
comment|/*Switch Profile request*/
end_comment

begin_define
define|#
directive|define
name|VSWPrsp
value|24
end_define

begin_comment
comment|/*Switch Profile response*/
end_comment

begin_define
define|#
directive|define
name|VUABreq
value|25
end_define

begin_comment
comment|/*VT-U-ABORT request*/
end_comment

begin_define
define|#
directive|define
name|APQ
value|26
end_define

begin_comment
comment|/*VT-P-ABORT request*/
end_comment

begin_define
define|#
directive|define
name|ASQ
value|27
end_define

begin_comment
comment|/*Associate Request*/
end_comment

begin_define
define|#
directive|define
name|ASR
value|28
end_define

begin_comment
comment|/*Associate Response*/
end_comment

begin_define
define|#
directive|define
name|AUQ
value|29
end_define

begin_comment
comment|/*VT-U-ABORT request*/
end_comment

begin_define
define|#
directive|define
name|BKQ
value|30
end_define

begin_comment
comment|/*Break Request*/
end_comment

begin_define
define|#
directive|define
name|BKR
value|31
end_define

begin_comment
comment|/*Break Response*/
end_comment

begin_define
define|#
directive|define
name|DAQ
value|32
end_define

begin_comment
comment|/*VT-ACK-RECEIPT*/
end_comment

begin_define
define|#
directive|define
name|DLQ
value|33
end_define

begin_comment
comment|/*VT-DELIVER*/
end_comment

begin_define
define|#
directive|define
name|HDQ
value|34
end_define

begin_comment
comment|/*VT-EXPEDITED-DATA*/
end_comment

begin_define
define|#
directive|define
name|ENQ
value|35
end_define

begin_comment
comment|/*End Negotiation Request*/
end_comment

begin_define
define|#
directive|define
name|ENR
value|36
end_define

begin_comment
comment|/*End Negotiation Response*/
end_comment

begin_define
define|#
directive|define
name|GTQ
value|37
end_define

begin_comment
comment|/*VT-GIVE-TOKEN*/
end_comment

begin_define
define|#
directive|define
name|NAQ
value|38
end_define

begin_comment
comment|/*Negotiation Accept Request*/
end_comment

begin_define
define|#
directive|define
name|NDQ_ntr
value|39
end_define

begin_comment
comment|/*VT-DATA -- No Trigger Update*/
end_comment

begin_define
define|#
directive|define
name|NDQ_tr
value|40
end_define

begin_comment
comment|/*VT-DATA -- Trigger Update*/
end_comment

begin_define
define|#
directive|define
name|NJQ
value|41
end_define

begin_comment
comment|/*Negotiation Reject Request*/
end_comment

begin_define
define|#
directive|define
name|NIQ
value|42
end_define

begin_comment
comment|/*Negotiation Invite Request*/
end_comment

begin_define
define|#
directive|define
name|NOQ
value|43
end_define

begin_comment
comment|/*Negotiation Offer Request*/
end_comment

begin_define
define|#
directive|define
name|RLQ
value|44
end_define

begin_comment
comment|/*VT-RELEASE-REQ*/
end_comment

begin_define
define|#
directive|define
name|RLR
value|45
end_define

begin_comment
comment|/*VT-RELEASE-RESP*/
end_comment

begin_define
define|#
directive|define
name|RTQ
value|46
end_define

begin_comment
comment|/*VT-REQUEST-TOKEN*/
end_comment

begin_define
define|#
directive|define
name|SPQ
value|47
end_define

begin_comment
comment|/*VT-SWITCH-PROFILE-REQ*/
end_comment

begin_define
define|#
directive|define
name|SPR
value|48
end_define

begin_comment
comment|/*VT-SWITCH-PROFILE-RESP*/
end_comment

begin_define
define|#
directive|define
name|SNQ
value|49
end_define

begin_comment
comment|/*Start Negotiation Request*/
end_comment

begin_define
define|#
directive|define
name|SNR
value|50
end_define

begin_comment
comment|/*Start Negotiation Response*/
end_comment

begin_define
define|#
directive|define
name|UDQ
value|51
end_define

begin_comment
comment|/*VT-UNCONTROLLED-DATA*/
end_comment

begin_define
define|#
directive|define
name|AUTO
value|52
end_define

begin_comment
comment|/*Internal event not defined by VTP*/
end_comment

begin_define
define|#
directive|define
name|VTAB
value|53
end_define

begin_comment
comment|/*Irrecoverable exception condition*/
end_comment

begin_define
define|#
directive|define
name|PAB
value|54
end_define

begin_comment
comment|/*Failure Indication*/
end_comment

begin_comment
comment|/*  Outgoing Events -- Table 27, ISO 9041	*/
end_comment

begin_define
define|#
directive|define
name|VACKind
value|55
end_define

begin_comment
comment|/*VT-ACK-RECEIPT Indication*/
end_comment

begin_define
define|#
directive|define
name|VASSind
value|56
end_define

begin_comment
comment|/*VT-ASSOCIATE Indication*/
end_comment

begin_define
define|#
directive|define
name|VASScnf
value|57
end_define

begin_comment
comment|/*VT-ASSOCIATE Confirm*/
end_comment

begin_define
define|#
directive|define
name|VBRKind
value|58
end_define

begin_comment
comment|/*VT-BREAK Indication*/
end_comment

begin_define
define|#
directive|define
name|VBRKcnf
value|59
end_define

begin_comment
comment|/*VT-BREAK Confirm*/
end_comment

begin_define
define|#
directive|define
name|VDATind_u
value|60
end_define

begin_comment
comment|/*VT-DATA indication -- urgent object*/
end_comment

begin_define
define|#
directive|define
name|VDATind_h
value|61
end_define

begin_comment
comment|/*VT-DATA indication -- high object*/
end_comment

begin_define
define|#
directive|define
name|VDATind_n
value|62
end_define

begin_comment
comment|/*VT-DATA indication -- normal object*/
end_comment

begin_define
define|#
directive|define
name|VDATind_Vnt
value|63
end_define

begin_comment
comment|/*Sequence of Vnt VT-DATA normal*/
end_comment

begin_define
define|#
directive|define
name|VDELind
value|64
end_define

begin_comment
comment|/*VT-DELIVER indication*/
end_comment

begin_define
define|#
directive|define
name|VENEGind
value|65
end_define

begin_comment
comment|/*VT-END-NEG indication*/
end_comment

begin_define
define|#
directive|define
name|VENEGcnf
value|66
end_define

begin_comment
comment|/*VT-END-NEG confirm*/
end_comment

begin_define
define|#
directive|define
name|VGVTind
value|67
end_define

begin_comment
comment|/*VT-GIVE-TOKENS indication*/
end_comment

begin_define
define|#
directive|define
name|VNINVind
value|68
end_define

begin_comment
comment|/*VT-NEG-INVITE indication*/
end_comment

begin_define
define|#
directive|define
name|VNOFFind
value|69
end_define

begin_comment
comment|/*VT-NEG-OFFER indication*/
end_comment

begin_define
define|#
directive|define
name|VNACCind
value|70
end_define

begin_comment
comment|/*VT-NEG-ACCEPT indication*/
end_comment

begin_define
define|#
directive|define
name|VNREJind
value|71
end_define

begin_comment
comment|/*VT-NEG-REJECT indication*/
end_comment

begin_define
define|#
directive|define
name|VPABind
value|72
end_define

begin_comment
comment|/*VT-P-ABORT indication*/
end_comment

begin_define
define|#
directive|define
name|VRELind
value|73
end_define

begin_comment
comment|/*VT-RELEASE indication*/
end_comment

begin_define
define|#
directive|define
name|VRELcnf
value|74
end_define

begin_comment
comment|/*VT-RELEASE confirm*/
end_comment

begin_define
define|#
directive|define
name|VRQTind
value|75
end_define

begin_comment
comment|/*VT-REQUEST-TOKENS indication*/
end_comment

begin_define
define|#
directive|define
name|VSNEGind
value|76
end_define

begin_comment
comment|/*VT-START-NEG indication*/
end_comment

begin_define
define|#
directive|define
name|VSNEGcnf
value|77
end_define

begin_comment
comment|/*VT-START-NEG confirm*/
end_comment

begin_define
define|#
directive|define
name|VSWPind
value|78
end_define

begin_comment
comment|/*VT-SWITCH-PROFILE indication*/
end_comment

begin_define
define|#
directive|define
name|VSWPcnf
value|79
end_define

begin_comment
comment|/*VT-SWITCH-PROFILE confirm*/
end_comment

begin_define
define|#
directive|define
name|VUABind
value|80
end_define

begin_comment
comment|/*VT-U-ABORT indication*/
end_comment

begin_define
define|#
directive|define
name|NDQseq_ntr
value|81
end_define

begin_comment
comment|/*Sequence of NDQ-ntr to xmit updates*/
end_comment

begin_define
define|#
directive|define
name|NDQseq_tr
value|82
end_define

begin_comment
comment|/*1 NDQ-tr preceeded by>=1 NDQ-ntr*/
end_comment

begin_define
define|#
directive|define
name|NDQ_x_tr
value|83
end_define

begin_define
define|#
directive|define
name|NDQ_x_ntr
value|84
end_define

begin_comment
comment|/* Sector 1 States */
end_comment

begin_define
define|#
directive|define
name|S1_01
value|0
end_define

begin_comment
comment|/*No Association*/
end_comment

begin_define
define|#
directive|define
name|S1_02B
value|1
end_define

begin_comment
comment|/*Associate -- Awaiting target*/
end_comment

begin_define
define|#
directive|define
name|S1_02S
value|2
end_define

begin_comment
comment|/*Associate -- Awaiting target*/
end_comment

begin_define
define|#
directive|define
name|S1_03B
value|3
end_define

begin_comment
comment|/*Associate -- Awaiting User*/
end_comment

begin_define
define|#
directive|define
name|S1_03S
value|4
end_define

begin_comment
comment|/*Associate -- Awaiting User*/
end_comment

begin_define
define|#
directive|define
name|S1_10B
value|5
end_define

begin_comment
comment|/*Environment Not Agreed*/
end_comment

begin_define
define|#
directive|define
name|S1_10N
value|6
end_define

begin_define
define|#
directive|define
name|S1_10T
value|7
end_define

begin_define
define|#
directive|define
name|S1_50B
value|8
end_define

begin_define
define|#
directive|define
name|S1_51Q
value|9
end_define

begin_comment
comment|/*Release -- Awaiting Peer*/
end_comment

begin_define
define|#
directive|define
name|S1_51R
value|10
end_define

begin_comment
comment|/*Release -- Awaiting User*/
end_comment

begin_define
define|#
directive|define
name|S1_51N
value|11
end_define

begin_comment
comment|/*Release -- Awaiting User*/
end_comment

begin_define
define|#
directive|define
name|S1_51T
value|12
end_define

begin_comment
comment|/*Release -- Awaiting Peer*/
end_comment

begin_comment
comment|/* Sector 5 States */
end_comment

begin_define
define|#
directive|define
name|S5_400B
value|0
end_define

begin_comment
comment|/*Data Transfer*/
end_comment

begin_define
define|#
directive|define
name|S5_402B
value|1
end_define

begin_comment
comment|/*Data Xfer -- Awaiting Ack from user*/
end_comment

begin_define
define|#
directive|define
name|S5_420B
value|2
end_define

begin_comment
comment|/*Data Xfer -- Awaiting Ack from peer*/
end_comment

begin_define
define|#
directive|define
name|S5_422B
value|3
end_define

begin_comment
comment|/*Data xfer -- Awaiting Ack (Both)*/
end_comment

begin_define
define|#
directive|define
name|S5_40N
value|4
end_define

begin_comment
comment|/*Data Transfer*/
end_comment

begin_define
define|#
directive|define
name|S5_40T
value|5
end_define

begin_comment
comment|/*Data Transfer*/
end_comment

begin_define
define|#
directive|define
name|S5_42T
value|6
end_define

begin_comment
comment|/*Data Xfer -- Awaiting Ack from peer*/
end_comment

begin_define
define|#
directive|define
name|S5_42N
value|7
end_define

begin_comment
comment|/*Data Xfer -- Awaiting Ack from user*/
end_comment

begin_define
define|#
directive|define
name|S5_61
value|8
end_define

begin_comment
comment|/*Break Request rcv'd from User*/
end_comment

begin_define
define|#
directive|define
name|S5_62
value|9
end_define

begin_comment
comment|/*Break Request rcv'd from Peer*/
end_comment

begin_define
define|#
directive|define
name|INITIATOR
value|0
end_define

begin_define
define|#
directive|define
name|ACCEPTOR
value|1
end_define

begin_define
define|#
directive|define
name|ACHOICE
value|2
end_define

begin_comment
comment|/*  PDU Types  (Table 4, ISO 9041) */
end_comment

begin_define
define|#
directive|define
name|ASQ_PDU
value|0
end_define

begin_define
define|#
directive|define
name|ASR_PDU
value|1
end_define

begin_define
define|#
directive|define
name|RLR_PDU
value|2
end_define

begin_define
define|#
directive|define
name|AUQ_PDU
value|3
end_define

begin_define
define|#
directive|define
name|APQ_PDU
value|4
end_define

begin_define
define|#
directive|define
name|HDQ_PDU
value|5
end_define

begin_define
define|#
directive|define
name|NDQ_PDU
value|6
end_define

begin_define
define|#
directive|define
name|UDQ_PDU
value|7
end_define

begin_define
define|#
directive|define
name|BKQ_PDU
value|8
end_define

begin_define
define|#
directive|define
name|BKR_PDU
value|9
end_define

begin_define
define|#
directive|define
name|DLQ_PDU
value|10
end_define

begin_define
define|#
directive|define
name|DAQ_PDU
value|11
end_define

begin_define
define|#
directive|define
name|SPQ_PDU
value|12
end_define

begin_define
define|#
directive|define
name|SPR_PDU
value|13
end_define

begin_define
define|#
directive|define
name|SNQ_PDU
value|14
end_define

begin_define
define|#
directive|define
name|SNR_PDU
value|15
end_define

begin_define
define|#
directive|define
name|ENQ_PDU
value|16
end_define

begin_define
define|#
directive|define
name|ENR_PDU
value|17
end_define

begin_define
define|#
directive|define
name|NIQ_PDU
value|18
end_define

begin_define
define|#
directive|define
name|NOQ_PDU
value|19
end_define

begin_define
define|#
directive|define
name|NAQ_PDU
value|20
end_define

begin_define
define|#
directive|define
name|NJQ_PDU
value|21
end_define

begin_define
define|#
directive|define
name|PEPYPARM
value|int *
end_define

begin_decl_stmt
name|PE
name|pre
decl_stmt|,
name|pwe
decl_stmt|;
end_decl_stmt

begin_function_decl
name|PE
name|mkdeliver
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|fd
decl_stmt|,
name|readfds
decl_stmt|,
name|writefds
decl_stmt|,
name|exfds
decl_stmt|,
name|sd
decl_stmt|,
name|connected
decl_stmt|,
name|netfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|dprofile
decl_stmt|,
modifier|*
name|cprofile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|myname
decl_stmt|,
name|ttyname
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PE
name|p_ondq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|LLog
name|_vt_log
decl_stmt|,
modifier|*
name|vt_log
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|state
decl_stmt|,
name|sector
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vns
decl_stmt|,
name|allpmde
decl_stmt|,
comment|/* all draft VTE parameters defined */
name|allpmdu
decl_stmt|,
comment|/* all draft VTE parameters defined or undefined */
name|cnw
decl_stmt|,
comment|/* collision winner right assigned to this VTPM  */
name|dcno
decl_stmt|,
comment|/* no delivery control */
name|dcqua
decl_stmt|,
comment|/* quarantine delivery control */
name|dcsim
decl_stmt|,
comment|/* simple delivery control     */
name|pmacc
decl_stmt|,
comment|/* parameter values acceptable */
name|dr_pm_st
decl_stmt|,
comment|/* draft parameter status: 						DEFINED, 						UNDEFINED, 						OFI,  (offered, initiator) 						OFR,  (offered, responder) 						COFI, (counter-offered, initiator) 						COFR, (counter-offered, responder) 						INVI, (invited, initiator) 						INVR  (invited, responder) 				*/
name|pracc
decl_stmt|,
name|vtpma
decl_stmt|,
name|vcwa
decl_stmt|,
comment|/* whether the collision winner right is owned */
name|vena
decl_stmt|,
comment|/* agreement on current VTE */
name|vnt
decl_stmt|,
comment|/* number of VT service data units held for local delivery */
name|vns
decl_stmt|,
comment|/* number of VT service data units held for transmission */
name|vacc
decl_stmt|,
comment|/*action choice: switch, restore, or not specified*/
name|vacp
decl_stmt|,
comment|/*action proposal: switch, restore, or responder 			  choice*/
name|vrea
decl_stmt|,
comment|/*failure reason: collision detected or profile not 			  supplied*/
name|vrjo
decl_stmt|,
comment|/*rejection option: retain, discard, or responder 			  choice*/
name|vrsl
decl_stmt|,
comment|/*result: succes, failure, or success with warning*/
name|vsmd
decl_stmt|,
comment|/*1 if S-Mode, 0 if A-Mode*/
name|vtok
decl_stmt|,
comment|/*1 if tokens held, 0 otherwise*/
name|vtkp
decl_stmt|,
comment|/*token parameters*/
name|waca
decl_stmt|,
comment|/*WACA right*/
name|vra
decl_stmt|,
comment|/*Boolean recording of acknowledgement request*/
name|G_Func_Units
decl_stmt|,
comment|/*Bit map of Functional Units requested*/
name|wavar
decl_stmt|,
comment|/* boolean, this VTPM has the token */
name|waci
decl_stmt|,
comment|/* boolean, this VTPM is assigned the waci right */
name|del_cont
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* type of delivery control		*/
end_comment

begin_comment
comment|/*  	profile is name of the profile. This is also used for the draft profile. */
end_comment

begin_decl_stmt
name|int
name|s1_01
argument_list|()
decl_stmt|,
name|s1_02B
argument_list|()
decl_stmt|,
name|s1_02S
argument_list|()
decl_stmt|,
name|s1_03B
argument_list|()
decl_stmt|,
name|s1_03S
argument_list|()
decl_stmt|,
name|s1_10B
argument_list|()
decl_stmt|,
name|s1_10N
argument_list|()
decl_stmt|,
name|s1_10T
argument_list|()
decl_stmt|,
name|s1_50B
argument_list|()
decl_stmt|,
name|s1_51Q
argument_list|()
decl_stmt|,
name|s1_51R
argument_list|()
decl_stmt|,
name|s1_51N
argument_list|()
decl_stmt|,
name|s1_51T
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|s5_400B
argument_list|()
decl_stmt|,
name|s5_402B
argument_list|()
decl_stmt|,
name|s5_420B
argument_list|()
decl_stmt|,
name|s5_422B
argument_list|()
decl_stmt|,
name|s5_40N
argument_list|()
decl_stmt|,
name|s5_40T
argument_list|()
decl_stmt|,
name|s5_42N
argument_list|()
decl_stmt|,
name|s5_42T
argument_list|()
decl_stmt|,
name|s5_61
argument_list|()
decl_stmt|,
name|s5_62
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|SSAPref
name|sfs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|SSAPref
modifier|*
name|sf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|PSAPaddr
modifier|*
name|pa
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|AcSAPconnect
name|accs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|AcSAPconnect
modifier|*
name|acc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|AcSAPrelease
name|acrs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|AcSAPrelease
modifier|*
name|acr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|AcSAPindication
name|acis
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|AcSAPindication
modifier|*
name|aci
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|AcSAPabort
modifier|*
name|aca
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|AEI
name|aei
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|OID
name|ctx
decl_stmt|,
name|pci
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|AcSAPstart
name|acss
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|AcSAPstart
modifier|*
name|acs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|PSAPstart
modifier|*
name|ps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|PSAPindication
name|pi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|PSAPdata
name|px
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|PSAPfinish
modifier|*
name|pf
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|finalbye
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|adios
argument_list|()
decl_stmt|,
name|advise
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|acs_adios
argument_list|()
decl_stmt|,
name|acs_advise
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ps_adios
argument_list|()
decl_stmt|,
name|ps_advise
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|connected
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*TEMP -- for sector 1 testing only -- will be supplied by VTP*/
end_comment

begin_function_decl
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

end_unit

