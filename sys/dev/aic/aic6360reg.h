begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994 Charles Hannum.  * Copyright (c) 1994 Jarle Greipsland.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Jarle Greipsland  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,   * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|SCSISEQ
value|0x00
end_define

begin_comment
comment|/* SCSI sequence control */
end_comment

begin_define
define|#
directive|define
name|SXFRCTL0
value|0x01
end_define

begin_comment
comment|/* SCSI transfer control 0 */
end_comment

begin_define
define|#
directive|define
name|SXFRCTL1
value|0x02
end_define

begin_comment
comment|/* SCSI transfer control 1 */
end_comment

begin_define
define|#
directive|define
name|SCSISIGI
value|0x03
end_define

begin_comment
comment|/* SCSI signal in */
end_comment

begin_define
define|#
directive|define
name|SCSISIGO
value|0x03
end_define

begin_comment
comment|/* SCSI signal out */
end_comment

begin_define
define|#
directive|define
name|SCSIRATE
value|0x04
end_define

begin_comment
comment|/* SCSI rate control */
end_comment

begin_define
define|#
directive|define
name|SCSIID
value|0x05
end_define

begin_comment
comment|/* SCSI ID */
end_comment

begin_define
define|#
directive|define
name|SELID
value|0x05
end_define

begin_comment
comment|/* Selection/Reselection ID */
end_comment

begin_define
define|#
directive|define
name|SCSIDAT
value|0x06
end_define

begin_comment
comment|/* SCSI Latched Data */
end_comment

begin_define
define|#
directive|define
name|SCSIBUS
value|0x07
end_define

begin_comment
comment|/* SCSI Data Bus*/
end_comment

begin_define
define|#
directive|define
name|STCNT0
value|0x08
end_define

begin_comment
comment|/* SCSI transfer count */
end_comment

begin_define
define|#
directive|define
name|STCNT1
value|0x09
end_define

begin_define
define|#
directive|define
name|STCNT2
value|0x0a
end_define

begin_define
define|#
directive|define
name|CLRSINT0
value|0x0b
end_define

begin_comment
comment|/* Clear SCSI interrupts 0 */
end_comment

begin_define
define|#
directive|define
name|SSTAT0
value|0x0b
end_define

begin_comment
comment|/* SCSI interrupt status 0 */
end_comment

begin_define
define|#
directive|define
name|CLRSINT1
value|0x0c
end_define

begin_comment
comment|/* Clear SCSI interrupts 1 */
end_comment

begin_define
define|#
directive|define
name|SSTAT1
value|0x0c
end_define

begin_comment
comment|/* SCSI status 1 */
end_comment

begin_define
define|#
directive|define
name|SSTAT2
value|0x0d
end_define

begin_comment
comment|/* SCSI status 2 */
end_comment

begin_define
define|#
directive|define
name|SCSITEST
value|0x0e
end_define

begin_comment
comment|/* SCSI test control */
end_comment

begin_define
define|#
directive|define
name|SSTAT3
value|0x0e
end_define

begin_comment
comment|/* SCSI status 3 */
end_comment

begin_define
define|#
directive|define
name|CLRSERR
value|0x0f
end_define

begin_comment
comment|/* Clear SCSI errors */
end_comment

begin_define
define|#
directive|define
name|SSTAT4
value|0x0f
end_define

begin_comment
comment|/* SCSI status 4 */
end_comment

begin_define
define|#
directive|define
name|SIMODE0
value|0x10
end_define

begin_comment
comment|/* SCSI interrupt mode 0 */
end_comment

begin_define
define|#
directive|define
name|SIMODE1
value|0x11
end_define

begin_comment
comment|/* SCSI interrupt mode 1 */
end_comment

begin_define
define|#
directive|define
name|DMACNTRL0
value|0x12
end_define

begin_comment
comment|/* DMA control 0 */
end_comment

begin_define
define|#
directive|define
name|DMACNTRL1
value|0x13
end_define

begin_comment
comment|/* DMA control 1 */
end_comment

begin_define
define|#
directive|define
name|DMASTAT
value|0x14
end_define

begin_comment
comment|/* DMA status */
end_comment

begin_define
define|#
directive|define
name|FIFOSTAT
value|0x15
end_define

begin_comment
comment|/* FIFO status */
end_comment

begin_define
define|#
directive|define
name|DMADATA
value|0x16
end_define

begin_comment
comment|/* DMA data */
end_comment

