begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  *	Copyright (C) 1994, Paul S. LaFollette, Jr. This software may be used,  *	modified, copied, distributed, and sold, in both source and binary form  *	provided that the above copyright and these terms are retained. Under  *	no circumstances is the author responsible for the proper functioning  *	of this software, nor does the author assume any responsibility  *	for damages incurred with its use  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *	Register and bit definitions for CORTEX-I frame grabber  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_ISA_CTXREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_I386_ISA_CTXREG_H_
end_define

begin_comment
comment|/*  Control Ports (all are write-only) */
end_comment

begin_define
define|#
directive|define
name|ctx_cp0
value|0
end_define

begin_comment
comment|/*	offset to control port 0   */
end_comment

begin_define
define|#
directive|define
name|ctx_cp1
value|1
end_define

begin_comment
comment|/*	offset to control port 1   */
end_comment

begin_define
define|#
directive|define
name|ctx_lutaddr
value|2
end_define

begin_comment
comment|/*	offset to lut address port */
end_comment

begin_define
define|#
directive|define
name|ctx_lutdata
value|3
end_define

begin_comment
comment|/*	offset to lut data port	   */
end_comment

begin_comment
comment|/*  Status port (read-only but same address as control port 0)  */
end_comment

begin_define
define|#
directive|define
name|ctx_status
value|0
end_define

begin_comment
comment|/*	offset to status port 	   */
end_comment

begin_comment
comment|/*  Bit assignments for control port 0 */
end_comment

begin_define
define|#
directive|define
name|PAGE_SELECT0
value|1
end_define

begin_comment
comment|/* These two bits choose which 1/4 of the   */
end_comment

begin_define
define|#
directive|define
name|PAGE_SELECT1
value|2
end_define

begin_comment
comment|/* video memory is accessible to us.        */
end_comment

begin_define
define|#
directive|define
name|PAGE_ROTATE
value|4
end_define

begin_comment
comment|/* 0 => horizontal access. 1 => vertical    */
end_comment

begin_define
define|#
directive|define
name|ACQUIRE
value|8
end_define

begin_comment
comment|/* set to start frame grab		    */
end_comment

begin_define
define|#
directive|define
name|SEE_STORED_VIDEO
value|16
end_define

begin_comment
comment|/* set to allow stored frame to be seen     */
end_comment

begin_define
define|#
directive|define
name|LOW_RESOLUTION
value|32
end_define

begin_comment
comment|/* set to enable 256 x 256 mode		    */
end_comment

begin_comment
comment|/*  Bit assignments for control port 1 */
end_comment

begin_define
define|#
directive|define
name|INTERRUPT_ENABLE
value|1
end_define

begin_comment
comment|/* Allow interrupts (we avoid this bit)     */
end_comment

begin_define
define|#
directive|define
name|TRIGGER_ENABLE
value|2
end_define

begin_comment
comment|/* Enable external trigger for frame grab   */
end_comment

begin_define
define|#
directive|define
name|LUT_LOAD_ENABLE
value|4
end_define

begin_comment
comment|/* Allow loading of lookup table	    */
end_comment

begin_define
define|#
directive|define
name|BLANK_DISPLAY
value|8
end_define

begin_comment
comment|/* Turn off display 		            */
end_comment

begin_define
define|#
directive|define
name|AB_SELECT
value|16
end_define

begin_comment
comment|/* Along with HW switch, choose base memory */
end_comment

begin_define
define|#
directive|define
name|RAM_ENABLE
value|32
end_define

begin_comment
comment|/* Connect video RAM to computer bus	    */
end_comment

begin_comment
comment|/*  Bit assignments for status port */
end_comment

begin_define
define|#
directive|define
name|INTERRUPT_STATUS
value|1
end_define

begin_comment
comment|/* Ignored by us			    */
end_comment

begin_define
define|#
directive|define
name|ADC_OVERFLOW
value|2
end_define

begin_comment
comment|/* Set if any pixes from camera "too bright"*/
end_comment

begin_define
define|#
directive|define
name|FIELD
value|4
end_define

begin_comment
comment|/* 0 or 1 shows which interlace field are in*/
end_comment

begin_define
define|#
directive|define
name|VERTICAL_BLANK
value|8
end_define

begin_comment
comment|/* 1 if in vertical blanking interval       */
end_comment

begin_define
define|#
directive|define
name|TRIGGERED
value|16
end_define

begin_comment
comment|/* 1 if HW trigger contacts closed	    */
end_comment

begin_define
define|#
directive|define
name|ACQUIRING_ACK
value|32
end_define

begin_comment
comment|/* 1 if currently grabbing a frame          */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifndef  _I386_ISA_CTXREG_H_ */
end_comment

end_unit

