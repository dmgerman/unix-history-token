begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Definitions and declarations used for storage management.  */
end_comment

begin_define
define|#
directive|define
name|MARK
value|0100000
end_define

begin_comment
comment|/* high-order bit for gc marking */
end_comment

begin_define
define|#
directive|define
name|SQLINC
value|128
end_define

begin_comment
comment|/* increment for s. q. list space */
end_comment

begin_comment
comment|/*  * External definitions.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|heapneed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stated need for heap space */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|strneed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stated need for string space */
end_comment

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|boundary
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Icon/C stack boundary address */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|descrip
modifier|*
name|globals
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start of global variables */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|descrip
modifier|*
name|eglobals
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of global variables */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|descrip
modifier|*
name|gnames
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start of global variable names */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|descrip
modifier|*
name|egnames
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of global variable names */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|descrip
modifier|*
name|statics
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start of static variables */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|descrip
modifier|*
name|estatics
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of static variables */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|descrip
name|tended
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tended descriptors, used by lib routines */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|descrip
name|etended
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of tended descriptors */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|descrip
modifier|*
modifier|*
name|sqlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* beginning of string qualifier list */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|descrip
modifier|*
modifier|*
name|sqfree
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* string qualifier list free pointer */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|descrip
modifier|*
modifier|*
name|esqlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end of string qualifier list */
end_comment

begin_comment
comment|/*  * Test if *x is a pointer.  */
end_comment

begin_define
define|#
directive|define
name|isptr
parameter_list|(
name|x
parameter_list|)
value|((!QUAL(*x))&& (VAR(*x) || POINTER(*x)))
end_define

begin_comment
comment|/*  * Get type of block pointed at by x.  */
end_comment

begin_define
define|#
directive|define
name|blktype
parameter_list|(
name|x
parameter_list|)
value|(*(int *)x)
end_define

begin_comment
comment|/*  * getsize(x) takes the block pointed to by x and if the size of  *  the block as indicated by bsizes[] is non-zero it returns the  *  indicated size, otherwise it returns the second word in the  *  block which should be the size.  */
end_comment

begin_define
define|#
directive|define
name|getsize
parameter_list|(
name|x
parameter_list|)
value|(bsizes[*(int *)x& ~MARK] ? \ 		     bsizes[*(int *)x& ~MARK] : *((int *)x + 1))
end_define

end_unit

