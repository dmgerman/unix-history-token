begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)ikreg.h	7.1 (Berkeley) 5/21/88  */
end_comment

begin_comment
comment|/*  * IKON DR-11W register definitions.  */
end_comment

begin_struct
struct|struct
name|ikdevice
block|{
name|u_short
name|ik_csr
decl_stmt|;
comment|/* control status register */
name|u_short
name|ik_data
decl_stmt|;
comment|/* data in/out register */
name|u_char
name|ik_mod
decl_stmt|;
comment|/* address modifier */
name|u_char
name|ik_vec
decl_stmt|;
comment|/* interrupt vector */
name|u_short
name|ik_pulse
decl_stmt|;
comment|/* pulse commands (w) */
name|u_short
name|ik_fill
index|[
literal|5
index|]
decl_stmt|;
name|u_short
name|ik_balo
decl_stmt|;
comment|/* low word of dma beginning address (w) */
name|u_short
name|ik_wc
decl_stmt|;
comment|/* dma word count */
name|u_short
name|ik_calo
decl_stmt|;
comment|/* low word of dma current address (r) */
name|u_short
name|ik_fill1
decl_stmt|;
name|u_short
name|ik_bahi
decl_stmt|;
comment|/* high word of dma beginning address (w) */
name|u_short
name|ik_fill2
decl_stmt|;
name|u_short
name|ik_cahi
decl_stmt|;
comment|/* high word of dma current address (r) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * CSR control definitions (write-only).  */
end_comment

begin_define
define|#
directive|define
name|IKCSR_GO
value|0x0001
end_define

begin_comment
comment|/* start dma */
end_comment

begin_define
define|#
directive|define
name|IKCSR_FNC1
value|0x0002
end_define

begin_comment
comment|/* function bit 1 */
end_comment

begin_define
define|#
directive|define
name|IKCSR_FNC2
value|0x0004
end_define

begin_comment
comment|/* function bit 2 */
end_comment

begin_define
define|#
directive|define
name|IKCSR_FNC3
value|0x0008
end_define

begin_comment
comment|/* function bit 3 */
end_comment

begin_comment
comment|/* bits 4-5 are unused */
end_comment

begin_define
define|#
directive|define
name|IKCSR_IENA
value|0x0040
end_define

begin_comment
comment|/* enable/disable interrupts */
end_comment

begin_comment
comment|/* bit 7 is unused */
end_comment

begin_define
define|#
directive|define
name|IKCSR_CYCLE
value|0x0100
end_define

begin_comment
comment|/* force dma to cycle */
end_comment

begin_comment
comment|/* bits 9-11 are unused */
end_comment

begin_define
define|#
directive|define
name|IKCSR_MCLR
value|0x1000
end_define

begin_comment
comment|/* master clear board */
end_comment

begin_define
define|#
directive|define
name|IKCSR_RPERR
value|0x2000
end_define

begin_comment
comment|/* reset parity error */
end_comment

begin_define
define|#
directive|define
name|IKCSR_RATTF
value|0x4000
end_define

begin_comment
comment|/* reset attention */
end_comment

begin_define
define|#
directive|define
name|IKCSR_RDMAF
value|0x8000
end_define

begin_comment
comment|/* reset dma completion */
end_comment

begin_comment
comment|/*  * CSR status definitions (read-only).  */
end_comment

begin_define
define|#
directive|define
name|IKCSR_DEV
value|0x0001
end_define

begin_comment
comment|/* device flag (0 = 10083, 1 = 10077) */
end_comment

begin_comment
comment|/* bits 1-3 reflect the function latch state */
end_comment

begin_define
define|#
directive|define
name|IKCSR_TIMO
value|0x0010
end_define

begin_comment
comment|/* bus timeout during dma */
end_comment

begin_define
define|#
directive|define
name|IKCSR_BERR
value|0x0020
end_define

begin_comment
comment|/* bus error during dma */
end_comment

begin_comment
comment|/* bit 6 reflects interrupt enable state */
end_comment

begin_define
define|#
directive|define
name|IKCSR_READY
value|0x0080
end_define

begin_comment
comment|/* device ready for next command */
end_comment

begin_comment
comment|/* bit 8 should be 0 */
end_comment

begin_define
define|#
directive|define
name|IKCSR_STATC
value|0x0200
end_define

begin_comment
comment|/* status bit C */
end_comment

begin_define
define|#
directive|define
name|IKCSR_STATB
value|0x0400
end_define

begin_comment
comment|/* status bit B */
end_comment

begin_define
define|#
directive|define
name|IKCSR_STATA
value|0x0800
end_define

begin_comment
comment|/* status bit A */
end_comment

begin_define
define|#
directive|define
name|IKCSR_PERR
value|0x1000
end_define

begin_comment
comment|/* parity error during pi/o or dma */
end_comment

begin_define
define|#
directive|define
name|IKCSR_ATTN
value|0x2000
end_define

begin_comment
comment|/* current state of attention bit */
end_comment

begin_define
define|#
directive|define
name|IKCSR_ATTF
value|0x4000
end_define

begin_comment
comment|/* latched attention t-f transition */
end_comment

begin_define
define|#
directive|define
name|IKCSR_DMAF
value|0x8000
end_define

begin_comment
comment|/* dma completed or terminated */
end_comment

begin_define
define|#
directive|define
name|IKCSR_BITS
define|\
value|"\020\1DEV\2FNC1\3FNC2\4FNC3\5TIMO\6BERR\7IENA\10READY\12STATC\13STATB\14STATA\ \15PERR\16ATTN\17ATTF\20DMAF"
end_define

begin_comment
comment|/*  * Pulse command register definitions (write-only).  */
end_comment

begin_define
define|#
directive|define
name|IKPULSE_GO
value|0x0001
end_define

begin_comment
comment|/* enable dma */
end_comment

begin_define
define|#
directive|define
name|IKPULSE_FNC2
value|0x0004
end_define

begin_comment
comment|/* pulse function bit 1 */
end_comment

begin_define
define|#
directive|define
name|IKPULSE_RIENA
value|0x0020
end_define

begin_comment
comment|/* reset IKCSR_IENA */
end_comment

begin_define
define|#
directive|define
name|IKPULSE_SIENA
value|0x0040
end_define

begin_comment
comment|/* set IKCSR_IENA */
end_comment

begin_define
define|#
directive|define
name|IKPULSE_CYCL
value|0x0100
end_define

begin_comment
comment|/* force dma to cycle */
end_comment

begin_define
define|#
directive|define
name|IKPULSE_MCLR
value|0x1000
end_define

begin_comment
comment|/* initialize interface */
end_comment

begin_define
define|#
directive|define
name|IKPULSE_RPERR
value|0x2000
end_define

begin_comment
comment|/* reset IKCSR_PERR */
end_comment

begin_define
define|#
directive|define
name|IKPULSE_RATTF
value|0x4000
end_define

begin_comment
comment|/* reset IKCSR_ATTF */
end_comment

begin_define
define|#
directive|define
name|IKPULSE_RDMAF
value|0x8000
end_define

begin_comment
comment|/* reset IKCSR_DMAF */
end_comment

end_unit

