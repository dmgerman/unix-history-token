begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__SOUND_EMU10K1_H
end_ifndef

begin_define
define|#
directive|define
name|__SOUND_EMU10K1_H
end_define

begin_comment
comment|/*  *  Copyright (c) by Jaroslav Kysela<perex@suse.cz>,  *		     Creative Labs, Inc.  *  Definitions for EMU10K1 (SB Live!) chips  *  *  *   This program is free software; you can redistribute it and/or modify  *   it under the terms of the GNU General Public License as published by  *   the Free Software Foundation; either version 2 of the License, or  *   (at your option) any later version.  *  *   This program is distributed in the hope that it will be useful,  *   but WITHOUT ANY WARRANTY; without even the implied warranty of  *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  *   GNU General Public License for more details.  *  *   You should have received a copy of the GNU General Public License  *   along with this program; if not, write to the Free Software  *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_include
include|#
directive|include
file|<sound/pcm.h>
end_include

begin_include
include|#
directive|include
file|<sound/rawmidi.h>
end_include

begin_include
include|#
directive|include
file|<sound/hwdep.h>
end_include

begin_include
include|#
directive|include
file|<sound/ac97_codec.h>
end_include

begin_include
include|#
directive|include
file|<sound/util_mem.h>
end_include

begin_include
include|#
directive|include
file|<linux/interrupt.h>
end_include

begin_include
include|#
directive|include
file|<asm/io.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_VENDOR_ID_CREATIVE
end_ifndef

begin_define
define|#
directive|define
name|PCI_VENDOR_ID_CREATIVE
value|0x1102
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_DEVICE_ID_CREATIVE_EMU10K1
end_ifndef

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_CREATIVE_EMU10K1
value|0x0002
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ------------------- DEFINES -------------------- */
end_comment

begin_define
define|#
directive|define
name|EMUPAGESIZE
value|4096
end_define

begin_define
define|#
directive|define
name|MAXREQVOICES
value|8
end_define

begin_define
define|#
directive|define
name|MAXPAGES
value|8192
end_define

begin_define
define|#
directive|define
name|RESERVED
value|0
end_define

begin_define
define|#
directive|define
name|NUM_MIDI
value|16
end_define

begin_define
define|#
directive|define
name|NUM_G
value|64
end_define

begin_comment
comment|/* use all channels */
end_comment

begin_define
define|#
directive|define
name|NUM_FXSENDS
value|4
end_define

begin_define
define|#
directive|define
name|EMU10K1_DMA_MASK
value|0x7fffffffUL
end_define

begin_comment
comment|/* 31bit */
end_comment

begin_define
define|#
directive|define
name|AUDIGY_DMA_MASK
value|0xffffffffUL
end_define

begin_comment
comment|/* 32bit */
end_comment

begin_define
define|#
directive|define
name|TMEMSIZE
value|256*1024
end_define

begin_define
define|#
directive|define
name|TMEMSIZEREG
value|4
end_define

begin_define
define|#
directive|define
name|IP_TO_CP
parameter_list|(
name|ip
parameter_list|)
value|((ip == 0) ? 0 : (((0x00001000uL | (ip& 0x00000FFFL))<< (((ip>> 12)& 0x000FL) + 4))& 0xFFFF0000uL))
end_define

begin_comment
comment|// Audigy specify registers are prefixed with 'A_'
end_comment

begin_comment
comment|/************************************************************************************************/
end_comment

begin_comment
comment|/* PCI function 0 registers, address =<val> + PCIBASE0						*/
end_comment

begin_comment
comment|/************************************************************************************************/
end_comment

begin_define
define|#
directive|define
name|PTR
value|0x00
end_define

begin_comment
comment|/* Indexed register set pointer register	*/
end_comment

begin_comment
comment|/* NOTE: The CHANNELNUM and ADDRESS words can	*/
end_comment

begin_comment
comment|/* be modified independently of each other.	*/
end_comment

begin_define
define|#
directive|define
name|PTR_CHANNELNUM_MASK
value|0x0000003f
end_define

begin_comment
comment|/* For each per-channel register, indicates the	*/
end_comment

begin_comment
comment|/* channel number of the register to be		*/
end_comment

begin_comment
comment|/* accessed.  For non per-channel registers the	*/
end_comment

begin_comment
comment|/* value should be set to zero.			*/
end_comment

begin_define
define|#
directive|define
name|PTR_ADDRESS_MASK
value|0x07ff0000
end_define

begin_comment
comment|/* Register index				*/
end_comment

begin_define
define|#
directive|define
name|A_PTR_ADDRESS_MASK
value|0x0fff0000
end_define

begin_define
define|#
directive|define
name|DATA
value|0x04
end_define

begin_comment
comment|/* Indexed register set data register		*/
end_comment

begin_define
define|#
directive|define
name|IPR
value|0x08
end_define

begin_comment
comment|/* Global interrupt pending register		*/
end_comment

begin_comment
comment|/* Clear pending interrupts by writing a 1 to	*/
end_comment

begin_comment
comment|/* the relevant bits and zero to the other bits	*/
end_comment

begin_comment
comment|/* The next two interrupts are for the midi port on the Audigy Drive (A_MPU1)			*/
end_comment

begin_define
define|#
directive|define
name|IPR_A_MIDITRANSBUFEMPTY2
value|0x10000000
end_define

begin_comment
comment|/* MIDI UART transmit buffer empty		*/
end_comment

begin_define
define|#
directive|define
name|IPR_A_MIDIRECVBUFEMPTY2
value|0x08000000
end_define

begin_comment
comment|/* MIDI UART receive buffer empty		*/
end_comment

begin_define
define|#
directive|define
name|IPR_SAMPLERATETRACKER
value|0x01000000
end_define

begin_comment
comment|/* Sample rate tracker lock status change	*/
end_comment

begin_define
define|#
directive|define
name|IPR_FXDSP
value|0x00800000
end_define

begin_comment
comment|/* Enable FX DSP interrupts			*/
end_comment

begin_define
define|#
directive|define
name|IPR_FORCEINT
value|0x00400000
end_define

begin_comment
comment|/* Force Sound Blaster interrupt		*/
end_comment

begin_define
define|#
directive|define
name|IPR_PCIERROR
value|0x00200000
end_define

begin_comment
comment|/* PCI bus error				*/
end_comment

begin_define
define|#
directive|define
name|IPR_VOLINCR
value|0x00100000
end_define

begin_comment
comment|/* Volume increment button pressed		*/
end_comment

begin_define
define|#
directive|define
name|IPR_VOLDECR
value|0x00080000
end_define

begin_comment
comment|/* Volume decrement button pressed		*/
end_comment

begin_define
define|#
directive|define
name|IPR_MUTE
value|0x00040000
end_define

begin_comment
comment|/* Mute button pressed				*/
end_comment

begin_define
define|#
directive|define
name|IPR_MICBUFFULL
value|0x00020000
end_define

begin_comment
comment|/* Microphone buffer full			*/
end_comment

begin_define
define|#
directive|define
name|IPR_MICBUFHALFFULL
value|0x00010000
end_define

begin_comment
comment|/* Microphone buffer half full			*/
end_comment

begin_define
define|#
directive|define
name|IPR_ADCBUFFULL
value|0x00008000
end_define

begin_comment
comment|/* ADC buffer full				*/
end_comment

begin_define
define|#
directive|define
name|IPR_ADCBUFHALFFULL
value|0x00004000
end_define

begin_comment
comment|/* ADC buffer half full				*/
end_comment

begin_define
define|#
directive|define
name|IPR_EFXBUFFULL
value|0x00002000
end_define

begin_comment
comment|/* Effects buffer full				*/
end_comment

begin_define
define|#
directive|define
name|IPR_EFXBUFHALFFULL
value|0x00001000
end_define

begin_comment
comment|/* Effects buffer half full			*/
end_comment

begin_define
define|#
directive|define
name|IPR_GPSPDIFSTATUSCHANGE
value|0x00000800
end_define

begin_comment
comment|/* GPSPDIF channel status change		*/
end_comment

begin_define
define|#
directive|define
name|IPR_CDROMSTATUSCHANGE
value|0x00000400
end_define

begin_comment
comment|/* CD-ROM channel status change			*/
end_comment

begin_define
define|#
directive|define
name|IPR_INTERVALTIMER
value|0x00000200
end_define

begin_comment
comment|/* Interval timer terminal count		*/
end_comment

begin_define
define|#
directive|define
name|IPR_MIDITRANSBUFEMPTY
value|0x00000100
end_define

begin_comment
comment|/* MIDI UART transmit buffer empty		*/
end_comment

begin_define
define|#
directive|define
name|IPR_MIDIRECVBUFEMPTY
value|0x00000080
end_define

begin_comment
comment|/* MIDI UART receive buffer empty		*/
end_comment

begin_define
define|#
directive|define
name|IPR_CHANNELLOOP
value|0x00000040
end_define

begin_comment
comment|/* One or more channel loop interrupts pending	*/
end_comment

begin_define
define|#
directive|define
name|IPR_CHANNELNUMBERMASK
value|0x0000003f
end_define

begin_comment
comment|/* When IPR_CHANNELLOOP is set, indicates the	*/
end_comment

begin_comment
comment|/* Highest set channel in CLIPL or CLIPH.  When	*/
end_comment

begin_comment
comment|/* IP is written with CL set, the bit in CLIPL	*/
end_comment

begin_comment
comment|/* or CLIPH corresponding to the CIN value 	*/
end_comment

begin_comment
comment|/* written will be cleared.			*/
end_comment

begin_define
define|#
directive|define
name|INTE
value|0x0c
end_define

begin_comment
comment|/* Interrupt enable register			*/
end_comment

begin_define
define|#
directive|define
name|INTE_VIRTUALSB_MASK
value|0xc0000000
end_define

begin_comment
comment|/* Virtual Soundblaster I/O port capture	*/
end_comment

begin_define
define|#
directive|define
name|INTE_VIRTUALSB_220
value|0x00000000
end_define

begin_comment
comment|/* Capture at I/O base address 0x220-0x22f	*/
end_comment

begin_define
define|#
directive|define
name|INTE_VIRTUALSB_240
value|0x40000000
end_define

begin_comment
comment|/* Capture at I/O base address 0x240		*/
end_comment

begin_define
define|#
directive|define
name|INTE_VIRTUALSB_260
value|0x80000000
end_define

begin_comment
comment|/* Capture at I/O base address 0x260		*/
end_comment

begin_define
define|#
directive|define
name|INTE_VIRTUALSB_280
value|0xc0000000
end_define

begin_comment
comment|/* Capture at I/O base address 0x280		*/
end_comment

begin_define
define|#
directive|define
name|INTE_VIRTUALMPU_MASK
value|0x30000000
end_define

begin_comment
comment|/* Virtual MPU I/O port capture			*/
end_comment

begin_define
define|#
directive|define
name|INTE_VIRTUALMPU_300
value|0x00000000
end_define

begin_comment
comment|/* Capture at I/O base address 0x300-0x301	*/
end_comment

begin_define
define|#
directive|define
name|INTE_VIRTUALMPU_310
value|0x10000000
end_define

begin_comment
comment|/* Capture at I/O base address 0x310		*/
end_comment

begin_define
define|#
directive|define
name|INTE_VIRTUALMPU_320
value|0x20000000
end_define

begin_comment
comment|/* Capture at I/O base address 0x320		*/
end_comment

begin_define
define|#
directive|define
name|INTE_VIRTUALMPU_330
value|0x30000000
end_define

begin_comment
comment|/* Capture at I/O base address 0x330		*/
end_comment

begin_define
define|#
directive|define
name|INTE_MASTERDMAENABLE
value|0x08000000
end_define

begin_comment
comment|/* Master DMA emulation at 0x000-0x00f		*/
end_comment

begin_define
define|#
directive|define
name|INTE_SLAVEDMAENABLE
value|0x04000000
end_define

begin_comment
comment|/* Slave DMA emulation at 0x0c0-0x0df		*/
end_comment

begin_define
define|#
directive|define
name|INTE_MASTERPICENABLE
value|0x02000000
end_define

begin_comment
comment|/* Master PIC emulation at 0x020-0x021		*/
end_comment

begin_define
define|#
directive|define
name|INTE_SLAVEPICENABLE
value|0x01000000
end_define

begin_comment
comment|/* Slave PIC emulation at 0x0a0-0x0a1		*/
end_comment

begin_define
define|#
directive|define
name|INTE_VSBENABLE
value|0x00800000
end_define

begin_comment
comment|/* Enable virtual Soundblaster			*/
end_comment

begin_define
define|#
directive|define
name|INTE_ADLIBENABLE
value|0x00400000
end_define

begin_comment
comment|/* Enable AdLib emulation at 0x388-0x38b	*/
end_comment

begin_define
define|#
directive|define
name|INTE_MPUENABLE
value|0x00200000
end_define

begin_comment
comment|/* Enable virtual MPU				*/
end_comment

begin_define
define|#
directive|define
name|INTE_FORCEINT
value|0x00100000
end_define

begin_comment
comment|/* Continuously assert INTAN			*/
end_comment

begin_define
define|#
directive|define
name|INTE_MRHANDENABLE
value|0x00080000
end_define

begin_comment
comment|/* Enable the "Mr. Hand" logic			*/
end_comment

begin_comment
comment|/* NOTE: There is no reason to use this under	*/
end_comment

begin_comment
comment|/* Linux, and it will cause odd hardware 	*/
end_comment

begin_comment
comment|/* behavior and possibly random segfaults and	*/
end_comment

begin_comment
comment|/* lockups if enabled.				*/
end_comment

begin_comment
comment|/* The next two interrupts are for the midi port on the Audigy Drive (A_MPU1)			*/
end_comment

begin_define
define|#
directive|define
name|INTE_A_MIDITXENABLE2
value|0x00020000
end_define

begin_comment
comment|/* Enable MIDI transmit-buffer-empty interrupts	*/
end_comment

begin_define
define|#
directive|define
name|INTE_A_MIDIRXENABLE2
value|0x00010000
end_define

begin_comment
comment|/* Enable MIDI receive-buffer-empty interrupts	*/
end_comment

begin_define
define|#
directive|define
name|INTE_SAMPLERATETRACKER
value|0x00002000
end_define

begin_comment
comment|/* Enable sample rate tracker interrupts	*/
end_comment

begin_comment
comment|/* NOTE: This bit must always be enabled       	*/
end_comment

begin_define
define|#
directive|define
name|INTE_FXDSPENABLE
value|0x00001000
end_define

begin_comment
comment|/* Enable FX DSP interrupts			*/
end_comment

begin_define
define|#
directive|define
name|INTE_PCIERRORENABLE
value|0x00000800
end_define

begin_comment
comment|/* Enable PCI bus error interrupts		*/
end_comment

begin_define
define|#
directive|define
name|INTE_VOLINCRENABLE
value|0x00000400
end_define

begin_comment
comment|/* Enable volume increment button interrupts	*/
end_comment

begin_define
define|#
directive|define
name|INTE_VOLDECRENABLE
value|0x00000200
end_define

begin_comment
comment|/* Enable volume decrement button interrupts	*/
end_comment

begin_define
define|#
directive|define
name|INTE_MUTEENABLE
value|0x00000100
end_define

begin_comment
comment|/* Enable mute button interrupts		*/
end_comment

begin_define
define|#
directive|define
name|INTE_MICBUFENABLE
value|0x00000080
end_define

begin_comment
comment|/* Enable microphone buffer interrupts		*/
end_comment

begin_define
define|#
directive|define
name|INTE_ADCBUFENABLE
value|0x00000040
end_define

begin_comment
comment|/* Enable ADC buffer interrupts			*/
end_comment

begin_define
define|#
directive|define
name|INTE_EFXBUFENABLE
value|0x00000020
end_define

begin_comment
comment|/* Enable Effects buffer interrupts		*/
end_comment

begin_define
define|#
directive|define
name|INTE_GPSPDIFENABLE
value|0x00000010
end_define

begin_comment
comment|/* Enable GPSPDIF status interrupts		*/
end_comment

begin_define
define|#
directive|define
name|INTE_CDSPDIFENABLE
value|0x00000008
end_define

begin_comment
comment|/* Enable CDSPDIF status interrupts		*/
end_comment

begin_define
define|#
directive|define
name|INTE_INTERVALTIMERENB
value|0x00000004
end_define

begin_comment
comment|/* Enable interval timer interrupts		*/
end_comment

begin_define
define|#
directive|define
name|INTE_MIDITXENABLE
value|0x00000002
end_define

begin_comment
comment|/* Enable MIDI transmit-buffer-empty interrupts	*/
end_comment

begin_define
define|#
directive|define
name|INTE_MIDIRXENABLE
value|0x00000001
end_define

begin_comment
comment|/* Enable MIDI receive-buffer-empty interrupts	*/
end_comment

begin_define
define|#
directive|define
name|WC
value|0x10
end_define

begin_comment
comment|/* Wall Clock register				*/
end_comment

begin_define
define|#
directive|define
name|WC_SAMPLECOUNTER_MASK
value|0x03FFFFC0
end_define

begin_comment
comment|/* Sample periods elapsed since reset		*/
end_comment

begin_define
define|#
directive|define
name|WC_SAMPLECOUNTER
value|0x14060010
end_define

begin_define
define|#
directive|define
name|WC_CURRENTCHANNEL
value|0x0000003F
end_define

begin_comment
comment|/* Channel [0..63] currently being serviced	*/
end_comment

begin_comment
comment|/* NOTE: Each channel takes 1/64th of a sample	*/
end_comment

begin_comment
comment|/* period to be serviced.			*/
end_comment

begin_define
define|#
directive|define
name|HCFG
value|0x14
end_define

begin_comment
comment|/* Hardware config register			*/
end_comment

