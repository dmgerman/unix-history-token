begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  *  Copyright (c) 2003-2008 Cavium Networks (support@cavium.com). All rights  *  reserved.  *  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions are  *  met:  *  *      * Redistributions of source code must retain the above copyright  *        notice, this list of conditions and the following disclaimer.  *  *      * Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials provided  *        with the distribution.  *  *      * Neither the name of Cavium Networks nor the names of  *        its contributors may be used to endorse or promote products  *        derived from this software without specific prior written  *        permission.  *  *  TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  *  AND WITH ALL FAULTS AND CAVIUM NETWORKS MAKES NO PROMISES, REPRESENTATIONS  *  OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH  *  RESPECT TO THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY  *  REPRESENTATION OR DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT  *  DEFECTS, AND CAVIUM SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES  *  OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR  *  PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET  *  POSSESSION OR CORRESPONDENCE TO DESCRIPTION.  THE ENTIRE RISK ARISING OUT  *  OF USE OR PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  *  *  *  For any questions regarding licensing please contact marketing@caviumnetworks.com  *  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * This file is resposible for including all system dependent  * headers for the cvmx-* files.  *  *<hr>$Revision: 41586 $<hr> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_PLATFORM_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_PLATFORM_H__
end_define

begin_include
include|#
directive|include
file|"cvmx-abi.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|EXTERN_ASM
value|extern "C"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXTERN_ASM
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This file defines macros for use in determining the current     building environment. It defines a single CVMX_BUILD_FOR_*     macro representing the target of the build. The current     possibilities are:         CVMX_BUILD_FOR_UBOOT         CVMX_BUILD_FOR_LINUX_KERNEL         CVMX_BUILD_FOR_LINUX_USER         CVMX_BUILD_FOR_LINUX_HOST         CVMX_BUILD_FOR_VXWORKS         CVMX_BUILD_FOR_STANDALONE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__U_BOOT__
argument_list|)
end_if

begin_comment
comment|/* We are being used inside of Uboot */
end_comment

begin_define
define|#
directive|define
name|CVMX_BUILD_FOR_UBOOT
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__linux__
argument_list|)
end_elif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__KERNEL__
argument_list|)
end_if

begin_comment
comment|/* We are in the Linux kernel on Octeon */
end_comment

begin_define
define|#
directive|define
name|CVMX_BUILD_FOR_LINUX_KERNEL
end_define

begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|__mips__
argument_list|)
end_elif

begin_comment
comment|/* We are being used under Linux but not on Octeon. Assume             we are on a Linux host with an Octeon target over PCI/PCIe */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CVMX_BUILD_FOR_LINUX_HOST
end_ifndef

begin_define
define|#
directive|define
name|CVMX_BUILD_FOR_LINUX_HOST
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|CVMX_BUILD_FOR_LINUX_HOST
end_ifdef

begin_comment
comment|/* This is a manual special case. The host PCI utilities can                 be configured to run on Octeon. In this case it is impossible                 to tell the difference between the normal userspace setup                 and using cvmx_read/write_csr over the PCI bus. The host                 utilites force this define to fix this */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* We are in the Linux userspace on Octeon */
end_comment

begin_define
define|#
directive|define
name|CVMX_BUILD_FOR_LINUX_USER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_WRS_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|VXWORKS_USER_MAPPINGS
argument_list|)
end_elif

begin_comment
comment|/* We are in VxWorks on Octeon */
end_comment

begin_define
define|#
directive|define
name|CVMX_BUILD_FOR_VXWORKS
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_OCTEON_TOOLCHAIN_RUNTIME
argument_list|)
end_elif

begin_comment
comment|/* To build the simple exec toolchain runtime (newlib) library. We        should only use features available on all Octeon models.  */
end_comment

begin_define
define|#
directive|define
name|CVMX_BUILD_FOR_TOOLCHAIN
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_elif

begin_define
define|#
directive|define
name|CVMX_BUILD_FOR_FREEBSD
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* We are building a simple exec standalone image for Octeon */
end_comment

begin_define
define|#
directive|define
name|CVMX_BUILD_FOR_STANDALONE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* To have a global variable be shared among all cores,  * declare with the CVMX_SHARED attribute.  Ex:  * CVMX_SHARED int myglobal;  * This will cause the variable to be placed in a special  * section that the loader will map as shared for all cores  * This is for data structures use by software ONLY,  * as it is not 1-1 VA-PA mapped.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CVMX_BUILD_FOR_FREEBSD
argument_list|)
end_if

begin_define
define|#
directive|define
name|CVMX_SHARED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CVMX_SHARED
value|__attribute__ ((cvmx_shared))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CVMX_BUILD_FOR_UBOOT
argument_list|)
end_if

begin_include
include|#
directive|include
file|<common.h>
end_include

begin_include
include|#
directive|include
file|"cvmx-sysinfo.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|CVMX_BUILD_FOR_LINUX_KERNEL
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<linux/kernel.h>
end_include

begin_include
include|#
directive|include
file|<linux/string.h>
end_include

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|CVMX_BUILD_FOR_LINUX_USER
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|CVMX_BUILD_FOR_LINUX_HOST
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|CVMX_BUILD_FOR_VXWORKS
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|CVMX_BUILD_FOR_STANDALONE
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|CVMX_BUILD_FOR_TOOLCHAIN
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|CVMX_BUILD_FOR_FREEBSD
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<mips/cavium/cvmx_config.h>
end_include

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|Unexpected CVMX_BUILD_FOR_* macro
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CVMX_PLATFORM_H__ */
end_comment

end_unit

