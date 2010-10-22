begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_BLKIF_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_BLKIF_H__
end_define

begin_include
include|#
directive|include
file|<xen/interface/io/ring.h>
end_include

begin_include
include|#
directive|include
file|<xen/interface/io/blkif.h>
end_include

begin_include
include|#
directive|include
file|<xen/interface/io/protocols.h>
end_include

begin_comment
comment|/* Not a real protocol.  Used to generate ring structs which contain  * the elements common to all protocols only.  This way we get a  * compiler-checkable way to use common struct elements, so we can  * avoid using switch(protocol) in a number of places.  */
end_comment

begin_struct
struct|struct
name|blkif_common_request
block|{
name|char
name|dummy
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|blkif_common_response
block|{
name|char
name|dummy
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* i386 protocol version */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|4
name|)
end_pragma

begin_struct
struct|struct
name|blkif_x86_32_request
block|{
name|uint8_t
name|operation
decl_stmt|;
comment|/* BLKIF_OP_???                         */
name|uint8_t
name|nr_segments
decl_stmt|;
comment|/* number of segments                   */
name|blkif_vdev_t
name|handle
decl_stmt|;
comment|/* only for read/write requests         */
name|uint64_t
name|id
decl_stmt|;
comment|/* private guest value, echoed in resp  */
name|blkif_sector_t
name|sector_number
decl_stmt|;
comment|/* start sector idx on disk (r/w only)  */
name|struct
name|blkif_request_segment
name|seg
index|[
name|BLKIF_MAX_SEGMENTS_PER_HEADER_BLOCK
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|blkif_x86_32_response
block|{
name|uint64_t
name|id
decl_stmt|;
comment|/* copied from request */
name|uint8_t
name|operation
decl_stmt|;
comment|/* copied from request */
name|int16_t
name|status
decl_stmt|;
comment|/* BLKIF_RSP_???       */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|blkif_x86_32_request
name|blkif_x86_32_request_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|blkif_x86_32_response
name|blkif_x86_32_response_t
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_comment
comment|/* x86_64 protocol version */
end_comment

begin_struct
struct|struct
name|blkif_x86_64_request
block|{
name|uint8_t
name|operation
decl_stmt|;
comment|/* BLKIF_OP_???                         */
name|uint8_t
name|nr_segments
decl_stmt|;
comment|/* number of segments                   */
name|blkif_vdev_t
name|handle
decl_stmt|;
comment|/* only for read/write requests         */
name|uint64_t
name|__attribute__
argument_list|(
operator|(
name|__aligned__
argument_list|(
literal|8
argument_list|)
operator|)
argument_list|)
name|id
decl_stmt|;
name|blkif_sector_t
name|sector_number
decl_stmt|;
comment|/* start sector idx on disk (r/w only)  */
name|struct
name|blkif_request_segment
name|seg
index|[
name|BLKIF_MAX_SEGMENTS_PER_HEADER_BLOCK
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|blkif_x86_64_response
block|{
name|uint64_t
name|__attribute__
argument_list|(
operator|(
name|__aligned__
argument_list|(
literal|8
argument_list|)
operator|)
argument_list|)
name|id
decl_stmt|;
name|uint8_t
name|operation
decl_stmt|;
comment|/* copied from request */
name|int16_t
name|status
decl_stmt|;
comment|/* BLKIF_RSP_???       */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|blkif_x86_64_request
name|blkif_x86_64_request_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|blkif_x86_64_response
name|blkif_x86_64_response_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_RING_TYPES
argument_list|(
name|blkif_common
argument_list|,
expr|struct
name|blkif_common_request
argument_list|,
expr|struct
name|blkif_common_response
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_RING_TYPES
argument_list|(
name|blkif_x86_32
argument_list|,
expr|struct
name|blkif_x86_32_request
argument_list|,
expr|struct
name|blkif_x86_32_response
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEFINE_RING_TYPES
argument_list|(
name|blkif_x86_64
argument_list|,
expr|struct
name|blkif_x86_64_request
argument_list|,
expr|struct
name|blkif_x86_64_response
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Maximum number of requests that can be active for a given instance  * regardless of the protocol in use, based on the ring size.  This constant  * facilitates resource pre-allocation in backend drivers since the size is  * known well in advance of attaching to a front end.  */
end_comment

begin_define
define|#
directive|define
name|BLKIF_MAX_RING_REQUESTS
parameter_list|(
name|_sz
parameter_list|)
define|\
value|MAX(__RING_SIZE((blkif_x86_64_sring_t *)NULL, _sz),	\ 	    MAX(__RING_SIZE((blkif_x86_32_sring_t *)NULL, _sz),	\ 		__RING_SIZE((blkif_sring_t *)NULL, _sz)))
end_define

begin_comment
comment|/*  * The number of ring pages required to support a given number of requests  * for a given instance regardless of the protocol in use.  */
end_comment

begin_define
define|#
directive|define
name|BLKIF_RING_PAGES
parameter_list|(
name|_entries
parameter_list|)
define|\
value|MAX(__RING_PAGES((blkif_x86_64_sring_t *)NULL, _entries),	\ 	    MAX(__RING_PAGES((blkif_x86_32_sring_t *)NULL, _entries),	\ 		__RING_PAGES((blkif_sring_t *)NULL, _entries)))
end_define

begin_union
union|union
name|blkif_back_rings
block|{
name|blkif_back_ring_t
name|native
decl_stmt|;
name|blkif_common_back_ring_t
name|common
decl_stmt|;
name|blkif_x86_32_back_ring_t
name|x86_32
decl_stmt|;
name|blkif_x86_64_back_ring_t
name|x86_64
decl_stmt|;
block|}
union|;
end_union

begin_typedef
typedef|typedef
name|union
name|blkif_back_rings
name|blkif_back_rings_t
typedef|;
end_typedef

begin_enum
enum|enum
name|blkif_protocol
block|{
name|BLKIF_PROTOCOL_NATIVE
init|=
literal|1
block|,
name|BLKIF_PROTOCOL_X86_32
init|=
literal|2
block|,
name|BLKIF_PROTOCOL_X86_64
init|=
literal|3
block|, }
enum|;
end_enum

begin_function
specifier|static
name|void
specifier|inline
name|blkif_get_x86_32_req
parameter_list|(
name|blkif_request_t
modifier|*
name|dst
parameter_list|,
name|blkif_x86_32_request_t
modifier|*
name|src
parameter_list|)
block|{
name|int
name|i
decl_stmt|,
name|n
init|=
name|BLKIF_MAX_SEGMENTS_PER_HEADER_BLOCK
decl_stmt|;
name|dst
operator|->
name|operation
operator|=
name|src
operator|->
name|operation
expr_stmt|;
name|dst
operator|->
name|nr_segments
operator|=
name|src
operator|->
name|nr_segments
expr_stmt|;
name|dst
operator|->
name|handle
operator|=
name|src
operator|->
name|handle
expr_stmt|;
name|dst
operator|->
name|id
operator|=
name|src
operator|->
name|id
expr_stmt|;
name|dst
operator|->
name|sector_number
operator|=
name|src
operator|->
name|sector_number
expr_stmt|;
name|barrier
argument_list|()
expr_stmt|;
if|if
condition|(
name|n
operator|>
name|dst
operator|->
name|nr_segments
condition|)
name|n
operator|=
name|dst
operator|->
name|nr_segments
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
name|i
operator|++
control|)
name|dst
operator|->
name|seg
index|[
name|i
index|]
operator|=
name|src
operator|->
name|seg
index|[
name|i
index|]
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
specifier|inline
name|blkif_get_x86_64_req
parameter_list|(
name|blkif_request_t
modifier|*
name|dst
parameter_list|,
name|blkif_x86_64_request_t
modifier|*
name|src
parameter_list|)
block|{
name|int
name|i
decl_stmt|,
name|n
init|=
name|BLKIF_MAX_SEGMENTS_PER_HEADER_BLOCK
decl_stmt|;
name|dst
operator|->
name|operation
operator|=
name|src
operator|->
name|operation
expr_stmt|;
name|dst
operator|->
name|nr_segments
operator|=
name|src
operator|->
name|nr_segments
expr_stmt|;
name|dst
operator|->
name|handle
operator|=
name|src
operator|->
name|handle
expr_stmt|;
name|dst
operator|->
name|id
operator|=
name|src
operator|->
name|id
expr_stmt|;
name|dst
operator|->
name|sector_number
operator|=
name|src
operator|->
name|sector_number
expr_stmt|;
name|barrier
argument_list|()
expr_stmt|;
if|if
condition|(
name|n
operator|>
name|dst
operator|->
name|nr_segments
condition|)
name|n
operator|=
name|dst
operator|->
name|nr_segments
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
name|i
operator|++
control|)
name|dst
operator|->
name|seg
index|[
name|i
index|]
operator|=
name|src
operator|->
name|seg
index|[
name|i
index|]
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_BLKIF_H__ */
end_comment

end_unit