begin_define
define|#
directive|define
name|DMADATAL
value|0x16
end_define

begin_comment
comment|/* DMA data low byte */
end_comment

begin_define
define|#
directive|define
name|DMADATAH
value|0x17
end_define

begin_comment
comment|/* DMA data high byte */
end_comment

begin_define
define|#
directive|define
name|BRSTCNTRL
value|0x18
end_define

begin_comment
comment|/* Burst Control */
end_comment

begin_define
define|#
directive|define
name|DMADATALONG
value|0x18
end_define

begin_define
define|#
directive|define
name|PORTA
value|0x1a
end_define

begin_comment
comment|/* Port A */
end_comment

begin_define
define|#
directive|define
name|PORTB
value|0x1b
end_define

begin_comment
comment|/* Port B */
end_comment

begin_define
define|#
directive|define
name|REV
value|0x1c
end_define

begin_comment
comment|/* Revision (001 for 6360) */
end_comment

begin_define
define|#
directive|define
name|STACK
value|0x1d
end_define

begin_comment
comment|/* Stack */
end_comment

begin_define
define|#
directive|define
name|TEST
value|0x1e
end_define

begin_comment
comment|/* Test register */
end_comment

begin_define
define|#
directive|define
name|ID
value|0x1f
end_define

begin_comment
comment|/* ID register */
end_comment

begin_define
define|#
directive|define
name|IDSTRING
value|"(C)1991ADAPTECAIC6360           "
end_define

begin_comment
comment|/* What all the bits do */
end_comment

begin_comment
comment|/* SCSISEQ */
end_comment

begin_define
define|#
directive|define
name|TEMODEO
value|0x80
end_define

begin_define
define|#
directive|define
name|ENSELO
value|0x40
end_define

begin_define
define|#
directive|define
name|ENSELI
value|0x20
end_define

begin_define
define|#
directive|define
name|ENRESELI
value|0x10
end_define

begin_define
define|#
directive|define
name|ENAUTOATNO
value|0x08
end_define

begin_define
define|#
directive|define
name|ENAUTOATNI
value|0x04
end_define

begin_define
define|#
directive|define
name|ENAUTOATNP
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSIRSTO
value|0x01
end_define

begin_comment
comment|/* SXFRCTL0 */
end_comment

begin_define
define|#
directive|define
name|SCSIEN
value|0x80
end_define

begin_define
define|#
directive|define
name|DMAEN
value|0x40
end_define

begin_define
define|#
directive|define
name|CHEN
value|0x20
end_define

begin_define
define|#
directive|define
name|CLRSTCNT
value|0x10
end_define

begin_define
define|#
directive|define
name|SPIOEN
value|0x08
end_define

begin_define
define|#
directive|define
name|CLRCH
value|0x02
end_define

begin_comment
comment|/* SXFRCTL1 */
end_comment

begin_define
define|#
directive|define
name|BITBUCKET
value|0x80
end_define

begin_define
define|#
directive|define
name|SWRAPEN
value|0x40
end_define

begin_define
define|#
directive|define
name|ENSPCHK
value|0x20
end_define

begin_define
define|#
directive|define
name|STIMESEL1
value|0x10
end_define

begin_define
define|#
directive|define
name|STIMESEL0
value|0x08
end_define

begin_define
define|#
directive|define
name|STIMO_256ms
value|0x00
end_define

begin_define
define|#
directive|define
name|STIMO_128ms
value|0x08
end_define

begin_define
define|#
directive|define
name|STIMO_64ms
value|0x10
end_define

begin_define
define|#
directive|define
name|STIMO_32ms
value|0x18
end_define

begin_define
define|#
directive|define
name|ENSTIMER
value|0x04
end_define

begin_define
define|#
directive|define
name|BYTEALIGN
value|0x02
end_define

begin_comment
comment|/* SCSISIGI */
end_comment

begin_define
define|#
directive|define
name|CDI
value|0x80
end_define

begin_define
define|#
directive|define
name|IOI
value|0x40
end_define

begin_define
define|#
directive|define
name|MSGI
value|0x20
end_define

begin_define
define|#
directive|define
name|ATNI
value|0x10
end_define

begin_define
define|#
directive|define
name|SELI
value|0x08
end_define

begin_define
define|#
directive|define
name|BSYI
value|0x04
end_define

begin_define
define|#
directive|define
name|REQI
value|0x02
end_define

