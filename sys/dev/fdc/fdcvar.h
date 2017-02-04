begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004-2005 M. Warner Losh.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* XXX should audit this file to see if additional copyrights needed */
end_comment

begin_enum
enum|enum
name|fdc_type
block|{
name|FDC_NE765
block|,
name|FDC_ENHANCED
block|,
name|FDC_UNKNOWN
init|=
operator|-
literal|1
block|}
enum|;
end_enum

begin_comment
comment|/*  * Per controller structure (softc).  */
end_comment

begin_struct
struct|struct
name|fdc_data
block|{
name|int
name|fdcu
decl_stmt|;
comment|/* our unit number */
name|int
name|dmachan
decl_stmt|;
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|FDC_HASDMA
value|0x01
define|#
directive|define
name|FDC_STAT_VALID
value|0x08
define|#
directive|define
name|FDC_HAS_FIFO
value|0x10
define|#
directive|define
name|FDC_NEEDS_RESET
value|0x20
define|#
directive|define
name|FDC_NODMA
value|0x40
comment|/* Don't do DMA */
define|#
directive|define
name|FDC_NOFAST
value|0x80
comment|/* Don't register isr as a fast one */
define|#
directive|define
name|FDC_KTHREAD_EXIT
value|0x1000
comment|/* request worker thread to stop */
define|#
directive|define
name|FDC_KTHREAD_ALIVE
value|0x2000
comment|/* worker thread is alive */
name|struct
name|fd_data
modifier|*
name|fd
decl_stmt|;
comment|/* The active drive */
name|int
name|retry
decl_stmt|;
name|int
name|fdout
decl_stmt|;
comment|/* mirror of the w/o digital output reg */
name|u_int
name|status
index|[
literal|7
index|]
decl_stmt|;
comment|/* copy of the registers */
name|enum
name|fdc_type
name|fdct
decl_stmt|;
comment|/* chip version of FDC */
name|int
name|fdc_errs
decl_stmt|;
comment|/* number of logged errors */
name|struct
name|bio_queue_head
name|head
decl_stmt|;
name|struct
name|bio
modifier|*
name|bp
decl_stmt|;
comment|/* active buffer */
name|struct
name|resource
modifier|*
name|res_irq
decl_stmt|,
modifier|*
name|res_drq
decl_stmt|;
name|int
name|rid_irq
decl_stmt|,
name|rid_drq
decl_stmt|;
define|#
directive|define
name|FDC_MAXREG
value|8
name|int
name|ridio
index|[
name|FDC_MAXREG
index|]
decl_stmt|;
name|struct
name|resource
modifier|*
name|resio
index|[
name|FDC_MAXREG
index|]
decl_stmt|;
name|bus_space_tag_t
name|iot
decl_stmt|;
name|bus_space_handle_t
name|ioh
index|[
name|FDC_MAXREG
index|]
decl_stmt|;
name|int
name|ioff
index|[
name|FDC_MAXREG
index|]
decl_stmt|;
name|void
modifier|*
name|fdc_intr
decl_stmt|;
name|device_t
name|fdc_dev
decl_stmt|;
name|struct
name|mtx
name|fdc_mtx
decl_stmt|;
name|struct
name|proc
modifier|*
name|fdc_thread
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|devclass_t
name|fdc_devclass
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|fdc_device_ivars
block|{
name|FDC_IVAR_FDUNIT
block|,
name|FDC_IVAR_FDTYPE
block|, }
enum|;
end_enum

begin_expr_stmt
name|__BUS_ACCESSOR
argument_list|(
name|fdc
argument_list|,
name|fdunit
argument_list|,
name|FDC
argument_list|,
name|FDUNIT
argument_list|,
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__BUS_ACCESSOR
argument_list|(
name|fdc
argument_list|,
name|fdtype
argument_list|,
name|FDC
argument_list|,
name|FDTYPE
argument_list|,
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|fdc_release_resources
parameter_list|(
name|struct
name|fdc_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdc_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fdc_start_worker
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdc_hints_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdc_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_t
name|fdc_add_child
parameter_list|(
name|device_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdc_initial_reset
parameter_list|(
name|device_t
parameter_list|,
name|struct
name|fdc_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdc_print_child
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdc_read_ivar
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|,
name|int
parameter_list|,
name|uintptr_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdc_write_ivar
parameter_list|(
name|device_t
parameter_list|,
name|device_t
parameter_list|,
name|int
parameter_list|,
name|uintptr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdc_isa_alloc_resources
parameter_list|(
name|device_t
parameter_list|,
name|struct
name|fdc_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

