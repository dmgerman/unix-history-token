begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************  * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *  * is provided to you without charge, and with no warranty.  You may give  *  * away copies of JOVE, including sources, provided that this notice is    *  * included in all the files.                                              *  ***************************************************************************/
end_comment

begin_comment
comment|/* jove.h header file to be included by EVERYONE */
end_comment

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|TUNED
end_ifndef

begin_include
include|#
directive|include
file|"tune.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAC
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* proto: macro to allow us to prototype any function declaration  * without upsetting old compilers.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|REALSTDC
end_ifdef

begin_define
define|#
directive|define
name|USE_PROTOTYPES
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_PROTOTYPES
end_ifdef

begin_define
define|#
directive|define
name|proto
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NO_PTRPROTO
end_ifdef

begin_comment
comment|/* on these systems, a prototype cannot be used for a pointer to function */
end_comment

begin_define
define|#
directive|define
name|ptrproto
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ptrproto
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|proto
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_define
define|#
directive|define
name|ptrproto
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* There are two ways to handle functions with a variable number of args.  * The old portable way uses varargs.h.  The way sanctioned by ANSI X3J11  * uses stdarg.h.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|REALSTDC
end_ifdef

begin_define
define|#
directive|define
name|STDARGS
value|1
end_define

begin_define
define|#
directive|define
name|va_init
parameter_list|(
name|ap
parameter_list|,
name|parmN
parameter_list|)
value|{ va_start((ap), (parmN)); }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|va_init
parameter_list|(
name|ap
parameter_list|,
name|parmN
parameter_list|)
value|{ va_start((ap)); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ANSI Goodies and their substitutes  *  * const: readonly type qualifier  *  * volatile: type qualifier indicating one of two kinds of magic.  * 1. This object may be modified by an event unknown to the implementation  *    (eg. asynchronous signal or memory-mapped I/O device).  * 2. This automatic variable might be modified between a setjmp()  *    and a longjmp(), and we wish it to have the correct value after  *    the longjmp().  This second meaning is an X3J11 abomination.  * So far, only the second meaning is used.  *  * UnivPtr: universal pointer type  *  * UnivConstPtr: universal pointer to const  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|REALSTDC
end_ifdef

begin_typedef
typedef|typedef
name|void
modifier|*
name|UnivPtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|void
modifier|*
name|UnivConstPtr
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !REALSTDC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|const
end_ifndef

begin_define
define|#
directive|define
name|const
end_define

begin_comment
comment|/* Only in ANSI C.  Pity */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|volatile
end_ifndef

begin_define
define|#
directive|define
name|volatile
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|char
modifier|*
name|UnivPtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|char
modifier|*
name|UnivConstPtr
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !REALSTDC */
end_comment

begin_comment
comment|/* According to the ANSI standard for C, any library routine may  * be defined as a macro with parameters.  In order to prevent  * the expansion of this macro in a declaration of the routine,  * ANSI suggests parenthesizing the identifier.  This is a reasonable  * and legal approach, even for K&R C.  *  * A bug in the MIPS compiler used on MIPS, IRIS, and probably other  * MIPS R[23]000 based systems, causes the compiler to reject  * these declarations (at least at the current time, 1989 August).  * To avoid this bug, we conditionally define and use UNMACRO.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|mips
end_ifdef

begin_define
define|#
directive|define
name|UNMACRO
parameter_list|(
name|proc
parameter_list|)
value|proc
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UNMACRO
parameter_list|(
name|proc
parameter_list|)
value|(proc)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Since we don't use stdio.h, we may have to define NULL and EOF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EOF
end_ifndef

begin_define
define|#
directive|define
name|EOF
value|(-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|private
value|static
end_define

begin_typedef
typedef|typedef
name|int
name|bool
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NO
value|0
end_define

begin_define
define|#
directive|define
name|YES
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|OFF
value|0
end_define

begin_define
define|#
directive|define
name|ON
value|1
end_define

begin_comment
comment|/* typedef structure definitions */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IPROCS
end_ifdef

begin_typedef
typedef|typedef
name|struct
name|process
name|Process
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|struct
name|window
name|Window
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|position
name|Bufpos
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|mark
name|Mark
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|buffer
name|Buffer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|line
name|Line
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|iobuf
name|IOBUF
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"buf.h"
end_include

begin_include
include|#
directive|include
file|"wind.h"
end_include

begin_include
include|#
directive|include
file|"io.h"
end_include

begin_include
include|#
directive|include
file|"dataobj.h"
end_include

begin_include
include|#
directive|include
file|"keymaps.h"
end_include

begin_include
include|#
directive|include
file|"argcount.h"
end_include

begin_include
include|#
directive|include
file|"util.h"
end_include

begin_include
include|#
directive|include
file|"vars.h"
end_include

begin_include
include|#
directive|include
file|"screen.h"
end_include

begin_comment
comment|/* return codes for command completion (all< 0 because>= 0 are    legitimate offsets into array of strings */
end_comment

begin_define
define|#
directive|define
name|AMBIGUOUS
value|(-2)
end_define

begin_comment
comment|/* matches more than one at this point */
end_comment

begin_define
define|#
directive|define
name|UNIQUE
value|(-3)
end_define

begin_comment
comment|/* matches only one string */
end_comment

begin_define
define|#
directive|define
name|ORIGINAL
value|(-4)
end_define

begin_comment
comment|/* matches no strings at all! */
end_comment

begin_define
define|#
directive|define
name|NULLSTRING
value|(-5)
end_define

begin_comment
comment|/* just hit return without typing anything */
end_comment

begin_comment
comment|/* values for the `flags' argument to complete */
end_comment

begin_define
define|#
directive|define
name|NOTHING
value|0
end_define

begin_comment
comment|/* opposite of RET_STATE */
end_comment

begin_define
define|#
directive|define
name|RET_STATE
value|1
end_define

begin_comment
comment|/* return state when we hit return */
end_comment

begin_define
define|#
directive|define
name|RCOMMAND
value|2
end_define

begin_comment
comment|/* we are reading a joverc file */
end_comment

begin_define
define|#
directive|define
name|CASEIND
value|4
end_define

begin_comment
comment|/* map all to lower case */
end_comment

begin_define
define|#
directive|define
name|FORWARD
value|1
end_define

begin_define
define|#
directive|define
name|BACKWARD
value|(-1)
end_define

begin_define
define|#
directive|define
name|ARG_CMD
value|1
end_define

begin_define
define|#
directive|define
name|LINECMD
value|2
end_define

begin_define
define|#
directive|define
name|KILLCMD
value|3
end_define

begin_comment
comment|/* so we can merge kills */
end_comment

begin_define
define|#
directive|define
name|YANKCMD
value|4
end_define

begin_comment
comment|/* so we can do ESC Y (yank-pop) */
end_comment

begin_decl_stmt
specifier|extern
name|jmp_buf
name|mainjmp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* setjmp/longjmp args for DoKeys() mainjmp */
end_comment

begin_define
define|#
directive|define
name|FIRSTCALL
value|0
end_define

begin_define
define|#
directive|define
name|ERROR
value|1
end_define

begin_define
define|#
directive|define
name|COMPLAIN
value|2
end_define

begin_comment
comment|/* do the error without a getDOT */
end_comment

begin_define
define|#
directive|define
name|QUIT
value|3
end_define

begin_comment
comment|/* leave this level of recursion */
end_comment

begin_define
define|#
directive|define
name|INT_OKAY
value|0
end_define

begin_define
define|#
directive|define
name|INT_BAD
value|(-1)
end_define

begin_decl_stmt
specifier|extern
name|char
name|NullStr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ProcFmt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|LastKeyStruck
decl_stmt|,
name|RecDepth
decl_stmt|,
comment|/* recursion depth */
name|InJoverc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* depth in sourcing */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|InMacDefine
decl_stmt|,
comment|/* are we defining a macro right now? */
name|TOabort
decl_stmt|,
comment|/* flag set by Typeout() */
name|errormsg
decl_stmt|,
comment|/* last message was an error message 			   so don't erase the error before it 			   has been read */
name|InputPending
decl_stmt|,
comment|/* nonzero if there is input waiting to 			   be processed */
name|Interactive
decl_stmt|,
name|inIOread
decl_stmt|,
comment|/* so we know whether we can do a redisplay. */
name|Asking
decl_stmt|,
comment|/* are we on read a string from the terminal? */
name|InRealAsk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* are we currently executing real_ask()? */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|AskingWidth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* width of question being asked */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Inputp
decl_stmt|,
name|Minibuf
index|[
name|LBSIZE
index|]
decl_stmt|,
name|ShcomBuf
index|[
name|LBSIZE
index|]
decl_stmt|,
modifier|*
name|version
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MESG_SIZE
value|128
end_define

begin_decl_stmt
specifier|extern
name|char
name|mesgbuf
index|[
name|MESG_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"externs.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|W_OK
end_ifndef

begin_define
define|#
directive|define
name|W_OK
value|2
end_define

begin_define
define|#
directive|define
name|X_OK
value|1
end_define

begin_define
define|#
directive|define
name|F_OK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

