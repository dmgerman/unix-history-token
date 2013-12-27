begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2005 M. Warner Losh. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PC98_INCLUDE_MD_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_PC98_INCLUDE_MD_VAR_H_
end_define

begin_include
include|#
directive|include
file|<i386/md_var.h>
end_include

begin_comment
comment|/*  * PC98 machines are based on Intel CPUs.  Some add-in boards offer  * different CPUs than came with the processor.  These CPUs sometimes  * require additional flushing before and/or after DMAs.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|need_pre_dma_flush
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|need_post_dma_flush
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The geometry of disks might need adjustment on PC98 machines.  */
end_comment

begin_struct_decl
struct_decl|struct
name|ccb_calc_geometry
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|scsi_da_bios_params
parameter_list|(
name|struct
name|ccb_calc_geometry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|disk
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|pc98_ata_disk_firmware_geom_adjust
parameter_list|(
name|struct
name|disk
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ata_disk_firmware_geom_adjust
parameter_list|(
name|disk
parameter_list|)
define|\
value|pc98_ata_disk_firmware_geom_adjust(disk)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PC98_INCLUDE_MD_VAR_H_ */
end_comment

end_unit

