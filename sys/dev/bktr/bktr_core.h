begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * This is part of the Driver for Video Capture Cards (Frame grabbers)  * and TV Tuner cards using the Brooktree Bt848, Bt848A, Bt849A, Bt878, Bt879  * chipset.  * Copyright Roger Hardiman and Amancio Hasty.  *  * bktr_core : This deals with the Bt848/849/878/879 PCI Frame Grabber,  *               Handles all the open, close, ioctl and read userland calls.  *               Sets the Bt848 registers and generates RISC pograms.  *               Controls the i2c bus and GPIO interface.  *               Contains the interface to the kernel.  *               (eg probe/attach and open/close/ioctl)  *  */
end_comment

begin_comment
comment|/*  * 1. Redistributions of source code must retain the  * Copyright (c) 1997 Amancio Hasty, 1999 Roger Hardiman  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Amancio Hasty and  *      Roger Hardiman  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_function_decl
name|int
name|i2cWrite
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|,
name|int
name|addr
parameter_list|,
name|int
name|byte1
parameter_list|,
name|int
name|byte2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|i2cRead
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|,
name|int
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msp_dpl_reset
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|,
name|int
name|i2d_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|msp_dpl_read
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|,
name|int
name|i2c_addr
parameter_list|,
name|unsigned
name|char
name|dev
parameter_list|,
name|unsigned
name|int
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|msp_dpl_write
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|,
name|int
name|i2c_addr
parameter_list|,
name|unsigned
name|char
name|dev
parameter_list|,
name|unsigned
name|int
name|addr
parameter_list|,
name|unsigned
name|int
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Defines for userland processes blocked in this driver  *   For /dev/bktr[n] use memory address of bktr structure  *   For /dev/vbi[n] use memory address of bktr structure + 1  *                   this is ok as the bktr structure is> 1 byte  */
end_comment

begin_define
define|#
directive|define
name|BKTR_SLEEP
value|((caddr_t)bktr    )
end_define

begin_define
define|#
directive|define
name|VBI_SLEEP
value|((caddr_t)bktr + 1)
end_define

begin_comment
comment|/* device name for printf */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|bktr_name
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Prototypes for attatch and interrupt functions */
end_comment

begin_function_decl
name|void
name|common_bktr_attach
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|,
name|int
name|unit
parameter_list|,
name|u_long
name|pci_id
parameter_list|,
name|u_int
name|rev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|common_bktr_intr
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Prototypes for open, close, read, mmap and ioctl calls */
end_comment

begin_function_decl
name|int
name|video_open
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|video_close
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|video_read
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|,
name|int
name|unit
parameter_list|,
name|dev_t
name|dev
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|video_ioctl
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|,
name|int
name|unit
parameter_list|,
name|ioctl_cmd_t
name|cmd
parameter_list|,
name|caddr_t
name|arg
parameter_list|,
name|struct
name|proc
modifier|*
name|pr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tuner_open
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tuner_close
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tuner_ioctl
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|,
name|int
name|unit
parameter_list|,
name|ioctl_cmd_t
name|cmd
parameter_list|,
name|caddr_t
name|arg
parameter_list|,
name|struct
name|proc
modifier|*
name|pr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vbi_open
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vbi_close
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vbi_read
parameter_list|(
name|bktr_ptr_t
name|bktr
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
name|ioflag
parameter_list|)
function_decl|;
end_function_decl

end_unit

