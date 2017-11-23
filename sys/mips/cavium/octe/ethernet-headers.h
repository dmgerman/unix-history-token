begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************************* SPDX-License-Identifier: BSD-3-Clause  Copyright (c) 2003-2007  Cavium Networks (support@cavium.com). All rights reserved.   Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      * Redistributions of source code must retain the above copyright       notice, this list of conditions and the following disclaimer.      * Redistributions in binary form must reproduce the above       copyright notice, this list of conditions and the following       disclaimer in the documentation and/or other materials provided       with the distribution.      * Neither the name of Cavium Networks nor the names of       its contributors may be used to endorse or promote products       derived from this software without specific prior written       permission.  This Software, including technical data, may be subject to U.S. export  control laws, including the U.S. Export Administration Act and its  associated regulations, and may be subject to export or import  regulations in other countries.  TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS AND CAVIUM  NETWORKS MAKES NO PROMISES, REPRESENTATIONS OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  *************************************************************************/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ETHERNET_HEADERS_H__
end_ifndef

begin_define
define|#
directive|define
name|__ETHERNET_HEADERS_H__
end_define

begin_include
include|#
directive|include
file|"cavium-ethernet.h"
end_include

begin_include
include|#
directive|include
file|"ethernet-common.h"
end_include

begin_include
include|#
directive|include
file|"ethernet-defines.h"
end_include

begin_include
include|#
directive|include
file|"ethernet-mdio.h"
end_include

begin_include
include|#
directive|include
file|"ethernet-mem.h"
end_include

begin_include
include|#
directive|include
file|"ethernet-rx.h"
end_include

begin_include
include|#
directive|include
file|"ethernet-tx.h"
end_include

begin_include
include|#
directive|include
file|"ethernet-util.h"
end_include

begin_comment
comment|/*  * Any board- or vendor-specific includes.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OCTEON_VENDOR_LANNER
end_ifdef

begin_include
include|#
directive|include
file|"ethernet-mv88e61xx.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

