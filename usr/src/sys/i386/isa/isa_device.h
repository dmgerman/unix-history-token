begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)isa_device.h	8.1 (Berkeley) 6/11/93  */
end_comment

begin_comment
comment|/*  * ISA Bus Autoconfiguration  */
end_comment

begin_comment
comment|/*  * Per device structure.  */
end_comment

begin_struct
struct|struct
name|isa_device
block|{
name|struct
name|isa_driver
modifier|*
name|id_driver
decl_stmt|;
name|short
name|id_iobase
decl_stmt|;
comment|/* base i/o address */
name|short
name|id_irq
decl_stmt|;
comment|/* interrupt request */
name|short
name|id_drq
decl_stmt|;
comment|/* DMA request */
name|caddr_t
name|id_maddr
decl_stmt|;
comment|/* physical i/o memory address on bus (if any)*/
name|int
name|id_msize
decl_stmt|;
comment|/* size of i/o memory */
name|int
function_decl|(
modifier|*
name|id_intr
function_decl|)
parameter_list|()
function_decl|;
comment|/* interrupt interface routine */
name|int
name|id_unit
decl_stmt|;
comment|/* unit number */
name|int
name|id_scsiid
decl_stmt|;
comment|/* scsi id if needed */
name|int
name|id_alive
decl_stmt|;
comment|/* device is present */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-driver structure.  *  * Each device driver defines entries for a set of routines  * as well as an array of types which are acceptable to it.  * These are used at boot time by the configuration program.  */
end_comment

begin_struct
struct|struct
name|isa_driver
block|{
name|int
function_decl|(
modifier|*
name|probe
function_decl|)
parameter_list|()
function_decl|;
comment|/* test whether device is present */
name|int
function_decl|(
modifier|*
name|attach
function_decl|)
parameter_list|()
function_decl|;
comment|/* setup driver for a device */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* device name */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|isa_device
name|isa_devtab_bio
index|[]
decl_stmt|,
name|isa_devtab_tty
index|[]
decl_stmt|,
name|isa_devtab_net
index|[]
decl_stmt|,
name|isa_devtab_null
index|[]
decl_stmt|;
end_decl_stmt

end_unit

