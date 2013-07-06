begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 HighPoint Technologies, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|hptnr_CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|hptnr_CONFIG_H
end_define

begin_define
define|#
directive|define
name|SUPPORT_ARRAY
end_define

begin_define
define|#
directive|define
name|__KERNEL__
value|1
end_define

begin_define
define|#
directive|define
name|DRIVER_MINOR
value|16
end_define

begin_define
define|#
directive|define
name|TARGETNAME
value|hptnr
end_define

begin_define
define|#
directive|define
name|__dummy_reg
value|hptnr___dummy_reg
end_define

begin_define
define|#
directive|define
name|__ldm_alloc_cmd
value|hptnr___ldm_alloc_cmd
end_define

begin_define
define|#
directive|define
name|delay_between_spinup
value|hptnr_delay_between_spinup
end_define

begin_define
define|#
directive|define
name|dmapool_active
value|hptnr_dmapool_active
end_define

begin_define
define|#
directive|define
name|dmapool_get_page
value|hptnr_dmapool_get_page
end_define

begin_define
define|#
directive|define
name|dmapool_get_page_at
value|hptnr_dmapool_get_page_at
end_define

begin_define
define|#
directive|define
name|dmapool_init
value|hptnr_dmapool_init
end_define

begin_define
define|#
directive|define
name|dmapool_make_order
value|hptnr_dmapool_make_order
end_define

begin_define
define|#
directive|define
name|dmapool_max_class_pages
value|hptnr_dmapool_max_class_pages
end_define

begin_define
define|#
directive|define
name|dmapool_put_page
value|hptnr_dmapool_put_page
end_define

begin_define
define|#
directive|define
name|dmapool_register_client
value|hptnr_dmapool_register_client
end_define

begin_define
define|#
directive|define
name|driver_name
value|hptnr_driver_name
end_define

begin_define
define|#
directive|define
name|driver_name_long
value|hptnr_driver_name_long
end_define

begin_define
define|#
directive|define
name|driver_ver
value|hptnr_driver_ver
end_define

begin_define
define|#
directive|define
name|freelist_get
value|hptnr_freelist_get
end_define

begin_define
define|#
directive|define
name|freelist_get_dma
value|hptnr_freelist_get_dma
end_define

begin_define
define|#
directive|define
name|freelist_put
value|hptnr_freelist_put
end_define

begin_define
define|#
directive|define
name|freelist_put_dma
value|hptnr_freelist_put_dma
end_define

begin_define
define|#
directive|define
name|freelist_reserve
value|hptnr_freelist_reserve
end_define

begin_define
define|#
directive|define
name|freelist_reserve_dma
value|hptnr_freelist_reserve_dma
end_define

begin_define
define|#
directive|define
name|gGlobalNcqFlag
value|hptnr_gGlobalNcqFlag
end_define

begin_define
define|#
directive|define
name|gProbeInInitializing
value|hptnr_gProbeInInitializing
end_define

begin_define
define|#
directive|define
name|gSGPIOPartSupport
value|hptnr_gSGPIOPartSupport
end_define

begin_define
define|#
directive|define
name|gSpinupOneDevEachTime
value|hptnr_gSpinupOneDevEachTime
end_define

begin_define
define|#
directive|define
name|g_legacy_mode
value|hptnr_g_legacy_mode
end_define

begin_define
define|#
directive|define
name|gautorebuild
value|hptnr_gautorebuild
end_define

begin_define
define|#
directive|define
name|grebuildpriority
value|hptnr_grebuildpriority
end_define

begin_define
define|#
directive|define
name|him_handle_to_vbus
value|hptnr_him_handle_to_vbus
end_define

begin_define
define|#
directive|define
name|him_list
value|hptnr_him_list
end_define

begin_define
define|#
directive|define
name|init_config
value|hptnr_init_config
end_define

begin_define
define|#
directive|define
name|init_module_him_dc7280
value|hptnr_init_module_him_dc7280
end_define

begin_define
define|#
directive|define
name|init_module_him_r750
value|hptnr_init_module_him_r750
end_define

begin_define
define|#
directive|define
name|init_module_vdev_raw
value|hptnr_init_module_vdev_raw
end_define

begin_define
define|#
directive|define
name|ldm_acquire_lock
value|hptnr_ldm_acquire_lock
end_define

begin_define
define|#
directive|define
name|ldm_add_spare_to_array
value|hptnr_ldm_add_spare_to_array
end_define

