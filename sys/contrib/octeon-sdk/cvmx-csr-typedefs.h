begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2012  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Configuration and status register (CSR) address and type definitions for  * Octeon. Include cvmx-csr.h instead of this file directly.  *  * This file is auto generated. Do not edit.  *  *<hr>$Revision: 69515 $<hr>  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_CSR_TYPEDEFS_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_CSR_TYPEDEFS_H__
end_define

begin_include
include|#
directive|include
file|"cvmx-agl-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-asxx-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-asx0-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-ciu2-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-ciu-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-dbg-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-dfa-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-dfm-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-dpi-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-endor-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-eoi-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-fpa-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-gmxx-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-gpio-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-ilk-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-iob1-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-iob-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-ipd-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-key-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-l2c-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-l2d-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-l2t-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-led-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-lmcx-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-mio-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-mixx-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-mpi-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-ndf-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-npei-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-npi-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-pci-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-pcieepx-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-pciercx-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-pcmx-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-pcm-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-pcsx-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-pcsxx-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-pemx-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-pescx-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-pip-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-pko-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-pow-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-rad-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-rnm-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-sli-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-smix-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-smi-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-spxx-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-spx0-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-sriox-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-sriomaintx-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-srxx-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-sso-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-stxx-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-tim-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-trax-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-uahcx-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-uctlx-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-usbcx-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-usbnx-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-zip-defs.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-pexp-defs.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CVMX_CSR_TYPEDEFS_H__ */
end_comment

end_unit

