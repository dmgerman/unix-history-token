begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Michael Smith  * Copyright (c) 2000 Scott Long  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * Command queue statistics  */
end_comment

begin_define
define|#
directive|define
name|AACQ_FREE
value|0
end_define

begin_define
define|#
directive|define
name|AACQ_BIO
value|1
end_define

begin_define
define|#
directive|define
name|AACQ_READY
value|2
end_define

begin_define
define|#
directive|define
name|AACQ_BUSY
value|3
end_define

begin_define
define|#
directive|define
name|AACQ_COMPLETE
value|4
end_define

begin_define
define|#
directive|define
name|AACQ_COUNT
value|5
end_define

begin_comment
comment|/* total number of queues */
end_comment

begin_struct
struct|struct
name|aac_qstat
block|{
name|u_int32_t
name|q_length
decl_stmt|;
name|u_int32_t
name|q_max
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Statistics request  */
end_comment

begin_union
union|union
name|aac_statrequest
block|{
name|u_int32_t
name|as_item
decl_stmt|;
name|struct
name|aac_qstat
name|as_qstat
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|AACIO_STATS
value|_IOWR('T', 101, union aac_statrequest)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|AAC_COMPAT_LINUX
end_ifdef

begin_comment
comment|/*  * Ioctl commands likely to be submitted from a Linux management application.  * These bit encodings are actually descended from Windows NT.  Ick.  */
end_comment

begin_define
define|#
directive|define
name|CTL_CODE
parameter_list|(
name|devType
parameter_list|,
name|func
parameter_list|,
name|meth
parameter_list|,
name|acc
parameter_list|)
value|(((devType)<< 16) | ((acc)<< 14) | ((func)<< 2) | (meth))
end_define

begin_define
define|#
directive|define
name|METHOD_BUFFERED
value|0
end_define

begin_define
define|#
directive|define
name|METHOD_IN_DIRECT
value|1
end_define

begin_define
define|#
directive|define
name|METHOD_OUT_DIRECT
value|2
end_define

begin_define
define|#
directive|define
name|METHOD_NEITHER
value|3
end_define

begin_define
define|#
directive|define
name|FILE_ANY_ACCESS
value|0
end_define

begin_define
define|#
directive|define
name|FILE_READ_ACCESS
value|( 0x0001 )
end_define

begin_define
define|#
directive|define
name|FILE_WRITE_ACCESS
value|( 0x0002 )
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_CONTROLLER
value|0x00000004
end_define

begin_define
define|#
directive|define
name|FSACTL_SENDFIB
value|CTL_CODE(FILE_DEVICE_CONTROLLER, 2050, METHOD_BUFFERED, FILE_ANY_ACCESS)
end_define

begin_define
define|#
directive|define
name|FSACTL_AIF_THREAD
value|CTL_CODE(FILE_DEVICE_CONTROLLER, 2127, METHOD_NEITHER, FILE_ANY_ACCESS)
end_define

begin_define
define|#
directive|define
name|FSACTL_OPEN_GET_ADAPTER_FIB
value|CTL_CODE(FILE_DEVICE_CONTROLLER, 2100, METHOD_BUFFERED, FILE_ANY_ACCESS)
end_define

begin_define
define|#
directive|define
name|FSACTL_GET_NEXT_ADAPTER_FIB
value|CTL_CODE(FILE_DEVICE_CONTROLLER, 2101, METHOD_BUFFERED, FILE_ANY_ACCESS)
end_define

begin_define
define|#
directive|define
name|FSACTL_CLOSE_GET_ADAPTER_FIB
value|CTL_CODE(FILE_DEVICE_CONTROLLER, 2102, METHOD_BUFFERED, FILE_ANY_ACCESS)
end_define

begin_define
define|#
directive|define
name|FSACTL_MINIPORT_REV_CHECK
value|CTL_CODE(FILE_DEVICE_CONTROLLER, 2107, METHOD_BUFFERED, FILE_ANY_ACCESS)
end_define

begin_comment
comment|/*  * Support for faking the "miniport" version.  */
end_comment

begin_struct
struct|struct
name|aac_rev_check
block|{
name|RevComponent
name|callingComponent
decl_stmt|;
name|struct
name|FsaRevision
name|callingRevision
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|aac_rev_check_resp
block|{
name|int
name|possiblyCompatible
decl_stmt|;
name|struct
name|FsaRevision
name|adapterSWRevision
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Context passed in by a consumer looking to collect an AIF.  */
end_comment

begin_define
define|#
directive|define
name|AAC_AIF_SILLYMAGIC
value|0xdeadbeef
end_define

begin_struct
struct|struct
name|get_adapter_fib_ioctl
block|{
name|u_int32_t
name|AdapterFibContext
decl_stmt|;
name|int
name|Wait
decl_stmt|;
name|caddr_t
name|AifFib
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

