begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)term.h	8.37 (Berkeley) 3/22/94  */
end_comment

begin_comment
comment|/*  * Fundamental character types.  *  * CHAR_T	An integral type that can hold any character.  * ARG_CHAR_T	The type of a CHAR_T when passed as an argument using  *		traditional promotion rules.  It should also be able  *		to be compared against any CHAR_T for equality without  *		problems.  * MAX_CHAR_T	The maximum value of any character.  *  * If no integral type can hold a character, don't even try the port.  */
end_comment

begin_typedef
typedef|typedef
name|u_char
name|CHAR_T
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int
name|ARG_CHAR_T
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_CHAR_T
value|0xff
end_define

begin_comment
comment|/* The maximum number of columns any character can take up on a screen. */
end_comment

begin_define
define|#
directive|define
name|MAX_CHARACTER_COLUMNS
value|4
end_define

begin_comment
comment|/* Structure to return a character and associated information. */
end_comment

begin_struct
struct|struct
name|_ch
block|{
name|CHAR_T
name|ch
decl_stmt|;
comment|/* Character. */
define|#
directive|define
name|K_NOTUSED
value|0
define|#
directive|define
name|K_CARAT
value|1
define|#
directive|define
name|K_CNTRLD
value|2
define|#
directive|define
name|K_CNTRLR
value|3
define|#
directive|define
name|K_CNTRLT
value|4
define|#
directive|define
name|K_CNTRLZ
value|5
define|#
directive|define
name|K_COLON
value|6
define|#
directive|define
name|K_CR
value|7
define|#
directive|define
name|K_ESCAPE
value|8
define|#
directive|define
name|K_FORMFEED
value|9
define|#
directive|define
name|K_NL
value|10
define|#
directive|define
name|K_RIGHTBRACE
value|11
define|#
directive|define
name|K_RIGHTPAREN
value|12
define|#
directive|define
name|K_TAB
value|13
define|#
directive|define
name|K_VERASE
value|14
define|#
directive|define
name|K_VINTR
value|15
define|#
directive|define
name|K_VKILL
value|16
define|#
directive|define
name|K_VLNEXT
value|17
define|#
directive|define
name|K_VWERASE
value|18
define|#
directive|define
name|K_ZERO
value|19
name|u_int8_t
name|value
decl_stmt|;
comment|/* Special character flag values. */
define|#
directive|define
name|CH_ABBREVIATED
value|0x01
comment|/* Character from an abbreviation. */
define|#
directive|define
name|CH_NOMAP
value|0x02
comment|/* Do not attempt to map the character. */
define|#
directive|define
name|CH_QUOTED
value|0x04
comment|/* Character is already quoted. */
name|u_int8_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Structure for the key input buffer. */
end_comment

begin_struct
struct|struct
name|_ibuf
block|{
name|CHAR_T
modifier|*
name|ch
decl_stmt|;
comment|/* Array of characters. */
name|u_int8_t
modifier|*
name|chf
decl_stmt|;
comment|/* Array of character flags (CH_*). */
define|#
directive|define
name|MAX_MAP_COUNT
value|50
comment|/* Infinite loop check. */
name|u_int8_t
modifier|*
name|cmap
decl_stmt|;
comment|/* Number of times character has been mapped. */
name|size_t
name|cnt
decl_stmt|;
comment|/* Count of remaining characters. */
name|size_t
name|nelem
decl_stmt|;
comment|/* Numer of array elements. */
name|size_t
name|next
decl_stmt|;
comment|/* Offset of next array entry. */
block|}
struct|;
end_struct

begin_comment
comment|/* Return if more keys in queue. */
end_comment

begin_define
define|#
directive|define
name|KEYS_WAITING
parameter_list|(
name|sp
parameter_list|)
value|((sp)->gp->tty->cnt)
end_define

begin_define
define|#
directive|define
name|MAPPED_KEYS_WAITING
parameter_list|(
name|sp
parameter_list|)
define|\
value|(KEYS_WAITING(sp)&& sp->gp->tty->cmap[sp->gp->tty->next])
end_define

begin_comment
comment|/*  * Structure to name a character.  Used both as an interface to the  * screen and to name objects named by characters in error messages.  */
end_comment

begin_struct
struct|struct
name|_chname
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Character name. */
name|u_int8_t
name|len
decl_stmt|;
comment|/* Length of the character name. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Routines that return a key as a side-effect return:  *  *	INP_OK		Returning a character; must be 0.  *	INP_EOF		EOF.  *	INP_ERR		Error.  *  * The vi structure depends on the key routines being able to return INP_EOF  * multiple times without failing -- eventually enough things will end due to  * INP_EOF that vi will reach the command level for the screen, at which point  * the exit flags will be set and vi will exit.  */
end_comment

begin_enum
enum|enum
name|input
block|{
name|INP_OK
init|=
literal|0
block|,
name|INP_EOF
block|,
name|INP_ERR
block|}
enum|;
end_enum

begin_comment
comment|/*  * Routines that return a confirmation return:  *  *	CONF_NO		User answered no.  *	CONF_QUIT	User answered quit, eof or an error.  *	CONF_YES	User answered yes.  */
end_comment

begin_enum
enum|enum
name|confirm
block|{
name|CONF_NO
block|,
name|CONF_QUIT
block|,
name|CONF_YES
block|}
enum|;
end_enum

begin_comment
comment|/*  * Ex/vi commands are generally separated by whitespace characters.  We  * can't use the standard isspace(3) macro because it returns true for  * characters like ^K in the ASCII character set.  The 4.4BSD isblank(3)  * macro does exactly what we want, but it's not portable yet.  *  * XXX  * Note side effect, ch is evaluated multiple times.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|isblank
end_ifndef

begin_define
define|#
directive|define
name|isblank
parameter_list|(
name|ch
parameter_list|)
value|((ch) == ' ' || (ch) == '\t')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The "standard" tab width, for displaying things to users. */
end_comment

begin_define
define|#
directive|define
name|STANDARD_TAB
value|6
end_define

begin_comment
comment|/* Various special characters, messages. */
end_comment

begin_define
define|#
directive|define
name|CURSOR_CH
value|' '
end_define

begin_comment
comment|/* Cursor character. */
end_comment

begin_define
define|#
directive|define
name|END_CH
value|'$'
end_define

begin_comment
comment|/* End of a range. */
end_comment

begin_define
define|#
directive|define
name|HEX_CH
value|'x'
end_define

begin_comment
comment|/* Leading hex number. */
end_comment

begin_define
define|#
directive|define
name|LITERAL_CH
value|'\026'
end_define

begin_comment
comment|/* Standard literal ^V. */
end_comment

begin_define
define|#
directive|define
name|NOT_DIGIT_CH
value|'a'
end_define

begin_comment
comment|/* A non-isdigit() character. */
end_comment

begin_define
define|#
directive|define
name|NO_CH
value|'n'
end_define

begin_comment
comment|/* No. */
end_comment

begin_define
define|#
directive|define
name|QUIT_CH
value|'q'
end_define

begin_comment
comment|/* Quit. */
end_comment

begin_define
define|#
directive|define
name|YES_CH
value|'y'
end_define

begin_comment
comment|/* Yes. */
end_comment

begin_define
define|#
directive|define
name|CONFSTRING
value|"confirm? [ynq]"
end_define

begin_define
define|#
directive|define
name|CONTMSG
value|"Enter return to continue: "
end_define

begin_define
define|#
directive|define
name|CONTMSG_I
value|"Enter return to continue [q to quit]: "
end_define

begin_comment
comment|/* Flags describing how input is handled. */
end_comment

begin_define
define|#
directive|define
name|TXT_AICHARS
value|0x0000001
end_define

begin_comment
comment|/* Leading autoindent chars. */
end_comment

begin_define
define|#
directive|define
name|TXT_ALTWERASE
value|0x0000002
end_define

begin_comment
comment|/* Option: altwerase. */
end_comment

begin_define
define|#
directive|define
name|TXT_APPENDEOL
value|0x0000004
end_define

begin_comment
comment|/* Appending after EOL. */
end_comment

begin_define
define|#
directive|define
name|TXT_AUTOINDENT
value|0x0000008
end_define

begin_comment
comment|/* Autoindent set this line. */
end_comment

begin_define
define|#
directive|define
name|TXT_BEAUTIFY
value|0x0000010
end_define

begin_comment
comment|/* Only printable characters. */
end_comment

begin_define
define|#
directive|define
name|TXT_BS
value|0x0000020
end_define

begin_comment
comment|/* Backspace returns the buffer. */
end_comment

begin_define
define|#
directive|define
name|TXT_CNTRLD
value|0x0000040
end_define

begin_comment
comment|/* Control-D is a special command. */
end_comment

begin_define
define|#
directive|define
name|TXT_CNTRLT
value|0x0000080
end_define

begin_comment
comment|/* Control-T is an indent special. */
end_comment

begin_define
define|#
directive|define
name|TXT_CR
value|0x0000100
end_define

begin_comment
comment|/* CR returns the buffer. */
end_comment

begin_define
define|#
directive|define
name|TXT_EMARK
value|0x0000200
end_define

begin_comment
comment|/* End of replacement mark. */
end_comment

begin_define
define|#
directive|define
name|TXT_ESCAPE
value|0x0000400
end_define

begin_comment
comment|/* Escape returns the buffer. */
end_comment

begin_define
define|#
directive|define
name|TXT_INFOLINE
value|0x0000800
end_define

begin_comment
comment|/* Editing the info line. */
end_comment

begin_define
define|#
directive|define
name|TXT_MAPCOMMAND
value|0x0001000
end_define

begin_comment
comment|/* Apply the command map. */
end_comment

begin_define
define|#
directive|define
name|TXT_MAPINPUT
value|0x0002000
end_define

begin_comment
comment|/* Apply the input map. */
end_comment

begin_define
define|#
directive|define
name|TXT_MAPNODIGIT
value|0x0004000
end_define

begin_comment
comment|/* Return to a digit. */
end_comment

begin_define
define|#
directive|define
name|TXT_NLECHO
value|0x0008000
end_define

begin_comment
comment|/* Echo the newline. */
end_comment

begin_define
define|#
directive|define
name|TXT_OVERWRITE
value|0x0010000
end_define

begin_comment
comment|/* Overwrite characters. */
end_comment

begin_define
define|#
directive|define
name|TXT_PROMPT
value|0x0020000
end_define

begin_comment
comment|/* Display a prompt. */
end_comment

begin_define
define|#
directive|define
name|TXT_RECORD
value|0x0040000
end_define

begin_comment
comment|/* Record for replay. */
end_comment

begin_define
define|#
directive|define
name|TXT_REPLACE
value|0x0080000
end_define

begin_comment
comment|/* Replace; don't delete overwrite. */
end_comment

begin_define
define|#
directive|define
name|TXT_REPLAY
value|0x0100000
end_define

begin_comment
comment|/* Replay the last input. */
end_comment

begin_define
define|#
directive|define
name|TXT_RESOLVE
value|0x0200000
end_define

begin_comment
comment|/* Resolve the text into the file. */
end_comment

begin_define
define|#
directive|define
name|TXT_SHOWMATCH
value|0x0400000
end_define

begin_comment
comment|/* Option: showmatch. */
end_comment

begin_define
define|#
directive|define
name|TXT_TTYWERASE
value|0x0800000
end_define

begin_comment
comment|/* Option: ttywerase. */
end_comment

begin_define
define|#
directive|define
name|TXT_WRAPMARGIN
value|0x1000000
end_define

begin_comment
comment|/* Option: wrapmargin. */
end_comment

begin_comment
comment|/* Support keyboard routines. */
end_comment

begin_decl_stmt
name|int
name|__term_key_val
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|ARG_CHAR_T
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|term_ab_flush
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|term_init
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|enum
name|input
name|term_key
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|CH
operator|*
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|term_key_queue
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|term_map_flush
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|term_push
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|CHAR_T
operator|*
operator|,
name|size_t
operator|,
name|u_int
operator|,
name|u_int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|enum
name|input
name|term_user_key
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|CH
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|term_waiting
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

