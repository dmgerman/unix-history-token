begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1995 by Pavel Antonov, Moscow, Russia.  * Copyright (C) 1995 by Andrey A. Chernov, Moscow, Russia.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Cirrus Logic CD180 registers  */
end_comment

begin_comment
comment|/* Global registers */
end_comment

begin_define
define|#
directive|define
name|CD180_GIVR
value|0x40
end_define

begin_comment
comment|/* Global Interrupt Verctor Register      */
end_comment

begin_define
define|#
directive|define
name|CD180_GICR
value|0x41
end_define

begin_comment
comment|/* Global Interrupting Channel Register   */
end_comment

begin_define
define|#
directive|define
name|CD180_PILR1
value|0x61
end_define

begin_comment
comment|/* Priority Interrupt Level Register 1    */
end_comment

begin_define
define|#
directive|define
name|CD180_PILR2
value|0x62
end_define

begin_comment
comment|/* Priority Interrupt Level Register 2    */
end_comment

begin_define
define|#
directive|define
name|CD180_PILR3
value|0x63
end_define

begin_comment
comment|/* Priority Interrupt Level Register 3    */
end_comment

begin_define
define|#
directive|define
name|CD180_CAR
value|0x64
end_define

begin_comment
comment|/* Channel Access Register                */
end_comment

begin_define
define|#
directive|define
name|CD180_GFRCR
value|0x6B
end_define

begin_comment
comment|/* Global Firmware Revision Code Register */
end_comment

begin_define
define|#
directive|define
name|CD180_PPRH
value|0x70
end_define

begin_comment
comment|/* Prescaler Period Register MSB          */
end_comment

begin_define
define|#
directive|define
name|CD180_PPRL
value|0x71
end_define

begin_comment
comment|/* Prescaler Period Register LSB          */
end_comment

begin_define
define|#
directive|define
name|CD180_RDR
value|0x78
end_define

begin_comment
comment|/* Receiver Data Register                 */
end_comment

begin_define
define|#
directive|define
name|CD180_RCSR
value|0x7A
end_define

begin_comment
comment|/* Receiver Character Status Register     */
end_comment

begin_define
define|#
directive|define
name|CD180_TDR
value|0x7B
end_define

begin_comment
comment|/* Transmit Data Register                 */
end_comment

begin_define
define|#
directive|define
name|CD180_EOIR
value|0x7F
end_define

begin_comment
comment|/* End of Interrupt Register              */
end_comment

begin_comment
comment|/* Channel Registers */
end_comment

begin_define
define|#
directive|define
name|CD180_CCR
value|0x01
end_define

begin_comment
comment|/* Channel Command Register               */
end_comment

begin_define
define|#
directive|define
name|CD180_IER
value|0x02
end_define

begin_comment
comment|/* Interrupt Enable Register              */
end_comment

begin_define
define|#
directive|define
name|CD180_COR1
value|0x03
end_define

begin_comment
comment|/* Channel Option Register 1              */
end_comment

begin_define
define|#
directive|define
name|CD180_COR2
value|0x04
end_define

begin_comment
comment|/* Channel Option Register 1              */
end_comment

begin_define
define|#
directive|define
name|CD180_COR3
value|0x05
end_define

begin_comment
comment|/* Channel Option Register 1              */
end_comment

begin_define
define|#
directive|define
name|CD180_CCSR
value|0x06
end_define

begin_comment
comment|/* Channel Control STatus Register        */
end_comment

begin_define
define|#
directive|define
name|CD180_RDCR
value|0x07
end_define

begin_comment
comment|/* Receive Data Count Register            */
end_comment

begin_define
define|#
directive|define
name|CD180_SCHR1
value|0x09
end_define

begin_comment
comment|/* Special Character Register 1           */
end_comment

begin_define
define|#
directive|define
name|CD180_SCHR2
value|0x0A
end_define

begin_comment
comment|/* Special Character Register 2           */
end_comment

begin_define
define|#
directive|define
name|CD180_SCHR3
value|0x0B
end_define

begin_comment
comment|/* Special Character Register 3           */
end_comment

begin_define
define|#
directive|define
name|CD180_SCHR4
value|0x0C
end_define

begin_comment
comment|/* Special Character Register 4           */
end_comment

begin_define
define|#
directive|define
name|CD180_MCOR1
value|0x10
end_define

begin_comment
comment|/* Modem Change Option 1 Register         */
end_comment

begin_define
define|#
directive|define
name|CD180_MCOR2
value|0x11
end_define

