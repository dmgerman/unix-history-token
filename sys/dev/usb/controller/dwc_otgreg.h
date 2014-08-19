begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2010,2011 Aleksandr Rybalko. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DWC_OTGREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DWC_OTGREG_H_
end_define

begin_define
define|#
directive|define
name|DOTG_GOTGCTL
value|0x0000
end_define

begin_define
define|#
directive|define
name|DOTG_GOTGINT
value|0x0004
end_define

begin_define
define|#
directive|define
name|DOTG_GAHBCFG
value|0x0008
end_define

begin_define
define|#
directive|define
name|DOTG_GUSBCFG
value|0x000C
end_define

begin_define
define|#
directive|define
name|DOTG_GRSTCTL
value|0x0010
end_define

begin_define
define|#
directive|define
name|DOTG_GINTSTS
value|0x0014
end_define

begin_define
define|#
directive|define
name|DOTG_GINTMSK
value|0x0018
end_define

begin_define
define|#
directive|define
name|DOTG_GRXSTSRD
value|0x001C
end_define

begin_define
define|#
directive|define
name|DOTG_GRXSTSRH
value|0x001C
end_define

begin_define
define|#
directive|define
name|DOTG_GRXSTSPD
value|0x0020
end_define

begin_define
define|#
directive|define
name|DOTG_GRXSTSPH
value|0x0020
end_define

begin_define
define|#
directive|define
name|DOTG_GRXFSIZ
value|0x0024
end_define

begin_define
define|#
directive|define
name|DOTG_GNPTXFSIZ
value|0x0028
end_define

begin_define
define|#
directive|define
name|DOTG_GNPTXSTS
value|0x002C
end_define

begin_define
define|#
directive|define
name|DOTG_GI2CCTL
value|0x0030
end_define

begin_define
define|#
directive|define
name|DOTG_GPVNDCTL
value|0x0034
end_define

begin_define
define|#
directive|define
name|DOTG_GGPIO
value|0x0038
end_define

begin_define
define|#
directive|define
name|DOTG_GUID
value|0x003C
end_define

begin_define
define|#
directive|define
name|DOTG_GSNPSID
value|0x0040
end_define

begin_define
define|#
directive|define
name|DOTG_GHWCFG1
value|0x0044
end_define

begin_define
define|#
directive|define
name|DOTG_GHWCFG2
value|0x0048
end_define

begin_define
define|#
directive|define
name|DOTG_GHWCFG3
value|0x004C
end_define

begin_define
define|#
directive|define
name|DOTG_GHWCFG4
value|0x0050
end_define

begin_define
define|#
directive|define
name|DOTG_GLPMCFG
value|0x0054
end_define

begin_define
define|#
directive|define
name|DOTG_GPWRDN
value|0x0058
end_define

begin_define
define|#
directive|define
name|DOTG_GDFIFOCFG
value|0x005C
end_define

begin_define
define|#
directive|define
name|DOTG_GADPCTL
value|0x0060
end_define

begin_define
define|#
directive|define
name|DOTG_HPTXFSIZ
value|0x0100
end_define

begin_comment
comment|/* start from 0x104, but fifo0 not exists */
end_comment

begin_define
define|#
directive|define
name|DOTG_DPTXFSIZ
parameter_list|(
name|fifo
parameter_list|)
value|(0x0100 + (4*(fifo)))
end_define

begin_define
define|#
directive|define
name|DOTG_DIEPTXF
parameter_list|(
name|fifo
parameter_list|)
value|(0x0100 + (4*(fifo)))
end_define

begin_define
define|#
directive|define
name|DOTG_HCFG
value|0x0400
end_define

begin_define
define|#
directive|define
name|DOTG_HFIR
value|0x0404
end_define

begin_define
define|#
directive|define
name|DOTG_HFNUM
value|0x0408
end_define

begin_define
define|#
directive|define
name|DOTG_HPTXSTS
value|0x0410
end_define

begin_define
define|#
directive|define
name|DOTG_HAINT
value|0x0414
end_define

begin_define
define|#
directive|define
name|DOTG_HAINTMSK
value|0x0418
end_define

begin_define
define|#
directive|define
name|DOTG_HPRT
value|0x0440
end_define

begin_define
define|#
directive|define
name|DOTG_HCCHAR
parameter_list|(
name|ch
parameter_list|)
value|(0x0500 + (32*(ch)))
end_define

begin_define
define|#
directive|define
name|DOTG_HCSPLT
parameter_list|(
name|ch
parameter_list|)
value|(0x0504 + (32*(ch)))
end_define

begin_define
define|#
directive|define
name|DOTG_HCINT
parameter_list|(
name|ch
parameter_list|)
value|(0x0508 + (32*(ch)))
end_define

begin_define
define|#
directive|define
name|DOTG_HCINTMSK
parameter_list|(
name|ch
parameter_list|)
value|(0x050C + (32*(ch)))
end_define

begin_define
define|#
directive|define
name|DOTG_HCTSIZ
parameter_list|(
name|ch
parameter_list|)
value|(0x0510 + (32*(ch)))
end_define

begin_define
define|#
directive|define
name|DOTG_HCDMA
parameter_list|(
name|ch
parameter_list|)
value|(0x0514 + (32*(ch)))
end_define

begin_define
define|#
directive|define
name|DOTG_HCDMAI
parameter_list|(
name|ch
parameter_list|)
value|(0x0514 + (32*(ch)))
end_define

begin_define
define|#
directive|define
name|DOTG_HCDMAO
parameter_list|(
name|ch
parameter_list|)
value|(0x0514 + (32*(ch)))
end_define

begin_define
define|#
directive|define
name|DOTG_HCDMAB
parameter_list|(
name|ch
parameter_list|)
value|(0x051C + (32*(ch)))
end_define

begin_comment
comment|/* Device Mode */
end_comment

begin_define
define|#
directive|define
name|DOTG_DCFG
value|0x0800
end_define

begin_define
define|#
directive|define
name|DOTG_DCTL
value|0x0804
end_define

begin_define
define|#
directive|define
name|DOTG_DSTS
value|0x0808
end_define

begin_define
define|#
directive|define
name|DOTG_DIEPMSK
value|0x0810
end_define

begin_define
define|#
directive|define
name|DOTG_DOEPMSK
value|0x0814
end_define

begin_define
define|#
directive|define
name|DOTG_DAINT
value|0x0818
end_define

begin_define
define|#
directive|define
name|DOTG_DAINTMSK
value|0x081C
end_define

