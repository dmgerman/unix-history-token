begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1992, 1993, 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  *  * See the LICENSE file for redistribution information.  *  *	@(#)ex.h	10.24 (Berkeley) 8/12/96  */
end_comment

begin_define
define|#
directive|define
name|PROMPTCHAR
value|':'
end_define

begin_comment
comment|/* Prompt using a colon. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_excmdlist
block|{
comment|/* Ex command table structure. */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Command name, underlying function. */
name|int
argument_list|(
argument|*fn
argument_list|)
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXCMD
operator|*
operator|)
argument_list|)
expr_stmt|;
define|#
directive|define
name|E_ADDR1
value|0x00000001
comment|/* One address. */
define|#
directive|define
name|E_ADDR2
value|0x00000002
comment|/* Two addresses. */
define|#
directive|define
name|E_ADDR2_ALL
value|0x00000004
comment|/* Zero/two addresses; zero == all. */
define|#
directive|define
name|E_ADDR2_NONE
value|0x00000008
comment|/* Zero/two addresses; zero == none. */
define|#
directive|define
name|E_ADDR_ZERO
value|0x00000010
comment|/* 0 is a legal addr1. */
define|#
directive|define
name|E_ADDR_ZERODEF
value|0x00000020
comment|/* 0 is default addr1 of empty files. */
define|#
directive|define
name|E_AUTOPRINT
value|0x00000040
comment|/* Command always sets autoprint. */
define|#
directive|define
name|E_CLRFLAG
value|0x00000080
comment|/* Clear the print (#, l, p) flags. */
define|#
directive|define
name|E_NEWSCREEN
value|0x00000100
comment|/* Create a new screen. */
define|#
directive|define
name|E_SECURE
value|0x00000200
comment|/* Permission denied if O_SECURE set. */
define|#
directive|define
name|E_VIONLY
value|0x00000400
comment|/* Meaningful only in vi. */
define|#
directive|define
name|__INUSE1
value|0xfffff800
comment|/* Same name space as EX_PRIVATE. */
name|u_int16_t
name|flags
decl_stmt|;
name|char
modifier|*
name|syntax
decl_stmt|;
comment|/* Syntax script. */
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
name|EXCMDLIST
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAXCMDNAMELEN
value|12
end_define

begin_comment
comment|/* Longest command name. */
end_comment

begin_decl_stmt
specifier|extern
name|EXCMDLIST
specifier|const
name|cmds
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Table of ex commands. */
end_comment

begin_comment
comment|/*  * !!!  * QUOTING NOTE:  *  * Historically, .exrc files and EXINIT variables could only use ^V as an  * escape character, neither ^Q or a user specified character worked.  We  * enforce that here, just in case someone depends on it.  */
end_comment

begin_define
define|#
directive|define
name|IS_ESCAPE
parameter_list|(
name|sp
parameter_list|,
name|cmdp
parameter_list|,
name|ch
parameter_list|)
define|\
value|(F_ISSET(cmdp, E_VLITONLY) ?					\ 	    (ch) == CH_LITERAL : KEY_VAL(sp, ch) == K_VLNEXT)
end_define

begin_comment
comment|/*  * File state must be checked for each command -- any ex command may be entered  * at any time, and most of them won't work well if a file hasn't yet been read  * in.  Historic vi generally took the easy way out and dropped core.  */
end_comment

begin_define
define|#
directive|define
name|NEEDFILE
parameter_list|(
name|sp
parameter_list|,
name|cmdp
parameter_list|)
value|{						\ 	if ((sp)->ep == NULL) {						\ 		ex_emsg(sp, (cmdp)->cmd->name, EXM_NOFILEYET);		\ 		return (1);						\ 	}								\ }
end_define

begin_comment
comment|/* Range structures for global and @ commands. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_range
name|RANGE
typedef|;
end_typedef

begin_struct
struct|struct
name|_range
block|{
comment|/* Global command range. */
name|CIRCLEQ_ENTRY
argument_list|(
argument|_range
argument_list|)
name|q
expr_stmt|;
comment|/* Linked list of ranges. */
name|recno_t
name|start
decl_stmt|,
name|stop
decl_stmt|;
comment|/* Start/stop of the range. */
block|}
struct|;
end_struct

