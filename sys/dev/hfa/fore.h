begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * FORE Systems 200-Series Adapter Support  * ---------------------------------------  *  * Protocol and implementation definitions  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FORE_H
end_ifndef

begin_define
define|#
directive|define
name|_FORE_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|FORE_DEV_NAME
end_ifndef

begin_define
define|#
directive|define
name|FORE_DEV_NAME
value|"hfa"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FORE_MAX_UNITS
value|8
end_define

begin_comment
comment|/* Maximum number of devices we support */
end_comment

begin_define
define|#
directive|define
name|FORE_MIN_UCODE
value|0x20300
end_define

begin_comment
comment|/* Minimum microcode version we support */
end_comment

begin_define
define|#
directive|define
name|FORE_IFF_MTU
value|9188
end_define

begin_comment
comment|/* Network interface MTU */
end_comment

begin_define
define|#
directive|define
name|FORE_MAX_VCC
value|1024
end_define

begin_comment
comment|/* Maximum number of open VCCs */
end_comment

begin_define
define|#
directive|define
name|FORE_MAX_VPI
value|0
end_define

begin_comment
comment|/* Maximum VPI value */
end_comment

begin_define
define|#
directive|define
name|FORE_MAX_VCI
value|1023
end_define

begin_comment
comment|/* Maximum VCI value */
end_comment

begin_define
define|#
directive|define
name|FORE_DEF_RATE
value|0x00000000
end_define

begin_comment
comment|/* Default rate control = disabled */
end_comment

begin_define
define|#
directive|define
name|XMIT_QUELEN
value|32
end_define

begin_comment
comment|/* Length of transmit queue */
end_comment

begin_define
define|#
directive|define
name|RECV_QUELEN
value|32
end_define

begin_comment
comment|/* Length of receive queue */
end_comment

begin_define
define|#
directive|define
name|CMD_QUELEN
value|8
end_define

begin_comment
comment|/* Length of command queue */
end_comment

begin_define
define|#
directive|define
name|FORE_TIME_TICK
value|5
end_define

begin_comment
comment|/* Watchdog timer tick (seconds) */
end_comment

begin_define
define|#
directive|define
name|FORE_WATCHDOG
value|3
end_define

begin_comment
comment|/* Device watchdog timeout (ticks) */
end_comment

begin_define
define|#
directive|define
name|FORE_RECV_RETRY
value|3
end_define

begin_comment
comment|/* Wait for receive queue entry retry count */
end_comment

begin_define
define|#
directive|define
name|FORE_RECV_DELAY
value|10
end_define

begin_comment
comment|/* Wait for receive queue entry delay (usec) */
end_comment

begin_comment
comment|/*  * Receive Buffer strategies  */
end_comment

begin_define
define|#
directive|define
name|BUF_MIN_VCC
value|4
end_define

begin_comment
comment|/* Minimum for buffer supply calculations */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FORE_SBUS
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun4c
argument_list|)
end_if

begin_define
define|#
directive|define
name|BUF_DATA_ALIGN
value|32
end_define

begin_comment
comment|/* Fore-required data alignment */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|sun4m
argument_list|)
end_elif

begin_define
define|#
directive|define
name|BUF_DATA_ALIGN
value|64
end_define

begin_comment
comment|/* Fore-required data alignment */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FORE_PCI
end_ifdef

begin_define
define|#
directive|define
name|BUF_DATA_ALIGN
value|4
end_define

begin_comment
comment|/* Fore-required data alignment */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD
argument_list|)
end_if

begin_comment
comment|/*  * Strategy 1 Small - mbuf  * Strategy 1 Large - cluster mbuf  *  * XXX buffer controls - the RECV_MAX_SEGS calculation comes out wrong  * using the true buffer size values if the CP really only does full-cell  * filling of a particular buffer - we must clarify this...it also appears  * the minimum buffer size is 64, even if the CP can only fit in 1 cell.  */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_Buf_handle
value|16
end_define

begin_comment
comment|/* XXX sizeof(Buf_handle) */
end_comment

begin_if
if|#
directive|if
name|BSD
operator|>=
literal|199103
end_if

begin_undef
undef|#
directive|undef
name|m_ext
end_undef

begin_typedef
typedef|typedef
name|struct
name|m_ext
name|M_ext
typedef|;
end_typedef

begin_define
define|#
directive|define
name|m_ext
value|M_dat.MH.MH_dat.MH_ext
end_define

