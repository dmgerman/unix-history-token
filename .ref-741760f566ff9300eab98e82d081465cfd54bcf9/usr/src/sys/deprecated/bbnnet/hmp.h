begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * $Header: hmp.h,v 1.1 85/04/08 15:27:33 craig Exp $   *   * $Log:	hmp.h,v $  * Revision 1.1  85/04/08  15:27:33  craig  * Initial revision  *    *  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*  sockaddr_in with additional fields for hmp                            */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_struct
struct|struct
name|sockaddr_hmp
block|{
name|short
name|sin_family
decl_stmt|;
comment|/* standard INET stuff */
name|u_short
name|sin_port
decl_stmt|;
name|struct
name|in_addr
name|sin_addr
decl_stmt|;
name|u_char
name|sih_systype
decl_stmt|;
comment|/* HMP specific fields */
name|u_char
name|sih_msgtype
decl_stmt|;
name|u_char
name|sih_options
decl_stmt|;
name|u_char
name|sih_ctlflgs
decl_stmt|;
name|u_short
name|sih_seqno
decl_stmt|;
name|u_short
name|sih_passwd
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sih_rseqno
value|sih_passwd
end_define

begin_define
define|#
directive|define
name|HM_MOREBIT
value|0x2
end_define

begin_comment
comment|/* sih_ctlflgs: remote host has more data */
end_comment

begin_define
define|#
directive|define
name|HM_TRAPOPT
value|0x1
end_define

begin_comment
comment|/* sih_options: receive traps */
end_comment

begin_define
define|#
directive|define
name|HM_SEQOPT
value|0x2
end_define

begin_comment
comment|/* sih_options: enforce sequencing */
end_comment

begin_define
define|#
directive|define
name|HM_NUMOPT
value|0x3
end_define

begin_comment
comment|/* sih_options: use remote seqnum */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|HM_CONNOPTS
value|(HM_NUMOPT)
end_define

begin_define
define|#
directive|define
name|HM_BINDOPTS
value|(HM_TRAPOPT|HM_SEQOPT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*                       SYSTEM TYPES                                     */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_define
define|#
directive|define
name|HM_MONHOST
value|1
end_define

begin_define
define|#
directive|define
name|HM_IMP
value|2
end_define

begin_define
define|#
directive|define
name|HM_TAC
value|3
end_define

begin_define
define|#
directive|define
name|HM_GWY
value|4
end_define

begin_define
define|#
directive|define
name|HM_SIMP
value|5
end_define

begin_define
define|#
directive|define
name|HM_HOST
value|6
end_define

begin_comment
comment|/* BBN 4.1BSD HOSTS */
end_comment

begin_define
define|#
directive|define
name|HM_RESERVED
value|7
end_define

begin_define
define|#
directive|define
name|HM_TIU
value|9
end_define

begin_define
define|#
directive|define
name|HM_FEP
value|10
end_define

begin_define
define|#
directive|define
name|HM_CRHOST
value|11
end_define

begin_comment
comment|/* CRONUS HOST */
end_comment

begin_define
define|#
directive|define
name|HM_CRMCS
value|12
end_define

begin_comment
comment|/* CRONUS MON& CTL STA */
end_comment

begin_define
define|#
directive|define
name|HM_42HOST
value|7
end_define

begin_define
define|#
directive|define
name|HM_43HOST
value|13
end_define

begin_comment
comment|/* unapproved # */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*                         MESSAGE TYPES                                  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_define
define|#
directive|define
name|HM_TRAP
value|1
end_define

begin_define
define|#
directive|define
name|HM_STATUS
value|2
end_define

begin_define
define|#
directive|define
name|HM_THRUPUT
value|3
end_define

begin_define
define|#
directive|define
name|HM_HTM
value|4
end_define

begin_define
define|#
directive|define
name|HM_PARAM
value|5
end_define

begin_define
define|#
directive|define
name|HM_ROUTE
value|6
end_define

begin_define
define|#
directive|define
name|HM_CALLACCT
value|7
end_define

begin_define
define|#
directive|define
name|HM_POLL
value|100
end_define

begin_define
define|#
directive|define
name|HM_ERROR
value|101
end_define

begin_define
define|#
directive|define
name|HM_CTLACK
value|102
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*                       ERROR TYPES                                      */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_define
define|#
directive|define
name|HM_EUNSPEC
value|1
end_define

begin_comment
comment|/* reason unspecified */
end_comment

begin_define
define|#
directive|define
name|HM_ERTYPE
value|2
end_define

begin_comment
comment|/* bad r-message type */
end_comment

begin_define
define|#
directive|define
name|HM_ERSUB
value|3
end_define

begin_comment
comment|/* bad r-sub type */
end_comment

begin_define
define|#
directive|define
name|HM_EUPARAM
value|4
end_define

begin_comment
comment|/* unknown param */
end_comment

begin_define
define|#
directive|define
name|HM_EIPARAM
value|5
end_define

begin_comment
comment|/* invalid param */
end_comment

begin_define
define|#
directive|define
name|HM_EFORMAT
value|6
end_define

begin_comment
comment|/* invalid paramter/value format */
end_comment

begin_define
define|#
directive|define
name|HM_ELOADER
value|7
end_define

begin_comment
comment|/* machine in loader */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*                      SPECIAL PORTS                                     */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_define
define|#
directive|define
name|HM_MAXPORTS
value|0xff
end_define

begin_define
define|#
directive|define
name|HOST_PORT
value|1
end_define

begin_comment
comment|/* where polls to this host go */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*			OPTIONS                                           */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SOI_MONHOST
value|0x1
end_define

begin_comment
comment|/* HMP -- set/get monioring hosts */
end_comment

begin_define
define|#
directive|define
name|MAX_MONHOSTS
value|2
end_define

begin_comment
comment|/* how many hosts monitor us at once */
end_comment

end_unit

