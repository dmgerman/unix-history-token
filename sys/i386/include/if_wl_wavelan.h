begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: if_wl_wavelan.h,v 1.2 1997/08/01 03:33:43 msmith Exp $ */
end_comment

begin_comment
comment|/*   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain all copyright   *    notices, this list of conditions and the following disclaimer.  * 2. The names of the authors may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CHIPS_WAVELAN_H
end_ifndef

begin_define
define|#
directive|define
name|_CHIPS_WAVELAN_H
end_define

begin_comment
comment|/* This file contains definitions that are common for all versions of  * the NCR WaveLAN  */
end_comment

begin_define
define|#
directive|define
name|WAVELAN_ADDR_SIZE
value|6
end_define

begin_comment
comment|/* Size of a MAC address */
end_comment

begin_define
define|#
directive|define
name|WAVELAN_MTU
value|1500
end_define

begin_comment
comment|/* Maximum size of Wavelan packet */
end_comment

begin_comment
comment|/* Modem Management Controler write commands */
end_comment

begin_define
define|#
directive|define
name|MMC_ENCR_KEY
value|0x00
end_define

begin_comment
comment|/* to 0x07 */
end_comment

begin_define
define|#
directive|define
name|MMC_ENCR_ENABLE
value|0x08
end_define

begin_define
define|#
directive|define
name|MMC_DES_IO_INVERT
value|0x0a
end_define

begin_define
define|#
directive|define
name|MMC_LOOPT_SEL
value|0x10
end_define

begin_define
define|#
directive|define
name|MMC_JABBER_ENABLE
value|0x11
end_define

begin_define
define|#
directive|define
name|MMC_FREEZE
value|0x12
end_define

begin_define
define|#
directive|define
name|MMC_ANTEN_SEL
value|0x13
end_define

begin_define
define|#
directive|define
name|MMC_IFS
value|0x14
end_define

begin_define
define|#
directive|define
name|MMC_MOD_DELAY
value|0x15
end_define

begin_define
define|#
directive|define
name|MMC_JAM_TIME
value|0x16
end_define

begin_define
define|#
directive|define
name|MMC_THR_PRE_SET
value|0x18
end_define

begin_define
define|#
directive|define
name|MMC_DECAY_PRM
value|0x19
end_define

begin_define
define|#
directive|define
name|MMC_DECAY_UPDAT_PRM
value|0x1a
end_define

begin_define
define|#
directive|define
name|MMC_QUALITY_THR
value|0x1b
end_define

begin_define
define|#
directive|define
name|MMC_NETW_ID_L
value|0x1c
end_define

begin_define
define|#
directive|define
name|MMC_NETW_ID_H
value|0x1d
end_define

begin_define
define|#
directive|define
name|MMC_MODE_SEL
value|0x1e
end_define

begin_define
define|#
directive|define
name|MMC_EECTRL
value|0x20
end_define

begin_comment
comment|/* 2.4 Gz */
end_comment

begin_define
define|#
directive|define
name|MMC_EEADDR
value|0x21
end_define

begin_comment
comment|/* 2.4 Gz */
end_comment

begin_define
define|#
directive|define
name|MMC_EEDATAL
value|0x22
end_define

begin_comment
comment|/* 2.4 Gz */
end_comment

begin_define
define|#
directive|define
name|MMC_EEDATAH
value|0x23
end_define

begin_comment
comment|/* 2.4 Gz */
end_comment

begin_define
define|#
directive|define
name|MMC_ANALCTRL
value|0x24
end_define

begin_comment
comment|/* 2.4 Gz */
end_comment

begin_comment
comment|/* fields in MMC registers that relate to EEPROM in WaveMODEM daughtercard */
end_comment

begin_define
define|#
directive|define
name|MMC_EECTRL_EEPRE
value|0x10
end_define

begin_comment
comment|/* 2.4 Gz EEPROM Protect Reg Enable */
end_comment

begin_define
define|#
directive|define
name|MMC_EECTRL_DWLD
value|0x08
end_define

