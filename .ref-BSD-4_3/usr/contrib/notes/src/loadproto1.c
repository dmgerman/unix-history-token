begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"parms.h"
end_include

begin_include
include|#
directive|include
file|"structs.h"
end_include

begin_include
include|#
directive|include
file|"dump.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|RCSIDENT
end_ifdef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Header: loadproto1.c,v 1.7 85/01/18 15:43:15 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

begin_comment
comment|/*  *	load notes and responses in protocol 1  *  *	Ray Essick	March 1984  */
end_comment

begin_macro
name|ldnote1
argument_list|(
argument|io
argument_list|,
argument|whofrom
argument_list|,
argument|extensive
argument_list|,
argument|lockit
argument_list|,
argument|infile
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|io_f
modifier|*
name|io
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* notesfile */
end_comment

begin_decl_stmt
name|char
modifier|*
name|whofrom
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sending system */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|infile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* incoming stream */
end_comment

begin_block
block|{
name|struct
name|note_f
name|note
decl_stmt|;
comment|/* note descriptor */
name|initnote
argument_list|(
operator|&
name|note
argument_list|)
expr_stmt|;
comment|/* zero fields */
while|while
condition|(
name|fgets
argument_list|(
name|line
argument_list|,
sizeof|sizeof
name|line
argument_list|,
name|infile
argument_list|)
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
operator|(
name|varno
operator|=
name|rfcparse
argument_list|(
name|line
argument_list|,
operator|&
name|notenanmes
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
comment|/* wierd */
continue|continue;
comment|/* ignore it */
name|field
operator|=
name|index
argument_list|(
name|line
argument_list|,
literal|':'
argument_list|)
expr_stmt|;
comment|/* find data */
name|field
operator|++
expr_stmt|;
comment|/* skip colon */
name|field
operator|++
expr_stmt|;
comment|/* skip space */
switch|switch
condition|(
name|varno
condition|)
block|{
case|case
name|NOTE_TITLE
case|:
case|case
name|NOTE_AUTHOR
case|:
case|case
name|NOTE_AUTHOR_UID
case|:
case|case
name|NOTE_ID
case|:
case|case
name|NOTE_WRITTEN
case|:
case|case
name|NOTE_RECEIVED
case|:
case|case
name|NOTE_MODIFIED
case|:
case|case
name|NOTE_FROMSYS
case|:
case|case
name|NOTE_STATUS
case|:
case|case
name|NOTE_LENGTH
case|:
default|default:
comment|/* strange */
block|}
block|}
block|}
end_block

begin_macro
name|ldresp1
argument_list|(
argument|io
argument_list|,
argument|whofrom
argument_list|,
argument|extensive
argument_list|,
argument|lockit
argument_list|,
argument|infile
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|io_f
modifier|*
name|io
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* notesfile */
end_comment

begin_decl_stmt
name|char
modifier|*
name|whofrom
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sending system */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|infile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* incoming stream */
end_comment

begin_block
block|{
while|while
condition|(
name|fgets
argument_list|(
name|line
argument_list|,
sizeof|sizeof
name|line
argument_list|,
name|infile
argument_list|)
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
operator|(
name|varno
operator|=
name|rfcparse
argument_list|(
name|line
argument_list|,
operator|&
name|notenanmes
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
comment|/* wierd */
continue|continue;
comment|/* ignore it */
name|field
operator|=
name|index
argument_list|(
name|line
argument_list|,
literal|':'
argument_list|)
expr_stmt|;
comment|/* find data */
name|field
operator|++
expr_stmt|;
comment|/* skip colon */
name|field
operator|++
expr_stmt|;
comment|/* skip space */
switch|switch
condition|(
name|varno
condition|)
block|{
case|case
name|RESP_TITLE
case|:
comment|/* ignored */
case|case
name|RESP_PARENT
case|:
case|case
name|RESP_AUTHOR
case|:
case|case
name|RESP_AUTHOR_UID
case|:
case|case
name|RESP_ID
case|:
case|case
name|RESP_WRITTEN
case|:
case|case
name|RESP_RECEIVED
case|:
case|case
name|RESP_FROMSYS
case|:
case|case
name|RESP_STATUS
case|:
case|case
name|RESP_LENGTH
case|:
default|default:
comment|/* strange */
block|}
block|}
block|}
end_block

end_unit

