begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998, 1999, 2000-2003  *	Bill Paul<wpaul@windriver.com>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Definitions for the ASIX Electronics AX88172 to ethernet controller.  */
end_comment

begin_comment
comment|/*  * Vendor specific commands  * ASIX conveniently doesn't document the 'set NODEID' command in their  * datasheet (thanks a lot guys).  * To make handling these commands easier, I added some extra data  * which is decided by the axe_cmd() routine. Commands are encoded  * in 16 bites, with the format: LDCC. L and D are both nibbles in  * the high byte. L represents the data length (0 to 15) and D  * represents the direction (0 for vendor read, 1 for vendor write).  * CC is the command byte, as specified in the manual.  */
end_comment

begin_define
define|#
directive|define
name|AXE_CMD_DIR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x0F00)>> 8)
end_define

begin_define
define|#
directive|define
name|AXE_CMD_LEN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF000)>> 12)
end_define

begin_define
define|#
directive|define
name|AXE_CMD_CMD
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x00FF)
end_define

begin_define
define|#
directive|define
name|AXE_CMD_READ_RXTX_SRAM
value|0x2002
end_define

begin_define
define|#
directive|define
name|AXE_CMD_WRITE_RX_SRAM
value|0x0103
end_define

begin_define
define|#
directive|define
name|AXE_CMD_WRITE_TX_SRAM
value|0x0104
end_define

begin_define
define|#
directive|define
name|AXE_CMD_MII_OPMODE_SW
value|0x0106
end_define

begin_define
define|#
directive|define
name|AXE_CMD_MII_READ_REG
value|0x2007
end_define

begin_define
define|#
directive|define
name|AXE_CMD_MII_WRITE_REG
value|0x2108
end_define

begin_define
define|#
directive|define
name|AXE_CMD_MII_READ_OPMODE
value|0x1009
end_define

begin_define
define|#
directive|define
name|AXE_CMD_MII_OPMODE_HW
value|0x010A
end_define

begin_define
define|#
directive|define
name|AXE_CMD_SROM_READ
value|0x200B
end_define

begin_define
define|#
directive|define
name|AXE_CMD_SROM_WRITE
value|0x010C
end_define

begin_define
define|#
directive|define
name|AXE_CMD_SROM_WR_ENABLE
value|0x010D
end_define

begin_define
define|#
directive|define
name|AXE_CMD_SROM_WR_DISABLE
value|0x010E
end_define

begin_define
define|#
directive|define
name|AXE_CMD_RXCTL_READ
value|0x200F
end_define

begin_define
define|#
directive|define
name|AXE_CMD_RXCTL_WRITE
value|0x0110
end_define

begin_define
define|#
directive|define
name|AXE_CMD_READ_IPG012
value|0x3011
end_define

begin_define
define|#
directive|define
name|AXE_CMD_WRITE_IPG0
value|0x0112
end_define

begin_define
define|#
directive|define
name|AXE_CMD_WRITE_IPG1
value|0x0113
end_define

begin_define
define|#
directive|define
name|AXE_CMD_WRITE_IPG2
value|0x0114
end_define

begin_define
define|#
directive|define
name|AXE_CMD_READ_MCAST
value|0x8015
end_define

begin_define
define|#
directive|define
name|AXE_CMD_WRITE_MCAST
value|0x8116
end_define

begin_define
define|#
directive|define
name|AXE_CMD_READ_NODEID
value|0x6017
end_define

begin_define
define|#
directive|define
name|AXE_CMD_WRITE_NODEID
value|0x6118
end_define

begin_define
define|#
directive|define
name|AXE_CMD_READ_PHYID
value|0x2019
end_define

begin_define
define|#
directive|define
name|AXE_CMD_READ_MEDIA
value|0x101A
end_define

begin_define
define|#
directive|define
name|AXE_CMD_WRITE_MEDIA
value|0x011B
end_define

begin_define
define|#
directive|define
name|AXE_CMD_READ_MONITOR_MODE
value|0x101C
end_define

begin_define
define|#
directive|define
name|AXE_CMD_WRITE_MONITOR_MODE
value|0x011D
end_define

begin_define
define|#
directive|define
name|AXE_CMD_READ_GPIO
value|0x101E
end_define

begin_define
define|#
directive|define
name|AXE_CMD_WRITE_GPIO
value|0x011F
end_define

begin_define
define|#
directive|define
name|AXE_RXCMD_PROMISC
value|0x0001
end_define

begin_define
define|#
directive|define
name|AXE_RXCMD_ALLMULTI
value|0x0002
end_define

begin_define
define|#
directive|define
name|AXE_RXCMD_UNICAST
value|0x0004
end_define