begin_comment
comment|/* Modem Change Option 2 Register         */
end_comment

begin_define
define|#
directive|define
name|CD180_MCR
value|0x12
end_define

begin_comment
comment|/* Modem Change Register                  */
end_comment

begin_define
define|#
directive|define
name|CD180_RTPR
value|0x18
end_define

begin_comment
comment|/* Receive Timeout Period Register        */
end_comment

begin_define
define|#
directive|define
name|CD180_MSVR
value|0x28
end_define

begin_comment
comment|/* Modem Signal Value Register            */
end_comment

begin_define
define|#
directive|define
name|CD180_RBPRH
value|0x31
end_define

begin_comment
comment|/* Receive Baud Rate Period Register MSB  */
end_comment

begin_define
define|#
directive|define
name|CD180_RBPRL
value|0x32
end_define

begin_comment
comment|/* Receive Baud Rate Period Register LSB  */
end_comment

begin_define
define|#
directive|define
name|CD180_TBPRH
value|0x39
end_define

begin_comment
comment|/* Transmit Baud Rate Period Register MSB */
end_comment

begin_define
define|#
directive|define
name|CD180_TBPRL
value|0x3A
end_define

begin_comment
comment|/* Transmit Baud Rate Period Register LSB */
end_comment

begin_comment
comment|/** Register descritpions **/
end_comment

begin_comment
comment|/* Global Interrupt Vector Register */
end_comment

begin_define
define|#
directive|define
name|GIVR_IT_MSCI
value|0x01
end_define

begin_comment
comment|/* Modem Signal Change Interrupt          */
end_comment

begin_define
define|#
directive|define
name|GIVR_IT_TDI
value|0x02
end_define

begin_comment
comment|/* Transmit Data Interrupt                */
end_comment

begin_define
define|#
directive|define
name|GIVR_IT_RGDI
value|0x03
end_define

begin_comment
comment|/* Receive Good Data Interrupt            */
end_comment

begin_define
define|#
directive|define
name|GIVR_IT_REI
value|0x07
end_define

begin_comment
comment|/* Receive Exception Interrupt            */
end_comment

begin_comment
comment|/* Global Interrupt Channel Register */
end_comment

begin_define
define|#
directive|define
name|GICR_CHAN
value|0x1C
end_define

begin_comment
comment|/* Channel Number Mask                    */
end_comment

begin_define
define|#
directive|define
name|GICR_LSH
value|2
end_define

begin_comment
comment|/* Channel Number Shift                   */
end_comment

begin_comment
comment|/* Channel Address Register */
end_comment

begin_define
define|#
directive|define
name|CAR_CHAN
value|0x07
end_define

begin_comment
comment|/* Channel Number Mask                    */
end_comment

begin_define
define|#
directive|define
name|CAR_A7
value|0x08
end_define

begin_comment
comment|/* Addres bit 7 (unused)                  */
end_comment

begin_comment
comment|/* Receive Character Status Register */
end_comment

begin_define
define|#
directive|define
name|RCSR_OE
value|0x01
end_define

begin_comment
comment|/* Overrun Error                          */
end_comment

begin_define
define|#
directive|define
name|RCSR_FE
value|0x02
end_define

begin_comment
comment|/* Frame Error                            */
end_comment

begin_define
define|#
directive|define
name|RCSR_PE
value|0x04
end_define

begin_comment
comment|/* Parity Error                           */
end_comment

begin_define
define|#
directive|define
name|RCSR_Break
value|0x08
end_define

begin_comment
comment|/* Break detected                         */
end_comment

begin_define
define|#
directive|define
name|RCSR_Timeout
value|0x80
end_define

begin_comment
comment|/* Rx Timeout                             */
end_comment

begin_define
define|#
directive|define
name|RCSR_SCMASK
value|0x70
end_define

begin_comment
comment|/* Special Character Detected Mask        */
end_comment

begin_define
define|#
directive|define
name|RCSR_SC1
value|0x10
end_define

begin_comment
comment|/* Special Char 1 (or 1& 3 seq matched)  */
end_comment

begin_define
define|#
directive|define
name|RCSR_SC2
value|0x20
end_define

begin_comment
comment|/* Special Char 2 (or 2& 4 seq matched)  */
end_comment

begin_define
define|#
directive|define
name|RCSR_SC3
value|0x30
end_define

begin_comment
comment|/* Special Char 3                         */
end_comment

begin_define
define|#
directive|define
name|RCSR_SC4
value|0x40
end_define

begin_comment
comment|/* Special Char 4                         */
end_comment