begin_define
define|#
directive|define
name|DOTG_DTKNQR1
value|0x0820
end_define

begin_define
define|#
directive|define
name|DOTG_DTKNQR2
value|0x0824
end_define

begin_define
define|#
directive|define
name|DOTG_DVBUSDIS
value|0x0828
end_define

begin_define
define|#
directive|define
name|DOTG_DVBUSPULSE
value|0x082C
end_define

begin_define
define|#
directive|define
name|DOTG_DTHRCTL
value|0x0830
end_define

begin_define
define|#
directive|define
name|DOTG_DTKNQR4
value|0x0834
end_define

begin_define
define|#
directive|define
name|DOTG_DIEPEMPMSK
value|0x0834
end_define

begin_define
define|#
directive|define
name|DOTG_DEACHINT
value|0x0838
end_define

begin_define
define|#
directive|define
name|DOTG_DEACHINTMSK
value|0x083C
end_define

begin_define
define|#
directive|define
name|DOTG_DIEPEACHINTMSK
parameter_list|(
name|ch
parameter_list|)
value|(0x0840 + (4*(ch)))
end_define

begin_define
define|#
directive|define
name|DOTG_DOEPEACHINTMSK
parameter_list|(
name|ch
parameter_list|)
value|(0x0880 + (4*(ch)))
end_define

begin_define
define|#
directive|define
name|DOTG_DIEPCTL
parameter_list|(
name|ep
parameter_list|)
value|(0x0900 + (32*(ep)))
end_define

begin_define
define|#
directive|define
name|DOTG_DIEPINT
parameter_list|(
name|ep
parameter_list|)
value|(0x0908 + (32*(ep)))
end_define

begin_define
define|#
directive|define
name|DOTG_DIEPTSIZ
parameter_list|(
name|ep
parameter_list|)
value|(0x0910 + (32*(ep)))
end_define

begin_define
define|#
directive|define
name|DOTG_DIEPDMA
parameter_list|(
name|ep
parameter_list|)
value|(0x0914 + (32*(ep)))
end_define

begin_define
define|#
directive|define
name|DOTG_DTXFSTS
parameter_list|(
name|ep
parameter_list|)
value|(0x0918 + (32*(ep)))
end_define

begin_define
define|#
directive|define
name|DOTG_DIEPDMAB
parameter_list|(
name|ep
parameter_list|)
value|(0x091c + (32*(ep)))
end_define

begin_define
define|#
directive|define
name|DOTG_DOEPCTL
parameter_list|(
name|ep
parameter_list|)
value|(0x0B00 + (32*(ep)))
end_define

begin_define
define|#
directive|define
name|DOTG_DOEPFN
parameter_list|(
name|ep
parameter_list|)
value|(0x0B04 + (32*(ep)))
end_define

begin_define
define|#
directive|define
name|DOTG_DOEPINT
parameter_list|(
name|ep
parameter_list|)
value|(0x0B08 + (32*(ep)))
end_define

begin_define
define|#
directive|define
name|DOTG_DOEPTSIZ
parameter_list|(
name|ep
parameter_list|)
value|(0x0B10 + (32*(ep)))
end_define

begin_define
define|#
directive|define
name|DOTG_DOEPDMA
parameter_list|(
name|ep
parameter_list|)
value|(0x0B14 + (32*(ep)))
end_define

begin_define
define|#
directive|define
name|DOTG_DOEPDMAB
parameter_list|(
name|ep
parameter_list|)
value|(0x0B1c + (32*(ep)))
end_define

begin_comment
comment|/* End Device Mode */
end_comment

begin_comment
comment|/* Host Mode #define	DOTG_CTL_STATUS		0x0800 #define	DOTG_DMA0_INB_CHN0	0x0818 #define	DOTG_DMA0_INB_CHN1	0x0820 #define	DOTG_DMA0_INB_CHN2	0x0828 #define	DOTG_DVBUSDIS		0x0828 #define	DOTG_DVBUSPULSE		0x082c #define	DOTG_DMA0_INB_CHN3	0x0830 #define	DOTG_DMA0_INB_CHN4	0x0838 #define	DOTG_DMA0_INB_CHN5	0x0840 #define	DOTG_DMA0_INB_CHN6	0x0848 #define	DOTG_DMA0_INB_CHN7	0x0850 #define	DOTG_DMA0_OUTB_CHN0	0x0858 #define	DOTG_DMA0_OUTB_CHN1	0x0860 #define	DOTG_DMA0_OUTB_CHN2	0x0868 #define	DOTG_DMA0_OUTB_CHN3	0x0870 #define	DOTG_DMA0_OUTB_CHN4	0x0878 #define	DOTG_DMA0_OUTB_CHN5	0x0880 #define	DOTG_DMA0_OUTB_CHN6	0x0888 #define	DOTG_DMA0_OUTB_CHN7	0x0890  End Host Mode */
end_comment

begin_comment
comment|/* Power and clock gating CSR */
end_comment

begin_define
define|#
directive|define
name|DOTG_PCGCCTL
value|0x0E00
end_define

begin_comment
comment|/* FIFO access registers (PIO-mode) */
end_comment

begin_define
define|#
directive|define
name|DOTG_DFIFO
parameter_list|(
name|n
parameter_list|)
value|(0x1000 + (0x1000 * (n)))
end_define

begin_define
define|#
directive|define
name|GOTGCTL_CHIRP_ON
value|(1<<27)
end_define

begin_define
define|#
directive|define
name|GOTGCTL_BSESVLD
value|(1<<19)
end_define

begin_define
define|#
directive|define
name|GOTGCTL_ASESVLD
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|GOTGCTL_DBNCTIME
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|GOTGCTL_CONIDSTS
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|GOTGCTL_DEVHNPEN
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|GOTGCTL_HSTSETHNPEN
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|GOTGCTL_HNPREQ
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|GOTGCTL_HSTNEGSCS
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|GOTGCTL_SESREQ
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|GOTGCTL_SESREQSCS
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|GOTGCTL_DBNCEDONE
value|(1<<19)
end_define

begin_define
define|#
directive|define
name|GOTGCTL_ADEVTOUTCHG
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|GOTGCTL_HSTNEGDET
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|GOTGCTL_HSTNEGSUCSTSCHG
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|GOTGCTL_SESREQSUCSTSCHG
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|GOTGCTL_SESENDDET
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|GAHBCFG_PTXFEMPLVL
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|GAHBCFG_NPTXFEMPLVL
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|GAHBCFG_DMAEN
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|GAHBCFG_HBSTLEN_MASK
value|0x0000001e
end_define

