begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Cedric GROSS<cg@cgross.info>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_IWN_DEVID_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_IWN_DEVID_H__
end_define

begin_define
define|#
directive|define
name|IWN_HW_REV_TYPE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|IWN_HW_REV_TYPE_MASK
value|0x1f
end_define

begin_comment
comment|/* Device revision */
end_comment

begin_define
define|#
directive|define
name|IWN_HW_REV_TYPE_4965
value|0
end_define

begin_define
define|#
directive|define
name|IWN_HW_REV_TYPE_5300
value|2
end_define

begin_define
define|#
directive|define
name|IWN_HW_REV_TYPE_5350
value|3
end_define

begin_define
define|#
directive|define
name|IWN_HW_REV_TYPE_5150
value|4
end_define

begin_define
define|#
directive|define
name|IWN_HW_REV_TYPE_5100
value|5
end_define

begin_define
define|#
directive|define
name|IWN_HW_REV_TYPE_1000
value|6
end_define

begin_define
define|#
directive|define
name|IWN_HW_REV_TYPE_6000
value|7
end_define

begin_define
define|#
directive|define
name|IWN_HW_REV_TYPE_6050
value|8
end_define

begin_define
define|#
directive|define
name|IWN_HW_REV_TYPE_6005
value|11
end_define

begin_define
define|#
directive|define
name|IWN_HW_REV_TYPE_2030
value|12
end_define

begin_define
define|#
directive|define
name|IWN_HW_REV_TYPE_2000
value|16
end_define

begin_define
define|#
directive|define
name|IWN_HW_REV_TYPE_105
value|17
end_define

begin_define
define|#
directive|define
name|IWN_HW_REV_TYPE_135
value|18
end_define

begin_comment
comment|/* ==========================================================================  * DEVICE ID BLOCK  * ========================================================================== */
end_comment

begin_comment
comment|/*  * --------------------------------------------------------------------------  * Device ID for 2x00 series  * --------------------------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|IWN_DID_2x00_1
value|0x0890
end_define

begin_define
define|#
directive|define
name|IWN_DID_2x00_2
value|0x0891
end_define

begin_comment
comment|/* SubDevice ID */
end_comment

begin_define
define|#
directive|define
name|IWN_SDID_2x00_1
value|0x4022
end_define

begin_define
define|#
directive|define
name|IWN_SDID_2x00_2
value|0x4222
end_define

begin_define
define|#
directive|define
name|IWN_SDID_2x00_3
value|0x4422
end_define

begin_define
define|#
directive|define
name|IWN_SDID_2x00_4
value|0x4822
end_define

begin_comment
comment|/*  * --------------------------------------------------------------------------  * Device ID for 2x30 series  * --------------------------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|IWN_DID_2x30_1
value|0x0887
end_define

begin_define
define|#
directive|define
name|IWN_DID_2x30_2
value|0x0888
end_define

begin_comment
comment|/* SubDevice ID */
end_comment

begin_define
define|#
directive|define
name|IWN_SDID_2x30_1
value|0x4062
end_define

begin_define
define|#
directive|define
name|IWN_SDID_2x30_2
value|0x4262
end_define

begin_define
define|#
directive|define
name|IWN_SDID_2x30_3
value|0x4462
end_define

begin_define
define|#
directive|define
name|IWN_SDID_2x30_4
value|0x4066
end_define

begin_define
define|#
directive|define
name|IWN_SDID_2x30_5
value|0x4266
end_define

begin_define
define|#
directive|define
name|IWN_SDID_2x30_6
value|0x4466
end_define

begin_comment
comment|/*  * --------------------------------------------------------------------------  * Device ID for 1000 series  * --------------------------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|IWN_DID_1000_1
value|0x0083
end_define

begin_define
define|#
directive|define
name|IWN_DID_1000_2
value|0x0084
end_define

begin_comment
comment|/* SubDevice ID */
end_comment

begin_define
define|#
directive|define
name|IWN_SDID_1000_1
value|0x1205
end_define

begin_define
define|#
directive|define
name|IWN_SDID_1000_2
value|0x1305
end_define

begin_define
define|#
directive|define
name|IWN_SDID_1000_3
value|0x1225
end_define

begin_define
define|#
directive|define
name|IWN_SDID_1000_4
value|0x1325
end_define

begin_define
define|#
directive|define
name|IWN_SDID_1000_5
value|0x1215
end_define