begin_comment
comment|/* NOTE: There is no reason to use the legacy	*/
end_comment

begin_comment
comment|/* SoundBlaster emulation stuff described below	*/
end_comment

begin_comment
comment|/* under Linux, and all kinds of weird hardware	*/
end_comment

begin_comment
comment|/* behavior can result if you try.  Don't.	*/
end_comment

begin_define
define|#
directive|define
name|HCFG_LEGACYFUNC_MASK
value|0xe0000000
end_define

begin_comment
comment|/* Legacy function number 			*/
end_comment

begin_define
define|#
directive|define
name|HCFG_LEGACYFUNC_MPU
value|0x00000000
end_define

begin_comment
comment|/* Legacy MPU	 				*/
end_comment

begin_define
define|#
directive|define
name|HCFG_LEGACYFUNC_SB
value|0x40000000
end_define

begin_comment
comment|/* Legacy SB					*/
end_comment

begin_define
define|#
directive|define
name|HCFG_LEGACYFUNC_AD
value|0x60000000
end_define

begin_comment
comment|/* Legacy AD					*/
end_comment

begin_define
define|#
directive|define
name|HCFG_LEGACYFUNC_MPIC
value|0x80000000
end_define

begin_comment
comment|/* Legacy MPIC					*/
end_comment

begin_define
define|#
directive|define
name|HCFG_LEGACYFUNC_MDMA
value|0xa0000000
end_define

begin_comment
comment|/* Legacy MDMA					*/
end_comment

begin_define
define|#
directive|define
name|HCFG_LEGACYFUNC_SPCI
value|0xc0000000
end_define

begin_comment
comment|/* Legacy SPCI					*/
end_comment

begin_define
define|#
directive|define
name|HCFG_LEGACYFUNC_SDMA
value|0xe0000000
end_define

begin_comment
comment|/* Legacy SDMA					*/
end_comment

begin_define
define|#
directive|define
name|HCFG_IOCAPTUREADDR
value|0x1f000000
end_define

begin_comment
comment|/* The 4 LSBs of the captured I/O address.	*/
end_comment

begin_define
define|#
directive|define
name|HCFG_LEGACYWRITE
value|0x00800000
end_define

begin_comment
comment|/* 1 = write, 0 = read 				*/
end_comment

begin_define
define|#
directive|define
name|HCFG_LEGACYWORD
value|0x00400000
end_define

begin_comment
comment|/* 1 = word, 0 = byte 				*/
end_comment

begin_define
define|#
directive|define
name|HCFG_LEGACYINT
value|0x00200000
end_define

begin_comment
comment|/* 1 = legacy event captured. Write 1 to clear.	*/
end_comment

begin_comment
comment|/* NOTE: The rest of the bits in this register	*/
end_comment

begin_comment
comment|/* _are_ relevant under Linux.			*/
end_comment

begin_define
define|#
directive|define
name|HCFG_CODECFORMAT_MASK
value|0x00070000
end_define

begin_comment
comment|/* CODEC format					*/
end_comment

begin_define
define|#
directive|define
name|HCFG_CODECFORMAT_AC97
value|0x00000000
end_define

begin_comment
comment|/* AC97 CODEC format -- Primary Output		*/
end_comment

begin_define
define|#
directive|define
name|HCFG_CODECFORMAT_I2S
value|0x00010000
end_define

begin_comment
comment|/* I2S CODEC format -- Secondary (Rear) Output	*/
end_comment

begin_define
define|#
directive|define
name|HCFG_GPINPUT0
value|0x00004000
end_define

begin_comment
comment|/* External pin112				*/
end_comment

begin_define
define|#
directive|define
name|HCFG_GPINPUT1
value|0x00002000
end_define

begin_comment
comment|/* External pin110				*/
end_comment

begin_define
define|#
directive|define
name|HCFG_GPOUTPUT_MASK
value|0x00001c00
end_define

begin_comment
comment|/* External pins which may be controlled	*/
end_comment

begin_define
define|#
directive|define
name|HCFG_GPOUT0
value|0x00001000
end_define

begin_comment
comment|/* External pin? (spdif enable on 5.1)		*/
end_comment

begin_define
define|#
directive|define
name|HCFG_GPOUT1
value|0x00000800
end_define

begin_comment
comment|/* External pin? (IR)				*/
end_comment

begin_define
define|#
directive|define
name|HCFG_GPOUT2
value|0x00000400
end_define

begin_comment
comment|/* External pin? (IR)				*/
end_comment

begin_define
define|#
directive|define
name|HCFG_JOYENABLE
value|0x00000200
end_define

begin_comment
comment|/* Internal joystick enable    			*/
end_comment

begin_define
define|#
directive|define
name|HCFG_PHASETRACKENABLE
value|0x00000100
end_define

begin_comment
comment|/* Phase tracking enable			*/
end_comment

begin_comment
comment|/* 1 = Force all 3 async digital inputs to use	*/
end_comment

begin_comment
comment|/* the same async sample rate tracker (ZVIDEO)	*/
end_comment

begin_define
define|#
directive|define
name|HCFG_AC3ENABLE_MASK
value|0x000000e0
end_define

begin_comment
comment|/* AC3 async input control - Not implemented	*/
end_comment

begin_define
define|#
directive|define
name|HCFG_AC3ENABLE_ZVIDEO
value|0x00000080
end_define

begin_comment
comment|/* Channels 0 and 1 replace ZVIDEO		*/
end_comment

begin_define
define|#
directive|define
name|HCFG_AC3ENABLE_CDSPDIF
value|0x00000040
end_define

begin_comment
comment|/* Channels 0 and 1 replace CDSPDIF		*/
end_comment

begin_define
define|#
directive|define
name|HCFG_AC3ENABLE_GPSPDIF
value|0x00000020
end_define

begin_comment
comment|/* Channels 0 and 1 replace GPSPDIF             */
end_comment

begin_define
define|#
directive|define
name|HCFG_AUTOMUTE
value|0x00000010
end_define

begin_comment
comment|/* When set, the async sample rate convertors	*/
end_comment

begin_comment
comment|/* will automatically mute their output when	*/
end_comment

begin_comment
comment|/* they are not rate-locked to the external	*/
end_comment

begin_comment
comment|/* async audio source  				*/
end_comment

begin_define
define|#
directive|define
name|HCFG_LOCKSOUNDCACHE
value|0x00000008
end_define

begin_comment
comment|/* 1 = Cancel bustmaster accesses to soundcache */
end_comment

begin_comment
comment|/* NOTE: This should generally never be used.  	*/
end_comment

begin_define
define|#
directive|define
name|HCFG_LOCKTANKCACHE_MASK
value|0x00000004
end_define

begin_comment
comment|/* 1 = Cancel bustmaster accesses to tankcache	*/
end_comment

begin_comment
comment|/* NOTE: This should generally never be used.  	*/
end_comment

begin_define
define|#
directive|define
name|HCFG_LOCKTANKCACHE
value|0x01020014
end_define

begin_define
define|#
directive|define
name|HCFG_MUTEBUTTONENABLE
value|0x00000002
end_define

begin_comment
comment|/* 1 = Master mute button sets AUDIOENABLE = 0.	*/
end_comment

begin_comment
comment|/* NOTE: This is a 'cheap' way to implement a	*/
end_comment

begin_comment
comment|/* master mute function on the mute button, and	*/
end_comment

begin_comment
comment|/* in general should not be used unless a more	*/
end_comment

begin_comment
comment|/* sophisticated master mute function has not	*/
end_comment

begin_comment
comment|/* been written.       				*/
end_comment

begin_define
define|#
directive|define
name|HCFG_AUDIOENABLE
value|0x00000001
end_define

begin_comment
comment|/* 0 = CODECs transmit zero-valued samples	*/
end_comment

begin_comment
comment|/* Should be set to 1 when the EMU10K1 is	*/
end_comment

begin_comment
comment|/* completely initialized.			*/
end_comment

begin_comment
comment|//For Audigy, MPU port move to 0x70-0x74 ptr register
end_comment

begin_define
define|#
directive|define
name|MUDATA
value|0x18
end_define

begin_comment
comment|/* MPU401 data register (8 bits)       		*/
end_comment

begin_define
define|#
directive|define
name|MUCMD
value|0x19
end_define

begin_comment
comment|/* MPU401 command register (8 bits)    		*/
end_comment

begin_define
define|#
directive|define
name|MUCMD_RESET
value|0xff
end_define

begin_comment
comment|/* RESET command				*/
end_comment

begin_define
define|#
directive|define
name|MUCMD_ENTERUARTMODE
value|0x3f
end_define

begin_comment
comment|/* Enter_UART_mode command			*/
end_comment

begin_comment
comment|/* NOTE: All other commands are ignored		*/
end_comment

begin_define
define|#
directive|define
name|MUSTAT
value|MUCMD
end_define

begin_comment
comment|/* MPU401 status register (8 bits)     		*/
end_comment

begin_define
define|#
directive|define
name|MUSTAT_IRDYN
value|0x80
end_define

begin_comment
comment|/* 0 = MIDI data or command ACK			*/
end_comment

begin_define
define|#
directive|define
name|MUSTAT_ORDYN
value|0x40
end_define

begin_comment
comment|/* 0 = MUDATA can accept a command or data	*/
end_comment

begin_define
define|#
directive|define
name|A_IOCFG
value|0x18
end_define

begin_comment
comment|/* GPIO on Audigy card (16bits)			*/
end_comment

begin_define
define|#
directive|define
name|A_GPINPUT_MASK
value|0xff00
end_define

begin_define
define|#
directive|define
name|A_GPOUTPUT_MASK
value|0x00ff
end_define

begin_define
define|#
directive|define
name|A_IOCFG_GPOUT0
value|0x0044
end_define

begin_comment
comment|/* analog/digital? */
end_comment

begin_define
define|#
directive|define
name|A_IOCFG_GPOUT1
value|0x0002
end_define

begin_comment
comment|/* IR */
end_comment

begin_define
define|#
directive|define
name|A_IOCFG_GPOUT2
value|0x0001
end_define

begin_comment
comment|/* IR */
end_comment

begin_define
define|#
directive|define
name|TIMER
value|0x1a
end_define

begin_comment
comment|/* Timer terminal count register		*/
end_comment

begin_comment
comment|/* NOTE: After the rate is changed, a maximum	*/
end_comment

begin_comment
comment|/* of 1024 sample periods should be allowed	*/
end_comment

begin_comment
comment|/* before the new rate is guaranteed accurate.	*/
end_comment

begin_define
define|#
directive|define
name|TIMER_RATE_MASK
value|0x000003ff
end_define

begin_comment
comment|/* Timer interrupt rate in sample periods	*/
end_comment

begin_comment
comment|/* 0 == 1024 periods, [1..4] are not useful	*/
end_comment

begin_define
define|#
directive|define
name|TIMER_RATE
value|0x0a00001a
end_define

begin_define
define|#
directive|define
name|AC97DATA
value|0x1c
end_define

begin_comment
comment|/* AC97 register set data register (16 bit)	*/
end_comment

begin_define
define|#
directive|define
name|AC97ADDRESS
value|0x1e
end_define

begin_comment
comment|/* AC97 register set address register (8 bit)	*/
end_comment

begin_define
define|#
directive|define
name|AC97ADDRESS_READY
value|0x80
end_define

begin_comment
comment|/* Read-only bit, reflects CODEC READY signal	*/
end_comment

begin_define
define|#
directive|define
name|AC97ADDRESS_ADDRESS
value|0x7f
end_define

begin_comment
comment|/* Address of indexed AC97 register		*/
end_comment

begin_comment
comment|/************************************************************************************************/
end_comment

begin_comment
comment|/* PCI function 1 registers, address =<val> + PCIBASE1						*/
end_comment

begin_comment
comment|/************************************************************************************************/
end_comment

begin_define
define|#
directive|define
name|JOYSTICK1
value|0x00
end_define

begin_comment
comment|/* Analog joystick port register		*/
end_comment

begin_define
define|#
directive|define
name|JOYSTICK2
value|0x01
end_define

begin_comment
comment|/* Analog joystick port register		*/
end_comment

begin_define
define|#
directive|define
name|JOYSTICK3
value|0x02
end_define

begin_comment
comment|/* Analog joystick port register		*/
end_comment

begin_define
define|#
directive|define
name|JOYSTICK4
value|0x03
end_define

begin_comment
comment|/* Analog joystick port register		*/
end_comment

begin_define
define|#
directive|define
name|JOYSTICK5
value|0x04
end_define

begin_comment
comment|/* Analog joystick port register		*/
end_comment

begin_define
define|#
directive|define
name|JOYSTICK6
value|0x05
end_define

begin_comment
comment|/* Analog joystick port register		*/
end_comment

begin_define
define|#
directive|define
name|JOYSTICK7
value|0x06
end_define

begin_comment
comment|/* Analog joystick port register		*/
end_comment

begin_define
define|#
directive|define
name|JOYSTICK8
value|0x07
end_define

begin_comment
comment|/* Analog joystick port register		*/
end_comment

begin_comment
comment|/* When writing, any write causes JOYSTICK_COMPARATOR output enable to be pulsed on write.	*/
end_comment

begin_comment
comment|/* When reading, use these bitfields: */
end_comment

begin_define
define|#
directive|define
name|JOYSTICK_BUTTONS
value|0x0f
end_define

begin_comment
comment|/* Joystick button data				*/
end_comment

begin_define
define|#
directive|define
name|JOYSTICK_COMPARATOR
value|0xf0
end_define

begin_comment
comment|/* Joystick comparator data			*/
end_comment

begin_comment
comment|/********************************************************************************************************/
end_comment

begin_comment
comment|/* Emu10k1 pointer-offset register set, accessed through the PTR and DATA registers			*/
end_comment

begin_comment
comment|/********************************************************************************************************/
end_comment

begin_define
define|#
directive|define
name|CPF
value|0x00
end_define

begin_comment
comment|/* Current pitch and fraction register			*/
end_comment

begin_define
define|#
directive|define
name|CPF_CURRENTPITCH_MASK
value|0xffff0000
end_define

begin_comment
comment|/* Current pitch (linear, 0x4000 == unity pitch shift) 	*/
end_comment

begin_define
define|#
directive|define
name|CPF_CURRENTPITCH
value|0x10100000
end_define

begin_define
define|#
directive|define
name|CPF_STEREO_MASK
value|0x00008000
end_define

begin_comment
comment|/* 1 = Even channel interleave, odd channel locked	*/
end_comment

begin_define
define|#
directive|define
name|CPF_STOP_MASK
value|0x00004000
end_define

begin_comment
comment|/* 1 = Current pitch forced to 0			*/
end_comment

begin_define
define|#
directive|define
name|CPF_FRACADDRESS_MASK
value|0x00003fff
end_define

begin_comment
comment|/* Linear fractional address of the current channel	*/
end_comment

begin_define
define|#
directive|define
name|PTRX
value|0x01
end_define

begin_comment
comment|/* Pitch target and send A/B amounts register		*/
end_comment

begin_define
define|#
directive|define
name|PTRX_PITCHTARGET_MASK
value|0xffff0000
end_define

begin_comment
comment|/* Pitch target of specified channel			*/
end_comment

begin_define
define|#
directive|define
name|PTRX_PITCHTARGET
value|0x10100001
end_define

begin_define
define|#
directive|define
name|PTRX_FXSENDAMOUNT_A_MASK
value|0x0000ff00
end_define

begin_comment
comment|/* Linear level of channel output sent to FX send bus A	*/
end_comment

begin_define
define|#
directive|define
name|PTRX_FXSENDAMOUNT_A
value|0x08080001
end_define

begin_define
define|#
directive|define
name|PTRX_FXSENDAMOUNT_B_MASK
value|0x000000ff
end_define

begin_comment
comment|/* Linear level of channel output sent to FX send bus B	*/
end_comment

begin_define
define|#
directive|define
name|PTRX_FXSENDAMOUNT_B
value|0x08000001
end_define

begin_define
define|#
directive|define
name|CVCF
value|0x02
end_define

begin_comment
comment|/* Current volume and filter cutoff register		*/
end_comment

begin_define
define|#
directive|define
name|CVCF_CURRENTVOL_MASK
value|0xffff0000
end_define

begin_comment
comment|/* Current linear volume of specified channel		*/
end_comment

begin_define
define|#
directive|define
name|CVCF_CURRENTVOL
value|0x10100002
end_define

begin_define
define|#
directive|define
name|CVCF_CURRENTFILTER_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* Current filter cutoff frequency of specified channel	*/
end_comment

begin_define
define|#
directive|define
name|CVCF_CURRENTFILTER
value|0x10000002
end_define

begin_define
define|#
directive|define
name|VTFT
value|0x03
end_define

begin_comment
comment|/* Volume target and filter cutoff target register	*/
end_comment

begin_define
define|#
directive|define
name|VTFT_VOLUMETARGET_MASK
value|0xffff0000
end_define

begin_comment
comment|/* Volume target of specified channel			*/
end_comment

begin_define
define|#
directive|define
name|VTFT_VOLUMETARGET
value|0x10100003
end_define

begin_define
define|#
directive|define
name|VTFT_FILTERTARGET_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* Filter cutoff target of specified channel		*/
end_comment

begin_define
define|#
directive|define
name|VTFT_FILTERTARGET
value|0x10000003
end_define

begin_define
define|#
directive|define
name|Z1
value|0x05
end_define

begin_comment
comment|/* Filter delay memory 1 register			*/
end_comment

begin_define
define|#
directive|define
name|Z2
value|0x04
end_define

begin_comment
comment|/* Filter delay memory 2 register			*/
end_comment

begin_define
define|#
directive|define
name|PSST
value|0x06
end_define

