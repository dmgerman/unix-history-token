begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ioreq.h: I/O request definitions for device models  * Copyright (c) 2004, Intel Corporation.  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IOREQ_H_
end_ifndef

begin_define
define|#
directive|define
name|_IOREQ_H_
end_define

begin_define
define|#
directive|define
name|IOREQ_READ
value|1
end_define

begin_define
define|#
directive|define
name|IOREQ_WRITE
value|0
end_define

begin_define
define|#
directive|define
name|STATE_IOREQ_NONE
value|0
end_define

begin_define
define|#
directive|define
name|STATE_IOREQ_READY
value|1
end_define

begin_define
define|#
directive|define
name|STATE_IOREQ_INPROCESS
value|2
end_define

begin_define
define|#
directive|define
name|STATE_IORESP_READY
value|3
end_define

begin_define
define|#
directive|define
name|IOREQ_TYPE_PIO
value|0
end_define

begin_comment
comment|/* pio */
end_comment

begin_define
define|#
directive|define
name|IOREQ_TYPE_COPY
value|1
end_define

begin_comment
comment|/* mmio ops */
end_comment

begin_define
define|#
directive|define
name|IOREQ_TYPE_TIMEOFFSET
value|7
end_define

begin_define
define|#
directive|define
name|IOREQ_TYPE_INVALIDATE
value|8
end_define

begin_comment
comment|/* mapcache */
end_comment

begin_comment
comment|/*  * VMExit dispatcher should cooperate with instruction decoder to  * prepare this structure and notify service OS and DM by sending  * virq  */
end_comment

begin_struct
struct|struct
name|ioreq
block|{
name|uint64_t
name|addr
decl_stmt|;
comment|/*  physical address            */
name|uint64_t
name|size
decl_stmt|;
comment|/*  size in bytes               */
name|uint64_t
name|count
decl_stmt|;
comment|/*  for rep prefixes            */
name|uint64_t
name|data
decl_stmt|;
comment|/*  data (or paddr of data)     */
name|uint8_t
name|state
range|:
literal|4
decl_stmt|;
name|uint8_t
name|data_is_ptr
range|:
literal|1
decl_stmt|;
comment|/*  if 1, data above is the guest paddr                               *   of the real data to use.   */
name|uint8_t
name|dir
range|:
literal|1
decl_stmt|;
comment|/*  1=read, 0=write             */
name|uint8_t
name|df
range|:
literal|1
decl_stmt|;
name|uint8_t
name|pad
range|:
literal|1
decl_stmt|;
name|uint8_t
name|type
decl_stmt|;
comment|/* I/O type                     */
name|uint8_t
name|_pad0
index|[
literal|6
index|]
decl_stmt|;
name|uint64_t
name|io_count
decl_stmt|;
comment|/* How many IO done on a vcpu   */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ioreq
name|ioreq_t
typedef|;
end_typedef

begin_struct
struct|struct
name|vcpu_iodata
block|{
name|struct
name|ioreq
name|vp_ioreq
decl_stmt|;
comment|/* Event channel port, used for notifications to/from the device model. */
name|uint32_t
name|vp_eport
decl_stmt|;
name|uint32_t
name|_pad0
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|vcpu_iodata
name|vcpu_iodata_t
typedef|;
end_typedef

begin_struct
struct|struct
name|shared_iopage
block|{
name|struct
name|vcpu_iodata
name|vcpu_iodata
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|shared_iopage
name|shared_iopage_t
typedef|;
end_typedef

begin_struct
struct|struct
name|buf_ioreq
block|{
name|uint8_t
name|type
decl_stmt|;
comment|/* I/O type                    */
name|uint8_t
name|pad
range|:
literal|1
decl_stmt|;
name|uint8_t
name|dir
range|:
literal|1
decl_stmt|;
comment|/* 1=read, 0=write             */
name|uint8_t
name|size
range|:
literal|2
decl_stmt|;
comment|/* 0=>1, 1=>2, 2=>4, 3=>8. If 8, use two buf_ioreqs */
name|uint32_t
name|addr
range|:
literal|20
decl_stmt|;
comment|/* physical address            */
name|uint32_t
name|data
decl_stmt|;
comment|/* data                        */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|buf_ioreq
name|buf_ioreq_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IOREQ_BUFFER_SLOT_NUM
value|511
end_define

begin_comment
comment|/* 8 bytes each, plus 2 4-byte indexes */
end_comment

begin_struct
struct|struct
name|buffered_iopage
block|{
name|unsigned
name|int
name|read_pointer
decl_stmt|;
name|unsigned
name|int
name|write_pointer
decl_stmt|;
name|buf_ioreq_t
name|buf_ioreq
index|[
name|IOREQ_BUFFER_SLOT_NUM
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* NB. Size of this structure must be no greater than one page. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|buffered_iopage
name|buffered_iopage_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ia64__
argument_list|)
end_if

begin_struct
struct|struct
name|pio_buffer
block|{
name|uint32_t
name|page_offset
decl_stmt|;
name|uint32_t
name|pointer
decl_stmt|;
name|uint32_t
name|data_end
decl_stmt|;
name|uint32_t
name|buf_size
decl_stmt|;
name|void
modifier|*
name|opaque
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PIO_BUFFER_IDE_PRIMARY
value|0
end_define

begin_comment
comment|/* I/O port = 0x1F0 */
end_comment

begin_define
define|#
directive|define
name|PIO_BUFFER_IDE_SECONDARY
value|1
end_define

begin_comment
comment|/* I/O port = 0x170 */
end_comment

begin_define
define|#
directive|define
name|PIO_BUFFER_ENTRY_NUM
value|2
end_define

begin_struct
struct|struct
name|buffered_piopage
block|{
name|struct
name|pio_buffer
name|pio
index|[
name|PIO_BUFFER_ENTRY_NUM
index|]
decl_stmt|;
name|uint8_t
name|buffer
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__ia64__) */
end_comment

begin_define
define|#
directive|define
name|ACPI_PM1A_EVT_BLK_ADDRESS
value|0x0000000000001f40
end_define

begin_define
define|#
directive|define
name|ACPI_PM1A_CNT_BLK_ADDRESS
value|(ACPI_PM1A_EVT_BLK_ADDRESS + 0x04)
end_define

begin_define
define|#
directive|define
name|ACPI_PM_TMR_BLK_ADDRESS
value|(ACPI_PM1A_EVT_BLK_ADDRESS + 0x08)
end_define

begin_define
define|#
directive|define
name|ACPI_GPE0_BLK_ADDRESS
value|(ACPI_PM_TMR_BLK_ADDRESS + 0x20)
end_define

begin_define
define|#
directive|define
name|ACPI_GPE0_BLK_LEN
value|0x08
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IOREQ_H_ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

