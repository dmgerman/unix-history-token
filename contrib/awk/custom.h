begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * custom.h  *  * This file is for use on systems where Autoconf isn't quite able to  * get things right. It is included after config.h in awk.h, to override  * definitions from Autoconf that are erroneous. See the manual for more  * information.  *  * If you make additions to this file for your system, please send me  * the information, to arnold@gnu.org.  */
end_comment

begin_comment
comment|/*   * Copyright (C) 1995-2001 the Free Software Foundation, Inc.  *   * This file is part of GAWK, the GNU implementation of the  * AWK Programming Language.  *   * GAWK is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *   * GAWK is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *   * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA  */
end_comment

begin_comment
comment|/* for MIPS RiscOS, from Nelson H. F. Beebe, beebe@math.utah.edu */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__host_mips
argument_list|)
operator|&&
name|defined
argument_list|(
name|SYSTYPE_BSD43
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|HAVE_STRTOD
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_STRERROR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* for VMS POSIX, from Pat Rankin, rankin@eql.caltech.edu */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMS_POSIX
end_ifdef

begin_undef
undef|#
directive|undef
name|VMS
end_undef

begin_include
include|#
directive|include
file|"vms/redirect.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For QNX, based on submission from Michael Hunter, mphunter@qnx.com */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__QNX__
end_ifdef

begin_define
define|#
directive|define
name|GETPGRP_VOID
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For Amigas, from Fred Fish, fnf@ninemoons.com */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__amigaos__
end_ifdef

begin_define
define|#
directive|define
name|fork
value|vfork
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For BeOS, from mc@whoever.com */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__dest_os
argument_list|)
operator|&&
name|__dest_os
operator|==
name|__be_os
end_if

begin_define
define|#
directive|define
name|BROKEN_STRNCASECMP
end_define

begin_define
define|#
directive|define
name|ELIDE_CODE
end_define

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For Tandems, based on code from scldad@sdc.com.au */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TANDEM
end_ifdef

begin_define
define|#
directive|define
name|tempnam
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|tmpnam(NULL)
end_define

begin_define
define|#
directive|define
name|variable
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|variabl(a,b,c)
end_define

begin_define
define|#
directive|define
name|srandom
value|srand
end_define

begin_define
define|#
directive|define
name|random
value|rand
end_define

begin_include
include|#
directive|include
file|<cextdecs(PROCESS_GETINFO_)>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For 16-bit DOS */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MSC_VER
argument_list|)
operator|&&
name|defined
argument_list|(
name|MSDOS
argument_list|)
end_if

begin_define
define|#
directive|define
name|NO_PROFILING
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For MacOS X, which is almost BSD Unix */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE__
end_ifdef

begin_define
define|#
directive|define
name|HAVE_MKTIME
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For ULTRIX 4.3 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ultrix
end_ifdef

begin_define
define|#
directive|define
name|HAVE_MKTIME
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

