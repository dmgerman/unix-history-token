begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Harris Corp.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)hdreg.h	7.3 (Berkeley) 3/7/89  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COMPAT_42
end_ifndef

begin_define
define|#
directive|define
name|COMPAT_42
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|HDC_MAXMCBS
value|32
end_define

begin_comment
comment|/* max# mcb's the hdc can handle */
end_comment

begin_define
define|#
directive|define
name|HDC_MAXCHAIN
value|64
end_define

begin_comment
comment|/* max# of data chains */
end_comment

begin_define
define|#
directive|define
name|HDC_MAXBC
value|64*1024
end_define

begin_comment
comment|/* max# byte count per data chain */
end_comment

begin_define
define|#
directive|define
name|HDC_MAXFLAWS
value|8000
end_define

begin_comment
comment|/* max# flaws per hdc disk */
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
name|HDC_VDATA_SIZE
value|16
end_define

begin_comment
comment|/* vendor data size (long words) */
end_comment

begin_define
define|#
directive|define
name|HDC_REG
parameter_list|(
name|x
parameter_list|)
value|(hd->reg->x)
end_define

begin_comment
comment|/* set an HDC register */
end_comment

begin_comment
comment|/* number of blocks per dump record */
end_comment

begin_define
define|#
directive|define
name|HDC_DUMPSIZE
value|(HDC_MAXBC/DEV_BSIZE*HDC_MAXCHAIN)
end_define

begin_comment
comment|/*  * These are the 4 hdc i/o register addresses.  Writing to "master_mcb"  * tells the hdc controller where the master mcb is and initiates hdc  * operation. The hdc then reads the master mcb and all new mcb's in the  * active mcb queue.  Writing to "module_id" causes the hdc to return the  * hdc's module id word in the location specified by the address written  * into the register.  "soft_reset" causes orderly shutdown of HDC; it's  * unclear from the manual what "hard_reset" does, but it should never be  * used as use while the HDC is active may cause format errors.  */
end_comment

