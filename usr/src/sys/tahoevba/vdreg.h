begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)vdreg.h	7.2 (Berkeley) 6/29/88  */
end_comment

begin_comment
comment|/*  * Versabus VDDC/SMDE disk controller definitions.  */
end_comment

begin_define
define|#
directive|define
name|VDDC_SECSIZE
value|512
end_define

begin_comment
comment|/* sector size for VDDC */
end_comment

begin_define
define|#
directive|define
name|VD_MAXSECSIZE
value|1024
end_define

begin_comment
comment|/* max sector size for SMD/E */
end_comment

begin_comment
comment|/*  * Controller communications block.  */
end_comment

begin_struct
struct|struct
name|vddevice
block|{
name|u_long
name|vdcdr
decl_stmt|;
comment|/* controller device register */
name|u_long
name|vdreset
decl_stmt|;
comment|/* controller reset register */
name|u_long
name|vdcsr
decl_stmt|;
comment|/* control-status register */
name|long
name|vdrstclr
decl_stmt|;
comment|/* reset clear register */
name|u_short
name|vdstatus
index|[
literal|16
index|]
decl_stmt|;
comment|/* per-drive status register */
name|u_short
name|vdicf_status
decl_stmt|;
comment|/* status change interupt control format */
name|u_short
name|vdicf_done
decl_stmt|;
comment|/* interrupt complete control format */
name|u_short
name|vdicf_error
decl_stmt|;
comment|/* interrupt error control format */
name|u_short
name|vdicf_success
decl_stmt|;
comment|/* interrupt success control format */
name|u_short
name|vdtcf_mdcb
decl_stmt|;
comment|/* mdcb transfer control format */
name|u_short
name|vdtcf_dcb
decl_stmt|;
comment|/* dcb transfer control format */
name|u_short
name|vdtcf_trail
decl_stmt|;
comment|/* trail transfer control format */
name|u_short
name|vdtcf_data
decl_stmt|;
comment|/* data transfer control format */
name|u_long
name|vdccf
decl_stmt|;
comment|/* controller configuration flags */
name|u_long
name|vdsecsize
decl_stmt|;
comment|/* sector size */
name|u_short
name|vdfill0
decl_stmt|;
name|u_char
name|vdcylskew
decl_stmt|;
comment|/* cylinder to cylinder skew factor */
name|u_char
name|vdtrackskew
decl_stmt|;
comment|/* track to track skew factor */
name|u_long
name|vdfill1
decl_stmt|;
name|u_long
name|vddfr
decl_stmt|;
comment|/* diagnostic flag register */
name|u_long
name|vddda
decl_stmt|;
comment|/* diagnostic dump address */
block|}
struct|;
end_struct

begin_comment
comment|/* controller types */
end_comment

begin_define
define|#
directive|define
name|VDTYPE_VDDC
value|1
end_define

begin_comment
comment|/* old vddc controller (smd only) */
end_comment

begin_define
define|#
directive|define
name|VDTYPE_SMDE
value|2
end_define

begin_comment
comment|/* new smde controller (smd-e) */
end_comment

begin_comment
comment|/*  * Controller status definitions.  */
end_comment

begin_define
define|#
directive|define
name|CS_SCS
value|0xf
end_define

begin_comment
comment|/* status change source (drive number) */
end_comment

begin_define
define|#
directive|define
name|CS_ELC
value|0x10
end_define

begin_comment
comment|/* error on last command */
end_comment

begin_define
define|#
directive|define
name|CS_ICC
value|0x60
end_define

begin_comment
comment|/* interupt cause code */
end_comment

begin_define
define|#
directive|define
name|ICC_NOI
value|0x00
end_define

begin_comment
comment|/* no interupt */
end_comment

begin_define
define|#
directive|define
name|ICC_DUN
value|0x20
end_define

begin_comment
comment|/* no interupt */
end_comment

begin_define
define|#
directive|define
name|ICC_ERR
value|0x40
end_define

begin_comment
comment|/* no interupt */
end_comment

begin_define
define|#
directive|define
name|ICC_SUC
value|0x60
end_define

begin_comment
comment|/* no interupt */
end_comment

begin_define
define|#
directive|define
name|CS_GO
value|0x80
end_define

begin_comment
comment|/* go bit (controller busy) */
end_comment

