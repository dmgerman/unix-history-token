begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)optim.h	5.1 (Berkeley) 6/7/85  */
end_comment

begin_comment
comment|/*  * structure to hold trees for optimization  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|slt
block|{
name|field
name|type
decl_stmt|;
name|field
name|flags
decl_stmt|;
name|short
name|lineno
decl_stmt|;
name|struct
name|slt
modifier|*
name|next
decl_stmt|,
modifier|*
name|prev
decl_stmt|;
name|struct
name|slt
modifier|*
name|nullslot
decl_stmt|;
name|expptr
name|expr
decl_stmt|;
name|int
name|label
decl_stmt|;
name|int
modifier|*
name|ctlinfo
decl_stmt|;
block|}
empty_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|slt
modifier|*
name|Slotp
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|Slotp
name|firstslot
decl_stmt|,
name|lastslot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* first, last slots in buffer */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|numslots
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of slots */
end_comment

begin_decl_stmt
name|Slotp
name|newslot
argument_list|()
decl_stmt|,
name|optbuff
argument_list|()
decl_stmt|,
name|optinsert
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|Ctlframe
modifier|*
name|cpframe
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* **      Structures for cse analysis */
end_comment

begin_typedef
typedef|typedef
name|struct
name|IDblock
modifier|*
name|idptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|VALUEnode
modifier|*
name|valuen
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|IDlist
modifier|*
name|idlptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|DUPlist
modifier|*
name|duplptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|NODElist
modifier|*
name|nodelptr
typedef|;
end_typedef

begin_struct
struct|struct
name|IDblock
block|{
name|expptr
name|idaddr
decl_stmt|;
name|valuen
name|initval
decl_stmt|,
name|assgnval
decl_stmt|;
name|nodelptr
name|headnodelist
decl_stmt|;
name|struct
name|IDblock
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|VALUEnode
block|{
name|expptr
name|opp
decl_stmt|;
name|expptr
modifier|*
name|parent
decl_stmt|;
name|int
name|n_dups
decl_stmt|;
name|unsigned
name|is_dead
range|:
literal|1
decl_stmt|;
name|valuen
name|lc
decl_stmt|,
name|rc
decl_stmt|,
name|rs
decl_stmt|;
name|idlptr
name|headdeplist
decl_stmt|;
name|duplptr
name|headduplist
decl_stmt|;
name|struct
name|VALUEnode
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|IDlist
block|{
name|idptr
name|idp
decl_stmt|;
name|struct
name|IDlist
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DUPlist
block|{
name|expptr
modifier|*
name|parent
decl_stmt|;
name|struct
name|DUPlist
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|NODElist
block|{
name|valuen
name|nodep
decl_stmt|;
name|struct
name|NODElist
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * structure to hold information on basic blocks  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|bblock
block|{
name|Slotp
name|first
decl_stmt|,
name|last
decl_stmt|;
name|idptr
name|headid
decl_stmt|;
name|valuen
name|headnode
decl_stmt|,
name|tailnode
decl_stmt|;
name|struct
name|bblock
modifier|*
name|next
decl_stmt|,
modifier|*
name|prev
decl_stmt|;
block|}
empty_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|bblock
modifier|*
name|Bblockp
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|Bblockp
name|firstblock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* first block in buffer */
end_comment

begin_decl_stmt
specifier|extern
name|Bblockp
name|lastblock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last block in buffer */
end_comment

begin_comment
comment|/* data structure for optloop and regalloc routines */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|regnode
block|{
name|field
name|vstg
decl_stmt|;
name|field
name|vtype
decl_stmt|;
name|int
name|memno
decl_stmt|;
name|int
name|memoffset
decl_stmt|;
name|unsigned
name|isarrayarg
range|:
literal|1
decl_stmt|;
block|}
name|REGNODE
typedef|;
end_typedef

end_unit

