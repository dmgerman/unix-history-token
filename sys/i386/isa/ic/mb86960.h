begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * All Rights Reserved, Copyright (C) Fujitsu Limited 1995  *  * This software may be used, modified, copied, distributed, and sold, in  * both source and binary form provided that the above copyright, these  * terms and the following disclaimer are retained.  The name of the author  * and/or the contributor may not be used to endorse or promote products  * derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND THE CONTRIBUTOR ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR THE CONTRIBUTOR BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Registers of Fujitsu MB86960A/MB86965A series Ethernet controllers.  * Written and contributed by M.S.<seki@sysrap.cs.fujitsu.co.jp>  */
end_comment

begin_comment
comment|/*  * Notes on register naming:  *  * Fujitsu documents for MB86960A/MB86965A uses no mnemorable names  * for their registers.  They defined only three names for 32  * registers and appended numbers to distinguish registers of  * same name.  Surprisingly, the numbers represent I/O address  * offsets of the registers from the base addresses, and their  * names correspond to the "bank" the registers are allocated.  * All this means that, for example, to say "read DLCR8" has no more  * than to say "read a register at offset 8 on bank DLCR."  *  * The following definitions may look silly, but that's what Fujitsu  * did, and it is necessary to know these names to read Fujitsu  * documents..  */
end_comment

begin_comment
comment|/* Data Link Control Registrs, on invaliant port addresses.  */
end_comment

begin_define
define|#
directive|define
name|FE_DLCR0
value|0
end_define

begin_define
define|#
directive|define
name|FE_DLCR1
value|1
end_define

begin_define
define|#
directive|define
name|FE_DLCR2
value|2
end_define

begin_define
define|#
directive|define
name|FE_DLCR3
value|3
end_define

begin_define
define|#
directive|define
name|FE_DLCR4
value|4
end_define

begin_define
define|#
directive|define
name|FE_DLCR5
value|5
end_define

begin_define
define|#
directive|define
name|FE_DLCR6
value|6
end_define

begin_define
define|#
directive|define
name|FE_DLCR7
value|7
end_define

begin_comment
comment|/* More DLCRs, on register bank #0.  */
end_comment

begin_define
define|#
directive|define
name|FE_DLCR8
value|8
end_define

begin_define
define|#
directive|define
name|FE_DLCR9
value|9
end_define

begin_define
define|#
directive|define
name|FE_DLCR10
value|10
end_define

begin_define
define|#
directive|define
name|FE_DLCR11
value|11
end_define

begin_define
define|#
directive|define
name|FE_DLCR12
value|12
end_define

begin_define
define|#
directive|define
name|FE_DLCR13
value|13
end_define

begin_define
define|#
directive|define
name|FE_DLCR14
value|14
end_define

begin_define
define|#
directive|define
name|FE_DLCR15
value|15
end_define

begin_comment
comment|/* Malticast Address Registers.  On register bank #1.  */
end_comment

begin_define
define|#
directive|define
name|FE_MAR8
value|8
end_define

begin_define
define|#
directive|define
name|FE_MAR9
value|9
end_define

begin_define
define|#
directive|define
name|FE_MAR10
value|10
end_define

begin_define
define|#
directive|define
name|FE_MAR11
value|11
end_define

begin_define
define|#
directive|define
name|FE_MAR12
value|12
end_define

begin_define
define|#
directive|define
name|FE_MAR13
value|13
end_define

begin_define
define|#
directive|define
name|FE_MAR14
value|14
end_define

begin_define
define|#
directive|define
name|FE_MAR15
value|15
end_define

begin_comment
comment|/* Buffer Memory Port Registers.  On register back #2.  */
end_comment

begin_define
define|#
directive|define
name|FE_BMPR8
value|8
end_define

begin_define
define|#
directive|define
name|FE_BMPR9
value|9
end_define

begin_define
define|#
directive|define
name|FE_BMPR10
value|10
end_define

begin_define
define|#
directive|define
name|FE_BMPR11
value|11
end_define

begin_define
define|#
directive|define
name|FE_BMPR12
value|12
end_define

begin_define
define|#
directive|define
name|FE_BMPR13
value|13
end_define

begin_define
define|#
directive|define
name|FE_BMPR14
value|14
end_define

begin_define
define|#
directive|define
name|FE_BMPR15
value|15
end_define

