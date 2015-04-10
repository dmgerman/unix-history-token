begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1993, 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  *  * See the LICENSE file for redistribution information.  *  *	$Id: gs.h,v 11.0 2012/10/17 06:34:37 zy Exp $  */
end_comment

begin_define
define|#
directive|define
name|TEMPORARY_FILE_STRING
value|"/tmp"
end_define

begin_comment
comment|/* Default temporary file name. */
end_comment

begin_include
include|#
directive|include
file|<nl_types.h>
end_include

begin_comment
comment|/*  * File reference structure (FREF).  The structure contains the name of the  * file, along with the information that follows the name.  *  * !!!  * The read-only bit follows the file name, not the file itself.  */
end_comment

begin_struct
struct|struct
name|_fref
block|{
name|TAILQ_ENTRY
argument_list|(
argument|_fref
argument_list|)
name|q
expr_stmt|;
comment|/* Linked list of file references. */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* File name. */
name|char
modifier|*
name|tname
decl_stmt|;
comment|/* Backing temporary file name. */
name|recno_t
name|lno
decl_stmt|;
comment|/* 1-N: file cursor line. */
name|size_t
name|cno
decl_stmt|;
comment|/* 0-N: file cursor column. */
define|#
directive|define
name|FR_CURSORSET
value|0x0001
comment|/* If lno/cno values valid. */
define|#
directive|define
name|FR_DONTDELETE
value|0x0002
comment|/* Don't delete the temporary file. */
define|#
directive|define
name|FR_EXNAMED
value|0x0004
comment|/* Read/write renamed the file. */
define|#
directive|define
name|FR_NAMECHANGE
value|0x0008
comment|/* If the name changed. */
define|#
directive|define
name|FR_NEWFILE
value|0x0010
comment|/* File doesn't really exist yet. */
define|#
directive|define
name|FR_RECOVER
value|0x0020
comment|/* File is being recovered. */
define|#
directive|define
name|FR_TMPEXIT
value|0x0040
comment|/* Modified temporary file, no exit. */
define|#
directive|define
name|FR_TMPFILE
value|0x0080
comment|/* If file has no name. */
define|#
directive|define
name|FR_UNLOCKED
value|0x0100
comment|/* File couldn't be locked. */
name|u_int16_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Action arguments to scr_exadjust(). */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EX_TERM_CE
block|,
name|EX_TERM_SCROLL
block|}
name|exadj_t
typedef|;
end_typedef

begin_comment
comment|/* Screen attribute arguments to scr_attr(). */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|SA_ALTERNATE
block|,
name|SA_INVERSE
block|}
name|scr_attr_t
typedef|;
end_typedef

begin_comment
comment|/* Key type arguments to scr_keyval(). */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|KEY_VEOF
block|,
name|KEY_VERASE
block|,
name|KEY_VKILL
block|,
name|KEY_VWERASE
block|}
name|scr_keyval_t
typedef|;
end_typedef

begin_comment
comment|/*  * GS:  *  * Structure that describes global state of the running program.  */
end_comment