begin_define
define|#
directive|define
name|ACKI
value|0x01
end_define

begin_comment
comment|/* Important! The 3 most significant bits of this register, in initiator mode,  * represents the "expected" SCSI bus phase and can be used to trigger phase  * mismatch and phase change interrupts.  But more important:  If there is a  * phase mismatch the chip will not transfer any data!  This is actually a nice  * feature as it gives us a bit more control over what is happening when we are  * bursting data (in) through the FIFOs and the phase suddenly changes from  * DATA IN to STATUS or MESSAGE IN.  The transfer will stop and wait for the  * proper phase to be set in this register instead of dumping the bits into the  * FIFOs.  */
end_comment

begin_comment
comment|/* SCSISIGO */
end_comment

begin_define
define|#
directive|define
name|CDO
value|0x80
end_define

begin_define
define|#
directive|define
name|IOO
value|0x40
end_define

begin_define
define|#
directive|define
name|MSGO
value|0x20
end_define

begin_define
define|#
directive|define
name|ATNO
value|0x10
end_define

begin_define
define|#
directive|define
name|SELO
value|0x08
end_define

begin_define
define|#
directive|define
name|BSYO
value|0x04
end_define

begin_define
define|#
directive|define
name|REQO
value|0x02
end_define

begin_define
define|#
directive|define
name|ACKO
value|0x01
end_define

begin_comment
comment|/* Information transfer phases */
end_comment

begin_define
define|#
directive|define
name|PH_DATAOUT
value|(0)
end_define

begin_define
define|#
directive|define
name|PH_DATAIN
value|(IOI)
end_define

begin_define
define|#
directive|define
name|PH_CMD
value|(CDI)
end_define

begin_define
define|#
directive|define
name|PH_STAT
value|(CDI|IOI)
end_define

begin_define
define|#
directive|define
name|PH_MSGOUT
value|(MSGI|CDI)
end_define

begin_define
define|#
directive|define
name|PH_MSGIN
value|(MSGI|CDI|IOI)
end_define

begin_define
define|#
directive|define
name|PH_MASK
value|(MSGI|CDI|IOI)
end_define

begin_comment
comment|/* SCSIRATE */
end_comment

begin_define
define|#
directive|define
name|SXFR2
value|0x40
end_define

begin_define
define|#
directive|define
name|SXFR1
value|0x20
end_define

begin_define
define|#
directive|define
name|SXFR0
value|0x10
end_define

begin_define
define|#
directive|define
name|SOFS3
value|0x08
end_define

begin_define
define|#
directive|define
name|SOFS2
value|0x04
end_define

begin_define
define|#
directive|define
name|SOFS1
value|0x02
end_define

begin_define
define|#
directive|define
name|SOFS0
value|0x01
end_define

begin_comment
comment|/* SCSI ID */
end_comment

begin_define
define|#
directive|define
name|OID2
value|0x40
end_define

begin_define
define|#
directive|define
name|OID1
value|0x20
end_define

begin_define
define|#
directive|define
name|OID0
value|0x10
end_define

begin_define
define|#
directive|define
name|OID_S
value|4
end_define

begin_comment
comment|/* shift value */
end_comment

begin_define
define|#
directive|define
name|TID2
value|0x04
end_define

begin_define
define|#
directive|define
name|TID1
value|0x02
end_define

begin_define
define|#
directive|define
name|TID0
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSI_ID_MASK
value|0x7
end_define

begin_comment
comment|/* SCSI selection/reselection ID (both target *and* initiator) */
end_comment

begin_define
define|#
directive|define
name|SELID7
value|0x80
end_define

begin_define
define|#
directive|define
name|SELID6
value|0x40
end_define

begin_define
define|#
directive|define
name|SELID5
value|0x20
end_define

begin_define
define|#
directive|define
name|SELID4
value|0x10
end_define

begin_define
define|#
directive|define
name|SELID3
value|0x08
end_define

begin_define
define|#
directive|define
name|SELID2
value|0x04
end_define

begin_define
define|#
directive|define
name|SELID1
value|0x02
end_define

begin_define
define|#
directive|define
name|SELID0
value|0x01
end_define

begin_comment
comment|/* CLRSINT0                      Clears what? (interrupt and/or status bit) */
end_comment

begin_define
define|#
directive|define
name|SETSDONE
value|0x80
end_define

begin_define
define|#
directive|define
name|CLRSELDO
value|0x40
end_define

