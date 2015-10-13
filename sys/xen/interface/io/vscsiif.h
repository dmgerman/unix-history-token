begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * vscsiif.h  *  * Based on the blkif.h code.  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright(c) FUJITSU Limited 2008.  */
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
comment|/*  * Feature and Parameter Negotiation  * =================================  * The two halves of a Xen pvSCSI driver utilize nodes within the XenStore to  * communicate capabilities and to negotiate operating parameters.  This  * section enumerates these nodes which reside in the respective front and  * backend portions of the XenStore, following the XenBus convention.  *  * Any specified default value is in effect if the corresponding XenBus node  * is not present in the XenStore.  *  * XenStore nodes in sections marked "PRIVATE" are solely for use by the  * driver side whose XenBus tree contains them.  *  *****************************************************************************  *                            Backend XenBus Nodes  *****************************************************************************  *  *------------------ Backend Device Identification (PRIVATE) ------------------  *  * p-devname  *      Values:         string  *  *      A free string used to identify the physical device (e.g. a disk name).  *  * p-dev  *      Values:         string  *  *      A string specifying the backend device: either a 4-tuple "h:c:t:l"  *      (host, controller, target, lun, all integers), or a WWN (e.g.  *      "naa.60014054ac780582").  *  * v-dev  *      Values:         string  *  *      A string specifying the frontend device in form of a 4-tuple "h:c:t:l"  *      (host, controller, target, lun, all integers).  *  *--------------------------------- Features ---------------------------------  *  * feature-sg-grant  *      Values:         unsigned [VSCSIIF_SG_TABLESIZE...65535]  *      Default Value:  0  *  *      Specifies the maximum number of scatter/gather elements in grant pages  *      supported. If not set, the backend supports up to VSCSIIF_SG_TABLESIZE  *      SG elements specified directly in the request.  *  *****************************************************************************  *                            Frontend XenBus Nodes  *****************************************************************************  *  *----------------------- Request Transport Parameters -----------------------  *  * event-channel  *      Values:         unsigned  *  *      The identifier of the Xen event channel used to signal activity  *      in the ring buffer.  *  * ring-ref  *      Values:         unsigned  *  *      The Xen grant reference granting permission for the backend to map  *      the sole page in a single page sized ring buffer.  *  * protocol  *      Values:         string (XEN_IO_PROTO_ABI_*)  *      Default Value:  XEN_IO_PROTO_ABI_NATIVE  *  *      The machine ABI rules governing the format of all ring request and  *      response structures.  */
end_comment

begin_comment
comment|/* Requests from the frontend to the backend */
end_comment

begin_comment
comment|/*  * Request a SCSI operation specified via a CDB in vscsiif_request.cmnd.  * The target is specified via channel, id and lun.  *  * The operation to be performed is specified via a CDB in cmnd[], the length  * of the CDB is in cmd_len. sc_data_direction specifies the direction of data  * (to the device, from the device, or none at all).  *  * If data is to be transferred to or from the device the buffer(s) in the  * guest memory is/are specified via one or multiple scsiif_request_segment  * descriptors each specifying a memory page via a grant_ref_t, a offset into  * the page and the length of the area in that page. All scsiif_request_segment  * areas concatenated form the resulting data buffer used by the operation.  * If the number of scsiif_request_segment areas is not too large (less than  * or equal VSCSIIF_SG_TABLESIZE) the areas can be specified directly in the  * seg[] array and the number of valid scsiif_request_segment elements is to be  * set in nr_segments.  *  * If "feature-sg-grant" in the Xenstore is set it is possible to specify more  * than VSCSIIF_SG_TABLESIZE scsiif_request_segment elements via indirection.  * The maximum number of allowed scsiif_request_segment elements is the value  * of the "feature-sg-grant" entry from Xenstore. When using indirection the  * seg[] array doesn't contain specifications of the data buffers, but  * references to scsiif_request_segment arrays, which in turn reference the  * data buffers. While nr_segments holds the number of populated seg[] entries  * (plus the set VSCSIIF_SG_GRANT bit), the number of scsiif_request_segment  * elements referencing the target data buffers is calculated from the lengths  * of the seg[] elements (the sum of all valid seg[].length divided by the  * size of one scsiif_request_segment structure). The frontend may use a mix of  * direct and indirect requests.  */
end_comment

begin_define
define|#
directive|define
name|VSCSIIF_ACT_SCSI_CDB
value|1
end_define

begin_comment
comment|/*  * Request abort of a running operation for the specified target given by  * channel, id, lun and the operation's rqid in ref_rqid.  */
end_comment

