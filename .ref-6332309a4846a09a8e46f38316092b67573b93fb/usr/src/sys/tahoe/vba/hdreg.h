begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Include file for HCX Disk Controller (HDC).  *  *	@(#)hdreg.h	7.2 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|HDC_READ
value|0
end_define

begin_define
define|#
directive|define
name|HDC_WRITE
value|1
end_define

begin_define
define|#
directive|define
name|HDC_MAXBUS
value|2
end_define

begin_comment
comment|/* max# buses */
end_comment

begin_define
define|#
directive|define
name|HDC_MAXCTLR
value|21
end_define

begin_comment
comment|/* max# hdc controllers per bus */
end_comment

begin_define
define|#
directive|define
name|HDC_MAXDRIVE
value|4
end_define

begin_comment
comment|/* max# drives per hdc controller */
end_comment

begin_define
define|#
directive|define
name|HDC_UNIT
parameter_list|(
name|x
parameter_list|)
value|(minor(x)>> 3)
end_define

begin_comment
comment|/* the hdc unit number (0-31) */
end_comment

begin_define
define|#
directive|define
name|HDC_PARTITION
parameter_list|(
name|x
parameter_list|)
value|(minor(x)&0x07)
end_define

begin_comment
comment|/* the hdc partition number (0-7) */
end_comment

begin_define
define|#
directive|define
name|HDC_DEFPART
value|GB_MAXPART-1
end_define

begin_comment
comment|/* partition# of def and diag cyls */
end_comment

begin_define
define|#
directive|define
name|HDC_SPB
value|2
end_define

begin_comment
comment|/* sectors per block for hdc's */
end_comment

begin_define
define|#
directive|define
name|HDC_MID
value|HID_HDC
end_define

begin_comment
comment|/* module id code for hdc's */
end_comment

begin_define
define|#
directive|define
name|HDC_REMOVABLE
value|80
end_define

begin_comment
comment|/* lowest model# for removable disks */
end_comment

begin_define
define|#
directive|define
name|HDC_PHIO_SIZE
value|256
end_define

begin_comment
comment|/* lword size of physical io buffer */
end_comment

begin_define
define|#
directive|define
name|HDC_VDATA_SIZE
value|16
end_define

begin_comment
comment|/* vendor data size (long words) */
end_comment

begin_define
define|#
directive|define
name|HDC_XSTAT_SIZE
value|128
end_define

begin_comment
comment|/* size of extended status (lwords) */
end_comment

begin_define
define|#
directive|define
name|HDC_MAXCHAIN
value|33
end_define

begin_comment
comment|/* maximum number of data chains */
end_comment

begin_define
define|#
directive|define
name|HDC_MAXBC
value|64*1024
end_define

begin_comment
comment|/* maximum byte count per data chain */
end_comment

begin_define
define|#
directive|define
name|HDC_MAXMCBS
value|32
end_define

begin_comment
comment|/* max# mcb's the hdc can handle */
end_comment

begin_define
define|#
directive|define
name|HDC_MAXFLAWS
value|8000
end_define

begin_comment
comment|/* max number of flaws per hdc disk */
end_comment

begin_define
define|#
directive|define
name|HDC_REGISTER
parameter_list|(
name|x
parameter_list|)
value|(hc->registers->x)
end_define

begin_comment
comment|/* io to an hdc register */
end_comment

begin_define
define|#
directive|define
name|HDC_DUMPSIZE
value|HDC_MAXBC/DEV_BSIZE*HDC_MAXCHAIN
end_define

begin_comment
comment|/* number of blocks per dump record */
end_comment

begin_comment
comment|/*  * The following buf structure defines are used by the hdc handler.  * These are required since the handler initiates strategy calls;  * these calls require more function codes than just read/write,  * and they like to directly specify the cyl/head/sector.  * Note that b_upte and B_NOT1K are never used by the handler.  */
end_comment

begin_define
define|#
directive|define
name|B_LOCALIO
value|B_NOT1K
end_define

begin_define
define|#
directive|define
name|b_hdccommand
value|b_upte[0]
end_define

begin_define
define|#
directive|define
name|b_cyl
value|b_upte[1]
end_define

begin_define
define|#
directive|define
name|b_head
value|b_upte[2]
end_define

begin_define
define|#
directive|define
name|b_sector
value|b_upte[3]
end_define

begin_comment
comment|/*  * These are the 4 hdc i/o register addresses.  *  * Writing to "master_mcb_reg" tells the hdc controller where the master  * mcb is and initiates hdc operation. The hdc then reads the master mcb  * and all new mcb's in the active mcb queue.  *  * Writing to "module_id_reg" causes the hdc to return the hdc's module id  * word in the location specified by the address written into the register.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|master_mcb_reg
decl_stmt|;
comment|/* set the master mcb address */
name|unsigned
name|long
name|module_id_reg
decl_stmt|;
comment|/* returns hdc's module id (hdc_mid) */
name|unsigned
name|long
name|soft_reset_reg
decl_stmt|;
comment|/* a write here shuts down the hdc */
name|unsigned
name|long
name|hard_reset_reg
decl_stmt|;
comment|/* send a system reset to the hdc */
block|}
name|hdc_regs_type
typedef|;
end_typedef

