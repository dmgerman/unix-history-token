begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Mark Nudleman  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Mark Nudleman.  *   * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)less.h	5.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Standard include file for "less".  */
end_comment

begin_comment
comment|/*  * Language details.  */
end_comment

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
comment|/*  * The type of signal handler functions.  * Usually int, although it should be void.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|HANDLER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FILENAME
value|128
end_define

begin_comment
comment|/* Max size of a filename */
end_comment

begin_define
define|#
directive|define
name|EOI
value|(0)
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
name|BO_CHAR
value|'\203'
end_define

begin_comment
comment|/* Enter boldface mode */
end_comment

begin_define
define|#
directive|define
name|BE_CHAR
value|'\204'
end_define

begin_comment
comment|/* Exit boldface mode */
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

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_comment
comment|/* Library function declarations */
end_comment

begin_function_decl
name|off_t
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|calloc
parameter_list|()
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|"funcs.h"
end_include

end_unit

