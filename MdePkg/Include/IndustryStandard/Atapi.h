begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file contains just some basic definitions that are needed by drivers   that dealing with ATA/ATAPI interface.  Copyright (c) 2007 - 2016, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATAPI_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATAPI_H_
end_define

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|///
end_comment

begin_comment
comment|/// ATA5_IDENTIFY_DATA is defined in ATA-5.
end_comment

begin_comment
comment|/// (This structure is provided mainly for backward-compatibility support.
end_comment

begin_comment
comment|/// Old drivers may reference fields that are marked "obsolete" in
end_comment

begin_comment
comment|/// ATA_IDENTIFY_DATA, which currently conforms to ATA-8.)
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|config
decl_stmt|;
comment|///< General Configuration.
name|UINT16
name|cylinders
decl_stmt|;
comment|///< Number of Cylinders.
name|UINT16
name|reserved_2
decl_stmt|;
name|UINT16
name|heads
decl_stmt|;
comment|///< Number of logical heads.
name|UINT16
name|vendor_data1
decl_stmt|;
name|UINT16
name|vendor_data2
decl_stmt|;
name|UINT16
name|sectors_per_track
decl_stmt|;
name|UINT16
name|vendor_specific_7_9
index|[
literal|3
index|]
decl_stmt|;
name|CHAR8
name|SerialNo
index|[
literal|20
index|]
decl_stmt|;
comment|///< ASCII
name|UINT16
name|vendor_specific_20_21
index|[
literal|2
index|]
decl_stmt|;
name|UINT16
name|ecc_bytes_available
decl_stmt|;
name|CHAR8
name|FirmwareVer
index|[
literal|8
index|]
decl_stmt|;
comment|///< ASCII
name|CHAR8
name|ModelName
index|[
literal|40
index|]
decl_stmt|;
comment|///< ASCII
name|UINT16
name|multi_sector_cmd_max_sct_cnt
decl_stmt|;
name|UINT16
name|reserved_48
decl_stmt|;
name|UINT16
name|capabilities
decl_stmt|;
name|UINT16
name|reserved_50
decl_stmt|;
name|UINT16
name|pio_cycle_timing
decl_stmt|;
name|UINT16
name|reserved_52
decl_stmt|;
name|UINT16
name|field_validity
decl_stmt|;
name|UINT16
name|current_cylinders
decl_stmt|;
name|UINT16
name|current_heads
decl_stmt|;
name|UINT16
name|current_sectors
decl_stmt|;
name|UINT16
name|CurrentCapacityLsb
decl_stmt|;
name|UINT16
name|CurrentCapacityMsb
decl_stmt|;
name|UINT16
name|reserved_59
decl_stmt|;
name|UINT16
name|user_addressable_sectors_lo
decl_stmt|;
name|UINT16
name|user_addressable_sectors_hi
decl_stmt|;
name|UINT16
name|reserved_62
decl_stmt|;
name|UINT16
name|multi_word_dma_mode
decl_stmt|;
name|UINT16
name|advanced_pio_modes
decl_stmt|;
name|UINT16
name|min_multi_word_dma_cycle_time
decl_stmt|;
name|UINT16
name|rec_multi_word_dma_cycle_time
decl_stmt|;
name|UINT16
name|min_pio_cycle_time_without_flow_control
decl_stmt|;
name|UINT16
name|min_pio_cycle_time_with_flow_control
decl_stmt|;
name|UINT16
name|reserved_69_79
index|[
literal|11
index|]
decl_stmt|;
name|UINT16
name|major_version_no
decl_stmt|;
name|UINT16
name|minor_version_no
decl_stmt|;
name|UINT16
name|command_set_supported_82
decl_stmt|;
comment|///< word 82
name|UINT16
name|command_set_supported_83
decl_stmt|;
comment|///< word 83
name|UINT16
name|command_set_feature_extn
decl_stmt|;
comment|///< word 84
name|UINT16
name|command_set_feature_enb_85
decl_stmt|;
comment|///< word 85
name|UINT16
name|command_set_feature_enb_86
decl_stmt|;
comment|///< word 86
name|UINT16
name|command_set_feature_default
decl_stmt|;
comment|///< word 87
name|UINT16
name|ultra_dma_mode
decl_stmt|;
comment|///< word 88
name|UINT16
name|reserved_89_127
index|[
literal|39
index|]
decl_stmt|;
name|UINT16
name|security_status
decl_stmt|;
name|UINT16
name|vendor_data_129_159
index|[
literal|31
index|]
decl_stmt|;
name|UINT16
name|reserved_160_255
index|[
literal|96
index|]
decl_stmt|;
block|}
name|ATA5_IDENTIFY_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// ATA_IDENTIFY_DATA strictly complies with ATA/ATAPI-8 Spec
end_comment

begin_comment
comment|/// to define the data returned by an ATA device upon successful
end_comment

