begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  *	defs	--	constant and macro definitions for dipress  *  *	John Mellor-Crummey (Xerox Corp)  *	  *	Copyright (c) 1985 Xerox Corporation  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|QUIT
value|1
end_define

begin_define
define|#
directive|define
name|CONTINUE
value|0
end_define

begin_define
define|#
directive|define
name|MAX_NUM_FONTS
value|60
end_define

begin_define
define|#
directive|define
name|DEFAULTRANGEBOT
value|-9999
end_define

begin_comment
comment|/* used to fill in an unspecified lower page# */
end_comment

begin_define
define|#
directive|define
name|DEFAULTRANGETOP
value|9999
end_define

begin_comment
comment|/* used to fill in an unspecified top page# */
end_comment

begin_define
define|#
directive|define
name|MAXPAGESPEC
value|25
end_define

begin_comment
comment|/* maximum number of page specifications on  				 * the command line using -o 				 */
end_comment

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|BUFFERSIZE
value|512
end_define

begin_comment
comment|/* buffer for reading ditroff commands */
end_comment

begin_define
define|#
directive|define
name|Showbuff_size
value|255
end_define

begin_define
define|#
directive|define
name|INCH
value|2540
end_define

begin_comment
comment|/* micas per inch */
end_comment

begin_define
define|#
directive|define
name|F_transform
value|0
end_define

begin_define
define|#
directive|define
name|maxPointsInSpline
value|60
end_define

begin_comment
comment|/* maximum number of points in a  					 * wiggly line 					 */
end_comment

begin_define
define|#
directive|define
name|maxPointsInPolygon
value|500
end_define

begin_comment
comment|/* Similarly */
end_comment

begin_define
define|#
directive|define
name|curr_strokewidth
value|(pointsizeTab[size - 1] * 4)
end_define

begin_define
define|#
directive|define
name|gobj_size
parameter_list|(
name|h1
parameter_list|,
name|v1
parameter_list|,
name|h2
parameter_list|,
name|v2
parameter_list|)
value|new_bitmap(curr_strokewidth, h1, v1, h2, v2)
end_define

begin_comment
comment|/* macros for positioning within the document */
end_comment

begin_define
define|#
directive|define
name|hInc
parameter_list|(
name|n
parameter_list|)
value|hor_pos += n
end_define

begin_define
define|#
directive|define
name|hMov
parameter_list|(
name|n
parameter_list|)
value|hor_pos = n
end_define

begin_define
define|#
directive|define
name|vInc
parameter_list|(
name|n
parameter_list|)
value|ver_pos += n
end_define

begin_define
define|#
directive|define
name|vMov
parameter_list|(
name|n
parameter_list|)
value|ver_pos = n
end_define

begin_comment
comment|/* translate ditroff h and v into interpress x and y */
end_comment

begin_comment
comment|/* (rx and ry are for relative x and y values) */
end_comment

begin_define
define|#
directive|define
name|xloc
parameter_list|(
name|h
parameter_list|)
value|((h) * scale)
end_define

begin_define
define|#
directive|define
name|rx
parameter_list|(
name|h
parameter_list|)
value|x(h)
end_define

begin_define
define|#
directive|define
name|yloc
parameter_list|(
name|v
parameter_list|)
value|(11 * INCH - ((v) * scale))
end_define

begin_define
define|#
directive|define
name|ry
parameter_list|(
name|v
parameter_list|)
value|(-(v) * scale)
end_define

begin_comment
comment|/* fontNumber -- coerce an out of range font index to the default font */
end_comment

begin_define
define|#
directive|define
name|fontNumber
parameter_list|(
name|n
parameter_list|)
value|((n< 0 || n> device.num_fonts) ? 1 : n)
end_define

begin_define
define|#
directive|define
name|white
parameter_list|(
name|ch
parameter_list|)
value|(ch == ' ' || ch == '\t')
end_define

begin_define
define|#
directive|define
name|abs
parameter_list|(
name|n
parameter_list|)
value|(((n)< 0) ? - (n) : (n))
end_define

begin_define
define|#
directive|define
name|sqr
parameter_list|(
name|n
parameter_list|)
value|((n) * (n))
end_define