begin_define
define|#
directive|define
name|GAHBCFG_HBSTLEN_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|GAHBCFG_GLBLINTRMSK
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|GUSBCFG_CORRUPTTXPACKET
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|GUSBCFG_FORCEDEVMODE
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|GUSBCFG_FORCEHOSTMODE
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|GUSBCFG_NO_PULLUP
value|(1<<27)
end_define

begin_define
define|#
directive|define
name|GUSBCFG_IC_USB_CAP
value|(1<<26)
end_define

begin_define
define|#
directive|define
name|GUSBCFG_TERMSELDLPULSE
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|GUSBCFG_ULPIEXTVBUSINDICATOR
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|GUSBCFG_ULPIEXTVBUSDRV
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|GUSBCFG_ULPICLKSUSM
value|(1<<19)
end_define

begin_define
define|#
directive|define
name|GUSBCFG_ULPIAUTORES
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|GUSBCFG_ULPIFSLS
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|GUSBCFG_OTGI2CSEL
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|GUSBCFG_PHYLPWRCLKSEL
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|GUSBCFG_USBTRDTIM_MASK
value|0x00003c00
end_define

begin_define
define|#
directive|define
name|GUSBCFG_USBTRDTIM_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|GUSBCFG_TRD_TIM_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 15)<< 10)
end_define

begin_define
define|#
directive|define
name|GUSBCFG_HNPCAP
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|GUSBCFG_SRPCAP
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|GUSBCFG_DDRSEL
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|GUSBCFG_PHYSEL
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|GUSBCFG_FSINTF
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|GUSBCFG_ULPI_UTMI_SEL
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|GUSBCFG_PHYIF
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|GUSBCFG_TOUTCAL_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|GUSBCFG_TOUTCAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GRSTCTL_AHBIDLE
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|GRSTCTL_DMAREQ
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|GRSTCTL_TXFNUM_MASK
value|0x000007c0
end_define

begin_define
define|#
directive|define
name|GRSTCTL_TXFNUM_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|GRSTCTL_TXFIFO
parameter_list|(
name|n
parameter_list|)
value|(((n)& 31)<< 6)
end_define

begin_define
define|#
directive|define
name|GRSTCTL_TXFFLSH
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|GRSTCTL_RXFFLSH
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|GRSTCTL_INTKNQFLSH
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|GRSTCTL_FRMCNTRRST
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|GRSTCTL_HSFTRST
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|GRSTCTL_CSFTRST
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|GINTSTS_WKUPINT
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|GINTSTS_SESSREQINT
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|GINTSTS_DISCONNINT
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|GINTSTS_CONIDSTSCHNG
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|GINTSTS_LPM
value|(1<<27)
end_define

begin_define
define|#
directive|define
name|GINTSTS_PTXFEMP
value|(1<<26)
end_define

begin_define
define|#
directive|define
name|GINTSTS_HCHINT
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|GINTSTS_PRTINT
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|GINTSTS_RESETDET
value|(1<<23)
end_define

begin_define
define|#
directive|define
name|GINTSTS_FETSUSP
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|GINTSTS_INCOMPLP
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|GINTSTS_INCOMPISOIN
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|GINTSTS_OEPINT
value|(1<<19)
end_define

begin_define
define|#
directive|define
name|GINTSTS_IEPINT
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|GINTSTS_EPMIS
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|GINTSTS_RESTORE_DONE
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|GINTSTS_EOPF
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|GINTSTS_ISOOUTDROP
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|GINTSTS_ENUMDONE
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|GINTSTS_USBRST
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|GINTSTS_USBSUSP
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|GINTSTS_ERLYSUSP
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|GINTSTS_I2CINT
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|GINTSTS_ULPICKINT
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|GINTSTS_GOUTNAKEFF
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|GINTSTS_GINNAKEFF
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|GINTSTS_NPTXFEMP
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|GINTSTS_RXFLVL
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|GINTSTS_SOF
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|GINTSTS_OTGINT
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|GINTSTS_MODEMIS
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|GINTSTS_CURMOD
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|GINTMSK_WKUPINTMSK
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|GINTMSK_SESSREQINTMSK
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|GINTMSK_DISCONNINTMSK
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|GINTMSK_CONIDSTSCHNGMSK
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|GINTMSK_PTXFEMPMSK
value|(1<<26)
end_define

begin_define
define|#
directive|define
name|GINTMSK_HCHINTMSK
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|GINTMSK_PRTINTMSK
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|GINTMSK_FETSUSPMSK
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|GINTMSK_INCOMPLPMSK
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|GINTMSK_INCOMPISOINMSK
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|GINTMSK_OEPINTMSK
value|(1<<19)
end_define

begin_define
define|#
directive|define
name|GINTMSK_IEPINTMSK
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|GINTMSK_EPMISMSK
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|GINTMSK_EOPFMSK
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|GINTMSK_ISOOUTDROPMSK
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|GINTMSK_ENUMDONEMSK
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|GINTMSK_USBRSTMSK
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|GINTMSK_USBSUSPMSK
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|GINTMSK_ERLYSUSPMSK
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|GINTMSK_I2CINTMSK
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|GINTMSK_ULPICKINTMSK
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|GINTMSK_GOUTNAKEFFMSK
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|GINTMSK_GINNAKEFFMSK
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|GINTMSK_NPTXFEMPMSK
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|GINTMSK_RXFLVLMSK
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|GINTMSK_SOFMSK
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|GINTMSK_OTGINTMSK
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|GINTMSK_MODEMISMSK
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|GINTMSK_CURMODMSK
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|GRXSTSRH_PKTSTS_MASK
value|0x001e0000
end_define

begin_define
define|#
directive|define
name|GRXSTSRH_PKTSTS_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|GRXSTSRH_DPID_MASK
value|0x00018000
end_define

begin_define
define|#
directive|define
name|GRXSTSRH_DPID_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|GRXSTSRH_BCNT_MASK
value|0x00007ff0
end_define

begin_define
define|#
directive|define
name|GRXSTSRH_BCNT_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|GRXSTSRH_CHNUM_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|GRXSTSRH_CHNUM_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GRXSTSRD_FN_MASK
value|0x01e00000
end_define

begin_define
define|#
directive|define
name|GRXSTSRD_FN_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 21)& 15)
end_define