begin_comment
comment|/// completion of the ATA IDENTIFY_DEVICE command.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|config
decl_stmt|;
comment|///< General Configuration.
name|UINT16
name|obsolete_1
decl_stmt|;
name|UINT16
name|specific_config
decl_stmt|;
comment|///< Specific Configuration.
name|UINT16
name|obsolete_3
decl_stmt|;
name|UINT16
name|retired_4_5
index|[
literal|2
index|]
decl_stmt|;
name|UINT16
name|obsolete_6
decl_stmt|;
name|UINT16
name|cfa_reserved_7_8
index|[
literal|2
index|]
decl_stmt|;
name|UINT16
name|retired_9
decl_stmt|;
name|CHAR8
name|SerialNo
index|[
literal|20
index|]
decl_stmt|;
comment|///< word 10~19
name|UINT16
name|retired_20_21
index|[
literal|2
index|]
decl_stmt|;
name|UINT16
name|obsolete_22
decl_stmt|;
name|CHAR8
name|FirmwareVer
index|[
literal|8
index|]
decl_stmt|;
comment|///< word 23~26
name|CHAR8
name|ModelName
index|[
literal|40
index|]
decl_stmt|;
comment|///< word 27~46
name|UINT16
name|multi_sector_cmd_max_sct_cnt
decl_stmt|;
name|UINT16
name|trusted_computing_support
decl_stmt|;
name|UINT16
name|capabilities_49
decl_stmt|;
name|UINT16
name|capabilities_50
decl_stmt|;
name|UINT16
name|obsolete_51_52
index|[
literal|2
index|]
decl_stmt|;
name|UINT16
name|field_validity
decl_stmt|;
name|UINT16
name|obsolete_54_58
index|[
literal|5
index|]
decl_stmt|;
name|UINT16
name|multi_sector_setting
decl_stmt|;
name|UINT16
name|user_addressable_sectors_lo
decl_stmt|;
name|UINT16
name|user_addressable_sectors_hi
decl_stmt|;
name|UINT16
name|obsolete_62
decl_stmt|;
name|UINT16
name|multi_word_dma_mode
decl_stmt|;
name|UINT16
name|advanced_pio_modes
decl_stmt|;
name|UINT16
name|min_multi_word_dma_cycle_time
decl_stmt|;
name|UINT16
name|rec_multi_word_dma_cycle_time
decl_stmt|;
name|UINT16
name|min_pio_cycle_time_without_flow_control
decl_stmt|;
name|UINT16
name|min_pio_cycle_time_with_flow_control
decl_stmt|;
name|UINT16
name|additional_supported
decl_stmt|;
comment|///< word 69
name|UINT16
name|reserved_70
decl_stmt|;
name|UINT16
name|reserved_71_74
index|[
literal|4
index|]
decl_stmt|;
comment|///< Reserved for IDENTIFY PACKET DEVICE cmd.
name|UINT16
name|queue_depth
decl_stmt|;
name|UINT16
name|serial_ata_capabilities
decl_stmt|;
name|UINT16
name|reserved_77
decl_stmt|;
comment|///< Reserved for Serial ATA
name|UINT16
name|serial_ata_features_supported
decl_stmt|;
name|UINT16
name|serial_ata_features_enabled
decl_stmt|;
name|UINT16
name|major_version_no
decl_stmt|;
name|UINT16
name|minor_version_no
decl_stmt|;
name|UINT16
name|command_set_supported_82
decl_stmt|;
comment|///< word 82
name|UINT16
name|command_set_supported_83
decl_stmt|;
comment|///< word 83
name|UINT16
name|command_set_feature_extn
decl_stmt|;
comment|///< word 84
name|UINT16
name|command_set_feature_enb_85
decl_stmt|;
comment|///< word 85
name|UINT16
name|command_set_feature_enb_86
decl_stmt|;
comment|///< word 86
name|UINT16
name|command_set_feature_default
decl_stmt|;
comment|///< word 87
name|UINT16
name|ultra_dma_mode
decl_stmt|;
comment|///< word 88
name|UINT16
name|time_for_security_erase_unit
decl_stmt|;
name|UINT16
name|time_for_enhanced_security_erase_unit
decl_stmt|;
name|UINT16
name|advanced_power_management_level
decl_stmt|;
name|UINT16
name|master_password_identifier
decl_stmt|;
name|UINT16
name|hardware_configuration_test_result
decl_stmt|;
name|UINT16
name|obsolete_94
decl_stmt|;
name|UINT16
name|stream_minimum_request_size
decl_stmt|;
name|UINT16
name|streaming_transfer_time_for_dma
decl_stmt|;
name|UINT16
name|streaming_access_latency_for_dma_and_pio
decl_stmt|;
name|UINT16
name|streaming_performance_granularity
index|[
literal|2
index|]
decl_stmt|;
comment|///< word 98~99
name|UINT16
name|maximum_lba_for_48bit_addressing
index|[
literal|4
index|]
decl_stmt|;
comment|///< word 100~103
name|UINT16
name|streaming_transfer_time_for_pio
decl_stmt|;
name|UINT16
name|max_no_of_512byte_blocks_per_data_set_cmd
decl_stmt|;
name|UINT16
name|phy_logic_sector_support
decl_stmt|;
comment|///< word 106
name|UINT16
name|interseek_delay_for_iso7779
decl_stmt|;
name|UINT16
name|world_wide_name
index|[
literal|4
index|]
decl_stmt|;
comment|///< word 108~111
name|UINT16
name|reserved_for_128bit_wwn_112_115
index|[
literal|4
index|]
decl_stmt|;
name|UINT16
name|reserved_for_technical_report
decl_stmt|;
name|UINT16
name|logic_sector_size_lo
decl_stmt|;
comment|///< word 117
name|UINT16
name|logic_sector_size_hi
decl_stmt|;
comment|///< word 118
name|UINT16
name|features_and_command_sets_supported_ext
decl_stmt|;
comment|///< word 119
name|UINT16
name|features_and_command_sets_enabled_ext
decl_stmt|;
comment|///< word 120
name|UINT16
name|reserved_121_126
index|[
literal|6
index|]
decl_stmt|;
name|UINT16
name|obsolete_127
decl_stmt|;
name|UINT16
name|security_status
decl_stmt|;
comment|///< word 128
name|UINT16
name|vendor_specific_129_159
index|[
literal|31
index|]
decl_stmt|;
name|UINT16
name|cfa_power_mode
decl_stmt|;
comment|///< word 160
name|UINT16
name|reserved_for_compactflash_161_167
index|[
literal|7
index|]
decl_stmt|;
name|UINT16
name|device_nominal_form_factor
decl_stmt|;
name|UINT16
name|is_data_set_cmd_supported
decl_stmt|;
name|CHAR8
name|additional_product_identifier
index|[
literal|8
index|]
decl_stmt|;
name|UINT16
name|reserved_174_175
index|[
literal|2
index|]
decl_stmt|;
name|CHAR8
name|media_serial_number
index|[
literal|60
index|]
decl_stmt|;
comment|///< word 176~205
name|UINT16
name|sct_command_transport
decl_stmt|;
comment|///< word 206
name|UINT16
name|reserved_207_208
index|[
literal|2
index|]
decl_stmt|;
name|UINT16
name|alignment_logic_in_phy_blocks
decl_stmt|;
comment|///< word 209
name|UINT16
name|write_read_verify_sector_count_mode3
index|[
literal|2
index|]
decl_stmt|;
comment|///< word 210~211
name|UINT16
name|verify_sector_count_mode2
index|[
literal|2
index|]
decl_stmt|;
name|UINT16
name|nv_cache_capabilities
decl_stmt|;
name|UINT16
name|nv_cache_size_in_logical_block_lsw
decl_stmt|;
comment|///< word 215
name|UINT16
name|nv_cache_size_in_logical_block_msw
decl_stmt|;
comment|///< word 216
name|UINT16
name|nominal_media_rotation_rate
decl_stmt|;
name|UINT16
name|reserved_218
decl_stmt|;
name|UINT16
name|nv_cache_options
decl_stmt|;
comment|///< word 219
name|UINT16
name|write_read_verify_mode
decl_stmt|;
comment|///< word 220
name|UINT16
name|reserved_221
decl_stmt|;
name|UINT16
name|transport_major_revision_number
decl_stmt|;
name|UINT16
name|transport_minor_revision_number
decl_stmt|;
name|UINT16
name|reserved_224_229
index|[
literal|6
index|]
decl_stmt|;
name|UINT64
name|extended_no_of_addressable_sectors
decl_stmt|;
name|UINT16
name|min_number_per_download_microcode_mode3
decl_stmt|;
comment|///< word 234
name|UINT16
name|max_number_per_download_microcode_mode3
decl_stmt|;
comment|///< word 235
name|UINT16
name|reserved_236_254
index|[
literal|19
index|]
decl_stmt|;
name|UINT16
name|integrity_word
decl_stmt|;
block|}
name|ATA_IDENTIFY_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// ATAPI_IDENTIFY_DATA strictly complies with ATA/ATAPI-8 Spec
end_comment

begin_comment
comment|/// to define the data returned by an ATAPI device upon successful
end_comment

