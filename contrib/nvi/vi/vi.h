begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1992, 1993, 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  *  * See the LICENSE file for redistribution information.  *  *	@(#)vi.h	10.19 (Berkeley) 6/30/96  */
end_comment

begin_comment
comment|/* Definition of a vi "word". */
end_comment

begin_define
define|#
directive|define
name|inword
parameter_list|(
name|ch
parameter_list|)
value|(isalnum(ch) || (ch) == '_')
end_define

begin_typedef
typedef|typedef
name|struct
name|_vikeys
name|VIKEYS
typedef|;
end_typedef

begin_comment
comment|/* Structure passed around to functions implementing vi commands. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_vicmd
block|{
name|CHAR_T
name|key
decl_stmt|;
comment|/* Command key. */
name|CHAR_T
name|buffer
decl_stmt|;
comment|/* Buffer. */
name|CHAR_T
name|character
decl_stmt|;
comment|/* Character. */
name|u_long
name|count
decl_stmt|;
comment|/* Count. */
name|u_long
name|count2
decl_stmt|;
comment|/* Second count (only used by z). */
name|EVENT
name|ev
decl_stmt|;
comment|/* Associated event. */
define|#
directive|define
name|ISCMD
parameter_list|(
name|p
parameter_list|,
name|key
parameter_list|)
value|((p) ==&vikeys[key])
name|VIKEYS
specifier|const
modifier|*
name|kp
decl_stmt|;
comment|/* Command/Motion VIKEYS entry. */
define|#
directive|define
name|ISMOTION
parameter_list|(
name|vp
parameter_list|)
value|(vp->rkp != NULL&& F_ISSET(vp->rkp, V_MOTION))
name|VIKEYS
specifier|const
modifier|*
name|rkp
decl_stmt|;
comment|/* Related C/M VIKEYS entry. */
comment|/* 	 * Historic vi allowed "dl" when the cursor was on the last column, 	 * deleting the last character, and similarly allowed "dw" when 	 * the cursor was on the last column of the file.  It didn't allow 	 * "dh" when the cursor was on column 1, although these cases are 	 * not strictly analogous.  The point is that some movements would 	 * succeed if they were associated with a motion command, and fail 	 * otherwise.  This is part of the off-by-1 schizophrenia that 	 * plagued vi.  Other examples are that "dfb" deleted everything 	 * up to and including the next 'b' character, while "d/b" deleted 	 * everything up to the next 'b' character.  While this implementation 	 * regularizes the interface to the extent possible, there are many 	 * special cases that can't be fixed.  The special cases are handled 	 * by setting flags per command so that the underlying command and 	 * motion routines know what's really going on. 	 * 	 * The VM_* flags are set in the vikeys array and by the underlying 	 * functions (motion component or command) as well.  For this reason, 	 * the flags in the VICMD and VIKEYS structures live in the same name 	 * space. 	 */
define|#
directive|define
name|VM_CMDFAILED
value|0x00000001
comment|/* Command failed. */
define|#
directive|define
name|VM_CUTREQ
value|0x00000002
comment|/* Always cut into numeric buffers. */
define|#
directive|define
name|VM_LDOUBLE
value|0x00000004
comment|/* Doubled command for line mode. */
define|#
directive|define
name|VM_LMODE
value|0x00000008
comment|/* Motion is line oriented. */
define|#
directive|define
name|VM_COMMASK
value|0x0000000f
comment|/* Mask for VM flags. */
comment|/* 	 * The VM_RCM_* flags are single usage, i.e. if you set one, you have 	 * to clear the others. 	 */
define|#
directive|define
name|VM_RCM
value|0x00000010
comment|/* Use relative cursor movment (RCM). */
define|#
directive|define
name|VM_RCM_SET
value|0x00000020
comment|/* RCM: set to current position. */
define|#
directive|define
name|VM_RCM_SETFNB
value|0x00000040
comment|/* RCM: set to first non-blank (FNB). */
define|#
directive|define
name|VM_RCM_SETLAST
value|0x00000080
comment|/* RCM: set to last character. */
define|#
directive|define
name|VM_RCM_SETNNB
value|0x00000100
comment|/* RCM: set to next non-blank. */
define|#
directive|define
name|VM_RCM_MASK
value|0x000001f0
comment|/* Mask for RCM flags. */
comment|/* Flags for the underlying function. */
define|#
directive|define
name|VC_BUFFER
value|0x00000200
comment|/* The buffer was set. */
define|#
directive|define
name|VC_C1RESET
value|0x00000400
comment|/* Reset C1SET flag for dot commands. */
define|#
directive|define
name|VC_C1SET
value|0x00000800
comment|/* Count 1 was set. */
define|#
directive|define
name|VC_C2SET
value|0x00001000
comment|/* Count 2 was set. */
define|#
directive|define
name|VC_ISDOT
value|0x00002000
comment|/* Command was the dot command. */
name|u_int32_t
name|flags
decl_stmt|;
comment|/* 	 * There are four cursor locations that we worry about: the initial 	 * cursor position, the start of the range, the end of the range, 	 * and the final cursor position.  The initial cursor position and 	 * the start of the range are both m_start, and are always the same. 	 * All locations are initialized to the starting cursor position by 	 * the main vi routines, and the underlying functions depend on this. 	 * 	 * Commands that can be motion components set the end of the range 	 * cursor position, m_stop.  All commands must set the ending cursor 	 * position, m_final.  The reason that m_stop isn't the same as m_final 	 * is that there are situations where the final position of the cursor 	 * is outside of the cut/delete range (e.g. 'd[[' from the first column 	 * of a line).  The final cursor position often varies based on the 	 * direction of the movement, as well as the command.  The only special 	 * case that the delete code handles is that it will make adjustments 	 * if the final cursor position is deleted. 	 * 	 * The reason for all of this is that the historic vi semantics were 	 * defined command-by-command.  Every function has to roll its own 	 * starting and stopping positions, and adjust them if it's being used 	 * as a motion component.  The general rules are as follows: 	 * 	 *	1: If not a motion component, the final cursor is at the end 	 *	   of the range. 	 *	2: If moving backward in the file, delete and yank move the 	 *	   final cursor to the end of the range. 	 *	3: If moving forward in the file, delete and yank leave the 	 *	   final cursor at the start of the range. 	 * 	 * Usually, if moving backward in the file and it's a motion component, 	 * the starting cursor is decremented by a single character (or, in a 	 * few cases, to the end of the previous line) so that the starting 	 * cursor character isn't cut or deleted.  No cursor adjustment is 	 * needed for moving forward, because the cut/delete routines handle 	 * m_stop inclusively, i.e. the last character in the range is cut or 	 * deleted.  This makes cutting to the EOF/EOL reasonable. 	 * 	 * The 'c', '<', '>', and '!' commands are special cases.  We ignore 	 * the final cursor position for all of them: for 'c', the text input 	 * routines set the cursor to the last character inserted; for '<', 	 * '>' and '!', the underlying ex commands that do the operation will 	 * set the cursor for us, usually to something related to the first 	 *<nonblank>. 	 */
name|MARK
name|m_start
decl_stmt|;
comment|/* mark: initial cursor, range start. */
name|MARK
name|m_stop
decl_stmt|;
comment|/* mark: range end. */
name|MARK
name|m_final
decl_stmt|;
comment|/* mark: final cursor position. */
block|}
name|VICMD
typedef|;
end_typedef

