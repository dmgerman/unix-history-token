begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain all copyright   *    notices, this list of conditions and the following disclaimer.  * 2. The names of the authors may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   * $FreeBSD$  */
end_comment

begin_comment
comment|/* Definitions for WaveLAN driver */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_WL_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_WL_H
end_define

begin_define
define|#
directive|define
name|STATUS_TRIES
value|15000
end_define

begin_define
define|#
directive|define
name|N_FD
value|100
end_define

begin_define
define|#
directive|define
name|N_RBD
value|100
end_define

begin_define
define|#
directive|define
name|N_TBD
value|72
end_define

begin_define
define|#
directive|define
name|RCVBUFSIZE
value|540
end_define

begin_define
define|#
directive|define
name|I82586NULL
value|0xffff
end_define

begin_define
define|#
directive|define
name|DSF_RUNNING
value|1
end_define

begin_define
define|#
directive|define
name|MOD_ENAL
value|1
end_define

begin_define
define|#
directive|define
name|MOD_PROM
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|rbd_t
name|r
decl_stmt|;
name|char
name|rbd_pad
index|[
literal|2
index|]
decl_stmt|;
name|char
name|rbuffer
index|[
name|RCVBUFSIZE
index|]
decl_stmt|;
block|}
name|ru_t
typedef|;
end_typedef

begin_comment
comment|/* Board 64k RAM layout. Offsets from 0x0000 */
end_comment

begin_define
define|#
directive|define
name|OFFSET_RU
value|0x0000
end_define

begin_comment
comment|/* 0x64 * fd_t = 0x898 */
end_comment

begin_define
define|#
directive|define
name|OFFSET_RBD
value|0x0900
end_define

begin_comment
comment|/* 0x64 * ru_t = 0xd7a0 */
end_comment

begin_define
define|#
directive|define
name|OFFSET_CU
value|0xe0a0
end_define

begin_comment
comment|/* 0x100 */
end_comment

begin_define
define|#
directive|define
name|OFFSET_TBD
value|0xe1a0
end_define

begin_comment
comment|/* 0x48 * tbd_t = 0x240 */
end_comment

begin_define
define|#
directive|define
name|OFFSET_TBUF
value|0xe3e0
end_define

begin_comment
comment|/* 0x1bfe */
end_comment

begin_define
define|#
directive|define
name|OFFSET_SCB
value|0xffde
end_define

begin_comment
comment|/* 0x1 * scb_t = 0x10 */
end_comment

begin_define
define|#
directive|define
name|OFFSET_ISCP
value|0xffee
end_define

begin_comment
comment|/* 0x1 * iscp_t = 0x8 */
end_comment

begin_define
define|#
directive|define
name|OFFSET_SCP
value|0xfff6
end_define

begin_comment
comment|/* 0x1 * scp_t = 0xa */
end_comment

begin_comment
comment|/* WaveLAN host interface definitions */
end_comment

begin_define
define|#
directive|define
name|HACR
parameter_list|(
name|base
parameter_list|)
value|(base)
end_define

begin_comment
comment|/* Host Adapter Command Register */
end_comment

begin_define
define|#
directive|define
name|HASR
parameter_list|(
name|base
parameter_list|)
value|(base)
end_define

begin_comment
comment|/* Host Adapter Status Register */
end_comment

begin_define
define|#
directive|define
name|MMCR
parameter_list|(
name|base
parameter_list|)
value|(base+0x2)
end_define

begin_comment
comment|/* Modem Management Ctrl Register */
end_comment

begin_define
define|#
directive|define
name|PIOR0
parameter_list|(
name|base
parameter_list|)
value|(base+0x4)
end_define

begin_comment
comment|/* Program I/O Address Register 0 */
end_comment

begin_define
define|#
directive|define
name|PIOP0
parameter_list|(
name|base
parameter_list|)
value|(base+0x6)
end_define

begin_comment
comment|/* Program I/O Port 0 */
end_comment

begin_define
define|#
directive|define
name|PIOR1
parameter_list|(
name|base
parameter_list|)
value|(base+0x8)
end_define

begin_comment
comment|/* Program I/O Address Register 1 */
end_comment

begin_define
define|#
directive|define
name|PIOP1
parameter_list|(
name|base
parameter_list|)
value|(base+0xa)
end_define

begin_comment
comment|/* Program I/O Port 1 */
end_comment

begin_define
define|#
directive|define
name|PIOR2
parameter_list|(
name|base
parameter_list|)
value|(base+0xc)
end_define

begin_comment
comment|/* Program I/O Address Register 2 */
end_comment

begin_define
define|#
directive|define
name|PIOP2
parameter_list|(
name|base
parameter_list|)
value|(base+0xe)
end_define

begin_comment
comment|/* Program I/O Port 2 */
end_comment

begin_comment
comment|/* Program I/O Mode Register values */
end_comment