begin_comment
comment|/* Channel Command Register */
end_comment

begin_define
define|#
directive|define
name|CCR_ResetChan
value|0x80
end_define

begin_comment
comment|/* Reset Channel                          */
end_comment

begin_define
define|#
directive|define
name|CCR_HWRESET
value|0x81
end_define

begin_comment
comment|/* Hardware Reset (all channels)          */
end_comment

begin_define
define|#
directive|define
name|CCR_CORCHG1
value|0x42
end_define

begin_comment
comment|/* Channel Option Register 1 Changed      */
end_comment

begin_define
define|#
directive|define
name|CCR_CORCHG2
value|0x44
end_define

begin_comment
comment|/* Channel Option Register 2 Changed      */
end_comment

begin_define
define|#
directive|define
name|CCR_CORCHG3
value|0x48
end_define

begin_comment
comment|/* Channel Option Register 3 Changed      */
end_comment

begin_define
define|#
directive|define
name|CCR_SENDSPCH1
value|0x21
end_define

begin_comment
comment|/* Send Special Character 1               */
end_comment

begin_define
define|#
directive|define
name|CCR_SENDSPCH2
value|0x22
end_define

begin_comment
comment|/* Send Special Character 2               */
end_comment

begin_define
define|#
directive|define
name|CCR_SENDSPCH3
value|0x23
end_define

begin_comment
comment|/* Send Special Character 3               */
end_comment

begin_define
define|#
directive|define
name|CCR_SENDSPCH4
value|0x24
end_define

begin_comment
comment|/* Send Special Character 4               */
end_comment

begin_define
define|#
directive|define
name|CCR_RCVRDIS
value|0x11
end_define

begin_comment
comment|/* Receiver Disable                       */
end_comment

begin_define
define|#
directive|define
name|CCR_RCVREN
value|0x12
end_define

begin_comment
comment|/* Receiver Enable                        */
end_comment

begin_define
define|#
directive|define
name|CCR_XMTRDIS
value|0x14
end_define

begin_comment
comment|/* Transmitter Disable                    */
end_comment

begin_define
define|#
directive|define
name|CCR_XMTREN
value|0x18
end_define

begin_comment
comment|/* Transmitter Enable                     */
end_comment

begin_comment
comment|/* Interrupt Enable Register */
end_comment

begin_define
define|#
directive|define
name|IER_DSR
value|0x80
end_define

begin_comment
comment|/* Enable interrupt on DSR change         */
end_comment

begin_define
define|#
directive|define
name|IER_CD
value|0x40
end_define

begin_comment
comment|/* Enable interrupt on CD change          */
end_comment

begin_define
define|#
directive|define
name|IER_CTS
value|0x20
end_define

begin_comment
comment|/* Enable interrupt on CTS change         */
end_comment

begin_define
define|#
directive|define
name|IER_RxData
value|0x10
end_define

begin_comment
comment|/* Enable interrupt on Receive Data       */
end_comment

begin_define
define|#
directive|define
name|IER_RxSC
value|0x08
end_define

begin_comment
comment|/* Enable interrupt on Receive Spec. Char */
end_comment

begin_define
define|#
directive|define
name|IER_TxRdy
value|0x04
end_define

begin_comment
comment|/* Enable interrupt on TX FIFO empty      */
end_comment

begin_define
define|#
directive|define
name|IER_TxMpty
value|0x02
end_define

begin_comment
comment|/* Enable interrupt on TX completely empty*/
end_comment

begin_define
define|#
directive|define
name|IER_RET
value|0x01
end_define

begin_comment
comment|/* Enable interrupt on RX Except. Timeout */
end_comment

begin_comment
comment|/* Channel Option Register 1 */
end_comment

begin_define
define|#
directive|define
name|COR1_ODDP
value|0x80
end_define

begin_comment
comment|/* Odd Parity                             */
end_comment

begin_define
define|#
directive|define
name|COR1_ParMMASK
value|0x60
end_define

begin_comment
comment|/* Parity Mode mask                       */
end_comment

begin_define
define|#
directive|define
name|COR1_NOPAR
value|0x02
end_define

begin_comment
comment|/* No Parity                              */
end_comment

begin_define
define|#
directive|define
name|COR1_FORCEPAR
value|0x20
end_define

begin_comment
comment|/* Force Parity                           */
end_comment

begin_define
define|#
directive|define
name|COR1_NORMPAR
value|0x40
end_define

begin_comment
comment|/* Normal Parity                          */
end_comment

