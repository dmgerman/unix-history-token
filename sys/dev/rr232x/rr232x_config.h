begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|rr232x_CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|rr232x_CONFIG_H
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
value|1
end_define

begin_define
define|#
directive|define
name|TARGETNAME
value|rr232x
end_define

begin_define
define|#
directive|define
name|__dummy_reg
value|rr232x___dummy_reg
end_define

begin_define
define|#
directive|define
name|__ldm_alloc_cmd
value|rr232x___ldm_alloc_cmd
end_define

begin_define
define|#
directive|define
name|dmapool_active
value|rr232x_dmapool_active
end_define

begin_define
define|#
directive|define
name|dmapool_get_page
value|rr232x_dmapool_get_page
end_define

begin_define
define|#
directive|define
name|dmapool_make_order
value|rr232x_dmapool_make_order
end_define

begin_define
define|#
directive|define
name|dmapool_put_page
value|rr232x_dmapool_put_page
end_define

begin_define
define|#
directive|define
name|dmapool_register_client
value|rr232x_dmapool_register_client
end_define

begin_define
define|#
directive|define
name|driver_name
value|rr232x_driver_name
end_define

begin_define
define|#
directive|define
name|driver_name_long
value|rr232x_driver_name_long
end_define

begin_define
define|#
directive|define
name|driver_ver
value|rr232x_driver_ver
end_define

begin_define
define|#
directive|define
name|freelist_get
value|rr232x_freelist_get
end_define

begin_define
define|#
directive|define
name|freelist_get_dma
value|rr232x_freelist_get_dma
end_define

begin_define
define|#
directive|define
name|freelist_put
value|rr232x_freelist_put
end_define

begin_define
define|#
directive|define
name|freelist_put_dma
value|rr232x_freelist_put_dma
end_define

begin_define
define|#
directive|define
name|freelist_reserve
value|rr232x_freelist_reserve
end_define

begin_define
define|#
directive|define
name|freelist_reserve_dma
value|rr232x_freelist_reserve_dma
end_define

begin_define
define|#
directive|define
name|him_handle_to_vbus
value|rr232x_him_handle_to_vbus
end_define

begin_define
define|#
directive|define
name|him_list
value|rr232x_him_list
end_define

begin_define
define|#
directive|define
name|init_config
value|rr232x_init_config
end_define

begin_define
define|#
directive|define
name|init_module_him_sx508x
value|rr232x_init_module_him_sx508x
end_define

begin_define
define|#
directive|define
name|init_module_jbod
value|rr232x_init_module_jbod
end_define

begin_define
define|#
directive|define
name|init_module_partition
value|rr232x_init_module_partition
end_define

begin_define
define|#
directive|define
name|init_module_raid0
value|rr232x_init_module_raid0
end_define

begin_define
define|#
directive|define
name|init_module_raid1
value|rr232x_init_module_raid1
end_define

begin_define
define|#
directive|define
name|init_module_raid5
value|rr232x_init_module_raid5
end_define

begin_define
define|#
directive|define
name|init_module_vdev_raw
value|rr232x_init_module_vdev_raw
end_define

begin_define
define|#
directive|define
name|ldm_acquire_lock
value|rr232x_ldm_acquire_lock
end_define

begin_define
define|#
directive|define
name|ldm_add_spare_to_array
value|rr232x_ldm_add_spare_to_array
end_define

begin_define
define|#
directive|define
name|ldm_alloc_cmds_R_5_34_48_37_16
value|rr232x_ldm_alloc_cmds_R_5_34_48_37_16
end_define

begin_define
define|#
directive|define
name|ldm_alloc_cmds_from_list
value|rr232x_ldm_alloc_cmds_from_list
end_define

begin_define
define|#
directive|define
name|ldm_check_array_online
value|rr232x_ldm_check_array_online
end_define

begin_define
define|#
directive|define
name|ldm_create_vbus
value|rr232x_ldm_create_vbus
end_define

begin_define
define|#
directive|define
name|ldm_create_vdev
value|rr232x_ldm_create_vdev
end_define

begin_define
define|#
directive|define
name|ldm_event_notify
value|rr232x_ldm_event_notify
end_define

begin_define
define|#
directive|define
name|ldm_find_target
value|rr232x_ldm_find_target
end_define

begin_define
define|#
directive|define
name|ldm_finish_cmd
value|rr232x_ldm_finish_cmd
end_define

begin_define
define|#
directive|define
name|ldm_free_cmds
value|rr232x_ldm_free_cmds
end_define

begin_define
define|#
directive|define
name|ldm_free_cmds_to_list
value|rr232x_ldm_free_cmds_to_list
end_define

begin_define
define|#
directive|define
name|ldm_generic_member_failed
value|rr232x_ldm_generic_member_failed
end_define

begin_define
define|#
directive|define
name|ldm_get_cmd_size
value|rr232x_ldm_get_cmd_size
end_define

begin_define
define|#
directive|define
name|ldm_get_device_id
value|rr232x_ldm_get_device_id
end_define

begin_define
define|#
directive|define
name|ldm_get_mem_info
value|rr232x_ldm_get_mem_info
end_define

begin_define
define|#
directive|define
name|ldm_get_next_vbus
value|rr232x_ldm_get_next_vbus
end_define

begin_define
define|#
directive|define
name|ldm_get_vbus_ext
value|rr232x_ldm_get_vbus_ext
end_define

begin_define
define|#
directive|define
name|ldm_get_vbus_size
value|rr232x_ldm_get_vbus_size
end_define

begin_define
define|#
directive|define
name|ldm_initialize_vbus_async
value|rr232x_ldm_initialize_vbus_async
end_define

begin_define
define|#
directive|define
name|ldm_intr
value|rr232x_ldm_intr
end_define