begin_define
define|#
directive|define
name|ldm_alloc_cmds_R_6_55_75_46_64
value|hptnr_ldm_alloc_cmds_R_6_55_75_46_64
end_define

begin_define
define|#
directive|define
name|ldm_alloc_cmds_from_list
value|hptnr_ldm_alloc_cmds_from_list
end_define

begin_define
define|#
directive|define
name|ldm_check_array_online
value|hptnr_ldm_check_array_online
end_define

begin_define
define|#
directive|define
name|ldm_create_vbus
value|hptnr_ldm_create_vbus
end_define

begin_define
define|#
directive|define
name|ldm_create_vdev
value|hptnr_ldm_create_vdev
end_define

begin_define
define|#
directive|define
name|ldm_event_notify
value|hptnr_ldm_event_notify
end_define

begin_define
define|#
directive|define
name|ldm_find_stamp
value|hptnr_ldm_find_stamp
end_define

begin_define
define|#
directive|define
name|ldm_find_target
value|hptnr_ldm_find_target
end_define

begin_define
define|#
directive|define
name|ldm_finish_cmd
value|hptnr_ldm_finish_cmd
end_define

begin_define
define|#
directive|define
name|ldm_free_cmds
value|hptnr_ldm_free_cmds
end_define

begin_define
define|#
directive|define
name|ldm_free_cmds_to_list
value|hptnr_ldm_free_cmds_to_list
end_define

begin_define
define|#
directive|define
name|ldm_generic_member_failed
value|hptnr_ldm_generic_member_failed
end_define

begin_define
define|#
directive|define
name|ldm_get_cmd_size
value|hptnr_ldm_get_cmd_size
end_define

begin_define
define|#
directive|define
name|ldm_get_device_id
value|hptnr_ldm_get_device_id
end_define

begin_define
define|#
directive|define
name|ldm_get_mem_info
value|hptnr_ldm_get_mem_info
end_define

begin_define
define|#
directive|define
name|ldm_get_next_vbus
value|hptnr_ldm_get_next_vbus
end_define

begin_define
define|#
directive|define
name|ldm_get_vbus_ext
value|hptnr_ldm_get_vbus_ext
end_define

begin_define
define|#
directive|define
name|ldm_get_vbus_size
value|hptnr_ldm_get_vbus_size
end_define

begin_define
define|#
directive|define
name|ldm_ide_fixstring
value|hptnr_ldm_ide_fixstring
end_define

begin_define
define|#
directive|define
name|ldm_idle
value|hptnr_ldm_idle
end_define

begin_define
define|#
directive|define
name|ldm_initialize_vbus_async
value|hptnr_ldm_initialize_vbus_async
end_define

begin_define
define|#
directive|define
name|ldm_intr
value|hptnr_ldm_intr
end_define

begin_define
define|#
directive|define
name|ldm_ioctl
value|hptnr_ldm_ioctl
end_define

begin_define
define|#
directive|define
name|ldm_on_timer
value|hptnr_ldm_on_timer
end_define

begin_define
define|#
directive|define
name|ldm_queue_cmd
value|hptnr_ldm_queue_cmd
end_define

begin_define
define|#
directive|define
name|ldm_queue_task
value|hptnr_ldm_queue_task
end_define

begin_define
define|#
directive|define
name|ldm_queue_vbus_dpc
value|hptnr_ldm_queue_vbus_dpc
end_define

begin_define
define|#
directive|define
name|ldm_register_adapter
value|hptnr_ldm_register_adapter
end_define

begin_define
define|#
directive|define
name|ldm_register_device
value|hptnr_ldm_register_device
end_define

begin_define
define|#
directive|define
name|ldm_register_him_R_6_55_75_46_64
value|hptnr_ldm_register_him_R_6_55_75_46_64
end_define

begin_define
define|#
directive|define
name|ldm_register_vdev_class_R_6_55_75_46_64
value|hptnr_ldm_register_vdev_class_R_6_55_75_46_64
end_define

begin_define
define|#
directive|define
name|ldm_release_lock
value|hptnr_ldm_release_lock
end_define

begin_define
define|#
directive|define
name|ldm_release_vbus
value|hptnr_ldm_release_vbus
end_define

begin_define
define|#
directive|define
name|ldm_release_vdev
value|hptnr_ldm_release_vdev
end_define

begin_define
define|#
directive|define
name|ldm_remove_timer
value|hptnr_ldm_remove_timer
end_define

begin_define
define|#
directive|define
name|ldm_request_timer
value|hptnr_ldm_request_timer
end_define

begin_define
define|#
directive|define
name|ldm_reset_vbus
value|hptnr_ldm_reset_vbus
end_define

