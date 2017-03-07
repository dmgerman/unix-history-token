begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   IPMI 2.0 definitions from the IPMI Specification Version 2.0, Revision 1.1.    See IPMI specification, Appendix G, Command Assignments   and Appendix H, Sub-function Assignments.    Copyright (c) 1999 - 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED. **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IPMI_H_
end_ifndef

begin_define
define|#
directive|define
name|_IPMI_H_
end_define

begin_include
include|#
directive|include
file|<IndustryStandard/IpmiNetFnChassis.h>
end_include

begin_include
include|#
directive|include
file|<IndustryStandard/IpmiNetFnBridge.h>
end_include

begin_include
include|#
directive|include
file|<IndustryStandard/IpmiNetFnSensorEvent.h>
end_include

begin_include
include|#
directive|include
file|<IndustryStandard/IpmiNetFnApp.h>
end_include

begin_include
include|#
directive|include
file|<IndustryStandard/IpmiNetFnFirmware.h>
end_include

begin_include
include|#
directive|include
file|<IndustryStandard/IpmiNetFnStorage.h>
end_include

begin_include
include|#
directive|include
file|<IndustryStandard/IpmiNetFnTransport.h>
end_include

begin_include
include|#
directive|include
file|<IndustryStandard/IpmiNetFnGroupExtension.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

