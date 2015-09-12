begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* ** * Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE ** * $FreeBSD$ * ********************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DMDEFS_H__
end_ifndef

begin_define
define|#
directive|define
name|__DMDEFS_H__
end_define

begin_include
include|#
directive|include
file|<dev/pms/RefTisa/tisa/sassata/common/ossa.h>
end_include

begin_define
define|#
directive|define
name|DIRECT_SMP
end_define

begin_comment
comment|//#undef DIRECT_SMP
end_comment

begin_comment
comment|/* the index for memory requirement, must be continious */
end_comment

begin_define
define|#
directive|define
name|DM_ROOT_MEM_INDEX
value|0
end_define

begin_comment
comment|/**< the index of dm root memory */
end_comment

begin_define
define|#
directive|define
name|DM_PORT_MEM_INDEX
value|1
end_define

begin_comment
comment|/**< the index of port context memory */
end_comment

begin_define
define|#
directive|define
name|DM_DEVICE_MEM_INDEX
value|2
end_define

begin_comment
comment|/**< the index of Device descriptors memory */
end_comment

begin_define
define|#
directive|define
name|DM_EXPANDER_MEM_INDEX
value|3
end_define

begin_comment
comment|/**< the index of Expander device descriptors memory */
end_comment

begin_define
define|#
directive|define
name|DM_SMP_MEM_INDEX
value|4
end_define

begin_comment
comment|/**< the index of SMP command descriptors memory */
end_comment

begin_define
define|#
directive|define
name|DM_INDIRECT_SMP_MEM_INDEX
value|5
end_define

begin_comment
comment|/**< the index of Indirect SMP command descriptors memory */
end_comment

begin_define
define|#
directive|define
name|DM_MAX_NUM_PHYS
value|16
end_define

begin_define
define|#
directive|define
name|DM_MAX_EXPANDER_PHYS
value|256
end_define

begin_define
define|#
directive|define
name|DM_MAX_DEV
value|2048
end_define

begin_define
define|#
directive|define
name|DM_MAX_EXPANDER_DEV
value|32
end_define

begin_define
define|#
directive|define
name|DM_MAX_PORT_CONTEXT
value|16
end_define

begin_define
define|#
directive|define
name|DM_MAX_SMP
value|32
end_define

begin_define
define|#
directive|define
name|DM_MAX_INDIRECT_SMP
value|DM_MAX_SMP
end_define

begin_define
define|#
directive|define
name|DM_USECS_PER_TICK
value|1000000
end_define

begin_comment
comment|/**< defines the heart beat of the LL layer 10ms */
end_comment

begin_comment
comment|/* *  FIS type  */
end_comment

begin_define
define|#
directive|define
name|PIO_SETUP_DEV_TO_HOST_FIS
value|0x5F
end_define

begin_define
define|#
directive|define
name|REG_DEV_TO_HOST_FIS
value|0x34
end_define

begin_define
define|#
directive|define
name|SET_DEV_BITS_FIS
value|0xA1
end_define

begin_define
define|#
directive|define
name|DEFAULT_KEY_BUFFER_SIZE
value|64
end_define

begin_enum
enum|enum
name|dm_locks_e
block|{
name|DM_PORT_LOCK
init|=
literal|0
block|,
name|DM_DEVICE_LOCK
block|,
name|DM_EXPANDER_LOCK
block|,
name|DM_TIMER_LOCK
block|,
name|DM_SMP_LOCK
block|,
name|DM_MAX_LOCKS
block|}
enum|;
end_enum

begin_comment
comment|/* default SMP timeout: 0xFFFF is the Maximum Allowed */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SMP_TIMEOUT
value|0xFFFF
end_define

begin_comment
comment|/* SMP direct payload size limit: IOMB direct payload size = 48 */
end_comment

begin_define
define|#
directive|define
name|SMP_DIRECT_PAYLOAD_LIMIT
value|44
end_define

begin_define
define|#
directive|define
name|SMP_INDIRECT_PAYLOAD
value|512
end_define

begin_comment
comment|/* SMP maximum payload size allowed by SAS spec withtout CRC 4 bytes */
end_comment

begin_define
define|#
directive|define
name|SMP_MAXIMUM_PAYLOAD
value|1024
end_define

begin_comment
comment|/*! \def MIN(a,b) * \brief MIN macro * * use to find MIN of two values */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*! \def MAX(a,b) * \brief MAX macro * * use to find MAX of two values */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAX
end_ifndef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (b) : (a))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|agNULL
end_ifndef

begin_define
define|#
directive|define
name|agNULL
value|((void *)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* for debugging print */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DM_DEBUG
argument_list|)
end_if

begin_comment
comment|/* * for debugging purposes.   */
end_comment

begin_decl_stmt
specifier|extern
name|bit32
name|gDMDebugLevel
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DM_DBG0
parameter_list|(
name|format
parameter_list|)
value|tddmLogDebugString(gDMDebugLevel, 0, format)
end_define

begin_define
define|#
directive|define
name|DM_DBG1
parameter_list|(
name|format
parameter_list|)
value|tddmLogDebugString(gDMDebugLevel, 1, format)
end_define

begin_define
define|#
directive|define
name|DM_DBG2
parameter_list|(
name|format
parameter_list|)
value|tddmLogDebugString(gDMDebugLevel, 2, format)
end_define

begin_define
define|#
directive|define
name|DM_DBG3
parameter_list|(
name|format
parameter_list|)
value|tddmLogDebugString(gDMDebugLevel, 3, format)
end_define

begin_define
define|#
directive|define
name|DM_DBG4
parameter_list|(
name|format
parameter_list|)
value|tddmLogDebugString(gDMDebugLevel, 4, format)
end_define

begin_define
define|#
directive|define
name|DM_DBG5
parameter_list|(
name|format
parameter_list|)
value|tddmLogDebugString(gDMDebugLevel, 5, format)
end_define

