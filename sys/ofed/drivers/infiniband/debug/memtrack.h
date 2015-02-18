begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   This software is available to you under a choice of one of two   licenses.  You may choose to be licensed under the terms of the GNU   General Public License (GPL) Version 2, available at<http://www.fsf.org/copyleft/gpl.html>, or the OpenIB.org BSD   license, available in the LICENSE.TXT file accompanying this   software.  These details are also available at<http://openib.org/license.html>.    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE   SOFTWARE.    Copyright (c) 2004 Mellanox Technologies Ltd.  All rights reserved. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|H_MEMTRACK_H
end_ifndef

begin_define
define|#
directive|define
name|H_MEMTRACK_H
end_define

begin_enum
enum|enum
name|memtrack_memtype_t
block|{
name|MEMTRACK_KMALLOC
block|,
name|MEMTRACK_VMALLOC
block|,
name|MEMTRACK_KMEM_OBJ
block|,
name|MEMTRACK_IOREMAP
block|,
comment|/* IO-RE/UN-MAP */
name|MEMTRACK_WORK_QUEUE
block|,
comment|/* Handle work-queue create& destroy */
name|MEMTRACK_PAGE_ALLOC
block|,
comment|/* Handle page allocation and free */
name|MEMTRACK_DMA_MAP_SINGLE
block|,
comment|/* Handle ib_dma_single map and unmap */
name|MEMTRACK_DMA_MAP_PAGE
block|,
comment|/* Handle ib_dma_page map and unmap */
name|MEMTRACK_DMA_MAP_SG
block|,
comment|/* Handle ib_dma_sg map and unmap with and without attributes */
name|MEMTRACK_NUM_OF_MEMTYPES
block|}
enum|;
end_enum

begin_comment
comment|/* Invoke on memory allocation */
end_comment

begin_function_decl
name|void
name|memtrack_alloc
parameter_list|(
name|enum
name|memtrack_memtype_t
name|memtype
parameter_list|,
name|unsigned
name|long
name|dev
parameter_list|,
name|unsigned
name|long
name|addr
parameter_list|,
name|unsigned
name|long
name|size
parameter_list|,
name|unsigned
name|long
name|addr2
parameter_list|,
name|int
name|direction
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
specifier|const
name|unsigned
name|long
name|line_num
parameter_list|,
name|int
name|alloc_flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Invoke on memory free */
end_comment

begin_function_decl
name|void
name|memtrack_free
parameter_list|(
name|enum
name|memtrack_memtype_t
name|memtype
parameter_list|,
name|unsigned
name|long
name|dev
parameter_list|,
name|unsigned
name|long
name|addr
parameter_list|,
name|unsigned
name|long
name|size
parameter_list|,
name|int
name|direction
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
specifier|const
name|unsigned
name|long
name|line_num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * This function recognizes allocations which  * may be released by kernel (e.g. skb& vnic) and  * therefore not trackable by memtrack.  * The allocations are recognized by the name  * of their calling function.  */
end_comment

begin_function_decl
name|int
name|is_non_trackable_alloc_func
parameter_list|(
specifier|const
name|char
modifier|*
name|func_name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * In some cases we need to free a memory  * we defined as "non trackable" (see  * is_non_trackable_alloc_func).  * This function recognizes such releases  * by the name of their calling function.  */
end_comment

begin_function_decl
name|int
name|is_non_trackable_free_func
parameter_list|(
specifier|const
name|char
modifier|*
name|func_name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* WA - In this function handles confirm    the the function name is    '__ib_umem_release' or 'ib_umem_get'    In this case we won't track the    memory there because the kernel    was the one who allocated it.    Return value:      1 - if the function name is match, else 0    */
end_comment

begin_function_decl
name|int
name|is_umem_put_page
parameter_list|(
specifier|const
name|char
modifier|*
name|func_name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Check page order size    When Freeing a page allocation it checks whether    we are trying to free the same amount of pages    we ask to allocate (In log2(order)).    In case an error if found it will print    an error msg                                    */
end_comment

begin_function_decl
name|int
name|memtrack_check_size
parameter_list|(
name|enum
name|memtrack_memtype_t
name|memtype
parameter_list|,
name|unsigned
name|long
name|addr
parameter_list|,
name|unsigned
name|long
name|size
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
specifier|const
name|unsigned
name|long
name|line_num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Search for a specific addr whether it exist in the    current data-base.    If not it will print an error msg,    Return value: 0 - if addr exist, else 1 */
end_comment

begin_function_decl
name|int
name|memtrack_is_new_addr
parameter_list|(
name|enum
name|memtrack_memtype_t
name|memtype
parameter_list|,
name|unsigned
name|long
name|addr
parameter_list|,
name|int
name|expect_exist
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
specifier|const
name|unsigned
name|long
name|line_num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return current page reference counter */
end_comment

begin_function_decl
name|int
name|memtrack_get_page_ref_count
parameter_list|(
name|unsigned
name|long
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Report current allocations status (for all memory types) */
end_comment

begin_comment
comment|/* we do not export this function since it is used by cleanup_module only */
end_comment

begin_comment
comment|/* void memtrack_report(void); */
end_comment

begin_comment
comment|/* Allow support of error injections */
end_comment

begin_function_decl
name|int
name|memtrack_inject_error
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* randomize allocated memory */
end_comment

begin_function_decl
name|int
name|memtrack_randomize_mem
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

