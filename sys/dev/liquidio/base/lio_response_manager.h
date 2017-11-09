begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   BSD LICENSE  *  *   Copyright(c) 2017 Cavium, Inc.. All rights reserved.  *   All rights reserved.  *  *   Redistribution and use in source and binary forms, with or without  *   modification, are permitted provided that the following conditions  *   are met:  *  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in  *       the documentation and/or other materials provided with the  *       distribution.  *     * Neither the name of Cavium, Inc. nor the names of its  *       contributors may be used to endorse or promote products derived  *       from this software without specific prior written permission.  *  *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  *   OWNER(S) OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_comment
comment|/*  * ! \file lio_response_manager.h  *  \brief Host Driver:  Response queues for host instructions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LIO_RESPONSE_MANAGER_H__
end_ifndef

begin_define
define|#
directive|define
name|__LIO_RESPONSE_MANAGER_H__
end_define

begin_comment
comment|/*  * Maximum ordered requests to process in every invocation of  * lio_process_ordered_list(). The function will continue to process requests  * as long as it can find one that has finished processing. If it keeps  * finding requests that have completed, the function can run for ever. The  * value defined here sets an upper limit on the number of requests it can  * process before it returns control to the poll thread.  */
end_comment

begin_define
define|#
directive|define
name|LIO_MAX_ORD_REQS_TO_PROCESS
value|4096
end_define

begin_comment
comment|/*  * Head of a response list. There are several response lists in the  * system. One for each response order- Unordered, ordered  * and 1 for noresponse entries on each instruction queue.  */
end_comment

begin_struct
struct|struct
name|lio_response_list
block|{
comment|/* List structure to add delete pending entries to */
name|struct
name|lio_stailq_head
name|head
decl_stmt|;
comment|/* A lock for this response list */
name|struct
name|mtx
name|lock
decl_stmt|;
specifier|volatile
name|int
name|pending_req_count
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The type of response list. */
end_comment

begin_enum
enum|enum
block|{
name|LIO_ORDERED_LIST
init|=
literal|0
block|,
name|LIO_UNORDERED_NONBLOCKING_LIST
init|=
literal|1
block|,
name|LIO_UNORDERED_BLOCKING_LIST
init|=
literal|2
block|,
name|LIO_ORDERED_SC_LIST
init|=
literal|3
block|}
enum|;
end_enum

begin_comment
comment|/*  * Error codes  used in Octeon Host-Core communication.  *  *   31            16 15            0  *   ---------------------------------  *   |               |               |  *   ---------------------------------  *   Error codes are 32-bit wide. The upper 16-bits, called Major Error Number,  *   are reserved to identify the group to which the error code belongs. The  *   lower 16-bits, called Minor Error Number, carry the actual code.  *  *   So error codes are (MAJOR NUMBER<< 16)| MINOR_NUMBER.  */
end_comment

begin_comment
comment|/*------   Error codes used by firmware (bits 15..0 set by firmware */
end_comment

begin_define
define|#
directive|define
name|LIO_FW_MAJOR_ERROR_CODE
value|0x0001
end_define

begin_comment
comment|/* A value of 0x00000000 indicates no error i.e. success */
end_comment

begin_define
define|#
directive|define
name|LIO_DRIVER_ERROR_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|LIO_DRIVER_ERROR_REQ_PENDING
value|0x00000001
end_define

begin_define
define|#
directive|define
name|LIO_DRIVER_ERROR_REQ_TIMEOUT
value|0x00000003
end_define

begin_define
define|#
directive|define
name|LIO_DRIVER_ERROR_REQ_EINTR
value|0x00000004
end_define

begin_comment
comment|/*  * Status for a request.  * If a request is not queued to Octeon by the driver, the driver returns  * an error condition that's describe by one of the OCTEON_REQ_ERR_* value  * below. If the request is successfully queued, the driver will return  * a LIO_REQUEST_PENDING status. LIO_REQUEST_TIMEOUT and  * LIO_REQUEST_INTERRUPTED are only returned by the driver if the  * response for request failed to arrive before a time-out period or if  * the request processing * got interrupted due to a signal respectively.  */
end_comment

begin_enum
enum|enum
block|{
name|LIO_REQUEST_DONE
init|=
operator|(
name|LIO_DRIVER_ERROR_NONE
operator|)
block|,
name|LIO_REQUEST_PENDING
init|=
operator|(
name|LIO_DRIVER_ERROR_REQ_PENDING
operator|)
block|,
name|LIO_REQUEST_TIMEOUT
init|=
operator|(
name|LIO_DRIVER_ERROR_REQ_TIMEOUT
operator|)
block|,
name|LIO_REQUEST_INTERRUPTED
init|=
operator|(
name|LIO_DRIVER_ERROR_REQ_EINTR
operator|)
block|,
name|LIO_REQUEST_NO_DEVICE
init|=
operator|(
literal|0x00000021
operator|)
block|,
name|LIO_REQUEST_NOT_RUNNING
block|,
name|LIO_REQUEST_INVALID_IQ
block|,
name|LIO_REQUEST_INVALID_BUFCNT
block|,
name|LIO_REQUEST_INVALID_RESP_ORDER
block|,
name|LIO_REQUEST_NO_MEMORY
block|,
name|LIO_REQUEST_INVALID_BUFSIZE
block|,
name|LIO_REQUEST_NO_PENDING_ENTRY
block|,
name|LIO_REQUEST_NO_IQ_SPACE
init|=
operator|(
literal|0x7FFFFFFF
operator|)
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|LIO_STAILQ_FIRST_ENTRY
parameter_list|(
name|ptr
parameter_list|,
name|type
parameter_list|,
name|elem
parameter_list|)
define|\
value|(type *)((char *)((ptr)->stqh_first) - offsetof(type, elem))
end_define

begin_define
define|#
directive|define
name|LIO_FW_STATUS_CODE
parameter_list|(
name|status
parameter_list|)
define|\
value|((LIO_FW_MAJOR_ERROR_CODE<< 16) | (status))
end_define

begin_comment
comment|/*  * Initialize the response lists. The number of response lists to create is  * given by count.  * @param octeon_dev      - the octeon device structure.  */
end_comment

begin_function_decl
name|int
name|lio_setup_response_list
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|octeon_dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lio_delete_response_list
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|octeon_dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Check the status of first entry in the ordered list. If the instruction at  * that entry finished processing or has timed-out, the entry is cleaned.  * @param octeon_dev  - the octeon device structure.  * @param force_quit - the request is forced to timeout if this is 1  * @return 1 if the ordered list is empty, 0 otherwise.  */
end_comment

begin_function_decl
name|int
name|lio_process_ordered_list
parameter_list|(
name|struct
name|octeon_device
modifier|*
name|octeon_dev
parameter_list|,
name|uint32_t
name|force_quit
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __LIO_RESPONSE_MANAGER_H__ */
end_comment

end_unit

