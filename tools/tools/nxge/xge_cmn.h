begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2007 Neterion, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XGE_CMN_H
end_ifndef

begin_define
define|#
directive|define
name|XGE_CMN_H
end_define

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
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|XGE_OS_HOST_BIG_ENDIAN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|u64
value|unsigned long long
end_define

begin_define
define|#
directive|define
name|u32
value|unsigned int
end_define

begin_define
define|#
directive|define
name|u16
value|unsigned short
end_define

begin_define
define|#
directive|define
name|u8
value|unsigned char
end_define

begin_define
define|#
directive|define
name|XGE_COUNT_REGS
value|386
end_define

begin_define
define|#
directive|define
name|XGE_COUNT_STATS
value|160
end_define

begin_define
define|#
directive|define
name|XGE_COUNT_PCICONF
value|43
end_define

begin_define
define|#
directive|define
name|XGE_COUNT_DEVCONF
value|1677
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_LRO
end_ifdef

begin_define
define|#
directive|define
name|XGE_COUNT_INTRSTAT
value|26
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XGE_COUNT_INTRSTAT
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XGE_COUNT_TCODESTAT
value|54
end_define

begin_define
define|#
directive|define
name|DEVICE_ID_XFRAME_II
value|0x5832
end_define

begin_define
define|#
directive|define
name|XGE_COUNT_EXTENDED_STATS
value|56
end_define

begin_define
define|#
directive|define
name|XGE_PRINT
parameter_list|(
name|fd
parameter_list|,
name|fmt
modifier|...
parameter_list|)
define|\
value|{                                                                             \     fprintf( fd, fmt );                                                       \     fprintf( fd, "\n" );                                                      \     printf( fmt );                                                            \     printf( "\n" );                                                           \ }
end_define

begin_define
define|#
directive|define
name|XGE_PRINT_LINE
parameter_list|(
name|fd
parameter_list|)
value|XGE_PRINT(fd, line);
end_define

begin_comment
comment|/* Read& Write Register */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|barregister
block|{
name|char
name|option
index|[
literal|2
index|]
decl_stmt|;
name|u64
name|offset
decl_stmt|;
name|u64
name|value
decl_stmt|;
block|}
name|bar0reg_t
typedef|;
end_typedef

begin_comment
comment|/* Register Dump */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xge_pci_bar0_t
block|{
name|u8
name|name
index|[
literal|32
index|]
decl_stmt|;
comment|/* Register name as in user guides */
name|u64
name|offset
decl_stmt|;
comment|/* Offset from base address        */
name|u64
name|value
decl_stmt|;
comment|/* Value                           */
name|char
name|type
decl_stmt|;
comment|/* 1: XframeII, 0: Common          */
block|}
name|xge_pci_bar0_t
typedef|;
end_typedef

begin_comment
comment|/* Hardware Statistics */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xge_stats_hw_info_t
block|{
name|u8
name|name
index|[
literal|32
index|]
decl_stmt|;
comment|/* Statistics name                 */
name|u64
name|be_offset
decl_stmt|;
comment|/* Offset from base address (BE)   */
name|u64
name|le_offset
decl_stmt|;
comment|/* Offset from base address (LE)   */
name|u8
name|type
decl_stmt|;
comment|/* Type: 1, 2, 3 or 4 bytes        */
name|u64
name|value
decl_stmt|;
comment|/* Value                           */
block|}
name|xge_stats_hw_info_t
typedef|;
end_typedef

begin_comment
comment|/* PCI Configuration Space */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xge_pci_config_t
block|{
name|u8
name|name
index|[
literal|32
index|]
decl_stmt|;
comment|/* Pci conf. name                  */
name|u64
name|be_offset
decl_stmt|;
comment|/* Offset from base address (BE)   */
name|u64
name|le_offset
decl_stmt|;
comment|/* Offset from base address (LE)   */
name|u64
name|value
decl_stmt|;
comment|/* Value                           */
block|}
name|xge_pci_config_t
typedef|;
end_typedef

begin_comment
comment|/* Device Configuration */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xge_device_config_t
block|{
name|u8
name|name
index|[
literal|32
index|]
decl_stmt|;
comment|/* Device conf. name               */
name|u64
name|value
decl_stmt|;
comment|/* Value                           */
block|}
name|xge_device_config_t
typedef|;
end_typedef

begin_comment
comment|/* Interrupt Statistics */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xge_stats_intr_info_t
block|{
name|u8
name|name
index|[
literal|32
index|]
decl_stmt|;
comment|/* Interrupt entry name            */
name|u64
name|value
decl_stmt|;
comment|/* Value (count)                   */
block|}
name|xge_stats_intr_info_t
typedef|;
end_typedef

begin_comment
comment|/* Tcode Statistics */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|xge_stats_tcode_info_t
block|{
name|u8
name|name
index|[
literal|32
index|]
decl_stmt|;
comment|/* Tcode entry name                */
name|u64
name|value
decl_stmt|;
comment|/* Value (count)                   */
name|u8
name|type
decl_stmt|;
comment|/* Type: 1, 2, 3 or 4 bytes        */
name|u16
name|flag
decl_stmt|;
block|}
name|xge_stats_tcode_info_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|XGE_OS_HOST_BIG_ENDIAN
end_ifdef

begin_define
define|#
directive|define
name|GET_OFFSET_STATS
parameter_list|(
name|index
parameter_list|)
value|statsInfo[(index)].be_offset
end_define

begin_define
define|#
directive|define
name|GET_OFFSET_PCICONF
parameter_list|(
name|index
parameter_list|)
value|pciconfInfo[(index)].be_offset
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GET_OFFSET_STATS
parameter_list|(
name|index
parameter_list|)
value|statsInfo[(index)].le_offset
end_define

begin_define
define|#
directive|define
name|GET_OFFSET_PCICONF
parameter_list|(
name|index
parameter_list|)
value|pciconfInfo[(index)].le_offset
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//XGE_CMN_H
end_comment

end_unit