begin_define
define|#
directive|define
name|VSCSIIF_ACT_SCSI_ABORT
value|2
end_define

begin_comment
comment|/*  * Request a device reset of the specified target (channel and id).  */
end_comment

begin_define
define|#
directive|define
name|VSCSIIF_ACT_SCSI_RESET
value|3
end_define

begin_comment
comment|/*  * Preset scatter/gather elements for a following request. Deprecated.  * Keeping the define only to avoid usage of the value "4" for other actions.  */
end_comment

begin_define
define|#
directive|define
name|VSCSIIF_ACT_SCSI_SG_PRESET
value|4
end_define

begin_comment
comment|/*  * Maximum scatter/gather segments per request.  *  * Considering balance between allocating at least 16 "vscsiif_request"  * structures on one page (4096 bytes) and the number of scatter/gather  * elements needed, we decided to use 26 as a magic number.  *  * If "feature-sg-grant" is set, more scatter/gather elements can be specified  * by placing them in one or more (up to VSCSIIF_SG_TABLESIZE) granted pages.  * In this case the vscsiif_request seg elements don't contain references to  * the user data, but to the SG elements referencing the user data.  */
end_comment

begin_define
define|#
directive|define
name|VSCSIIF_SG_TABLESIZE
value|26
end_define

begin_comment
comment|/*  * based on Linux kernel 2.6.18, still valid  *  * Changing these values requires support of multiple protocols via the rings  * as "old clients" will blindly use these values and the resulting structure  * sizes.  */
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
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|scsiif_request_segment
name|vscsiif_segment_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VSCSIIF_SG_PER_PAGE
value|(PAGE_SIZE / sizeof(struct scsiif_request_segment))
end_define

begin_comment
comment|/* Size of one request is 252 bytes */
end_comment

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
comment|/* valid CDB bytes */
name|uint8_t
name|cmnd
index|[
name|VSCSIIF_MAX_COMMAND_SIZE
index|]
decl_stmt|;
comment|/* the CDB */
name|uint16_t
name|timeout_per_command
decl_stmt|;
comment|/* deprecated: timeout in secs, 0=default */
name|uint16_t
name|channel
decl_stmt|,
name|id
decl_stmt|,
name|lun
decl_stmt|;
comment|/* (virtual) device specification */
name|uint16_t
name|ref_rqid
decl_stmt|;
comment|/* command abort reference */
name|uint8_t
name|sc_data_direction
decl_stmt|;
comment|/* for DMA_TO_DEVICE(1)                                        DMA_FROM_DEVICE(2)                                        DMA_NONE(3) requests  */
name|uint8_t
name|nr_segments
decl_stmt|;
comment|/* Number of pieces of scatter-gather */
comment|/*  * flag in nr_segments: SG elements via grant page  *  * If VSCSIIF_SG_GRANT is set, the low 7 bits of nr_segments specify the number  * of grant pages containing SG elements. Usable if "feature-sg-grant" set.  */
define|#
directive|define
name|VSCSIIF_SG_GRANT
value|0x80
name|vscsiif_segment_t
name|seg
index|[
name|VSCSIIF_SG_TABLESIZE
index|]
decl_stmt|;
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

begin_comment
comment|/*  * The following interface is deprecated!  */
end_comment

begin_define
define|#
directive|define
name|VSCSIIF_SG_LIST_SIZE
value|((sizeof(vscsiif_request_t) - 4) \                               / sizeof(vscsiif_segment_t))
end_define

begin_struct
struct|struct
name|vscsiif_sg_list
block|{
comment|/* First two fields must match struct vscsiif_request! */
name|uint16_t
name|rqid
decl_stmt|;
comment|/* private guest value, must match main req */
name|uint8_t
name|act
decl_stmt|;
comment|/* VSCSIIF_ACT_SCSI_SG_PRESET */
name|uint8_t
name|nr_segments
decl_stmt|;
comment|/* Number of pieces of scatter-gather */
name|vscsiif_segment_t
name|seg
index|[
name|VSCSIIF_SG_LIST_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|vscsiif_sg_list
name|vscsiif_sg_list_t
typedef|;
end_typedef

begin_comment
comment|/* End of deprecated interface */
end_comment

begin_comment
comment|/* Size of one response is 252 bytes */
end_comment

begin_struct
struct|struct
name|vscsiif_response
block|{
name|uint16_t
name|rqid
decl_stmt|;
comment|/* identifies request */
name|uint8_t
name|act
decl_stmt|;
comment|/* deprecated: valid only if SG_PRESET supported */
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
comment|/*  * Local variables:  * mode: C  * c-file-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

