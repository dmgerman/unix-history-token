begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/* **  INGRES.H -- basic header file for ingres. ** **	See also aux.h for definitions used by some but not all. ** **	Version: **		@(#)ingres.h	7.1	2/5/81 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXNAME
end_ifndef

begin_comment
comment|/* **  Some generally useful stuff. */
end_comment

begin_include
include|#
directive|include
file|<useful.h>
end_include

begin_comment
comment|/* **	definition of machine type ** **	If PDP11 is defined, the wordsize is defined as 16, and any other **	machine dependant things are set to the values needed for a PDP 11/70. **	Currently the default is to the 32 bits existant on VAX 11/780s. */
end_comment

begin_define
define|#
directive|define
name|VAX
end_define

begin_include
include|#
directive|include
file|<trace.h>
end_include

begin_comment
comment|/* **	INGRES manifest constants ** **	These constants are manifest to the operation of the entire **	system.  If anything **	is changed part or all of the system will stop working. **	The values have been carefully chosen and are not intended **	to be modifiable by users. */
end_comment

begin_define
define|#
directive|define
name|MAXDOM
value|50
end_define

begin_comment
comment|/* max # + 1 of doms in a relation */
end_comment

begin_define
define|#
directive|define
name|MAXNAME
value|12
end_define

begin_comment
comment|/* max size of a name (in bytes) */
end_comment

begin_define
define|#
directive|define
name|MAXVAR
value|10
end_define

begin_comment
comment|/* max # of variables */
end_comment

begin_define
define|#
directive|define
name|MAXKEYS
value|6
end_define

begin_comment
comment|/* max # of keys in secondary index */
end_comment

begin_define
define|#
directive|define
name|MAXAGG
value|50
end_define

begin_comment
comment|/* max number of aggs in a qry */
end_comment

begin_define
define|#
directive|define
name|STACKSIZ
value|20
end_define

begin_comment
comment|/* max depth for arith. expr. stacks */
end_comment

begin_define
define|#
directive|define
name|I1MASK
value|0377
end_define

begin_comment
comment|/* mask out sign extension that occurs 						**  when a c1 or i1 field is converted 						**  to an i2 field.  						*/
end_comment

begin_define
define|#
directive|define
name|i_1
value|char
end_define

begin_define
define|#
directive|define
name|i_2
value|short
end_define

begin_define
define|#
directive|define
name|i_4
value|long
end_define

begin_define
define|#
directive|define
name|c_1
value|char
end_define

begin_define
define|#
directive|define
name|c_2
value|char
end_define

begin_define
define|#
directive|define
name|c_12
value|char
end_define

begin_comment
comment|/* **	RELATION relation struct ** **	The RELATION relation contains one tuple for each relation **	in the database.  This relation contains information which **	describes how each relation is actually stored in the **	database, who the owner is, information about its size, **	assorted operation information, etc. */
end_comment

begin_define
define|#
directive|define
name|RELID
value|1
end_define

begin_comment
comment|/* domain for setkey */
end_comment

begin_define
define|#
directive|define
name|RELOWNER
value|2
end_define

begin_struct
struct|struct
name|relation
block|{
name|c_12
name|relid
index|[
name|MAXNAME
index|]
decl_stmt|;
comment|/* relation name	*/
name|c_2
name|relowner
index|[
literal|2
index|]
decl_stmt|;
comment|/* code of relation owner */
name|i_1
name|relspec
decl_stmt|;
comment|/* storage mode of relation	*/
comment|/* M_HEAP  unsorted paged heap	*/
comment|/* -M_HEAP compressed heap	*/
comment|/* M_ISAM  isam			*/
comment|/* -M_ISAM compressed isam	*/
comment|/* M_HASH  hashed		*/
comment|/* -M_HASH compressed hash	*/
name|i_1
name|relindxd
decl_stmt|;
comment|/* -1 rel is an index, 0 not indexed, 1 indexed */
name|i_2
name|relstat2
decl_stmt|;
comment|/* more status bits */
name|i_2
name|relstat
decl_stmt|;
comment|/* relation status bits */
name|i_4
name|relsave
decl_stmt|;
comment|/*unix time until which relation is saved*/
name|i_4
name|reltups
decl_stmt|;
comment|/*number of tuples in relation	*/
name|i_2
name|relatts
decl_stmt|;
comment|/*number of attributes in relation	*/
name|i_2
name|relwid
decl_stmt|;
comment|/*width (in bytes) of relation	*/
name|i_4
name|relprim
decl_stmt|;
comment|/*no. of primary pages in relation*/
name|i_4
name|relfree
decl_stmt|;
comment|/* head of freelist (b-trees only) */
name|i_4
name|relstamp
decl_stmt|;
comment|/*time of last mod*/
block|}
struct|;
end_struct

