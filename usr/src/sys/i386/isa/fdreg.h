begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * AT floppy controller registers and bitfields  *	@(#)fdreg.h	1.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* uses NEC765 controller */
end_comment

begin_include
include|#
directive|include
file|"../i386/isa/ic/nec765.h"
end_include

begin_comment
comment|/* registers */
end_comment

begin_define
define|#
directive|define
name|fdout
value|2
end_define

begin_comment
comment|/* Digital Output Register (W) */
end_comment

begin_define
define|#
directive|define
name|FDO_FDSEL
value|0x01
end_define

begin_comment
comment|/*  floppy device select */
end_comment

begin_define
define|#
directive|define
name|FDO_FRST
value|0x04
end_define

begin_comment
comment|/*  floppy controller reset */
end_comment

begin_define
define|#
directive|define
name|FDO_FDMAEN
value|0x08
end_define

begin_comment
comment|/*  enable floppy DMA and Interrupt */
end_comment

begin_define
define|#
directive|define
name|FDO_MOEN0
value|0x10
end_define

begin_comment
comment|/*  motor enable drive 0 */
end_comment

begin_define
define|#
directive|define
name|FDO_MOEN1
value|0x20
end_define

begin_comment
comment|/*  motor enable drive 1 */
end_comment

begin_define
define|#
directive|define
name|fdsts
value|4
end_define

begin_comment
comment|/* NEC 765 Main Status Register (R) */
end_comment

begin_define
define|#
directive|define
name|fddata
value|5
end_define

begin_comment
comment|/* NEC 765 Data Register (R/W) */
end_comment

begin_define
define|#
directive|define
name|fdctl
value|7
end_define

begin_comment
comment|/* Control Register (W) */
end_comment

begin_define
define|#
directive|define
name|FDC_500KBPS
value|0x00
end_define

begin_comment
comment|/* 500KBPS MFM drive transfer rate */
end_comment

begin_define
define|#
directive|define
name|FDC_300KBPS
value|0x01
end_define

begin_comment
comment|/* 300KBPS MFM drive transfer rate */
end_comment

begin_define
define|#
directive|define
name|FDC_250KBPS
value|0x02
end_define

begin_comment
comment|/* 250KBPS MFM drive transfer rate */
end_comment

begin_define
define|#
directive|define
name|FDC_125KBPS
value|0x03
end_define

begin_comment
comment|/* 125KBPS FM drive transfer rate */
end_comment

begin_define
define|#
directive|define
name|fdin
value|7
end_define

begin_comment
comment|/* Digital Input Register (R) */
end_comment

begin_define
define|#
directive|define
name|FDI_DCHG
value|0x80
end_define

begin_comment
comment|/* diskette has been changed */
end_comment

end_unit

