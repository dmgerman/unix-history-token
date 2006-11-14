begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*<proc_service.h> replacement for systems that don't have it.    Copyright 2000 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GDB_PROC_SERVICE_H
end_ifndef

begin_define
define|#
directive|define
name|GDB_PROC_SERVICE_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_PROC_SERVICE_H
end_ifdef

begin_include
include|#
directive|include
file|<proc_service.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PROCFS_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/procfs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"gregset.h"
end_include

begin_typedef
typedef|typedef
enum|enum
block|{
name|PS_OK
block|,
comment|/* Success.  */
name|PS_ERR
block|,
comment|/* Generic error.  */
name|PS_BADPID
block|,
comment|/* Bad process handle.  */
name|PS_BADLID
block|,
comment|/* Bad LWP id.  */
name|PS_BADADDR
block|,
comment|/* Bad address.  */
name|PS_NOSYM
block|,
comment|/* Symbol not found.  */
name|PS_NOFREGS
comment|/* FPU register set not available.  */
block|}
name|ps_err_e
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_LWPID_T
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|lwpid_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|long
name|paddr_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_PSADDR_T
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|psaddr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_PRGREGSET_T
end_ifndef

begin_typedef
typedef|typedef
name|gdb_gregset_t
name|prgregset_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_PRFPREGSET_T
end_ifndef

begin_typedef
typedef|typedef
name|gdb_fpregset_t
name|prfpregset_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_PROC_SERVICE_H */
end_comment

begin_comment
comment|/* Fix-up some broken systems.  */
end_comment

begin_comment
comment|/* Unfortunately glibc 2.1.3 was released with a broken prfpregset_t    type.  We let configure check for this lossage, and make    appropriate typedefs here.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PRFPREGSET_T_BROKEN
end_ifdef

begin_typedef
typedef|typedef
name|gdb_fpregset_t
name|gdb_prfpregset_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|prfpregset_t
name|gdb_prfpregset_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Structure that identifies the target process.  */
end_comment

begin_struct
struct|struct
name|ps_prochandle
block|{
comment|/* The process id is all we need.  */
name|pid_t
name|pid
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* gdb_proc_service.h */
end_comment

end_unit

