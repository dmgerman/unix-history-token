begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*					-[Sat Jan 29 13:56:53 1983 by jkf]-  * 	catchfram.h			$Locker:  $  * catch frame definition  *  * $Header: /na/franz/franz/h/catchfram.h,v 1.1 83/01/29 14:02:54 jkf Exp $  *  * (c) copyright 1982, Regents of the University of California  */
end_comment

begin_struct
struct|struct
name|catchfr
block|{
comment|/* catch and errset frame */
name|struct
name|catchfr
modifier|*
name|link
decl_stmt|;
comment|/* link to next catchframe */
name|lispval
name|flag
decl_stmt|;
comment|/* Do we print ?  */
name|lispval
name|labl
decl_stmt|;
comment|/* label caught at this point  */
name|struct
name|nament
modifier|*
name|svbnp
decl_stmt|;
comment|/* saved bnp */
name|lispval
name|retenv
index|[
literal|11
index|]
decl_stmt|;
comment|/* reset environment - actually a savblock */
name|lispval
name|rs
index|[
literal|4
index|]
decl_stmt|;
comment|/* regis 6-11 and 13 */
name|lispval
function_decl|(
modifier|*
name|retadr
function_decl|)
parameter_list|()
function_decl|;
comment|/* address to continue execution */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|savblock
block|{
name|lispval
name|envir
index|[
literal|10
index|]
decl_stmt|;
name|struct
name|savblock
modifier|*
name|savlnk
decl_stmt|;
block|}
struct|;
end_struct

end_unit