begin_comment
comment|/* I */
end_comment

begin_define
define|#
directive|define
name|CLRSELDI
value|0x20
end_define

begin_comment
comment|/* I+ */
end_comment

begin_define
define|#
directive|define
name|CLRSELINGO
value|0x10
end_define

begin_comment
comment|/* I */
end_comment

begin_define
define|#
directive|define
name|CLRSWRAP
value|0x08
end_define

begin_comment
comment|/* I+S */
end_comment

begin_define
define|#
directive|define
name|CLRSDONE
value|0x04
end_define

begin_comment
comment|/* I+S */
end_comment

begin_define
define|#
directive|define
name|CLRSPIORDY
value|0x02
end_define

begin_comment
comment|/* I */
end_comment

begin_define
define|#
directive|define
name|CLRDMADONE
value|0x01
end_define

begin_comment
comment|/* I */
end_comment

begin_comment
comment|/* SSTAT0                          Howto clear */
end_comment

begin_define
define|#
directive|define
name|TARGET
value|0x80
end_define

begin_define
define|#
directive|define
name|SELDO
value|0x40
end_define

begin_comment
comment|/* Selfclearing */
end_comment

begin_define
define|#
directive|define
name|SELDI
value|0x20
end_define

begin_comment
comment|/* Selfclearing when CLRSELDI is set */
end_comment

begin_define
define|#
directive|define
name|SELINGO
value|0x10
end_define

begin_comment
comment|/* Selfclearing */
end_comment

begin_define
define|#
directive|define
name|SWRAP
value|0x08
end_define

begin_comment
comment|/* CLRSWAP */
end_comment

begin_define
define|#
directive|define
name|SDONE
value|0x04
end_define

begin_comment
comment|/* Not used in initiator mode */
end_comment

begin_define
define|#
directive|define
name|SPIORDY
value|0x02
end_define

begin_comment
comment|/* Selfclearing (op on SCSIDAT) */
end_comment

begin_define
define|#
directive|define
name|DMADONE
value|0x01
end_define

begin_comment
comment|/* Selfclearing (all FIFOs empty& T/C */
end_comment

begin_comment
comment|/* CLRSINT1                      Clears what? */
end_comment

begin_define
define|#
directive|define
name|CLRSELTIMO
value|0x80
end_define

begin_comment
comment|/* I+S */
end_comment

begin_define
define|#
directive|define
name|CLRATNO
value|0x40
end_define

begin_define
define|#
directive|define
name|CLRSCSIRSTI
value|0x20
end_define

begin_comment
comment|/* I+S */
end_comment

begin_define
define|#
directive|define
name|CLRBUSFREE
value|0x08
end_define

begin_comment
comment|/* I+S */
end_comment

begin_define
define|#
directive|define
name|CLRSCSIPERR
value|0x04
end_define

begin_comment
comment|/* I+S */
end_comment

begin_define
define|#
directive|define
name|CLRPHASECHG
value|0x02
end_define

begin_comment
comment|/* I+S */
end_comment

begin_define
define|#
directive|define
name|CLRREQINIT
value|0x01
end_define

begin_comment
comment|/* I+S */
end_comment

begin_comment
comment|/* SSTAT1                       How to clear?  When set?*/
end_comment

begin_define
define|#
directive|define
name|SELTO
value|0x80
end_define

begin_comment
comment|/* C		select out timeout */
end_comment

begin_define
define|#
directive|define
name|ATNTARG
value|0x40
end_define

begin_comment
comment|/* Not used in initiator mode */
end_comment

begin_define
define|#
directive|define
name|SCSIRSTI
value|0x20
end_define

begin_comment
comment|/* C		RST asserted */
end_comment

begin_define
define|#
directive|define
name|PHASEMIS
value|0x10
end_define

begin_comment
comment|/* Selfclearing */
end_comment

begin_define
define|#
directive|define
name|BUSFREE
value|0x08
end_define

begin_comment
comment|/* C		bus free condition */
end_comment

begin_define
define|#
directive|define
name|SCSIPERR
value|0x04
end_define

begin_comment
comment|/* C		parity error on inbound data */
end_comment

begin_define
define|#
directive|define
name|PHASECHG
value|0x02
end_define

begin_comment
comment|/* C	     phase in SCSISIGI doesn't match */
end_comment

begin_define
define|#
directive|define
name|REQINIT
value|0x01
end_define

