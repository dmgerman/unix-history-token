begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 2000 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	i4b_q932fac.h - Q932 facility handling header file  *	--------------------------------------------------  *  *	$Id: i4b_q932fac.h,v 1.8 2000/04/27 09:25:22 hm Exp $   *  * $FreeBSD$  *  *      last edit-date: [Thu Apr 27 11:07:52 2000]  *  *---------------------------------------------------------------------------  *  *	- Q.932 (03/93) Generic Procedures for the Control of  *		ISDN Supplementaty Services  *	- Q.950 (03/93) Supplementary Services Protocols, Structure and  *		General Principles  *	- ETS 300 179 (10/92) Advice Of Charge: charging information during  *		the call (AOC-D) supplementary service Service description  *	- ETS 300 180 (10/92) Advice Of Charge: charging information at the  *		end of call (AOC-E) supplementary service Service description  *	- ETS 300 181 (04/93) Advice Of Charge (AOC) supplementary service  *		Functional capabilities and information flows  *	- ETS 300 182 (04/93) Advice Of Charge (AOC) supplementary service  *		Digital Subscriber Signalling System No. one (DSS1) protocol  *	- X.208 Specification of Abstract Syntax Notation One (ASN.1)  *	- X.209 Specification of Basic Encoding Rules for  *		Abstract Syntax Notation One (ASN.1)   *	- "ASN.1 Abstract Syntax Notation One", Walter Gora, DATACOM-Verlag  *		1992, 3rd Edition (ISBN 3-89238-062-7) (german !)  *  *---------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* protocols */
end_comment

begin_define
define|#
directive|define
name|FAC_PROTO_ROP
value|0x11
end_define

begin_define
define|#
directive|define
name|FAC_PROTO_CMIP
value|0x12
end_define

begin_define
define|#
directive|define
name|FAC_PROTO_ACSE
value|0x13
end_define

begin_comment
comment|/* tag classes */
end_comment

begin_define
define|#
directive|define
name|FAC_TAGCLASS_UNI
value|0x00
end_define

begin_define
define|#
directive|define
name|FAC_TAGCLASS_APW
value|0x01
end_define

begin_define
define|#
directive|define
name|FAC_TAGCLASS_COS
value|0x02
end_define

begin_define
define|#
directive|define
name|FAC_TAGCLASS_PRU
value|0x03
end_define

begin_comment
comment|/* tag forms */
end_comment

begin_define
define|#
directive|define
name|FAC_TAGFORM_PRI
value|0x00
end_define

begin_define
define|#
directive|define
name|FAC_TAGFORM_CON
value|0x01
end_define

begin_comment
comment|/* class UNIVERSAL values */
end_comment

begin_define
define|#
directive|define
name|FAC_CODEUNI_BOOL
value|1
end_define

begin_define
define|#
directive|define
name|FAC_CODEUNI_INT
value|2
end_define

begin_define
define|#
directive|define
name|FAC_CODEUNI_BITS
value|3
end_define

begin_define
define|#
directive|define
name|FAC_CODEUNI_OCTS
value|4
end_define

begin_define
define|#
directive|define
name|FAC_CODEUNI_NULL
value|5
end_define

begin_define
define|#
directive|define
name|FAC_CODEUNI_OBJI
value|6
end_define

begin_define
define|#
directive|define
name|FAC_CODEUNI_OBJD
value|7
end_define

begin_define
define|#
directive|define
name|FAC_CODEUNI_EXT
value|8
end_define

begin_define
define|#
directive|define
name|FAC_CODEUNI_REAL
value|9
end_define

begin_define
define|#
directive|define
name|FAC_CODEUNI_ENUM
value|10
end_define

begin_define
define|#
directive|define
name|FAC_CODEUNI_R11
value|11
end_define

begin_define
define|#
directive|define
name|FAC_CODEUNI_R12
value|12
end_define

