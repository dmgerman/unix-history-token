begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Validate defines required by cvmx-helper. This header file  * validates a number of defines required for cvmx-helper to  * function properly. It either supplies a default or fails  * compile if a define is incorrect.  *  *<hr>$Revision: 70030 $<hr>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_HELPER_CHECK_DEFINES_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_HELPER_CHECK_DEFINES_H__
end_define

begin_comment
comment|/* CVMX_HELPER_FIRST_MBUFF_SKIP is the number of bytes to reserve before     the beginning of the packet. Override in executive-config.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CVMX_HELPER_FIRST_MBUFF_SKIP
end_ifndef

begin_define
define|#
directive|define
name|CVMX_HELPER_FIRST_MBUFF_SKIP
value|184
end_define

begin_warning
warning|#
directive|warning
warning|WARNING: default CVMX_HELPER_FIRST_MBUFF_SKIP used.  Defaults deprecated, please set in executive-config.h
end_warning

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CVMX_HELPER_NOT_FIRST_MBUFF_SKIP is the number of bytes to reserve in each     chained packet element. Override in executive-config.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CVMX_HELPER_NOT_FIRST_MBUFF_SKIP
end_ifndef

begin_define
define|#
directive|define
name|CVMX_HELPER_NOT_FIRST_MBUFF_SKIP
value|0
end_define

begin_warning
warning|#
directive|warning
warning|WARNING: default CVMX_HELPER_NOT_FIRST_MBUFF_SKIP used.  Defaults deprecated, please set in executive-config.h
end_warning

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CVMX_HELPER_ENABLE_IPD controls if the IPD is enabled in the helper     function. Once it is enabled the hardware starts accepting packets. You     might want to skip the IPD enable if configuration changes are need     from the default helper setup. Override in executive-config.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CVMX_HELPER_ENABLE_IPD
end_ifndef

begin_define
define|#
directive|define
name|CVMX_HELPER_ENABLE_IPD
value|1
end_define

begin_warning
warning|#
directive|warning
warning|WARNING: default CVMX_HELPER_ENABLE_IPD used.  Defaults deprecated, please set in executive-config.h
end_warning

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Set default (defaults are deprecated) input tag type */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CVMX_HELPER_INPUT_TAG_TYPE
end_ifndef

begin_define
define|#
directive|define
name|CVMX_HELPER_INPUT_TAG_TYPE
value|CVMX_POW_TAG_TYPE_ORDERED
end_define

begin_warning
warning|#
directive|warning
warning|WARNING: default CVMX_HELPER_INPUT_TAG_TYPE used.  Defaults deprecated, please set in executive-config.h
end_warning

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CVMX_HELPER_INPUT_PORT_SKIP_MODE
end_ifndef

begin_define
define|#
directive|define
name|CVMX_HELPER_INPUT_PORT_SKIP_MODE
value|CVMX_PIP_PORT_CFG_MODE_SKIPL2
end_define

begin_warning
warning|#
directive|warning
warning|WARNING: default CVMX_HELPER_INPUT_PORT_SKIP_MODE used.  Defaults deprecated, please set in executive-config.h
end_warning

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CVMX_ENABLE_HELPER_FUNCTIONS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CVMX_HELPER_INPUT_TAG_INPUT_PORT
argument_list|)
end_if

begin_error
error|#
directive|error
error|CVMX_HELPER_INPUT_TAG_* values for determining tag hash inputs must be defined in executive-config.h
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

