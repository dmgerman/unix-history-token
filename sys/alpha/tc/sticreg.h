begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: sticreg.h,v 1.1 1997/11/08 07:27:50 jonathan Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1997 Jonathan Stone  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Jonathan Stone for  *      the NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*   * Register definitions for the pixelstamp and stamp interface  chip (STIC)  * used in PMAG-C 2-d and PMAG-D 3-d accelerated TurboChannel framebuffers.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TC_STICREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_TC_STICREG_H_
end_define

begin_struct
struct|struct
name|stic_regs
block|{
specifier|volatile
name|int32_t
name|stic__pad0
decl_stmt|,
name|__pad1
decl_stmt|;
specifier|volatile
name|int32_t
name|hsync
decl_stmt|;
specifier|volatile
name|int32_t
name|hsync2
decl_stmt|;
specifier|volatile
name|int32_t
name|hblank
decl_stmt|;
specifier|volatile
name|int32_t
name|vsync
decl_stmt|;
specifier|volatile
name|int32_t
name|vblank
decl_stmt|;
specifier|volatile
name|int32_t
name|vtest
decl_stmt|;
specifier|volatile
name|int32_t
name|ipdvint
decl_stmt|;
specifier|volatile
name|int32_t
name|stic__pad2
decl_stmt|;
specifier|volatile
name|int32_t
name|sticsr
decl_stmt|;
specifier|volatile
name|int32_t
name|busdat
decl_stmt|;
specifier|volatile
name|int32_t
name|busadr
decl_stmt|;
specifier|volatile
name|int32_t
name|stic__pad3
decl_stmt|;
specifier|volatile
name|int32_t
name|buscsr
decl_stmt|;
specifier|volatile
name|int32_t
name|modcl
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|STICADDR
parameter_list|(
name|x
parameter_list|)
value|((volatile struct stic_regs*) (x))
end_define

begin_comment
comment|/*  * Bit definitions for stic_regs.stic_csr.  * these appear to exactly what the PROM tests use.  */
end_comment

begin_define
define|#
directive|define
name|STIC_CSR_TSTFNC
value|0x00000003
end_define

begin_define
define|#
directive|define
name|STIC_CSR_TSTFNC_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|STIC_CSR_TSTFNC_PARITY
value|1
end_define

begin_define
define|#
directive|define
name|STIC_CSR_TSTFNC_CNTPIX
value|2
end_define

begin_define
define|#
directive|define
name|STIC_CSR_TSTFNC_TSTDAC
value|3
end_define

begin_define
define|#
directive|define
name|STIC_CSR_CHECKPAR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|STIC_CSR_STARTVT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|STIC_CSR_START
value|0x00000020
end_define

begin_define
define|#
directive|define
name|STIC_CSR_RESET
value|0x00000040
end_define

begin_define
define|#
directive|define
name|STIC_CSR_STARTST
value|0x00000080
end_define

begin_comment
comment|/*  * Bit definitions for stic_regs.int.  * Three four-bit wide fields, for error (E), vertical-blank (V), and   * packetbuf-done (P) intererupts, respectively.   * The low-order three bits of each field are enable, requested,  * and acknowledge bits. The top bit of each field is unused.  */
end_comment

begin_define
define|#
directive|define
name|STIC_INT_E_EN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|STIC_INT_E
value|0x00000002
end_define

begin_define
define|#
directive|define
name|STIC_INT_E_WE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|STIC_INT_V_EN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|STIC_INT_V
value|0x00000200
end_define

begin_define
define|#
directive|define
name|STIC_INT_V_WE
value|0x00000400
end_define

begin_define
define|#
directive|define
name|STIC_INT_P_EN
value|0x00010000
end_define

begin_define
define|#
directive|define
name|STIC_INT_P
value|0x00020000
end_define

begin_define
define|#
directive|define
name|STIC_INT_P_WE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|STIC_INT_WE
value|(STIC_INT_E_WE|STIC_INT_V_WE|STIC_INT_PE_WE)
end_define

begin_define
define|#
directive|define
name|STIC_INT_CLR
value|(STIC_INT_E_EN|STIC_INT_V_EN|STIC_INT_P_EN)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TC_STICREG_H_ */
end_comment

end_unit

