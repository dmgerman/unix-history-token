begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)reboot.h	7.1 (Berkeley) 6/4/86  */
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
comment|/* name given for /etc/init */
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
name|RB_PANIC
value|0
end_define

begin_comment
comment|/* reboot due to panic */
end_comment

begin_define
define|#
directive|define
name|RB_BOOT
value|1
end_define

begin_comment
comment|/* reboot due to boot() */
end_comment

begin_comment
comment|/*  * Constants for converting boot-style device number to type,  * adaptor (uba, mba, etc), unit number and partition number.  * Type (== major device number) is in the low byte  * for backward compatibility.  Except for that of the "magic  * number", each mask applies to the shifted value.  */
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
name|B_UNITSHIFT
value|16
end_define

begin_define
define|#
directive|define
name|B_UNITMASK
value|0xff
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
name|B_MAGICMASK
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|B_DEVMAGIC
value|0xa0000000
end_define

end_unit

