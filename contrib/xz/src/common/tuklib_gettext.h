begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       tuklib_gettext.h
end_comment

begin_comment
comment|/// \brief      Wrapper for gettext and friends
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Author:     Lasse Collin
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file has been put into the public domain.
end_comment

begin_comment
comment|//  You can do whatever you want with this file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TUKLIB_GETTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|TUKLIB_GETTEXT_H
end_define

begin_include
include|#
directive|include
file|"tuklib_common.h"
end_include

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|TUKLIB_GETTEXT
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|ENABLE_NLS
end_ifdef

begin_define
define|#
directive|define
name|TUKLIB_GETTEXT
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TUKLIB_GETTEXT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TUKLIB_GETTEXT
end_if

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_define
define|#
directive|define
name|tuklib_gettext_init
parameter_list|(
name|package
parameter_list|,
name|localedir
parameter_list|)
define|\
value|do { \ 			setlocale(LC_ALL, ""); \ 			bindtextdomain(package, localedir); \ 			textdomain(package); \ 		} while (0)
end_define

begin_define
define|#
directive|define
name|_
parameter_list|(
name|msgid
parameter_list|)
value|gettext(msgid)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|tuklib_gettext_init
parameter_list|(
name|package
parameter_list|,
name|localedir
parameter_list|)
define|\
value|setlocale(LC_ALL, "")
end_define

begin_define
define|#
directive|define
name|_
parameter_list|(
name|msgid
parameter_list|)
value|(msgid)
end_define

begin_define
define|#
directive|define
name|ngettext
parameter_list|(
name|msgid1
parameter_list|,
name|msgid2
parameter_list|,
name|n
parameter_list|)
value|((n) == 1 ? (msgid1) : (msgid2))
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
name|msgid
parameter_list|)
value|msgid
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

