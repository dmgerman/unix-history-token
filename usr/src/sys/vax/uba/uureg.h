begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	uureg.h	4.2	83/04/09	*/
end_comment

begin_comment
comment|/*  * DL11-E/DL11-W UNIBUS (for TU58) controller registers  */
end_comment

begin_struct
struct|struct
name|uudevice
block|{
name|short
name|uurcs
decl_stmt|;
comment|/* receiver status register */
name|short
name|uurdb
decl_stmt|;
comment|/* receiver data buffer register */
name|short
name|uutcs
decl_stmt|;
comment|/* transmitter status register */
name|short
name|uutdb
decl_stmt|;
comment|/* transmitter data buffer register */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Receiver status register status/command bits  */
end_comment

begin_define
define|#
directive|define
name|UURCS_DONE
value|0x80
end_define

begin_comment
comment|/* Receiver done (byte ready) */
end_comment

begin_define
define|#
directive|define
name|UURCS_INTR
value|0x40
end_define

begin_comment
comment|/* Receiver interrupt enable */
end_comment

begin_comment
comment|/*  * Receiver data buffer register status bits  */
end_comment

begin_define
define|#
directive|define
name|UURDB_ERROR
value|0x8000
end_define

begin_comment
comment|/* Error (overrun or break) */
end_comment

begin_define
define|#
directive|define
name|UURDB_ORUN
value|0x4000
end_define

begin_comment
comment|/* Data overrun error */
end_comment

begin_define
define|#
directive|define
name|UURDB_BREAK
value|0x2000
end_define

begin_comment
comment|/* TU58 break */
end_comment

begin_comment
comment|/*  * Transmitter status register status/command bits  */
end_comment

begin_define
define|#
directive|define
name|UUTCS_READY
value|0x80
end_define

begin_comment
comment|/* transmitter ready */
end_comment

begin_define
define|#
directive|define
name|UUTCS_INTR
value|0x40
end_define

begin_comment
comment|/* transmitter interrupt enable */
end_comment

begin_define
define|#
directive|define
name|UUTCS_MAINT
value|0x02
end_define

begin_comment
comment|/* maintenance check */
end_comment

begin_define
define|#
directive|define
name|UUTCS_BREAK
value|0x01
end_define

begin_comment
comment|/* send break */
end_comment

begin_define
define|#
directive|define
name|UUDB_DMASK
value|0x00ff
end_define

begin_comment
comment|/* data mask (send and receive data) */
end_comment

end_unit