begin_define
define|#
directive|define
name|GRXSTSRD_FN_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|GRXSTSRD_PKTSTS_MASK
value|0x001e0000
end_define

begin_define
define|#
directive|define
name|GRXSTSRD_PKTSTS_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|GRXSTSRH_IN_DATA
value|(2<<17)
end_define

begin_define
define|#
directive|define
name|GRXSTSRH_IN_COMPLETE
value|(3<<17)
end_define

begin_define
define|#
directive|define
name|GRXSTSRH_DT_ERROR
value|(5<<17)
end_define

begin_define
define|#
directive|define
name|GRXSTSRH_HALTED
value|(7<<17)
end_define

begin_define
define|#
directive|define
name|GRXSTSRD_GLOB_OUT_NAK
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|GRXSTSRD_OUT_DATA
value|(2<<17)
end_define

begin_define
define|#
directive|define
name|GRXSTSRD_OUT_COMPLETE
value|(3<<17)
end_define

begin_define
define|#
directive|define
name|GRXSTSRD_STP_COMPLETE
value|(4<<17)
end_define

begin_define
define|#
directive|define
name|GRXSTSRD_STP_DATA
value|(6<<17)
end_define

begin_define
define|#
directive|define
name|GRXSTSRD_DPID_MASK
value|0x00018000
end_define

begin_define
define|#
directive|define
name|GRXSTSRD_DPID_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|GRXSTSRD_DPID_DATA0
value|(0<<15)
end_define

begin_define
define|#
directive|define
name|GRXSTSRD_DPID_DATA1
value|(2<<15)
end_define

begin_define
define|#
directive|define
name|GRXSTSRD_DPID_DATA2
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|GRXSTSRD_DPID_MDATA
value|(3<<15)
end_define

begin_define
define|#
directive|define
name|GRXSTSRD_BCNT_MASK
value|0x00007ff0
end_define

begin_define
define|#
directive|define
name|GRXSTSRD_BCNT_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x7FF)
end_define

begin_define
define|#
directive|define
name|GRXSTSRD_BCNT_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|GRXSTSRD_CHNUM_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|GRXSTSRD_CHNUM_GET
parameter_list|(
name|x
parameter_list|)
value|((x)& 15)
end_define

begin_define
define|#
directive|define
name|GRXSTSRD_CHNUM_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GRXFSIZ_RXFDEP_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|GRXFSIZ_RXFDEP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GNPTXFSIZ_NPTXFDEP_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|GNPTXFSIZ_NPTXFDEP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GNPTXFSIZ_NPTXFSTADDR_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|GNPTXFSIZ_NPTXFSTADDR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|GNPTXSTS_NPTXQTOP_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|GNPTXSTS_NPTXQTOP_MASK
value|0x7f000000
end_define

begin_define
define|#
directive|define
name|GNPTXSTS_NPTXQSPCAVAIL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|GNPTXSTS_NPTXQSPCAVAIL_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|GNPTXSTS_NPTXFSPCAVAIL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GNPTXSTS_NPTXFSPCAVAIL_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|GI2CCTL_BSYDNE_SC
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|GI2CCTL_RW
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|GI2CCTL_I2CDATSE0
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|GI2CCTL_I2CDEVADR_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|GI2CCTL_I2CDEVADR_MASK
value|0x0c000000
end_define

begin_define
define|#
directive|define
name|GI2CCTL_I2CSUSPCTL
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|GI2CCTL_ACK
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|GI2CCTL_I2CEN
value|(1<<23)
end_define

begin_define
define|#
directive|define
name|GI2CCTL_ADDR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|GI2CCTL_ADDR_MASK
value|0x007f0000
end_define

begin_define
define|#
directive|define
name|GI2CCTL_REGADDR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|GI2CCTL_REGADDR_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|GI2CCTL_RWDATA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GI2CCTL_RWDATA_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|GPVNDCTL_DISULPIDRVR
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|GPVNDCTL_VSTSDONE
value|(1<<27)
end_define

begin_define
define|#
directive|define
name|GPVNDCTL_VSTSBSY
value|(1<<26)
end_define

begin_define
define|#
directive|define
name|GPVNDCTL_NEWREGREQ
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|GPVNDCTL_REGWR
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|GPVNDCTL_REGADDR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|GPVNDCTL_REGADDR_MASK
value|0x003f0000
end_define

begin_define
define|#
directive|define
name|GPVNDCTL_VCTRL_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|GPVNDCTL_VCTRL_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|GPVNDCTL_REGDATA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GPVNDCTL_REGDATA_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|GGPIO_GPO_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|GGPIO_GPO_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|GGPIO_GPI_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GGPIO_GPI_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|GHWCFG1_GET_DIR
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|(((x)>> (2 * (n)))& 3)
end_define

begin_define
define|#
directive|define
name|GHWCFG1_BIDIR
value|0
end_define

begin_define
define|#
directive|define
name|GHWCFG1_IN
value|1
end_define

begin_define
define|#
directive|define
name|GHWCFG1_OUT
value|2
end_define

begin_define
define|#
directive|define
name|GHWCFG2_TKNQDEPTH_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|GHWCFG2_TKNQDEPTH_MASK
value|0x7c000000
end_define

begin_define
define|#
directive|define
name|GHWCFG2_PTXQDEPTH_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|GHWCFG2_PTXQDEPTH_MASK
value|0x03000000
end_define

begin_define
define|#
directive|define
name|GHWCFG2_NPTXQDEPTH_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|GHWCFG2_NPTXQDEPTH_MASK
value|0x00c00000
end_define

begin_define
define|#
directive|define
name|GHWCFG2_MPI
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|GHWCFG2_DYNFIFOSIZING
value|(1<<19)
end_define

begin_define
define|#
directive|define
name|GHWCFG2_PERIOSUPPORT
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|GHWCFG2_NUMHSTCHNL_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|GHWCFG2_NUMHSTCHNL_MASK
value|0x0003c000
end_define

begin_define
define|#
directive|define
name|GHWCFG2_NUMHSTCHNL_GET
parameter_list|(
name|x
parameter_list|)
value|((((x)>> 14)& 15) + 1)
end_define

begin_define
define|#
directive|define
name|GHWCFG2_NUMDEVEPS_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|GHWCFG2_NUMDEVEPS_MASK
value|0x00003c00
end_define

begin_define
define|#
directive|define
name|GHWCFG2_NUMDEVEPS_GET
parameter_list|(
name|x
parameter_list|)
value|((((x)>> 10)& 15) + 1)
end_define

