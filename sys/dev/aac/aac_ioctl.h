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
name|FSACTL_LNX_SENDFIB
value|CTL_CODE(FILE_DEVICE_CONTROLLER, 2050, \ 					METHOD_BUFFERED, FILE_ANY_ACCESS)
end_define

begin_define
define|#
directive|define
name|FSACTL_LNX_GET_COMM_PERF_DATA
value|CTL_CODE(FILE_DEVICE_CONTROLLER, 2084, \ 					METHOD_BUFFERED, FILE_ANY_ACCESS)
end_define

begin_define
define|#
directive|define
name|FSACTL_LNX_OPENCLS_COMM_PERF_DATA
value|CTL_CODE(FILE_DEVICE_CONTROLLER, \ 					2085, METHOD_BUFFERED, FILE_ANY_ACCESS)
end_define

begin_define
define|#
directive|define
name|FSACTL_LNX_OPEN_GET_ADAPTER_FIB
value|CTL_CODE(FILE_DEVICE_CONTROLLER, 2100, \ 					METHOD_BUFFERED, FILE_ANY_ACCESS)
end_define

begin_define
define|#
directive|define
name|FSACTL_LNX_GET_NEXT_ADAPTER_FIB
value|CTL_CODE(FILE_DEVICE_CONTROLLER, 2101, \ 					METHOD_BUFFERED, FILE_ANY_ACCESS)
end_define

begin_define
define|#
directive|define
name|FSACTL_LNX_CLOSE_GET_ADAPTER_FIB
value|CTL_CODE(FILE_DEVICE_CONTROLLER, \ 					2102, METHOD_BUFFERED, FILE_ANY_ACCESS)
end_define

begin_define
define|#
directive|define
name|FSACTL_LNX_CLOSE_ADAPTER_CONFIG
value|CTL_CODE(FILE_DEVICE_CONTROLLER, 2104, \ 					METHOD_BUFFERED, FILE_ANY_ACCESS)
end_define

begin_define
define|#
directive|define
name|FSACTL_LNX_OPEN_ADAPTER_CONFIG
value|CTL_CODE(FILE_DEVICE_CONTROLLER, 2105, \ 					METHOD_BUFFERED, FILE_ANY_ACCESS)
end_define

begin_define
define|#
directive|define
name|FSACTL_LNX_MINIPORT_REV_CHECK
value|CTL_CODE(FILE_DEVICE_CONTROLLER, 2107, \ 					METHOD_BUFFERED, FILE_ANY_ACCESS)
end_define

begin_define
define|#
directive|define
name|FSACTL_LNX_QUERY_ADAPTER_CONFIG
value|CTL_CODE(FILE_DEVICE_CONTROLLER, 2113, \ 					METHOD_BUFFERED, FILE_ANY_ACCESS)
end_define

begin_define
define|#
directive|define
name|FSACTL_LNX_GET_PCI_INFO
value|CTL_CODE(FILE_DEVICE_CONTROLLER, 2119, \ 					METHOD_BUFFERED, FILE_ANY_ACCESS)
end_define

begin_define
define|#
directive|define
name|FSACTL_LNX_FORCE_DELETE_DISK
value|CTL_CODE(FILE_DEVICE_CONTROLLER, 2120, \ 					METHOD_NEITHER, FILE_ANY_ACCESS)
end_define

begin_define
define|#
directive|define
name|FSACTL_LNX_AIF_THREAD
value|CTL_CODE(FILE_DEVICE_CONTROLLER, 2127, \ 					METHOD_NEITHER, FILE_ANY_ACCESS)
end_define

begin_comment
comment|/* Why these don't follow the previous convention, I don't know */
end_comment

begin_define
define|#
directive|define
name|FSACTL_LNX_NULL_IO_TEST
value|0x43
end_define

begin_define
define|#
directive|define
name|FSACTL_LNX_SIM_IO_TEST
value|0x53
end_define

begin_define
define|#
directive|define
name|FSACTL_LNX_DOWNLOAD
value|0x83
end_define

begin_define
define|#
directive|define
name|FSACTL_LNX_GET_VAR
value|0x93
end_define

begin_define
define|#
directive|define
name|FSACTL_LNX_SET_VAR
value|0xa3
end_define

begin_define
define|#
directive|define
name|FSACTL_LNX_GET_FIBTIMES
value|0xb3
end_define

begin_define
define|#
directive|define
name|FSACTL_LNX_ZERO_FIBTIMES
value|0xc3
end_define

begin_define
define|#
directive|define
name|FSACTL_LNX_DELETE_DISK
value|0x163
end_define