begin_define
define|#
directive|define
name|IWN_SDID_1000_6
value|0x1315
end_define

begin_define
define|#
directive|define
name|IWN_SDID_1000_7
value|0x1206
end_define

begin_define
define|#
directive|define
name|IWN_SDID_1000_8
value|0x1306
end_define

begin_define
define|#
directive|define
name|IWN_SDID_1000_9
value|0x1226
end_define

begin_define
define|#
directive|define
name|IWN_SDID_1000_10
value|0x1326
end_define

begin_define
define|#
directive|define
name|IWN_SDID_1000_11
value|0x1216
end_define

begin_define
define|#
directive|define
name|IWN_SDID_1000_12
value|0x1316
end_define

begin_comment
comment|/*  * --------------------------------------------------------------------------  * Device ID for 6x00 series  * --------------------------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|IWN_DID_6x00_1
value|0x422B
end_define

begin_define
define|#
directive|define
name|IWN_DID_6x00_2
value|0x422C
end_define

begin_define
define|#
directive|define
name|IWN_DID_6x00_3
value|0x4238
end_define

begin_define
define|#
directive|define
name|IWN_DID_6x00_4
value|0x4239
end_define

begin_comment
comment|/* SubDevice ID */
end_comment

begin_define
define|#
directive|define
name|IWN_SDID_6x00_1
value|0x1101
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6x00_2
value|0x1121
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6x00_3
value|0x1301
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6x00_4
value|0x1306
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6x00_5
value|0x1307
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6x00_6
value|0x1321
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6x00_7
value|0x1326
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6x00_8
value|0x1111
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6x00_9
value|0x1311
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6x00_10
value|0x1316
end_define

begin_comment
comment|/*  * --------------------------------------------------------------------------  * Device ID for 6x05 series  * --------------------------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|IWN_DID_6x05_1
value|0x0082
end_define

begin_define
define|#
directive|define
name|IWN_DID_6x05_2
value|0x0085
end_define

begin_comment
comment|/* SubDevice ID */
end_comment

begin_define
define|#
directive|define
name|IWN_SDID_6x05_1
value|0x1301
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6x05_2
value|0x1306
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6x05_3
value|0x1307
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6x05_4
value|0x1321
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6x05_5
value|0x1326
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6x05_6
value|0x1311
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6x05_7
value|0x1316
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6x05_8
value|0xC020
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6x05_9
value|0xC220
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6x05_10
value|0x4820
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6x05_11
value|0x1304
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6x05_12
value|0x1305
end_define

begin_comment
comment|/*  * --------------------------------------------------------------------------  * Device ID for 6050 WiFi/WiMax Series  * --------------------------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|IWN_DID_6050_1
value|0x0087
end_define

begin_define
define|#
directive|define
name|IWN_DID_6050_2
value|0x0089
end_define

begin_comment
comment|/* SubDevice ID */
end_comment

begin_define
define|#
directive|define
name|IWN_SDID_6050_1
value|0x1301
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6050_2
value|0x1306
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6050_3
value|0x1321
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6050_4
value|0x1326
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6050_5
value|0x1311
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6050_6
value|0x1316
end_define

begin_comment
comment|/*  * --------------------------------------------------------------------------  * Device ID for 6150 Series  * --------------------------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|IWN_DID_6150_1
value|0x0885
end_define

begin_define
define|#
directive|define
name|IWN_DID_6150_2
value|0x0886
end_define

begin_comment
comment|/* SubDevice ID */
end_comment

begin_define
define|#
directive|define
name|IWN_SDID_6150_1
value|0x1305
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6150_2
value|0x1307
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6150_3
value|0x1325
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6150_4
value|0x1327
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6150_5
value|0x1315
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6150_6
value|0x1317
end_define

begin_comment
comment|/*  * --------------------------------------------------------------------------  * Device ID for 6035 Series  * --------------------------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|IWN_DID_6035_1
value|0x088E
end_define

begin_define
define|#
directive|define
name|IWN_DID_6035_2
value|0x088F
end_define

begin_comment
comment|/* SubDevice ID */
end_comment

begin_define
define|#
directive|define
name|IWN_SDID_6035_1
value|0x4060
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6035_2
value|0x4260
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6035_3
value|0x4460
end_define

begin_define
define|#
directive|define
name|IWN_SDID_6035_4
value|0x4860
end_define

