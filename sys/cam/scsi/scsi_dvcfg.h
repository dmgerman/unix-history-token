begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$NecBSD: scsi_dvcfg.h,v 1.4 1998/03/14 07:05:06 kmatsuda Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD$	*/
end_comment

begin_comment
comment|/*  * [NetBSD for NEC PC-98 series]  *  Copyright (c) 1994, 1995, 1996, 1997, 1998  *	NetBSD/pc98 porting staff. All rights reserved.  *  Copyright (c) 1994, 1995, 1996, 1997, 1998  *	Naofumi HONDA. All rights reserved.  *   *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  3. The name of the author may not be used to endorse or promote products  *     derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCSI_DVCFG_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCSI_DVCFG_H_
end_define

begin_comment
comment|/* common dvcfg flags defitions for bs, ncv, stg */
end_comment

begin_define
define|#
directive|define
name|DVF_SCSI_SYNC
value|0x01
end_define

begin_define
define|#
directive|define
name|DVF_SCSI_DISC
value|0x02
end_define

begin_define
define|#
directive|define
name|DVF_SCSI_WAIT
value|0x04
end_define

begin_define
define|#
directive|define
name|DVF_SCSI_LINK
value|0x08
end_define

begin_define
define|#
directive|define
name|DVF_SCSI_QTAG
value|0x10
end_define

begin_define
define|#
directive|define
name|DVF_SCSI_SP0
value|0x100
end_define

begin_define
define|#
directive|define
name|DVF_SCSI_NOPARITY
value|0x200
end_define

begin_define
define|#
directive|define
name|DVF_SCSI_SAVESP
value|0x400
end_define

begin_define
define|#
directive|define
name|DVF_SCSI_SP1
value|0x800
end_define

begin_define
define|#
directive|define
name|DVF_SCSI_PERIOD
parameter_list|(
name|XXX
parameter_list|)
value|(((XXX)>> 24)& 0xff)
end_define

begin_define
define|#
directive|define
name|DVF_SCSI_OFFSET
parameter_list|(
name|XXX
parameter_list|)
value|(((XXX)>> 16)& 0xff)
end_define

begin_define
define|#
directive|define
name|DVF_SCSI_SYNCMASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|DVF_SCSI_DEFCFG
value|(DVF_SCSI_SYNC | DVF_SCSI_NOPARITY | DVF_SCSI_SYNCMASK)
end_define

begin_define
define|#
directive|define
name|DVF_SCSI_BITS
value|"\020\13fssp\12noparity\11nosat\005qtag\004cmdlnk\003wait\002disc\001sync"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SCSI_DVCFG_H_ */
end_comment

end_unit

