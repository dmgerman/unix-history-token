begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998  *	Nan Yang Computer Services Limited.  All rights reserved.  *  *  This software is distributed under the so-called ``Berkeley  *  License'':  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Nan Yang Computer  *      Services Limited.  * 4. Neither the name of the Company nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *    * This software is provided ``as is'', and any express or implied  * warranties, including, but not limited to, the implied warranties of  * merchantability and fitness for a particular purpose are disclaimed.  * In no event shall the company or contributors be liable for any  * direct, indirect, incidental, special, exemplary, or consequential  * damages (including, but not limited to, procurement of substitute  * goods or services; loss of use, data, or profits; or business  * interruption) however caused and on any theory of liability, whether  * in contract, strict liability, or tort (including negligence or  * otherwise) arising in any way out of the use of this software, even if  * advised of the possibility of such damage.  *  */
end_comment

begin_comment
comment|/* Header files used by all modules */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|REALLYKERNEL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|REALLYKERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEVFS
end_ifdef

begin_error
error|#
directive|error
literal|"DEVFS code not complete yet"
end_error

begin_include
include|#
directive|include
file|<sys/devfsext.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*DEVFS */
end_comment

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/dkstat.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/namei.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/disklabel.h>
end_include

begin_include
include|#
directive|include
file|<ufs/ffs/fs.h>
end_include

begin_include
include|#
directive|include
file|<sys/mount.h>
end_include

begin_include
include|#
directive|include
file|<sys/device.h>
end_include

begin_undef
undef|#
directive|undef
name|KERNEL
end_undef

begin_comment
comment|/* XXX */
end_comment

begin_include
include|#
directive|include
file|<sys/disk.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|REALLYKERNEL
end_ifdef

begin_define
define|#
directive|define
name|KERNEL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|<sys/dkbad.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/* Why the&*(&*(& don't we have this in the kernel somewhere? */
end_comment

begin_define
define|#
directive|define
name|_JBLEN
value|8
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|_jb
index|[
name|_JBLEN
operator|+
literal|1
index|]
decl_stmt|;
block|}
name|jmp_buf
index|[
literal|1
index|]
typedef|;
end_typedef

begin_function_decl
name|int
name|setjmp
parameter_list|(
name|jmp_buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|longjmp
parameter_list|(
name|jmp_buf
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|<machine/stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<machine/ipl.h>
end_include

begin_include
include|#
directive|include
file|<machine/spl.h>
end_include

begin_include
include|#
directive|include
file|"vinumvar.h"
end_include

begin_include
include|#
directive|include
file|"vinumio.h"
end_include

begin_include
include|#
directive|include
file|"vinumkw.h"
end_include

begin_include
include|#
directive|include
file|"vinumext.h"
end_include

begin_undef
undef|#
directive|undef
name|Free
end_undef

begin_comment
comment|/* defined in some funny net stuff */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|REALLYKERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|VINUMDEBUG
end_ifdef

begin_define
define|#
directive|define
name|Malloc
parameter_list|(
name|x
parameter_list|)
value|MMalloc ((x), __FILE__, __LINE__)
end_define

begin_comment
comment|/* show where we came from */
end_comment

begin_define
define|#
directive|define
name|Free
parameter_list|(
name|x
parameter_list|)
value|FFree ((x), __FILE__, __LINE__)
end_define

begin_comment
comment|/* show where we came from */
end_comment

begin_function_decl
name|caddr_t
name|MMalloc
parameter_list|(
name|int
name|size
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FFree
parameter_list|(
name|void
modifier|*
name|mem
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Malloc
parameter_list|(
name|x
parameter_list|)
value|malloc((x), M_DEVBUF, M_WAITOK)
end_define

begin_define
define|#
directive|define
name|Free
parameter_list|(
name|x
parameter_list|)
value|free((x), M_DEVBUF)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Malloc
parameter_list|(
name|x
parameter_list|)
value|malloc ((x))
end_define

begin_comment
comment|/* just the size */
end_comment

begin_define
define|#
directive|define
name|Free
parameter_list|(
name|x
parameter_list|)
value|free ((x))
end_define

begin_comment
comment|/* just the address */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

