begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  **********************************************************************  *     emu10k1.h, derived from 8010.h  *     Copyright 1999, 2000 Creative Labs, Inc.  *  **********************************************************************  *  *     Date		    Author	    Summary of changes  *     ----		    ------	    ------------------  *     October 20, 1999     Bertrand Lee    base code release  *     November 2, 1999     Alan Cox	    Cleaned of 8bit chars, DOS  *					    line endings  *     December 8, 1999     Jon Taylor	    Added lots of new register info  *  **********************************************************************  *  *     This program is free software; you can redistribute it and/or  *     modify it under the terms of the GNU General Public License as  *     published by the Free Software Foundation; either version 2 of  *     the License, or (at your option) any later version.  *  *     This program is distributed in the hope that it will be useful,  *     but WITHOUT ANY WARRANTY; without even the implied warranty of  *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  *     GNU General Public License for more details.  *  *     You should have received a copy of the GNU General Public  *     License along with this program; if not, write to the Free  *     Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139,  *     USA.  *  *  **********************************************************************  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EMU10K1_H
end_ifndef

begin_define
define|#
directive|define
name|EMU10K1_H
end_define

begin_comment
comment|/* ------------------- DEFINES -------------------- */
end_comment

begin_define
define|#
directive|define
name|EMUPAGESIZE
value|4096
end_define

begin_comment
comment|/* don't change */
end_comment

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
value|(32768 * 64 / EMUPAGESIZE)
end_define

begin_comment
comment|/* WAVEOUT_MAXBUFSIZE * NUM_G / EMUPAGESIZE */
end_comment

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
value|0x0x0000e0
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
name|HCFG_LOCKTANKCACHE
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
comment|/* AC97 pointer-offset register set, accessed through the AC97ADDRESS and AC97DATA registers		*/
end_comment

begin_comment
comment|/********************************************************************************************************/
end_comment

begin_define
define|#
directive|define
name|AC97_RESET
value|0x00
end_define

begin_define
define|#
directive|define
name|AC97_MASTERVOLUME
value|0x02
end_define

begin_comment
comment|/* Master volume					*/
end_comment

begin_define
define|#
directive|define
name|AC97_HEADPHONEVOLUME
value|0x04
end_define

begin_comment
comment|/* Headphone volume					*/
end_comment

begin_define
define|#
directive|define
name|AC97_MASTERVOLUMEMONO
value|0x06
end_define

begin_comment
comment|/* Mast volume mono					*/
end_comment

begin_define
define|#
directive|define
name|AC97_MASTERTONE
value|0x08
end_define

begin_define
define|#
directive|define
name|AC97_PCBEEPVOLUME
value|0x0a
end_define

begin_comment
comment|/* PC speaker system beep volume			*/
end_comment

begin_define
define|#
directive|define
name|AC97_PHONEVOLUME
value|0x0c
end_define

begin_define
define|#
directive|define
name|AC97_MICVOLUME
value|0x0e
end_define

begin_define
define|#
directive|define
name|AC97_LINEINVOLUME
value|0x10
end_define

begin_define
define|#
directive|define
name|AC97_CDVOLUME
value|0x12
end_define

begin_define
define|#
directive|define
name|AC97_VIDEOVOLUME
value|0x14
end_define

begin_define
define|#
directive|define
name|AC97_AUXVOLUME
value|0x16
end_define

begin_define
define|#
directive|define
name|AC97_PCMOUTVOLUME
value|0x18
end_define

begin_define
define|#
directive|define
name|AC97_RECORDSELECT
value|0x1a
end_define

begin_define
define|#
directive|define
name|AC97_RECORDGAIN
value|0x1c
end_define

begin_define
define|#
directive|define
name|AC97_RECORDGAINMIC
value|0x1e
end_define

begin_define
define|#
directive|define
name|AC97_GENERALPUPOSE
value|0x20
end_define

begin_define
define|#
directive|define
name|AC97_3DCONTROL
value|0x22
end_define

begin_define
define|#
directive|define
name|AC97_MODEMRATE
value|0x24
end_define

begin_define
define|#
directive|define
name|AC97_POWERDOWN
value|0x26
end_define

begin_define
define|#
directive|define
name|AC97_VENDORID1
value|0x7c
end_define

begin_define
define|#
directive|define
name|AC97_VENDORID2
value|0x7e
end_define

begin_define
define|#
directive|define
name|AC97_ZVIDEOVOLUME
value|0xec
end_define

begin_define
define|#
directive|define
name|AC97_AC3VOLUME
value|0xed
end_define

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
name|VTFT_FILTERTARGET_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* Filter cutoff target of specified channel		*/
end_comment

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

begin_define
define|#
directive|define
name|ENABLE
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|DISABLE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ENV_ON
value|0x80
end_define

begin_define
define|#
directive|define
name|ENV_OFF
value|0x00
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EMU10K1_H */
end_comment

end_unit