begin_comment
comment|/*  * --------------------------------------------------------------------------  * Device ID for 1030 and 6030 Series  * --------------------------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|IWN_DID_x030_1
value|0x008A
end_define

begin_define
define|#
directive|define
name|IWN_DID_x030_2
value|0x008B
end_define

begin_define
define|#
directive|define
name|IWN_DID_x030_3
value|0x0090
end_define

begin_define
define|#
directive|define
name|IWN_DID_x030_4
value|0x0091
end_define

begin_comment
comment|/* SubDevice ID */
end_comment

begin_define
define|#
directive|define
name|IWN_SDID_x030_1
value|0x5305
end_define

begin_define
define|#
directive|define
name|IWN_SDID_x030_2
value|0x5307
end_define

begin_define
define|#
directive|define
name|IWN_SDID_x030_3
value|0x5325
end_define

begin_define
define|#
directive|define
name|IWN_SDID_x030_4
value|0x5327
end_define

begin_define
define|#
directive|define
name|IWN_SDID_x030_5
value|0x5315
end_define

begin_define
define|#
directive|define
name|IWN_SDID_x030_6
value|0x5317
end_define

begin_define
define|#
directive|define
name|IWN_SDID_x030_7
value|0x5211
end_define

begin_define
define|#
directive|define
name|IWN_SDID_x030_8
value|0x5215
end_define

begin_define
define|#
directive|define
name|IWN_SDID_x030_9
value|0x5216
end_define

begin_define
define|#
directive|define
name|IWN_SDID_x030_10
value|0x5201
end_define

begin_define
define|#
directive|define
name|IWN_SDID_x030_11
value|0x5205
end_define

begin_define
define|#
directive|define
name|IWN_SDID_x030_12
value|0x5206
end_define

begin_define
define|#
directive|define
name|IWN_SDID_x030_13
value|0x5207
end_define

begin_define
define|#
directive|define
name|IWN_SDID_x030_14
value|0x5221
end_define

begin_define
define|#
directive|define
name|IWN_SDID_x030_15
value|0x5225
end_define

begin_define
define|#
directive|define
name|IWN_SDID_x030_16
value|0x5226
end_define

begin_comment
comment|/*  * --------------------------------------------------------------------------  * Device ID for 130 Series  * --------------------------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|IWN_DID_130_1
value|0x0896
end_define

begin_define
define|#
directive|define
name|IWN_DID_130_2
value|0x0897
end_define

begin_comment
comment|/* SubDevice ID */
end_comment

begin_define
define|#
directive|define
name|IWN_SDID_130_1
value|0x5005
end_define

begin_define
define|#
directive|define
name|IWN_SDID_130_2
value|0x5007
end_define

begin_define
define|#
directive|define
name|IWN_SDID_130_3
value|0x5015
end_define

begin_define
define|#
directive|define
name|IWN_SDID_130_4
value|0x5017
end_define

begin_define
define|#
directive|define
name|IWN_SDID_130_5
value|0x5025
end_define

begin_define
define|#
directive|define
name|IWN_SDID_130_6
value|0x5027
end_define

begin_comment
comment|/*  * --------------------------------------------------------------------------  * Device ID for 100 Series  * --------------------------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|IWN_DID_100_1
value|0x08AE
end_define

begin_define
define|#
directive|define
name|IWN_DID_100_2
value|0x08AF
end_define

begin_comment
comment|/* SubDevice ID */
end_comment

begin_define
define|#
directive|define
name|IWN_SDID_100_1
value|0x1005
end_define

begin_define
define|#
directive|define
name|IWN_SDID_100_2
value|0x1007
end_define

begin_define
define|#
directive|define
name|IWN_SDID_100_3
value|0x1015
end_define

begin_define
define|#
directive|define
name|IWN_SDID_100_4
value|0x1017
end_define

begin_define
define|#
directive|define
name|IWN_SDID_100_5
value|0x1025
end_define

begin_define
define|#
directive|define
name|IWN_SDID_100_6
value|0x1027
end_define

begin_comment
comment|/*  * --------------------------------------------------------------------------  * Device ID for 105 Series  * --------------------------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|IWN_DID_105_1
value|0x0894
end_define

begin_define
define|#
directive|define
name|IWN_DID_105_2
value|0x0895
end_define

begin_comment
comment|/* SubDevice ID */
end_comment