begin_define
define|#
directive|define
name|DM_DBG6
parameter_list|(
name|format
parameter_list|)
value|tddmLogDebugString(gDMDebugLevel, 6, format)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DM_DBG0
parameter_list|(
name|format
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DM_DBG1
parameter_list|(
name|format
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DM_DBG2
parameter_list|(
name|format
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DM_DBG3
parameter_list|(
name|format
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DM_DBG4
parameter_list|(
name|format
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DM_DBG5
parameter_list|(
name|format
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DM_DBG6
parameter_list|(
name|format
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DM_DEBUG */
end_comment

begin_comment
comment|//#define DM_ASSERT OS_ASSERT
end_comment

begin_comment
comment|//#define tddmLogDebugString TIDEBUG_MSG
end_comment

begin_comment
comment|/* discovery related state */
end_comment

begin_define
define|#
directive|define
name|DM_DSTATE_NOT_STARTED
value|0
end_define

begin_define
define|#
directive|define
name|DM_DSTATE_STARTED
value|1
end_define

begin_define
define|#
directive|define
name|DM_DSTATE_COMPLETED
value|2
end_define

begin_define
define|#
directive|define
name|DM_DSTATE_COMPLETED_WITH_FAILURE
value|3
end_define

begin_comment
comment|/* SAS/SATA discovery status */
end_comment

begin_define
define|#
directive|define
name|DISCOVERY_NOT_START
value|0
end_define

begin_comment
comment|/**< status indicates discovery not started */
end_comment

begin_define
define|#
directive|define
name|DISCOVERY_UP_STREAM
value|1
end_define

begin_comment
comment|/**< status indicates discover upstream */
end_comment

begin_define
define|#
directive|define
name|DISCOVERY_DOWN_STREAM
value|2
end_define

begin_comment
comment|/**< status indicates discover downstream */
end_comment

begin_define
define|#
directive|define
name|DISCOVERY_CONFIG_ROUTING
value|3
end_define

begin_comment
comment|/**< status indicates discovery config routing table */
end_comment

begin_define
define|#
directive|define
name|DISCOVERY_SAS_DONE
value|4
end_define

begin_comment
comment|/**< status indicates discovery done */
end_comment

begin_define
define|#
directive|define
name|DISCOVERY_REPORT_PHY_SATA
value|5
end_define

begin_comment
comment|/**< status indicates discovery report phy sata */
end_comment

begin_comment
comment|/* SMP function */
end_comment

begin_define
define|#
directive|define
name|SMP_REPORT_GENERAL
value|0x00
end_define

begin_define
define|#
directive|define
name|SMP_REPORT_MANUFACTURE_INFORMATION
value|0x01
end_define

begin_define
define|#
directive|define
name|SMP_READ_GPIO_REGISTER
value|0x02
end_define

begin_define
define|#
directive|define
name|SMP_DISCOVER
value|0x10
end_define

begin_define
define|#
directive|define
name|SMP_REPORT_PHY_ERROR_LOG
value|0x11
end_define

begin_define
define|#
directive|define
name|SMP_REPORT_PHY_SATA
value|0x12
end_define

begin_define
define|#
directive|define
name|SMP_REPORT_ROUTING_INFORMATION
value|0x13
end_define

begin_define
define|#
directive|define
name|SMP_WRITE_GPIO_REGISTER
value|0x82
end_define

begin_define
define|#
directive|define
name|SMP_CONFIGURE_ROUTING_INFORMATION
value|0x90
end_define

begin_define
define|#
directive|define
name|SMP_PHY_CONTROL
value|0x91
end_define

begin_define
define|#
directive|define
name|SMP_PHY_TEST_FUNCTION
value|0x92
end_define

begin_define
define|#
directive|define
name|SMP_PMC_SPECIFIC
value|0xC0
end_define

begin_define
define|#
directive|define
name|SMP_DISCOVER_LIST
value|0x20
end_define

begin_comment
comment|/* SMP function results */
end_comment

begin_define
define|#
directive|define
name|SMP_FUNCTION_ACCEPTED
value|0x00
end_define

begin_define
define|#
directive|define
name|UNKNOWN_SMP_FUNCTION
value|0x01
end_define

begin_define
define|#
directive|define
name|SMP_FUNCTION_FAILED
value|0x02
end_define

begin_define
define|#
directive|define
name|INVALID_REQUEST_FRAME_LENGTH
value|0x03
end_define

begin_define
define|#
directive|define
name|INVALID_EXPANDER_CHANGE_COUNT
value|0x04
end_define

begin_define
define|#
directive|define
name|SMP_FN_BUSY
value|0x05
end_define

begin_define
define|#
directive|define
name|INCOMPLETE_DESCRIPTOR_LIST
value|0x06
end_define

begin_define
define|#
directive|define
name|PHY_DOES_NOT_EXIST
value|0x10
end_define

begin_define
define|#
directive|define
name|INDEX_DOES_NOT_EXIST
value|0x11
end_define

begin_define
define|#
directive|define
name|PHY_DOES_NOT_SUPPORT_SATA
value|0x12
end_define

begin_define
define|#
directive|define
name|UNKNOWN_PHY_OPERATION
value|0x13
end_define

begin_define
define|#
directive|define
name|UNKNOWN_PHY_TEST_FUNCTION
value|0x14
end_define

begin_define
define|#
directive|define
name|PHY_TEST_FUNCTION_IN_PROGRESS
value|0x15
end_define

begin_define
define|#
directive|define
name|PHY_VACANT
value|0x16
end_define

begin_define
define|#
directive|define
name|UNKNOWN_PHY_EVENT_SOURCE
value|0x17
end_define

begin_define
define|#
directive|define
name|UNKNOWN_DESCRIPTOT_TYPE
value|0x18
end_define

begin_define
define|#
directive|define
name|UNKNOWN_PHY_FILETER
value|0x19
end_define

begin_define
define|#
directive|define
name|AFFILIATION_VIOLATION
value|0x1A
end_define

begin_define
define|#
directive|define
name|SMP_ZONE_VIOLATION
value|0x20
end_define

begin_define
define|#
directive|define
name|NO_MANAGEMENT_ACCESS_RIGHTS
value|0x21
end_define

begin_define
define|#
directive|define
name|UNKNOWN_ENABLE_DISABLE_ZONING_VALUE
value|0x22
end_define

begin_define
define|#
directive|define
name|ZONE_LOCK_VIOLATION
value|0x23
end_define

begin_define
define|#
directive|define
name|NOT_ACTIVATED
value|0x24
end_define

begin_define
define|#
directive|define
name|ZONE_GROUP_OUT_OF_RANGE
value|0x25
end_define

begin_define
define|#
directive|define
name|NO_PHYSICAL_PRESENCE
value|0x26
end_define

begin_define
define|#
directive|define
name|SAVING_NOT_SUPPORTED
value|0x27
end_define

begin_define
define|#
directive|define
name|SOURCE_ZONE_GROUP_DOES_NOT_EXIST
value|0x28
end_define

begin_define
define|#
directive|define
name|DISABLED_PASSWORD_NOT_SUPPORTED
value|0x29
end_define

begin_comment
comment|/* SMP PHY CONTROL OPERATION */
end_comment

begin_define
define|#
directive|define
name|SMP_PHY_CONTROL_NOP
value|0x00
end_define

begin_define
define|#
directive|define
name|SMP_PHY_CONTROL_LINK_RESET
value|0x01
end_define

begin_define
define|#
directive|define
name|SMP_PHY_CONTROL_HARD_RESET
value|0x02
end_define

begin_define
define|#
directive|define
name|SMP_PHY_CONTROL_DISABLE
value|0x03
end_define

begin_define
define|#
directive|define
name|SMP_PHY_CONTROL_CLEAR_ERROR_LOG
value|0x05
end_define

begin_define
define|#
directive|define
name|SMP_PHY_CONTROL_CLEAR_AFFILIATION
value|0x06
end_define

begin_define
define|#
directive|define
name|SMP_PHY_CONTROL_XMIT_SATA_PS_SIGNAL
value|0x07
end_define

begin_define
define|#
directive|define
name|DM_VEN_DEV_SPC
value|0x80010000
end_define

begin_define
define|#
directive|define
name|DM_VEN_DEV_ADAPSPC
value|0x80810000
end_define

begin_define
define|#
directive|define
name|DM_VEN_DEV_SPCv
value|0x80080000
end_define

begin_define
define|#
directive|define
name|DM_VEN_DEV_SPCve
value|0x80090000
end_define

begin_define
define|#
directive|define
name|DM_VEN_DEV_SPCvplus
value|0x80180000
end_define

begin_define
define|#
directive|define
name|DM_VEN_DEV_SPCveplus
value|0x80190000
end_define

begin_define
define|#
directive|define
name|DM_VEN_DEV_ADAPvplus
value|0x80880000
end_define

begin_define
define|#
directive|define
name|DM_VEN_DEV_ADAPveplus
value|0x80890000
end_define

begin_define
define|#
directive|define
name|DMIsSPC
parameter_list|(
name|agr
parameter_list|)
value|(DM_VEN_DEV_SPC        == (ossaHwRegReadConfig32(agr,0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPC */
end_comment

begin_define
define|#
directive|define
name|DMIsSPCADAP
parameter_list|(
name|agr
parameter_list|)
value|(DM_VEN_DEV_SPC        == (ossaHwRegReadConfig32(agr,0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPC */
end_comment

begin_define
define|#
directive|define
name|DMIsSPCv
parameter_list|(
name|agr
parameter_list|)
value|(DM_VEN_DEV_SPCv       == (ossaHwRegReadConfig32(agr,0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPCv */
end_comment

begin_define
define|#
directive|define
name|DMIsSPCve
parameter_list|(
name|agr
parameter_list|)
value|(DM_VEN_DEV_SPCve      == (ossaHwRegReadConfig32(agr,0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPCve */
end_comment

begin_define
define|#
directive|define
name|DMIsSPCvplus
parameter_list|(
name|agr
parameter_list|)
value|(DM_VEN_DEV_SPCvplus   == (ossaHwRegReadConfig32(agr,0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPCv+ */
end_comment

begin_define
define|#
directive|define
name|DMIsSPCveplus
parameter_list|(
name|agr
parameter_list|)
value|(DM_VEN_DEV_SPCveplus  == (ossaHwRegReadConfig32(agr,0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPCve+ */
end_comment

begin_define
define|#
directive|define
name|DMIsSPCADAPvplus
parameter_list|(
name|agr
parameter_list|)
value|(DM_VEN_DEV_ADAPvplus  == (ossaHwRegReadConfig32(agr,0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPCv+ */
end_comment

begin_define
define|#
directive|define
name|DMIsSPCADAPveplus
parameter_list|(
name|agr
parameter_list|)
value|(DM_VEN_DEV_ADAPveplus == (ossaHwRegReadConfig32(agr,0 )& 0xFFFF0000) ? 1 : 0)
end_define

begin_comment
comment|/* returns true config space read is SPCve+ */
end_comment

begin_comment
comment|/****************************************************************  *            SAS 1.1 Spec  ****************************************************************/
end_comment

begin_comment
comment|/* SMP header definition */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dmSMPFrameHeader_s
block|{
name|bit8
name|smpFrameType
decl_stmt|;
comment|/* The first byte of SMP frame represents the SMP FRAME TYPE */
name|bit8
name|smpFunction
decl_stmt|;
comment|/* The second byte of the SMP frame represents the SMP FUNCTION */
name|bit8
name|smpFunctionResult
decl_stmt|;
comment|/* The third byte of SMP frame represents FUNCTION RESULT of the SMP response. */
name|bit8
name|smpReserved
decl_stmt|;
comment|/* reserved */
block|}
name|dmSMPFrameHeader_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *            report general request  ****************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FOR_COMPLETENESS
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|smpReqReportGeneral_s
block|{
comment|/* nothing. some compiler disallowed structure with no member */
block|}
name|smpReqReportGeneral_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/****************************************************************  *            report general response  ****************************************************************/
end_comment

begin_define
define|#
directive|define
name|REPORT_GENERAL_CONFIGURING_BIT
value|0x2
end_define

begin_define
define|#
directive|define
name|REPORT_GENERAL_CONFIGURABLE_BIT
value|0x1
end_define

begin_define
define|#
directive|define
name|REPORT_GENERAL_LONG_RESPONSE_BIT
value|0x80
end_define

begin_typedef
typedef|typedef
struct|struct
name|smpRespReportGeneral_s
block|{
name|bit8
name|expanderChangeCount16
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|expanderRouteIndexes16
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|reserved1
decl_stmt|;
comment|/* byte 9; has LONG Response for SAS 2 at bit 8 */
name|bit8
name|numOfPhys
decl_stmt|;
name|bit8
name|configuring_configurable
decl_stmt|;
comment|/* B7-2 : reserved */
comment|/* B1   : configuring */
comment|/* B0   : configurable */
name|bit8
name|reserved4
index|[
literal|17
index|]
decl_stmt|;
block|}
name|smpRespReportGeneral_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|REPORT_GENERAL_IS_CONFIGURING
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->configuring_configurable& REPORT_GENERAL_CONFIGURING_BIT) == \       REPORT_GENERAL_CONFIGURING_BIT)
end_define

begin_define
define|#
directive|define
name|REPORT_GENERAL_IS_CONFIGURABLE
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->configuring_configurable& REPORT_GENERAL_CONFIGURABLE_BIT) == \       REPORT_GENERAL_CONFIGURABLE_BIT)
end_define

begin_define
define|#
directive|define
name|REPORT_GENERAL_GET_ROUTEINDEXES
parameter_list|(
name|pResp
parameter_list|)
define|\
value|DMA_BEBIT16_TO_BIT16(*(bit16 *)((pResp)->expanderRouteIndexes16))
end_define

begin_define
define|#
directive|define
name|REPORT_GENERAL_IS_LONG_RESPONSE
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->reserved1& REPORT_GENERAL_LONG_RESPONSE_BIT) == \       REPORT_GENERAL_LONG_RESPONSE_BIT)
end_define

begin_comment
comment|/****************************************************************  *            report manufacturer info response  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpRespReportManufactureInfo_s
block|{
name|bit8
name|reserved1
index|[
literal|8
index|]
decl_stmt|;
name|bit8
name|vendorIdentification
index|[
literal|8
index|]
decl_stmt|;
name|bit8
name|productIdentification
index|[
literal|16
index|]
decl_stmt|;
name|bit8
name|productRevisionLevel
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|vendorSpecific
index|[
literal|20
index|]
decl_stmt|;
block|}
name|smpRespReportManufactureInfo_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *           discover request  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpReqDiscover_s
block|{
name|bit32
name|reserved1
decl_stmt|;
name|bit8
name|reserved2
decl_stmt|;
name|bit8
name|phyIdentifier
decl_stmt|;
name|bit8
name|ignored
decl_stmt|;
name|bit8
name|reserved3
decl_stmt|;
block|}
name|smpReqDiscover_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *           discover response  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpRespDiscover_s
block|{
name|bit8
name|reserved1
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|reserved2
decl_stmt|;
name|bit8
name|phyIdentifier
decl_stmt|;
name|bit8
name|reserved3
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|attachedDeviceType
decl_stmt|;
comment|/* byte 12 */
comment|/* B7   : reserved */
comment|/* B6-4 : attachedDeviceType */
comment|/* B3-0 : reserved */
name|bit8
name|negotiatedPhyLinkRate
decl_stmt|;
comment|/* byte 11 */
comment|/* B7-4 : reserved */
comment|/* B3-0 : negotiatedPhyLinkRate */
name|bit8
name|attached_Ssp_Stp_Smp_Sata_Initiator
decl_stmt|;
comment|/* byte 14 */
comment|/* B7-4 : reserved */
comment|/* B3   : attachedSspInitiator */
comment|/* B2   : attachedStpInitiator */
comment|/* B1   : attachedSmpInitiator */
comment|/* B0   : attachedSataHost */
name|bit8
name|attached_SataPS_Ssp_Stp_Smp_Sata_Target
decl_stmt|;
comment|/* byte 15 */
comment|/* B7   : attachedSataPortSelector */
comment|/* B6-4 : reserved */
comment|/* B3   : attachedSspTarget */
comment|/* B2   : attachedStpTarget */
comment|/* B1   : attachedSmpTarget */
comment|/* B0   : attachedSatadevice */
name|bit8
name|sasAddressHi
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|sasAddressLo
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|attachedSasAddressHi
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|attachedSasAddressLo
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|attachedPhyIdentifier
decl_stmt|;
name|bit8
name|reserved9
index|[
literal|7
index|]
decl_stmt|;
name|bit8
name|programmedAndHardware_MinPhyLinkRate
decl_stmt|;
comment|/* B7-4 : programmedMinPhyLinkRate */
comment|/* B3-0 : hardwareMinPhyLinkRate */
name|bit8
name|programmedAndHardware_MaxPhyLinkRate
decl_stmt|;
comment|/* B7-4 : programmedMaxPhyLinkRate */
comment|/* B3-0 : hardwareMaxPhyLinkRate */
name|bit8
name|phyChangeCount
decl_stmt|;
name|bit8
name|virtualPhy_partialPathwayTimeout
decl_stmt|;
comment|/* byte 43 */
comment|/* B7   : virtualPhy*/
comment|/* B6-4 : reserved */
comment|/* B3-0 : partialPathwayTimeout */
name|bit8
name|routingAttribute
decl_stmt|;
comment|/* B7-4 : reserved */
comment|/* B3-0 : routingAttribute */
name|bit8
name|reserved13
index|[
literal|5
index|]
decl_stmt|;
name|bit8
name|vendorSpecific
index|[
literal|2
index|]
decl_stmt|;
block|}
name|smpRespDiscover_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DISCRSP_SSP_BIT
value|0x08
end_define

begin_define
define|#
directive|define
name|DISCRSP_STP_BIT
value|0x04
end_define

begin_define
define|#
directive|define
name|DISCRSP_SMP_BIT
value|0x02
end_define

begin_define
define|#
directive|define
name|DISCRSP_SATA_BIT
value|0x01
end_define

begin_define
define|#
directive|define
name|DISCRSP_SATA_PS_BIT
value|0x80
end_define

begin_define
define|#
directive|define
name|DISCRSP_GET_ATTACHED_DEVTYPE
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attachedDeviceType& 0x70)>> 4)
end_define

begin_define
define|#
directive|define
name|DISCRSP_GET_LINKRATE
parameter_list|(
name|pResp
parameter_list|)
define|\
value|((pResp)->negotiatedPhyLinkRate& 0x0F)
end_define

begin_define
define|#
directive|define
name|DISCRSP_IS_SSP_INITIATOR
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_Ssp_Stp_Smp_Sata_Initiator& DISCRSP_SSP_BIT) == DISCRSP_SSP_BIT)
end_define

begin_define
define|#
directive|define
name|DISCRSP_IS_STP_INITIATOR
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_Ssp_Stp_Smp_Sata_Initiator& DISCRSP_STP_BIT) == DISCRSP_STP_BIT)
end_define

begin_define
define|#
directive|define
name|DISCRSP_IS_SMP_INITIATOR
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_Ssp_Stp_Smp_Sata_Initiator& DISCRSP_SMP_BIT) == DISCRSP_SMP_BIT)
end_define

begin_define
define|#
directive|define
name|DISCRSP_IS_SATA_HOST
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_Ssp_Stp_Smp_Sata_Initiator& DISCRSP_SATA_BIT) == DISCRSP_SATA_BIT)
end_define

begin_define
define|#
directive|define
name|DISCRSP_IS_SSP_TARGET
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_SataPS_Ssp_Stp_Smp_Sata_Target& DISCRSP_SSP_BIT) == DISCRSP_SSP_BIT)
end_define

begin_define
define|#
directive|define
name|DISCRSP_IS_STP_TARGET
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_SataPS_Ssp_Stp_Smp_Sata_Target& DISCRSP_STP_BIT) == DISCRSP_STP_BIT)
end_define

begin_define
define|#
directive|define
name|DISCRSP_IS_SMP_TARGET
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_SataPS_Ssp_Stp_Smp_Sata_Target& DISCRSP_SMP_BIT) == DISCRSP_SMP_BIT)
end_define

begin_define
define|#
directive|define
name|DISCRSP_IS_SATA_DEVICE
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_SataPS_Ssp_Stp_Smp_Sata_Target& DISCRSP_SATA_BIT) == DISCRSP_SATA_BIT)
end_define

begin_define
define|#
directive|define
name|DISCRSP_IS_SATA_PORTSELECTOR
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_SataPS_Ssp_Stp_Smp_Sata_Target& DISCRSP_SATA_PS_BIT) == DISCRSP_SATA_PS_BIT)
end_define

begin_comment
comment|/* bit8 array[4] -> bit32 */
end_comment

begin_define
define|#
directive|define
name|DISCRSP_GET_SAS_ADDRESSHI
parameter_list|(
name|pResp
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)(pResp)->sasAddressHi)
end_define