begin_comment
comment|/// completion of the ATA IDENTIFY_PACKET_DEVICE command.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|config
decl_stmt|;
comment|///< General Configuration.
name|UINT16
name|reserved_1
decl_stmt|;
name|UINT16
name|specific_config
decl_stmt|;
comment|///< Specific Configuration.
name|UINT16
name|reserved_3_9
index|[
literal|7
index|]
decl_stmt|;
name|CHAR8
name|SerialNo
index|[
literal|20
index|]
decl_stmt|;
comment|///< word 10~19
name|UINT16
name|reserved_20_22
index|[
literal|3
index|]
decl_stmt|;
name|CHAR8
name|FirmwareVer
index|[
literal|8
index|]
decl_stmt|;
comment|///< word 23~26
name|CHAR8
name|ModelName
index|[
literal|40
index|]
decl_stmt|;
comment|///< word 27~46
name|UINT16
name|reserved_47_48
index|[
literal|2
index|]
decl_stmt|;
name|UINT16
name|capabilities_49
decl_stmt|;
name|UINT16
name|capabilities_50
decl_stmt|;
name|UINT16
name|obsolete_51
decl_stmt|;
name|UINT16
name|reserved_52
decl_stmt|;
name|UINT16
name|field_validity
decl_stmt|;
comment|///< word 53
name|UINT16
name|reserved_54_61
index|[
literal|8
index|]
decl_stmt|;
name|UINT16
name|dma_dir
decl_stmt|;
name|UINT16
name|multi_word_dma_mode
decl_stmt|;
comment|///< word 63
name|UINT16
name|advanced_pio_modes
decl_stmt|;
comment|///< word 64
name|UINT16
name|min_multi_word_dma_cycle_time
decl_stmt|;
name|UINT16
name|rec_multi_word_dma_cycle_time
decl_stmt|;
name|UINT16
name|min_pio_cycle_time_without_flow_control
decl_stmt|;
name|UINT16
name|min_pio_cycle_time_with_flow_control
decl_stmt|;
name|UINT16
name|reserved_69_70
index|[
literal|2
index|]
decl_stmt|;
name|UINT16
name|obsolete_71_72
index|[
literal|2
index|]
decl_stmt|;
name|UINT16
name|reserved_73_74
index|[
literal|2
index|]
decl_stmt|;
name|UINT16
name|obsolete_75
decl_stmt|;
name|UINT16
name|serial_ata_capabilities
decl_stmt|;
name|UINT16
name|reserved_77
decl_stmt|;
comment|///< Reserved for Serial ATA
name|UINT16
name|serial_ata_features_supported
decl_stmt|;
name|UINT16
name|serial_ata_features_enabled
decl_stmt|;
name|UINT16
name|major_version_no
decl_stmt|;
comment|///< word 80
name|UINT16
name|minor_version_no
decl_stmt|;
comment|///< word 81
name|UINT16
name|cmd_set_support_82
decl_stmt|;
name|UINT16
name|cmd_set_support_83
decl_stmt|;
name|UINT16
name|cmd_feature_support
decl_stmt|;
name|UINT16
name|cmd_feature_enable_85
decl_stmt|;
name|UINT16
name|cmd_feature_enable_86
decl_stmt|;
name|UINT16
name|cmd_feature_default
decl_stmt|;
name|UINT16
name|ultra_dma_select
decl_stmt|;
name|UINT16
name|time_required_for_sec_erase
decl_stmt|;
comment|///< word 89
name|UINT16
name|time_required_for_enhanced_sec_erase
decl_stmt|;
comment|///< word 90
name|UINT16
name|advanced_power_management_level
decl_stmt|;
name|UINT16
name|master_pwd_revison_code
decl_stmt|;
name|UINT16
name|hardware_reset_result
decl_stmt|;
comment|///< word 93
name|UINT16
name|obsolete_94
decl_stmt|;
name|UINT16
name|reserved_95_107
index|[
literal|13
index|]
decl_stmt|;
name|UINT16
name|world_wide_name
index|[
literal|4
index|]
decl_stmt|;
comment|///< word 108~111
name|UINT16
name|reserved_for_128bit_wwn_112_115
index|[
literal|4
index|]
decl_stmt|;
name|UINT16
name|reserved_116_118
index|[
literal|3
index|]
decl_stmt|;
name|UINT16
name|command_and_feature_sets_supported
decl_stmt|;
comment|///< word 119
name|UINT16
name|command_and_feature_sets_supported_enabled
decl_stmt|;
name|UINT16
name|reserved_121_124
index|[
literal|4
index|]
decl_stmt|;
name|UINT16
name|atapi_byte_count_0_behavior
decl_stmt|;
comment|///< word 125
name|UINT16
name|obsolete_126_127
index|[
literal|2
index|]
decl_stmt|;
name|UINT16
name|security_status
decl_stmt|;
name|UINT16
name|reserved_129_159
index|[
literal|31
index|]
decl_stmt|;
name|UINT16
name|cfa_reserved_160_175
index|[
literal|16
index|]
decl_stmt|;
name|UINT16
name|reserved_176_221
index|[
literal|46
index|]
decl_stmt|;
name|UINT16
name|transport_major_version
decl_stmt|;
name|UINT16
name|transport_minor_version
decl_stmt|;
name|UINT16
name|reserved_224_254
index|[
literal|31
index|]
decl_stmt|;
name|UINT16
name|integrity_word
decl_stmt|;
block|}
name|ATAPI_IDENTIFY_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Standard Quiry Data format, defined in SFF-8070i(ATAPI Removable Rewritable Specification).
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|peripheral_type
decl_stmt|;
name|UINT8
name|RMB
decl_stmt|;
name|UINT8
name|version
decl_stmt|;
name|UINT8
name|response_data_format
decl_stmt|;
name|UINT8
name|addnl_length
decl_stmt|;
comment|///< n - 4, Numbers of bytes following this one.
name|UINT8
name|reserved_5
decl_stmt|;
name|UINT8
name|reserved_6
decl_stmt|;
name|UINT8
name|reserved_7
decl_stmt|;
name|UINT8
name|vendor_info
index|[
literal|8
index|]
decl_stmt|;
name|UINT8
name|product_id
index|[
literal|16
index|]
decl_stmt|;
name|UINT8
name|product_revision_level
index|[
literal|4
index|]
decl_stmt|;
name|UINT8
name|vendor_specific_36_55
index|[
literal|55
operator|-
literal|36
operator|+
literal|1
index|]
decl_stmt|;
name|UINT8
name|reserved_56_95
index|[
literal|95
operator|-
literal|56
operator|+
literal|1
index|]
decl_stmt|;
comment|///
comment|/// Vendor-specific parameters fields. The sizeof (ATAPI_INQUIRY_DATA) is 254
comment|/// since allocation_length is one byte in ATAPI_INQUIRY_CMD.
comment|///
name|UINT8
name|vendor_specific_96_253
index|[
literal|253
operator|-
literal|96
operator|+
literal|1
index|]
decl_stmt|;
block|}
name|ATAPI_INQUIRY_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Request Sense Standard Data, defined in SFF-8070i(ATAPI Removable Rewritable Specification).
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|error_code
range|:
literal|7
decl_stmt|;
name|UINT8
name|valid
range|:
literal|1
decl_stmt|;
name|UINT8
name|reserved_1
decl_stmt|;
name|UINT8
name|sense_key
range|:
literal|4
decl_stmt|;
name|UINT8
name|reserved_2
range|:
literal|1
decl_stmt|;
name|UINT8
name|Vendor_specifc_1
range|:
literal|3
decl_stmt|;
name|UINT8
name|vendor_specific_3
decl_stmt|;
name|UINT8
name|vendor_specific_4
decl_stmt|;
name|UINT8
name|vendor_specific_5
decl_stmt|;
name|UINT8
name|vendor_specific_6
decl_stmt|;
name|UINT8
name|addnl_sense_length
decl_stmt|;
comment|///< n - 7
name|UINT8
name|vendor_specific_8
decl_stmt|;
name|UINT8
name|vendor_specific_9
decl_stmt|;
name|UINT8
name|vendor_specific_10
decl_stmt|;
name|UINT8
name|vendor_specific_11
decl_stmt|;
name|UINT8
name|addnl_sense_code
decl_stmt|;
comment|///< mandatory
name|UINT8
name|addnl_sense_code_qualifier
decl_stmt|;
comment|///< mandatory
name|UINT8
name|field_replaceable_unit_code
decl_stmt|;
comment|///< optional
name|UINT8
name|sense_key_specific_15
range|:
literal|7
decl_stmt|;
name|UINT8
name|SKSV
range|:
literal|1
decl_stmt|;
name|UINT8
name|sense_key_specific_16
decl_stmt|;
name|UINT8
name|sense_key_specific_17
decl_stmt|;
block|}
name|ATAPI_REQUEST_SENSE_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// READ CAPACITY Data, defined in SFF-8070i(ATAPI Removable Rewritable Specification).
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|LastLba3
decl_stmt|;
name|UINT8
name|LastLba2
decl_stmt|;
name|UINT8
name|LastLba1
decl_stmt|;
name|UINT8
name|LastLba0
decl_stmt|;
name|UINT8
name|BlockSize3
decl_stmt|;
name|UINT8
name|BlockSize2
decl_stmt|;
name|UINT8
name|BlockSize1
decl_stmt|;
name|UINT8
name|BlockSize0
decl_stmt|;
block|}
name|ATAPI_READ_CAPACITY_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Capacity List Header + Current/Maximum Capacity Descriptor,
end_comment

