begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   The standard set of Extended SAL service classes.    Copyright (c) 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EXTENDED_SAL_SERVICE_CLASSES_H_
end_ifndef

begin_define
define|#
directive|define
name|_EXTENDED_SAL_SERVICE_CLASSES_H_
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extended SAL Base I/O Services Class
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
name|EFI_EXTENDED_SAL_BASE_IO_SERVICES_PROTOCOL_GUID_LO
value|0x451531e15aea42b5
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_BASE_IO_SERVICES_PROTOCOL_GUID_HI
value|0xa6657525d5b831bc
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_BASE_IO_SERVICES_PROTOCOL_GUID
define|\
value|{ 0x5aea42b5, 0x31e1, 0x4515, {0xbc, 0x31, 0xb8, 0xd5, 0x25, 0x75, 0x65, 0xa6 } }
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|IoReadFunctionId
block|,
name|IoWriteFunctionId
block|,
name|MemReadFunctionId
block|,
name|MemWriteFunctionId
block|}
name|EFI_EXTENDED_SAL_BASE_IO_SERVICES_FUNC_ID
typedef|;
end_typedef

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extended SAL Stall Services Class
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
name|EFI_EXTENDED_SAL_STALL_SERVICES_PROTOCOL_GUID_LO
value|0x4d8cac2753a58d06
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_STALL_SERVICES_PROTOCOL_GUID_HI
value|0x704165808af0e9b5
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_STALL_SERVICES_PROTOCOL_GUID
define|\
value|{ 0x53a58d06, 0xac27, 0x4d8c, {0xb5, 0xe9, 0xf0, 0x8a, 0x80, 0x65, 0x41, 0x70 } }
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|StallFunctionId
block|}
name|EFI_EXTENDED_SAL_STALL_FUNC_ID
typedef|;
end_typedef

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extended SAL Real Time Clock Services Class
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
name|EFI_EXTENDED_SAL_RTC_SERVICES_PROTOCOL_GUID_LO
value|0x4d02efdb7e97a470
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_RTC_SERVICES_PROTOCOL_GUID_HI
value|0x96a27bd29061ce8f
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_RTC_SERVICES_PROTOCOL_GUID
define|\
value|{ 0x7e97a470, 0xefdb, 0x4d02, {0x8f, 0xce, 0x61, 0x90, 0xd2, 0x7b, 0xa2, 0x96 } }
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|GetTimeFunctionId
block|,
name|SetTimeFunctionId
block|,
name|GetWakeupTimeFunctionId
block|,
name|SetWakeupTimeFunctionId
block|,
name|GetRtcFreqFunctionId
block|,
name|InitializeThresholdFunctionId
block|,
name|BumpThresholdCountFunctionId
block|,
name|GetThresholdCountFunctionId
block|}
name|EFI_EXTENDED_SAL_RTC_SERVICES_FUNC_ID
typedef|;
end_typedef

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extended SAL Variable Services Class
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
name|EFI_EXTENDED_SAL_VARIABLE_SERVICES_PROTOCOL_GUID_LO
value|0x4370c6414ecb6c53
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_VARIABLE_SERVICES_PROTOCOL_GUID_HI
value|0x78836e490e3bb28c
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_VARIABLE_SERVICES_PROTOCOL_GUID
define|\
value|{ 0x4ecb6c53, 0xc641, 0x4370, {0x8c, 0xb2, 0x3b, 0x0e, 0x49, 0x6e, 0x83, 0x78 } }
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|EsalGetVariableFunctionId
block|,
name|EsalGetNextVariableNameFunctionId
block|,
name|EsalSetVariableFunctionId
block|,
name|EsalQueryVariableInfoFunctionId
block|}
name|EFI_EXTENDED_SAL_VARIABLE_SERVICES_FUNC_ID
typedef|;
end_typedef

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extended SAL Monotonic Counter Services Class
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
name|EFI_EXTENDED_SAL_MTC_SERVICES_PROTOCOL_GUID_LO
value|0x408b75e8899afd18
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_MTC_SERVICES_PROTOCOL_GUID_HI
value|0x54f4cd7e2e6e1aa4
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_MTC_SERVICES_PROTOCOL_GUID
define|\
value|{ 0x899afd18, 0x75e8, 0x408b, {0xa4, 0x1a, 0x6e, 0x2e, 0x7e, 0xcd, 0xf4, 0x54 } }
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|GetNextHighMonotonicCountFunctionId
block|}
name|EFI_EXTENDED_SAL_MTC_SERVICES_FUNC_ID
typedef|;
end_typedef

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extended SAL Reset Services Class
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
name|EFI_EXTENDED_SAL_RESET_SERVICES_PROTOCOL_GUID_LO
value|0x46f58ce17d019990
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_RESET_SERVICES_PROTOCOL_GUID_HI
value|0xa06a6798513c76a7
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_RESET_SERVICES_PROTOCOL_GUID
define|\
value|{ 0x7d019990, 0x8ce1, 0x46f5, {0xa7, 0x76, 0x3c, 0x51, 0x98, 0x67, 0x6a, 0xa0 } }
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|ResetSystemFunctionId
block|}
name|EFI_EXTENDED_SAL_RESET_SERVICES_FUNC_ID
typedef|;
end_typedef

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extended SAL Status Code Services Class
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
name|EFI_EXTENDED_SAL_STATUS_CODE_SERVICES_PROTOCOL_GUID_LO
value|0x420f55e9dbd91d
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_STATUS_CODE_SERVICES_PROTOCOL_GUID_HI
value|0x4fb437849f5e3996
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_STATUS_CODE_SERVICES_PROTOCOL_GUID
define|\
value|{ 0xdbd91d, 0x55e9, 0x420f, {0x96, 0x39, 0x5e, 0x9f, 0x84, 0x37, 0xb4, 0x4f } }
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|ReportStatusCodeServiceFunctionId
block|}
name|EFI_EXTENDED_SAL_STATUS_CODE_SERVICES_FUNC_ID
typedef|;
end_typedef

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extended SAL Firmware Volume Block Services Class
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
name|EFI_EXTENDED_SAL_FV_BLOCK_SERVICES_PROTOCOL_GUID_LO
value|0x4f1dbcbba2271df1
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_FV_BLOCK_SERVICES_PROTOCOL_GUID_HI
value|0x1a072f17bc06a998
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_FV_BLOCK_SERVICES_PROTOCOL_GUID
define|\
value|{ 0xa2271df1, 0xbcbb, 0x4f1d, {0x98, 0xa9, 0x06, 0xbc, 0x17, 0x2f, 0x07, 0x1a } }
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|ReadFunctionId
block|,
name|WriteFunctionId
block|,
name|EraseBlockFunctionId
block|,
name|GetVolumeAttributesFunctionId
block|,
name|SetVolumeAttributesFunctionId
block|,
name|GetPhysicalAddressFunctionId
block|,
name|GetBlockSizeFunctionId
block|, }
name|EFI_EXTENDED_SAL_FV_BLOCK_SERVICES_FUNC_ID
typedef|;
end_typedef

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extended SAL MP Services Class
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
name|EFI_EXTENDED_SAL_MP_SERVICES_PROTOCOL_GUID_LO
value|0x4dc0cf18697d81a2
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_MP_SERVICES_PROTOCOL_GUID_HI
value|0x3f8a613b11060d9e
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_MP_SERVICES_PROTOCOL_GUID
define|\
value|{ 0x697d81a2, 0xcf18, 0x4dc0, {0x9e, 0x0d, 0x06, 0x11, 0x3b, 0x61, 0x8a, 0x3f } }
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|AddCpuDataFunctionId
block|,
name|RemoveCpuDataFunctionId
block|,
name|ModifyCpuDataFunctionId
block|,
name|GetCpuDataByIDFunctionId
block|,
name|GetCpuDataByIndexFunctionId
block|,
name|SendIpiFunctionId
block|,
name|CurrentProcInfoFunctionId
block|,
name|NumProcessorsFunctionId
block|,
name|SetMinStateFunctionId
block|,
name|GetMinStateFunctionId
block|}
name|EFI_EXTENDED_SAL_MP_SERVICES_FUNC_ID
typedef|;
end_typedef

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extended SAL PAL Services Class
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
name|EFI_EXTENDED_SAL_PAL_SERVICES_PROTOCOL_GUID_LO
value|0x438d0fc2e1cd9d21
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_PAL_SERVICES_PROTOCOL_GUID_HI
value|0x571e966de6040397
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_PAL_SERVICES_PROTOCOL_GUID
define|\
value|{ 0xe1cd9d21, 0x0fc2, 0x438d, {0x97, 0x03, 0x04, 0xe6, 0x6d, 0x96, 0x1e, 0x57 } }
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|PalProcFunctionId
block|,
name|SetNewPalEntryFunctionId
block|,
name|GetNewPalEntryFunctionId
block|,
name|EsalUpdatePalFunctionId
block|}
name|EFI_EXTENDED_SAL_PAL_SERVICES_FUNC_ID
typedef|;
end_typedef

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extended SAL Base Services Class
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
name|EFI_EXTENDED_SAL_BASE_SERVICES_PROTOCOL_GUID_LO
value|0x41c30fe0d9e9fa06
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_BASE_SERVICES_PROTOCOL_GUID_HI
value|0xf894335a4283fb96
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_BASE_SERVICES_PROTOCOL_GUID
define|\
value|{ 0xd9e9fa06, 0x0fe0, 0x41c3, {0x96, 0xfb, 0x83, 0x42, 0x5a, 0x33, 0x94, 0xf8 } }
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|SalSetVectorsFunctionId
block|,
name|SalMcRendezFunctionId
block|,
name|SalMcSetParamsFunctionId
block|,
name|EsalGetVectorsFunctionId
block|,
name|EsalMcGetParamsFunctionId
block|,
name|EsalMcGetMcParamsFunctionId
block|,
name|EsalGetMcCheckinFlagsFunctionId
block|,
name|EsalGetPlatformBaseFreqFunctionId
block|,
name|EsalPhysicalIdInfoFunctionId
block|,
name|EsalRegisterPhysicalAddrFunctionId
block|}
name|EFI_EXTENDED_SAL_BASE_SERVICES_FUNC_ID
typedef|;
end_typedef

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extended SAL MCA Services Class
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
name|EFI_EXTENDED_SAL_MCA_SERVICES_PROTOCOL_GUID_LO
value|0x42b16cc72a591128
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_MCA_SERVICES_PROTOCOL_GUID_HI
value|0xbb2d683b9358f08a
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_MCA_SERVICES_PROTOCOL_GUID
define|\
value|{ 0x2a591128, 0x6cc7, 0x42b1, {0x8a, 0xf0, 0x58, 0x93, 0x3b, 0x68, 0x2d, 0xbb } }
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|McaGetStateInfoFunctionId
block|,
name|McaRegisterCpuFunctionId
block|}
name|EFI_EXTENDED_SAL_MCA_SERVICES_FUNC_ID
typedef|;
end_typedef

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extended SAL PCI Services Class
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
name|EFI_EXTENDED_SAL_PCI_SERVICES_PROTOCOL_GUID_LO
value|0x4905ad66a46b1a31
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_PCI_SERVICES_PROTOCOL_GUID_HI
value|0x6330dc59462bf692
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_PCI_SERVICES_PROTOCOL_GUID
define|\
value|{ 0xa46b1a31, 0xad66, 0x4905, {0x92, 0xf6, 0x2b, 0x46, 0x59, 0xdc, 0x30, 0x63 } }
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|SalPciConfigReadFunctionId
block|,
name|SalPciConfigWriteFunctionId
block|}
name|EFI_EXTENDED_SAL_PCI_SERVICES_FUNC_ID
typedef|;
end_typedef

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extended SAL Cache Services Class
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
name|EFI_EXTENDED_SAL_CACHE_SERVICES_PROTOCOL_GUID_LO
value|0x4ba52743edc9494
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_CACHE_SERVICES_PROTOCOL_GUID_HI
value|0x88f11352ef0a1888
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_CACHE_SERVICES_PROTOCOL_GUID
define|\
value|{ 0xedc9494, 0x2743, 0x4ba5, { 0x88, 0x18, 0x0a, 0xef, 0x52, 0x13, 0xf1, 0x88 } }
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|SalCacheInitFunctionId
block|,
name|SalCacheFlushFunctionId
block|}
name|EFI_EXTENDED_SAL_CACHE_SERVICES_FUNC_ID
typedef|;
end_typedef

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extended SAL MCA Log Services Class
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
name|EFI_EXTENDED_SAL_MCA_LOG_SERVICES_PROTOCOL_GUID_LO
value|0x4c0338a3cb3fd86e
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_MCA_LOG_SERVICES_PROTOCOL_GUID_HI
value|0x7aaba2a3cf905c9a
end_define

begin_define
define|#
directive|define
name|EFI_EXTENDED_SAL_MCA_LOG_SERVICES_PROTOCOL_GUID
define|\
value|{ 0xcb3fd86e, 0x38a3, 0x4c03, {0x9a, 0x5c, 0x90, 0xcf, 0xa3, 0xa2, 0xab, 0x7a } }
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|SalGetStateInfoFunctionId
block|,
name|SalGetStateInfoSizeFunctionId
block|,
name|SalClearStateInfoFunctionId
block|,
name|EsalGetStateBufferFunctionId
block|,
name|EsalSaveStateBufferFunctionId
block|}
name|EFI_EXTENDED_SAL_MCA_LOG_SERVICES_FUNC_ID
typedef|;
end_typedef

begin_comment
comment|///@}
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

