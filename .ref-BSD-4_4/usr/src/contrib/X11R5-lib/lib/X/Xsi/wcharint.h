begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: wcharint.h,v 1.12 92/09/10 17:09:53 rws Exp $  */
end_comment

begin_comment
comment|/*  * Copyright 1990, 1991 by OMRON Corporation, NTT Software Corporation,  *                      and Nippon Telegraph and Telephone Corporation  * Copyright 1991 by the Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the names of OMRON, NTT Software, NTT, and M.I.T.  * not be used in advertising or publicity pertaining to distribution of the  * software without specific, written prior permission. OMRON, NTT Software,  * NTT, and M.I.T. make no representations about the suitability of this  * software for any purpose.  It is provided "as is" without express or  * implied warranty.  *  * OMRON, NTT SOFTWARE, NTT, AND M.I.T. DISCLAIM ALL WARRANTIES WITH REGARD  * TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS, IN NO EVENT SHALL OMRON, NTT SOFTWARE, NTT, OR M.I.T. BE  * LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES   * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *   *	Author: Li Yuhong	OMRON Corporation  *     */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MCHARINT_H_
end_ifndef

begin_define
define|#
directive|define
name|_MCHARINT_H_
end_define

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_WCHARXLIB_
end_ifndef

begin_include
include|#
directive|include
file|"wchar.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_WCHAR_
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|wchar
typedef|;
end_typedef

begin_comment
comment|/* must be unsigned 4-byte type, ISO10646 */
end_comment

begin_define
define|#
directive|define
name|_WCHAR_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WNULL
end_ifndef

begin_define
define|#
directive|define
name|WNULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LATIN1_GROUP
value|0x20
end_define

begin_comment
comment|/* Latin 1 Group# */
end_comment

begin_define
define|#
directive|define
name|LATIN1_PLANE
value|0x20
end_define

begin_comment
comment|/* Latin 1 Plane# */
end_comment

begin_define
define|#
directive|define
name|LATIN1_ROW
value|0x20
end_define

begin_comment
comment|/* Latin 1 Row#   */
end_comment

begin_define
define|#
directive|define
name|SCRIPT1
value|0xffffff00
end_define

begin_define
define|#
directive|define
name|SCRIPT2
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|CONTROLSCRIPT
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|LATINSCRIPT
value|0x20202000
end_define

begin_define
define|#
directive|define
name|HIRAGANASCRIPT
value|0x20202f00
end_define

begin_define
define|#
directive|define
name|KATAKANASCRIPT
value|0x20202f80
end_define

begin_define
define|#
directive|define
name|HANZISCRIPT
value|0x20308080
end_define

begin_define
define|#
directive|define
name|KANJISCRIPT
value|0x20408080
end_define

begin_define
define|#
directive|define
name|HANJASCRIPT
value|0x20508080
end_define

begin_define
define|#
directive|define
name|CLPADPADPAD
value|0x00808080
end_define

begin_define
define|#
directive|define
name|WCHARSPACE
value|0x20202020
end_define

begin_define
define|#
directive|define
name|PrivateZone
value|0x20203400
end_define

begin_comment
comment|/* Private Use Zone */
end_comment

begin_define
define|#
directive|define
name|PrivateZoneLast
value|0x20203b00
end_define

begin_comment
comment|/* Last row of Private Use Zone */
end_comment

begin_define
define|#
directive|define
name|PrivatePlane
value|0x20e00000
end_define

begin_comment
comment|/* Private Use Plane */
end_comment

begin_define
define|#
directive|define
name|PrivatePlaneLast
value|0x20ff0000
end_define

begin_comment
comment|/* Last row of Private Use Plane */
end_comment

begin_define
define|#
directive|define
name|PrivatePlaneLastI11
value|(PrivatePlaneLast | 0x8080)
end_define

begin_define
define|#
directive|define
name|PrivatePlaneLastI10
value|(PrivatePlaneLast | 0x8000)
end_define

begin_define
define|#
directive|define
name|wgetgroup
parameter_list|(
name|wc
parameter_list|)
value|((unsigned char)(((wc)>> 24)& 0x000000ff))
end_define

begin_define
define|#
directive|define
name|wgetplane
parameter_list|(
name|wc
parameter_list|)
value|((unsigned char)(((wc)>> 16)& 0x000000ff))
end_define

begin_define
define|#
directive|define
name|wgetrow
parameter_list|(
name|wc
parameter_list|)
value|((unsigned char)(((wc)>>  8)& 0x000000ff))
end_define

begin_define
define|#
directive|define
name|wgetcell
parameter_list|(
name|wc
parameter_list|)
value|((unsigned char)((wc)& 0x000000ff))
end_define

begin_define
define|#
directive|define
name|_Xiswcntrl
parameter_list|(
name|wc
parameter_list|)
value|( ((wc)==WNULL) || \ 			   (((wc)&CONTROLSCRIPT)==CLPADPADPAD \&& iscntrl(wgetgroup(wc)&0x7f)) )
end_define

begin_define
define|#
directive|define
name|_Xatowc
parameter_list|(
name|c
parameter_list|)
value|( ((c)=='\0') ? WNULL: \ 			 (iscntrl((c)&0x7f)) ? (((wchar)(c)<<24)|CLPADPADPAD): \ 						  (LATINSCRIPT|(c)) )
end_define

begin_define
define|#
directive|define
name|_Xwctoa
parameter_list|(
name|wc
parameter_list|)
value|( _Xiswcntrl(wc) ? wgetgroup(wc): \ 			 (((wc)&SCRIPT1)==LATINSCRIPT) ? wgetcell(wc): \ 						(-1) )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MCHARINT_H_ */
end_comment

end_unit

