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

begin_typedef
typedef|typedef
enum|enum
block|{
name|MEMTRACK_KMALLOC
block|,
name|MEMTRACK_VMALLOC
block|,
name|MEMTRACK_KMEM_OBJ
block|,
name|MEMTRACK_NUM_OF_MEMTYPES
block|}
name|memtrack_memtype_t
typedef|;
end_typedef

begin_comment
comment|/* Invoke on memory allocation */
end_comment

begin_function_decl
name|void
name|memtrack_alloc
parameter_list|(
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
name|memtrack_memtype_t
name|memtype
parameter_list|,
name|unsigned
name|long
name|addr
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
comment|/* Report current allocations status (for all memory types) */
end_comment

begin_comment
comment|/* we do not export this function since it is used by cleanup_module only */
end_comment

begin_comment
comment|/* void memtrack_report(void); */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