begin_define
define|#
directive|define
name|FAC_CODEUNI_R13
value|13
end_define

begin_define
define|#
directive|define
name|FAC_CODEUNI_R14
value|14
end_define

begin_define
define|#
directive|define
name|FAC_CODEUNI_R15
value|15
end_define

begin_define
define|#
directive|define
name|FAC_CODEUNI_SEQ
value|16
end_define

begin_define
define|#
directive|define
name|FAC_CODEUNI_SET
value|17
end_define

begin_define
define|#
directive|define
name|FAC_CODEUNI_NSTR
value|18
end_define

begin_define
define|#
directive|define
name|FAC_CODEUNI_PSTR
value|19
end_define

begin_define
define|#
directive|define
name|FAC_CODEUNI_TSTR
value|20
end_define

begin_define
define|#
directive|define
name|FAC_CODEUNI_VSTR
value|21
end_define

begin_define
define|#
directive|define
name|FAC_CODEUNI_ISTR
value|22
end_define

begin_define
define|#
directive|define
name|FAC_CODEUNI_UTIME
value|23
end_define

begin_define
define|#
directive|define
name|FAC_CODEUNI_GTIME
value|24
end_define

begin_define
define|#
directive|define
name|FAC_CODEUNI_GSTR
value|25
end_define

begin_define
define|#
directive|define
name|FAC_CODEUNI_VISTR
value|26
end_define

begin_define
define|#
directive|define
name|FAC_CODEUNI_GNSTR
value|27
end_define

begin_comment
comment|/* operation values */
end_comment

begin_define
define|#
directive|define
name|FAC_OPVAL_UUS
value|1
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_CUG
value|2
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_MCID
value|3
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_BTPY
value|4
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_ETPY
value|5
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_ECT
value|6
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_DIV_ACT
value|7
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_DIV_DEACT
value|8
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_DIV_ACTSN
value|9
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_DIV_DEACTSN
value|10
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_DIV_INTER
value|11
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_DIV_INFO
value|12
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_DIV_CALLDEF
value|13
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_DIV_CALLRER
value|14
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_DIV_LINF2
value|15
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_DIV_INVS
value|16
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_DIV_INTER1
value|17
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_DIV_LINF1
value|18
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_DIV_LINF3
value|19
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_ER_CRCO
value|20
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_ER_MGMT
value|21
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_ER_CANC
value|22
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_MLPP_QUERY
value|24
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_MLPP_CALLR
value|25
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_MLPP_CALLP
value|26
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_AOC_REQ
value|30
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_AOC_S_CUR
value|31
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_AOC_S_SPC
value|32
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_AOC_D_CUR
value|33
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_AOC_D_UNIT
value|34
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_AOC_E_CUR
value|35
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_AOC_E_UNIT
value|36
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_AOC_IDOFCRG
value|37
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_CONF_BEG
value|40
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_CONF_ADD
value|41
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_CONF_SPLIT
value|42
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_CONF_DROP
value|43
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_CONF_ISOLATE
value|44
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_CONF_REATT
value|45
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_CONF_PDISC
value|46
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_CONF_FCONF
value|47
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_CONF_END
value|48
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_CONF_IDCFE
value|49
end_define

begin_define
define|#
directive|define
name|FAC_OPVAL_REVC_REQ
value|60
end_define

begin_enum
enum|enum
name|states
block|{
name|ST_EXP_COMP_TYP
block|,
name|ST_EXP_INV_ID
block|,
name|ST_EXP_OP_VAL
block|,
name|ST_EXP_INFO
block|,
name|ST_EXP_RUL
block|,
name|ST_EXP_RU
block|,
name|ST_EXP_RNOU
block|,
name|ST_EXP_TOCI
block|,
name|ST_EXP_DBID
block|,
name|ST_EXP_NIX
block|}
enum|;
end_enum

begin_comment
comment|/* EOF */
end_comment

end_unit