begin_comment
comment|/// defined in SFF-8070i(ATAPI Removable Rewritable Specification).
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|reserved_0
decl_stmt|;
name|UINT8
name|reserved_1
decl_stmt|;
name|UINT8
name|reserved_2
decl_stmt|;
name|UINT8
name|Capacity_Length
decl_stmt|;
name|UINT8
name|LastLba3
decl_stmt|;
name|UINT8
name|LastLba2
decl_stmt|;
name|UINT8
name|LastLba1
decl_stmt|;
name|UINT8
name|LastLba0
decl_stmt|;
name|UINT8
name|DesCode
range|:
literal|2
decl_stmt|;
name|UINT8
name|reserved_9
range|:
literal|6
decl_stmt|;
name|UINT8
name|BlockSize2
decl_stmt|;
name|UINT8
name|BlockSize1
decl_stmt|;
name|UINT8
name|BlockSize0
decl_stmt|;
block|}
name|ATAPI_READ_FORMAT_CAPACITY_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Test Unit Ready Command, defined in SFF-8070i(ATAPI Removable Rewritable Specification).
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|opcode
decl_stmt|;
name|UINT8
name|reserved_1
decl_stmt|;
name|UINT8
name|reserved_2
decl_stmt|;
name|UINT8
name|reserved_3
decl_stmt|;
name|UINT8
name|reserved_4
decl_stmt|;
name|UINT8
name|reserved_5
decl_stmt|;
name|UINT8
name|reserved_6
decl_stmt|;
name|UINT8
name|reserved_7
decl_stmt|;
name|UINT8
name|reserved_8
decl_stmt|;
name|UINT8
name|reserved_9
decl_stmt|;
name|UINT8
name|reserved_10
decl_stmt|;
name|UINT8
name|reserved_11
decl_stmt|;
block|}
name|ATAPI_TEST_UNIT_READY_CMD
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// INQUIRY Command, defined in SFF-8070i(ATAPI Removable Rewritable Specification).
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|opcode
decl_stmt|;
name|UINT8
name|reserved_1
range|:
literal|5
decl_stmt|;
name|UINT8
name|lun
range|:
literal|3
decl_stmt|;
name|UINT8
name|page_code
decl_stmt|;
comment|///< defined in SFF8090i, V6
name|UINT8
name|reserved_3
decl_stmt|;
name|UINT8
name|allocation_length
decl_stmt|;
name|UINT8
name|reserved_5
decl_stmt|;
name|UINT8
name|reserved_6
decl_stmt|;
name|UINT8
name|reserved_7
decl_stmt|;
name|UINT8
name|reserved_8
decl_stmt|;
name|UINT8
name|reserved_9
decl_stmt|;
name|UINT8
name|reserved_10
decl_stmt|;
name|UINT8
name|reserved_11
decl_stmt|;
block|}
name|ATAPI_INQUIRY_CMD
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// REQUEST SENSE Command, defined in SFF-8070i(ATAPI Removable Rewritable Specification).
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|opcode
decl_stmt|;
name|UINT8
name|reserved_1
range|:
literal|5
decl_stmt|;
name|UINT8
name|lun
range|:
literal|3
decl_stmt|;
name|UINT8
name|reserved_2
decl_stmt|;
name|UINT8
name|reserved_3
decl_stmt|;
name|UINT8
name|allocation_length
decl_stmt|;
name|UINT8
name|reserved_5
decl_stmt|;
name|UINT8
name|reserved_6
decl_stmt|;
name|UINT8
name|reserved_7
decl_stmt|;
name|UINT8
name|reserved_8
decl_stmt|;
name|UINT8
name|reserved_9
decl_stmt|;
name|UINT8
name|reserved_10
decl_stmt|;
name|UINT8
name|reserved_11
decl_stmt|;
block|}
name|ATAPI_REQUEST_SENSE_CMD
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// READ (10) Command, defined in SFF-8070i(ATAPI Removable Rewritable Specification).
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|opcode
decl_stmt|;
name|UINT8
name|reserved_1
range|:
literal|5
decl_stmt|;
name|UINT8
name|lun
range|:
literal|3
decl_stmt|;
name|UINT8
name|Lba0
decl_stmt|;
name|UINT8
name|Lba1
decl_stmt|;
name|UINT8
name|Lba2
decl_stmt|;
name|UINT8
name|Lba3
decl_stmt|;
name|UINT8
name|reserved_6
decl_stmt|;
name|UINT8
name|TranLen0
decl_stmt|;
name|UINT8
name|TranLen1
decl_stmt|;
name|UINT8
name|reserved_9
decl_stmt|;
name|UINT8
name|reserved_10
decl_stmt|;
name|UINT8
name|reserved_11
decl_stmt|;
block|}
name|ATAPI_READ10_CMD
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// READ Format Capacity Command, defined in SFF-8070i(ATAPI Removable Rewritable Specification).
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|opcode
decl_stmt|;
name|UINT8
name|reserved_1
range|:
literal|5
decl_stmt|;
name|UINT8
name|lun
range|:
literal|3
decl_stmt|;
name|UINT8
name|reserved_2
decl_stmt|;
name|UINT8
name|reserved_3
decl_stmt|;
name|UINT8
name|reserved_4
decl_stmt|;
name|UINT8
name|reserved_5
decl_stmt|;
name|UINT8
name|reserved_6
decl_stmt|;
name|UINT8
name|allocation_length_hi
decl_stmt|;
name|UINT8
name|allocation_length_lo
decl_stmt|;
name|UINT8
name|reserved_9
decl_stmt|;
name|UINT8
name|reserved_10
decl_stmt|;
name|UINT8
name|reserved_11
decl_stmt|;
block|}
name|ATAPI_READ_FORMAT_CAP_CMD
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// MODE SENSE Command, defined in SFF-8070i(ATAPI Removable Rewritable Specification).
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|opcode
decl_stmt|;
name|UINT8
name|reserved_1
range|:
literal|5
decl_stmt|;
name|UINT8
name|lun
range|:
literal|3
decl_stmt|;
name|UINT8
name|page_code
range|:
literal|6
decl_stmt|;
name|UINT8
name|page_control
range|:
literal|2
decl_stmt|;
name|UINT8
name|reserved_3
decl_stmt|;
name|UINT8
name|reserved_4
decl_stmt|;
name|UINT8
name|reserved_5
decl_stmt|;
name|UINT8
name|reserved_6
decl_stmt|;
name|UINT8
name|parameter_list_length_hi
decl_stmt|;
name|UINT8
name|parameter_list_length_lo
decl_stmt|;
name|UINT8
name|reserved_9
decl_stmt|;
name|UINT8
name|reserved_10
decl_stmt|;
name|UINT8
name|reserved_11
decl_stmt|;
block|}
name|ATAPI_MODE_SENSE_CMD
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// ATAPI_PACKET_COMMAND is not defined in the ATA specification.
end_comment

begin_comment
comment|/// We add it here for the convenience of ATA/ATAPI module writers.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|UINT16
name|Data16
index|[
literal|6
index|]
decl_stmt|;
name|ATAPI_TEST_UNIT_READY_CMD
name|TestUnitReady
decl_stmt|;
name|ATAPI_READ10_CMD
name|Read10
decl_stmt|;
name|ATAPI_REQUEST_SENSE_CMD
name|RequestSence
decl_stmt|;
name|ATAPI_INQUIRY_CMD
name|Inquiry
decl_stmt|;
name|ATAPI_MODE_SENSE_CMD
name|ModeSense
decl_stmt|;
name|ATAPI_READ_FORMAT_CAP_CMD
name|ReadFormatCapacity
decl_stmt|;
block|}
name|ATAPI_PACKET_COMMAND
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_define
define|#
directive|define
name|ATAPI_MAX_DMA_EXT_CMD_SECTORS
value|0x10000
end_define

begin_define
define|#
directive|define
name|ATAPI_MAX_DMA_CMD_SECTORS
value|0x100
end_define

begin_comment
comment|//  ATA/ATAPI Signature equates
end_comment

begin_define
define|#
directive|define
name|ATA_SIGNATURE
value|0x0101
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATAPI_SIGNATURE
value|0xeb14
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATAPI_SIGNATURE_32
value|0xeb140101
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_comment
comment|//  Spin Up Configuration definitions
end_comment

begin_define
define|#
directive|define
name|ATA_SPINUP_CFG_REQUIRED_IDD_INCOMPLETE
value|0x37c8
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SPINUP_CFG_REQUIRED_IDD_COMPLETE
value|0x738c
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SPINUP_CFG_NOT_REQUIRED_IDD_INCOMPLETE
value|0x8c73
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SPINUP_CFG_NOT_REQUIRED_IDD_COMPLETE
value|0xc837
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ATA Packet Command Code
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_FORMAT_UNIT
value|0x04
end_define

