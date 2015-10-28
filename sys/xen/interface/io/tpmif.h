begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * tpmif.h  *  * TPM I/O interface for Xen guest OSes.  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2005, IBM Corporation  *  * Author: Stefan Berger, stefanb@us.ibm.com  * Grant table support: Mahadevan Gomathisankaran  *  * This code has been derived from tools/libxc/xen/io/netif.h  *  * Copyright (c) 2003-2004, Keir Fraser  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_IO_TPMIF_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_IO_TPMIF_H__
end_define

begin_include
include|#
directive|include
file|"../grant_table.h"
end_include

begin_struct
struct|struct
name|tpmif_tx_request
block|{
name|unsigned
name|long
name|addr
decl_stmt|;
comment|/* Machine address of packet.   */
name|grant_ref_t
name|ref
decl_stmt|;
comment|/* grant table access reference */
name|uint16_t
name|unused
decl_stmt|;
name|uint16_t
name|size
decl_stmt|;
comment|/* Packet size in bytes.        */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|tpmif_tx_request
name|tpmif_tx_request_t
typedef|;
end_typedef

begin_comment
comment|/*  * The TPMIF_TX_RING_SIZE defines the number of pages the  * front-end and backend can exchange (= size of array).  */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|TPMIF_RING_IDX
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TPMIF_TX_RING_SIZE
value|1
end_define

begin_comment
comment|/* This structure must fit in a memory page. */
end_comment

begin_struct
struct|struct
name|tpmif_ring
block|{
name|struct
name|tpmif_tx_request
name|req
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|tpmif_ring
name|tpmif_ring_t
typedef|;
end_typedef

begin_struct
struct|struct
name|tpmif_tx_interface
block|{
name|struct
name|tpmif_ring
name|ring
index|[
name|TPMIF_TX_RING_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|tpmif_tx_interface
name|tpmif_tx_interface_t
typedef|;
end_typedef

begin_comment
comment|/******************************************************************************  * TPM I/O interface for Xen guest OSes, v2  *  * Author: Daniel De Graaf<dgdegra@tycho.nsa.gov>  *  * This protocol emulates the request/response behavior of a TPM using a Xen  * shared memory interface. All interaction with the TPM is at the direction  * of the frontend, since a TPM (hardware or virtual) is a passive device -  * the backend only processes commands as requested by the frontend.  *  * The frontend sends a request to the TPM by populating the shared page with  * the request packet, changing the state to TPMIF_STATE_SUBMIT, and sending  * and event channel notification. When the backend is finished, it will set  * the state to TPMIF_STATE_FINISH and send an event channel notification.  *  * In order to allow long-running commands to be canceled, the frontend can  * at any time change the state to TPMIF_STATE_CANCEL and send a notification.  * The TPM can either finish the command (changing state to TPMIF_STATE_FINISH)  * or can cancel the command and change the state to TPMIF_STATE_IDLE. The TPM  * can also change the state to TPMIF_STATE_IDLE instead of TPMIF_STATE_FINISH  * if another reason for cancellation is required - for example, a physical  * TPM may cancel a command if the interface is seized by another locality.  *  * The TPM command format is defined by the TCG, and is available at  * http://www.trustedcomputinggroup.org/resources/tpm_main_specification  */
end_comment

begin_enum
enum|enum
name|tpmif_state
block|{
name|TPMIF_STATE_IDLE
block|,
comment|/* no contents / vTPM idle / cancel complete */
name|TPMIF_STATE_SUBMIT
block|,
comment|/* request ready / vTPM working */
name|TPMIF_STATE_FINISH
block|,
comment|/* response ready / vTPM idle */
name|TPMIF_STATE_CANCEL
block|,
comment|/* cancel requested / vTPM working */
block|}
enum|;
end_enum

begin_comment
comment|/* Note: The backend should only change state to IDLE or FINISH, while the  * frontend should only change to SUBMIT or CANCEL. Status changes do not need  * to use atomic operations.  */
end_comment

begin_comment
comment|/* The shared page for vTPM request/response packets looks like:  *  *  Offset               Contents  *  =================================================  *  0                    struct tpmif_shared_page  *  16                   [optional] List of grant IDs  *  16+4*nr_extra_pages  TPM packet data  *  * If the TPM packet data extends beyond the end of a single page, the grant IDs  * defined in extra_pages are used as if they were mapped immediately following  * the primary shared page. The grants are allocated by the frontend and mapped  * by the backend. Before sending a request spanning multiple pages, the  * frontend should verify that the TPM supports such large requests by querying  * the TPM_CAP_PROP_INPUT_BUFFER property from the TPM.  */
end_comment

begin_struct
struct|struct
name|tpmif_shared_page
block|{
name|uint32_t
name|length
decl_stmt|;
comment|/* request/response length in bytes */
name|uint8_t
name|state
decl_stmt|;
comment|/* enum tpmif_state */
name|uint8_t
name|locality
decl_stmt|;
comment|/* for the current request */
name|uint8_t
name|pad
decl_stmt|;
comment|/* should be zero */
name|uint8_t
name|nr_extra_pages
decl_stmt|;
comment|/* extra pages for long packets; may be zero */
name|uint32_t
name|extra_pages
index|[
literal|0
index|]
decl_stmt|;
comment|/* grant IDs; length is actually nr_extra_pages */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|tpmif_shared_page
name|tpmif_shared_page_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Local variables:  * mode: C  * c-file-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