begin_comment
comment|/* Vi command table structure. */
end_comment

begin_struct
struct|struct
name|_vikeys
block|{
comment|/* Underlying function. */
name|int
argument_list|(
argument|*func
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|VICMD
operator|*
operator|)
argument_list|)
expr_stmt|;
define|#
directive|define
name|V_ABS
value|0x00004000
comment|/* Absolute movement, set '' mark. */
define|#
directive|define
name|V_ABS_C
value|0x00008000
comment|/* V_ABS: if the line/column changed. */
define|#
directive|define
name|V_ABS_L
value|0x00010000
comment|/* V_ABS: if the line changed. */
define|#
directive|define
name|V_CHAR
value|0x00020000
comment|/* Character (required, trailing). */
define|#
directive|define
name|V_CNT
value|0x00040000
comment|/* Count (optional, leading). */
define|#
directive|define
name|V_DOT
value|0x00080000
comment|/* On success, sets dot command. */
define|#
directive|define
name|V_KEYW
value|0x00100000
comment|/* Cursor referenced word. */
define|#
directive|define
name|V_MOTION
value|0x00200000
comment|/* Motion (required, trailing). */
define|#
directive|define
name|V_MOVE
value|0x00400000
comment|/* Command defines movement. */
define|#
directive|define
name|V_OBUF
value|0x00800000
comment|/* Buffer (optional, leading). */
define|#
directive|define
name|V_RBUF
value|0x01000000
comment|/* Buffer (required, trailing). */
define|#
directive|define
name|V_SECURE
value|0x02000000
comment|/* Permission denied if O_SECURE set. */
name|u_int32_t
name|flags
decl_stmt|;
name|char
modifier|*
name|usage
decl_stmt|;
comment|/* Usage line. */
name|char
modifier|*
name|help
decl_stmt|;
comment|/* Help line. */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAXVIKEY
value|126
end_define

