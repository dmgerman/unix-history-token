begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)pmreg.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_comment
comment|/*  * Defines for the graphics hardware.  */
end_comment

begin_comment
comment|/*  * Structure to descripte the programmable cursor chip (DC503) from DEC.  */
end_comment

begin_typedef
typedef|typedef
specifier|volatile
struct|struct
name|PCCRegs
block|{
name|u_short
name|cmdr
decl_stmt|;
comment|/* cursor command register */
name|short
name|pad1
decl_stmt|;
name|u_short
name|xpos
decl_stmt|;
comment|/* cursor X position */
name|short
name|pad2
decl_stmt|;
name|u_short
name|ypos
decl_stmt|;
comment|/* cursor Y position */
name|short
name|pad3
decl_stmt|;
name|u_short
name|xmin1
decl_stmt|;
comment|/* region 1 left edge */
name|short
name|pad4
decl_stmt|;
name|u_short
name|xmax1
decl_stmt|;
comment|/* region 1 right edge */
name|short
name|pad5
decl_stmt|;
name|u_short
name|ymin1
decl_stmt|;
comment|/* region 1 top edge */
name|short
name|pad6
decl_stmt|;
name|u_short
name|ymax1
decl_stmt|;
comment|/* region 1 bottom edge */
name|short
name|pad7
index|[
literal|9
index|]
decl_stmt|;
name|u_short
name|xmin2
decl_stmt|;
comment|/* region 2 left edge */
name|short
name|pad8
decl_stmt|;
name|u_short
name|xmax2
decl_stmt|;
comment|/* region 2 right edge */
name|short
name|pad9
decl_stmt|;
name|u_short
name|ymin2
decl_stmt|;
comment|/* region 2 top edge */
name|short
name|pad10
decl_stmt|;
name|u_short
name|ymax2
decl_stmt|;
comment|/* region 2 bottom edge */
name|short
name|pad11
decl_stmt|;
name|u_short
name|memory
decl_stmt|;
comment|/* cursor sprite pattern load */
block|}
name|PCCRegs
typedef|;
end_typedef

begin_comment
comment|/* define bits in pcc_cmdr */
end_comment

begin_define
define|#
directive|define
name|PCC_TEST
value|0x8000
end_define

begin_define
define|#
directive|define
name|PCC_HSHI
value|0x4000
end_define

begin_define
define|#
directive|define
name|PCC_VBHI
value|0x2000
end_define

begin_define
define|#
directive|define
name|PCC_LODSA
value|0x1000
end_define

begin_define
define|#
directive|define
name|PCC_FORG2
value|0x0800
end_define

begin_define
define|#
directive|define
name|PCC_ENRG2
value|0x0400
end_define

begin_define
define|#
directive|define
name|PCC_FORG1
value|0x0200
end_define

begin_define
define|#
directive|define
name|PCC_ENRG1
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCC_XHWID
value|0x0080
end_define

begin_define
define|#
directive|define
name|PCC_XHCL1
value|0x0040
end_define

begin_define
define|#
directive|define
name|PCC_XHCLP
value|0x0020
end_define

begin_define
define|#
directive|define
name|PCC_XHAIR
value|0x0010
end_define

begin_define
define|#
directive|define
name|PCC_FOPB
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCC_ENPB
value|0x0004
end_define

begin_define
define|#
directive|define
name|PCC_FOPA
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCC_ENPA
value|0x0001
end_define

begin_comment
comment|/* offset for cursor X& Y locations */
end_comment

begin_define
define|#
directive|define
name|PCC_X_OFFSET
value|212
end_define

begin_define
define|#
directive|define
name|PCC_Y_OFFSET
value|34
end_define

begin_typedef
typedef|typedef
specifier|volatile
struct|struct
name|VDACRegs
block|{
name|u_char
name|mapWA
decl_stmt|;
comment|/* address register (color map write) */
name|char
name|pad1
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|map
decl_stmt|;
comment|/* color map */
name|char
name|pad2
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|mask
decl_stmt|;
comment|/* pixel read mask */
name|char
name|pad3
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|mapRA
decl_stmt|;
comment|/* address register (color map read) */
name|char
name|pad4
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|overWA
decl_stmt|;
comment|/* address register (overlay map write) */
name|char
name|pad5
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|over
decl_stmt|;
comment|/* overlay map */
name|char
name|pad6
index|[
literal|7
index|]
decl_stmt|;
name|u_char
name|overRA
decl_stmt|;
comment|/* address register (overlay map read) */
block|}
name|VDACRegs
typedef|;
end_typedef

end_unit

