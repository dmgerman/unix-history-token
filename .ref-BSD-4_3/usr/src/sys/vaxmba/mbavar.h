begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)mbavar.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_comment
comment|/*  * This file contains definitions related to the kernel structures  * for dealing with the massbus adapters.  *  * Each mba has a mba_hd structure.  * Each massbus device has a mba_device structure.  * Each massbus slave has a mba_slave structure.  *  * At boot time we prowl the structures and fill in the pointers  * for devices which we find.  */
end_comment

begin_comment
comment|/*  * Per-mba structure.  *  * The initialization routine uses the information in the mbdinit table  * to initialize the what is attached to each massbus slot information.  * It counts the number of devices on each mba (to see if bothering to  * search/seek is appropriate).  *  * During normal operation, the devices attached to the mba which wish  * to transfer are queued on the mh_act? links.  */
end_comment

begin_struct
struct|struct
name|mba_hd
block|{
name|short
name|mh_active
decl_stmt|;
comment|/* set if mba is active */
name|short
name|mh_ndrive
decl_stmt|;
comment|/* number of devices, to avoid seeks */
name|struct
name|mba_regs
modifier|*
name|mh_mba
decl_stmt|;
comment|/* virt addr of mba */
name|struct
name|mba_regs
modifier|*
name|mh_physmba
decl_stmt|;
comment|/* phys addr of mba */
name|struct
name|mba_device
modifier|*
name|mh_mbip
index|[
literal|8
index|]
decl_stmt|;
comment|/* what is attached to each dev */
name|struct
name|mba_device
modifier|*
name|mh_actf
decl_stmt|;
comment|/* head of queue to transfer */
name|struct
name|mba_device
modifier|*
name|mh_actl
decl_stmt|;
comment|/* tail of queue to transfer */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-device structure  * (one for each RM/RP disk, and one for each tape formatter).  *  * This structure is used by the device driver as its argument  * to the massbus driver, and by the massbus driver to locate  * the device driver for a particular massbus slot.  *  * The device drivers hang ready buffers on this structure,  * and the massbus driver will start i/o on the first such buffer  * when appropriate.  */
end_comment

begin_struct
struct|struct
name|mba_device
block|{
name|struct
name|mba_driver
modifier|*
name|mi_driver
decl_stmt|;
name|short
name|mi_unit
decl_stmt|;
comment|/* unit number to the system */
name|short
name|mi_mbanum
decl_stmt|;
comment|/* the mba it is on */
name|short
name|mi_drive
decl_stmt|;
comment|/* controller on mba */
name|short
name|mi_dk
decl_stmt|;
comment|/* driver number for iostat */
name|short
name|mi_alive
decl_stmt|;
comment|/* device exists */
name|short
name|mi_type
decl_stmt|;
comment|/* driver specific unit type */
name|struct
name|buf
name|mi_tab
decl_stmt|;
comment|/* head of queue for this device */
name|struct
name|mba_device
modifier|*
name|mi_forw
decl_stmt|;
comment|/* we could compute these every time, but hereby save time */
name|struct
name|mba_regs
modifier|*
name|mi_mba
decl_stmt|;
name|struct
name|mba_drv
modifier|*
name|mi_drv
decl_stmt|;
name|struct
name|mba_hd
modifier|*
name|mi_hd
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|b_bdone
value|b_bufsize
end_define

begin_comment
comment|/* redefinition for mi_tab XXX */
end_comment

begin_comment
comment|/*  * Tape formatter slaves are specified by  * the following information which is used  * at boot time to initialize the tape driver  * internal tables.  */
end_comment

begin_struct
struct|struct
name|mba_slave
block|{
name|struct
name|mba_driver
modifier|*
name|ms_driver
decl_stmt|;
name|short
name|ms_ctlr
decl_stmt|;
comment|/* which of several formatters */
name|short
name|ms_unit
decl_stmt|;
comment|/* which unit to system */
name|short
name|ms_slave
decl_stmt|;
comment|/* which slave to formatter */
name|short
name|ms_alive
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per device-type structure.  *  * Each massbus driver defines entries for a set of routines used  * by the massbus driver, as well as an array of types which are  * acceptable to it.  */
end_comment

begin_struct
struct|struct
name|mba_driver
block|{
name|int
function_decl|(
modifier|*
name|md_attach
function_decl|)
parameter_list|()
function_decl|;
comment|/* attach a device */
name|int
function_decl|(
modifier|*
name|md_slave
function_decl|)
parameter_list|()
function_decl|;
comment|/* attach a slave */
name|int
function_decl|(
modifier|*
name|md_ustart
function_decl|)
parameter_list|()
function_decl|;
comment|/* unit start routine */
name|int
function_decl|(
modifier|*
name|md_start
function_decl|)
parameter_list|()
function_decl|;
comment|/* setup a data transfer */
name|int
function_decl|(
modifier|*
name|md_dtint
function_decl|)
parameter_list|()
function_decl|;
comment|/* data transfer complete */
name|int
function_decl|(
modifier|*
name|md_ndint
function_decl|)
parameter_list|()
function_decl|;
comment|/* non-data transfer interrupt */
name|short
modifier|*
name|md_type
decl_stmt|;
comment|/* array of drive type codes */
name|char
modifier|*
name|md_dname
decl_stmt|,
modifier|*
name|md_sname
decl_stmt|;
comment|/* device, slave names */
name|struct
name|mba_device
modifier|*
modifier|*
name|md_info
decl_stmt|;
comment|/* backpointers to mbinit structs */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Possible return values from unit start routines.  */
end_comment

begin_define
define|#
directive|define
name|MBU_NEXT
value|0
end_define

begin_comment
comment|/* skip to next operation */
end_comment

begin_define
define|#
directive|define
name|MBU_BUSY
value|1
end_define

begin_comment
comment|/* dual port busy; wait for intr */
end_comment

begin_define
define|#
directive|define
name|MBU_STARTED
value|2
end_define

begin_comment
comment|/* non-data transfer started */
end_comment

begin_define
define|#
directive|define
name|MBU_DODATA
value|3
end_define

begin_comment
comment|/* data transfer ready; start mba */
end_comment

begin_comment
comment|/*  * Possible return values from data transfer interrupt handling routines  */
end_comment

begin_define
define|#
directive|define
name|MBD_DONE
value|0
end_define

begin_comment
comment|/* data transfer complete */
end_comment

begin_define
define|#
directive|define
name|MBD_RETRY
value|1
end_define

begin_comment
comment|/* error occurred, please retry */
end_comment

begin_define
define|#
directive|define
name|MBD_RESTARTED
value|2
end_define

begin_comment
comment|/* driver restarted i/o itself */
end_comment

begin_define
define|#
directive|define
name|MBD_REPOSITION
value|3
end_define

begin_comment
comment|/* driver started unit, not transfer */
end_comment

begin_comment
comment|/*  * Possible return values from non-data-transfer interrupt handling routines  */
end_comment

begin_define
define|#
directive|define
name|MBN_DONE
value|0
end_define

begin_comment
comment|/* non-data transfer complete */
end_comment

begin_define
define|#
directive|define
name|MBN_RETRY
value|1
end_define

begin_comment
comment|/* failed; retry the operation */
end_comment

begin_define
define|#
directive|define
name|MBN_SKIP
value|2
end_define

begin_comment
comment|/* don't do anything */
end_comment

begin_comment
comment|/*  * Clear attention status for specified device.  */
end_comment

begin_define
define|#
directive|define
name|mbclrattn
parameter_list|(
name|mi
parameter_list|)
value|((mi)->mi_mba->mba_drv[0].mbd_as = 1<< (mi)->mi_drive)
end_define

begin_comment
comment|/*  * Kernel definitions related to mba.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|int
name|nummba
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|NMBA
operator|>
literal|0
end_if

begin_decl_stmt
name|struct
name|mba_hd
name|mba_hd
index|[
name|NMBA
index|]
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern	Xmba0int(
end_extern

begin_operator
unit|)
operator|,
end_operator

begin_expr_stmt
name|Xmba1int
argument_list|()
operator|,
name|Xmba2int
argument_list|()
operator|,
name|Xmba3int
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mba_device
name|mbdinit
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mba_slave
name|mbsinit
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