begin_comment
comment|/* List of vi commands. */
end_comment

begin_decl_stmt
specifier|extern
name|VIKEYS
specifier|const
name|vikeys
index|[
name|MAXVIKEY
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|VIKEYS
specifier|const
name|tmotion
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX Hacked ~ command. */
end_comment

begin_comment
comment|/* Character stream structure, prototypes. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_vcs
block|{
name|recno_t
name|cs_lno
decl_stmt|;
comment|/* Line. */
name|size_t
name|cs_cno
decl_stmt|;
comment|/* Column. */
name|CHAR_T
modifier|*
name|cs_bp
decl_stmt|;
comment|/* Buffer. */
name|size_t
name|cs_len
decl_stmt|;
comment|/* Length. */
name|CHAR_T
name|cs_ch
decl_stmt|;
comment|/* Character. */
define|#
directive|define
name|CS_EMP
value|1
comment|/* Empty line. */
define|#
directive|define
name|CS_EOF
value|2
comment|/* End-of-file. */
define|#
directive|define
name|CS_EOL
value|3
comment|/* End-of-line. */
define|#
directive|define
name|CS_SOF
value|4
comment|/* Start-of-file. */
name|int
name|cs_flags
decl_stmt|;
comment|/* Return flags. */
block|}
name|VCS
typedef|;
end_typedef

begin_decl_stmt
name|int
name|cs_bblank
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|VCS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cs_fblank
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|VCS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cs_fspace
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|VCS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cs_init
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|VCS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cs_next
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|VCS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cs_prev
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|VCS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * We use a single "window" for each set of vi screens.  The model would be  * simpler with two windows (one for the text, and one for the modeline)  * because scrolling the text window down would work correctly then, not  * affecting the mode line.  As it is we have to play games to make it look  * right.  The reason for this choice is that it would be difficult for  * curses to optimize the movement, i.e. detect that the downward scroll  * isn't going to change the modeline, set the scrolling region on the  * terminal and only scroll the first part of the text window.  *  * Structure for mapping lines to the screen.  An SMAP is an array, with one  * structure element per screen line, which holds information describing the  * physical line which is displayed in the screen line.  The first two fields  * (lno and off) are all that are necessary to describe a line.  The rest of  * the information is useful to keep information from being re-calculated.  *  * The SMAP always has an entry for each line of the physical screen, plus a  * slot for the colon command line, so there is room to add any screen into  * another one at screen exit.  *  * Lno is the line number.  If doing the historic vi long line folding, off  * is the screen offset into the line.  For example, the pair 2:1 would be  * the first screen of line 2, and 2:2 would be the second.  In the case of  * long lines, the screen map will tend to be staggered, e.g., 1:1, 1:2, 1:3,  * 2:1, 3:1, etc.  If doing left-right scrolling, the off field is the screen  * column offset into the lines, and can take on any value, as it's adjusted  * by the user set value O_SIDESCROLL.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_smap
block|{
name|recno_t
name|lno
decl_stmt|;
comment|/* 1-N: Physical file line number. */
name|size_t
name|coff
decl_stmt|;
comment|/* 0-N: Column offset in the line. */
name|size_t
name|soff
decl_stmt|;
comment|/* 1-N: Screen offset in the line. */
comment|/* vs_line() cache information. */
name|size_t
name|c_sboff
decl_stmt|;
comment|/* 0-N: offset of first character byte. */
name|size_t
name|c_eboff
decl_stmt|;
comment|/* 0-N: offset of  last character byte. */
name|u_int8_t
name|c_scoff
decl_stmt|;
comment|/* 0-N: offset into the first character. */
name|u_int8_t
name|c_eclen
decl_stmt|;
comment|/* 1-N: columns from the last character. */
name|u_int8_t
name|c_ecsize
decl_stmt|;
comment|/* 1-N: size of the last character. */
block|}
name|SMAP
typedef|;
end_typedef