begin_comment
comment|/* 2.4 Gz EEPROM Download Synths   */
end_comment

begin_define
define|#
directive|define
name|MMC_EECTRL_EEOP
value|0x07
end_define

begin_comment
comment|/* 2.4 Gz EEPROM Opcode mask	 */
end_comment

begin_define
define|#
directive|define
name|MMC_EECTRL_EEOP_READ
value|0x06
end_define

begin_comment
comment|/* 2.4 Gz EEPROM Read Opcode	 */
end_comment

begin_define
define|#
directive|define
name|MMC_EEADDR_CHAN
value|0xf0
end_define

begin_comment
comment|/* 2.4 Gz EEPROM Channel # mask	 */
end_comment

begin_define
define|#
directive|define
name|MMC_EEADDR_WDCNT
value|0x0f
end_define

begin_comment
comment|/* 2.4 Gz EEPROM DNLD WordCount-1 */
end_comment

begin_define
define|#
directive|define
name|MMC_ANALCTRL_ANTPOL
value|0x02
end_define

begin_comment
comment|/* 2.4 Gz Antenna Polarity mask	 */
end_comment

begin_define
define|#
directive|define
name|MMC_ANALCTRL_EXTANT
value|0x01
end_define

begin_comment
comment|/* 2.4 Gz External Antenna mask	 */
end_comment

begin_comment
comment|/* MMC read register names */
end_comment

begin_define
define|#
directive|define
name|MMC_DCE_STATUS
value|0x10
end_define

begin_define
define|#
directive|define
name|MMC_CORRECT_NWID_L
value|0x14
end_define

begin_define
define|#
directive|define
name|MMC_CORRECT_NWID_H
value|0x15
end_define

begin_define
define|#
directive|define
name|MMC_WRONG_NWID_L
value|0x16
end_define

begin_define
define|#
directive|define
name|MMC_WRONG_NWID_H
value|0x17
end_define

begin_define
define|#
directive|define
name|MMC_THR_PRE_SET
value|0x18
end_define

begin_define
define|#
directive|define
name|MMC_SIGNAL_LVL
value|0x19
end_define

begin_define
define|#
directive|define
name|MMC_SILENCE_LVL
value|0x1a
end_define

begin_define
define|#
directive|define
name|MMC_SIGN_QUAL
value|0x1b
end_define

begin_define
define|#
directive|define
name|MMC_DES_AVAIL
value|0x09
end_define

begin_define
define|#
directive|define
name|MMC_EECTRLstat
value|0x20
end_define

begin_comment
comment|/* 2.4 Gz  EEPROM r/w/dwld status */
end_comment

begin_define
define|#
directive|define
name|MMC_EEDATALrv
value|0x22
end_define

begin_comment
comment|/* 2.4 Gz  EEPROM read value	  */
end_comment

begin_define
define|#
directive|define
name|MMC_EEDATAHrv
value|0x23
end_define

begin_comment
comment|/* 2.4 Gz  EEPROM read value	  */
end_comment

begin_comment
comment|/* fields in MMC registers that relate to EEPROM in WaveMODEM daughtercard */
end_comment

begin_define
define|#
directive|define
name|MMC_EECTRLstat_ID24
value|0xf0
end_define

begin_comment
comment|/* 2.4 Gz  =A0 rev-A, =B0 rev-B   */
end_comment

begin_define
define|#
directive|define
name|MMC_EECTRLstat_DWLD
value|0x08
end_define

begin_comment
comment|/* 2.4 Gz  Synth/Tx-Pwr DWLD busy */
end_comment

begin_define
define|#
directive|define
name|MMC_EECTRLstat_EEBUSY
value|0x04
end_define

begin_comment
comment|/* 2.4 Gz  EEPROM busy		  */
end_comment

begin_comment
comment|/* additional socket ioctl params for wl card     * see sys/sockio.h for numbers.  The 2nd params here  * must be greater than any values in sockio.h  */
end_comment

begin_define
define|#
directive|define
name|SIOCGWLCNWID
value|_IOWR('i', 60, struct ifreq)
end_define

