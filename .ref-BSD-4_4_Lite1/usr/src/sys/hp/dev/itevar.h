begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: Utah $Hdr: itevar.h 1.15 92/12/20$  *  *	@(#)itevar.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_define
define|#
directive|define
name|UNIT
parameter_list|(
name|dev
parameter_list|)
value|minor(dev)
end_define

begin_struct
struct|struct
name|itesw
block|{
name|int
name|ite_hwid
decl_stmt|;
comment|/* Hardware id */
name|int
function_decl|(
modifier|*
name|ite_init
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|ite_deinit
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|ite_clear
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|ite_putc
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|ite_cursor
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|ite_scroll
function_decl|)
parameter_list|()
function_decl|;
name|u_char
function_decl|(
modifier|*
name|ite_readbyte
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|ite_writeglyph
function_decl|)
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|getbyte
parameter_list|(
name|ip
parameter_list|,
name|offset
parameter_list|)
define|\
value|((*(ip)->isw->ite_readbyte)(ip, offset))
end_define

begin_define
define|#
directive|define
name|getword
parameter_list|(
name|ip
parameter_list|,
name|offset
parameter_list|)
define|\
value|((getbyte(ip, offset)<< 8) | getbyte(ip, (offset) + 2))
end_define

begin_define
define|#
directive|define
name|writeglyph
parameter_list|(
name|ip
parameter_list|,
name|offset
parameter_list|,
name|fontbuf
parameter_list|)
define|\
value|((*(ip)->isw->ite_writeglyph)((ip), (offset), (fontbuf)))
end_define

begin_struct
struct|struct
name|ite_softc
block|{
name|int
name|flags
decl_stmt|;
name|struct
name|itesw
modifier|*
name|isw
decl_stmt|;
name|struct
name|grf_softc
modifier|*
name|grf
decl_stmt|;
name|caddr_t
name|regbase
decl_stmt|,
name|fbbase
decl_stmt|;
name|short
name|curx
decl_stmt|,
name|cury
decl_stmt|;
name|short
name|cursorx
decl_stmt|,
name|cursory
decl_stmt|;
name|short
name|cblankx
decl_stmt|,
name|cblanky
decl_stmt|;
name|short
name|rows
decl_stmt|,
name|cols
decl_stmt|;
name|short
name|cpl
decl_stmt|;
name|short
name|dheight
decl_stmt|,
name|dwidth
decl_stmt|;
name|short
name|fbheight
decl_stmt|,
name|fbwidth
decl_stmt|;
name|short
name|ftheight
decl_stmt|,
name|ftwidth
decl_stmt|;
name|short
name|fontx
decl_stmt|,
name|fonty
decl_stmt|;
name|short
name|attribute
decl_stmt|;
name|u_char
modifier|*
name|attrbuf
decl_stmt|;
name|short
name|planemask
decl_stmt|;
name|short
name|pos
decl_stmt|;
name|char
name|imode
decl_stmt|,
name|escape
decl_stmt|,
name|fpd
decl_stmt|,
name|hold
decl_stmt|;
name|caddr_t
name|devdata
decl_stmt|;
comment|/* display dependent data */
block|}
struct|;
end_struct

begin_comment
comment|/* Flags */
end_comment

begin_define
define|#
directive|define
name|ITE_ALIVE
value|0x01
end_define

begin_comment
comment|/* hardware exists */
end_comment

begin_define
define|#
directive|define
name|ITE_INITED
value|0x02
end_define

begin_comment
comment|/* device has been initialized */
end_comment

begin_define
define|#
directive|define
name|ITE_CONSOLE
value|0x04
end_define

begin_comment
comment|/* device can be console */
end_comment

begin_define
define|#
directive|define
name|ITE_ISCONS
value|0x08
end_define

begin_comment
comment|/* device is console */
end_comment

begin_define
define|#
directive|define
name|ITE_ACTIVE
value|0x10
end_define

begin_comment
comment|/* device is being used as ITE */
end_comment

begin_define
define|#
directive|define
name|ITE_INGRF
value|0x20
end_define

begin_comment
comment|/* device in use as non-ITE */
end_comment

begin_define
define|#
directive|define
name|ITE_CURSORON
value|0x40
end_define

begin_comment
comment|/* cursor being tracked */
end_comment

begin_define
define|#
directive|define
name|attrloc
parameter_list|(
name|ip
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|)
define|\
value|(ip->attrbuf + ((y) * ip->cols) + (x))
end_define

begin_define
define|#
directive|define
name|attrclr
parameter_list|(
name|ip
parameter_list|,
name|sy
parameter_list|,
name|sx
parameter_list|,
name|h
parameter_list|,
name|w
parameter_list|)
define|\
value|bzero(ip->attrbuf + ((sy) * ip->cols) + (sx), (h) * (w))
end_define

begin_define
define|#
directive|define
name|attrmov
parameter_list|(
name|ip
parameter_list|,
name|sy
parameter_list|,
name|sx
parameter_list|,
name|dy
parameter_list|,
name|dx
parameter_list|,
name|h
parameter_list|,
name|w
parameter_list|)
define|\
value|bcopy(ip->attrbuf + ((sy) * ip->cols) + (sx), \ 	      ip->attrbuf + ((dy) * ip->cols) + (dx), \ 	      (h) * (w))
end_define

begin_define
define|#
directive|define
name|attrtest
parameter_list|(
name|ip
parameter_list|,
name|attr
parameter_list|)
define|\
value|((* (u_char *) attrloc(ip, ip->cury, ip->curx))& attr)
end_define

begin_define
define|#
directive|define
name|attrset
parameter_list|(
name|ip
parameter_list|,
name|attr
parameter_list|)
define|\
value|((* (u_char *) attrloc(ip, ip->cury, ip->curx)) = attr)
end_define

begin_comment
comment|/*  * X and Y location of character 'c' in the framebuffer, in pixels.  */
end_comment

begin_define
define|#
directive|define
name|charX
parameter_list|(
name|ip
parameter_list|,
name|c
parameter_list|)
define|\
value|(((c) % (ip)->cpl) * (ip)->ftwidth + (ip)->fontx)
end_define

begin_define
define|#
directive|define
name|charY
parameter_list|(
name|ip
parameter_list|,
name|c
parameter_list|)
define|\
value|(((c) / (ip)->cpl) * (ip)->ftheight + (ip)->fonty)
end_define

begin_comment
comment|/*  * The cursor is just an inverted space.  */
end_comment

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

begin_comment
comment|/* Character attributes */
end_comment

begin_define
define|#
directive|define
name|ATTR_NOR
value|0x0
end_define

begin_comment
comment|/* normal */
end_comment

begin_define
define|#
directive|define
name|ATTR_INV
value|0x1
end_define

begin_comment
comment|/* inverse */
end_comment

begin_define
define|#
directive|define
name|ATTR_UL
value|0x2
end_define

begin_comment
comment|/* underline */
end_comment

begin_define
define|#
directive|define
name|ATTR_ALL
value|(ATTR_INV | ATTR_UL)
end_define

begin_comment
comment|/* Keyboard attributes */
end_comment

begin_define
define|#
directive|define
name|ATTR_KPAD
value|0x4
end_define

begin_comment
comment|/* keypad transmit */
end_comment

begin_comment
comment|/* Replacement Rules */
end_comment

begin_define
define|#
directive|define
name|RR_CLEAR
value|0x0
end_define

begin_define
define|#
directive|define
name|RR_COPY
value|0x3
end_define

begin_define
define|#
directive|define
name|RR_XOR
value|0x6
end_define

begin_define
define|#
directive|define
name|RR_COPYINVERTED
value|0xc
end_define

begin_define
define|#
directive|define
name|SCROLL_UP
value|0x01
end_define

begin_define
define|#
directive|define
name|SCROLL_DOWN
value|0x02
end_define

begin_define
define|#
directive|define
name|SCROLL_LEFT
value|0x03
end_define

begin_define
define|#
directive|define
name|SCROLL_RIGHT
value|0x04
end_define

begin_define
define|#
directive|define
name|DRAW_CURSOR
value|0x05
end_define

begin_define
define|#
directive|define
name|ERASE_CURSOR
value|0x06
end_define

begin_define
define|#
directive|define
name|MOVE_CURSOR
value|0x07
end_define

begin_define
define|#
directive|define
name|KBD_SSHIFT
value|4
end_define

begin_comment
comment|/* bits to shift status */
end_comment

begin_define
define|#
directive|define
name|KBD_CHARMASK
value|0x7F
end_define

begin_comment
comment|/* keyboard status */
end_comment

begin_define
define|#
directive|define
name|KBD_SMASK
value|0xF
end_define

begin_comment
comment|/* service request status mask */
end_comment

begin_define
define|#
directive|define
name|KBD_CTRLSHIFT
value|0x8
end_define

begin_comment
comment|/* key + CTRL + SHIFT */
end_comment

begin_define
define|#
directive|define
name|KBD_CTRL
value|0x9
end_define

begin_comment
comment|/* key + CTRL */
end_comment

begin_define
define|#
directive|define
name|KBD_SHIFT
value|0xA
end_define

begin_comment
comment|/* key + SHIFT */
end_comment

begin_define
define|#
directive|define
name|KBD_KEY
value|0xB
end_define

begin_comment
comment|/* key only */
end_comment

begin_define
define|#
directive|define
name|KBD_CAPSLOCK
value|0x18
end_define

begin_define
define|#
directive|define
name|KBD_EXT_LEFT_DOWN
value|0x12
end_define

begin_define
define|#
directive|define
name|KBD_EXT_LEFT_UP
value|0x92
end_define

begin_define
define|#
directive|define
name|KBD_EXT_RIGHT_DOWN
value|0x13
end_define

begin_define
define|#
directive|define
name|KBD_EXT_RIGHT_UP
value|0x93
end_define

begin_define
define|#
directive|define
name|TABSIZE
value|8
end_define

begin_define
define|#
directive|define
name|TABEND
parameter_list|(
name|u
parameter_list|)
value|(ite_tty[u].t_winsize.ws_col - TABSIZE)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|ite_softc
name|ite_softc
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|itesw
name|itesw
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nitesw
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

