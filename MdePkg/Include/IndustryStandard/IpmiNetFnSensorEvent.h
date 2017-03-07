begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   IPMI 2.0 definitions from the IPMI Specification Version 2.0, Revision 1.1.    This file contains all NetFn Sensor/Event commands, including:     Event Commands (Chapter 29)     PEF and Alerting Commands (Chapter 30)     Sensor Device Commands (Chapter 35)    See IPMI specification, Appendix G, Command Assignments   and Appendix H, Sub-function Assignments.    Copyright (c) 1999 - 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED. **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IPMI_NET_FN_SENSOR_EVENT_H_
end_ifndef

begin_define
define|#
directive|define
name|_IPMI_NET_FN_SENSOR_EVENT_H_
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
comment|//
end_comment

begin_comment
comment|// Net function definition for Sensor command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_NETFN_SENSOR_EVENT
value|0x04
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// All Sensor commands and their structure definitions to follow here
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Definitions for Send Platform Event Message command
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IPMI_SENSOR_PLATFORM_EVENT_MESSAGE
value|0x02
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|GeneratorId
decl_stmt|;
name|UINT8
name|EvMRevision
decl_stmt|;
name|UINT8
name|SensorType
decl_stmt|;
name|UINT8
name|SensorNumber
decl_stmt|;
name|UINT8
name|EventDirType
decl_stmt|;
name|UINT8
name|OEMEvData1
decl_stmt|;
name|UINT8
name|OEMEvData2
decl_stmt|;
name|UINT8
name|OEMEvData3
decl_stmt|;
block|}
name|IPMI_PLATFORM_EVENT_MESSAGE_DATA_REQUEST
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

end_unit

