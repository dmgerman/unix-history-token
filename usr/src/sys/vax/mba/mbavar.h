begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	mbavar.h	4.7	81/02/19	*/
end_comment

begin_comment
comment|/*  * VAX Massbus adapter registers  */
end_comment

begin_struct
struct|struct
name|mba_regs
block|{
name|int
name|mba_csr
decl_stmt|;
comment|/* configuration register */
name|int
name|mba_cr
decl_stmt|;
comment|/* control register */
name|int
name|mba_sr
decl_stmt|;
comment|/* status register */
name|int
name|mba_var
decl_stmt|;
comment|/* virtual address register */
name|int
name|mba_bcr
decl_stmt|;
comment|/* byte count register */
name|int
name|mba_dr
decl_stmt|;
name|int
name|mba_pad1
index|[
literal|250
index|]
decl_stmt|;
struct|struct
name|mba_drv
block|{
comment|/* per drive registers */
name|int
name|mbd_cs1
decl_stmt|;
comment|/* control status */
name|int
name|mbd_ds
decl_stmt|;
comment|/* drive status */
name|int
name|mbd_er1
decl_stmt|;
comment|/* error register */
name|int
name|mbd_mr1
decl_stmt|;
comment|/* maintenance register */
name|int
name|mbd_as
decl_stmt|;
comment|/* attention status */
name|int
name|mbd_da
decl_stmt|;
comment|/* desired address (disks) */
define|#
directive|define
name|mbd_fc
value|mbd_da
comment|/* frame count (tapes) */
name|int
name|mbd_dt
decl_stmt|;
comment|/* drive type */
name|int
name|mbd_la
decl_stmt|;
comment|/* look ahead (disks) */
define|#
directive|define
name|mbd_ck
value|mbd_la
comment|/* ??? (tapes) */
name|int
name|mbd_sn
decl_stmt|;
comment|/* serial number */
name|int
name|mbd_of
decl_stmt|;
comment|/* ??? */
define|#
directive|define
name|mbd_tc
value|mbd_of
comment|/* ??? */
name|int
name|mbd_fill
index|[
literal|22
index|]
decl_stmt|;
block|}
name|mba_drv
index|[
literal|8
index|]
struct|;
name|struct
name|pte
name|mba_map
index|[
literal|256
index|]
decl_stmt|;
comment|/* io space virtual map */
name|int
name|mba_pad2
index|[
literal|256
operator|*
literal|5
index|]
decl_stmt|;
comment|/* to size of a nexus */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Bits in mba_cr  */
end_comment

begin_define
define|#
directive|define
name|MBAINIT
value|0x1
end_define

begin_comment
comment|/* init mba */
end_comment

begin_define
define|#
directive|define
name|MBAIE
value|0x4
end_define

begin_comment
comment|/* enable mba interrupts */
end_comment

begin_comment
comment|/*  * Bits in mba_sr  */
end_comment

begin_define
define|#
directive|define
name|MBS_DTBUSY
value|0x80000000
end_define

begin_comment
comment|/* data transfer busy */
end_comment

begin_define
define|#
directive|define
name|MBS_NRCONF
value|0x40000000
end_define

begin_comment
comment|/* no response confirmation */
end_comment

begin_define
define|#
directive|define
name|MBS_CRD
value|0x20000000
end_define

begin_comment
comment|/* corrected read data */
end_comment

begin_define
define|#
directive|define
name|MBS_CBHUNG
value|0x00800000
end_define

begin_comment
comment|/* control bus hung */
end_comment

begin_define
define|#
directive|define
name|MBS_PGE
value|0x00080000
end_define

begin_comment
comment|/* programming error */
end_comment

begin_define
define|#
directive|define
name|MBS_NED
value|0x00040000
end_define

begin_comment
comment|/* non-existant drive */
end_comment

begin_define
define|#
directive|define
name|MBS_MCPE
value|0x00020000
end_define

begin_comment
comment|/* massbus control parity error */
end_comment

begin_define
define|#
directive|define
name|MBS_ATTN
value|0x00010000
end_define

begin_comment
comment|/* attention from massbus */
end_comment

begin_define
define|#
directive|define
name|MBS_SPE
value|0x00004000
end_define

begin_comment
comment|/* silo parity error */
end_comment

begin_define
define|#
directive|define
name|MBS_DTCMP
value|0x00002000
end_define

begin_comment
comment|/* data transfer completed */
end_comment

begin_define
define|#
directive|define
name|MBS_DTABT
value|0x00001000
end_define

begin_comment
comment|/* data transfer aborted */
end_comment

begin_define
define|#
directive|define
name|MBS_DLT
value|0x00000800
end_define

begin_comment
comment|/* data late */
end_comment

begin_define
define|#
directive|define
name|MBS_WCKUP
value|0x00000400
end_define

begin_comment
comment|/* write check upper */
end_comment

begin_define
define|#
directive|define
name|MBS_WCKLWR
value|0x00000200
end_define

begin_comment
comment|/* write check lower */
end_comment

begin_define
define|#
directive|define
name|MBS_MXF
value|0x00000100
end_define

begin_comment
comment|/* miss transfer error */
end_comment

begin_define
define|#
directive|define
name|MBS_MBEXC
value|0x00000080
end_define

begin_comment
comment|/* massbus exception */
end_comment

begin_define
define|#
directive|define
name|MBS_MDPE
value|0x00000040
end_define

begin_comment
comment|/* massbus data parity error */
end_comment

begin_define
define|#
directive|define
name|MBS_MAPPE
value|0x00000020
end_define

begin_comment
comment|/* page frame map parity error */
end_comment

begin_define
define|#
directive|define
name|MBS_INVMAP
value|0x00000010
end_define

begin_comment
comment|/* invalid map */
end_comment

begin_define
define|#
directive|define
name|MBS_ERRCONF
value|0x00000008
end_define

begin_comment
comment|/* error confirmation */
end_comment

begin_define
define|#
directive|define
name|MBS_RDS
value|0x00000004
end_define

begin_comment
comment|/* read data substitute */
end_comment

begin_define
define|#
directive|define
name|MBS_ISTIMO
value|0x00000002
end_define

begin_comment
comment|/* interface sequence timeout */
end_comment

begin_define
define|#
directive|define
name|MBS_RDTIMO
value|0x00000001
end_define

begin_comment
comment|/* read data timeout */
end_comment

begin_define
define|#
directive|define
name|MBAEBITS
value|(~(MBS_DTBUSY|MBS_CRD|MBS_ATTN|MBS_DTCMP))
end_define

begin_comment
comment|/*  * Commands for mbd_cs1  */
end_comment

begin_define
define|#
directive|define
name|MBD_WCOM
value|0x30
end_define

begin_define
define|#
directive|define
name|MBD_RCOM
value|0x38
end_define

begin_define
define|#
directive|define
name|MBD_GO
value|0x1
end_define

begin_comment
comment|/*  * Bits in mbd_ds.  */
end_comment

begin_define
define|#
directive|define
name|MBD_DRY
value|0x80
end_define

begin_comment
comment|/* drive ready */
end_comment

begin_define
define|#
directive|define
name|MBD_MOL
value|0x1000
end_define

begin_comment
comment|/* medium on line */
end_comment

begin_define
define|#
directive|define
name|MBD_DPR
value|0x100
end_define

begin_comment
comment|/* drive present */
end_comment

begin_define
define|#
directive|define
name|MBD_ERR
value|0x4000
end_define

begin_comment
comment|/* error in drive */
end_comment

begin_comment
comment|/*  * Bits in mbd_dt  */
end_comment

begin_define
define|#
directive|define
name|MBDT_NSA
value|0x8000
end_define

begin_comment
comment|/* not sector addressible */
end_comment

begin_define
define|#
directive|define
name|MBDT_TAP
value|0x4000
end_define

begin_comment
comment|/* is a tape */
end_comment

begin_define
define|#
directive|define
name|MBDT_MOH
value|0x2000
end_define

begin_comment
comment|/* moving head */
end_comment

begin_define
define|#
directive|define
name|MBDT_7CH
value|0x1000
end_define

begin_comment
comment|/* 7 channel */
end_comment

begin_define
define|#
directive|define
name|MBDT_DRQ
value|0x800
end_define

begin_comment
comment|/* drive request required */
end_comment

begin_define
define|#
directive|define
name|MBDT_SPR
value|0x400
end_define

begin_comment
comment|/* slave present */
end_comment

begin_define
define|#
directive|define
name|MBDT_TYPE
value|0x1ff
end_define

begin_define
define|#
directive|define
name|MBDT_MASK
value|(MBDT_NSA|MBDT_TAP|MBDT_TYPE)
end_define

begin_comment
comment|/* type codes for disk drives */
end_comment

begin_define
define|#
directive|define
name|MBDT_RP04
value|020
end_define

begin_define
define|#
directive|define
name|MBDT_RP05
value|021
end_define

begin_define
define|#
directive|define
name|MBDT_RP06
value|022
end_define

begin_define
define|#
directive|define
name|MBDT_RP07
value|042
end_define

begin_define
define|#
directive|define
name|MBDT_RM03
value|024
end_define

begin_define
define|#
directive|define
name|MBDT_RM05
value|027
end_define

begin_define
define|#
directive|define
name|MBDT_RM80
value|026
end_define

begin_comment
comment|/* type codes for tape drives */
end_comment

begin_define
define|#
directive|define
name|MBDT_TM03
value|050
end_define

begin_define
define|#
directive|define
name|MBDT_TE16
value|051
end_define

begin_define
define|#
directive|define
name|MBDT_TU45
value|052
end_define

begin_define
define|#
directive|define
name|MBDT_TU77
value|054
end_define

begin_define
define|#
directive|define
name|MBDT_TU78
value|0140
end_define

begin_comment
comment|/* can't handle these (yet) */
end_comment

begin_comment
comment|/*  * Each driver has an array of pointers to these structures, one for  * each device it is willing to handle.  At bootstrap time, the  * driver tables are filled in;  */
end_comment

begin_struct
struct|struct
name|mba_info
block|{
name|struct
name|mba_driver
modifier|*
name|mi_driver
decl_stmt|;
name|short
name|mi_name
decl_stmt|;
comment|/* two character generic name */
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
name|mi_slave
decl_stmt|;
comment|/* slave to controller (TM03/TU16) */
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
name|mba_info
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

begin_comment
comment|/*  * The initialization routine uses the information in the mbinit table  * to initialize the drive type routines in the drivers and the  * mbahd array summarizing which devices are hooked to which massbus slots.  */
end_comment

begin_struct
struct|struct
name|mba_hd
block|{
name|short
name|mh_active
decl_stmt|;
name|short
name|mh_flags
decl_stmt|;
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
name|mba_info
modifier|*
name|mh_mbip
index|[
literal|8
index|]
decl_stmt|;
comment|/* what is attached */
name|struct
name|mba_info
modifier|*
name|mh_actf
decl_stmt|;
comment|/* head of queue to transfer */
name|struct
name|mba_info
modifier|*
name|mh_actl
decl_stmt|;
comment|/* tail of queue to transfer */
block|}
name|mba_hd
index|[
literal|4
index|]
struct|;
end_struct

begin_comment
comment|/*  * Values for flags; normally MH_NOSEEK will be set when there is  * only a single drive on an massbus.  */
end_comment

begin_define
define|#
directive|define
name|MH_NOSEEK
value|1
end_define

begin_define
define|#
directive|define
name|MH_NOSEARCH
value|2
end_define

begin_comment
comment|/*  * Each massbus driver defines entries for a set of routines  * as well as an array of types which are acceptable to it.  */
end_comment

begin_struct
struct|struct
name|mba_driver
block|{
name|int
function_decl|(
modifier|*
name|md_dkinit
function_decl|)
parameter_list|()
function_decl|;
comment|/* setup dk info (mspw) */
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
name|struct
name|mba_info
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

begin_comment
comment|/*  * Clear attention status for specified drive.  */
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
name|mba_info
name|mbinit
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* blanks for filling mba_info */
end_comment

begin_decl_stmt
name|int
name|nummba
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