begin_comment
comment|/*  * Definition for the module id returned by the hdc when "module_id_reg"  * is written to. The format is defined by the hdc microcode.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|module_id
decl_stmt|;
comment|/* module id; hdc's return HDC_MID */
name|unsigned
name|char
name|reserved
decl_stmt|;
name|unsigned
name|char
name|code_rev
decl_stmt|;
comment|/* micro-code rev#; FF= not loaded */
name|unsigned
name|char
name|fit
decl_stmt|;
comment|/* FIT test result; FF= no error */
block|}
name|hdc_mid_type
typedef|;
end_typedef

begin_comment
comment|/*  * This structure defines the mcb's. A portion of this structure is  * used only by the software. The other portion is set up by software  * and sent to the hdc firmware to perform an operation; the order  * of this part of the mcb is determined by the controller firmware.  *  * "forw_mcb" and "back_mcb" form a doubly-linked list of mcb's.  *  * "context" is the software context word. The hdc firmware copies the  * the contents of this word to the master mcb whenever the mcb has been  * completed. Currently the virtual address of the mcb is saved here.  *  * "forw_phaddr" forms a linked list of mcbs. The addresses are physical  * since they are used by the hdc firmware.  *  * Bits in device control word #1 define the hdc command and  * control the operation of the hdc.  *  * Bits in device control word #2 define the disk sector address  * for the operation defined in dcw1.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|lwc
decl_stmt|;
comment|/* long word count& data chain bit */
name|long
name|ta
decl_stmt|;
comment|/* transfer address */
block|}
name|data_chain_type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LWC_DATA_CHAIN
value|0x80000000
end_define

begin_comment
comment|/* mask for data chain bit in lwc */
end_comment

begin_struct_decl
struct_decl|struct
name|mcb_struct
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|mcb_struct
name|mcb_type
typedef|;
end_typedef

begin_struct
struct|struct
name|mcb_struct
block|{
comment|/* this part used only by software */
name|mcb_type
modifier|*
name|forw_mcb
decl_stmt|;
comment|/* pointer to next mcb in chain */
name|mcb_type
modifier|*
name|back_mcb
decl_stmt|;
comment|/* pointer to previous mcb in chain */
name|struct
name|buf
modifier|*
name|buf_ptr
decl_stmt|;
comment|/* ptr to buf structure for this mcb */
name|long
name|mcb_phaddr
decl_stmt|;
comment|/* phaddr of hw's part of this mcb */
comment|/* this part is sent to the hdc hw */
name|unsigned
name|long
name|forw_phaddr
decl_stmt|;
comment|/* phys address of next mcb */
name|unsigned
name|priority
range|:
literal|8
decl_stmt|;
comment|/* device control word #1 */
name|unsigned
name|interrupt
range|:
literal|1
decl_stmt|;
comment|/*        "               */
name|unsigned
name|drive
range|:
literal|7
decl_stmt|;
comment|/*        "               */
name|unsigned
name|command
range|:
literal|16
decl_stmt|;
comment|/*        "   (see HCMD_) */
name|unsigned
name|cyl
range|:
literal|13
decl_stmt|;
comment|/* device control word #2 */
name|unsigned
name|head
range|:
literal|9
decl_stmt|;
comment|/*        "               */
name|unsigned
name|sector
range|:
literal|10
decl_stmt|;
comment|/*        "               */
name|unsigned
name|long
name|reserved
index|[
literal|2
index|]
decl_stmt|;
comment|/*                        */
name|unsigned
name|long
name|context
decl_stmt|;
comment|/* software context word */
name|data_chain_type
name|chain
index|[
name|HDC_MAXCHAIN
index|]
decl_stmt|;
comment|/* data chain and lword count */
block|}
struct|;
end_struct

