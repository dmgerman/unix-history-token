begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPDX-License-Identifier: GPL-2.0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ROCKCHIP_BOOT_MODE_H
end_ifndef

begin_define
define|#
directive|define
name|__ROCKCHIP_BOOT_MODE_H
end_define

begin_comment
comment|/*high 24 bits is tag, low 8 bits is type*/
end_comment

begin_define
define|#
directive|define
name|REBOOT_FLAG
value|0x5242C300
end_define

begin_comment
comment|/* normal boot */
end_comment

begin_define
define|#
directive|define
name|BOOT_NORMAL
value|(REBOOT_FLAG + 0)
end_define

begin_comment
comment|/* enter bootloader rockusb mode */
end_comment

begin_define
define|#
directive|define
name|BOOT_BL_DOWNLOAD
value|(REBOOT_FLAG + 1)
end_define

begin_comment
comment|/* enter recovery */
end_comment

begin_define
define|#
directive|define
name|BOOT_RECOVERY
value|(REBOOT_FLAG + 3)
end_define

begin_comment
comment|/* enter fastboot mode */
end_comment

begin_define
define|#
directive|define
name|BOOT_FASTBOOT
value|(REBOOT_FLAG + 9)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

