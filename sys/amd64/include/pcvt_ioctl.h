begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 2000 Hellmuth Michaelis  * Copyright (c) 1992, 1995 Joerg Wunsch.  * Copyright (c) 1992, 1993 Brian Dunford-Shore and Holger Veit.  * Copyright (C) 1992, 1993 Soeren Schmidt.  * All rights reserved.  *  * For the sake of compatibility, portions of this code regarding the  * X server interface are taken from Soeren Schmidt's syscons driver.  *  * This code is derived from software contributed to 386BSD by  * Holger Veit.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz and Don Ahn.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by  * 	Hellmuth Michaelis, Brian Dunford-Shore, Joerg Wunsch, Holger Veit  *	and Soeren Schmidt.  * 4. The name authors may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------  *  *	pcvt_ioctl.h	ioctl's for the VT220 video driver 'pcvt'  *	---------------------------------------------------------  *  *	Last Edit-Date: [Fri Mar 31 10:22:29 2000]  *  * $FreeBSD$  *   *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PCVT_IOCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PCVT_IOCTL_H_
end_define

begin_comment
comment|/* pcvt version information for VGAPCVTID ioctl */
end_comment

begin_define
define|#
directive|define
name|PCVTIDNAME
value|"pcvt"
end_define

begin_comment
comment|/* driver id - string		*/
end_comment

begin_define
define|#
directive|define
name|PCVTIDMAJOR
value|3
end_define

begin_comment
comment|/* driver id - major release	*/
end_comment

begin_define
define|#
directive|define
name|PCVTIDMINOR
value|60
end_define

begin_comment
comment|/* driver id - minor release	*/
end_comment

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_define
define|#
directive|define
name|VGAPCVTID
value|_IOWR('V',113, struct pcvtid)
end_define

begin_comment
comment|/* get driver id */
end_comment

begin_struct
struct|struct
name|pcvtid
block|{
comment|/* THIS STRUCTURE IS NOW FROZEN !!! */
define|#
directive|define
name|PCVTIDNAMELN
value|16
comment|/* driver id - string length	*/
name|char
name|name
index|[
name|PCVTIDNAMELN
index|]
decl_stmt|;
comment|/* driver name, == PCVTIDSTR	*/
name|int
name|rmajor
decl_stmt|;
comment|/* revision number, major	*/
name|int
name|rminor
decl_stmt|;
comment|/* revision number, minor	*/
block|}
struct|;
end_struct

begin_comment
comment|/* END OF COLD PART ...		*/
end_comment

begin_define
define|#
directive|define
name|VGAPCVTINFO
value|_IOWR('V',114, struct pcvtinfo)
end_define

begin_comment
comment|/* get driver info */
end_comment

begin_struct
struct|struct
name|pcvtinfo
block|{
comment|/* compile time option values */
name|u_int
name|nscreens
decl_stmt|;
comment|/* PCVT_NSCREENS */
name|u_int
name|scanset
decl_stmt|;
comment|/* PCVT_SCANSET */
name|u_int
name|updatefast
decl_stmt|;
comment|/* PCVT_UPDATEFAST */
name|u_int
name|updateslow
decl_stmt|;
comment|/* PCVT_UPDATESLOW */
name|u_int
name|sysbeepf
decl_stmt|;
comment|/* PCVT_SYSBEEPF */
name|u_int
name|pcburst
decl_stmt|;
comment|/* PCVT_PCBURST */
name|u_int
name|kbd_fifo_sz
decl_stmt|;
comment|/* PCVT_KBD_FIFO_SZ */
comment|/* config booleans */
name|u_long
name|compile_opts
decl_stmt|;
comment|/* PCVT_xxxxxxxxxxxxxxx */
define|#
directive|define
name|CONF_VT220KEYB
value|0x00000001
define|#
directive|define
name|CONF_SCREENSAVER
value|0x00000002
define|#
directive|define
name|CONF_PRETTYSCRNS
value|0x00000004
define|#
directive|define
name|CONF_CTRL_ALT_DEL
value|0x00000008
define|#
directive|define
name|CONF_USEKBDSEC
value|0x00000010
define|#
directive|define
name|CONF_24LINESDEF
value|0x00000020
define|#
directive|define
name|CONF_SHOWKEYS
value|0x00000040
define|#
directive|define
name|CONF_NULLCHARS
value|0x00000080
define|#
directive|define
name|CONF_SETCOLOR
value|0x00000100
define|#
directive|define
name|CONF_132GENERIC
value|0x00000200
define|#
directive|define
name|CONF_XSERVER
value|0x00000400
define|#
directive|define
name|CONF_INHIBIT_NUMLOCK
value|0x00000800
define|#
directive|define
name|CONF_META_ESC
value|0x00001000
define|#
directive|define
name|CONF_SLOW_INTERRUPT
value|0x00002000
define|#
directive|define
name|CONF_NO_LED_UPDATE
value|0x00004000
define|#
directive|define
name|CONF_GREENSAVER
value|0x00008000
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_PCVT_IOCTL_H_ */
end_comment

end_unit

