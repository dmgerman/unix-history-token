begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)assyms.h	5.1 (Berkeley) 4/30/85  */
end_comment

begin_comment
comment|/*  *	To speed up walks through symbols defined in a particular  *	segment, we buil up a table of pointers into the symbol table  *	and a table of delimiters for each segment.  The delimiter for  *	the particular segment points to the first word in that segment.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|symtab
modifier|*
modifier|*
name|symptrs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*dynamically allocated*/
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|symtab
modifier|*
modifier|*
name|symdelim
index|[
name|NLOC
operator|+
name|NLOC
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|symtab
modifier|*
modifier|*
name|symptrub
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nsyms
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*number in the symbol table*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|njxxx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*the number of jxxx entries in the table*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nforgotten
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*how many entries erroneously entered*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nlabels
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*how many labels in the symbol table*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|hshused
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*how many hash slots used*/
end_comment

begin_define
define|#
directive|define
name|SEGITERATE
parameter_list|(
name|segno
parameter_list|,
name|start
parameter_list|,
name|end
parameter_list|,
name|copointer
parameter_list|,
name|walkpointer
parameter_list|,
name|ubpointer
parameter_list|,
name|direction
parameter_list|)
define|\
value|for(copointer = start == 0? symdelim[segno]:start,\ 	    ubpointer = end == 0 ? *symdelim[segno+1] : *(symdelim[segno]-1),\ 	    walkpointer = *copointer;\ 	    walkpointer != ubpointer;\ 	    walkpointer = * direction copointer)
end_define

begin_define
define|#
directive|define
name|SYMITERATE
parameter_list|(
name|copointer
parameter_list|,
name|walkpointer
parameter_list|)
define|\
value|for(copointer = symptrs, \ 	    walkpointer = *copointer; \ 	    copointer< symptrub; \ 	    walkpointer = * ++ copointer)
end_define

begin_comment
comment|/*  *	Symbols are allocated in non contiguous chunks by extending  *	the data area.  */
end_comment

begin_define
define|#
directive|define
name|SYMDALLOP
value|200
end_define

begin_struct
struct|struct
name|allocbox
block|{
name|struct
name|allocbox
modifier|*
name|nextalloc
decl_stmt|;
name|struct
name|symtab
name|symslots
index|[
name|SYMDALLOP
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Names are allocated in a dynamically extensible string pool.  */
end_comment

begin_struct
struct|struct
name|strpool
block|{
name|struct
name|strpool
modifier|*
name|str_next
decl_stmt|;
name|int
name|str_nalloc
decl_stmt|;
name|char
name|str_names
index|[
name|STRPOOLDALLOP
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|strpool
modifier|*
name|strplhead
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|allocbox
modifier|*
name|allochead
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|allocbox
modifier|*
name|alloctail
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|symtab
modifier|*
name|nextsym
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|allocbox
modifier|*
name|newbox
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|namebuffer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|symsleft
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ALLOCQTY
value|sizeof (struct allocbox)
end_define

begin_comment
comment|/*  *	Iterate through all symbols in the symbol table in declaration  *	order  */
end_comment

begin_define
define|#
directive|define
name|DECLITERATE
parameter_list|(
name|allocwalk
parameter_list|,
name|walkpointer
parameter_list|,
name|ubpointer
parameter_list|)
define|\
value|for(allocwalk = allochead; \ 	    allocwalk != 0; \ 	    allocwalk = allocwalk->nextalloc) \ 		for (walkpointer =&allocwalk->symslots[0],\ 		        ubpointer =&allocwalk->symslots[SYMDALLOP], \ 		        ubpointer = ubpointer> ( (struct symtab *)alloctail) \ 				 ? nextsym : ubpointer ;\ 		     walkpointer< ubpointer; \ 		     walkpointer++ )
end_define

begin_comment
comment|/*  *	The hash table is segmented, and dynamically extendable.  *	We have a linked list of hash table segments; within each  *	segment we use a quadratic rehash that touches no more than 1/2  *	of the buckets in the hash table when probing.  *	If the probe does not find the desired symbol, it moves to the  *	next segment, or allocates a new segment.  *  *	Hash table segments are kept on the linked list with the first  *	segment always first (that contains the reserved words) and  *	the last added segment immediately after the first segment  *	to hopefully gain something by locality of reference.  */
end_comment

begin_struct
struct|struct
name|hashdallop
block|{
name|int
name|h_nused
decl_stmt|;
name|struct
name|hashdallop
modifier|*
name|h_next
decl_stmt|;
name|struct
name|symtab
modifier|*
name|h_htab
index|[
name|NHASH
index|]
decl_stmt|;
block|}
struct|;
end_struct

end_unit

