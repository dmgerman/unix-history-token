begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) KATO Takenori, 1996.  All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer as  *    the first lines of this file unmodified.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PC98_PC98_AIC_98_H__
end_ifndef

begin_define
define|#
directive|define
name|__PC98_PC98_AIC_98_H__
end_define

begin_comment
comment|/* generic card */
end_comment

begin_decl_stmt
specifier|static
name|int
name|aicport_generic
index|[
literal|32
index|]
init|=
block|{
literal|0x00
block|,
literal|0x01
block|,
literal|0x02
block|,
literal|0x03
block|,
literal|0x04
block|,
literal|0x05
block|,
literal|0x06
block|,
literal|0x07
block|,
literal|0x08
block|,
literal|0x09
block|,
literal|0x0a
block|,
literal|0x0b
block|,
literal|0x0c
block|,
literal|0x0d
block|,
literal|0x0e
block|,
literal|0x0f
block|,
literal|0x10
block|,
literal|0x11
block|,
literal|0x12
block|,
literal|0x13
block|,
literal|0x14
block|,
literal|0x15
block|,
literal|0x16
block|,
literal|0x17
block|,
literal|0x18
block|,
literal|0x19
block|,
literal|0x1a
block|,
literal|0x1b
block|,
literal|0x1c
block|,
literal|0x1d
block|,
literal|0x1e
block|,
literal|0x1f
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* PC-9801-100 */
end_comment

begin_decl_stmt
specifier|static
name|int
name|aicport_100
index|[
literal|32
index|]
init|=
block|{
literal|0x00
block|,
literal|0x02
block|,
literal|0x04
block|,
literal|0x06
block|,
literal|0x08
block|,
literal|0x0a
block|,
literal|0x0c
block|,
literal|0x0e
block|,
literal|0x10
block|,
literal|0x12
block|,
literal|0x14
block|,
literal|0x16
block|,
literal|0x18
block|,
literal|0x1a
block|,
literal|0x1c
block|,
literal|0x1e
block|,
literal|0x20
block|,
literal|0x22
block|,
literal|0x24
block|,
literal|0x26
block|,
literal|0x28
block|,
literal|0x2a
block|,
literal|0x2c
block|,
literal|0x2e
block|,
literal|0x30
block|,
literal|0x32
block|,
literal|0x34
block|,
literal|0x36
block|,
literal|0x38
block|,
literal|0x3a
block|,
literal|0x3c
block|,
literal|0x3e
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|AIC98_GENERIC
value|0x00
end_define

begin_define
define|#
directive|define
name|AIC98_100
value|0x01
end_define

begin_define
define|#
directive|define
name|AIC_TYPE98
parameter_list|(
name|x
parameter_list|)
value|((x>> 16)& 0xff)
end_define

begin_define
define|#
directive|define
name|SCSISEQ
value|(iobase + aic->aicport[0x00])
end_define

begin_comment
comment|/* SCSI sequence control */
end_comment

begin_define
define|#
directive|define
name|SXFRCTL0
value|(iobase + aic->aicport[0x01])
end_define

begin_comment
comment|/* SCSI transfer control 0 */
end_comment

begin_define
define|#
directive|define
name|SXFRCTL1
value|(iobase + aic->aicport[0x02])
end_define

begin_comment
comment|/* SCSI transfer control 1 */
end_comment

begin_define
define|#
directive|define
name|SCSISIGI
value|(iobase + aic->aicport[0x03])
end_define

begin_comment
comment|/* SCSI signal in */
end_comment

begin_define
define|#
directive|define
name|SCSISIGO
value|(iobase + aic->aicport[0x03])
end_define

begin_comment
comment|/* SCSI signal out */
end_comment

begin_define
define|#
directive|define
name|SCSIRATE
value|(iobase + aic->aicport[0x04])
end_define

begin_comment
comment|/* SCSI rate control */
end_comment

begin_define
define|#
directive|define
name|SCSIID
value|(iobase + aic->aicport[0x05])
end_define

begin_comment
comment|/* SCSI ID */
end_comment

begin_define
define|#
directive|define
name|SELID
value|(iobase + aic->aicport[0x05])
end_define

begin_comment
comment|/* Selection/Reselection ID */
end_comment

begin_define
define|#
directive|define
name|SCSIDAT
value|(iobase + aic->aicport[0x06])
end_define

begin_comment
comment|/* SCSI Latched Data */
end_comment

begin_define
define|#
directive|define
name|SCSIBUS
value|(iobase + aic->aicport[0x07])
end_define

begin_comment
comment|/* SCSI Data Bus*/
end_comment

begin_define
define|#
directive|define
name|STCNT0
value|(iobase + aic->aicport[0x08])
end_define

begin_comment
comment|/* SCSI transfer count */
end_comment

begin_define
define|#
directive|define
name|STCNT1
value|(iobase + aic->aicport[0x09)
end_define

begin_define
define|#
directive|define
name|STCNT2
value|(iobase + aic->aicport[0x0a)
end_define

begin_define
define|#
directive|define
name|CLRSINT0
value|(iobase + aic->aicport[0x0b])
end_define

begin_comment
comment|/* Clear SCSI interrupts 0 */
end_comment

begin_define
define|#
directive|define
name|SSTAT0
value|(iobase + aic->aicport[0x0b])
end_define

begin_comment
comment|/* SCSI interrupt status 0 */
end_comment

begin_define
define|#
directive|define
name|CLRSINT1
value|(iobase + aic->aicport[0x0c])
end_define

begin_comment
comment|/* Clear SCSI interrupts 1 */
end_comment

begin_define
define|#
directive|define
name|SSTAT1
value|(iobase + aic->aicport[0x0c])
end_define

begin_comment
comment|/* SCSI status 1 */
end_comment

begin_define
define|#
directive|define
name|SSTAT2
value|(iobase + aic->aicport[0x0d])
end_define

begin_comment
comment|/* SCSI status 2 */
end_comment

begin_define
define|#
directive|define
name|SCSITEST
value|(iobase + aic->aicport[0x0e])
end_define

begin_comment
comment|/* SCSI test control */
end_comment

begin_define
define|#
directive|define
name|SSTAT3
value|(iobase + aic->aicport[0x0e])
end_define

begin_comment
comment|/* SCSI status 3 */
end_comment

begin_define
define|#
directive|define
name|CLRSERR
value|(iobase + aic->aicport[0x0f])
end_define

begin_comment
comment|/* Clear SCSI errors */
end_comment

begin_define
define|#
directive|define
name|SSTAT4
value|(iobase + aic->aicport[0x0f])
end_define

begin_comment
comment|/* SCSI status 4 */
end_comment

begin_define
define|#
directive|define
name|SIMODE0
value|(iobase + aic->aicport[0x10])
end_define

begin_comment
comment|/* SCSI interrupt mode 0 */
end_comment

begin_define
define|#
directive|define
name|SIMODE1
value|(iobase + aic->aicport[0x11])
end_define

begin_comment
comment|/* SCSI interrupt mode 1 */
end_comment

begin_define
define|#
directive|define
name|DMACNTRL0
value|(iobase + aic->aicport[0x12])
end_define

begin_comment
comment|/* DMA control 0 */
end_comment

begin_define
define|#
directive|define
name|DMACNTRL1
value|(iobase + aic->aicport[0x13])
end_define

begin_comment
comment|/* DMA control 1 */
end_comment

begin_define
define|#
directive|define
name|DMASTAT
value|(iobase + aic->aicport[0x14])
end_define

begin_comment
comment|/* DMA status */
end_comment

begin_define
define|#
directive|define
name|FIFOSTAT
value|(iobase + aic->aicport[0x15])
end_define

begin_comment
comment|/* FIFO status */
end_comment

begin_define
define|#
directive|define
name|DMADATA
value|(iobase + aic->aicport[0x16])
end_define

begin_comment
comment|/* DMA data */
end_comment

begin_define
define|#
directive|define
name|DMADATAL
value|(iobase + aic->aicport[0x16])
end_define

begin_comment
comment|/* DMA data low byte */
end_comment

begin_define
define|#
directive|define
name|DMADATAH
value|(iobase + aic->aicport[0x17])
end_define

begin_comment
comment|/* DMA data high byte */
end_comment

begin_define
define|#
directive|define
name|BRSTCNTRL
value|(iobase + aic->aicport[0x18])
end_define

begin_comment
comment|/* Burst Control */
end_comment

begin_define
define|#
directive|define
name|DMADATALONG
value|(iobase + aic->aicport[0x18)
end_define

begin_define
define|#
directive|define
name|PORTA
value|(iobase + aic->aicport[0x1a])
end_define

begin_comment
comment|/* Port A */
end_comment

begin_define
define|#
directive|define
name|PORTB
value|(iobase + aic->aicport[0x1b])
end_define

begin_comment
comment|/* Port B */
end_comment

begin_define
define|#
directive|define
name|REV
value|(iobase + aic->aicport[0x1c])
end_define

begin_comment
comment|/* Revision (001 for 6360) */
end_comment

begin_define
define|#
directive|define
name|STACK
value|(iobase + aic->aicport[0x1d])
end_define

begin_comment
comment|/* Stack */
end_comment

begin_define
define|#
directive|define
name|TEST
value|(iobase + aic->aicport[0x1e])
end_define

begin_comment
comment|/* Test register */
end_comment

begin_define
define|#
directive|define
name|ID
value|(iobase + aic->aicport[0x1f])
end_define

begin_comment
comment|/* ID register */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