begin_define
define|#
directive|define
name|CS_BE
value|0x100
end_define

begin_comment
comment|/* buss error */
end_comment

begin_define
define|#
directive|define
name|CS_BOK
value|0x4000
end_define

begin_comment
comment|/* board ok */
end_comment

begin_define
define|#
directive|define
name|CS_SFL
value|0x8000
end_define

begin_comment
comment|/* system fail */
end_comment

begin_define
define|#
directive|define
name|CS_LEC
value|0xff000000
end_define

begin_comment
comment|/* last error code */
end_comment

begin_comment
comment|/*  * Drive status definitions.  */
end_comment

begin_define
define|#
directive|define
name|STA_UR
value|0x1
end_define

begin_comment
comment|/* unit ready */
end_comment

begin_define
define|#
directive|define
name|STA_OC
value|0x2
end_define

begin_comment
comment|/* on cylinder */
end_comment

begin_define
define|#
directive|define
name|STA_SE
value|0x4
end_define

begin_comment
comment|/* seek error */
end_comment

begin_define
define|#
directive|define
name|STA_DF
value|0x8
end_define

begin_comment
comment|/* drive fault */
end_comment

begin_define
define|#
directive|define
name|STA_WP
value|0x10
end_define

begin_comment
comment|/* write protected */
end_comment

begin_define
define|#
directive|define
name|STA_US
value|0x20
end_define

begin_comment
comment|/* unit selected */
end_comment

begin_comment
comment|/*  * Interupt Control Field definitions.  */
end_comment

begin_define
define|#
directive|define
name|ICF_IPL
value|0x7
end_define

begin_comment
comment|/* interupt priority level */
end_comment

begin_define
define|#
directive|define
name|ICF_IEN
value|0x8
end_define

begin_comment
comment|/* interupt enable */
end_comment

begin_define
define|#
directive|define
name|ICF_IV
value|0xff00
end_define

begin_comment
comment|/* interupt vector */
end_comment

begin_comment
comment|/*  * Transfer Control Format definitions.  */
end_comment

begin_define
define|#
directive|define
name|TCF_AM
value|0xff
end_define

begin_comment
comment|/* Address Modifier */
end_comment

begin_define
define|#
directive|define
name|AM_SNPDA
value|0x01
end_define

begin_comment
comment|/* Standard Non-Privileged Data Access */
end_comment

begin_define
define|#
directive|define
name|AM_SASA
value|0x81
end_define

begin_comment
comment|/* Standard Ascending Sequential Access */
end_comment

begin_define
define|#
directive|define
name|AM_ENPDA
value|0xf1
end_define

begin_comment
comment|/* Extended Non-Privileged Data Access */
end_comment

begin_define
define|#
directive|define
name|AM_EASA
value|0xe1
end_define

begin_comment
comment|/* Extended Ascending Sequential Access */
end_comment

begin_define
define|#
directive|define
name|TCF_BTE
value|0x800
end_define

begin_comment
comment|/* Block Transfer Enable */
end_comment

begin_comment
comment|/*  * Controller Configuration Flags.  */
end_comment

begin_define
define|#
directive|define
name|CCF_STS
value|0x1
end_define

begin_comment
comment|/* sectors per track selectable */
end_comment

begin_define
define|#
directive|define
name|CCF_EAV
value|0x2
end_define

begin_comment
comment|/* enable auto vector */
end_comment

begin_define
define|#
directive|define
name|CCF_ERR
value|0x4
end_define

begin_comment
comment|/* enable reset register */
end_comment

begin_define
define|#
directive|define
name|CCF_DER
value|0x8
end_define

begin_comment
comment|/* disable error recovery */
end_comment

begin_define
define|#
directive|define
name|CCF_XMD
value|0x60
end_define

begin_comment
comment|/* xmd transfer mode (bus size) */
end_comment

begin_define
define|#
directive|define
name|XMD_8BIT
value|0x20
end_define

begin_comment
comment|/*   do only 8 bit transfers */
end_comment

begin_define
define|#
directive|define
name|XMD_16BIT
value|0x40
end_define

begin_comment
comment|/*   do only 16 bit transfers */
end_comment

begin_define
define|#
directive|define
name|XMD_32BIT
value|0x60
end_define

begin_comment
comment|/*   do only 32 bit transfers */
end_comment

