begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Standard include file for "less".  */
end_comment

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
name|END_POSITION
value|((POSITION)(-2))
end_define

begin_define
define|#
directive|define
name|NULL_POSITION
value|((POSITION)(-1))
end_define

begin_define
define|#
directive|define
name|EOF
value|(0)
end_define

begin_define
define|#
directive|define
name|NULL
value|(0)
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
name|BS_UNDERLINE
value|0
end_define

begin_comment
comment|/* Underlining converted to underline mode */
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
comment|/* Flag to eq_message() telling what to put in the message */
end_comment

begin_define
define|#
directive|define
name|MNAME
value|001
end_define

begin_comment
comment|/* File name */
end_comment

begin_define
define|#
directive|define
name|MOF
value|002
end_define

begin_comment
comment|/* "file x of y" */
end_comment

begin_define
define|#
directive|define
name|MBYTE
value|004
end_define

begin_comment
comment|/* "byte x/y" */
end_comment

begin_define
define|#
directive|define
name|MPCT
value|010
end_define

begin_comment
comment|/* Percentage into the file */
end_comment

begin_comment
comment|/* Special chars used to tell put_line() to do something special */
end_comment

begin_define
define|#
directive|define
name|UL_CHAR
value|'\201'
end_define

begin_comment
comment|/* Enter underline mode */
end_comment

begin_define
define|#
directive|define
name|UE_CHAR
value|'\202'
end_define

begin_comment
comment|/* Exit underline mode */
end_comment

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
name|SIGNAL
parameter_list|(
name|sig
parameter_list|,
name|func
parameter_list|)
value|signal(sig,func)
end_define

begin_function_decl
name|off_t
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|"funcs.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NRTC
end_ifdef

begin_define
define|#
directive|define
name|carat_char
parameter_list|(
name|c
parameter_list|)
value|(c ^ 0100)
end_define

begin_endif
endif|#
directive|endif
endif|NRTC
end_endif

end_unit

