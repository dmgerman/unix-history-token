begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007, 2008 Rui Paulo<rpaulo@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_define
define|#
directive|define
name|ASMC_MAXFANS
value|2
end_define

begin_struct
struct|struct
name|asmc_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
name|int
name|sc_nfan
decl_stmt|;
name|int16_t
name|sms_rest_x
decl_stmt|;
name|int16_t
name|sms_rest_y
decl_stmt|;
name|int16_t
name|sms_rest_z
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|sc_fan_tree
index|[
name|ASMC_MAXFANS
operator|+
literal|1
index|]
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|sc_temp_tree
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|sc_sms_tree
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|sc_light_tree
decl_stmt|;
name|struct
name|asmc_model
modifier|*
name|sc_model
decl_stmt|;
name|int
name|sc_rid_port
decl_stmt|;
name|int
name|sc_rid_irq
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_ioport
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_irq
decl_stmt|;
name|void
modifier|*
name|sc_cookie
decl_stmt|;
name|int
name|sc_sms_intrtype
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|sc_sms_tq
decl_stmt|;
name|struct
name|task
name|sc_sms_task
decl_stmt|;
name|uint8_t
name|sc_sms_intr_works
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Data port.  */
end_comment

begin_define
define|#
directive|define
name|ASMC_DATAPORT_READ
parameter_list|(
name|sc
parameter_list|)
value|bus_read_1(sc->sc_ioport, 0x00)
end_define

begin_define
define|#
directive|define
name|ASMC_DATAPORT_WRITE
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_1(sc->sc_ioport, 0x00, val)
end_define

begin_define
define|#
directive|define
name|ASMC_STATUS_MASK
value|0x0f
end_define

begin_comment
comment|/*  * Command port.  */
end_comment

begin_define
define|#
directive|define
name|ASMC_CMDPORT_READ
parameter_list|(
name|sc
parameter_list|)
value|bus_read_1(sc->sc_ioport, 0x04)
end_define

begin_define
define|#
directive|define
name|ASMC_CMDPORT_WRITE
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_1(sc->sc_ioport, 0x04, val)
end_define

begin_define
define|#
directive|define
name|ASMC_CMDREAD
value|0x10
end_define

begin_define
define|#
directive|define
name|ASMC_CMDWRITE
value|0x11
end_define

begin_comment
comment|/*  * Interrupt port.  */
end_comment

begin_define
define|#
directive|define
name|ASMC_INTPORT_READ
parameter_list|(
name|sc
parameter_list|)
value|bus_read_1(sc->sc_ioport, 0x1f)
end_define

begin_comment
comment|/* Number of keys */
end_comment

begin_define
define|#
directive|define
name|ASMC_NKEYS
value|"#KEY"
end_define

begin_comment
comment|/* RO; 4 bytes */
end_comment

begin_comment
comment|/*  * Fan control via SMC.  */
end_comment

begin_define
define|#
directive|define
name|ASMC_KEY_FANCOUNT
value|"FNum"
end_define

begin_comment
comment|/* RO; 1 byte */
end_comment

begin_define
define|#
directive|define
name|ASMC_KEY_FANMANUAL
value|"FS! "
end_define

begin_comment
comment|/* RW; 2 bytes */
end_comment

begin_define
define|#
directive|define
name|ASMC_KEY_FANSPEED
value|"F%dAc"
end_define

begin_comment
comment|/* RO; 2 bytes */
end_comment

begin_define
define|#
directive|define
name|ASMC_KEY_FANMINSPEED
value|"F%dMn"
end_define

begin_comment
comment|/* RO; 2 bytes */
end_comment

begin_define
define|#
directive|define
name|ASMC_KEY_FANMAXSPEED
value|"F%dMx"
end_define

begin_comment
comment|/* RO; 2 bytes */
end_comment

begin_define
define|#
directive|define
name|ASMC_KEY_FANSAFESPEED
value|"F%dSf"
end_define

begin_comment
comment|/* RO; 2 bytes */
end_comment

begin_define
define|#
directive|define
name|ASMC_KEY_FANTARGETSPEED
value|"F%dTg"
end_define

begin_comment
comment|/* RW; 2 bytes */
end_comment

begin_comment
comment|/*  * Sudden Motion Sensor (SMS).  */
end_comment

begin_define
define|#
directive|define
name|ASMC_SMS_INIT1
value|0xe0
end_define

begin_define
define|#
directive|define
name|ASMC_SMS_INIT2
value|0xf8
end_define

begin_define
define|#
directive|define
name|ASMC_KEY_SMS
value|"MOCN"
end_define

begin_comment
comment|/* RW; 2 bytes */
end_comment

