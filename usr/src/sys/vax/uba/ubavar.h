begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	ubavar.h	4.7	%G%	*/
end_comment

begin_comment
comment|/*  * UNIBUS adaptor  */
end_comment

begin_if
if|#
directive|if
name|VAX750
end_if

begin_define
define|#
directive|define
name|UBA750
value|((struct uba_regs *)0xf30000)
end_define

begin_define
define|#
directive|define
name|UMEM750
value|((u_short *)0xfc0000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|VAX780
end_if

begin_comment
comment|/*  * UBA registers  */
end_comment

begin_struct
struct|struct
name|uba_regs
block|{
name|int
name|uba_cnfgr
decl_stmt|;
name|int
name|uba_cr
decl_stmt|;
name|int
name|uba_sr
decl_stmt|;
name|int
name|uba_dcr
decl_stmt|;
name|int
name|uba_fmer
decl_stmt|;
name|int
name|uba_fubar
decl_stmt|;
name|int
name|pad1
index|[
literal|2
index|]
decl_stmt|;
name|int
name|uba_brsvr
index|[
literal|4
index|]
decl_stmt|;
name|int
name|uba_brrvr
index|[
literal|4
index|]
decl_stmt|;
name|int
name|uba_dpr
index|[
literal|16
index|]
decl_stmt|;
name|int
name|pad2
index|[
literal|480
index|]
decl_stmt|;
name|struct
name|pte
name|uba_map
index|[
literal|496
index|]
decl_stmt|;
name|int
name|pad3
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* UBA control register, UBACR */
end_comment

begin_define
define|#
directive|define
name|UBA_MRD16
value|0x40000000
end_define

begin_comment
comment|/* map reg disable bit 4 */
end_comment

begin_define
define|#
directive|define
name|UBA_MRD8
value|0x20000000
end_define

begin_comment
comment|/* map reg disable bit 3 */
end_comment

begin_define
define|#
directive|define
name|UBA_MRD4
value|0x10000000
end_define

begin_comment
comment|/* map reg disable bit 2 */
end_comment

begin_define
define|#
directive|define
name|UBA_MRD2
value|0x08000000
end_define

begin_comment
comment|/* map reg disable bit 1 */
end_comment

begin_define
define|#
directive|define
name|UBA_MRD1
value|0x04000000
end_define

begin_comment
comment|/* map reg disable bit 0 */
end_comment

begin_define
define|#
directive|define
name|UBA_IFS
value|0x00000040
end_define

begin_comment
comment|/* interrupt field switch */
end_comment

begin_define
define|#
directive|define
name|UBA_BRIE
value|0x00000020
end_define

begin_comment
comment|/* BR interrupt enable */
end_comment

begin_define
define|#
directive|define
name|UBA_USEFIE
value|0x00000010
end_define

begin_comment
comment|/* UNIBUS to SBI error field IE */
end_comment

begin_define
define|#
directive|define
name|UBA_SUEFIE
value|0x00000008
end_define

begin_comment
comment|/* SBI to UNIBUS error field IE */
end_comment

begin_define
define|#
directive|define
name|UBA_CNFIE
value|0x00000004
end_define

begin_comment
comment|/* configuration IE */
end_comment

begin_define
define|#
directive|define
name|UBA_UPF
value|0x00000002
end_define

begin_comment
comment|/* UNIBUS power fail */
end_comment

begin_define
define|#
directive|define
name|UBA_ADINIT
value|0x00000001
end_define

begin_comment
comment|/* adapter init */
end_comment

begin_comment
comment|/* UBA status register, UASR */
end_comment

begin_define
define|#
directive|define
name|UBA_BR7FULL
value|0x08000000
end_define

begin_comment
comment|/* BR7 receive vector reg full */
end_comment

begin_define
define|#
directive|define
name|UBA_BR6FULL
value|0x04000000
end_define

begin_comment
comment|/* BR6 receive vector reg full */
end_comment

begin_define
define|#
directive|define
name|UBA_BR5FULL
value|0x02000000
end_define

begin_comment
comment|/* BR5 receive vector reg full */
end_comment

begin_define
define|#
directive|define
name|UBA_BR4FULL
value|0x01000000
end_define

begin_comment
comment|/* BR4 receive vector reg full */
end_comment

begin_define
define|#
directive|define
name|UBA_RDTO
value|0x00000400
end_define

begin_comment
comment|/* UNIBUS to SBI read data timeout */
end_comment

begin_define
define|#
directive|define
name|UBA_RDS
value|0x00000200
end_define

begin_comment
comment|/* read data substitute */
end_comment

begin_define
define|#
directive|define
name|UBA_CRD
value|0x00000100
end_define

begin_comment
comment|/* corrected read data */
end_comment

begin_define
define|#
directive|define
name|UBA_CXTER
value|0x00000080
end_define

begin_comment
comment|/* command transmit error */
end_comment

begin_define
define|#
directive|define
name|UBA_CXTMO
value|0x00000040
end_define

begin_comment
comment|/* command transmit timeout */
end_comment

begin_define
define|#
directive|define
name|UBA_DPPE
value|0x00000020
end_define

begin_comment
comment|/* data path parity error */
end_comment

begin_define
define|#
directive|define
name|UBA_IVMR
value|0x00000010
end_define

begin_comment
comment|/* invalid map register */
end_comment

begin_define
define|#
directive|define
name|UBA_MRPF
value|0x00000008
end_define

begin_comment
comment|/* map register parity failure */
end_comment

begin_define
define|#
directive|define
name|UBA_LEB
value|0x00000004
end_define

begin_comment
comment|/* lost error */
end_comment

begin_define
define|#
directive|define
name|UBA_UBSTO
value|0x00000002
end_define

begin_comment
comment|/* UNIBUS select timeout */
end_comment

begin_define
define|#
directive|define
name|UBA_UBSSTO
value|0x00000001
end_define

begin_comment
comment|/* UNIBUS slave sync timeout */
end_comment

begin_comment
comment|/* BR receive vector register, BRRVR */
end_comment

begin_define
define|#
directive|define
name|UBA_AIRI
value|0x80000000
end_define

begin_comment
comment|/* adapter interrupt request */
end_comment

begin_define
define|#
directive|define
name|UBA_DIV
value|0x0000ffff
end_define

begin_comment
comment|/* device interrupt vector field */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* data path register, DPR */
end_comment

begin_if
if|#
directive|if
name|VAX780
end_if

begin_define
define|#
directive|define
name|UBA_BNE
value|0x80000000
end_define

begin_comment
comment|/* buffer not empty - purge */
end_comment

begin_define
define|#
directive|define
name|UBA_BTE
value|0x40000000
end_define

begin_comment
comment|/* buffer transfer error */
end_comment

begin_define
define|#
directive|define
name|UBA_DPF
value|0x20000000
end_define

begin_comment
comment|/* DP function (RO) */
end_comment

begin_define
define|#
directive|define
name|UBA_BS
value|0x007f0000
end_define

begin_comment
comment|/* buffer state field */
end_comment

begin_define
define|#
directive|define
name|UBA_BUBA
value|0x0000ffff
end_define

begin_comment
comment|/* buffered UNIBUS address */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|VAX750
end_if

begin_define
define|#
directive|define
name|UBA_ERROR
value|0x20000000
end_define

begin_define
define|#
directive|define
name|UBA_NXM
value|0x40000000
end_define

begin_define
define|#
directive|define
name|UBA_UCE
value|0x20000000
end_define

begin_define
define|#
directive|define
name|UBA_PURGE
value|0x00000001
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* map register, MR */
end_comment

begin_define
define|#
directive|define
name|UBA_MRV
value|0x80000000
end_define

begin_comment
comment|/* map register valid */
end_comment

begin_define
define|#
directive|define
name|UBA_BO
value|0x02000000
end_define

begin_comment
comment|/* byte offset bit */
end_comment

begin_define
define|#
directive|define
name|UBA_DPDB
value|0x01e00000
end_define

begin_comment
comment|/* data path designator field */
end_comment

begin_define
define|#
directive|define
name|UBA_SBIPFN
value|0x000fffff
end_define

begin_comment
comment|/* SBI page address field */
end_comment

begin_define
define|#
directive|define
name|UBA_DPSHIFT
value|21
end_define

begin_comment
comment|/* shift to data path designator */
end_comment

begin_comment
comment|/*  * Each UNIBUS mass storage controller has uba_minfo structure,  * and a uba_dinfo structure (as below) for each attached drive.  */
end_comment

begin_struct
struct|struct
name|uba_minfo
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
name|int
name|um_cmd
decl_stmt|;
comment|/* communication to dgo() */
name|int
name|um_ubinfo
decl_stmt|;
comment|/* save unibus registers, etc */
name|struct
name|buf
name|um_tab
decl_stmt|;
comment|/* queue for this controller */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Each UNIBUS device has a uba_dinfo structure.  * If a controller has many drives attached, then there will  * be several uba_dinfo structures associated with a single uba_minfo  * structure.  */
end_comment

begin_struct
struct|struct
name|uba_dinfo
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
name|short
name|ui_flags
decl_stmt|;
comment|/* param to device init. */
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
name|struct
name|uba_dinfo
modifier|*
name|ui_forw
decl_stmt|;
comment|/* if the driver isn't also a controller, this is the controller it is on */
name|struct
name|uba_minfo
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

begin_define
define|#
directive|define
name|NUBA780
value|4
end_define

begin_define
define|#
directive|define
name|NUBA750
value|1
end_define

begin_if
if|#
directive|if
name|VAX780
end_if

begin_define
define|#
directive|define
name|MAXNUBA
value|4
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXNUBA
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This structure exists per-uba.  *  * N.B.: THE SIZE AND SHAPE OF THIS STRUCTURE IS KNOWN IN uba.m.  */
end_comment

begin_struct
struct|struct
name|uba_hd
block|{
name|int
name|uh_active
decl_stmt|;
comment|/* bit per device transferring */
name|struct
name|uba_regs
modifier|*
name|uh_uba
decl_stmt|;
comment|/* virt addr of uba */
name|struct
name|uba_regs
modifier|*
name|uh_physuba
decl_stmt|;
comment|/* phys addr of uba */
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
name|uba_dinfo
modifier|*
name|uh_actf
decl_stmt|;
comment|/* head of queue to transfer */
name|struct
name|uba_dinfo
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
comment|/* number of 0 vectors */
define|#
directive|define
name|UAMSIZ
value|50
name|struct
name|map
modifier|*
name|uh_map
decl_stmt|;
block|}
name|uba_hd
index|[
name|MAXNUBA
index|]
struct|;
end_struct

begin_comment
comment|/*  * Each UNIBUS driver defines entries for a set of routines  * as well as an array of types which are acceptable to it.  */
end_comment

begin_struct
struct|struct
name|uba_driver
block|{
name|int
function_decl|(
modifier|*
name|ud_cntrlr
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
comment|/* see if a slave is there; init */
name|int
function_decl|(
modifier|*
name|ud_dgo
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine to stuff driver regs */
comment|/* dgo is called back by the unibus (usu ubaalloc), when the bus is ready */
name|short
name|ud_needexcl
decl_stmt|;
comment|/* need exclusive use of uba (rk07) */
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
name|uba_dinfo
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
name|uba_minfo
modifier|*
modifier|*
name|ud_minfo
decl_stmt|;
comment|/* backpointers to ubminit structs */
block|}
struct|;
end_struct

begin_comment
comment|/*  * unibus maps  */
end_comment

begin_define
define|#
directive|define
name|NBDP780
value|15
end_define

begin_define
define|#
directive|define
name|NBDP750
value|3
end_define

begin_define
define|#
directive|define
name|MAXNBDP
value|15
end_define

begin_define
define|#
directive|define
name|NUBMREG
value|496
end_define

begin_comment
comment|/*  * flags to uba map/bdp allocation routines  */
end_comment

begin_define
define|#
directive|define
name|UBA_NEEDBDP
value|1
end_define

begin_comment
comment|/* transfer needs a bdp */
end_comment

begin_define
define|#
directive|define
name|UBA_CANTWAIT
value|2
end_define

begin_comment
comment|/* don't block me */
end_comment

begin_define
define|#
directive|define
name|UBA_NEED16
value|3
end_define

begin_comment
comment|/* need 16 bit addresses only */
end_comment

begin_comment
comment|/*  * UNIBUS related kernel variables  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|uba_minfo
name|ubminit
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|uba_dinfo
name|ubdinit
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|numuba
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pte
name|UMEMmap
index|[
name|MAXNUBA
index|]
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|umem
index|[
name|MAXNUBA
index|]
index|[
literal|16
operator|*
name|NBPG
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|UNIvec
index|[]
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|VAX780
end_if

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
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

