begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1988, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)reboot.h	8.3 (Berkeley) 12/13/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_REBOOT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_REBOOT_H_
end_define

begin_comment
comment|/*  * Arguments to reboot system call.  These are passed to  * the boot program and on to init.  */
end_comment

begin_define
define|#
directive|define
name|RB_AUTOBOOT
value|0
end_define

begin_comment
comment|/* flags for system auto-booting itself */
end_comment

begin_define
define|#
directive|define
name|RB_ASKNAME
value|0x001
end_define

begin_comment
comment|/* ask for file name to reboot from */
end_comment

begin_define
define|#
directive|define
name|RB_SINGLE
value|0x002
end_define

begin_comment
comment|/* reboot to single user only */
end_comment

begin_define
define|#
directive|define
name|RB_NOSYNC
value|0x004
end_define

begin_comment
comment|/* dont sync before reboot */
end_comment

begin_define
define|#
directive|define
name|RB_HALT
value|0x008
end_define

begin_comment
comment|/* don't reboot, just halt */
end_comment

begin_define
define|#
directive|define
name|RB_INITNAME
value|0x010
end_define

begin_comment
comment|/* name given for /etc/init (unused) */
end_comment

begin_define
define|#
directive|define
name|RB_DFLTROOT
value|0x020
end_define

begin_comment
comment|/* use compiled-in rootdev */
end_comment

begin_define
define|#
directive|define
name|RB_KDB
value|0x040
end_define

begin_comment
comment|/* give control to kernel debugger */
end_comment

begin_define
define|#
directive|define
name|RB_RDONLY
value|0x080
end_define

begin_comment
comment|/* mount root fs read-only */
end_comment

begin_define
define|#
directive|define
name|RB_DUMP
value|0x100
end_define

begin_comment
comment|/* dump kernel memory before reboot */
end_comment

begin_define
define|#
directive|define
name|RB_MINIROOT
value|0x200
end_define

begin_comment
comment|/* mini-root present in memory at boot time */
end_comment

begin_define
define|#
directive|define
name|RB_CONFIG
value|0x400
end_define

begin_comment
comment|/* invoke user configuration routing */
end_comment

begin_define
define|#
directive|define
name|RB_VERBOSE
value|0x800
end_define

begin_comment
comment|/* print all potentially useful info */
end_comment

begin_define
define|#
directive|define
name|RB_SERIAL
value|0x1000
end_define

begin_comment
comment|/* user serial port as console */
end_comment

begin_define
define|#
directive|define
name|RB_CDROM
value|0x2000
end_define

begin_comment
comment|/* use cdrom as root */
end_comment

begin_define
define|#
directive|define
name|RB_POWEROFF
value|0x4000
end_define

begin_comment
comment|/* if you can, turn the power off */
end_comment

begin_define
define|#
directive|define
name|RB_GDB
value|0x8000
end_define

begin_comment
comment|/* use GDB remote debugger instead of DDB */
end_comment

begin_define
define|#
directive|define
name|RB_MUTE
value|0x10000
end_define

begin_comment
comment|/* Come up with the console muted */
end_comment

begin_define
define|#
directive|define
name|RB_SELFTEST
value|0x20000
end_define

begin_comment
comment|/* don't boot to normal operation, do selftest */
end_comment

begin_define
define|#
directive|define
name|RB_PAUSE
value|0x40000
end_define

begin_comment
comment|/* pause after each output line during probe */
end_comment

begin_define
define|#
directive|define
name|RB_BOOTINFO
value|0x80000000
end_define

begin_comment
comment|/* have `struct bootinfo *' arg */
end_comment

begin_comment
comment|/*  * Constants for converting boot-style device number to type,  * adaptor (uba, mba, etc), unit number and partition number.  * Type (== major device number) is in the low byte  * for backward compatibility.  Except for that of the "magic  * number", each mask applies to the shifted value.  * Format:  *	 (4) (4) (4) (4)  (8)     (8)  *	--------------------------------  *	|MA | AD| CT| UN| PART  | TYPE |  *	--------------------------------  */
end_comment

begin_define
define|#
directive|define
name|B_ADAPTORSHIFT
value|24
end_define

begin_define
define|#
directive|define
name|B_ADAPTORMASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|B_ADAPTOR
parameter_list|(
name|val
parameter_list|)
value|(((val)>> B_ADAPTORSHIFT)& B_ADAPTORMASK)
end_define

begin_define
define|#
directive|define
name|B_CONTROLLERSHIFT
value|20
end_define

begin_define
define|#
directive|define
name|B_CONTROLLERMASK
value|0xf
end_define

begin_define
define|#
directive|define
name|B_CONTROLLER
parameter_list|(
name|val
parameter_list|)
value|(((val)>>B_CONTROLLERSHIFT)& B_CONTROLLERMASK)
end_define

begin_define
define|#
directive|define
name|B_SLICESHIFT
value|20
end_define

begin_define
define|#
directive|define
name|B_SLICEMASK
value|0xff
end_define

begin_define
define|#
directive|define
name|B_SLICE
parameter_list|(
name|val
parameter_list|)
value|(((val)>>B_SLICESHIFT)& B_SLICEMASK)
end_define

begin_define
define|#
directive|define
name|B_UNITSHIFT
value|16
end_define

begin_define
define|#
directive|define
name|B_UNITMASK
value|0xf
end_define

begin_define
define|#
directive|define
name|B_UNIT
parameter_list|(
name|val
parameter_list|)
value|(((val)>> B_UNITSHIFT)& B_UNITMASK)
end_define

begin_define
define|#
directive|define
name|B_PARTITIONSHIFT
value|8
end_define

begin_define
define|#
directive|define
name|B_PARTITIONMASK
value|0xff
end_define

begin_define
define|#
directive|define
name|B_PARTITION
parameter_list|(
name|val
parameter_list|)
value|(((val)>> B_PARTITIONSHIFT)& B_PARTITIONMASK)
end_define

begin_define
define|#
directive|define
name|B_TYPESHIFT
value|0
end_define

begin_define
define|#
directive|define
name|B_TYPEMASK
value|0xff
end_define

begin_define
define|#
directive|define
name|B_TYPE
parameter_list|(
name|val
parameter_list|)
value|(((val)>> B_TYPESHIFT)& B_TYPEMASK)
end_define

begin_define
define|#
directive|define
name|B_MAGICMASK
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|B_DEVMAGIC
value|0xa0000000
end_define

begin_define
define|#
directive|define
name|MAKEBOOTDEV
parameter_list|(
name|type
parameter_list|,
name|adaptor
parameter_list|,
name|controller
parameter_list|,
name|unit
parameter_list|,
name|partition
parameter_list|)
define|\
value|(((type)<< B_TYPESHIFT) | ((adaptor)<< B_ADAPTORSHIFT) | \ 	((controller)<< B_CONTROLLERSHIFT) | ((unit)<< B_UNITSHIFT) | \ 	((partition)<< B_PARTITIONSHIFT) | B_DEVMAGIC)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