begin_comment
comment|/* Send C amount and loop start address register	*/
end_comment

begin_define
define|#
directive|define
name|PSST_FXSENDAMOUNT_C_MASK
value|0xff000000
end_define

begin_comment
comment|/* Linear level of channel output sent to FX send bus C	*/
end_comment

begin_define
define|#
directive|define
name|PSST_FXSENDAMOUNT_C
value|0x08180006
end_define

begin_define
define|#
directive|define
name|PSST_LOOPSTARTADDR_MASK
value|0x00ffffff
end_define

begin_comment
comment|/* Loop start address of the specified channel		*/
end_comment

begin_define
define|#
directive|define
name|PSST_LOOPSTARTADDR
value|0x18000006
end_define

begin_define
define|#
directive|define
name|DSL
value|0x07
end_define

begin_comment
comment|/* Send D amount and loop start address register	*/
end_comment

begin_define
define|#
directive|define
name|DSL_FXSENDAMOUNT_D_MASK
value|0xff000000
end_define

begin_comment
comment|/* Linear level of channel output sent to FX send bus D	*/
end_comment

begin_define
define|#
directive|define
name|DSL_FXSENDAMOUNT_D
value|0x08180007
end_define

begin_define
define|#
directive|define
name|DSL_LOOPENDADDR_MASK
value|0x00ffffff
end_define

begin_comment
comment|/* Loop end address of the specified channel		*/
end_comment

begin_define
define|#
directive|define
name|DSL_LOOPENDADDR
value|0x18000007
end_define

begin_define
define|#
directive|define
name|CCCA
value|0x08
end_define

begin_comment
comment|/* Filter Q, interp. ROM, byte size, cur. addr register */
end_comment

begin_define
define|#
directive|define
name|CCCA_RESONANCE
value|0xf0000000
end_define

begin_comment
comment|/* Lowpass filter resonance (Q) height			*/
end_comment

begin_define
define|#
directive|define
name|CCCA_INTERPROMMASK
value|0x0e000000
end_define

begin_comment
comment|/* Selects passband of interpolation ROM		*/
end_comment

begin_comment
comment|/* 1 == full band, 7 == lowpass				*/
end_comment

begin_comment
comment|/* ROM 0 is used when pitch shifting downward or less	*/
end_comment

begin_comment
comment|/* then 3 semitones upward.  Increasingly higher ROM	*/
end_comment

begin_comment
comment|/* numbers are used, typically in steps of 3 semitones,	*/
end_comment

begin_comment
comment|/* as upward pitch shifting is performed.		*/
end_comment

begin_define
define|#
directive|define
name|CCCA_INTERPROM_0
value|0x00000000
end_define

begin_comment
comment|/* Select interpolation ROM 0				*/
end_comment

begin_define
define|#
directive|define
name|CCCA_INTERPROM_1
value|0x02000000
end_define

begin_comment
comment|/* Select interpolation ROM 1				*/
end_comment

begin_define
define|#
directive|define
name|CCCA_INTERPROM_2
value|0x04000000
end_define

begin_comment
comment|/* Select interpolation ROM 2				*/
end_comment

begin_define
define|#
directive|define
name|CCCA_INTERPROM_3
value|0x06000000
end_define

begin_comment
comment|/* Select interpolation ROM 3				*/
end_comment

begin_define
define|#
directive|define
name|CCCA_INTERPROM_4
value|0x08000000
end_define

begin_comment
comment|/* Select interpolation ROM 4				*/
end_comment

begin_define
define|#
directive|define
name|CCCA_INTERPROM_5
value|0x0a000000
end_define

begin_comment
comment|/* Select interpolation ROM 5				*/
end_comment

begin_define
define|#
directive|define
name|CCCA_INTERPROM_6
value|0x0c000000
end_define

begin_comment
comment|/* Select interpolation ROM 6				*/
end_comment

begin_define
define|#
directive|define
name|CCCA_INTERPROM_7
value|0x0e000000
end_define

begin_comment
comment|/* Select interpolation ROM 7				*/
end_comment

begin_define
define|#
directive|define
name|CCCA_8BITSELECT
value|0x01000000
end_define

begin_comment
comment|/* 1 = Sound memory for this channel uses 8-bit samples	*/
end_comment

begin_define
define|#
directive|define
name|CCCA_CURRADDR_MASK
value|0x00ffffff
end_define

begin_comment
comment|/* Current address of the selected channel		*/
end_comment

begin_define
define|#
directive|define
name|CCCA_CURRADDR
value|0x18000008
end_define

begin_define
define|#
directive|define
name|CCR
value|0x09
end_define

begin_comment
comment|/* Cache control register				*/
end_comment

begin_define
define|#
directive|define
name|CCR_CACHEINVALIDSIZE
value|0x07190009
end_define

begin_define
define|#
directive|define
name|CCR_CACHEINVALIDSIZE_MASK
value|0xfe000000
end_define

begin_comment
comment|/* Number of invalid samples cache for this channel    	*/
end_comment

begin_define
define|#
directive|define
name|CCR_CACHELOOPFLAG
value|0x01000000
end_define

begin_comment
comment|/* 1 = Cache has a loop service pending			*/
end_comment

begin_define
define|#
directive|define
name|CCR_INTERLEAVEDSAMPLES
value|0x00800000
end_define

begin_comment
comment|/* 1 = A cache service will fetch interleaved samples	*/
end_comment

begin_define
define|#
directive|define
name|CCR_WORDSIZEDSAMPLES
value|0x00400000
end_define

begin_comment
comment|/* 1 = A cache service will fetch word sized samples	*/
end_comment

begin_define
define|#
directive|define
name|CCR_READADDRESS
value|0x06100009
end_define

begin_define
define|#
directive|define
name|CCR_READADDRESS_MASK
value|0x003f0000
end_define

begin_comment
comment|/* Location of cache just beyond current cache service	*/
end_comment

begin_define
define|#
directive|define
name|CCR_LOOPINVALSIZE
value|0x0000fe00
end_define

begin_comment
comment|/* Number of invalid samples in cache prior to loop	*/
end_comment

begin_comment
comment|/* NOTE: This is valid only if CACHELOOPFLAG is set	*/
end_comment

begin_define
define|#
directive|define
name|CCR_LOOPFLAG
value|0x00000100
end_define

begin_comment
comment|/* Set for a single sample period when a loop occurs	*/
end_comment

begin_define
define|#
directive|define
name|CCR_CACHELOOPADDRHI
value|0x000000ff
end_define

begin_comment
comment|/* DSL_LOOPSTARTADDR's hi byte if CACHELOOPFLAG is set	*/
end_comment

begin_define
define|#
directive|define
name|CLP
value|0x0a
end_define

begin_comment
comment|/* Cache loop register (valid if CCR_CACHELOOPFLAG = 1) */
end_comment

begin_comment
comment|/* NOTE: This register is normally not used		*/
end_comment

begin_define
define|#
directive|define
name|CLP_CACHELOOPADDR
value|0x0000ffff
end_define

begin_comment
comment|/* Cache loop address (DSL_LOOPSTARTADDR [0..15])	*/
end_comment

begin_define
define|#
directive|define
name|FXRT
value|0x0b
end_define

begin_comment
comment|/* Effects send routing register			*/
end_comment

begin_comment
comment|/* NOTE: It is illegal to assign the same routing to	*/
end_comment

begin_comment
comment|/* two effects sends.					*/
end_comment

begin_define
define|#
directive|define
name|FXRT_CHANNELA
value|0x000f0000
end_define

begin_comment
comment|/* Effects send bus number for channel's effects send A	*/
end_comment

begin_define
define|#
directive|define
name|FXRT_CHANNELB
value|0x00f00000
end_define

begin_comment
comment|/* Effects send bus number for channel's effects send B	*/
end_comment

begin_define
define|#
directive|define
name|FXRT_CHANNELC
value|0x0f000000
end_define

begin_comment
comment|/* Effects send bus number for channel's effects send C	*/
end_comment

begin_define
define|#
directive|define
name|FXRT_CHANNELD
value|0xf0000000
end_define

begin_comment
comment|/* Effects send bus number for channel's effects send D	*/
end_comment

begin_define
define|#
directive|define
name|MAPA
value|0x0c
end_define

begin_comment
comment|/* Cache map A						*/
end_comment

begin_define
define|#
directive|define
name|MAPB
value|0x0d
end_define

begin_comment
comment|/* Cache map B						*/
end_comment

begin_define
define|#
directive|define
name|MAP_PTE_MASK
value|0xffffe000
end_define

begin_comment
comment|/* The 19 MSBs of the PTE indexed by the PTI		*/
end_comment

begin_define
define|#
directive|define
name|MAP_PTI_MASK
value|0x00001fff
end_define

begin_comment
comment|/* The 13 bit index to one of the 8192 PTE dwords      	*/
end_comment

begin_define
define|#
directive|define
name|ENVVOL
value|0x10
end_define

begin_comment
comment|/* Volume envelope register				*/
end_comment

begin_define
define|#
directive|define
name|ENVVOL_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* Current value of volume envelope state variable	*/
end_comment

begin_comment
comment|/* 0x8000-n == 666*n usec delay	       			*/
end_comment

begin_define
define|#
directive|define
name|ATKHLDV
value|0x11
end_define

begin_comment
comment|/* Volume envelope hold and attack register		*/
end_comment

begin_define
define|#
directive|define
name|ATKHLDV_PHASE0
value|0x00008000
end_define

begin_comment
comment|/* 0 = Begin attack phase				*/
end_comment

begin_define
define|#
directive|define
name|ATKHLDV_HOLDTIME_MASK
value|0x00007f00
end_define

begin_comment
comment|/* Envelope hold time (127-n == n*88.2msec)		*/
end_comment

begin_define
define|#
directive|define
name|ATKHLDV_ATTACKTIME_MASK
value|0x0000007f
end_define

begin_comment
comment|/* Envelope attack time, log encoded			*/
end_comment

begin_comment
comment|/* 0 = infinite, 1 = 10.9msec, ... 0x7f = 5.5msec	*/
end_comment

begin_define
define|#
directive|define
name|DCYSUSV
value|0x12
end_define

begin_comment
comment|/* Volume envelope sustain and decay register		*/
end_comment

begin_define
define|#
directive|define
name|DCYSUSV_PHASE1_MASK
value|0x00008000
end_define

begin_comment
comment|/* 0 = Begin attack phase, 1 = begin release phase	*/
end_comment

begin_define
define|#
directive|define
name|DCYSUSV_SUSTAINLEVEL_MASK
value|0x00007f00
end_define

begin_comment
comment|/* 127 = full, 0 = off, 0.75dB increments		*/
end_comment

begin_define
define|#
directive|define
name|DCYSUSV_CHANNELENABLE_MASK
value|0x00000080
end_define

begin_comment
comment|/* 1 = Inhibit envelope engine from writing values in	*/
end_comment

begin_comment
comment|/* this channel and from writing to pitch, filter and	*/
end_comment

begin_comment
comment|/* volume targets.					*/
end_comment

begin_define
define|#
directive|define
name|DCYSUSV_DECAYTIME_MASK
value|0x0000007f
end_define

begin_comment
comment|/* Volume envelope decay time, log encoded     		*/
end_comment

begin_comment
comment|/* 0 = 43.7msec, 1 = 21.8msec, 0x7f = 22msec		*/
end_comment

begin_define
define|#
directive|define
name|LFOVAL1
value|0x13
end_define

begin_comment
comment|/* Modulation LFO value					*/
end_comment

begin_define
define|#
directive|define
name|LFOVAL_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* Current value of modulation LFO state variable	*/
end_comment

begin_comment
comment|/* 0x8000-n == 666*n usec delay				*/
end_comment

begin_define
define|#
directive|define
name|ENVVAL
value|0x14
end_define

begin_comment
comment|/* Modulation envelope register				*/
end_comment

begin_define
define|#
directive|define
name|ENVVAL_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* Current value of modulation envelope state variable 	*/
end_comment

begin_comment
comment|/* 0x8000-n == 666*n usec delay				*/
end_comment

begin_define
define|#
directive|define
name|ATKHLDM
value|0x15
end_define

begin_comment
comment|/* Modulation envelope hold and attack register		*/
end_comment

begin_define
define|#
directive|define
name|ATKHLDM_PHASE0
value|0x00008000
end_define

begin_comment
comment|/* 0 = Begin attack phase				*/
end_comment

begin_define
define|#
directive|define
name|ATKHLDM_HOLDTIME
value|0x00007f00
end_define

begin_comment
comment|/* Envelope hold time (127-n == n*42msec)		*/
end_comment

begin_define
define|#
directive|define
name|ATKHLDM_ATTACKTIME
value|0x0000007f
end_define

begin_comment
comment|/* Envelope attack time, log encoded			*/
end_comment

begin_comment
comment|/* 0 = infinite, 1 = 11msec, ... 0x7f = 5.5msec		*/
end_comment

begin_define
define|#
directive|define
name|DCYSUSM
value|0x16
end_define

begin_comment
comment|/* Modulation envelope decay and sustain register	*/
end_comment

begin_define
define|#
directive|define
name|DCYSUSM_PHASE1_MASK
value|0x00008000
end_define

begin_comment
comment|/* 0 = Begin attack phase, 1 = begin release phase	*/
end_comment

begin_define
define|#
directive|define
name|DCYSUSM_SUSTAINLEVEL_MASK
value|0x00007f00
end_define

begin_comment
comment|/* 127 = full, 0 = off, 0.75dB increments		*/
end_comment

begin_define
define|#
directive|define
name|DCYSUSM_DECAYTIME_MASK
value|0x0000007f
end_define

begin_comment
comment|/* Envelope decay time, log encoded			*/
end_comment

begin_comment
comment|/* 0 = 43.7msec, 1 = 21.8msec, 0x7f = 22msec		*/
end_comment

begin_define
define|#
directive|define
name|LFOVAL2
value|0x17
end_define

begin_comment
comment|/* Vibrato LFO register					*/
end_comment

begin_define
define|#
directive|define
name|LFOVAL2_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* Current value of vibrato LFO state variable 		*/
end_comment

begin_comment
comment|/* 0x8000-n == 666*n usec delay				*/
end_comment

begin_define
define|#
directive|define
name|IP
value|0x18
end_define

begin_comment
comment|/* Initial pitch register				*/
end_comment

begin_define
define|#
directive|define
name|IP_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* Exponential initial pitch shift			*/
end_comment

begin_comment
comment|/* 4 bits of octave, 12 bits of fractional octave	*/
end_comment

begin_define
define|#
directive|define
name|IP_UNITY
value|0x0000e000
end_define

begin_comment
comment|/* Unity pitch shift					*/
end_comment

begin_define
define|#
directive|define
name|IFATN
value|0x19
end_define

begin_comment
comment|/* Initial filter cutoff and attenuation register	*/
end_comment

begin_define
define|#
directive|define
name|IFATN_FILTERCUTOFF_MASK
value|0x0000ff00
end_define

begin_comment
comment|/* Initial filter cutoff frequency in exponential units	*/
end_comment

begin_comment
comment|/* 6 most significant bits are semitones		*/
end_comment

begin_comment
comment|/* 2 least significant bits are fractions		*/
end_comment

begin_define
define|#
directive|define
name|IFATN_FILTERCUTOFF
value|0x08080019
end_define

begin_define
define|#
directive|define
name|IFATN_ATTENUATION_MASK
value|0x000000ff
end_define

begin_comment
comment|/* Initial attenuation in 0.375dB steps			*/
end_comment

begin_define
define|#
directive|define
name|IFATN_ATTENUATION
value|0x08000019
end_define

begin_define
define|#
directive|define
name|PEFE
value|0x1a
end_define

begin_comment
comment|/* Pitch envelope and filter envelope amount register	*/
end_comment

begin_define
define|#
directive|define
name|PEFE_PITCHAMOUNT_MASK
value|0x0000ff00
end_define

begin_comment
comment|/* Pitch envlope amount					*/
end_comment

begin_comment
comment|/* Signed 2's complement, +/- one octave peak extremes	*/
end_comment

begin_define
define|#
directive|define
name|PEFE_PITCHAMOUNT
value|0x0808001a
end_define

begin_define
define|#
directive|define
name|PEFE_FILTERAMOUNT_MASK
value|0x000000ff
end_define

begin_comment
comment|/* Filter envlope amount				*/
end_comment

begin_comment
comment|/* Signed 2's complement, +/- six octaves peak extremes */
end_comment

begin_define
define|#
directive|define
name|PEFE_FILTERAMOUNT
value|0x0800001a
end_define

begin_define
define|#
directive|define
name|FMMOD
value|0x1b
end_define

begin_comment
comment|/* Vibrato/filter modulation from LFO register		*/
end_comment

begin_define
define|#
directive|define
name|FMMOD_MODVIBRATO
value|0x0000ff00
end_define

begin_comment
comment|/* Vibrato LFO modulation depth				*/
end_comment

begin_comment
comment|/* Signed 2's complement, +/- one octave extremes	*/
end_comment

begin_define
define|#
directive|define
name|FMMOD_MOFILTER
value|0x000000ff
end_define

begin_comment
comment|/* Filter LFO modulation depth				*/
end_comment

begin_comment
comment|/* Signed 2's complement, +/- three octave extremes	*/
end_comment

begin_define
define|#
directive|define
name|TREMFRQ
value|0x1c
end_define

begin_comment
comment|/* Tremolo amount and modulation LFO frequency register	*/
end_comment

begin_define
define|#
directive|define
name|TREMFRQ_DEPTH
value|0x0000ff00
end_define

begin_comment
comment|/* Tremolo depth					*/
end_comment

begin_comment
comment|/* Signed 2's complement, with +/- 12dB extremes	*/
end_comment