begin_comment
comment|/* Ex command structure. */
end_comment

begin_struct
struct|struct
name|_excmd
block|{
name|LIST_ENTRY
argument_list|(
argument|_excmd
argument_list|)
name|q
expr_stmt|;
comment|/* Linked list of commands. */
name|char
modifier|*
name|if_name
decl_stmt|;
comment|/* Associated file. */
name|recno_t
name|if_lno
decl_stmt|;
comment|/* Associated line number. */
comment|/* Clear the structure for the ex parser. */
define|#
directive|define
name|CLEAR_EX_PARSER
parameter_list|(
name|cmdp
parameter_list|)
define|\
value|memset(&((cmdp)->cp), 0, ((char *)&(cmdp)->flags -		\ 	    (char *)&((cmdp)->cp)) + sizeof((cmdp)->flags))
name|char
modifier|*
name|cp
decl_stmt|;
comment|/* Current command text. */
name|size_t
name|clen
decl_stmt|;
comment|/* Current command length. */
name|char
modifier|*
name|save_cmd
decl_stmt|;
comment|/* Remaining command. */
name|size_t
name|save_cmdlen
decl_stmt|;
comment|/* Remaining command length. */
name|EXCMDLIST
specifier|const
modifier|*
name|cmd
decl_stmt|;
comment|/* Command: entry in command table. */
name|EXCMDLIST
name|rcmd
decl_stmt|;
comment|/* Command: table entry/replacement. */
name|CIRCLEQ_HEAD
argument_list|(
argument|_rh
argument_list|,
argument|_range
argument_list|)
name|rq
expr_stmt|;
comment|/* @/global range: linked list. */
name|recno_t
name|range_lno
decl_stmt|;
comment|/* @/global range: set line number. */
name|char
modifier|*
name|o_cp
decl_stmt|;
comment|/* Original @/global command. */
name|size_t
name|o_clen
decl_stmt|;
comment|/* Original @/global command length. */
define|#
directive|define
name|AGV_AT
value|0x01
comment|/* @ buffer execution. */
define|#
directive|define
name|AGV_AT_NORANGE
value|0x02
comment|/* @ buffer execution without range. */
define|#
directive|define
name|AGV_GLOBAL
value|0x04
comment|/* global command. */
define|#
directive|define
name|AGV_V
value|0x08
comment|/* v command. */
define|#
directive|define
name|AGV_ALL
value|(AGV_AT | AGV_AT_NORANGE | AGV_GLOBAL | AGV_V)
name|u_int8_t
name|agv_flags
decl_stmt|;
comment|/* Clear the structure before each ex command. */
define|#
directive|define
name|CLEAR_EX_CMD
parameter_list|(
name|cmdp
parameter_list|)
value|{						\ 	u_int32_t L__f = F_ISSET(cmdp, E_PRESERVE);			\ 	memset(&((cmdp)->buffer), 0, ((char *)&(cmdp)->flags -		\ 	    (char *)&((cmdp)->buffer)) + sizeof((cmdp)->flags));	\ 	F_SET(cmdp, L__f);						\ }
name|CHAR_T
name|buffer
decl_stmt|;
comment|/* Command: named buffer. */
name|recno_t
name|lineno
decl_stmt|;
comment|/* Command: line number. */
name|long
name|count
decl_stmt|;
comment|/* Command: signed count. */
name|long
name|flagoff
decl_stmt|;
comment|/* Command: signed flag offset. */
name|int
name|addrcnt
decl_stmt|;
comment|/* Command: addresses (0, 1 or 2). */
name|MARK
name|addr1
decl_stmt|;
comment|/* Command: 1st address. */
name|MARK
name|addr2
decl_stmt|;
comment|/* Command: 2nd address. */
name|ARGS
modifier|*
modifier|*
name|argv
decl_stmt|;
comment|/* Command: array of arguments. */
name|int
name|argc
decl_stmt|;
comment|/* Command: count of arguments. */
define|#
directive|define
name|E_C_BUFFER
value|0x00001
comment|/* Buffer name specified. */
define|#
directive|define
name|E_C_CARAT
value|0x00002
comment|/*  ^ flag. */
define|#
directive|define
name|E_C_COUNT
value|0x00004
comment|/* Count specified. */
define|#
directive|define
name|E_C_COUNT_NEG
value|0x00008
comment|/* Count was signed negative. */
define|#
directive|define
name|E_C_COUNT_POS
value|0x00010
comment|/* Count was signed positive. */
define|#
directive|define
name|E_C_DASH
value|0x00020
comment|/*  - flag. */
define|#
directive|define
name|E_C_DOT
value|0x00040
comment|/*  . flag. */
define|#
directive|define
name|E_C_EQUAL
value|0x00080
comment|/*  = flag. */
define|#
directive|define
name|E_C_FORCE
value|0x00100
comment|/*  ! flag. */
define|#
directive|define
name|E_C_HASH
value|0x00200
comment|/*  # flag. */
define|#
directive|define
name|E_C_LIST
value|0x00400
comment|/*  l flag. */
define|#
directive|define
name|E_C_PLUS
value|0x00800
comment|/*  + flag. */
define|#
directive|define
name|E_C_PRINT
value|0x01000
comment|/*  p flag. */
name|u_int16_t
name|iflags
decl_stmt|;
comment|/* User input information. */
define|#
directive|define
name|__INUSE2
value|0x000004ff
comment|/* Same name space as EXCMDLIST. */
define|#
directive|define
name|E_BLIGNORE
value|0x00000800
comment|/* Ignore blank lines. */
define|#
directive|define
name|E_NAMEDISCARD
value|0x00001000
comment|/* Free/discard the name. */
define|#
directive|define
name|E_NOAUTO
value|0x00002000
comment|/* Don't do autoprint output. */
define|#
directive|define
name|E_NOPRDEF
value|0x00004000
comment|/* Don't print as default. */
define|#
directive|define
name|E_NRSEP
value|0x00008000
comment|/* Need to line adjust ex output. */
define|#
directive|define
name|E_OPTNUM
value|0x00010000
comment|/* Number edit option affected. */
define|#
directive|define
name|E_VLITONLY
value|0x00020000
comment|/* Use ^V quoting only. */
define|#
directive|define
name|E_PRESERVE
value|0x0003f800
comment|/* Bits to preserve across commands. */
define|#
directive|define
name|E_ABSMARK
value|0x00040000
comment|/* Set the absolute mark. */
define|#
directive|define
name|E_ADDR_DEF
value|0x00080000
comment|/* Default addresses used. */
define|#
directive|define
name|E_DELTA
value|0x00100000
comment|/* Search address with delta. */
define|#
directive|define
name|E_MODIFY
value|0x00200000
comment|/* File name expansion modified arg. */
define|#
directive|define
name|E_MOVETOEND
value|0x00400000
comment|/* Move to the end of the file first. */
define|#
directive|define
name|E_NEWLINE
value|0x00800000
comment|/* Found ending<newline>. */
define|#
directive|define
name|E_SEARCH_WMSG
value|0x01000000
comment|/* Display search-wrapped message. */
define|#
directive|define
name|E_USELASTCMD
value|0x02000000
comment|/* Use the last command. */
define|#
directive|define
name|E_VISEARCH
value|0x04000000
comment|/* It's really a vi search command. */
ifdef|#
directive|ifdef
name|GTAGS
define|#
directive|define
name|E_REFERENCE
value|0x08000000
comment|/* locate function references */
endif|#
directive|endif
name|u_int32_t
name|flags
decl_stmt|;
comment|/* Current flags. */
block|}
struct|;
end_struct

