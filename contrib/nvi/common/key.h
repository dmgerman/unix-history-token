begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1991, 1993, 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  *  * See the LICENSE file for redistribution information.  *  *	@(#)key.h	10.18 (Berkeley) 6/30/96  */
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
comment|/*  * Event types.  *  * The program structure depends on the event loop being able to return  * E_EOF/E_ERR multiple times -- eventually enough things will end due  * to the events that vi will reach the command level for the screen, at  * which point the exit flags will be set and vi will exit.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|E_NOTUSED
init|=
literal|0
block|,
comment|/* Not set. */
name|E_CHARACTER
block|,
comment|/* Input character: e_c set. */
name|E_EOF
block|,
comment|/* End of input (NOT ^D). */
name|E_ERR
block|,
comment|/* Input error. */
name|E_INTERRUPT
block|,
comment|/* Interrupt. */
name|E_QUIT
block|,
comment|/* Quit. */
name|E_REPAINT
block|,
comment|/* Repaint: e_flno, e_tlno set. */
name|E_SIGHUP
block|,
comment|/* SIGHUP. */
name|E_SIGTERM
block|,
comment|/* SIGTERM. */
name|E_STRING
block|,
comment|/* Input string: e_csp, e_len set. */
name|E_TIMEOUT
block|,
comment|/* Timeout. */
name|E_WRESIZE
block|,
comment|/* Window resize. */
name|E_WRITE
comment|/* Write. */
block|}
name|e_event_t
typedef|;
end_typedef

begin_comment
comment|/*  * Character values.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|K_NOTUSED
init|=
literal|0
block|,
comment|/* Not set. */
name|K_BACKSLASH
block|,
comment|/*  \ */
name|K_CARAT
block|,
comment|/*  ^ */
name|K_CNTRLD
block|,
comment|/* ^D */
name|K_CNTRLR
block|,
comment|/* ^R */
name|K_CNTRLT
block|,
comment|/* ^T */
name|K_CNTRLZ
block|,
comment|/* ^Z */
name|K_COLON
block|,
comment|/*  : */
name|K_CR
block|,
comment|/* \r */
name|K_ESCAPE
block|,
comment|/* ^[ */
name|K_FORMFEED
block|,
comment|/* \f */
name|K_HEXCHAR
block|,
comment|/* ^X */
name|K_NL
block|,
comment|/* \n */
name|K_RIGHTBRACE
block|,
comment|/*  } */
name|K_RIGHTPAREN
block|,
comment|/*  ) */
name|K_TAB
block|,
comment|/* \t */
name|K_VERASE
block|,
comment|/* set from tty: default ^H */
name|K_VKILL
block|,
comment|/* set from tty: default ^U */
name|K_VLNEXT
block|,
comment|/* set from tty: default ^V */
name|K_VWERASE
block|,
comment|/* set from tty: default ^W */
name|K_ZERO
comment|/*  0 */
block|}
name|e_key_t
typedef|;
end_typedef

