begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)tt.h	3.25 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Interface structure for the terminal drivers.  */
end_comment

begin_struct
struct|struct
name|tt
block|{
comment|/* startup and cleanup */
name|int
function_decl|(
modifier|*
name|tt_start
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|tt_end
function_decl|)
parameter_list|()
function_decl|;
comment|/* terminal functions */
name|int
function_decl|(
modifier|*
name|tt_move
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|tt_insline
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|tt_delline
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|tt_inschar
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|tt_insspace
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|tt_delchar
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|tt_write
function_decl|)
parameter_list|()
function_decl|;
comment|/* write a whole block */
name|int
function_decl|(
modifier|*
name|tt_putc
function_decl|)
parameter_list|()
function_decl|;
comment|/* write one character */
name|int
function_decl|(
modifier|*
name|tt_clreol
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|tt_clreos
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|tt_clear
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|tt_scroll_down
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|tt_scroll_up
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|tt_setscroll
function_decl|)
parameter_list|()
function_decl|;
comment|/* set scrolling region */
name|int
function_decl|(
modifier|*
name|tt_setmodes
function_decl|)
parameter_list|()
function_decl|;
comment|/* set display modes */
name|int
function_decl|(
modifier|*
name|tt_set_token
function_decl|)
parameter_list|()
function_decl|;
comment|/* define a token */
name|int
function_decl|(
modifier|*
name|tt_put_token
function_decl|)
parameter_list|()
function_decl|;
comment|/* refer to a defined token */
comment|/* internal variables */
name|char
name|tt_modes
decl_stmt|;
comment|/* the current display modes */
name|char
name|tt_nmodes
decl_stmt|;
comment|/* the new modes for next write */
name|char
name|tt_insert
decl_stmt|;
comment|/* currently in insert mode */
name|int
name|tt_row
decl_stmt|;
comment|/* cursor row */
name|int
name|tt_col
decl_stmt|;
comment|/* cursor column */
name|int
name|tt_scroll_top
decl_stmt|;
comment|/* top of scrolling region */
name|int
name|tt_scroll_bot
decl_stmt|;
comment|/* bottom of scrolling region */
comment|/* terminal info */
name|int
name|tt_nrow
decl_stmt|;
comment|/* number of display rows */
name|int
name|tt_ncol
decl_stmt|;
comment|/* number of display columns */
name|char
name|tt_availmodes
decl_stmt|;
comment|/* the display modes supported */
name|char
name|tt_wrap
decl_stmt|;
comment|/* has auto wrap around */
name|char
name|tt_retain
decl_stmt|;
comment|/* can retain below (db flag) */
name|short
name|tt_padc
decl_stmt|;
comment|/* the pad character */
name|int
name|tt_ntoken
decl_stmt|;
comment|/* number of compression tokens */
name|int
name|tt_token_min
decl_stmt|;
comment|/* minimun token size */
name|int
name|tt_token_max
decl_stmt|;
comment|/* maximum token size */
name|int
name|tt_set_token_cost
decl_stmt|;
comment|/* cost in addition to string */
name|int
name|tt_put_token_cost
decl_stmt|;
comment|/* constant cost */
comment|/* the frame characters */
name|short
modifier|*
name|tt_frame
decl_stmt|;
comment|/* the output routine */
name|int
function_decl|(
modifier|*
name|tt_flush
function_decl|)
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|tt
name|tt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * tt_padc is used by the compression routine.  * It is a short to allow the driver to indicate that there is no padding.  */
end_comment

begin_define
define|#
directive|define
name|TT_PADC_NONE
value|0x100
end_define

begin_comment
comment|/*  * List of terminal drivers.  */
end_comment

begin_struct
struct|struct
name|tt_tab
block|{
name|char
modifier|*
name|tt_name
decl_stmt|;
name|int
name|tt_len
decl_stmt|;
name|int
function_decl|(
modifier|*
name|tt_func
function_decl|)
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|tt_tab
name|tt_tab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Clean interface to termcap routines.  * Too may t's.  */
end_comment

begin_decl_stmt
name|char
name|tt_strings
index|[
literal|1024
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string buffer */
end_comment

begin_decl_stmt
name|char
modifier|*
name|tt_strp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer for it */
end_comment

begin_struct
struct|struct
name|tt_str
block|{
name|char
modifier|*
name|ts_str
decl_stmt|;
name|int
name|ts_n
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|tt_str
modifier|*
name|tttgetstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tt_str
modifier|*
name|ttxgetstr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* tgetstr() and expand delays */
end_comment

begin_function_decl
name|int
name|tttputc
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|tttputs
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|tputs((s)->ts_str, (n), tttputc)
end_define

begin_define
define|#
directive|define
name|ttxputs
parameter_list|(
name|s
parameter_list|)
value|ttwrite((s)->ts_str, (s)->ts_n)
end_define

begin_comment
comment|/*  * Buffered output without stdio.  * These variables have different meanings from the ww_ob* variables.  * But I'm too lazy to think up different names.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|tt_ob
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|tt_obp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|tt_obe
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ttputc
parameter_list|(
name|c
parameter_list|)
value|(tt_obp< tt_obe ? (*tt_obp++ = (c)) \ 				: ((*tt.tt_flush)(), *tt_obp++ = (c)))
end_define

begin_comment
comment|/*  * Convenience macros for the drivers  * They require char.h  */
end_comment

begin_define
define|#
directive|define
name|ttctrl
parameter_list|(
name|c
parameter_list|)
value|ttputc(ctrl(c))
end_define

begin_define
define|#
directive|define
name|ttesc
parameter_list|(
name|c
parameter_list|)
value|(ttctrl('['), ttputc(c))
end_define

end_unit

