begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * IEEE Std 802.1X-2010 definitions  * Copyright (c) 2013-2014, Qualcomm Atheros, Inc.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IEEE802_1X_DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|IEEE802_1X_DEFS_H
end_define

begin_define
define|#
directive|define
name|CS_ID_LEN
value|8
end_define

begin_define
define|#
directive|define
name|CS_ID_GCM_AES_128
value|{0x00, 0x80, 0x02, 0x00, 0x01, 0x00, 0x00, 0x01}
end_define

begin_define
define|#
directive|define
name|CS_NAME_GCM_AES_128
value|"GCM-AES-128"
end_define

begin_enum
enum|enum
name|macsec_policy
block|{
comment|/** 	 * Should secure sessions. 	 * This accepts key server's advice to determine whether to secure the 	 * session or not. 	 */
name|SHOULD_SECURE
block|,
comment|/** 	 * Disabled MACsec - do not secure sessions. 	 */
name|DO_NOT_SECURE
block|, }
enum|;
end_enum

begin_comment
comment|/* IEEE Std 802.1X-2010 - Table 11-6 - MACsec Capability */
end_comment

begin_enum
enum|enum
name|macsec_cap
block|{
comment|/** 	 * MACsec is not implemented 	 */
name|MACSEC_CAP_NOT_IMPLEMENTED
block|,
comment|/** 	 * 'Integrity without confidentiality' 	 */
name|MACSEC_CAP_INTEGRITY
block|,
comment|/** 	 * 'Integrity without confidentiality' and 	 * 'Integrity and confidentiality' with a confidentiality offset of 0 	 */
name|MACSEC_CAP_INTEG_AND_CONF
block|,
comment|/** 	 * 'Integrity without confidentiality' and 	 * 'Integrity and confidentiality' with a confidentiality offset of 0, 	 * 30, 50 	 */
name|MACSEC_CAP_INTEG_AND_CONF_0_30_50
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|validate_frames
block|{
name|Disabled
block|,
name|Checked
block|,
name|Strict
block|, }
enum|;
end_enum

begin_comment
comment|/* IEEE Std 802.1X-2010 - Table 11-6 - Confidentiality Offset */
end_comment

begin_enum
enum|enum
name|confidentiality_offset
block|{
name|CONFIDENTIALITY_NONE
init|=
literal|0
block|,
name|CONFIDENTIALITY_OFFSET_0
init|=
literal|1
block|,
name|CONFIDENTIALITY_OFFSET_30
init|=
literal|2
block|,
name|CONFIDENTIALITY_OFFSET_50
init|=
literal|3
block|, }
enum|;
end_enum

begin_comment
comment|/* IEEE Std 802.1X-2010 - Table 9-2 */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PRIO_INFRA_PORT
value|0x10
end_define

begin_define
define|#
directive|define
name|DEFAULT_PRIO_PRIMRAY_AP
value|0x30
end_define

begin_define
define|#
directive|define
name|DEFAULT_PRIO_SECONDARY_AP
value|0x50
end_define

begin_define
define|#
directive|define
name|DEFAULT_PRIO_GROUP_CA_MEMBER
value|0x70
end_define

begin_define
define|#
directive|define
name|DEFAULT_PRIO_NOT_KEY_SERVER
value|0xFF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IEEE802_1X_DEFS_H */
end_comment

end_unit