begin_define
define|#
directive|define
name|GHWCFG2_FSPHYTYPE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|GHWCFG2_FSPHYTYPE_MASK
value|0x00000300
end_define

begin_define
define|#
directive|define
name|GHWCFG2_HSPHYTYPE_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|GHWCFG2_HSPHYTYPE_MASK
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|GHWCFG2_SINGPNT
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|GHWCFG2_OTGARCH_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|GHWCFG2_OTGARCH_MASK
value|0x00000018
end_define

begin_define
define|#
directive|define
name|GHWCFG2_OTGMODE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GHWCFG2_OTGMODE_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|GHWCFG3_DFIFODEPTH_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|GHWCFG3_DFIFODEPTH_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|GHWCFG3_DFIFODEPTH_GET
parameter_list|(
name|x
parameter_list|)
value|((x)>> 16)
end_define

begin_define
define|#
directive|define
name|GHWCFG3_RSTTYPE
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|GHWCFG3_OPTFEATURE
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|GHWCFG3_VNDCTLSUPT
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|GHWCFG3_I2CINTSEL
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|GHWCFG3_OTGEN
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|GHWCFG3_PKTSIZEWIDTH_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|GHWCFG3_PKTSIZEWIDTH_MASK
value|0x00000070
end_define

begin_define
define|#
directive|define
name|GHWCFG3_PKTSIZE_GET
parameter_list|(
name|x
parameter_list|)
value|(0x10<<(((x)>> 4)& 7))
end_define

begin_define
define|#
directive|define
name|GHWCFG3_XFERSIZEWIDTH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GHWCFG3_XFERSIZEWIDTH_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|GHWCFG3_XFRRSIZE_GET
parameter_list|(
name|x
parameter_list|)
value|(0x400<<(((x)>> 0)& 15))
end_define

begin_define
define|#
directive|define
name|GHWCFG4_NUM_IN_EP_GET
parameter_list|(
name|x
parameter_list|)
value|((((x)>> 26)& 15) + 1)
end_define

begin_define
define|#
directive|define
name|GHWCFG4_SESSENDFLTR
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|GHWCFG4_BVALIDFLTR
value|(1<<23)
end_define

begin_define
define|#
directive|define
name|GHWCFG4_AVALIDFLTR
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|GHWCFG4_VBUSVALIDFLTR
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|GHWCFG4_IDDGFLTR
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|GHWCFG4_NUMCTLEPS_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|GHWCFG4_NUMCTLEPS_MASK
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|GHWCFG4_NUMCTLEPS_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 15)
end_define

begin_define
define|#
directive|define
name|GHWCFG4_PHYDATAWIDTH_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|GHWCFG4_PHYDATAWIDTH_MASK
value|0x0000c000
end_define

begin_define
define|#
directive|define
name|GHWCFG4_AHBFREQ
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|GHWCFG4_ENABLEPWROPT
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|GHWCFG4_NUMDEVPERIOEPS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GHWCFG4_NUMDEVPERIOEPS_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|GHWCFG4_NUMDEVPERIOEPS_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 15)
end_define

begin_define
define|#
directive|define
name|GLPMCFG_HSIC_CONN
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|GPWRDN_BVALID
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|GPWRDN_IDDIG
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|GPWRDN_CONNDET_INT
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|GPWRDN_CONNDET
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|GPWRDN_DISCONN_INT
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|GPWRDN_DISCONN
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|GPWRDN_RESETDET_INT
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|GPWRDN_RESETDET
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|GPWRDN_LINESTATE_INT
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|GPWRDN_LINESTATE
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|GPWRDN_DISABLE_VBUS
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|GPWRDN_POWER_DOWN
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|GPWRDN_POWER_DOWN_RST
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|GPWRDN_POWER_DOWN_CLAMP
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|GPWRDN_RESTORE
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|GPWRDN_PMU_ACTIVE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|GPWRDN_PMU_IRQ_SEL
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|HPTXFSIZ_PTXFSIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HPTXFSIZ_PTXFSIZE_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|HPTXFSIZ_PTXFSTADDR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HPTXFSIZ_PTXFSTADDR_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|DPTXFSIZN_DPTXFSIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|DPTXFSIZN_DPTXFSIZE_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|DPTXFSIZN_PTXFSTADDR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DPTXFSIZN_PTXFSTADDR_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|DIEPTXFN_INEPNTXFDEP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|DIEPTXFN_INEPNTXFDEP_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|DIEPTXFN_INEPNTXFSTADDR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DIEPTXFN_INEPNTXFSTADDR_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|HCFG_MODECHANGERDY
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|HCFG_PERSCHEDENABLE
value|(1<<26)
end_define

begin_define
define|#
directive|define
name|HCFG_FLENTRIES_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|HCFG_FLENTRIES_MASK
value|0x03000000
end_define

begin_define
define|#
directive|define
name|HCFG_FLENTRIES_8
value|(0)
end_define

begin_define
define|#
directive|define
name|HCFG_FLENTRIES_16
value|(1)
end_define

begin_define
define|#
directive|define
name|HCFG_FLENTRIES_32
value|(2)
end_define

begin_define
define|#
directive|define
name|HCFG_FLENTRIES_64
value|(3)
end_define

begin_define
define|#
directive|define
name|HCFG_MULTISEGDMA
value|(1<<23)
end_define

begin_define
define|#
directive|define
name|HCFG_32KHZSUSPEND
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|HCFG_FSLSSUPP
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|HCFG_FSLSPCLKSEL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HCFG_FSLSPCLKSEL_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|HFIR_RELOADCTRL
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|HFIR_FRINT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HFIR_FRINT_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|HFNUM_FRREM_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HFNUM_FRREM_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|HFNUM_FRNUM_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HFNUM_FRNUM_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|HPTXSTS_ODD
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|HPTXSTS_CHAN_SHIFT
value|27
end_define

begin_define
define|#
directive|define
name|HPTXSTS_CHAN_MASK
value|0x78000000
end_define

begin_define
define|#
directive|define
name|HPTXSTS_TOKEN_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|HPTXSTS_TOKEN_MASK
value|0x06000000
end_define

begin_define
define|#
directive|define
name|HPTXSTS_TOKEN_ZL
value|0
end_define

begin_define
define|#
directive|define
name|HPTXSTS_TOKEN_PING
value|1
end_define

begin_define
define|#
directive|define
name|HPTXSTS_TOKEN_DISABLE
value|2
end_define

