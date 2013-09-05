begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * vscsiif.h  *   * Based on the blkif.h code.  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright(c) FUJITSU Limited 2008.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN__PUBLIC_IO_SCSI_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN__PUBLIC_IO_SCSI_H__
end_define

begin_include
include|#
directive|include
file|"ring.h"
end_include

begin_include
include|#
directive|include
file|"../grant_table.h"
end_include

begin_comment
comment|/* command between backend and frontend */
end_comment

begin_define
define|#
directive|define
name|VSCSIIF_ACT_SCSI_CDB
value|1
end_define

begin_comment
comment|/* SCSI CDB command */
end_comment

begin_define
define|#
directive|define
name|VSCSIIF_ACT_SCSI_ABORT
value|2
end_define

begin_comment
comment|/* SCSI Device(Lun) Abort*/
end_comment

begin_define
define|#
directive|define
name|VSCSIIF_ACT_SCSI_RESET
value|3
end_define

begin_comment
comment|/* SCSI Device(Lun) Reset*/
end_comment

begin_define
define|#
directive|define
name|VSCSIIF_BACK_MAX_PENDING_REQS
value|128
end_define

begin_comment
comment|/*  * Maximum scatter/gather segments per request.  *  * Considering balance between allocating al least 16 "vscsiif_request"  * structures on one page (4096bytes) and number of scatter gather   * needed, we decided to use 26 as a magic number.  */
end_comment

begin_define
define|#
directive|define
name|VSCSIIF_SG_TABLESIZE
value|26
end_define

begin_comment
comment|/*  * base on linux kernel 2.6.18  */
end_comment

begin_define
define|#
directive|define
name|VSCSIIF_MAX_COMMAND_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|VSCSIIF_SENSE_BUFFERSIZE
value|96
end_define

begin_struct
struct|struct
name|vscsiif_request
block|{
name|uint16_t
name|rqid
decl_stmt|;
comment|/* private guest value, echoed in resp  */
name|uint8_t
name|act
decl_stmt|;
comment|/* command between backend and frontend */
name|uint8_t
name|cmd_len
decl_stmt|;
name|uint8_t
name|cmnd
index|[
name|VSCSIIF_MAX_COMMAND_SIZE
index|]
decl_stmt|;
name|uint16_t
name|timeout_per_command
decl_stmt|;
comment|/* The command is issued by twice                                           the value in Backend. */
name|uint16_t
name|channel
decl_stmt|,
name|id
decl_stmt|,
name|lun
decl_stmt|;
name|uint16_t
name|padding
decl_stmt|;
name|uint8_t
name|sc_data_direction
decl_stmt|;
comment|/* for DMA_TO_DEVICE(1)                                          DMA_FROM_DEVICE(2)                                          DMA_NONE(3) requests  */
name|uint8_t
name|nr_segments
decl_stmt|;
comment|/* Number of pieces of scatter-gather */
struct|struct
name|scsiif_request_segment
block|{
name|grant_ref_t
name|gref
decl_stmt|;
name|uint16_t
name|offset
decl_stmt|;
name|uint16_t
name|length
decl_stmt|;
block|}
name|seg
index|[
name|VSCSIIF_SG_TABLESIZE
index|]
struct|;
name|uint32_t
name|reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|vscsiif_request
name|vscsiif_request_t
typedef|;
end_typedef

begin_struct
struct|struct
name|vscsiif_response
block|{
name|uint16_t
name|rqid
decl_stmt|;
name|uint8_t
name|padding
decl_stmt|;
name|uint8_t
name|sense_len
decl_stmt|;
name|uint8_t
name|sense_buffer
index|[
name|VSCSIIF_SENSE_BUFFERSIZE
index|]
decl_stmt|;
name|int32_t
name|rslt
decl_stmt|;
name|uint32_t
name|residual_len
decl_stmt|;
comment|/* request bufflen -                                    return the value from physical device */
name|uint32_t
name|reserved
index|[
literal|36
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|vscsiif_response
name|vscsiif_response_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_RING_TYPES
argument_list|(
name|vscsiif
argument_list|,
expr|struct
name|vscsiif_request
argument_list|,
expr|struct
name|vscsiif_response
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__XEN__PUBLIC_IO_SCSI_H__*/
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

