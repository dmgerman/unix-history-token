begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 Yen Yen Lim and North Dakota State University  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Yen Yen Lim and         North Dakota State University  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * @(#) $Header: /tcpdump/master/libpcap/sunatmpos.h,v 1.1 2002/07/11 09:06:47 guy Exp $ (LBL)  */
end_comment

begin_comment
comment|/* SunATM header for ATM packet */
end_comment

begin_define
define|#
directive|define
name|SUNATM_DIR_POS
value|0
end_define

begin_define
define|#
directive|define
name|SUNATM_VPI_POS
value|1
end_define

begin_define
define|#
directive|define
name|SUNATM_VCI_POS
value|2
end_define

begin_define
define|#
directive|define
name|SUNATM_PKT_BEGIN_POS
value|4
end_define

begin_comment
comment|/* Start of ATM packet */
end_comment

begin_comment
comment|/* Protocol type values in the bottom for bits of the byte at SUNATM_DIR_POS. */
end_comment

begin_define
define|#
directive|define
name|PT_LANE
value|0x01
end_define

begin_comment
comment|/* LANE */
end_comment

begin_define
define|#
directive|define
name|PT_LLC
value|0x02
end_define

begin_comment
comment|/* LLC encapsulation */
end_comment

begin_define
define|#
directive|define
name|PT_ILMI
value|0x05
end_define

begin_comment
comment|/* ILMI */
end_comment

begin_define
define|#
directive|define
name|PT_QSAAL
value|0x06
end_define

begin_comment
comment|/* Q.SAAL */
end_comment

end_unit

