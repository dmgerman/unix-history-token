begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)ubavar.h	7.4 (Berkeley) 5/14/88  */
end_comment

begin_comment
comment|/*  * This file contains definitions related to the kernel structures  * for dealing with the unibus adapters.  *  * Each uba has a uba_hd structure.  * Each unibus controller which is not a device has a uba_ctlr structure.  * Each unibus device has a uba_device structure.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * Per-uba structure.  *  * This structure holds the interrupt vector for the uba,  * and its address in physical and virtual space.  At boot time  * we determine the devices attached to the uba's and their  * interrupt vectors, filling in uh_vec.  We free the map  * register and bdp resources of the uba into the structures  * defined here.  *  * During normal operation, resources are allocated and returned  * to the structures here.  We watch the number of passive releases  * on each uba, and if the number is excessive may reset the uba.  *   * When uba resources are needed and not available, or if a device  * which can tolerate no other uba activity (rk07) gets on the bus,  * then device drivers may have to wait to get to the bus and are  * queued here.  It is also possible for processes to block in  * the unibus driver in resource wait (mrwant, bdpwant); these  * wait states are also recorded here.  */
end_comment

begin_struct
struct|struct
name|uba_hd
block|{
name|int
name|uh_type
decl_stmt|;
comment|/* type of adaptor */
name|struct
name|uba_regs
modifier|*
name|uh_uba
decl_stmt|;
comment|/* virt addr of uba adaptor regs */
name|struct
name|uba_regs
modifier|*
name|uh_physuba
decl_stmt|;
comment|/* phys addr of uba adaptor regs */
name|struct
name|pte
modifier|*
name|uh_mr
decl_stmt|;
comment|/* start of page map */
name|int
name|uh_memsize
decl_stmt|;
comment|/* size of uba memory, pages */
name|caddr_t
name|uh_mem
decl_stmt|;
comment|/* start of uba memory address space */
name|caddr_t
name|uh_iopage
decl_stmt|;
comment|/* start of uba io page */
name|int
function_decl|(
modifier|*
modifier|*
name|uh_vec
function_decl|)
parameter_list|()
function_decl|;
comment|/* interrupt vector */
name|struct
name|uba_device
modifier|*
name|uh_actf
decl_stmt|;
comment|/* head of queue to transfer */
name|struct
name|uba_device
modifier|*
name|uh_actl
decl_stmt|;
comment|/* tail of queue to transfer */
name|short
name|uh_mrwant
decl_stmt|;
comment|/* someone is waiting for map reg */
name|short
name|uh_bdpwant
decl_stmt|;
comment|/* someone awaits bdp's */
name|int
name|uh_bdpfree
decl_stmt|;
comment|/* free bdp's */
name|int
name|uh_hangcnt
decl_stmt|;
comment|/* number of ticks hung */
name|int
name|uh_zvcnt
decl_stmt|;
comment|/* number of recent 0 vectors */
name|long
name|uh_zvtime
decl_stmt|;
comment|/* time over which zvcnt accumulated */
name|int
name|uh_zvtotal
decl_stmt|;
comment|/* total number of 0 vectors */
name|int
name|uh_errcnt
decl_stmt|;
comment|/* number of errors */
name|int
name|uh_lastiv
decl_stmt|;
comment|/* last free interrupt vector */
name|short
name|uh_users
decl_stmt|;
comment|/* transient bdp use count */
name|short
name|uh_xclu
decl_stmt|;
comment|/* an rk07 is using this uba! */
name|int
name|uh_lastmem
decl_stmt|;
comment|/* limit of any unibus memory */
define|#
directive|define
name|UAMSIZ
value|100
name|struct
name|map
modifier|*
name|uh_map
decl_stmt|;
comment|/* buffered data path regs free */
block|}
struct|;
end_struct

begin_comment
comment|/* given a pointer to uba_regs, find DWBUA registers */
end_comment

begin_comment
comment|/* this should be replaced with a union in uba_hd */
end_comment

begin_define
define|#
directive|define
name|BUA
parameter_list|(
name|uba
parameter_list|)
value|((struct dwbua_regs *)(uba))
end_define

begin_comment
comment|/*  * Per-controller structure.  * (E.g. one for each disk and tape controller, and other things  * which use and release buffered data paths.)  *  * If a controller has devices attached, then there are  * cross-referenced uba_drive structures.  * This structure is the one which is queued in unibus resource wait,  * and saves the information about unibus resources which are used.  * The queue of devices waiting to transfer is also attached here.  */
end_comment