begin_comment
comment|/* Ex private, per-screen memory. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ex_private
block|{
name|CIRCLEQ_HEAD
argument_list|(
argument|_tqh
argument_list|,
argument|_tagq
argument_list|)
name|tq
expr_stmt|;
comment|/* Tag queue. */
name|TAILQ_HEAD
argument_list|(
argument|_tagfh
argument_list|,
argument|_tagf
argument_list|)
name|tagfq
expr_stmt|;
comment|/* Tag file list. */
name|LIST_HEAD
argument_list|(
argument|_csch
argument_list|,
argument|_csc
argument_list|)
name|cscq
expr_stmt|;
comment|/* Cscope connection list. */
name|char
modifier|*
name|tag_last
decl_stmt|;
comment|/* Saved last tag string. */
name|CHAR_T
modifier|*
name|lastbcomm
decl_stmt|;
comment|/* Last bang command. */
name|ARGS
modifier|*
modifier|*
name|args
decl_stmt|;
comment|/* Command: argument list. */
name|int
name|argscnt
decl_stmt|;
comment|/* Command: argument list count. */
name|int
name|argsoff
decl_stmt|;
comment|/* Command: offset into arguments. */
name|u_int32_t
name|fdef
decl_stmt|;
comment|/* Saved E_C_* default command flags. */
name|char
modifier|*
name|ibp
decl_stmt|;
comment|/* File line input buffer. */
name|size_t
name|ibp_len
decl_stmt|;
comment|/* File line input buffer length. */
comment|/* 	 * Buffers for the ex output.  The screen/vi support doesn't do any 	 * character buffering of any kind.  We do it here so that we're not 	 * calling the screen output routines on every character. 	 * 	 * XXX 	 * Change to grow dynamically. 	 */
name|char
name|obp
index|[
literal|1024
index|]
decl_stmt|;
comment|/* Ex output buffer. */
name|size_t
name|obp_len
decl_stmt|;
comment|/* Ex output buffer length. */
define|#
directive|define
name|EXP_CSCINIT
value|0x01
comment|/* Cscope initialized. */
name|u_int8_t
name|flags
decl_stmt|;
block|}
name|EX_PRIVATE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EXP
parameter_list|(
name|sp
parameter_list|)
value|((EX_PRIVATE *)((sp)->ex_private))
end_define