begin_comment
comment|/* **	ATTRIBUTE relation struct ** **	The ATTRIBUTE relation contains one tuple for each domain **	of each relation in the database.  This relation describes **	the position of each domain in the tuple, its format, **	its length, and whether or not it is used in part of the key. */
end_comment

begin_define
define|#
directive|define
name|ATTRELID
value|1
end_define

begin_define
define|#
directive|define
name|ATTOWNER
value|2
end_define

begin_define
define|#
directive|define
name|ATTID
value|3
end_define

begin_define
define|#
directive|define
name|ATTNAME
value|4
end_define

begin_struct
struct|struct
name|attribute
block|{
name|c_12
name|attrelid
index|[
name|MAXNAME
index|]
decl_stmt|;
comment|/*relation name of which this is an attr */
name|c_2
name|attowner
index|[
literal|2
index|]
decl_stmt|;
comment|/* code of relation owner */
name|i_2
name|attid
decl_stmt|;
comment|/*domain number (from 1 to relatts)	*/
name|c_12
name|attname
index|[
name|MAXNAME
index|]
decl_stmt|;
comment|/*alias for this domain*/
name|i_2
name|attoff
decl_stmt|;
comment|/*offset in tuple (no. of bytes*/
name|i_1
name|attfrmt
decl_stmt|;
comment|/* INT, FLOAT, CHAR (in symbol.h) */
name|i_1
name|attfrml
decl_stmt|;
comment|/* unsigned integer no of bytes	*/
name|i_1
name|attxtra
decl_stmt|;
comment|/* flag indicating whether this dom is part of a key */
block|}
struct|;
end_struct

begin_comment
comment|/* **	tuple id struct ** **	We want the line_id to be in the low-order of a long, in **	order to make index work efficiently; since the order **	of halfwords is reversed in a VAX, this is dependent... */
end_comment

begin_struct
struct|struct
name|tup_id
block|{
ifdef|#
directive|ifdef
name|PDP11
name|c_1
name|pg1
decl_stmt|,
name|pg0
decl_stmt|;
name|c_1
name|line_id
decl_stmt|,
name|pg2
decl_stmt|;
else|#
directive|else
else|PDP11
name|c_1
name|line_id
decl_stmt|,
name|pg2
decl_stmt|,
name|pg1
decl_stmt|,
name|pg0
decl_stmt|;
endif|#
directive|endif
endif|PDP11
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|tup_id
name|TID
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|long
name|ltid
decl_stmt|;
name|TID
name|s_tupid
decl_stmt|;
block|}
name|tid_type
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<range.h>
end_include

begin_comment
comment|/* to get the descriptor struct */
end_comment

begin_comment
comment|/* modes to find */
end_comment

begin_define
define|#
directive|define
name|NOKEY
value|1
end_define

begin_comment
comment|/* scan entire relation */
end_comment

begin_define
define|#
directive|define
name|EXACTKEY
value|2
end_define

begin_define
define|#
directive|define
name|LRANGEKEY
value|3
end_define

begin_comment
comment|/* low range key */
end_comment

begin_define
define|#
directive|define
name|FULLKEY
value|4
end_define

begin_comment
comment|/* forces full key comparison */
end_comment

begin_define
define|#
directive|define
name|HRANGEKEY
value|5
end_define

begin_comment
comment|/* high range key */
end_comment

begin_comment
comment|/* **	anytype union -- union of ingres types */
end_comment

begin_union
union|union
name|anytype
block|{
name|char
name|i1type
decl_stmt|;
name|short
name|i2type
decl_stmt|;
name|long
name|i4type
decl_stmt|;
name|float
name|f4type
decl_stmt|;
name|double
name|f8type
decl_stmt|;
name|char
name|c0type
index|[
literal|1
index|]
decl_stmt|;
comment|/* the 1 is bogus, only needs  					 * starting address 					 */
name|char
modifier|*
name|cptype
decl_stmt|;
name|char
modifier|*
modifier|*
name|cpptype
decl_stmt|;
block|}
union|;
end_union

begin_typedef
typedef|typedef
name|union
name|anytype
name|ANYTYPE
typedef|;
end_typedef

begin_comment
comment|/* **  Definitions for interface to the control module. */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|Qbuf
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|MAXNAME
end_endif

end_unit