begin_struct
struct|struct
name|uba_ctlr
block|{
name|struct
name|uba_driver
modifier|*
name|um_driver
decl_stmt|;
name|short
name|um_ctlr
decl_stmt|;
comment|/* controller index in driver */
name|short
name|um_ubanum
decl_stmt|;
comment|/* the uba it is on */
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
name|uba_hd
modifier|*
name|um_hd
decl_stmt|;
comment|/* the driver saves the prototype command here for use in its go routine */
name|int
name|um_cmd
decl_stmt|;
comment|/* communication to dgo() */
name|int
name|um_ubinfo
decl_stmt|;
comment|/* save unibus registers, etc */
name|int
name|um_bdp
decl_stmt|;
comment|/* for controllers that hang on to bdp's */
name|struct
name|buf
name|um_tab
decl_stmt|;
comment|/* queue of devices for this controller */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per ``device'' structure.  * (A controller has devices or uses and releases buffered data paths).  * (Everything else is a ``device''.)  *  * If a controller has many drives attached, then there will  * be several uba_device structures associated with a single uba_ctlr  * structure.  *  * This structure contains all the information necessary to run  * a unibus device such as a dz or a dh.  It also contains information  * for slaves of unibus controllers as to which device on the slave  * this is.  A flags field here can also be given in the system specification  * and is used to tell which dz lines are hard wired or other device  * specific parameters.  */
end_comment

begin_struct
struct|struct
name|uba_device
block|{
name|struct
name|uba_driver
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
name|ui_ubanum
decl_stmt|;
comment|/* the uba it is on */
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
name|int
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
name|uba_device
modifier|*
name|ui_forw
decl_stmt|;
comment|/* if the device is connected to a controller, this is the controller */
name|struct
name|uba_ctlr
modifier|*
name|ui_mi
decl_stmt|;
name|struct
name|uba_hd
modifier|*
name|ui_hd
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-driver structure.  *  * Each unibus driver defines entries for a set of routines  * as well as an array of types which are acceptable to it.  * These are used at boot time by the configuration program.  */
end_comment

begin_struct
struct|struct
name|uba_driver
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
name|u_short
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
name|uba_device
modifier|*
modifier|*
name|ud_dinfo
decl_stmt|;
comment|/* backpointers to ubdinit structs */
name|char
modifier|*
name|ud_mname
decl_stmt|;
comment|/* name of a controller */
name|struct
name|uba_ctlr
modifier|*
modifier|*
name|ud_minfo
decl_stmt|;
comment|/* backpointers to ubminit structs */
name|short
name|ud_xclu
decl_stmt|;
comment|/* want exclusive use of bdp's */
name|short
name|ud_keepbdp
decl_stmt|;
comment|/* hang on to bdp's once allocated */
name|int
function_decl|(
modifier|*
name|ud_ubamem
function_decl|)
parameter_list|()
function_decl|;
comment|/* see if dedicated memory is present */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Flags to UBA map/bdp allocation routines  */
end_comment

begin_define
define|#
directive|define
name|UBA_NEEDBDP
value|0x01
end_define

begin_comment
comment|/* transfer needs a bdp */
end_comment

begin_define
define|#
directive|define
name|UBA_CANTWAIT
value|0x02
end_define

begin_comment
comment|/* don't block me */
end_comment

begin_define
define|#
directive|define
name|UBA_NEED16
value|0x04
end_define

begin_comment
comment|/* need 16 bit addresses only */
end_comment

begin_define
define|#
directive|define
name|UBA_HAVEBDP
value|0x08
end_define

begin_comment
comment|/* use bdp specified in high bits */
end_comment

begin_comment
comment|/*  * Macros to bust return word from map allocation routines.  */
end_comment

begin_define
define|#
directive|define
name|UBAI_BDP
parameter_list|(
name|i
parameter_list|)
value|((int)(((unsigned)(i))>>28))
end_define

begin_define
define|#
directive|define
name|UBAI_NMR
parameter_list|(
name|i
parameter_list|)
value|((int)((i)>>18)&0x3ff)
end_define

begin_define
define|#
directive|define
name|UBAI_MR
parameter_list|(
name|i
parameter_list|)
value|((int)((i)>>9)&0x1ff)
end_define

begin_define
define|#
directive|define
name|UBAI_BOFF
parameter_list|(
name|i
parameter_list|)
value|((int)((i)&0x1ff))
end_define

begin_define
define|#
directive|define
name|UBAI_ADDR
parameter_list|(
name|i
parameter_list|)
value|((int)((i)&0x3ffff))
end_define

begin_comment
comment|/* uba addr (boff+mr) */
end_comment

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

begin_define
define|#
directive|define
name|ubago
parameter_list|(
name|ui
parameter_list|)
value|ubaqueue(ui, 0)
end_define

begin_comment
comment|/*  * UBA related kernel variables  */
end_comment

begin_decl_stmt
name|int
name|numuba
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of uba's */
end_comment

begin_decl_stmt
name|struct
name|uba_hd
name|uba_hd
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Ubminit and ubdinit initialize the mass storage controller and  * device tables specifying possible devices.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|uba_ctlr
name|ubminit
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|uba_device
name|ubdinit
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * UNIBUS device address space is mapped by UMEMmap  * into virtual address umem[][].  * The IO page is mapped to the last 8K of each.  * This should be enlarged for the Q22 bus.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|pte
name|UMEMmap
index|[]
index|[
literal|512
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* uba device addr pte's */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|umem
index|[]
index|[
literal|512
operator|*
name|NBPG
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* uba device addr space */
end_comment

begin_comment
comment|/*  * Since some VAXen vector their unibus interrupts  * just adjacent to the system control block, we must  * allocate space there when running on ``any'' cpu.  This space is  * used for the vectors for all ubas.  */
end_comment

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|UNIvec
index|[]
index|[
literal|128
index|]
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* unibus vec for ubas */
end_comment

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|eUNIvec
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* end of unibus vec */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VAX780
argument_list|)
operator|||
name|defined
argument_list|(
name|VAX8600
argument_list|)
end_if

begin_comment
comment|/*  * On DW780's, we must set the scb vectors for the nexus of the  * UNIbus adaptors to vector to locore unibus adaptor interrupt dispatchers  * which make 780's look like the other VAXen.  */
end_comment

begin_extern
extern|extern	Xua0int(
end_extern

begin_operator
unit|)
operator|,
end_operator

begin_expr_stmt
name|Xua1int
argument_list|()
operator|,
name|Xua2int
argument_list|()
operator|,
name|Xua3int
argument_list|()
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
endif|VAX780
end_endif

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

