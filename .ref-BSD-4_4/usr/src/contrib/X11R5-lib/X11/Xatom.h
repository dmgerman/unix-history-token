begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|XATOM_H
end_ifndef

begin_define
define|#
directive|define
name|XATOM_H
value|1
end_define

begin_comment
comment|/* THIS IS A GENERATED FILE  *  * Do not change!  Changing this file implies a protocol change!  */
end_comment

begin_define
define|#
directive|define
name|XA_PRIMARY
value|((Atom) 1)
end_define

begin_define
define|#
directive|define
name|XA_SECONDARY
value|((Atom) 2)
end_define

begin_define
define|#
directive|define
name|XA_ARC
value|((Atom) 3)
end_define

begin_define
define|#
directive|define
name|XA_ATOM
value|((Atom) 4)
end_define

begin_define
define|#
directive|define
name|XA_BITMAP
value|((Atom) 5)
end_define

begin_define
define|#
directive|define
name|XA_CARDINAL
value|((Atom) 6)
end_define

begin_define
define|#
directive|define
name|XA_COLORMAP
value|((Atom) 7)
end_define

begin_define
define|#
directive|define
name|XA_CURSOR
value|((Atom) 8)
end_define

begin_define
define|#
directive|define
name|XA_CUT_BUFFER0
value|((Atom) 9)
end_define

begin_define
define|#
directive|define
name|XA_CUT_BUFFER1
value|((Atom) 10)
end_define

begin_define
define|#
directive|define
name|XA_CUT_BUFFER2
value|((Atom) 11)
end_define

begin_define
define|#
directive|define
name|XA_CUT_BUFFER3
value|((Atom) 12)
end_define

begin_define
define|#
directive|define
name|XA_CUT_BUFFER4
value|((Atom) 13)
end_define

begin_define
define|#
directive|define
name|XA_CUT_BUFFER5
value|((Atom) 14)
end_define

begin_define
define|#
directive|define
name|XA_CUT_BUFFER6
value|((Atom) 15)
end_define

begin_define
define|#
directive|define
name|XA_CUT_BUFFER7
value|((Atom) 16)
end_define

begin_define
define|#
directive|define
name|XA_DRAWABLE
value|((Atom) 17)
end_define

begin_define
define|#
directive|define
name|XA_FONT
value|((Atom) 18)
end_define

begin_define
define|#
directive|define
name|XA_INTEGER
value|((Atom) 19)
end_define

begin_define
define|#
directive|define
name|XA_PIXMAP
value|((Atom) 20)
end_define

begin_define
define|#
directive|define
name|XA_POINT
value|((Atom) 21)
end_define

begin_define
define|#
directive|define
name|XA_RECTANGLE
value|((Atom) 22)
end_define

begin_define
define|#
directive|define
name|XA_RESOURCE_MANAGER
value|((Atom) 23)
end_define

begin_define
define|#
directive|define
name|XA_RGB_COLOR_MAP
value|((Atom) 24)
end_define

begin_define
define|#
directive|define
name|XA_RGB_BEST_MAP
value|((Atom) 25)
end_define

begin_define
define|#
directive|define
name|XA_RGB_BLUE_MAP
value|((Atom) 26)
end_define

begin_define
define|#
directive|define
name|XA_RGB_DEFAULT_MAP
value|((Atom) 27)
end_define

begin_define
define|#
directive|define
name|XA_RGB_GRAY_MAP
value|((Atom) 28)
end_define

begin_define
define|#
directive|define
name|XA_RGB_GREEN_MAP
value|((Atom) 29)
end_define

begin_define
define|#
directive|define
name|XA_RGB_RED_MAP
value|((Atom) 30)
end_define

begin_define
define|#
directive|define
name|XA_STRING
value|((Atom) 31)
end_define

begin_define
define|#
directive|define
name|XA_VISUALID
value|((Atom) 32)
end_define

begin_define
define|#
directive|define
name|XA_WINDOW
value|((Atom) 33)
end_define

begin_define
define|#
directive|define
name|XA_WM_COMMAND
value|((Atom) 34)
end_define

