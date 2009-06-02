begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *                     The LLVM Compiler Infrastructure  *  * This file is distributed under the University of Illinois Open Source  * License. See LICENSE.TXT for details.  *  ******************************************************************************  *  * Description:  *  This header file includes the infamous alloc.h header file if the  *  autoconf system has found it.  It hides all of the autoconf details  *  from the rest of the application source code.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CONFIG_ALLOC_H
end_ifndef

begin_define
define|#
directive|define
name|_CONFIG_ALLOC_H
end_define

begin_include
include|#
directive|include
file|"llvm/Config/config.h"
end_include

begin_comment
comment|/*  * This is a modified version of that suggested by the Autoconf manual.  *  1) The #pragma is indented so that pre-ANSI C compilers ignore it.  *  2) If alloca.h cannot be found, then try stdlib.h.  Some platforms  *     (notably FreeBSD) defined alloca() there.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_define
define|#
directive|define
name|alloca
value|_alloca
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_ALLOCA_H
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_MALLOC_H
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_elif

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|alloca
end_pragma

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|alloca
end_ifndef

begin_function_decl
name|char
modifier|*
name|alloca
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDLIB_H
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"The function alloca() is required but not found!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

