begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This may look like C code, but it is really -*- C++ -*-
end_comment

begin_comment
comment|/* Manipulate all directory entries for all file classes. */
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_include
include|#
directive|include
file|"entry-handler.h"
end_include

begin_decl_stmt
name|class
name|Directory_Handler
block|{
name|public
label|:
comment|/* There are five major types of files in the UNIX system. */
enum|enum
name|file_types
block|{
name|DIRS
block|,
comment|/* Subdirectories. */
name|FILES
block|,
comment|/* Regular files. */
name|EXECS
block|,
comment|/* Executable files. */
name|DLINKS
block|,
comment|/* Directory links (if -l option is enabled). */
name|FLINKS
block|,
comment|/* File links (if -l option is enabled). */
name|LINKS
block|,
comment|/* File *and* directory links (if -l option is *not* enabled). */
name|MAX_TYPES
block|,     }
enum|;
name|Directory_Handler
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|/* Formats the current directory files. */
name|void
name|print
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Lists the current directory files. */
name|private
label|:
comment|/* static */
name|Entry_Handler
name|file_class
index|[
name|MAX_TYPES
index|]
decl_stmt|;
comment|/* File class array. */
specifier|static
name|char
modifier|*
name|class_name
index|[
name|MAX_TYPES
index|]
decl_stmt|;
comment|/* String naem for each file class. */
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

