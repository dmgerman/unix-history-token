begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD backend for local host's a.out binaries    Copyright (C) 1990, 91, 92, 93, 94 Free Software Foundation, Inc.    Written by Cygnus Support.  Probably John Gilmore's fault.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|"libbfd.h"
end_include

begin_define
define|#
directive|define
name|ARCH_SIZE
value|32
end_define

begin_comment
comment|/* When porting to a new system, you must supply:  	HOST_PAGE_SIZE		(optional) 	HOST_SEGMENT_SIZE	(optional -- defaults to page size) 	HOST_MACHINE_ARCH	(optional) 	HOST_MACHINE_MACHINE	(optional) 	HOST_TEXT_START_ADDR	(optional) 	HOST_STACK_END_ADDR	(not used, except by trad-core ???) 	HOST_BIG_ENDIAN_P	(required -- define if big-endian)     in the ./hosts/h-systemname.h file.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TRAD_HEADER
end_ifdef

begin_include
include|#
directive|include
include|TRAD_HEADER
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HOST_PAGE_SIZE
end_ifdef

begin_define
define|#
directive|define
name|TARGET_PAGE_SIZE
value|HOST_PAGE_SIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HOST_SEGMENT_SIZE
end_ifdef

begin_define
define|#
directive|define
name|SEGMENT_SIZE
value|HOST_SEGMENT_SIZE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SEGMENT_SIZE
value|TARGET_PAGE_SIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HOST_TEXT_START_ADDR
end_ifdef

begin_define
define|#
directive|define
name|TEXT_START_ADDR
value|HOST_TEXT_START_ADDR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HOST_STACK_END_ADDR
end_ifdef

begin_define
define|#
directive|define
name|STACK_END_ADDR
value|HOST_STACK_END_ADDR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HOST_BIG_ENDIAN_P
end_ifdef

begin_define
define|#
directive|define
name|TARGET_IS_BIG_ENDIAN_P
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|TARGET_IS_BIG_ENDIAN_P
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"libaout.h"
end_include

begin_comment
comment|/* BFD a.out internal data structures */
end_comment

begin_include
include|#
directive|include
file|"aout/aout64.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HOST_MACHINE_ARCH
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HOST_MACHINE_MACHINE
end_ifdef

begin_define
define|#
directive|define
name|SET_ARCH_MACH
parameter_list|(
name|abfd
parameter_list|,
name|execp
parameter_list|)
define|\
value|bfd_default_set_arch_mach(abfd, HOST_MACHINE_ARCH, HOST_MACHINE_MACHINE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SET_ARCH_MACH
parameter_list|(
name|abfd
parameter_list|,
name|execp
parameter_list|)
define|\
value|bfd_default_set_arch_mach(abfd, HOST_MACHINE_ARCH, 0)
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
comment|/* HOST_MACHINE_ARCH */
end_comment

begin_define
define|#
directive|define
name|MY
parameter_list|(
name|OP
parameter_list|)
value|CAT(host_aout_,OP)
end_define

begin_define
define|#
directive|define
name|TARGETNAME
value|"a.out"
end_define

begin_include
include|#
directive|include
file|"aout-target.h"
end_include

end_unit

