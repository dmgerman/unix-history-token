begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$NecBSD: ncr53c500hw.h,v 1.6 1998/11/26 01:59:12 honda Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD$	*/
end_comment

begin_comment
comment|/*  * [NetBSD for NEC PC-98 series]  *  Copyright (c) 1996, 1997, 1998  *	NetBSD/pc98 porting staff. All rights reserved.  *  Copyright (c) 1996, 1997, 1998  *	Naofumi HONDA. All rights reserved.  *   *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  3. The name of the author may not be used to endorse or promote products  *     derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NCR53C500HW_H_
end_ifndef

begin_define
define|#
directive|define
name|__NCR53C500HW_H_
end_define

begin_include
include|#
directive|include
file|<machine/dvcfg.h>
end_include

begin_define
define|#
directive|define
name|NCV_HOSTID
value|7
end_define

begin_define
define|#
directive|define
name|NCV_NTARGETS
value|8
end_define

begin_define
define|#
directive|define
name|NCV_NLUNS
value|8
end_define

begin_struct
struct|struct
name|ncv_hw
block|{
comment|/* configuration images */
name|u_int8_t
name|hw_cfg1
decl_stmt|;
name|u_int8_t
name|hw_cfg2
decl_stmt|;
name|u_int8_t
name|hw_cfg3
decl_stmt|;
name|u_int8_t
name|hw_cfg4
decl_stmt|;
name|u_int8_t
name|hw_cfg5
decl_stmt|;
comment|/* synch */
name|u_int8_t
name|hw_clk
decl_stmt|;
name|u_int8_t
name|hw_mperiod
decl_stmt|;
name|u_int8_t
name|hw_moffset
decl_stmt|;
comment|/* cfg3 quirks */
name|u_int8_t
name|hw_cfg3_fscsi
decl_stmt|;
name|u_int8_t
name|hw_cfg3_fclk
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* dvcfg */
end_comment

begin_define
define|#
directive|define
name|NCV_C5IMG
parameter_list|(
name|flags
parameter_list|)
value|((DVCFG_MAJOR(flags)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|NCV_CLKFACTOR
parameter_list|(
name|flags
parameter_list|)
value|(DVCFG_MAJOR(flags)& 0x0f)
end_define

begin_define
define|#
directive|define
name|NCVHWCFG_MAX10M
value|0x01
end_define

begin_define
define|#
directive|define
name|NCVHWCFG_SCSI1
value|0x02
end_define

begin_define
define|#
directive|define
name|NCVHWCFG_SLOW
value|0x04
end_define

begin_define
define|#
directive|define
name|NCVHWCFG_FIFOBUG
value|0x08
end_define

begin_define
define|#
directive|define
name|NCV_SPECIAL
parameter_list|(
name|flags
parameter_list|)
value|((DVCFG_MAJOR(flags)>> 4)& 0x0f)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__NCR53C500HW_H_ */
end_comment

end_unit

