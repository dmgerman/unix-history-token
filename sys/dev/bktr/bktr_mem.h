begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * This is prt of the Driver for Video Capture Cards (Frame grabbers)  * and TV Tuner cards using the Brooktree Bt848, Bt848A, Bt849A, Bt878, Bt879  * chipset.  * Copyright Roger Hardiman.  *  * bktr_mem : This kernel module allows us to keep our allocated  *            contiguous memory for the video buffer, DMA programs and VBI data  *            while the main bktr driver is unloaded and reloaded.  *            This avoids the problem of trying to allocate contiguous each  *            time the bktr driver is loaded.  */
end_comment

begin_comment
comment|/*  * 1. Redistributions of source code must retain the  * Copyright (c) 2000 Roger Hardiman  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Roger Hardiman  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* Support this number of devices */
end_comment

begin_define
define|#
directive|define
name|BKTR_MEM_MAX_DEVICES
value|8
end_define

begin_comment
comment|/* Define a name for each block of memory we need to keep hold of */
end_comment

begin_define
define|#
directive|define
name|BKTR_MEM_DMA_PROG
value|1
end_define

begin_define
define|#
directive|define
name|BKTR_MEM_ODD_DMA_PROG
value|2
end_define

begin_define
define|#
directive|define
name|BKTR_MEM_VBIDATA
value|3
end_define

begin_define
define|#
directive|define
name|BKTR_MEM_VBIBUFFER
value|4
end_define

begin_define
define|#
directive|define
name|BKTR_MEM_BUF
value|5
end_define

begin_comment
comment|/* Prototypes */
end_comment

begin_function_decl
name|int
name|bktr_has_stored_addresses
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bktr_store_address
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|type
parameter_list|,
name|vm_offset_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|bktr_retrieve_address
parameter_list|(
name|int
name|unit
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

end_unit

