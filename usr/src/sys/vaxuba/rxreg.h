begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)rxreg.h	7.2 (Berkeley) 12/22/87  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"ioctl.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * RX02 registers  */
end_comment

begin_struct
struct|struct
name|rxdevice
block|{
name|short
name|rxcs
decl_stmt|;
comment|/* control/status register */
name|short
name|rxdb
decl_stmt|;
comment|/* data buffer register */
block|}
struct|;
end_struct

begin_comment
comment|/*  * RX211 Command and Status Register (RX2CS)  */
end_comment

begin_define
define|#
directive|define
name|RX_DRV0
value|0x0000
end_define

begin_comment
comment|/* select drive 0 */
end_comment

begin_define
define|#
directive|define
name|RX_DRV1
value|0x0010
end_define

begin_comment
comment|/* select drive 1 */
end_comment

begin_define
define|#
directive|define
name|RX_DONE
value|0x0020
end_define

begin_comment
comment|/* function complete */
end_comment

begin_define
define|#
directive|define
name|RX_INTR
value|0x0040
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|RX_TREQ
value|0x0080
end_define

begin_comment
comment|/* transfer request (data only)	*/
end_comment

begin_define
define|#
directive|define
name|RX_SDEN
value|0x0000
end_define

begin_comment
comment|/* single density */
end_comment

begin_define
define|#
directive|define
name|RX_DDEN
value|0x0100
end_define

begin_comment
comment|/* double density */
end_comment

begin_define
define|#
directive|define
name|RX_EXT
value|0x3000
end_define

begin_comment
comment|/* extended address bits */
end_comment

begin_define
define|#
directive|define
name|RX_INIT
value|0x4000
end_define

begin_comment
comment|/* initialize RX211 interface */
end_comment

begin_define
define|#
directive|define
name|RX_ERR
value|0x8000
end_define

begin_comment
comment|/* general error bit */
end_comment

begin_comment
comment|/*  * RX211 control function bits (0-3 of RX2CS)  */
end_comment

begin_define
define|#
directive|define
name|RX_FILL
value|0x0001
end_define

begin_comment
comment|/* fill the buffer */
end_comment

begin_define
define|#
directive|define
name|RX_EMPTY
value|0x0003
end_define

begin_comment
comment|/* empty the buffer */
end_comment

begin_define
define|#
directive|define
name|RX_WRITE
value|0x0005
end_define

begin_comment
comment|/* write the buffer to disk */
end_comment

begin_define
define|#
directive|define
name|RX_READ
value|0x0007
end_define

begin_comment
comment|/* read a disk sector to the buffer */
end_comment

begin_define
define|#
directive|define
name|RX_FORMAT
value|0x0009
end_define

begin_comment
comment|/* set the media density (format) */
end_comment

begin_define
define|#
directive|define
name|RX_RDSTAT
value|0x000b
end_define

begin_comment
comment|/* read the disk status */
end_comment

begin_define
define|#
directive|define
name|RX_WDDS
value|0x000d
end_define

begin_comment
comment|/* write a deleted-data sector */
end_comment

begin_define
define|#
directive|define
name|RX_RDERR
value|0x000f
end_define

begin_comment
comment|/* read the error registers */
end_comment

begin_define
define|#
directive|define
name|RXCS_BITS
define|\
value|"\20\20RX_ERR\17RX_INIT\11RX_DDEN\10RX_TREQ\7RX_IE\6RX_DONE\5RX_DRV1"
end_define

begin_comment
comment|/*  * RX211 Error and Status Register (RX2ES) --  * information is located in RX2DB after completion of function.  * The READY bit's value is available only after a "read status".  */
end_comment

begin_define
define|#
directive|define
name|RXES_CRCERR
value|0x0001
end_define

begin_comment
comment|/* CRC error (data read error) */
end_comment

begin_define
define|#
directive|define
name|RXES_IDONE
value|0x0004
end_define

