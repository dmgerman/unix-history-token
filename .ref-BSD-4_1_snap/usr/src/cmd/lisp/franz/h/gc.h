begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* gc.h   structures used by the gc analysis routines   *	  this is a temporary file  */
end_comment

begin_struct
struct|struct
name|gchead
block|{
name|int
name|version
decl_stmt|;
comment|/* version number of this dump file */
name|int
name|lowdata
decl_stmt|;
comment|/* low address of sharable lisp data */
name|int
name|dummy
decl_stmt|,
name|dummy2
decl_stmt|,
name|dummy3
decl_stmt|;
comment|/* to be used later	*/
block|}
struct|;
end_struct

end_unit