begin_comment
comment|/* Macros to flush/test cached information. */
end_comment

begin_define
define|#
directive|define
name|SMAP_CACHE
parameter_list|(
name|smp
parameter_list|)
value|((smp)->c_ecsize != 0)
end_define

begin_define
define|#
directive|define
name|SMAP_FLUSH
parameter_list|(
name|smp
parameter_list|)
value|((smp)->c_ecsize = 0)
end_define

begin_comment
comment|/* Character search information. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CNOTSET
block|,
name|FSEARCH
block|,
name|fSEARCH
block|,
name|TSEARCH
block|,
name|tSEARCH
block|}
name|cdir_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|AB_NOTSET
block|,
name|AB_NOTWORD
block|,
name|AB_INWORD
block|}
name|abb_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|Q_NOTSET
block|,
name|Q_BNEXT
block|,
name|Q_BTHIS
block|,
name|Q_VNEXT
block|,
name|Q_VTHIS
block|}
name|quote_t
typedef|;
end_typedef

begin_comment
comment|/* Vi private, per-screen memory. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_vi_private
block|{
name|VICMD
name|cmd
decl_stmt|;
comment|/* Current command, motion. */
name|VICMD
name|motion
decl_stmt|;
comment|/* 	 * !!! 	 * The saved command structure can be modified by the underlying 	 * vi functions, see v_Put() and v_put(). 	 */
name|VICMD
name|sdot
decl_stmt|;
comment|/* Saved dot, motion command. */
name|VICMD
name|sdotmotion
decl_stmt|;
name|CHAR_T
modifier|*
name|keyw
decl_stmt|;
comment|/* Keyword buffer. */
name|size_t
name|klen
decl_stmt|;
comment|/* Keyword length. */
name|size_t
name|keywlen
decl_stmt|;
comment|/* Keyword buffer length. */
name|CHAR_T
name|rlast
decl_stmt|;
comment|/* Last 'r' replacement character. */
name|e_key_t
name|rvalue
decl_stmt|;
comment|/* Value of last replacement character. */
name|EVENT
modifier|*
name|rep
decl_stmt|;
comment|/* Input replay buffer. */
name|size_t
name|rep_len
decl_stmt|;
comment|/* Input replay buffer length. */
name|size_t
name|rep_cnt
decl_stmt|;
comment|/* Input replay buffer characters. */
name|mtype_t
name|mtype
decl_stmt|;
comment|/* Last displayed message type. */
name|size_t
name|linecount
decl_stmt|;
comment|/* 1-N: Output overwrite count. */
name|size_t
name|lcontinue
decl_stmt|;
comment|/* 1-N: Output line continue value. */
name|size_t
name|totalcount
decl_stmt|;
comment|/* 1-N: Output overwrite count. */
comment|/* Busy state. */
name|int
name|busy_ref
decl_stmt|;
comment|/* Busy reference count. */
name|int
name|busy_ch
decl_stmt|;
comment|/* Busy character. */
name|size_t
name|busy_fx
decl_stmt|;
comment|/* Busy character x coordinate. */
name|size_t
name|busy_oldy
decl_stmt|;
comment|/* Saved y coordinate. */
name|size_t
name|busy_oldx
decl_stmt|;
comment|/* Saved x coordinate. */
name|struct
name|timeval
name|busy_tv
decl_stmt|;
comment|/* Busy timer. */
name|char
modifier|*
name|ps
decl_stmt|;
comment|/* Paragraph plus section list. */
name|u_long
name|u_ccnt
decl_stmt|;
comment|/* Undo command count. */
name|CHAR_T
name|lastckey
decl_stmt|;
comment|/* Last search character. */
name|cdir_t
name|csearchdir
decl_stmt|;
comment|/* Character search direction. */
name|SMAP
modifier|*
name|h_smap
decl_stmt|;
comment|/* First slot of the line map. */
name|SMAP
modifier|*
name|t_smap
decl_stmt|;
comment|/* Last slot of the line map. */
comment|/* 	 * One extra slot is always allocated for the map so that we can use 	 * it to do vi :colon command input; see v_tcmd(). 	 */
name|recno_t
name|sv_tm_lno
decl_stmt|;
comment|/* tcmd: saved TMAP lno field. */
name|size_t
name|sv_tm_coff
decl_stmt|;
comment|/* tcmd: saved TMAP coff field. */
name|size_t
name|sv_tm_soff
decl_stmt|;
comment|/* tcmd: saved TMAP soff field. */
name|size_t
name|sv_t_maxrows
decl_stmt|;
comment|/* tcmd: saved t_maxrows. */
name|size_t
name|sv_t_minrows
decl_stmt|;
comment|/* tcmd: saved t_minrows. */
name|size_t
name|sv_t_rows
decl_stmt|;
comment|/* tcmd: saved t_rows. */
define|#
directive|define
name|SIZE_HMAP
parameter_list|(
name|sp
parameter_list|)
value|(VIP(sp)->srows + 1)
comment|/* 	 * Macros to get to the head/tail of the smap.  If the screen only has 	 * one line, HMAP can be equal to TMAP, so the code has to understand 	 * the off-by-one errors that can result.  If stepping through an SMAP 	 * and operating on each entry, use sp->t_rows as the count of slots, 	 * don't use a loop that compares<= TMAP. 	 */
define|#
directive|define
name|_HMAP
parameter_list|(
name|sp
parameter_list|)
value|(VIP(sp)->h_smap)
define|#
directive|define
name|HMAP
value|_HMAP(sp)
define|#
directive|define
name|_TMAP
parameter_list|(
name|sp
parameter_list|)
value|(VIP(sp)->t_smap)
define|#
directive|define
name|TMAP
value|_TMAP(sp)
name|recno_t
name|ss_lno
decl_stmt|;
comment|/* 1-N: vi_opt_screens cached line number. */
name|size_t
name|ss_screens
decl_stmt|;
comment|/* vi_opt_screens cached return value. */
define|#
directive|define
name|VI_SCR_CFLUSH
parameter_list|(
name|vip
parameter_list|)
value|vip->ss_lno = OOBLNO
name|size_t
name|srows
decl_stmt|;
comment|/* 1-N: rows in the terminal/window. */
name|recno_t
name|olno
decl_stmt|;
comment|/* 1-N: old cursor file line. */
name|size_t
name|ocno
decl_stmt|;
comment|/* 0-N: old file cursor column. */
name|size_t
name|sc_col
decl_stmt|;
comment|/* 0-N: LOGICAL screen column. */
name|SMAP
modifier|*
name|sc_smap
decl_stmt|;
comment|/* SMAP entry where sc_col occurs. */
define|#
directive|define
name|VIP_CUR_INVALID
value|0x0001
comment|/* Cursor position is unknown. */
define|#
directive|define
name|VIP_DIVIDER
value|0x0002
comment|/* Divider line was displayed. */
define|#
directive|define
name|VIP_N_EX_PAINT
value|0x0004
comment|/* Clear and repaint when ex finishes. */
define|#
directive|define
name|VIP_N_EX_REDRAW
value|0x0008
comment|/* Schedule SC_SCR_REDRAW when ex finishes. */
define|#
directive|define
name|VIP_N_REFRESH
value|0x0010
comment|/* Repaint (from SMAP) on the next refresh. */
define|#
directive|define
name|VIP_N_RENUMBER
value|0x0020
comment|/* Renumber screen on the next refresh. */
define|#
directive|define
name|VIP_RCM_LAST
value|0x0040
comment|/* Cursor drawn to the last column. */
define|#
directive|define
name|VIP_S_MODELINE
value|0x0080
comment|/* Skip next modeline refresh. */
define|#
directive|define
name|VIP_S_REFRESH
value|0x0100
comment|/* Skip next refresh. */
name|u_int16_t
name|flags
decl_stmt|;
block|}
name|VI_PRIVATE
typedef|;
end_typedef