begin_comment
comment|/* constants for drawarc -- definition of the directions of movement */
end_comment

begin_define
define|#
directive|define
name|M1
value|1
end_define

begin_define
define|#
directive|define
name|M2
value|2
end_define

begin_define
define|#
directive|define
name|M3
value|3
end_define

begin_define
define|#
directive|define
name|setpixel
parameter_list|()
value|set_pixel(hor_pos,ver_pos)
end_define

begin_define
define|#
directive|define
name|MAXSTATE
value|5
end_define

begin_comment
comment|/* maximum number of stacked environments */
end_comment

begin_comment
comment|/* mneumonics for the Device Independent Troff Commands */
end_comment

begin_define
define|#
directive|define
name|cmdPointSize
value|'s'
end_define

begin_define
define|#
directive|define
name|cmdFont
value|'f'
end_define

begin_define
define|#
directive|define
name|cmdChar
value|'c'
end_define

begin_define
define|#
directive|define
name|cmdSpecChar
value|'C'
end_define

begin_define
define|#
directive|define
name|cmdAbsHoriz
value|'H'
end_define

begin_define
define|#
directive|define
name|cmdRelHoriz
value|'h'
end_define

begin_define
define|#
directive|define
name|cmdAbsVert
value|'V'
end_define

begin_define
define|#
directive|define
name|cmdRelVert
value|'v'
end_define

begin_define
define|#
directive|define
name|cmdEol
value|'n'
end_define

begin_define
define|#
directive|define
name|cmdStippleFamily
value|'i'
end_define

begin_define
define|#
directive|define
name|cmdWordSep
value|'w'
end_define

begin_define
define|#
directive|define
name|cmdNewPage
value|'p'
end_define

begin_define
define|#
directive|define
name|cmdPushEnv
value|'{'
end_define

begin_define
define|#
directive|define
name|cmdPopEnv
value|'}'
end_define

begin_define
define|#
directive|define
name|cmdCharString
value|'t'
end_define

begin_define
define|#
directive|define
name|cmdComment
value|'#'
end_define

begin_define
define|#
directive|define
name|cmdDraw
value|'D'
end_define

begin_define
define|#
directive|define
name|drawLine
value|'l'
end_define

begin_define
define|#
directive|define
name|drawThick
value|'t'
end_define

begin_define
define|#
directive|define
name|drawStyle
value|'s'
end_define

begin_define
define|#
directive|define
name|drawCircle
value|'c'
end_define

begin_define
define|#
directive|define
name|drawEllipse
value|'e'
end_define

begin_define
define|#
directive|define
name|drawArc
value|'a'
end_define

begin_define
define|#
directive|define
name|drawWigglyLine
value|'~'
end_define

begin_define
define|#
directive|define
name|drawGremlinSpline
value|'g'
end_define

begin_define
define|#
directive|define
name|drawPolygon
value|'p'
end_define

begin_define
define|#
directive|define
name|drawUbPolygon
value|'P'
end_define

begin_define
define|#
directive|define
name|cmdDevice
value|'x'
end_define

begin_define
define|#
directive|define
name|deviceInit
value|'i'
end_define

begin_define
define|#
directive|define
name|deviceName
value|'T'
end_define

begin_define
define|#
directive|define
name|deviceResolution
value|'r'
end_define

begin_define
define|#
directive|define
name|devicePause
value|'p'
end_define

begin_define
define|#
directive|define
name|deviceStop
value|'s'
end_define

begin_define
define|#
directive|define
name|deviceTrailer
value|'t'
end_define

begin_define
define|#
directive|define
name|deviceFont
value|'f'
end_define

begin_define
define|#
directive|define
name|deviceHeight
value|'H'
end_define

begin_define
define|#
directive|define
name|deviceSlant
value|'S'
end_define

begin_define
define|#
directive|define
name|deviceXerox
value|'X'
end_define

begin_comment
comment|/* Xerox specific device commands */
end_comment

begin_define
define|#
directive|define
name|xeroxDeviceInsertIP
value|'I'
end_define

begin_define
define|#
directive|define
name|xeroxDeviceInsertRES
value|'R'
end_define

end_unit