begin_comment
comment|/* defines for the "command"s */
end_comment

begin_define
define|#
directive|define
name|HCMD_STATUS
value|0x40
end_define

begin_comment
comment|/* command: read drive status */
end_comment

begin_define
define|#
directive|define
name|HCMD_READ
value|0x60
end_define

begin_comment
comment|/* command: read data */
end_comment

begin_define
define|#
directive|define
name|HCMD_VENDOR
value|0x6A
end_define

begin_comment
comment|/* command: read vendor data */
end_comment

begin_define
define|#
directive|define
name|HCMD_VERIFY
value|0x6D
end_define

begin_comment
comment|/* command: verify a track */
end_comment

begin_define
define|#
directive|define
name|HCMD_WRITE
value|0x70
end_define

begin_comment
comment|/* command: write data */
end_comment

begin_define
define|#
directive|define
name|HCMD_FORMAT
value|0x7E
end_define

begin_comment
comment|/* command: format a track */
end_comment

begin_define
define|#
directive|define
name|HCMD_CERTIFY
value|0x7F
end_define

begin_comment
comment|/* command: certify a track */
end_comment

begin_define
define|#
directive|define
name|HCMD_WCS
value|0xD0
end_define

begin_comment
comment|/* command: write control store */
end_comment

begin_comment
comment|/*  * This structure defines the master mcb - one per hdc controller.  * The order of this structure is determined by the controller firmware.  * "R" and "W" indicate read-only and write-only.  *  * Bits in the module control long word, "mcl", control the invocation of  * operations on the hdc.  *  * The hdc operates in queued mode or immediate mode.  * In queued mode, it grabs new mcb's, prioritizes them, and adds  * them to its queue; it knows if we've added any mcb's by checking  * forw_phaddr to see if any are linked off of there.  *  * Bits in the master mcb's status word, "mcs", indicate the status  * of the last-processed mcb. The MCS_ definitions define these bits.  * This word is set to zero when the mcb queue is passed to the hdc  * controller; the hdc controller then sets bits in this word.  * We cannot modify the mcb queue until the hdc has completed an mcb  * (the hdc sets the MCS_Q_DONE bit).  *  * The "context" word is copied from the context word of the completed  * mcb. It is currently the virtual pointer to the completed mcb.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|mcl
decl_stmt|;
comment|/* W  module control lword (MCL_) */
name|unsigned
name|long
name|interrupt
decl_stmt|;
comment|/* W  interrupt acknowledge word */
name|unsigned
name|long
name|forw_phaddr
decl_stmt|;
comment|/* W  physical address of first mcb */
name|unsigned
name|long
name|reserve1
decl_stmt|;
name|unsigned
name|long
name|reserve2
decl_stmt|;
name|unsigned
name|long
name|mcs
decl_stmt|;
comment|/* R  status for last completed mcb */
name|unsigned
name|long
name|cmcb_phaddr
decl_stmt|;
comment|/* W  physical addr of completed mcb */
name|unsigned
name|long
name|context
decl_stmt|;
comment|/* R  software context word */
name|unsigned
name|long
name|xstatus
index|[
name|HDC_XSTAT_SIZE
index|]
decl_stmt|;
comment|/* R  xstatus of last mcb */
block|}
name|master_mcb_type
typedef|;
end_typedef

begin_comment
comment|/* definition of master mcb "mcl" */
end_comment

