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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MAC
argument_list|)
end_if

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|USE_PROTOTYPES
argument_list|)
end_if

begin_define
define|#
directive|define
name|proto
parameter_list|(
name|x
parameter_list|)
value|x
end_define

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNDEF: macro to allow is to use ansi style undefinition of macros when  * declaring functions. i.e.   * 	extern int (vfork) (void)  * is declared as  * 	extern int UNDEF(vfork) proto((void))  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|UNDEF
parameter_list|(
name|proc
parameter_list|)
value|(proc)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UNDEF
parameter_list|(
name|proc
parameter_list|)
value|proc
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

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
comment|/* const: readonly type qualifier */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
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

begin_comment
comment|/* !__STDC__ */
end_comment

begin_comment
comment|/* UnivPtr: universal pointer type */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
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
comment|/* !__STDC__ */
end_comment

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
comment|/* !__STDC__ */
end_comment

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

begin_include
include|#
directive|include
file|"style.h"
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
name|YES_NODIGIT
value|2
end_define

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
name|InMacDefine
decl_stmt|,
comment|/* are we defining a macro right now? */
name|LastKeyStruck
decl_stmt|,
name|TOabort
decl_stmt|,
comment|/* flag set by Typeout() */
name|errormsg
decl_stmt|,
comment|/* last message was an error message 			   so don't erase the error before it 			   has been read */
name|RecDepth
decl_stmt|,
comment|/* recursion depth */
name|InputPending
decl_stmt|,
comment|/* nonzero if there is input waiting to 			   be processed */
name|InJoverc
decl_stmt|,
name|Interactive
decl_stmt|,
name|Crashing
decl_stmt|,
comment|/* we are in the middle of crashing */
name|Asking
decl_stmt|,
comment|/* are we on read a string from the terminal? */
name|InRealAsk
decl_stmt|,
comment|/* are we currently executing real_ask()? */
name|inIOread
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* so we know whether we can do a redisplay. */
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

begin_define
define|#
directive|define
name|CATCH
define|\
value|{\ 	jmp_buf	sav_jmp; \ \ 	push_env(sav_jmp); \ 	if (setjmp(mainjmp) == 0) {
end_define

begin_define
define|#
directive|define
name|ONERROR
define|\
value|} else { \  #define ENDCATCH \ 	} \ 	pop_env(sav_jmp); \ }
end_define

begin_include
include|#
directive|include
file|"externs.h"
end_include

end_unit