begin_struct
struct|struct
name|registers
block|{
name|u_long
name|master_mcb
decl_stmt|,
comment|/* set the master mcb address */
name|module_id
decl_stmt|,
comment|/* returns hdc's module id (hdc_mid) */
name|soft_reset
decl_stmt|,
comment|/* shut down the hdc */
name|hard_reset
decl_stmt|;
comment|/* send a system reset to the hdc */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Definition for the module id returned by the hdc when "module_id"  * is written to.  The format is defined by the hdc microcode.  */
end_comment

begin_define
define|#
directive|define
name|HID_HDC
value|0x01
end_define

begin_comment
comment|/* hvme_id for HDC */
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

begin_struct
struct|struct
name|module_id
block|{
name|u_char
name|module_id
decl_stmt|,
comment|/* module id; hdc's return HDC_MID */
name|reserved
decl_stmt|,
name|code_rev
decl_stmt|,
comment|/* micro-code rev#; FF= not loaded */
name|fit
decl_stmt|;
comment|/* FIT test result; FF= no error */
block|}
struct|;
end_struct

begin_comment
comment|/*  * This structure defines the mcb's.  A portion of this structure is used  * only by the software.  The other portion is set up by software and sent  * to the hdc firmware to perform an operation; the order of this part of  * the mcb is determined by the controller firmware.  *  * "context" is the software context word.  The hdc firmware copies the  * contents of this word to the master mcb whenever the mcb has been  * completed.  The virtual address of the mcb is usually saved here.  *  * "forw_phaddr" forms a linked list of mcbs.  The addresses are physical  * since they are used by the hdc firmware.  *  * Bits in device control word #1 define the hdc command and control the  * operation of the hdc.  Bits in device control word #2 define the disk  * sector address for the operation defined in control word #1.  */
end_comment

begin_define
define|#
directive|define
name|LWC_DATA_CHAIN
value|0x80000000
end_define

begin_comment
comment|/* mask for data chain bit in wcount */
end_comment

begin_struct
struct|struct
name|mcb
block|{
name|u_long
name|forw_phaddr
decl_stmt|;
comment|/* phys address of next mcb */
name|u_int
name|priority
range|:
literal|8
decl_stmt|,
comment|/* device control word #1 */
name|interrupt
range|:
literal|1
decl_stmt|,
comment|/*        "               */
name|drive
range|:
literal|7
decl_stmt|,
comment|/*        "               */
name|command
range|:
literal|16
decl_stmt|,
comment|/*        "   (see HCMD_) */
name|cyl
range|:
literal|13
decl_stmt|,
comment|/* device control word #2 */
name|head
range|:
literal|9
decl_stmt|,
comment|/*        "               */
name|sector
range|:
literal|10
decl_stmt|;
comment|/*        "               */
name|u_long
name|r1
decl_stmt|,
name|r2
decl_stmt|,
name|context
decl_stmt|;
comment|/* software context word */
struct|struct
name|chain
block|{
name|long
name|wcount
decl_stmt|,
comment|/* word count */
name|memadr
decl_stmt|;
comment|/* transfer address */
block|}
name|chain
index|[
name|HDC_MAXCHAIN
index|]
struct|;
comment|/* data chain */
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
value|0x6a
end_define

begin_comment
comment|/* command: read vendor data */
end_comment

begin_define
define|#
directive|define
name|HCMD_VERIFY
value|0x6d
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
value|0x7e
end_define

begin_comment
comment|/* command: format a track */
end_comment

begin_define
define|#
directive|define
name|HCMD_CERTIFY
value|0x7f
end_define

begin_comment
comment|/* command: certify a track */
end_comment

begin_define
define|#
directive|define
name|HCMD_WCS
value|0xd0
end_define

begin_comment
comment|/* command: write control store */
end_comment

begin_comment
comment|/*  * This structure defines the master mcb - one per hdc controller.  * The order of this structure is determined by the controller firmware.  * "R" and "W" indicate read-only and write-only.  *  * Bits in the module control long word, "mcl", control the invocation of  * operations on the hdc.  *  * The hdc operates in queued mode or immediate mode.  In queued mode, it  * grabs new mcb's, prioritizes them, and adds them to its queue; it knows  * if we've added any mcb's by checking forw_phaddr to see if any are  * linked off of there.  *  * Bits in the master mcb's status word, "mcs", indicate the status  * of the last-processed mcb.  The MCS_ definitions define these bits.  * This word is set to zero when the mcb queue is passed to the hdc  * controller; the hdc controller then sets bits in this word.  * We cannot modify the mcb queue until the hdc has completed an mcb  * (the hdc sets the MCS_Q_DONE bit).  *  * The "context" word is copied from the context word of the completed  * mcb.  It is currently the virtual pointer to the completed mcb.  */
end_comment

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

begin_struct
struct|struct
name|master_mcb
block|{
name|u_long
name|mcw
decl_stmt|,
comment|/* W  module control word (MCL_) */
name|interrupt
decl_stmt|,
comment|/* W  interrupt acknowledge word */
name|forw_phaddr
decl_stmt|,
comment|/* W  physical address of first mcb */
name|r1
decl_stmt|,
name|r2
decl_stmt|,
name|mcs
decl_stmt|,
comment|/* R  status for last completed mcb */
name|cmcb_phaddr
decl_stmt|,
comment|/* W  physical addr of completed mcb */
name|context
decl_stmt|,
comment|/* W  software context word */
define|#
directive|define
name|HDC_XSTAT_SIZE
value|128
comment|/* size of extended status (lwords) */
name|xstatus
index|[
name|HDC_XSTAT_SIZE
index|]
decl_stmt|;
comment|/* R  xstatus of last mcb */
block|}
struct|;
end_struct

begin_comment
comment|/*  * This structure defines the information returned by the hdc controller for  * a "read drive status" (HCMD_STATUS) command.  The format of this structure  * is determined by the hdc firmware.  r[1-11] are reserved for future use.  */
end_comment

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

begin_struct
struct|struct
name|status
block|{
name|u_long
name|drs
decl_stmt|,
comment|/* drive status (see DRS_) */
name|r1
decl_stmt|,
name|r2
decl_stmt|,
name|r3
decl_stmt|;
name|u_short
name|max_cyl
decl_stmt|,
comment|/* max logical cylinder address */
name|max_head
decl_stmt|,
comment|/* max logical head address */
name|r4
decl_stmt|,
name|max_sector
decl_stmt|,
comment|/* max logical sector address */
name|def_cyl
decl_stmt|,
comment|/* definition track cylinder address */
name|def_cyl_count
decl_stmt|,
comment|/* definition track cylinder count */
name|diag_cyl
decl_stmt|,
comment|/* diagnostic track cylinder address */
name|diag_cyl_count
decl_stmt|,
comment|/* diagnostic track cylinder count */
name|max_phys_cyl
decl_stmt|,
comment|/* max physical cylinder address */
name|max_phys_head
decl_stmt|,
comment|/* max physical head address */
name|r5
decl_stmt|,
name|max_phys_sector
decl_stmt|,
comment|/* max physical sector address */
name|r6
decl_stmt|,
name|id
decl_stmt|,
comment|/* drive id (drive model) */
name|r7
decl_stmt|,
name|bytes_per_sec
decl_stmt|,
comment|/* bytes/sector -vendorflaw conversn */
name|r8
decl_stmt|,
name|rpm
decl_stmt|;
comment|/* disk revolutions per minute */
name|u_long
name|r9
decl_stmt|,
name|r10
decl_stmt|,
name|r11
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_42
end_ifdef

begin_define
define|#
directive|define
name|GB_ID
value|"geometry"
end_define

begin_define
define|#
directive|define
name|GB_ID_LEN
value|sizeof(GB_ID)-1
end_define

begin_define
define|#
directive|define
name|GB_MAXPART
value|8
end_define

begin_define
define|#
directive|define
name|GB_VERSION
value|1
end_define

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
name|BPS
value|512
end_define

begin_comment
comment|/* bytes per sector */
end_comment

begin_comment
comment|/*  * Geometry Block:  *  * The geometry block defines partition offsets and information about the  * flaw maps on the flaw map track.  It resides on the first sector of the  * flaw map track.  This structure is also used by vddc disk controllers.  * In this case, the block resides at sector 0 of the disk.  *  * The geometry_sector structure defines the sector containing the geometry  * block.  This sector is checksumed independent of the geometry information.  * The fields in these structured which should never be moved are the id and  * version fields in the geometry_block structure and the checksum field in  * the geometry_sector structure.  This will provide for easy extensions in  * the future.  */
end_comment

begin_define
define|#
directive|define
name|DRIVE_TYPE
value|flaw_offset
end_define

begin_comment
comment|/* For VDDC Geometry Blocks Only */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|id
index|[
name|GB_ID_LEN
index|]
decl_stmt|;
comment|/* identifies the geometry block */
name|long
name|version
decl_stmt|,
comment|/* geometry block version number */
name|flaw_offset
decl_stmt|,
comment|/* flaw map byte offset in partition7 */
name|flaw_size
decl_stmt|,
comment|/* harris flaw map size in bytes */
name|flaw_checksum
decl_stmt|,
comment|/* sum of bytes in harris flaw map */
name|unused
index|[
literal|3
index|]
decl_stmt|;
comment|/* --- available for use */
struct|struct
name|par_tab
block|{
name|long
name|start
decl_stmt|,
comment|/* starting 1K block number */
name|length
decl_stmt|;
comment|/* partition size in 1K blocks */
block|}
name|partition
index|[
name|GB_MAXPART
index|]
struct|;
comment|/* partition definitions */
block|}
name|geometry_block
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|geometry_block
name|geometry_block
decl_stmt|;
comment|/* disk geometry */
name|char
name|filler
index|[
name|BPS
operator|-
sizeof|sizeof
argument_list|(
name|geometry_block
argument_list|)
operator|-
sizeof|sizeof
argument_list|(
name|long
argument_list|)
index|]
decl_stmt|;
name|long
name|checksum
decl_stmt|;
comment|/* sector checksum */
block|}
name|geometry_sector
typedef|;
end_typedef

begin_comment
comment|/*  * GB_CHECKSUM:  *  * This macro computes the checksum for the geometry sector and returns the  * value.  Input to this macro is a pointer to the geometry_sector.  Pretty  * useless, should at least have done an XOR.  */
end_comment

begin_define
define|#
directive|define
name|GB_CHECKSUM
parameter_list|(
name|_gs_ptr
parameter_list|,
name|_checksum
parameter_list|)
value|{ \ 	register u_char *_ptr; \ 	register u_long _i, _xsum; \ 	_xsum = 0; \ 	_ptr = (u_char *)(_gs_ptr); \ 	for (_i = 0; _i< (sizeof(geometry_sector) - sizeof(long)); _i++) \ 		_xsum += * _ptr++; \ 	_checksum = _xsum; \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COMPAT_42 */
end_comment

end_unit

