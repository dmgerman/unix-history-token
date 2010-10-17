begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* alphavms.h -- BFD definitions for an openVMS host    Copyright 1996, 2000 Free Software Foundation, Inc.    Written by Klaus Kämpf (kkaempf@progis.de)    of proGIS Softwareentwicklung, Aachen, Germany  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unixlib.h>
end_include

begin_include
include|#
directive|include
file|<unixio.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|BFD_HOST_64_BIT
end_ifndef

begin_comment
comment|/* Make the basic types 64-bit quantities on the host.    Also provide the support macros BFD needs.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|BFD_HOST_64_BIT
value|long long
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BFD_HOST_64_BIT
value|long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|BFD_HOST_64_BIT
name|uint64_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|BFD_HOST_64_BIT
name|int64_type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sprintf_vma
parameter_list|(
name|s
parameter_list|,
name|x
parameter_list|)
value|sprintf (s, "%016lx", x)
end_define

begin_comment
comment|/* BFD_HOST_64_BIT */
end_comment

begin_define
define|#
directive|define
name|fprintf_vma
parameter_list|(
name|f
parameter_list|,
name|x
parameter_list|)
value|fprintf (f, "%016lx", x)
end_define

begin_comment
comment|/* BFD_HOST_64_BIT */
end_comment

begin_define
define|#
directive|define
name|BYTES_IN_PRINTF_INT
value|4
end_define

begin_comment
comment|/* These must have type unsigned long because they are used as    arguments in printf functions.  */
end_comment

begin_define
define|#
directive|define
name|uint64_typeLOW
parameter_list|(
name|x
parameter_list|)
value|((unsigned long) (((x)& 0xffffffff)))
end_define

begin_comment
comment|/* BFD_HOST_64_BIT */
end_comment

begin_define
define|#
directive|define
name|uint64_typeHIGH
parameter_list|(
name|x
parameter_list|)
value|((unsigned long) (((x)>> 32)& 0xffffffff))
end_define

begin_comment
comment|/* BFD_HOST_64_BIT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BFD_HOST_64_BIT */
end_comment

begin_include
include|#
directive|include
file|"fopen-vms.h"
end_include

begin_define
define|#
directive|define
name|NO_FCNTL
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|O_ACCMODE
end_ifndef

begin_define
define|#
directive|define
name|O_ACCMODE
value|(O_RDONLY | O_WRONLY | O_RDWR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|getpagesize
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