begin_define
define|#
directive|define
name|COR1_Ignore
value|0x10
end_define

begin_comment
comment|/* Ignore Parity on RX                    */
end_comment

begin_define
define|#
directive|define
name|COR1_StopMASK
value|0x0C
end_define

begin_comment
comment|/* Stop Bits mode mask                    */
end_comment

begin_define
define|#
directive|define
name|COR1_1SB
value|0x00
end_define

begin_comment
comment|/* 1 Stop Bit                             */
end_comment

begin_define
define|#
directive|define
name|COR1_15SB
value|0x04
end_define

begin_comment
comment|/* 1.5 Stop Bits                          */
end_comment

begin_define
define|#
directive|define
name|COR1_2SB
value|0x08
end_define

begin_comment
comment|/* 2 Stop Bits                            */
end_comment

begin_define
define|#
directive|define
name|COR1_CHLMASK
value|0x03
end_define

begin_comment
comment|/* Character Length mask                  */
end_comment

begin_define
define|#
directive|define
name|COR1_5BITS
value|0x00
end_define

begin_comment
comment|/* 5 bits                                 */
end_comment

begin_define
define|#
directive|define
name|COR1_6BITS
value|0x01
end_define

begin_comment
comment|/* 6 bits                                 */
end_comment

begin_define
define|#
directive|define
name|COR1_7BITS
value|0x02
end_define

begin_comment
comment|/* 7 bits                                 */
end_comment

begin_define
define|#
directive|define
name|COR1_8BITS
value|0x03
end_define

begin_comment
comment|/* 8 bits                                 */
end_comment

begin_comment
comment|/* Channel Option Register 2 */
end_comment

begin_define
define|#
directive|define
name|COR2_IXM
value|0x80
end_define

begin_comment
comment|/* Implied XON mode                       */
end_comment

begin_define
define|#
directive|define
name|COR2_TxIBE
value|0x40
end_define

begin_comment
comment|/* Enable In-Band XON/XOFF Flow Control   */
end_comment

begin_define
define|#
directive|define
name|COR2_ETC
value|0x20
end_define

begin_comment
comment|/* Embedded Tx Commands Enable            */
end_comment

begin_define
define|#
directive|define
name|COR2_LLM
value|0x10
end_define

begin_comment
comment|/* Local Loopback Mode                    */
end_comment

begin_define
define|#
directive|define
name|COR2_RLM
value|0x08
end_define

begin_comment
comment|/* Remote Loopback Mode                   */
end_comment

begin_define
define|#
directive|define
name|COR2_RtsAO
value|0x04
end_define

begin_comment
comment|/* RTS Automatic Output Enable            */
end_comment

begin_define
define|#
directive|define
name|COR2_CtsAE
value|0x02
end_define

begin_comment
comment|/* CTS Automatic Enable                   */
end_comment

begin_define
define|#
directive|define
name|COR2_DsrAE
value|0x01
end_define

begin_comment
comment|/* DSR Automatic Enable                   */
end_comment

begin_comment
comment|/* Channel Option Register 3 */
end_comment

begin_define
define|#
directive|define
name|COR3_XonCH
value|0x80
end_define

begin_comment
comment|/* XON is a double seq (1& 3)            */
end_comment

begin_define
define|#
directive|define
name|COR3_XoffCH
value|0x40
end_define

begin_comment
comment|/* XOFF is a double seq (1& 3)           */
end_comment

begin_define
define|#
directive|define
name|COR3_FCT
value|0x20
end_define

begin_comment
comment|/* Flow-Control Transparency Mode         */
end_comment

begin_define
define|#
directive|define
name|COR3_SCDE
value|0x10
end_define

begin_comment
comment|/* Special Character Detection Enable     */
end_comment

begin_define
define|#
directive|define
name|COR3_RxTHMASK
value|0x0F
end_define

begin_comment
comment|/* RX FIFO Threshold value (1-8)          */
end_comment

begin_comment
comment|/* Channel Control Status Register */
end_comment

begin_define
define|#
directive|define
name|CCSR_RxEn
value|0x80
end_define

begin_comment
comment|/* Revceiver Enabled                      */
end_comment

begin_define
define|#
directive|define
name|CCSR_RxFloff
value|0x40
end_define

begin_comment
comment|/* Receive Flow Off (XOFF sent)           */
end_comment

begin_define
define|#
directive|define
name|CCSR_RxFlon
value|0x20
end_define

begin_comment
comment|/* Receive Flow On (XON sent)             */
end_comment

