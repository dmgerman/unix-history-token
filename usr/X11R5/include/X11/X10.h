begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: X10.h,v 11.11 89/07/21 13:37:37 jim Exp $ */
end_comment

begin_comment
comment|/*   * Copyright 1985, 1986, 1987 by the Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided   * that the above copyright notice appear in all copies and that both that   * copyright notice and this permission notice appear in supporting   * documentation, and that the name of M.I.T. not be used in advertising  * or publicity pertaining to distribution of the software without specific,   * written prior permission. M.I.T. makes no representations about the   * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * The X Window System is a Trademark of MIT.  *  */
end_comment

begin_comment
comment|/*  *	X10.h - Header definition and support file for the C subroutine  *	interface library for V10 support routines.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_X10_H_
end_ifndef

begin_define
define|#
directive|define
name|_X10_H_
end_define

begin_comment
comment|/* Used in XDraw and XDrawFilled */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|x
decl_stmt|,
name|y
decl_stmt|;
name|unsigned
name|short
name|flags
decl_stmt|;
block|}
name|Vertex
typedef|;
end_typedef

begin_comment
comment|/* The meanings of the flag bits.  If the bit is 1 the predicate is true */
end_comment

begin_define
define|#
directive|define
name|VertexRelative
value|0x0001
end_define

begin_comment
comment|/* else absolute */
end_comment

begin_define
define|#
directive|define
name|VertexDontDraw
value|0x0002
end_define

begin_comment
comment|/* else draw */
end_comment

begin_define
define|#
directive|define
name|VertexCurved
value|0x0004
end_define

begin_comment
comment|/* else straight */
end_comment

begin_define
define|#
directive|define
name|VertexStartClosed
value|0x0008
end_define

begin_comment
comment|/* else not */
end_comment

begin_define
define|#
directive|define
name|VertexEndClosed
value|0x0010
end_define

begin_comment
comment|/* else not */
end_comment

begin_comment
comment|/*#define VertexDrawLastPoint	0x0020 	*/
end_comment

begin_comment
comment|/* else don't */
end_comment

begin_comment
comment|/* The VertexDrawLastPoint option has not been implemented in XDraw and  XDrawFilled so it shouldn't be defined.  */
end_comment

begin_comment
comment|/*  * XAssoc - Associations used in the XAssocTable data structure.  The   * associations are used as circular queue entries in the association table  * which is contains an array of circular queues (buckets).  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_XAssoc
block|{
name|struct
name|_XAssoc
modifier|*
name|next
decl_stmt|;
comment|/* Next object in this bucket. */
name|struct
name|_XAssoc
modifier|*
name|prev
decl_stmt|;
comment|/* Previous obejct in this bucket. */
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* Display which ownes the id. */
name|XID
name|x_id
decl_stmt|;
comment|/* X Window System id. */
name|char
modifier|*
name|data
decl_stmt|;
comment|/* Pointer to untyped memory. */
block|}
name|XAssoc
typedef|;
end_typedef

begin_comment
comment|/*   * XAssocTable - X Window System id to data structure pointer association  * table.  An XAssocTable is a hash table whose buckets are circular  * queues of XAssoc's.  The XAssocTable is constructed from an array of  * XAssoc's which are the circular queue headers (bucket headers).    * An XAssocTable consists an XAssoc pointer that points to the first  * bucket in the bucket array and an integer that indicates the number  * of buckets in the array.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|XAssoc
modifier|*
name|buckets
decl_stmt|;
comment|/* Pointer to first bucket in bucket array.*/
name|int
name|size
decl_stmt|;
comment|/* Table size (number of buckets). */
block|}
name|XAssocTable
typedef|;
end_typedef

begin_function_decl
name|XAssocTable
modifier|*
name|XCreateAssocTable
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|XLookUpAssoc
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _X10_H_ */
end_comment

end_unit

