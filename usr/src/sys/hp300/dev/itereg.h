begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: Utah $Hdr: itereg.h 1.1 90/07/09$  *  *	@(#)itereg.h	7.2 (Berkeley) 11/4/90  */
end_comment

begin_define
define|#
directive|define
name|REGADDR
value|ip->regbase
end_define

begin_define
define|#
directive|define
name|FBBASE
value|((volatile u_char *)ip->fbbase)
end_define

begin_define
define|#
directive|define
name|FONTROM
value|((u_char *)(REGADDR+0x3B))
end_define

begin_define
define|#
directive|define
name|ITEREGS
value|((struct iteregs *)(REGADDR))
end_define

begin_comment
comment|/*  * All of the HP displays use the same font ROM setup. These structures  * are used to get at them.  */
end_comment

begin_struct
struct|struct
name|iteregs
block|{
name|u_short
name|reset
decl_stmt|;
name|u_short
name|interrupt
decl_stmt|;
name|u_char
label|:
literal|8
operator|,
name|fbwidth_h
operator|,
operator|:
literal|8
operator|,
name|fbwidth_l
operator|,
operator|:
literal|8
operator|,
name|fbheight_h
operator|,
operator|:
literal|8
operator|,
name|fbheight_l
operator|,
operator|:
literal|8
operator|,
name|dispwidth_h
operator|,
operator|:
literal|8
operator|,
name|dispwidth_l
operator|,
operator|:
literal|8
operator|,
name|dispheight_h
operator|,
operator|:
literal|8
operator|,
name|dispheight_l
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fontinfo
block|{
name|u_char
name|nfonts
decl_stmt|,
range|:
literal|8
decl_stmt|,
name|fontid
decl_stmt|,
range|:
literal|8
decl_stmt|,
name|haddr
decl_stmt|,
range|:
literal|8
decl_stmt|,
name|laddr
decl_stmt|,
range|:
literal|8
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|font
block|{
name|u_char
name|fh
decl_stmt|,
range|:
literal|8
decl_stmt|,
name|fw
decl_stmt|;
name|u_char
name|pad
index|[
literal|7
index|]
decl_stmt|,
name|data
index|[
literal|256
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|draw_cursor
parameter_list|(
name|ip
parameter_list|)
value|{ \ 	WINDOWMOVER(ip, ip->cblanky, ip->cblankx, \ 		    ip->cury * ip->ftheight, \ 		    ip->curx * ip->ftwidth, \ 		    ip->ftheight, ip->ftwidth, RR_XOR); \         ip->cursorx = ip->curx; \ 	ip->cursory = ip->cury; }
end_define

begin_define
define|#
directive|define
name|erase_cursor
parameter_list|(
name|ip
parameter_list|)
define|\
value|WINDOWMOVER(ip, ip->cblanky, ip->cblankx, \ 		    ip->cursory * ip->ftheight, \ 		    ip->cursorx * ip->ftwidth, \ 		    ip->ftheight, ip->ftwidth, RR_XOR);
end_define

end_unit

