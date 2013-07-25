begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * sioemu.h  *  * Copyright (c) 2008 Tristan Gingold<tgingold@free.fr>  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_IA64_SIOEMU_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_IA64_SIOEMU_H__
end_define

begin_comment
comment|/* SIOEMU specific hypercalls.    The numbers are the minor part of FW_HYPERCALL_SIOEMU.  */
end_comment

begin_comment
comment|/* Defines the callback entry point.  r8=ip, r9=data.    Must be called per-vcpu.  */
end_comment

begin_define
define|#
directive|define
name|SIOEMU_HYPERCALL_SET_CALLBACK
value|0x01
end_define

begin_comment
comment|/* Finish sioemu fw initialization and start firmware.  r8=ip.  */
end_comment

begin_define
define|#
directive|define
name|SIOEMU_HYPERCALL_START_FW
value|0x02
end_define

begin_comment
comment|/* Add IO pages in physmap.  */
end_comment

begin_define
define|#
directive|define
name|SIOEMU_HYPERCALL_ADD_IO_PHYSMAP
value|0x03
end_define

begin_comment
comment|/* Get wallclock time.  */
end_comment

begin_define
define|#
directive|define
name|SIOEMU_HYPERCALL_GET_TIME
value|0x04
end_define

begin_comment
comment|/* Flush cache.  */
end_comment

begin_define
define|#
directive|define
name|SIOEMU_HYPERCALL_FLUSH_CACHE
value|0x07
end_define

begin_comment
comment|/* Get freq base.  */
end_comment

begin_define
define|#
directive|define
name|SIOEMU_HYPERCALL_FREQ_BASE
value|0x08
end_define

begin_comment
comment|/* Return from callback.  */
end_comment

begin_define
define|#
directive|define
name|SIOEMU_HYPERCALL_CALLBACK_RETURN
value|0x09
end_define

begin_comment
comment|/* Deliver an interrupt.  */
end_comment

begin_define
define|#
directive|define
name|SIOEMU_HYPERCALL_DELIVER_INT
value|0x0a
end_define

begin_comment
comment|/* SIOEMU callback reason.  */
end_comment

begin_comment
comment|/* An event (from event channel) has to be delivered.  */
end_comment

begin_define
define|#
directive|define
name|SIOEMU_CB_EVENT
value|0x00
end_define

begin_comment
comment|/* Emulate an IO access.  */
end_comment

begin_define
define|#
directive|define
name|SIOEMU_CB_IO_EMULATE
value|0x01
end_define

begin_comment
comment|/* An IPI is sent to a dead vcpu.  */
end_comment

begin_define
define|#
directive|define
name|SIOEMU_CB_WAKEUP_VCPU
value|0x02
end_define

begin_comment
comment|/* A SAL hypercall is executed.  */
end_comment

begin_define
define|#
directive|define
name|SIOEMU_CB_SAL_ASSIST
value|0x03
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLY__
end_ifndef

begin_struct
struct|struct
name|sioemu_callback_info
block|{
comment|/* Saved registers.  */
name|unsigned
name|long
name|ip
decl_stmt|;
name|unsigned
name|long
name|psr
decl_stmt|;
name|unsigned
name|long
name|ifs
decl_stmt|;
name|unsigned
name|long
name|nats
decl_stmt|;
name|unsigned
name|long
name|r8
decl_stmt|;
name|unsigned
name|long
name|r9
decl_stmt|;
name|unsigned
name|long
name|r10
decl_stmt|;
name|unsigned
name|long
name|r11
decl_stmt|;
comment|/* Callback parameters.  */
name|unsigned
name|long
name|cause
decl_stmt|;
name|unsigned
name|long
name|arg0
decl_stmt|;
name|unsigned
name|long
name|arg1
decl_stmt|;
name|unsigned
name|long
name|arg2
decl_stmt|;
name|unsigned
name|long
name|arg3
decl_stmt|;
name|unsigned
name|long
name|_pad2
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|long
name|r2
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ASSEMBLY__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_IA64_SIOEMU_H__ */
end_comment

end_unit