begin_define
define|#
directive|define
name|CCSR_TxEn
value|0x08
end_define

begin_comment
comment|/* Transmitter Enabled                    */
end_comment

begin_define
define|#
directive|define
name|CCSR_TxFloff
value|0x04
end_define

begin_comment
comment|/* Transmit Flow Off (got XOFF)           */
end_comment

begin_define
define|#
directive|define
name|CCSR_TxFlon
value|0x02
end_define

begin_comment
comment|/* Transmit Flow On (got XON)             */
end_comment

begin_comment
comment|/* Modem Change Option Register 1 */
end_comment

begin_define
define|#
directive|define
name|MCOR1_DSRzd
value|0x80
end_define

begin_comment
comment|/* Detect 0->1 transition of DSR          */
end_comment

begin_define
define|#
directive|define
name|MCOR1_CDzd
value|0x40
end_define

begin_comment
comment|/* Detect 0->1 transition of CD           */
end_comment

begin_define
define|#
directive|define
name|MCOR1_CTSzd
value|0x20
end_define

begin_comment
comment|/* Detect 0->1 transition of CTS          */
end_comment

begin_define
define|#
directive|define
name|MCOR1_DTRthMASK
value|0x0F
end_define

begin_comment
comment|/* Automatic DTR FC Threshold (1-8) chars */
end_comment

begin_comment
comment|/* Modem Change Option Register 2 */
end_comment

begin_define
define|#
directive|define
name|MCOR2_DSRod
value|0x80
end_define

begin_comment
comment|/* Detect 1->0 transition of DSR          */
end_comment

begin_define
define|#
directive|define
name|MCOR2_CDod
value|0x40
end_define

begin_comment
comment|/* Detect 1->0 transition of CD           */
end_comment

begin_define
define|#
directive|define
name|MCOR2_CTSod
value|0x20
end_define

begin_comment
comment|/* Detect 1->0 transition of CTS          */
end_comment

begin_comment
comment|/* Modem Change Register */
end_comment

begin_define
define|#
directive|define
name|MCR_DSRchg
value|0x80
end_define

begin_comment
comment|/* DSR Changed                            */
end_comment

begin_define
define|#
directive|define
name|MCR_CDchg
value|0x40
end_define

begin_comment
comment|/* CD  Changed                            */
end_comment

begin_define
define|#
directive|define
name|MCR_CTSchg
value|0x20
end_define

begin_comment
comment|/* CTS Changed                            */
end_comment

begin_comment
comment|/* Modem Signal Value Register */
end_comment

begin_define
define|#
directive|define
name|MSVR_DSR
value|0x80
end_define

begin_comment
comment|/* Current state of DSR input             */
end_comment

begin_define
define|#
directive|define
name|MSVR_CD
value|0x40
end_define

begin_comment
comment|/* Current state of DSR input             */
end_comment

begin_define
define|#
directive|define
name|MSVR_CTS
value|0x20
end_define

begin_comment
comment|/* Current state of CTS input             */
end_comment

begin_define
define|#
directive|define
name|MSVR_DTR
value|0x02
end_define

begin_comment
comment|/* Current state of DTR output            */
end_comment

begin_define
define|#
directive|define
name|MSVR_RTS
value|0x01
end_define

begin_comment
comment|/* Current state of RTS output            */
end_comment

begin_comment
comment|/* Escape characters */
end_comment

begin_define
define|#
directive|define
name|CD180_C_ESC
value|0x00
end_define

begin_comment
comment|/* Escape character                       */
end_comment

begin_define
define|#
directive|define
name|CD180_C_SBRK
value|0x81
end_define

begin_comment
comment|/* Start sending BREAK                    */
end_comment

begin_define
define|#
directive|define
name|CD180_C_DELAY
value|0x82
end_define

begin_comment
comment|/* Delay output                           */
end_comment

begin_define
define|#
directive|define
name|CD180_C_EBRK
value|0x83
end_define

begin_comment
comment|/* Stop sending BREAK                     */
end_comment

begin_comment
comment|/* Miscellaneous */
end_comment

begin_define
define|#
directive|define
name|CD180_NCHAN
value|8
end_define

begin_comment
comment|/* 8 channels per chip                    */
end_comment

begin_define
define|#
directive|define
name|CD180_CTICKS
value|16
end_define

begin_comment
comment|/* 16 ticks for character processing      */
end_comment

begin_define
define|#
directive|define
name|CD180_NFIFO
value|8
end_define

begin_comment
comment|/* 8 bytes in FIFO                        */
end_comment

end_unit