begin_comment
comment|/* More BMPRs, only on 86965, accessible only when JLI mode.  */
end_comment

begin_define
define|#
directive|define
name|FE_BMPR16
value|16
end_define

begin_define
define|#
directive|define
name|FE_BMPR17
value|17
end_define

begin_define
define|#
directive|define
name|FE_BMPR18
value|18
end_define

begin_define
define|#
directive|define
name|FE_BMPR19
value|19
end_define

begin_comment
comment|/*  * Definitions of registers.  * I don't have Fujitsu documents of MB86960A/MB86965A, so I don't  * know the official names for each flags and fields.  The following  * names are assigned by me (the author of this file,) since I cannot  * mnemorize hexadecimal constants for all of these functions.  * Comments?  *  * I've got documents from Fujitsu web site, recently.  However, it's  * too late.  Names for some fields (bits) are kept different from  * those used in the Fujitsu documents...  */
end_comment

begin_comment
comment|/* DLCR0 -- transmitter status */
end_comment

begin_define
define|#
directive|define
name|FE_D0_BUSERR
value|0x01
end_define

begin_comment
comment|/* Bus write error?			*/
end_comment

begin_define
define|#
directive|define
name|FE_D0_COLL16
value|0x02
end_define

begin_comment
comment|/* Collision limit (16) encountered	*/
end_comment

begin_define
define|#
directive|define
name|FE_D0_COLLID
value|0x04
end_define

begin_comment
comment|/* Collision on last transmission	*/
end_comment

begin_define
define|#
directive|define
name|FE_D0_JABBER
value|0x08
end_define

begin_comment
comment|/* Jabber				*/
end_comment

begin_define
define|#
directive|define
name|FE_D0_CRLOST
value|0x10
end_define

begin_comment
comment|/* Carrier lost on last transmission	*/
end_comment

begin_define
define|#
directive|define
name|FE_D0_PKTRCD
value|0x20
end_define

begin_comment
comment|/* Last packet looped back correctly	*/
end_comment

begin_define
define|#
directive|define
name|FE_D0_NETBSY
value|0x40
end_define

begin_comment
comment|/* Network Busy (Carrier Detected)	*/
end_comment

begin_define
define|#
directive|define
name|FE_D0_TXDONE
value|0x80
end_define

begin_comment
comment|/* Transmission complete		*/
end_comment

begin_comment
comment|/* DLCR1 -- receiver status */
end_comment

begin_define
define|#
directive|define
name|FE_D1_OVRFLO
value|0x01
end_define

begin_comment
comment|/* Receiver buffer overflow		*/
end_comment

begin_define
define|#
directive|define
name|FE_D1_CRCERR
value|0x02
end_define

begin_comment
comment|/* CRC error on last packet		*/
end_comment

begin_define
define|#
directive|define
name|FE_D1_ALGERR
value|0x04
end_define

begin_comment
comment|/* Alignment error on last packet	*/
end_comment

begin_define
define|#
directive|define
name|FE_D1_SRTPKT
value|0x08
end_define

begin_comment
comment|/* Short (RUNT) packet is received	*/
end_comment

begin_define
define|#
directive|define
name|FE_D1_RMTRST
value|0x10
end_define

begin_comment
comment|/* Remote reset packet (type = 0x0900)	*/
end_comment

begin_define
define|#
directive|define
name|FE_D1_DMAEOP
value|0x20
end_define

begin_comment
comment|/* Host asserted End of DMA OPeration	*/
end_comment

begin_define
define|#
directive|define
name|FE_D1_BUSERR
value|0x40
end_define

begin_comment
comment|/* Bus read error			*/
end_comment

begin_define
define|#
directive|define
name|FE_D1_PKTRDY
value|0x80
end_define

begin_comment
comment|/* Packet(s) ready on receive buffer	*/
end_comment

begin_comment
comment|/* DLCR2 -- transmitter interrupt control; same layout as DLCR0 */
end_comment

begin_define
define|#
directive|define
name|FE_D2_BUSERR
value|FE_D0_BUSERR
end_define

begin_define
define|#
directive|define
name|FE_D2_COLL16
value|FE_D0_COLL16
end_define

begin_define
define|#
directive|define
name|FE_D2_COLLID
value|FE_D0_COLLID
end_define

begin_define
define|#
directive|define
name|FE_D2_JABBER
value|FE_D0_JABBER
end_define