begin_define
define|#
directive|define
name|MCL_QUEUED
value|0x00000010
end_define

begin_comment
comment|/* start queued execution of mcb's */
end_comment

begin_define
define|#
directive|define
name|MCL_IMMEDIATE
value|0x00000001
end_define

begin_comment
comment|/* start immediate xqt of an mcb */
end_comment

begin_comment
comment|/* definition of master mcb "mcs" */
end_comment

begin_define
define|#
directive|define
name|MCS_DONE
value|0x00000080
end_define

begin_comment
comment|/* an mcb is done; status is valid */
end_comment

begin_define
define|#
directive|define
name|MCS_FATALERROR
value|0x00000002
end_define

begin_comment
comment|/* a fatal error occurred */
end_comment

begin_define
define|#
directive|define
name|MCS_SOFTERROR
value|0x00000001
end_define

begin_comment
comment|/* a recoverable error occurred */
end_comment

begin_comment
comment|/*  * This structure defines the information returned by the hdc  * controller for a "read drive status" (HCMD_STATUS) command.  * The format of this structure is determined by the hdc firmware.  * r1, r2, etc. are reserved for future use.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|drs
decl_stmt|;
comment|/* drive status (see DRS_ below) */
name|unsigned
name|long
name|r1
decl_stmt|;
name|unsigned
name|long
name|r2
decl_stmt|;
name|unsigned
name|long
name|r3
decl_stmt|;
name|unsigned
name|short
name|max_cyl
decl_stmt|;
comment|/* max logical cylinder address */
name|unsigned
name|short
name|max_head
decl_stmt|;
comment|/* max logical head address */
name|unsigned
name|short
name|r4
decl_stmt|;
name|unsigned
name|short
name|max_sector
decl_stmt|;
comment|/* max logical sector address */
name|unsigned
name|short
name|def_cyl
decl_stmt|;
comment|/* definition track cylinder address */
name|unsigned
name|short
name|def_cyl_count
decl_stmt|;
comment|/* definition track cylinder count */
name|unsigned
name|short
name|diag_cyl
decl_stmt|;
comment|/* diagnostic track cylinder address */
name|unsigned
name|short
name|diag_cyl_count
decl_stmt|;
comment|/* diagnostic track cylinder count */
name|unsigned
name|short
name|max_phys_cyl
decl_stmt|;
comment|/* max physical cylinder address */
name|unsigned
name|short
name|max_phys_head
decl_stmt|;
comment|/* max physical head address */
name|unsigned
name|short
name|r5
decl_stmt|;
name|unsigned
name|short
name|max_phys_sector
decl_stmt|;
comment|/* max physical sector address */
name|unsigned
name|short
name|r6
decl_stmt|;
name|unsigned
name|short
name|id
decl_stmt|;
comment|/* drive id (drive model) */
name|unsigned
name|short
name|r7
decl_stmt|;
name|unsigned
name|short
name|bytes_per_sec
decl_stmt|;
comment|/* bytes/sector -vendorflaw conversn */
name|unsigned
name|short
name|r8
decl_stmt|;
name|unsigned
name|short
name|rpm
decl_stmt|;
comment|/* disk revolutions per minute */
name|unsigned
name|long
name|r9
decl_stmt|;
name|unsigned
name|long
name|r10
decl_stmt|;
name|unsigned
name|long
name|r11
decl_stmt|;
block|}
name|drive_stat_type
typedef|;
end_typedef

begin_comment
comment|/* defines for drive_stat drs word */
end_comment

begin_define
define|#
directive|define
name|DRS_FAULT
value|0x00000080
end_define

begin_comment
comment|/* drive is reporting a fault */
end_comment

begin_define
define|#
directive|define
name|DRS_RESERVED
value|0x00000040
end_define

begin_comment
comment|/* drive is reserved by other port */
end_comment

begin_define
define|#
directive|define
name|DRS_WRITE_PROT
value|0x00000020
end_define

begin_comment
comment|/* drive is write protected */
end_comment

begin_define
define|#
directive|define
name|DRS_ON_CYLINDER
value|0x00000002
end_define

begin_comment
comment|/* drive heads are not moving now */
end_comment

