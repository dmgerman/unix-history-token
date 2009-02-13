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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