begin_define
define|#
directive|define
name|DISCRSP_GET_SAS_ADDRESSLO
parameter_list|(
name|pResp
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)(pResp)->sasAddressLo)
end_define

begin_comment
comment|/* bit8 array[4] -> bit32 */
end_comment

begin_define
define|#
directive|define
name|DISCRSP_GET_ATTACHED_SAS_ADDRESSHI
parameter_list|(
name|pResp
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)(pResp)->attachedSasAddressHi)
end_define

begin_define
define|#
directive|define
name|DISCRSP_GET_ATTACHED_SAS_ADDRESSLO
parameter_list|(
name|pResp
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)(pResp)->attachedSasAddressLo)
end_define

begin_define
define|#
directive|define
name|DISCRSP_VIRTUALPHY_BIT
value|0x80
end_define

begin_define
define|#
directive|define
name|DISCRSP_IS_VIRTUALPHY
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->virtualPhy_partialPathwayTimeout& DISCRSP_VIRTUALPHY_BIT) == DISCRSP_VIRTUALPHY_BIT)
end_define

begin_define
define|#
directive|define
name|DISCRSP_GET_ROUTINGATTRIB
parameter_list|(
name|pResp
parameter_list|)
define|\
value|((pResp)->routingAttribute& 0x0F)
end_define

begin_comment
comment|/****************************************************************  *            report route table request  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpReqReportRouteTable_s
block|{
name|bit8
name|reserved1
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|expanderRouteIndex16
index|[
literal|20
index|]
decl_stmt|;
name|bit8
name|reserved2
decl_stmt|;
name|bit8
name|phyIdentifier
decl_stmt|;
name|bit8
name|reserved3
index|[
literal|2
index|]
decl_stmt|;
block|}
name|smpReqReportRouteTable_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *            report route response  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpRespReportRouteTable_s
block|{
name|bit8
name|reserved1
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|expanderRouteIndex16
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|reserved2
decl_stmt|;
name|bit8
name|phyIdentifier
decl_stmt|;
name|bit8
name|reserved3
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|disabled
decl_stmt|;
comment|/* B7   : expander route entry disabled */
comment|/* B6-0 : reserved */
name|bit8
name|reserved5
index|[
literal|3
index|]
decl_stmt|;
name|bit8
name|routedSasAddressHi32
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|routedSasAddressLo32
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|reserved6
index|[
literal|16
index|]
decl_stmt|;
block|}
name|smpRespReportRouteTable_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *            configure route information request  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpReqConfigureRouteInformation_s
block|{
name|bit8
name|reserved1
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|expanderRouteIndex
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|reserved2
decl_stmt|;
name|bit8
name|phyIdentifier
decl_stmt|;
name|bit8
name|reserved3
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|disabledBit_reserved4
decl_stmt|;
name|bit8
name|reserved5
index|[
literal|3
index|]
decl_stmt|;
name|bit8
name|routedSasAddressHi
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|routedSasAddressLo
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|reserved6
index|[
literal|16
index|]
decl_stmt|;
block|}
name|smpReqConfigureRouteInformation_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *            configure route response  ****************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FOR_COMPLETENESS
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|smpRespConfigureRouteInformation_s
block|{
comment|/* nothing. some compiler disallowed structure with no member */
block|}
name|smpRespConfigureRouteInformation_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/****************************************************************  *            report Phy Sata request  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpReqReportPhySata_s
block|{
name|bit8
name|reserved1
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|reserved2
decl_stmt|;
name|bit8
name|phyIdentifier
decl_stmt|;
name|bit8
name|reserved3
index|[
literal|2
index|]
decl_stmt|;
block|}
name|smpReqReportPhySata_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *            report Phy Sata response  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpRespReportPhySata_s
block|{
name|bit8
name|reserved1
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|reserved2
decl_stmt|;
name|bit8
name|phyIdentifier
decl_stmt|;
name|bit8
name|reserved3
decl_stmt|;
name|bit8
name|affiliations_sup_valid
decl_stmt|;
comment|/* b7-2 : reserved */
comment|/* b1   : Affiliations supported */
comment|/* b0   : Affiliation valid */
name|bit8
name|reserved5
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|stpSasAddressHi
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|stpSasAddressLo
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|regDevToHostFis
index|[
literal|20
index|]
decl_stmt|;
name|bit8
name|reserved6
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|affiliatedStpInitiatorSasAddressHi
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|affiliatedStpInitiatorSasAddressLo
index|[
literal|4
index|]
decl_stmt|;
block|}
name|smpRespReportPhySata_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *            Phy Control request  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpReqPhyControl_s
block|{
name|bit8
name|reserved1
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|reserved2
decl_stmt|;
name|bit8
name|phyIdentifier
decl_stmt|;
name|bit8
name|phyOperation
decl_stmt|;
name|bit8
name|updatePartialPathwayTOValue
decl_stmt|;
comment|/* b7-1 : reserved */
comment|/* b0   : update partial pathway timeout value */
name|bit8
name|reserved3
index|[
literal|20
index|]
decl_stmt|;
name|bit8
name|programmedMinPhysicalLinkRate
decl_stmt|;
comment|/* b7-4 : programmed Minimum Physical Link Rate*/
comment|/* b3-0 : reserved */
name|bit8
name|programmedMaxPhysicalLinkRate
decl_stmt|;
comment|/* b7-4 : programmed Maximum Physical Link Rate*/
comment|/* b3-0 : reserved */
name|bit8
name|reserved4
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|partialPathwayTOValue
decl_stmt|;
comment|/* b7-4 : reserved */
comment|/* b3-0 : partial Pathway TO Value */
name|bit8
name|reserved5
index|[
literal|3
index|]
decl_stmt|;
block|}
name|smpReqPhyControl_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *            Phy Control response  ****************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FOR_COMPLETENESS
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|smpRespPhyControl_s
block|{
comment|/* nothing. some compiler disallowed structure with no member */
block|}
name|smpRespPhyControl_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/****************************************************************  *            SAS 2 Rev 14c Spec  ****************************************************************/
end_comment