begin_define
define|#
directive|define
name|ldm_ioctl
value|rr232x_ldm_ioctl
end_define

begin_define
define|#
directive|define
name|ldm_on_timer
value|rr232x_ldm_on_timer
end_define

begin_define
define|#
directive|define
name|ldm_queue_cmd
value|rr232x_ldm_queue_cmd
end_define

begin_define
define|#
directive|define
name|ldm_queue_task
value|rr232x_ldm_queue_task
end_define

begin_define
define|#
directive|define
name|ldm_queue_vbus_dpc
value|rr232x_ldm_queue_vbus_dpc
end_define

begin_define
define|#
directive|define
name|ldm_register_adapter
value|rr232x_ldm_register_adapter
end_define

begin_define
define|#
directive|define
name|ldm_register_device
value|rr232x_ldm_register_device
end_define

begin_define
define|#
directive|define
name|ldm_register_him_R_5_34_48_37_16
value|rr232x_ldm_register_him_R_5_34_48_37_16
end_define

begin_define
define|#
directive|define
name|ldm_register_vdev_class_R_5_34_48_37_16
value|rr232x_ldm_register_vdev_class_R_5_34_48_37_16
end_define

begin_define
define|#
directive|define
name|ldm_release_lock
value|rr232x_ldm_release_lock
end_define

begin_define
define|#
directive|define
name|ldm_release_vbus
value|rr232x_ldm_release_vbus
end_define

begin_define
define|#
directive|define
name|ldm_release_vdev
value|rr232x_ldm_release_vdev
end_define

begin_define
define|#
directive|define
name|ldm_remove_timer
value|rr232x_ldm_remove_timer
end_define

begin_define
define|#
directive|define
name|ldm_request_timer
value|rr232x_ldm_request_timer
end_define

begin_define
define|#
directive|define
name|ldm_reset_vbus
value|rr232x_ldm_reset_vbus
end_define

begin_define
define|#
directive|define
name|ldm_resume
value|rr232x_ldm_resume
end_define

begin_define
define|#
directive|define
name|ldm_shutdown
value|rr232x_ldm_shutdown
end_define

begin_define
define|#
directive|define
name|ldm_suspend
value|rr232x_ldm_suspend
end_define

begin_define
define|#
directive|define
name|ldm_sync_array_info
value|rr232x_ldm_sync_array_info
end_define

begin_define
define|#
directive|define
name|ldm_sync_array_stamp
value|rr232x_ldm_sync_array_stamp
end_define

begin_define
define|#
directive|define
name|ldm_timer_probe_device
value|rr232x_ldm_timer_probe_device
end_define

begin_define
define|#
directive|define
name|ldm_unregister_device
value|rr232x_ldm_unregister_device
end_define

begin_define
define|#
directive|define
name|num_drives_per_spinup
value|rr232x_num_drives_per_spinup
end_define

begin_define
define|#
directive|define
name|os_get_stamp
value|rr232x_os_get_stamp
end_define

begin_define
define|#
directive|define
name|os_get_vbus_seq
value|rr232x_os_get_vbus_seq
end_define

begin_define
define|#
directive|define
name|os_inb
value|rr232x_os_inb
end_define

begin_define
define|#
directive|define
name|os_inl
value|rr232x_os_inl
end_define

begin_define
define|#
directive|define
name|os_insw
value|rr232x_os_insw
end_define

begin_define
define|#
directive|define
name|os_inw
value|rr232x_os_inw
end_define

begin_define
define|#
directive|define
name|os_map_pci_bar
value|rr232x_os_map_pci_bar
end_define

begin_define
define|#
directive|define
name|os_outb
value|rr232x_os_outb
end_define

begin_define
define|#
directive|define
name|os_outl
value|rr232x_os_outl
end_define

begin_define
define|#
directive|define
name|os_outsw
value|rr232x_os_outsw
end_define

begin_define
define|#
directive|define
name|os_outw
value|rr232x_os_outw
end_define

begin_define
define|#
directive|define
name|os_pci_readb
value|rr232x_os_pci_readb
end_define

begin_define
define|#
directive|define
name|os_pci_readl
value|rr232x_os_pci_readl
end_define

begin_define
define|#
directive|define
name|os_pci_readw
value|rr232x_os_pci_readw
end_define

begin_define
define|#
directive|define
name|os_pci_writeb
value|rr232x_os_pci_writeb
end_define

begin_define
define|#
directive|define
name|os_pci_writel
value|rr232x_os_pci_writel
end_define

begin_define
define|#
directive|define
name|os_pci_writew
value|rr232x_os_pci_writew
end_define

begin_define
define|#
directive|define
name|os_printk
value|rr232x_os_printk
end_define

begin_define
define|#
directive|define
name|os_query_remove_device
value|rr232x_os_query_remove_device
end_define

begin_define
define|#
directive|define
name|os_query_time
value|rr232x_os_query_time
end_define

begin_define
define|#
directive|define
name|os_request_timer
value|rr232x_os_request_timer
end_define

begin_define
define|#
directive|define
name|os_revalidate_device
value|rr232x_os_revalidate_device
end_define

begin_define
define|#
directive|define
name|os_schedule_task
value|rr232x_os_schedule_task
end_define

begin_define
define|#
directive|define
name|os_stallexec
value|rr232x_os_stallexec
end_define

begin_define
define|#
directive|define
name|os_unmap_pci_bar
value|rr232x_os_unmap_pci_bar
end_define

begin_define
define|#
directive|define
name|osm_max_targets
value|rr232x_osm_max_targets
end_define

begin_define
define|#
directive|define
name|vdev_queue_cmd
value|rr232x_vdev_queue_cmd
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

