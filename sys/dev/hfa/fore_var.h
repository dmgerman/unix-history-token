begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * FORE Systems 200-Series Adapter Support  * ---------------------------------------  *  * Host protocol control blocks  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FORE_VAR_H
end_ifndef

begin_define
define|#
directive|define
name|_FORE_VAR_H
end_define

begin_comment
comment|/*  * Device VCC Entry  *  * Contains the common and Fore-specific information for each VCC   * which is opened through a Fore device.  */
end_comment

begin_struct
struct|struct
name|fore_vcc
block|{
name|struct
name|cmn_vcc
name|fv_cmn
decl_stmt|;
comment|/* Common VCC stuff */
name|Fore_aal
name|fv_aal
decl_stmt|;
comment|/* CP version of AAL */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|fore_vcc
name|Fore_vcc
typedef|;
end_typedef

begin_define
define|#
directive|define
name|fv_next
value|fv_cmn.cv_next
end_define

begin_define
define|#
directive|define
name|fv_toku
value|fv_cmn.cv_toku
end_define

begin_define
define|#
directive|define
name|fv_upper
value|fv_cmn.cv_upper
end_define

begin_define
define|#
directive|define
name|fv_connvc
value|fv_cmn.cv_connvc
end_define

begin_define
define|#
directive|define
name|fv_state
value|fv_cmn.cv_state
end_define

begin_define
define|#
directive|define
name|fv_flags
value|fv_cmn.cv_flags
end_define

begin_comment
comment|/*  * VCC Flags  */
end_comment

begin_define
define|#
directive|define
name|FVF_ACTCMD
value|0x01
end_define

begin_comment
comment|/* Activate command issued */
end_comment

begin_comment
comment|/*  * Host Transmit Queue Element  *  * Defines the host's view of the CP PDU Transmit Queue  */
end_comment

begin_struct
struct|struct
name|h_xmit_queue
block|{
name|struct
name|h_xmit_queue
modifier|*
name|hxq_next
decl_stmt|;
comment|/* Next element in queue */
name|Xmit_queue
modifier|*
name|hxq_cpelem
decl_stmt|;
comment|/* CP queue element */
name|Q_status
modifier|*
name|hxq_status
decl_stmt|;
comment|/* Element status word */
name|Xmit_descr
modifier|*
name|hxq_descr
decl_stmt|;
comment|/* Element's transmit descriptor */
name|Xmit_descr
modifier|*
name|hxq_descr_dma
decl_stmt|;
comment|/* Element's transmit descriptor */
name|Fore_vcc
modifier|*
name|hxq_vcc
decl_stmt|;
comment|/* Data's VCC */
name|KBuffer
modifier|*
name|hxq_buf
decl_stmt|;
comment|/* Data's buffer chain head */
name|H_dma
name|hxq_dma
index|[
name|XMIT_MAX_SEGS
index|]
decl_stmt|;
comment|/* DMA addresses for segments */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|h_xmit_queue
name|H_xmit_queue
typedef|;
end_typedef

begin_comment
comment|/*  * Host Receive Queue Element  *  * Defines the host's view of the CP PDU Receive Queue  */
end_comment

begin_struct
struct|struct
name|h_recv_queue
block|{
name|struct
name|h_recv_queue
modifier|*
name|hrq_next
decl_stmt|;
comment|/* Next element in queue */
name|Recv_queue
modifier|*
name|hrq_cpelem
decl_stmt|;
comment|/* CP queue element */
name|Q_status
modifier|*
name|hrq_status
decl_stmt|;
comment|/* Element status word */
name|Recv_descr
modifier|*
name|hrq_descr
decl_stmt|;
comment|/* Element's receive descriptor */
name|Recv_descr
modifier|*
name|hrq_descr_dma
decl_stmt|;
comment|/* Element's receive descriptor */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|h_recv_queue
name|H_recv_queue
typedef|;
end_typedef

begin_comment
comment|/*  * Host Buffer Supply Queue Element  *  * Defines the host's view of the CP Buffer Supply Queue  */
end_comment

begin_struct
struct|struct
name|h_buf_queue
block|{
name|struct
name|h_buf_queue
modifier|*
name|hbq_next
decl_stmt|;
comment|/* Next element in queue */
name|Buf_queue
modifier|*
name|hbq_cpelem
decl_stmt|;
comment|/* CP queue element */
name|Q_status
modifier|*
name|hbq_status
decl_stmt|;
comment|/* Element status word */
name|Buf_descr
modifier|*
name|hbq_descr
decl_stmt|;
comment|/* Element's buffer descriptor array */
name|Buf_descr
modifier|*
name|hbq_descr_dma
decl_stmt|;
comment|/* Element's buffer descriptor array */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|h_buf_queue
name|H_buf_queue
typedef|;
end_typedef

begin_comment
comment|/*  * Host Command Queue Element  *  * Defines the host's view of the CP Command Queue  */
end_comment

begin_struct
struct|struct
name|h_cmd_queue
block|{
name|struct
name|h_cmd_queue
modifier|*
name|hcq_next
decl_stmt|;
comment|/* Next element in queue */
name|Cmd_queue
modifier|*
name|hcq_cpelem
decl_stmt|;
comment|/* CP queue element */
name|Q_status
modifier|*
name|hcq_status
decl_stmt|;
comment|/* Element status word */
name|Cmd_code
name|hcq_code
decl_stmt|;
comment|/* Command code */
name|void
modifier|*
name|hcq_arg
decl_stmt|;
comment|/* Command-specific argument */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|h_cmd_queue
name|H_cmd_queue
typedef|;
end_typedef

begin_comment
comment|/*  * Host Buffer Handle  *  * For each buffer supplied to the CP, there will be one of these structures  * embedded into the non-data portion of the buffer.  This will allow us to  * track which buffers are currently "controlled" by the CP.  The address of  * this structure will supplied to/returned from the CP as the buffer handle.  */
end_comment

begin_struct
struct|struct
name|buf_handle
block|{
name|Qelem_t
name|bh_qelem
decl_stmt|;
comment|/* Queuing element */
name|u_int
name|bh_type
decl_stmt|;
comment|/* Buffer type (see below) */
name|H_dma
name|bh_dma
decl_stmt|;
comment|/* Buffer DMA address */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|buf_handle
name|Buf_handle
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SIZEOF_Buf_handle
value|16
end_define

begin_comment
comment|/*  * Buffer Types  */
end_comment

begin_define
define|#
directive|define
name|BHT_S1_SMALL
value|1
end_define

begin_comment
comment|/* Buffer strategy 1, small */
end_comment

begin_define
define|#
directive|define
name|BHT_S1_LARGE
value|2
end_define

begin_comment
comment|/* Buffer strategy 1, large */
end_comment

begin_define
define|#
directive|define
name|BHT_S2_SMALL
value|3
end_define

begin_comment
comment|/* Buffer strategy 2, small */
end_comment

begin_define
define|#
directive|define
name|BHT_S2_LARGE
value|4
end_define

begin_comment
comment|/* Buffer strategy 2, large */
end_comment

begin_comment
comment|/*  * Device Unit Structure  *  * Contains all the information for a single device (adapter).  */
end_comment

begin_struct
struct|struct
name|fore_unit
block|{
name|Cmn_unit
name|fu_cmn
decl_stmt|;
comment|/* Common unit stuff */
ifdef|#
directive|ifdef
name|sun
name|struct
name|dev_info
modifier|*
name|fu_devinfo
decl_stmt|;
comment|/* Device node for this unit */
endif|#
directive|endif
name|Fore_reg
modifier|*
name|fu_ctlreg
decl_stmt|;
comment|/* Device control register */
ifdef|#
directive|ifdef
name|FORE_SBUS
name|Fore_reg
modifier|*
name|fu_intlvl
decl_stmt|;
comment|/* Interrupt level register */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|FORE_PCI
name|Fore_reg
modifier|*
name|fu_imask
decl_stmt|;
comment|/* Interrupt mask register */
name|Fore_reg
modifier|*
name|fu_psr
decl_stmt|;
comment|/* PCI specific register */
name|pcici_t
name|fu_pcitag
decl_stmt|;
comment|/* PCI tag */
endif|#
directive|endif
name|Fore_mem
modifier|*
name|fu_ram
decl_stmt|;
comment|/* Device RAM */
name|u_int
name|fu_ramsize
decl_stmt|;
comment|/* Size of device RAM */
name|Mon960
modifier|*
name|fu_mon
decl_stmt|;
comment|/* Monitor program interface */
name|Aali
modifier|*
name|fu_aali
decl_stmt|;
comment|/* Microcode program interface */
name|u_int
name|fu_timer
decl_stmt|;
comment|/* Watchdog timer value */
comment|/* Transmit Queue */
name|H_xmit_queue
name|fu_xmit_q
index|[
name|XMIT_QUELEN
index|]
decl_stmt|;
comment|/* Host queue */
name|H_xmit_queue
modifier|*
name|fu_xmit_head
decl_stmt|;
comment|/* Queue head */
name|H_xmit_queue
modifier|*
name|fu_xmit_tail
decl_stmt|;
comment|/* Queue tail */
name|Q_status
modifier|*
name|fu_xmit_stat
decl_stmt|;
comment|/* Status array (host) */
name|Q_status
modifier|*
name|fu_xmit_statd
decl_stmt|;
comment|/* Status array (DMA) */
comment|/* Receive Queue */
name|H_recv_queue
name|fu_recv_q
index|[
name|RECV_QUELEN
index|]
decl_stmt|;
comment|/* Host queue */
name|H_recv_queue
modifier|*
name|fu_recv_head
decl_stmt|;
comment|/* Queue head */
name|Q_status
modifier|*
name|fu_recv_stat
decl_stmt|;
comment|/* Status array (host) */
name|Q_status
modifier|*
name|fu_recv_statd
decl_stmt|;
comment|/* Status array (DMA) */
name|Recv_descr
modifier|*
name|fu_recv_desc
decl_stmt|;
comment|/* Descriptor array (host) */
name|Recv_descr
modifier|*
name|fu_recv_descd
decl_stmt|;
comment|/* Descriptor array (DMA) */
comment|/* Buffer Supply Queue - Strategy 1 Small */
name|H_buf_queue
name|fu_buf1s_q
index|[
name|BUF1_SM_QUELEN
index|]
decl_stmt|;
comment|/* Host queue */
name|H_buf_queue
modifier|*
name|fu_buf1s_head
decl_stmt|;
comment|/* Queue head */
name|H_buf_queue
modifier|*
name|fu_buf1s_tail
decl_stmt|;
comment|/* Queue tail */
name|Q_status
modifier|*
name|fu_buf1s_stat
decl_stmt|;
comment|/* Status array (host) */
name|Q_status
modifier|*
name|fu_buf1s_statd
decl_stmt|;
comment|/* Status array (DMA) */
name|Buf_descr
modifier|*
name|fu_buf1s_desc
decl_stmt|;
comment|/* Descriptor array (host) */
name|Buf_descr
modifier|*
name|fu_buf1s_descd
decl_stmt|;
comment|/* Descriptor array (DMA) */
name|Queue_t
name|fu_buf1s_bq
decl_stmt|;
comment|/* Queue of supplied buffers */
name|u_int
name|fu_buf1s_cnt
decl_stmt|;
comment|/* Count of supplied buffers */
comment|/* Buffer Supply Queue - Strategy 1 Large */
name|H_buf_queue
name|fu_buf1l_q
index|[
name|BUF1_LG_QUELEN
index|]
decl_stmt|;
comment|/* Host queue */
name|H_buf_queue
modifier|*
name|fu_buf1l_head
decl_stmt|;
comment|/* Queue head */
name|H_buf_queue
modifier|*
name|fu_buf1l_tail
decl_stmt|;
comment|/* Queue tail */
name|Q_status
modifier|*
name|fu_buf1l_stat
decl_stmt|;
comment|/* Status array (host) */
name|Q_status
modifier|*
name|fu_buf1l_statd
decl_stmt|;
comment|/* Status array (DMA) */
name|Buf_descr
modifier|*
name|fu_buf1l_desc
decl_stmt|;
comment|/* Descriptor array (host) */
name|Buf_descr
modifier|*
name|fu_buf1l_descd
decl_stmt|;
comment|/* Descriptor array (DMA) */
name|Queue_t
name|fu_buf1l_bq
decl_stmt|;
comment|/* Queue of supplied buffers */
name|u_int
name|fu_buf1l_cnt
decl_stmt|;
comment|/* Count of supplied buffers */
comment|/* Command Queue */
name|H_cmd_queue
name|fu_cmd_q
index|[
name|CMD_QUELEN
index|]
decl_stmt|;
comment|/* Host queue */
name|H_cmd_queue
modifier|*
name|fu_cmd_head
decl_stmt|;
comment|/* Queue head */
name|H_cmd_queue
modifier|*
name|fu_cmd_tail
decl_stmt|;
comment|/* Queue tail */
name|Q_status
modifier|*
name|fu_cmd_stat
decl_stmt|;
comment|/* Status array (host) */
name|Q_status
modifier|*
name|fu_cmd_statd
decl_stmt|;
comment|/* Status array (DMA) */
name|Fore_stats
modifier|*
name|fu_stats
decl_stmt|;
comment|/* Device statistics buffer */
name|Fore_stats
modifier|*
name|fu_statsd
decl_stmt|;
comment|/* Device statistics buffer (DMA) */
name|time_t
name|fu_stats_time
decl_stmt|;
comment|/* Last stats request timestamp */
name|int
name|fu_stats_ret
decl_stmt|;
comment|/* Stats request return code */
ifdef|#
directive|ifdef
name|FORE_PCI
name|Fore_prom
modifier|*
name|fu_prom
decl_stmt|;
comment|/* Device PROM buffer */
name|Fore_prom
modifier|*
name|fu_promd
decl_stmt|;
comment|/* Device PROM buffer (DMA) */
endif|#
directive|endif
name|struct
name|callout_handle
name|fu_thandle
decl_stmt|;
comment|/* Timer handle */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|fore_unit
name|Fore_unit
typedef|;
end_typedef

begin_define
define|#
directive|define
name|fu_pif
value|fu_cmn.cu_pif
end_define

begin_define
define|#
directive|define
name|fu_unit
value|fu_cmn.cu_unit
end_define

begin_define
define|#
directive|define
name|fu_flags
value|fu_cmn.cu_flags
end_define

begin_define
define|#
directive|define
name|fu_mtu
value|fu_cmn.cu_mtu
end_define

begin_define
define|#
directive|define
name|fu_open_vcc
value|fu_cmn.cu_open_vcc
end_define

begin_define
define|#
directive|define
name|fu_vcc
value|fu_cmn.cu_vcc
end_define

begin_define
define|#
directive|define
name|fu_intrpri
value|fu_cmn.cu_intrpri
end_define

begin_define
define|#
directive|define
name|fu_savepri
value|fu_cmn.cu_savepri
end_define

begin_define
define|#
directive|define
name|fu_vcc_pool
value|fu_cmn.cu_vcc_pool
end_define

begin_define
define|#
directive|define
name|fu_nif_pool
value|fu_cmn.cu_nif_pool
end_define

begin_define
define|#
directive|define
name|fu_ioctl
value|fu_cmn.cu_ioctl
end_define

begin_define
define|#
directive|define
name|fu_instvcc
value|fu_cmn.cu_instvcc
end_define

begin_define
define|#
directive|define
name|fu_openvcc
value|fu_cmn.cu_openvcc
end_define

begin_define
define|#
directive|define
name|fu_closevcc
value|fu_cmn.cu_closevcc
end_define

begin_define
define|#
directive|define
name|fu_output
value|fu_cmn.cu_output
end_define

begin_define
define|#
directive|define
name|fu_config
value|fu_cmn.cu_config
end_define

begin_comment
comment|/*  * Device flags (in addition to CUF_* flags)  */
end_comment

begin_define
define|#
directive|define
name|FUF_STATCMD
value|0x80
end_define

begin_comment
comment|/* Statistics request in progress */
end_comment

begin_comment
comment|/*  * Macros to access CP memory  */
end_comment

begin_define
define|#
directive|define
name|CP_READ
parameter_list|(
name|x
parameter_list|)
value|ntohl((u_long)(x))
end_define

begin_define
define|#
directive|define
name|CP_WRITE
parameter_list|(
name|x
parameter_list|)
value|htonl((u_long)(x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FORE_VAR_H */
end_comment

end_unit

