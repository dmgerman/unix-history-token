begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)isa_device.h	7.1 (Berkeley) %G%  */
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

