begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|BISON_SYSTEM_H
end_ifndef

begin_define
define|#
directive|define
name|BISON_SYSTEM_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MSDOS
end_ifdef

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<process.h>
end_include

begin_define
define|#
directive|define
name|getpid
value|_getpid
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
name|HAVE_STDLIB_H
argument_list|)
operator|||
name|defined
argument_list|(
name|MSDOS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_UNISTD_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|VMS
argument_list|)
operator|||
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_STRING_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
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
name|STDC_HEADERS
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_STRING_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/* An ANSI string.h and pre-ANSI memory.h might conflict.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|STDC_HEADERS
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_MEMORY_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not STDC_HEADERS and HAVE_MEMORY_H */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|bcopy
end_ifndef

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|num
parameter_list|)
value|memcpy((dst), (src), (num))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not STDC_HEADERS and not HAVE_STRING_H */
end_comment

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_comment
comment|/* memory.h and strings.h conflict on some systems.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not STDC_HEADERS and not HAVE_STRING_H */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|STDC_HEADERS
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_CTYPE_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LOCALE_H
end_ifdef

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SETLOCALE
end_ifndef

begin_define
define|#
directive|define
name|setlocale
parameter_list|(
name|Category
parameter_list|,
name|Locale
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ENABLE_NLS
end_ifdef

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_define
define|#
directive|define
name|_
parameter_list|(
name|Text
parameter_list|)
value|gettext (Text)
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|bindtextdomain
end_undef

begin_define
define|#
directive|define
name|bindtextdomain
parameter_list|(
name|Domain
parameter_list|,
name|Directory
parameter_list|)
end_define

begin_undef
undef|#
directive|undef
name|textdomain
end_undef

begin_define
define|#
directive|define
name|textdomain
parameter_list|(
name|Domain
parameter_list|)
end_define

begin_define
define|#
directive|define
name|_
parameter_list|(
name|Text
parameter_list|)
value|Text
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|Text
parameter_list|)
value|Text
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCALEDIR
end_ifndef

begin_define
define|#
directive|define
name|LOCALEDIR
value|"/usr/local/share/locale"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BISON_SYSTEM_H */
end_comment

end_unit

