begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tpkt.h - include file for transport providers (TS-PROVIDER) */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/RCS/tpkt.h,v 7.4 91/02/22 09:25:14 mrose Interim $  *  *  * $Log:	tpkt.h,v $  * Revision 7.4  91/02/22  09:25:14  mrose  * Interim 6.8  *   * Revision 7.3  90/07/27  08:44:50  mrose  * update  *   * Revision 7.2  90/03/23  17:30:54  mrose  * 8  *   * Revision 7.1  89/12/07  01:07:57  mrose  * queued writes  *   * Revision 7.0  89/11/23  21:56:07  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_include
include|#
directive|include
file|"tsap.h"
end_include

begin_comment
comment|/* definitions for TS-USERs */
end_comment

begin_comment
comment|/*
comment|*/
end_comment

begin_define
define|#
directive|define
name|tsapPsig
parameter_list|(
name|tb
parameter_list|,
name|sd
parameter_list|)
define|\
value|{ \     if ((tb = findtblk (sd)) == NULL) { \ 	(void) sigiomask (smask); \ 	return tsaplose (td, DR_PARAMETER, NULLCP, \ 			    "invalid transport descriptor"); \     } \     if (!(tb -> tb_flags& TB_CONN)) { \ 	(void) sigiomask (smask); \ 	return tsaplose (td, DR_OPERATION, NULLCP, \ 			    "transport descriptor not connected"); \     } \ }
end_define

begin_define
define|#
directive|define
name|missingP
parameter_list|(
name|p
parameter_list|)
define|\
value|{ \     if (p == NULL) \ 	return tsaplose (td, DR_PARAMETER, NULLCP, \ 			    "mandatory parameter \"%s\" missing", "p"); \ }
end_define

begin_define
define|#
directive|define
name|toomuchP
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|,
name|m
parameter_list|,
name|p
parameter_list|)
define|\
value|{ \     if (b == NULL) \ 	n = 0; \     else \ 	if (n> m) \ 	    return tsaplose (td, DR_PARAMETER, NULLCP, \ 			    "too much %s user data, %d octets", p, n); \ }
end_define