begin_define
define|#
directive|define
name|HPTXSTS_TERMINATE
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|HPTXSTS_PTXQSPCAVAIL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HPTXSTS_PTXQSPCAVAIL_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|HPTXSTS_PTXFSPCAVAIL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HPTXSTS_PTXFSPCAVAIL_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|HAINT_HAINT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HAINT_HAINT_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|HAINTMSK_HAINTMSK_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HAINTMSK_HAINTMSK_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|HPRT_PRTSPD_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|HPRT_PRTSPD_MASK
value|0x00060000
end_define

begin_define
define|#
directive|define
name|HPRT_PRTSPD_HIGH
value|0
end_define

begin_define
define|#
directive|define
name|HPRT_PRTSPD_FULL
value|1
end_define

begin_define
define|#
directive|define
name|HPRT_PRTSPD_LOW
value|2
end_define

begin_define
define|#
directive|define
name|HPRT_PRTSPD_MASK
value|0x00060000
end_define

begin_define
define|#
directive|define
name|HPRT_PRTTSTCTL_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|HPRT_PRTTSTCTL_MASK
value|0x0001e000
end_define

begin_define
define|#
directive|define
name|HPRT_PRTPWR
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|HPRT_PRTLNSTS_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|HPRT_PRTLNSTS_MASK
value|0x00000c00
end_define

begin_define
define|#
directive|define
name|HPRT_PRTRST
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|HPRT_PRTSUSP
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|HPRT_PRTRES
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|HPRT_PRTOVRCURRCHNG
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|HPRT_PRTOVRCURRACT
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|HPRT_PRTENCHNG
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|HPRT_PRTENA
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|HPRT_PRTCONNDET
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|HPRT_PRTCONNSTS
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|HCCHAR_CHENA
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|HCCHAR_CHDIS
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|HCCHAR_ODDFRM
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|HCCHAR_DEVADDR_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|HCCHAR_DEVADDR_MASK
value|0x1fc00000
end_define

begin_define
define|#
directive|define
name|HCCHAR_MC_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|HCCHAR_MC_MASK
value|0x00300000
end_define

begin_define
define|#
directive|define
name|HCCHAR_EPTYPE_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|HCCHAR_EPTYPE_MASK
value|0x000c0000
end_define

begin_define
define|#
directive|define
name|HCCHAR_LSPDDEV
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|HCCHAR_EPDIR
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|HCCHAR_EPDIR_IN
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|HCCHAR_EPDIR_OUT
value|0
end_define

begin_define
define|#
directive|define
name|HCCHAR_EPNUM_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|HCCHAR_EPNUM_MASK
value|0x00007800
end_define

begin_define
define|#
directive|define
name|HCCHAR_MPS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HCCHAR_MPS_MASK
value|0x000007ff
end_define

begin_define
define|#
directive|define
name|HCSPLT_SPLTENA
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|HCSPLT_COMPSPLT
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|HCSPLT_XACTPOS_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|HCSPLT_XACTPOS_MASK
value|0x0000c000
end_define

begin_define
define|#
directive|define
name|HCSPLT_XACTPOS_MIDDLE
value|0
end_define

begin_define
define|#
directive|define
name|HCSPLT_XACTPOS_LAST
value|1
end_define

begin_define
define|#
directive|define
name|HCSPLT_XACTPOS_BEGIN
value|2
end_define

begin_define
define|#
directive|define
name|HCSPLT_XACTPOS_ALL
value|3
end_define

begin_define
define|#
directive|define
name|HCSPLT_XACTLEN_BURST
value|1023
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|HCSPLT_HUBADDR_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|HCSPLT_HUBADDR_MASK
value|0x00003f80
end_define

begin_define
define|#
directive|define
name|HCSPLT_PRTADDR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HCSPLT_PRTADDR_MASK
value|0x0000007f
end_define

begin_define
define|#
directive|define
name|HCINT_ERRORS
define|\
value|(HCINT_BBLERR | HCINT_XACTERR)
end_define

begin_define
define|#
directive|define
name|HCINT_RETRY
define|\
value|(HCINT_DATATGLERR | HCINT_FRMOVRUN | HCINT_NAK)
end_define

begin_define
define|#
directive|define
name|HCINT_DEFAULT_MASK
define|\
value|(HCINT_STALL | HCINT_BBLERR | \    HCINT_XACTERR | HCINT_NAK | HCINT_ACK | HCINT_NYET | \    HCINT_CHHLTD | HCINT_FRMOVRUN | \    HCINT_DATATGLERR)
end_define

begin_define
define|#
directive|define
name|HCINT_HCH_DONE_MASK
define|\
value|(HCINT_ACK | HCINT_RETRY | HCINT_NYET | \    HCINT_ERRORS | HCINT_STALL | HCINT_SOFTWARE_ONLY)
end_define

begin_define
define|#
directive|define
name|HCINT_SOFTWARE_ONLY
value|(1<<20)
end_define

begin_comment
comment|/* BSD only */
end_comment

begin_define
define|#
directive|define
name|HCINT_DATATGLERR
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|HCINT_FRMOVRUN
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|HCINT_BBLERR
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|HCINT_XACTERR
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|HCINT_NYET
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|HCINT_ACK
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|HCINT_NAK
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|HCINT_STALL
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|HCINT_AHBERR
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|HCINT_CHHLTD
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|HCINT_XFERCOMPL
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|HCINTMSK_DATATGLERRMSK
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|HCINTMSK_FRMOVRUNMSK
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|HCINTMSK_BBLERRMSK
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|HCINTMSK_XACTERRMSK
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|HCINTMSK_NYETMSK
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|HCINTMSK_ACKMSK
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|HCINTMSK_NAKMSK
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|HCINTMSK_STALLMSK
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|HCINTMSK_AHBERRMSK
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|HCINTMSK_CHHLTDMSK
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|HCINTMSK_XFERCOMPLMSK
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|HCTSIZ_DOPNG
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|HCTSIZ_PID_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|HCTSIZ_PID_MASK
value|0x60000000
end_define

begin_define
define|#
directive|define
name|HCTSIZ_PID_DATA0
value|0
end_define

begin_define
define|#
directive|define
name|HCTSIZ_PID_DATA2
value|1
end_define

begin_define
define|#
directive|define
name|HCTSIZ_PID_DATA1
value|2
end_define

begin_define
define|#
directive|define
name|HCTSIZ_PID_MDATA
value|3
end_define

