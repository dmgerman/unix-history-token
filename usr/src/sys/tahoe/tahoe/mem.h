begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)mem.h	7.1 (Berkeley) 5/21/88  */
end_comment

begin_comment
comment|/*  * Memory controller registers  *  */
end_comment

begin_comment
comment|/*  * Some bits definition for MCR  */
end_comment

begin_define
define|#
directive|define
name|EED
value|0x01
end_define

begin_comment
comment|/* Enable error detection */
end_comment

begin_define
define|#
directive|define
name|EEC
value|0x02
end_define

begin_comment
comment|/* Enable error correction */
end_comment

begin_define
define|#
directive|define
name|WMD
value|0x04
end_define

begin_comment
comment|/* Write memory diagnostic */
end_comment

begin_define
define|#
directive|define
name|RMD
value|0x08
end_define

begin_comment
comment|/* Read memory diagnostic */
end_comment

begin_define
define|#
directive|define
name|INT
value|0x20
end_define

begin_comment
comment|/* Init = power on bit */
end_comment

begin_define
define|#
directive|define
name|CEC
value|0x40
end_define

begin_comment
comment|/* Clear error count */
end_comment

begin_define
define|#
directive|define
name|CME
value|0x80
end_define

begin_comment
comment|/* Clear memory error */
end_comment

begin_define
define|#
directive|define
name|CMEC
value|0xff00
end_define

begin_comment
comment|/* Corrected memory error count (mask) */
end_comment

begin_comment
comment|/* shifts to get the values of MCR fields. */
end_comment

begin_define
define|#
directive|define
name|EECSHFT
value|0x01
end_define

begin_comment
comment|/* Enable error correction */
end_comment

begin_define
define|#
directive|define
name|WMDSHFT
value|0x02
end_define

begin_comment
comment|/* Write memory diagnostic */
end_comment

begin_define
define|#
directive|define
name|RMDSHFT
value|0x03
end_define

begin_comment
comment|/* Read memory diagnostic */
end_comment

begin_define
define|#
directive|define
name|INTSHFT
value|0x05
end_define

begin_comment
comment|/* Init = power on bit */
end_comment

begin_define
define|#
directive|define
name|CECSHFT
value|0x06
end_define

begin_comment
comment|/* Clear error count */
end_comment

begin_define
define|#
directive|define
name|CMESHFT
value|0x07
end_define

begin_comment
comment|/* Clear memory error */
end_comment

begin_define
define|#
directive|define
name|CMECSHFT
value|0x08
end_define

begin_comment
comment|/* Corrected memory error count (mask) */
end_comment

begin_comment
comment|/*  * MER bits  */
end_comment

begin_define
define|#
directive|define
name|ERRCD
value|0x07
end_define

begin_comment
comment|/* Error code (mask) */
end_comment

begin_define
define|#
directive|define
name|APE
value|1
end_define

begin_comment
comment|/* Address parity error */
end_comment

begin_define
define|#
directive|define
name|DPE
value|2
end_define

begin_comment
comment|/* Data parity error */
end_comment

begin_define
define|#
directive|define
name|DCE
value|3
end_define

begin_comment
comment|/* Data check error */
end_comment

begin_define
define|#
directive|define
name|VTO
value|4
end_define

begin_comment
comment|/* Versabus timeout */
end_comment

begin_define
define|#
directive|define
name|VBE
value|5
end_define

begin_comment
comment|/* Versabus error */
end_comment

begin_define
define|#
directive|define
name|NEM
value|6
end_define

begin_comment
comment|/* Non-existent memory */
end_comment

begin_define
define|#
directive|define
name|AXE
value|0x08
end_define

begin_comment
comment|/* Adapter external error */
end_comment

begin_define
define|#
directive|define
name|ERM
value|0x10
end_define

begin_comment
comment|/* Error master (0=CPU, 1=Versabus) */
end_comment

begin_define
define|#
directive|define
name|IVV
value|0x100
end_define

begin_comment
comment|/* Illegal Versabus vector */
end_comment

begin_comment
comment|/*  * MCBR bits  */
end_comment

begin_define
define|#
directive|define
name|MCBR
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|MEAR
value|0xffff0000
end_define

end_unit