begin_comment
comment|/* get wlan current nwid */
end_comment

begin_define
define|#
directive|define
name|SIOCSWLCNWID
value|_IOWR('i', 61, struct ifreq)
end_define

begin_comment
comment|/* set wlan current nwid */
end_comment

begin_define
define|#
directive|define
name|SIOCGWLPSA
value|_IOWR('i', 62, struct ifreq)
end_define

begin_comment
comment|/* get wlan PSA (all) */
end_comment

begin_define
define|#
directive|define
name|SIOCSWLPSA
value|_IOWR('i', 63, struct ifreq)
end_define

begin_comment
comment|/* set wlan PSA (all) */
end_comment

begin_define
define|#
directive|define
name|SIOCDWLCACHE
value|_IOW('i',  64, struct ifreq)
end_define

begin_comment
comment|/* clear SNR cache    */
end_comment

begin_define
define|#
directive|define
name|SIOCSWLTHR
value|_IOW('i',  65, struct ifreq)
end_define

begin_comment
comment|/* set new quality threshold */
end_comment

begin_define
define|#
directive|define
name|SIOCGWLEEPROM
value|_IOWR('i', 66, struct ifreq)
end_define

begin_comment
comment|/* get modem EEPROM   */
end_comment

begin_define
define|#
directive|define
name|SIOCGWLCACHE
value|_IOWR('i', 67, struct ifreq)
end_define

begin_comment
comment|/* get SNR cache */
end_comment

begin_define
define|#
directive|define
name|SIOCGWLCITEM
value|_IOWR('i', 68, struct ifreq)
end_define

begin_comment
comment|/* get cache element count */
end_comment

begin_comment
comment|/* PSA address definitions */
end_comment

begin_define
define|#
directive|define
name|WLPSA_ID
value|0x0
end_define

begin_comment
comment|/* ID byte (0 for ISA, 0x14 for MCA) */
end_comment

begin_define
define|#
directive|define
name|WLPSA_IO1
value|0x1
end_define

begin_comment
comment|/* I/O address 1 */
end_comment

begin_define
define|#
directive|define
name|WLPSA_IO2
value|0x2
end_define

begin_comment
comment|/* I/O address 2 */
end_comment

begin_define
define|#
directive|define
name|WLPSA_IO3
value|0x3
end_define

begin_comment
comment|/* I/O address 3 */
end_comment

begin_define
define|#
directive|define
name|WLPSA_BR1
value|0x4
end_define

begin_comment
comment|/* Bootrom address 1 */
end_comment

begin_define
define|#
directive|define
name|WLPSA_BR2
value|0x5
end_define

begin_comment
comment|/* Bootrom address 2 */
end_comment

begin_define
define|#
directive|define
name|WLPSA_BR3
value|0x6
end_define

begin_comment
comment|/* Bootrom address 3 */
end_comment

begin_define
define|#
directive|define
name|WLPSA_HWCONF
value|0x7
end_define

begin_comment
comment|/* HW config bits */
end_comment

begin_define
define|#
directive|define
name|WLPSA_IRQNO
value|0x8
end_define

begin_comment
comment|/* IRQ value */
end_comment

begin_define
define|#
directive|define
name|WLPSA_UNIMAC
value|0x10
end_define

begin_comment
comment|/* Universal MAC address */
end_comment

begin_define
define|#
directive|define
name|WLPSA_LOCALMAC
value|0x16
end_define

begin_comment
comment|/* Locally configured MAC address */
end_comment

begin_define
define|#
directive|define
name|WLPSA_MACSEL
value|0x1c
end_define

begin_comment
comment|/* MAC selector */
end_comment

begin_define
define|#
directive|define
name|WLPSA_COMPATNO
value|0x1d
end_define

begin_comment
comment|/* compatability number */
end_comment

begin_define
define|#
directive|define
name|WLPSA_THRESH
value|0x1e
end_define

begin_comment
comment|/* RF modem threshold preset */
end_comment