begin_comment
comment|/* Vi private area. */
end_comment

begin_define
define|#
directive|define
name|VIP
parameter_list|(
name|sp
parameter_list|)
value|((VI_PRIVATE *)((sp)->vi_private))
end_define

begin_define
define|#
directive|define
name|O_NUMBER_FMT
value|"%7lu "
end_define

begin_comment
comment|/* O_NUMBER format, length. */
end_comment

begin_define
define|#
directive|define
name|O_NUMBER_LENGTH
value|8
end_define

begin_define
define|#
directive|define
name|SCREEN_COLS
parameter_list|(
name|sp
parameter_list|)
comment|/* Screen columns. */
define|\
value|((O_ISSET(sp, O_NUMBER) ? (sp)->cols - O_NUMBER_LENGTH : (sp)->cols))
end_define

begin_comment
comment|/*  * LASTLINE is the zero-based, last line in the screen.  Note that it is correct  * regardless of the changes in the screen to permit text input on the last line  * of the screen, or the existence of small screens.  */
end_comment

begin_define
define|#
directive|define
name|LASTLINE
parameter_list|(
name|sp
parameter_list|)
define|\
value|((sp)->t_maxrows< (sp)->rows ? (sp)->t_maxrows : (sp)->rows - 1)
end_define

begin_comment
comment|/*  * Small screen (see vs_refresh.c, section 6a) and one-line screen test.  * Note, both cannot be true for the same screen.  */
end_comment

