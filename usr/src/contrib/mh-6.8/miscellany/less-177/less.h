begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Standard include file for "less".  */
end_comment

begin_comment
comment|/*  * Include the file of compile-time options.  */
end_comment

begin_include
include|#
directive|include
file|"defines.h"
end_include

begin_comment
comment|/*  * Language details.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|VOID
end_if

begin_define
define|#
directive|define
name|void
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|public
end_define

begin_comment
comment|/* PUBLIC FUNCTION */
end_comment

begin_comment
comment|/*  * Special types and constants.  */
end_comment

begin_typedef
typedef|typedef
name|long
name|POSITION
typedef|;
end_typedef

begin_comment
comment|/*  * {{ Warning: if POSITION is changed to other than "long",  *    you may have to change some of the printfs which use "%ld"  *    to print a variable of type POSITION. }}  */
end_comment

begin_define
define|#
directive|define
name|NULL_POSITION
value|((POSITION)(-1))
end_define

begin_comment
comment|/*  * The type of an interrupt handler.  */
end_comment

begin_define
define|#
directive|define
name|HANDLER
value|void
end_define

begin_comment
comment|/*  * An IFILE represents an input file.  */
end_comment

begin_define
define|#
directive|define
name|IFILE
value|VOID_POINTER
end_define

begin_define
define|#
directive|define
name|NULL_IFILE
value|((IFILE)NULL)
end_define

begin_comment
comment|/*  * The structure used to represent a "screen position".  * This consists of a file position, and a screen line number.  * The meaning is that the line starting at the given file  * position is displayed on the ln-th line of the screen.  * (Screen lines before ln are empty.)  */
end_comment

begin_struct
struct|struct
name|scrpos
block|{
name|POSITION
name|pos
decl_stmt|;
name|int
name|ln
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
union|union
name|parg
block|{
name|char
modifier|*
name|p_string
decl_stmt|;
name|int
name|p_int
decl_stmt|;
block|}
name|PARG
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULL_PARG
value|((PARG *)NULL)
end_define

begin_define
define|#
directive|define
name|EOI
value|(-1)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|READ_INTR
value|(-2)
end_define

begin_comment
comment|/* How quiet should we be? */
end_comment

begin_define
define|#
directive|define
name|NOT_QUIET
value|0
end_define

begin_comment
comment|/* Ring bell at eof and for errors */
end_comment

begin_define
define|#
directive|define
name|LITTLE_QUIET
value|1
end_define

begin_comment
comment|/* Ring bell only for errors */
end_comment

begin_define
define|#
directive|define
name|VERY_QUIET
value|2
end_define

begin_comment
comment|/* Never ring bell */
end_comment

begin_comment
comment|/* How should we prompt? */
end_comment

begin_define
define|#
directive|define
name|PR_SHORT
value|0
end_define

begin_comment
comment|/* Prompt with colon */
end_comment

begin_define
define|#
directive|define
name|PR_MEDIUM
value|1
end_define

begin_comment
comment|/* Prompt with message */
end_comment

begin_define
define|#
directive|define
name|PR_LONG
value|2
end_define

begin_comment
comment|/* Prompt with longer message */
end_comment

begin_comment
comment|/* How should we handle backspaces? */
end_comment

begin_define
define|#
directive|define
name|BS_SPECIAL
value|0
end_define

begin_comment
comment|/* Do special things for underlining and bold */
end_comment

begin_define
define|#
directive|define
name|BS_NORMAL
value|1
end_define

begin_comment
comment|/* \b treated as normal char; actually output */
end_comment

begin_define
define|#
directive|define
name|BS_CONTROL
value|2
end_define

begin_comment
comment|/* \b treated as control char; prints as ^H */
end_comment

begin_comment
comment|/* How should we search? */
end_comment

begin_define
define|#
directive|define
name|SRCH_FORW
value|0
end_define

begin_comment
comment|/* Search forward from current position */
end_comment

begin_define
define|#
directive|define
name|SRCH_BACK
value|1
end_define

begin_comment
comment|/* Search backward from current position */
end_comment

begin_define
define|#
directive|define
name|SRCH_NOMATCH
value|0100
end_define

begin_comment
comment|/* Search for non-matching lines */
end_comment

begin_define
define|#
directive|define
name|SRCH_PAST_EOF
value|0200
end_define

begin_comment
comment|/* Search past end-of-file, into next file */
end_comment

begin_define
define|#
directive|define
name|SRCH_FIRST_FILE
value|0400
end_define

begin_comment
comment|/* Search starting at the first file */
end_comment

begin_define
define|#
directive|define
name|SRCH_DIR
parameter_list|(
name|t
parameter_list|)
value|((t)& 01)
end_define

begin_define
define|#
directive|define
name|SRCH_REVERSE
parameter_list|(
name|t
parameter_list|)
value|((t) ^ 01)
end_define

begin_comment
comment|/* Special chars used to tell put_line() to do something special */
end_comment

begin_define
define|#
directive|define
name|NORMAL
value|(0)
end_define

begin_define
define|#
directive|define
name|UNDERLINE
value|(1)
end_define

begin_define
define|#
directive|define
name|BOLD
value|(2)
end_define

begin_define
define|#
directive|define
name|BLINK
value|(3)
end_define

begin_define
define|#
directive|define
name|INVIS
value|(4)
end_define

begin_define
define|#
directive|define
name|CONTROL
parameter_list|(
name|c
parameter_list|)
value|((c)&037)
end_define

begin_define
define|#
directive|define
name|ESC
value|CONTROL('[')
end_define

begin_define
define|#
directive|define
name|SIGNAL
parameter_list|(
name|sig
parameter_list|,
name|func
parameter_list|)
value|signal(sig,func)
end_define

begin_comment
comment|/* Library function declarations */
end_comment

begin_function_decl
name|offset_t
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|BAD_LSEEK
value|((offset_t)-1)
end_define

begin_function_decl
name|VOID_POINTER
name|calloc
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ch_zero
parameter_list|()
value|((POSITION)0)
end_define

begin_include
include|#
directive|include
file|"funcs.h"
end_include

end_unit