begin_define
define|#
directive|define
name|DRS_ONLINE
value|0x00000001
end_define

begin_comment
comment|/* drive is available for operation */
end_comment

begin_comment
comment|/*  * hdc controller table. It contains information specific to each controller.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|ctlr
decl_stmt|;
comment|/* controller number (0-15) */
name|hdc_regs_type
modifier|*
name|registers
decl_stmt|;
comment|/* base address of hdc io registers */
name|mcb_type
modifier|*
name|forw_active
decl_stmt|;
comment|/* doubly linked list of */
name|mcb_type
modifier|*
name|back_active
decl_stmt|;
comment|/* .. active mcb's */
name|mcb_type
modifier|*
name|forw_free
decl_stmt|;
comment|/* doubly linked list of */
name|mcb_type
modifier|*
name|back_free
decl_stmt|;
comment|/* .. free mcb's */
name|mcb_type
modifier|*
name|forw_wait
decl_stmt|;
comment|/* doubly linked list of */
name|mcb_type
modifier|*
name|back_wait
decl_stmt|;
comment|/* .. waiting mcb's */
name|hdc_mid_type
name|mid
decl_stmt|;
comment|/* the module id is read to here */
name|long
name|master_phaddr
decl_stmt|;
comment|/* physical address of master mcb */
name|master_mcb_type
name|master_mcb
decl_stmt|;
comment|/* the master mcb for this hdc */
name|mcb_type
name|mcbs
index|[
name|HDC_MAXMCBS
index|]
decl_stmt|;
comment|/* pool of mcb's for this hdc */
block|}
name|hdc_ctlr_type
typedef|;
end_typedef

begin_comment
comment|/*  * hdc unit table. It contains information specific to each hdc drive.  * Some information is obtained from the profile prom and geometry block.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|par_tab
name|partition
index|[
name|GB_MAXPART
index|]
decl_stmt|;
comment|/* partition definitions */
name|int
name|ctlr
decl_stmt|;
comment|/* the controller number (0-15) */
name|int
name|slave
decl_stmt|;
comment|/* the slave number (0-4) */
name|int
name|unit
decl_stmt|;
comment|/* the unit number (0-31) */
name|int
name|id
decl_stmt|;
comment|/* identifies the disk model */
name|int
name|spc
decl_stmt|;
comment|/* sectors per cylinder */
name|int
name|cylinders
decl_stmt|;
comment|/* number of logical cylinders */
name|int
name|heads
decl_stmt|;
comment|/* number of logical heads */
name|int
name|sectors
decl_stmt|;
comment|/* number of logical sectors/track */
name|int
name|phys_cylinders
decl_stmt|;
comment|/* number of physical cylinders */
name|int
name|phys_heads
decl_stmt|;
comment|/* number of physical heads */
name|int
name|phys_sectors
decl_stmt|;
comment|/* number of physical sectors/track */
name|int
name|def_cyl
decl_stmt|;
comment|/* logical cylinder of drive def */
name|int
name|def_cyl_count
decl_stmt|;
comment|/* number of logical def cylinders */
name|int
name|diag_cyl
decl_stmt|;
comment|/* logical cylinder of diag area */
name|int
name|diag_cyl_count
decl_stmt|;
comment|/* number of logical diag cylinders */
name|int
name|rpm
decl_stmt|;
comment|/* disk rpm */
name|int
name|bytes_per_sec
decl_stmt|;
comment|/* bytes/sector -vendorflaw conversn */
name|int
name|format
decl_stmt|;
comment|/* TRUE= format program is using dsk */
name|mcb_type
name|phio_mcb
decl_stmt|;
comment|/* mcb for handler physical io */
name|struct
name|buf
name|phio_buf
decl_stmt|;
comment|/* buf for handler physical io */
name|unsigned
name|long
name|phio_data
index|[
name|HDC_PHIO_SIZE
index|]
decl_stmt|;
comment|/* data for physical io */
name|struct
name|buf
name|raw_buf
decl_stmt|;
comment|/* buf structure for raw i/o */
block|}
name|hdc_unit_type
typedef|;
end_typedef

end_unit