begin_define
define|#
directive|define
name|FE_D2_TXDONE
value|FE_D0_TXDONE
end_define

begin_define
define|#
directive|define
name|FE_D2_RESERVED
value|0x70
end_define

begin_comment
comment|/* DLCR3 -- receiver interrupt control; same layout as DLCR1 */
end_comment

begin_define
define|#
directive|define
name|FE_D3_OVRFLO
value|FE_D1_OVRFLO
end_define

begin_define
define|#
directive|define
name|FE_D3_CRCERR
value|FE_D1_CRCERR
end_define

begin_define
define|#
directive|define
name|FE_D3_ALGERR
value|FE_D1_ALGERR
end_define

begin_define
define|#
directive|define
name|FE_D3_SRTPKT
value|FE_D1_SRTPKT
end_define

begin_define
define|#
directive|define
name|FE_D3_RMTRST
value|FE_D1_RMTRST
end_define

begin_define
define|#
directive|define
name|FE_D3_DMAEOP
value|FE_D1_DMAEOP
end_define

begin_define
define|#
directive|define
name|FE_D3_BUSERR
value|FE_D1_BUSERR
end_define

begin_define
define|#
directive|define
name|FE_D3_PKTRDY
value|FE_D1_PKTRDY
end_define

begin_comment
comment|/* DLCR4 -- transmitter operation mode */
end_comment

begin_define
define|#
directive|define
name|FE_D4_DSC
value|0x01
end_define

begin_comment
comment|/* Disable carrier sense on trans.	*/
end_comment

begin_define
define|#
directive|define
name|FE_D4_LBC
value|0x02
end_define

begin_comment
comment|/* Loop back test control		*/
end_comment

begin_define
define|#
directive|define
name|FE_D4_CNTRL
value|0x04
end_define

begin_comment
comment|/* - tied to CNTRL pin of the chip	*/
end_comment

begin_define
define|#
directive|define
name|FE_D4_TEST1
value|0x08
end_define

begin_comment
comment|/* Test output #1			*/
end_comment

begin_define
define|#
directive|define
name|FE_D4_COL
value|0xF0
end_define

begin_comment
comment|/* Collision counter			*/
end_comment

begin_define
define|#
directive|define
name|FE_D4_LBC_ENABLE
value|0x00
end_define

begin_comment
comment|/* Perform loop back test	*/
end_comment

begin_define
define|#
directive|define
name|FE_D4_LBC_DISABLE
value|0x02
end_define

begin_comment
comment|/* Normal operation		*/
end_comment

begin_define
define|#
directive|define
name|FE_D4_COL_SHIFT
value|4
end_define

begin_comment
comment|/* DLCR5 -- receiver operation mode */
end_comment

begin_define
define|#
directive|define
name|FE_D5_AFM0
value|0x01
end_define

begin_comment
comment|/* Receive packets for other stations	*/
end_comment

begin_define
define|#
directive|define
name|FE_D5_AFM1
value|0x02
end_define

begin_comment
comment|/* Receive packets for this station	*/
end_comment

begin_define
define|#
directive|define
name|FE_D5_RMTRST
value|0x04
end_define

begin_comment
comment|/* Enable remote reset operation	*/
end_comment

begin_define
define|#
directive|define
name|FE_D5_SRTPKT
value|0x08
end_define

begin_comment
comment|/* Accept short (RUNT) packets		*/
end_comment

begin_define
define|#
directive|define
name|FE_D5_SRTADR
value|0x10
end_define

begin_comment
comment|/* Short (16 bits?) MAC address		*/
end_comment

begin_define
define|#
directive|define
name|FE_D5_BADPKT
value|0x20
end_define

begin_comment
comment|/* Accept packets with error		*/
end_comment

begin_define
define|#
directive|define
name|FE_D5_BUFEMP
value|0x40
end_define

begin_comment
comment|/* Receive buffer is empty		*/
end_comment

begin_define
define|#
directive|define
name|FE_D5_TEST2
value|0x80
end_define

begin_comment
comment|/* Test output #2			*/
end_comment

begin_comment
comment|/* DLCR6 -- hardware configuration #0 */
end_comment

begin_define
define|#
directive|define
name|FE_D6_BUFSIZ
value|0x03
end_define

begin_comment
comment|/* Size of NIC buffer SRAM		*/
end_comment