begin_define
define|#
directive|define
name|IWN_SDID_105_1
value|0x0022
end_define

begin_define
define|#
directive|define
name|IWN_SDID_105_2
value|0x0222
end_define

begin_define
define|#
directive|define
name|IWN_SDID_105_3
value|0x0422
end_define

begin_define
define|#
directive|define
name|IWN_SDID_105_4
value|0x0822
end_define

begin_comment
comment|/*  * --------------------------------------------------------------------------  * Device ID for 135 Series  * --------------------------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|IWN_DID_135_1
value|0x0892
end_define

begin_define
define|#
directive|define
name|IWN_DID_135_2
value|0x0893
end_define

begin_comment
comment|/* SubDevice ID */
end_comment

begin_define
define|#
directive|define
name|IWN_SDID_135_1
value|0x0062
end_define

begin_define
define|#
directive|define
name|IWN_SDID_135_2
value|0x0262
end_define

begin_define
define|#
directive|define
name|IWN_SDID_135_3
value|0x0462
end_define

begin_comment
comment|/*  * --------------------------------------------------------------------------  * Device ID for 5x00 Series  * --------------------------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|IWN_DID_5x00_1
value|0x4232
end_define

begin_define
define|#
directive|define
name|IWN_DID_5x00_2
value|0x4237
end_define

begin_define
define|#
directive|define
name|IWN_DID_5x00_3
value|0x4235
end_define

begin_define
define|#
directive|define
name|IWN_DID_5x00_4
value|0x4236
end_define

begin_comment
comment|/* SubDevice ID */
end_comment

begin_define
define|#
directive|define
name|IWN_SDID_5x00_1
value|0x1201
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_2
value|0x1301
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_3
value|0x1204
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_4
value|0x1304
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_5
value|0x1205
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_6
value|0x1305
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_7
value|0x1206
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_8
value|0x1306
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_9
value|0x1221
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_10
value|0x1321
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_11
value|0x1224
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_12
value|0x1324
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_13
value|0x1225
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_14
value|0x1325
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_15
value|0x1226
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_16
value|0x1326
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_17
value|0x1211
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_18
value|0x1311
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_19
value|0x1214
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_20
value|0x1314
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_21
value|0x1215
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_22
value|0x1315
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_23
value|0x1216
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_24
value|0x1316
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_25
value|0x1021
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_26
value|0x1121
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_27
value|0x1024
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_28
value|0x1124
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_29
value|0x1001
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_30
value|0x1101
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_31
value|0x1004
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_32
value|0x1104
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_33
value|0x1011
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_34
value|0x1111
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_35
value|0x1014
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x00_36
value|0x1114
end_define

begin_comment
comment|/*  * --------------------------------------------------------------------------  * Device ID for 5x50 Series  * --------------------------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|IWN_DID_5x50_1
value|0x423A
end_define

begin_define
define|#
directive|define
name|IWN_DID_5x50_2
value|0x423B
end_define

begin_define
define|#
directive|define
name|IWN_DID_5x50_3
value|0x423C
end_define

begin_define
define|#
directive|define
name|IWN_DID_5x50_4
value|0x423D
end_define

begin_comment
comment|/* SubDevice ID */
end_comment

begin_define
define|#
directive|define
name|IWN_SDID_5x50_1
value|0x1001
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x50_2
value|0x1021
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x50_3
value|0x1011
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x50_4
value|0x1201
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x50_5
value|0x1301
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x50_6
value|0x1206
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x50_7
value|0x1306
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x50_8
value|0x1221
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x50_9
value|0x1321
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x50_10
value|0x1211
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x50_11
value|0x1311
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x50_12
value|0x1216
end_define

begin_define
define|#
directive|define
name|IWN_SDID_5x50_13
value|0x1316
end_define

begin_comment
comment|/*  * --------------------------------------------------------------------------  * Device ID for 4965 Series  * --------------------------------------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|IWN_DID_4965_1
value|0x4229
end_define

begin_define
define|#
directive|define
name|IWN_DID_4965_2
value|0x422d
end_define

begin_define
define|#
directive|define
name|IWN_DID_4965_3
value|0x4230
end_define

begin_define
define|#
directive|define
name|IWN_DID_4965_4
value|0x4233
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __IF_IWN_DEVID_H__ */
end_comment

end_unit