begin_comment
comment|/*  * Filter actions:  *  *	FILTER_BANG	!:	filter text through the utility.  *	FILTER_RBANG	!:	read from the utility (without stdin).  *	FILTER_READ	read:	read from the utility (with stdin).  *	FILTER_WRITE	write:	write to the utility, display its output.  */
end_comment

begin_enum
enum|enum
name|filtertype
block|{
name|FILTER_BANG
block|,
name|FILTER_RBANG
block|,
name|FILTER_READ
block|,
name|FILTER_WRITE
block|}
enum|;
end_enum

begin_comment
comment|/* Ex common error messages. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EXM_EMPTYBUF
block|,
comment|/* Empty buffer. */
name|EXM_FILECOUNT
block|,
comment|/* Too many file names. */
name|EXM_NOCANON
block|,
comment|/* No terminal interface. */
name|EXM_NOCANON_F
block|,
comment|/* EXM_NOCANO: filter version. */
name|EXM_NOFILEYET
block|,
comment|/* Illegal until a file read in. */
name|EXM_NOPREVBUF
block|,
comment|/* No previous buffer specified. */
name|EXM_NOPREVRE
block|,
comment|/* No previous RE specified. */
name|EXM_NOSUSPEND
block|,
comment|/* No suspension. */
name|EXM_SECURE
block|,
comment|/* Illegal if secure edit option set. */
name|EXM_SECURE_F
block|,
comment|/* EXM_SECURE: filter version */
name|EXM_USAGE
comment|/* Standard usage message. */
block|}
name|exm_t
typedef|;
end_typedef

begin_comment
comment|/* Ex address error types. */
end_comment

begin_enum
enum|enum
name|badaddr
block|{
name|A_COMBO
block|,
name|A_EMPTY
block|,
name|A_EOF
block|,
name|A_NOTSET
block|,
name|A_ZERO
block|}
enum|;
end_enum

begin_comment
comment|/* Ex common tag error messages. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|TAG_BADLNO
block|,
comment|/* Tag line doesn't exist. */
name|TAG_EMPTY
block|,
comment|/* Tags stack is empty. */
name|TAG_SEARCH
comment|/* Tags search pattern wasn't found. */
block|}
name|tagmsg_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"ex_def.h"
end_include

begin_include
include|#
directive|include
file|"ex_extern.h"
end_include

end_unit