begin_define
define|#
directive|define
name|TREMFRQ_FREQUENCY
value|0x000000ff
end_define

begin_comment
comment|/* Tremolo LFO frequency				*/
end_comment

begin_comment
comment|/* ??Hz steps, maximum of ?? Hz.			*/
end_comment

begin_define
define|#
directive|define
name|FM2FRQ2
value|0x1d
end_define

begin_comment
comment|/* Vibrato amount and vibrato LFO frequency register	*/
end_comment

begin_define
define|#
directive|define
name|FM2FRQ2_DEPTH
value|0x0000ff00
end_define

begin_comment
comment|/* Vibrato LFO vibrato depth				*/
end_comment

begin_comment
comment|/* Signed 2's complement, +/- one octave extremes	*/
end_comment

begin_define
define|#
directive|define
name|FM2FRQ2_FREQUENCY
value|0x000000ff
end_define

begin_comment
comment|/* Vibrato LFO frequency				*/
end_comment

begin_comment
comment|/* 0.039Hz steps, maximum of 9.85 Hz.			*/
end_comment

begin_define
define|#
directive|define
name|TEMPENV
value|0x1e
end_define

begin_comment
comment|/* Tempory envelope register				*/
end_comment

begin_define
define|#
directive|define
name|TEMPENV_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* 16-bit value						*/
end_comment

begin_comment
comment|/* NOTE: All channels contain internal variables; do	*/
end_comment

begin_comment
comment|/* not write to these locations.			*/
end_comment

begin_define
define|#
directive|define
name|CD0
value|0x20
end_define

begin_comment
comment|/* Cache data 0 register				*/
end_comment

begin_define
define|#
directive|define
name|CD1
value|0x21
end_define

begin_comment
comment|/* Cache data 1 register				*/
end_comment

begin_define
define|#
directive|define
name|CD2
value|0x22
end_define

begin_comment
comment|/* Cache data 2 register				*/
end_comment

begin_define
define|#
directive|define
name|CD3
value|0x23
end_define

begin_comment
comment|/* Cache data 3 register				*/
end_comment

begin_define
define|#
directive|define
name|CD4
value|0x24
end_define

begin_comment
comment|/* Cache data 4 register				*/
end_comment

begin_define
define|#
directive|define
name|CD5
value|0x25
end_define

begin_comment
comment|/* Cache data 5 register				*/
end_comment

begin_define
define|#
directive|define
name|CD6
value|0x26
end_define

begin_comment
comment|/* Cache data 6 register				*/
end_comment

begin_define
define|#
directive|define
name|CD7
value|0x27
end_define

begin_comment
comment|/* Cache data 7 register				*/
end_comment

begin_define
define|#
directive|define
name|CD8
value|0x28
end_define

begin_comment
comment|/* Cache data 8 register				*/
end_comment

begin_define
define|#
directive|define
name|CD9
value|0x29
end_define

begin_comment
comment|/* Cache data 9 register				*/
end_comment

begin_define
define|#
directive|define
name|CDA
value|0x2a
end_define

begin_comment
comment|/* Cache data A register				*/
end_comment

begin_define
define|#
directive|define
name|CDB
value|0x2b
end_define

begin_comment
comment|/* Cache data B register				*/
end_comment

begin_define
define|#
directive|define
name|CDC
value|0x2c
end_define

begin_comment
comment|/* Cache data C register				*/
end_comment

begin_define
define|#
directive|define
name|CDD
value|0x2d
end_define

begin_comment
comment|/* Cache data D register				*/
end_comment

begin_define
define|#
directive|define
name|CDE
value|0x2e
end_define

begin_comment
comment|/* Cache data E register				*/
end_comment

begin_define
define|#
directive|define
name|CDF
value|0x2f
end_define

begin_comment
comment|/* Cache data F register				*/
end_comment

begin_define
define|#
directive|define
name|PTB
value|0x40
end_define

begin_comment
comment|/* Page table base register				*/
end_comment

begin_define
define|#
directive|define
name|PTB_MASK
value|0xfffff000
end_define

begin_comment
comment|/* Physical address of the page table in host memory	*/
end_comment

begin_define
define|#
directive|define
name|TCB
value|0x41
end_define

begin_comment
comment|/* Tank cache base register    				*/
end_comment

begin_define
define|#
directive|define
name|TCB_MASK
value|0xfffff000
end_define

begin_comment
comment|/* Physical address of the bottom of host based TRAM	*/
end_comment

begin_define
define|#
directive|define
name|ADCCR
value|0x42
end_define

begin_comment
comment|/* ADC sample rate/stereo control register		*/
end_comment

begin_define
define|#
directive|define
name|ADCCR_RCHANENABLE
value|0x00000010
end_define

begin_comment
comment|/* Enables right channel for writing to the host       	*/
end_comment

begin_define
define|#
directive|define
name|ADCCR_LCHANENABLE
value|0x00000008
end_define

begin_comment
comment|/* Enables left channel for writing to the host		*/
end_comment

begin_comment
comment|/* NOTE: To guarantee phase coherency, both channels	*/
end_comment

begin_comment
comment|/* must be disabled prior to enabling both channels.	*/
end_comment

begin_define
define|#
directive|define
name|A_ADCCR_RCHANENABLE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|A_ADCCR_LCHANENABLE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|A_ADCCR_SAMPLERATE_MASK
value|0x0000000F
end_define

begin_comment
comment|/* Audigy sample rate convertor output rate		*/
end_comment

begin_define
define|#
directive|define
name|ADCCR_SAMPLERATE_MASK
value|0x00000007
end_define

begin_comment
comment|/* Sample rate convertor output rate			*/
end_comment

begin_define
define|#
directive|define
name|ADCCR_SAMPLERATE_48
value|0x00000000
end_define

begin_comment
comment|/* 48kHz sample rate					*/
end_comment

begin_define
define|#
directive|define
name|ADCCR_SAMPLERATE_44
value|0x00000001
end_define

begin_comment
comment|/* 44.1kHz sample rate					*/
end_comment

begin_define
define|#
directive|define
name|ADCCR_SAMPLERATE_32
value|0x00000002
end_define

begin_comment
comment|/* 32kHz sample rate					*/
end_comment

begin_define
define|#
directive|define
name|ADCCR_SAMPLERATE_24
value|0x00000003
end_define

begin_comment
comment|/* 24kHz sample rate					*/
end_comment

begin_define
define|#
directive|define
name|ADCCR_SAMPLERATE_22
value|0x00000004
end_define

begin_comment
comment|/* 22.05kHz sample rate					*/
end_comment

begin_define
define|#
directive|define
name|ADCCR_SAMPLERATE_16
value|0x00000005
end_define

begin_comment
comment|/* 16kHz sample rate					*/
end_comment

begin_define
define|#
directive|define
name|ADCCR_SAMPLERATE_11
value|0x00000006
end_define

begin_comment
comment|/* 11.025kHz sample rate				*/
end_comment

begin_define
define|#
directive|define
name|ADCCR_SAMPLERATE_8
value|0x00000007
end_define

begin_comment
comment|/* 8kHz sample rate					*/
end_comment

begin_define
define|#
directive|define
name|A_ADCCR_SAMPLERATE_12
value|0x00000006
end_define

begin_comment
comment|/* 12kHz sample rate					*/
end_comment

begin_define
define|#
directive|define
name|A_ADCCR_SAMPLERATE_11
value|0x00000007
end_define

begin_comment
comment|/* 11.025kHz sample rate				*/
end_comment

begin_define
define|#
directive|define
name|A_ADCCR_SAMPLERATE_8
value|0x00000008
end_define

begin_comment
comment|/* 8kHz sample rate					*/
end_comment

begin_define
define|#
directive|define
name|FXWC
value|0x43
end_define

begin_comment
comment|/* FX output write channels register			*/
end_comment

begin_comment
comment|/* When set, each bit enables the writing of the	*/
end_comment

begin_comment
comment|/* corresponding FX output channel into host memory	*/
end_comment

begin_define
define|#
directive|define
name|FXWC_DEFAULTROUTE_C
value|(1<<0)
end_define

begin_comment
comment|/* left emu out? */
end_comment

begin_define
define|#
directive|define
name|FXWC_DEFAULTROUTE_B
value|(1<<1)
end_define

begin_comment
comment|/* right emu out? */
end_comment

begin_define
define|#
directive|define
name|FXWC_DEFAULTROUTE_A
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|FXWC_DEFAULTROUTE_D
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|FXWC_ADCLEFT
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|FXWC_CDROMSPDIFLEFT
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|FXWC_ADCRIGHT
value|(1<<19)
end_define

begin_define
define|#
directive|define
name|FXWC_CDROMSPDIFRIGHT
value|(1<<19)
end_define

begin_define
define|#
directive|define
name|FXWC_MIC
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|FXWC_ZOOMLEFT
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|FXWC_ZOOMRIGHT
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|FXWC_SPDIFLEFT
value|(1<<22)
end_define

begin_comment
comment|/* 0x00400000 */
end_comment

begin_define
define|#
directive|define
name|FXWC_SPDIFRIGHT
value|(1<<23)
end_define

begin_comment
comment|/* 0x00800000 */
end_comment

begin_define
define|#
directive|define
name|TCBS
value|0x44
end_define

begin_comment
comment|/* Tank cache buffer size register			*/
end_comment

begin_define
define|#
directive|define
name|TCBS_MASK
value|0x00000007
end_define

begin_comment
comment|/* Tank cache buffer size field				*/
end_comment

begin_define
define|#
directive|define
name|TCBS_BUFFSIZE_16K
value|0x00000000
end_define

begin_define
define|#
directive|define
name|TCBS_BUFFSIZE_32K
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TCBS_BUFFSIZE_64K
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TCBS_BUFFSIZE_128K
value|0x00000003
end_define

begin_define
define|#
directive|define
name|TCBS_BUFFSIZE_256K
value|0x00000004
end_define

begin_define
define|#
directive|define
name|TCBS_BUFFSIZE_512K
value|0x00000005
end_define

begin_define
define|#
directive|define
name|TCBS_BUFFSIZE_1024K
value|0x00000006
end_define

begin_define
define|#
directive|define
name|TCBS_BUFFSIZE_2048K
value|0x00000007
end_define

begin_define
define|#
directive|define
name|MICBA
value|0x45
end_define

begin_comment
comment|/* AC97 microphone buffer address register		*/
end_comment

begin_define
define|#
directive|define
name|MICBA_MASK
value|0xfffff000
end_define

begin_comment
comment|/* 20 bit base address					*/
end_comment

begin_define
define|#
directive|define
name|ADCBA
value|0x46
end_define

begin_comment
comment|/* ADC buffer address register				*/
end_comment

begin_define
define|#
directive|define
name|ADCBA_MASK
value|0xfffff000
end_define

begin_comment
comment|/* 20 bit base address					*/
end_comment

begin_define
define|#
directive|define
name|FXBA
value|0x47
end_define

begin_comment
comment|/* FX Buffer Address */
end_comment

begin_define
define|#
directive|define
name|FXBA_MASK
value|0xfffff000
end_define

begin_comment
comment|/* 20 bit base address					*/
end_comment

begin_define
define|#
directive|define
name|MICBS
value|0x49
end_define

begin_comment
comment|/* Microphone buffer size register			*/
end_comment

begin_define
define|#
directive|define
name|ADCBS
value|0x4a
end_define

begin_comment
comment|/* ADC buffer size register				*/
end_comment

begin_define
define|#
directive|define
name|FXBS
value|0x4b
end_define

begin_comment
comment|/* FX buffer size register				*/
end_comment

begin_comment
comment|/* The following mask values define the size of the ADC, MIX and FX buffers in bytes */
end_comment

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_384
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_448
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_512
value|0x00000003
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_640
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_768
value|0x00000005
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_896
value|0x00000006
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_1024
value|0x00000007
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_1280
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_1536
value|0x00000009
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_1792
value|0x0000000a
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_2048
value|0x0000000b
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_2560
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_3072
value|0x0000000d
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_3584
value|0x0000000e
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_4096
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_5120
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_6144
value|0x00000011
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_7168
value|0x00000012
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_8192
value|0x00000013
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_10240
value|0x00000014
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_12288
value|0x00000015
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_14366
value|0x00000016
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_16384
value|0x00000017
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_20480
value|0x00000018
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_24576
value|0x00000019
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_28672
value|0x0000001a
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_32768
value|0x0000001b
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_40960
value|0x0000001c
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_49152
value|0x0000001d
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_57344
value|0x0000001e
end_define

begin_define
define|#
directive|define
name|ADCBS_BUFSIZE_65536
value|0x0000001f
end_define

begin_define
define|#
directive|define
name|CDCS
value|0x50
end_define

begin_comment
comment|/* CD-ROM digital channel status register	*/
end_comment

begin_define
define|#
directive|define
name|GPSCS
value|0x51
end_define

begin_comment
comment|/* General Purpose SPDIF channel status register*/
end_comment

begin_define
define|#
directive|define
name|DBG
value|0x52
end_define

begin_comment
comment|/* DO NOT PROGRAM THIS REGISTER!!! MAY DESTROY CHIP */
end_comment

begin_define
define|#
directive|define
name|REG53
value|0x53
end_define

begin_comment
comment|/* DO NOT PROGRAM THIS REGISTER!!! MAY DESTROY CHIP */
end_comment

begin_define
define|#
directive|define
name|A_DBG
value|0x53
end_define

begin_define
define|#
directive|define
name|A_DBG_SINGLE_STEP
value|0x00020000
end_define

begin_comment
comment|/* Set to zero to start dsp */
end_comment

begin_define
define|#
directive|define
name|A_DBG_ZC
value|0x40000000
end_define

begin_comment
comment|/* zero tram counter */
end_comment

begin_define
define|#
directive|define
name|A_DBG_STEP_ADDR
value|0x000003ff
end_define

begin_define
define|#
directive|define
name|A_DBG_SATURATION_OCCURED
value|0x20000000
end_define

begin_define
define|#
directive|define
name|A_DBG_SATURATION_ADDR
value|0x0ffc0000
end_define

begin_define
define|#
directive|define
name|SPCS0
value|0x54
end_define

begin_comment
comment|/* SPDIF output Channel Status 0 register	*/
end_comment

begin_define
define|#
directive|define
name|SPCS1
value|0x55
end_define

begin_comment
comment|/* SPDIF output Channel Status 1 register	*/
end_comment

begin_define
define|#
directive|define
name|SPCS2
value|0x56
end_define

begin_comment
comment|/* SPDIF output Channel Status 2 register	*/
end_comment

begin_define
define|#
directive|define
name|SPCS_CLKACCYMASK
value|0x30000000
end_define

begin_comment
comment|/* Clock accuracy				*/
end_comment

begin_define
define|#
directive|define
name|SPCS_CLKACCY_1000PPM
value|0x00000000
end_define

begin_comment
comment|/* 1000 parts per million			*/
end_comment

begin_define
define|#
directive|define
name|SPCS_CLKACCY_50PPM
value|0x10000000
end_define

begin_comment
comment|/* 50 parts per million				*/
end_comment

begin_define
define|#
directive|define
name|SPCS_CLKACCY_VARIABLE
value|0x20000000
end_define

begin_comment
comment|/* Variable accuracy				*/
end_comment

begin_define
define|#
directive|define
name|SPCS_SAMPLERATEMASK
value|0x0f000000
end_define

begin_comment
comment|/* Sample rate					*/
end_comment

begin_define
define|#
directive|define
name|SPCS_SAMPLERATE_44
value|0x00000000
end_define

begin_comment
comment|/* 44.1kHz sample rate				*/
end_comment

begin_define
define|#
directive|define
name|SPCS_SAMPLERATE_48
value|0x02000000
end_define

begin_comment
comment|/* 48kHz sample rate				*/
end_comment

begin_define
define|#
directive|define
name|SPCS_SAMPLERATE_32
value|0x03000000
end_define

begin_comment
comment|/* 32kHz sample rate				*/
end_comment

begin_define
define|#
directive|define
name|SPCS_CHANNELNUMMASK
value|0x00f00000
end_define

begin_comment
comment|/* Channel number				*/
end_comment

begin_define
define|#
directive|define
name|SPCS_CHANNELNUM_UNSPEC
value|0x00000000
end_define

begin_comment
comment|/* Unspecified channel number			*/
end_comment

begin_define
define|#
directive|define
name|SPCS_CHANNELNUM_LEFT
value|0x00100000
end_define

begin_comment
comment|/* Left channel					*/
end_comment

begin_define
define|#
directive|define
name|SPCS_CHANNELNUM_RIGHT
value|0x00200000
end_define

begin_comment
comment|/* Right channel				*/
end_comment

begin_define
define|#
directive|define
name|SPCS_SOURCENUMMASK
value|0x000f0000
end_define

begin_comment
comment|/* Source number				*/
end_comment

begin_define
define|#
directive|define
name|SPCS_SOURCENUM_UNSPEC
value|0x00000000
end_define

begin_comment
comment|/* Unspecified source number			*/
end_comment

begin_define
define|#
directive|define
name|SPCS_GENERATIONSTATUS
value|0x00008000
end_define

begin_comment
comment|/* Originality flag (see IEC-958 spec)		*/
end_comment

begin_define
define|#
directive|define
name|SPCS_CATEGORYCODEMASK
value|0x00007f00
end_define

begin_comment
comment|/* Category code (see IEC-958 spec)		*/
end_comment

begin_define
define|#
directive|define
name|SPCS_MODEMASK
value|0x000000c0
end_define

begin_comment
comment|/* Mode (see IEC-958 spec)			*/
end_comment

begin_define
define|#
directive|define
name|SPCS_EMPHASISMASK
value|0x00000038
end_define

begin_comment
comment|/* Emphasis					*/
end_comment

