begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)screen.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_define
define|#
directive|define
name|INCLUDED_SCREEN
end_define

begin_comment
comment|/* defines and defines to describe how to deal with the screen */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MSDOS
argument_list|)
end_if

begin_define
define|#
directive|define
name|MAXNUMBERLINES
value|43
end_define

begin_comment
comment|/* 3278-4 */
end_comment

begin_define
define|#
directive|define
name|MAXNUMBERCOLUMNS
value|132
end_define

begin_comment
comment|/* 3278-5 */
end_comment

begin_define
define|#
directive|define
name|MAXSCREENSIZE
value|3564
end_define

begin_comment
comment|/* (27*132) 3278-5 */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !defined(MSDOS) */
end_comment

begin_comment
comment|/* MSDOS has memory constraints */
end_comment

begin_define
define|#
directive|define
name|MAXNUMBERLINES
value|25
end_define

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|MAXNUMBERCOLUMNS
value|80
end_define

begin_define
define|#
directive|define
name|MAXSCREENSIZE
value|(MAXNUMBERLINES*MAXNUMBERCOLUMNS)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(MSDOS) */
end_comment

begin_comment
comment|/* MSDOS has memory constraints */
end_comment

begin_define
define|#
directive|define
name|LowestScreen
parameter_list|()
value|0
end_define

begin_define
define|#
directive|define
name|HighestScreen
parameter_list|()
value|(ScreenSize-1)
end_define

begin_define
define|#
directive|define
name|ScreenLineOffset
parameter_list|(
name|x
parameter_list|)
value|((x)%NumberColumns)
end_define

begin_define
define|#
directive|define
name|ScreenLine
parameter_list|(
name|x
parameter_list|)
value|((int)((x)/NumberColumns))
end_define

begin_define
define|#
directive|define
name|ScreenInc
parameter_list|(
name|x
parameter_list|)
value|(((x)==HighestScreen())? LowestScreen():x+1)
end_define

begin_define
define|#
directive|define
name|ScreenDec
parameter_list|(
name|x
parameter_list|)
value|(((x)==LowestScreen())? HighestScreen():x-1)
end_define

begin_define
define|#
directive|define
name|ScreenUp
parameter_list|(
name|x
parameter_list|)
value|(((x)+(ScreenSize-NumberColumns))%ScreenSize)
end_define

begin_define
define|#
directive|define
name|ScreenDown
parameter_list|(
name|x
parameter_list|)
value|(((x)+NumberColumns)%ScreenSize)
end_define

begin_define
define|#
directive|define
name|IsOrder
parameter_list|(
name|x
parameter_list|)
value|(Orders[x])
end_define

begin_define
define|#
directive|define
name|BAIC
parameter_list|(
name|x
parameter_list|)
value|((x)&0x3f)
end_define

begin_define
define|#
directive|define
name|CIAB
parameter_list|(
name|x
parameter_list|)
value|(CIABuffer[(x)&0x3f])
end_define

begin_define
define|#
directive|define
name|BufferTo3270_0
parameter_list|(
name|x
parameter_list|)
value|(CIABuffer[(int)((x)/0x40)])
end_define

begin_define
define|#
directive|define
name|BufferTo3270_1
parameter_list|(
name|x
parameter_list|)
value|(CIABuffer[(x)&0x3f])
end_define

begin_define
define|#
directive|define
name|Addr3270
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(BAIC(x)*64+BAIC(y))
end_define

begin_define
define|#
directive|define
name|SetBufferAddress
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)*NumberColumns+(y))
end_define

begin_escape
end_escape

begin_comment
comment|/* These know how fields are implemented... */
end_comment

begin_define
define|#
directive|define
name|WhereAttrByte
parameter_list|(
name|p
parameter_list|)
value|(IsStartField(p)? p: FieldDec(p))
end_define

begin_define
define|#
directive|define
name|WhereHighByte
parameter_list|(
name|p
parameter_list|)
value|ScreenDec(FieldInc(p))
end_define

begin_define
define|#
directive|define
name|WhereLowByte
parameter_list|(
name|p
parameter_list|)
value|ScreenInc(WhereAttrByte(p))
end_define

begin_define
define|#
directive|define
name|FieldAttributes
parameter_list|(
name|x
parameter_list|)
value|(IsStartField(x)? GetHost(x) : \ 				    GetHost(WhereAttrByte(x)))
end_define

begin_define
define|#
directive|define
name|FieldAttributesPointer
parameter_list|(
name|p
parameter_list|)
value|(IsStartFieldPointer(p)? \ 				    GetHostPointer(p): \ 				    GetHost(WhereAttrByte((p)-&Host[0])))
end_define

begin_comment
comment|/*  * The MDT functions need to protect against the case where the screen  * is unformatted (sigh).  */
end_comment

begin_comment
comment|/* Turn off the Modified Data Tag */
end_comment

begin_define
define|#
directive|define
name|TurnOffMdt
parameter_list|(
name|x
parameter_list|)
define|\
value|if (HasMdt(WhereAttrByte(x))) { \ 	ModifyMdt(x, 0); \     }
end_define

begin_comment
comment|/* Turn on the Modified Data Tag */
end_comment

