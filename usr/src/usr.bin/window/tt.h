begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * @(#)tt.h	3.14 %G%  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California,  * All rights reserved.  Redistribution permitted subject to  * the terms of the Berkeley Software License Agreement.  */
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
name|tt_init
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
name|tt_setinsert
function_decl|)
parameter_list|()
function_decl|;
comment|/* set insert mode */
name|int
function_decl|(
modifier|*
name|tt_setmodes
function_decl|)
parameter_list|()
function_decl|;
comment|/* set display modes */
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
name|char
name|tt_ninsert
decl_stmt|;
comment|/* insert mode on next write */
name|int
name|tt_row
decl_stmt|;
comment|/* cursor row */
name|int
name|tt_col
decl_stmt|;
comment|/* cursor column */
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
name|tt_hasinsert
decl_stmt|;
comment|/* has insert character */
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
comment|/* the frame characters */
name|short
modifier|*
name|tt_frame
decl_stmt|;
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

begin_define
define|#
directive|define
name|tttgetstr
parameter_list|(
name|s
parameter_list|)
value|tgetstr((s),&tt_strp)
end_define

begin_function_decl
name|char
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
value|tputs((s), (n), tttputc)
end_define

begin_comment
comment|/*  * Buffered output without stdio.  * These variables have different meanings from the ww_ob* variabels.  * But I'm too lazy to think up different names.  */
end_comment

begin_decl_stmt
name|char
name|tt_ob
index|[
literal|512
index|]
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
value|(tt_obp< tt_obe ? (*tt_obp++ = (c)) \ 				: (ttflush(), *tt_obp++ = (c)))
end_define

end_unit