begin_define
define|#
directive|define
name|STATIC_PIO
value|0
end_define

begin_comment
comment|/* Mode 1: static mode */
end_comment

begin_define
define|#
directive|define
name|AUTOINCR_PIO
value|1
end_define

begin_comment
comment|/* Mode 2: auto increment mode */
end_comment

begin_define
define|#
directive|define
name|AUTODECR_PIO
value|2
end_define

begin_comment
comment|/* Mode 3: auto decrement mode */
end_comment

begin_define
define|#
directive|define
name|PARAM_ACCESS_PIO
value|3
end_define

begin_comment
comment|/* Mode 4: LAN parameter access mode */
end_comment

begin_define
define|#
directive|define
name|PIO_MASK
value|3
end_define

begin_comment
comment|/* register mask */
end_comment

begin_define
define|#
directive|define
name|PIOM
parameter_list|(
name|cmd
parameter_list|,
name|piono
parameter_list|)
value|((u_short)cmd<< 10<< (piono * 2))
end_define

begin_comment
comment|/* Host Adapter status register definitions */
end_comment

begin_define
define|#
directive|define
name|HASR_INTR
value|0x0001
end_define

begin_comment
comment|/* Interrupt request from 82586 */
end_comment

begin_define
define|#
directive|define
name|HASR_MMC_INTR
value|0x0002
end_define

begin_comment
comment|/* Interrupt request from MMC */
end_comment

begin_define
define|#
directive|define
name|HASR_MMC_BUSY
value|0x0004
end_define

begin_comment
comment|/* MMC busy indication */
end_comment

begin_define
define|#
directive|define
name|HASR_PARA_BUSY
value|0x0008
end_define

begin_comment
comment|/* LAN parameter storage area busy */
end_comment

begin_comment
comment|/* Host Adapter command register definitions */
end_comment

begin_define
define|#
directive|define
name|HACR_RESET
value|0x0001
end_define

begin_comment
comment|/* Reset board */
end_comment

begin_define
define|#
directive|define
name|HACR_CA
value|0x0002
end_define

begin_comment
comment|/* Set Channel Attention for 82586 */
end_comment

begin_define
define|#
directive|define
name|HACR_16BITS
value|0x0004
end_define

begin_comment
comment|/* 1==16 bits operation, 0==8 bits */
end_comment

begin_define
define|#
directive|define
name|HACR_OUT1
value|0x0008
end_define

begin_comment
comment|/* General purpose output pin */
end_comment

begin_define
define|#
directive|define
name|HACR_OUT2
value|0x0010
end_define

begin_comment
comment|/* General purpose output pin */
end_comment

begin_define
define|#
directive|define
name|HACR_MASK_82586
value|0x0020
end_define

begin_comment
comment|/* Mask 82586 interrupts, 1==unmask */
end_comment

begin_define
define|#
directive|define
name|HACR_MASK_MMC
value|0x0040
end_define

begin_comment
comment|/* Mask MMC interrupts, 1==unmask */
end_comment

begin_define
define|#
directive|define
name|HACR_INTR_CLEN
value|0x0080
end_define

begin_comment
comment|/* interrupt status clear enable */
end_comment

begin_define
define|#
directive|define
name|HACR_DEFAULT
value|(HACR_OUT1 | HACR_OUT2 | HACR_16BITS | PIOM(STATIC_PIO, 0) | PIOM(AUTOINCR_PIO, 1) | PIOM(PARAM_ACCESS_PIO, 2))
end_define

begin_define
define|#
directive|define
name|HACR_INTRON
value|(HACR_MASK_82586 | HACR_MASK_MMC | HACR_INTR_CLEN)
end_define

begin_define
define|#
directive|define
name|CMD
parameter_list|(
name|unit
parameter_list|)
define|\
value|{ \ 		   outw(HACR(WLSOFTC(unit)->base),WLSOFTC(unit)->hacr); \
comment|/* delay for 50 us, might only be needed sometimes */
value|\ 		   DELAY(DELAYCONST); \ 	        }
end_define

begin_comment
comment|/* macro for setting the channel attention bit.  No delays here since  * it is used in critical sections  */
end_comment

begin_define
define|#
directive|define
name|SET_CHAN_ATTN
parameter_list|(
name|unit
parameter_list|)
define|\
value|{ \          outw(HACR(WLSOFTC(unit)->base),WLSOFTC(unit)->hacr | HACR_CA); \       }
end_define

begin_define
define|#
directive|define
name|MMC_WRITE
parameter_list|(
name|cmd
parameter_list|,
name|val
parameter_list|)
define|\
value|while(inw(HASR(WLSOFTC(unit)->base))& HASR_MMC_BUSY) ; \ 	outw(MMCR(WLSOFTC(unit)->base), \ 	     (u_short)(((u_short)(val)<< 8) | ((cmd)<< 1) | 1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_WL_H */
end_comment

end_unit

