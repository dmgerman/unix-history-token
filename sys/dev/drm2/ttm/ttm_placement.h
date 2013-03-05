begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************************  *  * Copyright (c) 2006-2009 VMware, Inc., Palo Alto, CA., USA  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the  * "Software"), to deal in the Software without restriction, including  * without limitation the rights to use, copy, modify, merge, publish,  * distribute, sub license, and/or sell copies of the Software, and to  * permit persons to whom the Software is furnished to do so, subject to  * the following conditions:  *  * The above copyright notice and this permission notice (including the  * next paragraph) shall be included in all copies or substantial portions  * of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS, AUTHORS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM,  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE  * USE OR OTHER DEALINGS IN THE SOFTWARE.  *  **************************************************************************/
end_comment

begin_comment
comment|/*  * Authors: Thomas Hellstrom<thellstrom-at-vmware-dot-com>  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TTM_PLACEMENT_H_
end_ifndef

begin_define
define|#
directive|define
name|_TTM_PLACEMENT_H_
end_define

begin_comment
comment|/*  * Memory regions for data placement.  */
end_comment

begin_define
define|#
directive|define
name|TTM_PL_SYSTEM
value|0
end_define

begin_define
define|#
directive|define
name|TTM_PL_TT
value|1
end_define

begin_define
define|#
directive|define
name|TTM_PL_VRAM
value|2
end_define

begin_define
define|#
directive|define
name|TTM_PL_PRIV0
value|3
end_define

begin_define
define|#
directive|define
name|TTM_PL_PRIV1
value|4
end_define

begin_define
define|#
directive|define
name|TTM_PL_PRIV2
value|5
end_define

begin_define
define|#
directive|define
name|TTM_PL_PRIV3
value|6
end_define

begin_define
define|#
directive|define
name|TTM_PL_PRIV4
value|7
end_define

begin_define
define|#
directive|define
name|TTM_PL_PRIV5
value|8
end_define

begin_define
define|#
directive|define
name|TTM_PL_SWAPPED
value|15
end_define

begin_define
define|#
directive|define
name|TTM_PL_FLAG_SYSTEM
value|(1<< TTM_PL_SYSTEM)
end_define

begin_define
define|#
directive|define
name|TTM_PL_FLAG_TT
value|(1<< TTM_PL_TT)
end_define

begin_define
define|#
directive|define
name|TTM_PL_FLAG_VRAM
value|(1<< TTM_PL_VRAM)
end_define

begin_define
define|#
directive|define
name|TTM_PL_FLAG_PRIV0
value|(1<< TTM_PL_PRIV0)
end_define

begin_define
define|#
directive|define
name|TTM_PL_FLAG_PRIV1
value|(1<< TTM_PL_PRIV1)
end_define

begin_define
define|#
directive|define
name|TTM_PL_FLAG_PRIV2
value|(1<< TTM_PL_PRIV2)
end_define

begin_define
define|#
directive|define
name|TTM_PL_FLAG_PRIV3
value|(1<< TTM_PL_PRIV3)
end_define

begin_define
define|#
directive|define
name|TTM_PL_FLAG_PRIV4
value|(1<< TTM_PL_PRIV4)
end_define

begin_define
define|#
directive|define
name|TTM_PL_FLAG_PRIV5
value|(1<< TTM_PL_PRIV5)
end_define

begin_define
define|#
directive|define
name|TTM_PL_FLAG_SWAPPED
value|(1<< TTM_PL_SWAPPED)
end_define

begin_define
define|#
directive|define
name|TTM_PL_MASK_MEM
value|0x0000FFFF
end_define

begin_comment
comment|/*  * Other flags that affects data placement.  * TTM_PL_FLAG_CACHED indicates cache-coherent mappings  * if available.  * TTM_PL_FLAG_SHARED means that another application may  * reference the buffer.  * TTM_PL_FLAG_NO_EVICT means that the buffer may never  * be evicted to make room for other buffers.  */
end_comment

begin_define
define|#
directive|define
name|TTM_PL_FLAG_CACHED
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|TTM_PL_FLAG_UNCACHED
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|TTM_PL_FLAG_WC
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|TTM_PL_FLAG_SHARED
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|TTM_PL_FLAG_NO_EVICT
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|TTM_PL_MASK_CACHING
value|(TTM_PL_FLAG_CACHED | \ 				 TTM_PL_FLAG_UNCACHED | \ 				 TTM_PL_FLAG_WC)
end_define

begin_define
define|#
directive|define
name|TTM_PL_MASK_MEMTYPE
value|(TTM_PL_MASK_MEM | TTM_PL_MASK_CACHING)
end_define

begin_comment
comment|/*  * Access flags to be used for CPU- and GPU- mappings.  * The idea is that the TTM synchronization mechanism will  * allow concurrent READ access and exclusive write access.  * Currently GPU- and CPU accesses are exclusive.  */
end_comment

begin_define
define|#
directive|define
name|TTM_ACCESS_READ
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|TTM_ACCESS_WRITE
value|(1<< 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