begin_comment
comment|///< defined in ATAPI Removable Rewritable Media Devcies
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_SOFT_RESET
value|0x08
end_define

begin_comment
comment|///< defined from ATA-3
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_PACKET
value|0xA0
end_define

begin_comment
comment|///< defined from ATA-3
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_IDENTIFY_DEVICE
value|0xA1
end_define

begin_comment
comment|///< defined from ATA-3
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_SERVICE
value|0xA2
end_define

begin_comment
comment|///< defined from ATA-3
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_TEST_UNIT_READY
value|0x00
end_define

begin_comment
comment|///< defined from ATA-1
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_REQUEST_SENSE
value|0x03
end_define

begin_comment
comment|///< defined from ATA-4
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_INQUIRY
value|0x12
end_define

begin_comment
comment|///< defined in ATAPI Removable Rewritable Media Devcies
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_READ_FORMAT_CAPACITY
value|0x23
end_define

begin_comment
comment|///< defined in ATAPI Removable Rewritable Media Devcies
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_READ_CAPACITY
value|0x25
end_define

begin_comment
comment|///< defined in ATAPI Removable Rewritable Media Devcies
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_READ_10
value|0x28
end_define

begin_comment
comment|///< defined in ATAPI Removable Rewritable Media Devcies
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_WRITE_10
value|0x2A
end_define

begin_comment
comment|///< defined in ATAPI Removable Rewritable Media Devcies
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_ATAPI_SEEK
value|0x2B
end_define

begin_comment
comment|///< defined in ATAPI Removable Rewritable Media Devcies
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_WRITE_AND_VERIFY
value|0x2E
end_define

begin_comment
comment|///< defined in ATAPI Removable Rewritable Media Devcies
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_VERIFY
value|0x2F
end_define

begin_comment
comment|///< defined in ATAPI Removable Rewritable Media Devcies
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_READ_12
value|0xA8
end_define

begin_comment
comment|///< defined in ATAPI Removable Rewritable Media Devcies
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_WRITE_12
value|0xAA
end_define

begin_comment
comment|///< defined in ATAPI Removable Rewritable Media Devcies
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_START_STOP_UNIT
value|0x1B
end_define

begin_comment
comment|///< defined in ATAPI Removable Rewritable Media Devcies
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_PREVENT_ALLOW_MEDIA_REMOVAL
value|0x1E
end_define

begin_comment
comment|///< defined in ATAPI Removable Rewritable Media Devcies
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_MODE_SELECT
value|0x55
end_define

begin_comment
comment|///< defined in ATAPI Removable Rewritable Media Devcies
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_MODE_SENSE
value|0x5A
end_define

begin_comment
comment|///< defined in ATAPI Removable Rewritable Media Devcies
end_comment

begin_define
define|#
directive|define
name|ATA_PAGE_CODE_READ_WRITE_ERROR
value|0x01
end_define

begin_comment
comment|///< defined in ATAPI Removable Rewritable Media Devcies
end_comment

begin_define
define|#
directive|define
name|ATA_PAGE_CODE_CACHING_PAGE
value|0x08
end_define

begin_comment
comment|///< defined in ATAPI Removable Rewritable Media Devcies
end_comment

begin_define
define|#
directive|define
name|ATA_PAGE_CODE_REMOVABLE_BLOCK_CAPABILITIES
value|0x1B
end_define

begin_comment
comment|///< defined in ATAPI Removable Rewritable Media Devcies
end_comment

begin_define
define|#
directive|define
name|ATA_PAGE_CODE_TIMER_PROTECT_PAGE
value|0x1C
end_define

begin_comment
comment|///< defined in ATAPI Removable Rewritable Media Devcies
end_comment

begin_define
define|#
directive|define
name|ATA_PAGE_CODE_RETURN_ALL_PAGES
value|0x3F
end_define

begin_comment
comment|///< defined in ATAPI Removable Rewritable Media Devcies
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_GET_CONFIGURATION
value|0x46
end_define

begin_comment
comment|///< defined in ATAPI Multimedia Devices
end_comment

begin_define
define|#
directive|define
name|ATA_GCCD_RT_FIELD_VALUE_ALL
value|0x00
end_define

begin_comment
comment|///< defined in ATAPI Multimedia Devices
end_comment

begin_define
define|#
directive|define
name|ATA_GCCD_RT_FIELD_VALUE_CURRENT
value|0x01
end_define

begin_comment
comment|///< defined in ATAPI Multimedia Devices
end_comment

begin_define
define|#
directive|define
name|ATA_GCCD_RT_FIELD_VALUE_SINGLE
value|0x02
end_define

begin_comment
comment|///< defined in ATAPI Multimedia Devices
end_comment

begin_define
define|#
directive|define
name|ATA_GCCD_RT_FIELD_VALUE_RESERVED
value|0x03
end_define

begin_comment
comment|///< defined in ATAPI Multimedia Devices
end_comment

begin_define
define|#
directive|define
name|ATA_FEATURE_LIST_PROFILE_LIST
value|0x0000
end_define

begin_comment
comment|///< defined in ATAPI Multimedia Devices
end_comment

begin_define
define|#
directive|define
name|ATA_FEATURE_LIST_CORE
value|0x0001
end_define

begin_comment
comment|///< defined in ATAPI Multimedia Devices
end_comment

begin_define
define|#
directive|define
name|ATA_FEATURE_LIST_MORPHING
value|0x0002
end_define

begin_comment
comment|///< defined in ATAPI Multimedia Devices
end_comment

begin_define
define|#
directive|define
name|ATA_FEATURE_LIST_REMOVEABLE_MEDIUM
value|0x0003
end_define

begin_comment
comment|///< defined in ATAPI Multimedia Devices
end_comment

begin_define
define|#
directive|define
name|ATA_FEATURE_LIST_WRITE_PROTECT
value|0x0004
end_define

begin_comment
comment|///< defined in ATAPI Multimedia Devices
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Start/Stop and Eject Operations
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_SUBOP_STOP_DISC
value|0x00
end_define

begin_comment
comment|///< Stop the Disc
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_SUBOP_START_DISC
value|0x01
end_define

begin_comment
comment|///< Start the Disc and acquire the format type
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_SUBOP_EJECT_DISC
value|0x02
end_define

begin_comment
comment|///< Eject the Disc if possible
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_SUBOP_CLOSE_TRAY
value|0x03
end_define

begin_comment
comment|///< Load the Disc (Close Tray)
end_comment

begin_comment
comment|///@}
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ATA Commands Code
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Class 1: PIO Data-In Commands
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_IDENTIFY_DRIVE
value|0xec
end_define

begin_comment
comment|///< defined from ATA-3
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_READ_BUFFER
value|0xe4
end_define

begin_comment
comment|///< defined from ATA-1
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_READ_SECTORS
value|0x20
end_define

begin_comment
comment|///< defined from ATA-1
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_READ_SECTORS_WITH_RETRY
value|0x21
end_define

begin_comment
comment|///< defined from ATA-1, obsoleted from ATA-5
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_READ_LONG
value|0x22
end_define

begin_comment
comment|///< defined from ATA-1, obsoleted from ATA-5
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_READ_LONG_WITH_RETRY
value|0x23
end_define

begin_comment
comment|///< defined from ATA-1, obsoleted from ATA-5
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_READ_SECTORS_EXT
value|0x24
end_define

begin_comment
comment|///< defined from ATA-6
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_READ_MULTIPLE
value|0xc4
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_READ_MULTIPLE_EXT
value|0x29
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_READ_LOG_EXT
value|0x2f
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Class 2: PIO Data-Out Commands
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_FORMAT_TRACK
value|0x50
end_define

begin_comment
comment|///< defined from ATA-1, obsoleted from ATA-4
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_WRITE_BUFFER
value|0xe8
end_define

begin_comment
comment|///< defined from ATA-1
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_WRITE_SECTORS
value|0x30
end_define

