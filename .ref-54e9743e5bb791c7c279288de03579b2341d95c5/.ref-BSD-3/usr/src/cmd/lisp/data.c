begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"global.h"
end_include

begin_include
include|#
directive|include
file|"gtabs.h"
end_include

begin_decl_stmt
name|lispval
name|lispsys
index|[
name|SIGNIF
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lisp data used by system */
end_comment

begin_decl_stmt
name|lispval
name|gftab
index|[
name|GFTABLEN
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global function table for interpreter */
end_comment

begin_decl_stmt
name|lispval
name|gctab
index|[
name|GCTABLEN
index|]
init|=
comment|/* global constant table for interpreter */
block|{
name|nil
block|,
literal|0
block|,
name|SMALL
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|SMALL
argument_list|(
literal|0
argument_list|)
block|,
name|SMALL
argument_list|(
literal|1
argument_list|)
block|,
name|SMALL
argument_list|(
literal|2
argument_list|)
block|,
name|SMALL
argument_list|(
literal|3
argument_list|)
block|,
name|SMALL
argument_list|(
literal|4
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Port definitions *****************************************************/
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|piport
decl_stmt|,
comment|/* standard input port		*/
modifier|*
name|poport
decl_stmt|,
comment|/* standard output port		*/
modifier|*
name|errport
decl_stmt|,
comment|/* port for error messages	*/
modifier|*
name|rdrport
decl_stmt|,
comment|/* temporary port for readr	*/
modifier|*
name|proport
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* port for protocal		*/
end_comment

begin_decl_stmt
name|int
name|lineleng
init|=
literal|80
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line length desired		*/
end_comment

begin_decl_stmt
name|int
name|rlevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used to indicate depth of recursion 				   in reader.  No longer really necessary */
end_comment

begin_decl_stmt
name|char
name|keybin
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* logical flag: using keyboard	*/
end_comment

begin_decl_stmt
name|char
name|protflag
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* logical flag: want protocall */
end_comment

begin_decl_stmt
name|char
name|rbktf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* logical flag: ] mode		*/
end_comment

begin_comment
comment|/* name stack ***********************************************************/
end_comment

begin_decl_stmt
name|struct
name|argent
modifier|*
name|namptr
decl_stmt|,
comment|/* temporary pointer	*/
modifier|*
name|nplim
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* don't have this = np	*/
end_comment

begin_decl_stmt
name|struct
name|nament
modifier|*
name|bnp
decl_stmt|,
comment|/* top of bind stack    */
modifier|*
name|orgbnp
decl_stmt|,
comment|/* absolute bottom of ""*/
modifier|*
name|bnplim
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* absolute top of ""   */
end_comment

begin_comment
comment|/* the typeing table ****************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ROWAN
end_ifndef

begin_decl_stmt
name|char
name|typetab
index|[
name|TTSIZE
index|]
init|=
block|{
name|UNBO
block|,
name|ATOM
block|,
name|INT
block|,
name|INT
block|,
name|PORT
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
name|typetab
index|[
name|TTSIZE
index|]
init|=
block|{
name|UNBO
block|,
name|ATOM
block|,
name|INT
block|,
name|INT
block|,
name|INT
block|,
name|PORT
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* hashing things *******************************************************/
end_comment

begin_decl_stmt
name|struct
name|atom
modifier|*
name|hasht
index|[
name|HASHTOP
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|hash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set by ratom		*/
end_comment

begin_decl_stmt
name|int
name|atmlen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* length of atom including final null	*/
end_comment

begin_comment
comment|/* big string buffer for whomever needs it ******************************/
end_comment

begin_decl_stmt
name|char
name|strbuf
index|[
name|STRBLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|endstrb
init|=
name|strbuf
operator|+
literal|255
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set by sstatus commands */
end_comment

begin_decl_stmt
name|int
name|uctolc
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* when set, uc chars in atoms go to lc */
end_comment

begin_decl_stmt
name|int
name|dmpmode
init|=
literal|413
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default mode for dumplisp  			   (note this is decimal not octal) */
end_comment

begin_comment
comment|/* break and error declarations *****************************************/
end_comment

begin_decl_stmt
name|int
name|depth
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* depth of nested breaks		*/
end_comment

begin_decl_stmt
name|lispval
name|contval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the value being returned up		*/
end_comment

begin_decl_stmt
name|struct
name|argent
modifier|*
name|orgnp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used by top level to reset to start  */
end_comment

begin_decl_stmt
name|int
name|retval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used by each error/prog call		*/
end_comment

begin_comment
comment|/* other stuff **********************************************************/
end_comment

begin_decl_stmt
name|lispval
name|ftemp
decl_stmt|,
name|vtemp
decl_stmt|,
name|argptr
decl_stmt|,
name|ttemp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* temporaries: use briefly	*/
end_comment

begin_decl_stmt
name|int
name|itemp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|lispval
name|sigacts
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for catching interrupts	*/
end_comment

begin_decl_stmt
name|int
name|sigstruck
decl_stmt|,
name|sigdelay
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for catching interrupts	*/
end_comment

begin_decl_stmt
name|lispval
name|stattab
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* miscelleneous options	*/
end_comment

begin_comment
comment|/*  interpreter globals    */
end_comment

begin_decl_stmt
name|int
name|lctrace
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fvirgin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|GCtime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|errp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where are lying through our teeth. This 				   is a pointer to inside a function. */
end_comment

end_unit

