begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)nhpibreg.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_include
include|#
directive|include
file|<hp/dev/iotypes.h>
end_include

begin_comment
comment|/* XXX */
end_comment

begin_struct
struct|struct
name|nhpibdevice
block|{
name|u_char
name|hpib_pad0
decl_stmt|;
name|vu_char
name|hpib_cid
decl_stmt|;
name|u_char
name|hpib_pad1
decl_stmt|;
define|#
directive|define
name|hpib_ie
value|hpib_ids
name|vu_char
name|hpib_ids
decl_stmt|;
name|u_char
name|hpib_pad2
decl_stmt|;
name|vu_char
name|hpib_csa
decl_stmt|;
name|u_char
name|hpib_pad3
index|[
literal|11
index|]
decl_stmt|;
define|#
directive|define
name|hpib_mim
value|hpib_mis
name|vu_char
name|hpib_mis
decl_stmt|;
name|u_char
name|hpib_pad4
decl_stmt|;
define|#
directive|define
name|hpib_lim
value|hpib_lis
name|vu_char
name|hpib_lis
decl_stmt|;
name|u_char
name|hpib_pad5
decl_stmt|;
name|vu_char
name|hpib_is
decl_stmt|;
name|u_char
name|hpib_pad6
decl_stmt|;
define|#
directive|define
name|hpib_acr
value|hpib_cls
name|vu_char
name|hpib_cls
decl_stmt|;
name|u_char
name|hpib_pad7
decl_stmt|;
name|vu_char
name|hpib_ar
decl_stmt|;
name|u_char
name|hpib_pad8
decl_stmt|;
name|vu_char
name|hpib_sprb
decl_stmt|;
name|u_char
name|hpib_pad9
decl_stmt|;
define|#
directive|define
name|hpib_ppr
value|hpib_cpt
name|vu_char
name|hpib_cpt
decl_stmt|;
name|u_char
name|hpib_pad10
decl_stmt|;
name|vu_char
name|hpib_data
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LIS_SRQ
value|0x02
end_define

begin_define
define|#
directive|define
name|LIS_ERR
value|0x40
end_define

begin_define
define|#
directive|define
name|MIS_END
value|0x08
end_define

begin_define
define|#
directive|define
name|MIS_BO
value|0x10
end_define

begin_define
define|#
directive|define
name|MIS_BI
value|0x20
end_define

begin_define
define|#
directive|define
name|IS_TADS
value|0x02
end_define

begin_define
define|#
directive|define
name|IS_LADS
value|0x04
end_define

begin_define
define|#
directive|define
name|AUX_CSWRST
value|0
end_define

begin_define
define|#
directive|define
name|AUX_RHDF
value|2
end_define

begin_define
define|#
directive|define
name|AUX_CHDFA
value|3
end_define

begin_define
define|#
directive|define
name|AUX_CHDFE
value|4
end_define

begin_define
define|#
directive|define
name|AUX_EOI
value|8
end_define

begin_define
define|#
directive|define
name|AUX_GTS
value|11
end_define

begin_define
define|#
directive|define
name|AUX_TCA
value|12
end_define

begin_define
define|#
directive|define
name|AUX_TCS
value|13
end_define

begin_define
define|#
directive|define
name|AUX_CPP
value|14
end_define

begin_define
define|#
directive|define
name|AUX_CSIC
value|15
end_define

begin_define
define|#
directive|define
name|AUX_CSRE
value|16
end_define

begin_define
define|#
directive|define
name|AUX_CDAI
value|19
end_define

begin_define
define|#
directive|define
name|AUX_CSHDW
value|22
end_define

begin_define
define|#
directive|define
name|AUX_SSWRST
value|128
end_define

begin_define
define|#
directive|define
name|AUX_SHDFE
value|132
end_define

begin_define
define|#
directive|define
name|AUX_SLON
value|137
end_define

begin_define
define|#
directive|define
name|AUX_STON
value|138
end_define

begin_define
define|#
directive|define
name|AUX_SPP
value|142
end_define

begin_define
define|#
directive|define
name|AUX_SSIC
value|143
end_define

begin_define
define|#
directive|define
name|AUX_SSRE
value|144
end_define

begin_define
define|#
directive|define
name|AUX_SSTD1
value|149
end_define

begin_define
define|#
directive|define
name|AUX_SVSTD1
value|151
end_define

end_unit

