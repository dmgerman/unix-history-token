begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1998-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: buffer.h,v 1.39.12.2 2004/03/08 09:04:51 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_BUFFER_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_BUFFER_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * Buffers  *  * A buffer is a region of memory, together with a set of related subregions.  * Buffers are used for parsing and I/O operations.  *  * The 'used region' and the 'available' region are disjoint, and their  * union is the buffer's region.  The used region extends from the beginning  * of the buffer region to the last used byte.  The available region  * extends from one byte greater than the last used byte to the end of the  * buffer's region.  The size of the used region can be changed using various  * buffer commands.  Initially, the used region is empty.  *  * The used region is further subdivided into two disjoint regions: the  * 'consumed region' and the 'remaining region'.  The union of these two  * regions is the used region.  The consumed region extends from the beginning  * of the used region to the byte before the 'current' offset (if any).  The  * 'remaining' region the current pointer to the end of the used  * region.  The size of the consumed region can be changed using various  * buffer commands.  Initially, the consumed region is empty.  *  * The 'active region' is an (optional) subregion of the remaining region.  * It extends from the current offset to an offset in the remaining region  * that is selected with isc_buffer_setactive().  Initially, the active region  * is empty.  If the current offset advances beyond the chosen offset, the  * active region will also be empty.  *  *  /------------entire length---------------\  *  /----- used region -----\/-- available --\  *  +----------------------------------------+  *  | consumed  | remaining |                |  *  +----------------------------------------+  *  a           b     c     d                e  *  * a == base of buffer.  * b == current pointer.  Can be anywhere between a and d.  * c == active pointer.  Meaningful between b and d.  * d == used pointer.  * e == length of buffer.  *  * a-e == entire length of buffer.  * a-d == used region.  * a-b == consumed region.  * b-d == remaining region.  * b-c == optional active region.  *  * The following invariants are maintained by all routines:  *  *	length> 0  *  *	base is a valid pointer to length bytes of memory  *  *	0<= used<= length  *  *	0<= current<= used  *  *	0<= active<= used  *	(although active< current implies empty active region)  *  * MP:  *	Buffers have no synchronization.  Clients must ensure exclusive  *	access.  *  * Reliability:  *	No anticipated impact.  *  * Resources:  *	Memory: 1 pointer + 6 unsigned integers per buffer.  *  * Security:  *	No anticipated impact.  *  * Standards:  *	None.  */
end_comment

begin_comment
comment|/***  *** Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/magic.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_comment
comment|/*  * To make many functions be inline macros (via #define) define this.  * If it is undefined, a function will be used.  */
end_comment

begin_comment
comment|/* #define ISC_BUFFER_USEINLINE */
end_comment

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/***  *** Magic numbers  ***/
end_comment

begin_define
define|#
directive|define
name|ISC_BUFFER_MAGIC
value|0x42756621U
end_define

begin_comment
comment|/* Buf!. */
end_comment

begin_define
define|#
directive|define
name|ISC_BUFFER_VALID
parameter_list|(
name|b
parameter_list|)
value|ISC_MAGIC_VALID(b, ISC_BUFFER_MAGIC)
end_define

begin_comment
comment|/*  * The following macros MUST be used only on valid buffers.  It is the  * caller's responsibility to ensure this by using the ISC_BUFFER_VALID  * check above, or by calling another isc_buffer_*() function (rather than  * another macro.)  */
end_comment

begin_comment
comment|/*  * Fundamental buffer elements.  (A through E in the introductory comment.)  */
end_comment

begin_define
define|#
directive|define
name|isc_buffer_base
parameter_list|(
name|b
parameter_list|)
value|((void *)(b)->base)
end_define

begin_comment
comment|/*a*/
end_comment

begin_define
define|#
directive|define
name|isc_buffer_current
parameter_list|(
name|b
parameter_list|)
define|\
value|((void *)((unsigned char *)(b)->base + (b)->current))
end_define

begin_comment
comment|/*b*/
end_comment

begin_define
define|#
directive|define
name|isc_buffer_active
parameter_list|(
name|b
parameter_list|)
define|\
value|((void *)((unsigned char *)(b)->base + (b)->active))
end_define

begin_comment
comment|/*c*/
end_comment

