begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vbavar.h	1.4	86/12/15	*/
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
comment|/*  * VERSAbus device address space is mapped by VMEMmap  * into virtual address vmem[][].  */
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
name|caddr_t
name|vmem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vba device addr space */
end_comment

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

