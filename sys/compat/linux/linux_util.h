begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994 Christos Zoulas  * Copyright (c) 1995 Frank van der Linden  * Copyright (c) 1995 Scott Bartram  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * from: svr4_util.h,v 1.5 1994/11/18 02:54:31 christos Exp  * from: linux_util.h,v 1.2 1995/03/05 23:23:50 fvdl Exp  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_UTIL_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_UTIL_H_
end_define

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_include
include|#
directive|include
file|<sys/exec.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysent.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|linux_emul_path
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|linux_emul_convpath
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|enum
name|uio_seg
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LCONVPATH_AT
parameter_list|(
name|td
parameter_list|,
name|upath
parameter_list|,
name|pathp
parameter_list|,
name|i
parameter_list|,
name|dfd
parameter_list|)
define|\
value|do {								\ 		int _error;						\ 									\ 		_error = linux_emul_convpath(td, upath, UIO_USERSPACE,	\ 		    pathp, i, dfd);					\ 		if (*(pathp) == NULL)					\ 			return (_error);				\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|LCONVPATH
parameter_list|(
name|td
parameter_list|,
name|upath
parameter_list|,
name|pathp
parameter_list|,
name|i
parameter_list|)
define|\
value|LCONVPATH_AT(td, upath, pathp, i, AT_FDCWD)
end_define

begin_define
define|#
directive|define
name|LCONVPATHEXIST
parameter_list|(
name|td
parameter_list|,
name|upath
parameter_list|,
name|pathp
parameter_list|)
value|LCONVPATH(td, upath, pathp, 0)
end_define

begin_define
define|#
directive|define
name|LCONVPATHEXIST_AT
parameter_list|(
name|td
parameter_list|,
name|upath
parameter_list|,
name|pathp
parameter_list|,
name|dfd
parameter_list|)
value|LCONVPATH_AT(td, upath, pathp, 0, dfd)
end_define

begin_define
define|#
directive|define
name|LCONVPATHCREAT
parameter_list|(
name|td
parameter_list|,
name|upath
parameter_list|,
name|pathp
parameter_list|)
value|LCONVPATH(td, upath, pathp, 1)
end_define

begin_define
define|#
directive|define
name|LCONVPATHCREAT_AT
parameter_list|(
name|td
parameter_list|,
name|upath
parameter_list|,
name|pathp
parameter_list|,
name|dfd
parameter_list|)
value|LCONVPATH_AT(td, upath, pathp, 1, dfd)
end_define

begin_define
define|#
directive|define
name|LFREEPATH
parameter_list|(
name|path
parameter_list|)
value|free(path, M_TEMP)
end_define

begin_define
define|#
directive|define
name|DUMMY
parameter_list|(
name|s
parameter_list|)
define|\
value|LIN_SDT_PROBE_DEFINE0(dummy, s, entry);					\ LIN_SDT_PROBE_DEFINE0(dummy, s, not_implemented);			\ LIN_SDT_PROBE_DEFINE1(dummy, s, return, "int");				\ int									\ linux_ ## s(struct thread *td, struct linux_ ## s ## _args *args)	\ {									\ 	static pid_t pid;						\ 									\ 	LIN_SDT_PROBE0(dummy, s, entry);				\ 									\ 	if (pid != td->td_proc->p_pid) {				\ 		linux_msg(td, "syscall %s not implemented", #s);	\ 		LIN_SDT_PROBE0(dummy, s, not_implemented);		\ 		pid = td->td_proc->p_pid;				\ 	};								\ 									\ 	LIN_SDT_PROBE1(dummy, s, return, ENOSYS);			\ 	return (ENOSYS);						\ }									\ struct __hack
end_define

begin_function_decl
name|void
name|linux_msg
parameter_list|(
specifier|const
name|struct
name|thread
modifier|*
name|td
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_struct
struct|struct
name|linux_device_handler
block|{
name|char
modifier|*
name|bsd_driver_name
decl_stmt|;
name|char
modifier|*
name|linux_driver_name
decl_stmt|;
name|char
modifier|*
name|bsd_device_name
decl_stmt|;
name|char
modifier|*
name|linux_device_name
decl_stmt|;
name|int
name|linux_major
decl_stmt|;
name|int
name|linux_minor
decl_stmt|;
name|int
name|linux_char_device
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|linux_device_register_handler
parameter_list|(
name|struct
name|linux_device_handler
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_device_unregister_handler
parameter_list|(
name|struct
name|linux_device_handler
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|linux_driver_get_name_dev
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_driver_get_major_minor
parameter_list|(
specifier|const
name|char
modifier|*
name|node
parameter_list|,
name|int
modifier|*
name|major
parameter_list|,
name|int
modifier|*
name|minor
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|linux_get_char_devices
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|linux_free_get_char_devices
parameter_list|(
name|char
modifier|*
name|string
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|KTR
argument_list|)
end_if

begin_define
define|#
directive|define
name|KTR_LINUX
value|KTR_SUBSYS
end_define

begin_define
define|#
directive|define
name|LINUX_CTRFMT
parameter_list|(
name|nm
parameter_list|,
name|fmt
parameter_list|)
value|#nm"("fmt")"
end_define

begin_define
define|#
directive|define
name|LINUX_CTR6
parameter_list|(
name|f
parameter_list|,
name|m
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|,
name|p6
parameter_list|)
value|do {			\ 	if (ldebug(f))							\ 		CTR6(KTR_LINUX, LINUX_CTRFMT(f, m),			\ 		    p1, p2, p3, p4, p5, p6);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|LINUX_CTR
parameter_list|(
name|f
parameter_list|)
value|LINUX_CTR6(f, "", 0, 0, 0, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|LINUX_CTR0
parameter_list|(
name|f
parameter_list|,
name|m
parameter_list|)
value|LINUX_CTR6(f, m, 0, 0, 0, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|LINUX_CTR1
parameter_list|(
name|f
parameter_list|,
name|m
parameter_list|,
name|p1
parameter_list|)
value|LINUX_CTR6(f, m, p1, 0, 0, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|LINUX_CTR2
parameter_list|(
name|f
parameter_list|,
name|m
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
value|LINUX_CTR6(f, m, p1, p2, 0, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|LINUX_CTR3
parameter_list|(
name|f
parameter_list|,
name|m
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|)
value|LINUX_CTR6(f, m, p1, p2, p3, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|LINUX_CTR4
parameter_list|(
name|f
parameter_list|,
name|m
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|)
value|LINUX_CTR6(f, m, p1, p2, p3, p4, 0, 0)
end_define

begin_define
define|#
directive|define
name|LINUX_CTR5
parameter_list|(
name|f
parameter_list|,
name|m
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|)
value|LINUX_CTR6(f, m, p1, p2, p3, p4, p5, 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LINUX_CTR
parameter_list|(
name|f
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LINUX_CTR0
parameter_list|(
name|f
parameter_list|,
name|m
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LINUX_CTR1
parameter_list|(
name|f
parameter_list|,
name|m
parameter_list|,
name|p1
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LINUX_CTR2
parameter_list|(
name|f
parameter_list|,
name|m
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LINUX_CTR3
parameter_list|(
name|f
parameter_list|,
name|m
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LINUX_CTR4
parameter_list|(
name|f
parameter_list|,
name|m
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LINUX_CTR5
parameter_list|(
name|f
parameter_list|,
name|m
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LINUX_CTR6
parameter_list|(
name|f
parameter_list|,
name|m
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|,
name|p6
parameter_list|)
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
comment|/* !_LINUX_UTIL_H_ */
end_comment

end_unit

