begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	Copyright 1984, 1985 by the Regents of the University of  *	California and by Gregory Glenn Minshall.  *  *	Permission to use, copy, modify, and distribute these  *	programs and their documentation for any purpose and  *	without fee is hereby granted, provided that this  *	copyright and permission appear on all copies and  *	supporting documentation, the name of the Regents of  *	the University of California not be used in advertising  *	or publicity pertaining to distribution of the programs  *	without specific prior permission, and notice be given in  *	supporting documentation that copying and distribution is  *	by permission of the Regents of the University of California  *	and by Gregory Glenn Minshall.  Neither the Regents of the  *	University of California nor Gregory Glenn Minshall make  *	representations about the suitability of this software  *	for any purpose.  It is provided "as is" without  *	express or implied warranty.  */
end_comment

begin_comment
comment|/* defines and defines to describe how to deal with the screen */
end_comment

begin_define
define|#
directive|define
name|LINESIZE
value|80
end_define

begin_define
define|#
directive|define
name|NUMBERLINES
value|24
end_define

begin_define
define|#
directive|define
name|SCREENSIZE
value|(LINESIZE*NUMBERLINES)
end_define

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
value|(SCREENSIZE-1)
end_define

begin_define
define|#
directive|define
name|ScreenLineOffset
parameter_list|(
name|x
parameter_list|)
value|((x)%LINESIZE)
end_define

begin_define
define|#
directive|define
name|ScreenLine
parameter_list|(
name|x
parameter_list|)
value|((int)((x)/LINESIZE))
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
value|(((x)+(SCREENSIZE-LINESIZE))%SCREENSIZE)
end_define

begin_define
define|#
directive|define
name|ScreenDown
parameter_list|(
name|x
parameter_list|)
value|(((x)+LINESIZE)%SCREENSIZE)
end_define

begin_define
define|#
directive|define
name|IsOrder
parameter_list|(
name|x
parameter_list|)
value|((x)&& ((x)< 0x40)&& (\ 			    ((x) == ORDER_SF) || \ 			    ((x) == ORDER_SBA) || \ 			    ((x) == ORDER_IC) || \ 			    ((x) == ORDER_PT) || \ 			    ((x) == ORDER_RA) || \ 			    ((x) == ORDER_EUA) || \ 			    ((x) == ORDER_YALE)))
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
value|((x)*LINESIZE+(y))
end_define

begin_escape
end_escape

begin_comment
comment|/* These know how fields are implemented... */
end_comment

begin_define
define|#
directive|define
name|FieldInc
parameter_list|(
name|p
parameter_list|)
value|FieldFind(FieldForward, p, LowestScreen())
end_define

begin_define
define|#
directive|define
name|FieldDec
parameter_list|(
name|p
parameter_list|)
value|(HighestScreen() - \ 				FieldFind(FieldReverse, \ 					HighestScreen()-p, HighestScreen()))
end_define

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
value|(IsStartField(x)? Host[x].field&0xff : \ 				    Host[WhereAttrByte(x)].field&0xff)
end_define

begin_define
define|#
directive|define
name|TermAttributes
parameter_list|(
name|x
parameter_list|)
value|(TermIsStartField(x)? Terminal[x].field&0xff : \ 				    Terminal[WhereTermAttrByte(x)].field&0xff)
end_define

begin_define
define|#
directive|define
name|TurnOffMdt
parameter_list|(
name|x
parameter_list|)
value|(Host[WhereAttrByte(x)].field&= ~ATTR_MDT)
end_define

begin_define
define|#
directive|define
name|TurnOnMdt
parameter_list|(
name|x
parameter_list|)
value|(Host[WhereAttrByte(x)].field |= ATTR_MDT)
end_define

begin_define
define|#
directive|define
name|HasMdt
parameter_list|(
name|x
parameter_list|)
value|(Host[x].field&ATTR_MDT)
end_define

begin_comment
comment|/* modified tag */
end_comment

begin_define
define|#
directive|define
name|IsStartField
parameter_list|(
name|x
parameter_list|)
value|(Host[x].field&ATTR_MASK)
end_define

begin_comment
comment|/* field starts here */
end_comment

begin_define
define|#
directive|define
name|TermIsStartField
parameter_list|(
name|x
parameter_list|)
value|(Terminal[x].field&ATTR_MASK)
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
value|(Host[p].field = (a)|ATTR_MASK, \ 			    FieldForward[p] = FieldReverse[SCREENSIZE-p-1] = 1)
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
value|(Terminal[p].field = (a)|ATTR_MASK)
end_define

begin_define
define|#
directive|define
name|DeleteField
parameter_list|(
name|p
parameter_list|)
value|(Host[p].field = 0, \ 			    FieldForward[p] = FieldReverse[SCREENSIZE-p-1] = 0)
end_define

begin_define
define|#
directive|define
name|TermDeleteField
parameter_list|(
name|p
parameter_list|)
value|(Terminal[p].field = 0)
end_define

begin_define
define|#
directive|define
name|DeleteAllFields
parameter_list|()
value|(bzero(FieldForward, sizeof FieldForward), \ 				    bzero(FieldReverse, sizeof FieldReverse))
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
name|MAX
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)<(y)? (y):(x))
end_define

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)<(y)? x:(y))
end_define

begin_define
define|#
directive|define
name|GetHost
parameter_list|(
name|i
parameter_list|)
value|Host[i].data
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
value|(Host[i].data = c)
end_define

begin_define
define|#
directive|define
name|GetTerminal
parameter_list|(
name|i
parameter_list|)
value|Terminal[i].data
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
value|(Terminal[i].data = c)
end_define

begin_struct
struct|struct
block|{
name|char
name|data
decl_stmt|,
comment|/* data at this position */
name|field
decl_stmt|;
comment|/* field attributes of this location if ATTR_MASK */
block|}
name|Host
index|[
name|SCREENSIZE
index|]
struct|,
comment|/* host view of screen */
name|Terminal
index|[
name|SCREENSIZE
index|]
struct|;
end_struct

begin_decl_stmt
name|char
name|FieldForward
index|[
name|SCREENSIZE
index|]
decl_stmt|,
comment|/* non-zero for SF, 0..1919 */
name|FieldReverse
index|[
name|SCREENSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* non-zero for SF, 1919..0 */
end_comment

begin_decl_stmt
name|int
name|CursorAddress
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where cursor is */
end_comment

begin_decl_stmt
name|int
name|BufferAddress
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where writes are going */
end_comment

begin_decl_stmt
name|int
name|Lowest
decl_stmt|,
name|Highest
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the Following are globals */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|CIABuffer
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|UnLocked
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* is the keyboard unlocked */
end_comment

begin_decl_stmt
name|int
name|AidByte
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Initialized
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* are we initialized? */
end_comment

end_unit