begin_define
define|#
directive|define
name|isc_buffer_used
parameter_list|(
name|b
parameter_list|)
define|\
value|((void *)((unsigned char *)(b)->base + (b)->used))
end_define

begin_comment
comment|/*d*/
end_comment

begin_define
define|#
directive|define
name|isc_buffer_length
parameter_list|(
name|b
parameter_list|)
value|((b)->length)
end_define

begin_comment
comment|/*e*/
end_comment

begin_comment
comment|/*  * Derived lengths.  (Described in the introductory comment.)  */
end_comment

begin_define
define|#
directive|define
name|isc_buffer_usedlength
parameter_list|(
name|b
parameter_list|)
value|((b)->used)
end_define

begin_comment
comment|/* d-a */
end_comment

begin_define
define|#
directive|define
name|isc_buffer_consumedlength
parameter_list|(
name|b
parameter_list|)
value|((b)->current)
end_define

begin_comment
comment|/* b-a */
end_comment

begin_define
define|#
directive|define
name|isc_buffer_remaininglength
parameter_list|(
name|b
parameter_list|)
value|((b)->used - (b)->current)
end_define

begin_comment
comment|/* d-b */
end_comment

begin_define
define|#
directive|define
name|isc_buffer_activelength
parameter_list|(
name|b
parameter_list|)
value|((b)->active - (b)->current)
end_define

begin_comment
comment|/* c-b */
end_comment

begin_define
define|#
directive|define
name|isc_buffer_availablelength
parameter_list|(
name|b
parameter_list|)
value|((b)->length - (b)->used)
end_define

begin_comment
comment|/* e-d */
end_comment

begin_comment
comment|/*  * Note that the buffer structure is public.  This is principally so buffer  * operations can be implemented using macros.  Applications are strongly  * discouraged from directly manipulating the structure.  */
end_comment

begin_struct
struct|struct
name|isc_buffer
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
name|void
modifier|*
name|base
decl_stmt|;
comment|/* The following integers are byte offsets from 'base'. */
name|unsigned
name|int
name|length
decl_stmt|;
name|unsigned
name|int
name|used
decl_stmt|;
name|unsigned
name|int
name|current
decl_stmt|;
name|unsigned
name|int
name|active
decl_stmt|;
comment|/* linkable */
name|ISC_LINK
argument_list|(
argument|isc_buffer_t
argument_list|)
name|link
expr_stmt|;
comment|/* private internal elements */
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/***  *** Functions  ***/
end_comment

begin_function_decl
name|isc_result_t
name|isc_buffer_allocate
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_buffer_t
modifier|*
modifier|*
name|dynbuffer
parameter_list|,
name|unsigned
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Allocate a dynamic linkable buffer which has "length" bytes in the  * data region.  *  * Requires:  *	"mctx" is valid.  *  *	"dynbuffer" is non-NULL, and "*dynbuffer" is NULL.  *  * Returns:  *	ISC_R_SUCCESS		- success  *	ISC_R_NOMEMORY		- no memory available  *  * Note:  *	Changing the buffer's length field is not permitted.  */
end_comment

