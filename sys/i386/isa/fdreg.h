begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)fdreg.h	7.1 (Berkeley) 5/9/91  *	$Id: fdreg.h,v 1.2 1993/10/16 13:45:50 rgrimes Exp $  */
end_comment

begin_comment
comment|/*  * AT floppy controller registers and bitfields  */
end_comment

begin_comment
comment|/* uses NEC765 controller */
end_comment

begin_include
include|#
directive|include
file|"../i386/isa/ic/nec765.h"
end_include

begin_comment
comment|/* registers */
end_comment

begin_define
define|#
directive|define
name|fdout
value|2
end_define

begin_comment
comment|/* Digital Output Register (W) */
end_comment

begin_define
define|#
directive|define
name|FDO_FDSEL
value|0x03
end_define

begin_comment
comment|/*  floppy device select */
end_comment

begin_define
define|#
directive|define
name|FDO_FRST
value|0x04
end_define

begin_comment
comment|/*  floppy controller reset */
end_comment

begin_define
define|#
directive|define
name|FDO_FDMAEN
value|0x08
end_define

begin_comment
comment|/*  enable floppy DMA and Interrupt */
end_comment

begin_define
define|#
directive|define
name|FDO_MOEN0
value|0x10
end_define

begin_comment
comment|/*  motor enable drive 0 */
end_comment

begin_define
define|#
directive|define
name|FDO_MOEN1
value|0x20
end_define

begin_comment
comment|/*  motor enable drive 1 */
end_comment

begin_define
define|#
directive|define
name|FDO_MOEN2
value|0x30
end_define

begin_comment
comment|/*  motor enable drive 2 */
end_comment

begin_define
define|#
directive|define
name|FDO_MOEN3
value|0x40
end_define

begin_comment
comment|/*  motor enable drive 3 */
end_comment

begin_define
define|#
directive|define
name|fdsts
value|4
end_define

begin_comment
comment|/* NEC 765 Main Status Register (R) */
end_comment

begin_define
define|#
directive|define
name|fddata
value|5
end_define

begin_comment
comment|/* NEC 765 Data Register (R/W) */
end_comment

begin_define
define|#
directive|define
name|fdctl
value|7
end_define

begin_comment
comment|/* Control Register (W) */
end_comment

begin_define
define|#
directive|define
name|FDC_500KBPS
value|0x00
end_define

begin_comment
comment|/* 500KBPS MFM drive transfer rate */
end_comment

begin_define
define|#
directive|define
name|FDC_300KBPS
value|0x01
end_define

begin_comment
comment|/* 300KBPS MFM drive transfer rate */
end_comment

begin_define
define|#
directive|define
name|FDC_250KBPS
value|0x02
end_define

begin_comment
comment|/* 250KBPS MFM drive transfer rate */
end_comment

begin_define
define|#
directive|define
name|FDC_125KBPS
value|0x03
end_define

begin_comment
comment|/* 125KBPS FM drive transfer rate */
end_comment

begin_define
define|#
directive|define
name|fdin
value|7
end_define

begin_comment
comment|/* Digital Input Register (R) */
end_comment

begin_define
define|#
directive|define
name|FDI_DCHG
value|0x80
end_define

begin_comment
comment|/* diskette has been changed */
end_comment

begin_comment
comment|/***********************************************************************\ * Per controller structure.						* \***********************************************************************/
end_comment

begin_struct
struct|struct
name|fdc_data
block|{
name|int
name|fdcu
decl_stmt|;
comment|/* our unit number */
name|int
name|baseport
decl_stmt|;
name|int
name|dmachan
decl_stmt|;
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|FDC_ATTACHED
value|0x01
define|#
directive|define
name|FDC_HASFTAPE
value|0x02
define|#
directive|define
name|FDC_TAPE_BUSY
value|0x04
name|struct
name|fd_data
modifier|*
name|fd
decl_stmt|;
name|int
name|fdu
decl_stmt|;
comment|/* the active drive	*/
name|struct
name|buf
name|head
decl_stmt|;
comment|/* Head of buf chain      */
name|struct
name|buf
name|rhead
decl_stmt|;
comment|/* Raw head of buf chain  */
name|int
name|state
decl_stmt|;
name|int
name|retry
decl_stmt|;
name|int
name|status
index|[
literal|7
index|]
decl_stmt|;
comment|/* copy of the registers */
block|}
struct|;
end_struct

begin_comment
comment|/***********************************************************************\ * Throughout this file the following conventions will be used:		* * fd is a pointer to the fd_data struct for the drive in question	* * fdc is a pointer to the fdc_data struct for the controller		* * fdu is the floppy drive unit number					* * fdcu is the floppy controller unit number				* * fdsu is the floppy drive unit number on that controller. (sub-unit)	* \***********************************************************************/
end_comment

begin_typedef
typedef|typedef
name|int
name|fdu_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|fdcu_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|fdsu_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|fd_data
modifier|*
name|fd_p
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|fdc_data
modifier|*
name|fdc_p
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FDUNIT
parameter_list|(
name|s
parameter_list|)
value|(((s)>>6)&03)
end_define

begin_define
define|#
directive|define
name|FDTYPE
parameter_list|(
name|s
parameter_list|)
value|((s)&077)
end_define

end_unit