begin_comment
comment|///< defined from ATA-1
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_WRITE_SECTORS_WITH_RETRY
value|0x31
end_define

begin_comment
comment|///< defined from ATA-1, obsoleted from ATA-5
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_WRITE_LONG
value|0x32
end_define

begin_comment
comment|///< defined from ATA-1, obsoleted from ATA-5
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_WRITE_LONG_WITH_RETRY
value|0x33
end_define

begin_comment
comment|///< defined from ATA-1, obsoleted from ATA-5
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_WRITE_VERIFY
value|0x3c
end_define

begin_comment
comment|///< defined from ATA-1, obsoleted from ATA-5
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_WRITE_SECTORS_EXT
value|0x34
end_define

begin_comment
comment|///< defined from ATA-6
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_WRITE_MULTIPLE
value|0xc5
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_WRITE_MULTIPLE_EXT
value|0x39
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Class 3 No Data Command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_ACK_MEDIA_CHANGE
value|0xdb
end_define

begin_comment
comment|///< defined from ATA-1, obsoleted from ATA-5
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_BOOT_POST_BOOT
value|0xdc
end_define

begin_comment
comment|///< defined from ATA-1, obsoleted from ATA-3
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_BOOT_PRE_BOOT
value|0xdd
end_define

begin_comment
comment|///< defined from ATA-1, obsoleted from ATA-3
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_CHECK_POWER_MODE
value|0x98
end_define

begin_comment
comment|///< defined from ATA-1, obsoleted from ATA-4
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_CHECK_POWER_MODE_ALIAS
value|0xe5
end_define

begin_comment
comment|///< defined from ATA-1
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_DOOR_LOCK
value|0xde
end_define

begin_comment
comment|///< defined from ATA-1
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_DOOR_UNLOCK
value|0xdf
end_define

begin_comment
comment|///< defined from ATA-1
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_EXEC_DRIVE_DIAG
value|0x90
end_define

begin_comment
comment|///< defined from ATA-1
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_IDLE_ALIAS
value|0x97
end_define

begin_comment
comment|///< defined from ATA-1, obsoleted from ATA-4
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_IDLE
value|0xe3
end_define

begin_comment
comment|///< defined from ATA-1
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_IDLE_IMMEDIATE
value|0x95
end_define

begin_comment
comment|///< defined from ATA-1, obsoleted from ATA-4
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_IDLE_IMMEDIATE_ALIAS
value|0xe1
end_define

begin_comment
comment|///< defined from ATA-1
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_INIT_DRIVE_PARAM
value|0x91
end_define

begin_comment
comment|///< defined from ATA-1, obsoleted from ATA-6
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_RECALIBRATE
value|0x10
end_define

begin_comment
comment|///< defined from ATA-1, obsoleted from ATA-4
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_READ_DRIVE_STATE
value|0xe9
end_define

begin_comment
comment|///< defined from ATA-1, obsoleted from ATA-3
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_SET_MULTIPLE_MODE
value|0xC6
end_define

begin_comment
comment|///< defined from ATA-2
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_READ_VERIFY
value|0x40
end_define

begin_comment
comment|///< defined from ATA-1
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_READ_VERIFY_WITH_RETRY
value|0x41
end_define

begin_comment
comment|///< defined from ATA-1, obsoleted from ATA-5
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_SEEK
value|0x70
end_define

begin_comment
comment|///< defined from ATA-1
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_SET_FEATURES
value|0xef
end_define

begin_comment
comment|///< defined from ATA-1
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_STANDBY
value|0x96
end_define

begin_comment
comment|///< defined from ATA-1, obsoleted from ATA-4
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_STANDBY_ALIAS
value|0xe2
end_define

begin_comment
comment|///< defined from ATA-1
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_STANDBY_IMMEDIATE
value|0x94
end_define

begin_comment
comment|///< defined from ATA-1, obsoleted from ATA-4
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_STANDBY_IMMEDIATE_ALIAS
value|0xe0
end_define

begin_comment
comment|///< defined from ATA-1
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_SLEEP
value|0xe6
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_READ_NATIVE_MAX_ADDRESS
value|0xf8
end_define

begin_comment
comment|///< defined in ATA-6
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_READ_NATIVE_MAX_ADDRESS_EXT
value|0x27
end_define

begin_comment
comment|///< defined in ATA-6
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Set Features Sub Command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ATA_SUB_CMD_ENABLE_VOLATILE_WRITE_CACHE
value|0x02
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SUB_CMD_SET_TRANSFER_MODE
value|0x03
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SUB_CMD_ENABLE_APM
value|0x05
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SUB_CMD_ENABLE_PUIS
value|0x06
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SUB_CMD_PUIS_SET_DEVICE_SPINUP
value|0x07
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SUB_CMD_ENABLE_WRITE_READ_VERIFY
value|0x0b
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SUB_CMD_ENABLE_SATA_FEATURE
value|0x10
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SUB_CMD_DISABLE_MEDIA_STATUS_NOTIFICATION
value|0x31
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SUB_CMD_ENABLE_FREE_FALL_CONTROL
value|0x41
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SUB_CMD_ACOUSTIC_MANAGEMENT_ENABLE
value|0x42
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SUB_CMD_SET_MAX_HOST_INTERFACE_SECTOR_TIMES
value|0x43
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SUB_CMD_EXTENDED_POWER_CONDITIONS
value|0x4a
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SUB_CMD_DISABLE_READ_LOOK_AHEAD
value|0x55
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SUB_CMD_EN_DIS_DSN_FEATURE
value|0x63
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SUB_CMD_DISABLE_REVERT_TO_POWER_ON_DEFAULTS
value|0x66
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SUB_CMD_DISABLE_VOLATILE_WRITE_CACHE
value|0x82
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SUB_CMD_DISABLE_APM
value|0x85
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SUB_CMD_DISABLE_PUIS
value|0x86
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SUB_CMD_DISABLE_WRITE_READ_VERIFY
value|0x8b
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SUB_CMD_DISABLE_SATA_FEATURE
value|0x90
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SUB_CMD_ENABLE_MEDIA_STATUS_NOTIFICATION
value|0x95
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SUB_CMD_ENABLE_READ_LOOK_AHEAD
value|0xaa
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SUB_CMD_DISABLE_FREE_FALL_CONTROL
value|0xc1
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SUB_CMD_ACOUSTIC_MANAGEMENT_DISABLE
value|0xc2
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SUB_CMD_EN_DIS_SENSE_DATA_REPORTING
value|0xc3
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SUB_CMD_ENABLE_REVERT_TO_POWER_ON_DEFAULTS
value|0xcc
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// S.M.A.R.T
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_SMART
value|0xb0
end_define

begin_comment
comment|///< defined from ATA-3
end_comment

begin_define
define|#
directive|define
name|ATA_CONSTANT_C2
value|0xc2
end_define

begin_comment
comment|///< reserved
end_comment

begin_define
define|#
directive|define
name|ATA_CONSTANT_4F
value|0x4f
end_define

begin_comment
comment|///< reserved
end_comment

begin_define
define|#
directive|define
name|ATA_SMART_READ_DATA
value|0xd0
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SMART_AUTOSAVE
value|0xd2
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_AUTOSAVE_DISABLE_ATTR
value|0x00
end_define

begin_define
define|#
directive|define
name|ATA_AUTOSAVE_ENABLE_ATTR
value|0xf1
end_define

begin_define
define|#
directive|define
name|ATA_SMART_EXECUTE_OFFLINE_IMMEDIATE
value|0xd4
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_EXECUTE_SMART_OFFLINE_ROUTINE
value|0x00
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_EXECUTE_SMART_OFFLINE_SHORT_SELFTEST
value|0x01
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_EXECUTE_SMART_OFFLINE_EXTENDED_SELFTEST
value|0x02
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_EXECUTE_SMART_OFFLINE_CONVEYANCE_SELFTEST
value|0x03
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_EXECUTE_SMART_OFFLINE_SELECTIVE_SELFTEST
value|0x04
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SMART_ABORT_SELF_TEST_SUBROUTINE
value|0x7f
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_EXECUTE_SMART_CAPTIVE_SHORT_SELFTEST
value|0x81
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_EXECUTE_SMART_CAPTIVE_EXTENDED_SELFTEST
value|0x82
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_EXECUTE_SMART_CAPTIVE_CONVEYANCE_SELFTEST
value|0x83
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_EXECUTE_SMART_CAPTIVE_SELECTIVE_SELFTEST
value|0x84
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SMART_READLOG
value|0xd5
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SMART_WRITELOG
value|0xd6
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SMART_ENABLE_OPERATION
value|0xd8
end_define