begin_comment
comment|/* SMP header definition */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tdssSMPFrameHeader2_s
block|{
name|bit8
name|smpFrameType
decl_stmt|;
comment|/* The first byte of SMP frame represents the SMP FRAME TYPE */
name|bit8
name|smpFunction
decl_stmt|;
comment|/* The second byte of the SMP frame represents the SMP FUNCTION */
name|bit8
name|smpAllocLenFuncResult
decl_stmt|;
comment|/* The third byte of SMP frame represents ALLOCATED RESPONSE LENGTH of SMP request or FUNCTION RESULT of the SMP response. */
name|bit8
name|smpReqResLen
decl_stmt|;
comment|/* The third byte of SMP frame represents REQUEST LENGTH of SMP request or RESPONSE LENGTH of the SMP response. */
block|}
name|tdssSMPFrameHeader2_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *            report general request  ****************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FOR_COMPLETENESS
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|smpReqReportGeneral2_s
block|{
comment|/* nothing. some compiler disallowed structure with no member */
block|}
name|smpReqReportGeneral2_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/****************************************************************  *            report general response  ****************************************************************/
end_comment

begin_define
define|#
directive|define
name|REPORT_GENERAL_TABLE_TO_TABLE_SUPPORTED_BIT
value|0x80
end_define

begin_define
define|#
directive|define
name|REPORT_GENERAL_CONFIGURES_OTHERS_BIT
value|0x04
end_define

begin_typedef
typedef|typedef
struct|struct
name|smpRespReportGeneral2_s
block|{
name|bit8
name|expanderChangeCount16
index|[
literal|2
index|]
decl_stmt|;
comment|/* byte 4-5 */
name|bit8
name|expanderRouteIndexes16
index|[
literal|2
index|]
decl_stmt|;
comment|/* byte 6-7 */
name|bit8
name|LongResponse
decl_stmt|;
comment|/* byte 8 */
comment|/* B7: LongResponse */
comment|/* B6-0: Reserved */
name|bit8
name|numOfPhys
decl_stmt|;
comment|/* byte 9 */
name|bit8
name|byte10
decl_stmt|;
comment|/* B7   : TABLE TO TABLE SUPPORTED */
comment|/* B6   : ZONE CONFIGURING */
comment|/* B5   : SELF CONFIGURING */
comment|/* B4   : STP CONTINUE AWT */
comment|/* B3   : OPEN REJECT RETRY SUPPORTED */
comment|/* B2   : CONFIGURES OTHERS */
comment|/* B1   : CONFIGURING */
comment|/* B0   : EXTERNALLY CONFIGURABLE ROUTE TABLE  */
name|bit8
name|reserved1
decl_stmt|;
comment|/* byte11 */
name|bit8
name|EnclosureLogicalID
index|[
literal|8
index|]
decl_stmt|;
name|bit8
name|reserved2
index|[
literal|8
index|]
decl_stmt|;
comment|/* upto byte27; Spec 1.1 */
name|bit8
name|reserved3
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|STPBusInactivityTimeLimit
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|STPMaxConnectTimeLimit
index|[
literal|2
index|]
decl_stmt|;
comment|/* byte33 */
name|bit8
name|STPSMPI_TNexusLossTime
index|[
literal|2
index|]
decl_stmt|;
comment|/* byte35 */
name|bit8
name|byte36
decl_stmt|;
comment|/* B7-6 : NUMBER OF ZONE GROUPS */
comment|/* B5   : RESERVED */
comment|/* B4   : ZONE LOCKED */
comment|/* B3   : PHYSICAL PRESENCE SUPPORTED */
comment|/* B2   : PHYSICAL PRESENCE ASSERTED */
comment|/* B1   : ZONING SUPPORTED */
comment|/* B0   : ZONING ENABLED */
name|bit8
name|byte37
decl_stmt|;
comment|/* B7-5 : RESERVED */
comment|/* B4   : SAVING */
comment|/* B3   : SAVING ZONE MANAGER PASSWORD SUPPORTED */
comment|/* B2   : SAVING ZONE PHY INFORMATION SUPPORTED   */
comment|/* B1   : SAVING ZONE PERMISSION TABLE SUPPORTED */
comment|/* B0   : SAVING ZONING ENABLED SUPPORTED */
name|bit8
name|MaxNumOfRoutedSASAddr
index|[
literal|2
index|]
decl_stmt|;
comment|/* byte39 */
name|bit8
name|ActiveZoneManagerSASAddr
index|[
literal|8
index|]
decl_stmt|;
comment|/* byte47 */
name|bit8
name|ZoneLockInactivityTimeLimit
index|[
literal|2
index|]
decl_stmt|;
comment|/* byte49 */
name|bit8
name|reserved4
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|reserved5
decl_stmt|;
comment|/* byte52 */
name|bit8
name|FirstEnclosureConnectorElementIdx
decl_stmt|;
comment|/* byte53 */
name|bit8
name|NumOfEnclosureConnectorElementIdxs
decl_stmt|;
comment|/* byte54 */
name|bit8
name|reserved6
decl_stmt|;
comment|/* byte55 */
name|bit8
name|ReducedFunctionality
decl_stmt|;
comment|/* B7: ReducedFunctionality */
comment|/* B6-0: Reserved */
name|bit8
name|TimeToReducedFunctionality
decl_stmt|;
name|bit8
name|InitialTimeToReducedFunctionality
decl_stmt|;
name|bit8
name|MaxReducedFunctionalityTime
decl_stmt|;
comment|/* byte59 */
name|bit8
name|LastSelfConfigurationStatusDescIdx
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|MaxNumOfStoredSelfConfigurationStatusDesc
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|LastPhyEventListDescIdx
index|[
literal|2
index|]
decl_stmt|;
name|bit8
name|MaxNumbOfStoredPhyEventListDesc
index|[
literal|2
index|]
decl_stmt|;
comment|/* byte67 */
name|bit8
name|STPRejectToOpenLimit
index|[
literal|2
index|]
decl_stmt|;
comment|/* byte69 */
name|bit8
name|reserved7
index|[
literal|2
index|]
decl_stmt|;
comment|/* byte71 */
block|}
name|smpRespReportGeneral2_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SAS2_REPORT_GENERAL_GET_ROUTEINDEXES
parameter_list|(
name|pResp
parameter_list|)
define|\
value|DMA_BEBIT16_TO_BIT16(*(bit16 *)((pResp)->expanderRouteIndexes16))
end_define

begin_define
define|#
directive|define
name|SAS2_REPORT_GENERAL_IS_CONFIGURING
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->byte10& REPORT_GENERAL_CONFIGURING_BIT) == \       REPORT_GENERAL_CONFIGURING_BIT)
end_define

begin_define
define|#
directive|define
name|SAS2_REPORT_GENERAL_IS_CONFIGURABLE
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->byte10& REPORT_GENERAL_CONFIGURABLE_BIT) == \       REPORT_GENERAL_CONFIGURABLE_BIT)
end_define

begin_define
define|#
directive|define
name|SAS2_REPORT_GENERAL_IS_TABLE_TO_TABLE_SUPPORTED
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->byte10& REPORT_GENERAL_TABLE_TO_TABLE_SUPPORTED_BIT) == \       REPORT_GENERAL_TABLE_TO_TABLE_SUPPORTED_BIT)
end_define

begin_define
define|#
directive|define
name|SAS2_REPORT_GENERAL_IS_CONFIGURES_OTHERS
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->byte10& REPORT_GENERAL_CONFIGURES_OTHERS_BIT) == \       REPORT_GENERAL_CONFIGURES_OTHERS_BIT)
end_define