begin_define
define|#
directive|define
name|XA_WM_HINTS
value|((Atom) 35)
end_define

begin_define
define|#
directive|define
name|XA_WM_CLIENT_MACHINE
value|((Atom) 36)
end_define

begin_define
define|#
directive|define
name|XA_WM_ICON_NAME
value|((Atom) 37)
end_define

begin_define
define|#
directive|define
name|XA_WM_ICON_SIZE
value|((Atom) 38)
end_define

begin_define
define|#
directive|define
name|XA_WM_NAME
value|((Atom) 39)
end_define

begin_define
define|#
directive|define
name|XA_WM_NORMAL_HINTS
value|((Atom) 40)
end_define

begin_define
define|#
directive|define
name|XA_WM_SIZE_HINTS
value|((Atom) 41)
end_define

begin_define
define|#
directive|define
name|XA_WM_ZOOM_HINTS
value|((Atom) 42)
end_define

begin_define
define|#
directive|define
name|XA_MIN_SPACE
value|((Atom) 43)
end_define

begin_define
define|#
directive|define
name|XA_NORM_SPACE
value|((Atom) 44)
end_define

begin_define
define|#
directive|define
name|XA_MAX_SPACE
value|((Atom) 45)
end_define

begin_define
define|#
directive|define
name|XA_END_SPACE
value|((Atom) 46)
end_define

begin_define
define|#
directive|define
name|XA_SUPERSCRIPT_X
value|((Atom) 47)
end_define

begin_define
define|#
directive|define
name|XA_SUPERSCRIPT_Y
value|((Atom) 48)
end_define

begin_define
define|#
directive|define
name|XA_SUBSCRIPT_X
value|((Atom) 49)
end_define

begin_define
define|#
directive|define
name|XA_SUBSCRIPT_Y
value|((Atom) 50)
end_define

begin_define
define|#
directive|define
name|XA_UNDERLINE_POSITION
value|((Atom) 51)
end_define

begin_define
define|#
directive|define
name|XA_UNDERLINE_THICKNESS
value|((Atom) 52)
end_define

begin_define
define|#
directive|define
name|XA_STRIKEOUT_ASCENT
value|((Atom) 53)
end_define

begin_define
define|#
directive|define
name|XA_STRIKEOUT_DESCENT
value|((Atom) 54)
end_define

begin_define
define|#
directive|define
name|XA_ITALIC_ANGLE
value|((Atom) 55)
end_define

begin_define
define|#
directive|define
name|XA_X_HEIGHT
value|((Atom) 56)
end_define

begin_define
define|#
directive|define
name|XA_QUAD_WIDTH
value|((Atom) 57)
end_define

begin_define
define|#
directive|define
name|XA_WEIGHT
value|((Atom) 58)
end_define

begin_define
define|#
directive|define
name|XA_POINT_SIZE
value|((Atom) 59)
end_define

begin_define
define|#
directive|define
name|XA_RESOLUTION
value|((Atom) 60)
end_define

begin_define
define|#
directive|define
name|XA_COPYRIGHT
value|((Atom) 61)
end_define

begin_define
define|#
directive|define
name|XA_NOTICE
value|((Atom) 62)
end_define

begin_define
define|#
directive|define
name|XA_FONT_NAME
value|((Atom) 63)
end_define

begin_define
define|#
directive|define
name|XA_FAMILY_NAME
value|((Atom) 64)
end_define

begin_define
define|#
directive|define
name|XA_FULL_NAME
value|((Atom) 65)
end_define

begin_define
define|#
directive|define
name|XA_CAP_HEIGHT
value|((Atom) 66)
end_define

begin_define
define|#
directive|define
name|XA_WM_CLASS
value|((Atom) 67)
end_define

begin_define
define|#
directive|define
name|XA_WM_TRANSIENT_FOR
value|((Atom) 68)
end_define

begin_define
define|#
directive|define
name|XA_LAST_PREDEFINED
value|((Atom) 68)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XATOM_H */
end_comment

end_unit