begin_comment
comment|///< reserved
end_comment

begin_define
define|#
directive|define
name|ATA_SMART_DISABLE_OPERATION
value|0xd9
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SMART_RETURN_STATUS
value|0xda
end_define

begin_comment
comment|///< defined from ATA-3
end_comment

begin_define
define|#
directive|define
name|ATA_SMART_THRESHOLD_NOT_EXCEEDED_VALUE
value|0xc24f
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SMART_THRESHOLD_EXCEEDED_VALUE
value|0x2cf4
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_comment
comment|// SMART Log Definitions
end_comment

begin_define
define|#
directive|define
name|ATA_SMART_LOG_DIRECTORY
value|0x00
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SMART_SUM_SMART_ERROR_LOG
value|0x01
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SMART_COMP_SMART_ERROR_LOG
value|0x02
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SMART_EXT_COMP_SMART_ERROR_LOG
value|0x03
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SMART_SMART_SELFTEST_LOG
value|0x06
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SMART_EXT_SMART_SELFTEST_LOG
value|0x07
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SMART_SELECTIVE_SELFTEST_LOG
value|0x09
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SMART_HOST_VENDOR_SPECIFIC
value|0x80
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SMART_DEVICE_VENDOR_SPECIFIC
value|0xa0
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Class 4: DMA Command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_READ_DMA
value|0xc8
end_define

begin_comment
comment|///< defined from ATA-1
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_READ_DMA_WITH_RETRY
value|0xc9
end_define

begin_comment
comment|///< defined from ATA-1, obsoleted from ATA-5
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_READ_DMA_EXT
value|0x25
end_define

begin_comment
comment|///< defined from ATA-6
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_WRITE_DMA
value|0xca
end_define

begin_comment
comment|///< defined from ATA-1
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_WRITE_DMA_WITH_RETRY
value|0xcb
end_define

begin_comment
comment|///< defined from ATA-1, obsoleted from ATA-
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_WRITE_DMA_EXT
value|0x35
end_define

begin_comment
comment|///< defined from ATA-6
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  ATA Security commands
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_SECURITY_SET_PASSWORD
value|0xf1
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_SECURITY_UNLOCK
value|0xf2
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_SECURITY_ERASE_PREPARE
value|0xf3
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_SECURITY_ERASE_UNIT
value|0xf4
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_SECURITY_FREEZE_LOCK
value|0xf5
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_SECURITY_DISABLE_PASSWORD
value|0xf6
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_SECURITY_BUFFER_LENGTH
value|512
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  ATA Device Config Overlay
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_DEV_CONFIG_OVERLAY
value|0xb1
end_define

begin_comment
comment|///< defined from ATA-6
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_DEV_CONFIG_RESTORE_FEATURE
value|0xc0
end_define

begin_comment
comment|///< defined from ATA-6
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_DEV_CONFIG_FREEZELOCK_FEATURE
value|0xc1
end_define

begin_comment
comment|///< defined from ATA-6
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_DEV_CONFIG_IDENTIFY_FEATURE
value|0xc2
end_define

begin_comment
comment|///< defined from ATA-6
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_DEV_CONFIG_SET_FEATURE
value|0xc3
end_define

begin_comment
comment|///< defined from ATA-6
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  ATA Trusted Computing Feature Set Commands
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_TRUSTED_NON_DATA
value|0x5b
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_TRUSTED_RECEIVE
value|0x5c
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_TRUSTED_RECEIVE_DMA
value|0x5d
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_TRUSTED_SEND
value|0x5e
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_TRUSTED_SEND_DMA
value|0x5f
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  ATA Trusted Receive Fields
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ATA_TR_RETURN_SECURITY_PROTOCOL_INFORMATION
value|0x00
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_TR_SECURITY_PROTOCOL_JEDEC_RESERVED
value|0xec
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_TR_SECURITY_PROTOCOL_SDCARD_RESERVED
value|0xed
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_TR_SECURITY_PROTOCOL_IEEE1667_RESERVED
value|0xee
end_define

begin_comment
comment|///< defined in ACS-3
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Equates used for Acoustic Flags
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ATA_ACOUSTIC_LEVEL_BYPASS
value|0xff
end_define

begin_comment
comment|///< defined from ATA-6
end_comment

begin_define
define|#
directive|define
name|ATA_ACOUSTIC_LEVEL_MAXIMUM_PERFORMANCE
value|0xfe
end_define

begin_comment
comment|///< defined from ATA-6
end_comment

begin_define
define|#
directive|define
name|ATA_ACOUSTIC_LEVEL_QUIET
value|0x80
end_define

begin_comment
comment|///< defined from ATA-6
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Equates used for DiPM Support
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_DIPM_SUB
value|0x03
end_define

begin_comment
comment|// defined in ACS-3 : Count value in SetFeature identification : 03h  Device-initiated interface power state transitions
end_comment

begin_define
define|#
directive|define
name|ATA_DIPM_ENABLE
value|0x10
end_define

begin_comment
comment|// defined in ACS-3
end_comment

begin_define
define|#
directive|define
name|ATA_DIPM_DISABLE
value|0x90
end_define

begin_comment
comment|// defined in ACS-3
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Equates used for DevSleep Support
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_DEVSLEEP_SUB
value|0x09
end_define

begin_comment
comment|// defined in SATA 3.2 Gold Spec :  Count value in SetFeature identification : 09h  Device Sleep
end_comment

begin_define
define|#
directive|define
name|ATA_DEVSLEEP_ENABLE
value|0x10
end_define

begin_comment
comment|// defined in SATA 3.2 Gold Spec
end_comment

begin_define
define|#
directive|define
name|ATA_DEVSLEEP_DISABLE
value|0x90
end_define

begin_comment
comment|// defined in SATA 3.2 Gold Spec
end_comment

begin_define
define|#
directive|define
name|ATA_DEVSLP_EXIT_TIMEOUT
value|20
end_define

begin_comment
comment|// MDAT - 20 ms
end_comment

begin_define
define|#
directive|define
name|ATA_DEVSLP_MINIMUM_DETECTION_TIME
value|10
end_define

begin_comment
comment|// DMDT - 10 us
end_comment

begin_define
define|#
directive|define
name|ATA_DEVSLP_MINIMUM_ASSERTION_TIME
value|10
end_define

begin_comment
comment|// DETO - 10 ms
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Set MAX Commands
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_SET_MAX_ADDRESS_EXT
value|0x37
end_define

begin_comment
comment|///< defined from ATA-6
end_comment

begin_define
define|#
directive|define
name|ATA_CMD_SET_MAX_ADDRESS
value|0xf9
end_define

begin_comment
comment|///< defined from ATA-6
end_comment

begin_define
define|#
directive|define
name|ATA_SET_MAX_SET_PASSWORD
value|0x01
end_define

begin_comment
comment|///< defined from ATA-6
end_comment

begin_define
define|#
directive|define
name|ATA_SET_MAX_LOCK
value|0x02
end_define

begin_comment
comment|///< defined from ATA-6
end_comment

begin_define
define|#
directive|define
name|ATA_SET_MAX_UNLOCK
value|0x03
end_define

begin_comment
comment|///< defined from ATA-6
end_comment

begin_define
define|#
directive|define
name|ATA_SET_MAX_FREEZE_LOCK
value|0x04
end_define

begin_comment
comment|///< defined from ATA-6
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Default content of device control register, disable INT,
end_comment

begin_comment
comment|/// Bit3 is set to 1 according ATA-1
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|ATA_DEFAULT_CTL
value|(0x0a)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Default context of Device/Head Register,
end_comment