begin_comment
comment|/****************************************************************  *            report manufacturer info request  ****************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FOR_COMPLETENESS
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|smpReqReportManufactureInfo2_s
block|{
comment|/* nothing. some compiler disallowed structure with no member */
block|}
name|smpReqReportManufactureInfo2_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/****************************************************************  *            report manufacturer info response  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpRespReportManufactureInfo2_s
block|{
name|bit16
name|ExpanderChangeCount
decl_stmt|;
comment|/* byte 4-5 */
name|bit8
name|reserved1
index|[
literal|2
index|]
decl_stmt|;
comment|/* byte 6-7 */
name|bit8
name|SAS11Format
decl_stmt|;
comment|/* byte 8 */
comment|/* B7-1 : RESERVED */
comment|/* B0   : SAS-1.1 Format */
name|bit8
name|reserved2
index|[
literal|3
index|]
decl_stmt|;
comment|/* byte 9-11 */
name|bit8
name|vendorIdentification
index|[
literal|8
index|]
decl_stmt|;
comment|/* byte 12-19 */
name|bit8
name|productIdentification
index|[
literal|16
index|]
decl_stmt|;
comment|/* byte 20-35 */
name|bit8
name|productRevisionLevel
index|[
literal|4
index|]
decl_stmt|;
comment|/* byte 36-39 */
name|bit8
name|componentVendorID
index|[
literal|8
index|]
decl_stmt|;
comment|/* byte 40-47 */
name|bit8
name|componentID
index|[
literal|2
index|]
decl_stmt|;
comment|/* byte 48-49 */
name|bit8
name|componentRevisionLevel
decl_stmt|;
comment|/* byte 50 */
name|bit8
name|reserved3
decl_stmt|;
comment|/* byte 51 */
name|bit8
name|vendorSpecific
index|[
literal|8
index|]
decl_stmt|;
comment|/* byte 52-59 */
block|}
name|smpRespReportManufactureInfo2_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *           discover request  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpReqDiscover2_s
block|{
name|bit32
name|reserved1
decl_stmt|;
comment|/* byte 4 - 7 */
name|bit8
name|IgnoreZoneGroup
decl_stmt|;
comment|/* byte 8 */
name|bit8
name|phyIdentifier
decl_stmt|;
comment|/* byte 9 */
name|bit16
name|reserved2
decl_stmt|;
comment|/* byte 10 - 11*/
block|}
name|smpReqDiscover2_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *           discover response  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpRespDiscover2_s
block|{
name|bit16
name|ExpanderChangeCount
decl_stmt|;
comment|/* byte 4 - 5 */
name|bit8
name|reserved1
index|[
literal|3
index|]
decl_stmt|;
comment|/* byte 6 - 8 */
name|bit8
name|phyIdentifier
decl_stmt|;
comment|/* byte 9 */
name|bit8
name|reserved2
index|[
literal|2
index|]
decl_stmt|;
comment|/* byte 10 - 11 */
name|bit8
name|attachedDeviceTypeReason
decl_stmt|;
comment|/* byte 12 */
comment|/* B7   : RESERVED */
comment|/* B6-4 : Attached Device Type */
comment|/* B3-0 : Attached Reason */
name|bit8
name|NegotiatedLogicalLinkRate
decl_stmt|;
comment|/* byte 13 */
comment|/* B7-4 : RESERVED */
comment|/* B3-0 : Negotiated Logical Link Rate */
name|bit8
name|attached_Ssp_Stp_Smp_Sata_Initiator
decl_stmt|;
comment|/* byte 14 */
comment|/* B7-4 : reserved */
comment|/* B3   : attached SSP Initiator */
comment|/* B2   : attached STP Initiator */
comment|/* B1   : attached SMP Initiator */
comment|/* B0   : attached SATA Host */
name|bit8
name|attached_SataPS_Ssp_Stp_Smp_Sata_Target
decl_stmt|;
comment|/* byte 15 */
comment|/* B7   : attached SATA Port Selector */
comment|/* B6-4 : reserved */
comment|/* B3   : attached SSP Target */
comment|/* B2   : attached STP Target */
comment|/* B1   : attached SMP Target */
comment|/* B0   : attached SATA device */
name|bit8
name|sasAddressHi
index|[
literal|4
index|]
decl_stmt|;
comment|/* byte 16 - 19 */
name|bit8
name|sasAddressLo
index|[
literal|4
index|]
decl_stmt|;
comment|/* byte 20 - 23 */
name|bit8
name|attachedSasAddressHi
index|[
literal|4
index|]
decl_stmt|;
comment|/* byte 24 - 27 */
name|bit8
name|attachedSasAddressLo
index|[
literal|4
index|]
decl_stmt|;
comment|/* byte 28 - 31 */
name|bit8
name|attachedPhyIdentifier
decl_stmt|;
comment|/* byte 32 */
name|bit8
name|byte33
decl_stmt|;
comment|/* byte 33 */
comment|/* B7-3   : reserved */
comment|/* B2   : attached Inside ZPSDS Persistent */
comment|/* B1   : attached Requested Inside ZPSDS */
comment|/* B0   : attached Break Reply Capable */
name|bit8
name|reserved3
index|[
literal|6
index|]
decl_stmt|;
comment|/* byte 34 - 39; for indentify address frame related fields */
name|bit8
name|programmedAndHardware_MinPhyLinkRate
decl_stmt|;
comment|/* byte 40 */
comment|/* B7-4 : programmedMinPhyLinkRate */
comment|/* B3-0 : hardwareMinPhyLinkRate */
name|bit8
name|programmedAndHardware_MaxPhyLinkRate
decl_stmt|;
comment|/* byte 41 */
comment|/* B7-4 : programmedMaxPhyLinkRate */
comment|/* B3-0 : hardwareMaxPhyLinkRate */
name|bit8
name|phyChangeCount
decl_stmt|;
comment|/* byte 42 */
name|bit8
name|virtualPhy_partialPathwayTimeout
decl_stmt|;
comment|/* byte 43 */
comment|/* B7   : virtualPhy*/
comment|/* B6-4 : reserved */
comment|/* B3-0 : partialPathwayTimeout */
name|bit8
name|routingAttribute
decl_stmt|;
comment|/* byte 44 */
comment|/* B7-4 : reserved */
comment|/* B3-0 : routingAttribute */
name|bit8
name|ConnectorType
decl_stmt|;
comment|/* byte 45 */
comment|/* B7   : reserved */
comment|/* B6-0 : Connector Type */
name|bit8
name|ConnectorElementIndex
decl_stmt|;
comment|/* byte 46 */
name|bit8
name|ConnectorPhysicalLink
decl_stmt|;
comment|/* byte 47 */
name|bit8
name|reserved4
index|[
literal|2
index|]
decl_stmt|;
comment|/* byte 48 - 49 */
name|bit8
name|vendorSpecific
index|[
literal|2
index|]
decl_stmt|;
comment|/* byte 50 - 51*/
name|bit8
name|AttachedDeviceName
index|[
literal|8
index|]
decl_stmt|;
comment|/* byte 52 - 59*/
name|bit8
name|byte60
decl_stmt|;
comment|/* byte 60 */
comment|/* B7   : reserved */
comment|/* B6   : Requested Inside ZPSDS Changed By Expander */
comment|/* B5   : Inside ZPSDS Persistent */
comment|/* B4   : Requested Inside ZPSDS */
comment|/* B3   : reserved */
comment|/* B2   : Zone Group Persistent */
comment|/* B1   : Inside ZPSDS */
comment|/* B0   : Zoning Enabled */
name|bit8
name|reserved5
index|[
literal|2
index|]
decl_stmt|;
comment|/* byte 61 - 62; zoning-related fields */
name|bit8
name|ZoneGroup
decl_stmt|;
comment|/* byte 63 */
name|bit8
name|SelfCongfiguringStatus
decl_stmt|;
comment|/* byte 64 */
name|bit8
name|SelfCongfigurationLevelsCompleted
decl_stmt|;
comment|/* byte 65 */
name|bit8
name|reserved6
index|[
literal|2
index|]
decl_stmt|;
comment|/* byte 66 - 67; self configuration related fields */
name|bit8
name|SelfConfigurationSASAddressHi
index|[
literal|4
index|]
decl_stmt|;
comment|/* byte 68 - 71 */
name|bit8
name|SelfConfigurationSASAddressLo
index|[
literal|4
index|]
decl_stmt|;
comment|/* byte 72 - 75 */
name|bit8
name|ProgrammedphyCapabilities
index|[
literal|4
index|]
decl_stmt|;
comment|/* byte 76 - 79 */
name|bit8
name|CurrentphyCapabilities
index|[
literal|4
index|]
decl_stmt|;
comment|/* byte 80 - 83 */
name|bit8
name|AttachedphyCapabilities
index|[
literal|4
index|]
decl_stmt|;
comment|/* byte 84 - 87 */
name|bit8
name|reserved7
index|[
literal|6
index|]
decl_stmt|;
comment|/* byte 88 - 93 */
name|bit8
name|ReasonNegotiatedPhysicalLinkRate
decl_stmt|;
comment|/* byte 94 */
name|bit8
name|NegotiatedSSCHWMuxingSupported
decl_stmt|;
comment|/* byte 95 */
comment|/* B7-2 : reserved */
comment|/* B1   : Negotiated SSC */
comment|/* B0   : HW Muxing Supported */
name|bit8
name|byte96
decl_stmt|;
comment|/* byte 96 */
comment|/* B7-6 : reserved */
comment|/* B5   : Default Inside ZPSDS Persistent */
comment|/* B4   : Default Requested Inside ZPSDS */
comment|/* B3   : reserved */
comment|/* B2   : Default Zone Group Persistent */
comment|/* B1   : reserved */
comment|/* B0   : Default Zoning Enabled */
name|bit8
name|reserved8
decl_stmt|;
comment|/* byte 97 */
name|bit8
name|reserved9
decl_stmt|;
comment|/* byte 98 */
name|bit8
name|DefaultZoneGroup
decl_stmt|;
comment|/* byte 99 */
name|bit8
name|byte100
decl_stmt|;
comment|/* byte 100 */
comment|/* B7-6 : reserved */
comment|/* B5   : Saved Inside ZPSDS Persistent */
comment|/* B4   : Saved Requested Inside ZPSDS */
comment|/* B3   : reserved */
comment|/* B2   : Saved Zone Group Persistent */
comment|/* B1   : reserved */
comment|/* B0   : Saved Zoning Enabled */
name|bit8
name|reserved10
decl_stmt|;
comment|/* byte 101 */
name|bit8
name|reserved11
decl_stmt|;
comment|/* byte 102 */
name|bit8
name|SavedZoneGroup
decl_stmt|;
comment|/* byte 103 */
name|bit8
name|byte104
decl_stmt|;
comment|/* byte 104 */
comment|/* B7-6 : reserved */
comment|/* B5   : Shadow Inside ZPSDS Persistent */
comment|/* B4   : Shadow Requested Inside ZPSDS */
comment|/* B3   : reserved */
comment|/* B2   : Shadow Zone Group Persistent */
comment|/* B1-0 : reserved */
name|bit8
name|reserved12
decl_stmt|;
comment|/* byte 105 */
name|bit8
name|reserved13
decl_stmt|;
comment|/* byte 106 */
name|bit8
name|ShadowZoneGroup
decl_stmt|;
comment|/* byte 107 */
name|bit8
name|DeviceSlotNumber
decl_stmt|;
comment|/* byte 108 */
name|bit8
name|GroupNumber
decl_stmt|;
comment|/* byte 109 */
name|bit16
name|PathToEnclosure
decl_stmt|;
comment|/* byte 110 - 111 */
block|}
name|smpRespDiscover2_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SAS2_DISCRSP_SSP_BIT
value|0x08
end_define

begin_define
define|#
directive|define
name|SAS2_DISCRSP_STP_BIT
value|0x04
end_define

begin_define
define|#
directive|define
name|SAS2_DISCRSP_SMP_BIT
value|0x02
end_define

begin_define
define|#
directive|define
name|SAS2_DISCRSP_SATA_BIT
value|0x01
end_define

begin_define
define|#
directive|define
name|SAS2_DISCRSP_SATA_PS_BIT
value|0x80
end_define

