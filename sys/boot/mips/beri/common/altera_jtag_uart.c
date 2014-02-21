begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011, 2013 Robert N. M. Watson  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract (FA8750-10-C-0237)  * ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"util.h"
end_include

begin_include
include|#
directive|include
file|"mips.h"
end_include

begin_comment
comment|/*-  * Routines for interacting with the CHERI console UART.  Programming details  * from the June 2011 "Embedded Peripherals User Guide" by Altera  * Corporation, tables 6-2 (JTAG UART Core Register Map), 6-3 (Data Register  * Bits), and 6-4 (Control Register Bits).  *  * Hard-coded physical address for the first JTAG UART -- true on all BERI and  * CHERI boards.  */
end_comment

begin_define
define|#
directive|define
name|CHERI_UART_BASE
value|0x7f000000
end_define

begin_comment
comment|/* JTAG UART */
end_comment

begin_comment
comment|/*  *  * Offsets of data and control registers relative to the base.  Altera  * conventions are maintained in CHERI.  */
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
comment|/*  * One-byte buffer as we can't check whether the UART is readable without  * actually reading from it.  */
end_comment

begin_decl_stmt
specifier|static
name|char
name|buffer_data
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|buffer_valid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Low-level read and write register routines; the Altera UART is little  * endian, so we byte swap 32-bit reads and writes.  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|uart_data_read
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|mips_ioread_uint32le
argument_list|(
name|mips_phys_to_uncached
argument_list|(
name|CHERI_UART_BASE
operator|+
name|ALTERA_JTAG_UART_DATA_OFF
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|uart_data_write
parameter_list|(
name|uint32_t
name|v
parameter_list|)
block|{
name|mips_iowrite_uint32le
argument_list|(
name|mips_phys_to_uncached
argument_list|(
name|CHERI_UART_BASE
operator|+
name|ALTERA_JTAG_UART_DATA_OFF
argument_list|)
argument_list|,
name|v
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint32_t
name|uart_control_read
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|mips_ioread_uint32le
argument_list|(
name|mips_phys_to_uncached
argument_list|(
name|CHERI_UART_BASE
operator|+
name|ALTERA_JTAG_UART_CONTROL_OFF
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|uart_control_write
parameter_list|(
name|uint32_t
name|v
parameter_list|)
block|{
name|mips_iowrite_uint32le
argument_list|(
name|mips_phys_to_uncached
argument_list|(
name|CHERI_UART_BASE
operator|+
name|ALTERA_JTAG_UART_DATA_OFF
argument_list|)
argument_list|,
name|v
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|uart_writable
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
operator|(
name|uart_control_read
argument_list|()
operator|&
name|ALTERA_JTAG_UART_CONTROL_WSPACE
operator|)
operator|!=
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|uart_readable
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|v
decl_stmt|;
if|if
condition|(
name|buffer_valid
condition|)
return|return
operator|(
literal|1
operator|)
return|;
name|v
operator|=
name|uart_data_read
argument_list|()
expr_stmt|;
if|if
condition|(
operator|(
name|v
operator|&
name|ALTERA_JTAG_UART_DATA_RVALID
operator|)
operator|!=
literal|0
condition|)
block|{
name|buffer_valid
operator|=
literal|1
expr_stmt|;
name|buffer_data
operator|=
operator|(
name|v
operator|&
name|ALTERA_JTAG_UART_DATA_DATA
operator|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|int
name|keyhit
parameter_list|(
name|int
name|seconds
parameter_list|)
block|{
name|register_t
name|stoptime
decl_stmt|;
name|stoptime
operator|=
name|cp0_count_get
argument_list|()
operator|+
name|seconds
operator|*
literal|100000000
expr_stmt|;
comment|/* 100 MHz. */
do|do
block|{
if|if
condition|(
name|uart_readable
argument_list|()
condition|)
return|return
operator|(
literal|1
operator|)
return|;
block|}
do|while
condition|(
name|cp0_count_get
argument_list|()
operator|<
name|stoptime
condition|)
do|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|int
name|getc
parameter_list|(
name|void
parameter_list|)
block|{
while|while
condition|(
operator|!
operator|(
name|uart_readable
argument_list|()
operator|)
condition|)
empty_stmt|;
name|buffer_valid
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|buffer_data
operator|)
return|;
block|}
end_function

begin_function
name|void
name|putc
parameter_list|(
name|int
name|ch
parameter_list|)
block|{
name|uart_data_write
argument_list|(
name|ch
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