begin_comment
comment|/* C or ACK	asserting edge of REQ */
end_comment

begin_comment
comment|/* SSTAT2 */
end_comment

begin_define
define|#
directive|define
name|SOFFSET
value|0x20
end_define

begin_define
define|#
directive|define
name|SEMPTY
value|0x10
end_define

begin_define
define|#
directive|define
name|SFULL
value|0x08
end_define

begin_define
define|#
directive|define
name|SFCNT2
value|0x04
end_define

begin_define
define|#
directive|define
name|SFCNT1
value|0x02
end_define

begin_define
define|#
directive|define
name|SFCNT0
value|0x01
end_define

begin_comment
comment|/* SCSITEST */
end_comment

begin_define
define|#
directive|define
name|SCTESTU
value|0x08
end_define

begin_define
define|#
directive|define
name|SCTESTD
value|0x04
end_define

begin_define
define|#
directive|define
name|STCTEST
value|0x01
end_define

begin_comment
comment|/* SSTAT3 */
end_comment

begin_define
define|#
directive|define
name|SCSICNT3
value|0x80
end_define

begin_define
define|#
directive|define
name|SCSICNT2
value|0x40
end_define

begin_define
define|#
directive|define
name|SCSICNT1
value|0x20
end_define

begin_define
define|#
directive|define
name|SCSICNT0
value|0x10
end_define

begin_define
define|#
directive|define
name|OFFCNT3
value|0x08
end_define

begin_define
define|#
directive|define
name|OFFCNT2
value|0x04
end_define

begin_define
define|#
directive|define
name|OFFCNT1
value|0x02
end_define

begin_define
define|#
directive|define
name|OFFCNT0
value|0x01
end_define

begin_comment
comment|/* CLRSERR */
end_comment

begin_define
define|#
directive|define
name|CLRSYNCERR
value|0x04
end_define

begin_define
define|#
directive|define
name|CLRFWERR
value|0x02
end_define

begin_define
define|#
directive|define
name|CLRFRERR
value|0x01
end_define

begin_comment
comment|/* SSTAT4 */
end_comment

begin_define
define|#
directive|define
name|SYNCERR
value|0x04
end_define

begin_define
define|#
directive|define
name|FWERR
value|0x02
end_define

begin_define
define|#
directive|define
name|FRERR
value|0x01
end_define

begin_comment
comment|/* SIMODE0 */
end_comment

begin_define
define|#
directive|define
name|ENSELDO
value|0x40
end_define

begin_define
define|#
directive|define
name|ENSELDI
value|0x20
end_define

begin_define
define|#
directive|define
name|ENSELINGO
value|0x10
end_define

begin_define
define|#
directive|define
name|ENSWRAP
value|0x08
end_define

begin_define
define|#
directive|define
name|ENSDONE
value|0x04
end_define

begin_define
define|#
directive|define
name|ENSPIORDY
value|0x02
end_define

begin_define
define|#
directive|define
name|ENDMADONE
value|0x01
end_define

begin_comment
comment|/* SIMODE1 */
end_comment

begin_define
define|#
directive|define
name|ENSELTIMO
value|0x80
end_define

begin_define
define|#
directive|define
name|ENATNTARG
value|0x40
end_define

begin_define
define|#
directive|define
name|ENSCSIRST
value|0x20
end_define

begin_define
define|#
directive|define
name|ENPHASEMIS
value|0x10
end_define

begin_define
define|#
directive|define
name|ENBUSFREE
value|0x08
end_define

begin_define
define|#
directive|define
name|ENSCSIPERR
value|0x04
end_define

begin_define
define|#
directive|define
name|ENPHASECHG
value|0x02
end_define

begin_define
define|#
directive|define
name|ENREQINIT
value|0x01
end_define

begin_comment
comment|/* DMACNTRL0 */
end_comment

begin_define
define|#
directive|define
name|ENDMA
value|0x80
end_define

begin_define
define|#
directive|define
name|B8MODE
value|0x40
end_define

begin_define
define|#
directive|define
name|DMA
value|0x20
end_define

begin_define
define|#
directive|define
name|DWORDPIO
value|0x10
end_define

begin_define
define|#
directive|define
name|WRITE
value|0x08
end_define

begin_define
define|#
directive|define
name|INTEN
value|0x04
end_define

begin_define
define|#
directive|define
name|RSTFIFO
value|0x02
end_define