begin_define
define|#
directive|define
name|CCF_BSZ
value|0x300
end_define

begin_comment
comment|/* burst size */
end_comment

begin_define
define|#
directive|define
name|BSZ_16WRD
value|0x000
end_define

begin_comment
comment|/*   16 word transfer burst */
end_comment

begin_define
define|#
directive|define
name|BSZ_12WRD
value|0x100
end_define

begin_comment
comment|/*   12 word transfer burst */
end_comment

begin_define
define|#
directive|define
name|BSZ_8WRD
value|0x200
end_define

begin_comment
comment|/*   8 word transfer burst */
end_comment

begin_define
define|#
directive|define
name|BSZ_4WRD
value|0x300
end_define

begin_comment
comment|/*   4 word transfer burst */
end_comment

begin_define
define|#
directive|define
name|CCF_SEN
value|0x400
end_define

begin_comment
comment|/* cylinder/track skew enable (for format) */
end_comment

begin_define
define|#
directive|define
name|CCF_ENP
value|0x1000
end_define

begin_comment
comment|/* enable parity */
end_comment

begin_define
define|#
directive|define
name|CCF_EPE
value|0x2000
end_define

begin_comment
comment|/* enable parity errors */
end_comment

begin_define
define|#
directive|define
name|CCF_EDE
value|0x10000
end_define

begin_comment
comment|/* error detection enable */
end_comment

begin_define
define|#
directive|define
name|CCF_ECE
value|0x20000
end_define

begin_comment
comment|/* error correction enable */
end_comment

begin_comment
comment|/*  * Diagnostic register definitions.  */
end_comment

begin_define
define|#
directive|define
name|DIA_DC
value|0x7f
end_define

begin_comment
comment|/* dump count mask */
end_comment

begin_define
define|#
directive|define
name|DIA_DWR
value|0x80
end_define

begin_comment
comment|/* dump write/read flag */
end_comment

begin_define
define|#
directive|define
name|DIA_ARE
value|0x100
end_define

begin_comment
comment|/* auto rebuild enable */
end_comment

begin_define
define|#
directive|define
name|DIA_CEN
value|0x200
end_define

begin_comment
comment|/* call enable flag */
end_comment

begin_define
define|#
directive|define
name|DIA_KEY
value|0xAA550000
end_define

begin_comment
comment|/* reset enable key */
end_comment

begin_comment
comment|/*  * Hardware interface flags, in dcb.devselect and d_devflags  */
end_comment

begin_define
define|#
directive|define
name|VD_ESDI
value|0x10
end_define

begin_comment
comment|/* drive is on ESDI interface */
end_comment

begin_define
define|#
directive|define
name|d_devflags
value|d_drivedata[0]
end_define

begin_comment
comment|/* in disk label */
end_comment

begin_comment
comment|/*  * Error recovery flags.  */
end_comment

begin_define
define|#
directive|define
name|VDRF_RTZ
value|0x0001
end_define

begin_comment
comment|/* return to zero */
end_comment

begin_define
define|#
directive|define
name|VDRF_OCF
value|0x0002
end_define

begin_comment
comment|/* on cylinder false */
end_comment

begin_define
define|#
directive|define
name|VDRF_OSP
value|0x0004
end_define

begin_comment
comment|/* offset plus */
end_comment

begin_define
define|#
directive|define
name|VDRF_OSM
value|0x0008
end_define

begin_comment
comment|/* offset minus */
end_comment

begin_define
define|#
directive|define
name|VDRF_DSE
value|0x0080
end_define

begin_comment
comment|/* data strobe early */
end_comment

begin_define
define|#
directive|define
name|VDRF_DSL
value|0x0100
end_define

begin_comment
comment|/* data strobe late */
end_comment

begin_define
define|#
directive|define
name|VDRF_NONE
value|0
end_define

begin_define
define|#
directive|define
name|VDRF_NORMAL
value|(VDRF_RTZ|VDRF_OCF|VDRF_OSP|VDRF_OSM|VDRF_DSE|VDRF_DSE)
end_define

begin_comment
comment|/*  * Perform a reset on the controller.  */
end_comment

