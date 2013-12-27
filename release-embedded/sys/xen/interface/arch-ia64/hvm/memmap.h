begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * memmap.h  *  * Copyright (c) 2008 Tristan Gingold<tgingold AT free fr>  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_HVM_MEMMAP_IA64_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_HVM_MEMMAP_IA64_H__
end_define

begin_define
define|#
directive|define
name|MEM_G
value|(1UL<< 30)
end_define

begin_define
define|#
directive|define
name|MEM_M
value|(1UL<< 20)
end_define

begin_define
define|#
directive|define
name|MEM_K
value|(1UL<< 10)
end_define

begin_comment
comment|/* Guest physical address of IO ports space.  */
end_comment

begin_define
define|#
directive|define
name|MMIO_START
value|(3 * MEM_G)
end_define

begin_define
define|#
directive|define
name|MMIO_SIZE
value|(512 * MEM_M)
end_define

begin_define
define|#
directive|define
name|VGA_IO_START
value|0xA0000UL
end_define

begin_define
define|#
directive|define
name|VGA_IO_SIZE
value|0x20000
end_define

begin_define
define|#
directive|define
name|LEGACY_IO_START
value|(MMIO_START + MMIO_SIZE)
end_define

begin_define
define|#
directive|define
name|LEGACY_IO_SIZE
value|(64 * MEM_M)
end_define

begin_define
define|#
directive|define
name|IO_PAGE_START
value|(LEGACY_IO_START + LEGACY_IO_SIZE)
end_define

begin_define
define|#
directive|define
name|IO_PAGE_SIZE
value|XEN_PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|STORE_PAGE_START
value|(IO_PAGE_START + IO_PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|STORE_PAGE_SIZE
value|XEN_PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|BUFFER_IO_PAGE_START
value|(STORE_PAGE_START + STORE_PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|BUFFER_IO_PAGE_SIZE
value|XEN_PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|BUFFER_PIO_PAGE_START
value|(BUFFER_IO_PAGE_START + BUFFER_IO_PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|BUFFER_PIO_PAGE_SIZE
value|XEN_PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|IO_SAPIC_START
value|0xfec00000UL
end_define

begin_define
define|#
directive|define
name|IO_SAPIC_SIZE
value|0x100000
end_define

begin_define
define|#
directive|define
name|PIB_START
value|0xfee00000UL
end_define

begin_define
define|#
directive|define
name|PIB_SIZE
value|0x200000
end_define

begin_define
define|#
directive|define
name|GFW_START
value|(4 * MEM_G - 16 * MEM_M)
end_define

begin_define
define|#
directive|define
name|GFW_SIZE
value|(16 * MEM_M)
end_define

begin_comment
comment|/* domVTI */
end_comment

begin_define
define|#
directive|define
name|GPFN_FRAME_BUFFER
value|0x1
end_define

begin_comment
comment|/* VGA framebuffer */
end_comment

begin_define
define|#
directive|define
name|GPFN_LOW_MMIO
value|0x2
end_define

begin_comment
comment|/* Low MMIO range */
end_comment

begin_define
define|#
directive|define
name|GPFN_PIB
value|0x3
end_define

begin_comment
comment|/* PIB base */
end_comment

begin_define
define|#
directive|define
name|GPFN_IOSAPIC
value|0x4
end_define

begin_comment
comment|/* IOSAPIC base */
end_comment

begin_define
define|#
directive|define
name|GPFN_LEGACY_IO
value|0x5
end_define

begin_comment
comment|/* Legacy I/O base */
end_comment

begin_define
define|#
directive|define
name|GPFN_HIGH_MMIO
value|0x6
end_define

begin_comment
comment|/* High MMIO range */
end_comment

begin_comment
comment|/* Nvram belongs to GFW memory space  */
end_comment

begin_define
define|#
directive|define
name|NVRAM_SIZE
value|(MEM_K * 64)
end_define

begin_define
define|#
directive|define
name|NVRAM_START
value|(GFW_START + 10 * MEM_M)
end_define

begin_define
define|#
directive|define
name|NVRAM_VALID_SIG
value|0x4650494e45584948
end_define

begin_comment
comment|/* "HIXENIPF" */
end_comment

begin_struct
struct|struct
name|nvram_save_addr
block|{
name|unsigned
name|long
name|addr
decl_stmt|;
name|unsigned
name|long
name|signature
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_HVM_MEMMAP_IA64_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