begin_define
define|#
directive|define
name|FE_D6_TXBSIZ
value|0x0C
end_define

begin_comment
comment|/* Size (and config)of trans. buffer	*/
end_comment

begin_define
define|#
directive|define
name|FE_D6_BBW
value|0x10
end_define

begin_comment
comment|/* Buffer SRAM bus width		*/
end_comment

begin_define
define|#
directive|define
name|FE_D6_SBW
value|0x20
end_define

begin_comment
comment|/* System bus width			*/
end_comment

begin_define
define|#
directive|define
name|FE_D6_SRAM
value|0x40
end_define

begin_comment
comment|/* Buffer SRAM access time		*/
end_comment

begin_define
define|#
directive|define
name|FE_D6_DLC
value|0x80
end_define

begin_comment
comment|/* Disable DLC (recever/transmitter)	*/
end_comment

begin_define
define|#
directive|define
name|FE_D6_BUFSIZ_8KB
value|0x00
end_define

begin_comment
comment|/* The board has  8KB SRAM	*/
end_comment

begin_define
define|#
directive|define
name|FE_D6_BUFSIZ_16KB
value|0x01
end_define

begin_comment
comment|/* The board has 16KB SRAM	*/
end_comment

begin_define
define|#
directive|define
name|FE_D6_BUFSIZ_32KB
value|0x02
end_define

begin_comment
comment|/* The board has 32KB SRAM	*/
end_comment

begin_define
define|#
directive|define
name|FE_D6_BUFSIZ_64KB
value|0x03
end_define

begin_comment
comment|/* The board has 64KB SRAM	*/
end_comment

begin_define
define|#
directive|define
name|FE_D6_TXBSIZ_1x2KB
value|0x00
end_define

begin_comment
comment|/* Single 2KB buffer for trans.	*/
end_comment

begin_define
define|#
directive|define
name|FE_D6_TXBSIZ_2x2KB
value|0x04
end_define

begin_comment
comment|/* Double 2KB buffers		*/
end_comment

begin_define
define|#
directive|define
name|FE_D6_TXBSIZ_2x4KB
value|0x08
end_define

begin_comment
comment|/* Double 4KB buffers		*/
end_comment

begin_define
define|#
directive|define
name|FE_D6_TXBSIZ_2x8KB
value|0x0C
end_define

begin_comment
comment|/* Double 8KB buffers		*/
end_comment

begin_define
define|#
directive|define
name|FE_D6_BBW_WORD
value|0x00
end_define

begin_comment
comment|/* SRAM has 16 bit data line	*/
end_comment

begin_define
define|#
directive|define
name|FE_D6_BBW_BYTE
value|0x10
end_define

begin_comment
comment|/* SRAM has  8 bit data line	*/
end_comment

begin_define
define|#
directive|define
name|FE_D6_SBW_WORD
value|0x00
end_define

begin_comment
comment|/* Access with 16 bit (AT) bus	*/
end_comment

begin_define
define|#
directive|define
name|FE_D6_SBW_BYTE
value|0x20
end_define

begin_comment
comment|/* Access with  8 bit (XT) bus	*/
end_comment

begin_define
define|#
directive|define
name|FE_D6_SRAM_150ns
value|0x00
end_define

begin_comment
comment|/* The board has slow SRAM	*/
end_comment

begin_define
define|#
directive|define
name|FE_D6_SRAM_100ns
value|0x40
end_define

begin_comment
comment|/* The board has fast SRAM	*/
end_comment

begin_define
define|#
directive|define
name|FE_D6_DLC_ENABLE
value|0x00
end_define

begin_comment
comment|/* Normal operation		*/
end_comment

begin_define
define|#
directive|define
name|FE_D6_DLC_DISABLE
value|0x80
end_define

begin_comment
comment|/* Stop sending/receiving	*/
end_comment

begin_comment
comment|/* DLC7 -- hardware configuration #1 */
end_comment

begin_define
define|#
directive|define
name|FE_D7_BYTSWP
value|0x01
end_define

begin_comment
comment|/* Host byte order control		*/
end_comment

begin_define
define|#
directive|define
name|FE_D7_EOPPOL
value|0x02
end_define

begin_comment
comment|/* Polarity of DMA EOP signal		*/
end_comment

begin_define
define|#
directive|define
name|FE_D7_RBS
value|0x0C
end_define

begin_comment
comment|/* Register bank select			*/
end_comment