begin_define
define|#
directive|define
name|ASMC_KEY_SMS_X
value|"MO_X"
end_define

begin_comment
comment|/* RO; 2 bytes */
end_comment

begin_define
define|#
directive|define
name|ASMC_KEY_SMS_Y
value|"MO_Y"
end_define

begin_comment
comment|/* RO; 2 bytes */
end_comment

begin_define
define|#
directive|define
name|ASMC_KEY_SMS_Z
value|"MO_Z"
end_define

begin_comment
comment|/* RO; 2 bytes */
end_comment

begin_define
define|#
directive|define
name|ASMC_KEY_SMS_LOW
value|"MOLT"
end_define

begin_comment
comment|/* RW; 2 bytes */
end_comment

begin_define
define|#
directive|define
name|ASMC_KEY_SMS_HIGH
value|"MOHT"
end_define

begin_comment
comment|/* RW; 2 bytes */
end_comment

begin_define
define|#
directive|define
name|ASMC_KEY_SMS_LOW_INT
value|"MOLD"
end_define

begin_comment
comment|/* RW; 1 byte */
end_comment

begin_define
define|#
directive|define
name|ASMC_KEY_SMS_HIGH_INT
value|"MOHD"
end_define

begin_comment
comment|/* RW; 1 byte */
end_comment

begin_define
define|#
directive|define
name|ASMC_KEY_SMS_FLAG
value|"MSDW"
end_define

begin_comment
comment|/* RW; 1 byte */
end_comment

begin_define
define|#
directive|define
name|ASMC_SMS_INTFF
value|0x60
end_define

begin_comment
comment|/* Free fall Interrupt */
end_comment

begin_define
define|#
directive|define
name|ASMC_SMS_INTHA
value|0x6f
end_define

begin_comment
comment|/* High Acceleration Interrupt */
end_comment

begin_define
define|#
directive|define
name|ASMC_SMS_INTSH
value|0x80
end_define

begin_comment
comment|/* Shock Interrupt */
end_comment

begin_comment
comment|/*  * Keyboard backlight.  */
end_comment

begin_define
define|#
directive|define
name|ASMC_KEY_LIGHTLEFT
value|"ALV0"
end_define

begin_comment
comment|/* RO; 6 bytes */
end_comment

begin_define
define|#
directive|define
name|ASMC_KEY_LIGHTRIGHT
value|"ALV1"
end_define

begin_comment
comment|/* RO; 6 bytes */
end_comment

begin_define
define|#
directive|define
name|ASMC_KEY_LIGHTVALUE
value|"LKSB"
end_define

begin_comment
comment|/* WO; 2 bytes */
end_comment

begin_comment
comment|/*  * Clamshell.  */
end_comment

begin_define
define|#
directive|define
name|ASMC_KEY_CLAMSHELL
value|"MSLD"
end_define

begin_comment
comment|/* RO; 1 byte */
end_comment

begin_comment
comment|/*  * Interrupt keys.  */
end_comment

begin_define
define|#
directive|define
name|ASMC_KEY_INTOK
value|"NTOK"
end_define

begin_comment
comment|/* WO; 1 byte */
end_comment

begin_comment
comment|/*  * Temperatures.  *  * First for MacBook, second for MacBook Pro, third for Intel Mac Mini,  * fourth the Mac Pro 8-core and finally the MacBook Air.  *  */
end_comment

begin_comment
comment|/* maximum array size for temperatures including the last NULL */
end_comment

begin_define
define|#
directive|define
name|ASMC_TEMP_MAX
value|36
end_define

begin_define
define|#
directive|define
name|ASMC_MB_TEMPS
value|{ "TB0T", "TN0P", "TN1P", "Th0H", "Th1H", \ 				  "TM0P", NULL }
end_define

begin_define
define|#
directive|define
name|ASMC_MB_TEMPNAMES
value|{ "enclosure", "northbridge1", \ 				  "northbridge2", "heatsink1", \ 				  "heatsink2", "memory", }
end_define

begin_define
define|#
directive|define
name|ASMC_MB_TEMPDESCS
value|{ "Enclosure Bottomside", \ 				  "Northbridge Point 1", \ 				  "Northbridge Point 2", "Heatsink 1", \ 				  "Heatsink 2", "Memory Bank A", }
end_define

begin_define
define|#
directive|define
name|ASMC_MBP_TEMPS
value|{ "TB0T", "Th0H", "Th1H", "Tm0P", \ 				  "TG0H", "TG0P", "TG0T", NULL }
end_define

begin_define
define|#
directive|define
name|ASMC_MBP_TEMPNAMES
value|{ "enclosure", "heatsink1", \ 				  "heatsink2", "memory", "graphics", \ 				  "graphicssink", "unknown", }
end_define

