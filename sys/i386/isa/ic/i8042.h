begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|KBSTATP
value|0x64
end_define

begin_comment
comment|/* kbd controller status port (I) */
end_comment

begin_define
define|#
directive|define
name|KBS_DIB
value|0x01
end_define

begin_comment
comment|/* kbd data in buffer */
end_comment

begin_define
define|#
directive|define
name|KBS_IBF
value|0x02
end_define

begin_comment
comment|/* kbd input buffer low */
end_comment

begin_define
define|#
directive|define
name|KBS_WARM
value|0x04
end_define

begin_comment
comment|/* kbd input buffer low */
end_comment

begin_define
define|#
directive|define
name|KBS_OCMD
value|0x08
end_define

begin_comment
comment|/* kbd output buffer has command */
end_comment

begin_define
define|#
directive|define
name|KBS_NOSEC
value|0x10
end_define

begin_comment
comment|/* kbd security lock not engaged */
end_comment

begin_define
define|#
directive|define
name|KBS_TERR
value|0x20
end_define

begin_comment
comment|/* kbd transmission error */
end_comment

begin_define
define|#
directive|define
name|KBS_RERR
value|0x40
end_define

begin_comment
comment|/* kbd receive error */
end_comment

begin_define
define|#
directive|define
name|KBS_PERR
value|0x80
end_define

begin_comment
comment|/* kbd parity error */
end_comment

begin_define
define|#
directive|define
name|KBCMDP
value|0x64
end_define

begin_comment
comment|/* kbd controller port (O) */
end_comment

begin_define
define|#
directive|define
name|KBDATAP
value|0x60
end_define

begin_comment
comment|/* kbd data port (I) */
end_comment

begin_define
define|#
directive|define
name|KBOUTP
value|0x60
end_define

begin_comment
comment|/* kbd data port (O) */
end_comment

begin_define
define|#
directive|define
name|K_LDCMDBYTE
value|0x60
end_define

begin_define
define|#
directive|define
name|KC8_TRANS
value|0x40
end_define

begin_comment
comment|/* convert to old scan codes */
end_comment

begin_define
define|#
directive|define
name|KC8_OLDPC
value|0x20
end_define

begin_comment
comment|/* old 9bit codes instead of new 11bit */
end_comment

begin_define
define|#
directive|define
name|KC8_DISABLE
value|0x10
end_define

begin_comment
comment|/* disable keyboard */
end_comment

begin_define
define|#
directive|define
name|KC8_IGNSEC
value|0x08
end_define

begin_comment
comment|/* ignore security lock */
end_comment

begin_define
define|#
directive|define
name|KC8_CPU
value|0x04
end_define

begin_comment
comment|/* exit from protected mode reset */
end_comment

begin_define
define|#
directive|define
name|KC8_IEN
value|0x01
end_define

begin_comment
comment|/* enable interrupt */
end_comment

begin_define
define|#
directive|define
name|CMDBYTE
value|(KC8_TRANS|KC8_IGNSEC|KC8_CPU|KC8_IEN)
end_define

end_unit