begin_define
define|#
directive|define
name|FE_D7_RDYPNS
value|0x10
end_define

begin_comment
comment|/* Senses RDYPNSEL input signal		*/
end_comment

begin_define
define|#
directive|define
name|FE_D7_POWER
value|0x20
end_define

begin_comment
comment|/* Stand-by (power down) mode control	*/
end_comment

begin_define
define|#
directive|define
name|FE_D7_IDENT
value|0xC0
end_define

begin_comment
comment|/* Chip identification			*/
end_comment

begin_define
define|#
directive|define
name|FE_D7_BYTSWP_LH
value|0x00
end_define

begin_comment
comment|/* DEC/Intel byte order		*/
end_comment

begin_define
define|#
directive|define
name|FE_D7_BYTSWP_HL
value|0x01
end_define

begin_comment
comment|/* IBM/Motorolla byte order	*/
end_comment

begin_define
define|#
directive|define
name|FE_D7_RBS_DLCR
value|0x00
end_define

begin_comment
comment|/* Select DLCR8-15		*/
end_comment

begin_define
define|#
directive|define
name|FE_D7_RBS_MAR
value|0x04
end_define

begin_comment
comment|/* Select MAR8-15		*/
end_comment

begin_define
define|#
directive|define
name|FE_D7_RBS_BMPR
value|0x08
end_define

begin_comment
comment|/* Select BMPR8-15		*/
end_comment

begin_define
define|#
directive|define
name|FE_D7_POWER_DOWN
value|0x00
end_define

begin_comment
comment|/* Power down (stand-by) mode	*/
end_comment

begin_define
define|#
directive|define
name|FE_D7_POWER_UP
value|0x20
end_define

begin_comment
comment|/* Normal operation		*/
end_comment

begin_define
define|#
directive|define
name|FE_D7_IDENT_TDK
value|0x00
end_define

begin_comment
comment|/* TDK chips?			*/
end_comment

begin_define
define|#
directive|define
name|FE_D7_IDENT_NICE
value|0x80
end_define

begin_comment
comment|/* Fujitsu NICE (86960)		*/
end_comment

begin_define
define|#
directive|define
name|FE_D7_IDENT_EC
value|0xC0
end_define

begin_comment
comment|/* Fujitsu EtherCoupler (86965)	*/
end_comment

begin_comment
comment|/* DLCR8 thru DLCR13 are for Ethernet station address.  */
end_comment

begin_comment
comment|/* DLCR14 and DLCR15 are for TDR.  (TDR is used for cable diagnostic.)  */
end_comment

begin_comment
comment|/* MAR8 thru MAR15 are for Multicast address filter.  */
end_comment

begin_comment
comment|/* BMPR8 and BMPR9 are for packet data.  */
end_comment

begin_comment
comment|/* BMPR10 -- transmitter start trigger */
end_comment

begin_define
define|#
directive|define
name|FE_B10_START
value|0x80
end_define

begin_comment
comment|/* Start transmitter			*/
end_comment

begin_define
define|#
directive|define
name|FE_B10_COUNT
value|0x7F
end_define

begin_comment
comment|/* Packet count				*/
end_comment

begin_comment
comment|/* BMPR11 -- 16 collisions control */
end_comment

begin_define
define|#
directive|define
name|FE_B11_CTRL
value|0x01
end_define

begin_comment
comment|/* Skip or resend errored packets	*/
end_comment

begin_define
define|#
directive|define
name|FE_B11_MODE1
value|0x02
end_define

begin_comment
comment|/* Restart transmitter after COLL16	*/
end_comment

begin_define
define|#
directive|define
name|FE_B11_MODE2
value|0x04
end_define

begin_comment
comment|/* Automatic restart enable		*/
end_comment

begin_define
define|#
directive|define
name|FE_B11_CTRL_RESEND
value|0x00
end_define

begin_comment
comment|/* Re-send the collided packet	*/
end_comment

begin_define
define|#
directive|define
name|FE_B11_CTRL_SKIP
value|0x01
end_define

begin_comment
comment|/* Skip the collided packet	*/
end_comment

begin_comment
comment|/* BMPR12 -- DMA enable */
end_comment

begin_define
define|#
directive|define
name|FE_B12_TXDMA
value|0x01
end_define

begin_comment
comment|/* Enable transmitter DMA		*/
end_comment

