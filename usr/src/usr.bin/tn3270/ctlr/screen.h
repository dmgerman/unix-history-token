begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)screen.h	3.1  10/29/86  */
end_comment

begin_define
define|#
directive|define
name|INCLUDED_SCREEN
end_define

begin_comment
comment|/* defines and defines to describe how to deal with the screen */
end_comment

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
value|(HighestScreen() - \ 				FieldFind(FieldReverse, \ 					HighestScreen()-(p), HighestScreen()))
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
value|(IsStartField(x)? Host[x].data : \ 				    Host[WhereAttrByte(x)].data)
end_define

begin_define
define|#
directive|define
name|FieldAttributesPointer
parameter_list|(
name|p
parameter_list|)
value|(IsStartFieldPointer(p)? (p)->data : \ 				    Host[WhereAttrByte((p)-&Host[0])].data)
end_define

begin_define
define|#
directive|define
name|TurnOffMdt
parameter_list|(
name|x
parameter_list|)
value|(Host[WhereAttrByte(x)].data&= ~ATTR_MDT)
end_define

begin_define
define|#
directive|define
name|TurnOnMdt
parameter_list|(
name|x
parameter_list|)
value|(Host[WhereAttrByte(x)].data |= ATTR_MDT)
end_define

begin_define
define|#
directive|define
name|HasMdt
parameter_list|(
name|x
parameter_list|)
value|(Host[x].data&ATTR_MDT)
end_define

begin_comment
comment|/* modified tag */
end_comment

begin_comment
comment|/* 	 * Is the screen formatted?  Some algorithms change depending 	 * on whether there are any attribute bytes lying around. 	 */
end_comment

begin_define
define|#
directive|define
name|FormattedScreen
parameter_list|()
define|\
value|((WhereAttrByte(0) != 0) || ((Host[0].data&ATTR_MASK) == ATTR_MASK))
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
value|((Host[x].data&ATTR_MASK) == ATTR_MASK)
end_define

begin_define
define|#
directive|define
name|IsStartFieldPointer
parameter_list|(
name|p
parameter_list|)
value|(((p)->data&ATTR_MASK) == ATTR_MASK)
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
value|(Host[p].data = (a)|ATTR_MASK, \ 			    FieldForward[p] = FieldReverse[ScreenSize-p-1] = 1)
end_define

begin_define
define|#
directive|define
name|DeleteField
parameter_list|(
name|p
parameter_list|)
value|(Host[p].data = 0, \ 			    FieldForward[p] = FieldReverse[ScreenSize-p-1] = 0)
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

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|data
decl_stmt|;
comment|/* data at this position */
block|}
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
name|p
parameter_list|,
name|c
parameter_list|)
value|(Host[p].data = c)
end_define

end_unit

