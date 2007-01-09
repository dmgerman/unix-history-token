begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000, 2001 Richard Hodges and Matriplex, inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Matriplex, inc.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  ******************************************************************************  *  * This driver is derived from the Nicstar driver by Mark Tinguely, and  * some of the original driver still exists here.  Those portions are...  *   Copyright (c) 1996, 1997, 1998, 1999 Mark Tinguely  *   All rights reserved.  *  ******************************************************************************  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|IDT_VERSION
value|"IDT 1.101"
end_define

begin_define
define|#
directive|define
name|CBR_VERBOSE
value|1
end_define

begin_comment
comment|/* show CBR time slots */
end_comment

begin_define
define|#
directive|define
name|IDT_MAX_CBRSLOTS
value|2100
end_define

begin_comment
comment|/* no smaller than value assigned to card */
end_comment

begin_define
define|#
directive|define
name|IDT_MAX_CBRQUEUE
value|64
end_define

begin_comment
comment|/* max number of CBR connections: 1k each */
end_comment

begin_comment
comment|/* AAL types */
end_comment

begin_define
define|#
directive|define
name|IDTAAL0
value|0
end_define

begin_define
define|#
directive|define
name|IDTAAL1
value|1
end_define

begin_define
define|#
directive|define
name|IDTAAL3_4
value|3
end_define

begin_define
define|#
directive|define
name|IDTAAL5
value|5
end_define

begin_define
define|#
directive|define
name|NICCBR
value|1
end_define

begin_define
define|#
directive|define
name|NICVBR
value|2
end_define

begin_define
define|#
directive|define
name|NICABR
value|3
end_define

begin_define
define|#
directive|define
name|NICUBR
value|4
end_define

begin_comment
comment|/* NICStAR Operation Registers */
end_comment

begin_define
define|#
directive|define
name|REGCMD
value|0x10
end_define

begin_comment
comment|/* command          w */
end_comment

begin_define
define|#
directive|define
name|REGCFG
value|0x14
end_define

begin_comment
comment|/* configuration  r/w */
end_comment

begin_define
define|#
directive|define
name|REGSTAT
value|0x18
end_define

begin_comment
comment|/* status         r/w */
end_comment

begin_define
define|#
directive|define
name|REGRSQB
value|0x1c
end_define

begin_comment
comment|/* RSQ base         w */
end_comment

begin_define
define|#
directive|define
name|REGRSQT
value|0x20
end_define

begin_comment
comment|/* RSQ tail         r */
end_comment

begin_define
define|#
directive|define
name|REGRSQH
value|0x24
end_define

begin_comment
comment|/* RSQ head         w */
end_comment

begin_define
define|#
directive|define
name|REGCDC
value|0x28
end_define

begin_comment
comment|/* cell drop cnt  r/c */
end_comment

begin_define
define|#
directive|define
name|REGVPEC
value|0x2c
end_define

begin_comment
comment|/* vci/vpi er cnt r/c */
end_comment

begin_define
define|#
directive|define
name|REGICC
value|0x30
end_define

begin_comment
comment|/* invalid cell   r/c */
end_comment

begin_define
define|#
directive|define
name|REGRAWT
value|0x34
end_define

begin_comment
comment|/* raw cell tail    r */
end_comment

begin_define
define|#
directive|define
name|REGTMR
value|0x38
end_define

begin_comment
comment|/* timer            r */
end_comment

begin_define
define|#
directive|define
name|REGTSTB
value|0x3c
end_define

begin_comment
comment|/* TST base       r/w */
end_comment

begin_define
define|#
directive|define
name|REGTSQB
value|0x40
end_define

begin_comment
comment|/* TSQ base         w */
end_comment

begin_define
define|#
directive|define
name|REGTSQT
value|0x44
end_define

begin_comment
comment|/* TSQ tail         r */
end_comment

begin_define
define|#
directive|define
name|REGTSQH
value|0x48
end_define

begin_comment
comment|/* TSQ head         w */
end_comment

begin_define
define|#
directive|define
name|REGGP
value|0x4c
end_define

begin_comment
comment|/* general purp   r/w */
end_comment

begin_define
define|#
directive|define
name|REGVMSK
value|0x50
end_define

begin_comment
comment|/* vci/vpi mask     w */
end_comment

end_unit

