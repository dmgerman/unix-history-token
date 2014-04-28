begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013-2014 Robert N. M. Watson  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract (FA8750-10-C-0237)  * ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BOOT_LOADER_H_
end_ifndef

begin_define
define|#
directive|define
name|_BOOT_LOADER_H_
end_define

begin_comment
comment|/* beri_console.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|console
name|altera_jtag_uart_console
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* beri_disk.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|devsw
name|beri_cfi_disk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|devsw
name|beri_sdcard_disk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* devicename.c */
end_comment

begin_function_decl
name|int
name|beri_arch_setcurrdev
parameter_list|(
name|struct
name|env_var
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|beri_arch_fmtdev
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|beri_arch_getdev
parameter_list|(
name|void
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* exec.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|file_format
name|beri_elf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* main.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|boot2_argc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|boot2_argv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|boot2_envv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|bootinfo
name|boot2_bootinfo
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* metadata.c */
end_comment

begin_function_decl
name|int
name|md_load64
parameter_list|(
name|char
modifier|*
name|args
parameter_list|,
name|vm_offset_t
modifier|*
name|modulep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* vers.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|bootprog_name
index|[]
decl_stmt|,
name|bootprog_rev
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|bootprog_date
index|[]
decl_stmt|,
name|bootprog_maker
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_BOOT_LOADER_H_ */
end_comment

end_unit

