begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	dmfreg.h	6.1	83/07/29	*/
end_comment

begin_comment
comment|/*  * DMF-32 definitions.  */
end_comment

begin_comment
comment|/*  * "dmf" (unqualified) refers to the async portion of the dmf32,  * "dmfc" to the combo portion,  * "dmfs" to the sync portion,  * "dmfl" to the lp portion, and  * "dmfd" to the dr portion.  */
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
name|short
name|dmfcsr
decl_stmt|;
comment|/* control-status register */
name|short
name|dmflpr
decl_stmt|;
comment|/* line parameter register */
name|short
name|dmfrbuf
decl_stmt|;
comment|/* receiver buffer (ro) */
union|union
block|{
name|u_short
name|dmfirw
decl_stmt|;
comment|/* indirect register word */
name|u_char
name|dmfirc
index|[
literal|2
index|]
decl_stmt|;
comment|/*    "         "    bytes */
block|}
name|dmfun
union|;
name|short
name|dmfl
index|[
literal|2
index|]
decl_stmt|;
name|short
name|dmfd
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|dmfrsp
value|dmfrbuf
end_define

begin_comment
comment|/* receive silo parameter register (wo) */
end_comment

begin_define
define|#
directive|define
name|dmftbuf
value|dmfun.dmfirc[0]
end_define

begin_comment
comment|/* transmit buffer */
end_comment

begin_define
define|#
directive|define
name|dmftsc
value|dmfun.dmfirc[0]
end_define

begin_comment
comment|/* transmit silo count */
end_comment

begin_define
define|#
directive|define
name|dmfrms
value|dmfun.dmfirc[1]
end_define

begin_comment
comment|/* receive modem status */
end_comment

begin_define
define|#
directive|define
name|dmflcr
value|dmfun.dmfirc[0]
end_define

begin_comment
comment|/* line control register */
end_comment

begin_define
define|#
directive|define
name|dmftms
value|dmfun.dmfirc[1]
end_define

begin_comment
comment|/* transmit modem status */
end_comment

begin_define
define|#
directive|define
name|dmftba
value|dmfun.dmfirw
end_define

begin_comment
comment|/* transmit buffer address */
end_comment

begin_define
define|#
directive|define
name|dmftcc
value|dmfun.dmfirw
end_define

begin_comment
comment|/* transmit character count */
end_comment

begin_comment
comment|/* bits in dmfcsr */
end_comment

begin_define
define|#
directive|define
name|DMF_TI
value|0100000
end_define

begin_comment
comment|/* transmit interrupt */
end_comment

begin_define
define|#
directive|define
name|DMF_TIE
value|0040000
end_define

begin_comment
comment|/* transmit interrupt enable */
end_comment

begin_define
define|#
directive|define
name|DMF_NXM
value|0020000
end_define

begin_comment
comment|/* non-existant memory */
end_comment

begin_define
define|#
directive|define
name|DMF_LIN
value|0003400
end_define

begin_comment
comment|/* transmit line number */
end_comment

begin_define
define|#
directive|define
name|DMF_RI
value|0000200
end_define

begin_comment
comment|/* receiver interrupt */
end_comment

begin_define
define|#
directive|define
name|DMF_RIE
value|0000100
end_define

begin_comment
comment|/* receiver interrupt enable */
end_comment

begin_define
define|#
directive|define
name|DMF_CLR
value|0000040
end_define

begin_comment
comment|/* master reset */
end_comment

begin_define
define|#
directive|define
name|DMF_IAD
value|0000037
end_define

begin_comment
comment|/* indirect address register */
end_comment

begin_define
define|#
directive|define
name|DMFIR_TBUF
value|000
end_define

begin_comment
comment|/* select tbuf indirect register */
end_comment

begin_define
define|#
directive|define
name|DMFIR_LCR
value|010
end_define

begin_comment
comment|/* select lcr indirect register */
end_comment

begin_define
define|#
directive|define
name|DMFIR_TBA
value|020
end_define

begin_comment
comment|/* select tba indirect register */
end_comment

begin_define
define|#
directive|define
name|DMFIR_TCC
value|030
end_define

begin_comment
comment|/* select tcc indirect register */
end_comment

begin_comment
comment|/* bits in dmflpr */
end_comment

begin_define
define|#
directive|define
name|BITS6
value|(01<<3)
end_define

begin_define
define|#
directive|define
name|BITS7
value|(02<<3)
end_define

begin_define
define|#
directive|define
name|BITS8
value|(03<<3)
end_define

begin_define
define|#
directive|define
name|TWOSB
value|0200
end_define

begin_define
define|#
directive|define
name|PENABLE
value|040
end_define

begin_define
define|#
directive|define
name|EPAR
value|0100
end_define

begin_define
define|#
directive|define
name|DMF_IE
value|(DMF_TIE|DMF_RIE)
end_define

begin_define
define|#
directive|define
name|DMF_SILOCNT
value|32
end_define

begin_comment
comment|/* size of DMF output silo (per line) */
end_comment

begin_comment
comment|/* bits in dmfrbuf */
end_comment

begin_define
define|#
directive|define
name|DMF_DSC
value|0004000
end_define

begin_comment
comment|/* data set change */
end_comment

begin_define
define|#
directive|define
name|DMF_PE
value|0010000
end_define

begin_comment
comment|/* parity error */
end_comment

