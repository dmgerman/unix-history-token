begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Interface to the GMX hardware.  *  *<hr>$Revision: 70030 $<hr>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_GMX_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_GMX_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* CSR typedefs have been moved to cvmx-gmx-defs.h */
comment|/**  * Disables the sending of flow control (pause) frames on the specified  * RGMII port(s).  *  * @param interface Which interface (0 or 1)  * @param port_mask Mask (4bits) of which ports on the interface to disable  *                  backpressure on.  *                  1 => disable backpressure  *                  0 => enable backpressure  *  * @return 0 on success  *         -1 on error  */
specifier|static
specifier|inline
name|int
name|cvmx_gmx_set_backpressure_override
parameter_list|(
name|uint32_t
name|interface
parameter_list|,
name|uint32_t
name|port_mask
parameter_list|)
block|{
name|cvmx_gmxx_tx_ovr_bp_t
name|gmxx_tx_ovr_bp
decl_stmt|;
comment|/* Check for valid arguments */
if|if
condition|(
name|port_mask
operator|&
operator|~
literal|0xf
operator|||
name|interface
operator|&
operator|~
literal|0x1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|gmxx_tx_ovr_bp
operator|.
name|u64
operator|=
literal|0
expr_stmt|;
name|gmxx_tx_ovr_bp
operator|.
name|s
operator|.
name|en
operator|=
name|port_mask
expr_stmt|;
comment|/* Per port Enable back pressure override */
name|gmxx_tx_ovr_bp
operator|.
name|s
operator|.
name|ign_full
operator|=
name|port_mask
expr_stmt|;
comment|/* Ignore the RX FIFO full when computing BP */
name|cvmx_write_csr
argument_list|(
name|CVMX_GMXX_TX_OVR_BP
argument_list|(
name|interface
argument_list|)
argument_list|,
name|gmxx_tx_ovr_bp
operator|.
name|u64
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

