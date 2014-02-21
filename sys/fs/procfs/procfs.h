begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 Jan-Simon Pendry  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)procfs.h	8.9 (Berkeley) 5/14/95  *  * From:  * $FreeBSD$  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|int
name|procfs_docurproc
parameter_list|(
name|PFS_FILL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|procfs_doosrel
parameter_list|(
name|PFS_FILL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|procfs_doproccmdline
parameter_list|(
name|PFS_FILL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|procfs_doprocctl
parameter_list|(
name|PFS_FILL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|procfs_doprocdbregs
parameter_list|(
name|PFS_FILL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|procfs_doprocfile
parameter_list|(
name|PFS_FILL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|procfs_doprocfpregs
parameter_list|(
name|PFS_FILL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|procfs_doprocmap
parameter_list|(
name|PFS_FILL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|procfs_doprocmem
parameter_list|(
name|PFS_FILL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|procfs_doprocnote
parameter_list|(
name|PFS_FILL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|procfs_doprocregs
parameter_list|(
name|PFS_FILL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|procfs_doprocrlimit
parameter_list|(
name|PFS_FILL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|procfs_doprocstatus
parameter_list|(
name|PFS_FILL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|procfs_doproctype
parameter_list|(
name|PFS_FILL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|procfs_ioctl
parameter_list|(
name|PFS_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|procfs_close
parameter_list|(
name|PFS_CLOSE_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Attributes */
end_comment

begin_function_decl
name|int
name|procfs_attr
parameter_list|(
name|PFS_ATTR_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Visibility */
end_comment

begin_function_decl
name|int
name|procfs_notsystem
parameter_list|(
name|PFS_VIS_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|procfs_candebug
parameter_list|(
name|PFS_VIS_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

end_unit

