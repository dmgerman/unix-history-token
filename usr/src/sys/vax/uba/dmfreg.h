begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)dmfreg.h	7.2 (Berkeley) 2/19/87  */
end_comment

begin_comment
comment|/*  * DMF-32 definitions.  */
end_comment

begin_comment
comment|/*  * "dmfa" refers to the async portion of the dmf32,  * "dmfc" to the combo portion,  * "dmfs" to the sync portion,  * "dmfl" to the lp portion, and  * "dmfd" to the dr portion.  */
end_comment

begin_struct
struct|struct
name|dmfdevice
block|{
name|short
name|dmfccsr0
decl_stmt|;
comment|/* combo csr 0 */
name|short
name|dmfccsr1
decl_stmt|;
comment|/* combo csr 1 */
name|short
name|dmfs
index|[
literal|4
index|]
decl_stmt|;
comment|/* synch. device */
name|struct
name|dmx_octet
name|dmfa
decl_stmt|;
comment|/* asynch portion */
name|short
name|dmfl_ctrl
decl_stmt|;
comment|/* line printer control register */
name|short
name|dmfl_indrct
decl_stmt|;
comment|/* line printer indirect register */
name|short
name|dmfd
index|[
literal|4
index|]
decl_stmt|;
comment|/* for dr11 (not implemented) */
block|}
struct|;
end_struct

begin_comment
comment|/* dmf line printer csr def */
end_comment

begin_define
define|#
directive|define
name|DMFL_PEN
value|(1<<0)
end_define

begin_comment
comment|/* print enable */
end_comment

begin_define
define|#
directive|define
name|DMFL_RESET
value|(1<<1)
end_define

begin_comment
comment|/* master reset */
end_comment

begin_define
define|#
directive|define
name|DMFL_FORMAT
value|(1<<2)
end_define

begin_comment
comment|/* format control */
end_comment

begin_define
define|#
directive|define
name|DMFL_UNUSED
value|(3<<3)
end_define

begin_define
define|#
directive|define
name|DMFL_MAINT
value|(1<<5)
end_define

begin_comment
comment|/* maintenance mode on */
end_comment

begin_define
define|#
directive|define
name|DMFL_IE
value|(1<<6)
end_define

begin_comment
comment|/* intr enable */
end_comment

begin_define
define|#
directive|define
name|DMFL_PDONE
value|(1<<7)
end_define

begin_comment
comment|/* print done bit */
end_comment

begin_define
define|#
directive|define
name|DMFL_INDIR
value|(7<<8)
end_define

begin_comment
comment|/* indirect reg */
end_comment

begin_define
define|#
directive|define
name|DMFL_UNUSED2
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|DMFL_CONV
value|(1<<12)
end_define

begin_comment
comment|/* connect verify */
end_comment

begin_define
define|#
directive|define
name|DMFL_DAVRDY
value|(1<<13)
end_define

begin_comment
comment|/* davfu ready */
end_comment

begin_define
define|#
directive|define
name|DMFL_OFFLINE
value|(1<<14)
end_define

begin_comment
comment|/* printer offline */
end_comment

begin_define
define|#
directive|define
name|DMFL_DMAERR
value|(1<<15)
end_define

begin_comment
comment|/* dma error bit */
end_comment

begin_define
define|#
directive|define
name|DMFL_BUFSIZ
value|512
end_define

begin_comment
comment|/* max chars per dma */
end_comment

begin_define
define|#
directive|define
name|DMFL_DEFCOLS
value|132
end_define

begin_comment
comment|/* default # of cols/line<=255 */
end_comment

begin_define
define|#
directive|define
name|DMFL_DEFLINES
value|66
end_define

begin_comment
comment|/* default # of lines/page<=255 */
end_comment

begin_define
define|#
directive|define
name|DMFL_OPTIONS
value|((1<< 8) | (1<< 9) | (1<< 15))
end_define

begin_comment
comment|/* auto cr, real ff, no lower to upper */
end_comment

begin_comment
comment|/*  *  Bits in the configuration register  */
end_comment

begin_define
define|#
directive|define
name|DMFC_CONFMASK
value|0xf000
end_define

begin_comment
comment|/* picks off the configuration bits */
end_comment

begin_define
define|#
directive|define
name|DMFC_DR
value|0x1000
end_define

begin_comment
comment|/* DR11 parallel interface */
end_comment

begin_define
define|#
directive|define
name|DMFC_LP
value|0x2000
end_define

begin_comment
comment|/* LP dma parallel lineprinter i'face */
end_comment

begin_define
define|#
directive|define
name|DMFC_SYNC
value|0x4000
end_define

begin_comment
comment|/* Synchronous serial interface */
end_comment

begin_define
define|#
directive|define
name|DMFC_ASYNC
value|0x8000
end_define

begin_comment
comment|/* 8 Serial ports */
end_comment

end_unit

