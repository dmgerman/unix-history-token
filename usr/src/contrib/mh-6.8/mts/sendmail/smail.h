begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* smail.h - definitions for the MH-SendMail/SMTP Interface */
end_comment

begin_define
define|#
directive|define
name|S_MAIL
value|0
end_define

begin_define
define|#
directive|define
name|S_SEND
value|1
end_define

begin_define
define|#
directive|define
name|S_SOML
value|2
end_define

begin_define
define|#
directive|define
name|S_SAML
value|3
end_define

begin_struct
struct|struct
name|smtp
block|{
name|int
name|code
decl_stmt|;
name|int
name|length
decl_stmt|;
name|char
name|text
index|[
name|BUFSIZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|client
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|sm_init
argument_list|()
decl_stmt|,
name|sm_winit
argument_list|()
decl_stmt|,
name|sm_wadr
argument_list|()
decl_stmt|,
name|sm_waend
argument_list|()
decl_stmt|,
name|sm_wtxt
argument_list|()
decl_stmt|,
name|sm_wtend
argument_list|()
decl_stmt|,
name|sm_end
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|rp_string
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/* The remainder of this file is derived from "mmdf.h" */
end_comment

begin_comment
comment|/*  *     Copyright (C) 1979,1980,1981,1982,1983  University of Delaware  *     Used by permission, May, 1984.  */
end_comment

begin_comment
comment|/*  *     MULTI-CHANNEL MEMO DISTRIBUTION FACILITY  (MMDF)  *       *  *     Copyright (C) 1979,1980,1981,1982,1983  University of Delaware  *       *     Department of Electrical Engineering  *     University of Delaware  *     Newark, Delaware  19711  *  *     Phone:  (302) 738-1163  *       *       *     This program module was developed as part of the University  *     of Delaware's Multi-Channel Memo Distribution Facility (MMDF).  *       *     Acquisition, use, and distribution of this module and its listings  *     are subject restricted to the terms of a license agreement.  *     Documents describing systems using this module must cite its source.  *  *     The above statements must be retained with all copies of this  *     program and may not be removed without the consent of the  *     University of Delaware.  *       */
end_comment

begin_comment
comment|/*                      Reply Codes for MMDF  *  *  Based on: "Revised FTP Reply Codes", by Jon Postel& Nancy Neigus Arpanet  *      RFC 640 / NIC 30843, in the "Arpanet Protocol Handbook", E.  Feinler  *      and J. Postel (eds.), NIC 7104, Network Information Center, SRI  *      International:  Menlo Park, CA.  (NTIS AD-A0038901)  *  *  Actual values are different, but scheme is same.  Codes must fit into  *  8-bits (to pass on exit() calls); fields are packed 2-3-3 and interpreted  *  as octal numbers.  *  *  Basic format:  *  *      0yz: positive completion; entire action done  *      1yz: positive intermediate; only part done  *      2yz: Transient negative completion; may work later  *      3yz: Permanent negative completion; you lose forever  *  *      x0z: syntax  *      x1z: general; doesn't fit any other category  *      x2z: connections; truly transfer-related  *      x3z: user/authentication/account  *      x4x: mail  *      x5z: file system  *  *      3-bit z field is unique to the reply.  In the following,  *      the RP_xVAL defines are available for masking to obtain a field.  */
end_comment

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/***************  FIELD DEFINITIONS& BASIC VALUES  ******************* */
end_comment

begin_comment
comment|/*          Field 1:  Basic degree of success (2-bits)                  */
end_comment

begin_define
define|#
directive|define
name|RP_BTYP
value|'\200'
end_define

begin_comment
comment|/* good vs. bad; on => bad		*/
end_comment

begin_define
define|#
directive|define
name|RP_BVAL
value|'\300'
end_define

begin_comment
comment|/* basic degree of success		*/
end_comment

begin_define
define|#
directive|define
name|RP_BOK
value|'\000'
end_define

begin_comment
comment|/* went fine; all done                */
end_comment

begin_define
define|#
directive|define
name|RP_BPOK
value|'\100'
end_define

begin_comment
comment|/* only the first part got done       */
end_comment

begin_define
define|#
directive|define
name|RP_BTNO
value|'\200'
end_define

begin_comment
comment|/* temporary failure; try later       */
end_comment

begin_define
define|#
directive|define
name|RP_BNO
value|'\300'
end_define

begin_comment
comment|/* not now, nor never; you lose       */
end_comment

begin_comment
comment|/*          Field 2:  Basic domain of discourse (3-bits)                */
end_comment

begin_define
define|#
directive|define
name|RP_CVAL
value|'\070'
end_define

begin_comment
comment|/* basic category (domain) of reply   */
end_comment

begin_define
define|#
directive|define
name|RP_CSYN
value|'\000'
end_define

begin_comment
comment|/* purely a matter of form            */
end_comment

begin_define
define|#
directive|define
name|RP_CGEN
value|'\010'
end_define

begin_comment
comment|/* couldn't find anywhere else for it */
end_comment

begin_define
define|#
directive|define
name|RP_CCON
value|'\020'
end_define

begin_comment
comment|/* data-transfer-related issue        */
end_comment

begin_define
define|#
directive|define
name|RP_CUSR
value|'\030'
end_define

begin_comment
comment|/* pertaining to the user             */
end_comment

begin_define
define|#
directive|define
name|RP_CMAI
value|'\040'
end_define

begin_comment
comment|/* specific to mail semantics         */
end_comment

begin_define
define|#
directive|define
name|RP_CFIL
value|'\050'
end_define

begin_comment
comment|/* file system                        */
end_comment

begin_define
define|#
directive|define
name|RP_CLIO
value|'\060'
end_define

begin_comment
comment|/* local i/o system                   */
end_comment

begin_comment
comment|/*          Field 3:  Specific value for this reply (3-bits)            */
end_comment

begin_define
define|#
directive|define
name|RP_SVAL
value|'\007'
end_define

begin_comment
comment|/* specific value of reply            */
end_comment

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/*********************  SPECIFIC SUCCESS VALUES  ********************** */
end_comment

begin_comment
comment|/*                        Complete Success                              */
end_comment

begin_define
define|#
directive|define
name|RP_DONE
value|(RP_BOK | RP_CGEN | '\000')
end_define

begin_comment
comment|/* done (e.g., w/transaction)         */
end_comment

begin_define
define|#
directive|define
name|RP_OK
value|(RP_BOK | RP_CGEN | '\001')
end_define

begin_comment
comment|/* general-purpose OK                 */
end_comment

begin_define
define|#
directive|define
name|RP_MOK
value|(RP_BOK | RP_CMAI | '\000')
end_define

begin_comment
comment|/* message is accepted (w/text)       */
end_comment

begin_comment
comment|/*                        Partial Success                               */
end_comment

begin_define
define|#
directive|define
name|RP_MAST
value|(RP_BPOK| RP_CGEN | '\000')
end_define

begin_comment
comment|/* you are the requestor              */
end_comment

begin_define
define|#
directive|define
name|RP_SLAV
value|(RP_BPOK| RP_CGEN | '\001')
end_define

begin_comment
comment|/* you are the requestee              */
end_comment

begin_define
define|#
directive|define
name|RP_AOK
value|(RP_BPOK| RP_CMAI | '\000')
end_define

begin_comment
comment|/* message address is accepted        */
end_comment

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/* ********************  SPECIFIC FALURE VALUES  ********************** */
end_comment

begin_comment
comment|/*                        Partial Failure                               */
end_comment

begin_define
define|#
directive|define
name|RP_AGN
value|(RP_BTNO | RP_CGEN | '\000')
end_define

begin_comment
comment|/* not now; maybe later               */
end_comment

begin_define
define|#
directive|define
name|RP_TIME
value|(RP_BTNO | RP_CGEN | '\001')
end_define

begin_comment
comment|/* timeout                            */
end_comment

begin_define
define|#
directive|define
name|RP_NOOP
value|(RP_BTNO | RP_CGEN | '\002')
end_define

begin_comment
comment|/* no-op; nothing done, this time     */
end_comment

begin_define
define|#
directive|define
name|RP_EOF
value|(RP_BTNO | RP_CGEN | '\003')
end_define

begin_comment
comment|/* encountered an end of file         */
end_comment

begin_define
define|#
directive|define
name|RP_NET
value|(RP_BTNO | RP_CCON | '\000')
end_define

begin_comment
comment|/* channel went bad                   */
end_comment

begin_define
define|#
directive|define
name|RP_BHST
value|(RP_BTNO | RP_CCON | '\001')
end_define

begin_comment
comment|/* foreign host screwed up            */
end_comment

begin_define
define|#
directive|define
name|RP_DHST
value|(RP_BTNO | RP_CCON | '\002')
end_define

begin_comment
comment|/* host went away                     */
end_comment

begin_define
define|#
directive|define
name|RP_NIO
value|(RP_BTNO | RP_CCON | '\004')
end_define

begin_comment
comment|/* general net i/o problem            */
end_comment

begin_define
define|#
directive|define
name|RP_FIO
value|(RP_BTNO | RP_CFIL | '\000')
end_define

begin_comment
comment|/* error reading/writing file         */
end_comment

begin_define
define|#
directive|define
name|RP_FCRT
value|(RP_BTNO | RP_CFIL | '\001')
end_define

begin_comment
comment|/* unable to create file              */
end_comment

begin_define
define|#
directive|define
name|RP_FOPN
value|(RP_BTNO | RP_CFIL | '\002')
end_define

begin_comment
comment|/* unable to open file                */
end_comment

begin_define
define|#
directive|define
name|RP_LIO
value|(RP_BTNO | RP_CLIO | '\000')
end_define

begin_comment
comment|/* general local i/o problem          */
end_comment

begin_define
define|#
directive|define
name|RP_LOCK
value|(RP_BTNO | RP_CLIO | '\001')
end_define

begin_comment
comment|/* resource currently locked          */
end_comment

begin_comment
comment|/*                       Complete Failure                               */
end_comment

begin_define
define|#
directive|define
name|RP_MECH
value|(RP_BNO | RP_CGEN | '\000')
end_define

begin_comment
comment|/* bad mechanism/path; try alternate? */
end_comment

begin_define
define|#
directive|define
name|RP_NO
value|(RP_BNO | RP_CGEN | '\001')
end_define

begin_comment
comment|/* general-purpose NO                 */
end_comment

begin_define
define|#
directive|define
name|RP_PROT
value|(RP_BNO | RP_CCON | '\000')
end_define

begin_comment
comment|/* general prototocol error           */
end_comment

begin_define
define|#
directive|define
name|RP_RPLY
value|(RP_BNO | RP_CCON | '\001')
end_define

begin_comment
comment|/* bad reply code (PERMANENT ERROR)   */
end_comment

begin_define
define|#
directive|define
name|RP_NDEL
value|(RP_BNO | RP_CMAI | '\000')
end_define

begin_comment
comment|/* couldn't deliver                   */
end_comment

begin_define
define|#
directive|define
name|RP_HUH
value|(RP_BNO | RP_CSYN | '\000')
end_define

begin_comment
comment|/* couldn't parse the request         */
end_comment

begin_define
define|#
directive|define
name|RP_NCMD
value|(RP_BNO | RP_CSYN | '\001')
end_define

begin_comment
comment|/* no such command defined            */
end_comment

begin_define
define|#
directive|define
name|RP_PARM
value|(RP_BNO | RP_CSYN | '\002')
end_define

begin_comment
comment|/* bad parameter                      */
end_comment

begin_define
define|#
directive|define
name|RP_UCMD
value|(RP_BNO | RP_CSYN | '\003')
end_define

begin_comment
comment|/* command not implemented            */
end_comment

begin_define
define|#
directive|define
name|RP_USER
value|(RP_BNO | RP_CUSR | '\000')
end_define

begin_comment
comment|/* unknown user                       */
end_comment

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/*              PSEUDO-FUNCTIONS TO ACCESS REPLY INFO                   */
end_comment

begin_define
define|#
directive|define
name|rp_gval
parameter_list|(
name|val
parameter_list|)
value|((char) (val))
end_define

begin_comment
comment|/* get the entire return value        */
end_comment

begin_comment
comment|/*  The next three give the field's bits, within the whole value        */
end_comment

begin_define
define|#
directive|define
name|rp_gbval
parameter_list|(
name|val
parameter_list|)
value|(rp_gval (val)& RP_BVAL)
end_define

begin_comment
comment|/* get the basic part of return value */
end_comment

begin_define
define|#
directive|define
name|rp_gcval
parameter_list|(
name|val
parameter_list|)
value|(rp_gval (val)& RP_CVAL)
end_define

begin_comment
comment|/* get the domain part of value       */
end_comment

begin_define
define|#
directive|define
name|rp_gsval
parameter_list|(
name|val
parameter_list|)
value|(rp_gval (val)& RP_SVAL)
end_define

begin_comment
comment|/* get the specific part of value     */
end_comment

begin_comment
comment|/*  The next three give the numeric value withing the field             */
end_comment

begin_define
define|#
directive|define
name|rp_gbbit
parameter_list|(
name|val
parameter_list|)
value|((rp_gval (val)>> 6)& 03)
end_define

begin_comment
comment|/* get the basic part right-shifted   */
end_comment

begin_define
define|#
directive|define
name|rp_gcbit
parameter_list|(
name|val
parameter_list|)
value|((rp_gval (val)>> 3 )& 07)
end_define

begin_comment
comment|/* get the domain part right-shifted  */
end_comment

begin_define
define|#
directive|define
name|rp_gsbit
parameter_list|(
name|val
parameter_list|)
value|(rp_gval (val)& 07)
end_define

begin_comment
comment|/* get the specific part right-shifted */
end_comment

begin_comment
comment|/* MACHINE DEPENDENCY:  The following treat the value as strictly numeric.  *                      It relies on the negative values being numerically  *                      negative.  */
end_comment

begin_define
define|#
directive|define
name|rp_isgood
parameter_list|(
name|val
parameter_list|)
value|(rp_gval (val)>= 0)
end_define

begin_comment
comment|/* is return value positive?          */
end_comment

begin_define
define|#
directive|define
name|rp_isbad
parameter_list|(
name|val
parameter_list|)
value|(rp_gval (val)< 0)
end_define

begin_comment
comment|/* is return value negative?          */
end_comment

end_unit