begin_struct
struct|struct
name|_gs
block|{
name|char
modifier|*
name|progname
decl_stmt|;
comment|/* Programe name. */
name|int
name|id
decl_stmt|;
comment|/* Last allocated screen id. */
name|TAILQ_HEAD
argument_list|(
argument|_dqh
argument_list|,
argument|_scr
argument_list|)
name|dq
index|[
literal|1
index|]
expr_stmt|;
comment|/* Displayed screens. */
name|TAILQ_HEAD
argument_list|(
argument|_hqh
argument_list|,
argument|_scr
argument_list|)
name|hq
index|[
literal|1
index|]
expr_stmt|;
comment|/* Hidden screens. */
name|SCR
modifier|*
name|ccl_sp
decl_stmt|;
comment|/* Colon command-line screen. */
name|void
modifier|*
name|cl_private
decl_stmt|;
comment|/* Curses support private area. */
comment|/* File references. */
name|TAILQ_HEAD
argument_list|(
argument|_frefh
argument_list|,
argument|_fref
argument_list|)
name|frefq
index|[
literal|1
index|]
expr_stmt|;
define|#
directive|define
name|GO_COLUMNS
value|0
comment|/* Global options: columns. */
define|#
directive|define
name|GO_LINES
value|1
comment|/* Global options: lines. */
define|#
directive|define
name|GO_SECURE
value|2
comment|/* Global options: secure. */
define|#
directive|define
name|GO_TERM
value|3
comment|/* Global options: terminal type. */
name|OPTION
name|opts
index|[
name|GO_TERM
operator|+
literal|1
index|]
decl_stmt|;
name|nl_catd
name|catd
decl_stmt|;
comment|/* Message catalog descriptor. */
name|MSGH
name|msgq
index|[
literal|1
index|]
decl_stmt|;
comment|/* User message list. */
define|#
directive|define
name|DEFAULT_NOPRINT
value|'\1'
comment|/* Emergency non-printable character. */
name|int
name|noprint
decl_stmt|;
comment|/* Cached, unprintable character. */
name|char
modifier|*
name|tmp_bp
decl_stmt|;
comment|/* Temporary buffer. */
name|size_t
name|tmp_blen
decl_stmt|;
comment|/* Temporary buffer size. */
comment|/* 	 * Ex command structures (EXCMD).  Defined here because ex commands 	 * exist outside of any particular screen or file. 	 */
define|#
directive|define
name|EXCMD_RUNNING
parameter_list|(
name|gp
parameter_list|)
value|(SLIST_FIRST((gp)->ecq)->clen != 0)
comment|/* Ex command linked list. */
name|SLIST_HEAD
argument_list|(
argument|_excmdh
argument_list|,
argument|_excmd
argument_list|)
name|ecq
index|[
literal|1
index|]
expr_stmt|;
name|EXCMD
name|excmd
decl_stmt|;
comment|/* Default ex command structure. */
name|char
modifier|*
name|if_name
decl_stmt|;
comment|/* Current associated file. */
name|recno_t
name|if_lno
decl_stmt|;
comment|/* Current associated line number. */
name|char
modifier|*
name|c_option
decl_stmt|;
comment|/* Ex initial, command-line command. */
ifdef|#
directive|ifdef
name|DEBUG
name|FILE
modifier|*
name|tracefp
decl_stmt|;
comment|/* Trace file pointer. */
endif|#
directive|endif
name|EVENT
modifier|*
name|i_event
decl_stmt|;
comment|/* Array of input events. */
name|size_t
name|i_nelem
decl_stmt|;
comment|/* Number of array elements. */
name|size_t
name|i_cnt
decl_stmt|;
comment|/* Count of events. */
name|size_t
name|i_next
decl_stmt|;
comment|/* Offset of next event. */
name|CB
modifier|*
name|dcbp
decl_stmt|;
comment|/* Default cut buffer pointer. */
name|CB
name|dcb_store
decl_stmt|;
comment|/* Default cut buffer storage. */
name|SLIST_HEAD
argument_list|(
argument|_cuth
argument_list|,
argument|_cb
argument_list|)
name|cutq
index|[
literal|1
index|]
expr_stmt|;
comment|/* Linked list of cut buffers. */
define|#
directive|define
name|MAX_BIT_SEQ
value|0x7f
comment|/* Max + 1 fast check character. */
name|SLIST_HEAD
argument_list|(
argument|_seqh
argument_list|,
argument|_seq
argument_list|)
name|seqq
index|[
literal|1
index|]
expr_stmt|;
comment|/* Linked list of maps, abbrevs. */
name|bitstr_t
name|bit_decl
argument_list|(
name|seqb
argument_list|,
name|MAX_BIT_SEQ
operator|+
literal|1
argument_list|)
decl_stmt|;
define|#
directive|define
name|MAX_FAST_KEY
value|0xff
comment|/* Max fast check character.*/
define|#
directive|define
name|KEY_LEN
parameter_list|(
name|sp
parameter_list|,
name|ch
parameter_list|)
define|\
value|(((ch)& ~MAX_FAST_KEY) == 0 ?					\ 	    sp->gp->cname[(unsigned char)ch].len : v_key_len(sp, ch))
define|#
directive|define
name|KEY_NAME
parameter_list|(
name|sp
parameter_list|,
name|ch
parameter_list|)
define|\
value|(((ch)& ~MAX_FAST_KEY) == 0 ?					\ 	    sp->gp->cname[(unsigned char)ch].name : v_key_name(sp, ch))
struct|struct
block|{
name|char
name|name
index|[
name|MAX_CHARACTER_COLUMNS
operator|+
literal|1
index|]
decl_stmt|;
name|u_int8_t
name|len
decl_stmt|;
block|}
name|cname
index|[
name|MAX_FAST_KEY
operator|+
literal|1
index|]
struct|;
comment|/* Fast lookup table. */
define|#
directive|define
name|KEY_VAL
parameter_list|(
name|sp
parameter_list|,
name|ch
parameter_list|)
define|\
value|(((ch)& ~MAX_FAST_KEY) == 0 ? 					\ 	    sp->gp->special_key[(unsigned char)ch] : v_key_val(sp,ch))
name|e_key_t
comment|/* Fast lookup table. */
name|special_key
index|[
name|MAX_FAST_KEY
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Flags. */
define|#
directive|define
name|G_ABBREV
value|0x0001
comment|/* If have abbreviations. */
define|#
directive|define
name|G_BELLSCHED
value|0x0002
comment|/* Bell scheduled. */
define|#
directive|define
name|G_INTERRUPTED
value|0x0004
comment|/* Interrupted. */
define|#
directive|define
name|G_RECOVER_SET
value|0x0008
comment|/* Recover system initialized. */
define|#
directive|define
name|G_SCRIPTED
value|0x0010
comment|/* Ex script session. */
define|#
directive|define
name|G_SCRWIN
value|0x0020
comment|/* Scripting windows running. */
define|#
directive|define
name|G_SNAPSHOT
value|0x0040
comment|/* Always snapshot files. */
define|#
directive|define
name|G_SRESTART
value|0x0080
comment|/* Screen restarted. */
define|#
directive|define
name|G_TMP_INUSE
value|0x0100
comment|/* Temporary buffer in use. */
name|u_int32_t
name|flags
decl_stmt|;
comment|/* Screen interface functions. */
comment|/* Add a string to the screen. */
name|int
function_decl|(
modifier|*
name|scr_addstr
function_decl|)
parameter_list|(
name|SCR
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
comment|/* Add a string to the screen. */
name|int
function_decl|(
modifier|*
name|scr_waddstr
function_decl|)
parameter_list|(
name|SCR
modifier|*
parameter_list|,
specifier|const
name|CHAR_T
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
comment|/* Toggle a screen attribute. */
name|int
function_decl|(
modifier|*
name|scr_attr
function_decl|)
parameter_list|(
name|SCR
modifier|*
parameter_list|,
name|scr_attr_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* Terminal baud rate. */
name|int
function_decl|(
modifier|*
name|scr_baud
function_decl|)
parameter_list|(
name|SCR
modifier|*
parameter_list|,
name|u_long
modifier|*
parameter_list|)
function_decl|;
comment|/* Beep/bell/flash the terminal. */
name|int
function_decl|(
modifier|*
name|scr_bell
function_decl|)
parameter_list|(
name|SCR
modifier|*
parameter_list|)
function_decl|;
comment|/* Display a busy message. */
name|void
function_decl|(
modifier|*
name|scr_busy
function_decl|)
parameter_list|(
name|SCR
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|busy_t
parameter_list|)
function_decl|;
comment|/* Prepare child. */
name|int
function_decl|(
modifier|*
name|scr_child
function_decl|)
parameter_list|(
name|SCR
modifier|*
parameter_list|)
function_decl|;
comment|/* Clear to the end of the line. */
name|int
function_decl|(
modifier|*
name|scr_clrtoeol
function_decl|)
parameter_list|(
name|SCR
modifier|*
parameter_list|)
function_decl|;
comment|/* Return the cursor location. */
name|int
function_decl|(
modifier|*
name|scr_cursor
function_decl|)
parameter_list|(
name|SCR
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
comment|/* Delete a line. */
name|int
function_decl|(
modifier|*
name|scr_deleteln
function_decl|)
parameter_list|(
name|SCR
modifier|*
parameter_list|)
function_decl|;
comment|/* Discard a screen. */
name|int
function_decl|(
modifier|*
name|scr_discard
function_decl|)
parameter_list|(
name|SCR
modifier|*
parameter_list|,
name|SCR
modifier|*
modifier|*
parameter_list|)
function_decl|;
comment|/* Get a keyboard event. */
name|int
function_decl|(
modifier|*
name|scr_event
function_decl|)
parameter_list|(
name|SCR
modifier|*
parameter_list|,
name|EVENT
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* Ex: screen adjustment routine. */
name|int
function_decl|(
modifier|*
name|scr_ex_adjust
function_decl|)
parameter_list|(
name|SCR
modifier|*
parameter_list|,
name|exadj_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|scr_fmap
function_decl|)
comment|/* Set a function key. */
parameter_list|(
name|SCR
modifier|*
parameter_list|,
name|seq_t
parameter_list|,
name|CHAR_T
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|CHAR_T
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
comment|/* Get terminal key value. */
name|int
function_decl|(
modifier|*
name|scr_keyval
function_decl|)
parameter_list|(
name|SCR
modifier|*
parameter_list|,
name|scr_keyval_t
parameter_list|,
name|CHAR_T
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
comment|/* Insert a line. */
name|int
function_decl|(
modifier|*
name|scr_insertln
function_decl|)
parameter_list|(
name|SCR
modifier|*
parameter_list|)
function_decl|;
comment|/* Handle an option change. */
name|int
function_decl|(
modifier|*
name|scr_optchange
function_decl|)
parameter_list|(
name|SCR
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|u_long
modifier|*
parameter_list|)
function_decl|;
comment|/* Move the cursor. */
name|int
function_decl|(
modifier|*
name|scr_move
function_decl|)
parameter_list|(
name|SCR
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
comment|/* Message or ex output. */
name|void
function_decl|(
modifier|*
name|scr_msg
function_decl|)
parameter_list|(
name|SCR
modifier|*
parameter_list|,
name|mtype_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
comment|/* Refresh the screen. */
name|int
function_decl|(
modifier|*
name|scr_refresh
function_decl|)
parameter_list|(
name|SCR
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* Rename the file. */
name|int
function_decl|(
modifier|*
name|scr_rename
function_decl|)
parameter_list|(
name|SCR
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* Reply to an event. */
name|int
function_decl|(
modifier|*
name|scr_reply
function_decl|)
parameter_list|(
name|SCR
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
comment|/* Set the screen type. */
name|int
function_decl|(
modifier|*
name|scr_screen
function_decl|)
parameter_list|(
name|SCR
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
comment|/* Split the screen. */
name|int
function_decl|(
modifier|*
name|scr_split
function_decl|)
parameter_list|(
name|SCR
modifier|*
parameter_list|,
name|SCR
modifier|*
parameter_list|)
function_decl|;
comment|/* Suspend the editor. */
name|int
function_decl|(
modifier|*
name|scr_suspend
function_decl|)
parameter_list|(
name|SCR
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
comment|/* Print usage message. */
name|void
function_decl|(
modifier|*
name|scr_usage
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

end_unit

