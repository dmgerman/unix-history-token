begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * /src/NTP/ntp4-dev/include/ascii.h,v 4.4 2005/04/16 17:32:10 kardel RELEASE_20050508_A  *  * ascii.h,v 4.4 2005/04/16 17:32:10 kardel RELEASE_20050508_A  *  * $Created: Sun Jul 20 11:42:53 1997 $  *  * Copyright (c) 1997-2005 by Frank Kardel<kardel<AT> ntp.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASCII_H
end_ifndef

begin_define
define|#
directive|define
name|ASCII_H
end_define

begin_comment
comment|/*  * just name the common ASCII control codes  */
end_comment

begin_define
define|#
directive|define
name|NUL
value|0
end_define

begin_define
define|#
directive|define
name|SOH
value|1
end_define

begin_define
define|#
directive|define
name|STX
value|2
end_define

begin_define
define|#
directive|define
name|ETX
value|3
end_define

begin_define
define|#
directive|define
name|EOT
value|4
end_define

begin_define
define|#
directive|define
name|ENQ
value|5
end_define

begin_define
define|#
directive|define
name|ACK
value|6
end_define

begin_define
define|#
directive|define
name|BEL
value|7
end_define

begin_define
define|#
directive|define
name|BS
value|8
end_define

begin_define
define|#
directive|define
name|HT
value|9
end_define

begin_define
define|#
directive|define
name|NL
value|10
end_define

begin_define
define|#
directive|define
name|VT
value|11
end_define

begin_define
define|#
directive|define
name|NP
value|12
end_define

begin_define
define|#
directive|define
name|CR
value|13
end_define

begin_define
define|#
directive|define
name|SO
value|14
end_define

begin_define
define|#
directive|define
name|SI
value|15
end_define

begin_define
define|#
directive|define
name|DLE
value|16
end_define

begin_define
define|#
directive|define
name|DC1
value|17
end_define

begin_define
define|#
directive|define
name|DC2
value|18
end_define

begin_define
define|#
directive|define
name|DC3
value|19
end_define

begin_define
define|#
directive|define
name|DC4
value|20
end_define

begin_define
define|#
directive|define
name|NAK
value|21
end_define

begin_define
define|#
directive|define
name|SYN
value|22
end_define

begin_define
define|#
directive|define
name|ETB
value|23
end_define

begin_define
define|#
directive|define
name|CAN
value|24
end_define

begin_define
define|#
directive|define
name|EM
value|25
end_define

begin_define
define|#
directive|define
name|SUB
value|26
end_define

begin_define
define|#
directive|define
name|ESC
value|27
end_define

begin_define
define|#
directive|define
name|FS
value|28
end_define

begin_define
define|#
directive|define
name|GS
value|29
end_define

begin_define
define|#
directive|define
name|RS
value|30
end_define

begin_define
define|#
directive|define
name|US
value|31
end_define

begin_define
define|#
directive|define
name|SP
value|32
end_define

begin_define
define|#
directive|define
name|DEL
value|127
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * History:  *  * ascii.h,v  * Revision 4.4  2005/04/16 17:32:10  kardel  * update copyright  *  * Revision 4.3  2004/11/14 15:29:41  kardel  * support PPSAPI, upgrade Copyright to Berkeley style  *  * Revision 4.1  1998/07/11 10:05:22  kardel  * Release 4.0.73d reconcilation  *  * Revision 4.0  1998/04/10 19:50:38  kardel  * Start 4.0 release version numbering  *  * Revision 4.0  1998/04/10 19:50:38  kardel  * Start 4.0 release version numbering  *  */
end_comment

end_unit