begin_define
define|#
directive|define
name|VDRESET
parameter_list|(
name|a
parameter_list|,
name|t
parameter_list|)
value|{ \ 	if ((t) == VDTYPE_SMDE) { \ 		((struct vddevice *)(a))->vddfr = DIA_KEY|DIA_CEN; \ 		((struct vddevice *)(a))->vdcdr = (u_long)0xffffffff; \ 		DELAY(5000000); \ 	} else { \ 		((struct vddevice *)(a))->vdreset = 0; \ 		DELAY(1500000); \ 	} \ }
end_define

begin_comment
comment|/*  * Abort a controller operation.  */
end_comment

begin_define
define|#
directive|define
name|VDABORT
parameter_list|(
name|a
parameter_list|,
name|t
parameter_list|)
value|{ \ 	if ((t) == VDTYPE_VDDC) { \ 		movow((a), (VDOP_ABORT&0xffff0000)>>16) ; \ 		movow((int)(a)+2, VDOP_ABORT&0xffff); \ 	} else \ 		((struct vddevice *)(a))->vdcdr = (u_long)VDOP_ABORT; \ 	DELAY(1000000); \ }
end_define

begin_comment
comment|/*  * Start a command.  */
end_comment

begin_define
define|#
directive|define
name|VDGO
parameter_list|(
name|a
parameter_list|,
name|mdcb
parameter_list|,
name|t
parameter_list|)
value|{\ 	if ((t) == VDTYPE_VDDC) { \ 		movow((a), ((int)(mdcb)&0xffff0000)>>16) ; \ 		movow((int)((a))+2, (int)(mdcb)&0xffff); \ 	} else \ 		((struct vddevice *)(a))->vdcdr = (mdcb); \ }
end_define

begin_comment
comment|/*  * MDCB layout.  */
end_comment

begin_struct
struct|struct
name|mdcb
block|{
name|struct
name|dcb
modifier|*
name|mdcb_head
decl_stmt|;
comment|/* first dcb in list */
name|struct
name|dcb
modifier|*
name|mdcb_busy
decl_stmt|;
comment|/* dcb being processed */
name|struct
name|dcb
modifier|*
name|mdcb_intr
decl_stmt|;
comment|/* dcb causing interrupt */
name|long
name|mdcb_status
decl_stmt|;
comment|/* status of dcb in mdcb_busy */
block|}
struct|;
end_struct

begin_comment
comment|/*  * DCB definitions.  */
end_comment

begin_comment
comment|/*  * A disk address.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
name|track
decl_stmt|;
comment|/* all 8 bits */
name|u_char
name|sector
decl_stmt|;
comment|/* all 8  bits */
name|u_short
name|cylinder
decl_stmt|;
comment|/* low order 12 bits */
block|}
name|dskadr
typedef|;
end_typedef

begin_comment
comment|/*  * DCB trailer formats.  */
end_comment

begin_comment
comment|/* read/write trailer */
end_comment

begin_struct
struct|struct
name|trrw
block|{
name|u_long
name|memadr
decl_stmt|;
comment|/* memory address */
name|u_long
name|wcount
decl_stmt|;
comment|/* 16 bit word count */
name|dskadr
name|disk
decl_stmt|;
comment|/* disk address */
block|}
struct|;
end_struct

begin_comment
comment|/* scatter/gather trailer */
end_comment

begin_define
define|#
directive|define
name|VDMAXPAGES
value|(MAXPHYS / NBPG)
end_define

