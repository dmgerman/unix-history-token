begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 John D. Polstra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_PROCFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_PROCFS_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<machine/reg.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|reg
name|gregset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|fpreg
name|fpregset_t
typedef|;
end_typedef

begin_comment
comment|/*  * These structures define an interface between core files and the debugger.  * Never change or delete any elements.  If you add elements, add them to  * the end of the structure, and increment the value of its version field.  * This will help to ensure that today's core dump will still be usable  * with next year's debugger.  *  * A lot more things should be added to these structures.  At present,  * they contain the absolute bare minimum required to allow GDB to work  * with ELF core dumps.  */
end_comment

begin_comment
comment|/*  * The parenthsized numbers like (1) indicate the minimum version number  * for which each element exists in the structure.  */
end_comment

begin_define
define|#
directive|define
name|PRSTATUS_VERSION
value|1
end_define

begin_comment
comment|/* Current version of prstatus_t */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|prstatus
block|{
name|int
name|pr_version
decl_stmt|;
comment|/* Version number of struct (1) */
name|size_t
name|pr_statussz
decl_stmt|;
comment|/* sizeof(prstatus_t) (1) */
name|size_t
name|pr_gregsetsz
decl_stmt|;
comment|/* sizeof(gregset_t) (1) */
name|size_t
name|pr_fpregsetsz
decl_stmt|;
comment|/* sizeof(fpregset_t) (1) */
name|int
name|pr_osreldate
decl_stmt|;
comment|/* Kernel version (1) */
name|int
name|pr_cursig
decl_stmt|;
comment|/* Current signal (1) */
name|pid_t
name|pr_pid
decl_stmt|;
comment|/* Process ID (1) */
name|gregset_t
name|pr_reg
decl_stmt|;
comment|/* General purpose registers (1) */
block|}
name|prstatus_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|fpregset_t
name|prfpregset_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PRARGSZ
value|80
end_define

begin_comment
comment|/* Maximum argument bytes saved */
end_comment

begin_define
define|#
directive|define
name|PRPSINFO_VERSION
value|1
end_define

begin_comment
comment|/* Current version of prpsinfo_t */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|prpsinfo
block|{
name|int
name|pr_version
decl_stmt|;
comment|/* Version number of struct (1) */
name|size_t
name|pr_psinfosz
decl_stmt|;
comment|/* sizeof(prpsinfo_t) (1) */
name|char
name|pr_fname
index|[
name|MAXCOMLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Command name, null terminated (1) */
name|char
name|pr_psargs
index|[
name|PRARGSZ
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Arguments, null terminated (1) */
block|}
name|prpsinfo_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_PROCFS_H_ */
end_comment

end_unit

