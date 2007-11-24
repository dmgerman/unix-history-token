begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1993, 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  *  * See the LICENSE file for redistribution information.  *  *	@(#)gs.h	10.34 (Berkeley) 9/24/96  */
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

begin_comment
comment|/*  * File reference structure (FREF).  The structure contains the name of the  * file, along with the information that follows the name.  *  * !!!  * The read-only bit follows the file name, not the file itself.  */
end_comment

begin_struct
struct|struct
name|_fref
block|{
name|CIRCLEQ_ENTRY
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
name|CIRCLEQ_HEAD
argument_list|(
argument|_dqh
argument_list|,
argument|_scr
argument_list|)
name|dq
expr_stmt|;
comment|/* Displayed screens. */
name|CIRCLEQ_HEAD
argument_list|(
argument|_hqh
argument_list|,
argument|_scr
argument_list|)
name|hq
expr_stmt|;
comment|/* Hidden screens. */
name|SCR
modifier|*
name|ccl_sp
decl_stmt|;
comment|/* Colon command-line screen. */
name|void
modifier|*
name|perl_interp
decl_stmt|;
comment|/* Perl interpreter. */
name|void
modifier|*
name|tcl_interp
decl_stmt|;
comment|/* Tcl_Interp *: Tcl interpreter. */
name|void
modifier|*
name|cl_private
decl_stmt|;
comment|/* Curses support private area. */
name|void
modifier|*
name|ip_private
decl_stmt|;
comment|/* IP support private area. */
name|void
modifier|*
name|tk_private
decl_stmt|;
comment|/* Tk/Tcl support private area. */
comment|/* File references. */
name|CIRCLEQ_HEAD
argument_list|(
argument|_frefh
argument_list|,
argument|_fref
argument_list|)
name|frefq
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
name|DB
modifier|*
name|msg
decl_stmt|;
comment|/* Message catalog DB. */
name|MSGH
name|msgq
decl_stmt|;
comment|/* User message list. */
define|#
directive|define
name|DEFAULT_NOPRINT
value|'\1'
comment|/* Emergency non-printable character. */
name|CHAR_T
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
value|((gp)->ecq.lh_first->clen != 0)
name|LIST_HEAD
argument_list|(
argument|_excmdh
argument_list|,
argument|_excmd
argument_list|)
name|ecq
expr_stmt|;
comment|/* Ex command linked list. */
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
name|LIST_HEAD
argument_list|(
argument|_cuth
argument_list|,
argument|_cb
argument_list|)
name|cutq
expr_stmt|;
comment|/* Linked list of cut buffers. */
define|#
directive|define
name|MAX_BIT_SEQ
value|128
comment|/* Max + 1 fast check character. */
name|LIST_HEAD
argument_list|(
argument|_seqh
argument_list|,
argument|_seq
argument_list|)
name|seqq
expr_stmt|;
comment|/* Linked list of maps, abbrevs. */
name|bitstr_t
name|bit_decl
parameter_list|(
name|seqb
parameter_list|,
name|MAX_BIT_SEQ
parameter_list|)
function_decl|;
define|#
directive|define
name|MAX_FAST_KEY
value|254
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
value|((unsigned char)(ch)<= MAX_FAST_KEY ?				\ 	    sp->gp->cname[(unsigned char)ch].len : v_key_len(sp, ch))
define|#
directive|define
name|KEY_NAME
parameter_list|(
name|sp
parameter_list|,
name|ch
parameter_list|)
define|\
value|((unsigned char)(ch)<= MAX_FAST_KEY ?				\ 	    sp->gp->cname[(unsigned char)ch].name : v_key_name(sp, ch))
struct|struct
block|{
name|CHAR_T
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
value|((unsigned char)(ch)<= MAX_FAST_KEY ? 				\ 	    sp->gp->special_key[(unsigned char)ch] :			\ 	    (unsigned char)(ch)> sp->gp->max_special ? 0 : v_key_val(sp,ch))
name|CHAR_T
name|max_special
decl_stmt|;
comment|/* Max special character. */
name|u_char
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
argument_list|(
argument|*scr_addstr
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
expr_stmt|;
comment|/* Toggle a screen attribute. */
name|int
argument_list|(
argument|*scr_attr
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|scr_attr_t
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Terminal baud rate. */
name|int
argument_list|(
argument|*scr_baud
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|u_long
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Beep/bell/flash the terminal. */
name|int
argument_list|(
argument|*scr_bell
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Display a busy message. */
name|void
argument_list|(
argument|*scr_busy
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|busy_t
operator|)
argument_list|)
expr_stmt|;
comment|/* Clear to the end of the line. */
name|int
argument_list|(
argument|*scr_clrtoeol
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Return the cursor location. */
name|int
argument_list|(
argument|*scr_cursor
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|size_t
operator|*
operator|,
name|size_t
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Delete a line. */
name|int
argument_list|(
argument|*scr_deleteln
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Get a keyboard event. */
name|int
argument_list|(
argument|*scr_event
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EVENT
operator|*
operator|,
name|u_int32_t
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Ex: screen adjustment routine. */
name|int
argument_list|(
argument|*scr_ex_adjust
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|exadj_t
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*scr_fmap
argument_list|)
comment|/* Set a function key. */
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|seq_t
operator|,
name|CHAR_T
operator|*
operator|,
name|size_t
operator|,
name|CHAR_T
operator|*
operator|,
name|size_t
operator|)
argument_list|)
expr_stmt|;
comment|/* Get terminal key value. */
name|int
argument_list|(
argument|*scr_keyval
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|scr_keyval_t
operator|,
name|CHAR_T
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Insert a line. */
name|int
argument_list|(
argument|*scr_insertln
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Handle an option change. */
name|int
argument_list|(
argument|*scr_optchange
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|u_long
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Move the cursor. */
name|int
argument_list|(
argument|*scr_move
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|size_t
operator|,
name|size_t
operator|)
argument_list|)
expr_stmt|;
comment|/* Message or ex output. */
name|void
argument_list|(
argument|*scr_msg
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|mtype_t
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
expr_stmt|;
comment|/* Refresh the screen. */
name|int
argument_list|(
argument|*scr_refresh
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Rename the file. */
name|int
argument_list|(
argument|*scr_rename
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Set the screen type. */
name|int
argument_list|(
argument|*scr_screen
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|u_int32_t
operator|)
argument_list|)
expr_stmt|;
comment|/* Suspend the editor. */
name|int
argument_list|(
argument|*scr_suspend
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Print usage message. */
name|void
argument_list|(
argument|*scr_usage
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * XXX  * Block signals if there are asynchronous events.  Used to keep DB system calls  * from being interrupted and not restarted, as that will result in consistency  * problems.  This should be handled by DB.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BLOCK_SIGNALS
end_ifdef

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_decl_stmt
specifier|extern
name|sigset_t
name|__sigblockset
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SIGBLOCK
define|\
value|(void)sigprocmask(SIG_BLOCK,&__sigblockset, NULL)
end_define

begin_define
define|#
directive|define
name|SIGUNBLOCK
define|\
value|(void)sigprocmask(SIG_UNBLOCK,&__sigblockset, NULL);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIGBLOCK
end_define

begin_define
define|#
directive|define
name|SIGUNBLOCK
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