begin_define
define|#
directive|define
name|SPCS_EMPHASIS_NONE
value|0x00000000
end_define

begin_comment
comment|/* No emphasis					*/
end_comment

begin_define
define|#
directive|define
name|SPCS_EMPHASIS_50_15
value|0x00000008
end_define

begin_comment
comment|/* 50/15 usec 2 channel				*/
end_comment

begin_define
define|#
directive|define
name|SPCS_COPYRIGHT
value|0x00000004
end_define

begin_comment
comment|/* Copyright asserted flag -- do not modify	*/
end_comment

begin_define
define|#
directive|define
name|SPCS_NOTAUDIODATA
value|0x00000002
end_define

begin_comment
comment|/* 0 = Digital audio, 1 = not audio		*/
end_comment

begin_define
define|#
directive|define
name|SPCS_PROFESSIONAL
value|0x00000001
end_define

begin_comment
comment|/* 0 = Consumer (IEC-958), 1 = pro (AES3-1992)	*/
end_comment

begin_comment
comment|/* The 32-bit CLIx and SOLx registers all have one bit per channel control/status      		*/
end_comment

begin_define
define|#
directive|define
name|CLIEL
value|0x58
end_define

begin_comment
comment|/* Channel loop interrupt enable low register	*/
end_comment

begin_define
define|#
directive|define
name|CLIEH
value|0x59
end_define

begin_comment
comment|/* Channel loop interrupt enable high register	*/
end_comment

begin_define
define|#
directive|define
name|CLIPL
value|0x5a
end_define

begin_comment
comment|/* Channel loop interrupt pending low register	*/
end_comment

begin_define
define|#
directive|define
name|CLIPH
value|0x5b
end_define

begin_comment
comment|/* Channel loop interrupt pending high register	*/
end_comment

begin_define
define|#
directive|define
name|SOLEL
value|0x5c
end_define

begin_comment
comment|/* Stop on loop enable low register		*/
end_comment

begin_define
define|#
directive|define
name|SOLEH
value|0x5d
end_define

begin_comment
comment|/* Stop on loop enable high register		*/
end_comment

begin_define
define|#
directive|define
name|SPBYPASS
value|0x5e
end_define

begin_comment
comment|/* SPDIF BYPASS mode register			*/
end_comment

begin_define
define|#
directive|define
name|SPBYPASS_ENABLE
value|0x00000001
end_define

begin_comment
comment|/* Enable SPDIF bypass mode			*/
end_comment

begin_define
define|#
directive|define
name|AC97SLOT
value|0x5f
end_define

begin_comment
comment|/* additional AC97 slots enable bits		*/
end_comment

begin_define
define|#
directive|define
name|AC97SLOT_CNTR
value|0x10
end_define

begin_comment
comment|/* Center enable */
end_comment

begin_define
define|#
directive|define
name|AC97SLOT_LFE
value|0x20
end_define

begin_comment
comment|/* LFE enable */
end_comment

begin_define
define|#
directive|define
name|CDSRCS
value|0x60
end_define

begin_comment
comment|/* CD-ROM Sample Rate Converter status register	*/
end_comment

begin_define
define|#
directive|define
name|GPSRCS
value|0x61
end_define

begin_comment
comment|/* General Purpose SPDIF sample rate cvt status */
end_comment

begin_define
define|#
directive|define
name|ZVSRCS
value|0x62
end_define

begin_comment
comment|/* ZVideo sample rate converter status		*/
end_comment

begin_comment
comment|/* NOTE: This one has no SPDIFLOCKED field	*/
end_comment

begin_comment
comment|/* Assumes sample lock				*/
end_comment

begin_comment
comment|/* These three bitfields apply to CDSRCS, GPSRCS, and (except as noted) ZVSRCS.			*/
end_comment

begin_define
define|#
directive|define
name|SRCS_SPDIFLOCKED
value|0x02000000
end_define

begin_comment
comment|/* SPDIF stream locked				*/
end_comment

begin_define
define|#
directive|define
name|SRCS_RATELOCKED
value|0x01000000
end_define

begin_comment
comment|/* Sample rate locked				*/
end_comment

begin_define
define|#
directive|define
name|SRCS_ESTSAMPLERATE
value|0x0007ffff
end_define

begin_comment
comment|/* Do not modify this field.			*/
end_comment

begin_comment
comment|/* Note that these values can vary +/- by a small amount                                        */
end_comment

begin_define
define|#
directive|define
name|SRCS_SPDIFRATE_44
value|0x0003acd9
end_define

begin_define
define|#
directive|define
name|SRCS_SPDIFRATE_48
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SRCS_SPDIFRATE_96
value|0x00080000
end_define

begin_define
define|#
directive|define
name|MICIDX
value|0x63
end_define

begin_comment
comment|/* Microphone recording buffer index register   */
end_comment

begin_define
define|#
directive|define
name|MICIDX_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* 16-bit value                                 */
end_comment

begin_define
define|#
directive|define
name|MICIDX_IDX
value|0x10000063
end_define

begin_define
define|#
directive|define
name|ADCIDX
value|0x64
end_define

begin_comment
comment|/* ADC recording buffer index register		*/
end_comment

begin_define
define|#
directive|define
name|ADCIDX_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* 16 bit index field				*/
end_comment

begin_define
define|#
directive|define
name|ADCIDX_IDX
value|0x10000064
end_define

begin_define
define|#
directive|define
name|A_ADCIDX
value|0x63
end_define

begin_define
define|#
directive|define
name|A_ADCIDX_IDX
value|0x10000063
end_define

begin_define
define|#
directive|define
name|FXIDX
value|0x65
end_define

begin_comment
comment|/* FX recording buffer index register		*/
end_comment

begin_define
define|#
directive|define
name|FXIDX_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* 16-bit value					*/
end_comment

begin_define
define|#
directive|define
name|FXIDX_IDX
value|0x10000065
end_define

begin_comment
comment|/* This is the MPU port on the card (via the game port)						*/
end_comment

begin_define
define|#
directive|define
name|A_MUDATA1
value|0x70
end_define

begin_define
define|#
directive|define
name|A_MUCMD1
value|0x71
end_define

begin_define
define|#
directive|define
name|A_MUSTAT1
value|A_MUCMD1
end_define

begin_comment
comment|/* This is the MPU port on the Audigy Drive 							*/
end_comment

begin_define
define|#
directive|define
name|A_MUDATA2
value|0x72
end_define

begin_define
define|#
directive|define
name|A_MUCMD2
value|0x73
end_define

begin_define
define|#
directive|define
name|A_MUSTAT2
value|A_MUCMD2
end_define

begin_comment
comment|/* The next two are the Audigy equivalent of FXWC						*/
end_comment

begin_comment
comment|/* the Audigy can record any output (16bit, 48kHz, up to 64 channel simultaneously) 		*/
end_comment

begin_comment
comment|/* Each bit selects a channel for recording */
end_comment

begin_define
define|#
directive|define
name|A_FXWC1
value|0x74
end_define

begin_comment
comment|/* Selects 0x7f-0x60 for FX recording           */
end_comment

begin_define
define|#
directive|define
name|A_FXWC2
value|0x75
end_define

begin_comment
comment|/* Selects 0x9f-0x80 for FX recording           */
end_comment

begin_define
define|#
directive|define
name|A_SPDIF_SAMPLERATE
value|0x76
end_define

begin_comment
comment|/* Set the sample rate of SPDIF output		*/
end_comment

begin_define
define|#
directive|define
name|A_SPDIF_48000
value|0x00000080
end_define

begin_define
define|#
directive|define
name|A_SPDIF_44100
value|0x00000000
end_define

begin_define
define|#
directive|define
name|A_SPDIF_96000
value|0x00000040
end_define

begin_define
define|#
directive|define
name|A_FXRT2
value|0x7c
end_define

begin_define
define|#
directive|define
name|A_FXRT_CHANNELE
value|0x0000003f
end_define

begin_comment
comment|/* Effects send bus number for channel's effects send E	*/
end_comment

begin_define
define|#
directive|define
name|A_FXRT_CHANNELF
value|0x00003f00
end_define

begin_comment
comment|/* Effects send bus number for channel's effects send F	*/
end_comment

begin_define
define|#
directive|define
name|A_FXRT_CHANNELG
value|0x003f0000
end_define

begin_comment
comment|/* Effects send bus number for channel's effects send G	*/
end_comment

begin_define
define|#
directive|define
name|A_FXRT_CHANNELH
value|0x3f000000
end_define

begin_comment
comment|/* Effects send bus number for channel's effects send H	*/
end_comment

begin_define
define|#
directive|define
name|A_SENDAMOUNTS
value|0x7d
end_define

begin_define
define|#
directive|define
name|A_FXSENDAMOUNT_E_MASK
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|A_FXSENDAMOUNT_F_MASK
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|A_FXSENDAMOUNT_G_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|A_FXSENDAMOUNT_H_MASK
value|0x000000FF
end_define

begin_comment
comment|/* The send amounts for this one are the same as used with the emu10k1 */
end_comment

begin_define
define|#
directive|define
name|A_FXRT1
value|0x7e
end_define

begin_define
define|#
directive|define
name|A_FXRT_CHANNELA
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|A_FXRT_CHANNELB
value|0x00003f00
end_define

begin_define
define|#
directive|define
name|A_FXRT_CHANNELC
value|0x003f0000
end_define

begin_define
define|#
directive|define
name|A_FXRT_CHANNELD
value|0x3f000000
end_define

begin_comment
comment|/* Each FX general purpose register is 32 bits in length, all bits are used			*/
end_comment

begin_define
define|#
directive|define
name|FXGPREGBASE
value|0x100
end_define

begin_comment
comment|/* FX general purpose registers base       	*/
end_comment

begin_define
define|#
directive|define
name|A_FXGPREGBASE
value|0x400
end_define

begin_comment
comment|/* Audigy GPRs, 0x400 to 0x5ff			*/
end_comment

begin_comment
comment|/* Tank audio data is logarithmically compressed down to 16 bits before writing to TRAM and is	*/
end_comment

begin_comment
comment|/* decompressed back to 20 bits on a read.  There are a total of 160 locations, the last 32	*/
end_comment

begin_comment
comment|/* locations are for external TRAM. 								*/
end_comment

begin_define
define|#
directive|define
name|TANKMEMDATAREGBASE
value|0x200
end_define

begin_comment
comment|/* Tank memory data registers base     		*/
end_comment

begin_define
define|#
directive|define
name|TANKMEMDATAREG_MASK
value|0x000fffff
end_define

begin_comment
comment|/* 20 bit tank audio data field			*/
end_comment

begin_comment
comment|/* Combined address field and memory opcode or flag field.  160 locations, last 32 are external	*/
end_comment

begin_define
define|#
directive|define
name|TANKMEMADDRREGBASE
value|0x300
end_define

begin_comment
comment|/* Tank memory address registers base		*/
end_comment

begin_define
define|#
directive|define
name|TANKMEMADDRREG_ADDR_MASK
value|0x000fffff
end_define

begin_comment
comment|/* 20 bit tank address field			*/
end_comment

begin_define
define|#
directive|define
name|TANKMEMADDRREG_CLEAR
value|0x00800000
end_define

begin_comment
comment|/* Clear tank memory				*/
end_comment

begin_define
define|#
directive|define
name|TANKMEMADDRREG_ALIGN
value|0x00400000
end_define

begin_comment
comment|/* Align read or write relative to tank access	*/
end_comment

begin_define
define|#
directive|define
name|TANKMEMADDRREG_WRITE
value|0x00200000
end_define

begin_comment
comment|/* Write to tank memory				*/
end_comment

begin_define
define|#
directive|define
name|TANKMEMADDRREG_READ
value|0x00100000
end_define

begin_comment
comment|/* Read from tank memory			*/
end_comment

begin_define
define|#
directive|define
name|MICROCODEBASE
value|0x400
end_define

begin_comment
comment|/* Microcode data base address			*/
end_comment

begin_comment
comment|/* Each DSP microcode instruction is mapped into 2 doublewords 					*/
end_comment

begin_comment
comment|/* NOTE: When writing, always write the LO doubleword first.  Reads can be in either order.	*/
end_comment

begin_define
define|#
directive|define
name|LOWORD_OPX_MASK
value|0x000ffc00
end_define

begin_comment
comment|/* Instruction operand X			*/
end_comment

begin_define
define|#
directive|define
name|LOWORD_OPY_MASK
value|0x000003ff
end_define

begin_comment
comment|/* Instruction operand Y			*/
end_comment

begin_define
define|#
directive|define
name|HIWORD_OPCODE_MASK
value|0x00f00000
end_define

begin_comment
comment|/* Instruction opcode				*/
end_comment

begin_define
define|#
directive|define
name|HIWORD_RESULT_MASK
value|0x000ffc00
end_define

begin_comment
comment|/* Instruction result				*/
end_comment

begin_define
define|#
directive|define
name|HIWORD_OPA_MASK
value|0x000003ff
end_define

begin_comment
comment|/* Instruction operand A			*/
end_comment

begin_comment
comment|/* Audigy Soundcard have a different instruction format */
end_comment

begin_define
define|#
directive|define
name|A_MICROCODEBASE
value|0x600
end_define

begin_define
define|#
directive|define
name|A_LOWORD_OPY_MASK
value|0x000007ff
end_define

begin_define
define|#
directive|define
name|A_LOWORD_OPX_MASK
value|0x007ff000
end_define

begin_define
define|#
directive|define
name|A_HIWORD_OPCODE_MASK
value|0x0f000000
end_define

begin_define
define|#
directive|define
name|A_HIWORD_RESULT_MASK
value|0x007ff000
end_define

begin_define
define|#
directive|define
name|A_HIWORD_OPA_MASK
value|0x000007ff
end_define

begin_comment
comment|/* ------------------- STRUCTURES -------------------- */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_snd_emu10k1
name|emu10k1_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_snd_emu10k1_voice
name|emu10k1_voice_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_snd_emu10k1_pcm
name|emu10k1_pcm_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|EMU10K1_PCM
block|,
name|EMU10K1_SYNTH
block|,
name|EMU10K1_MIDI
block|}
name|emu10k1_voice_type_t
typedef|;
end_typedef

begin_struct
struct|struct
name|_snd_emu10k1_voice
block|{
name|emu10k1_t
modifier|*
name|emu
decl_stmt|;
name|int
name|number
decl_stmt|;
name|int
name|use
range|:
literal|1
decl_stmt|,
name|pcm
range|:
literal|1
decl_stmt|,
name|synth
range|:
literal|1
decl_stmt|,
name|midi
range|:
literal|1
decl_stmt|;
name|void
function_decl|(
modifier|*
name|interrupt
function_decl|)
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|emu10k1_voice_t
modifier|*
name|pvoice
parameter_list|)
function_decl|;
name|emu10k1_pcm_t
modifier|*
name|epcm
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|PLAYBACK_EMUVOICE
block|,
name|CAPTURE_AC97ADC
block|,
name|CAPTURE_AC97MIC
block|,
name|CAPTURE_EFX
block|}
name|snd_emu10k1_pcm_type_t
typedef|;
end_typedef

begin_struct
struct|struct
name|_snd_emu10k1_pcm
block|{
name|emu10k1_t
modifier|*
name|emu
decl_stmt|;
name|snd_emu10k1_pcm_type_t
name|type
decl_stmt|;
name|snd_pcm_substream_t
modifier|*
name|substream
decl_stmt|;
name|emu10k1_voice_t
modifier|*
name|voices
index|[
literal|2
index|]
decl_stmt|;
name|emu10k1_voice_t
modifier|*
name|extra
decl_stmt|;
name|unsigned
name|short
name|running
decl_stmt|;
name|unsigned
name|short
name|first_ptr
decl_stmt|;
name|snd_util_memblk_t
modifier|*
name|memblk
decl_stmt|;
name|unsigned
name|int
name|start_addr
decl_stmt|;
name|unsigned
name|int
name|ccca_start_addr
decl_stmt|;
name|unsigned
name|int
name|capture_ipr
decl_stmt|;
comment|/* interrupt acknowledge mask */
name|unsigned
name|int
name|capture_inte
decl_stmt|;
comment|/* interrupt enable mask */
name|unsigned
name|int
name|capture_ba_reg
decl_stmt|;
comment|/* buffer address register */
name|unsigned
name|int
name|capture_bs_reg
decl_stmt|;
comment|/* buffer size register */
name|unsigned
name|int
name|capture_idx_reg
decl_stmt|;
comment|/* buffer index register */
name|unsigned
name|int
name|capture_cr_val
decl_stmt|;
comment|/* control value */
name|unsigned
name|int
name|capture_cr_val2
decl_stmt|;
comment|/* control value2 (for audigy) */
name|unsigned
name|int
name|capture_bs_val
decl_stmt|;
comment|/* buffer size value */
name|unsigned
name|int
name|capture_bufsize
decl_stmt|;
comment|/* buffer size in bytes */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|send_routing
index|[
literal|3
index|]
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|char
name|send_volume
index|[
literal|3
index|]
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|short
name|attn
index|[
literal|3
index|]
decl_stmt|;
name|emu10k1_pcm_t
modifier|*
name|epcm
decl_stmt|;
block|}
name|emu10k1_pcm_mixer_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|snd_emu10k1_compose_send_routing
parameter_list|(
name|route
parameter_list|)
define|\
value|((route[0] | (route[1]<< 4) | (route[2]<< 8) | (route[3]<< 12))<< 16)
end_define

begin_define
define|#
directive|define
name|snd_emu10k1_compose_audigy_fxrt1
parameter_list|(
name|route
parameter_list|)
define|\
value|(((unsigned int)route[0] | ((unsigned int)route[1]<< 8) | ((unsigned int)route[2]<< 16) | ((unsigned int)route[3]<< 12))<< 24)
end_define

