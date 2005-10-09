begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000-2001 by Coleman Kane<cokane@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Gardner Buchanan.  * 4. The name of Gardner Buchanan may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *   $FreeBSD$  */
end_comment

begin_comment
comment|/* tdfx_pci.h -- Prototypes for tdfx device methods */
end_comment

begin_comment
comment|/* Copyright (C) 2000-2001 by Coleman Kane<cokane@FreeBSD.org> */
end_comment

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_comment
comment|/* Driver functions */
end_comment

begin_function_decl
specifier|static
name|int
name|tdfx_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|tdfx_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|tdfx_setmtrr
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|tdfx_clrmtrr
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|tdfx_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|tdfx_shutdown
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* CDEV file ops */
end_comment

begin_decl_stmt
specifier|static
name|d_open_t
name|tdfx_open
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_close_t
name|tdfx_close
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_mmap_t
name|tdfx_mmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_ioctl_t
name|tdfx_ioctl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Card Queries */
end_comment

begin_function_decl
specifier|static
name|int
name|tdfx_do_query
parameter_list|(
name|u_int
name|cmd
parameter_list|,
name|struct
name|tdfx_pio_data
modifier|*
name|piod
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|tdfx_query_boards
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|tdfx_query_fetch
parameter_list|(
name|u_int
name|cmd
parameter_list|,
name|struct
name|tdfx_pio_data
modifier|*
name|piod
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|tdfx_query_update
parameter_list|(
name|u_int
name|cmd
parameter_list|,
name|struct
name|tdfx_pio_data
modifier|*
name|piod
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Card PIO funcs */
end_comment

begin_function_decl
specifier|static
name|int
name|tdfx_do_pio
parameter_list|(
name|u_int
name|cmd
parameter_list|,
name|struct
name|tdfx_pio_data
modifier|*
name|piod
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|tdfx_do_pio_wt
parameter_list|(
name|struct
name|tdfx_pio_data
modifier|*
name|piod
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|tdfx_do_pio_rd
parameter_list|(
name|struct
name|tdfx_pio_data
modifier|*
name|piod
parameter_list|)
function_decl|;
end_function_decl

end_unit

