begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993 Peter J. Nicklin.  * Copyright (c) 1991, 1993 Version Technology.  * All Rights Reserved.  *  * $License: VT.1.1 $  * Redistribution and use in source and binary forms,  with or without  * modification,  are permitted provided that the following conditions  * are met:  (1) Redistributions of source code must retain the  above  * copyright  notice,  this  list  of  conditions  and  the  following  * disclaimer.  (2) Redistributions in binary form must reproduce  the  * above  copyright notice,  this list of conditions and the following  * disclaimer in the  documentation  and/or other  materials  provided  * with  the  distribution.  (3) All advertising materials  mentioning  * features or  use  of  this  software  must  display  the  following  * acknowledgement:  ``This  product  includes  software  developed by  * Version Technology.''  Neither the name of Version  Technology  nor  * the  name  of  Peter J. Nicklin  may  be used to endorse or promote  * products derived from this software without specific prior  written  * permission.  *  * THIS SOFTWARE IS PROVIDED BY VERSION TECHNOLOGY ``AS IS''  AND  ANY  * EXPRESS OR IMPLIED WARRANTIES,  INCLUDING,  BUT NOT LIMITED TO, THE  * IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  VERSION  TECHNOLOGY  BE  * LIABLE  FOR ANY DIRECT,  INDIRECT,  INCIDENTAL, SPECIAL, EXEMPLARY,  * OR  CONSEQUENTIAL DAMAGES   (INCLUDING,   BUT   NOT   LIMITED   TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY  * OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT LIABILITY,  OR  TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING  IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE,  EVEN  IF  ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * Report problems and direct questions to nicklin@netcom.com  *  * $Header: config.h,v 4.8 93/05/26 00:27:01 nicklin Exp $  *  * System configuration definitions  *  * Author: Peter J. Nicklin  *  * The following definitions control the conditional compilation of the  * mkmf source code for variants of the the UNIX operating system. New  * definitions should be added to the applicable system profiles below.  *  * _HasRename			rename() system call	(BSD)  * _HasStrDcl			str???() declared in #include (ANSI)  * _HasStrchr			strchr()& strrchr() library routines (SYSV)  * _HasNetRoot			// network root 	(Domain/OS only)  * _HasOpenMode			optional mode parameter in open() system call  * _HasSymLinks			symbolic links 		(BSD file systems)  * _HasSystemProfile		custom system configuration profile exists  * _HasIncludeDirent		#include<dirent.h>	(SYSV)  * _HasIncludeSysDir		#include<sys/dir.h>	(BSD)  * _HasIncludeSysNdir		#include<sys/ndir.h>	(ndir library)  * _HasIncludeStrings		#include<strings.h>	(BSD)  * _HasCompileSysType		COMPILESYSTYPE environment var (Domain/OS only)  * _HasEnxioReadlinkReturn	Readlink returns ENXIO (Domain/OS 10.2 bug only)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|CONFIG_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|hpux
argument_list|)
operator|||
name|defined
argument_list|(
name|__hpux
argument_list|)
end_if

begin_define
define|#
directive|define
name|_HasRename
end_define

begin_define
define|#
directive|define
name|_HasStrDcl
end_define

begin_define
define|#
directive|define
name|_HasStrchr
end_define

begin_define
define|#
directive|define
name|_HasOpenMode
end_define

begin_define
define|#
directive|define
name|_HasSymLinks
end_define

begin_define
define|#
directive|define
name|_HasIncludeDirent
end_define

begin_define
define|#
directive|define
name|_HasSystemProfile
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
name|apollo
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYSV
argument_list|)
end_if

begin_define
define|#
directive|define
name|_HasRename
end_define

begin_define
define|#
directive|define
name|_HasStrDcl
end_define

begin_define
define|#
directive|define
name|_HasStrchr
end_define

begin_define
define|#
directive|define
name|_HasNetRoot
end_define

begin_define
define|#
directive|define
name|_HasOpenMode
end_define

begin_define
define|#
directive|define
name|_HasSymLinks
end_define

begin_define
define|#
directive|define
name|_HasIncludeDirent
end_define

begin_define
define|#
directive|define
name|_HasCompileSysType
end_define

begin_define
define|#
directive|define
name|_HasEnxioReadlinkReturn
end_define

begin_define
define|#
directive|define
name|_HasSystemProfile
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_HasRename
end_define

begin_define
define|#
directive|define
name|_HasStrDcl
end_define

begin_define
define|#
directive|define
name|_HasNetRoot
end_define

begin_define
define|#
directive|define
name|_HasOpenMode
end_define

begin_define
define|#
directive|define
name|_HasSymLinks
end_define

begin_define
define|#
directive|define
name|_HasIncludeSysDir
end_define

begin_define
define|#
directive|define
name|_HasIncludeStrings
end_define

begin_define
define|#
directive|define
name|_HasCompileSysType
end_define

begin_define
define|#
directive|define
name|_HasEnxioReadlinkReturn
end_define

begin_define
define|#
directive|define
name|_HasSystemProfile
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
name|defined
argument_list|(
name|sun
argument_list|)
end_if

begin_define
define|#
directive|define
name|_HasRename
end_define

begin_define
define|#
directive|define
name|_HasStrDcl
end_define

begin_define
define|#
directive|define
name|_HasOpenMode
end_define

begin_define
define|#
directive|define
name|_HasSymLinks
end_define

