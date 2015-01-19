begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$NecBSD: nspvar.h,v 1.7.14.5 2001/06/29 06:27:54 honda Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD$	*/
end_comment

begin_comment
comment|/*-  * [NetBSD for NEC PC-98 series]  *  Copyright (c) 1998, 1999, 2000, 2001  *	NetBSD/pc98 porting staff. All rights reserved.  *  *  Copyright (c) 1998, 1999, 2000, 2001  *	Naofumi HONDA. All rights reserved.  *   *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  3. The name of the author may not be used to endorse or promote products  *     derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NSPVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NSPVAR_H_
end_define

begin_comment
comment|/*****************************************************************  * Host adapter structure  *****************************************************************/
end_comment

begin_struct
struct|struct
name|nsp_softc
block|{
name|struct
name|scsi_low_softc
name|sc_sclow
decl_stmt|;
comment|/* generic data */
name|int
name|port_rid
decl_stmt|;
name|int
name|irq_rid
decl_stmt|;
name|int
name|mem_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|port_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|mem_res
decl_stmt|;
name|void
modifier|*
name|nsp_intrhand
decl_stmt|;
name|int
name|sc_tmaxcnt
decl_stmt|;
comment|/* timeout count */
name|int
name|sc_seltout
decl_stmt|;
comment|/* selection timeout counter */
name|int
name|sc_timer
decl_stmt|;
comment|/* timer start */
name|int
name|sc_suspendio
decl_stmt|;
comment|/* SMIT: data suspendio bytes */
name|u_int8_t
name|sc_xfermr
decl_stmt|;
comment|/* SMIT: fifo control reg */
name|int
name|sc_dataout_timeout
decl_stmt|;
comment|/* data out timeout counter */
name|u_int
name|sc_idbit
decl_stmt|;
comment|/* host id bit pattern */
name|u_int
name|sc_cnt
decl_stmt|;
comment|/* fifo R/W count (host) */
name|u_int8_t
name|sc_iclkdiv
decl_stmt|;
comment|/* scsi chip clock divisor */
name|u_int8_t
name|sc_clkdiv
decl_stmt|;
comment|/* asic chip clock divisor */
name|u_int8_t
name|sc_icr
decl_stmt|;
comment|/* interrupt control reg */
name|u_int8_t
name|sc_busc
decl_stmt|;
comment|/* busc registers */
name|u_int8_t
name|sc_parr
decl_stmt|;
comment|/* parity control register */
block|}
struct|;
end_struct

begin_comment
comment|/*****************************************************************  * Lun information   *****************************************************************/
end_comment

begin_struct
struct|struct
name|nsp_targ_info
block|{
name|struct
name|targ_info
name|nti_ti
decl_stmt|;
comment|/* generic lun info */
name|u_int8_t
name|nti_reg_syncr
decl_stmt|;
comment|/* sync registers per devices */
name|u_int8_t
name|nti_reg_ackwidth
decl_stmt|;
comment|/* ackwidth per devices */
block|}
struct|;
end_struct

begin_comment
comment|/*****************************************************************  * Proto  *****************************************************************/
end_comment

begin_function_decl
name|int
name|nspprobesubr
parameter_list|(
name|struct
name|resource
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nspattachsubr
parameter_list|(
name|struct
name|nsp_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nspintr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NSPVAR_H_ */
end_comment

end_unit

