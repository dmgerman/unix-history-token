begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************** Copyright 1990, 1991, 1994 by AT&T, Lucent Technologies and Bellcore.  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that the copyright notice and this permission notice and warranty disclaimer appear in supporting documentation, and that the names of AT&T, Bell Laboratories, Lucent or Bellcore or any of their entities not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  AT&T, Lucent and Bellcore disclaim all warranties with regard to this software, including all implied warranties of merchantability and fitness.  In no event shall AT&T, Lucent or Bellcore be liable for any special, indirect or consequential damages or any damages whatsoever resulting from loss of use, data or profits, whether in an action of contract, negligence or other tortious action, arising out of or in connection with the use or performance of this software. ****************************************************************/
end_comment

begin_comment
comment|/* This file is included at the start of defs.h; this file  * is an initial attempt to gather in one place some declarations  * that may need to be tweaked on some systems.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_undef
undef|#
directive|undef
name|KR_headers
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|KR_headers
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|ANSI_Libraries
end_ifndef

begin_define
define|#
directive|define
name|ANSI_Libraries
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ANSI_Prototypes
end_ifndef

begin_define
define|#
directive|define
name|ANSI_Prototypes
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__BORLANDC__
end_ifdef

begin_define
define|#
directive|define
name|MSDOS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__ZTC__
end_ifdef

begin_comment
comment|/* Zortech */
end_comment

begin_define
define|#
directive|define
name|MSDOS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MSDOS
end_ifdef

begin_define
define|#
directive|define
name|ANSI_Libraries
end_define

begin_define
define|#
directive|define
name|ANSI_Prototypes
end_define

begin_define
define|#
directive|define
name|LONG_CAST
value|(long)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LONG_CAST
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ANSI_Libraries
end_ifdef

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|calloc
argument_list|()
decl_stmt|,
modifier|*
name|malloc
argument_list|()
decl_stmt|,
modifier|*
name|memcpy
argument_list|()
decl_stmt|,
modifier|*
name|memset
argument_list|()
decl_stmt|,
modifier|*
name|realloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
name|size_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|atol
end_ifndef

begin_function_decl
name|long
name|atol
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ANSI_Prototypes
end_ifdef

begin_function_decl
specifier|extern
name|double
name|atof
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|double
name|strtod
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|double
name|atof
argument_list|()
decl_stmt|,
name|strtod
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* On systems like VMS where fopen might otherwise create  * multiple versions of intermediate files, you may wish to  * #define scrub(x) unlink(x)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|scrub
end_ifndef

begin_define
define|#
directive|define
name|scrub
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/* do nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* On systems that severely limit the total size of statically  * allocated arrays, you may need to change the following to  *	extern char **chr_fmt, *escapes, **str_fmt;  * and to modify sysdep.c appropriately  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|chr_fmt
index|[]
decl_stmt|,
name|escapes
index|[]
decl_stmt|,
modifier|*
name|str_fmt
index|[]
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"ctype.h"
end_include

begin_define
define|#
directive|define
name|Bits_per_Byte
value|8
end_define

begin_define
define|#
directive|define
name|Table_size
value|(1<< Bits_per_Byte)
end_define

end_unit