begin_define
define|#
directive|define
name|FE_B12_RXDMA
value|0x02
end_define

begin_comment
comment|/* Enable receiver DMA			*/
end_comment

begin_comment
comment|/* BMPR13 -- DMA control */
end_comment

begin_define
define|#
directive|define
name|FE_B13_BSTCTL
value|0x03
end_define

begin_comment
comment|/* DMA burst mode control		*/
end_comment

begin_define
define|#
directive|define
name|FE_B13_TPTYPE
value|0x04
end_define

begin_comment
comment|/* Twisted pair cable impedance		*/
end_comment

begin_define
define|#
directive|define
name|FE_B13_PORT
value|0x18
end_define

begin_comment
comment|/* Port (TP/AUI) selection		*/
end_comment

begin_define
define|#
directive|define
name|FE_B13_LNKTST
value|0x20
end_define

begin_comment
comment|/* Link test enable			*/
end_comment

begin_define
define|#
directive|define
name|FE_B13_SQTHLD
value|0x40
end_define

begin_comment
comment|/* Lower squelch threshold		*/
end_comment

begin_define
define|#
directive|define
name|FE_B13_IOUNLK
value|0x80
end_define

begin_comment
comment|/* Change I/O base address, on JLI mode	*/
end_comment

begin_define
define|#
directive|define
name|FE_B13_BSTCTL_1
value|0x00
end_define

begin_define
define|#
directive|define
name|FE_B13_BSTCTL_4
value|0x01
end_define

begin_define
define|#
directive|define
name|FE_B13_BSTCTL_8
value|0x02
end_define

begin_define
define|#
directive|define
name|FE_B13_BSTCLT_12
value|0x03
end_define

begin_define
define|#
directive|define
name|FE_B13_TPTYPE_UTP
value|0x00
end_define

begin_comment
comment|/* Unshielded (standard) cable	*/
end_comment

begin_define
define|#
directive|define
name|FE_B13_TPTYPE_STP
value|0x04
end_define

begin_comment
comment|/* Shielded (IBM) cable		*/
end_comment

begin_define
define|#
directive|define
name|FE_B13_PORT_AUTO
value|0x00
end_define

begin_comment
comment|/* Auto detected		*/
end_comment

begin_define
define|#
directive|define
name|FE_B13_PORT_TP
value|0x08
end_define

begin_comment
comment|/* Force TP			*/
end_comment

begin_define
define|#
directive|define
name|FE_B13_PORT_AUI
value|0x18
end_define

begin_comment
comment|/* Force AUI			*/
end_comment

begin_comment
comment|/* BMPR14 -- More receiver control and more transmission interrupts */
end_comment

begin_define
define|#
directive|define
name|FE_B14_FILTER
value|0x01
end_define

begin_comment
comment|/* Filter out self-originated packets	*/
end_comment

begin_define
define|#
directive|define
name|FE_B14_SQE
value|0x02
end_define

begin_comment
comment|/* SQE interrupt enable			*/
end_comment

begin_define
define|#
directive|define
name|FE_B14_SKIP
value|0x04
end_define

begin_comment
comment|/* Skip a received packet		*/
end_comment

begin_define
define|#
directive|define
name|FE_B14_RJAB
value|0x20
end_define

begin_comment
comment|/* RJAB interrupt enable		*/
end_comment

begin_define
define|#
directive|define
name|FE_B14_LLD
value|0x40
end_define

begin_comment
comment|/* Local-link-down interrupt enable	*/
end_comment

begin_define
define|#
directive|define
name|FE_B14_RLD
value|0x80
end_define

begin_comment
comment|/* Remote-link-down interrupt enable	*/
end_comment

begin_comment
comment|/* BMPR15 -- More transmitter status; basically same layout as BMPR14 */
end_comment

begin_define
define|#
directive|define
name|FE_B15_SQE
value|FE_B14_SQE
end_define

begin_define
define|#
directive|define
name|FE_B15_RCVPOL
value|0x08
end_define

begin_comment
comment|/* Reversed receive line polarity	*/
end_comment

begin_define
define|#
directive|define
name|FE_B15_RMTPRT
value|0x10
end_define

begin_comment
comment|/* ???					*/
end_comment

begin_define
define|#
directive|define
name|FE_B15_RAJB
value|FE_B14_RJAB
end_define

