begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2012  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * cvmx-tra-defs.h  *  * Configuration and status register (CSR) type definitions for  * Octeon tra.  *  * This file is auto generated. Do not edit.  *  *<hr>$Revision$<hr>  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_TRA_TYPEDEFS_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_TRA_TYPEDEFS_H__
end_define

begin_include
include|#
directive|include
file|"cvmx-trax-defs.h"
end_include

begin_define
define|#
directive|define
name|CVMX_TRA_BIST_STATUS
value|(CVMX_TRAX_BIST_STATUS(0))
end_define

begin_define
define|#
directive|define
name|CVMX_TRA_CTL
value|(CVMX_TRAX_CTL(0))
end_define

begin_define
define|#
directive|define
name|CVMX_TRA_CYCLES_SINCE
value|(CVMX_TRAX_CYCLES_SINCE(0))
end_define

begin_define
define|#
directive|define
name|CVMX_TRA_CYCLES_SINCE1
value|(CVMX_TRAX_CYCLES_SINCE1(0))
end_define

begin_define
define|#
directive|define
name|CVMX_TRA_FILT_ADR_ADR
value|(CVMX_TRAX_FILT_ADR_ADR(0))
end_define

begin_define
define|#
directive|define
name|CVMX_TRA_FILT_ADR_MSK
value|(CVMX_TRAX_FILT_ADR_MSK(0))
end_define

begin_define
define|#
directive|define
name|CVMX_TRA_FILT_CMD
value|(CVMX_TRAX_FILT_CMD(0))
end_define

begin_define
define|#
directive|define
name|CVMX_TRA_FILT_DID
value|(CVMX_TRAX_FILT_DID(0))
end_define

begin_define
define|#
directive|define
name|CVMX_TRA_FILT_SID
value|(CVMX_TRAX_FILT_SID(0))
end_define

begin_define
define|#
directive|define
name|CVMX_TRA_INT_STATUS
value|(CVMX_TRAX_INT_STATUS(0))
end_define

begin_define
define|#
directive|define
name|CVMX_TRA_READ_DAT
value|(CVMX_TRAX_READ_DAT(0))
end_define

begin_define
define|#
directive|define
name|CVMX_TRA_READ_DAT_HI
value|(CVMX_TRAX_READ_DAT_HI(0))
end_define

begin_define
define|#
directive|define
name|CVMX_TRA_TRIG0_ADR_ADR
value|(CVMX_TRAX_TRIG0_ADR_ADR(0))
end_define

begin_define
define|#
directive|define
name|CVMX_TRA_TRIG0_ADR_MSK
value|(CVMX_TRAX_TRIG0_ADR_MSK(0))
end_define

begin_define
define|#
directive|define
name|CVMX_TRA_TRIG0_CMD
value|(CVMX_TRAX_TRIG0_CMD(0))
end_define

begin_define
define|#
directive|define
name|CVMX_TRA_TRIG0_DID
value|(CVMX_TRAX_TRIG0_DID(0))
end_define

begin_define
define|#
directive|define
name|CVMX_TRA_TRIG0_SID
value|(CVMX_TRAX_TRIG0_SID(0))
end_define

begin_define
define|#
directive|define
name|CVMX_TRA_TRIG1_ADR_ADR
value|(CVMX_TRAX_TRIG1_ADR_ADR(0))
end_define

begin_define
define|#
directive|define
name|CVMX_TRA_TRIG1_ADR_MSK
value|(CVMX_TRAX_TRIG1_ADR_MSK(0))
end_define

begin_define
define|#
directive|define
name|CVMX_TRA_TRIG1_CMD
value|(CVMX_TRAX_TRIG1_CMD(0))
end_define

begin_define
define|#
directive|define
name|CVMX_TRA_TRIG1_DID
value|(CVMX_TRAX_TRIG1_DID(0))
end_define

begin_define
define|#
directive|define
name|CVMX_TRA_TRIG1_SID
value|(CVMX_TRAX_TRIG1_SID(0))
end_define

begin_typedef
typedef|typedef
name|union
name|cvmx_trax_bist_status
name|cvmx_tra_bist_status_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|cvmx_trax_ctl
name|cvmx_tra_ctl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|cvmx_trax_cycles_since
name|cvmx_tra_cycles_since_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|cvmx_trax_cycles_since1
name|cvmx_tra_cycles_since1_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|cvmx_trax_filt_adr_adr
name|cvmx_tra_filt_adr_adr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|cvmx_trax_filt_adr_msk
name|cvmx_tra_filt_adr_msk_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|cvmx_trax_filt_cmd
name|cvmx_tra_filt_cmd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|cvmx_trax_filt_did
name|cvmx_tra_filt_did_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|cvmx_trax_filt_sid
name|cvmx_tra_filt_sid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|cvmx_trax_int_status
name|cvmx_tra_int_status_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|cvmx_trax_read_dat
name|cvmx_tra_read_dat_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|cvmx_trax_read_dat_hi
name|cvmx_tra_read_dat_hi_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|cvmx_trax_trig0_adr_adr
name|cvmx_tra_trig0_adr_adr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|cvmx_trax_trig0_adr_msk
name|cvmx_tra_trig0_adr_msk_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|cvmx_trax_trig0_cmd
name|cvmx_tra_trig0_cmd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|cvmx_trax_trig0_did
name|cvmx_tra_trig0_did_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|cvmx_trax_trig0_sid
name|cvmx_tra_trig0_sid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|cvmx_trax_trig1_adr_adr
name|cvmx_tra_trig1_adr_adr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|cvmx_trax_trig1_adr_msk
name|cvmx_tra_trig1_adr_msk_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|cvmx_trax_trig1_cmd
name|cvmx_tra_trig1_cmd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|cvmx_trax_trig1_did
name|cvmx_tra_trig1_did_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|cvmx_trax_trig1_sid
name|cvmx_tra_trig1_sid_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

