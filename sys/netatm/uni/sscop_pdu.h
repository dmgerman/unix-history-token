begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * ATM Forum UNI Support  * ---------------------  *  * SSCOP Protocol Data Unit (PDU) definitions  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UNI_SSCOP_PDU_H
end_ifndef

begin_define
define|#
directive|define
name|_UNI_SSCOP_PDU_H
end_define

begin_comment
comment|/*  * SSCOP PDU Constants  */
end_comment

begin_define
define|#
directive|define
name|PDU_MIN_LEN
value|4
end_define

begin_comment
comment|/* Minimum PDU length */
end_comment

begin_define
define|#
directive|define
name|PDU_LEN_MASK
value|3
end_define

begin_comment
comment|/* PDU length must be 32-bit aligned */
end_comment

begin_define
define|#
directive|define
name|PDU_ADDR_MASK
value|3
end_define

begin_comment
comment|/* PDUs must be 32-bit aligned */
end_comment

begin_define
define|#
directive|define
name|PDU_SEQ_MASK
value|0x00ffffff
end_define

begin_comment
comment|/* Mask for 24-bit sequence values */
end_comment

begin_define
define|#
directive|define
name|PDU_MAX_INFO
value|65528
end_define

begin_comment
comment|/* Maximum length of PDU info field */
end_comment

begin_define
define|#
directive|define
name|PDU_MAX_UU
value|65524
end_define

begin_comment
comment|/* Maximum length of SSCOP-UU field */
end_comment

begin_define
define|#
directive|define
name|PDU_MAX_STAT
value|65520
end_define

begin_comment
comment|/* Maximum length of STAT list */
end_comment

begin_define
define|#
directive|define
name|PDU_MAX_ELEM
value|67
end_define

begin_comment
comment|/* Maximum elements sent in STAT */
end_comment

begin_define
define|#
directive|define
name|PDU_PAD_ALIGN
value|4
end_define

begin_comment
comment|/* I-field padding alignment */
end_comment

begin_comment
comment|/*  * PDU Queueing Header  *  * There will be a queueing header tacked on to the front of each  * buffer chain that is placed on any of the sscop SD PDU queues (not  * including the SD transmission queue).  Note that this header will  * not be included in the buffer data length/offset fields.  */
end_comment