begin_define
define|#
directive|define
name|BUF1_SM_HOFF
value|(sizeof(struct m_hdr))
end_define

begin_comment
comment|/* Buffer-to-handle offset */
end_comment

begin_define
define|#
directive|define
name|BUF1_SM_HDR
value|(sizeof(struct m_hdr) + sizeof(struct pkthdr))
end_define

begin_define
define|#
directive|define
name|BUF1_SM_LEN
value|(MHLEN)
end_define

begin_define
define|#
directive|define
name|BUF1_LG_HOFF
value|(sizeof(struct m_hdr) + sizeof(struct pkthdr) \ 			    + sizeof(M_ext))
end_define

begin_comment
comment|/* Buffer-to-handle offset */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BUF1_SM_HOFF
value|(MMINOFF)
end_define

begin_comment
comment|/* Buffer-to-handle offset */
end_comment

begin_define
define|#
directive|define
name|BUF1_SM_HDR
value|(MMINOFF)
end_define

begin_define
define|#
directive|define
name|BUF1_SM_LEN
value|(MLEN)
end_define

begin_define
define|#
directive|define
name|BUF1_LG_HOFF
value|(MMINOFF + 16)
end_define

begin_comment
comment|/* Buffer-to-handle offset */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * BUF1_SM_DOFF - CP data offset into buffer data space  * BUF1_SM_SIZE - Buffer size  *  * These should be defined as follows, but we need compile-time constants:  *  *	#define	BUF1_SM_DOFF (roundup(BUF1_SM_HOFF + SIZEOF_Buf_handle,   *			BUF_DATA_ALIGN) - BUF1_SM_HDR)  *	#define	BUF1_SM_SIZE	MAX(BUF1_SM_LEN - BUF1_SM_DOFF, 64)  *  */
end_comment

begin_if
if|#
directive|if
operator|(
operator|(
name|BSD
operator|>=
literal|199103
operator|)
operator|&&
name|defined
argument_list|(
name|FORE_PCI
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|BUF1_SM_DOFF
value|(SIZEOF_Buf_handle)
end_define

begin_define
define|#
directive|define
name|BUF1_SM_SIZE
value|(BUF1_SM_LEN - BUF1_SM_DOFF)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
operator|(
name|BSD
operator|<
literal|199103
operator|)
operator|&&
name|defined
argument_list|(
name|FORE_SBUS
argument_list|)
operator|&&
name|defined
argument_list|(
name|sun4c
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|BUF1_SM_DOFF
value|(BUF_DATA_ALIGN - BUF1_SM_HDR)
end_define

begin_define
define|#
directive|define
name|BUF1_SM_SIZE
value|(BUF1_SM_LEN - BUF1_SM_DOFF)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
operator|(
name|BSD
operator|<
literal|199103
operator|)
operator|&&
name|defined
argument_list|(
name|FORE_SBUS
argument_list|)
operator|&&
name|defined
argument_list|(
name|sun4m
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|BUF1_SM_DOFF
value|(BUF_DATA_ALIGN - BUF1_SM_HDR)
end_define

begin_define
define|#
directive|define
name|BUF1_SM_SIZE
value|(64)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BUF1_SM_QUELEN
value|16
end_define

begin_comment
comment|/* Entries in supply queue */
end_comment

begin_define
define|#
directive|define
name|BUF1_SM_CPPOOL
value|256
end_define

begin_comment
comment|/* Buffers in CP-resident pool */
end_comment

begin_define
define|#
directive|define
name|BUF1_SM_ENTSIZE
value|8
end_define

begin_comment
comment|/* Buffers in each supply queue entry */
end_comment

begin_define
define|#
directive|define
name|BUF1_LG_DOFF
value|0
end_define

begin_comment
comment|/* CP data offset into mbuf data space */
end_comment

begin_define
define|#
directive|define
name|BUF1_LG_SIZE
value|MCLBYTES
end_define

begin_comment
comment|/* Buffer size */
end_comment

begin_define
define|#
directive|define
name|BUF1_LG_QUELEN
value|16
end_define

begin_comment
comment|/* Entries in supply queue */
end_comment

begin_define
define|#
directive|define
name|BUF1_LG_CPPOOL
value|512
end_define

begin_comment
comment|/* Buffers in CP-resident pool */
end_comment

begin_define
define|#
directive|define
name|BUF1_LG_ENTSIZE
value|8
end_define

begin_comment
comment|/* Buffers in each supply queue entry */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(BSD) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FORE_H */
end_comment

end_unit