begin_define
define|#
directive|define
name|snd_emu10k1_compose_audigy_fxrt2
parameter_list|(
name|route
parameter_list|)
define|\
value|(((unsigned int)route[4] | ((unsigned int)route[5]<< 8) | ((unsigned int)route[6]<< 16) | ((unsigned int)route[7]<< 12))<< 24)
end_define

begin_typedef
typedef|typedef
struct|struct
name|snd_emu10k1_memblk
block|{
name|snd_util_memblk_t
name|mem
decl_stmt|;
comment|/* private part */
name|short
name|first_page
decl_stmt|,
name|last_page
decl_stmt|,
name|pages
decl_stmt|,
name|mapped_page
decl_stmt|;
name|unsigned
name|int
name|map_locked
decl_stmt|;
name|struct
name|list_head
name|mapped_link
decl_stmt|;
name|struct
name|list_head
name|mapped_order_link
decl_stmt|;
block|}
name|emu10k1_memblk_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|snd_emu10k1_memblk_offset
parameter_list|(
name|blk
parameter_list|)
value|(((blk)->mapped_page<< PAGE_SHIFT) | ((blk)->mem.offset& (PAGE_SIZE - 1)))
end_define

begin_define
define|#
directive|define
name|EMU10K1_MAX_TRAM_BLOCKS_PER_CODE
value|16
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|list_head
name|list
decl_stmt|;
comment|/* list link container */
name|unsigned
name|int
name|vcount
decl_stmt|;
name|unsigned
name|int
name|count
decl_stmt|;
comment|/* count of GPR (1..16) */
name|unsigned
name|char
name|gpr
index|[
literal|32
index|]
decl_stmt|;
comment|/* GPR number(s) */
name|unsigned
name|int
name|value
index|[
literal|32
index|]
decl_stmt|;
name|unsigned
name|int
name|min
decl_stmt|;
comment|/* minimum range */
name|unsigned
name|int
name|max
decl_stmt|;
comment|/* maximum range */
name|unsigned
name|int
name|translation
decl_stmt|;
comment|/* translation type (EMU10K1_GRP_TRANSLATION*) */
name|snd_kcontrol_t
modifier|*
name|kcontrol
decl_stmt|;
block|}
name|snd_emu10k1_fx8010_ctl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|snd_fx8010_irq_handler_t
function_decl|)
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|void
modifier|*
name|private_data
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_snd_emu10k1_fx8010_irq
block|{
name|struct
name|_snd_emu10k1_fx8010_irq
modifier|*
name|next
decl_stmt|;
name|snd_fx8010_irq_handler_t
modifier|*
name|handler
decl_stmt|;
name|unsigned
name|char
name|gpr_running
decl_stmt|;
name|void
modifier|*
name|private_data
decl_stmt|;
block|}
name|snd_emu10k1_fx8010_irq_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|valid
range|:
literal|1
decl_stmt|,
name|opened
range|:
literal|1
decl_stmt|,
name|active
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|channels
decl_stmt|;
comment|/* 16-bit channels count */
name|unsigned
name|int
name|tram_start
decl_stmt|;
comment|/* initial ring buffer position in TRAM (in samples) */
name|unsigned
name|int
name|buffer_size
decl_stmt|;
comment|/* count of buffered samples */
name|unsigned
name|char
name|gpr_size
decl_stmt|;
comment|/* GPR containing size of ring buffer in samples (host) */
name|unsigned
name|char
name|gpr_ptr
decl_stmt|;
comment|/* GPR containing current pointer in the ring buffer (host = reset, FX8010) */
name|unsigned
name|char
name|gpr_count
decl_stmt|;
comment|/* GPR containing count of samples between two interrupts (host) */
name|unsigned
name|char
name|gpr_tmpcount
decl_stmt|;
comment|/* GPR containing current count of samples to interrupt (host = set, FX8010) */
name|unsigned
name|char
name|gpr_trigger
decl_stmt|;
comment|/* GPR containing trigger (activate) information (host) */
name|unsigned
name|char
name|gpr_running
decl_stmt|;
comment|/* GPR containing info if PCM is running (FX8010) */
name|unsigned
name|char
name|etram
index|[
literal|32
index|]
decl_stmt|;
comment|/* external TRAM address& data */
name|unsigned
name|int
name|sw_data
decl_stmt|,
name|hw_data
decl_stmt|;
name|unsigned
name|int
name|sw_io
decl_stmt|,
name|hw_io
decl_stmt|;
name|unsigned
name|int
name|sw_ready
decl_stmt|,
name|hw_ready
decl_stmt|;
name|unsigned
name|int
name|appl_ptr
decl_stmt|;
name|unsigned
name|int
name|tram_pos
decl_stmt|;
name|unsigned
name|int
name|tram_shift
decl_stmt|;
name|snd_emu10k1_fx8010_irq_t
modifier|*
name|irq
decl_stmt|;
block|}
name|snd_emu10k1_fx8010_pcm_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|fxbus_mask
decl_stmt|;
comment|/* used FX buses (bitmask) */
name|unsigned
name|short
name|extin_mask
decl_stmt|;
comment|/* used external inputs (bitmask) */
name|unsigned
name|short
name|extout_mask
decl_stmt|;
comment|/* used external outputs (bitmask) */
name|unsigned
name|short
name|pad1
decl_stmt|;
name|unsigned
name|int
name|itram_size
decl_stmt|;
comment|/* internal TRAM size in samples */
name|unsigned
name|int
name|etram_size
decl_stmt|;
comment|/* external TRAM size in samples */
name|void
modifier|*
name|etram_pages
decl_stmt|;
comment|/* allocated pages for external TRAM */
name|dma_addr_t
name|etram_pages_dmaaddr
decl_stmt|;
name|unsigned
name|int
name|dbg
decl_stmt|;
comment|/* FX debugger register */
name|unsigned
name|char
name|name
index|[
literal|128
index|]
decl_stmt|;
name|int
name|gpr_size
decl_stmt|;
comment|/* size of allocated GPR controls */
name|int
name|gpr_count
decl_stmt|;
comment|/* count of used kcontrols */
name|struct
name|list_head
name|gpr_ctl
decl_stmt|;
comment|/* GPR controls */
name|struct
name|semaphore
name|lock
decl_stmt|;
name|snd_emu10k1_fx8010_pcm_t
name|pcm
index|[
literal|8
index|]
decl_stmt|;
name|spinlock_t
name|irq_lock
decl_stmt|;
name|snd_emu10k1_fx8010_irq_t
modifier|*
name|irq_handlers
decl_stmt|;
block|}
name|snd_emu10k1_fx8010_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|emu10k1_gpr_ctl
parameter_list|(
name|n
parameter_list|)
value|list_entry(n, snd_emu10k1_fx8010_ctl_t, list)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|_snd_emu10k1
modifier|*
name|emu
decl_stmt|;
name|snd_rawmidi_t
modifier|*
name|rmidi
decl_stmt|;
name|snd_rawmidi_substream_t
modifier|*
name|substream_input
decl_stmt|;
name|snd_rawmidi_substream_t
modifier|*
name|substream_output
decl_stmt|;
name|unsigned
name|int
name|midi_mode
decl_stmt|;
name|spinlock_t
name|input_lock
decl_stmt|;
name|spinlock_t
name|output_lock
decl_stmt|;
name|spinlock_t
name|open_lock
decl_stmt|;
name|int
name|tx_enable
decl_stmt|,
name|rx_enable
decl_stmt|;
name|int
name|port
decl_stmt|;
name|int
name|ipr_tx
decl_stmt|,
name|ipr_rx
decl_stmt|;
name|void
function_decl|(
modifier|*
name|interrupt
function_decl|)
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|unsigned
name|int
name|status
parameter_list|)
function_decl|;
block|}
name|emu10k1_midi_t
typedef|;
end_typedef

