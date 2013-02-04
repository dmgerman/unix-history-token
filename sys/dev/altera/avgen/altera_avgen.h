begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Robert N. M. Watson  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract (FA8750-10-C-0237)  * ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ALTERA_AVALON_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ALTERA_AVALON_H_
end_define

begin_struct
struct|struct
name|altera_avgen_softc
block|{
comment|/* 	 * Bus-related fields. 	 */
name|device_t
name|avg_dev
decl_stmt|;
name|int
name|avg_unit
decl_stmt|;
comment|/* 	 * The device node and memory-mapped I/O region. 	 */
name|struct
name|cdev
modifier|*
name|avg_cdev
decl_stmt|;
name|struct
name|resource
modifier|*
name|avg_res
decl_stmt|;
name|int
name|avg_rid
decl_stmt|;
comment|/* 	 * Access properties configured by device.hints. 	 */
name|u_int
name|avg_flags
decl_stmt|;
name|u_int
name|avg_width
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Various flags extracted from device.hints to configure operations on the  * device.  */
end_comment

begin_define
define|#
directive|define
name|ALTERA_AVALON_FLAG_READ
value|0x01
end_define

begin_define
define|#
directive|define
name|ALTERA_AVALON_FLAG_WRITE
value|0x02
end_define

begin_define
define|#
directive|define
name|ALTERA_AVALON_FLAG_MMAP_READ
value|0x04
end_define

begin_define
define|#
directive|define
name|ALTERA_AVALON_FLAG_MMAP_WRITE
value|0x08
end_define

begin_define
define|#
directive|define
name|ALTERA_AVALON_FLAG_MMAP_EXEC
value|0x10
end_define

begin_define
define|#
directive|define
name|ALTERA_AVALON_CHAR_READ
value|'r'
end_define

begin_define
define|#
directive|define
name|ALTERA_AVALON_CHAR_WRITE
value|'w'
end_define

begin_define
define|#
directive|define
name|ALTERA_AVALON_CHAR_EXEC
value|'x'
end_define

begin_define
define|#
directive|define
name|ALTERA_AVALON_STR_WIDTH
value|"width"
end_define

begin_define
define|#
directive|define
name|ALTERA_AVALON_STR_FILEIO
value|"fileio"
end_define

begin_define
define|#
directive|define
name|ALTERA_AVALON_STR_MMAPIO
value|"mmapio"
end_define

begin_define
define|#
directive|define
name|ALTERA_AVALON_STR_DEVNAME
value|"devname"
end_define

begin_define
define|#
directive|define
name|ALTERA_AVALON_STR_DEVUNIT
value|"devunit"
end_define

begin_comment
comment|/*  * Driver setup routines from the bus attachment/teardown.  */
end_comment

begin_function_decl
name|int
name|altera_avgen_attach
parameter_list|(
name|struct
name|altera_avgen_softc
modifier|*
name|sc
parameter_list|,
specifier|const
name|char
modifier|*
name|str_fileio
parameter_list|,
specifier|const
name|char
modifier|*
name|str_mmapio
parameter_list|,
specifier|const
name|char
modifier|*
name|str_devname
parameter_list|,
name|int
name|devunit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|altera_avgen_detach
parameter_list|(
name|struct
name|altera_avgen_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|devclass_t
name|altera_avgen_devclass
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_ALTERA_AVALON_H_ */
end_comment

end_unit

