begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This may look like C code, but it is really -*- C++ -*-
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_comment
comment|/* Process directory listing program options. */
end_comment

begin_comment
comment|/* Enumeration of all directory listing options. */
end_comment

begin_enum
enum|enum
name|option_type
block|{
name|HIDDEN
init|=
literal|01
block|,
comment|/* Print hidden files (those beginning with '.') */
name|LINK
init|=
literal|02
block|,
comment|/* Distinguish between directory and file links. */
block|}
enum|;
end_enum

begin_decl_stmt
name|class
name|Option_Handler
block|{
name|private
label|:
specifier|static
name|unsigned
name|option_word
decl_stmt|;
comment|/* Compact bitwise-storage for program options. */
specifier|static
name|char
modifier|*
name|program_name
decl_stmt|;
comment|/* Name of listing program. */
specifier|static
name|void
name|usage
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Prints usage then exits. */
name|public
label|:
name|Option_Handler
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/* Initialize options. */
name|void
name|operator
argument_list|()
operator|(
name|int
name|argc
operator|,
name|char
operator|*
name|argv
index|[]
operator|)
expr_stmt|;
comment|/* Process command-line options. */
name|int
name|operator
function_decl|[]
parameter_list|(
name|option_type
name|option
parameter_list|)
function_decl|;
comment|/* Check if option is enabled. */
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Speed things up a bit if we're optimizing. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__OPTIMIZE__
end_ifdef

begin_expr_stmt
specifier|inline
name|int
name|Option_Handler
operator|::
name|operator
index|[]
operator|(
name|option_type
name|option
operator|)
block|{
return|return
name|option_word
operator|&
name|option
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __OPTIMIZE__
end_comment

end_unit