begin_define
define|#
directive|define
name|SAS2_MUXING_SUPPORTED
value|0x01
end_define

begin_define
define|#
directive|define
name|SAS2_DISCRSP_GET_ATTACHED_DEVTYPE
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attachedDeviceTypeReason& 0x70)>> 4)
end_define

begin_define
define|#
directive|define
name|SAS2_DISCRSP_GET_LINKRATE
parameter_list|(
name|pResp
parameter_list|)
define|\
value|((pResp)->ReasonNegotiatedPhysicalLinkRate& 0x0F)
end_define

begin_define
define|#
directive|define
name|SAS2_DISCRSP_GET_LOGICAL_LINKRATE
parameter_list|(
name|pResp
parameter_list|)
define|\
value|((pResp)->NegotiatedLogicalLinkRate& 0x0F)
end_define

begin_define
define|#
directive|define
name|SAS2_DISCRSP_IS_SSP_INITIATOR
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_Ssp_Stp_Smp_Sata_Initiator& DISCRSP_SSP_BIT) == DISCRSP_SSP_BIT)
end_define

begin_define
define|#
directive|define
name|SAS2_DISCRSP_IS_STP_INITIATOR
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_Ssp_Stp_Smp_Sata_Initiator& DISCRSP_STP_BIT) == DISCRSP_STP_BIT)
end_define

begin_define
define|#
directive|define
name|SAS2_DISCRSP_IS_SMP_INITIATOR
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_Ssp_Stp_Smp_Sata_Initiator& DISCRSP_SMP_BIT) == DISCRSP_SMP_BIT)
end_define

begin_define
define|#
directive|define
name|SAS2_DISCRSP_IS_SATA_HOST
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_Ssp_Stp_Smp_Sata_Initiator& DISCRSP_SATA_BIT) == DISCRSP_SATA_BIT)
end_define

begin_define
define|#
directive|define
name|SAS2_DISCRSP_IS_SSP_TARGET
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_SataPS_Ssp_Stp_Smp_Sata_Target& DISCRSP_SSP_BIT) == DISCRSP_SSP_BIT)
end_define

begin_define
define|#
directive|define
name|SAS2_DISCRSP_IS_STP_TARGET
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_SataPS_Ssp_Stp_Smp_Sata_Target& DISCRSP_STP_BIT) == DISCRSP_STP_BIT)
end_define

begin_define
define|#
directive|define
name|SAS2_DISCRSP_IS_SMP_TARGET
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_SataPS_Ssp_Stp_Smp_Sata_Target& DISCRSP_SMP_BIT) == DISCRSP_SMP_BIT)
end_define

begin_define
define|#
directive|define
name|SAS2_DISCRSP_IS_SATA_DEVICE
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_SataPS_Ssp_Stp_Smp_Sata_Target& DISCRSP_SATA_BIT) == DISCRSP_SATA_BIT)
end_define

begin_define
define|#
directive|define
name|SAS2_DISCRSP_IS_SATA_PORTSELECTOR
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->attached_SataPS_Ssp_Stp_Smp_Sata_Target& DISCRSP_SATA_PS_BIT) == DISCRSP_SATA_PS_BIT)
end_define

begin_define
define|#
directive|define
name|SAS2_DISCRSP_GET_SAS_ADDRESSHI
parameter_list|(
name|pResp
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)(pResp)->sasAddressHi)
end_define

begin_define
define|#
directive|define
name|SAS2_DISCRSP_GET_SAS_ADDRESSLO
parameter_list|(
name|pResp
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)(pResp)->sasAddressLo)
end_define

begin_define
define|#
directive|define
name|SAS2_DISCRSP_GET_ATTACHED_SAS_ADDRESSHI
parameter_list|(
name|pResp
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)(pResp)->attachedSasAddressHi)
end_define

begin_define
define|#
directive|define
name|SAS2_DISCRSP_GET_ATTACHED_SAS_ADDRESSLO
parameter_list|(
name|pResp
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)(pResp)->attachedSasAddressLo)
end_define

begin_define
define|#
directive|define
name|SAS2_DISCRSP_VIRTUALPHY_BIT
value|0x80
end_define

begin_define
define|#
directive|define
name|SAS2_DISCRSP_IS_VIRTUALPHY
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->virtualPhy_partialPathwayTimeout& DISCRSP_VIRTUALPHY_BIT) == DISCRSP_VIRTUALPHY_BIT)
end_define

begin_define
define|#
directive|define
name|SAS2_DISCRSP_GET_ROUTINGATTRIB
parameter_list|(
name|pResp
parameter_list|)
define|\
value|((pResp)->routingAttribute& 0x0F)
end_define

begin_define
define|#
directive|define
name|SAS2_DISCRSP_IS_MUXING_SUPPORTED
parameter_list|(
name|pResp
parameter_list|)
define|\
value|(((pResp)->NegotiatedSSCHWMuxingSupported& SAS2_MUXING_SUPPORTED) == SAS2_MUXING_SUPPORTED)
end_define

