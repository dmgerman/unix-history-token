begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This may look like C code, but it is really -*- C++ -*-
end_comment

begin_comment
comment|/* Manipulate directory entries of a particular file class. */
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_include
include|#
directive|include
file|<std.h>
end_include

begin_include
include|#
directive|include
file|<new.h>
end_include

begin_include
include|#
directive|include
file|"screen-handler.h"
end_include

begin_comment
comment|/* Defined in sort.cc. */
end_comment

begin_function_decl
name|void
name|sort
parameter_list|(
name|char
modifier|*
modifier|*
name|base_ptr
parameter_list|,
name|int
name|total_elems
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|class
name|Entry_Handler
block|{
name|private
label|:
specifier|static
specifier|const
name|int
name|default_entries
decl_stmt|;
comment|/* Initial number of file entries per class. */
name|int
name|max_entry_length
decl_stmt|;
comment|/* Size of largest filename. */
name|int
name|total_entries
decl_stmt|;
comment|/* Total number of filenames. */
name|int
name|entries
decl_stmt|;
comment|/* Current number of filenames. */
name|char
modifier|*
modifier|*
name|buf
decl_stmt|;
comment|/* Buffer containing filenames for this file class. */
name|public
label|:
name|Entry_Handler
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/* Initialize a new file class. */
name|int
name|entry_number
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Current number of entries. */
name|void
name|add_entry
parameter_list|(
name|char
modifier|*
name|entry_name
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
comment|/* Add an entry to the class. */
name|void
name|sort_entries
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Sort entries by filename. */
name|void
name|print_entries
parameter_list|(
name|char
modifier|*
name|class_name
parameter_list|)
function_decl|;
comment|/* Print file entries. */
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* See comments in the .cc file for the following inline functions */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__OPTIMIZE__
end_ifdef

begin_expr_stmt
specifier|inline
name|Entry_Handler
operator|::
name|Entry_Handler
argument_list|(
argument|void
argument_list|)
block|{
name|entries
operator|=
name|max_entry_length
operator|=
literal|0
block|;
name|total_entries
operator|=
name|default_entries
block|;
name|buf
operator|=
name|new
name|char
operator|*
index|[
name|default_entries
index|]
block|; }
specifier|inline
name|int
name|Entry_Handler
operator|::
name|entry_number
argument_list|(
argument|void
argument_list|)
block|{
return|return
name|entries
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|void
name|Entry_Handler
operator|::
name|add_entry
argument_list|(
argument|char *entry_name
argument_list|,
argument|int length
argument_list|)
block|{
if|if
condition|(
name|entries
operator|>=
name|total_entries
condition|)
name|buf
operator|=
name|new
block|{
name|buf
block|,
name|total_entries
operator|*=
literal|2
block|}
name|char
operator|*
expr_stmt|;
name|max_entry_length
operator|>
condition|?
operator|=
name|length
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|buf
index|[
name|entries
operator|++
index|]
operator|=
name|strcpy
argument_list|(
argument|new char[length +
literal|1
argument|]
argument_list|,
argument|entry_name
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  inline
name|void
name|Entry_Handler
operator|::
name|sort_entries
argument_list|(
argument|void
argument_list|)
block|{
name|sort
argument_list|(
name|buf
argument_list|,
name|entries
argument_list|)
block|; }
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __OPTIMIZE__
end_comment

end_unit

