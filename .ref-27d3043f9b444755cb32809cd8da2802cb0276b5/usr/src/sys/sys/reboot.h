begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	reboot.h	4.1	%G%	*/
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
value|1
end_define

begin_comment
comment|/* ask for file name to reboot from */
end_comment

begin_define
define|#
directive|define
name|RB_SINGLE
value|2
end_define

begin_comment
comment|/* reboot to single user only */
end_comment

begin_define
define|#
directive|define
name|RB_NOSYNC
value|4
end_define

begin_comment
comment|/* dont sync before reboot */
end_comment

begin_define
define|#
directive|define
name|RB_HALT
value|8
end_define

begin_comment
comment|/* don't reboot, just halt */
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

end_unit

