begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/* **  CATALOG.H -- system catalog definitions ** **	relation and attribute catalogs are defined in ingres.h. ** **	Version: **		@(#)catalog.h	7.1	2/5/81 */
end_comment

begin_comment
comment|/* **	INDEX relation struct ** **	The INDEX relation is used to determine what, if any, **	secondary indicies exist for relations.  If a relation **	has a secondary index, there will be one tuple in the **	INDEX relation for each such index.  There may be one **	or more domains indexed by one or many INDEX relations **	depending on whether single or combined indicies are **	being used. ** **	Combined indices may use up to six domains to form the **	index. ** **	The simple existance of a secondary index is better **	checked using the "relindxd" field in the RELATION **	relation, since that is more efficient. ** **	The two values SECINDEX and SECBASE are the values for **	the relindxd field of the relation relation.  Implicitly **	SECINDEX must be< 0 and SECBASE must be> 0. */
end_comment

begin_define
define|#
directive|define
name|IRELIDP
value|1
end_define

begin_define
define|#
directive|define
name|IOWNERP
value|2
end_define

begin_define
define|#
directive|define
name|IRELIDI
value|3
end_define

begin_define
define|#
directive|define
name|SECINDEX
value|-2
end_define

begin_comment
comment|/* this value in rel.relindxd indicates 					** that the relation is a sec. index */
end_comment

begin_define
define|#
directive|define
name|SECBASE
value|1
end_define

begin_comment
comment|/* this value in rel.relindxd indicates 					** has a sec. index */
end_comment

begin_struct
struct|struct
name|index
block|{
name|char
name|irelidp
index|[
name|MAXNAME
index|]
decl_stmt|;
comment|/*unique name of primary relation	*/
name|char
name|iownerp
index|[
literal|2
index|]
decl_stmt|;
comment|/*owner of primary relation*/
name|char
name|irelidi
index|[
name|MAXNAME
index|]
decl_stmt|;
comment|/*unique name of index relation	*/
name|char
name|irelspeci
decl_stmt|;
comment|/*relspec of index relation*/
name|char
name|idom
index|[
name|MAXKEYS
index|]
decl_stmt|;
comment|/* domain number of primary relation */
comment|/* which corresponds to each index attribute */
comment|/* In the indexes relation these are stored as */
comment|/* idom1, idom2, ..,idom6 */
block|}
struct|;
end_struct

begin_comment
comment|/* **  TREE RELATION STRUCT ** **	The TREE relation stores trees used by query modification and **	for distribution criteria. */
end_comment

begin_struct
struct|struct
name|tree
block|{
name|char
name|treerelid
index|[
name|MAXNAME
index|]
decl_stmt|;
comment|/* relation name */
name|char
name|treeowner
index|[
literal|2
index|]
decl_stmt|;
comment|/* relation owner */
name|short
name|treeid
decl_stmt|;
comment|/* internal name of this tuple */
name|short
name|treeseq
decl_stmt|;
comment|/* sequence number in tree */
name|char
name|treetype
decl_stmt|;
comment|/* type info for this tree */
name|char
name|treexxxx
decl_stmt|;
name|char
name|treetree
index|[
literal|100
index|]
decl_stmt|;
comment|/* contents of tree */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TREERELID
value|1
end_define

begin_define
define|#
directive|define
name|TREEOWNER
value|2
end_define

begin_define
define|#
directive|define
name|TREEID
value|3
end_define

begin_define
define|#
directive|define
name|TREESEQ
value|4
end_define

begin_define
define|#
directive|define
name|TREETYPE
value|5
end_define

begin_comment
comment|/* **  STRUCT PROTECT -- protection catalog ** **	This structure defines the format of the 'protect' catalog. **	One or two things should be noted.  First, the 'prodomset' **	field is actually four domains in the physical relation, **	since the best we know about is i4's, and we need an i16. **	Second, both the proopset and the prodomset fields **	are bit maps. */
end_comment

begin_struct
struct|struct
name|protect
block|{
name|char
name|prorelid
index|[
name|MAXNAME
index|]
decl_stmt|;
comment|/* relation to which this applies */
name|char
name|prorelown
index|[
literal|2
index|]
decl_stmt|;
comment|/* owner */
name|short
name|propermid
decl_stmt|;
comment|/* permission sequence number */
name|char
name|prouser
index|[
literal|2
index|]
decl_stmt|;
comment|/* user code in PERMIT */
name|char
name|proterm
index|[
literal|8
index|]
decl_stmt|;
comment|/* terminal in PERMIT */
name|char
name|proresvar
decl_stmt|;
comment|/* Resultvarno in tree */
name|char
name|proopset
decl_stmt|;
comment|/* operation set */
name|short
name|protodbgn
decl_stmt|;
comment|/* beginning time of day */
name|short
name|protodend
decl_stmt|;
comment|/* ending time of day */
name|char
name|prodowbgn
decl_stmt|;
comment|/* beginning day of week */
name|char
name|prodowend
decl_stmt|;
comment|/* ending day of week */
name|short
name|prodomset
index|[
literal|8
index|]
decl_stmt|;
comment|/* domain set permitted */
name|short
name|protree
decl_stmt|;
comment|/* link to qualification */
block|}
struct|;
end_struct

begin_comment
comment|/* field numbers for find() calls */
end_comment

begin_define
define|#
directive|define
name|PRORELID
value|1
end_define

begin_define
define|#
directive|define
name|PRORELOWN
value|2
end_define

begin_define
define|#
directive|define
name|PROPERMID
value|3
end_define

begin_define
define|#
directive|define
name|PROTREE
value|16
end_define

begin_comment
comment|/* bit values for proopset */
end_comment

begin_define
define|#
directive|define
name|PRO_RETR
value|0001
end_define

begin_comment
comment|/* retrieve */
end_comment

begin_define
define|#
directive|define
name|PRO_REPL
value|0002
end_define

begin_comment
comment|/* replace */
end_comment

begin_define
define|#
directive|define
name|PRO_DEL
value|0004
end_define

begin_comment
comment|/* delete */
end_comment

begin_define
define|#
directive|define
name|PRO_APP
value|0010
end_define

begin_comment
comment|/* append */
end_comment

begin_define
define|#
directive|define
name|PRO_TEST
value|0020
end_define

begin_comment
comment|/* test in qualification */
end_comment

begin_define
define|#
directive|define
name|PRO_AGGR
value|0040
end_define

begin_comment
comment|/* retrieve aggregate value */
end_comment

begin_comment
comment|/* **  STRUCT INTEGRITY -- the descriptor for the integrity relation */
end_comment

begin_struct
struct|struct
name|integrity
block|{
name|char
name|intrelid
index|[
name|MAXNAME
index|]
decl_stmt|;
comment|/* name of the relation */
name|char
name|intrelowner
index|[
literal|2
index|]
decl_stmt|;
comment|/* owner of the relation */
name|short
name|inttree
decl_stmt|;
comment|/* pointer into the tree catalog */
name|short
name|intdomset
index|[
literal|8
index|]
decl_stmt|;
comment|/* set of domains this applies to */
name|char
name|intresvar
decl_stmt|;
comment|/* primary variable number */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|INTRELID
value|1
end_define

begin_define
define|#
directive|define
name|INTRELOWNER
value|2
end_define

begin_define
define|#
directive|define
name|INTTREE
value|3
end_define

end_unit

