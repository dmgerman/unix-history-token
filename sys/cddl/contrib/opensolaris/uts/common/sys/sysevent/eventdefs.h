begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2005, 2010, Oracle and/or its affiliates. All rights reserved.  * Copyright 2011 Nexenta Systems, Inc.  All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SYSEVENT_EVENTDEFS_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SYSEVENT_EVENTDEFS_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/*  * eventdefs.h contains public definitions for sysevent types (classes  * and subclasses).  All additions/removal/changes are subject  * to PSARC approval.  */
comment|/* Sysevent Class definitions */
define|#
directive|define
name|EC_NONE
value|"EC_none"
define|#
directive|define
name|EC_PRIV
value|"EC_priv"
define|#
directive|define
name|EC_PLATFORM
value|"EC_platform"
comment|/* events private to platform */
define|#
directive|define
name|EC_DR
value|"EC_dr"
comment|/* Dynamic reconfiguration event class */
define|#
directive|define
name|EC_ENV
value|"EC_env"
comment|/* Environmental monitor event class */
define|#
directive|define
name|EC_DOMAIN
value|"EC_domain"
comment|/* Domain event class */
define|#
directive|define
name|EC_AP_DRIVER
value|"EC_ap_driver"
comment|/* Alternate Pathing event class */
define|#
directive|define
name|EC_IPMP
value|"EC_ipmp"
comment|/* IP Multipathing event class */
define|#
directive|define
name|EC_DEV_ADD
value|"EC_dev_add"
comment|/* device add event class */
define|#
directive|define
name|EC_DEV_REMOVE
value|"EC_dev_remove"
comment|/* device remove event class */
define|#
directive|define
name|EC_DEV_BRANCH
value|"EC_dev_branch"
comment|/* device tree branch event class */
define|#
directive|define
name|EC_DEV_STATUS
value|"EC_dev_status"
comment|/* device status event class */
define|#
directive|define
name|EC_FM
value|"EC_fm"
comment|/* FMA error report event */
define|#
directive|define
name|EC_ZFS
value|"EC_zfs"
comment|/* ZFS event */
define|#
directive|define
name|EC_DATALINK
value|"EC_datalink"
comment|/* datalink event */
define|#
directive|define
name|EC_VRRP
value|"EC_vrrp"
comment|/* VRRP event */
comment|/*  * The following event class is reserved for exclusive use  * by Sun Cluster software.  */
define|#
directive|define
name|EC_CLUSTER
value|"EC_Cluster"
comment|/*  * The following classes are exclusively reserved for use by the  * Solaris Volume Manager (SVM)  */
define|#
directive|define
name|EC_SVM_CONFIG
value|"EC_SVM_Config"
define|#
directive|define
name|EC_SVM_STATE
value|"EC_SVM_State"
comment|/*  * EC_SVM_CONFIG subclass definitions - supporting attributes (name/value pairs)  * are found in sys/sysevent/svm.h  */
define|#
directive|define
name|ESC_SVM_CREATE
value|"ESC_SVM_Create"
define|#
directive|define
name|ESC_SVM_DELETE
value|"ESC_SVM_Delete"
define|#
directive|define
name|ESC_SVM_ADD
value|"ESC_SVM_Add"
define|#
directive|define
name|ESC_SVM_REMOVE
value|"ESC_SVM_Remove"
define|#
directive|define
name|ESC_SVM_REPLACE
value|"ESC_SVM_Replace"
define|#
directive|define
name|ESC_SVM_GROW
value|"ESC_SVM_Grow"
define|#
directive|define
name|ESC_SVM_RENAME_SRC
value|"ESC_SVM_Rename_Src"
define|#
directive|define
name|ESC_SVM_RENAME_DST
value|"ESC_SVM_Rename_Dst"
define|#
directive|define
name|ESC_SVM_MEDIATOR_ADD
value|"ESC_SVM_Mediator_Add"
define|#
directive|define
name|ESC_SVM_MEDIATOR_DELETE
value|"ESC_SVM_Mediator_Delete"
define|#
directive|define
name|ESC_SVM_HOST_ADD
value|"ESC_SVM_Host_Add"
define|#
directive|define
name|ESC_SVM_HOST_DELETE
value|"ESC_SVM_Host_Delete"
define|#
directive|define
name|ESC_SVM_DRIVE_ADD
value|"ESC_SVM_Drive_Add"
define|#
directive|define
name|ESC_SVM_DRIVE_DELETE
value|"ESC_SVM_Drive_Delete"
define|#
directive|define
name|ESC_SVM_DETACH
value|"ESC_SVM_Detach"
define|#
directive|define
name|ESC_SVM_DETACHING
value|"ESC_SVM_Detaching"
define|#
directive|define
name|ESC_SVM_ATTACH
value|"ESC_SVM_Attach"
define|#
directive|define
name|ESC_SVM_ATTACHING
value|"ESC_SVM_Attaching"
comment|/*  * EC_SVM_STATE subclass definitions - supporting attributes (name/value pairs)  * are found in sys/sysevent/svm.h  */
define|#
directive|define
name|ESC_SVM_INIT_START
value|"ESC_SVM_Init_Start"
define|#
directive|define
name|ESC_SVM_INIT_FAILED
value|"ESC_SVM_Init_Failed"
define|#
directive|define
name|ESC_SVM_INIT_FATAL
value|"ESC_SVM_Init_Fatal"
define|#
directive|define
name|ESC_SVM_INIT_SUCCESS
value|"ESC_SVM_Init_Success"
define|#
directive|define
name|ESC_SVM_IOERR
value|"ESC_SVM_Ioerr"
define|#
directive|define
name|ESC_SVM_ERRED
value|"ESC_SVM_Erred"
define|#
directive|define
name|ESC_SVM_LASTERRED
value|"ESC_SVM_Lasterred"
define|#
directive|define
name|ESC_SVM_OK
value|"ESC_SVM_Ok"
define|#
directive|define
name|ESC_SVM_ENABLE
value|"ESC_SVM_Enable"
define|#
directive|define
name|ESC_SVM_RESYNC_START
value|"ESC_SVM_Resync_Start"
define|#
directive|define
name|ESC_SVM_RESYNC_FAILED
value|"ESC_SVM_Resync_Failed"
define|#
directive|define
name|ESC_SVM_RESYNC_SUCCESS
value|"ESC_SVM_Resync_Success"
define|#
directive|define
name|ESC_SVM_RESYNC_DONE
value|"ESC_SVM_Resync_Done"
define|#
directive|define
name|ESC_SVM_HOTSPARED
value|"ESC_SVM_Hotspared"
define|#
directive|define
name|ESC_SVM_HS_FREED
value|"ESC_SVM_HS_Freed"
define|#
directive|define
name|ESC_SVM_HS_CHANGED
value|"ESC_SVM_HS_Changed"
define|#
directive|define
name|ESC_SVM_TAKEOVER
value|"ESC_SVM_Takeover"
define|#
directive|define
name|ESC_SVM_RELEASE
value|"ESC_SVM_Release"
define|#
directive|define
name|ESC_SVM_OPEN_FAIL
value|"ESC_SVM_Open_Fail"
define|#
directive|define
name|ESC_SVM_OFFLINE
value|"ESC_SVM_Offline"
define|#
directive|define
name|ESC_SVM_ONLINE
value|"ESC_SVM_Online"
define|#
directive|define
name|ESC_SVM_CHANGE
value|"ESC_SVM_Change"
define|#
directive|define
name|ESC_SVM_EXCHANGE
value|"ESC_SVM_Exchange"
define|#
directive|define
name|ESC_SVM_REGEN_START
value|"ESC_SVM_Regen_Start"
define|#
directive|define
name|ESC_SVM_REGEN_DONE
value|"ESC_SVM_Regen_Done"
define|#
directive|define
name|ESC_SVM_REGEN_FAILED
value|"ESC_SVM_Regen_Failed"
comment|/*  * EC_DR subclass definitions - supporting attributes (name/value pairs)  * are found in sys/sysevent/dr.h  */
comment|/* Attachment point state change */
define|#
directive|define
name|ESC_DR_AP_STATE_CHANGE
value|"ESC_dr_ap_state_change"
define|#
directive|define
name|ESC_DR_REQ
value|"ESC_dr_req"
comment|/* Request DR */
define|#
directive|define
name|ESC_DR_TARGET_STATE_CHANGE
value|"ESC_dr_target_state_change"
comment|/*  * EC_ENV subclass definitions - supporting attributes (name/value pairs)  * are found in sys/sysevent/env.h  */
define|#
directive|define
name|ESC_ENV_TEMP
value|"ESC_env_temp"
comment|/* Temperature change event subclass */
define|#
directive|define
name|ESC_ENV_FAN
value|"ESC_env_fan"
comment|/* Fan status change event subclass */
define|#
directive|define
name|ESC_ENV_POWER
value|"ESC_env_power"
comment|/* Power supply change event subclass */
define|#
directive|define
name|ESC_ENV_LED
value|"ESC_env_led"
comment|/* LED change event subclass */
comment|/*  * EC_DOMAIN subclass definitions - supporting attributes (name/value pairs)  * are found in sys/sysevent/domain.h  */
comment|/* Domain state change */
define|#
directive|define
name|ESC_DOMAIN_STATE_CHANGE
value|"ESC_domain_state_change"
comment|/* Domain loghost name change */
define|#
directive|define
name|ESC_DOMAIN_LOGHOST_CHANGE
value|"ESC_domain_loghost_change"
comment|/*  * EC_AP_DRIVER subclass definitions - supporting attributes (name/value pairs)  * are found in sys/sysevent/ap_driver.h  */
comment|/* Alternate Pathing path switch */
define|#
directive|define
name|ESC_AP_DRIVER_PATHSWITCH
value|"ESC_ap_driver_pathswitch"
comment|/* Alternate Pathing database commit */
define|#
directive|define
name|ESC_AP_DRIVER_COMMIT
value|"ESC_ap_driver_commit"
comment|/* Alternate Pathing physical path status change */
define|#
directive|define
name|ESC_AP_DRIVER_PHYS_PATH_STATUS_CHANGE
define|\
value|"ESC_ap_driver_phys_path_status_change"
comment|/*  * EC_IPMP subclass definitions - supporting attributes (name/value pairs)  * are found in sys/sysevent/ipmp.h  */
comment|/* IPMP group has changed state */
define|#
directive|define
name|ESC_IPMP_GROUP_STATE
value|"ESC_ipmp_group_state"
comment|/* IPMP group has been created or removed */
define|#
directive|define
name|ESC_IPMP_GROUP_CHANGE
value|"ESC_ipmp_group_change"
comment|/* IPMP group has had an interface added or removed */
define|#
directive|define
name|ESC_IPMP_GROUP_MEMBER_CHANGE
value|"ESC_ipmp_group_member_change"
comment|/* Interface within an IPMP group has changed state or type */
define|#
directive|define
name|ESC_IPMP_IF_CHANGE
value|"ESC_ipmp_if_change"
comment|/* IPMP probe has changed state */
define|#
directive|define
name|ESC_IPMP_PROBE_STATE
value|"ESC_ipmp_probe_state"
comment|/*  * EC_DEV_ADD and EC_DEV_REMOVE subclass definitions - supporting attributes  * (name/value pairs) are found in sys/sysevent/dev.h  */
define|#
directive|define
name|ESC_DISK
value|"disk"
comment|/* disk device */
define|#
directive|define
name|ESC_NETWORK
value|"network"
comment|/* network interface */
define|#
directive|define
name|ESC_PRINTER
value|"printer"
comment|/* printer device */
define|#
directive|define
name|ESC_LOFI
value|"lofi"
comment|/* lofi device */
comment|/*  * EC_DEV_BRANCH subclass definitions - supporting attributes (name/value pairs)  * are found in sys/sysevent/dev.h  */
comment|/* device tree branch added */
define|#
directive|define
name|ESC_DEV_BRANCH_ADD
value|"ESC_dev_branch_add"
comment|/* device tree branch removed */
define|#
directive|define
name|ESC_DEV_BRANCH_REMOVE
value|"ESC_dev_branch_remove"
comment|/*  * EC_DEV_STATUS subclass definitions  *  * device capacity dynamically changed  */
define|#
directive|define
name|ESC_DEV_DLE
value|"ESC_dev_dle"
comment|/* LUN has received an eject request from the user */
define|#
directive|define
name|ESC_DEV_EJECT_REQUEST
value|"ESC_dev_eject_request"
comment|/* FMA Fault and Error event protocol subclass */
define|#
directive|define
name|ESC_FM_ERROR
value|"ESC_FM_error"
define|#
directive|define
name|ESC_FM_ERROR_REPLAY
value|"ESC_FM_error_replay"
comment|/* Service processor subclass definitions */
define|#
directive|define
name|ESC_PLATFORM_SP_RESET
value|"ESC_platform_sp_reset"
comment|/*  * EC_PWRCTL subclass definitions  */
define|#
directive|define
name|EC_PWRCTL
value|"EC_pwrctl"
define|#
directive|define
name|ESC_PWRCTL_ADD
value|"ESC_pwrctl_add"
define|#
directive|define
name|ESC_PWRCTL_REMOVE
value|"ESC_pwrctl_remove"
define|#
directive|define
name|ESC_PWRCTL_WARN
value|"ESC_pwrctl_warn"
define|#
directive|define
name|ESC_PWRCTL_LOW
value|"ESC_pwrctl_low"
define|#
directive|define
name|ESC_PWRCTL_STATE_CHANGE
value|"ESC_pwrctl_state_change"
define|#
directive|define
name|ESC_PWRCTL_POWER_BUTTON
value|"ESC_pwrctl_power_button"
define|#
directive|define
name|ESC_PWRCTL_BRIGHTNESS_UP
value|"ESC_pwrctl_brightness_up"
define|#
directive|define
name|ESC_PWRCTL_BRIGHTNESS_DOWN
value|"ESC_pwrctl_brightness_down"
comment|/* EC_ACPIEV subclass definitions */
define|#
directive|define
name|EC_ACPIEV
value|"EC_acpiev"
define|#
directive|define
name|ESC_ACPIEV_DISPLAY_SWITCH
value|"ESC_acpiev_display_switch"
define|#
directive|define
name|ESC_ACPIEV_SCREEN_LOCK
value|"ESC_acpiev_screen_lock"
define|#
directive|define
name|ESC_ACPIEV_SLEEP
value|"ESC_acpiev_sleep"
define|#
directive|define
name|ESC_ACPIEV_AUDIO_MUTE
value|"ESC_acpiev_audio_mute"
define|#
directive|define
name|ESC_ACPIEV_WIFI
value|"ESC_acpiev_wifi"
define|#
directive|define
name|ESC_ACPIEV_TOUCHPAD
value|"ESC_acpiev_touchpad"
comment|/*  * ZFS subclass definitions.  supporting attributes (name/value paris) are found  * in sys/fs/zfs.h  */
define|#
directive|define
name|ESC_ZFS_RESILVER_START
value|"ESC_ZFS_resilver_start"
define|#
directive|define
name|ESC_ZFS_RESILVER_FINISH
value|"ESC_ZFS_resilver_finish"
define|#
directive|define
name|ESC_ZFS_VDEV_REMOVE
value|"ESC_ZFS_vdev_remove"
define|#
directive|define
name|ESC_ZFS_POOL_DESTROY
value|"ESC_ZFS_pool_destroy"
define|#
directive|define
name|ESC_ZFS_VDEV_CLEAR
value|"ESC_ZFS_vdev_clear"
define|#
directive|define
name|ESC_ZFS_VDEV_CHECK
value|"ESC_ZFS_vdev_check"
define|#
directive|define
name|ESC_ZFS_CONFIG_SYNC
value|"ESC_ZFS_config_sync"
define|#
directive|define
name|ESC_ZFS_SCRUB_START
value|"ESC_ZFS_scrub_start"
define|#
directive|define
name|ESC_ZFS_SCRUB_FINISH
value|"ESC_ZFS_scrub_finish"
define|#
directive|define
name|ESC_ZFS_VDEV_SPARE
value|"ESC_ZFS_vdev_spare"
define|#
directive|define
name|ESC_ZFS_BOOTFS_VDEV_ATTACH
value|"ESC_ZFS_bootfs_vdev_attach"
define|#
directive|define
name|ESC_ZFS_POOL_REGUID
value|"ESC_ZFS_pool_reguid"
define|#
directive|define
name|ESC_ZFS_VDEV_AUTOEXPAND
value|"ESC_ZFS_vdev_autoexpand"
comment|/*  * datalink subclass definitions.  */
define|#
directive|define
name|ESC_DATALINK_PHYS_ADD
value|"ESC_datalink_phys_add"
comment|/* new physical link */
comment|/*  * VRRP subclass definitions. Supporting attributes (name/value paris) are  * found in sys/sysevent/vrrp.h  */
define|#
directive|define
name|ESC_VRRP_STATE_CHANGE
value|"ESC_vrrp_state_change"
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_SYSEVENT_EVENTDEFS_H */
end_comment

end_unit

