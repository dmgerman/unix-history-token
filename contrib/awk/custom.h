begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * custom.h  *  * This file is for use on systems where Autoconf isn't quite able to  * get things right. It is included after config.h in awk.h, to override  * definitions from Autoconf that are erroneous. See the manual for more  * information.  *  * If you make additions to this file for your system, please send me  * the information, to arnold@gnu.ai.mit.edu.  */
end_comment

begin_comment
comment|/*   * Copyright (C) 1995-1997 the Free Software Foundation, Inc.  *   * This file is part of GAWK, the GNU implementation of the  * AWK Programming Language.  *   * GAWK is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *   * GAWK is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *   * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA  */
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
comment|/* For sequent, based on email with Aron Griffis<agriffis@calypso.coat.com> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SEQUENT_
end_ifdef

begin_undef
undef|#
directive|undef
name|HAVE_MMAP
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

