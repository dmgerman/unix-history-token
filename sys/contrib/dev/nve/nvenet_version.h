begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************** \ |*                                                                 *| |*                                                                 *| |*  (c) NVIDIA Corporation. All rights reserved                    *|  |*                                                                 *| |*  THE INFORMATION CONTAINED HEREIN IS PROPRIETARY AND            *| |*  CONFIDENTIAL                                                   *| |*  TO NVIDIA, CORPORATION. USE, REPORDUCTION OR DISCLOSURE TO ANY *| |*  THIRD PARTY IS SUBJECT TO WRITTEN PRE-APPROVAL BY NVIDIA CORP. *| |*                                                                 *| |*  THE INFORMATION CONTAINED HEREIN IS PROVIDED "AS IS" WITHOUT   *| |*  EXPRESS OR IMPLIED WARRANTY OF ANY KIND, INCLUDING ALL IMPLIED *| |*  WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS    *| |*  FOR A PARTICULAR PURPOSE.                                      *| |*                                                                 *| ********************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NVENET_VERSION_H__
end_ifndef

begin_define
define|#
directive|define
name|__NVENET_VERSION_H__
end_define

begin_define
define|#
directive|define
name|DRIVER_VERSION_MAJOR
value|"1"
end_define

begin_define
define|#
directive|define
name|DRIVER_VERSION_MINOR
value|"0"
end_define

begin_define
define|#
directive|define
name|DRIVER_VERSION_PATCH
value|"13"
end_define

begin_define
define|#
directive|define
name|DRIVER_VERSION
value|DRIVER_VERSION_MAJOR"."\                                     DRIVER_VERSION_MINOR"-"\                                     DRIVER_VERSION_PATCH
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