begin_comment
comment|/****************************************************************  *           discover list request  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpReqDiscoverList2_s
block|{
name|bit32
name|reserved1
decl_stmt|;
comment|/* byte 4 - 7 */
name|bit8
name|StartingPhyID
decl_stmt|;
comment|/* byte 8 */
name|bit8
name|MaxNumDiscoverDesc
decl_stmt|;
comment|/* byte 9 */
name|bit8
name|byte10
decl_stmt|;
comment|/* byte 10 */
comment|/* B7   : Ignore Zone Group */
comment|/* B6-4 : Reserved */
comment|/* B3-0 : Phy Filter */
name|bit8
name|byte11
decl_stmt|;
comment|/* byte 11 */
comment|/* B7-4 : Reserved */
comment|/* B6-4 : Descriptor Type */
name|bit32
name|reserved2
decl_stmt|;
comment|/* byte 12 - 15 */
name|bit8
name|VendorSpecific
index|[
literal|12
index|]
decl_stmt|;
comment|/* byte 16 - 27 */
block|}
name|smpReqDiscoverList2_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *           discover list response  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpRespDiscoverList2_s
block|{
name|bit16
name|ExpanderChangeCount
decl_stmt|;
comment|/* byte 4 - 5 */
name|bit16
name|reserved1
decl_stmt|;
comment|/* byte 6 - 7 */
name|bit8
name|StartingPhyID
decl_stmt|;
comment|/* byte 8 */
name|bit8
name|MaxNumDiscoverDesc
decl_stmt|;
comment|/* byte 9 */
name|bit8
name|byte10
decl_stmt|;
comment|/* byte 10 */
comment|/* B7-4 : Reserved */
comment|/* B3-0 : Phy Filter */
name|bit8
name|byte11
decl_stmt|;
comment|/* byte 11 */
comment|/* B7-4 : Reserved */
comment|/* B6-4 : Descriptor Type */
name|bit8
name|DescLen
decl_stmt|;
comment|/* byte 12 */
name|bit8
name|reserved2
decl_stmt|;
comment|/* byte 13 */
name|bit16
name|reserved3
decl_stmt|;
comment|/* byte 14 - 15 */
name|bit8
name|byte16
decl_stmt|;
comment|/* byte 16 */
comment|/* B7   : Zoning Supported */
comment|/* B6   : Zoning Enabled */
comment|/* B5-4 : Reserved */
comment|/* B3   : Self Configuring */
comment|/* B2   : Zone Configuring */
comment|/* B1   : Configuring */
comment|/* B0   : Externally Configurable Route Table */
name|bit8
name|reserved4
decl_stmt|;
comment|/* byte 17 */
name|bit16
name|LastDescIdx
decl_stmt|;
comment|/* byte 18 - 19 */
name|bit16
name|LastPhyDescIdx
decl_stmt|;
comment|/* byte 20 - 21 */
name|bit8
name|reserved5
index|[
literal|10
index|]
decl_stmt|;
comment|/* byte 22 - 31 */
name|bit8
name|VendorSpecific
index|[
literal|16
index|]
decl_stmt|;
comment|/* byte 32 - 47 */
block|}
name|smpRespDiscoverList2_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *            report route table request  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpReqReportRouteTable2_s
block|{
name|bit8
name|reserved1
index|[
literal|2
index|]
decl_stmt|;
comment|/* byte 4 - 5 */
name|bit8
name|expanderRouteIndex16
index|[
literal|20
index|]
decl_stmt|;
comment|/* byte 6- 7 */
name|bit8
name|reserved2
decl_stmt|;
comment|/* byte 8 */
name|bit8
name|phyIdentifier
decl_stmt|;
comment|/* byte 9 */
name|bit8
name|reserved3
index|[
literal|2
index|]
decl_stmt|;
comment|/* byte 10 -11  */
block|}
name|smpReqReportRouteTable2_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *            report route response  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpRespReportRouteTable2_s
block|{
name|bit16
name|expanderChangeCount
decl_stmt|;
comment|/* byte 4 - 5 */
name|bit16
name|expanderRouteIndex
decl_stmt|;
comment|/* byte 6 - 7 */
name|bit8
name|reserved1
decl_stmt|;
comment|/* byte 8 */
name|bit8
name|phyIdentifier
decl_stmt|;
comment|/* byte 9 */
name|bit8
name|reserved2
index|[
literal|2
index|]
decl_stmt|;
comment|/* byte 10 - 11 */
name|bit8
name|disabledBit_reserved3
decl_stmt|;
comment|/* byte 12 */
comment|/* B7   : Expander Route Entry Disabled */
comment|/* B6-0 : reserved */
name|bit8
name|reserved4
index|[
literal|3
index|]
decl_stmt|;
comment|/* byte 13-15 */
name|bit8
name|routedSasAddressHi
index|[
literal|4
index|]
decl_stmt|;
comment|/* byte 16-19 */
name|bit8
name|routedSasAddressLo
index|[
literal|4
index|]
decl_stmt|;
comment|/* byte 20-23 */
name|bit8
name|reserved5
index|[
literal|16
index|]
decl_stmt|;
comment|/* byte 24-39 */
block|}
name|smpRespReportRouteTable2_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *            configure route information request  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpReqConfigureRouteInformation2_s
block|{
name|bit16
name|expectedExpanderChangeCount
decl_stmt|;
comment|/* byte 4-5 */
name|bit16
name|expanderRouteIndex
decl_stmt|;
comment|/* byte 6-7 */
name|bit8
name|reserved1
decl_stmt|;
comment|/* byte 8 */
name|bit8
name|phyIdentifier
decl_stmt|;
comment|/* byte 9 */
name|bit8
name|reserved2
index|[
literal|2
index|]
decl_stmt|;
comment|/* byte 10-11 */
name|bit8
name|disabledBit_reserved3
decl_stmt|;
comment|/* byte 12 */
comment|/* B7   : Expander Route Entry Disabled */
comment|/* B6-0 : reserved */
name|bit8
name|reserved4
index|[
literal|3
index|]
decl_stmt|;
comment|/* byte 13-15 */
name|bit8
name|routedSasAddressHi
index|[
literal|4
index|]
decl_stmt|;
comment|/* byte 16-19 */
name|bit8
name|routedSasAddressLo
index|[
literal|4
index|]
decl_stmt|;
comment|/* byte 20-23 */
name|bit8
name|reserved5
index|[
literal|16
index|]
decl_stmt|;
comment|/* byte 24-39 */
block|}
name|smpReqConfigureRouteInformation2_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *            configure route response  ****************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FOR_COMPLETENESS
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|smpRespConfigureRouteInformation2_s
block|{
comment|/* nothing. some compiler disallowed structure with no member */
block|}
name|smpRespConfigureRouteInformation2_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/****************************************************************  *            report Phy Sata request  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpReqReportPhySata2_s
block|{
name|bit8
name|reserved1
index|[
literal|5
index|]
decl_stmt|;
comment|/* byte 4-8 */
name|bit8
name|phyIdentifier
decl_stmt|;
comment|/* byte 9 */
name|bit8
name|AffiliationContext
decl_stmt|;
comment|/* byte 10 */
name|bit8
name|reserved2
decl_stmt|;
comment|/* byte 11 */
block|}
name|smpReqReportPhySata2_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *            report Phy Sata response  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpRespReportPhySata2_s
block|{
name|bit16
name|expanderChangeCount
decl_stmt|;
comment|/* byte 4-5 */
name|bit8
name|reserved1
index|[
literal|3
index|]
decl_stmt|;
comment|/* byte 6-8 */
name|bit8
name|phyIdentifier
decl_stmt|;
comment|/* byte 9 */
name|bit8
name|reserved2
decl_stmt|;
comment|/* byte 10 */
name|bit8
name|byte11
decl_stmt|;
comment|/* byte 11 */
comment|/* b7-3 : reserved */
comment|/* b2   : STP I_T Nexus Loss Occurred */
comment|/* b1   : Affiliations supported */
comment|/* b0   : Affiliation valid */
name|bit8
name|reserved3
index|[
literal|4
index|]
decl_stmt|;
comment|/* byte 12-15 */
name|bit8
name|stpSasAddressHi
index|[
literal|4
index|]
decl_stmt|;
comment|/* byte 16-19 */
name|bit8
name|stpSasAddressLo
index|[
literal|4
index|]
decl_stmt|;
comment|/* byte 20-23 */
name|bit8
name|regDevToHostFis
index|[
literal|20
index|]
decl_stmt|;
comment|/* byte 24-43 */
name|bit8
name|reserved4
index|[
literal|4
index|]
decl_stmt|;
comment|/* byte 44-47 */
name|bit8
name|affiliatedStpInitiatorSasAddressHi
index|[
literal|4
index|]
decl_stmt|;
comment|/* byte 48-51 */
name|bit8
name|affiliatedStpInitiatorSasAddressLo
index|[
literal|4
index|]
decl_stmt|;
comment|/* byte 52-55 */
name|bit8
name|STPITNexusLossSASAddressHi
index|[
literal|4
index|]
decl_stmt|;
comment|/* byte 56-59 */
name|bit8
name|STPITNexusLossSASAddressLo
index|[
literal|4
index|]
decl_stmt|;
comment|/* byte 60-63 */
name|bit8
name|reserved5
decl_stmt|;
comment|/* byte 64 */
name|bit8
name|AffiliationContext
decl_stmt|;
comment|/* byte 65 */
name|bit8
name|CurrentAffiliationContexts
decl_stmt|;
comment|/* byte 66 */
name|bit8
name|MaxAffiliationContexts
decl_stmt|;
comment|/* byte 67 */
block|}
name|smpRespReportPhySata2_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *            Phy Control request  ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|smpReqPhyControl2_s
block|{
name|bit16
name|expectedExpanderChangeCount
decl_stmt|;
comment|/* byte 4-5 */
name|bit8
name|reserved1
index|[
literal|3
index|]
decl_stmt|;
comment|/* byte 6-8 */
name|bit8
name|phyIdentifier
decl_stmt|;
comment|/* byte 9 */
name|bit8
name|phyOperation
decl_stmt|;
comment|/* byte 10 */
name|bit8
name|updatePartialPathwayTOValue
decl_stmt|;
comment|/* byte 11 */
comment|/* b7-1 : reserved */
comment|/* b0   : update partial pathway timeout value */
name|bit8
name|reserved2
index|[
literal|12
index|]
decl_stmt|;
comment|/* byte 12-23 */
name|bit8
name|AttachedDeviceName
index|[
literal|8
index|]
decl_stmt|;
comment|/* byte 24-31 */
name|bit8
name|programmedMinPhysicalLinkRate
decl_stmt|;
comment|/* byte 32 */
comment|/* b7-4 : programmed Minimum Physical Link Rate*/
comment|/* b3-0 : reserved */
name|bit8
name|programmedMaxPhysicalLinkRate
decl_stmt|;
comment|/* byte 33 */
comment|/* b7-4 : programmed Maximum Physical Link Rate*/
comment|/* b3-0 : reserved */
name|bit8
name|reserved3
index|[
literal|2
index|]
decl_stmt|;
comment|/* byte 34-35 */
name|bit8
name|partialPathwayTOValue
decl_stmt|;
comment|/* byte 36 */
comment|/* b7-4 : reserved */
comment|/* b3-0 : partial Pathway TO Value */
name|bit8
name|reserved4
index|[
literal|3
index|]
decl_stmt|;
comment|/* byte 37-39 */
block|}
name|smpReqPhyControl2_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************  *            Phy Control response  ****************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FOR_COMPLETENESS
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|smpRespPhyControl2_s
block|{
comment|/* nothing. some compiler disallowed structure with no member */
block|}
name|smpRespPhyControl2_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SMP_REQUEST
value|0x40
end_define

begin_define
define|#
directive|define
name|SMP_RESPONSE
value|0x41
end_define

begin_comment
comment|/* bit8 array[4] -> bit32 */
end_comment

begin_define
define|#
directive|define
name|DM_GET_SAS_ADDRESSLO
parameter_list|(
name|sasAddressLo
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)sasAddressLo)
end_define

begin_define
define|#
directive|define
name|DM_GET_SAS_ADDRESSHI
parameter_list|(
name|sasAddressHi
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)sasAddressHi)
end_define

begin_define
define|#
directive|define
name|DM_GET_LINK_RATE
parameter_list|(
name|input
parameter_list|)
value|(input& 0x0F)
end_define

begin_define
define|#
directive|define
name|DM_SAS_CONNECTION_RATE_1_5G
value|0x08
end_define

begin_define
define|#
directive|define
name|DM_SAS_CONNECTION_RATE_3_0G
value|0x09
end_define

begin_define
define|#
directive|define
name|DM_SAS_CONNECTION_RATE_6_0G
value|0x0A
end_define

begin_define
define|#
directive|define
name|DM_SAS_CONNECTION_RATE_12_0G
value|0x0B
end_define

begin_define
define|#
directive|define
name|DISCOVERY_CONFIGURING_TIMER_VALUE
value|(3 * 1000 * 1000)
end_define

begin_comment
comment|/* 3 seconds */
end_comment

begin_define
define|#
directive|define
name|DISCOVERY_RETRIES
value|3
end_define

begin_define
define|#
directive|define
name|CONFIGURE_ROUTE_TIMER_VALUE
value|(1 * 1000 * 1000)
end_define

begin_comment
comment|/* 1 seconds */
end_comment

begin_define
define|#
directive|define
name|DEVICE_REGISTRATION_TIMER_VALUE
value|(2 * 1000 * 1000)
end_define

begin_comment
comment|/* 2 seconds */
end_comment

begin_define
define|#
directive|define
name|SMP_RETRIES
value|5
end_define

begin_define
define|#
directive|define
name|SMP_BUSY_TIMER_VALUE
value|(1 * 1000 * 1000)
end_define

begin_comment
comment|/* 1 second */
end_comment

begin_define
define|#
directive|define
name|SMP_BUSY_RETRIES
value|5
end_define

begin_define
define|#
directive|define
name|SATA_ID_DEVICE_DATA_TIMER_VALUE
value|(3 * 1000 * 1000)
end_define

begin_comment
comment|/* 3 second */
end_comment

begin_define
define|#
directive|define
name|SATA_ID_DEVICE_DATA_RETRIES
value|3
end_define

begin_define
define|#
directive|define
name|BC_TIMER_VALUE
value|(5 * 1000 * 1000)
end_define

begin_comment
comment|/* 5 second */
end_comment

begin_define
define|#
directive|define
name|SMP_TIMER_VALUE
value|(30 * 1000 * 1000)
end_define

begin_comment
comment|/* 30 second */
end_comment

begin_define
define|#
directive|define
name|STP_DEVICE_TYPE
value|0
end_define

begin_comment
comment|/* SATA behind expander 00*/
end_comment

begin_define
define|#
directive|define
name|SAS_DEVICE_TYPE
value|1
end_define

begin_comment
comment|/* SSP or SMP 01 */
end_comment

begin_define
define|#
directive|define
name|SATA_DEVICE_TYPE
value|2
end_define

begin_comment
comment|/* direct SATA 10 */
end_comment

begin_define
define|#
directive|define
name|ATAPI_DEVICE_FLAG
value|0x200000
end_define

begin_comment
comment|/* ATAPI device flag*/
end_comment

begin_comment
comment|/* ATA device type */
end_comment

begin_define
define|#
directive|define
name|SATA_ATA_DEVICE
value|0x01
end_define

begin_comment
comment|/**< ATA ATA device type */
end_comment

begin_define
define|#
directive|define
name|SATA_ATAPI_DEVICE
value|0x02
end_define

begin_comment
comment|/**< ATA ATAPI device type */
end_comment

begin_define
define|#
directive|define
name|SATA_PM_DEVICE
value|0x03
end_define

begin_comment
comment|/**< ATA PM device type */
end_comment

begin_define
define|#
directive|define
name|SATA_SEMB_DEVICE
value|0x04
end_define

begin_comment
comment|/**< ATA SEMB device type */
end_comment

begin_define
define|#
directive|define
name|SATA_SEMB_WO_SEP_DEVICE
value|0x05
end_define

