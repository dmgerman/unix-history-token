begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// fileread.h -- read files for gold   -*- C++ -*-
end_comment

begin_comment
comment|// Classes used to read data from binary input files.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GOLD_FILEREAD_H
end_ifndef

begin_define
define|#
directive|define
name|GOLD_FILEREAD_H
end_define

begin_include
include|#
directive|include
file|<list>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"options.h"
end_include

begin_decl_stmt
name|namespace
name|gold
block|{
name|class
name|Dirsearch
decl_stmt|;
name|class
name|File_view
decl_stmt|;
comment|// File_read manages a file descriptor for a file we are reading.  We
comment|// close file descriptors if we run out of them, so this class reopens
comment|// the file as needed.
name|class
name|File_read
block|{
name|public
label|:
name|File_read
argument_list|()
operator|:
name|name_
argument_list|()
operator|,
name|descriptor_
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|lock_count_
argument_list|(
literal|0
argument_list|)
operator|,
name|views_
argument_list|()
operator|,
name|saved_views_
argument_list|()
operator|,
name|contents_
argument_list|(
name|NULL
argument_list|)
operator|,
name|contents_size_
argument_list|(
literal|0
argument_list|)
block|{ }
operator|~
name|File_read
argument_list|()
expr_stmt|;
comment|// Open a file.
name|bool
name|open
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|name
argument_list|)
decl_stmt|;
comment|// Pretend to open the file, but provide the file contents.  No
comment|// actual file system activity will occur.  This is used for
comment|// testing.
name|bool
name|open
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|name
argument_list|,
specifier|const
name|unsigned
name|char
operator|*
name|contents
argument_list|,
name|off_t
name|size
argument_list|)
decl_stmt|;
comment|// Return the file name.
specifier|const
name|std
operator|::
name|string
operator|&
name|filename
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|name_
return|;
block|}
comment|// Lock the file for access within a particular Task::run execution.
comment|// This means that the descriptor can not be closed.  This routine
comment|// may only be called from the main thread.
name|void
name|lock
parameter_list|()
function_decl|;
comment|// Unlock the descriptor, permitting it to be closed if necessary.
name|void
name|unlock
parameter_list|()
function_decl|;
comment|// Test whether the object is locked.
name|bool
name|is_locked
parameter_list|()
function_decl|;
comment|// Return a view into the file.  The pointer will remain valid until
comment|// the File_read is unlocked.  If PBYTES is NULL, it is an error if
comment|// we can not read enough data.  Otherwise *PBYTES is set to the
comment|// number of bytes read.
specifier|const
name|unsigned
name|char
modifier|*
name|get_view
parameter_list|(
name|off_t
name|start
parameter_list|,
name|off_t
name|size
parameter_list|,
name|off_t
modifier|*
name|pbytes
init|=
name|NULL
parameter_list|)
function_decl|;
comment|// Read data from the file into the buffer P.  PBYTES is as in
comment|// get_view.
name|void
name|read
parameter_list|(
name|off_t
name|start
parameter_list|,
name|off_t
name|size
parameter_list|,
name|void
modifier|*
name|p
parameter_list|,
name|off_t
modifier|*
name|pbytes
init|=
name|NULL
parameter_list|)
function_decl|;
comment|// Return a lasting view into the file.  This is allocated with new,
comment|// and the caller is responsible for deleting it when done.  The
comment|// data associated with this view will remain valid until the view
comment|// is deleted.  PBYTES is handled as with get_view.
name|File_view
modifier|*
name|get_lasting_view
parameter_list|(
name|off_t
name|start
parameter_list|,
name|off_t
name|size
parameter_list|,
name|off_t
modifier|*
name|pbytes
init|=
name|NULL
parameter_list|)
function_decl|;
name|private
label|:
comment|// This class may not be copied.
name|File_read
argument_list|(
specifier|const
name|File_read
operator|&
argument_list|)
expr_stmt|;
name|File_read
modifier|&
name|operator
init|=
operator|(
specifier|const
name|File_read
operator|&
operator|)
decl_stmt|;
comment|// A view into the file when not using mmap.
name|class
name|View
block|{
name|public
label|:
name|View
argument_list|(
argument|off_t start
argument_list|,
argument|off_t size
argument_list|,
argument|unsigned char* data
argument_list|)
block|:
name|start_
argument_list|(
name|start
argument_list|)
operator|,
name|size_
argument_list|(
name|size
argument_list|)
operator|,
name|data_
argument_list|(
name|data
argument_list|)
operator|,
name|lock_count_
argument_list|(
literal|0
argument_list|)
block|{ }
operator|~
name|View
argument_list|()
expr_stmt|;
name|off_t
name|start
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|start_
return|;
block|}
name|off_t
name|size
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|size_
return|;
block|}
name|unsigned
name|char
operator|*
name|data
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|data_
return|;
block|}
name|void
name|lock
parameter_list|()
function_decl|;
name|void
name|unlock
parameter_list|()
function_decl|;
name|bool
name|is_locked
parameter_list|()
function_decl|;
name|private
label|:
name|View
argument_list|(
specifier|const
name|View
operator|&
argument_list|)
expr_stmt|;
name|View
modifier|&
name|operator
init|=
operator|(
specifier|const
name|View
operator|&
operator|)
decl_stmt|;
name|off_t
name|start_
decl_stmt|;
name|off_t
name|size_
decl_stmt|;
name|unsigned
name|char
modifier|*
name|data_
decl_stmt|;
name|int
name|lock_count_
decl_stmt|;
block|}
empty_stmt|;
name|friend
name|class
name|File_view
decl_stmt|;
comment|// Find a view into the file.
name|View
modifier|*
name|find_view
parameter_list|(
name|off_t
name|start
parameter_list|,
name|off_t
name|size
parameter_list|)
function_decl|;
comment|// Read data from the file into a buffer.
name|off_t
name|do_read
parameter_list|(
name|off_t
name|start
parameter_list|,
name|off_t
name|size
parameter_list|,
name|void
modifier|*
name|p
parameter_list|,
name|off_t
modifier|*
name|pbytes
parameter_list|)
function_decl|;
comment|// Find or make a view into the file.
name|View
modifier|*
name|find_or_make_view
parameter_list|(
name|off_t
name|start
parameter_list|,
name|off_t
name|size
parameter_list|,
name|off_t
modifier|*
name|pbytes
parameter_list|)
function_decl|;
comment|// Clear the file views.
name|void
name|clear_views
parameter_list|(
name|bool
parameter_list|)
function_decl|;
comment|// The size of a file page for buffering data.
specifier|static
specifier|const
name|off_t
name|page_size
init|=
literal|8192
decl_stmt|;
comment|// Given a file offset, return the page offset.
specifier|static
name|off_t
name|page_offset
parameter_list|(
name|off_t
name|file_offset
parameter_list|)
block|{
return|return
name|file_offset
operator|&
operator|~
operator|(
name|page_size
operator|-
literal|1
operator|)
return|;
block|}
comment|// Given a file size, return the size to read integral pages.
specifier|static
name|off_t
name|pages
parameter_list|(
name|off_t
name|file_size
parameter_list|)
block|{
return|return
operator|(
name|file_size
operator|+
operator|(
name|page_size
operator|-
literal|1
operator|)
operator|)
operator|&
operator|~
operator|(
name|page_size
operator|-
literal|1
operator|)
return|;
block|}
comment|// The type of a mapping from page start to views.
typedef|typedef
name|std
operator|::
name|map
operator|<
name|off_t
operator|,
name|View
operator|*
operator|>
name|Views
expr_stmt|;
comment|// A simple list of Views.
typedef|typedef
name|std
operator|::
name|list
operator|<
name|View
operator|*
operator|>
name|Saved_views
expr_stmt|;
comment|// File name.
name|std
operator|::
name|string
name|name_
expr_stmt|;
comment|// File descriptor.
name|int
name|descriptor_
decl_stmt|;
comment|// Number of locks on the file.
name|int
name|lock_count_
decl_stmt|;
comment|// Buffered views into the file.
name|Views
name|views_
decl_stmt|;
comment|// List of views which were locked but had to be removed from views_
comment|// because they were not large enough.
name|Saved_views
name|saved_views_
decl_stmt|;
comment|// Specified file contents.  Used only for testing purposes.
specifier|const
name|unsigned
name|char
modifier|*
name|contents_
decl_stmt|;
comment|// Specified file size.  Used only for testing purposes.
name|off_t
name|contents_size_
decl_stmt|;
block|}
empty_stmt|;
comment|// A view of file data that persists even when the file is unlocked.
comment|// Callers should destroy these when no longer required.  These are
comment|// obtained form File_read::get_lasting_view.  They may only be
comment|// destroyed when the underlying File_read is locked.
name|class
name|File_view
block|{
name|public
label|:
comment|// This may only be called when the underlying File_read is locked.
operator|~
name|File_view
argument_list|()
expr_stmt|;
comment|// Return a pointer to the data associated with this view.
specifier|const
name|unsigned
name|char
operator|*
name|data
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|data_
return|;
block|}
name|private
label|:
name|File_view
argument_list|(
specifier|const
name|File_view
operator|&
argument_list|)
expr_stmt|;
name|File_view
modifier|&
name|operator
init|=
operator|(
specifier|const
name|File_view
operator|&
operator|)
decl_stmt|;
name|friend
name|class
name|File_read
decl_stmt|;
comment|// Callers have to get these via File_read::get_lasting_view.
name|File_view
argument_list|(
argument|File_read& file
argument_list|,
argument|File_read::View* view
argument_list|,
argument|const unsigned char* data
argument_list|)
block|:
name|file_
argument_list|(
name|file
argument_list|)
operator|,
name|view_
argument_list|(
name|view
argument_list|)
operator|,
name|data_
argument_list|(
argument|data
argument_list|)
block|{ }
name|File_read
operator|&
name|file_
expr_stmt|;
name|File_read
operator|::
name|View
operator|*
name|view_
expr_stmt|;
specifier|const
name|unsigned
name|char
modifier|*
name|data_
decl_stmt|;
block|}
empty_stmt|;
comment|// All the information we hold for a single input file.  This can be
comment|// an object file, a shared library, or an archive.
name|class
name|Input_file
block|{
name|public
label|:
name|Input_file
argument_list|(
specifier|const
name|Input_file_argument
operator|*
name|input_argument
argument_list|)
operator|:
name|input_argument_
argument_list|(
name|input_argument
argument_list|)
operator|,
name|file_
argument_list|()
block|{ }
comment|// Create an input file with the contents already provided.  This is
comment|// only used for testing.  With this path, don't call the open
comment|// method.
name|Input_file
argument_list|(
argument|const char* name
argument_list|,
argument|const unsigned char* contents
argument_list|,
argument|off_t size
argument_list|)
expr_stmt|;
comment|// Open the file.
name|void
name|open
parameter_list|(
specifier|const
name|General_options
modifier|&
parameter_list|,
specifier|const
name|Dirsearch
modifier|&
parameter_list|)
function_decl|;
comment|// Return the name given by the user.
specifier|const
name|char
operator|*
name|name
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|input_argument_
operator|->
name|name
argument_list|()
return|;
block|}
comment|// Return the file name.
specifier|const
name|std
operator|::
name|string
operator|&
name|filename
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|file_
operator|.
name|filename
argument_list|()
return|;
block|}
name|File_read
modifier|&
name|file
parameter_list|()
block|{
return|return
name|this
operator|->
name|file_
return|;
block|}
name|private
label|:
name|Input_file
argument_list|(
specifier|const
name|Input_file
operator|&
argument_list|)
expr_stmt|;
name|Input_file
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Input_file
operator|&
operator|)
decl_stmt|;
specifier|const
name|Input_file_argument
modifier|*
name|input_argument_
decl_stmt|;
name|File_read
name|file_
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace gold
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(GOLD_FILEREAD_H)
end_comment

end_unit