begin_struct
struct|struct
name|pdu_hdr
block|{
union|union
block|{
name|struct
name|pdu_hdr
modifier|*
name|phu_pack_lk
decl_stmt|;
comment|/* Pending ack queue link */
name|struct
name|pdu_hdr
modifier|*
name|phu_recv_lk
decl_stmt|;
comment|/* Receive queue link */
block|}
name|ph_u
union|;
name|struct
name|pdu_hdr
modifier|*
name|ph_rexmit_lk
decl_stmt|;
comment|/* Retranmit queue link */
name|sscop_seq
name|ph_ns
decl_stmt|;
comment|/* SD.N(S) - SD's sequence number */
name|sscop_seq
name|ph_nps
decl_stmt|;
comment|/* SD.N(PS) - SD's poll sequence */
name|KBuffer
modifier|*
name|ph_buf
decl_stmt|;
comment|/* Pointer to containing buffer */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ph_pack_lk
value|ph_u.phu_pack_lk
end_define

begin_define
define|#
directive|define
name|ph_recv_lk
value|ph_u.phu_recv_lk
end_define

begin_comment
comment|/*  * SSCOP PDU formats  *  * N.B. - all SSCOP PDUs are trailer oriented (don't ask me...)  */
end_comment

begin_comment
comment|/*  * PDU Type Fields  */
end_comment

begin_define
define|#
directive|define
name|PT_PAD_MASK
value|0xc0
end_define

begin_comment
comment|/* Pad length mask */
end_comment

begin_define
define|#
directive|define
name|PT_PAD_SHIFT
value|6
end_define

begin_comment
comment|/* Pad byte shift count */
end_comment

begin_define
define|#
directive|define
name|PT_SOURCE_SSCOP
value|0x10
end_define

begin_comment
comment|/* Source = SSCOP */
end_comment

begin_define
define|#
directive|define
name|PT_TYPE_MASK
value|0x0f
end_define

begin_comment
comment|/* Type mask */
end_comment

begin_define
define|#
directive|define
name|PT_TYPE_MAX
value|0x0f
end_define

begin_comment
comment|/* Maximum pdu type */
end_comment

begin_define
define|#
directive|define
name|PT_TYPE_SHIFT
value|24
end_define

begin_comment
comment|/* Type word shift count */
end_comment

begin_define
define|#
directive|define
name|PT_BGN
value|0x01
end_define

begin_comment
comment|/* Begin */
end_comment

begin_define
define|#
directive|define
name|PT_BGAK
value|0x02
end_define

begin_comment
comment|/* Begin Acknowledge */
end_comment

begin_define
define|#
directive|define
name|PT_BGREJ
value|0x07
end_define

begin_comment
comment|/* Begin Reject */
end_comment

begin_define
define|#
directive|define
name|PT_END
value|0x03
end_define

begin_comment
comment|/* End */
end_comment

begin_define
define|#
directive|define
name|PT_ENDAK
value|0x04
end_define

begin_comment
comment|/* End Acknowledge */
end_comment

begin_define
define|#
directive|define
name|PT_RS
value|0x05
end_define

begin_comment
comment|/* Resynchronization */
end_comment

begin_define
define|#
directive|define
name|PT_RSAK
value|0x06
end_define

begin_comment
comment|/* Resynchronization Acknowledge */
end_comment

begin_define
define|#
directive|define
name|PT_ER
value|0x09
end_define

begin_comment
comment|/* Error Recovery */
end_comment

begin_define
define|#
directive|define
name|PT_ERAK
value|0x0f
end_define

begin_comment
comment|/* Error Recovery Acknowledge */
end_comment

begin_define
define|#
directive|define
name|PT_SD
value|0x08
end_define

begin_comment
comment|/* Sequenced Data */
end_comment

begin_define
define|#
directive|define
name|PT_SDP
value|0x09
end_define

begin_comment
comment|/* Sequenced Data with Poll */
end_comment

begin_define
define|#
directive|define
name|PT_POLL
value|0x0a
end_define

begin_comment
comment|/* Status Request */
end_comment

begin_define
define|#
directive|define
name|PT_STAT
value|0x0b
end_define

begin_comment
comment|/* Solicited Status Response */
end_comment

begin_define
define|#
directive|define
name|PT_USTAT
value|0x0c
end_define

begin_comment
comment|/* Unsolicited Status Response */
end_comment

begin_define
define|#
directive|define
name|PT_UD
value|0x0d
end_define

begin_comment
comment|/* Unnumbered Data */
end_comment

begin_define
define|#
directive|define
name|PT_MD
value|0x0e
end_define

begin_comment
comment|/* Management Data */
end_comment

begin_comment
comment|/*  * Begin PDU  */
end_comment

begin_struct
struct|struct
name|bgn_pdu
block|{
name|u_char
name|bgn_rsvd
index|[
literal|3
index|]
decl_stmt|;
comment|/* Reserved */
name|u_char
name|bgn_nsq
decl_stmt|;
comment|/* N(SQ) */
union|union
block|{
name|u_char
name|bgnu_type
decl_stmt|;
comment|/* PDU type, etc */
name|sscop_seq
name|bgnu_nmr
decl_stmt|;
comment|/* N(MR) */
block|}
name|bgn_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|bgn_type
value|bgn_u.bgnu_type
end_define

begin_define
define|#
directive|define
name|bgn_nmr
value|bgn_u.bgnu_nmr
end_define

begin_comment
comment|/*  * Begin Acknowledge PDU  */
end_comment

begin_struct
struct|struct
name|bgak_pdu
block|{
name|int
name|bgak_rsvd
decl_stmt|;
comment|/* Reserved */
union|union
block|{
name|u_char
name|bgaku_type
decl_stmt|;
comment|/* PDU type, etc */
name|sscop_seq
name|bgaku_nmr
decl_stmt|;
comment|/* N(MR) */
block|}
name|bgak_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|bgak_type
value|bgak_u.bgaku_type
end_define

begin_define
define|#
directive|define
name|bgak_nmr
value|bgak_u.bgaku_nmr
end_define

begin_comment
comment|/*  * Begin Reject PDU  */
end_comment

begin_struct
struct|struct
name|bgrej_pdu
block|{
name|int
name|bgrej_rsvd2
decl_stmt|;
comment|/* Reserved */
name|u_char
name|bgrej_type
decl_stmt|;
comment|/* PDU type, etc */
name|u_char
name|bgrej_rsvd1
index|[
literal|3
index|]
decl_stmt|;
comment|/* Reserved */
block|}
struct|;
end_struct

begin_comment
comment|/*  * End PDU  */
end_comment

begin_struct
struct|struct
name|end_pdu
block|{
name|int
name|end_rsvd2
decl_stmt|;
comment|/* Reserved */
name|u_char
name|end_type
decl_stmt|;
comment|/* PDU type, etc */
name|u_char
name|end_rsvd1
index|[
literal|3
index|]
decl_stmt|;
comment|/* Reserved */
block|}
struct|;
end_struct

begin_comment
comment|/*  * End Acknowledge PDU (Q.2110)  */
end_comment

begin_struct
struct|struct
name|endak_q2110_pdu
block|{
name|int
name|endak_rsvd2
decl_stmt|;
comment|/* Reserved */
name|u_char
name|endak_type
decl_stmt|;
comment|/* PDU type, etc */
name|u_char
name|endak_rsvd1
index|[
literal|3
index|]
decl_stmt|;
comment|/* Reserved */
block|}
struct|;
end_struct

begin_comment
comment|/*  * End Acknowledge PDU (Q.SAAL)  */
end_comment

begin_struct
struct|struct
name|endak_qsaal_pdu
block|{
name|u_char
name|endak_type
decl_stmt|;
comment|/* PDU type, etc */
name|u_char
name|endak_rsvd
index|[
literal|3
index|]
decl_stmt|;
comment|/* Reserved */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Resynchronization PDU  */
end_comment

begin_struct
struct|struct
name|rs_pdu
block|{
name|char
name|rs_rsvd
index|[
literal|3
index|]
decl_stmt|;
comment|/* Reserved */
name|u_char
name|rs_nsq
decl_stmt|;
comment|/* N(SQ) */
union|union
block|{
name|u_char
name|rsu_type
decl_stmt|;
comment|/* PDU type, etc */
name|sscop_seq
name|rsu_nmr
decl_stmt|;
comment|/* N(MR) */
block|}
name|rs_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|rs_type
value|rs_u.rsu_type
end_define

begin_define
define|#
directive|define
name|rs_nmr
value|rs_u.rsu_nmr
end_define

begin_comment
comment|/*  * Resynchronization Acknowledge PDU (Q.2110)  */
end_comment

begin_struct
struct|struct
name|rsak_q2110_pdu
block|{
name|int
name|rsak_rsvd
decl_stmt|;
comment|/* Reserved */
union|union
block|{
name|u_char
name|rsaku_type
decl_stmt|;
comment|/* PDU type, etc */
name|sscop_seq
name|rsaku_nmr
decl_stmt|;
comment|/* N(MR) */
block|}
name|rsak_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|rsak2_type
value|rsak_u.rsaku_type
end_define

begin_define
define|#
directive|define
name|rsak_nmr
value|rsak_u.rsaku_nmr
end_define

begin_comment
comment|/*  * Resynchronization Acknowledge PDU (Q.SAAL)  */
end_comment

begin_struct
struct|struct
name|rsak_qsaal_pdu
block|{
name|u_char
name|rsaks_type
decl_stmt|;
comment|/* PDU type, etc */
name|u_char
name|rsak_rsvd
index|[
literal|3
index|]
decl_stmt|;
comment|/* Reserved */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Error Recovery PDU  */
end_comment

begin_struct
struct|struct
name|er_pdu
block|{
name|char
name|er_rsvd
index|[
literal|3
index|]
decl_stmt|;
comment|/* Reserved */
name|u_char
name|er_nsq
decl_stmt|;
comment|/* N(SQ) */
union|union
block|{
name|u_char
name|eru_type
decl_stmt|;
comment|/* PDU type, etc */
name|sscop_seq
name|eru_nmr
decl_stmt|;
comment|/* N(MR) */
block|}
name|er_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|er_type
value|er_u.eru_type
end_define

begin_define
define|#
directive|define
name|er_nmr
value|er_u.eru_nmr
end_define

begin_comment
comment|/*  * Error Recovery Acknowledge PDU  */
end_comment

begin_struct
struct|struct
name|erak_pdu
block|{
name|int
name|erak_rsvd
decl_stmt|;
comment|/* Reserved */
union|union
block|{
name|u_char
name|eraku_type
decl_stmt|;
comment|/* PDU type, etc */
name|sscop_seq
name|eraku_nmr
decl_stmt|;
comment|/* N(MR) */
block|}
name|erak_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|erak_type
value|erak_u.eraku_type
end_define

begin_define
define|#
directive|define
name|erak_nmr
value|erak_u.eraku_nmr
end_define

begin_comment
comment|/*  * Sequenced Data PDU  */
end_comment

begin_struct
struct|struct
name|sd_pdu
block|{
union|union
block|{
name|u_char
name|sdu_type
decl_stmt|;
comment|/* PDU type, etc */
name|sscop_seq
name|sdu_ns
decl_stmt|;
comment|/* N(S) */
block|}
name|sd_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sd_type
value|sd_u.sdu_type
end_define

begin_define
define|#
directive|define
name|sd_ns
value|sd_u.sdu_ns
end_define

begin_comment
comment|/*  * Sequenced Data with Poll PDU  */
end_comment

begin_struct
struct|struct
name|sdp_pdu
block|{
name|sscop_seq
name|sdp_nps
decl_stmt|;
comment|/* N(PS) */
union|union
block|{
name|u_char
name|sdpu_type
decl_stmt|;
comment|/* PDU type, etc */
name|sscop_seq
name|sdpu_ns
decl_stmt|;
comment|/* N(S) */
block|}
name|sdp_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sdp_type
value|sdp_u.sdpu_type
end_define

begin_define
define|#
directive|define
name|sdp_ns
value|sdp_u.sdpu_ns
end_define

begin_comment
comment|/*  * Poll PDU  */
end_comment

begin_struct
struct|struct
name|poll_pdu
block|{
name|sscop_seq
name|poll_nps
decl_stmt|;
comment|/* N(PS) */
union|union
block|{
name|u_char
name|pollu_type
decl_stmt|;
comment|/* PDU type, etc */
name|sscop_seq
name|pollu_ns
decl_stmt|;
comment|/* N(S) */
block|}
name|poll_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|poll_type
value|poll_u.pollu_type
end_define

begin_define
define|#
directive|define
name|poll_ns
value|poll_u.pollu_ns
end_define

begin_comment
comment|/*  * Solicited Status PDU  */
end_comment

begin_struct
struct|struct
name|stat_pdu
block|{
name|sscop_seq
name|stat_nps
decl_stmt|;
comment|/* N(PS) */
name|sscop_seq
name|stat_nmr
decl_stmt|;
comment|/* N(MR) */
union|union
block|{
name|u_char
name|statu_type
decl_stmt|;
comment|/* PDU type, etc */
name|sscop_seq
name|statu_nr
decl_stmt|;
comment|/* N(R) */
block|}
name|stat_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|stat_type
value|stat_u.statu_type
end_define

begin_define
define|#
directive|define
name|stat_nr
value|stat_u.statu_nr
end_define

begin_comment
comment|/*  * Unsolicited Status PDU  */
end_comment

begin_struct
struct|struct
name|ustat_pdu
block|{
name|sscop_seq
name|ustat_le1
decl_stmt|;
comment|/* List element 1 */
name|sscop_seq
name|ustat_le2
decl_stmt|;
comment|/* List element 2 */
name|sscop_seq
name|ustat_nmr
decl_stmt|;
comment|/* N(MR) */
union|union
block|{
name|u_char
name|ustatu_type
decl_stmt|;
comment|/* PDU type, etc */
name|sscop_seq
name|ustatu_nr
decl_stmt|;
comment|/* N(R) */
block|}
name|ustat_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ustat_type
value|ustat_u.ustatu_type
end_define

begin_define
define|#
directive|define
name|ustat_nr
value|ustat_u.ustatu_nr
end_define

begin_comment
comment|/*  * Unit Data PDU  */
end_comment

begin_struct
struct|struct
name|ud_pdu
block|{
name|u_char
name|ud_type
decl_stmt|;
comment|/* PDU type, etc */
name|u_char
name|ud_rsvd
index|[
literal|3
index|]
decl_stmt|;
comment|/* Reserved */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Management Data PDU  */
end_comment

begin_struct
struct|struct
name|md_pdu
block|{
name|u_char
name|md_type
decl_stmt|;
comment|/* PDU type, etc */
name|u_char
name|md_rsvd
index|[
literal|3
index|]
decl_stmt|;
comment|/* Reserved */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UNI_SSCOP_PDU_H */
end_comment

end_unit

