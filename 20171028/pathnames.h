begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: pathnames.h,v 1.17 2009/04/11 09:41:18 apb Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)pathnames.h	5.2 (Berkeley) 6/1/90  *	$Id: pathnames.h,v 1.13 2009/08/26 23:43:42 sjg Exp $  */
end_comment

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAKE_NATIVE
end_ifndef

begin_if
if|#
directive|if
name|HAVE_NBTOOL_CONFIG_H
end_if

begin_include
include|#
directive|include
file|"nbtool_config.h"
end_include

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
name|HAVE_PATHS_H
end_ifdef

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_PATH_OBJDIR
value|"obj"
end_define

begin_define
define|#
directive|define
name|_PATH_OBJDIRPREFIX
value|"/usr/obj"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DEFSHELLDIR
end_ifndef

begin_define
define|#
directive|define
name|_PATH_DEFSHELLDIR
value|"/bin"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_PATH_DEFSYSMK
value|"sys.mk"
end_define

begin_define
define|#
directive|define
name|_path_defsyspath
value|"/usr/share/mk:/usr/local/share/mk:/opt/share/mk"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PATH_DEFSYSPATH
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_PATH_PREFIX_SYSPATH
end_ifdef

begin_define
define|#
directive|define
name|_PATH_DEFSYSPATH
value|_PATH_PREFIX_SYSPATH ":" _path_defsyspath
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_PATH_DEFSYSPATH
value|_path_defsyspath
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
name|_PATH_TMP
end_ifndef

begin_define
define|#
directive|define
name|_PATH_TMP
value|"/tmp/"
end_define

begin_comment
comment|/* with trailing slash */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