begin_define
define|#
directive|define
name|AXE_RXCMD_BROADCAST
value|0x0008
end_define

begin_define
define|#
directive|define
name|AXE_RXCMD_MULTICAST
value|0x0010
end_define

begin_define
define|#
directive|define
name|AXE_RXCMD_ENABLE
value|0x0080
end_define

begin_define
define|#
directive|define
name|AXE_NOPHY
value|0xE0
end_define

begin_define
define|#
directive|define
name|AXE_TIMEOUT
value|1000
end_define

begin_define
define|#
directive|define
name|AXE_MIN_FRAMELEN
value|60
end_define

begin_define
define|#
directive|define
name|AXE_RX_FRAMES
value|1
end_define

begin_define
define|#
directive|define
name|AXE_TX_FRAMES
value|1
end_define

begin_define
define|#
directive|define
name|AXE_CTL_READ
value|0x01
end_define

begin_define
define|#
directive|define
name|AXE_CTL_WRITE
value|0x02
end_define

begin_define
define|#
directive|define
name|AXE_CONFIG_NO
value|1
end_define

begin_define
define|#
directive|define
name|AXE_IFACE_IDX
value|0
end_define

begin_comment
comment|/*  * The interrupt endpoint is currently unused  * by the ASIX part.  */
end_comment

begin_define
define|#
directive|define
name|AXE_ENDPT_RX
value|0x0
end_define

begin_define
define|#
directive|define
name|AXE_ENDPT_TX
value|0x1
end_define

begin_define
define|#
directive|define
name|AXE_ENDPT_INTR
value|0x2
end_define

begin_define
define|#
directive|define
name|AXE_ENDPT_MAX
value|0x3
end_define

begin_struct
struct|struct
name|axe_type
block|{
name|u_int16_t
name|axe_vid
decl_stmt|;
name|u_int16_t
name|axe_did
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AXE_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x) = (x + 1) % y
end_define

begin_struct
struct|struct
name|axe_softc
block|{
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
define|#
directive|define
name|GET_MII
parameter_list|(
name|sc
parameter_list|)
value|(device_get_softc((sc)->axe_miibus))
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
define|#
directive|define
name|GET_MII
parameter_list|(
name|sc
parameter_list|)
value|(&(sc)->axe_mii)
elif|#
directive|elif
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
define|#
directive|define
name|GET_MII
parameter_list|(
name|sc
parameter_list|)
value|(&(sc)->axe_mii)
endif|#
directive|endif
name|struct
name|ifnet
modifier|*
name|axe_ifp
decl_stmt|;
name|device_t
name|axe_miibus
decl_stmt|;
name|device_t
name|axe_dev
decl_stmt|;
name|usbd_device_handle
name|axe_udev
decl_stmt|;
name|usbd_interface_handle
name|axe_iface
decl_stmt|;
name|int
name|axe_ed
index|[
name|AXE_ENDPT_MAX
index|]
decl_stmt|;
name|usbd_pipe_handle
name|axe_ep
index|[
name|AXE_ENDPT_MAX
index|]
decl_stmt|;
name|int
name|axe_unit
decl_stmt|;
name|int
name|axe_if_flags
decl_stmt|;
name|struct
name|ue_cdata
name|axe_cdata
decl_stmt|;
name|struct
name|callout_handle
name|axe_stat_ch
decl_stmt|;
name|struct
name|mtx
name|axe_mtx
decl_stmt|;
name|struct
name|sx
name|axe_sleeplock
decl_stmt|;
name|char
name|axe_dying
decl_stmt|;
name|int
name|axe_link
decl_stmt|;
name|unsigned
name|char
name|axe_ipgs
index|[
literal|3
index|]
decl_stmt|;
name|unsigned
name|char
name|axe_phyaddrs
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|timeval
name|axe_rx_notice
decl_stmt|;
name|struct
name|usb_qdat
name|axe_qdat
decl_stmt|;
name|struct
name|usb_task
name|axe_tick_task
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|AXE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->axe_mtx)
end_define

begin_define
define|#
directive|define
name|AXE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->axe_mtx)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AXE_LOCK
parameter_list|(
name|_sc
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AXE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AXE_SLEEPLOCK
parameter_list|(
name|_sc
parameter_list|)
value|sx_xlock(&(_sc)->axe_sleeplock)
end_define

begin_define
define|#
directive|define
name|AXE_SLEEPUNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|sx_xunlock(&(_sc)->axe_sleeplock)
end_define

begin_define
define|#
directive|define
name|AXE_SLEEPLOCKASSERT
parameter_list|(
name|_sc
parameter_list|)
value|sx_assert(&(_sc)->axe_sleeplock, SX_XLOCKED)
end_define

end_unit