begin_define
define|#
directive|define
name|IS_SMALL
parameter_list|(
name|sp
parameter_list|)
value|((sp)->t_minrows != (sp)->t_maxrows)
end_define

begin_define
define|#
directive|define
name|IS_ONELINE
parameter_list|(
name|sp
parameter_list|)
value|((sp)->rows == 1)
end_define

begin_define
define|#
directive|define
name|HALFTEXT
parameter_list|(
name|sp
parameter_list|)
comment|/* Half text. */
define|\
value|((sp)->t_rows == 1 ? 1 : (sp)->t_rows / 2)
end_define

begin_define
define|#
directive|define
name|HALFSCREEN
parameter_list|(
name|sp
parameter_list|)
comment|/* Half text screen. */
define|\
value|((sp)->t_maxrows == 1 ? 1 : (sp)->t_maxrows / 2)
end_define

begin_comment
comment|/*  * Next tab offset.  *  * !!!  * There are problems with how the historical vi handled tabs.  For example,  * by doing "set ts=3" and building lines that fold, you can get it to step  * through tabs as if they were spaces and move inserted characters to new  * positions when<esc> is entered.  I believe that nvi does tabs correctly,  * but there are some historical incompatibilities.  */
end_comment

begin_define
define|#
directive|define
name|TAB_OFF
parameter_list|(
name|c
parameter_list|)
value|COL_OFF((c), O_VAL(sp, O_TABSTOP))
end_define

begin_comment
comment|/* If more than one screen being shown. */
end_comment

begin_define
define|#
directive|define
name|IS_SPLIT
parameter_list|(
name|sp
parameter_list|)
define|\
value|((sp)->q.cqe_next != (void *)&(sp)->gp->dq ||			\ 	(sp)->q.cqe_prev != (void *)&(sp)->gp->dq)
end_define

begin_comment
comment|/* Screen adjustment operations. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|A_DECREASE
block|,
name|A_INCREASE
block|,
name|A_SET
block|}
name|adj_t
typedef|;
end_typedef

begin_comment
comment|/* Screen position operations. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|P_BOTTOM
block|,
name|P_FILL
block|,
name|P_MIDDLE
block|,
name|P_TOP
block|}
name|pos_t
typedef|;
end_typedef

begin_comment
comment|/* Scrolling operations. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CNTRL_B
block|,
name|CNTRL_D
block|,
name|CNTRL_E
block|,
name|CNTRL_F
block|,
name|CNTRL_U
block|,
name|CNTRL_Y
block|,
name|Z_CARAT
block|,
name|Z_PLUS
block|}
name|scroll_t
typedef|;
end_typedef

begin_comment
comment|/* Vi common error messages. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|VIM_COMBUF
block|,
name|VIM_EMPTY
block|,
name|VIM_EOF
block|,
name|VIM_EOL
block|,
name|VIM_NOCOM
block|,
name|VIM_NOCOM_B
block|,
name|VIM_USAGE
block|,
name|VIM_WRESIZE
block|}
name|vim_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"vi_extern.h"
end_include

end_unit