begin_define
define|#
directive|define
name|WLPSA_FEATSEL
value|0x1f
end_define

begin_comment
comment|/* feature select */
end_comment

begin_define
define|#
directive|define
name|WLPSA_SUBBAND
value|0x20
end_define

begin_comment
comment|/* subband selector */
end_comment

begin_define
define|#
directive|define
name|WLPSA_QUALTHRESH
value|0x21
end_define

begin_comment
comment|/* RF modem quality threshold preset */
end_comment

begin_define
define|#
directive|define
name|WLPSA_HWVERSION
value|0x22
end_define

begin_comment
comment|/* hardware version indicator */
end_comment

begin_define
define|#
directive|define
name|WLPSA_NWID
value|0x23
end_define

begin_comment
comment|/* network ID */
end_comment

begin_define
define|#
directive|define
name|WLPSA_NWIDENABLE
value|0x24
end_define

begin_comment
comment|/* network ID enable */
end_comment

begin_define
define|#
directive|define
name|WLPSA_SECURITY
value|0x25
end_define

begin_comment
comment|/* datalink security enable */
end_comment

begin_define
define|#
directive|define
name|WLPSA_DESKEY
value|0x26
end_define

begin_comment
comment|/* datalink security DES key */
end_comment

begin_define
define|#
directive|define
name|WLPSA_DBWIDTH
value|0x2f
end_define

begin_comment
comment|/* databus width select */
end_comment

begin_define
define|#
directive|define
name|WLPSA_CALLCODE
value|0x30
end_define

begin_comment
comment|/* call code (japan only) */
end_comment

begin_define
define|#
directive|define
name|WLPSA_CONFIGURED
value|0x3c
end_define

begin_comment
comment|/* configuration status */
end_comment

begin_define
define|#
directive|define
name|WLPSA_CRCLOW
value|0x3d
end_define

begin_comment
comment|/* CRC-16 (lowbyte) */
end_comment

begin_define
define|#
directive|define
name|WLPSA_CRCHIGH
value|0x3e
end_define

begin_comment
comment|/*        (highbyte) */
end_comment

begin_define
define|#
directive|define
name|WLPSA_CRCOK
value|0x3f
end_define

begin_comment
comment|/* CRC OK flag */
end_comment

begin_define
define|#
directive|define
name|WLPSA_COMPATNO_WL24B
value|0x04
end_define

begin_comment
comment|/* 2.4 Gz WaveMODEM ISA rev-B  */
end_comment

begin_comment
comment|/*   * signal strength cache  *  * driver (wlp only at the moment) keeps cache of last  * IP (only) packets to arrive including signal strength info.  * daemons may read this with kvm.  See if_wlp.c for globals  * that may be accessed through kvm.  *  * Each entry in the w_sigcache has a unique macsrc and age.  * Each entry is identified by its macsrc field.  * Age of the packet is identified by its age field.  */
end_comment

begin_define
define|#
directive|define
name|MAXCACHEITEMS
value|10
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|INT_MAX
end_ifndef

begin_define
define|#
directive|define
name|INT_MAX
value|2147483647
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAX_AGE
value|(INT_MAX - MAXCACHEITEMS)
end_define

begin_comment
comment|/* signal is 7 bits, 0..63, although it doesn't seem to get to 63.  * silence is 7 bits, 0..63  * quality is 4 bits, 0..15  */
end_comment

begin_struct
struct|struct
name|w_sigcache
block|{
name|char
name|macsrc
index|[
literal|6
index|]
decl_stmt|;
comment|/* unique MAC address for entry */
name|int
name|ipsrc
decl_stmt|;
comment|/* ip address associated with packet */
name|int
name|signal
decl_stmt|;
comment|/* signal strength of the packet */
name|int
name|silence
decl_stmt|;
comment|/* silence of the packet */
name|int
name|quality
decl_stmt|;
comment|/* quality of the packet */
name|int
name|snr
decl_stmt|;
comment|/* packet has unique age between 1 to MAX_AGE - 1 */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CHIPS_WAVELAN_H */
end_comment

end_unit

