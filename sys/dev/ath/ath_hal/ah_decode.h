begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATH_AH_DECODE_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATH_AH_DECODE_H_
end_define

begin_comment
comment|/*  * Register tracing support.  *  * Setting hw.ath.hal.alq=1 enables tracing of all register reads and  * writes to the file /tmp/ath_hal.log.  The file format is a simple  * fixed-size array of records.  When done logging set hw.ath.hal.alq=0  * and then decode the file with the arcode program (that is part of the  * HAL).  If you start+stop tracing the data will be appended to an  * existing file.  */
end_comment

begin_struct
struct|struct
name|athregrec
block|{
name|uint32_t
name|threadid
decl_stmt|;
name|uint32_t
name|op
range|:
literal|8
decl_stmt|,
name|reg
range|:
literal|24
decl_stmt|;
name|uint32_t
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|OP_READ
init|=
literal|0
block|,
comment|/* register read */
name|OP_WRITE
init|=
literal|1
block|,
comment|/* register write */
name|OP_DEVICE
init|=
literal|2
block|,
comment|/* device identification */
name|OP_MARK
init|=
literal|3
block|,
comment|/* application marker */
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|AH_MARK_RESET
block|,
comment|/* ar*Reset entry, bChannelChange */
name|AH_MARK_RESET_LINE
block|,
comment|/* ar*_reset.c, line %d */
name|AH_MARK_RESET_DONE
block|,
comment|/* ar*Reset exit, error code */
name|AH_MARK_CHIPRESET
block|,
comment|/* ar*ChipReset, channel num */
name|AH_MARK_PERCAL
block|,
comment|/* ar*PerCalibration, channel num */
name|AH_MARK_SETCHANNEL
block|,
comment|/* ar*SetChannel, channel num */
name|AH_MARK_ANI_RESET
block|,
comment|/* ar*AniReset, opmode */
name|AH_MARK_ANI_POLL
block|,
comment|/* ar*AniReset, listen time */
name|AH_MARK_ANI_CONTROL
block|,
comment|/* ar*AniReset, cmd */
name|AH_MARK_RX_CTL
block|,
comment|/* RX DMA control */
name|AH_MARK_CHIP_POWER
block|,
comment|/* chip power control, mode */
name|AH_MARK_CHIP_POWER_DONE
block|,
comment|/* chip power control done, status */
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|AH_MARK_RX_CTL_PCU_START
block|,
name|AH_MARK_RX_CTL_PCU_STOP
block|,
name|AH_MARK_RX_CTL_DMA_START
block|,
name|AH_MARK_RX_CTL_DMA_STOP
block|,
name|AH_MARK_RX_CTL_DMA_STOP_ERR
block|,
name|AH_MARK_RX_CTL_DMA_STOP_OK
block|, }
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ATH_AH_DECODE_H_ */
end_comment

end_unit