begin_define
define|#
directive|define
name|ldm_resume
value|hptnr_ldm_resume
end_define

begin_define
define|#
directive|define
name|ldm_run
value|hptnr_ldm_run
end_define

begin_define
define|#
directive|define
name|ldm_set_autorebuild
value|hptnr_ldm_set_autorebuild
end_define

begin_define
define|#
directive|define
name|ldm_shutdown
value|hptnr_ldm_shutdown
end_define

begin_define
define|#
directive|define
name|ldm_suspend
value|hptnr_ldm_suspend
end_define

begin_define
define|#
directive|define
name|ldm_sync_array_info
value|hptnr_ldm_sync_array_info
end_define

begin_define
define|#
directive|define
name|ldm_sync_array_stamp
value|hptnr_ldm_sync_array_stamp
end_define

begin_define
define|#
directive|define
name|ldm_timer_probe_device
value|hptnr_ldm_timer_probe_device
end_define

begin_define
define|#
directive|define
name|ldm_unregister_device
value|hptnr_ldm_unregister_device
end_define

begin_define
define|#
directive|define
name|log_sector_repair
value|hptnr_log_sector_repair
end_define

begin_define
define|#
directive|define
name|num_drives_per_spinup
value|hptnr_num_drives_per_spinup
end_define

begin_define
define|#
directive|define
name|os_get_stamp
value|hptnr_os_get_stamp
end_define

begin_define
define|#
directive|define
name|os_get_vbus_seq
value|hptnr_os_get_vbus_seq
end_define

begin_define
define|#
directive|define
name|os_inb
value|hptnr_os_inb
end_define

begin_define
define|#
directive|define
name|os_inl
value|hptnr_os_inl
end_define

begin_define
define|#
directive|define
name|os_insw
value|hptnr_os_insw
end_define

begin_define
define|#
directive|define
name|os_inw
value|hptnr_os_inw
end_define

begin_define
define|#
directive|define
name|os_map_pci_bar
value|hptnr_os_map_pci_bar
end_define

begin_define
define|#
directive|define
name|os_max_cache_size
value|hptnr_os_max_cache_size
end_define

begin_define
define|#
directive|define
name|os_outb
value|hptnr_os_outb
end_define

begin_define
define|#
directive|define
name|os_outl
value|hptnr_os_outl
end_define

begin_define
define|#
directive|define
name|os_outsw
value|hptnr_os_outsw
end_define

begin_define
define|#
directive|define
name|os_outw
value|hptnr_os_outw
end_define

begin_define
define|#
directive|define
name|os_pci_readb
value|hptnr_os_pci_readb
end_define

begin_define
define|#
directive|define
name|os_pci_readl
value|hptnr_os_pci_readl
end_define

begin_define
define|#
directive|define
name|os_pci_readw
value|hptnr_os_pci_readw
end_define

begin_define
define|#
directive|define
name|os_pci_writeb
value|hptnr_os_pci_writeb
end_define

begin_define
define|#
directive|define
name|os_pci_writel
value|hptnr_os_pci_writel
end_define

begin_define
define|#
directive|define
name|os_pci_writew
value|hptnr_os_pci_writew
end_define

begin_define
define|#
directive|define
name|os_printk
value|hptnr_os_printk
end_define

begin_define
define|#
directive|define
name|os_query_remove_device
value|hptnr_os_query_remove_device
end_define

begin_define
define|#
directive|define
name|os_query_time
value|hptnr_os_query_time
end_define

begin_define
define|#
directive|define
name|os_request_timer
value|hptnr_os_request_timer
end_define

begin_define
define|#
directive|define
name|os_revalidate_device
value|hptnr_os_revalidate_device
end_define

begin_define
define|#
directive|define
name|os_schedule_task
value|hptnr_os_schedule_task
end_define

begin_define
define|#
directive|define
name|os_stallexec
value|hptnr_os_stallexec
end_define

begin_define
define|#
directive|define
name|os_unmap_pci_bar
value|hptnr_os_unmap_pci_bar
end_define

begin_define
define|#
directive|define
name|osm_max_targets
value|hptnr_osm_max_targets
end_define

begin_define
define|#
directive|define
name|pcicfg_read_dword
value|hptnr_pcicfg_read_dword
end_define

begin_define
define|#
directive|define
name|vbus_list
value|hptnr_vbus_list
end_define

begin_define
define|#
directive|define
name|vdev_queue_cmd
value|hptnr_vdev_queue_cmd
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

