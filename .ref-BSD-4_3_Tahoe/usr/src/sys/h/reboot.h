begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)reboot.h	7.5 (Berkeley) 6/27/88  */
end_comment

begin_comment
comment|/*  * Arguments to reboot system call.  * These are passed to boot program in r11,  * and on to init.  */
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
value|0x01
end_define

begin_comment
comment|/* ask for file name to reboot from */
end_comment

begin_define
define|#
directive|define
name|RB_SINGLE
value|0x02
end_define

begin_comment
comment|/* reboot to single user only */
end_comment

begin_define
define|#
directive|define
name|RB_NOSYNC
value|0x04
end_define

begin_comment
comment|/* dont sync before reboot */
end_comment

begin_define
define|#
directive|define
name|RB_HALT
value|0x08
end_define

begin_comment
comment|/* don't reboot, just halt */
end_comment

begin_define
define|#
directive|define
name|RB_INITNAME
value|0x10
end_define

begin_comment
comment|/* name given for /etc/init (unused) */
end_comment

begin_define
define|#
directive|define
name|RB_DFLTROOT
value|0x20
end_define

begin_comment
comment|/* use compiled-in rootdev */
end_comment

begin_define
define|#
directive|define
name|RB_KDB
value|0x40
end_define

begin_comment
comment|/* give control to kernel debugger */
end_comment

begin_define
define|#
directive|define
name|RB_RDONLY
value|0x80
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
value|((u_long)0xf0000000)
end_define

begin_define
define|#
directive|define
name|B_DEVMAGIC
value|((u_long)0xa0000000)
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

end_unit

