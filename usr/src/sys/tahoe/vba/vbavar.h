begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)vbavar.h	7.4 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * This file contains definitions related to the kernel structures  * for dealing with the VERSAbus adapters.  *  * Each VERSAbus has a vba_hd structure.  * Each VERSAbus controller which is not a device has a vba_ctlr structure.  * Each VERSAbus device has a vba_device structure.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * Per-vba structure.  */
end_comment

begin_struct
struct|struct
name|vba_hd
block|{
name|int
name|vh_lastiv
decl_stmt|;
comment|/* last interrupt vector assigned */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-controller structure.  * (E.g. one for each disk and tape controller, and other things  * which use and release buffered data paths.)  *  * If a controller has devices attached, then there are  * cross-referenced vba_drive structures.  * This structure is the one which is queued in VERSAbus resource wait,  * and saves the information about VERSAbus resources which are used.  * The queue of devices waiting to transfer is also attached here.  */
end_comment

begin_struct
struct|struct
name|vba_ctlr
block|{
name|struct
name|vba_driver
modifier|*
name|um_driver
decl_stmt|;
name|short
name|um_ctlr
decl_stmt|;
comment|/* controller index in driver */
name|short
name|um_vbanum
decl_stmt|;
comment|/* the vba it is on */
name|short
name|um_alive
decl_stmt|;
comment|/* controller exists */
name|int
function_decl|(
modifier|*
modifier|*
name|um_intr
function_decl|)
parameter_list|()
function_decl|;
comment|/* interrupt handler(s) */
name|caddr_t
name|um_addr
decl_stmt|;
comment|/* address of device in i/o space */
name|struct
name|vba_hd
modifier|*
name|um_hd
decl_stmt|;
comment|/* the driver saves the prototype command here for use in its go routine */
name|int
name|um_cmd
decl_stmt|;
comment|/* communication to dgo() */
name|int
name|um_vbinfo
decl_stmt|;
comment|/* save VERSAbus registers, etc */
name|struct
name|buf
name|um_tab
decl_stmt|;
comment|/* queue of devices for this controller */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per ``device'' structure.  * (A controller has devices or uses and releases buffered data paths).  * (Everything else is a ``device''.)  *  * If a controller has many drives attached, then there will  * be several vba_device structures associated with a single vba_ctlr  * structure.  *  * This structure contains all the information necessary to run  * a VERSAbus device.  It also contains information  * for slaves of VERSAbus controllers as to which device on the slave  * this is.  A flags field here can also be given in the system specification  * and is used to tell which tty lines are hard wired or other device  * specific parameters.  */
end_comment

begin_struct
struct|struct
name|vba_device
block|{
name|struct
name|vba_driver
modifier|*
name|ui_driver
decl_stmt|;
name|short
name|ui_unit
decl_stmt|;
comment|/* unit number on the system */
name|short
name|ui_ctlr
decl_stmt|;
comment|/* mass ctlr number; -1 if none */
name|short
name|ui_vbanum
decl_stmt|;
comment|/* the vba it is on */
name|short
name|ui_slave
decl_stmt|;
comment|/* slave on controller */
name|int
function_decl|(
modifier|*
modifier|*
name|ui_intr
function_decl|)
parameter_list|()
function_decl|;
comment|/* interrupt handler(s) */
name|caddr_t
name|ui_addr
decl_stmt|;
comment|/* address of device in i/o space */
name|short
name|ui_dk
decl_stmt|;
comment|/* if init 1 set to number for iostat */
name|long
name|ui_flags
decl_stmt|;
comment|/* parameter from system specification */
name|short
name|ui_alive
decl_stmt|;
comment|/* device exists */
name|short
name|ui_type
decl_stmt|;
comment|/* driver specific type information */
name|caddr_t
name|ui_physaddr
decl_stmt|;
comment|/* phys addr, for standalone (dump) code */
comment|/* this is the forward link in a list of devices on a controller */
name|struct
name|vba_device
modifier|*
name|ui_forw
decl_stmt|;
comment|/* if the device is connected to a controller, this is the controller */
name|struct
name|vba_ctlr
modifier|*
name|ui_mi
decl_stmt|;
name|struct
name|vba_hd
modifier|*
name|ui_hd
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Per-driver structure.  *  * Each VERSAbus driver defines entries for a set of routines  * as well as an array of types which are acceptable to it.  * These are used at boot time by the configuration program.  */
end_comment

begin_struct
struct|struct
name|vba_driver
block|{
name|int
function_decl|(
modifier|*
name|ud_probe
function_decl|)
parameter_list|()
function_decl|;
comment|/* see if a driver is really there */
name|int
function_decl|(
modifier|*
name|ud_slave
function_decl|)
parameter_list|()
function_decl|;
comment|/* see if a slave is there */
name|int
function_decl|(
modifier|*
name|ud_attach
function_decl|)
parameter_list|()
function_decl|;
comment|/* setup driver for a slave */
name|int
function_decl|(
modifier|*
name|ud_dgo
function_decl|)
parameter_list|()
function_decl|;
comment|/* fill csr/ba to start transfer */
name|long
modifier|*
name|ud_addr
decl_stmt|;
comment|/* device csr addresses */
name|char
modifier|*
name|ud_dname
decl_stmt|;
comment|/* name of a device */
name|struct
name|vba_device
modifier|*
modifier|*
name|ud_dinfo
decl_stmt|;
comment|/* backpointers to vbdinit structs */
name|char
modifier|*
name|ud_mname
decl_stmt|;
comment|/* name of a controller */
name|struct
name|vba_ctlr
modifier|*
modifier|*
name|ud_minfo
decl_stmt|;
comment|/* backpointers to vbminit structs */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Common state for Versabus driver I/O resources,  * including memory for intermediate buffer and page map,  * allocated by vbainit.  */
end_comment

begin_struct
struct|struct
name|vb_buf
block|{
comment|/* these fields set up once by vbainit */
name|int
name|vb_flags
decl_stmt|;
comment|/* device parameters */
name|struct
name|pte
modifier|*
name|vb_map
decl_stmt|;
comment|/* private page entries */
name|caddr_t
name|vb_utl
decl_stmt|;
comment|/* virtual addresses mapped by vb_map */
name|caddr_t
name|vb_rawbuf
decl_stmt|;
comment|/* intermediate buffer */
name|u_long
name|vb_physbuf
decl_stmt|;
comment|/* phys addr of intermediate buffer */
name|u_long
name|vb_bufsize
decl_stmt|;
comment|/* intermediate buffer size */
name|u_long
name|vb_maxphys
decl_stmt|;
comment|/* physical address limit */
comment|/* remaining fields apply to current transfer: */
name|int
name|vb_copy
decl_stmt|;
comment|/* copy to/from intermediate buffer */
name|int
name|vb_iskernel
decl_stmt|;
comment|/* is to/from kernel address space */
block|}
struct|;
end_struct

begin_comment
comment|/*  * flags to vbainit  */
end_comment

begin_define
define|#
directive|define
name|VB_32BIT
value|0x00
end_define

begin_comment
comment|/* device uses 32-bit addressing */
end_comment

begin_define
define|#
directive|define
name|VB_24BIT
value|0x01
end_define

begin_comment
comment|/* device uses 24-bit addressing */
end_comment

begin_define
define|#
directive|define
name|VB_20BIT
value|0x02
end_define

begin_comment
comment|/* device uses 20-bit addressing */
end_comment

begin_define
define|#
directive|define
name|VB_SCATTER
value|0x04
end_define

begin_comment
comment|/* device does scatter-gather */
end_comment

begin_comment
comment|/*  * hardware memory-addressing limits: highest physical address  * that each address length can use for main memory access.  */
end_comment

begin_define
define|#
directive|define
name|VB_MAXADDR20
value|0x000fffff
end_define

begin_comment
comment|/* highest addr for 20-bit */
end_comment

begin_define
define|#
directive|define
name|VB_MAXADDR24
value|0x00efffff
end_define

begin_comment
comment|/* highest addr for 23/24-bit */
end_comment

begin_define
define|#
directive|define
name|VB_MAXADDR32
value|0x3effffff
end_define

begin_comment
comment|/* highest addr for 32-bit */
end_comment

begin_comment
comment|/*  * Statistics on vba operations.  */
end_comment

begin_struct
struct|struct
name|vbastat
block|{
name|u_long
name|k_raw
decl_stmt|;
comment|/* to/from contiguous kernel DMA buffer */
name|u_long
name|u_raw
decl_stmt|;
comment|/* to/from contiguous user DMA buffer */
name|u_long
name|k_copy
decl_stmt|;
comment|/* copied to/from kernel */
name|u_long
name|u_copy
decl_stmt|;
comment|/* copied to/from user */
name|u_long
name|k_sg
decl_stmt|;
comment|/* scatter-gather to/from kernel */
name|u_long
name|u_sg
decl_stmt|;
comment|/* scatter-gather to/from user */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * VBA related kernel variables  */
end_comment

begin_decl_stmt
name|int
name|numvba
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of uba's */
end_comment

begin_decl_stmt
name|struct
name|vba_hd
name|vba_hd
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|vbastat
name|vbastat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Vbminit and vbdinit initialize the mass storage controller and  * device tables specifying possible devices.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vba_ctlr
name|vbminit
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vba_device
name|vbdinit
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * VERSAbus device address space is mapped by VMEMmap  * into virtual address vmem[].  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pte
name|VMEMmap
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vba device addr pte's */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|vmem
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vba device addr space */
end_comment

begin_function_decl
name|u_long
name|vbasetup
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|KERNEL
end_endif

begin_endif
endif|#
directive|endif
endif|!LOCORE
end_endif

end_unit

