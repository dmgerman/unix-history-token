begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)terminal.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_define
define|#
directive|define
name|INCLUDED_TERMINAL
end_define

begin_comment
comment|/*  * In the situation where we have a copy of the terminal screen in front  * of us, here are some macros to deal with them.  */
end_comment

begin_define
define|#
directive|define
name|TermAttributes
parameter_list|(
name|x
parameter_list|)
value|(TermIsStartField(x)? GetTerminal(x)&0xff : \ 				    GetTerminal(WhereTermAttrByte(x))&0xff)
end_define

begin_define
define|#
directive|define
name|TermIsStartField
parameter_list|(
name|x
parameter_list|)
value|((GetTerminal(x)&ATTR_MASK) == ATTR_MASK)
end_define

begin_define
define|#
directive|define
name|TermNewField
parameter_list|(
name|p
parameter_list|,
name|a
parameter_list|)
value|SetTerminal(p, (a)|ATTR_MASK)
end_define

begin_define
define|#
directive|define
name|TermDeleteField
parameter_list|(
name|p
parameter_list|)
value|SetTerminal(p, 0)
end_define

begin_define
define|#
directive|define
name|TermIsNonDisplay
parameter_list|(
name|x
parameter_list|)
define|\
value|((TermAttributes(x)&ATTR_DSPD_MASK) == ATTR_DSPD_NONDISPLAY)
end_define

begin_define
define|#
directive|define
name|TermIsHighlighted
parameter_list|(
name|x
parameter_list|)
define|\
value|(((TermAttributes(x)&ATTR_DSPD_MASK) == ATTR_DSPD_HIGH) \&& !TermIsStartField(x))
end_define

begin_define
define|#
directive|define
name|TerminalCharacterAttr
parameter_list|(
name|c
parameter_list|,
name|p
parameter_list|,
name|a
parameter_list|)
value|(IsNonDisplayAttr(a) ? ' ':c)
end_define

begin_define
define|#
directive|define
name|TerminalCharacter
parameter_list|(
name|c
parameter_list|,
name|p
parameter_list|)
value|TerminalCharacterAttr(c,p,FieldAttributes(p))
end_define

begin_comment
comment|/* 	 * Is the screen formatted?  Some algorithms change depending 	 * on whether there are any attribute bytes lying around. 	 */
end_comment

begin_define
define|#
directive|define
name|TerminalFormattedScreen
parameter_list|()
define|\
value|((WhereTermAttrByte(0) != 0) || ((GetTerminal(0)&ATTR_MASK) == ATTR_MASK))
end_define

begin_define
define|#
directive|define
name|NeedToRedisplayFields
parameter_list|(
name|p
parameter_list|)
value|((TermIsNonDisplay(p) != IsNonDisplay(p)) || \ 				(TermIsHighlighted(p) != IsHighlighted(p)))
end_define

begin_define
define|#
directive|define
name|NeedToRedisplayFieldsAttr
parameter_list|(
name|p
parameter_list|,
name|c
parameter_list|)
value|( \ 			(TermIsNonDisplay(p) != IsNonDisplayAttr(c)) || \ 			(TermIsHighlighted(p) != IsHighlightedAttr(c)))
end_define

begin_define
define|#
directive|define
name|NotVisuallyCompatibleAttributes
parameter_list|(
name|p
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|( \ 			(IsNonDisplayAttr(c) != IsNonDisplayAttr(d)) || \ 			(IsHighlightedAttr(c) != IsHighlightedAttr(d)))
end_define

begin_define
define|#
directive|define
name|NeedToRedisplayAttr
parameter_list|(
name|c
parameter_list|,
name|p
parameter_list|,
name|a
parameter_list|)
define|\
value|((c != GetTerminal(p)) || NeedToRedisplayFieldsAttr(p,a))
end_define

begin_define
define|#
directive|define
name|NeedToRedisplay
parameter_list|(
name|c
parameter_list|,
name|p
parameter_list|)
value|NeedToRedisplayAttr(c,p,FieldAttributes(p))
end_define

begin_define
define|#
directive|define
name|GetTerminal
parameter_list|(
name|i
parameter_list|)
value|GetGeneric(i, Terminal)
end_define

begin_define
define|#
directive|define
name|GetTerminalPointer
parameter_list|(
name|p
parameter_list|)
value|GetGenericPointer(p)
end_define

begin_define
define|#
directive|define
name|SetTerminal
parameter_list|(
name|i
parameter_list|,
name|c
parameter_list|)
value|SetGeneric(i,c,Terminal)
end_define

end_unit

