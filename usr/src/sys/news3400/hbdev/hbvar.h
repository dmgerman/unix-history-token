begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: hbvar.h,v 4.300 91/06/09 06:21:52 root Rel41 $ SONY  *  *	@(#)hbvar.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1987,1988 by SONY Corporation.  */
end_comment

begin_comment
comment|/*  *	hbvar.h.c	ver 0.1		  *					Form	Fri Dec 11 16:07:41 JST 1987  *					Modify	Thu Feb  2 08:57:52 JST 1989  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HBVAR__
end_ifndef

begin_define
define|#
directive|define
name|__HBVAR__
value|1
end_define

begin_comment
comment|/*  * This file contains definitions related to the kernel structures  * for dealing with the HYPER-BUS interface.  *  * Each HYPER-BUS has a hb_hd structure.  * Each HYPER-BUS controller which is not a device has a hb_ctlr structure.  * Each HYPER-BUS device has a hb_device structure.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * Per-HYPER-BUS structure.  *  * This structure holds the interrupt vector for the HYPER-BUS,  * and its address in physical and virtual space.  At boot time  * we determine the devices attached to the HYPER-BUS and their  * interrupt vectors, filling in vh_vec.  We free the map  * register resources of the HYPER-BUS into the structures  * defined here.  *  * During normal operation, resources are allocated and returned  * to the structures here.  We watch the number of passive releases  * on each HYPER-BUS, and if the number is excessive may reset the HYPER-BUS.  *   * When HYPER-BUS resources are needed and not available,  * then device drivers may have to wait to get to the bus and are  * queued here.  It is also possible for processes to block in  * the HYPER-BUS driver in resource wait (mrwant); these  * wait states are also recorded here.  */
end_comment

begin_struct
struct|struct
name|hb_hd
block|{
name|caddr_t
name|hh_phys
decl_stmt|;
comment|/* Not used and init now. */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Per-controller structure.  *  * If a controller has devices attached, then there are  * cross-referenced hb_drive structures.  * This structure is the one which is queued in HYPER-BUS resource wait,  * and saves the information about HYPER-BUS resources which are used.  * The queue of devices waiting to transfer is also attached here.  */
end_comment

begin_struct
struct|struct
name|hb_ctlr
block|{
name|struct
name|hb_driver
modifier|*
name|hm_driver
decl_stmt|;
name|short
name|hm_ctlr
decl_stmt|;
comment|/* controller index in driver */
name|short
name|hm_alive
decl_stmt|;
comment|/* controller exists */
name|caddr_t
name|hm_addr
decl_stmt|;
comment|/* address of command area */
name|int
name|hm_intr
decl_stmt|;
comment|/* interrupt number */
name|short
name|hm_scnum
decl_stmt|;
comment|/* the scsi it is on */
name|struct
name|hb_hd
modifier|*
name|hm_hd
decl_stmt|;
name|int
name|hm_hbinfo
decl_stmt|;
comment|/* save map registers, etc */
name|struct
name|buf
name|hm_tab
decl_stmt|;
comment|/* queue of devices for this controller */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Per ``device'' structure.  *  * If a controller has many drives attached, then there will  * be several hb_device structures associated with a single hb_ctlr  * structure.  */
end_comment

begin_struct
struct|struct
name|hb_device
block|{
name|struct
name|hb_driver
modifier|*
name|hi_driver
decl_stmt|;
name|short
name|hi_unit
decl_stmt|;
comment|/* unit number on the system */
name|short
name|hi_ctlr
decl_stmt|;
comment|/* mass ctlr number; -1 if none */
name|short
name|hi_slave
decl_stmt|;
comment|/* slave on controller */
name|caddr_t
name|hi_addr
decl_stmt|;
comment|/* address of command area */
name|int
name|hi_intr
decl_stmt|;
comment|/* interrupt number */
name|short
name|hi_dk
decl_stmt|;
comment|/* if init 1 set to number for iostat */
name|int
name|hi_flags
decl_stmt|;
comment|/* parameter from system specification */
name|short
name|hi_alive
decl_stmt|;
comment|/* device exists */
name|short
name|hi_type
decl_stmt|;
comment|/* driver specific type information */
comment|/*	caddr_t hi_physaddr;	/* phys addr, for standalone (dump) code */
comment|/* this is the forward link in a list of devices on a controller */
name|struct
name|hb_device
modifier|*
name|hi_forw
decl_stmt|;
comment|/* if the device is connected to a controller, this is the controller */
name|struct
name|hb_ctlr
modifier|*
name|hi_mi
decl_stmt|;
name|struct
name|hb_hd
modifier|*
name|hi_hd
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Per-driver structure.  *  * Each HYPER-BUS driver defines entries for a set of routines  * as well as an array of types which are acceptable to it.  * These are used at boot time by the configuration program.  */
end_comment

begin_struct
struct|struct
name|hb_driver
block|{
name|int
function_decl|(
modifier|*
name|hd_probe
function_decl|)
parameter_list|()
function_decl|;
comment|/* see if a driver is really there */
name|int
function_decl|(
modifier|*
name|hd_slave
function_decl|)
parameter_list|()
function_decl|;
comment|/* see if a slave is there */
name|int
function_decl|(
modifier|*
name|hd_attach
function_decl|)
parameter_list|()
function_decl|;
comment|/* setup driver for a slave */
name|int
function_decl|(
modifier|*
name|hd_dgo
function_decl|)
parameter_list|()
function_decl|;
comment|/* start transfer */
name|int
function_decl|(
modifier|*
name|hd_intr
function_decl|)
parameter_list|()
function_decl|;
comment|/* interrupt handler */
name|char
modifier|*
name|hd_dname
decl_stmt|;
comment|/* name of a device */
name|struct
name|hb_device
modifier|*
modifier|*
name|hd_dinfo
decl_stmt|;
comment|/* backpointers to hdinit structs */
name|char
modifier|*
name|hd_mname
decl_stmt|;
comment|/* name of a controller */
name|struct
name|hb_ctlr
modifier|*
modifier|*
name|hd_minfo
decl_stmt|;
comment|/* backpointers to hminit structs */
name|short
name|hd_xclu
decl_stmt|;
comment|/* want exclusive use */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * HYPER-BUS related kernel variables  */
end_comment

begin_decl_stmt
name|struct
name|hb_hd
name|hb_hd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Hbinit and hdinit initialize the mass storage controller and  * device tables specifying possible devices.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|hb_ctlr
name|hminit
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|hb_device
name|hdinit
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__HBVAR__ */
end_comment

end_unit