begin_define
define|#
directive|define
name|ASMC_MBP_TEMPDESCS
value|{ "Enclosure Bottomside", \ 				  "Heatsink 1", "Heatsink 2", \ 				  "Memory Controller", \ 				  "Graphics Chip", "Graphics Heatsink", \ 				  "Unknown", }
end_define

begin_define
define|#
directive|define
name|ASMC_MBP4_TEMPS
value|{ "TB0T", "Th0H", "Th1H", "Th2H", "Tm0P", \ 				  "TG0H", "TG0D", "TC0D", "TC0P", "Ts0P", \ 				  "TTF0", "TW0P", NULL }
end_define

begin_define
define|#
directive|define
name|ASMC_MBP4_TEMPNAMES
value|{ "enclosure", "heatsink1", "heatsink2", \ 				  "heatsink3", "memory", "graphicssink", \ 				  "graphics", "cpu", "cpu2", "unknown1", \ 				  "unknown2", "wireless", }
end_define

begin_define
define|#
directive|define
name|ASMC_MBP4_TEMPDESCS
value|{ "Enclosure Bottomside", \ 				  "Main Heatsink 1", "Main Heatsink 2", \ 				  "Main Heatsink 3", \ 				  "Memory Controller", \ 				  "Graphics Chip Heatsink", \ 				  "Graphics Chip Diode", \ 				  "CPU Temperature Diode", "CPU Point 2", \ 				  "Unknown", "Unknown", \ 				  "Wireless Module", }
end_define

begin_define
define|#
directive|define
name|ASMC_MM_TEMPS
value|{ "TN0P", "TN1P", NULL }
end_define

begin_define
define|#
directive|define
name|ASMC_MM_TEMPNAMES
value|{ "northbridge1", "northbridge2" }
end_define

begin_define
define|#
directive|define
name|ASMC_MM_TEMPDESCS
value|{ "Northbridge Point 1", \ 				  "Northbridge Point 2" }
end_define

begin_define
define|#
directive|define
name|ASMC_MP_TEMPS
value|{ "TA0P", "TCAG", "TCAH", "TCBG", "TCBH", \ 				  "TC0C", "TC0D", "TC0P", "TC1C", "TC1D", \ 				  "TC2C", "TC2D", "TC3C", "TC3D", "THTG", \ 				  "TH0P", "TH1P", "TH2P", "TH3P", "TMAP", \ 				  "TMAS", "TMBS", "TM0P", "TM0S", "TM1P", \ 				  "TM1S", "TM2P", "TM2S", "TM3S", "TM8P", \ 				  "TM8S", "TM9P", "TM9S", "TN0H", "TS0C", \ 				  NULL }
end_define

begin_define
define|#
directive|define
name|ASMC_MP_TEMPNAMES
value|{ "TA0P", "TCAG", "TCAH", "TCBG", "TCBH", \ 				  "TC0C", "TC0D", "TC0P", "TC1C", "TC1D", \ 				  "TC2C", "TC2D", "TC3C", "TC3D", "THTG", \ 				  "TH0P", "TH1P", "TH2P", "TH3P", "TMAP", \ 				  "TMAS", "TMBS", "TM0P", "TM0S", "TM1P", \ 				  "TM1S", "TM2P", "TM2S", "TM3S", "TM8P", \ 				  "TM8S", "TM9P", "TM9S", "TN0H", "TS0C", \ 				  NULL }
end_define

begin_define
define|#
directive|define
name|ASMC_MP_TEMPDESCS
value|{ "TA0P", "TCAG", "TCAH", "TCBG", "TCBH", \ 				  "TC0C", "TC0D", "TC0P", "TC1C", "TC1D", \ 				  "TC2C", "TC2D", "TC3C", "TC3D", "THTG", \ 				  "TH0P", "TH1P", "TH2P", "TH3P", "TMAP", \ 				  "TMAS", "TMBS", "TM0P", "TM0S", "TM1P", \ 				  "TM1S", "TM2P", "TM2S", "TM3S", "TM8P", \ 				  "TM8S", "TM9P", "TM9S", "TN0H", "TS0C", \ 				  NULL }
end_define

begin_define
define|#
directive|define
name|ASMC_MBA_TEMPS
value|{ "TB0T", NULL }
end_define

begin_define
define|#
directive|define
name|ASMC_MBA_TEMPNAMES
value|{ "enclosure" }
end_define

begin_define
define|#
directive|define
name|ASMC_MBA_TEMPDESCS
value|{ "Enclosure Bottom" }
end_define

end_unit