begin_define
define|#
directive|define
name|SWINT
value|0x01
end_define

begin_comment
comment|/* DMACNTRL1 */
end_comment

begin_define
define|#
directive|define
name|PWRDWN
value|0x80
end_define

begin_define
define|#
directive|define
name|ENSTK32
value|0x40
end_define

begin_define
define|#
directive|define
name|STK4
value|0x10
end_define

begin_define
define|#
directive|define
name|STK3
value|0x08
end_define

begin_define
define|#
directive|define
name|STK2
value|0x04
end_define

begin_define
define|#
directive|define
name|STK1
value|0x02
end_define

begin_define
define|#
directive|define
name|STK0
value|0x01
end_define

begin_comment
comment|/* DMASTAT */
end_comment

begin_define
define|#
directive|define
name|ATDONE
value|0x80
end_define

begin_define
define|#
directive|define
name|WORDRDY
value|0x40
end_define

begin_define
define|#
directive|define
name|INTSTAT
value|0x20
end_define

begin_define
define|#
directive|define
name|DFIFOFULL
value|0x10
end_define

begin_define
define|#
directive|define
name|DFIFOEMP
value|0x08
end_define

begin_define
define|#
directive|define
name|DFIFOHF
value|0x04
end_define

begin_define
define|#
directive|define
name|DWORDRDY
value|0x02
end_define

begin_comment
comment|/* BRSTCNTRL */
end_comment

begin_define
define|#
directive|define
name|BON3
value|0x80
end_define

begin_define
define|#
directive|define
name|BON2
value|0x40
end_define

begin_define
define|#
directive|define
name|BON1
value|0x20
end_define

begin_define
define|#
directive|define
name|BON0
value|0x10
end_define

begin_define
define|#
directive|define
name|BOFF3
value|0x08
end_define

begin_define
define|#
directive|define
name|BOFF2
value|0x04
end_define

begin_define
define|#
directive|define
name|BOFF1
value|0x02
end_define

begin_define
define|#
directive|define
name|BOFF0
value|0x01
end_define

begin_comment
comment|/* TEST */
end_comment

begin_define
define|#
directive|define
name|BOFFTMR
value|0x40
end_define

begin_define
define|#
directive|define
name|BONTMR
value|0x20
end_define

begin_define
define|#
directive|define
name|STCNTH
value|0x10
end_define

begin_define
define|#
directive|define
name|STCNTM
value|0x08
end_define

begin_define
define|#
directive|define
name|STCNTL
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSIBLK
value|0x02
end_define

begin_define
define|#
directive|define
name|DMABLK
value|0x01
end_define

begin_comment
comment|/* PORTA */
end_comment

begin_define
define|#
directive|define
name|PORTA_ID
parameter_list|(
name|a
parameter_list|)
value|((a)& 7)
end_define

begin_define
define|#
directive|define
name|PORTA_IRQ
parameter_list|(
name|a
parameter_list|)
value|((((a)>> 3)& 3) + 9)
end_define

begin_define
define|#
directive|define
name|PORTA_DRQ
parameter_list|(
name|a
parameter_list|)
value|((((a)>> 5)& 3) ? (((a)>> 5)& 3) + 4 : 0)
end_define

begin_define
define|#
directive|define
name|PORTA_PARITY
parameter_list|(
name|a
parameter_list|)
value|((a)& 0x80)
end_define

begin_comment
comment|/* PORTB */
end_comment

begin_define
define|#
directive|define
name|PORTB_DISC
parameter_list|(
name|b
parameter_list|)
value|((b)& 4)
end_define

begin_define
define|#
directive|define
name|PORTB_SYNC
parameter_list|(
name|b
parameter_list|)
value|((b)& 8)
end_define

begin_define
define|#
directive|define
name|PORTB_BOOT
parameter_list|(
name|b
parameter_list|)
value|((b)& 0x40)
end_define

begin_define
define|#
directive|define
name|PORTB_DMA
parameter_list|(
name|b
parameter_list|)
value|((b)& 0x80)
end_define

begin_comment
comment|/* How to behave on the (E)ISA bus when/if DMAing (on<<4) + off in us */
end_comment

begin_define
define|#
directive|define
name|EISA_BRST_TIM
value|((15<<4) + 1)
end_define

begin_comment
comment|/* 15us on, 1us off */
end_comment

begin_define
define|#
directive|define
name|FIFOSIZE
value|128
end_define

end_unit

