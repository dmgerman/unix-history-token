begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|FL_FFC
value|0x200
end_define

begin_comment
comment|/* floppy function complete */
end_comment

begin_define
define|#
directive|define
name|FL_ERR
value|0x80
end_define

begin_comment
comment|/* error bit in floppy status byte */
end_comment

begin_define
define|#
directive|define
name|FL_PERR
value|0x905
end_define

begin_comment
comment|/* Floppy protocol error */
end_comment

begin_define
define|#
directive|define
name|FL_DATA
value|0x100
end_define

begin_comment
comment|/*  floppy data select code */
end_comment

begin_define
define|#
directive|define
name|FL_RS
value|0x900
end_define

begin_comment
comment|/* floppy read sector command */
end_comment

begin_define
define|#
directive|define
name|FL_WS
value|0x901
end_define

begin_comment
comment|/*  floppy write sector command */
end_comment

begin_define
define|#
directive|define
name|FL_STAT
value|0x902
end_define

begin_comment
comment|/* floppy get status command */
end_comment

begin_comment
comment|/*		*/
end_comment

begin_define
define|#
directive|define
name|BLKSIZ
value|512
end_define

begin_comment
comment|/*  tape block size */
end_comment

begin_define
define|#
directive|define
name|RXFTRK
value|77
end_define

begin_comment
comment|/* no. tracks/floppy */
end_comment

begin_define
define|#
directive|define
name|RXSTRK
value|26
end_define

begin_comment
comment|/*  no. sectors/track */
end_comment

begin_define
define|#
directive|define
name|RXBYSEC
value|128
end_define

begin_comment
comment|/*  no. bytes/sector  */
end_comment

begin_define
define|#
directive|define
name|MAXSEC
value|(RXFTRK*RXSTRK)
end_define

begin_comment
comment|/* no. sectors/floppy */
end_comment

end_unit

