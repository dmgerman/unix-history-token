begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2014 The DragonFly Project.  All rights reserved.  *  * This code is derived from software contributed to The DragonFly Project  * by Matthew Dillon<dillon@backplane.com> and was subsequently ported  * to FreeBSD by Michael Gmelin<freebsd@grem.de>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  * 3. Neither the name of The DragonFly Project nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific, prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE  * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ICHIIC_IG4_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_ICHIIC_IG4_VAR_H_
end_define

begin_include
include|#
directive|include
file|"bus_if.h"
end_include

begin_include
include|#
directive|include
file|"device_if.h"
end_include

begin_include
include|#
directive|include
file|"pci_if.h"
end_include

begin_include
include|#
directive|include
file|"iicbus_if.h"
end_include

begin_define
define|#
directive|define
name|IG4_RBUFSIZE
value|128
end_define

begin_define
define|#
directive|define
name|IG4_RBUFMASK
value|(IG4_RBUFSIZE - 1)
end_define

begin_enum
enum|enum
name|ig4_op
block|{
name|IG4_IDLE
block|,
name|IG4_READ
block|,
name|IG4_WRITE
block|}
enum|;
end_enum

begin_struct
struct|struct
name|ig4iic_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|struct
name|intr_config_hook
name|enum_hook
decl_stmt|;
name|device_t
name|iicbus
decl_stmt|;
name|struct
name|resource
modifier|*
name|regs_res
decl_stmt|;
name|int
name|regs_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|intr_res
decl_stmt|;
name|int
name|intr_rid
decl_stmt|;
name|void
modifier|*
name|intr_handle
decl_stmt|;
name|int
name|intr_type
decl_stmt|;
name|enum
name|ig4_op
name|op
decl_stmt|;
name|int
name|cmd
decl_stmt|;
name|int
name|rnext
decl_stmt|;
name|int
name|rpos
decl_stmt|;
name|char
name|rbuf
index|[
name|IG4_RBUFSIZE
index|]
decl_stmt|;
name|int
name|error
decl_stmt|;
name|uint8_t
name|last_slave
decl_stmt|;
name|int
name|platform_attached
range|:
literal|1
decl_stmt|;
name|int
name|use_10bit
range|:
literal|1
decl_stmt|;
name|int
name|slave_valid
range|:
literal|1
decl_stmt|;
name|int
name|read_started
range|:
literal|1
decl_stmt|;
name|int
name|write_started
range|:
literal|1
decl_stmt|;
comment|/* 	 * Locking semantics: 	 * 	 * Functions implementing the icbus interface that interact 	 * with the controller acquire an exclusive lock on call_lock 	 * to prevent interleaving of calls to the interface and a lock on 	 * io_lock right afterwards, to synchronize controller I/O activity. 	 * 	 * The interrupt handler can only read data while no iicbus call 	 * is in progress or while io_lock is dropped during mtx_sleep in 	 * wait_status and set_controller. It is safe to drop io_lock in those 	 * places, because the interrupt handler only accesses those registers: 	 * 	 * - IG4_REG_I2C_STA  (I2C Status) 	 * - IG4_REG_DATA_CMD (Data Buffer and Command) 	 * - IG4_REG_CLR_INTR (Clear Interrupt) 	 * 	 * Locking outside of those places is required to make the content 	 * of rpos/rnext predictable (e.g. whenever data_read is called and in 	 * ig4iic_transfer). 	 */
name|struct
name|sx
name|call_lock
decl_stmt|;
name|struct
name|mtx
name|io_lock
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ig4iic_softc
name|ig4iic_softc_t
typedef|;
end_typedef

begin_comment
comment|/* Attach/Detach called from ig4iic_pci_*() */
end_comment

begin_function_decl
name|int
name|ig4iic_attach
parameter_list|(
name|ig4iic_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ig4iic_detach
parameter_list|(
name|ig4iic_softc_t
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* iicbus methods */
end_comment

begin_decl_stmt
specifier|extern
name|iicbus_transfer_t
name|ig4iic_transfer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|iicbus_reset_t
name|ig4iic_reset
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ICHIIC_IG4_VAR_H_ */
end_comment

end_unit

