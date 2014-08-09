begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 The FreeBSD Foundation  * Copyright (c) 2008 John Birrell (jb@freebsd.org)  * All rights reserved.  *  * Portions of this software were developed by Rui Paulo under sponsorship  * from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBPROC_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIBPROC_H_
end_define

begin_include
include|#
directive|include
file|<gelf.h>
end_include

begin_include
include|#
directive|include
file|<rtld_db.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_struct_decl
struct_decl|struct
name|proc_handle
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|proc_child_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Values returned by proc_state(). */
end_comment

begin_define
define|#
directive|define
name|PS_IDLE
value|1
end_define

begin_define
define|#
directive|define
name|PS_STOP
value|2
end_define

begin_define
define|#
directive|define
name|PS_RUN
value|3
end_define

begin_define
define|#
directive|define
name|PS_UNDEAD
value|4
end_define

begin_define
define|#
directive|define
name|PS_DEAD
value|5
end_define

begin_define
define|#
directive|define
name|PS_LOST
value|6
end_define

begin_comment
comment|/* Reason values for proc_detach(). */
end_comment

begin_define
define|#
directive|define
name|PRELEASE_HANG
value|1
end_define

begin_define
define|#
directive|define
name|PRELEASE_KILL
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
name|prmap
block|{
name|uintptr_t
name|pr_vaddr
decl_stmt|;
comment|/* Virtual address. */
name|size_t
name|pr_size
decl_stmt|;
comment|/* Mapping size in bytes */
name|size_t
name|pr_offset
decl_stmt|;
comment|/* Mapping offset in object */
name|char
name|pr_mapname
index|[
name|PATH_MAX
index|]
decl_stmt|;
comment|/* Mapping filename */
name|uint8_t
name|pr_mflags
decl_stmt|;
comment|/* Protection flags */
define|#
directive|define
name|MA_READ
value|0x01
define|#
directive|define
name|MA_WRITE
value|0x02
define|#
directive|define
name|MA_EXEC
value|0x04
define|#
directive|define
name|MA_COW
value|0x08
define|#
directive|define
name|MA_NEEDS_COPY
value|0x10
define|#
directive|define
name|MA_NOCOREDUMP
value|0x20
block|}
name|prmap_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|proc_map_f
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|prmap_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|proc_sym_f
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|GElf_Sym
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Values for ELF sections */
end_comment

begin_define
define|#
directive|define
name|PR_SYMTAB
value|1
end_define

begin_define
define|#
directive|define
name|PR_DYNSYM
value|2
end_define

begin_comment
comment|/* Values for the 'mask' parameter in the iteration functions */
end_comment

begin_define
define|#
directive|define
name|BIND_LOCAL
value|0x0001
end_define

begin_define
define|#
directive|define
name|BIND_GLOBAL
value|0x0002
end_define

begin_define
define|#
directive|define
name|BIND_WEAK
value|0x0004
end_define

begin_define
define|#
directive|define
name|BIND_ANY
value|(BIND_LOCAL|BIND_GLOBAL|BIND_WEAK)
end_define

begin_define
define|#
directive|define
name|TYPE_NOTYPE
value|0x0100
end_define

begin_define
define|#
directive|define
name|TYPE_OBJECT
value|0x0200
end_define

begin_define
define|#
directive|define
name|TYPE_FUNC
value|0x0400
end_define

begin_define
define|#
directive|define
name|TYPE_SECTION
value|0x0800
end_define

begin_define
define|#
directive|define
name|TYPE_FILE
value|0x1000
end_define

begin_define
define|#
directive|define
name|TYPE_ANY
value|(TYPE_NOTYPE|TYPE_OBJECT|TYPE_FUNC|TYPE_SECTION|\     			 TYPE_FILE)
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|REG_PC
block|,
name|REG_SP
block|,
name|REG_RVAL1
block|,
name|REG_RVAL2
block|}
name|proc_reg_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SIG2STR_MAX
value|8
end_define

begin_typedef
typedef|typedef
struct|struct
name|lwpstatus
block|{
name|int
name|pr_why
decl_stmt|;
define|#
directive|define
name|PR_REQUESTED
value|1
define|#
directive|define
name|PR_FAULTED
value|2
define|#
directive|define
name|PR_SYSENTRY
value|3
define|#
directive|define
name|PR_SYSEXIT
value|4
define|#
directive|define
name|PR_SIGNALLED
value|5
name|int
name|pr_what
decl_stmt|;
define|#
directive|define
name|FLTBPT
value|-1
block|}
name|lwpstatus_t
typedef|;
end_typedef

begin_comment
comment|/* Function prototype definitions. */
end_comment

begin_function_decl
name|__BEGIN_DECLS
name|prmap_t
modifier|*
name|proc_addr2map
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|,
name|uintptr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|prmap_t
modifier|*
name|proc_name2map
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|proc_objname
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|,
name|uintptr_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|prmap_t
modifier|*
name|proc_obj2map
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_iter_objs
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|,
name|proc_map_f
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_iter_symbyaddr
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|proc_sym_f
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_addr2sym
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|,
name|uintptr_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|GElf_Sym
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_attach
parameter_list|(
name|pid_t
name|pid
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|proc_handle
modifier|*
modifier|*
name|pphdl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_continue
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_clearflags
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_create
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
parameter_list|,
name|proc_child_func
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|proc_handle
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_detach
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_getflags
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_name2sym
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|GElf_Sym
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_setflags
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_state
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|pid_t
name|proc_getpid
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_wstatus
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_getwstat
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|proc_signame
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_read
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|lwpstatus_t
modifier|*
name|proc_getlwpstatus
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|proc_free
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rd_agent_t
modifier|*
name|proc_rdagent
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|proc_updatesyms
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_bkptset
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|,
name|uintptr_t
parameter_list|,
name|unsigned
name|long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_bkptdel
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|,
name|uintptr_t
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|proc_bkptregadj
parameter_list|(
name|unsigned
name|long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_bkptexec
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_regget
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|,
name|proc_reg_t
parameter_list|,
name|unsigned
name|long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proc_regset
parameter_list|(
name|struct
name|proc_handle
modifier|*
parameter_list|,
name|proc_reg_t
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LIBPROC_H_ */
end_comment

end_unit

