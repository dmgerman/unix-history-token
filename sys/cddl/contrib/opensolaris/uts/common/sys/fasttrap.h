begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_FASTTRAP_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_FASTTRAP_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_include
include|#
directive|include
file|<sys/fasttrap_isa.h>
end_include

begin_include
include|#
directive|include
file|<sys/dtrace.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
define|#
directive|define
name|FASTTRAPIOC
value|(('m'<< 24) | ('r'<< 16) | ('f'<< 8))
define|#
directive|define
name|FASTTRAPIOC_MAKEPROBE
value|(FASTTRAPIOC | 1)
define|#
directive|define
name|FASTTRAPIOC_GETINSTR
value|(FASTTRAPIOC | 2)
else|#
directive|else
define|#
directive|define
name|FASTTRAPIOC_GETINSTR
value|_IOWR('f', 2, uint8_t)
define|#
directive|define
name|FASTTRAPIOC_MAKEPROBE
value|_IO('f', 3)
endif|#
directive|endif
typedef|typedef
enum|enum
name|fasttrap_probe_type
block|{
name|DTFTP_NONE
init|=
literal|0
block|,
name|DTFTP_ENTRY
block|,
name|DTFTP_RETURN
block|,
name|DTFTP_OFFSETS
block|,
name|DTFTP_POST_OFFSETS
block|,
name|DTFTP_IS_ENABLED
block|}
name|fasttrap_probe_type_t
typedef|;
typedef|typedef
struct|struct
name|fasttrap_probe_spec
block|{
name|pid_t
name|ftps_pid
decl_stmt|;
name|fasttrap_probe_type_t
name|ftps_type
decl_stmt|;
name|char
name|ftps_func
index|[
name|DTRACE_FUNCNAMELEN
index|]
decl_stmt|;
name|char
name|ftps_mod
index|[
name|DTRACE_MODNAMELEN
index|]
decl_stmt|;
name|uint64_t
name|ftps_pc
decl_stmt|;
name|uint64_t
name|ftps_size
decl_stmt|;
name|uint64_t
name|ftps_noffs
decl_stmt|;
name|uint64_t
name|ftps_offs
index|[
literal|1
index|]
decl_stmt|;
block|}
name|fasttrap_probe_spec_t
typedef|;
typedef|typedef
struct|struct
name|fasttrap_instr_query
block|{
name|uint64_t
name|ftiq_pc
decl_stmt|;
name|pid_t
name|ftiq_pid
decl_stmt|;
name|fasttrap_instr_t
name|ftiq_instr
decl_stmt|;
block|}
name|fasttrap_instr_query_t
typedef|;
comment|/*  * To support the fasttrap provider from very early in a process's life,  * the run-time linker, ld.so.1, has a program header of type PT_SUNWDTRACE  * which points to a data object which must be PT_SUNWDTRACE_SIZE bytes.  * This structure mimics the fasttrap provider section of the ulwp_t structure.  * When the fasttrap provider is changed to require new or different  * instructions, the data object in ld.so.1 and the thread initializers in libc  * (libc_init() and _thrp_create()) need to be updated to include the new  * instructions, and PT_SUNWDTRACE needs to be changed to a new unique number  * (while the old value gets assigned something like PT_SUNWDTRACE_1). Since the  * linker must be backward compatible with old Solaris releases, it must have  * program headers for each of the PT_SUNWDTRACE versions. The kernel's  * elfexec() function only has to look for the latest version of the  * PT_SUNWDTRACE program header.  */
define|#
directive|define
name|PT_SUNWDTRACE_SIZE
value|FASTTRAP_SUNWDTRACE_SIZE
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_FASTTRAP_H */
end_comment

end_unit

