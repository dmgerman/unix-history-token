begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  Definitions for the range table. ** **	Version: **		@(#)range.h	7.1	2/5/81 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAXRANGE
end_ifndef

begin_define
define|#
directive|define
name|MAXRANGE
value|(MAXVAR + 1)
end_define

begin_comment
comment|/* **	DESCRIPTOR struct ** **	The DESCRIPTOR struct is initialized by OPENR to describe any **	open relation.  The first part of the descriptor is the tuple **	from the RELATION relation.  The remainder contains some magic **	numbers and a template initialized from the ATTRIBUTE relation. ** **	This structure also defines the range table. */
end_comment

begin_struct
struct|struct
name|descriptor
block|{
name|struct
name|relation
name|reldum
decl_stmt|;
comment|/*the above part of the descriptor struct is identical 		  to the relation struct and the inormation in this 		  part of the struct is read directly from the 		  relation tuple by openr.  the rest of the descriptor 		  struct is calculated by openr.  */
name|char
name|relvname
index|[
name|MAXNAME
index|]
decl_stmt|;
comment|/* range variable name */
name|i_2
name|relfp
decl_stmt|;
comment|/*filep for relation , if open	*/
name|i_2
name|relopn
decl_stmt|;
comment|/*indicates if relation is really open*/
name|tid_type
name|reltid
decl_stmt|;
comment|/*when relation is open, this indicates 				  the tid in the relation relation for 				  this relation */
name|i_4
name|reladds
decl_stmt|;
comment|/*no. of additions of tuples during this open*/
name|i_2
name|reloff
index|[
name|MAXDOM
index|]
decl_stmt|;
comment|/*reloff[i] is offset to domain i 	*/
name|c_1
name|relfrmt
index|[
name|MAXDOM
index|]
decl_stmt|;
comment|/* format of domain i 				 ** INT, FLOAT, or CHAR  */
name|c_1
name|relfrml
index|[
name|MAXDOM
index|]
decl_stmt|;
comment|/* relfrml[i] is an unsigned integer 				  which indicates length 				  in bytes of domain */
name|c_1
name|relxtra
index|[
name|MAXDOM
index|]
decl_stmt|;
comment|/*relxtra[i] is non-zero if domain i is 				 ** a key domain for the relation */
name|c_1
name|relgiven
index|[
name|MAXDOM
index|]
decl_stmt|;
comment|/*cleared by openr and set before 				  call to find to indicate value of this 				  domain has been supplied in the key*/
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|descriptor
name|DESC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|DESC
modifier|*
name|rngvdesc
decl_stmt|;
comment|/* pointer to descriptor for this var */
name|bool
name|rngvmark
decl_stmt|;
comment|/* send if marked */
block|}
name|RANGEV
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
endif|MAXRANGE
end_endif

end_unit

