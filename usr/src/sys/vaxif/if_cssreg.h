begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)if_cssreg.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_comment
comment|/*   * DEC/CSS IMP11-A ARPAnet interface  */
end_comment

begin_struct
struct|struct
name|cssdma
block|{
name|short
name|wc
decl_stmt|;
comment|/* word count */
name|u_short
name|ba
decl_stmt|;
comment|/* bus address (low 16 bits) */
name|short
name|csr
decl_stmt|;
comment|/* status register */
name|short
name|db
decl_stmt|;
comment|/* data buffer*/
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cssdevice
block|{
name|struct
name|cssdma
name|css_output
decl_stmt|;
comment|/* transmit DR11-B */
name|struct
name|cssdma
name|css_hole
decl_stmt|;
comment|/* unclever gap */
name|struct
name|cssdma
name|css_input
decl_stmt|;
comment|/* receive DR11-B */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|css_icsr
value|css_input.csr
end_define

begin_define
define|#
directive|define
name|css_iba
value|css_input.ba
end_define

begin_define
define|#
directive|define
name|css_iwc
value|css_input.wc
end_define

begin_define
define|#
directive|define
name|css_ocsr
value|css_output.csr
end_define

begin_define
define|#
directive|define
name|css_oba
value|css_output.ba
end_define

begin_define
define|#
directive|define
name|css_owc
value|css_output.wc
end_define

begin_comment
comment|/*  * Bits Common to both input and out CSR's  */
end_comment

begin_define
define|#
directive|define
name|CSS_ERR
value|0x8000
end_define

begin_comment
comment|/* error present */
end_comment

begin_define
define|#
directive|define
name|CSS_NXM
value|0x4000
end_define

begin_comment
comment|/* non-existant memory */
end_comment

begin_define
define|#
directive|define
name|CSS_ATTN
value|0x2000
end_define

begin_comment
comment|/* attention */
end_comment

begin_define
define|#
directive|define
name|CSS_MAINT
value|0x1000
end_define

begin_comment
comment|/* maintenance mode */
end_comment

begin_define
define|#
directive|define
name|CSS_CYCLE
value|0x0100
end_define

begin_comment
comment|/* force bus cycle */
end_comment

begin_define
define|#
directive|define
name|CSS_RDY
value|0x0080
end_define

begin_comment
comment|/* ready */
end_comment

begin_define
define|#
directive|define
name|CSS_IE
value|0x0040
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|CSS_XA
value|0x0030
end_define

begin_comment
comment|/* extended address bits */
end_comment

begin_define
define|#
directive|define
name|CSS_CLR
value|0x0020
end_define

begin_comment
comment|/* clear status (reset) */
end_comment

begin_define
define|#
directive|define
name|CSS_GO
value|0x0001
end_define

begin_comment
comment|/* start operation */
end_comment

begin_comment
comment|/*  * Input Control Status Register  */
end_comment

begin_define
define|#
directive|define
name|IN_EOM
value|0x0800
end_define

begin_comment
comment|/* end-of-message recieved */
end_comment

begin_define
define|#
directive|define
name|IN_IMPNR
value|0x0400
end_define

begin_comment
comment|/* IMP not ready */
end_comment

begin_define
define|#
directive|define
name|IN_RLE
value|0x0200
end_define

begin_comment
comment|/* ready line error */
end_comment

begin_define
define|#
directive|define
name|IN_WEN
value|0x0008
end_define

begin_comment
comment|/* write enable */
end_comment

begin_define
define|#
directive|define
name|IN_HRDY
value|0x0004
end_define

begin_comment
comment|/* host ready */
end_comment

begin_define
define|#
directive|define
name|CSS_INBITS
define|\
value|"\20\20ERR\17NXM\16ATTN\15MAINT\14EOM\13IMPNR\12RLE\11CYCLE\10RDY\7IE\6XBA17\5XBA16\4WE\3HRDY\2CLR\1GO"
end_define

begin_comment
comment|/*  * Output Control Status Register  */
end_comment

begin_define
define|#
directive|define
name|OUT_TXEC
value|0x0008
end_define

begin_comment
comment|/* tx error clear */
end_comment

begin_define
define|#
directive|define
name|OUT_ENLB
value|0x0004
end_define

begin_comment
comment|/* enable last bit */
end_comment

begin_define
define|#
directive|define
name|CSS_OUTBITS
define|\
value|"\20\20ERR\17NXM\16ATTN\15MAINT\11CYCLE\10RDY\7IE\6XBA17\5XBA16\4TXEC\3ENLB\2CLR\1GO"
end_define

end_unit