begin_struct
struct|struct
name|trsg
block|{
name|struct
name|trrw
name|start_addr
decl_stmt|;
struct|struct
name|addr_chain
block|{
name|u_long
name|nxt_addr
decl_stmt|;
name|u_long
name|nxt_len
decl_stmt|;
block|}
name|addr_chain
index|[
name|VDMAXPAGES
operator|+
literal|1
index|]
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/* seek trailer format */
end_comment

begin_struct
struct|struct
name|trseek
block|{
name|dskadr
name|skaddr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* format trailer */
end_comment

begin_struct
struct|struct
name|trfmt
block|{
name|char
modifier|*
name|addr
decl_stmt|;
comment|/* data buffer to be filled on sector*/
name|long
name|nsectors
decl_stmt|;
comment|/* # of sectors to be formatted */
name|dskadr
name|disk
decl_stmt|;
comment|/* disk physical address info */
name|dskadr
name|hdr
decl_stmt|;
comment|/* header address info */
block|}
struct|;
end_struct

begin_comment
comment|/* reset/configure trailer */
end_comment

begin_struct
struct|struct
name|treset
block|{
name|long
name|ncyl
decl_stmt|;
comment|/* # cylinders */
name|long
name|nsurfaces
decl_stmt|;
comment|/* # surfaces */
name|long
name|nsectors
decl_stmt|;
comment|/* # sectors */
name|long
name|slip_sec
decl_stmt|;
comment|/* # of slip sectors */
name|long
name|recovery
decl_stmt|;
comment|/* recovery flags */
block|}
struct|;
end_struct

begin_comment
comment|/* ident trailer */
end_comment

begin_struct
struct|struct
name|trid
block|{
name|long
name|name
decl_stmt|;
name|long
name|id
decl_stmt|;
name|long
name|date
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * DCB layout.  */
end_comment

begin_struct
struct|struct
name|dcb
block|{
name|struct
name|dcb
modifier|*
name|nxtdcb
decl_stmt|;
comment|/* next dcb */
name|short
name|intflg
decl_stmt|;
comment|/* interrupt settings and flags */
name|short
name|opcode
decl_stmt|;
comment|/* DCB command code etc... */
name|long
name|operrsta
decl_stmt|;
comment|/* error& status info */
name|short
name|fill
decl_stmt|;
comment|/* not used */
name|char
name|devselect
decl_stmt|;
comment|/* drive selection */
name|char
name|trailcnt
decl_stmt|;
comment|/* trailer Word Count */
name|long
name|err_memadr
decl_stmt|;
comment|/* error memory address */
name|char
name|err_code
decl_stmt|;
comment|/* error codes for SMD/E */
name|char
name|fill2
decl_stmt|;
comment|/* not used */
name|short
name|err_wcount
decl_stmt|;
comment|/* error word count */
name|char
name|err_trk
decl_stmt|;
comment|/* error track/sector */
name|char
name|err_sec
decl_stmt|;
comment|/* error track/sector */
name|short
name|err_cyl
decl_stmt|;
comment|/* error cylinder adr */
union|union
block|{
name|struct
name|trid
name|idtrail
decl_stmt|;
comment|/* ident command trailer */
name|struct
name|trseek
name|sktrail
decl_stmt|;
comment|/* seek command trailer */
name|struct
name|trsg
name|sgtrail
decl_stmt|;
comment|/* scatter/gather trailer */
name|struct
name|trrw
name|rwtrail
decl_stmt|;
comment|/* read/write trailer */
name|struct
name|trfmt
name|fmtrail
decl_stmt|;
comment|/* format trailer */
name|struct
name|treset
name|rstrail
decl_stmt|;
comment|/* reset/configure trailer */
block|}
name|trail
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * smaller DCB with seek trailer only (no scatter-gather).  */
end_comment

begin_struct
struct|struct
name|skdcb
block|{
name|struct
name|dcb
modifier|*
name|nxtdcb
decl_stmt|;
comment|/* next dcb */
name|short
name|intflg
decl_stmt|;
comment|/* interrupt settings and flags */
name|short
name|opcode
decl_stmt|;
comment|/* DCB command code etc... */
name|long
name|operrsta
decl_stmt|;
comment|/* error& status info */
name|short
name|fill
decl_stmt|;
comment|/* not used */
name|char
name|devselect
decl_stmt|;
comment|/* drive selection */
name|char
name|trailcnt
decl_stmt|;
comment|/* trailer Word Count */
name|long
name|err_memadr
decl_stmt|;
comment|/* error memory address */
name|char
name|err_code
decl_stmt|;
comment|/* error codes for SMD/E */
name|char
name|fill2
decl_stmt|;
comment|/* not used */
name|short
name|err_wcount
decl_stmt|;
comment|/* error word count */
name|char
name|err_trk
decl_stmt|;
comment|/* error track/sector */
name|char
name|err_sec
decl_stmt|;
comment|/* error track/sector */
name|short
name|err_cyl
decl_stmt|;
comment|/* error cylinder adr */
union|union
block|{
name|struct
name|trseek
name|sktrail
decl_stmt|;
comment|/* seek command trailer */
block|}
name|trail
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * DCB command codes.  */
end_comment

begin_define
define|#
directive|define
name|VDOP_RD
value|0x80
end_define

begin_comment
comment|/* read data */
end_comment

begin_define
define|#
directive|define
name|VDOP_FTR
value|0xc0
end_define

begin_comment
comment|/* full track read */
end_comment

begin_define
define|#
directive|define
name|VDOP_RAS
value|0x90
end_define

begin_comment
comment|/* read and scatter */
end_comment

begin_define
define|#
directive|define
name|VDOP_RDRAW
value|0x600
end_define

begin_comment
comment|/* read unformatted disk sector */
end_comment

begin_define
define|#
directive|define
name|VDOP_CMP
value|0xa0
end_define

begin_comment
comment|/* compare */
end_comment

begin_define
define|#
directive|define
name|VDOP_FTC
value|0xe0
end_define

begin_comment
comment|/* full track compare */
end_comment

begin_define
define|#
directive|define
name|VDOP_RHDE
value|0x180
end_define

begin_comment
comment|/* read header, data& ecc */
end_comment

begin_define
define|#
directive|define
name|VDOP_WD
value|0x00
end_define

begin_comment
comment|/* write data */
end_comment

begin_define
define|#
directive|define
name|VDOP_FTW
value|0x40
end_define

begin_comment
comment|/* full track write */
end_comment

begin_define
define|#
directive|define
name|VDOP_WTC
value|0x20
end_define

begin_comment
comment|/* write then compare */
end_comment

begin_define
define|#
directive|define
name|VDOP_FTWTC
value|0x60
end_define

begin_comment
comment|/* full track write then compare */
end_comment

begin_define
define|#
directive|define
name|VDOP_GAW
value|0x10
end_define

begin_comment
comment|/* gather and write */
end_comment

begin_define
define|#
directive|define
name|VDOP_WDE
value|0x100
end_define

begin_comment
comment|/* write data& ecc */
end_comment

begin_define
define|#
directive|define
name|VDOP_FSECT
value|0x900
end_define

begin_comment
comment|/* format sector */
end_comment

begin_define
define|#
directive|define
name|VDOP_GWC
value|0x30
end_define

begin_comment
comment|/* gather write& compare */
end_comment

begin_define
define|#
directive|define
name|VDOP_START
value|0x800
end_define

begin_comment
comment|/* start drives */
end_comment

begin_define
define|#
directive|define
name|VDOP_RELEASE
value|0xa00
end_define

begin_comment
comment|/* stop drives */
end_comment

begin_define
define|#
directive|define
name|VDOP_SEEK
value|0xb00
end_define

begin_comment
comment|/* seek */
end_comment

begin_define
define|#
directive|define
name|VDOP_INIT
value|0xc00
end_define

begin_comment
comment|/* initialize controller */
end_comment

begin_define
define|#
directive|define
name|VDOP_DIAG
value|0xd00
end_define

begin_comment
comment|/* diagnose (self-test) controller */
end_comment

begin_define
define|#
directive|define
name|VDOP_CONFIG
value|0xe00
end_define

begin_comment
comment|/* reset& configure drive */
end_comment

begin_define
define|#
directive|define
name|VDOP_STATUS
value|0xf00
end_define

begin_comment
comment|/* get drive status */
end_comment

begin_define
define|#
directive|define
name|VDOP_IDENT
value|0x700
end_define

begin_comment
comment|/* identify controller */
end_comment

begin_define
define|#
directive|define
name|VDOP_ABORT
value|0x80000000
end_define

begin_comment
comment|/* abort current command */
end_comment

begin_comment
comment|/*  * DCB status definitions.  */
end_comment

begin_define
define|#
directive|define
name|DCBS_HCRC
value|0x00000001
end_define

begin_comment
comment|/* header crc error */
end_comment

begin_define
define|#
directive|define
name|DCBS_HCE
value|0x00000002
end_define

begin_comment
comment|/* header compare error */
end_comment

begin_define
define|#
directive|define
name|DCBS_WPT
value|0x00000004
end_define

begin_comment
comment|/* drive write protected */
end_comment

begin_define
define|#
directive|define
name|DCBS_CHE
value|0x00000008
end_define

begin_comment
comment|/* controller hardware error */
end_comment

begin_define
define|#
directive|define
name|DCBS_SKI
value|0x00000010
end_define

begin_comment
comment|/* seek incomplete */
end_comment

begin_define
define|#
directive|define
name|DCBS_UDE
value|0x00000020
end_define

begin_comment
comment|/* uncorrectable data error */
end_comment

begin_define
define|#
directive|define
name|DCBS_OCYL
value|0x00000040
end_define

begin_comment
comment|/* off cylinder */
end_comment

begin_define
define|#
directive|define
name|DCBS_NRDY
value|0x00000080
end_define

begin_comment
comment|/* drive not ready */
end_comment

begin_define
define|#
directive|define
name|DCBS_ATA
value|0x00000100
end_define

begin_comment
comment|/* alternate track accessed */
end_comment

begin_define
define|#
directive|define
name|DCBS_SKS
value|0x00000200
end_define

begin_comment
comment|/* seek started */
end_comment

begin_define
define|#
directive|define
name|DCBS_IVA
value|0x00000400
end_define

begin_comment
comment|/* invalid disk address error */
end_comment

begin_define
define|#
directive|define
name|DCBS_NEM
value|0x00000800
end_define

begin_comment
comment|/* non-existant memory error */
end_comment

begin_define
define|#
directive|define
name|DCBS_DPE
value|0x00001000
end_define

begin_comment
comment|/* memory data parity error */
end_comment

begin_define
define|#
directive|define
name|DCBS_DCE
value|0x00002000
end_define

begin_comment
comment|/* data compare error */
end_comment

begin_define
define|#
directive|define
name|DCBS_DDI
value|0x00004000
end_define

begin_comment
comment|/* ddi ready */
end_comment

begin_define
define|#
directive|define
name|DCBS_OAB
value|0x00008000
end_define

begin_comment
comment|/* operation aborted */
end_comment

begin_define
define|#
directive|define
name|DCBS_DSE
value|0x00010000
end_define

begin_comment
comment|/* data strobe early */
end_comment

begin_define
define|#
directive|define
name|DCBS_DSL
value|0x00020000
end_define

begin_comment
comment|/* data strobe late */
end_comment

begin_define
define|#
directive|define
name|DCBS_TOP
value|0x00040000
end_define

begin_comment
comment|/* track offset plus */
end_comment

begin_define
define|#
directive|define
name|DCBS_TOM
value|0x00080000
end_define

begin_comment
comment|/* track offset minus */
end_comment

begin_define
define|#
directive|define
name|DCBS_CCD
value|0x00100000
end_define

begin_comment
comment|/* controller corrected data */
end_comment

begin_define
define|#
directive|define
name|DCBS_HARD
value|0x00200000
end_define

begin_comment
comment|/* hard error */
end_comment

begin_define
define|#
directive|define
name|DCBS_SOFT
value|0x00400000
end_define

begin_comment
comment|/* soft error (retry succesful) */
end_comment

begin_define
define|#
directive|define
name|DCBS_ERR
value|0x00800000
end_define

begin_comment
comment|/* composite error */
end_comment

begin_define
define|#
directive|define
name|DCBS_IVC
value|0x01000000
end_define

begin_comment
comment|/* invalid command error */
end_comment

begin_comment
comment|/* bits 24-27 unused */
end_comment

begin_define
define|#
directive|define
name|DCBS_BSY
value|0x10000000
end_define

begin_comment
comment|/* controller busy */
end_comment

begin_define
define|#
directive|define
name|DCBS_ICC
value|0x60000000
end_define

begin_comment
comment|/* interrupt cause code */
end_comment

begin_define
define|#
directive|define
name|DCBS_INT
value|0x80000000
end_define

begin_comment
comment|/* interrupt generated for this dcb */
end_comment

begin_define
define|#
directive|define
name|VDERRBITS
value|"\20\1HCRC\2HCE\3WPT\4CHE\5DSKI\6UDE\7OCYL\10NRDY\ \11ATA\12SKS\13IVA\14NEM\15DPE\16DCE\17DDI\20OAB\21DSE\22DSL\23TOP\24TOM\ \25CCD\26HARD\27SOFT\30ERR\31IVC\35ABORTED\36FAIL\37COMPLETE\40STARTED"
end_define

begin_comment
comment|/* drive related errors */
end_comment

begin_define
define|#
directive|define
name|VDERR_DRIVE
value|(DCBS_SKI|DCBS_OCYL|DCBS_NRDY|DCBS_IVA)
end_define

begin_comment
comment|/* controller related errors */
end_comment

begin_define
define|#
directive|define
name|VDERR_CTLR
value|(DCBS_CHE|DCBS_OAB|DCBS_IVC|DCBS_NEM)
end_define

begin_comment
comment|/* potentially recoverable errors */
end_comment

begin_define
define|#
directive|define
name|VDERR_RETRY
define|\
value|(VDERR_DRIVE|VDERR_CTLR|DCBS_DCE|DCBS_DPE|DCBS_HCRC|DCBS_HCE)
end_define

begin_comment
comment|/* uncorrected data errors */
end_comment

begin_define
define|#
directive|define
name|VDERR_HARD
value|(VDERR_RETRY|DCBS_WPT|DCBS_UDE)
end_define

begin_comment
comment|/*  * DCB status codes.  */
end_comment

begin_define
define|#
directive|define
name|DCBS_ABORT
value|0x10000000
end_define

begin_comment
comment|/* dcb aborted */
end_comment

begin_define
define|#
directive|define
name|DCBS_FAIL
value|0x20000000
end_define

begin_comment
comment|/* dcb unsuccesfully completed */
end_comment

begin_define
define|#
directive|define
name|DCBS_DONE
value|0x40000000
end_define

begin_comment
comment|/* dcb complete */
end_comment

begin_define
define|#
directive|define
name|DCBS_START
value|0x80000000
end_define

begin_comment
comment|/* dcb started */
end_comment

begin_comment
comment|/*  * DCB interrupt control.  */
end_comment

begin_define
define|#
directive|define
name|DCBINT_NONE
value|0x0
end_define

begin_comment
comment|/* don't interrupt */
end_comment

begin_define
define|#
directive|define
name|DCBINT_ERR
value|0x2
end_define

begin_comment
comment|/* interrupt on error */
end_comment

begin_define
define|#
directive|define
name|DCBINT_SUC
value|0x1
end_define

begin_comment
comment|/* interrupt on success */
end_comment

begin_define
define|#
directive|define
name|DCBINT_DONE
value|(DCBINT_ERR|DCBINT_SUC)
end_define

begin_define
define|#
directive|define
name|DCBINT_PBA
value|0x4
end_define

begin_comment
comment|/* proceed before acknowledge */
end_comment

begin_comment
comment|/*  * Sector formats.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|dskadr
name|hdr_addr
decl_stmt|;
name|short
name|smd_crc
decl_stmt|;
block|}
name|smd
struct|;
struct|struct
block|{
name|dskadr
name|physical
decl_stmt|;
name|dskadr
name|logical
decl_stmt|;
name|long
name|smd_e_crc
decl_stmt|;
block|}
name|smd_e
struct|;
block|}
name|fmt_hdr
typedef|;
end_typedef

begin_comment
comment|/* Sector Header bit assignments */
end_comment

begin_define
define|#
directive|define
name|VDMF
value|0x8000
end_define

begin_comment
comment|/* Manufacturer Fault 1=good sector */
end_comment

begin_define
define|#
directive|define
name|VDUF
value|0x4000
end_define

begin_comment
comment|/* User Fault 1=good sector */
end_comment

begin_define
define|#
directive|define
name|VDALT
value|0x2000
end_define

begin_comment
comment|/* Alternate Sector 1=alternate */
end_comment

begin_define
define|#
directive|define
name|VDWPT
value|0x1000
end_define

begin_comment
comment|/* Write Protect 1=Read Only Sector */
end_comment

begin_comment
comment|/* input register assignments for DIOCWFORMAT ioctl */
end_comment

begin_define
define|#
directive|define
name|dk_op
value|df_reg[0]
end_define

begin_comment
comment|/* opcode */
end_comment

begin_define
define|#
directive|define
name|dk_althdr
value|df_reg[1]
end_define

begin_comment
comment|/* alt. sect. header, in an int! */
end_comment

begin_define
define|#
directive|define
name|dk_fmtflags
value|df_reg[2]
end_define

begin_comment
comment|/* header format flags */
end_comment

begin_comment
comment|/* output register assignments for DIOCWFORMAT ioctl */
end_comment

begin_define
define|#
directive|define
name|dk_operrsta
value|df_reg[0]
end_define

begin_comment
comment|/* dcb operrsta */
end_comment

begin_define
define|#
directive|define
name|dk_ecode
value|df_reg[1]
end_define

begin_comment
comment|/* smd-e err_code */
end_comment

end_unit