begin_define
define|#
directive|define
name|HCTSIZ_PID_SETUP
value|3
end_define

begin_define
define|#
directive|define
name|HCTSIZ_PKTCNT_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|HCTSIZ_PKTCNT_MASK
value|0x1ff80000
end_define

begin_define
define|#
directive|define
name|HCTSIZ_XFERSIZE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HCTSIZ_XFERSIZE_MASK
value|0x0007ffff
end_define

begin_define
define|#
directive|define
name|DCFG_EPMISCNT_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|DCFG_EPMISCNT_MASK
value|0x007c0000
end_define

begin_define
define|#
directive|define
name|DCFG_PERFRINT_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|DCFG_PERFRINT_MASK
value|0x00001800
end_define

begin_define
define|#
directive|define
name|DCFG_DEVADDR_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|DCFG_DEVADDR_MASK
value|0x000007f0
end_define

begin_define
define|#
directive|define
name|DCFG_DEVADDR_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7F)<< 4)
end_define

begin_define
define|#
directive|define
name|DCFG_NZSTSOUTHSHK
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|DCFG_DEVSPD_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DCFG_DEVSPD_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|DCFG_DEVSPD_SET
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x3)
end_define

begin_define
define|#
directive|define
name|DCFG_DEVSPD_HI
value|0
end_define

begin_define
define|#
directive|define
name|DCFG_DEVSPD_FULL20
value|1
end_define

begin_define
define|#
directive|define
name|DCFG_DEVSPD_FULL10
value|3
end_define

begin_define
define|#
directive|define
name|DCTL_PWRONPRGDONE
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|DCTL_CGOUTNAK
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|DCTL_SGOUTNAK
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|DCTL_CGNPINNAK
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|DCTL_SGNPINNAK
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|DCTL_TSTCTL_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|DCTL_TSTCTL_MASK
value|0x00000070
end_define

begin_define
define|#
directive|define
name|DCTL_GOUTNAKSTS
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|DCTL_GNPINNAKSTS
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|DCTL_SFTDISCON
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|DCTL_RMTWKUPSIG
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|DSTS_SOFFN_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|DSTS_SOFFN_MASK
value|0x003fff00
end_define

begin_define
define|#
directive|define
name|DSTS_SOFFN_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x3FFF)
end_define

begin_define
define|#
directive|define
name|DSTS_ERRTICERR
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|DSTS_ENUMSPD_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|DSTS_ENUMSPD_MASK
value|0x00000006
end_define

begin_define
define|#
directive|define
name|DSTS_ENUMSPD_GET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 3)
end_define

begin_define
define|#
directive|define
name|DSTS_ENUMSPD_HI
value|0
end_define

begin_define
define|#
directive|define
name|DSTS_ENUMSPD_FULL20
value|1
end_define

begin_define
define|#
directive|define
name|DSTS_ENUMSPD_LOW10
value|2
end_define

begin_define
define|#
directive|define
name|DSTS_ENUMSPD_FULL10
value|3
end_define

begin_define
define|#
directive|define
name|DSTS_SUSPSTS
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|DIEPMSK_TXFIFOUNDRNMSK
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|DIEPMSK_INEPNAKEFFMSK
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|DIEPMSK_INTKNEPMISMSK
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|DIEPMSK_INTKNTXFEMPMSK
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|DIEPMSK_FIFOEMPTY
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|DIEPMSK_TIMEOUTMSK
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|DIEPMSK_AHBERRMSK
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|DIEPMSK_EPDISBLDMSK
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|DIEPMSK_XFERCOMPLMSK
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|DOEPMSK_OUTPKTERRMSK
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|DOEPMSK_BACK2BACKSETUP
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|DOEPMSK_OUTTKNEPDISMSK
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|DOEPMSK_FIFOEMPTY
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|DOEPMSK_SETUPMSK
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|DOEPMSK_AHBERRMSK
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|DOEPMSK_EPDISBLDMSK
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|DOEPMSK_XFERCOMPLMSK
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|DIEPINT_TXFIFOUNDRN
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|DIEPINT_INEPNAKEFF
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|DIEPINT_INTKNEPMIS
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|DIEPINT_INTKNTXFEMP
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|DIEPINT_TIMEOUT
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|DIEPINT_AHBERR
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|DIEPINT_EPDISBLD
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|DIEPINT_XFERCOMPL
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|DOEPINT_OUTPKTERR
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|DOEPINT_BACK2BACKSETUP
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|DOEPINT_OUTTKNEPDIS
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|DOEPINT_SETUP
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|DOEPINT_AHBERR
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|DOEPINT_EPDISBLD
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|DOEPINT_XFERCOMPL
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|DAINT_INEPINT_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|DAINT_INEPINT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DAINT_OUTEPINT_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|DAINT_OUTEPINT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|DAINTMSK_INEPINT_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|DAINTMSK_INEPINT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DAINTMSK_OUTEPINT_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|DAINTMSK_OUTEPINT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|DTKNQR1_EPTKN_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|DTKNQR1_EPTKN_MASK
value|0xffffff00
end_define

begin_define
define|#
directive|define
name|DTKNQR1_WRAPBIT
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|DTKNQR1_INTKNWPTR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DTKNQR1_INTKNWPTR_MASK
value|0x0000001f
end_define

begin_define
define|#
directive|define
name|DVBUSDIS_DVBUSDIS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DVBUSDIS_DVBUSDIS_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|DVBUSPULSE_DVBUSPULSE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DVBUSPULSE_DVBUSPULSE_MASK
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|DTHRCTL_ARBPRKEN
value|(1<<27)
end_define

begin_define
define|#
directive|define
name|DTHRCTL_RXTHRLEN_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|DTHRCTL_RXTHRLEN_MASK
value|0x03fe0000
end_define

begin_define
define|#
directive|define
name|DTHRCTL_RXTHREN
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|DTHRCTL_TXTHRLEN_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|DTHRCTL_TXTHRLEN_MASK
value|0x000007fc
end_define

begin_define
define|#
directive|define
name|DTHRCTL_ISOTHREN
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|DTHRCTL_NONISOTHREN
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|DIEPEMPMSK_INEPTXFEMPMSK_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DIEPEMPMSK_INEPTXFEMPMSK_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|DIEPCTL_EPENA
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|DIEPCTL_EPDIS
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|DIEPCTL_SETD1PID
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|DIEPCTL_SETD0PID
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|DIEPCTL_SNAK
value|(1<<27)
end_define

