begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* save (III)   J. Gillogly  * save user core image for restarting  * usage: save(<command file (argv[0] from main)>,<output file>)  * bugs  *   -  impure code (i.e. changes in instructions) is not handled  *      (but people that do that get what they deserve)  */
end_comment

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"	save.c	4.3	89/03/05	"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<a.out.h>
end_include

begin_decl_stmt
name|int
name|filesize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* accessible to caller         */
end_comment

begin_function_decl
name|char
modifier|*
name|sbrk
parameter_list|()
function_decl|;
end_function_decl

begin_macro
name|save
argument_list|(
argument|cmdfile
argument_list|,
argument|outfile
argument_list|)
end_macro

begin_comment
comment|/* save core image              */
end_comment

begin_decl_stmt
name|char
modifier|*
name|cmdfile
decl_stmt|,
modifier|*
name|outfile
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|c
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|,
name|fd
decl_stmt|;
name|int
name|fdaout
decl_stmt|;
name|struct
name|exec
name|header
decl_stmt|;
name|int
name|counter
decl_stmt|;
name|char
name|buff
index|[
literal|512
index|]
decl_stmt|,
name|pwbuf
index|[
literal|120
index|]
decl_stmt|;
name|fdaout
operator|=
name|open
argument_list|(
name|cmdfile
argument_list|,
name|O_RDONLY
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* open command */
if|if
condition|(
name|fdaout
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* can do nothing without text  */
if|if
condition|(
operator|(
name|fd
operator|=
name|creat
argument_list|(
name|outfile
argument_list|,
literal|0755
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|"Cannot create %s\n"
argument_list|,
name|outfile
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
comment|/* can get the text segment from the command that we were 	 * called with, and change all data from uninitialized to 	 * initialized.  It will start at the top again, so the user 	 * is responsible for checking whether it was restarted 	 * could ignore sbrks and breaks for the first pass 	 */
name|read
argument_list|(
name|fdaout
argument_list|,
operator|&
name|header
argument_list|,
sizeof|sizeof
name|header
argument_list|)
expr_stmt|;
comment|/* get the header       */
name|header
operator|.
name|a_bss
operator|=
literal|0
expr_stmt|;
comment|/* no data uninitialized        */
name|header
operator|.
name|a_syms
operator|=
literal|0
expr_stmt|;
comment|/* throw away symbol table      */
switch|switch
condition|(
name|header
operator|.
name|a_magic
condition|)
comment|/* find data segment            */
block|{
case|case
literal|0407
case|:
comment|/* non sharable code            */
name|c
operator|=
operator|(
name|char
operator|*
operator|)
name|header
operator|.
name|a_text
expr_stmt|;
comment|/* data starts right after text */
name|header
operator|.
name|a_data
operator|=
name|sbrk
argument_list|(
literal|0
argument_list|)
operator|-
name|c
expr_stmt|;
comment|/* current size (incl allocs)   */
break|break;
case|case
literal|0410
case|:
comment|/* sharable code                */
name|c
operator|=
operator|(
name|char
operator|*
operator|)
ifdef|#
directive|ifdef
name|pdp11
operator|(
name|header
operator|.
name|a_text
comment|/* starts after text            */
operator|&
literal|0160000
operator|)
comment|/* on an 8K boundary            */
operator|+
literal|020000
expr_stmt|;
comment|/* i.e. the next one up         */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|vax
operator|(
name|header
operator|.
name|a_text
comment|/* starts after text            */
operator|&
literal|037777776000
operator|)
comment|/* on an 1K boundary            */
operator|+
literal|02000
expr_stmt|;
comment|/* i.e. the next one up         */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|tahoe
operator|(
name|header
operator|.
name|a_text
comment|/* starts after text            */
operator|&
literal|037777776000
operator|)
comment|/* on an 1K boundary            */
operator|+
literal|02000
expr_stmt|;
comment|/* i.e. the next one up         */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|z8000
operator|(
name|header
operator|.
name|a_text
comment|/* starts after text            */
operator|&
literal|0174000
operator|)
comment|/* on an 2K boundary            */
operator|+
literal|004000
expr_stmt|;
comment|/* i.e. the next one up         */
endif|#
directive|endif
name|header
operator|.
name|a_data
operator|=
name|sbrk
argument_list|(
literal|0
argument_list|)
operator|-
name|c
expr_stmt|;
comment|/* current size (incl allocs)   */
break|break;
case|case
literal|0411
case|:
comment|/* sharable with split i/d      */
name|c
operator|=
literal|0
expr_stmt|;
comment|/* can't reach text             */
name|header
operator|.
name|a_data
operator|=
operator|(
name|int
operator|)
name|sbrk
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* current size (incl allocs)   */
break|break;
case|case
literal|0413
case|:
name|c
operator|=
operator|(
name|char
operator|*
operator|)
name|header
operator|.
name|a_text
expr_stmt|;
comment|/* starts after text            */
name|lseek
argument_list|(
name|fdaout
argument_list|,
literal|1024L
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* skip unused part of 1st block*/
block|}
if|if
condition|(
name|header
operator|.
name|a_data
operator|<
literal|0
condition|)
comment|/* data area very big           */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* fail for now                 */
name|filesize
operator|=
sizeof|sizeof
name|header
operator|+
name|header
operator|.
name|a_text
operator|+
name|header
operator|.
name|a_data
expr_stmt|;
name|write
argument_list|(
name|fd
argument_list|,
operator|&
name|header
argument_list|,
sizeof|sizeof
name|header
argument_list|)
expr_stmt|;
comment|/* make the new header          */
if|if
condition|(
name|header
operator|.
name|a_magic
operator|==
literal|0413
condition|)
name|lseek
argument_list|(
name|fd
argument_list|,
literal|1024L
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Start on 1K boundary	   */
name|counter
operator|=
name|header
operator|.
name|a_text
expr_stmt|;
comment|/* size of text                 */
while|while
condition|(
name|counter
operator|>
literal|512
condition|)
comment|/* copy 512-byte blocks         */
block|{
name|read
argument_list|(
name|fdaout
argument_list|,
name|buff
argument_list|,
literal|512
argument_list|)
expr_stmt|;
comment|/* as long as possible          */
name|write
argument_list|(
name|fd
argument_list|,
name|buff
argument_list|,
literal|512
argument_list|)
expr_stmt|;
name|counter
operator|-=
literal|512
expr_stmt|;
block|}
name|read
argument_list|(
name|fdaout
argument_list|,
name|buff
argument_list|,
name|counter
argument_list|)
expr_stmt|;
comment|/* then pick up the rest        */
name|write
argument_list|(
name|fd
argument_list|,
name|buff
argument_list|,
name|counter
argument_list|)
expr_stmt|;
name|write
argument_list|(
name|fd
argument_list|,
name|c
argument_list|,
name|header
operator|.
name|a_data
argument_list|)
expr_stmt|;
comment|/* write all data in 1 glob     */
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

