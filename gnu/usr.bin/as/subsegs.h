begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* subsegs.h -> subsegs.c     Copyright (C) 1987, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * For every sub-segment the user mentions in the ASsembler program,  * we make one struct frchain. Each sub-segment has exactly one struct frchain  * and vice versa.  *  * Struct frchain's are forward chained (in ascending order of sub-segment  * code number). The chain runs through frch_next of each subsegment.  * This makes it hard to find a subsegment's frags  * if programmer uses a lot of them. Most programs only use text0 and  * data0, so they don't suffer. At least this way:  * (1)	There are no "arbitrary" restrictions on how many subsegments  *	can be programmed;  * (2)	Subsegments' frchain-s are (later) chained together in the order in  *	which they are emitted for object file viz text then data.  *  * From each struct frchain dangles a chain of struct frags. The frags  * represent code fragments, for that sub-segment, forward chained.  */
end_comment

begin_struct
struct|struct
name|frchain
comment|/* control building of a frag chain */
block|{
comment|/* FRCH = FRagment CHain control */
name|struct
name|frag
modifier|*
name|frch_root
decl_stmt|;
comment|/* 1st struct frag in chain, or NULL */
name|struct
name|frag
modifier|*
name|frch_last
decl_stmt|;
comment|/* last struct frag in chain, or NULL */
name|struct
name|frchain
modifier|*
name|frch_next
decl_stmt|;
comment|/* next in chain of struct frchain-s */
name|segT
name|frch_seg
decl_stmt|;
comment|/* SEG_TEXT or SEG_DATA. */
name|subsegT
name|frch_subseg
decl_stmt|;
comment|/* subsegment number of this chain */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|frchain
name|frchainS
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|frchainS
modifier|*
name|frchain_root
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NULL means no frchains yet. */
end_comment

begin_comment
comment|/* all subsegments' chains hang off here */
end_comment

begin_decl_stmt
specifier|extern
name|frchainS
modifier|*
name|frchain_now
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Frchain we are assembling into now */
end_comment

begin_comment
comment|/* That is, the current segment's frag */
end_comment

begin_comment
comment|/* chain, even if it contains no (complete) */
end_comment

begin_comment
comment|/* frags. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MANY_SEGMENTS
end_ifdef

begin_typedef
typedef|typedef
struct|struct
block|{
name|frchainS
modifier|*
name|frchainP
decl_stmt|;
name|int
name|hadone
decl_stmt|;
name|int
name|user_stuff
decl_stmt|;
comment|/*  struct frag *frag_root;*/
comment|/*  struct frag *last_frag;*/
name|fixS
modifier|*
name|fix_root
decl_stmt|;
name|fixS
modifier|*
name|fix_tail
decl_stmt|;
name|struct
name|internal_scnhdr
name|scnhdr
decl_stmt|;
name|symbolS
modifier|*
name|dot
decl_stmt|;
name|struct
name|lineno_list
modifier|*
name|lineno_list_head
decl_stmt|;
name|struct
name|lineno_list
modifier|*
name|lineno_list_tail
decl_stmt|;
block|}
name|segment_info_type
typedef|;
end_typedef

begin_decl_stmt
name|segment_info_type
name|segment_info
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|frchainS
modifier|*
name|data0_frchainP
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|frchainS
modifier|*
name|bss0_frchainP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Sentinel for frchain crawling. */
end_comment

begin_comment
comment|/* Points to the 1st data-segment frchain. */
end_comment

begin_comment
comment|/* (Which is pointed to by the last text- */
end_comment

begin_comment
comment|/* segment frchain.) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* end of subsegs.h */
end_comment

end_unit

