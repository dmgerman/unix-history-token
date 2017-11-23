begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************************* SPDX-License-Identifier: BSD-3-Clause  Copyright (c) 2003-2007  Cavium Networks (support@cavium.com). All rights reserved.   Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      * Redistributions of source code must retain the above copyright       notice, this list of conditions and the following disclaimer.      * Redistributions in binary form must reproduce the above       copyright notice, this list of conditions and the following       disclaimer in the documentation and/or other materials provided       with the distribution.      * Neither the name of Cavium Networks nor the names of       its contributors may be used to endorse or promote products       derived from this software without specific prior written       permission.  This Software, including technical data, may be subject to U.S. export  control laws, including the U.S. Export Administration Act and its  associated regulations, and may be subject to export or import  regulations in other countries.  TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS AND CAVIUM  NETWORKS MAKES NO PROMISES, REPRESENTATIONS OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  *************************************************************************/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * A few defines are used to control the operation of this driver:  *  CONFIG_CAVIUM_OCTEON_NUM_PACKET_BUFFERS  *      This kernel config option allows the user to control the number of  *      packet and work queue buffers allocated by the driver. If this is zero,  *      the driver uses the default from below.  */
end_comment

begin_define
define|#
directive|define
name|INTERRUPT_LIMIT
value|10000
end_define

begin_comment
comment|/* Max interrupts per second per core */
end_comment

begin_comment
comment|/*#define INTERRUPT_LIMIT             0     */
end_comment

begin_comment
comment|/* Don't limit the number of interrupts */
end_comment

begin_define
define|#
directive|define
name|USE_RED
value|1
end_define

begin_comment
comment|/* Enable Random Early Dropping under load */
end_comment

begin_define
define|#
directive|define
name|USE_10MBPS_PREAMBLE_WORKAROUND
value|1
end_define

begin_comment
comment|/* Allow SW based preamble removal at 10Mbps to workaround PHYs giving us bad preambles */
end_comment

begin_define
define|#
directive|define
name|DONT_WRITEBACK
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_comment
comment|/* Use this to have all FPA frees also tell the L2 not to write data to memory */
end_comment

begin_comment
comment|/*#define DONT_WRITEBACK(x)         0   */
end_comment

begin_comment
comment|/* Use this to not have FPA frees control L2 */
end_comment

begin_define
define|#
directive|define
name|MAX_RX_PACKETS
value|120
end_define

begin_comment
comment|/* Maximum number of packets to process per interrupt. */
end_comment

begin_define
define|#
directive|define
name|MAX_OUT_QUEUE_DEPTH
value|1000
end_define

begin_define
define|#
directive|define
name|FAU_NUM_PACKET_BUFFERS_TO_FREE
value|(CVMX_FAU_REG_END - sizeof(uint32_t))
end_define

begin_define
define|#
directive|define
name|TOTAL_NUMBER_OF_PORTS
value|(CVMX_PIP_NUM_INPUT_PORTS+1)
end_define

end_unit

