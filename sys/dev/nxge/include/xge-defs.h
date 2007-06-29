begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2007 Neterion, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  FileName :    xge-defs.h  *  *  Description:  global definitions  *  *  Created:      13 May 2004  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XGE_DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|XGE_DEFS_H
end_define

begin_define
define|#
directive|define
name|XGE_PCI_VENDOR_ID
value|0x17D5
end_define

begin_define
define|#
directive|define
name|XGE_PCI_DEVICE_ID_XENA_1
value|0x5731
end_define

begin_define
define|#
directive|define
name|XGE_PCI_DEVICE_ID_XENA_2
value|0x5831
end_define

begin_define
define|#
directive|define
name|XGE_PCI_DEVICE_ID_HERC_1
value|0x5732
end_define

begin_define
define|#
directive|define
name|XGE_PCI_DEVICE_ID_HERC_2
value|0x5832
end_define

begin_define
define|#
directive|define
name|XGE_PCI_DEVICE_ID_TITAN_1
value|0x5733
end_define

begin_define
define|#
directive|define
name|XGE_PCI_DEVICE_ID_TITAN_2
value|0x5833
end_define

begin_define
define|#
directive|define
name|XGE_DRIVER_NAME
value|"Xge driver"
end_define

begin_define
define|#
directive|define
name|XGE_DRIVER_VENDOR
value|"Neterion, Inc"
end_define

begin_define
define|#
directive|define
name|XGE_CHIP_FAMILY
value|"Xframe"
end_define

begin_define
define|#
directive|define
name|XGE_SUPPORTED_MEDIA_0
value|"Fiber"
end_define

begin_include
include|#
directive|include
file|<dev/nxge/include/version.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|__EXTERN_BEGIN_DECLS
value|extern "C" {
end_define

begin_define
define|#
directive|define
name|__EXTERN_END_DECLS
value|}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__EXTERN_BEGIN_DECLS
end_define

begin_define
define|#
directive|define
name|__EXTERN_END_DECLS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__EXTERN_BEGIN_DECLS
end_macro

begin_comment
comment|/*---------------------------- DMA attributes ------------------------------*/
end_comment

begin_comment
comment|/*           Used in xge_os_dma_malloc() and xge_os_dma_map() */
end_comment

begin_comment
comment|/*---------------------------- DMA attributes ------------------------------*/
end_comment

begin_comment
comment|/* XGE_OS_DMA_REQUIRES_SYNC  - should be defined or                              NOT defined in the Makefile */
end_comment

begin_define
define|#
directive|define
name|XGE_OS_DMA_CACHELINE_ALIGNED
value|0x1
end_define

begin_comment
comment|/* Either STREAMING or CONSISTENT should be used.    The combination of both or none is invalid */
end_comment

begin_define
define|#
directive|define
name|XGE_OS_DMA_STREAMING
value|0x2
end_define

begin_define
define|#
directive|define
name|XGE_OS_DMA_CONSISTENT
value|0x4
end_define

begin_define
define|#
directive|define
name|XGE_OS_SPRINTF_STRLEN
value|64
end_define

begin_comment
comment|/*---------------------------- common stuffs -------------------------------*/
end_comment

begin_define
define|#
directive|define
name|XGE_OS_LLXFMT
value|"%llx"
end_define

begin_define
define|#
directive|define
name|XGE_OS_NEWLINE
value|"\n"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|XGE_OS_MEMORY_CHECK
end_ifdef

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|ptr
decl_stmt|;
name|int
name|size
decl_stmt|;
name|char
modifier|*
name|file
decl_stmt|;
name|int
name|line
decl_stmt|;
block|}
name|xge_os_malloc_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XGE_OS_MALLOC_CNT_MAX
value|64*1024
end_define

begin_decl_stmt
specifier|extern
name|xge_os_malloc_t
name|g_malloc_arr
index|[
name|XGE_OS_MALLOC_CNT_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|g_malloc_cnt
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|XGE_OS_MEMORY_CHECK_MALLOC
parameter_list|(
name|_vaddr
parameter_list|,
name|_size
parameter_list|,
name|_file
parameter_list|,
name|_line
parameter_list|)
value|{ \ 	if (_vaddr) { \ 		int i; \ 		for (i=0; i<g_malloc_cnt; i++) { \ 			if (g_malloc_arr[i].ptr == NULL) { \ 				break; \ 			} \ 		} \ 		if (i == g_malloc_cnt) { \ 			g_malloc_cnt++; \ 			if (g_malloc_cnt>= XGE_OS_MALLOC_CNT_MAX) { \ 			  xge_os_bug("g_malloc_cnt exceed %d", \ 						XGE_OS_MALLOC_CNT_MAX); \ 			} \ 		} \ 		g_malloc_arr[i].ptr = _vaddr; \ 		g_malloc_arr[i].size = _size; \ 		g_malloc_arr[i].file = _file; \ 		g_malloc_arr[i].line = _line; \ 		for (i=0; i<_size; i++) { \ 			*((char *)_vaddr+i) = 0x5a; \ 		} \ 	} \ }
end_define

begin_define
define|#
directive|define
name|XGE_OS_MEMORY_CHECK_FREE
parameter_list|(
name|_vaddr
parameter_list|,
name|_check_size
parameter_list|)
value|{ \ 	int i; \ 	for (i=0; i<XGE_OS_MALLOC_CNT_MAX; i++) { \ 		if (g_malloc_arr[i].ptr == _vaddr) { \ 			g_malloc_arr[i].ptr = NULL; \ 			if(_check_size&& g_malloc_arr[i].size!=_check_size) { \ 				xge_os_printf("OSPAL: freeing with wrong " \ 				      "size %d! allocated at %s:%d:"XGE_OS_LLXFMT":%d", \ 					 (int)_check_size, \ 					 g_malloc_arr[i].file, \ 					 g_malloc_arr[i].line, \ 					 (unsigned long long)(ulong_t) \ 					    g_malloc_arr[i].ptr, \ 					 g_malloc_arr[i].size); \ 			} \ 			break; \ 		} \ 	} \ 	if (i == XGE_OS_MALLOC_CNT_MAX) { \ 		xge_os_printf("OSPAL: ptr "XGE_OS_LLXFMT" not found!", \ 			    (unsigned long long)(ulong_t)_vaddr); \ 	} \ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XGE_OS_MEMORY_CHECK_MALLOC
parameter_list|(
name|ptr
parameter_list|,
name|size
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
end_define

begin_define
define|#
directive|define
name|XGE_OS_MEMORY_CHECK_FREE
parameter_list|(
name|vaddr
parameter_list|,
name|check_size
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__EXTERN_END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XGE_DEFS_H */
end_comment

end_unit