begin_define
define|#
directive|define
name|DIEPCTL_CNAK
value|(1<<26)
end_define

begin_define
define|#
directive|define
name|DIEPCTL_TXFNUM_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|DIEPCTL_TXFNUM_MASK
value|0x03c00000
end_define

begin_define
define|#
directive|define
name|DIEPCTL_TXFNUM_SET
parameter_list|(
name|n
parameter_list|)
value|(((n)& 15)<< 22)
end_define

begin_define
define|#
directive|define
name|DIEPCTL_STALL
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|DIEPCTL_EPTYPE_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|DIEPCTL_EPTYPE_MASK
value|0x000c0000
end_define

begin_define
define|#
directive|define
name|DIEPCTL_EPTYPE_SET
parameter_list|(
name|n
parameter_list|)
value|(((n)& 3)<< 18)
end_define

begin_define
define|#
directive|define
name|DIEPCTL_EPTYPE_CONTROL
value|0
end_define

begin_define
define|#
directive|define
name|DIEPCTL_EPTYPE_ISOC
value|1
end_define

begin_define
define|#
directive|define
name|DIEPCTL_EPTYPE_BULK
value|2
end_define

begin_define
define|#
directive|define
name|DIEPCTL_EPTYPE_INTERRUPT
value|3
end_define

begin_define
define|#
directive|define
name|DIEPCTL_NAKSTS
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|DIEPCTL_USBACTEP
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|DIEPCTL_NEXTEP_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|DIEPCTL_NEXTEP_MASK
value|0x00007800
end_define

begin_define
define|#
directive|define
name|DIEPCTL_MPS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DIEPCTL_MPS_MASK
value|0x000007ff
end_define

begin_define
define|#
directive|define
name|DIEPCTL_MPS_SET
parameter_list|(
name|n
parameter_list|)
value|((n)& 0x7FF)
end_define

begin_define
define|#
directive|define
name|DIEPCTL_MPS_64
value|(0<<0)
end_define

begin_define
define|#
directive|define
name|DIEPCTL_MPS_32
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|DIEPCTL_MPS_16
value|(2<<0)
end_define

begin_define
define|#
directive|define
name|DIEPCTL_MPS_8
value|(3<<0)
end_define

begin_define
define|#
directive|define
name|DOEPCTL_EPENA
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|DOEPCTL_EPDIS
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|DOEPCTL_SETD1PID
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|DOEPCTL_SETD0PID
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|DOEPCTL_SNAK
value|(1<<27)
end_define

begin_define
define|#
directive|define
name|DOEPCTL_CNAK
value|(1<<26)
end_define

begin_define
define|#
directive|define
name|DOEPCTL_FNUM_SET
parameter_list|(
name|n
parameter_list|)
value|(((n)& 15)<< 22)
end_define

begin_define
define|#
directive|define
name|DOEPCTL_STALL
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|DOEPCTL_EPTYPE_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|DOEPCTL_EPTYPE_MASK
value|0x000c0000
end_define

begin_define
define|#
directive|define
name|DOEPCTL_EPTYPE_SET
parameter_list|(
name|n
parameter_list|)
value|(((n)& 3)<< 18)
end_define

begin_define
define|#
directive|define
name|DOEPCTL_NAKSTS
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|DOEPCTL_USBACTEP
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|DOEPCTL_MPS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DOEPCTL_MPS_MASK
value|0x000007ff
end_define

begin_define
define|#
directive|define
name|DOEPCTL_MPS_SET
parameter_list|(
name|n
parameter_list|)
value|((n)& 0x7FF)
end_define

begin_define
define|#
directive|define
name|DOEPCTL_MPS_64
value|(0<<0)
end_define

begin_define
define|#
directive|define
name|DOEPCTL_MPS_32
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|DOEPCTL_MPS_16
value|(2<<0)
end_define

begin_define
define|#
directive|define
name|DOEPCTL_MPS_8
value|(3<<0)
end_define

begin_comment
comment|/* common bits */
end_comment

begin_define
define|#
directive|define
name|DXEPINT_TXFEMP
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|DXEPINT_SETUP
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|DXEPINT_XFER_COMPL
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|DIEPTSIZ_XFERSIZE_MASK
value|0x0007ffff
end_define

begin_define
define|#
directive|define
name|DIEPTSIZ_XFERSIZE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DIEPTSIZ_PKTCNT_MASK
value|0x1ff80000
end_define

begin_define
define|#
directive|define
name|DIEPTSIZ_PKTCNT_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|DIEPTSIZ_MC_MASK
value|0x60000000
end_define

begin_define
define|#
directive|define
name|DIEPTSIZ_MC_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|DOEPTSIZ_XFERSIZE_MASK
value|0x0007ffff
end_define

begin_define
define|#
directive|define
name|DOEPTSIZ_XFERSIZE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DOEPTSIZ_PKTCNT_MASK
value|0x1ff80000
end_define

begin_define
define|#
directive|define
name|DOEPTSIZ_PKTCNT_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|DOEPTSIZ_MC_MASK
value|0x60000000
end_define

begin_define
define|#
directive|define
name|DOEPTSIZ_MC_SHIFT
value|29
end_define

begin_comment
comment|/* common bits */
end_comment

begin_define
define|#
directive|define
name|DXEPTSIZ_SET_MULTI
parameter_list|(
name|n
parameter_list|)
value|(((n)& 3)<< 29)
end_define

begin_define
define|#
directive|define
name|DXEPTSIZ_SET_NPKT
parameter_list|(
name|n
parameter_list|)
value|(((n)& 0x3FF)<< 19)
end_define

begin_define
define|#
directive|define
name|DXEPTSIZ_GET_NPKT
parameter_list|(
name|n
parameter_list|)
value|(((n)>> 19)& 0x3FF)
end_define

begin_define
define|#
directive|define
name|DXEPTSIZ_SET_NBYTES
parameter_list|(
name|n
parameter_list|)
value|(((n)& 0x7FFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|DXEPTSIZ_GET_NBYTES
parameter_list|(
name|n
parameter_list|)
value|(((n)>> 0)& 0x7FFFFF)
end_define

begin_comment
comment|/* generic endpoint mask */
end_comment

begin_define
define|#
directive|define
name|ENDPOINT_MASK
parameter_list|(
name|x
parameter_list|,
name|in
parameter_list|)
define|\
value|((in) ? (1U<< ((x)& 15U)) : \ 	 (0x10000U<< ((x)& 15U)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DWC_OTGREG_H_ */
end_comment

end_unit

