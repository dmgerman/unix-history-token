begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * IBM PC display definitions  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Color attributes for foreground text */
end_comment

begin_define
define|#
directive|define
name|FG_BLACK
value|0
end_define

begin_define
define|#
directive|define
name|FG_BLUE
value|1
end_define

begin_define
define|#
directive|define
name|FG_GREEN
value|2
end_define

begin_define
define|#
directive|define
name|FG_CYAN
value|3
end_define

begin_define
define|#
directive|define
name|FG_RED
value|4
end_define

begin_define
define|#
directive|define
name|FG_MAGENTA
value|5
end_define

begin_define
define|#
directive|define
name|FG_BROWN
value|6
end_define

begin_define
define|#
directive|define
name|FG_LIGHTGREY
value|7
end_define

begin_define
define|#
directive|define
name|FG_DARKGREY
value|8
end_define

begin_define
define|#
directive|define
name|FG_LIGHTBLUE
value|9
end_define

begin_define
define|#
directive|define
name|FG_LIGHTGREEN
value|10
end_define

begin_define
define|#
directive|define
name|FG_LIGHTCYAN
value|11
end_define

begin_define
define|#
directive|define
name|FG_LIGHTRED
value|12
end_define

begin_define
define|#
directive|define
name|FG_LIGHTMAGENTA
value|13
end_define

begin_define
define|#
directive|define
name|FG_YELLOW
value|14
end_define

begin_define
define|#
directive|define
name|FG_WHITE
value|15
end_define

begin_define
define|#
directive|define
name|FG_BLINK
value|0x80
end_define

begin_comment
comment|/* Color attributes for text background */
end_comment

begin_define
define|#
directive|define
name|BG_BLACK
value|0x00
end_define

begin_define
define|#
directive|define
name|BG_BLUE
value|0x10
end_define

begin_define
define|#
directive|define
name|BG_GREEN
value|0x20
end_define

begin_define
define|#
directive|define
name|BG_CYAN
value|0x30
end_define

begin_define
define|#
directive|define
name|BG_RED
value|0x40
end_define

begin_define
define|#
directive|define
name|BG_MAGENTA
value|0x50
end_define

begin_define
define|#
directive|define
name|BG_BROWN
value|0x60
end_define

begin_define
define|#
directive|define
name|BG_LIGHTGREY
value|0x70
end_define

begin_comment
comment|/* Monochrome attributes for foreground text */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_comment
comment|/* PC-98 attributes for foreground text */
end_comment

begin_define
define|#
directive|define
name|FG_UNDERLINE
value|0x08
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FG_UNDERLINE
value|0x01
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FG_INTENSE
value|0x08
end_define

begin_comment
comment|/* Monochrome attributes for text background */
end_comment

begin_define
define|#
directive|define
name|BG_INTENSE
value|0x10
end_define

end_unit

