begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	if_unreg.h	6.1	83/07/29	*/
end_comment

begin_comment
comment|/*  * Device registers and bit meanings  */
end_comment

begin_struct
struct|struct
name|undevice
block|{
name|short
name|wcr
decl_stmt|;
comment|/* word count */
name|short
name|bar
decl_stmt|;
comment|/* bus address */
name|short
name|csr
decl_stmt|;
comment|/* control& status (also error& info) */
name|short
name|dar
decl_stmt|;
comment|/* input and output data register */
block|}
struct|;
end_struct

begin_comment
comment|/* CSR bits */
end_comment

begin_define
define|#
directive|define
name|GO
value|0000001
end_define

begin_define
define|#
directive|define
name|FCN1
value|0000002
end_define

begin_comment
comment|/* three function bits */
end_comment

begin_define
define|#
directive|define
name|FCN2
value|0000004
end_define

begin_define
define|#
directive|define
name|FCN3
value|0000010
end_define

begin_define
define|#
directive|define
name|XBA
value|0000060
end_define

begin_comment
comment|/* extended bus address (16&17) */
end_comment

begin_define
define|#
directive|define
name|IE
value|0000100
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|RDY
value|0000200
end_define

begin_comment
comment|/* ready */
end_comment

begin_define
define|#
directive|define
name|CYCL
value|0000400
end_define

begin_comment
comment|/* cycle */
end_comment

begin_define
define|#
directive|define
name|STATC
value|0001000
end_define

begin_comment
comment|/* Status bit C */
end_comment

begin_define
define|#
directive|define
name|STATB
value|0002000
end_define

begin_comment
comment|/* Status bit B */
end_comment

begin_define
define|#
directive|define
name|STATA
value|0004000
end_define

begin_comment
comment|/* Status bit A */
end_comment

begin_define
define|#
directive|define
name|MNT
value|0010000
end_define

begin_comment
comment|/* maintenance */
end_comment

begin_define
define|#
directive|define
name|ATTN
value|0020000
end_define

begin_comment
comment|/* attention (from device) */
end_comment

begin_define
define|#
directive|define
name|NEX
value|0040000
end_define

begin_comment
comment|/* non-existent memory */
end_comment

begin_define
define|#
directive|define
name|ERR
value|0100000
end_define

begin_define
define|#
directive|define
name|XADD
value|4
end_define

begin_define
define|#
directive|define
name|UNBITS
value|"\10\20ERR\17NEX\16ATTN\15MNT\14STATA\13STATB\12STATC\ \11CYCL\10RDY\7IE\6XBA17\5XBA16\4FCN3\3FCN2\2FCN1\1GO"
end_define

begin_comment
comment|/* EIR bits */
end_comment

begin_define
define|#
directive|define
name|RF
value|0000001
end_define

begin_comment
comment|/* register flag 1 - verifies EIR */
end_comment

begin_define
define|#
directive|define
name|NBST
value|0000400
end_define

begin_comment
comment|/* N - cycle burst */
end_comment

begin_define
define|#
directive|define
name|BDLT
value|0001000
end_define

begin_comment
comment|/* burst data late */
end_comment

begin_define
define|#
directive|define
name|PERR
value|0002000
end_define

begin_comment
comment|/* parity error */
end_comment

begin_define
define|#
directive|define
name|ACLO
value|0004000
end_define

begin_comment
comment|/* power fail */
end_comment

begin_define
define|#
directive|define
name|MCYC
value|0010000
end_define

begin_comment
comment|/* multicycle request */
end_comment

begin_define
define|#
directive|define
name|ATTN
value|0020000
end_define

begin_comment
comment|/* attention (from device) */
end_comment

begin_define
define|#
directive|define
name|NEX
value|0040000
end_define

begin_comment
comment|/* non-existent memory */
end_comment

begin_define
define|#
directive|define
name|ERR
value|0100000
end_define

begin_comment
comment|/* Network interface commands */
end_comment

begin_define
define|#
directive|define
name|UNRESET
value|0
end_define

begin_define
define|#
directive|define
name|UNRDHDR
value|FCN1
end_define

begin_define
define|#
directive|define
name|UNOUT
value|FCN2
end_define

begin_define
define|#
directive|define
name|UNRDDG
value|(FCN2|FCN1)
end_define

begin_define
define|#
directive|define
name|UNFLUSH
value|FCN3
end_define

begin_define
define|#
directive|define
name|UNIDLE
value|(FCN3|FCN2)
end_define

begin_comment
comment|/* Extended status bits (in dar) */
end_comment

begin_define
define|#
directive|define
name|RESETACK
value|1
end_define

begin_comment
comment|/* Reset cmd acknowledged */
end_comment

end_unit

