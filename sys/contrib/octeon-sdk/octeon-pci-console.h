begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__OCTEON_PCI_CONSOLE_H__
end_ifndef

begin_define
define|#
directive|define
name|__OCTEON_PCI_CONSOLE_H__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CVMX_BUILD_FOR_LINUX_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|"cvmx-platform.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Current versions */
end_comment

begin_define
define|#
directive|define
name|OCTEON_PCI_CONSOLE_MAJOR_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|OCTEON_PCI_CONSOLE_MINOR_VERSION
value|0
end_define

begin_define
define|#
directive|define
name|OCTEON_PCI_CONSOLE_BLOCK_NAME
value|"__pci_console"
end_define

begin_comment
comment|/* Structure that defines a single console.   * Note: when read_index == write_index, the buffer is empty.  The actual usable size *       of each console is console_buf_size -1; */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint64_t
name|input_base_addr
decl_stmt|;
name|uint32_t
name|input_read_index
decl_stmt|;
name|uint32_t
name|input_write_index
decl_stmt|;
name|uint64_t
name|output_base_addr
decl_stmt|;
name|uint32_t
name|output_read_index
decl_stmt|;
name|uint32_t
name|output_write_index
decl_stmt|;
name|uint32_t
name|lock
decl_stmt|;
name|uint32_t
name|buf_size
decl_stmt|;
block|}
name|octeon_pci_console_t
typedef|;
end_typedef

begin_comment
comment|/* This is the main container structure that contains all the information about all PCI consoles.  The address of this structure is passed to various routines that operation on PCI consoles. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|major_version
decl_stmt|;
name|uint32_t
name|minor_version
decl_stmt|;
name|uint32_t
name|lock
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|num_consoles
decl_stmt|;
name|uint32_t
name|pad
decl_stmt|;
comment|/* must be 64 bit aligned here... */
name|uint64_t
name|console_addr_array
index|[
literal|0
index|]
decl_stmt|;
comment|/* Array of addresses of octeon_pci_console_t structures */
comment|/* Implicit storage for console_addr_array */
block|}
name|octeon_pci_console_desc_t
typedef|;
end_typedef

begin_comment
comment|/* Flag definitions for octeon_pci_console_desc_t */
end_comment

begin_enum
enum|enum
block|{
name|OCT_PCI_CON_DESC_FLAG_PERCPU
init|=
literal|1
operator|<<
literal|0
block|,
comment|/* If set, output from core N will be sent to console N */
block|}
enum|;
end_enum

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OCTEON_TARGET
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__linux__
argument_list|)
end_if

begin_comment
comment|/**  * This is an internal-only function that is called from within the simple executive  * C library, and is not intended for any other use.  *  * @param fd  * @param buf  * @param nbytes  *  * @return  */
end_comment

begin_function_decl
name|int
name|__cvmx_pci_console_write
parameter_list|(
name|int
name|fd
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CVMX_BUILD_FOR_UBOOT
end_ifdef

begin_function_decl
name|uint64_t
name|octeon_pci_console_init
parameter_list|(
name|int
name|num_consoles
parameter_list|,
name|int
name|buffer_size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Flag definitions for read/write functions */
end_comment

begin_enum
enum|enum
block|{
name|OCT_PCI_CON_FLAG_NONBLOCK
init|=
literal|1
operator|<<
literal|0
block|,
comment|/* If set, read/write functions won't block waiting for space or data.                                           * For reads, 0 bytes may be read, and for writes not all of the                                           * supplied data may be written.*/
block|}
enum|;
end_enum

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|||
name|defined
argument_list|(
name|__KERNEL__
argument_list|)
end_if

begin_function_decl
name|int
name|octeon_pci_console_write
parameter_list|(
name|uint64_t
name|console_desc_addr
parameter_list|,
name|unsigned
name|int
name|console_num
parameter_list|,
specifier|const
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|bytes_to_write
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|octeon_pci_console_write_avail
parameter_list|(
name|uint64_t
name|console_desc_addr
parameter_list|,
name|unsigned
name|int
name|console_num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|octeon_pci_console_read
parameter_list|(
name|uint64_t
name|console_desc_addr
parameter_list|,
name|unsigned
name|int
name|console_num
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|buffer_size
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|octeon_pci_console_read_avail
parameter_list|(
name|uint64_t
name|console_desc_addr
parameter_list|,
name|unsigned
name|int
name|console_num
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|OCTEON_TARGET
argument_list|)
operator|&&
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__KERNEL__
argument_list|)
end_if

begin_function_decl
name|int
name|octeon_pci_console_host_write
parameter_list|(
name|uint64_t
name|console_desc_addr
parameter_list|,
name|unsigned
name|int
name|console_num
parameter_list|,
specifier|const
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|write_reqest_size
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|octeon_pci_console_host_write_avail
parameter_list|(
name|uint64_t
name|console_desc_addr
parameter_list|,
name|unsigned
name|int
name|console_num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|octeon_pci_console_host_read
parameter_list|(
name|uint64_t
name|console_desc_addr
parameter_list|,
name|unsigned
name|int
name|console_num
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|buf_size
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|octeon_pci_console_host_read_avail
parameter_list|(
name|uint64_t
name|console_desc_addr
parameter_list|,
name|unsigned
name|int
name|console_num
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

