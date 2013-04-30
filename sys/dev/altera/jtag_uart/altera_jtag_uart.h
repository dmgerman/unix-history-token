begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011-2012 Robert N. M. Watson  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract (FA8750-10-C-0237)  * ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ALTERA_JTAG_UART_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ALTERA_JTAG_UART_H_
end_define

begin_struct
struct|struct
name|altera_jtag_uart_softc
block|{
name|device_t
name|ajus_dev
decl_stmt|;
name|int
name|ajus_unit
decl_stmt|;
comment|/* 	 * Hardware resources. 	 */
name|struct
name|resource
modifier|*
name|ajus_irq_res
decl_stmt|;
name|int
name|ajus_irq_rid
decl_stmt|;
name|void
modifier|*
name|ajus_irq_cookie
decl_stmt|;
name|struct
name|resource
modifier|*
name|ajus_mem_res
decl_stmt|;
name|int
name|ajus_mem_rid
decl_stmt|;
comment|/* 	 * TTY resources. 	 */
name|struct
name|tty
modifier|*
name|ajus_ttyp
decl_stmt|;
name|int
name|ajus_alt_break_state
decl_stmt|;
comment|/* 	 * Driver resources. 	 */
name|u_int
name|ajus_flags
decl_stmt|;
name|struct
name|mtx
modifier|*
name|ajus_lockp
decl_stmt|;
name|struct
name|mtx
name|ajus_lock
decl_stmt|;
name|struct
name|callout
name|ajus_io_callout
decl_stmt|;
name|struct
name|callout
name|ajus_ac_callout
decl_stmt|;
comment|/* 	 * One-character buffer required because it's not possible to peek at 	 * the input FIFO without reading it. 	 */
name|int
name|ajus_buffer_valid
decl_stmt|;
name|int
modifier|*
name|ajus_buffer_validp
decl_stmt|;
name|uint8_t
name|ajus_buffer_data
decl_stmt|;
name|uint8_t
modifier|*
name|ajus_buffer_datap
decl_stmt|;
name|int
name|ajus_jtag_present
decl_stmt|;
name|int
modifier|*
name|ajus_jtag_presentp
decl_stmt|;
name|u_int
name|ajus_jtag_missed
decl_stmt|;
name|u_int
modifier|*
name|ajus_jtag_missedp
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AJU_TTYNAME
value|"ttyj"
end_define

begin_comment
comment|/*  * Flag values for ajus_flags.  */
end_comment

begin_define
define|#
directive|define
name|ALTERA_JTAG_UART_FLAG_CONSOLE
value|0x00000001
end_define

begin_comment
comment|/* Is console. */
end_comment

begin_comment
comment|/*  * Because tty-level use of the I/O ports completes with low-level console  * use, spinlocks must be employed here.  */
end_comment

begin_define
define|#
directive|define
name|AJU_CONSOLE_LOCK_INIT
parameter_list|()
value|do {					\ 	mtx_init(&aju_cons_lock, "aju_cons_lock", NULL, MTX_SPIN);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|AJU_CONSOLE_LOCK
parameter_list|()
value|do {						\ 	if (!kdb_active)						\ 		mtx_lock_spin(&aju_cons_lock);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|AJU_CONSOLE_LOCK_ASSERT
parameter_list|()
value|{					\ 	if (!kdb_active)						\ 		mtx_assert(&aju_cons_lock, MA_OWNED);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|AJU_CONSOLE_UNLOCK
parameter_list|()
value|do {					\ 	if (!kdb_active)						\ 		mtx_unlock_spin(&aju_cons_lock);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|AJU_LOCK_INIT
parameter_list|(
name|sc
parameter_list|)
value|do {						\ 	mtx_init(&(sc)->ajus_lock, "aju_lock", NULL, MTX_SPIN);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|AJU_LOCK_DESTROY
parameter_list|(
name|sc
parameter_list|)
value|do {					\ 	mtx_destroy(&(sc)->ajus_lock);					\ } while (0)
end_define

begin_define
define|#
directive|define
name|AJU_LOCK
parameter_list|(
name|sc
parameter_list|)
value|do {						\ 	mtx_lock_spin((sc)->ajus_lockp);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|AJU_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|do {					\ 	mtx_assert((sc)->ajus_lockp, MA_OWNED);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|AJU_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|do {						\ 	mtx_unlock_spin((sc)->ajus_lockp);				\ } while (0)
end_define

begin_comment
comment|/*  * When a TTY-level Altera JTAG UART instance is also the low-level console,  * the TTY layer borrows the console-layer lock and buffer rather than using  * its own.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|aju_cons_lock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|aju_cons_buffer_data
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|aju_cons_buffer_valid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|aju_cons_jtag_present
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|aju_cons_jtag_missed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Base physical address of the JTAG UART in BERI.  */
end_comment

begin_define
define|#
directive|define
name|BERI_UART_BASE
value|0x7f000000
end_define

begin_comment
comment|/* JTAG UART */
end_comment

begin_comment
comment|/*-  * Routines for interacting with the BERI console JTAG UART.  Programming  * details from the June 2011 "Embedded Peripherals User Guide" by Altera  * Corporation, tables 6-2 (JTAG UART Core Register Map), 6-3 (Data Register  * Bits), and 6-4 (Control Register Bits).  *  * Offsets of data and control registers relative to the base.  Altera  * conventions are maintained in BERI.  */
end_comment

begin_define
define|#
directive|define
name|ALTERA_JTAG_UART_DATA_OFF
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ALTERA_JTAG_UART_CONTROL_OFF
value|0x00000004
end_define

begin_comment
comment|/*  * Offset 0: 'data' register -- bits 31-16 (RAVAIL), 15 (RVALID),  * 14-8 (Reserved), 7-0 (DATA).  *  * DATA - One byte read or written.  * RAVAIL - Bytes available to read (excluding the current byte).  * RVALID - Whether the byte in DATA is valid.  */
end_comment

begin_define
define|#
directive|define
name|ALTERA_JTAG_UART_DATA_DATA
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|ALTERA_JTAG_UART_DATA_RESERVED
value|0x00007f00
end_define

begin_define
define|#
directive|define
name|ALTERA_JTAG_UART_DATA_RVALID
value|0x00008000
end_define

begin_define
define|#
directive|define
name|ALTERA_JTAG_UART_DATA_RAVAIL
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|ALTERA_JTAG_UART_DATA_RAVAIL_SHIFT
value|16
end_define

begin_comment
comment|/*-  * Offset 1: 'control' register -- bits 31-16 (WSPACE), 15-11 (Reserved),  * 10 (AC), 9 (WI), 8 (RI), 7..2 (Reserved), 1 (WE), 0 (RE).  *  * RE - Enable read interrupts.  * WE - Enable write interrupts.  * RI - Read interrupt pending.  * WI - Write interrupt pending.  * AC - Activity bit; set to '1' to clear to '0'.  * WSPACE - Space available in the write FIFO.  */
end_comment

begin_define
define|#
directive|define
name|ALTERA_JTAG_UART_CONTROL_RE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ALTERA_JTAG_UART_CONTROL_WE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ALTERA_JTAG_UART_CONTROL_RESERVED0
value|0x000000fc
end_define

begin_define
define|#
directive|define
name|ALTERA_JTAG_UART_CONTROL_RI
value|0x00000100
end_define

begin_define
define|#
directive|define
name|ALTERA_JTAG_UART_CONTROL_WI
value|0x00000200
end_define

begin_define
define|#
directive|define
name|ALTERA_JTAG_UART_CONTROL_AC
value|0x00000400
end_define

begin_define
define|#
directive|define
name|ALTERA_JTAG_UART_CONTROL_RESERVED1
value|0x0000f800
end_define

begin_define
define|#
directive|define
name|ALTERA_JTAG_UART_CONTROL_WSPACE
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|ALTERA_JTAG_UART_CONTROL_WSPACE_SHIFT
value|16
end_define

begin_comment
comment|/*  * Driver attachment functions for Nexus.  */
end_comment

begin_function_decl
name|int
name|altera_jtag_uart_attach
parameter_list|(
name|struct
name|altera_jtag_uart_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|altera_jtag_uart_detach
parameter_list|(
name|struct
name|altera_jtag_uart_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|devclass_t
name|altera_jtag_uart_devclass
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_ALTERA_JTAG_UART_H_ */
end_comment

end_unit