begin_define
define|#
directive|define
name|FE_B15_LLD
value|FE_B14_LLD
end_define

begin_define
define|#
directive|define
name|FE_B15_RLD
value|FE_B14_RLD
end_define

begin_comment
comment|/* BMPR16 -- EEPROM control */
end_comment

begin_define
define|#
directive|define
name|FE_B16_DOUT
value|0x04
end_define

begin_comment
comment|/* EEPROM Data in (CPU to EEPROM)	*/
end_comment

begin_define
define|#
directive|define
name|FE_B16_SELECT
value|0x20
end_define

begin_comment
comment|/* EEPROM chip select			*/
end_comment

begin_define
define|#
directive|define
name|FE_B16_CLOCK
value|0x40
end_define

begin_comment
comment|/* EEPROM shift clock			*/
end_comment

begin_define
define|#
directive|define
name|FE_B16_DIN
value|0x80
end_define

begin_comment
comment|/* EEPROM data out (EEPROM to CPU)	*/
end_comment

begin_comment
comment|/* BMPR17 -- EEPROM data */
end_comment

begin_define
define|#
directive|define
name|FE_B17_DATA
value|0x80
end_define

begin_comment
comment|/* EEPROM data bit			*/
end_comment

begin_comment
comment|/* BMPR18 -- cycle I/O address setting in JLI mode */
end_comment

begin_comment
comment|/* BMPR19 -- ISA interface configuration in JLI mode */
end_comment

begin_define
define|#
directive|define
name|FE_B19_IRQ
value|0xC0
end_define

begin_define
define|#
directive|define
name|FE_B19_IRQ_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|FE_B19_ROM
value|0x38
end_define

begin_define
define|#
directive|define
name|FE_B19_ROM_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|FE_B19_ADDR
value|0x07
end_define

begin_define
define|#
directive|define
name|FE_B19_ADDR_SHIFT
value|0
end_define

begin_comment
comment|/*  * An extra I/O port address to reset 86965.  This location is called  * "ID ROM area" by Fujitsu document.  */
end_comment

begin_comment
comment|/*  * Flags in Receive Packet Header... Basically same layout as DLCR1.  */
end_comment

begin_define
define|#
directive|define
name|FE_RPH_OVRFLO
value|FE_D1_OVRFLO
end_define

begin_define
define|#
directive|define
name|FE_RPH_CRCERR
value|FE_D1_CRCERR
end_define

begin_define
define|#
directive|define
name|FE_RPH_ALGERR
value|FE_D1_ALGERR
end_define

begin_define
define|#
directive|define
name|FE_RPH_SRTPKT
value|FE_D1_SRTPKT
end_define

begin_define
define|#
directive|define
name|FE_RPH_RMTRST
value|FE_D1_RMTRST
end_define

begin_define
define|#
directive|define
name|FE_RPH_GOOD
value|0x20
end_define

begin_comment
comment|/* Good packet follows			*/
end_comment

begin_comment
comment|/*  * EEPROM specification (of JLI mode).  */
end_comment

begin_comment
comment|/* Number of bytes in an EEPROM accessible through 86965.  */
end_comment

begin_define
define|#
directive|define
name|FE_EEPROM_SIZE
value|32
end_define

begin_comment
comment|/* Offset for JLI config; automatically copied into BMPR19 at startup.  */
end_comment

begin_define
define|#
directive|define
name|FE_EEPROM_CONF
value|0
end_define

begin_comment
comment|/*  * Some 8696x specific constants.  */
end_comment

begin_comment
comment|/* Length (in bytes) of a Multicast Address Filter.  */
end_comment

begin_define
define|#
directive|define
name|FE_FILTER_LEN
value|8
end_define

begin_comment
comment|/* How many packets we can put in the transmission buffer on NIC memory.  */
end_comment

begin_define
define|#
directive|define
name|FE_QUEUEING_MAX
value|127
end_define

begin_comment
comment|/* Length (in bytes) of a "packet length" word in transmission buffer.  */
end_comment

begin_define
define|#
directive|define
name|FE_DATA_LEN_LEN
value|2
end_define

begin_comment
comment|/* Special Multicast Address Filter value.  */
end_comment

begin_define
define|#
directive|define
name|FE_FILTER_NOTHING
value|{ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 }
end_define

begin_define
define|#
directive|define
name|FE_FILTER_ALL
value|{ 0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF }
end_define

end_unit

