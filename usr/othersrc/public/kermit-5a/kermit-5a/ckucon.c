begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
name|char
modifier|*
name|connv
init|=
literal|"CONNECT Command for UNIX, 5A(036) 8 Feb 92"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  C K U C O N  --  Dumb terminal connection to remote system, for UNIX  */
end_comment

begin_comment
comment|/*   Author: Frank da Cruz (fdc@columbia.edu, FDCCU@CUVMA.BITNET),   Columbia University Center for Computing Activities.   First released January 1985.   Copyright (C) 1985, 1992, Trustees of Columbia University in the City of New   York.  Permission is granted to any individual or institution to use this   software as long as it is not sold for profit.  This copyright notice must be   retained.  This software may not be included in commercial products without   written permission of Columbia University. */
end_comment

begin_include
include|#
directive|include
file|"ckcdeb.h"
end_include

begin_comment
comment|/* Common things first */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NEXT
end_ifdef

begin_undef
undef|#
directive|undef
name|NSIG
end_undef

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_comment
comment|/* For wait() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEXT */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_comment
comment|/* Signals */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/* Error numbers */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ZILOG
end_ifdef

begin_comment
comment|/* Longjumps */
end_comment

begin_include
include|#
directive|include
file|<setret.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ZILOG */
end_comment

begin_comment
comment|/* Kermit-specific includes */
end_comment

begin_include
include|#
directive|include
file|"ckcasc.h"
end_include

begin_comment
comment|/* ASCII characters */
end_comment

begin_include
include|#
directive|include
file|"ckcker.h"
end_include

begin_comment
comment|/* Kermit things */
end_comment

begin_include
include|#
directive|include
file|"ckucmd.h"
end_include

begin_comment
comment|/* For xxesc() prototype */
end_comment

begin_include
include|#
directive|include
file|"ckcnet.h"
end_include

begin_comment
comment|/* Network symbols */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOCSETS
end_ifndef

begin_include
include|#
directive|include
file|"ckcxla.h"
end_include

begin_comment
comment|/* Character set translation */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOCSETS */
end_comment