begin_comment
comment|/// Bit7 and Bit5 are set to 1 for back-compatibilities.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|ATA_DEFAULT_CMD
value|(0xa0)
end_define

begin_define
define|#
directive|define
name|ATAPI_MAX_BYTE_COUNT
value|(0xfffe)
end_define

begin_define
define|#
directive|define
name|ATA_REQUEST_SENSE_ERROR
value|(0x70)
end_define

begin_comment
comment|///< defined in SFF-8070i
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Sense Key, Additional Sense Codes and Additional Sense Code Qualifier
end_comment

begin_comment
comment|// defined in MultiMedia Commands (MMC, MMC-2)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Sense Key
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ATA_SK_NO_SENSE
value|(0x0)
end_define

begin_define
define|#
directive|define
name|ATA_SK_RECOVERY_ERROR
value|(0x1)
end_define

begin_define
define|#
directive|define
name|ATA_SK_NOT_READY
value|(0x2)
end_define

begin_define
define|#
directive|define
name|ATA_SK_MEDIUM_ERROR
value|(0x3)
end_define

begin_define
define|#
directive|define
name|ATA_SK_HARDWARE_ERROR
value|(0x4)
end_define

begin_define
define|#
directive|define
name|ATA_SK_ILLEGAL_REQUEST
value|(0x5)
end_define

begin_define
define|#
directive|define
name|ATA_SK_UNIT_ATTENTION
value|(0x6)
end_define

begin_define
define|#
directive|define
name|ATA_SK_DATA_PROTECT
value|(0x7)
end_define

begin_define
define|#
directive|define
name|ATA_SK_BLANK_CHECK
value|(0x8)
end_define

begin_define
define|#
directive|define
name|ATA_SK_VENDOR_SPECIFIC
value|(0x9)
end_define

begin_define
define|#
directive|define
name|ATA_SK_RESERVED_A
value|(0xA)
end_define

begin_define
define|#
directive|define
name|ATA_SK_ABORT
value|(0xB)
end_define

begin_define
define|#
directive|define
name|ATA_SK_RESERVED_C
value|(0xC)
end_define

begin_define
define|#
directive|define
name|ATA_SK_OVERFLOW
value|(0xD)
end_define

begin_define
define|#
directive|define
name|ATA_SK_MISCOMPARE
value|(0xE)
end_define

begin_define
define|#
directive|define
name|ATA_SK_RESERVED_F
value|(0xF)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Additional Sense Codes
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ATA_ASC_NOT_READY
value|(0x04)
end_define

begin_define
define|#
directive|define
name|ATA_ASC_MEDIA_ERR1
value|(0x10)
end_define

begin_define
define|#
directive|define
name|ATA_ASC_MEDIA_ERR2
value|(0x11)
end_define

begin_define
define|#
directive|define
name|ATA_ASC_MEDIA_ERR3
value|(0x14)
end_define

begin_define
define|#
directive|define
name|ATA_ASC_MEDIA_ERR4
value|(0x30)
end_define

begin_define
define|#
directive|define
name|ATA_ASC_MEDIA_UPSIDE_DOWN
value|(0x06)
end_define

begin_define
define|#
directive|define
name|ATA_ASC_INVALID_CMD
value|(0x20)
end_define

begin_define
define|#
directive|define
name|ATA_ASC_LBA_OUT_OF_RANGE
value|(0x21)
end_define

begin_define
define|#
directive|define
name|ATA_ASC_INVALID_FIELD
value|(0x24)
end_define

begin_define
define|#
directive|define
name|ATA_ASC_WRITE_PROTECTED
value|(0x27)
end_define

begin_define
define|#
directive|define
name|ATA_ASC_MEDIA_CHANGE
value|(0x28)
end_define

begin_define
define|#
directive|define
name|ATA_ASC_RESET
value|(0x29)
end_define

begin_comment
comment|///< Power On Reset or Bus Reset occurred.
end_comment

begin_define
define|#
directive|define
name|ATA_ASC_ILLEGAL_FIELD
value|(0x26)
end_define

begin_define
define|#
directive|define
name|ATA_ASC_NO_MEDIA
value|(0x3A)
end_define

begin_define
define|#
directive|define
name|ATA_ASC_ILLEGAL_MODE_FOR_THIS_TRACK
value|(0x64)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Additional Sense Code Qualifier
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ATA_ASCQ_IN_PROGRESS
value|(0x01)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Error Register
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ATA_ERRREG_BBK
value|BIT7
end_define

begin_comment
comment|///< Bad block detected      defined from ATA-1, obsoleted from ATA-2
end_comment

begin_define
define|#
directive|define
name|ATA_ERRREG_UNC
value|BIT6
end_define

begin_comment
comment|///< Uncorrectable Data      defined from ATA-1, obsoleted from ATA-4
end_comment

begin_define
define|#
directive|define
name|ATA_ERRREG_MC
value|BIT5
end_define

begin_comment
comment|///< Media Change            defined from ATA-1, obsoleted from ATA-4
end_comment

begin_define
define|#
directive|define
name|ATA_ERRREG_IDNF
value|BIT4
end_define

begin_comment
comment|///< ID Not Found            defined from ATA-1, obsoleted from ATA-4
end_comment

begin_define
define|#
directive|define
name|ATA_ERRREG_MCR
value|BIT3
end_define

begin_comment
comment|///< Media Change Requested  defined from ATA-1, obsoleted from ATA-4
end_comment

begin_define
define|#
directive|define
name|ATA_ERRREG_ABRT
value|BIT2
end_define

begin_comment
comment|///< Aborted Command         defined from ATA-1
end_comment

begin_define
define|#
directive|define
name|ATA_ERRREG_TK0NF
value|BIT1
end_define

begin_comment
comment|///< Track 0 Not Found       defined from ATA-1, obsoleted from ATA-4
end_comment

begin_define
define|#
directive|define
name|ATA_ERRREG_AMNF
value|BIT0
end_define

begin_comment
comment|///< Address Mark Not Found  defined from ATA-1, obsoleted from ATA-4
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Status Register
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ATA_STSREG_BSY
value|BIT7
end_define

begin_comment
comment|///< Controller Busy         defined from ATA-1
end_comment

begin_define
define|#
directive|define
name|ATA_STSREG_DRDY
value|BIT6
end_define

begin_comment
comment|///< Drive Ready             defined from ATA-1
end_comment

begin_define
define|#
directive|define
name|ATA_STSREG_DWF
value|BIT5
end_define

begin_comment
comment|///< Drive Write Fault       defined from ATA-1, obsoleted from ATA-4
end_comment

begin_define
define|#
directive|define
name|ATA_STSREG_DF
value|BIT5
end_define

begin_comment
comment|///< Drive Fault             defined from ATA-6
end_comment

begin_define
define|#
directive|define
name|ATA_STSREG_DSC
value|BIT4
end_define

begin_comment
comment|///< Disk Seek Complete      defined from ATA-1, obsoleted from ATA-4
end_comment

begin_define
define|#
directive|define
name|ATA_STSREG_DRQ
value|BIT3
end_define

begin_comment
comment|///< Data Request            defined from ATA-1
end_comment

begin_define
define|#
directive|define
name|ATA_STSREG_CORR
value|BIT2
end_define

begin_comment
comment|///< Corrected Data          defined from ATA-1, obsoleted from ATA-4
end_comment

begin_define
define|#
directive|define
name|ATA_STSREG_IDX
value|BIT1
end_define

begin_comment
comment|///< Index                   defined from ATA-1, obsoleted from ATA-4
end_comment

begin_define
define|#
directive|define
name|ATA_STSREG_ERR
value|BIT0
end_define

begin_comment
comment|///< Error                   defined from ATA-1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Device Control Register
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ATA_CTLREG_SRST
value|BIT2
end_define

begin_comment
comment|///< Software Reset.
end_comment

begin_define
define|#
directive|define
name|ATA_CTLREG_IEN_L
value|BIT1
end_define

begin_comment
comment|///< Interrupt Enable #.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