begin_comment
comment|/* reinitialization complete */
end_comment

begin_define
define|#
directive|define
name|RXES_DENERR
value|0x0010
end_define

begin_comment
comment|/* density error */
end_comment

begin_define
define|#
directive|define
name|RXES_DBLDEN
value|0x0020
end_define

begin_comment
comment|/* set if double density */
end_comment

begin_define
define|#
directive|define
name|RXES_DDMARK
value|0x0040
end_define

begin_comment
comment|/* deleted-data mark */
end_comment

begin_define
define|#
directive|define
name|RXES_READY
value|0x0080
end_define

begin_comment
comment|/* drive is ready */
end_comment

begin_define
define|#
directive|define
name|RXES_BITS
define|\
value|"\20\14RXES_NXM\13RXES_WCOF\11RXES_DRV1\10RXES_RDY\7RXES_DDMK\6RXES_DDEN\5\ RXES_DNER\4RXES_ACLO\3RXES_ID\1RXES_CRC"
end_define

begin_comment
comment|/*   * Ioctl commands, move to dkio.h later  */
end_comment

begin_define
define|#
directive|define
name|RXIOC_FORMAT
value|_IOW('d', 1, int)
end_define

begin_comment
comment|/* format the disk */
end_comment

begin_define
define|#
directive|define
name|RXIOC_WDDS
value|_IOW('d', 2, int)
end_define

begin_comment
comment|/* write `deleted data' mark */
end_comment

begin_comment
comment|/* on next sector */
end_comment

begin_define
define|#
directive|define
name|RXIOC_RDDSMK
value|_IOR('d', 3, int)
end_define

begin_comment
comment|/* did last read sector */
end_comment

begin_comment
comment|/* contain `deleted data'?*/
end_comment

begin_define
define|#
directive|define
name|RXIOC_GDENS
value|_IOR('d', 4, int)
end_define

begin_comment
comment|/* return density of current */
end_comment

begin_comment
comment|/* disk */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RXDEFERR
end_ifdef

begin_comment
comment|/*  * Table of values for definitive error code (rxxt[0]& 0xff)  */
end_comment

begin_struct
struct|struct
name|rxdeferr
block|{
name|short
name|errval
decl_stmt|;
name|char
modifier|*
name|errmsg
decl_stmt|;
block|}
name|rxdeferr
index|[]
init|=
block|{
block|{
literal|0010
block|,
literal|"Can't find home on drive 0"
block|}
block|,
block|{
literal|0020
block|,
literal|"Can't find home on drive 1"
block|}
block|,
block|{
literal|0040
block|,
literal|"Bad track number requested"
block|}
block|,
block|{
literal|0050
block|,
literal|"Home found too soon"
block|}
block|,
block|{
literal|0070
block|,
literal|"Can't find desired sector"
block|}
block|,
block|{
literal|0110
block|,
literal|"No SEP clock seen"
block|}
block|,
block|{
literal|0120
block|,
literal|"No preamble found"
block|}
block|,
block|{
literal|0130
block|,
literal|"Preamble, but no ID mark"
block|}
block|,
block|{
literal|0140
block|,
literal|"Header CRC error"
block|}
block|,
block|{
literal|0150
block|,
literal|"Track addr wrong in header"
block|}
block|,
block|{
literal|0160
block|,
literal|"Too many tries for ID AM"
block|}
block|,
block|{
literal|0170
block|,
literal|"No data AM found"
block|}
block|,
block|{
literal|0200
block|,
literal|"Data CRC error"
block|}
block|,
block|{
literal|0220
block|,
literal|"Maintenance test failure"
block|}
block|,
block|{
literal|0230
block|,
literal|"Word count overflow"
block|}
block|,
block|{
literal|0240
block|,
literal|"Density error"
block|}
block|,
block|{
literal|0250
block|,
literal|"Set-density protocol bad"
block|}
block|,
block|{
literal|0
block|,
literal|"Undefined error code"
block|}
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

