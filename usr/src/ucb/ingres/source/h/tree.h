begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  TREE.H -- defines the structure of a querytree ** **	Version: **		@(#)tree.h	7.1	2/5/81 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QT_HDR_SIZ
end_ifndef

begin_include
include|#
directive|include
file|<ingres.h>
end_include

begin_comment
comment|/* **	Structures Used In The Value Fields of Querytree nodes */
end_comment

begin_comment
comment|/* **  VAR node ** **	This node type contains info for a tuple variable. **	varno -- index into range table **	attno -- attribute number in this relation **	varfrmt -- type of this domain **	varfrml -- length of this domain **	valptr -- pointer to value when bound. ** **	If varno == -1, then this variable has been substituted; to **	get the actual VAR node, follow the chain of valptr's. */
end_comment

begin_struct
struct|struct
name|varnode
block|{
name|char
name|varno
decl_stmt|;
comment|/* variable number */
name|char
name|attno
decl_stmt|;
comment|/* attribute number */
name|char
name|varfrmt
decl_stmt|;
comment|/* type */
name|char
name|varfrml
decl_stmt|;
comment|/* length */
name|ANYTYPE
modifier|*
name|valptr
decl_stmt|;
comment|/* pointer to value */
block|}
struct|;
end_struct

begin_comment
comment|/* **	STRUCTURE FOR AND, AGHEAD, AND ROOT NODES ** **		In the parser and qrymod none of these fields are used. **		Decomp maintains information about the variables **		in the left and right descendents of the nodes. **		The "rootuser" flag is present only in the ROOT and AGHEAD **		nodes.  It is TRUE only in the original ROOT node of the query. */
end_comment

begin_struct
struct|struct
name|rootnode
comment|/* AND, AGHEAD, ROOT nodes */
block|{
name|char
name|tvarc
decl_stmt|;
comment|/* total of var's in sub-tree */
name|char
name|lvarc
decl_stmt|;
comment|/* # of variables in left branch */
name|short
name|lvarm
decl_stmt|;
comment|/* bit map of var's in left branch */
name|short
name|rvarm
decl_stmt|;
comment|/* bit map of var's in right branch*/
name|short
name|rootuser
decl_stmt|;
comment|/* flag: TRUE if root of user generated query */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|opnode
comment|/* AOP, BOP, UOP nodes */
block|{
name|short
name|opno
decl_stmt|;
comment|/* operator number */
name|char
name|opfrmt
decl_stmt|;
comment|/* format of function */
name|char
name|opfrml
decl_stmt|;
comment|/* length of function */
name|char
name|agfrmt
decl_stmt|;
comment|/* in AOP, format of result */
name|char
name|agfrml
decl_stmt|;
comment|/* in AOP, length of result */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|resdomnode
comment|/* RESDOM node */
block|{
name|short
name|resno
decl_stmt|;
comment|/* result domain number */
name|char
name|resfrmt
decl_stmt|;
comment|/* result format */
name|char
name|resfrml
decl_stmt|;
comment|/* result length */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|srcid
comment|/* SOURCEID node */
block|{
name|short
name|srcvar
decl_stmt|;
comment|/* variable number */
name|DESC
name|srcdesc
decl_stmt|;
comment|/* descriptor for this var */
block|}
struct|;
end_struct

begin_comment
comment|/* **	SYMVALUE UNION ** **		This union contains all of the types available **		in the value field of a querytree node. */
end_comment

begin_union
union|union
name|symvalue
block|{
name|union
name|anytype
name|sym_data
decl_stmt|;
name|struct
name|varnode
name|sym_var
decl_stmt|;
name|struct
name|rootnode
name|sym_root
decl_stmt|;
name|struct
name|opnode
name|sym_op
decl_stmt|;
name|struct
name|resdomnode
name|sym_resdom
decl_stmt|;
name|struct
name|srcid
name|sym_srcid
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* **	SYMBOL DEFINITION ** **		Basic symbol structure. "Type" is one of the symbols **		in "symbol.h", "len" is the length of the "value" **		field (0 to 255 bytes), "value" is variable length and **		holds the actual value (if len != 0) of the node. **		The "value" is one of the types contained in "union symvalue". ** **		On a thirty-two bit machine, there are two bytes of padding **		after type and length.  These two bytes are discarded  **		when a symbol is written to a pipe. */
end_comment

begin_struct
struct|struct
name|symbol
block|{
name|char
name|type
decl_stmt|;
comment|/* type codes in symbol.h */
name|char
name|len
decl_stmt|;
comment|/* length in bytes of value field */
name|union
name|symvalue
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|symbol
name|SYMBOL
typedef|;
end_typedef

begin_comment
comment|/* **	QUERYTREE NODE ** **		Basic node in the querytree. Each node has a left and **		right descendent. If the node is a leaf node then the **		left and right pointers will be NULL. Depending on the **		"type" field of the symbol structure, there may be additional **		information. */
end_comment

begin_struct
struct|struct
name|querytree
block|{
name|struct
name|querytree
modifier|*
name|left
decl_stmt|;
name|struct
name|querytree
modifier|*
name|right
decl_stmt|;
name|struct
name|symbol
name|sym
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|querytree
name|QTREE
typedef|;
end_typedef

begin_comment
comment|/* **	SUNDRY CONSTANTS ** **		There are several differences in the handling of data **		structures on 16 and 32 bit machines: **			1).  A pointer to  memory is either 2 or 4 bytes. **			2).  Padding is inserted in structures to insure **				alignment of 16 and 32 bit numbers. ** **		For these reasons the following constant definitions **		are useful for machine independent allocation. ** **		These are based on the PDP11 compile flag. ** **		QT_HDR_SIZ -- size of left and right pointers, typ, **			len and padding **		SYM_HDR_SIZ -- size of type and len in symbol **			structure -- includes any padding before **			the value field **		TYP_LEN_SIZ -- size of type and len in symbol **			structure -- without padding ** **		INGRES FOLKS: don't change these back to sizeof's!!! **			      The PDP-11 compiler doesn't understand! */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PDP11
end_ifdef

begin_define
define|#
directive|define
name|QT_HDR_SIZ
value|6
end_define

begin_define
define|#
directive|define
name|SYM_HDR_SIZ
value|2
end_define

begin_define
define|#
directive|define
name|TYP_LEN_SIZ
value|2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|QT_HDR_SIZ
value|12
end_define

begin_define
define|#
directive|define
name|SYM_HDR_SIZ
value|4
end_define

begin_define
define|#
directive|define
name|TYP_LEN_SIZ
value|2
end_define

begin_endif
endif|#
directive|endif
endif|PDP11
end_endif

begin_comment
comment|/* **  Query Tree Header. ** **	Qt_ctx should be of type 'ctx_t *', but it is 'char *' **		to insure that we don't need ctlmod.h. */
end_comment

begin_struct
struct|struct
name|qthdr
block|{
name|char
name|qt_active
decl_stmt|;
comment|/* if set, Qt area is in use */
name|char
modifier|*
name|qt_ctx
decl_stmt|;
comment|/* pointer to context */
name|short
name|qt_qmode
decl_stmt|;
comment|/* query mode */
name|short
name|qt_resvar
decl_stmt|;
comment|/* result variable number */
name|RANGEV
name|qt_rangev
index|[
name|MAXRANGE
index|]
decl_stmt|;
comment|/* the range table */
name|short
name|qt_remap
index|[
name|MAXRANGE
index|]
decl_stmt|;
comment|/* variable remapping (for QM) */
block|}
name|Qt
struct|;
end_struct

begin_endif
endif|#
directive|endif
endif|QT_HDR_SIZ
end_endif

end_unit