begin_define
define|#
directive|define
name|TurnOnMdt
parameter_list|(
name|x
parameter_list|)
define|\
value|if (!HasMdt(WhereAttrByte(x))) { \ 	ModifyMdt(x, 1); \     }
end_define

begin_comment
comment|/* If this location has the MDT bit turned on (implies start of field) ... */
end_comment

begin_define
define|#
directive|define
name|HasMdt
parameter_list|(
name|x
parameter_list|)
define|\
value|((GetHost(x)&(ATTR_MDT|ATTR_MASK)) == (ATTR_MDT|ATTR_MASK))
end_define

begin_comment
comment|/* 	 * Is the screen formatted?  Some algorithms change depending 	 * on whether there are any attribute bytes lying around. 	 */
end_comment

begin_define
define|#
directive|define
name|FormattedScreen
parameter_list|()
define|\
value|((WhereAttrByte(0) != 0) || ((GetHost(0)&ATTR_MASK) == ATTR_MASK))
end_define

begin_comment
comment|/* field starts here */
end_comment

begin_define
define|#
directive|define
name|IsStartField
parameter_list|(
name|x
parameter_list|)
value|((GetHost(x)&ATTR_MASK) == ATTR_MASK)
end_define

begin_define
define|#
directive|define
name|IsStartFieldPointer
parameter_list|(
name|p
parameter_list|)
value|((GetHostPointer(p)&ATTR_MASK) == ATTR_MASK)
end_define

begin_define
define|#
directive|define
name|NewField
parameter_list|(
name|p
parameter_list|,
name|a
parameter_list|)
value|SetHost(p, (a)|ATTR_MASK)
end_define

begin_define
define|#
directive|define
name|DeleteField
parameter_list|(
name|p
parameter_list|)
value|SetHost(p, 0)
end_define

begin_define
define|#
directive|define
name|DeleteAllFields
parameter_list|()
end_define

begin_escape
end_escape

begin_comment
comment|/* The following are independent of the implementation of fields */
end_comment

begin_define
define|#
directive|define
name|IsProtectedAttr
parameter_list|(
name|p
parameter_list|,
name|a
parameter_list|)
value|(IsStartField(p) || ((a)&ATTR_PROT))
end_define

begin_define
define|#
directive|define
name|IsProtected
parameter_list|(
name|p
parameter_list|)
value|IsProtectedAttr(p,FieldAttributes(p))
end_define

begin_define
define|#
directive|define
name|IsUnProtected
parameter_list|(
name|x
parameter_list|)
value|(!IsProtected(x))
end_define

begin_define
define|#
directive|define
name|IsAutoSkip
parameter_list|(
name|x
parameter_list|)
value|(FieldAttributes(x)&ATTR_AUTO_SKIP)
end_define

begin_define
define|#
directive|define
name|IsNonDisplayAttr
parameter_list|(
name|c
parameter_list|)
value|(((c)&ATTR_DSPD_MASK) == ATTR_DSPD_NONDISPLAY)
end_define

begin_define
define|#
directive|define
name|IsNonDisplay
parameter_list|(
name|p
parameter_list|)
value|IsNonDisplayAttr(FieldAttributes(p))
end_define

begin_define
define|#
directive|define
name|IsHighlightedAttr
parameter_list|(
name|c
parameter_list|)
define|\
value|(((c)&ATTR_DSPD_MASK) == ATTR_DSPD_HIGH)
end_define

begin_define
define|#
directive|define
name|IsHighlighted
parameter_list|(
name|p
parameter_list|)
define|\
value|(IsHighlightedAttr(FieldAttributes(p))&& !IsStartField(p))
end_define

begin_typedef
typedef|typedef
name|unsigned
name|char
name|ScreenImage
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|FieldFind
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
name|CIABuffer
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GetGeneric
parameter_list|(
name|i
parameter_list|,
name|h
parameter_list|)
value|(h)[i]
end_define

begin_define
define|#
directive|define
name|GetGenericPointer
parameter_list|(
name|p
parameter_list|)
value|(*(p))
end_define

begin_define
define|#
directive|define
name|SetGeneric
parameter_list|(
name|i
parameter_list|,
name|c
parameter_list|,
name|h
parameter_list|)
value|((h)[i] = (c))
end_define

begin_define
define|#
directive|define
name|ModifyGeneric
parameter_list|(
name|i
parameter_list|,
name|what
parameter_list|,
name|h
parameter_list|)
value|{(h)[i] what;}
end_define

begin_define
define|#
directive|define
name|GetHost
parameter_list|(
name|i
parameter_list|)
value|GetGeneric(i,Host)
end_define

begin_define
define|#
directive|define
name|GetHostPointer
parameter_list|(
name|p
parameter_list|)
value|GetGenericPointer(p)
end_define

begin_define
define|#
directive|define
name|SetHost
parameter_list|(
name|i
parameter_list|,
name|c
parameter_list|)
value|SetGeneric(i,c,Host)
end_define

begin_define
define|#
directive|define
name|ModifyHost
parameter_list|(
name|i
parameter_list|,
name|what
parameter_list|)
value|ModifyGeneric(i,what,Host)
end_define

end_unit

