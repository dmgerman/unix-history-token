begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************** Copyright (C) 1997-1999 Lucent Technologies All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that the copyright notice and this permission notice and warranty disclaimer appear in supporting documentation, and that the name of Lucent or any of its entities not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  LUCENT DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL LUCENT OR ANY OF ITS ENTITIES BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. ****************************************************************/
end_comment

begin_comment
comment|/* stdio1.h -- for using Printf, Fprintf, Sprintf while  * retaining the system-supplied printf, fprintf, sprintf.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STDIO1_H_included
end_ifndef

begin_define
define|#
directive|define
name|STDIO1_H_included
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|STDIO_H_included
end_ifndef

begin_comment
comment|/* allow suppressing stdio.h */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* in case it's already included, */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* e.g., by cplex.h */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KR_headers
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|_SIZE_T
end_ifndef

begin_define
define|#
directive|define
name|_SIZE_T
end_define

begin_typedef
typedef|typedef
name|unsigned
name|int
name|size_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ANSI
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_include
include|#
directive|include
file|"varargs.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|Char
end_ifndef

begin_define
define|#
directive|define
name|Char
value|char
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
name|ANSI
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_include
include|#
directive|include
file|"stdarg.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|Char
end_ifndef

begin_define
define|#
directive|define
name|Char
value|void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NO_STDIO1
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
specifier|extern
name|int
name|Fprintf
name|ANSI
argument_list|(
operator|(
name|FILE
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|Printf
name|ANSI
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|Sprintf
name|ANSI
argument_list|(
operator|(
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|Snprintf
name|ANSI
argument_list|(
operator|(
name|char
operator|*
operator|,
name|size_t
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|void
name|Perror
name|ANSI
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|Vfprintf
name|ANSI
argument_list|(
operator|(
name|FILE
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|va_list
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|Vsprintf
name|ANSI
argument_list|(
operator|(
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|va_list
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|Vsnprintf
name|ANSI
argument_list|(
operator|(
name|char
operator|*
operator|,
name|size_t
operator|,
specifier|const
name|char
operator|*
operator|,
name|va_list
operator|)
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|PF_BUF
specifier|extern
name|FILE
modifier|*
name|stderr_ASL
decl_stmt|;
extern|extern void (*pfbuf_print_ASL
block|)
name|ANSI
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
end_extern

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|pfbuf_ASL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|fflush_ASL
name|ANSI
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|fflush
end_ifdef

begin_define
define|#
directive|define
name|old_fflush_ASL
value|fflush
end_define

begin_undef
undef|#
directive|undef
name|fflush
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|fflush
value|fflush_ASL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|printf
end_undef

begin_undef
undef|#
directive|undef
name|fprintf
end_undef

begin_undef
undef|#
directive|undef
name|sprintf
end_undef

begin_undef
undef|#
directive|undef
name|perror
end_undef

begin_undef
undef|#
directive|undef
name|vfprintf
end_undef

begin_undef
undef|#
directive|undef
name|vsprintf
end_undef

begin_define
define|#
directive|define
name|printf
value|Printf
end_define

begin_define
define|#
directive|define
name|fprintf
value|Fprintf
end_define

begin_undef
undef|#
directive|undef
name|snprintf
end_undef

begin_comment
comment|/* for MacOSX */
end_comment

begin_undef
undef|#
directive|undef
name|vsnprintf
end_undef

begin_comment
comment|/* for MacOSX */
end_comment

begin_define
define|#
directive|define
name|snprintf
value|Snprintf
end_define

begin_define
define|#
directive|define
name|sprintf
value|Sprintf
end_define

begin_define
define|#
directive|define
name|perror
value|Perror
end_define

begin_define
define|#
directive|define
name|vfprintf
value|Vfprintf
end_define

begin_define
define|#
directive|define
name|vsnprintf
value|Vsnprintf
end_define

begin_define
define|#
directive|define
name|vsprintf
value|Vsprintf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NO_STDIO1 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STDIO1_H_included */
end_comment

end_unit