begin_struct
struct|struct
name|_snd_emu10k1
block|{
name|int
name|irq
decl_stmt|;
name|unsigned
name|long
name|port
decl_stmt|;
comment|/* I/O port number */
name|struct
name|resource
modifier|*
name|res_port
decl_stmt|;
name|int
name|APS
range|:
literal|1
decl_stmt|,
comment|/* APS flag */
name|tos_link
range|:
literal|1
decl_stmt|;
comment|/* tos link detected */
name|unsigned
name|int
name|audigy
decl_stmt|;
comment|/* is Audigy? */
name|unsigned
name|int
name|revision
decl_stmt|;
comment|/* chip revision */
name|unsigned
name|int
name|serial
decl_stmt|;
comment|/* serial number */
name|unsigned
name|short
name|model
decl_stmt|;
comment|/* subsystem id */
name|unsigned
name|int
name|card_type
decl_stmt|;
comment|/* EMU10K1_CARD_* */
name|unsigned
name|int
name|ecard_ctrl
decl_stmt|;
comment|/* ecard control bits */
name|unsigned
name|long
name|dma_mask
decl_stmt|;
comment|/* PCI DMA mask */
name|int
name|max_cache_pages
decl_stmt|;
comment|/* max memory size / PAGE_SIZE */
name|void
modifier|*
name|silent_page
decl_stmt|;
comment|/* silent page */
name|dma_addr_t
name|silent_page_dmaaddr
decl_stmt|;
specifier|volatile
name|u32
modifier|*
name|ptb_pages
decl_stmt|;
comment|/* page table pages */
name|dma_addr_t
name|ptb_pages_dmaaddr
decl_stmt|;
name|snd_util_memhdr_t
modifier|*
name|memhdr
decl_stmt|;
comment|/* page allocation list */
name|emu10k1_memblk_t
modifier|*
name|reserved_page
decl_stmt|;
comment|/* reserved page */
name|struct
name|list_head
name|mapped_link_head
decl_stmt|;
name|struct
name|list_head
name|mapped_order_link_head
decl_stmt|;
name|void
modifier|*
modifier|*
name|page_ptr_table
decl_stmt|;
name|unsigned
name|long
modifier|*
name|page_addr_table
decl_stmt|;
name|spinlock_t
name|memblk_lock
decl_stmt|;
name|unsigned
name|int
name|spdif_bits
index|[
literal|3
index|]
decl_stmt|;
comment|/* s/pdif out setup */
name|snd_emu10k1_fx8010_t
name|fx8010
decl_stmt|;
comment|/* FX8010 info */
name|int
name|gpr_base
decl_stmt|;
name|ac97_t
modifier|*
name|ac97
decl_stmt|;
name|struct
name|pci_dev
modifier|*
name|pci
decl_stmt|;
name|snd_card_t
modifier|*
name|card
decl_stmt|;
name|snd_pcm_t
modifier|*
name|pcm
decl_stmt|;
name|snd_pcm_t
modifier|*
name|pcm_mic
decl_stmt|;
name|snd_pcm_t
modifier|*
name|pcm_efx
decl_stmt|;
name|snd_pcm_t
modifier|*
name|pcm_fx8010
decl_stmt|;
name|spinlock_t
name|synth_lock
decl_stmt|;
name|void
modifier|*
name|synth
decl_stmt|;
name|int
function_decl|(
modifier|*
name|get_synth_voice
function_decl|)
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|)
function_decl|;
name|spinlock_t
name|reg_lock
decl_stmt|;
name|spinlock_t
name|emu_lock
decl_stmt|;
name|spinlock_t
name|voice_lock
decl_stmt|;
name|struct
name|semaphore
name|ptb_lock
decl_stmt|;
name|emu10k1_voice_t
name|voices
index|[
literal|64
index|]
decl_stmt|;
name|emu10k1_pcm_mixer_t
name|pcm_mixer
index|[
literal|32
index|]
decl_stmt|;
name|snd_kcontrol_t
modifier|*
name|ctl_send_routing
decl_stmt|;
name|snd_kcontrol_t
modifier|*
name|ctl_send_volume
decl_stmt|;
name|snd_kcontrol_t
modifier|*
name|ctl_attn
decl_stmt|;
name|void
function_decl|(
modifier|*
name|hwvol_interrupt
function_decl|)
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|unsigned
name|int
name|status
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|capture_interrupt
function_decl|)
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|unsigned
name|int
name|status
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|capture_mic_interrupt
function_decl|)
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|unsigned
name|int
name|status
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|capture_efx_interrupt
function_decl|)
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|unsigned
name|int
name|status
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|timer_interrupt
function_decl|)
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|spdif_interrupt
function_decl|)
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|unsigned
name|int
name|status
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|dsp_interrupt
function_decl|)
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|)
function_decl|;
name|snd_pcm_substream_t
modifier|*
name|pcm_capture_substream
decl_stmt|;
name|snd_pcm_substream_t
modifier|*
name|pcm_capture_mic_substream
decl_stmt|;
name|snd_pcm_substream_t
modifier|*
name|pcm_capture_efx_substream
decl_stmt|;
name|emu10k1_midi_t
name|midi
decl_stmt|;
name|emu10k1_midi_t
name|midi2
decl_stmt|;
comment|/* for audigy */
name|unsigned
name|int
name|efx_voices_mask
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|snd_emu10k1_create
parameter_list|(
name|snd_card_t
modifier|*
name|card
parameter_list|,
name|struct
name|pci_dev
modifier|*
name|pci
parameter_list|,
name|unsigned
name|short
name|extin_mask
parameter_list|,
name|unsigned
name|short
name|extout_mask
parameter_list|,
name|long
name|max_cache_bytes
parameter_list|,
name|int
name|enable_ir
parameter_list|,
name|emu10k1_t
modifier|*
modifier|*
name|remu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_emu10k1_pcm
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|int
name|device
parameter_list|,
name|snd_pcm_t
modifier|*
modifier|*
name|rpcm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_emu10k1_pcm_mic
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|int
name|device
parameter_list|,
name|snd_pcm_t
modifier|*
modifier|*
name|rpcm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_emu10k1_pcm_efx
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|int
name|device
parameter_list|,
name|snd_pcm_t
modifier|*
modifier|*
name|rpcm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_emu10k1_fx8010_pcm
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|int
name|device
parameter_list|,
name|snd_pcm_t
modifier|*
modifier|*
name|rpcm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_emu10k1_mixer
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_emu10k1_fx8010_new
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|int
name|device
parameter_list|,
name|snd_hwdep_t
modifier|*
modifier|*
name|rhwdep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|irqreturn_t
name|snd_emu10k1_interrupt
parameter_list|(
name|int
name|irq
parameter_list|,
name|void
modifier|*
name|dev_id
parameter_list|,
name|struct
name|pt_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* initialization */
end_comment

begin_function_decl
name|void
name|snd_emu10k1_voice_init
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|int
name|voice
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_emu10k1_init_efx
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snd_emu10k1_free_efx
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_emu10k1_fx8010_tram_setup
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|u32
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* I/O functions */
end_comment

begin_function_decl
name|unsigned
name|int
name|snd_emu10k1_ptr_read
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|unsigned
name|int
name|reg
parameter_list|,
name|unsigned
name|int
name|chn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snd_emu10k1_ptr_write
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|unsigned
name|int
name|reg
parameter_list|,
name|unsigned
name|int
name|chn
parameter_list|,
name|unsigned
name|int
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snd_emu10k1_efx_write
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|unsigned
name|int
name|pc
parameter_list|,
name|unsigned
name|int
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|snd_emu10k1_efx_read
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|unsigned
name|int
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snd_emu10k1_intr_enable
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|unsigned
name|int
name|intrenb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snd_emu10k1_intr_disable
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|unsigned
name|int
name|intrenb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snd_emu10k1_voice_intr_enable
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|unsigned
name|int
name|voicenum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snd_emu10k1_voice_intr_disable
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|unsigned
name|int
name|voicenum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snd_emu10k1_voice_intr_ack
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|unsigned
name|int
name|voicenum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snd_emu10k1_voice_set_loop_stop
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|unsigned
name|int
name|voicenum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snd_emu10k1_voice_clear_loop_stop
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|unsigned
name|int
name|voicenum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snd_emu10k1_wait
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|unsigned
name|int
name|wait
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|unsigned
name|int
name|snd_emu10k1_wc
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|)
block|{
return|return
operator|(
name|inl
argument_list|(
name|emu
operator|->
name|port
operator|+
name|WC
argument_list|)
operator|>>
literal|6
operator|)
operator|&
literal|0xfffff
return|;
block|}
end_function

begin_function_decl
name|unsigned
name|short
name|snd_emu10k1_ac97_read
parameter_list|(
name|ac97_t
modifier|*
name|ac97
parameter_list|,
name|unsigned
name|short
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snd_emu10k1_ac97_write
parameter_list|(
name|ac97_t
modifier|*
name|ac97
parameter_list|,
name|unsigned
name|short
name|reg
parameter_list|,
name|unsigned
name|short
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|snd_emu10k1_rate_to_pitch
parameter_list|(
name|unsigned
name|int
name|rate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|char
name|snd_emu10k1_sum_vol_attn
parameter_list|(
name|unsigned
name|int
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* memory allocation */
end_comment

begin_function_decl
name|snd_util_memblk_t
modifier|*
name|snd_emu10k1_alloc_pages
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|snd_pcm_substream_t
modifier|*
name|substream
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_emu10k1_free_pages
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|snd_util_memblk_t
modifier|*
name|blk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|snd_util_memblk_t
modifier|*
name|snd_emu10k1_synth_alloc
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_emu10k1_synth_free
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|snd_util_memblk_t
modifier|*
name|blk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_emu10k1_synth_bzero
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|snd_util_memblk_t
modifier|*
name|blk
parameter_list|,
name|int
name|offset
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_emu10k1_synth_copy_from_user
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|snd_util_memblk_t
modifier|*
name|blk
parameter_list|,
name|int
name|offset
parameter_list|,
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_emu10k1_memblk_map
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|emu10k1_memblk_t
modifier|*
name|blk
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* voice allocation */
end_comment

begin_function_decl
name|int
name|snd_emu10k1_voice_alloc
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|emu10k1_voice_type_t
name|type
parameter_list|,
name|int
name|pair
parameter_list|,
name|emu10k1_voice_t
modifier|*
modifier|*
name|rvoice
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_emu10k1_voice_free
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|,
name|emu10k1_voice_t
modifier|*
name|pvoice
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MIDI uart */
end_comment

begin_function_decl
name|int
name|snd_emu10k1_midi
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|snd_emu10k1_audigy_midi
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* proc interface */
end_comment

begin_function_decl
name|int
name|snd_emu10k1_proc_init
parameter_list|(
name|emu10k1_t
modifier|*
name|emu
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KERNEL__ */
end_comment

begin_comment
comment|/*  * ---- FX8010 ----  */
end_comment

begin_define
define|#
directive|define
name|EMU10K1_CARD_CREATIVE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EMU10K1_CARD_EMUAPS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EMU10K1_FX8010_PCM_COUNT
value|8
end_define

begin_comment
comment|/* instruction set */
end_comment

begin_define
define|#
directive|define
name|iMAC0
value|0x00
end_define

begin_comment
comment|/* R = A + (X * Y>> 31)   ; saturation */
end_comment

begin_define
define|#
directive|define
name|iMAC1
value|0x01
end_define

begin_comment
comment|/* R = A + (-X * Y>> 31)  ; saturation */
end_comment

begin_define
define|#
directive|define
name|iMAC2
value|0x02
end_define

begin_comment
comment|/* R = A + (X * Y>> 31)   ; wraparound */
end_comment

begin_define
define|#
directive|define
name|iMAC3
value|0x03
end_define

begin_comment
comment|/* R = A + (-X * Y>> 31)  ; wraparound */
end_comment

begin_define
define|#
directive|define
name|iMACINT0
value|0x04
end_define

begin_comment
comment|/* R = A + X * Y	   ; saturation */
end_comment

begin_define
define|#
directive|define
name|iMACINT1
value|0x05
end_define

begin_comment
comment|/* R = A + X * Y	   ; wraparound (31-bit) */
end_comment

begin_define
define|#
directive|define
name|iACC3
value|0x06
end_define

begin_comment
comment|/* R = A + X + Y	   ; saturation */
end_comment

begin_define
define|#
directive|define
name|iMACMV
value|0x07
end_define

begin_comment
comment|/* R = A, acc += X * Y>> 31 */
end_comment

begin_define
define|#
directive|define
name|iANDXOR
value|0x08
end_define

begin_comment
comment|/* R = (A& X) ^ Y */
end_comment

begin_define
define|#
directive|define
name|iTSTNEG
value|0x09
end_define

begin_comment
comment|/* R = (A>= Y) ? X : ~X */
end_comment

begin_define
define|#
directive|define
name|iLIMITGE
value|0x0a
end_define

begin_comment
comment|/* R = (A>= Y) ? X : Y */
end_comment

begin_define
define|#
directive|define
name|iLIMITLT
value|0x0b
end_define

begin_comment
comment|/* R = (A< Y) ? X : Y */
end_comment

begin_define
define|#
directive|define
name|iLOG
value|0x0c
end_define

begin_comment
comment|/* R = linear_data, A (log_data), X (max_exp), Y (format_word) */
end_comment

begin_define
define|#
directive|define
name|iEXP
value|0x0d
end_define

begin_comment
comment|/* R = log_data, A (linear_data), X (max_exp), Y (format_word) */
end_comment

begin_define
define|#
directive|define
name|iINTERP
value|0x0e
end_define

begin_comment
comment|/* R = A + (X * (Y - A)>> 31)  ; saturation */
end_comment

begin_define
define|#
directive|define
name|iSKIP
value|0x0f
end_define

begin_comment
comment|/* R = A (cc_reg), X (count), Y (cc_test) */
end_comment

begin_comment
comment|/* GPRs */
end_comment

begin_define
define|#
directive|define
name|FXBUS
parameter_list|(
name|x
parameter_list|)
value|(0x00 + (x))
end_define

begin_comment
comment|/* x = 0x00 - 0x0f */
end_comment

begin_define
define|#
directive|define
name|EXTIN
parameter_list|(
name|x
parameter_list|)
value|(0x10 + (x))
end_define

begin_comment
comment|/* x = 0x00 - 0x0f */
end_comment

begin_define
define|#
directive|define
name|EXTOUT
parameter_list|(
name|x
parameter_list|)
value|(0x20 + (x))
end_define

begin_comment
comment|/* x = 0x00 - 0x0f */
end_comment

begin_define
define|#
directive|define
name|C_00000000
value|0x40
end_define

begin_define
define|#
directive|define
name|C_00000001
value|0x41
end_define

begin_define
define|#
directive|define
name|C_00000002
value|0x42
end_define

begin_define
define|#
directive|define
name|C_00000003
value|0x43
end_define

begin_define
define|#
directive|define
name|C_00000004
value|0x44
end_define

begin_define
define|#
directive|define
name|C_00000008
value|0x45
end_define

begin_define
define|#
directive|define
name|C_00000010
value|0x46
end_define

begin_define
define|#
directive|define
name|C_00000020
value|0x47
end_define

begin_define
define|#
directive|define
name|C_00000100
value|0x48
end_define

begin_define
define|#
directive|define
name|C_00010000
value|0x49
end_define

begin_define
define|#
directive|define
name|C_00080000
value|0x4a
end_define

begin_define
define|#
directive|define
name|C_10000000
value|0x4b
end_define

begin_define
define|#
directive|define
name|C_20000000
value|0x4c
end_define

begin_define
define|#
directive|define
name|C_40000000
value|0x4d
end_define

begin_define
define|#
directive|define
name|C_80000000
value|0x4e
end_define

begin_define
define|#
directive|define
name|C_7fffffff
value|0x4f
end_define

begin_define
define|#
directive|define
name|C_ffffffff
value|0x50
end_define

begin_define
define|#
directive|define
name|C_fffffffe
value|0x51
end_define

begin_define
define|#
directive|define
name|C_c0000000
value|0x52
end_define

begin_define
define|#
directive|define
name|C_4f1bbcdc
value|0x53
end_define

begin_define
define|#
directive|define
name|C_5a7ef9db
value|0x54
end_define

begin_define
define|#
directive|define
name|C_00100000
value|0x55
end_define

begin_comment
comment|/* ?? */
end_comment

begin_define
define|#
directive|define
name|GPR_ACCU
value|0x56
end_define

begin_comment
comment|/* ACCUM, accumulator */
end_comment

begin_define
define|#
directive|define
name|GPR_COND
value|0x57
end_define

begin_comment
comment|/* CCR, condition register */
end_comment

begin_define
define|#
directive|define
name|GPR_NOISE0
value|0x58
end_define

begin_comment
comment|/* noise source */
end_comment

begin_define
define|#
directive|define
name|GPR_NOISE1
value|0x59
end_define

begin_comment
comment|/* noise source */
end_comment

begin_define
define|#
directive|define
name|GPR_IRQ
value|0x5a
end_define

begin_comment
comment|/* IRQ register */
end_comment

begin_define
define|#
directive|define
name|GPR_DBAC
value|0x5b
end_define

begin_comment
comment|/* TRAM Delay Base Address Counter */
end_comment

begin_define
define|#
directive|define
name|GPR
parameter_list|(
name|x
parameter_list|)
value|(FXGPREGBASE + (x))
end_define

begin_comment
comment|/* free GPRs: x = 0x00 - 0xff */
end_comment

begin_define
define|#
directive|define
name|ITRAM_DATA
parameter_list|(
name|x
parameter_list|)
value|(TANKMEMDATAREGBASE + 0x00 + (x))
end_define

begin_comment
comment|/* x = 0x00 - 0x7f */
end_comment

begin_define
define|#
directive|define
name|ETRAM_DATA
parameter_list|(
name|x
parameter_list|)
value|(TANKMEMDATAREGBASE + 0x80 + (x))
end_define

begin_comment
comment|/* x = 0x00 - 0x1f */
end_comment

begin_define
define|#
directive|define
name|ITRAM_ADDR
parameter_list|(
name|x
parameter_list|)
value|(TANKMEMADDRREGBASE + 0x00 + (x))
end_define

begin_comment
comment|/* x = 0x00 - 0x7f */
end_comment

begin_define
define|#
directive|define
name|ETRAM_ADDR
parameter_list|(
name|x
parameter_list|)
value|(TANKMEMADDRREGBASE + 0x80 + (x))
end_define

begin_comment
comment|/* x = 0x00 - 0x1f */
end_comment

begin_define
define|#
directive|define
name|A_FXBUS
parameter_list|(
name|x
parameter_list|)
value|(0x00 + (x))
end_define

begin_comment
comment|/* x = 0x00 - 0x3f? */
end_comment

begin_define
define|#
directive|define
name|A_EXTIN
parameter_list|(
name|x
parameter_list|)
value|(0x40 + (x))
end_define

begin_comment
comment|/* x = 0x00 - 0x1f? */
end_comment

begin_define
define|#
directive|define
name|A_EXTOUT
parameter_list|(
name|x
parameter_list|)
value|(0x60 + (x))
end_define

begin_comment
comment|/* x = 0x00 - 0x1f? */
end_comment

begin_define
define|#
directive|define
name|A_GPR
parameter_list|(
name|x
parameter_list|)
value|(A_FXGPREGBASE + (x))
end_define

begin_comment
comment|/* cc_reg constants */
end_comment

begin_define
define|#
directive|define
name|CC_REG_NORMALIZED
value|C_00000001
end_define

begin_define
define|#
directive|define
name|CC_REG_BORROW
value|C_00000002
end_define

begin_define
define|#
directive|define
name|CC_REG_MINUS
value|C_00000004
end_define

begin_define
define|#
directive|define
name|CC_REG_ZERO
value|C_00000008
end_define

begin_define
define|#
directive|define
name|CC_REG_SATURATE
value|C_00000010
end_define

begin_define
define|#
directive|define
name|CC_REG_NONZERO
value|C_00000100
end_define

begin_comment
comment|/* FX buses */
end_comment

begin_define
define|#
directive|define
name|FXBUS_PCM_LEFT
value|0x00
end_define

begin_define
define|#
directive|define
name|FXBUS_PCM_RIGHT
value|0x01
end_define

begin_define
define|#
directive|define
name|FXBUS_PCM_LEFT_REAR
value|0x02
end_define

begin_define
define|#
directive|define
name|FXBUS_PCM_RIGHT_REAR
value|0x03
end_define

begin_define
define|#
directive|define
name|FXBUS_MIDI_LEFT
value|0x04
end_define

begin_define
define|#
directive|define
name|FXBUS_MIDI_RIGHT
value|0x05
end_define

begin_define
define|#
directive|define
name|FXBUS_PCM_CENTER
value|0x06
end_define

begin_define
define|#
directive|define
name|FXBUS_PCM_LFE
value|0x07
end_define

begin_define
define|#
directive|define
name|FXBUS_MIDI_REVERB
value|0x0c
end_define

begin_define
define|#
directive|define
name|FXBUS_MIDI_CHORUS
value|0x0d
end_define

begin_comment
comment|/* Inputs */
end_comment

begin_define
define|#
directive|define
name|EXTIN_AC97_L
value|0x00
end_define

begin_comment
comment|/* AC'97 capture channel - left */
end_comment

begin_define
define|#
directive|define
name|EXTIN_AC97_R
value|0x01
end_define

begin_comment
comment|/* AC'97 capture channel - right */
end_comment

begin_define
define|#
directive|define
name|EXTIN_SPDIF_CD_L
value|0x02
end_define

begin_comment
comment|/* internal S/PDIF CD - onboard - left */
end_comment

begin_define
define|#
directive|define
name|EXTIN_SPDIF_CD_R
value|0x03
end_define

begin_comment
comment|/* internal S/PDIF CD - onboard - right */
end_comment

begin_define
define|#
directive|define
name|EXTIN_ZOOM_L
value|0x04
end_define

begin_comment
comment|/* Zoom Video I2S - left */
end_comment

begin_define
define|#
directive|define
name|EXTIN_ZOOM_R
value|0x05
end_define

begin_comment
comment|/* Zoom Video I2S - right */
end_comment

begin_define
define|#
directive|define
name|EXTIN_TOSLINK_L
value|0x06
end_define

begin_comment
comment|/* LiveDrive - TOSLink Optical - left */
end_comment

begin_define
define|#
directive|define
name|EXTIN_TOSLINK_R
value|0x07
end_define

begin_comment
comment|/* LiveDrive - TOSLink Optical - right */
end_comment

begin_define
define|#
directive|define
name|EXTIN_LINE1_L
value|0x08
end_define

begin_comment
comment|/* LiveDrive - Line/Mic 1 - left */
end_comment

begin_define
define|#
directive|define
name|EXTIN_LINE1_R
value|0x09
end_define

begin_comment
comment|/* LiveDrive - Line/Mic 1 - right */
end_comment

begin_define
define|#
directive|define
name|EXTIN_COAX_SPDIF_L
value|0x0a
end_define

begin_comment
comment|/* LiveDrive - Coaxial S/PDIF - left */
end_comment

begin_define
define|#
directive|define
name|EXTIN_COAX_SPDIF_R
value|0x0b
end_define

begin_comment
comment|/* LiveDrive - Coaxial S/PDIF - right */
end_comment

begin_define
define|#
directive|define
name|EXTIN_LINE2_L
value|0x0c
end_define

begin_comment
comment|/* LiveDrive - Line/Mic 2 - left */
end_comment

begin_define
define|#
directive|define
name|EXTIN_LINE2_R
value|0x0d
end_define

begin_comment
comment|/* LiveDrive - Line/Mic 2 - right */
end_comment

begin_comment
comment|/* Outputs */
end_comment

begin_define
define|#
directive|define
name|EXTOUT_AC97_L
value|0x00
end_define

begin_comment
comment|/* AC'97 playback channel - left */
end_comment

begin_define
define|#
directive|define
name|EXTOUT_AC97_R
value|0x01
end_define

begin_comment
comment|/* AC'97 playback channel - right */
end_comment

begin_define
define|#
directive|define
name|EXTOUT_TOSLINK_L
value|0x02
end_define

begin_comment
comment|/* LiveDrive - TOSLink Optical - left */
end_comment

begin_define
define|#
directive|define
name|EXTOUT_TOSLINK_R
value|0x03
end_define

begin_comment
comment|/* LiveDrive - TOSLink Optical - right */
end_comment

begin_define
define|#
directive|define
name|EXTOUT_CENTER
value|0x04
end_define

begin_comment
comment|/* SB Live 5.1 - center */
end_comment

begin_define
define|#
directive|define
name|EXTOUT_LFE
value|0x05
end_define

begin_comment
comment|/* SB Live 5.1 - LFE */
end_comment

begin_define
define|#
directive|define
name|EXTOUT_HEADPHONE_L
value|0x06
end_define

begin_comment
comment|/* LiveDrive - Headphone - left */
end_comment

begin_define
define|#
directive|define
name|EXTOUT_HEADPHONE_R
value|0x07
end_define

begin_comment
comment|/* LiveDrive - Headphone - right */
end_comment

begin_define
define|#
directive|define
name|EXTOUT_REAR_L
value|0x08
end_define

begin_comment
comment|/* Rear channel - left */
end_comment

begin_define
define|#
directive|define
name|EXTOUT_REAR_R
value|0x09
end_define

begin_comment
comment|/* Rear channel - right */
end_comment

begin_define
define|#
directive|define
name|EXTOUT_ADC_CAP_L
value|0x0a
end_define

begin_comment
comment|/* ADC Capture buffer - left */
end_comment

begin_define
define|#
directive|define
name|EXTOUT_ADC_CAP_R
value|0x0b
end_define

begin_comment
comment|/* ADC Capture buffer - right */
end_comment

begin_define
define|#
directive|define
name|EXTOUT_MIC_CAP
value|0x0c
end_define

begin_comment
comment|/* MIC Capture buffer */
end_comment

begin_define
define|#
directive|define
name|EXTOUT_ACENTER
value|0x11
end_define

begin_comment
comment|/* Analog Center */
end_comment

begin_define
define|#
directive|define
name|EXTOUT_ALFE
value|0x12
end_define

begin_comment
comment|/* Analog LFE */
end_comment

begin_comment
comment|/* Audigy Inputs */
end_comment

begin_define
define|#
directive|define
name|A_EXTIN_AC97_L
value|0x00
end_define

begin_comment
comment|/* AC'97 capture channel - left */
end_comment

begin_define
define|#
directive|define
name|A_EXTIN_AC97_R
value|0x01
end_define

begin_comment
comment|/* AC'97 capture channel - right */
end_comment

begin_define
define|#
directive|define
name|A_EXTIN_SPDIF_CD_L
value|0x02
end_define

begin_comment
comment|/* digital CD left */
end_comment

begin_define
define|#
directive|define
name|A_EXTIN_SPDIF_CD_R
value|0x03
end_define

begin_comment
comment|/* digital CD left */
end_comment

begin_define
define|#
directive|define
name|A_EXTIN_OPT_SPDIF_L
value|0x04
end_define

begin_comment
comment|/* audigy drive Optical SPDIF - left */
end_comment

begin_define
define|#
directive|define
name|A_EXTIN_OPT_SPDIF_R
value|0x05
end_define

begin_comment
comment|/*                              right */
end_comment

begin_define
define|#
directive|define
name|A_EXTIN_LINE2_L
value|0x08
end_define

begin_comment
comment|/* audigy drive line2/mic2 - left */
end_comment

begin_define
define|#
directive|define
name|A_EXTIN_LINE2_R
value|0x09
end_define

begin_comment
comment|/*                           right */
end_comment

begin_define
define|#
directive|define
name|A_EXTIN_RCA_SPDIF_L
value|0x0a
end_define

begin_comment
comment|/* audigy drive RCA SPDIF - left */
end_comment

begin_define
define|#
directive|define
name|A_EXTIN_RCA_SPDIF_R
value|0x0b
end_define

begin_comment
comment|/*                          right */
end_comment

begin_define
define|#
directive|define
name|A_EXTIN_AUX2_L
value|0x0c
end_define

begin_comment
comment|/* audigy drive aux2 - left */
end_comment

begin_define
define|#
directive|define
name|A_EXTIN_AUX2_R
value|0x0d
end_define

begin_comment
comment|/*                   - right */
end_comment

begin_comment
comment|/* Audigiy Outputs */
end_comment

begin_define
define|#
directive|define
name|A_EXTOUT_FRONT_L
value|0x00
end_define

begin_comment
comment|/* digital front left */
end_comment

begin_define
define|#
directive|define
name|A_EXTOUT_FRONT_R
value|0x01
end_define

begin_comment
comment|/*               right */
end_comment

begin_define
define|#
directive|define
name|A_EXTOUT_CENTER
value|0x02
end_define

begin_comment
comment|/* digital front center */
end_comment

begin_define
define|#
directive|define
name|A_EXTOUT_LFE
value|0x03
end_define

begin_comment
comment|/* digital front lfe */
end_comment

begin_define
define|#
directive|define
name|A_EXTOUT_HEADPHONE_L
value|0x04
end_define

begin_comment
comment|/* headphone audigy drive left */
end_comment

begin_define
define|#
directive|define
name|A_EXTOUT_HEADPHONE_R
value|0x05
end_define

begin_comment
comment|/*                        right */
end_comment

begin_define
define|#
directive|define
name|A_EXTOUT_REAR_L
value|0x06
end_define

begin_comment
comment|/* digital rear left */
end_comment

begin_define
define|#
directive|define
name|A_EXTOUT_REAR_R
value|0x07
end_define

begin_comment
comment|/*              right */
end_comment

begin_define
define|#
directive|define
name|A_EXTOUT_AFRONT_L
value|0x08
end_define

begin_comment
comment|/* analog front left */
end_comment

begin_define
define|#
directive|define
name|A_EXTOUT_AFRONT_R
value|0x09
end_define

begin_comment
comment|/*              right */
end_comment

begin_define
define|#
directive|define
name|A_EXTOUT_ACENTER
value|0x0a
end_define

begin_comment
comment|/* analog center */
end_comment

begin_define
define|#
directive|define
name|A_EXTOUT_ALFE
value|0x0b
end_define

begin_comment
comment|/* analog LFE */
end_comment

begin_comment
comment|/* 0x0c ?? */
end_comment

begin_comment
comment|/* 0x0d ?? */
end_comment

begin_define
define|#
directive|define
name|A_EXTOUT_AREAR_L
value|0x0e
end_define

begin_comment
comment|/* analog rear left */
end_comment

begin_define
define|#
directive|define
name|A_EXTOUT_AREAR_R
value|0x0f
end_define

begin_comment
comment|/*             right */
end_comment

begin_define
define|#
directive|define
name|A_EXTOUT_AC97_L
value|0x10
end_define

begin_comment
comment|/* AC97 left (front) */
end_comment

begin_define
define|#
directive|define
name|A_EXTOUT_AC97_R
value|0x11
end_define

begin_comment
comment|/*      right */
end_comment

begin_define
define|#
directive|define
name|A_EXTOUT_ADC_CAP_L
value|0x16
end_define

begin_comment
comment|/* ADC capture buffer left */
end_comment

begin_define
define|#
directive|define
name|A_EXTOUT_ADC_CAP_R
value|0x17
end_define

begin_comment
comment|/*                    right */
end_comment

begin_comment
comment|/* Audigy constants */
end_comment

begin_define
define|#
directive|define
name|A_C_00000000
value|0xc0
end_define

begin_define
define|#
directive|define
name|A_C_00000001
value|0xc1
end_define

begin_define
define|#
directive|define
name|A_C_00000002
value|0xc2
end_define

begin_define
define|#
directive|define
name|A_C_00000003
value|0xc3
end_define

begin_define
define|#
directive|define
name|A_C_00000004
value|0xc4
end_define

begin_define
define|#
directive|define
name|A_C_00000008
value|0xc5
end_define

begin_define
define|#
directive|define
name|A_C_00000010
value|0xc6
end_define

begin_define
define|#
directive|define
name|A_C_00000020
value|0xc7
end_define

begin_define
define|#
directive|define
name|A_C_00000100
value|0xc8
end_define

begin_define
define|#
directive|define
name|A_C_00010000
value|0xc9
end_define

begin_define
define|#
directive|define
name|A_C_00000800
value|0xca
end_define

begin_define
define|#
directive|define
name|A_C_10000000
value|0xcb
end_define

begin_define
define|#
directive|define
name|A_C_20000000
value|0xcc
end_define

begin_define
define|#
directive|define
name|A_C_40000000
value|0xcd
end_define

begin_define
define|#
directive|define
name|A_C_80000000
value|0xce
end_define

begin_define
define|#
directive|define
name|A_C_7fffffff
value|0xcf
end_define

begin_define
define|#
directive|define
name|A_C_ffffffff
value|0xd0
end_define

begin_define
define|#
directive|define
name|A_C_fffffffe
value|0xd1
end_define

begin_define
define|#
directive|define
name|A_C_c0000000
value|0xd2
end_define

begin_define
define|#
directive|define
name|A_C_4f1bbcdc
value|0xd3
end_define

begin_define
define|#
directive|define
name|A_C_5a7ef9db
value|0xd4
end_define

begin_define
define|#
directive|define
name|A_C_00100000
value|0xd5
end_define

begin_comment
comment|/* 0xd6 = 0x7fffffff  (?) ACCUM? */
end_comment

begin_comment
comment|/* 0xd7 = 0x0000000   CCR */
end_comment

begin_comment
comment|/* 0xd8 = noise1 */
end_comment

begin_comment
comment|/* 0xd9 = noise2 */
end_comment

begin_comment
comment|/* definitions for debug register */
end_comment

begin_define
define|#
directive|define
name|EMU10K1_DBG_ZC
value|0x80000000
end_define

begin_comment
comment|/* zero tram counter */
end_comment

begin_define
define|#
directive|define
name|EMU10K1_DBG_SATURATION_OCCURED
value|0x02000000
end_define

begin_comment
comment|/* saturation control */
end_comment

begin_define
define|#
directive|define
name|EMU10K1_DBG_SATURATION_ADDR
value|0x01ff0000
end_define

begin_comment
comment|/* saturation address */
end_comment

begin_define
define|#
directive|define
name|EMU10K1_DBG_SINGLE_STEP
value|0x00008000
end_define

begin_comment
comment|/* single step mode */
end_comment

begin_define
define|#
directive|define
name|EMU10K1_DBG_STEP
value|0x00004000
end_define

begin_comment
comment|/* start single step */
end_comment

begin_define
define|#
directive|define
name|EMU10K1_DBG_CONDITION_CODE
value|0x00003e00
end_define

begin_comment
comment|/* condition code */
end_comment

begin_define
define|#
directive|define
name|EMU10K1_DBG_SINGLE_STEP_ADDR
value|0x000001ff
end_define

begin_comment
comment|/* single step address */
end_comment

begin_comment
comment|/* tank memory address line */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__KERNEL__
end_ifndef

begin_define
define|#
directive|define
name|TANKMEMADDRREG_ADDR_MASK
value|0x000fffff
end_define

begin_comment
comment|/* 20 bit tank address field			*/
end_comment

begin_define
define|#
directive|define
name|TANKMEMADDRREG_CLEAR
value|0x00800000
end_define

begin_comment
comment|/* Clear tank memory				*/
end_comment

begin_define
define|#
directive|define
name|TANKMEMADDRREG_ALIGN
value|0x00400000
end_define

begin_comment
comment|/* Align read or write relative to tank access	*/
end_comment

begin_define
define|#
directive|define
name|TANKMEMADDRREG_WRITE
value|0x00200000
end_define

begin_comment
comment|/* Write to tank memory				*/
end_comment

begin_define
define|#
directive|define
name|TANKMEMADDRREG_READ
value|0x00100000
end_define

begin_comment
comment|/* Read from tank memory			*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|card
decl_stmt|;
comment|/* card type */
name|unsigned
name|int
name|internal_tram_size
decl_stmt|;
comment|/* in samples */
name|unsigned
name|int
name|external_tram_size
decl_stmt|;
comment|/* in samples */
name|char
name|fxbus_names
index|[
literal|16
index|]
index|[
literal|32
index|]
decl_stmt|;
comment|/* names of FXBUSes */
name|char
name|extin_names
index|[
literal|16
index|]
index|[
literal|32
index|]
decl_stmt|;
comment|/* names of external inputs */
name|char
name|extout_names
index|[
literal|32
index|]
index|[
literal|32
index|]
decl_stmt|;
comment|/* names of external outputs */
name|unsigned
name|int
name|gpr_controls
decl_stmt|;
comment|/* count of GPR controls */
block|}
name|emu10k1_fx8010_info_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EMU10K1_GPR_TRANSLATION_NONE
value|0
end_define

begin_define
define|#
directive|define
name|EMU10K1_GPR_TRANSLATION_TABLE100
value|1
end_define

begin_define
define|#
directive|define
name|EMU10K1_GRP_TRANSLATION_BASS
value|2
end_define

begin_define
define|#
directive|define
name|EMU10K1_GRP_TRANSLATION_TREBLE
value|3
end_define

begin_define
define|#
directive|define
name|EMU10K1_GPR_TRANSLATION_ONOFF
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|snd_ctl_elem_id_t
name|id
decl_stmt|;
comment|/* full control ID definition */
name|unsigned
name|int
name|vcount
decl_stmt|;
comment|/* visible count */
name|unsigned
name|int
name|count
decl_stmt|;
comment|/* count of GPR (1..16) */
name|unsigned
name|char
name|gpr
index|[
literal|32
index|]
decl_stmt|;
comment|/* GPR number(s) */
name|unsigned
name|int
name|value
index|[
literal|32
index|]
decl_stmt|;
comment|/* initial values */
name|unsigned
name|int
name|min
decl_stmt|;
comment|/* minimum range */
name|unsigned
name|int
name|max
decl_stmt|;
comment|/* maximum range */
name|unsigned
name|int
name|translation
decl_stmt|;
comment|/* translation type (EMU10K1_GRP_TRANSLATION*) */
block|}
name|emu10k1_fx8010_control_gpr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|name
index|[
literal|128
index|]
decl_stmt|;
name|unsigned
name|long
name|gpr_valid
index|[
literal|0x100
operator|/
operator|(
expr|sizeof
operator|(
name|unsigned
name|long
operator|)
operator|*
literal|8
block|)
struct|];
end_typedef

begin_comment
comment|/* bitmask of valid initializers */
end_comment

begin_decl_stmt
name|unsigned
name|int
name|gpr_map
index|[
literal|0x100
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* initializers */
end_comment

begin_decl_stmt
name|unsigned
name|int
name|gpr_add_control_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* count of GPR controls to add/replace */
end_comment

begin_decl_stmt
name|emu10k1_fx8010_control_gpr_t
modifier|*
name|gpr_add_controls
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* GPR controls to add/replace */
end_comment

begin_decl_stmt
name|unsigned
name|int
name|gpr_del_control_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* count of GPR controls to remove */
end_comment

begin_decl_stmt
name|snd_ctl_elem_id_t
modifier|*
name|gpr_del_controls
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* IDs of GPR controls to remove */
end_comment

begin_decl_stmt
name|unsigned
name|int
name|gpr_list_control_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* count of GPR controls to list */
end_comment

begin_decl_stmt
name|unsigned
name|int
name|gpr_list_control_total
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* total count of GPR controls */
end_comment

begin_decl_stmt
name|emu10k1_fx8010_control_gpr_t
modifier|*
name|gpr_list_controls
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* listed GPR controls */
end_comment

begin_expr_stmt
name|unsigned
name|long
name|tram_valid
index|[
literal|0xa0
operator|/
operator|(
expr|sizeof
operator|(
name|unsigned
name|long
operator|)
operator|*
literal|8
end_expr_stmt

begin_empty_stmt
unit|)]
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* bitmask of valid initializers */
end_comment

begin_decl_stmt
name|unsigned
name|int
name|tram_data_map
index|[
literal|0xa0
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* data initializers */
end_comment

begin_decl_stmt
name|unsigned
name|int
name|tram_addr_map
index|[
literal|0xa0
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* map initializers */
end_comment

begin_expr_stmt
name|unsigned
name|long
name|code_valid
index|[
literal|512
operator|/
operator|(
expr|sizeof
operator|(
name|unsigned
name|long
operator|)
operator|*
literal|8
end_expr_stmt

begin_empty_stmt
unit|)]
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* bitmask of valid instructions */
end_comment

begin_decl_stmt
name|unsigned
name|int
name|code
index|[
literal|512
index|]
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* one instruction - 64 bits */
end_comment

begin_empty_stmt
unit|} emu10k1_fx8010_code_t
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|address
decl_stmt|;
comment|/* 31.bit == 1 -> external TRAM */
name|unsigned
name|int
name|size
decl_stmt|;
comment|/* size in samples (4 bytes) */
name|unsigned
name|int
modifier|*
name|samples
decl_stmt|;
comment|/* pointer to samples (20-bit) */
comment|/* NULL->clear memory */
block|}
name|emu10k1_fx8010_tram_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|substream
decl_stmt|;
comment|/* substream number */
name|unsigned
name|int
name|res1
decl_stmt|;
comment|/* reserved */
name|unsigned
name|int
name|channels
decl_stmt|;
comment|/* 16-bit channels count, zero = remove this substream */
name|unsigned
name|int
name|tram_start
decl_stmt|;
comment|/* ring buffer position in TRAM (in samples) */
name|unsigned
name|int
name|buffer_size
decl_stmt|;
comment|/* count of buffered samples */
name|unsigned
name|char
name|gpr_size
decl_stmt|;
comment|/* GPR containing size of ringbuffer in samples (host) */
name|unsigned
name|char
name|gpr_ptr
decl_stmt|;
comment|/* GPR containing current pointer in the ring buffer (host = reset, FX8010) */
name|unsigned
name|char
name|gpr_count
decl_stmt|;
comment|/* GPR containing count of samples between two interrupts (host) */
name|unsigned
name|char
name|gpr_tmpcount
decl_stmt|;
comment|/* GPR containing current count of samples to interrupt (host = set, FX8010) */
name|unsigned
name|char
name|gpr_trigger
decl_stmt|;
comment|/* GPR containing trigger (activate) information (host) */
name|unsigned
name|char
name|gpr_running
decl_stmt|;
comment|/* GPR containing info if PCM is running (FX8010) */
name|unsigned
name|char
name|pad
decl_stmt|;
comment|/* reserved */
name|unsigned
name|char
name|etram
index|[
literal|32
index|]
decl_stmt|;
comment|/* external TRAM address& data (one per channel) */
name|unsigned
name|int
name|res2
decl_stmt|;
comment|/* reserved */
block|}
name|emu10k1_fx8010_pcm_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SNDRV_EMU10K1_IOCTL_INFO
value|_IOR ('H', 0x10, emu10k1_fx8010_info_t)
end_define

begin_define
define|#
directive|define
name|SNDRV_EMU10K1_IOCTL_CODE_POKE
value|_IOW ('H', 0x11, emu10k1_fx8010_code_t)
end_define

begin_define
define|#
directive|define
name|SNDRV_EMU10K1_IOCTL_CODE_PEEK
value|_IOW ('H', 0x12, emu10k1_fx8010_code_t)
end_define

begin_define
define|#
directive|define
name|SNDRV_EMU10K1_IOCTL_TRAM_SETUP
value|_IOW ('H', 0x20, int)
end_define

begin_define
define|#
directive|define
name|SNDRV_EMU10K1_IOCTL_TRAM_POKE
value|_IOW ('H', 0x21, emu10k1_fx8010_tram_t)
end_define

begin_define
define|#
directive|define
name|SNDRV_EMU10K1_IOCTL_TRAM_PEEK
value|_IOR ('H', 0x22, emu10k1_fx8010_tram_t)
end_define

begin_define
define|#
directive|define
name|SNDRV_EMU10K1_IOCTL_PCM_POKE
value|_IOW ('H', 0x30, emu10k1_fx8010_pcm_t)
end_define

begin_define
define|#
directive|define
name|SNDRV_EMU10K1_IOCTL_PCM_PEEK
value|_IOWR('H', 0x31, emu10k1_fx8010_pcm_t)
end_define

begin_define
define|#
directive|define
name|SNDRV_EMU10K1_IOCTL_STOP
value|_IO  ('H', 0x80)
end_define

begin_define
define|#
directive|define
name|SNDRV_EMU10K1_IOCTL_CONTINUE
value|_IO  ('H', 0x81)
end_define

begin_define
define|#
directive|define
name|SNDRV_EMU10K1_IOCTL_ZERO_TRAM_COUNTER
value|_IO ('H', 0x82)
end_define

begin_define
define|#
directive|define
name|SNDRV_EMU10K1_IOCTL_SINGLE_STEP
value|_IOW ('H', 0x83, int)
end_define

begin_define
define|#
directive|define
name|SNDRV_EMU10K1_IOCTL_DBG_READ
value|_IOR ('H', 0x84, int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SOUND_EMU10K1_H */
end_comment

end_unit

