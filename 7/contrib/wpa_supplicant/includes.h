begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * wpa_supplicant/hostapd - Default include files  * Copyright (c) 2005-2006, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  *  * This header file is included into all C files so that commonly used header  * files can be selected with OS specific #ifdefs in one place instead of  * having to have OS/C library specific selection in many files.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INCLUDES_H
end_ifndef

begin_define
define|#
directive|define
name|INCLUDES_H
end_define

begin_comment
comment|/* Include possible build time configuration before including anything else */
end_comment

begin_include
include|#
directive|include
file|"build_config.h"
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_WIN32_WCE
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_TI_COMPILER
end_ifndef

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_TI_COMPILER */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _WIN32_WCE */
end_comment

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_TI_COMPILER
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_MSC_VER
end_ifndef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MSC_VER */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_TI_COMPILER */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_NATIVE_WINDOWS
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_TI_COMPILER
end_ifndef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__vxworks
end_ifndef

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __vxworks */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_TI_COMPILER */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_NATIVE_WINDOWS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INCLUDES_H */
end_comment

end_unit

