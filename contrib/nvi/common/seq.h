begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1992, 1993, 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  *  * See the LICENSE file for redistribution information.  *  *	@(#)seq.h	10.3 (Berkeley) 3/6/96  */
end_comment

begin_comment
comment|/*  * Map and abbreviation structures.  *  * The map structure is doubly linked list, sorted by input string and by  * input length within the string.  (The latter is necessary so that short  * matches will happen before long matches when the list is searched.)  * Additionally, there is a bitmap which has bits set if there are entries  * starting with the corresponding character.  This keeps us from walking  * the list unless it's necessary.  *  * The name and the output fields of a SEQ can be empty, i.e. NULL.  * Only the input field is required.  *  * XXX  * The fast-lookup bits are never turned off -- users don't usually unmap  * things, though, so it's probably not a big deal.  */
end_comment

begin_struct
struct|struct
name|_seq
block|{
name|LIST_ENTRY
argument_list|(
argument|_seq
argument_list|)
name|q
expr_stmt|;
comment|/* Linked list of all sequences. */
name|seq_t
name|stype
decl_stmt|;
comment|/* Sequence type. */
name|CHAR_T
modifier|*
name|name
decl_stmt|;
comment|/* Sequence name (if any). */
name|size_t
name|nlen
decl_stmt|;
comment|/* Name length. */
name|CHAR_T
modifier|*
name|input
decl_stmt|;
comment|/* Sequence input keys. */
name|size_t
name|ilen
decl_stmt|;
comment|/* Input keys length. */
name|CHAR_T
modifier|*
name|output
decl_stmt|;
comment|/* Sequence output keys. */
name|size_t
name|olen
decl_stmt|;
comment|/* Output keys length. */
define|#
directive|define
name|SEQ_FUNCMAP
value|0x01
comment|/* If unresolved function key.*/
define|#
directive|define
name|SEQ_NOOVERWRITE
value|0x02
comment|/* Don't replace existing entry. */
define|#
directive|define
name|SEQ_SCREEN
value|0x04
comment|/* If screen specific. */
define|#
directive|define
name|SEQ_USERDEF
value|0x08
comment|/* If user defined. */
name|u_int8_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

end_unit