begin_comment
comment|/* Internal function prototypes */
end_comment

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID doesc
argument_list|,
argument|(char)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|VOID logchar
argument_list|,
argument|(char)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|_PROTOTYP
argument_list|(
argument|int hconne
argument_list|,
argument|(void)
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|SIGUSR1
end_ifndef

begin_comment
comment|/* User-defined signals */
end_comment

begin_define
define|#
directive|define
name|SIGUSR1
value|30
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIGUSR1 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIGUSR2
end_ifndef

begin_define
define|#
directive|define
name|SIGUSR2
value|31
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIGUSR2 */
end_comment

begin_comment
comment|/* External variables */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|local
decl_stmt|,
name|escape
decl_stmt|,
name|duplex
decl_stmt|,
name|parity
decl_stmt|,
name|flow
decl_stmt|,
name|seslog
decl_stmt|,
name|sessft
decl_stmt|,
name|debses
decl_stmt|,
name|mdmtyp
decl_stmt|,
name|ttnproto
decl_stmt|,
name|cmask
decl_stmt|,
name|cmdmsk
decl_stmt|,
name|network
decl_stmt|,
name|nettype
decl_stmt|,
name|deblog
decl_stmt|,
name|sosi
decl_stmt|,
name|tnlm
decl_stmt|,
name|xitsta
decl_stmt|,
name|what
decl_stmt|,
name|ttyfd
decl_stmt|,
name|quiet
decl_stmt|,
name|backgrd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|speed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|ttname
index|[]
decl_stmt|,
name|sesfil
index|[]
decl_stmt|,
name|myhost
index|[]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|NETCONN
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|tn_init
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETCONN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOSETKEY
end_ifndef

begin_comment
comment|/* Keyboard mapping */
end_comment

begin_decl_stmt
specifier|extern
name|KEY
modifier|*
name|keymap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Single-character key map */
end_comment

begin_decl_stmt
specifier|extern
name|MACRO
modifier|*
name|macrotab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Key macro pointer table */
end_comment

begin_decl_stmt
specifier|static
name|MACRO
name|kmptr
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to current key macro */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSETKEY */
end_comment

begin_comment
comment|/* Global variables local to this module */
end_comment

begin_decl_stmt
specifier|static
name|int
name|quitnow
init|=
literal|0
decl_stmt|,
comment|/*<esc-char>Q was typed */
name|dohangup
init|=
literal|0
decl_stmt|,
comment|/*<esc-char>H was typed */
name|sjval
init|=
literal|0
decl_stmt|,
comment|/* Setjump return value */
name|goterr
init|=
literal|0
decl_stmt|,
comment|/* I/O error flag */
name|active
init|=
literal|0
decl_stmt|,
comment|/* Lower fork active flag */
name|shift
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SO/SI shift state */
end_comment

begin_decl_stmt
specifier|static
name|char
name|kbuf
index|[
literal|10
index|]
decl_stmt|,
modifier|*
name|kbp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Keyboard buffer& pointer */
end_comment

begin_decl_stmt
specifier|static
name|PID_T
name|parent_id
init|=
operator|(
name|PID_T
operator|)
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Process id of keyboard fork */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|lbp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Line buffer pointer */
end_comment

begin_decl_stmt
specifier|static
name|int
name|lbc
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Line buffer count */
end_comment

begin_define
define|#
directive|define
name|LBUFL
value|200
end_define

begin_comment
comment|/* Line buffer length */
end_comment

begin_define
define|#
directive|define
name|TMPLEN
value|50
end_define

begin_comment
comment|/* Temp buffer length */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DYNAMIC
end_ifdef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|lbuf
decl_stmt|,
modifier|*
name|temp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Line and temp buffers */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|char
name|lbuf
index|[
name|LBUFL
index|]
decl_stmt|,
name|temp
index|[
name|TMPLEN
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DYNAMIC */
end_comment

begin_comment
comment|/* SunLink X.25 items */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUNX25
end_ifdef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* General purpose pointer */
end_comment

begin_decl_stmt
name|char
name|x25ibuf
index|[
name|MAXIX25
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Input buffer */
end_comment

begin_decl_stmt
name|char
name|x25obuf
index|[
name|MAXOX25
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output buffer */
end_comment

begin_decl_stmt
name|int
name|ibufl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Length of input buffer */
end_comment

begin_decl_stmt
name|int
name|obufl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Length of output buffer */
end_comment

begin_decl_stmt
name|unsigned
name|char
name|tosend
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|linkid
decl_stmt|,
name|lcn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|dox25clr
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CHAR
name|padparms
index|[
name|MAXPADPARMS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|padpipe
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pipe descriptor to pass PAD parms */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUNX25 */
end_comment

begin_comment
comment|/* Character-set items */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOCSETS
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|CK_ANSIC
end_ifdef

begin_comment
comment|/* ANSI C prototypes... */
end_comment

begin_function_decl
specifier|extern
name|CHAR
function_decl|(
modifier|*
name|xls
index|[
name|MAXTCSETS
operator|+
literal|1
index|]
index|[
name|MAXFCSETS
operator|+
literal|1
index|]
function_decl|)
parameter_list|(
name|CHAR
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Character set */
end_comment

begin_function_decl
specifier|extern
name|CHAR
function_decl|(
modifier|*
name|xlr
index|[
name|MAXTCSETS
operator|+
literal|1
index|]
index|[
name|MAXFCSETS
operator|+
literal|1
index|]
function_decl|)
parameter_list|(
name|CHAR
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* translation functions */
end_comment

begin_function_decl
specifier|static
name|CHAR
function_decl|(
modifier|*
name|sxo
function_decl|)
parameter_list|(
name|CHAR
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Local translation functions */
end_comment

begin_function_decl
specifier|static
name|CHAR
function_decl|(
modifier|*
name|rxo
function_decl|)
parameter_list|(
name|CHAR
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* for output (sending) terminal chars */
end_comment

begin_function_decl
specifier|static
name|CHAR
function_decl|(
modifier|*
name|sxi
function_decl|)
parameter_list|(
name|CHAR
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* and for input (receiving) terminal chars. */
end_comment

begin_function_decl
specifier|static
name|CHAR
function_decl|(
modifier|*
name|rxi
function_decl|)
parameter_list|(
name|CHAR
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Not ANSI C... */
end_comment

begin_function_decl
specifier|extern
name|CHAR
function_decl|(
modifier|*
name|xls
index|[
name|MAXTCSETS
operator|+
literal|1
index|]
index|[
name|MAXFCSETS
operator|+
literal|1
index|]
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Character set */
end_comment

begin_function_decl
specifier|extern
name|CHAR
function_decl|(
modifier|*
name|xlr
index|[
name|MAXTCSETS
operator|+
literal|1
index|]
index|[
name|MAXFCSETS
operator|+
literal|1
index|]
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* translation functions. */
end_comment

begin_function_decl
specifier|static
name|CHAR
function_decl|(
modifier|*
name|sxo
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Local translation functions */
end_comment

begin_function_decl
specifier|static
name|CHAR
function_decl|(
modifier|*
name|rxo
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* for output (sending) terminal chars */
end_comment

begin_function_decl
specifier|static
name|CHAR
function_decl|(
modifier|*
name|sxi
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* and for input (receiving) terminal chars. */
end_comment

begin_function_decl
specifier|static
name|CHAR
function_decl|(
modifier|*
name|rxi
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CK_ANSIC */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|language
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current language. */
end_comment

begin_decl_stmt
specifier|static
name|int
name|langsv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For remembering language setting. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|csinfo
name|fcsinfo
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File character set info. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tcsr
decl_stmt|,
name|tcsl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Terminal character sets, remote& local. */
end_comment

begin_decl_stmt
specifier|static
name|int
name|tcs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Intermediate ("transfer") character set. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NOESCSEQ
end_ifndef

begin_comment
comment|/*   As of edit 178, the CONNECT command will skip past ANSI escape sequences   to avoid translating the characters within them.  This allows the CONNECT   command to work correctly when connected to a remote host that uses a   7-bit ISO 646 national character set, in which characters like '[' would   normally be translated into accented characters, ruining the terminal's   interpretation (and generation) of escape sequences.    Escape sequences of non-ANSI/ISO-compliant terminals are not handled. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SKIPESC
end_ifndef

begin_define
define|#
directive|define
name|SKIPESC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SKIPESC */
end_comment

begin_comment
comment|/*   States for the escape-sequence recognizer. */
end_comment

begin_define
define|#
directive|define
name|ES_NORMAL
value|0
end_define

begin_comment
comment|/* Normal, not in escape sequence */
end_comment

begin_define
define|#
directive|define
name|ES_GOTESC
value|1
end_define

begin_comment
comment|/* Current character is ESC */
end_comment

begin_define
define|#
directive|define
name|ES_ESCSEQ
value|2
end_define

begin_comment
comment|/* Inside an escape sequence */
end_comment

begin_define
define|#
directive|define
name|ES_GOTCSI
value|3
end_define

begin_comment
comment|/* Inside a control sequence */
end_comment

begin_define
define|#
directive|define
name|ES_STRING
value|4
end_define

begin_comment
comment|/* Inside DCS,OSC,PM, or APC string */
end_comment

begin_define
define|#
directive|define
name|ES_TERMIN
value|5
end_define

begin_comment
comment|/* 1st char of string terminator */
end_comment

begin_decl_stmt
specifier|static
name|int
name|skipesc
init|=
literal|0
decl_stmt|,
comment|/* Skip over ANSI escape sequences */
name|inesc
init|=
name|ES_NORMAL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* State of sequence recognizer */
end_comment

begin_comment
comment|/*   ANSI escape sequence handling.  Only the 7-bit form is treated, because   translation is not a problem in the 8-bit environment, in which all GL   characters are ASCII and no translation takes place.  So we don't check   for the 8-bit single-character versions of CSI, DCS, OSC, APC, or ST.   Here is the ANSI sequence recognizer state table, followed by the code   that implements it.    Definitions:     CAN = Cancel                       01/08         Ctrl-X     SUB = Substitute                   01/10         Ctrl-Z     DCS = Device Control Sequence      01/11 05/00   ESC P     CSI = Control Sequence Introducer  01/11 05/11   ESC [     ST  = String Terminator            01/11 05/12   ESC \     OSC = Operating System Command     01/11 05/13   ESC ]     PM  = Privacy Message              01/11 05/14   ESC ^     APC = Application Program Command  01/11 05/15   ESC _    ANSI escape sequence recognizer:      State    Input  New State  ; Commentary      NORMAL   (start)           ; Start in NORMAL state      (any)    CAN    NORMAL     ; ^X cancels     (any)    SUB    NORMAL     ; ^Z cancels      NORMAL   ESC    GOTESC     ; Begin escape sequence     NORMAL   other             ; NORMAL control or graphic character      GOTESC   ESC               ; Start again     GOTESC   [      GOTCSI     ; CSI     GOTESC   P      STRING     ; DCS introducer, consume through ST     GOTESC   ]      STRING     ; OSC introducer, consume through ST     GOTESC   ^      STRING     ; PM  introducer, consume through ST     GOTESC   _      STRING     ; APC introducer, consume through ST     GOTESC   0..~   NORMAL     ; 03/00 through 17/14 = Final character     GOTESC   other  ESCSEQ     ; Intermediate or ignored control character      ESCSEQ   ESC    GOTESC     ; Start again     ESCSEQ   0..~   NORMAL     ; 03/00 through 17/14 = Final character     ESCSEQ   other             ; Intermediate or ignored control character      GOTCSI   ESC    GOTESC     ; Start again     GOTCSI   @..~   NORMAL     ; 04/00 through 17/14 = Final character     GOTCSI   other             ; Intermediate char or ignored control char      STRING   ESC    TERMIN     ; Maybe have ST     STRING   other             ; Consume all else      TERMIN   \      NORMAL     ; End of string     TERMIN   other  STRING     ; Still in string */
end_comment

begin_comment
comment|/*   chkaes() -- Check ANSI Escape Sequence.   Call with EACH character in input stream.   Sets global inesc variable according to escape sequence state. */
end_comment

begin_function
name|VOID
ifdef|#
directive|ifdef
name|CK_ANSIC
name|chkaes
parameter_list|(
name|char
name|c
parameter_list|)
else|#
directive|else
function|chkaes
parameter_list|(
name|c
parameter_list|)
name|char
name|c
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* chkaes */
block|{
if|if
condition|(
name|c
operator|==
name|CAN
operator|||
name|c
operator|==
name|SUB
condition|)
comment|/* CAN and SUB cancel any sequence */
name|inesc
operator|=
name|ES_NORMAL
expr_stmt|;
else|else
comment|/* Otherwise */
switch|switch
condition|(
name|inesc
condition|)
block|{
comment|/* enter state switcher */
case|case
name|ES_NORMAL
case|:
comment|/* NORMAL state */
if|if
condition|(
name|c
operator|==
name|ESC
condition|)
comment|/* Got an ESC */
name|inesc
operator|=
name|ES_GOTESC
expr_stmt|;
comment|/* Change state to GOTESC */
break|break;
comment|/* Otherwise stay in NORMAL state */
case|case
name|ES_GOTESC
case|:
comment|/* GOTESC state */
if|if
condition|(
name|c
operator|==
literal|'['
condition|)
comment|/* Left bracket after ESC is CSI */
name|inesc
operator|=
name|ES_GOTCSI
expr_stmt|;
comment|/* Change to GOTCSI state */
elseif|else
if|if
condition|(
name|c
operator|>
literal|057
operator|&&
name|c
operator|<
literal|0177
condition|)
comment|/* Final character '0' thru '~' */
name|inesc
operator|=
name|ES_NORMAL
expr_stmt|;
comment|/* Back to normal */
elseif|else
if|if
condition|(
name|c
operator|==
literal|'P'
operator|||
operator|(
name|c
operator|>
literal|0134
operator|&&
name|c
operator|<
literal|0140
operator|)
condition|)
comment|/* P, [, ^, or _ */
name|inesc
operator|=
name|ES_STRING
expr_stmt|;
comment|/* Switch to STRING-absorption state */
elseif|else
if|if
condition|(
name|c
operator|!=
name|ESC
condition|)
comment|/* ESC in an escape sequence... */
name|inesc
operator|=
name|ES_ESCSEQ
expr_stmt|;
comment|/* starts a new escape sequence */
break|break;
comment|/* Intermediate or ignored ctrl char */
case|case
name|ES_ESCSEQ
case|:
comment|/* ESCSEQ -- in an escape sequence */
if|if
condition|(
name|c
operator|>
literal|057
operator|&&
name|c
operator|<
literal|0177
condition|)
comment|/* Final character '0' thru '~' */
name|inesc
operator|=
name|ES_NORMAL
expr_stmt|;
comment|/* Return to NORMAL state. */
elseif|else
if|if
condition|(
name|c
operator|==
name|ESC
condition|)
comment|/* ESC ... */
name|inesc
operator|=
name|ES_GOTESC
expr_stmt|;
comment|/* starts a new escape sequence */
break|break;
comment|/* Intermediate or ignored ctrl char */
case|case
name|ES_GOTCSI
case|:
comment|/* GOTCSI -- In a control sequence */
if|if
condition|(
name|c
operator|>
literal|077
operator|&&
name|c
operator|<
literal|0177
condition|)
comment|/* Final character '@' thru '~' */
name|inesc
operator|=
name|ES_NORMAL
expr_stmt|;
comment|/* Return to NORMAL. */
elseif|else
if|if
condition|(
name|c
operator|==
name|ESC
condition|)
comment|/* ESC ... */
name|inesc
operator|=
name|ES_GOTESC
expr_stmt|;
comment|/* starts over. */
break|break;
comment|/* Intermediate or ignored ctrl char */
case|case
name|ES_STRING
case|:
comment|/* Inside a string */
if|if
condition|(
name|c
operator|==
name|ESC
condition|)
comment|/* ESC may be 1st char of terminator */
name|inesc
operator|=
name|ES_TERMIN
expr_stmt|;
comment|/* Go see. */
break|break;
comment|/* Absorb all other characters. */
case|case
name|ES_TERMIN
case|:
comment|/* May have a string terminator */
if|if
condition|(
name|c
operator|==
literal|'\\'
condition|)
comment|/* which must be backslash */
name|inesc
operator|=
name|ES_NORMAL
expr_stmt|;
comment|/* If so, back to NORMAL */
else|else
comment|/* Otherwise */
name|inesc
operator|=
name|ES_STRING
expr_stmt|;
comment|/* Back to string absorption. */
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOESCSEQ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOCSETS */
end_comment

begin_comment
comment|/* Connect state parent/child communication signal handlers */
end_comment

begin_decl_stmt
specifier|static
name|jmp_buf
name|con_env
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Environment pointer for connect errors */
end_comment

begin_comment
comment|/*   Note: Some C compilers (e.g. Cray UNICOS) interpret the ANSI C standard   about setjmp() in a way that disallows constructions like:      if ((var = setjmp(env)) == 0) ...    which prevents the value returned by longjmp() from being used at all.   So the following handlers set a global variable instead. */
end_comment

begin_function
specifier|static
name|SIGTYP
name|conn_int
parameter_list|(
name|foo
parameter_list|)
name|int
name|foo
decl_stmt|;
block|{
comment|/* Modem read failure handler, */
name|sjval
operator|=
literal|1
expr_stmt|;
comment|/* Set global variable */
name|signal
argument_list|(
name|SIGUSR1
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
comment|/* Disarm the interrupt */
name|longjmp
argument_list|(
name|con_env
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* Notifies parent process to stop */
block|}
end_function

begin_function
specifier|static
name|SIGTYP
name|mode_chg
parameter_list|(
name|foo
parameter_list|)
name|int
name|foo
decl_stmt|;
block|{
comment|/*   I think we could just put "pad(padpipe);" after the read() call below,   and skip the longjmp and fork-restarting business at "newfork:", but I   have no way to test this. */
ifdef|#
directive|ifdef
name|SUNX25
comment|/* X.25 read new params from pipe */
if|if
condition|(
name|nettype
operator|==
name|NET_SX25
condition|)
block|{
name|read
argument_list|(
name|padpipe
index|[
literal|0
index|]
argument_list|,
name|padparms
argument_list|,
name|MAXPADPARMS
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F100
argument_list|,
literal|"pad_chg"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
endif|#
directive|endif
comment|/* SUNX25 */
name|duplex
operator|=
literal|1
operator|-
name|duplex
expr_stmt|;
comment|/* Toggle duplex mode. */
name|signal
argument_list|(
name|SIGUSR2
argument_list|,
name|mode_chg
argument_list|)
expr_stmt|;
comment|/* Re-arm the signal. */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"mode_chg duplex"
argument_list|,
literal|""
argument_list|,
name|duplex
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SUNX25
block|}
name|sjval
operator|=
literal|2
expr_stmt|;
comment|/* Set global variable. */
name|longjmp
argument_list|(
name|con_env
argument_list|,
literal|2
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SUNX25 */
block|}
end_function

begin_comment
comment|/*  C O N E C T  --  Perform terminal connection  */
end_comment

begin_function
name|int
name|conect
parameter_list|()
block|{
name|PID_T
name|pid
decl_stmt|;
comment|/* Process id of child (modem reader) */
name|int
name|n
decl_stmt|;
comment|/* General purpose counter */
name|int
name|c
decl_stmt|;
comment|/* c is a character, but must be signed  				   integer to pass thru -1, which is the 				   modem disconnection signal, and is 				   different from the character 0377 */
name|int
name|c2
decl_stmt|;
comment|/* A copy of c */
name|int
name|csave
decl_stmt|;
comment|/* Another copy of c */
name|int
name|tx
decl_stmt|;
comment|/* tn_doop() return code */
ifdef|#
directive|ifdef
name|SUNX25
name|int
name|i
decl_stmt|;
comment|/* Worker for X.25 code*/
endif|#
directive|endif
comment|/* SUNX25 */
ifdef|#
directive|ifdef
name|DYNAMIC
if|if
condition|(
operator|!
operator|(
name|lbuf
operator|=
name|malloc
argument_list|(
name|LBUFL
operator|+
literal|1
argument_list|)
operator|)
condition|)
block|{
comment|/* Allocate input line buffer */
name|printf
argument_list|(
literal|"Sorry, CONNECT input buffer can't be allocated\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
operator|!
operator|(
name|temp
operator|=
name|malloc
argument_list|(
name|TMPLEN
operator|+
literal|1
argument_list|)
operator|)
condition|)
block|{
comment|/* Allocate temporary buffer */
name|printf
argument_list|(
literal|"Sorry, CONNECT temporary buffer can't be allocated\n"
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|lbuf
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
endif|#
directive|endif
comment|/* DYNAMIC */
if|if
condition|(
operator|!
name|local
condition|)
block|{
ifdef|#
directive|ifdef
name|NETCONN
name|printf
argument_list|(
literal|"Sorry, you must SET LINE or SET HOST first\n"
argument_list|)
expr_stmt|;
else|#
directive|else
name|printf
argument_list|(
literal|"Sorry, you must SET LINE first\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NETCONN */
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
name|backgrd
condition|)
block|{
name|printf
argument_list|(
literal|"\r\nSorry, Kermit's CONNECT command can be used only in the foreground\r\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
name|speed
operator|<
literal|0L
operator|&&
name|network
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"Sorry, you must SET SPEED first\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
ifdef|#
directive|ifdef
name|TCPSOCKET
if|if
condition|(
name|network
operator|&&
operator|(
name|nettype
operator|!=
name|NET_TCPB
operator|)
ifdef|#
directive|ifdef
name|SUNX25
operator|&&
operator|(
name|nettype
operator|!=
name|NET_SX25
operator|)
endif|#
directive|endif
comment|/* SUNX25 */
condition|)
block|{
name|printf
argument_list|(
literal|"Sorry, network type not supported\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
endif|#
directive|endif
comment|/* TCPSOCKET */
if|if
condition|(
name|ttyfd
operator|<
literal|0
condition|)
block|{
comment|/* If communication device not open */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"ckucon opening"
argument_list|,
name|ttname
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Open it now */
if|if
condition|(
name|ttopen
argument_list|(
name|ttname
argument_list|,
operator|&
name|local
argument_list|,
name|mdmtyp
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
block|{
name|sprintf
argument_list|(
name|temp
argument_list|,
literal|"Sorry, can't open %s"
argument_list|,
name|ttname
argument_list|)
expr_stmt|;
name|perror
argument_list|(
name|temp
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F110
argument_list|,
literal|"ckucon open failure"
argument_list|,
name|temp
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
block|}
name|dohangup
operator|=
literal|0
expr_stmt|;
comment|/* Hangup not requested yet */
ifdef|#
directive|ifdef
name|SUNX25
name|dox25clr
operator|=
literal|0
expr_stmt|;
comment|/* X.25 clear not requested yet */
endif|#
directive|endif
comment|/* SUNX25 */
if|if
condition|(
operator|!
name|quiet
condition|)
block|{
ifdef|#
directive|ifdef
name|NETCONN
if|if
condition|(
name|network
condition|)
block|{
name|printf
argument_list|(
literal|"Connecting to host %s"
argument_list|,
name|ttname
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SUNX25
if|if
condition|(
name|nettype
operator|==
name|NET_SX25
condition|)
name|printf
argument_list|(
literal|", Link ID %d, LCN %d"
argument_list|,
name|linkid
argument_list|,
name|lcn
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SUNX25 */
block|}
else|else
block|{
endif|#
directive|endif
comment|/* NETCONN */
name|printf
argument_list|(
literal|"Connecting to %s"
argument_list|,
name|ttname
argument_list|)
expr_stmt|;
if|if
condition|(
name|speed
operator|>
operator|-
literal|1L
condition|)
name|printf
argument_list|(
literal|", speed %ld"
argument_list|,
name|speed
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|NETCONN
block|}
endif|#
directive|endif
comment|/* NETCONN */
name|printf
argument_list|(
literal|".\r\nThe escape character is %s (ASCII %d).\r\n"
argument_list|,
name|dbchr
argument_list|(
name|escape
argument_list|)
argument_list|,
name|escape
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Type the escape character followed by C to get back,\r\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"or followed by ? to see other options.\r\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|seslog
condition|)
block|{
name|printf
argument_list|(
literal|"(Session logged to %s, "
argument_list|,
name|sesfil
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s)\r\n"
argument_list|,
name|sessft
condition|?
literal|"binary"
else|:
literal|"text"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|debses
condition|)
name|printf
argument_list|(
literal|"Debugging Display...)\r\n"
argument_list|)
expr_stmt|;
block|}
comment|/* Condition console terminal and communication line */
if|if
condition|(
name|conbin
argument_list|(
name|escape
argument_list|)
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"Sorry, can't condition console terminal\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|debug
argument_list|(
name|F101
argument_list|,
literal|"connect cmask"
argument_list|,
literal|""
argument_list|,
name|cmask
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"connect cmdmsk"
argument_list|,
literal|""
argument_list|,
name|cmdmsk
argument_list|)
expr_stmt|;
name|goterr
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|(
name|n
operator|=
name|ttvt
argument_list|(
name|speed
argument_list|,
name|flow
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
comment|/* Enter "virtual terminal" mode */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"CONNECT ttvt"
argument_list|,
literal|""
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|goterr
operator|=
literal|1
expr_stmt|;
comment|/* Error recovery... */
name|tthang
argument_list|()
expr_stmt|;
comment|/* Hang up and close the device. */
name|ttclos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|ttopen
argument_list|(
name|ttname
argument_list|,
operator|&
name|local
argument_list|,
name|mdmtyp
argument_list|,
literal|0
argument_list|)
operator|<
literal|0
condition|)
block|{
comment|/* Open it again... */
name|sprintf
argument_list|(
name|temp
argument_list|,
literal|"Sorry, can't reopen %s"
argument_list|,
name|ttname
argument_list|)
expr_stmt|;
name|perror
argument_list|(
name|temp
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
name|ttvt
argument_list|(
name|speed
argument_list|,
name|flow
argument_list|)
operator|<
literal|0
condition|)
block|{
comment|/* Try virtual terminal mode again. */
name|conres
argument_list|()
expr_stmt|;
comment|/* Failure this time is fatal. */
name|printf
argument_list|(
literal|"Sorry, Can't condition communication line\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
ifdef|#
directive|ifdef
name|NETCONN
if|if
condition|(
name|network
operator|&&
name|ttnproto
operator|==
name|NP_TELNET
condition|)
name|tn_ini
argument_list|()
expr_stmt|;
comment|/* Just in case ttopen didn't... */
endif|#
directive|endif
comment|/* NETCONN */
block|}
name|debug
argument_list|(
name|F101
argument_list|,
literal|"connect ttvt ok, escape"
argument_list|,
literal|""
argument_list|,
name|escape
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|NOCSETS
comment|/* Set up character set translations */
ifdef|#
directive|ifdef
name|KANJI
comment|/* Kanji not supported yet */
if|if
condition|(
name|fcsinfo
index|[
name|tcsr
index|]
operator|.
name|alphabet
operator|==
name|AL_JAPAN
operator|||
name|fcsinfo
index|[
name|tcsl
index|]
operator|.
name|alphabet
operator|==
name|AL_JAPAN
condition|)
block|{
name|tcs
operator|=
name|TC_TRANSP
expr_stmt|;
block|}
elseif|else
endif|#
directive|endif
comment|/* KANJI */
ifdef|#
directive|ifdef
name|CYRILLIC
if|if
condition|(
name|fcsinfo
index|[
name|tcsl
index|]
operator|.
name|alphabet
operator|==
name|AL_CYRIL
condition|)
block|{
name|tcs
operator|=
name|TC_CYRILL
expr_stmt|;
block|}
else|else
endif|#
directive|endif
comment|/* CYRILLIC */
name|tcs
operator|=
name|TC_1LATIN
expr_stmt|;
if|if
condition|(
name|tcsr
operator|==
name|tcsl
condition|)
block|{
comment|/* Remote and local sets the same? */
name|sxo
operator|=
name|rxo
operator|=
name|NULL
expr_stmt|;
comment|/* If so, no translation. */
name|sxi
operator|=
name|rxi
operator|=
name|NULL
expr_stmt|;
block|}
else|else
block|{
comment|/* Otherwise, set up */
name|sxo
operator|=
name|xls
index|[
name|tcs
index|]
index|[
name|tcsl
index|]
expr_stmt|;
comment|/* translation function */
name|rxo
operator|=
name|xlr
index|[
name|tcs
index|]
index|[
name|tcsr
index|]
expr_stmt|;
comment|/* pointers for output functions */
name|sxi
operator|=
name|xls
index|[
name|tcs
index|]
index|[
name|tcsr
index|]
expr_stmt|;
comment|/* and for input functions. */
name|rxi
operator|=
name|xlr
index|[
name|tcs
index|]
index|[
name|tcsl
index|]
expr_stmt|;
block|}
comment|/*   This is to prevent use of zmstuff() and zdstuff() by translation functions.   They only work with disk i/o, not with communication i/o.  Luckily Russian   translation functions don't do any stuffing... */
name|langsv
operator|=
name|language
expr_stmt|;
ifndef|#
directive|ifndef
name|NOCYRIL
if|if
condition|(
name|language
operator|!=
name|L_RUSSIAN
condition|)
endif|#
directive|endif
comment|/* NOCYRIL */
name|language
operator|=
name|L_USASCII
expr_stmt|;
ifdef|#
directive|ifdef
name|SKIPESC
comment|/*   We need to activate the "skip escape sequence" feature when:   (a) translation is elected, and   (b) the local and/or remote set is 7-bit set other than US ASCII. */
name|skipesc
operator|=
operator|(
name|tcs
operator|!=
name|TC_TRANSP
operator|)
operator|&&
comment|/* Not transparent */
operator|(
name|fcsinfo
index|[
name|tcsl
index|]
operator|.
name|size
operator|==
literal|128
operator|||
name|fcsinfo
index|[
name|tcsr
index|]
operator|.
name|size
operator|==
literal|128
operator|)
operator|&&
comment|/* 7 bits */
operator|(
name|fcsinfo
index|[
name|tcsl
index|]
operator|.
name|code
operator|!=
name|FC_USASCII
operator|)
expr_stmt|;
name|inesc
operator|=
name|ES_NORMAL
expr_stmt|;
comment|/* Initial state of recognizer */
ifdef|#
directive|ifdef
name|COMMENT
name|debug
argument_list|(
name|F101
argument_list|,
literal|"tcs"
argument_list|,
literal|""
argument_list|,
name|tcs
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"tcsl"
argument_list|,
literal|""
argument_list|,
name|tcsl
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"tcsr"
argument_list|,
literal|""
argument_list|,
name|tcsr
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"fcsinfo[tcsl].size"
argument_list|,
literal|""
argument_list|,
name|fcsinfo
index|[
name|tcsl
index|]
operator|.
name|size
argument_list|)
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"fcsinfo[tcsr].size"
argument_list|,
literal|""
argument_list|,
name|fcsinfo
index|[
name|tcsr
index|]
operator|.
name|size
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* COMMENT */
name|debug
argument_list|(
name|F101
argument_list|,
literal|"skipesc"
argument_list|,
literal|""
argument_list|,
name|skipesc
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SKIPESC */
endif|#
directive|endif
comment|/* NOCSETS */
comment|/*   This is a label we jump back to when the lower fork sensed the need   to change modes.  As of 5A(178), this is used only by X.25 code   (perhaps unnecessarily? -- The X.25 code needs a lot of testing and   cleaning up...) */
name|newfork
label|:
name|debug
argument_list|(
name|F100
argument_list|,
literal|"CONNECT newfork"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|parent_id
operator|=
name|getpid
argument_list|()
expr_stmt|;
comment|/* Get parent id for signalling */
name|signal
argument_list|(
name|SIGUSR1
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
comment|/* Don't kill myself */
ifdef|#
directive|ifdef
name|SUNX25
name|pipe
argument_list|(
name|padpipe
argument_list|)
expr_stmt|;
comment|/* Create pipe to pass PAD parms */
endif|#
directive|endif
comment|/* SUNX25 */
ifdef|#
directive|ifdef
name|OXOS
comment|/*   Because of the "extended security controls" in Olivetti X/OS,   the killing and killed process must have the same REAL uid.     Otherwise kill() gets ESRCH. */
name|priv_on
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* OXOS */
name|pid
operator|=
name|fork
argument_list|()
expr_stmt|;
comment|/* All ok, make a fork */
if|if
condition|(
name|pid
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* Can't create it. */
name|conres
argument_list|()
expr_stmt|;
comment|/* Reset the console. */
name|perror
argument_list|(
literal|"Can't create keyboard fork"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|quiet
condition|)
block|{
name|printf
argument_list|(
literal|"\r\nCommunications disconnect (Back at %s)\r\n"
argument_list|,
operator|*
name|myhost
condition|?
name|myhost
else|:
ifdef|#
directive|ifdef
name|UNIX
literal|"local UNIX system"
else|#
directive|else
literal|"local system"
endif|#
directive|endif
comment|/* UNIX */
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|what
operator|=
name|W_NOTHING
expr_stmt|;
comment|/* So console modes are set right. */
ifndef|#
directive|ifndef
name|NOCSETS
name|language
operator|=
name|langsv
expr_stmt|;
comment|/* Restore language */
endif|#
directive|endif
comment|/* NOCSETS */
name|parent_id
operator|=
operator|(
name|PID_T
operator|)
literal|0
expr_stmt|;
comment|/* Clean up */
ifdef|#
directive|ifdef
name|DYNAMIC
if|if
condition|(
name|temp
condition|)
name|free
argument_list|(
name|temp
argument_list|)
expr_stmt|;
if|if
condition|(
name|lbuf
condition|)
name|free
argument_list|(
name|lbuf
argument_list|)
expr_stmt|;
comment|/* Free allocated memory */
endif|#
directive|endif
comment|/* DYNAMIC */
return|return
operator|(
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|pid
condition|)
block|{
comment|/* This fork reads, sends keystrokes */
name|what
operator|=
name|W_CONNECT
expr_stmt|;
comment|/* Keep track of what we're doing */
name|active
operator|=
literal|1
expr_stmt|;
name|debug
argument_list|(
name|F101
argument_list|,
literal|"CONNECT keyboard fork duplex"
argument_list|,
literal|""
argument_list|,
name|duplex
argument_list|)
expr_stmt|;
comment|/* Catch communication errors or mode changes in lower fork */
if|if
condition|(
name|setjmp
argument_list|(
name|con_env
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|/* Normal entry... */
name|sjval
operator|=
literal|0
expr_stmt|;
comment|/* Initialize setjmp return code. */
name|signal
argument_list|(
name|SIGUSR1
argument_list|,
name|conn_int
argument_list|)
expr_stmt|;
comment|/* Routine for child process exit. */
name|signal
argument_list|(
name|SIGUSR2
argument_list|,
name|mode_chg
argument_list|)
expr_stmt|;
comment|/* Routine for mode change. */
ifdef|#
directive|ifdef
name|SUNX25
if|if
condition|(
name|network
operator|&&
name|nettype
operator|==
name|NET_SX25
condition|)
block|{
name|obufl
operator|=
literal|0
expr_stmt|;
name|bzero
argument_list|(
name|x25obuf
argument_list|,
sizeof|sizeof
argument_list|(
name|x25obuf
argument_list|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* SUNX25 */
comment|/*   Here is the big loop that gets characters from the keyboard and sends them   out the communication device.  There are two components to the communication   path: the connection from the keyboard to C-Kermit, and from C-Kermit to   the remote computer.  The treatment of the 8th bit of keyboard characters    is governed by SET COMMAND BYTESIZE (cmdmsk).  The treatment of the 8th bit   of characters sent to the remote is governed by SET TERMINAL BYTESIZE   (cmask).   This distinction was introduced in edit 5A(164). */
while|while
condition|(
name|active
condition|)
block|{
ifndef|#
directive|ifndef
name|NOSETKEY
if|if
condition|(
name|kmptr
condition|)
block|{
comment|/* Have current macro? */
if|if
condition|(
operator|(
name|c
operator|=
operator|(
name|CHAR
operator|)
operator|*
name|kmptr
operator|++
operator|)
operator|==
name|NUL
condition|)
block|{
comment|/* Get char from it */
name|kmptr
operator|=
name|NULL
expr_stmt|;
comment|/* If no more chars,  */
continue|continue;
comment|/* reset pointer and continue */
block|}
block|}
else|else
comment|/* No macro... */
endif|#
directive|endif
comment|/* NOSETKEY */
name|c
operator|=
name|congks
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* Read from keyboard */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"** KEYB"
argument_list|,
name|dbchr
argument_list|(
name|c
argument_list|)
argument_list|,
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* If read() got an error... */
ifdef|#
directive|ifdef
name|COMMENT
comment|/*  This seems to cause problems.  If read() returns -1, the signal has already  been delivered, and nothing will wake up the pause(). */
name|pause
argument_list|()
expr_stmt|;
comment|/* Wait for transmitter to finish. */
else|#
directive|else
ifdef|#
directive|ifdef
name|A986
comment|/*   On Altos machines with Xenix 3.0, pressing DEL in connect mode brings us   here (reason unknown).  The console line discipline at this point has   intr = ^C.  The communications tty has intr = DEL but we get here after   pressing DEL on the keyboard, even when the remote system has been set not   to echo.  With A986 defined, we stay in the read loop and beep only if the   offending character is not DEL. */
if|if
condition|(
operator|(
name|c
operator|&
literal|127
operator|)
operator|!=
literal|127
condition|)
name|conoc
argument_list|(
name|BEL
argument_list|)
expr_stmt|;
else|#
directive|else
name|conoc
argument_list|(
name|BEL
argument_list|)
expr_stmt|;
comment|/* Beep */
name|active
operator|=
literal|0
expr_stmt|;
comment|/* and terminate the read loop */
continue|continue;
endif|#
directive|endif
comment|/* A986 */
endif|#
directive|endif
comment|/* COMMENT */
block|}
name|c
operator|&=
name|cmdmsk
expr_stmt|;
comment|/* Do any requested masking */
ifndef|#
directive|ifndef
name|NOSETKEY
comment|/*   Note: kmptr is NULL if we got character c from the keyboard, and it is   not NULL if it came from a macro.  In the latter case, we must avoid   expanding it again. */
if|if
condition|(
operator|!
name|kmptr
operator|&&
name|macrotab
index|[
name|c
index|]
condition|)
block|{
comment|/* Macro definition for c? */
name|kmptr
operator|=
name|macrotab
index|[
name|c
index|]
expr_stmt|;
comment|/* Yes, set up macro pointer */
continue|continue;
comment|/* and restart the loop, */
block|}
else|else
name|c
operator|=
name|keymap
index|[
name|c
index|]
expr_stmt|;
comment|/* else use single-char keymap */
endif|#
directive|endif
comment|/* NOSETKEY */
if|if
condition|(
ifndef|#
directive|ifndef
name|NOSETKEY
operator|!
name|kmptr
operator|&&
endif|#
directive|endif
comment|/* NOSETKEY */
operator|(
operator|(
name|c
operator|&
literal|0x7f
operator|)
operator|==
name|escape
operator|)
condition|)
block|{
comment|/* Escape character? */
name|debug
argument_list|(
name|F000
argument_list|,
literal|"connect got escape"
argument_list|,
literal|""
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|c
operator|=
name|congks
argument_list|(
literal|0
argument_list|)
operator|&
literal|0177
expr_stmt|;
comment|/* Got esc, get its arg */
comment|/* No key mapping here */
name|doesc
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* Now process it */
block|}
else|else
block|{
comment|/* It's not the escape character */
name|csave
operator|=
name|c
expr_stmt|;
comment|/* Save it before translation */
comment|/* for local echoing. */
ifndef|#
directive|ifndef
name|NOCSETS
ifndef|#
directive|ifndef
name|SKIPESC
comment|/* Translate character sets */
if|if
condition|(
name|sxo
condition|)
name|c
operator|=
call|(
modifier|*
name|sxo
call|)
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* From local to intermediate. */
if|if
condition|(
name|rxo
condition|)
name|c
operator|=
call|(
modifier|*
name|rxo
call|)
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* From intermediate to remote. */
else|#
directive|else
if|if
condition|(
name|inesc
operator|==
name|ES_NORMAL
condition|)
block|{
comment|/* If not inside escape seq.. */
comment|/* Translate character sets */
if|if
condition|(
name|sxo
condition|)
name|c
operator|=
call|(
modifier|*
name|sxo
call|)
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* Local to intermediate. */
if|if
condition|(
name|rxo
condition|)
name|c
operator|=
call|(
modifier|*
name|rxo
call|)
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* Intermediate to remote. */
block|}
if|if
condition|(
name|skipesc
condition|)
name|chkaes
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* Check escape sequence status */
endif|#
directive|endif
comment|/* SKIPESC */
endif|#
directive|endif
comment|/* NOCSETS */
comment|/*  If Shift-In/Shift-Out is selected and we have a 7-bit connection,  handle shifting here. */
if|if
condition|(
name|sosi
condition|)
block|{
comment|/* Shift-In/Out selected? */
if|if
condition|(
name|cmask
operator|==
literal|0177
condition|)
block|{
comment|/* In 7-bit environment? */
if|if
condition|(
name|c
operator|&
literal|0200
condition|)
block|{
comment|/* 8-bit character? */
if|if
condition|(
name|shift
operator|==
literal|0
condition|)
block|{
comment|/* If not shifted, */
name|ttoc
argument_list|(
name|dopar
argument_list|(
name|SO
argument_list|)
argument_list|)
expr_stmt|;
comment|/* shift. */
name|shift
operator|=
literal|1
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
name|shift
operator|==
literal|1
condition|)
block|{
comment|/* 7-bit character */
name|ttoc
argument_list|(
name|dopar
argument_list|(
name|SI
argument_list|)
argument_list|)
expr_stmt|;
comment|/* If shifted, */
name|shift
operator|=
literal|0
expr_stmt|;
comment|/* unshift. */
block|}
block|}
block|}
if|if
condition|(
name|c
operator|==
name|SO
condition|)
name|shift
operator|=
literal|1
expr_stmt|;
comment|/* User typed SO */
if|if
condition|(
name|c
operator|==
name|SI
condition|)
name|shift
operator|=
literal|0
expr_stmt|;
comment|/* User typed SI */
block|}
name|c
operator|&=
name|cmask
expr_stmt|;
comment|/* Apply Kermit-to-host mask now. */
ifdef|#
directive|ifdef
name|NETCONN
ifdef|#
directive|ifdef
name|SUNX25
if|if
condition|(
name|network
operator|&&
name|nettype
operator|==
name|NET_SX25
condition|)
block|{
if|if
condition|(
name|padparms
index|[
name|PAD_ECHO
index|]
condition|)
block|{
if|if
condition|(
name|debses
condition|)
name|conol
argument_list|(
name|dbchr
argument_list|(
name|c
argument_list|)
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
operator|(
name|c
operator|!=
name|padparms
index|[
name|PAD_CHAR_DELETE_CHAR
index|]
operator|)
operator|&&
operator|(
name|c
operator|!=
name|padparms
index|[
name|PAD_BUFFER_DELETE_CHAR
index|]
operator|)
operator|&&
operator|(
name|c
operator|!=
name|padparms
index|[
name|PAD_BUFFER_DISPLAY_CHAR
index|]
operator|)
condition|)
name|conoc
argument_list|(
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
name|seslog
condition|)
name|logchar
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|c
operator|==
name|padparms
index|[
name|PAD_BREAK_CHARACTER
index|]
condition|)
name|breakact
argument_list|()
expr_stmt|;
elseif|else
if|if
condition|(
name|padparms
index|[
name|PAD_DATA_FORWARD_TIMEOUT
index|]
condition|)
block|{
name|tosend
operator|=
literal|1
expr_stmt|;
name|x25obuf
index|[
name|obufl
operator|++
index|]
operator|=
name|c
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
operator|(
name|c
operator|==
name|padparms
index|[
name|PAD_CHAR_DELETE_CHAR
index|]
operator|)
operator|||
operator|(
name|c
operator|==
name|padparms
index|[
name|PAD_BUFFER_DELETE_CHAR
index|]
operator|)
operator|||
operator|(
name|c
operator|==
name|padparms
index|[
name|PAD_BUFFER_DISPLAY_CHAR
index|]
operator|)
operator|)
operator|&&
operator|(
name|padparms
index|[
name|PAD_EDITING
index|]
operator|)
condition|)
if|if
condition|(
name|c
operator|==
name|padparms
index|[
name|PAD_CHAR_DELETE_CHAR
index|]
condition|)
if|if
condition|(
name|obufl
operator|>
literal|0
condition|)
block|{
name|conol
argument_list|(
literal|"\b \b"
argument_list|)
expr_stmt|;
name|obufl
operator|--
expr_stmt|;
block|}
else|else
block|{}
elseif|else
if|if
condition|(
name|c
operator|==
name|padparms
index|[
name|PAD_BUFFER_DELETE_CHAR
index|]
condition|)
block|{
name|conol
argument_list|(
literal|"\r\nPAD Buffer Deleted\r\n"
argument_list|)
expr_stmt|;
name|obufl
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|c
operator|==
name|padparms
index|[
name|PAD_BUFFER_DISPLAY_CHAR
index|]
condition|)
block|{
name|conol
argument_list|(
literal|"\r\n"
argument_list|)
expr_stmt|;
name|conol
argument_list|(
name|x25obuf
argument_list|)
expr_stmt|;
name|conol
argument_list|(
literal|"\r\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{}
else|else
block|{
name|x25obuf
index|[
name|obufl
operator|++
index|]
operator|=
name|c
expr_stmt|;
if|if
condition|(
name|obufl
operator|==
name|MAXOX25
condition|)
name|tosend
operator|=
literal|1
expr_stmt|;
elseif|else
if|if
condition|(
name|c
operator|==
name|CR
condition|)
name|tosend
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|tosend
condition|)
if|if
condition|(
name|ttol
argument_list|(
name|x25obuf
argument_list|,
name|obufl
argument_list|)
operator|<
literal|0
condition|)
block|{
name|perror
argument_list|(
literal|"\r\nCan't send characters"
argument_list|)
expr_stmt|;
name|active
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|bzero
argument_list|(
name|x25obuf
argument_list|,
sizeof|sizeof
argument_list|(
name|x25obuf
argument_list|)
argument_list|)
expr_stmt|;
name|obufl
operator|=
literal|0
expr_stmt|;
name|tosend
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{}
empty_stmt|;
block|}
else|else
block|{
endif|#
directive|endif
comment|/* SUNX25 */
comment|/*   This is for telnetting to IBM mainframes in linemode.   Blank lines (when you hit two CRs in a row) are normally ignored.   According to the telnet RFC, we must send both CR and LF.   Also, if the user types the 0xff character, which happens to be the   telnet IAC character, then it must be doubled. */
if|if
condition|(
name|network
operator|&&
name|ttnproto
operator|==
name|NP_TELNET
condition|)
block|{
if|if
condition|(
name|c
operator|==
literal|'\015'
operator|&&
name|duplex
operator|!=
literal|0
condition|)
block|{
name|ttoc
argument_list|(
name|dopar
argument_list|(
literal|'\015'
argument_list|)
argument_list|)
expr_stmt|;
name|conoc
argument_list|(
literal|'\015'
argument_list|)
expr_stmt|;
name|csave
operator|=
name|c
operator|=
literal|'\012'
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|c
operator|==
name|IAC
operator|&&
name|parity
operator|==
literal|0
condition|)
name|ttoc
argument_list|(
name|IAC
argument_list|)
expr_stmt|;
block|}
elseif|else
endif|#
directive|endif
comment|/* NETCONN */
if|if
condition|(
name|c
operator|==
literal|'\015'
operator|&&
name|tnlm
condition|)
block|{
comment|/* TERMINAL NEWLINE ON ? */
name|ttoc
argument_list|(
name|dopar
argument_list|(
literal|'\015'
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Send CR as CRLF */
if|if
condition|(
name|debses
condition|)
name|conol
argument_list|(
name|dbchr
argument_list|(
literal|'\015'
argument_list|)
argument_list|)
expr_stmt|;
name|csave
operator|=
name|c
operator|=
literal|'\012'
expr_stmt|;
block|}
comment|/* Send the character */
if|if
condition|(
name|ttoc
argument_list|(
name|dopar
argument_list|(
name|c
argument_list|)
argument_list|)
operator|>
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|duplex
condition|)
block|{
comment|/* If half duplex, must echo */
if|if
condition|(
name|debses
condition|)
name|conol
argument_list|(
name|dbchr
argument_list|(
name|csave
argument_list|)
argument_list|)
expr_stmt|;
comment|/* the original char */
else|else
comment|/* not the translated one */
name|conoc
argument_list|(
name|csave
argument_list|)
expr_stmt|;
if|if
condition|(
name|seslog
condition|)
block|{
comment|/* And maybe log it too */
name|c2
operator|=
name|csave
expr_stmt|;
if|if
condition|(
name|sessft
operator|==
literal|0
operator|&&
name|csave
operator|==
literal|'\r'
condition|)
name|c2
operator|=
literal|'\n'
expr_stmt|;
name|logchar
argument_list|(
name|c2
argument_list|)
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
name|perror
argument_list|(
literal|"\r\nCan't send character"
argument_list|)
expr_stmt|;
name|active
operator|=
literal|0
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|SUNX25
block|}
endif|#
directive|endif
comment|/* SUNX25 */
block|}
block|}
block|}
comment|/* Come here on death of child */
name|debug
argument_list|(
name|F100
argument_list|,
literal|"CONNECT killing port fork"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|kill
argument_list|(
operator|(
name|int
operator|)
name|pid
argument_list|,
literal|9
argument_list|)
expr_stmt|;
comment|/* Done, kill inferior fork. */
ifdef|#
directive|ifdef
name|OXOS
comment|/* See comments above about Olivetti X/OS. */
name|priv_off
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* OXOS */
name|wait
argument_list|(
operator|(
name|WAIT_T
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|/* Wait till gone. */
if|if
condition|(
name|sjval
operator|==
literal|1
condition|)
block|{
comment|/* Read error on comm device */
name|dohangup
operator|=
literal|1
expr_stmt|;
ifdef|#
directive|ifdef
name|NETCONN
if|if
condition|(
name|network
condition|)
block|{
name|ttclos
argument_list|(
literal|0
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SUNX25
if|if
condition|(
name|nettype
operator|==
name|NET_SX25
condition|)
name|initpad
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* SUNX25 */
block|}
endif|#
directive|endif
comment|/* NETCONN */
block|}
if|if
condition|(
name|sjval
operator|==
literal|2
condition|)
comment|/* If it was a mode change, go back */
goto|goto
name|newfork
goto|;
comment|/* and coordinate with other fork. */
name|conres
argument_list|()
expr_stmt|;
comment|/* Reset the console. */
if|if
condition|(
name|quitnow
condition|)
name|doexit
argument_list|(
name|GOOD_EXIT
argument_list|,
name|xitsta
argument_list|)
expr_stmt|;
comment|/* Exit now if requested. */
if|if
condition|(
name|dohangup
condition|)
block|{
comment|/* If hangup requested, do that. */
name|tthang
argument_list|()
expr_stmt|;
comment|/* And make sure we don't hang up */
name|dohangup
operator|=
literal|0
expr_stmt|;
comment|/* again unless requested again. */
block|}
ifdef|#
directive|ifdef
name|SUNX25
if|if
condition|(
name|dox25clr
condition|)
block|{
comment|/* If X.25 clear requested */
name|x25clear
argument_list|()
expr_stmt|;
comment|/* do that. */
name|initpad
argument_list|()
expr_stmt|;
name|dox25clr
operator|=
literal|0
expr_stmt|;
comment|/* But only once. */
block|}
endif|#
directive|endif
comment|/* SUNX25 */
if|if
condition|(
operator|!
name|quiet
condition|)
name|printf
argument_list|(
literal|"(Back at %s)"
argument_list|,
operator|*
name|myhost
condition|?
name|myhost
else|:
literal|"local UNIX system"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|what
operator|=
name|W_NOTHING
expr_stmt|;
comment|/* So console modes set right. */
ifndef|#
directive|ifndef
name|NOCSETS
name|language
operator|=
name|langsv
expr_stmt|;
comment|/* Restore language */
endif|#
directive|endif
comment|/* NOCSETS */
name|parent_id
operator|=
operator|(
name|PID_T
operator|)
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|DYNAMIC
if|if
condition|(
name|temp
condition|)
name|free
argument_list|(
name|temp
argument_list|)
expr_stmt|;
if|if
condition|(
name|lbuf
condition|)
name|free
argument_list|(
name|lbuf
argument_list|)
expr_stmt|;
comment|/* Free allocated memory */
endif|#
directive|endif
comment|/* DYNAMIC */
return|return
operator|(
literal|1
operator|)
return|;
block|}
else|else
block|{
comment|/* Inferior reads, prints port input */
if|if
condition|(
name|priv_can
argument_list|()
condition|)
block|{
comment|/* Cancel all privs */
name|printf
argument_list|(
literal|"?setuid error - fatal\n"
argument_list|)
expr_stmt|;
name|doexit
argument_list|(
name|BAD_EXIT
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
comment|/* In case these haven't been */
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
comment|/* inherited from above... */
name|shift
operator|=
literal|0
expr_stmt|;
comment|/* Initial shift state. */
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* Wait for parent's handler setup.  */
name|lbp
operator|=
name|lbuf
expr_stmt|;
comment|/* Initialize input buffering */
name|lbc
operator|=
literal|0
expr_stmt|;
name|debug
argument_list|(
name|F100
argument_list|,
literal|"CONNECT starting port fork"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
comment|/* Fresh read, wait for a character. */
ifdef|#
directive|ifdef
name|SUNX25
if|if
condition|(
name|network
operator|&&
operator|(
name|nettype
operator|==
name|NET_SX25
operator|)
condition|)
block|{
name|bzero
argument_list|(
name|x25ibuf
argument_list|,
sizeof|sizeof
argument_list|(
name|x25ibuf
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|ibufl
operator|=
name|ttxin
argument_list|(
name|MAXIX25
argument_list|,
name|x25ibuf
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|ibufl
operator|==
operator|-
literal|2
condition|)
block|{
comment|/* PAD parms changes */
name|write
argument_list|(
name|padpipe
index|[
literal|1
index|]
argument_list|,
name|padparms
argument_list|,
name|MAXPADPARMS
argument_list|)
expr_stmt|;
name|kill
argument_list|(
name|parent_id
argument_list|,
name|SIGUSR2
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
operator|!
name|quiet
condition|)
name|printf
argument_list|(
literal|"\r\nCommunications disconnect "
argument_list|)
expr_stmt|;
name|kill
argument_list|(
name|parent_id
argument_list|,
name|SIGUSR1
argument_list|)
expr_stmt|;
block|}
name|pause
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|debses
condition|)
block|{
comment|/* Debugging output */
name|p
operator|=
name|x25ibuf
expr_stmt|;
while|while
condition|(
name|ibufl
operator|--
condition|)
block|{
name|c
operator|=
operator|*
name|p
operator|++
expr_stmt|;
name|conol
argument_list|(
name|dbchr
argument_list|(
name|c
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
name|sosi
ifndef|#
directive|ifndef
name|NOCSETS
operator|||
name|tcsl
operator|!=
name|tcsr
endif|#
directive|endif
comment|/* NOCSETS */
condition|)
block|{
comment|/* Character at a time */
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
name|ibufl
condition|;
name|i
operator|++
control|)
block|{
name|c
operator|=
name|x25ibuf
index|[
name|i
index|]
operator|&
name|cmask
expr_stmt|;
if|if
condition|(
name|sosi
condition|)
block|{
comment|/* Handle SI/SO */
if|if
condition|(
name|c
operator|==
name|SO
condition|)
block|{
name|shift
operator|=
literal|1
expr_stmt|;
continue|continue;
block|}
elseif|else
if|if
condition|(
name|c
operator|==
name|SI
condition|)
block|{
name|shift
operator|=
literal|0
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|shift
condition|)
name|c
operator||=
literal|0200
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|NOCSETS
ifndef|#
directive|ifndef
name|SKIPESC
comment|/* Translate character sets */
if|if
condition|(
name|sxo
condition|)
name|c
operator|=
call|(
modifier|*
name|sxo
call|)
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* From local to intermediate. */
if|if
condition|(
name|rxo
condition|)
name|c
operator|=
call|(
modifier|*
name|rxo
call|)
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* From intermediate to remote. */
else|#
directive|else
comment|/* Skipping escape sequences... */
if|if
condition|(
name|inesc
operator|==
name|ES_NORMAL
condition|)
block|{
comment|/* If not inside escape seq.. */
comment|/* Translate character sets */
if|if
condition|(
name|sxo
condition|)
name|c
operator|=
call|(
modifier|*
name|sxo
call|)
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* Local to intermediate. */
if|if
condition|(
name|rxo
condition|)
name|c
operator|=
call|(
modifier|*
name|rxo
call|)
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* Intermediate to remote. */
block|}
if|if
condition|(
name|skipesc
condition|)
name|chkaes
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* Check escape sequence status */
endif|#
directive|endif
comment|/* SKIPESC */
endif|#
directive|endif
comment|/* NOCSETS */
name|c
operator|&=
name|cmdmsk
expr_stmt|;
comment|/* Apply command mask. */
name|conoc
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* Output to screen */
name|logchar
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* and session log */
block|}
block|}
else|else
block|{
comment|/* All at once */
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
name|ibufl
condition|;
name|i
operator|++
control|)
name|x25ibuf
index|[
name|i
index|]
operator|&=
operator|(
name|cmask
operator|&
name|cmdmsk
operator|)
expr_stmt|;
name|conxo
argument_list|(
name|ibufl
argument_list|,
name|x25ibuf
argument_list|)
expr_stmt|;
if|if
condition|(
name|seslog
condition|)
name|zsoutx
argument_list|(
name|ZSFILE
argument_list|,
name|x25ibuf
argument_list|,
name|ibufl
argument_list|)
expr_stmt|;
block|}
block|}
continue|continue;
block|}
else|else
block|{
comment|/* Not X.25... */
endif|#
directive|endif
comment|/* SUNX25 */
comment|/*   Get the next communication line character from our internal buffer.   If the buffer is empty, refill it. */
if|if
condition|(
name|lbc
operator|<
literal|1
condition|)
block|{
comment|/* Nothing left in input buffer. */
name|lbc
operator|=
literal|0
expr_stmt|;
comment|/* Must refresh it. */
name|lbp
operator|=
name|lbuf
expr_stmt|;
name|debug
argument_list|(
name|F100
argument_list|,
literal|"CONNECT refill buf"
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|c
operator|=
name|ttinc
argument_list|(
literal|0
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
comment|/* Get char from comm line */
if|if
condition|(
operator|!
name|quiet
condition|)
block|{
comment|/* Failed... */
name|printf
argument_list|(
literal|"\r\nCommunications disconnect "
argument_list|)
expr_stmt|;
if|if
condition|(
name|c
operator|==
operator|-
literal|3
ifdef|#
directive|ifdef
name|UTEK
comment|/* This happens on UTEK if there's no carrier */
operator|&&
name|errno
operator|!=
name|EWOULDBLOCK
endif|#
directive|endif
comment|/* UTEK */
condition|)
name|perror
argument_list|(
literal|"\r\nCan't read character"
argument_list|)
expr_stmt|;
block|}
name|tthang
argument_list|()
expr_stmt|;
comment|/* Hang up our side. */
ifdef|#
directive|ifdef
name|NETCONN
if|if
condition|(
name|network
operator|&&
name|ttnproto
operator|==
name|NP_TELNET
condition|)
name|tn_init
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
comment|/* NETCONN */
name|kill
argument_list|(
name|parent_id
argument_list|,
name|SIGUSR1
argument_list|)
expr_stmt|;
comment|/* Notify parent */
for|for
control|(
init|;
condition|;
control|)
name|pause
argument_list|()
expr_stmt|;
comment|/* and wait to be killed */
block|}
else|else
block|{
comment|/* Otherwise, got one character */
operator|*
name|lbp
operator|++
operator|=
name|c
expr_stmt|;
comment|/* Advance buffer pointer */
name|lbc
operator|++
expr_stmt|;
comment|/* and count. */
block|}
ifdef|#
directive|ifdef
name|TNCODE
comment|/*   The following buffering code makes CONNECT mode a lot more efficient,   especially on slow workstations.  But we can't use it if we're doing TELNET   protocol because we won't notice any in-band TELNET commands (tn_doop()   wants to read the characters following the IAC itself).  So this code will   always be used on non-network systems and it will be used on network systems   except during a TELNET session. */
if|if
condition|(
operator|!
name|network
operator|||
name|ttnproto
operator|!=
name|NP_TELNET
condition|)
block|{
endif|#
directive|endif
comment|/* TNCODE */
comment|/* Now quickly read any more that might have arrived */
while|while
condition|(
operator|(
name|n
operator|=
name|ttchk
argument_list|()
operator|)
operator|>
literal|0
condition|)
block|{
comment|/* Any more waiting? */
if|if
condition|(
name|n
operator|>
operator|(
name|LBUFL
operator|-
name|lbc
operator|)
condition|)
comment|/* Get them all at once. */
name|n
operator|=
name|LBUFL
operator|-
name|lbc
expr_stmt|;
comment|/* Don't overflow buffer */
if|if
condition|(
operator|(
name|n
operator|=
name|ttxin
argument_list|(
name|n
argument_list|,
operator|(
name|CHAR
operator|*
operator|)
name|lbp
argument_list|)
operator|)
operator|>
literal|0
condition|)
block|{
name|lbp
operator|+=
name|n
expr_stmt|;
comment|/* Advance pointer */
name|lbc
operator|+=
name|n
expr_stmt|;
comment|/* and counter */
block|}
else|else
break|break;
comment|/* Break on error */
block|}
name|debug
argument_list|(
name|F101
argument_list|,
literal|"connect lbc"
argument_list|,
literal|""
argument_list|,
name|lbc
argument_list|)
expr_stmt|;
comment|/* Log how many */
comment|/*   The following outputs to the console as much as possible in one write to   maximize throughput.  We can use this only if not doing any character-based   operations like TELNET negotiations, Shift-In/Shift/Out, or session   debugging.  Character-set translation MUST BE ONE-TO-ONE. */
if|if
condition|(
operator|!
name|sosi
operator|&&
operator|!
name|debses
condition|)
block|{
comment|/* No SO/SI or debugging... */
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
name|lbc
condition|;
name|n
operator|++
control|)
block|{
name|c
operator|=
name|lbuf
index|[
name|n
index|]
operator|&
name|cmask
expr_stmt|;
comment|/* Apply terminal mask */
ifndef|#
directive|ifndef
name|NOCSETS
ifndef|#
directive|ifndef
name|SKIPESC
if|if
condition|(
name|sxi
condition|)
name|c
operator|=
call|(
modifier|*
name|sxi
call|)
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* Xlate char sets */
if|if
condition|(
name|rxi
condition|)
name|c
operator|=
call|(
modifier|*
name|rxi
call|)
argument_list|(
name|c
argument_list|)
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|inesc
operator|==
name|ES_NORMAL
condition|)
block|{
if|if
condition|(
name|sxi
condition|)
name|c
operator|=
call|(
modifier|*
name|sxi
call|)
argument_list|(
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
name|rxi
condition|)
name|c
operator|=
call|(
modifier|*
name|rxi
call|)
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|skipesc
condition|)
name|chkaes
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* Esc seq status */
endif|#
directive|endif
comment|/* SKIPESC */
endif|#
directive|endif
comment|/* NOCSETS */
name|lbuf
index|[
name|n
index|]
operator|=
name|c
operator|&
name|cmdmsk
expr_stmt|;
comment|/* Replace in buffer */
if|if
condition|(
name|seslog
condition|)
name|logchar
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* Log it */
block|}
name|conxo
argument_list|(
name|lbc
argument_list|,
name|lbuf
argument_list|)
expr_stmt|;
comment|/* Write out whole buffer */
name|lbc
operator|=
literal|0
expr_stmt|;
comment|/* Reset buffer count */
continue|continue;
comment|/* ...the big while(1) loop */
block|}
ifdef|#
directive|ifdef
name|TNCODE
block|}
comment|/* Closing bracket for Not-TELNET section */
endif|#
directive|endif
comment|/* TNCODE */
name|lbp
operator|=
name|lbuf
expr_stmt|;
comment|/* Reset buffer pointer to beginning */
block|}
name|c
operator|=
operator|*
name|lbp
operator|++
expr_stmt|;
comment|/* Get a character from the buffer. */
name|lbc
operator|--
expr_stmt|;
comment|/* Count it. */
name|debug
argument_list|(
name|F111
argument_list|,
literal|"** PORT"
argument_list|,
name|dbchr
argument_list|(
name|c
argument_list|)
argument_list|,
name|c
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|TNCODE
comment|/* Handle TELNET negotiations here */
if|if
condition|(
name|network
operator|&&
name|ttnproto
operator|==
name|NP_TELNET
operator|&&
operator|(
operator|(
name|c
operator|&
literal|0xff
operator|)
operator|==
name|IAC
operator|)
condition|)
block|{
if|if
condition|(
operator|(
name|tx
operator|=
name|tn_doop
argument_list|(
operator|(
name|c
operator|&
literal|0xff
operator|)
argument_list|,
name|duplex
argument_list|)
operator|)
operator|==
literal|0
condition|)
block|{
continue|continue;
block|}
elseif|else
if|if
condition|(
name|tx
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* I/O error */
if|if
condition|(
operator|!
name|quiet
condition|)
name|printf
argument_list|(
literal|"\r\nCommunications disconnect "
argument_list|)
expr_stmt|;
name|kill
argument_list|(
name|parent_id
argument_list|,
name|SIGUSR1
argument_list|)
expr_stmt|;
comment|/* Notify parent. */
for|for
control|(
init|;
condition|;
control|)
name|pause
argument_list|()
expr_stmt|;
comment|/* Wait to be killed. */
block|}
elseif|else
if|if
condition|(
operator|(
name|tx
operator|==
literal|1
operator|)
operator|&&
operator|(
operator|!
name|duplex
operator|)
condition|)
block|{
comment|/* ECHO change */
name|kill
argument_list|(
name|parent_id
argument_list|,
name|SIGUSR2
argument_list|)
expr_stmt|;
comment|/* Tell the parent fork */
name|duplex
operator|=
literal|1
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|tx
operator|==
literal|2
operator|)
operator|&&
operator|(
name|duplex
operator|)
condition|)
block|{
comment|/* ECHO change */
name|kill
argument_list|(
name|parent_id
argument_list|,
name|SIGUSR2
argument_list|)
expr_stmt|;
name|duplex
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|tx
operator|==
literal|3
condition|)
block|{
comment|/* Quoted IAC */
name|c
operator|=
literal|255
expr_stmt|;
block|}
else|else
continue|continue;
comment|/* Negotiation OK, get next char. */
block|}
endif|#
directive|endif
comment|/* TNCODE */
if|if
condition|(
name|debses
condition|)
block|{
comment|/* Output character to screen */
name|conol
argument_list|(
name|dbchr
argument_list|(
name|c
argument_list|)
argument_list|)
expr_stmt|;
comment|/* debugging display */
block|}
else|else
block|{
comment|/* or regular display ... */
name|c
operator|&=
name|cmask
expr_stmt|;
comment|/* Apply Kermit-to-remote mask */
if|if
condition|(
name|sosi
condition|)
block|{
comment|/* Handle SI/SO */
if|if
condition|(
name|c
operator|==
name|SO
condition|)
block|{
comment|/* Shift Out */
name|shift
operator|=
literal|1
expr_stmt|;
continue|continue;
block|}
elseif|else
if|if
condition|(
name|c
operator|==
name|SI
condition|)
block|{
comment|/* Shift In */
name|shift
operator|=
literal|0
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|shift
condition|)
name|c
operator||=
literal|0200
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|NOCSETS
ifndef|#
directive|ifndef
name|SKIPESC
comment|/* Translate character sets */
if|if
condition|(
name|sxi
condition|)
name|c
operator|=
call|(
modifier|*
name|sxi
call|)
argument_list|(
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
name|rxi
condition|)
name|c
operator|=
call|(
modifier|*
name|rxi
call|)
argument_list|(
name|c
argument_list|)
expr_stmt|;
else|#
directive|else
if|if
condition|(
name|inesc
operator|==
name|ES_NORMAL
condition|)
block|{
comment|/* Translate character sets */
if|if
condition|(
name|sxi
condition|)
name|c
operator|=
call|(
modifier|*
name|sxi
call|)
argument_list|(
name|c
argument_list|)
expr_stmt|;
if|if
condition|(
name|rxi
condition|)
name|c
operator|=
call|(
modifier|*
name|rxi
call|)
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|skipesc
condition|)
name|chkaes
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* Adjust escape sequence status */
endif|#
directive|endif
comment|/* SKIPESC */
endif|#
directive|endif
comment|/* NOCSETS */
name|c
operator|&=
name|cmdmsk
expr_stmt|;
comment|/* Apply command mask. */
name|conoc
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* Output to screen */
if|if
condition|(
name|seslog
condition|)
name|logchar
argument_list|(
name|c
argument_list|)
expr_stmt|;
comment|/* Take care of session log */
block|}
ifdef|#
directive|ifdef
name|SUNX25
block|}
endif|#
directive|endif
comment|/* SUNX25 */
block|}
block|}
block|}
end_function

begin_comment
comment|/*  H C O N N E  --  Give help message for connect.  */
end_comment

begin_function
name|int
name|hconne
parameter_list|()
block|{
name|int
name|c
decl_stmt|;
specifier|static
name|char
modifier|*
name|hlpmsg
index|[]
init|=
block|{
literal|"\r\n  0 (zero) to send a null"
block|,
literal|"\r\n  B to send a BREAK"
block|,
ifdef|#
directive|ifdef
name|UNIX
literal|"\r\n  L to send a Long BREAK"
block|,
endif|#
directive|endif
comment|/* UNIX */
ifdef|#
directive|ifdef
name|SUNX25
literal|"\r\n  I to send X.25 interrupt packet"
block|,
literal|"\r\n  R to reset the virtual circuit"
block|,
literal|"\r\n  H to hangup the connection (clear virtual circuit)"
block|,
else|#
directive|else
literal|"\r\n  H to hangup and close the connection"
block|,
endif|#
directive|endif
comment|/* SUNX25 */
literal|"\r\n  Q to hangup and quit Kermit"
block|,
literal|"\r\n  S for status"
block|,
literal|"\r\n  ! to push to local shell"
block|,
literal|"\r\n  Z to suspend"
block|,
literal|"\r\n  \\ backslash escape:"
block|,
literal|"\r\n    \\nnn decimal character code"
block|,
literal|"\r\n    \\Onnn octal character code"
block|,
literal|"\r\n    \\Xhh  hexadecimal character code"
block|,
literal|"\r\n    terminate with carriage return."
block|,
literal|"\r\n  ? for help"
block|,
literal|"\r\n escape character twice to send the escape character"
block|,
literal|"\r\n space-bar to resume the CONNECT command\r\n\r\n"
block|,
literal|""
block|}
decl_stmt|;
name|conol
argument_list|(
literal|"\r\nPress C to return to "
argument_list|)
expr_stmt|;
name|conol
argument_list|(
operator|*
name|myhost
condition|?
name|myhost
else|:
literal|"the C-Kermit prompt"
argument_list|)
expr_stmt|;
name|conol
argument_list|(
literal|", or:"
argument_list|)
expr_stmt|;
name|conola
argument_list|(
name|hlpmsg
argument_list|)
expr_stmt|;
comment|/* Print the help message. */
name|conol
argument_list|(
literal|"Command>"
argument_list|)
expr_stmt|;
comment|/* Prompt for command. */
name|c
operator|=
name|congks
argument_list|(
literal|0
argument_list|)
operator|&
literal|0177
expr_stmt|;
comment|/* Get character, strip any parity. */
comment|/* No key mapping or translation here */
if|if
condition|(
name|c
operator|!=
name|CMDQ
condition|)
name|conoll
argument_list|(
literal|""
argument_list|)
expr_stmt|;
return|return
operator|(
name|c
operator|)
return|;
comment|/* Return it. */
block|}
end_function

begin_comment
comment|/*  D O E S C  --  Process an escape character argument  */
end_comment

begin_function
name|VOID
ifdef|#
directive|ifdef
name|CK_ANSIC
name|doesc
parameter_list|(
name|char
name|c
parameter_list|)
else|#
directive|else
function|doesc
parameter_list|(
name|c
parameter_list|)
name|char
name|c
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* doesc */
block|{
name|CHAR
name|d
decl_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
if|if
condition|(
name|c
operator|==
name|escape
condition|)
block|{
comment|/* Send escape character */
name|d
operator|=
name|dopar
argument_list|(
name|c
argument_list|)
expr_stmt|;
name|ttoc
argument_list|(
name|d
argument_list|)
expr_stmt|;
return|return;
block|}
elseif|else
comment|/* Or else look it up below. */
if|if
condition|(
name|isupper
argument_list|(
name|c
argument_list|)
condition|)
name|c
operator|=
name|tolower
argument_list|(
name|c
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|c
condition|)
block|{
case|case
literal|'c'
case|:
comment|/* Close connection */
case|case
literal|'\03'
case|:
name|active
operator|=
literal|0
expr_stmt|;
name|conol
argument_list|(
literal|"\r\n"
argument_list|)
expr_stmt|;
return|return;
case|case
literal|'b'
case|:
comment|/* Send a BREAK signal */
case|case
literal|'\02'
case|:
name|ttsndb
argument_list|()
expr_stmt|;
return|return;
ifdef|#
directive|ifdef
name|UNIX
case|case
literal|'l'
case|:
comment|/* Send a Long BREAK signal */
name|ttsndlb
argument_list|()
expr_stmt|;
return|return;
endif|#
directive|endif
comment|/* UNIX */
case|case
literal|'h'
case|:
comment|/* Hangup */
case|case
literal|'\010'
case|:
ifdef|#
directive|ifdef
name|SUNX25
if|if
condition|(
name|network
operator|&&
operator|(
name|nettype
operator|==
name|NET_SX25
operator|)
condition|)
name|dox25clr
operator|=
literal|1
expr_stmt|;
else|else
endif|#
directive|endif
comment|/* SUNX25 */
name|dohangup
operator|=
literal|1
expr_stmt|;
name|active
operator|=
literal|0
expr_stmt|;
name|conol
argument_list|(
literal|"\r\nHanging up "
argument_list|)
expr_stmt|;
return|return;
ifdef|#
directive|ifdef
name|SUNX25
case|case
literal|'i'
case|:
comment|/* Send an X.25 interrupt packet */
case|case
literal|'\011'
case|:
if|if
condition|(
name|network
operator|&&
operator|(
name|nettype
operator|==
name|NET_SX25
operator|)
condition|)
operator|(
name|VOID
operator|)
name|x25intr
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|conol
argument_list|(
literal|"\r\n"
argument_list|)
expr_stmt|;
return|return;
case|case
literal|'r'
case|:
comment|/* Reset the X.25 virtual circuit */
case|case
literal|'\022'
case|:
if|if
condition|(
name|network
operator|&&
operator|(
name|nettype
operator|==
name|NET_SX25
operator|)
condition|)
operator|(
name|VOID
operator|)
name|x25reset
argument_list|()
expr_stmt|;
name|conol
argument_list|(
literal|"\r\n"
argument_list|)
expr_stmt|;
return|return;
endif|#
directive|endif
comment|/* SUNX25 */
case|case
literal|'q'
case|:
name|quitnow
operator|=
literal|1
expr_stmt|;
name|active
operator|=
literal|0
expr_stmt|;
name|conol
argument_list|(
literal|"\r\n"
argument_list|)
expr_stmt|;
return|return;
case|case
literal|'s'
case|:
comment|/* Status */
name|conol
argument_list|(
literal|"\r\nConnected thru "
argument_list|)
expr_stmt|;
name|conol
argument_list|(
name|ttname
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SUNX25
if|if
condition|(
name|network
operator|&&
operator|(
name|nettype
operator|==
name|NET_SX25
operator|)
condition|)
name|printf
argument_list|(
literal|", Link ID %d, LCN %d"
argument_list|,
name|linkid
argument_list|,
name|lcn
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* SUNX25 */
if|if
condition|(
name|speed
operator|>=
literal|0L
condition|)
block|{
name|sprintf
argument_list|(
name|temp
argument_list|,
literal|", speed %ld"
argument_list|,
name|speed
argument_list|)
expr_stmt|;
name|conol
argument_list|(
name|temp
argument_list|)
expr_stmt|;
block|}
name|sprintf
argument_list|(
name|temp
argument_list|,
literal|", %d terminal bits"
argument_list|,
operator|(
name|cmask
operator|==
literal|0177
operator|)
condition|?
literal|7
else|:
literal|8
argument_list|)
expr_stmt|;
name|conol
argument_list|(
name|temp
argument_list|)
expr_stmt|;
if|if
condition|(
name|parity
condition|)
block|{
name|conol
argument_list|(
literal|", "
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|parity
condition|)
block|{
case|case
literal|'e'
case|:
name|conol
argument_list|(
literal|"even"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'o'
case|:
name|conol
argument_list|(
literal|"odd"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'s'
case|:
name|conol
argument_list|(
literal|"space"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'m'
case|:
name|conol
argument_list|(
literal|"mark"
argument_list|)
expr_stmt|;
break|break;
block|}
name|conol
argument_list|(
literal|" parity"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|seslog
condition|)
block|{
name|conol
argument_list|(
literal|", logging to "
argument_list|)
expr_stmt|;
name|conol
argument_list|(
name|sesfil
argument_list|)
expr_stmt|;
block|}
name|conoll
argument_list|(
literal|""
argument_list|)
expr_stmt|;
return|return;
case|case
literal|'?'
case|:
comment|/* Help */
name|c
operator|=
name|hconne
argument_list|()
expr_stmt|;
continue|continue;
case|case
literal|'0'
case|:
comment|/* Send a null */
name|c
operator|=
literal|'\0'
expr_stmt|;
name|d
operator|=
name|dopar
argument_list|(
name|c
argument_list|)
expr_stmt|;
name|ttoc
argument_list|(
name|d
argument_list|)
expr_stmt|;
return|return;
ifndef|#
directive|ifndef
name|NOPUSH
case|case
literal|'z'
case|:
case|case
literal|'\032'
case|:
comment|/* Suspend */
name|stptrap
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return;
case|case
literal|'@'
case|:
comment|/* Start inferior command processor */
case|case
literal|'!'
case|:
name|conres
argument_list|()
expr_stmt|;
comment|/* Put console back to normal */
name|zshcmd
argument_list|(
literal|""
argument_list|)
expr_stmt|;
comment|/* Fork a shell. */
if|if
condition|(
name|conbin
argument_list|(
name|escape
argument_list|)
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"Error resuming CONNECT session\n"
argument_list|)
expr_stmt|;
name|active
operator|=
literal|0
expr_stmt|;
block|}
return|return;
endif|#
directive|endif
comment|/* NOPUSH */
case|case
name|SP
case|:
comment|/* Space, ignore */
return|return;
default|default:
comment|/* Other */
if|if
condition|(
name|c
operator|==
name|CMDQ
condition|)
block|{
comment|/* Backslash escape */
name|int
name|x
decl_stmt|;
name|kbp
operator|=
name|kbuf
expr_stmt|;
operator|*
name|kbp
operator|++
operator|=
name|c
expr_stmt|;
while|while
condition|(
operator|(
operator|(
name|c
operator|=
operator|(
name|congks
argument_list|(
literal|0
argument_list|)
operator|&
name|cmdmsk
operator|)
operator|)
operator|!=
literal|'\r'
operator|)
operator|&&
operator|(
name|c
operator|!=
literal|'\n'
operator|)
condition|)
operator|*
name|kbp
operator|++
operator|=
name|c
expr_stmt|;
operator|*
name|kbp
operator|=
name|NUL
expr_stmt|;
name|kbp
operator|=
name|kbuf
expr_stmt|;
name|x
operator|=
name|xxesc
argument_list|(
operator|&
name|kbp
argument_list|)
expr_stmt|;
comment|/* Interpret it */
if|if
condition|(
name|x
operator|>=
literal|0
condition|)
block|{
comment|/* No key mapping here */
name|c
operator|=
name|dopar
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|ttoc
argument_list|(
name|c
argument_list|)
expr_stmt|;
return|return;
block|}
else|else
block|{
comment|/* Invalid backslash code. */
name|conoc
argument_list|(
name|BEL
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
name|conoc
argument_list|(
name|BEL
argument_list|)
expr_stmt|;
return|return;
comment|/* Invalid esc arg, beep */
block|}
block|}
block|}
end_function

begin_function
name|VOID
ifdef|#
directive|ifdef
name|CK_ANSIC
name|logchar
parameter_list|(
name|char
name|c
parameter_list|)
else|#
directive|else
function|logchar
parameter_list|(
name|c
parameter_list|)
name|char
name|c
decl_stmt|;
endif|#
directive|endif
comment|/* CK_ANSIC */
comment|/* logchar */
block|{
comment|/* Log character c to session log */
if|if
condition|(
name|seslog
condition|)
if|if
condition|(
operator|(
name|sessft
operator|!=
literal|0
operator|)
operator|||
operator|(
name|c
operator|!=
literal|'\r'
operator|&&
name|c
operator|!=
literal|'\0'
operator|&&
name|c
operator|!=
name|XON
operator|&&
name|c
operator|!=
name|XOFF
operator|)
condition|)
if|if
condition|(
name|zchout
argument_list|(
name|ZSFILE
argument_list|,
name|c
argument_list|)
operator|<
literal|0
condition|)
block|{
name|conoll
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|conoll
argument_list|(
literal|"ERROR WRITING SESSION LOG, LOG CLOSED!"
argument_list|)
expr_stmt|;
name|seslog
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function

end_unit