begin_function_decl
name|void
name|isc_buffer_free
parameter_list|(
name|isc_buffer_t
modifier|*
modifier|*
name|dynbuffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Release resources allocated for a dynamic buffer.  *  * Requires:  *	"dynbuffer" is not NULL.  *  *	"*dynbuffer" is a valid dynamic buffer.  *  * Ensures:  *	"*dynbuffer" will be NULL on return, and all memory associated with  *	the dynamic buffer is returned to the memory context used in  *	isc_buffer_allocate().  */
end_comment

begin_function_decl
name|void
name|isc__buffer_init
parameter_list|(
name|isc_buffer_t
modifier|*
name|b
parameter_list|,
specifier|const
name|void
modifier|*
name|base
parameter_list|,
name|unsigned
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Make 'b' refer to the 'length'-byte region starting at base.  *  * Requires:  *  *	'length'> 0  *  *	'base' is a pointer to a sequence of 'length' bytes.  *  */
end_comment

begin_function_decl
name|void
name|isc__buffer_invalidate
parameter_list|(
name|isc_buffer_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Make 'b' an invalid buffer.  *  * Requires:  *	'b' is a valid buffer.  *  * Ensures:  *	If assertion checking is enabled, future attempts to use 'b' without  *	calling isc_buffer_init() on it will cause an assertion failure.  */
end_comment

begin_function_decl
name|void
name|isc__buffer_region
parameter_list|(
name|isc_buffer_t
modifier|*
name|b
parameter_list|,
name|isc_region_t
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Make 'r' refer to the region of 'b'.  *  * Requires:  *  *	'b' is a valid buffer.  *  *	'r' points to a region structure.  */
end_comment

begin_function_decl
name|void
name|isc__buffer_usedregion
parameter_list|(
name|isc_buffer_t
modifier|*
name|b
parameter_list|,
name|isc_region_t
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Make 'r' refer to the used region of 'b'.  *  * Requires:  *  *	'b' is a valid buffer.  *  *	'r' points to a region structure.  */
end_comment

begin_function_decl
name|void
name|isc__buffer_availableregion
parameter_list|(
name|isc_buffer_t
modifier|*
name|b
parameter_list|,
name|isc_region_t
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Make 'r' refer to the available region of 'b'.  *  * Requires:  *  *	'b' is a valid buffer.  *  *	'r' points to a region structure.  */
end_comment

begin_function_decl
name|void
name|isc__buffer_add
parameter_list|(
name|isc_buffer_t
modifier|*
name|b
parameter_list|,
name|unsigned
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Increase the 'used' region of 'b' by 'n' bytes.  *  * Requires:  *  *	'b' is a valid buffer  *  *	used + n<= length  *  */
end_comment

begin_function_decl
name|void
name|isc__buffer_subtract
parameter_list|(
name|isc_buffer_t
modifier|*
name|b
parameter_list|,
name|unsigned
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Decrease the 'used' region of 'b' by 'n' bytes.  *  * Requires:  *  *	'b' is a valid buffer  *  *	used>= n  *  */
end_comment

begin_function_decl
name|void
name|isc__buffer_clear
parameter_list|(
name|isc_buffer_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Make the used region empty.  *  * Requires:  *  *	'b' is a valid buffer  *  * Ensures:  *  *	used = 0  *  */
end_comment

begin_function_decl
name|void
name|isc__buffer_consumedregion
parameter_list|(
name|isc_buffer_t
modifier|*
name|b
parameter_list|,
name|isc_region_t
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Make 'r' refer to the consumed region of 'b'.  *  * Requires:  *  *	'b' is a valid buffer.  *  *	'r' points to a region structure.  */
end_comment

begin_function_decl
name|void
name|isc__buffer_remainingregion
parameter_list|(
name|isc_buffer_t
modifier|*
name|b
parameter_list|,
name|isc_region_t
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Make 'r' refer to the remaining region of 'b'.  *  * Requires:  *  *	'b' is a valid buffer.  *  *	'r' points to a region structure.  */
end_comment

begin_function_decl
name|void
name|isc__buffer_activeregion
parameter_list|(
name|isc_buffer_t
modifier|*
name|b
parameter_list|,
name|isc_region_t
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Make 'r' refer to the active region of 'b'.  *  * Requires:  *  *	'b' is a valid buffer.  *  *	'r' points to a region structure.  */
end_comment

begin_function_decl
name|void
name|isc__buffer_setactive
parameter_list|(
name|isc_buffer_t
modifier|*
name|b
parameter_list|,
name|unsigned
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Sets the end of the active region 'n' bytes after current.  *  * Requires:  *  *	'b' is a valid buffer.  *  *	current + n<= used  */
end_comment

begin_function_decl
name|void
name|isc__buffer_first
parameter_list|(
name|isc_buffer_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Make the consumed region empty.  *  * Requires:  *  *	'b' is a valid buffer  *  * Ensures:  *  *	current == 0  *  */
end_comment

begin_function_decl
name|void
name|isc__buffer_forward
parameter_list|(
name|isc_buffer_t
modifier|*
name|b
parameter_list|,
name|unsigned
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Increase the 'consumed' region of 'b' by 'n' bytes.  *  * Requires:  *  *	'b' is a valid buffer  *  *	current + n<= used  *  */
end_comment

begin_function_decl
name|void
name|isc__buffer_back
parameter_list|(
name|isc_buffer_t
modifier|*
name|b
parameter_list|,
name|unsigned
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Decrease the 'consumed' region of 'b' by 'n' bytes.  *  * Requires:  *  *	'b' is a valid buffer  *  *	n<= current  *  */
end_comment

begin_function_decl
name|void
name|isc_buffer_compact
parameter_list|(
name|isc_buffer_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Compact the used region by moving the remaining region so it occurs  * at the start of the buffer.  The used region is shrunk by the size of  * the consumed region, and the consumed region is then made empty.  *  * Requires:  *  *	'b' is a valid buffer  *  * Ensures:  *  *	current == 0  *  *	The size of the used region is now equal to the size of the remaining  *	region (as it was before the call).  The contents of the used region  *	are those of the remaining region (as it was before the call).  */
end_comment

begin_function_decl
name|isc_uint8_t
name|isc_buffer_getuint8
parameter_list|(
name|isc_buffer_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Read an unsigned 8-bit integer from 'b' and return it.  *  * Requires:  *  *	'b' is a valid buffer.  *  *	The length of the available region of 'b' is at least 1.  *  * Ensures:  *  *	The current pointer in 'b' is advanced by 1.  *  * Returns:  *  *	A 8-bit unsigned integer.  */
end_comment

begin_function_decl
name|void
name|isc__buffer_putuint8
parameter_list|(
name|isc_buffer_t
modifier|*
name|b
parameter_list|,
name|isc_uint8_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Store an unsigned 8-bit integer from 'val' into 'b'.  *  * Requires:  *	'b' is a valid buffer.  *  *	The length of the unused region of 'b' is at least 1.  *  * Ensures:  *	The used pointer in 'b' is advanced by 1.  */
end_comment

begin_function_decl
name|isc_uint16_t
name|isc_buffer_getuint16
parameter_list|(
name|isc_buffer_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Read an unsigned 16-bit integer in network byte order from 'b', convert  * it to host byte order, and return it.  *  * Requires:  *  *	'b' is a valid buffer.  *  *	The length of the available region of 'b' is at least 2.  *  * Ensures:  *  *	The current pointer in 'b' is advanced by 2.  *  * Returns:  *  *	A 16-bit unsigned integer.  */
end_comment

begin_function_decl
name|void
name|isc__buffer_putuint16
parameter_list|(
name|isc_buffer_t
modifier|*
name|b
parameter_list|,
name|isc_uint16_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Store an unsigned 16-bit integer in host byte order from 'val'  * into 'b' in network byte order.  *  * Requires:  *	'b' is a valid buffer.  *  *	The length of the unused region of 'b' is at least 2.  *  * Ensures:  *	The used pointer in 'b' is advanced by 2.  */
end_comment

begin_function_decl
name|isc_uint32_t
name|isc_buffer_getuint32
parameter_list|(
name|isc_buffer_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Read an unsigned 32-bit integer in network byte order from 'b', convert  * it to host byte order, and return it.  *  * Requires:  *  *	'b' is a valid buffer.  *  *	The length of the available region of 'b' is at least 4.  *  * Ensures:  *  *	The current pointer in 'b' is advanced by 4.  *  * Returns:  *  *	A 32-bit unsigned integer.  */
end_comment

begin_function_decl
name|void
name|isc__buffer_putuint32
parameter_list|(
name|isc_buffer_t
modifier|*
name|b
parameter_list|,
name|isc_uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Store an unsigned 32-bit integer in host byte order from 'val'  * into 'b' in network byte order.  *  * Requires:  *	'b' is a valid buffer.  *  *	The length of the unused region of 'b' is at least 4.  *  * Ensures:  *	The used pointer in 'b' is advanced by 4.  */
end_comment

begin_function_decl
name|void
name|isc__buffer_putmem
parameter_list|(
name|isc_buffer_t
modifier|*
name|b
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|base
parameter_list|,
name|unsigned
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Copy 'length' bytes of memory at 'base' into 'b'.  *  * Requires:  *	'b' is a valid buffer.  *  *	'base' points to 'length' bytes of valid memory.  *  */
end_comment

begin_function_decl
name|void
name|isc__buffer_putstr
parameter_list|(
name|isc_buffer_t
modifier|*
name|b
parameter_list|,
specifier|const
name|char
modifier|*
name|source
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Copy 'source' into 'b', not including terminating NUL.  *  * Requires:  *	'b' is a valid buffer.  *  *	'source' to be a valid NULL terminated string.  *  *	strlen(source)<= isc_buffer_available(b)  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_buffer_copyregion
parameter_list|(
name|isc_buffer_t
modifier|*
name|b
parameter_list|,
specifier|const
name|isc_region_t
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Copy the contents of 'r' into 'b'.  *  * Requires:  *	'b' is a valid buffer.  *  *	'r' is a valid region.  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOSPACE			The available region of 'b' is not  *					big enough.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_comment
comment|/*  * Inline macro versions of the functions.  These should never be called  * directly by an application, but will be used by the functions within  * buffer.c.  The callers should always use "isc_buffer_*()" names, never  * ones beginning with "isc__"  */
end_comment

begin_comment
comment|/*  * XXXDCL Something more could be done with initializing buffers that  * point to const data.  For example, a new function, isc_buffer_initconst,  * could be used, and a new boolean flag in the buffer structure could  * indicate whether the buffer was initialized with that function.  * (isc_bufer_init itself would be reprototyped to *not* have its "base"  * parameter be const.)  Then if the boolean were true, the isc_buffer_put*  * functions could assert a contractual requirement for a non-const buffer.  * One drawback is that the isc_buffer_* functions (macros) that return  * pointers would still need to return non-const pointers to avoid compiler  * warnings, so it would be up to code that uses them to have to deal  * with the possibility that the buffer was initialized as const --  * a problem that they *already* have to deal with but have absolutely  * no ability to.  With a new isc_buffer_isconst() function returning  * true/false, they could at least assert a contractual requirement for  * non-const buffers when needed.  */
end_comment

begin_define
define|#
directive|define
name|ISC__BUFFER_INIT
parameter_list|(
name|_b
parameter_list|,
name|_base
parameter_list|,
name|_length
parameter_list|)
define|\
value|do { \ 		union { \ 			const void *	konst; \ 			void *		var; \ 		} _u; \ 		_u.konst = (_base); \ 		(_b)->base = _u.var; \ 		(_b)->length = (_length); \ 		(_b)->used = 0; \ 		(_b)->current = 0; \ 		(_b)->active = 0; \ 		(_b)->mctx = NULL; \ 		ISC_LINK_INIT(_b, link); \ 		(_b)->magic = ISC_BUFFER_MAGIC; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC__BUFFER_INVALIDATE
parameter_list|(
name|_b
parameter_list|)
define|\
value|do { \ 		(_b)->magic = 0; \ 		(_b)->base = NULL; \ 		(_b)->length = 0; \ 		(_b)->used = 0; \ 		(_b)->current = 0; \ 		(_b)->active = 0; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC__BUFFER_REGION
parameter_list|(
name|_b
parameter_list|,
name|_r
parameter_list|)
define|\
value|do { \ 		(_r)->base = (_b)->base; \ 		(_r)->length = (_b)->length; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC__BUFFER_USEDREGION
parameter_list|(
name|_b
parameter_list|,
name|_r
parameter_list|)
define|\
value|do { \ 		(_r)->base = (_b)->base; \ 		(_r)->length = (_b)->used; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC__BUFFER_AVAILABLEREGION
parameter_list|(
name|_b
parameter_list|,
name|_r
parameter_list|)
define|\
value|do { \ 		(_r)->base = isc_buffer_used(_b); \ 		(_r)->length = isc_buffer_availablelength(_b); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC__BUFFER_ADD
parameter_list|(
name|_b
parameter_list|,
name|_n
parameter_list|)
define|\
value|do { \ 		(_b)->used += (_n); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC__BUFFER_SUBTRACT
parameter_list|(
name|_b
parameter_list|,
name|_n
parameter_list|)
define|\
value|do { \ 		(_b)->used -= (_n); \ 		if ((_b)->current> (_b)->used) \ 			(_b)->current = (_b)->used; \ 		if ((_b)->active> (_b)->used) \ 			(_b)->active = (_b)->used; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC__BUFFER_CLEAR
parameter_list|(
name|_b
parameter_list|)
define|\
value|do { \ 		(_b)->used = 0; \ 		(_b)->current = 0; \ 		(_b)->active = 0; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC__BUFFER_CONSUMEDREGION
parameter_list|(
name|_b
parameter_list|,
name|_r
parameter_list|)
define|\
value|do { \ 		(_r)->base = (_b)->base; \ 		(_r)->length = (_b)->current; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC__BUFFER_REMAININGREGION
parameter_list|(
name|_b
parameter_list|,
name|_r
parameter_list|)
define|\
value|do { \ 		(_r)->base = isc_buffer_current(_b); \ 		(_r)->length = isc_buffer_remaininglength(_b); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC__BUFFER_ACTIVEREGION
parameter_list|(
name|_b
parameter_list|,
name|_r
parameter_list|)
define|\
value|do { \ 		if ((_b)->current< (_b)->active) { \ 			(_r)->base = isc_buffer_current(_b); \ 			(_r)->length = isc_buffer_activelength(_b); \ 		} else { \ 			(_r)->base = NULL; \ 			(_r)->length = 0; \ 		} \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC__BUFFER_SETACTIVE
parameter_list|(
name|_b
parameter_list|,
name|_n
parameter_list|)
define|\
value|do { \ 		(_b)->active = (_b)->current + (_n); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC__BUFFER_FIRST
parameter_list|(
name|_b
parameter_list|)
define|\
value|do { \ 		(_b)->current = 0; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC__BUFFER_FORWARD
parameter_list|(
name|_b
parameter_list|,
name|_n
parameter_list|)
define|\
value|do { \ 		(_b)->current += (_n); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC__BUFFER_BACK
parameter_list|(
name|_b
parameter_list|,
name|_n
parameter_list|)
define|\
value|do { \ 		(_b)->current -= (_n); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC__BUFFER_PUTMEM
parameter_list|(
name|_b
parameter_list|,
name|_base
parameter_list|,
name|_length
parameter_list|)
define|\
value|do { \ 		memcpy(isc_buffer_used(_b), (_base), (_length)); \ 		(_b)->used += (_length); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC__BUFFER_PUTSTR
parameter_list|(
name|_b
parameter_list|,
name|_source
parameter_list|)
define|\
value|do { \ 		unsigned int _length; \ 		unsigned char *_cp; \ 		_length = strlen(_source); \ 		_cp = isc_buffer_used(_b); \ 		memcpy(_cp, (_source), _length); \ 		(_b)->used += (_length); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC__BUFFER_PUTUINT8
parameter_list|(
name|_b
parameter_list|,
name|_val
parameter_list|)
define|\
value|do { \ 		unsigned char *_cp; \ 		isc_uint8_t _val2 = (_val); \ 		_cp = isc_buffer_used(_b); \ 		(_b)->used++; \ 		_cp[0] = _val2& 0x00ff; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC__BUFFER_PUTUINT16
parameter_list|(
name|_b
parameter_list|,
name|_val
parameter_list|)
define|\
value|do { \ 		unsigned char *_cp; \ 		isc_uint16_t _val2 = (_val); \ 		_cp = isc_buffer_used(_b); \ 		(_b)->used += 2; \ 		_cp[0] = (unsigned char)((_val2& 0xff00U)>> 8); \ 		_cp[1] = (unsigned char)(_val2& 0x00ffU); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ISC__BUFFER_PUTUINT32
parameter_list|(
name|_b
parameter_list|,
name|_val
parameter_list|)
define|\
value|do { \ 		unsigned char *_cp; \ 		isc_uint32_t _val2 = (_val); \ 		_cp = isc_buffer_used(_b); \ 		(_b)->used += 4; \ 		_cp[0] = (unsigned char)((_val2& 0xff000000)>> 24); \ 		_cp[1] = (unsigned char)((_val2& 0x00ff0000)>> 16); \ 		_cp[2] = (unsigned char)((_val2& 0x0000ff00)>> 8); \ 		_cp[3] = (unsigned char)((_val2& 0x000000ff)); \ 	} while (0)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ISC_BUFFER_USEINLINE
argument_list|)
end_if

begin_define
define|#
directive|define
name|isc_buffer_init
value|ISC__BUFFER_INIT
end_define

begin_define
define|#
directive|define
name|isc_buffer_invalidate
value|ISC__BUFFER_INVALIDATE
end_define

begin_define
define|#
directive|define
name|isc_buffer_region
value|ISC__BUFFER_REGION
end_define

begin_define
define|#
directive|define
name|isc_buffer_usedregion
value|ISC__BUFFER_USEDREGION
end_define

begin_define
define|#
directive|define
name|isc_buffer_availableregion
value|ISC__BUFFER_AVAILABLEREGION
end_define

begin_define
define|#
directive|define
name|isc_buffer_add
value|ISC__BUFFER_ADD
end_define

begin_define
define|#
directive|define
name|isc_buffer_subtract
value|ISC__BUFFER_SUBTRACT
end_define

begin_define
define|#
directive|define
name|isc_buffer_clear
value|ISC__BUFFER_CLEAR
end_define

begin_define
define|#
directive|define
name|isc_buffer_consumedregion
value|ISC__BUFFER_CONSUMEDREGION
end_define

begin_define
define|#
directive|define
name|isc_buffer_remainingregion
value|ISC__BUFFER_REMAININGREGION
end_define

begin_define
define|#
directive|define
name|isc_buffer_activeregion
value|ISC__BUFFER_ACTIVEREGION
end_define

begin_define
define|#
directive|define
name|isc_buffer_setactive
value|ISC__BUFFER_SETACTIVE
end_define

begin_define
define|#
directive|define
name|isc_buffer_first
value|ISC__BUFFER_FIRST
end_define

begin_define
define|#
directive|define
name|isc_buffer_forward
value|ISC__BUFFER_FORWARD
end_define

begin_define
define|#
directive|define
name|isc_buffer_back
value|ISC__BUFFER_BACK
end_define

begin_define
define|#
directive|define
name|isc_buffer_putmem
value|ISC__BUFFER_PUTMEM
end_define

begin_define
define|#
directive|define
name|isc_buffer_putstr
value|ISC__BUFFER_PUTSTR
end_define

begin_define
define|#
directive|define
name|isc_buffer_putuint8
value|ISC__BUFFER_PUTUINT8
end_define

begin_define
define|#
directive|define
name|isc_buffer_putuint16
value|ISC__BUFFER_PUTUINT16
end_define

begin_define
define|#
directive|define
name|isc_buffer_putuint32
value|ISC__BUFFER_PUTUINT32
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|isc_buffer_init
value|isc__buffer_init
end_define

begin_define
define|#
directive|define
name|isc_buffer_invalidate
value|isc__buffer_invalidate
end_define

begin_define
define|#
directive|define
name|isc_buffer_region
value|isc__buffer_region
end_define

begin_define
define|#
directive|define
name|isc_buffer_usedregion
value|isc__buffer_usedregion
end_define

begin_define
define|#
directive|define
name|isc_buffer_availableregion
value|isc__buffer_availableregion
end_define

begin_define
define|#
directive|define
name|isc_buffer_add
value|isc__buffer_add
end_define

begin_define
define|#
directive|define
name|isc_buffer_subtract
value|isc__buffer_subtract
end_define

begin_define
define|#
directive|define
name|isc_buffer_clear
value|isc__buffer_clear
end_define

begin_define
define|#
directive|define
name|isc_buffer_consumedregion
value|isc__buffer_consumedregion
end_define

begin_define
define|#
directive|define
name|isc_buffer_remainingregion
value|isc__buffer_remainingregion
end_define

begin_define
define|#
directive|define
name|isc_buffer_activeregion
value|isc__buffer_activeregion
end_define

begin_define
define|#
directive|define
name|isc_buffer_setactive
value|isc__buffer_setactive
end_define

begin_define
define|#
directive|define
name|isc_buffer_first
value|isc__buffer_first
end_define

begin_define
define|#
directive|define
name|isc_buffer_forward
value|isc__buffer_forward
end_define

begin_define
define|#
directive|define
name|isc_buffer_back
value|isc__buffer_back
end_define

begin_define
define|#
directive|define
name|isc_buffer_putmem
value|isc__buffer_putmem
end_define

begin_define
define|#
directive|define
name|isc_buffer_putstr
value|isc__buffer_putstr
end_define

begin_define
define|#
directive|define
name|isc_buffer_putuint8
value|isc__buffer_putuint8
end_define

begin_define
define|#
directive|define
name|isc_buffer_putuint16
value|isc__buffer_putuint16
end_define

begin_define
define|#
directive|define
name|isc_buffer_putuint32
value|isc__buffer_putuint32
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
comment|/* ISC_BUFFER_H */
end_comment

end_unit

