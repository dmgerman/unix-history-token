begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003 by Peter Grehan. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POWERPC_POWERMAC_HROWPICVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_POWERPC_POWERMAC_HROWPICVAR_H_
end_define

begin_define
define|#
directive|define
name|HROWPIC_IRQMAX
value|64
end_define

begin_define
define|#
directive|define
name|HROWPIC_IRQ_REGNUM
value|32
end_define

begin_comment
comment|/* irqs per register */
end_comment

begin_define
define|#
directive|define
name|HROWPIC_IRQ_SHIFT
value|5
end_define

begin_comment
comment|/* high or low irq word */
end_comment

begin_define
define|#
directive|define
name|HROWPIC_IRQ_MASK
value|((HROWPIC_IRQMAX-1)>> 1)
end_define

begin_comment
comment|/* irq bit pos in word */
end_comment

begin_comment
comment|/*  * Register offsets within bank. There are two identical banks,  * separated by 16 bytes. Interrupts 0->31 are processed in the  * second bank, and 32->63 in the first bank.  */
end_comment

begin_define
define|#
directive|define
name|HPIC_STATUS
value|0x00
end_define

begin_comment
comment|/* active interrupt sources */
end_comment

begin_define
define|#
directive|define
name|HPIC_ENABLE
value|0x04
end_define

begin_comment
comment|/* interrupt asserts ppc EXTINT */
end_comment

begin_define
define|#
directive|define
name|HPIC_CLEAR
value|0x08
end_define

begin_comment
comment|/* clear int source */
end_comment

begin_define
define|#
directive|define
name|HPIC_TRIGGER
value|0x0c
end_define

begin_comment
comment|/* edge/level int trigger */
end_comment

begin_define
define|#
directive|define
name|HPIC_PRIMARY
value|1
end_define

begin_comment
comment|/* primary register bank */
end_comment

begin_define
define|#
directive|define
name|HPIC_SECONDARY
value|0
end_define

begin_comment
comment|/* secondary register bank */
end_comment

begin_comment
comment|/*  * Convert an interrupt into a prim/sec bank number  */
end_comment

begin_define
define|#
directive|define
name|HPIC_INT_TO_BANK
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x)>> HROWPIC_IRQ_SHIFT) ^ 1)
end_define

begin_comment
comment|/*  * Convert an interrupt into the bit number within a bank register  */
end_comment

begin_define
define|#
directive|define
name|HPIC_INT_TO_REGBIT
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)& HROWPIC_IRQ_MASK)
end_define

begin_define
define|#
directive|define
name|HPIC_1ST_OFFSET
value|0x10
end_define

begin_comment
comment|/* offset to primary reg bank */
end_comment

begin_struct
struct|struct
name|hrowpic_softc
block|{
name|struct
name|rman
name|sc_rman
decl_stmt|;
comment|/* resource mgr for IRQs */
name|u_int32_t
name|sc_irq
index|[
name|HROWPIC_IRQMAX
index|]
decl_stmt|;
comment|/* allocated IRQ flags */
name|u_int32_t
name|sc_softreg
index|[
literal|2
index|]
decl_stmt|;
comment|/* ENABLE reg copy */
name|device_t
name|sc_maciodev
decl_stmt|;
comment|/* macio device */
name|struct
name|resource
modifier|*
name|sc_memr
decl_stmt|;
comment|/* macio bus resource */
name|bus_space_tag_t
name|sc_bt
decl_stmt|;
comment|/* macio bus tag/handle */
name|bus_space_handle_t
name|sc_bh
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POWERPC_POWERMAC_HROWPICVAR_H_ */
end_comment

end_unit