begin_define
define|#
directive|define
name|FSACTL_LNX_QUERY_DISK
value|0x173
end_define

begin_comment
comment|/* Ok, here it gets really lame */
end_comment

begin_define
define|#
directive|define
name|FSACTL_LNX_PROBE_CONTAINERS
value|2131
end_define

begin_comment
comment|/* Just guessing */
end_comment

begin_comment
comment|/* Do the native version of the ioctls.  Since the BSD encoding scheme  * conflicts with the 'standard' AAC encoding scheme, the resulting numbers  * will be different.  The '8' comes from the fact that the previous scheme  * used 12 bits for the number, with the the 12th bit being the only set  * bit above bit 8.  Thus the value of 8, with the lower 8 bits holding the  * command number.  9 is used for the odd overflow case.  */
end_comment

begin_define
define|#
directive|define
name|FSACTL_SENDFIB
value|_IO('8', 2)
end_define

begin_define
define|#
directive|define
name|FSACTL_GET_COMM_PERF_DATA
value|_IO('8', 36)
end_define

begin_define
define|#
directive|define
name|FSACTL_OPENCLS_COMM_PERF_DATA
value|_IO('8', 37)
end_define

begin_define
define|#
directive|define
name|FSACTL_OPEN_GET_ADAPTER_FIB
value|_IO('8', 52)
end_define

begin_define
define|#
directive|define
name|FSACTL_GET_NEXT_ADAPTER_FIB
value|_IO('8', 53)
end_define

begin_define
define|#
directive|define
name|FSACTL_CLOSE_GET_ADAPTER_FIB
value|_IO('8', 54)
end_define

begin_define
define|#
directive|define
name|FSACTL_CLOSE_ADAPTER_CONFIG
value|_IO('8', 56)
end_define

begin_define
define|#
directive|define
name|FSACTL_OPEN_ADAPTER_CONFIG
value|_IO('8', 57)
end_define

begin_define
define|#
directive|define
name|FSACTL_MINIPORT_REV_CHECK
value|_IO('8', 59)
end_define

begin_define
define|#
directive|define
name|FSACTL_QUERY_ADAPTER_CONFIG
value|_IO('8', 65)
end_define

begin_define
define|#
directive|define
name|FSACTL_GET_PCI_INFO
value|_IO('8', 71)
end_define

begin_define
define|#
directive|define
name|FSACTL_FORCE_DELETE_DISK
value|_IO('8', 72)
end_define

begin_define
define|#
directive|define
name|FSACTL_AIF_THREAD
value|_IO('8', 79)
end_define

begin_define
define|#
directive|define
name|FSACTL_NULL_IO_TEST
value|_IO('8', 67)
end_define

begin_define
define|#
directive|define
name|FSACTL_SIM_IO_TEST
value|_IO('8', 83)
end_define

begin_define
define|#
directive|define
name|FSACTL_DOWNLOAD
value|_IO('8', 131)
end_define

begin_define
define|#
directive|define
name|FSACTL_GET_VAR
value|_IO('8', 147)
end_define

begin_define
define|#
directive|define
name|FSACTL_SET_VAR
value|_IO('8', 163)
end_define

begin_define
define|#
directive|define
name|FSACTL_GET_FIBTIMES
value|_IO('8', 179)
end_define

begin_define
define|#
directive|define
name|FSACTL_ZERO_FIBTIMES
value|_IO('8', 195)
end_define

begin_define
define|#
directive|define
name|FSACTL_DELETE_DISK
value|_IO('8', 99)
end_define

begin_define
define|#
directive|define
name|FSACTL_QUERY_DISK
value|_IO('9', 115)
end_define

begin_define
define|#
directive|define
name|FSACTL_PROBE_CONTAINERS
value|_IO('9', 83)
end_define

begin_comment
comment|/* Just guessing */
end_comment

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

begin_struct
struct|struct
name|aac_query_disk
block|{
name|int32_t
name|ContainerNumber
decl_stmt|;
name|int32_t
name|Bus
decl_stmt|;
name|int32_t
name|Target
decl_stmt|;
name|int32_t
name|Lun
decl_stmt|;
name|u_int32_t
name|Valid
decl_stmt|;
name|u_int32_t
name|Locked
decl_stmt|;
name|u_int32_t
name|Deleted
decl_stmt|;
name|int32_t
name|Instance
decl_stmt|;
name|char
name|diskDeviceName
index|[
literal|10
index|]
decl_stmt|;
name|u_int32_t
name|UnMapped
decl_stmt|;
block|}
struct|;
end_struct

end_unit