begin_comment
comment|/**< ATA SEMB without SEP device type */
end_comment

begin_define
define|#
directive|define
name|UNKNOWN_DEVICE
value|0xFF
end_define

begin_comment
comment|/* SAS device type definition. SAS spec(r.7) p206  */
end_comment

begin_define
define|#
directive|define
name|SAS_NO_DEVICE
value|0
end_define

begin_define
define|#
directive|define
name|SAS_END_DEVICE
value|1
end_define

begin_define
define|#
directive|define
name|SAS_EDGE_EXPANDER_DEVICE
value|2
end_define

begin_define
define|#
directive|define
name|SAS_FANOUT_EXPANDER_DEVICE
value|3
end_define

begin_comment
comment|/* routing attributes */
end_comment

begin_define
define|#
directive|define
name|SAS_ROUTING_DIRECT
value|0x00
end_define

begin_define
define|#
directive|define
name|SAS_ROUTING_SUBTRACTIVE
value|0x01
end_define

begin_define
define|#
directive|define
name|SAS_ROUTING_TABLE
value|0x02
end_define

begin_define
define|#
directive|define
name|SAS_CONNECTION_RATE_1_5G
value|0x08
end_define

begin_define
define|#
directive|define
name|SAS_CONNECTION_RATE_3_0G
value|0x09
end_define

begin_define
define|#
directive|define
name|SAS_CONNECTION_RATE_6_0G
value|0x0A
end_define

begin_define
define|#
directive|define
name|SAS_CONNECTION_RATE_12_0G
value|0x0B
end_define

begin_define
define|#
directive|define
name|IT_NEXUS_TIMEOUT
value|0x7D0
end_define

begin_comment
comment|/* 2000 ms; old value was 0xFFFF */
end_comment

begin_comment
comment|/* bit8 array[4] -> bit32 */
end_comment

begin_define
define|#
directive|define
name|DEVINFO_GET_SAS_ADDRESSLO
parameter_list|(
name|devInfo
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)(devInfo)->sasAddressLo)
end_define

begin_define
define|#
directive|define
name|DEVINFO_GET_SAS_ADDRESSHI
parameter_list|(
name|devInfo
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)(devInfo)->sasAddressHi)
end_define

begin_comment
comment|/* this macro is based on SAS spec, not sTSDK 0xC0 */
end_comment

begin_define
define|#
directive|define
name|DEVINFO_GET_DEVICETTYPE
parameter_list|(
name|devInfo
parameter_list|)
define|\
value|(((devInfo)->devType_S_Rate& 0xC0)>> 6)
end_define

begin_define
define|#
directive|define
name|DEVINFO_GET_LINKRATE
parameter_list|(
name|devInfo
parameter_list|)
define|\
value|((devInfo)->devType_S_Rate& 0x0F)
end_define

begin_comment
comment|/**< target device type */
end_comment

begin_define
define|#
directive|define
name|DM_DEFAULT_DEVICE
value|0
end_define

begin_define
define|#
directive|define
name|DM_SAS_DEVICE
value|1
end_define

begin_define
define|#
directive|define
name|DM_SATA_DEVICE
value|2
end_define

begin_define
define|#
directive|define
name|DEVICE_SSP_BIT
value|0x8
end_define

begin_comment
comment|/* SSP Initiator port */
end_comment

begin_define
define|#
directive|define
name|DEVICE_STP_BIT
value|0x4
end_define

begin_comment
comment|/* STP Initiator port */
end_comment

begin_define
define|#
directive|define
name|DEVICE_SMP_BIT
value|0x2
end_define

begin_comment
comment|/* SMP Initiator port */
end_comment

begin_define
define|#
directive|define
name|DEVICE_SATA_BIT
value|0x1
end_define

begin_comment
comment|/* SATA device, valid in the discovery response only */
end_comment

begin_define
define|#
directive|define
name|DEVICE_IS_SSP_INITIATOR
parameter_list|(
name|DeviceData
parameter_list|)
define|\
value|(((DeviceData)->initiator_ssp_stp_smp& DEVICE_SSP_BIT) == DEVICE_SSP_BIT)
end_define

begin_define
define|#
directive|define
name|DEVICE_IS_STP_INITIATOR
parameter_list|(
name|DeviceData
parameter_list|)
define|\
value|(((DeviceData)->initiator_ssp_stp_smp& DEVICE_STP_BIT) == DEVICE_STP_BIT)
end_define

begin_define
define|#
directive|define
name|DEVICE_IS_SMP_INITIATOR
parameter_list|(
name|DeviceData
parameter_list|)
define|\
value|(((DeviceData)->initiator_ssp_stp_smp& DEVICE_SMP_BIT) == DEVICE_SMP_BIT)
end_define

begin_define
define|#
directive|define
name|DEVICE_IS_SSP_TARGET
parameter_list|(
name|DeviceData
parameter_list|)
define|\
value|(((DeviceData)->target_ssp_stp_smp& DEVICE_SSP_BIT) == DEVICE_SSP_BIT)
end_define

begin_define
define|#
directive|define
name|DEVICE_IS_STP_TARGET
parameter_list|(
name|DeviceData
parameter_list|)
define|\
value|(((DeviceData)->target_ssp_stp_smp& DEVICE_STP_BIT) == DEVICE_STP_BIT)
end_define

begin_define
define|#
directive|define
name|DEVICE_IS_SMP_TARGET
parameter_list|(
name|DeviceData
parameter_list|)
define|\
value|(((DeviceData)->target_ssp_stp_smp& DEVICE_SMP_BIT) == DEVICE_SMP_BIT)
end_define

begin_define
define|#
directive|define
name|DEVICE_IS_SATA_DEVICE
parameter_list|(
name|DeviceData
parameter_list|)
define|\
value|(((DeviceData)->target_ssp_stp_smp& DEVICE_SATA_BIT) == DEVICE_SATA_BIT)
end_define

begin_comment
comment|/* bit8 array[4] -> bit32 */
end_comment

begin_define
define|#
directive|define
name|DEVINFO_GET_SAS_ADDRESSLO
parameter_list|(
name|devInfo
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)(devInfo)->sasAddressLo)
end_define

begin_define
define|#
directive|define
name|DEVINFO_GET_SAS_ADDRESSHI
parameter_list|(
name|devInfo
parameter_list|)
define|\
value|DMA_BEBIT32_TO_BIT32(*(bit32 *)(devInfo)->sasAddressHi)
end_define

begin_comment
comment|/* this macro is based on SAS spec, not sTSDK 0xC0 */
end_comment

begin_define
define|#
directive|define
name|DEVINFO_GET_DEVICETTYPE
parameter_list|(
name|devInfo
parameter_list|)
define|\
value|(((devInfo)->devType_S_Rate& 0xC0)>> 6)
end_define

begin_define
define|#
directive|define
name|DEVINFO_GET_LINKRATE
parameter_list|(
name|devInfo
parameter_list|)
define|\
value|((devInfo)->devType_S_Rate& 0x0F)
end_define

begin_define
define|#
directive|define
name|DEVINFO_GET_EXT_SMP
parameter_list|(
name|devInfo
parameter_list|)
define|\
value|(((devInfo)->ext& 0x100)>> 8)
end_define

begin_define
define|#
directive|define
name|DEVINFO_GET_EXT_EXPANDER_TYPE
parameter_list|(
name|devInfo
parameter_list|)
define|\
value|(((devInfo)->ext& 0x600)>> 9)
end_define

begin_define
define|#
directive|define
name|DEVINFO_GET_EXT_MCN
parameter_list|(
name|devInfo
parameter_list|)
define|\
value|(((devInfo)->ext& 0x7800)>> 11)
end_define

begin_define
define|#
directive|define
name|DEVINFO_PUT_SMPTO
parameter_list|(
name|devInfo
parameter_list|,
name|smpto
parameter_list|)
define|\
value|((devInfo)->smpTimeout) = smpto
end_define

begin_define
define|#
directive|define
name|DEVINFO_PUT_ITNEXUSTO
parameter_list|(
name|devInfo
parameter_list|,
name|itnexusto
parameter_list|)
define|\
value|((devInfo)->it_NexusTimeout) = itnexusto
end_define

begin_define
define|#
directive|define
name|DEVINFO_PUT_FBS
parameter_list|(
name|devInfo
parameter_list|,
name|fbs
parameter_list|)
define|\
value|((devInfo)->firstBurstSize) = fbs
end_define

begin_define
define|#
directive|define
name|DEVINFO_PUT_FLAG
parameter_list|(
name|devInfo
parameter_list|,
name|tlr
parameter_list|)
define|\
value|((devInfo)->flag) = tlr
end_define

begin_define
define|#
directive|define
name|DEVINFO_PUT_DEV_S_RATE
parameter_list|(
name|devInfo
parameter_list|,
name|dev_s_rate
parameter_list|)
define|\
value|((devInfo)->devType_S_Rate) = dev_s_rate
end_define

begin_comment
comment|/* bit32 -> bit8 array[4] */
end_comment

begin_define
define|#
directive|define
name|DEVINFO_PUT_SAS_ADDRESSLO
parameter_list|(
name|devInfo
parameter_list|,
name|src32
parameter_list|)
define|\
value|*(bit32 *)((devInfo)->sasAddressLo) = BIT32_TO_DMA_BEBIT32(src32)
end_define

begin_define
define|#
directive|define
name|DEVINFO_PUT_SAS_ADDRESSHI
parameter_list|(
name|devInfo
parameter_list|,
name|src32
parameter_list|)
define|\
value|*(bit32 *)((devInfo)->sasAddressHi) = BIT32_TO_DMA_BEBIT32(src32)
end_define

begin_define
define|#
directive|define
name|DEVINFO_PUT_INITIATOR_SSP_STP_SMP
parameter_list|(
name|devInfo
parameter_list|,
name|ini_ssp_stp_smp
parameter_list|)
define|\
value|((devInfo)->initiator_ssp_stp_smp) = ini_ssp_stp_smp
end_define

begin_define
define|#
directive|define
name|DEVINFO_PUT_TARGET_SSP_STP_SMP
parameter_list|(
name|devInfo
parameter_list|,
name|tgt_ssp_stp_smp
parameter_list|)
define|\
value|((devInfo)->target_ssp_stp_smp) = tgt_ssp_stp_smp
end_define

begin_define
define|#
directive|define
name|DEVINFO_PUT_EXT
parameter_list|(
name|devInfo
parameter_list|,
name|extension
parameter_list|)
define|\
value|((devInfo)->ext) = extension
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DMDEFS_H__ */
end_comment

end_unit