begin_define
define|#
directive|define
name|_HasIncludeSysDir
end_define

begin_define
define|#
directive|define
name|_HasIncludeStrings
end_define

begin_define
define|#
directive|define
name|_HasSystemProfile
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
name|vax
argument_list|)
end_if

begin_define
define|#
directive|define
name|_HasRename
end_define

begin_define
define|#
directive|define
name|_HasStrDcl
end_define

begin_define
define|#
directive|define
name|_HasOpenMode
end_define

begin_define
define|#
directive|define
name|_HasSymLinks
end_define

begin_define
define|#
directive|define
name|_HasIncludeSysDir
end_define

begin_define
define|#
directive|define
name|_HasIncludeStrings
end_define

begin_define
define|#
directive|define
name|_HasSystemProfile
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
name|aix
argument_list|)
operator|||
name|defined
argument_list|(
name|_AIX
argument_list|)
end_if

begin_define
define|#
directive|define
name|_HasRename
end_define

begin_define
define|#
directive|define
name|_HasStrDcl
end_define

begin_define
define|#
directive|define
name|_HasStrchr
end_define

begin_define
define|#
directive|define
name|_HasOpenMode
end_define

begin_define
define|#
directive|define
name|_HasSymLinks
end_define

begin_define
define|#
directive|define
name|_HasIncludeDirent
end_define

begin_define
define|#
directive|define
name|_HasSystemProfile
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
name|_AUX_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|_HasRename
end_define

begin_define
define|#
directive|define
name|_HasStrchr
end_define

begin_define
define|#
directive|define
name|_HasOpenMode
end_define

begin_define
define|#
directive|define
name|_HasSymLinks
end_define

begin_define
define|#
directive|define
name|_HasIncludeDirent
end_define

begin_define
define|#
directive|define
name|_HasSystemProfile
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
name|cray
argument_list|)
operator|||
name|defined
argument_list|(
name|CRAY
argument_list|)
operator|||
name|defined
argument_list|(
name|_CRAY
argument_list|)
end_if

begin_define
define|#
directive|define
name|_HasRename
end_define

begin_define
define|#
directive|define
name|_HasStrDcl
end_define

begin_define
define|#
directive|define
name|_HasStrchr
end_define

begin_define
define|#
directive|define
name|_HasOpenMode
end_define

begin_define
define|#
directive|define
name|_HasIncludeDirent
end_define

begin_define
define|#
directive|define
name|_HasSystemProfile
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|UNICOS5
argument_list|)
end_if

begin_comment
comment|/* exclude with -DUNICOS5 compiler option */
end_comment

begin_define
define|#
directive|define
name|_HasSymLinks
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
name|defined
argument_list|(
name|BSD4X
argument_list|)
end_if

begin_comment
comment|/* generic BSD system */
end_comment

begin_define
define|#
directive|define
name|_HasRename
end_define

begin_define
define|#
directive|define
name|_HasStrDcl
end_define

begin_define
define|#
directive|define
name|_HasOpenMode
end_define

begin_define
define|#
directive|define
name|_HasSymLinks
end_define

begin_define
define|#
directive|define
name|_HasIncludeSysDir
end_define

begin_define
define|#
directive|define
name|_HasIncludeStrings
end_define

begin_define
define|#
directive|define
name|_HasSystemProfile
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
name|M_XENIX
argument_list|)
end_if

begin_define
define|#
directive|define
name|_HasStrchr
end_define

begin_define
define|#
directive|define
name|_IncludeSysNdir
end_define

begin_define
define|#
directive|define
name|_HasSystemProfile
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
name|__STDC__
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_HasStrDcl
argument_list|)
end_if

begin_define
define|#
directive|define
name|_HasStrDcl
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
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|_HasSystemProfile
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_HasRename
argument_list|)
end_if

begin_define
define|#
directive|define
name|_HasRename
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_HasStrDcl
argument_list|)
end_if

begin_define
define|#
directive|define
name|_HasStrDcl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_HasStrchr
argument_list|)
end_if

begin_define
define|#
directive|define
name|_HasStrchr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_HasOpenMode
argument_list|)
end_if

begin_define
define|#
directive|define
name|_HasOpenMode
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_HasIncludeDirent
argument_list|)
end_if

begin_define
define|#
directive|define
name|_HasIncludeDirent
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
name|defined
argument_list|(
name|_HasOpenMode
argument_list|)
end_if

begin_define
define|#
directive|define
name|OPEN
parameter_list|(
name|name
parameter_list|,
name|flags
parameter_list|,
name|mode
parameter_list|)
value|open(name,flags,mode)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OPEN
parameter_list|(
name|name
parameter_list|,
name|flags
parameter_list|,
name|mode
parameter_list|)
value|open(name,flags)
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
name|_HasRename
argument_list|)
end_if

begin_define
define|#
directive|define
name|RENAME
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|)
value|rename(from,to)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RENAME
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|)
define|\
value|(unlink(to), (link(from,to) != -1&& unlink(from) != -1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FILEXIST
parameter_list|(
name|file
parameter_list|)
value|((access(file,0) == 0) ? 1 : 0)
end_define

begin_define
define|#
directive|define
name|FILEWRITE
parameter_list|(
name|file
parameter_list|)
value|((access(file,6) == 0) ? 1 : 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_H */
end_comment

end_unit

