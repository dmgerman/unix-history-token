begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993, 1994 by Hellmuth Michaelis  *  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    This product includes software developed by Hellmuth Michaelis.  * 4. The name of the developer may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE DEVELOPER ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE DEVELOPERS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * 	fed.h, 3.00, last edit-date: [Sun Jan  2 20:10:31 1994]  */
end_comment

begin_include
include|#
directive|include
file|<ncurses.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|FED
end_ifdef

begin_decl_stmt
name|int
name|ch_height
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ch_width
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|curchar
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|WINDOW
modifier|*
name|ch_win
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|WINDOW
modifier|*
name|set_win
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|WINDOW
modifier|*
name|cmd_win
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|int
name|ch_height
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current fontfile character dimensions */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ch_width
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|curchar
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* character being edited */
end_comment

begin_decl_stmt
specifier|extern
name|WINDOW
modifier|*
name|ch_win
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* windows */
end_comment

begin_decl_stmt
specifier|extern
name|WINDOW
modifier|*
name|set_win
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|WINDOW
modifier|*
name|cmd_win
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FONTCHARS
value|256
end_define

begin_comment
comment|/* no of chars in a fontfile */
end_comment

begin_define
define|#
directive|define
name|WHITE
value|('.')
end_define

begin_define
define|#
directive|define
name|BLACK
value|('*')
end_define

begin_define
define|#
directive|define
name|K_UP
value|0x10
end_define

begin_comment
comment|/* ^P */
end_comment

begin_define
define|#
directive|define
name|K_DOWN
value|0x0e
end_define

begin_comment
comment|/* ^N */
end_comment

begin_define
define|#
directive|define
name|K_RIGHT
value|0x06
end_define

begin_comment
comment|/* ^F */
end_comment

begin_define
define|#
directive|define
name|K_LEFT
value|0x02
end_define

begin_comment
comment|/* ^B */
end_comment

begin_define
define|#
directive|define
name|WINROW
value|3
end_define

begin_define
define|#
directive|define
name|CMDCOL
value|3
end_define

begin_define
define|#
directive|define
name|CHCOL
value|20
end_define

begin_define
define|#
directive|define
name|SETCOL
value|41
end_define

begin_define
define|#
directive|define
name|WSIZE
value|16
end_define

begin_define
define|#
directive|define
name|CMDSIZE
value|12
end_define

begin_define
define|#
directive|define
name|WBORDER
value|1
end_define

begin_comment
comment|/* fonts */
end_comment

begin_define
define|#
directive|define
name|WIDTH8
value|8
end_define

begin_comment
comment|/* 8 bits wide font		      */
end_comment

begin_define
define|#
directive|define
name|WIDTH16
value|16
end_define

begin_comment
comment|/* 16 bits wide font		      */
end_comment

begin_define
define|#
directive|define
name|FONT8X8
value|2048
end_define

begin_comment
comment|/* filesize for 8x8 font              */
end_comment

begin_define
define|#
directive|define
name|HEIGHT8X8
value|8
end_define

begin_comment
comment|/* 8 scan lines char cell height      */
end_comment

begin_define
define|#
directive|define
name|FONT8X10
value|2560
end_define

begin_comment
comment|/* filesize for 8x10 font             */
end_comment

begin_define
define|#
directive|define
name|HEIGHT8X10
value|10
end_define

begin_comment
comment|/* 10 scan lines char cell height     */
end_comment

begin_define
define|#
directive|define
name|FONT8X14
value|3584
end_define

begin_comment
comment|/* filesize for 8x14 font             */
end_comment

begin_define
define|#
directive|define
name|HEIGHT8X14
value|14
end_define

begin_comment
comment|/* 14 scan lines char cell height     */
end_comment

begin_define
define|#
directive|define
name|WIDTH8X14
value|8
end_define

begin_comment
comment|/* 8 bits wide font		      */
end_comment

begin_define
define|#
directive|define
name|FONT8X16
value|4096
end_define

begin_comment
comment|/* filesize for 8x16 font             */
end_comment

begin_define
define|#
directive|define
name|HEIGHT8X16
value|16
end_define

begin_comment
comment|/* 16 scan lines char cell height     */
end_comment

begin_define
define|#
directive|define
name|FONT16X16
value|8192
end_define

begin_comment
comment|/* filesize for 16x16 font            */
end_comment

begin_define
define|#
directive|define
name|HEIGHT16X16
value|16
end_define

begin_comment
comment|/* 16 scan lines char cell height     */
end_comment

begin_function_decl
name|void
name|edit_mode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|edit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|normal_ch
parameter_list|(
name|int
name|r
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|chg_pt
parameter_list|(
name|int
name|r
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|invert
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setchr
parameter_list|(
name|char
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setrow
parameter_list|(
name|char
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setcol
parameter_list|(
name|char
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|readfont
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dis_cmd
parameter_list|(
name|char
modifier|*
name|strg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clr_cmd
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|save_ch
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|move_ch
parameter_list|(
name|int
name|src
parameter_list|,
name|int
name|dest
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xchg_ch
parameter_list|(
name|int
name|src
parameter_list|,
name|int
name|dest
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|display
parameter_list|(
name|int
name|no
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sel_mode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|selectc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|normal_set
parameter_list|(
name|int
name|r
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sel_dest
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|normal_uset
parameter_list|(
name|int
name|r
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|writefont
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ------------------------------ EOF ----------------------------------- */
end_comment

end_unit