begin_define
define|#
directive|define
name|copyTPKTdata
parameter_list|(
name|t
parameter_list|,
name|base
parameter_list|,
name|len
parameter_list|)
define|\
value|{ \     register struct udvec *uv = t -> t_udvec; \     if (len> 0) \ 	uv -> uv_base = base, uv -> uv_len = len, uv++; \     uv -> uv_base = NULL; \ }
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_define
define|#
directive|define
name|copyTSAPdata
parameter_list|(
name|base
parameter_list|,
name|len
parameter_list|,
name|d
parameter_list|)
define|\
value|{ \     register int i = len; \     if ((d -> d
comment|/* */
value|_cc = min (i, sizeof d -> d
comment|/* */
value|_data))> 0) \ 	bcopy (base, d -> d
comment|/* */
value|_data, d -> d
comment|/* */
value|_cc); \ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|copyTSAPdata
parameter_list|(
name|base
parameter_list|,
name|len
parameter_list|,
name|d
parameter_list|)
define|\
value|{ \     register int i = len; \     if ((d -> d##_cc = min (i, sizeof d -> d##_data))> 0) \ 	bcopy (base, d -> d##_data, d -> d##_cc); \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|copyTSAPdata
parameter_list|(
name|base
parameter_list|,
name|len
parameter_list|,
name|d
parameter_list|)
value|bcopy (base, (char *) d, len)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|tpktlose
argument_list|()
decl_stmt|,
name|tsaplose
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_struct
struct|struct
name|tsapADDR
block|{
name|struct
name|NSAPaddr
name|ta_addr
decl_stmt|;
name|int
name|ta_present
decl_stmt|;
name|int
name|ta_selectlen
decl_stmt|;
union|union
block|{
name|char
name|ta_un_selector
index|[
name|TSSIZE
index|]
decl_stmt|;
name|u_short
name|ta_un_port
decl_stmt|;
block|}
name|un_ta
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* network type codes: 					must be outside [0-9A-Fa-f] */
end_comment

begin_define
define|#
directive|define
name|NT_TCP
value|'T'
end_define

begin_comment
comment|/* TCP */
end_comment

begin_define
define|#
directive|define
name|NT_X25
value|'X'
end_define

begin_comment
comment|/* X.25 */
end_comment

begin_define
define|#
directive|define
name|NT_BRG
value|'G'
end_define

begin_comment
comment|/* Bridge */
end_comment

begin_define
define|#
directive|define
name|NT_BSD
value|'Z'
end_define

begin_comment
comment|/* 4.4BSD */
end_comment

begin_define
define|#
directive|define
name|NT_SUN
value|'S'
end_define

begin_comment
comment|/* SunLink OSI */
end_comment

begin_struct
struct|struct
name|tsapblk
block|{
name|struct
name|tsapblk
modifier|*
name|tb_forw
decl_stmt|;
comment|/* doubly-linked list */
name|struct
name|tsapblk
modifier|*
name|tb_back
decl_stmt|;
comment|/*   .. */
name|int
name|tb_fd
decl_stmt|;
comment|/* file descriptor */
name|char
name|tb_flags
decl_stmt|;
comment|/* our state */
define|#
directive|define
name|TB_NULL
value|0x00
define|#
directive|define
name|TB_CONN
value|0x01
comment|/* connected */
define|#
directive|define
name|TB_ASYN
value|0x02
comment|/* asynchronous */
define|#
directive|define
name|TB_EXPD
value|0x04
comment|/* expedited transfer selected */
define|#
directive|define
name|TB_TCP
value|0x08
comment|/* underlying service is TCP */
define|#
directive|define
name|TB_X25
value|0x10
comment|/*   ..		      is X.25 */
define|#
directive|define
name|TB_BRG
value|0x20
comment|/*   ..		      is Bridge */
define|#
directive|define
name|TB_TP0
value|(TB_TCP | TB_X25 | TB_BRG)
define|#
directive|define
name|TB_TP4
value|0x40
comment|/*   ..		      is TP4 */
comment|/* all TP4's use this value as it make 				   sense to have only one TP4 service 				   compiled in... */
define|#
directive|define
name|TB_QWRITES
value|0x80
comment|/* queued writes OK */
name|char
modifier|*
name|tb_magic
decl_stmt|;
comment|/* generic pointer */
comment|/* saved retry variables */
name|char
modifier|*
name|tb_data
decl_stmt|;
comment|/* saved user data */
name|int
name|tb_cc
decl_stmt|;
comment|/* saved user data count */
name|char
name|tb_expedited
decl_stmt|;
comment|/* saved expedited */
name|struct
name|TSAPaddr
modifier|*
name|tb_called
decl_stmt|;
comment|/* saved addresses */
name|struct
name|TSAPaddr
modifier|*
name|tb_calling
decl_stmt|;
comment|/*   .. */
name|struct
name|tsapkt
modifier|*
name|tb_retry
decl_stmt|;
comment|/* initial tpkt */
name|u_short
name|tb_srcref
decl_stmt|;
comment|/* source reference */
name|u_short
name|tb_dstref
decl_stmt|;
comment|/* destination reference */
name|int
name|tb_tsdusize
decl_stmt|;
comment|/* maximum TSDU size */
name|int
name|tb_tpduslop
decl_stmt|;
comment|/*   .. */
name|int
name|tb_tpdusize
decl_stmt|;
comment|/* for tp0ts */
name|int
name|tb_sent
decl_stmt|;
comment|/* TPDU bytes sent */
name|int
name|tb_recv
decl_stmt|;
comment|/* TPDU bytes recv */
name|struct
name|QOStype
name|tb_qos
decl_stmt|;
comment|/* quality of service */
name|struct
name|qbuf
name|tb_qbuf
decl_stmt|;
comment|/* for segmented TSDUs */
name|int
name|tb_len
decl_stmt|;
comment|/*   .. */
name|struct
name|tsapADDR
name|tb_initiating
decl_stmt|;
comment|/* initiator */
name|struct
name|tsapADDR
name|tb_responding
decl_stmt|;
comment|/* responder */
name|IFP
name|tb_retryfnx
decl_stmt|;
comment|/* resume async connection */
name|IFP
name|tb_connPfnx
decl_stmt|;
comment|/* TP connect */
name|IFP
name|tb_retryPfnx
decl_stmt|;
comment|/* TP retry connect */
name|IFP
name|tb_startPfnx
decl_stmt|;
comment|/* TP start accept */
name|IFP
name|tb_acceptPfnx
decl_stmt|;
comment|/* TP accept */
name|IFP
name|tb_writePfnx
decl_stmt|;
comment|/* TP write data */
name|IFP
name|tb_readPfnx
decl_stmt|;
comment|/* TP read data */
name|IFP
name|tb_discPfnx
decl_stmt|;
comment|/* TP disconnect */
name|IFP
name|tb_losePfnx
decl_stmt|;
comment|/* TP loses */
name|IFP
name|tb_drainPfnx
decl_stmt|;
comment|/* TP drain queued writes */
name|IFP
name|tb_queuePfnx
decl_stmt|;
comment|/* TP note queued writes */
name|struct
name|qbuf
name|tb_qwrites
decl_stmt|;
comment|/* queue of writes to retry */
name|IFP
name|tb_initfnx
decl_stmt|;
comment|/* init for read from network */
name|IFP
name|tb_readfnx
decl_stmt|;
comment|/* read from network */
name|IFP
name|tb_writefnx
decl_stmt|;
comment|/* write to network */
name|IFP
name|tb_closefnx
decl_stmt|;
comment|/* close network */
name|IFP
name|tb_selectfnx
decl_stmt|;
comment|/* select network */
name|IFP
name|tb_checkfnx
decl_stmt|;
comment|/* check network prior to select */
name|IFP
name|tb_nreadfnx
decl_stmt|;
comment|/* estimate of octets waiting to be read */
name|IFP
name|tb_DataIndication
decl_stmt|;
comment|/* INDICATION handlers */
name|IFP
name|tb_DiscIndication
decl_stmt|;
comment|/*   .. */
ifdef|#
directive|ifdef
name|MGMT
name|IFP
name|tb_manfnx
decl_stmt|;
comment|/* for management reports */
name|int
name|tb_pdus
decl_stmt|;
comment|/* PDUs sent */
name|int
name|tb_pdur
decl_stmt|;
comment|/* PDUs recv */
name|int
name|tb_bytes
decl_stmt|;
comment|/* bytes sent since last report */
name|int
name|tb_byter
decl_stmt|;
comment|/* bytes recv        ..         */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLBP
value|((struct tsapblk *) 0)
end_define

begin_function_decl
name|int
name|freetblk
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|tsapblk
modifier|*
name|newtblk
argument_list|()
decl_stmt|,
modifier|*
name|findtblk
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|TPKT datastructure */
end_comment

begin_struct
struct|struct
name|tsapkt
block|{
name|int
name|t_errno
decl_stmt|;
struct|struct
block|{
name|u_char
name|pk_vrsn
decl_stmt|;
define|#
directive|define
name|TPKT_VRSN
value|3
name|u_char
name|pk_rsrvd
decl_stmt|;
name|u_short
name|pk_length
decl_stmt|;
define|#
directive|define
name|TPKT_MAXLEN
value|0xffff
block|}
name|t_pkthdr
struct|;
define|#
directive|define
name|t_vrsn
value|t_pkthdr.pk_vrsn
define|#
directive|define
name|t_rsrvd
value|t_pkthdr.pk_rsrvd
define|#
directive|define
name|t_length
value|t_pkthdr.pk_length
define|#
directive|define
name|TPKT_HDRLEN
parameter_list|(
name|t
parameter_list|)
value|(sizeof ((t) -> t_pkthdr) + sizeof ((t) -> t_li) \ 			    + sizeof ((t) -> t_code))
struct|struct
block|{
name|u_char
name|tp_li
decl_stmt|;
ifndef|#
directive|ifndef
name|lint
ifndef|#
directive|ifndef
name|__STDC__
define|#
directive|define
name|TPDU_MINLEN
parameter_list|(
name|t
parameter_list|,
name|c
parameter_list|)
value|(c
comment|/* */
value|_SIZE(t) + sizeof ((t) -> t_code))
else|#
directive|else
define|#
directive|define
name|TPDU_MINLEN
parameter_list|(
name|t
parameter_list|,
name|c
parameter_list|)
value|(c##_SIZE(t) + sizeof ((t) -> t_code))
endif|#
directive|endif
else|#
directive|else
define|#
directive|define
name|TPDU_MINLEN
parameter_list|(
name|t
parameter_list|,
name|c
parameter_list|)
value|(sizeof ((t) -> t_code))
endif|#
directive|endif
define|#
directive|define
name|TPDU_MAXLEN
parameter_list|(
name|t
parameter_list|)
define|\
value|(min (0xfe, (t) -> t_length - sizeof ((t) -> t_pkthdr) \ 				    - sizeof ((t) -> t_li)))
define|#
directive|define
name|TPDU_USRLEN
parameter_list|(
name|t
parameter_list|)
define|\
value|((t) -> t_length - sizeof ((t) -> t_pkthdr) \ 			 - sizeof ((t) -> t_li) - (t) -> t_li)
name|u_char
name|tp_code
decl_stmt|;
define|#
directive|define
name|TPDU_CODE
parameter_list|(
name|t
parameter_list|)
value|((t) -> t_code& 0xf0)
define|#
directive|define
name|TPDU_CR
value|0xe0
comment|/* CONNECTION REQUEST */
define|#
directive|define
name|TPDU_CC
value|0xd0
comment|/* CONNECTION CONFIRMATION */
define|#
directive|define
name|TPDU_DR
value|0x80
comment|/* DISCONNECT REQUEST */
define|#
directive|define
name|TPDU_DC
value|0xc0
comment|/* DISCONNECT CONFIRMATION */
define|#
directive|define
name|TPDU_DT
value|0xf0
comment|/* DATA */
define|#
directive|define
name|TPDU_ED
value|0x10
comment|/* EXPEDITED DATA */
define|#
directive|define
name|TPDU_AK
value|0x60
comment|/* ACKNOWLEDGE */
define|#
directive|define
name|TPDU_EA
value|0x20
comment|/* EXPEDITED ACKNOWLEDGE */
define|#
directive|define
name|TPDU_RJ
value|0x50
comment|/* REJECT */
define|#
directive|define
name|TPDU_ER
value|0x70
comment|/* ERROR */
union|union
block|{
struct|struct
block|{
comment|/* FIXED part */
name|u_short
name|un_cr_dstref
decl_stmt|;
name|u_short
name|un_cr_srcref
decl_stmt|;
name|u_char
name|un_cr_class
decl_stmt|;
define|#
directive|define
name|CR_CLASS
parameter_list|(
name|t
parameter_list|)
value|((t) -> t_cr.cr_class& 0xf0)
define|#
directive|define
name|CR_CLASS_TP0
value|0x00
comment|/* class 0 */
define|#
directive|define
name|CR_CLASS_TP1
value|0x10
comment|/*   ..  1 */
define|#
directive|define
name|CR_CLASS_TP2
value|0x20
comment|/*   ..  2 */
define|#
directive|define
name|CR_CLASS_TP3
value|0x30
comment|/*   ..  3 */
define|#
directive|define
name|CR_CLASS_TP4
value|0x40
comment|/*   ..  4 */
define|#
directive|define
name|CR_OPT_EXTD
value|0x02
comment|/* extended formats in classes 2-4 */
define|#
directive|define
name|CR_OPT_EXPL
value|0x01
comment|/* explicit flow control in class 2 */
comment|/* VARIABLE part */
name|char
name|un_cr_called
index|[
name|TSSIZE
index|]
decl_stmt|;
name|int
name|un_cr_calledlen
decl_stmt|;
name|char
name|un_cr_calling
index|[
name|TSSIZE
index|]
decl_stmt|;
name|int
name|un_cr_callinglen
decl_stmt|;
name|u_char
name|un_cr_tpdusize
decl_stmt|;
name|u_short
name|un_cr_options
decl_stmt|;
name|u_char
name|un_cr_alternate
decl_stmt|;
block|}
name|un_cr
struct|;
define|#
directive|define
name|cr_dstref
value|un_cr_dstref
define|#
directive|define
name|cr_srcref
value|un_cr_srcref
define|#
directive|define
name|cr_class
value|un_cr_class
define|#
directive|define
name|cr_tpdusize
value|un_cr_tpdusize
define|#
directive|define
name|cr_options
value|un_cr_options
define|#
directive|define
name|cr_alternate
value|un_cr_alternate
define|#
directive|define
name|CR_SIZE
parameter_list|(
name|t
parameter_list|)
value|5
define|#
directive|define
name|un_cc
value|un_cr
define|#
directive|define
name|cc_dstref
value|un_cr_dstref
define|#
directive|define
name|cc_srcref
value|un_cr_srcref
define|#
directive|define
name|cc_class
value|un_cr_class
define|#
directive|define
name|cc_tpdusize
value|un_cr_tpdusize
define|#
directive|define
name|cc_options
value|un_cr_options
define|#
directive|define
name|CC_SIZE
parameter_list|(
name|t
parameter_list|)
value|5
struct|struct
block|{
comment|/* FIXED part */
name|u_short
name|un_dr_dstref
decl_stmt|;
name|u_short
name|un_dr_srcref
decl_stmt|;
name|u_char
name|un_dr_reason
decl_stmt|;
block|}
name|un_dr
struct|;
define|#
directive|define
name|dr_dstref
value|un_dr_dstref
define|#
directive|define
name|dr_srcref
value|un_dr_srcref
define|#
directive|define
name|dr_reason
value|un_dr_reason
define|#
directive|define
name|DR_SIZE
parameter_list|(
name|t
parameter_list|)
value|5
struct|struct
block|{
comment|/* FIXED part */
name|u_char
name|un_dt_nr
decl_stmt|;
define|#
directive|define
name|DT_EOT
value|0x80
block|}
name|un_dt
struct|;
define|#
directive|define
name|dt_nr
value|un_dt_nr
define|#
directive|define
name|DT_SIZE
parameter_list|(
name|t
parameter_list|)
value|1
define|#
directive|define
name|DT_MAGIC
value|(2 + 1)
comment|/* Expedited service is not allowed in TP0, but for testing purposes,    we permit it when the underlying service is TCP.  Note we use a    non-standard packet format (identical to the DT format).  */
define|#
directive|define
name|un_ed
value|un_dt
define|#
directive|define
name|ed_nr
value|un_dt_nr
define|#
directive|define
name|ED_SIZE
parameter_list|(
name|t
parameter_list|)
value|1
struct|struct
block|{
comment|/* FIXED part */
name|u_short
name|un_er_dstref
decl_stmt|;
name|u_char
name|un_er_reject
decl_stmt|;
define|#
directive|define
name|ER_REJ_NOTSPECIFIED
value|0x00
comment|/* Reason not specified */
define|#
directive|define
name|ER_REJ_CODE
value|0x01
comment|/* Invalid parameter code */
define|#
directive|define
name|ER_REJ_TPDU
value|0x02
comment|/* Invalid TPDU type */
define|#
directive|define
name|ER_REJ_VALUE
value|0x03
comment|/* Invalid parameter value */
block|}
name|un_er
struct|;
define|#
directive|define
name|er_dstref
value|un_er_dstref
define|#
directive|define
name|er_reject
value|un_er_reject
define|#
directive|define
name|ER_SIZE
parameter_list|(
name|t
parameter_list|)
value|3
block|}
name|tp_un
union|;
define|#
directive|define
name|tp_cr
value|tp_un.un_cr
define|#
directive|define
name|tp_cc
value|tp_un.un_cc
define|#
directive|define
name|tp_dr
value|tp_un.un_dr
define|#
directive|define
name|tp_dt
value|tp_un.un_dt
define|#
directive|define
name|tp_ed
value|tp_un.un_ed
define|#
directive|define
name|tp_er
value|tp_un.un_er
name|int
name|tp_vlen
decl_stmt|;
name|char
modifier|*
name|tp_vbase
decl_stmt|;
name|struct
name|qbuf
modifier|*
name|tp_qbuf
decl_stmt|;
comment|/* fd2tpkt ONLY */
define|#
directive|define
name|NTPUV
value|12
comment|/* really should be 						MSG_MAXIOVLEN - 4 */
name|struct
name|udvec
name|tp_udvec
index|[
name|NTPUV
index|]
decl_stmt|;
comment|/* tpkt2fd ONLY */
block|}
name|t_tpdu
struct|;
define|#
directive|define
name|t_li
value|t_tpdu.tp_li
define|#
directive|define
name|t_code
value|t_tpdu.tp_code
define|#
directive|define
name|t_cr
value|t_tpdu.tp_un.un_cr
define|#
directive|define
name|t_called
value|t_tpdu.tp_un.un_cr.un_cr_called
define|#
directive|define
name|t_calledlen
value|t_tpdu.tp_un.un_cr.un_cr_calledlen
define|#
directive|define
name|t_calling
value|t_tpdu.tp_un.un_cr.un_cr_calling
define|#
directive|define
name|t_callinglen
value|t_tpdu.tp_un.un_cr.un_cr_callinglen
define|#
directive|define
name|t_tpdusize
value|t_tpdu.tp_un.un_cr.un_cr_tpdusize
define|#
directive|define
name|t_options
value|t_tpdu.tp_un.un_cr.un_cr_options
define|#
directive|define
name|t_alternate
value|t_tpdu.tp_un.un_cr.un_cr_alternate
define|#
directive|define
name|t_cc
value|t_tpdu.tp_un.un_cc
define|#
directive|define
name|t_dr
value|t_tpdu.tp_un.un_dr
define|#
directive|define
name|t_dt
value|t_tpdu.tp_un.un_dt
define|#
directive|define
name|t_ed
value|t_tpdu.tp_un.un_ed
define|#
directive|define
name|t_er
value|t_tpdu.tp_un.un_er
define|#
directive|define
name|t_vdata
value|t_tpdu.tp_vbase
define|#
directive|define
name|t_vlen
value|t_tpdu.tp_vlen
define|#
directive|define
name|t_qbuf
value|t_tpdu.tp_qbuf
define|#
directive|define
name|t_udvec
value|t_tpdu.tp_udvec
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLPKT
value|((struct tsapkt *) 0)
end_define

begin_function_decl
name|int
name|freetpkt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tsapkt
modifier|*
name|newtpkt
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|text2tpkt
argument_list|()
decl_stmt|,
name|tpkt2text
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|tpkt2fd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tsapkt
modifier|*
name|fd2tpkt
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|tpkt2str
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tsapkt
modifier|*
name|str2tpkt
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|VARIABLE DATA codes, from ISO8073: */
end_comment

begin_comment
comment|/* for CR/CC TPDUs */
end_comment

begin_define
define|#
directive|define
name|VDAT_TSAP_SRV
value|0xc2
end_define

begin_comment
comment|/* TSAP ID of the calling TSAP */
end_comment

begin_define
define|#
directive|define
name|VDAT_TSAP_CLI
value|0xc1
end_define

begin_comment
comment|/* TSAP ID of the called TSAP */
end_comment

begin_define
define|#
directive|define
name|VDAT_SIZE
value|0xc0
end_define

begin_comment
comment|/* TPDU SIZE */
end_comment

begin_define
define|#
directive|define
name|SIZE_8K
value|0x0d
end_define

begin_comment
comment|/*   8192 */
end_comment

begin_define
define|#
directive|define
name|SIZE_4K
value|0x0c
end_define

begin_comment
comment|/*   4096 */
end_comment

begin_define
define|#
directive|define
name|SIZE_2K
value|0x0b
end_define

begin_comment
comment|/*   2048 */
end_comment

begin_define
define|#
directive|define
name|SIZE_1K
value|0x0a
end_define

begin_comment
comment|/*   1024 */
end_comment

begin_define
define|#
directive|define
name|SIZE_512
value|0x09
end_define

begin_comment
comment|/*    512 */
end_comment

begin_define
define|#
directive|define
name|SIZE_256
value|0x08
end_define

begin_comment
comment|/*    256 */
end_comment

begin_define
define|#
directive|define
name|SIZE_128
value|0x07
end_define

begin_comment
comment|/*    128 */
end_comment

begin_define
define|#
directive|define
name|SIZE_DFLT
value|SIZE_128
end_define

begin_define
define|#
directive|define
name|SIZE_MAXTP0
value|SIZE_2K
end_define

begin_define
define|#
directive|define
name|VDAT_VRSN
value|0xc4
end_define

begin_comment
comment|/* Version number */
end_comment

begin_define
define|#
directive|define
name|VDAT_SECURITY
value|0xc5
end_define

begin_comment
comment|/* Security parameters */
end_comment

begin_define
define|#
directive|define
name|VDAT_CHECKSUM
value|0xc3
end_define

begin_comment
comment|/* Checksum */
end_comment

begin_define
define|#
directive|define
name|VDAT_OPTIONS
value|0xc6
end_define

begin_comment
comment|/* Additional option selections */
end_comment

begin_define
define|#
directive|define
name|OPT_NEXPEDITE
value|0x08
end_define

begin_comment
comment|/*     Use network expedited */
end_comment

begin_define
define|#
directive|define
name|OPT_CONFIRM
value|0x04
end_define

begin_comment
comment|/*     Use receipt confirmation */
end_comment

begin_define
define|#
directive|define
name|OPT_CHECKSUM
value|0x02
end_define

begin_comment
comment|/*     Use 16-bit checksum */
end_comment

begin_define
define|#
directive|define
name|OPT_TEXPEDITE
value|0x01
end_define

begin_comment
comment|/*     Use transport expedited */
end_comment

begin_define
define|#
directive|define
name|VDAT_ALTERNATE
value|0xc7
end_define

begin_comment
comment|/* Alterated protocol class(es) */
end_comment

begin_define
define|#
directive|define
name|ALT_TP0
value|0x01
end_define

begin_comment
comment|/*     class 0 */
end_comment

begin_define
define|#
directive|define
name|ALT_TP1
value|0x02
end_define

begin_comment
comment|/*     class 1 */
end_comment

begin_define
define|#
directive|define
name|ALT_TP2
value|0x04
end_define

begin_comment
comment|/*     class 2 */
end_comment

begin_define
define|#
directive|define
name|ALT_TP3
value|0x08
end_define

begin_comment
comment|/*     class 3 */
end_comment

begin_define
define|#
directive|define
name|ALT_TP4
value|0x10
end_define

begin_comment
comment|/*     class 4 */
end_comment

begin_define
define|#
directive|define
name|VDAT_ACKTIME
value|0x85
end_define

begin_comment
comment|/* Acknowledge time */
end_comment

begin_define
define|#
directive|define
name|VDAT_THROUGHPUT
value|0x89
end_define

begin_comment
comment|/* Throughput */
end_comment

begin_define
define|#
directive|define
name|VDAT_ERRORATE
value|0x86
end_define

begin_comment
comment|/* Residual error rate */
end_comment

begin_define
define|#
directive|define
name|VDAT_PRIORITY
value|0x87
end_define

begin_comment
comment|/* Priority */
end_comment

begin_define
define|#
directive|define
name|VDAT_DELAY
value|0x88
end_define

begin_comment
comment|/* Transit delay */
end_comment

begin_define
define|#
directive|define
name|VDAT_TTR
value|0x8b
end_define

begin_comment
comment|/* Reassignment time */
end_comment

begin_comment
comment|/* for DR TPDUs */
end_comment

begin_define
define|#
directive|define
name|VDAT_ADDITIONAL
value|0xe0
end_define

begin_comment
comment|/* Additional information */
end_comment

begin_comment
comment|/* for AK TPDUs */
end_comment

begin_define
define|#
directive|define
name|VDAT_SUBSEQ
value|0x8c
end_define

begin_comment
comment|/* Sub-sequence number */
end_comment

begin_define
define|#
directive|define
name|VDAT_FLOWCTL
value|0x8b
end_define

begin_comment
comment|/* Flow control confirmation */
end_comment

begin_comment
comment|/* for ER TPDUs */
end_comment

begin_define
define|#
directive|define
name|VDAT_INVALID
value|0xc1
end_define

begin_comment
comment|/* invalid TPDU */
end_comment

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/* TP0 is the protocol */
end_comment

begin_function_decl
name|int
name|tp0init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tp0write
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* TCP is NS-provider */
end_comment

begin_function_decl
name|int
name|tcpopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|tcpsave
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcprestore
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* X.25 is NS-provider */
end_comment

begin_function_decl
name|int
name|x25open
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|x25save
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|x25restore
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Bridge is NS-provider */
end_comment

begin_function_decl
name|int
name|bridgeopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bridgediscrim
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|bridgesave
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bridgerestore
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* TP4 is the protocol and the TS-provider */
end_comment

begin_function_decl
name|int
name|tp4init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tp4open
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|tp4save
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tp4restore
parameter_list|()
function_decl|;
end_function_decl

end_unit