begin_struct
struct|struct
name|_event
block|{
name|TAILQ_ENTRY
argument_list|(
argument|_event
argument_list|)
name|q
expr_stmt|;
comment|/* Linked list of events. */
name|e_event_t
name|e_event
decl_stmt|;
comment|/* Event type. */
union|union
block|{
struct|struct
block|{
comment|/* Input character. */
name|CHAR_T
name|c
decl_stmt|;
comment|/* Character. */
name|e_key_t
name|value
decl_stmt|;
comment|/* Key type. */
define|#
directive|define
name|CH_ABBREVIATED
value|0x01
comment|/* Character is from an abbreviation. */
define|#
directive|define
name|CH_MAPPED
value|0x02
comment|/* Character is from a map. */
define|#
directive|define
name|CH_NOMAP
value|0x04
comment|/* Do not map the character. */
define|#
directive|define
name|CH_QUOTED
value|0x08
comment|/* Character is already quoted. */
name|u_int8_t
name|flags
decl_stmt|;
block|}
name|_e_ch
struct|;
define|#
directive|define
name|e_ch
value|_u_event._e_ch
comment|/* !!! The structure, not the char. */
define|#
directive|define
name|e_c
value|_u_event._e_ch.c
define|#
directive|define
name|e_value
value|_u_event._e_ch.value
define|#
directive|define
name|e_flags
value|_u_event._e_ch.flags
struct|struct
block|{
comment|/* Screen position, size. */
name|size_t
name|lno1
decl_stmt|;
comment|/* Line number. */
name|size_t
name|cno1
decl_stmt|;
comment|/* Column number. */
name|size_t
name|lno2
decl_stmt|;
comment|/* Line number. */
name|size_t
name|cno2
decl_stmt|;
comment|/* Column number. */
block|}
name|_e_mark
struct|;
define|#
directive|define
name|e_lno
value|_u_event._e_mark.lno1
comment|/* Single location. */
define|#
directive|define
name|e_cno
value|_u_event._e_mark.cno1
define|#
directive|define
name|e_flno
value|_u_event._e_mark.lno1
comment|/* Text region. */
define|#
directive|define
name|e_fcno
value|_u_event._e_mark.cno1
define|#
directive|define
name|e_tlno
value|_u_event._e_mark.lno2
define|#
directive|define
name|e_tcno
value|_u_event._e_mark.cno2
struct|struct
block|{
comment|/* Input string. */
name|CHAR_T
modifier|*
name|asp
decl_stmt|;
comment|/* Allocated string. */
name|CHAR_T
modifier|*
name|csp
decl_stmt|;
comment|/* String. */
name|size_t
name|len
decl_stmt|;
comment|/* String length. */
block|}
name|_e_str
struct|;
define|#
directive|define
name|e_asp
value|_u_event._e_str.asp
define|#
directive|define
name|e_csp
value|_u_event._e_str.csp
define|#
directive|define
name|e_len
value|_u_event._e_str.len
block|}
name|_u_event
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|_keylist
block|{
name|e_key_t
name|value
decl_stmt|;
comment|/* Special value. */
name|CHAR_T
name|ch
decl_stmt|;
comment|/* Key. */
block|}
name|KEYLIST
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|KEYLIST
name|keylist
index|[]
decl_stmt|;
end_decl_stmt

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
value|((sp)->gp->i_cnt != 0)
end_define

begin_define
define|#
directive|define
name|MAPPED_KEYS_WAITING
parameter_list|(
name|sp
parameter_list|)
define|\
value|(KEYS_WAITING(sp)&&						\ 	    F_ISSET(&sp->gp->i_event[sp->gp->i_next].e_ch, CH_MAPPED))
end_define

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
name|CH_BSEARCH
value|'?'
end_define

begin_comment
comment|/* Backward search prompt. */
end_comment

begin_define
define|#
directive|define
name|CH_CURSOR
value|' '
end_define

begin_comment
comment|/* Cursor character. */
end_comment

begin_define
define|#
directive|define
name|CH_ENDMARK
value|'$'
end_define

begin_comment
comment|/* End of a range. */
end_comment

begin_define
define|#
directive|define
name|CH_EXPROMPT
value|':'
end_define

begin_comment
comment|/* Ex prompt. */
end_comment

begin_define
define|#
directive|define
name|CH_FSEARCH
value|'/'
end_define

begin_comment
comment|/* Forward search prompt. */
end_comment

begin_define
define|#
directive|define
name|CH_HEX
value|'\030'
end_define

begin_comment
comment|/* Leading hex character. */
end_comment

begin_define
define|#
directive|define
name|CH_LITERAL
value|'\026'
end_define

begin_comment
comment|/* ASCII ^V. */
end_comment

begin_define
define|#
directive|define
name|CH_NO
value|'n'
end_define

begin_comment
comment|/* No. */
end_comment

begin_define
define|#
directive|define
name|CH_NOT_DIGIT
value|'a'
end_define

begin_comment
comment|/* A non-isdigit() character. */
end_comment

begin_define
define|#
directive|define
name|CH_QUIT
value|'q'
end_define

begin_comment
comment|/* Quit. */
end_comment

begin_define
define|#
directive|define
name|CH_YES
value|'y'
end_define

begin_comment
comment|/* Yes. */
end_comment

begin_comment
comment|/*  * Checking for interrupts means that we look at the bit that gets set if the  * screen code supports asynchronous events, and call back into the event code  * so that non-asynchronous screens get a chance to post the interrupt.  *  * INTERRUPT_CHECK is the number of lines "operated" on before checking for  * interrupts.  */
end_comment

begin_define
define|#
directive|define
name|INTERRUPT_CHECK
value|100
end_define

begin_define
define|#
directive|define
name|INTERRUPTED
parameter_list|(
name|sp
parameter_list|)
define|\
value|(F_ISSET((sp)->gp, G_INTERRUPTED) ||				\ 	(!v_event_get(sp, NULL, 0, EC_INTERRUPT)&&			\ 	F_ISSET((sp)->gp, G_INTERRUPTED)))
end_define

begin_define
define|#
directive|define
name|CLR_INTERRUPT
parameter_list|(
name|sp
parameter_list|)
define|\
value|F_CLR((sp)->gp, G_INTERRUPTED)
end_define

begin_comment
comment|/* Flags describing types of characters being requested. */
end_comment

begin_define
define|#
directive|define
name|EC_INTERRUPT
value|0x001
end_define

begin_comment
comment|/* Checking for interrupts. */
end_comment

begin_define
define|#
directive|define
name|EC_MAPCOMMAND
value|0x002
end_define

begin_comment
comment|/* Apply the command map. */
end_comment

begin_define
define|#
directive|define
name|EC_MAPINPUT
value|0x004
end_define

begin_comment
comment|/* Apply the input map. */
end_comment

begin_define
define|#
directive|define
name|EC_MAPNODIGIT
value|0x008
end_define

begin_comment
comment|/* Return to a digit. */
end_comment

begin_define
define|#
directive|define
name|EC_QUOTED
value|0x010
end_define

begin_comment
comment|/* Try to quote next character */
end_comment

begin_define
define|#
directive|define
name|EC_RAW
value|0x020
end_define

begin_comment
comment|/* Any next character. XXX: not used. */
end_comment

begin_define
define|#
directive|define
name|EC_TIMEOUT
value|0x040
end_define

begin_comment
comment|/* Timeout to next character. */
end_comment

begin_comment
comment|/* Flags describing text input special cases. */
end_comment

begin_define
define|#
directive|define
name|TXT_ADDNEWLINE
value|0x00000001
end_define

begin_comment
comment|/* Replay starts on a new line. */
end_comment

begin_define
define|#
directive|define
name|TXT_AICHARS
value|0x00000002
end_define

begin_comment
comment|/* Leading autoindent chars. */
end_comment

begin_define
define|#
directive|define
name|TXT_ALTWERASE
value|0x00000004
end_define

begin_comment
comment|/* Option: altwerase. */
end_comment

begin_define
define|#
directive|define
name|TXT_APPENDEOL
value|0x00000008
end_define

begin_comment
comment|/* Appending after EOL. */
end_comment

begin_define
define|#
directive|define
name|TXT_AUTOINDENT
value|0x00000010
end_define

begin_comment
comment|/* Autoindent set this line. */
end_comment

begin_define
define|#
directive|define
name|TXT_BACKSLASH
value|0x00000020
end_define

begin_comment
comment|/* Backslashes escape characters. */
end_comment

begin_define
define|#
directive|define
name|TXT_BEAUTIFY
value|0x00000040
end_define

begin_comment
comment|/* Only printable characters. */
end_comment

begin_define
define|#
directive|define
name|TXT_BS
value|0x00000080
end_define

begin_comment
comment|/* Backspace returns the buffer. */
end_comment

begin_define
define|#
directive|define
name|TXT_CEDIT
value|0x00000100
end_define

begin_comment
comment|/* Can return TERM_CEDIT. */
end_comment

begin_define
define|#
directive|define
name|TXT_CNTRLD
value|0x00000200
end_define

begin_comment
comment|/* Control-D is a command. */
end_comment

begin_define
define|#
directive|define
name|TXT_CNTRLT
value|0x00000400
end_define

begin_comment
comment|/* Control-T is an indent special. */
end_comment

begin_define
define|#
directive|define
name|TXT_CR
value|0x00000800
end_define

begin_comment
comment|/* CR returns the buffer. */
end_comment

begin_define
define|#
directive|define
name|TXT_DOTTERM
value|0x00001000
end_define

begin_comment
comment|/* Leading '.' terminates the input. */
end_comment

begin_define
define|#
directive|define
name|TXT_EMARK
value|0x00002000
end_define

begin_comment
comment|/* End of replacement mark. */
end_comment

begin_define
define|#
directive|define
name|TXT_EOFCHAR
value|0x00004000
end_define

begin_comment
comment|/* ICANON set, return EOF character. */
end_comment

begin_define
define|#
directive|define
name|TXT_ESCAPE
value|0x00008000
end_define

begin_comment
comment|/* Escape returns the buffer. */
end_comment

begin_define
define|#
directive|define
name|TXT_FILEC
value|0x00010000
end_define

begin_comment
comment|/* Option: filec. */
end_comment

begin_define
define|#
directive|define
name|TXT_INFOLINE
value|0x00020000
end_define

begin_comment
comment|/* Editing the info line. */
end_comment

begin_define
define|#
directive|define
name|TXT_MAPINPUT
value|0x00040000
end_define

begin_comment
comment|/* Apply the input map. */
end_comment

begin_define
define|#
directive|define
name|TXT_NLECHO
value|0x00080000
end_define

begin_comment
comment|/* Echo the newline. */
end_comment

begin_define
define|#
directive|define
name|TXT_NUMBER
value|0x00100000
end_define

begin_comment
comment|/* Number the line. */
end_comment

begin_define
define|#
directive|define
name|TXT_OVERWRITE
value|0x00200000
end_define

begin_comment
comment|/* Overwrite characters. */
end_comment

begin_define
define|#
directive|define
name|TXT_PROMPT
value|0x00400000
end_define

begin_comment
comment|/* Display a prompt. */
end_comment

begin_define
define|#
directive|define
name|TXT_RECORD
value|0x00800000
end_define

begin_comment
comment|/* Record for replay. */
end_comment

begin_define
define|#
directive|define
name|TXT_REPLACE
value|0x01000000
end_define

begin_comment
comment|/* Replace; don't delete overwrite. */
end_comment

begin_define
define|#
directive|define
name|TXT_REPLAY
value|0x02000000
end_define

begin_comment
comment|/* Replay the last input. */
end_comment

begin_define
define|#
directive|define
name|TXT_RESOLVE
value|0x04000000
end_define

begin_comment
comment|/* Resolve the text into the file. */
end_comment

begin_define
define|#
directive|define
name|TXT_SEARCHINCR
value|0x08000000
end_define

begin_comment
comment|/* Incremental search. */
end_comment

begin_define
define|#
directive|define
name|TXT_SHOWMATCH
value|0x10000000
end_define

begin_comment
comment|/* Option: showmatch. */
end_comment

begin_define
define|#
directive|define
name|TXT_TTYWERASE
value|0x20000000
end_define

begin_comment
comment|/* Option: ttywerase. */
end_comment

begin_define
define|#
directive|define
name|TXT_WRAPMARGIN
value|0x40000000
end_define

begin_comment
comment|/* Option: wrapmargin. */
end_comment

end_unit