begin_define
define|#
directive|define
name|DMF_FE
value|0020000
end_define

begin_comment
comment|/* framing error */
end_comment

begin_define
define|#
directive|define
name|DMF_DO
value|0040000
end_define

begin_comment
comment|/* data overrun */
end_comment

begin_comment
comment|/* bits in dmfrms */
end_comment

begin_define
define|#
directive|define
name|DMF_USRR
value|0004
end_define

begin_comment
comment|/* user modem signal (pin 25) */
end_comment

begin_define
define|#
directive|define
name|DMF_SR
value|0010
end_define

begin_comment
comment|/* secondary receive */
end_comment

begin_define
define|#
directive|define
name|DMF_CTS
value|0020
end_define

begin_comment
comment|/* clear to send */
end_comment

begin_define
define|#
directive|define
name|DMF_CAR
value|0040
end_define

begin_comment
comment|/* carrier detect */
end_comment

begin_define
define|#
directive|define
name|DMF_RNG
value|0100
end_define

begin_comment
comment|/* ring */
end_comment

begin_define
define|#
directive|define
name|DMF_DSR
value|0200
end_define

begin_comment
comment|/* data set ready */
end_comment

begin_comment
comment|/* bits in dmftms */
end_comment

begin_define
define|#
directive|define
name|DMF_USRW
value|0001
end_define

begin_comment
comment|/* user modem signal (pin 18) */
end_comment

begin_define
define|#
directive|define
name|DMF_DTR
value|0002
end_define

begin_comment
comment|/* data terminal ready */
end_comment

begin_define
define|#
directive|define
name|DMF_RATE
value|0004
end_define

begin_comment
comment|/* data signal rate select */
end_comment

begin_define
define|#
directive|define
name|DMF_ST
value|0010
end_define

begin_comment
comment|/* secondary transmit */
end_comment

begin_define
define|#
directive|define
name|DMF_RTS
value|0020
end_define

begin_comment
comment|/* request to send */
end_comment

begin_define
define|#
directive|define
name|DMF_BRK
value|0040
end_define

begin_comment
comment|/* pseudo break bit */
end_comment

begin_define
define|#
directive|define
name|DMF_PREEMPT
value|0200
end_define

begin_comment
comment|/* preempt output */
end_comment

begin_comment
comment|/* flags for modem control */
end_comment

begin_define
define|#
directive|define
name|DMF_ON
value|(DMF_DTR|DMF_RTS)
end_define

begin_define
define|#
directive|define
name|DMF_OFF
value|0
end_define

begin_comment
comment|/* bits in dmflcr */
end_comment

begin_define
define|#
directive|define
name|DMF_MIE
value|0040
end_define

begin_comment
comment|/* modem interrupt enable */
end_comment

begin_define
define|#
directive|define
name|DMF_FLUSH
value|0020
end_define

begin_comment
comment|/* flush transmit silo */
end_comment

begin_define
define|#
directive|define
name|DMF_RBRK
value|0010
end_define

begin_comment
comment|/* real break bit */
end_comment

begin_define
define|#
directive|define
name|DMF_RE
value|0004
end_define

begin_comment
comment|/* receive enable */
end_comment

begin_define
define|#
directive|define
name|DMF_AUTOX
value|0002
end_define

begin_comment
comment|/* auto XON/XOFF */
end_comment

begin_define
define|#
directive|define
name|DMF_TE
value|0001
end_define

begin_comment
comment|/* transmit enable */
end_comment

begin_define
define|#
directive|define
name|DMFLCR_ENA
value|(DMF_MIE|DMF_RE|DMF_TE)
end_define

begin_comment
comment|/* bits in dm lsr, copied from dh.c */
end_comment

begin_define
define|#
directive|define
name|DML_USR
value|0001000
end_define

begin_comment
comment|/* usr modem sig, not a real DM bit */
end_comment

begin_define
define|#
directive|define
name|DML_DSR
value|0000400
end_define

begin_comment
comment|/* data set ready, not a real DM bit */
end_comment

begin_define
define|#
directive|define
name|DML_RNG
value|0000200
end_define

begin_comment
comment|/* ring */
end_comment

begin_define
define|#
directive|define
name|DML_CAR
value|0000100
end_define

begin_comment
comment|/* carrier detect */
end_comment

begin_define
define|#
directive|define
name|DML_CTS
value|0000040
end_define

begin_comment
comment|/* clear to send */
end_comment

begin_define
define|#
directive|define
name|DML_SR
value|0000020
end_define

begin_comment
comment|/* secondary receive */
end_comment

begin_define
define|#
directive|define
name|DML_ST
value|0000010
end_define

begin_comment
comment|/* secondary transmit */
end_comment

begin_define
define|#
directive|define
name|DML_RTS
value|0000004
end_define

begin_comment
comment|/* request to send */
end_comment

begin_define
define|#
directive|define
name|DML_DTR
value|0000002
end_define

begin_comment
comment|/* data terminal ready */
end_comment

begin_define
define|#
directive|define
name|DML_LE
value|0000001
end_define

begin_comment
comment|/* line enable */
end_comment

begin_define
define|#
directive|define
name|SETLCR
parameter_list|(
name|pt
parameter_list|,
name|exp
parameter_list|)
define|\
value|pt->dmfun.dmfirw = (((pt)->dmftms)<<8) | ((exp)&0xff)
end_define

end_unit

